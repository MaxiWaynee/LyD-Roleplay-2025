#include <YSI\y_hooks>

CMD:namechange(playerid, params[]) {
    new oldName[MAX_PLAYER_NAME], newName[MAX_PLAYER_NAME];//, pID = INVALID_PLAYER_ID;
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "s[25]s[25]", oldName, newName)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Namechange [Name] [Neuer Name]");
    if (!strcmp(newName, "Niemand", true) || strlen(newName) < 3) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Gebe einen gültigen Spielernamen an.");
    mysql_real_escape_string(oldName, oldName, gSQL, sizeof(oldName));
    mysql_real_escape_string(newName, newName, gSQL, sizeof(newName));
    new tempName[MAX_PLAYER_NAME];
    GetPVarString(playerid, "NAMECHANGE.OLDNAME", tempName, sizeof(tempName));
    if (!isnull(tempName)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du führst bereits einen Namechange durch.");
    // sscanf(oldName, "k<playername>", pID);
    // if (pID != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist gerade online.");
    new query[128];
    SetPVarString(playerid, "NAMECHANGE.OLDNAME", oldName);
    SetPVarString(playerid, "NAMECHANGE.NEWNAME", newName);
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `Name` = '%s'", oldName);
    mysql_pquery(query, THREAD_CHECKNAMECHANGE_OLDNAME, playerid, gSQL, MySQLThreadOwner);
    return 1;
}



CMD:pwchange(playerid,params[]) {
    new spielername[MAX_PLAYER_NAME],pw[128];
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    if(sscanf(params,"s[32]s[128]",spielername,pw))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Pwchange [Name] [Passwort]");
    if(!IsPlayerConnected(GetPlayerIdFromName(spielername))) {
        new query[256];
        mysql_real_escape_string(pw, pw,gSQL,sizeof(pw));
        mysql_real_escape_string(spielername, spielername,gSQL,sizeof(spielername));
        format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `Name` = '%s'",spielername);
        if(mysql_pquery(query , THREAD_PWCHANGE , playerid, gSQL,MySQLThreadOwner)==101)
        {
        SendClientMessage(playerid, COLOR_YELLOW, "Das Passwort wurde erfolgreich geändert");
        }
        format(query,sizeof(query),"UPDATE `accounts` SET `Passwort`=SHA2(CONCAT('%s',`SaltKey`),256) WHERE `Name` = '%s'",pw,spielername);
        mysql_tquery(gSQL,query);
    } else {
        SendClientMessage(playerid,COLOR_RED,"Der Spieler ist derzeit online");
    }
    return 1;
}



CMD:configtanke(playerid)
{
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new t = IsPlayerAtTanke(playerid);
    if(t == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe einer Tankstelle.");
    ShowPlayerDialog(playerid, DIALOG_CONFIGTANKE, DIALOG_STYLE_LIST, "Konfigurieren der Tankstelle", "Besitzer rauswerfen\nKaufpreis ändern\nBenzinkosten ändern\nBeschreibung\nMax. Benzin ändern\nBenzinstand ändern", "Auswählen", "Abbrechen");
    return 1;
}



CMD:confighouse(playerid)
{
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new h = IsPlayerAtHouse(playerid);
    if(h == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    ShowPlayerDialog(playerid, DIALOG_CONFIGHOUSE, DIALOG_STYLE_LIST, "Konfigurieren des Hauses", "Bewohner und Besitzer rauswerfen\nKaufpreis ändern\nMietpreis ändern\nMieten zulassen\nStatus\nInterior\nBeschreibung\nMaximale Anzahl an Mietern", "Auswählen", "Abbrechen");
    return 1;
}



CMD:configbiz(playerid)
{
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new b = IsPlayerAtBiz(playerid);
    if(b == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Geschäftes.");
    new dialogCaption[128];
    format(dialogCaption, sizeof(dialogCaption), "Konfigurieren des Geschäftes (ID: %d)", Biz[b][bID]);
    ShowPlayerDialog(playerid, DIALOG_CONFIGBIZ, DIALOG_STYLE_LIST, dialogCaption, "Besitzer rauswerfen\nKaufpreis ändern\nWarenpreis ändern\nStatus\nBeschreibung\nMaximale Waren\nWaren\nÖffnungszeit\nBizkassestand", "Auswählen", "Abbrechen");
    return 1;
}



CMD:tankstand(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    new benzinstand, vehicleid = GetPlayerVehicleID(playerid);
    if (!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Du musst in einem Fahrzeug sein.");
    if (sscanf(params, "i", benzinstand)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/tankstand [Kraftstoffmenge]");
    gGas[vehicleid] = benzinstand;
    return SCMFormatted(playerid, COLOR_LIGHTBLUE, "* Du hast den Tankstand deines Fahrzeuges auf %i Liter gesetzt.", benzinstand);
}



CMD:auftanken(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    new vehid;
    if (isnull(params)) {
        vehid = GetPlayerVehicleID(playerid);
        if (!vehid) return SendClientMessage(playerid, COLOR_RED, "Du musst in einem Fahrzeug sein.");
    }
    else if (sscanf(params, "i", vehid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Auftanken [Vehicle ID]");
    new modelid = GetVehicleModel(vehid);
    if (!modelid) return SendClientMessage(playerid, COLOR_RED, "Die Fahrzeug-ID existiert nicht.");
    gGas[vehid] = GasMax[(modelid - 400)];
    return SCMFormatted(playerid, COLOR_LIGHTBLUE, "* Du hast das Fahrzeug mit der ID %i vollgetankt.", vehid);
}



CMD:setbwstrafe(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    new pID, hours, playerName[MAX_PLAYER_NAME], reason[128];
    if (GetPVarString(playerid, "OFFBW.NAME", reason, sizeof(reason)) != 0) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du erteilst gerade noch eine Bewährungsstrafe."); 
    if (sscanf(params, "u i s[128]", pID, hours, reason)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Setbwstrafe [Spieler ID/Name] [Spielstunden] [Grund]");
    if (pID == INVALID_PLAYER_ID && (sscanf(params, "s[24] i s[64]", playerName, hours, reason) || strlen(playerName) < 3)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der eingegebene Wert ist kein gültiger Spieler.");
    if (hours < 0) return SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Die Spielstunden können nicht negativ sein.");
    if (pID == INVALID_PLAYER_ID) { // Player offline
        new query[256];
        mysql_real_escape_string(playerName, playerName);
        mysql_real_escape_string(reason, reason);
        format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `Name` = '%s'", playerName);
        SetPVarString(playerid, "OFFBW.NAME", playerName);
        SetPVarString(playerid, "OFFBW.REASON", reason);
        SetPVarInt(playerid, "OFFBW.HOURS", hours);
        mysql_pquery(query, THREAD_OFFBWSTRAFE_CHECK, playerid, gSQL, MySQLThreadOwner);
        return 1;
    }
    new message[256];
    Spieler[pID][pSuspendedSentence] = hours;
    format(Spieler[pID][pSusSentenceReason], 128, reason);
    SCMFormatted(playerid, COLOR_LIGHTBLUE, "[INFO] {FFFFFF}Du hast die Bewährungsstrafe von %s auf %d Spielstunden gesetzt.", GetName(pID), hours);
    SCMFormatted(playerid, COLOR_LIGHTBLUE, "[INFO] {FFFFFF}Grund: %s", reason);
    SCMFormatted(pID, COLOR_LIGHTBLUE, "[INFO] {FFFFFF}Deine Bewährungsstrafe wurde von %s auf %d Spielstunden gesetzt.", GetName(playerid), hours);
    SCMFormatted(pID, COLOR_LIGHTBLUE, "[INFO] {FFFFFF}Grund: %s", reason);
    format(message, sizeof(message), "%s %s hat die Daten von Spieler %s überarbeitet! (BWStrafe gesetzt auf: %d, Grund: %s)", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), hours, reason);
    AdminLog(message);
    format(message, sizeof(message), "%s %s hat die Bewährungsstrafe von %s auf %d Spielstunden gesetzt. Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), hours, reason);
    SendUCPAktenEintrag(playerid, GetName(playerid), GetName(pID), message);
    SaveAccount(pID);
    return 1;
}



CMD:createhaus(playerid, params[]) return cmd_createhouse(playerid, params);
CMD:createhouse(playerid, params[])
{
        new chName[32], HouseType, Preis;
        if(sscanf(params, "iis[32]", HouseType, Preis, chName))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Createhouse [Haus-Typ] [Preis] [Name]");
        if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
        new query[1024], Float:x, Float:y, Float:z/* , Float:iX, Float:iY, Float:iZ*/;
        //new Float:px,Float:py,Float:pz;
        GetPlayerPos(playerid, x, y, z);
        //new interior;
        if(HouseType < 1 || HouseType > 23)return SendClientMessage(playerid, COLOR_RED, "Der Haus-Typ muss zwischen 1 und 23 liegen.");
        format(query, sizeof(query), "INSERT INTO `houses` (`ID`,`EnterX`, `EnterY`, `EnterZ`, `Besitzer`, `Name`, `Preis`, `Mieten`, `Lock`, `MietPreis`, `Kasse`,`SellX`,`SellY`,`SellZ`,`SellRot`) VALUES (NULL,%.2f, %.2f, %.2f, '%s', '%s', %d, %d, %d, %d, %d,0.0,0.0,0.0,0.0)", x,y,z,  "Niemand", chName, Preis, 0, 1, 100, 0 );
        mysql_pquery(query,THREAD_CREATEHOUSE,playerid,gSQL,MySQLThreadOwner);
        return 1;
}



CMD:makeadmin(playerid, params[])
{
    new pID, admid, string[128];
    if (Spieler[playerid][pAdmin] < 4)  return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "ui", pID, admid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Makeadmin [SpielerID/Name] [Admin-Rank]");
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online! Benutze /Offmakeadmin [Name] [Admin-Rank]");
    if (admid >= 0 && admid <= 3) {
        if (admid == 0) {
            Spieler[pID][pBMOD] = 0;
            Spieler[pID][pFV] = 0;
        }
        Spieler[pID][pAdmin] = admid;
        format(string, sizeof(string), "[ADMIN]: %s wurde von %s %s zum %s ernannt.", GetName(pID), GetPlayerAdminRang(playerid), GetName(playerid), GetPlayerAdminRang(pID));
        return SendClientMessageToAll(COLOR_DARKRED, string);
    }
    if (admid >= 0 && admid <= 7 && Spieler[playerid][pAdmin] >= 6) {//5
        if (admid == 0) {
            Spieler[pID][pBMOD] = 0;
            Spieler[pID][pFV] = 0;
        }
        Spieler[pID][pAdmin] = admid;
        format(string, sizeof(string), "[ADMIN]: %s wurde von %s %s zum %s ernannt.", GetName(pID), GetPlayerAdminRang(playerid), GetName(playerid), GetPlayerAdminRang(pID));
        return SendClientMessageToAll(COLOR_DARKRED, string);
    } else {
        return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du nur maximal den Adminrang 3 setzen!");
    }
}


CMD:offmakeadmin(playerid, params[]){
    new pID[24], admid, id;
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "s[24]i", pID, admid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Offmakeadmin [Name] [Admin-Rank]");
    if (!sscanf(pID, "u", id) && IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_RED, "[MAKEADMIN] {FFFFFF}Der Spieler ist zurzeit online. Benutze /Offmakeadmin.");
    if (admid >= 0 && admid <= 3) {
        new str[24];
        format(str, sizeof(str), "%s", pID);
        SetPVarString(playerid, "MAKEADMINNAME", str);
        SetPVarInt(playerid, "MAKEADMINRANK", admid);
        new query[256];
        format(query, sizeof(query), "SELECT `Name` FROM `accounts` WHERE `Name` = '%s' LIMIT 1", pID);
        mysql_pquery(query, THREAD_MAKEADMIN_CHECK, playerid, gSQL, MySQLThreadOwner);
        return 1;
    }
    if (admid >= 0 && admid <= 7 && Spieler[playerid][pAdmin] >= 6) {//5
        new str[24];
        format(str, sizeof(str), "%s", pID);
        SetPVarString(playerid, "MAKEADMINNAME", str);
        SetPVarInt(playerid, "MAKEADMINRANK", admid);
        new query[256];
        format(query, sizeof(query), "SELECT `Name` FROM `accounts` WHERE `Name` = '%s' LIMIT 1", pID);
        mysql_pquery(query, THREAD_MAKEADMIN_CHECK, playerid, gSQL, MySQLThreadOwner);
        return 1;
    }
    return SendClientMessage(playerid, COLOR_RED, "Der Rank muss zwischen 0 und 7 liegen.");
}



CMD:makebmod(playerid, params[]) {
    new pID, bmodid, string[128];
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "ui", pID, bmodid))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Makebmod [SpielerID/Name] [Rank 0-2]");
    if(!IsPlayerConnected(playerid))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(bmodid == 0 || bmodid == 2 || bmodid == 1) {
        new bmodname[30];
        if(bmodid == 1){ bmodname ="Beschwerdemoderator";}
        else if(bmodid == 2){ bmodname ="Beschwerdemoderator-Leiter";}
        Spieler[pID][pBMOD] = bmodid;
        if (bmodid == 0) {
            format(string, sizeof(string), "%s %s hat %s Beschwerdemoderator entzogen.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID));
        } else {
            format(string, sizeof(string), "%s %s hat %s zum %s ernannt.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), bmodname);
        }
        SendAdminMessage(COLOR_DARKRED, string);
        return 1;
    }
    return SendClientMessage(playerid, COLOR_RED, "[Fehler] {FFFFFF}Der Rank muss zwischen 0 und 2 liegen.");
}



CMD:offmakebmod(playerid, params[]){
    new pID[24], admid, id;
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "s[24]i", pID, admid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Offmakebmod [Name] [0-2]");
    if (!sscanf(pID, "u", id) && IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_RED, "[BESCHWERDEMODERATOR] {FFFFFF}Der Spieler ist zurzeit online. Benutze /Offmakebmod.");
    if(admid == 0 || admid == 2 || admid == 1) {
        new str[24];
        format(str, sizeof(str), "%s", pID);
        SetPVarString(playerid, "MAKEADMINNAME", str);
        SetPVarInt(playerid, "MAKEADMINRANK", admid);
        new query[256];
        format(query, sizeof(query), "SELECT `Name` FROM `accounts` WHERE `Name` = '%s' LIMIT 1", pID);
        mysql_pquery(query, THREAD_MAKEBMOD_CHECK, playerid, gSQL, MySQLThreadOwner);
        return 1;
    }
    return SendClientMessage(playerid, COLOR_RED, "[BESCHWERDEMODERATOR] {FFFFFF}Der Rank muss zwischen 0 und 2 liegen.");
}



CMD:makefv(playerid, params[]) {
    new pID, fvid, string[128];
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "ui", pID, fvid))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Makefv [SpielerID/Name] [Rank 0-1]");
    if(!IsPlayerConnected(playerid))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(fvid == 0 || fvid == 1) {
        Spieler[pID][pFV] = fvid;
        if (fvid == 0) {
            format(string, sizeof(string), "%s %s hat %s Fraktionsverwalter entzogen.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID));
        } else {         
            format(string, sizeof(string), "%s %s hat %s zum Fraktionsverwalter ernannt.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID));
        }
        SendAdminMessage(COLOR_DARKRED, string);
    }
    return 1;
}



CMD:offmakefv(playerid, params[]) {
    new pID[24], admid, id;
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "s[24]i", pID, admid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Offmakefv [Name] [0-1]");
    if (!sscanf(pID, "u", id) && IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_RED, "[Fehler] {FFFFFF}Der Spieler ist zurzeit online. Benutze /Offmakefv.");
    if(admid == 0 || admid == 1) {
        new str[24];
        format(str, sizeof(str), "%s", pID);
        SetPVarString(playerid, "MAKEADMINNAME", str);
        SetPVarInt(playerid, "MAKEADMINRANK", admid);
        new query[256];
        format(query, sizeof(query), "SELECT `Name` FROM `accounts` WHERE `Name` = '%s' LIMIT 1", pID);
        mysql_pquery(query, THREAD_MAKEFV_CHECK, playerid, gSQL, MySQLThreadOwner);
        return 1;
    }
    return SendClientMessage(playerid, COLOR_RED, "[Fehler] {FFFFFF}Der Rank muss zwischen 0 und 1 liegen.");
}



CMD:sacban(playerid, params[]) {
    new pID, grund[64], string[128], admin[128], string1[128], query[256];
    if(Spieler[playerid][pAdmin] < 4)return SendClientMessage(playerid, COLOR_SAMP, "{FFFFFE}Der Befehl {FF6731}'/sacban'{FFFFFE} wurde nicht gefunden. Benutze {FF6731}/Help{FFFFFE} für Hilfe.");
    if(sscanf(params, "uss[64]", pID, admin, grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/SACBan [SpielerID/Name] [Anti-Cheat / Server-System] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pAdmin] > 0)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Supporter bzw. Admins bannen.");
    if(strcmp(admin,"Anti-Cheat",true)==0){
        format(string, sizeof(string), "[BANNED]: Spieler %s wurde vom Anti-Cheat dauerhaft gebannt, Grund: %s", GetName(pID), grund);
        SendAdminMessage(COLOR_RED, string);
        format(string, sizeof(string), "[BANNED] Sie wurden soeben von Anti-Cheat dauerhaft gebannt. Grund: %s", grund);
        SendClientMessage(pID, COLOR_RED, string);
        format(string1, sizeof(string1), "Sind Sie der Meinung das diese Sperre falsch war? Dann schreiben Sie auf www.LyD-Roleplay.de ein Entbannantrag!");
        SendClientMessage(pID, COLOR_RED, string1);
        mysql_real_escape_string(grund,grund);
        format(query,sizeof(query),"UPDATE `accounts` SET `GebanntVon` = '%s' ,`BanGrund` = '%s' , `Banned` = 1 WHERE `Name` = '%s'",
            ("Anti-Cheat"),grund,GetName(pID));
        mysql_pquery(query,THREAD_SBAN,pID,gSQL,MySQLThreadOwner);
 
        format(query,sizeof(query),"Gebannt: %s von: %s, Grund: %s, Dauer: %s",GetName(pID),("Anti-Cheat"),grund,("Immer"));
        BanLog( query );
 
        format(query,sizeof(query),"%s wurde vom Anti-Cheat dauerhaft gebannt, Grund: %s",GetName(pID) , grund );
        SendUCPAktenEintrag( playerid, ("Anti-Cheat") , GetName(pID) , query );
    }
    else if(strcmp(admin,"Server-System",true)==0){
        format(string, sizeof(string), "[BANNED]: Spieler %s wurde vom Server-System dauerhaft gebannt, Grund: %s", GetName(pID), grund);
        SendAdminMessage(COLOR_RED, string);
        format(string, sizeof(string), "[BANNED] Sie wurden soeben von Server-System dauerhaft gebannt. Grund: %s", grund);
        SendClientMessage(pID, COLOR_RED, string);
        format(string1, sizeof(string1), "Sind Sie der Meinung das diese Sperre falsch war? Dann schreiben Sie auf www.LyD-Roleplay.de ein Entbannantrag!");
        SendClientMessage(pID, COLOR_RED, string1);
        mysql_real_escape_string(grund,grund);
        format(query,sizeof(query),"UPDATE `accounts` SET `GebanntVon` = '%s' ,`BanGrund` = '%s' , `Banned` = 1 WHERE `Name` = '%s'",
            ("Server-System"),grund,GetName(pID));
        mysql_pquery(query,THREAD_SBAN,pID,gSQL,MySQLThreadOwner);
 
        format(query,sizeof(query),"Gebannt: %s von: %s, Grund: %s, Dauer: %s",GetName(pID),("Server-System"),grund,("Immer"));
        BanLog( query );
 
        format(query,sizeof(query),"%s wurde vom Server-System dauerhaft gebannt, Grund: %s",GetName(pID) , grund );
        SendUCPAktenEintrag( playerid, ("Server-System") , GetName(pID) , query );
    }
    // Haus vom Gebannten freimachen
	new pHouse = GetPlayerHouse(pID);
    format(Haus[pHouse][hBesitzer],MAX_PLAYER_NAME,"Niemand");
    Haus[pHouse][hMieterMax] = 10;
    Haus[pHouse][hMieterAnzahl] = 0;
    Haus[pHouse][hMieten] = 0;
    format(query, sizeof(query), "\
    	UPDATE `accounts` SET \
    	`HouseMieteKey` = '999', \
    	`UpgradeWaffenlager` = '0',\
    	`UpgradeSafebox` = '0',\
    	`UpgradeHealing` = '0',\
    	`HausWaffenlager` = '0',\
    	`HausSafeboxSpice` = '0',\
    	`HausSafeboxDrogen` = '0'\
    	WHERE `HouseMieteKey` = %d", Spieler[pID][pPlayerHouse]);
    mysql_pquery(query,THREAD_DUMMY,playerid,gSQL,MySQLThreadOwner);
    Haus[pHouse][hMieterAnzahl] = 0;
    Haus[pHouse][hKasse] = 0;
    return 1;
}



CMD:amotor(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 4) return 0;
    new vehicleid = GetPlayerVehicleID(playerid);
    if (!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug.");
    if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Fahrer.");
    if (IsBicycle(GetVehicleModel(vehicleid))) return SendClientMessage(playerid, COLOR_RED, "Fahrräder haben keinen Motor.");
    if (gGas[vehicleid] < 1) return SendClientMessage(playerid, COLOR_YELLOW, "Das Fahrzeug hat kein Benzin mehr.");
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    if (engine == VEHICLE_PARAMS_OFF || engine == VEHICLE_PARAMS_UNSET) {
        SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lights, alarm, doors, bonnet, boot, objective);
        SendClientMessage(playerid, COLOR_YELLOW, "Du hast den Motor gestartet!");
        ShowBuyInformation(playerid,"~w~Motor ~g~gestartet!");
        return 1;
    }
    SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective);
    SendClientMessage(playerid, COLOR_YELLOW, "Du hast den Motor ausgeschaltet!");
    ShowBuyInformation(playerid,"~w~Motor ~r~ausgeschaltet!");
    return 1;
}



CMD:givecoins(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 6) return ERROR_RANG_MSG(playerid);
    new sSpieler[MAX_PLAYER_NAME], amount, message[128];
    GetPVarString(playerid, "GIVECOINS.NAME", sSpieler, sizeof(sSpieler));
    if (!isnull(sSpieler)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du gibst gerade noch jemandem Coins.");
    if (sscanf(params, "s[24]i", sSpieler, amount) || !amount) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Givecoins [Spielername] [Anzahl]");
    if (IsPlayerConnected(GetPlayerIdFromName(sSpieler))) {
      Spieler[GetPlayerIdFromName(sSpieler)][pCoins] += amount;
      format(message, sizeof(message), "%s %s hat %s %s Coins gegeben.", GetPlayerAdminRang(playerid), GetName(playerid), sSpieler, AddDelimiters(amount));
      AdminLog(message);
      SendUCPAktenEintrag(playerid, GetName(playerid), sSpieler, message);
      SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Du hast %s %s Coins gegeben.", sSpieler, AddDelimiters(amount));
      return 1;
    }
    new query[256];
    mysql_real_escape_string(sSpieler, sSpieler);
    SetPVarString(playerid, "GIVECOINS.NAME", sSpieler);
    SetPVarInt(playerid, "GIVECOINS.AMOUNT", amount);
    format(query, sizeof(query), "SELECT `Name` FROM `accounts` WHERE `Name` = '%s' LIMIT 1", sSpieler);
    mysql_pquery(query, THREAD_GIVECOINS_CHECK, playerid, gSQL, MySQLThreadOwner);
    return 1;
}



CMD:purge(playerid, params[]) {
    new status[16],string[128];
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "s[16]", status)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Purge [An/Aus]");
    if(strcmp(status, "an", true) == 0) {
        if(bPurgeEvent == false) {
	        format(string,sizeof(string),"[PURGE] "COLOR_HEX_WHITE"%s %s hat das Purge-Event aktiviert!",GetPlayerAdminRang(playerid),GetName(playerid));
	        SendClientMessageToAll(COLOR_YELLOW,string);
	        SendClientMessageToAll(COLOR_YELLOW,"[PURGE] "COLOR_HEX_WHITE"Ab jetzt gelten die Purge-Regeln.");
	        SendClientMessage(playerid,COLOR_RED,"[INFO] "COLOR_HEX_WHITE"Per /Purge Aus werden die Befehle deaktiviert & die speziellen Verleihe gelöscht.");
	        bPurgeEvent = true;
	        LoadPurgeVerleih();
            foreach(new i : Player) {
                if (IsPlayerConnected(i) && gPlayerLogged[i]) {
                    if (IsPlayerNPC(i)) continue;  
                    PlayAudioStreamForPlayer(i, SOUND_PURGE);
                }
            }
        } else return SendClientMessage(playerid,COLOR_RED,"Das Purge-Event ist bereits aktiviert.");
    }
    else if(strcmp(status, "aus", true) == 0) {
        if(bPurgeEvent == true) {
	        format(string,sizeof(string),"[PURGE] "COLOR_HEX_WHITE"%s %s hat das Purge-Event deaktiviert!",GetPlayerAdminRang(playerid),GetName(playerid));
	        SendClientMessageToAll(COLOR_YELLOW,string);
	        SendClientMessageToAll(COLOR_YELLOW,"[PURGE] "COLOR_HEX_WHITE"Ab jetzt gelten die normalen Server-Regeln.");
	        UnLoadPurgeVerleih();
	        bPurgeEvent = false;
            foreach(new i : Player) {
                if (IsPlayerConnected(i) && gPlayerLogged[i]) {
                    if (IsPlayerNPC(i)) continue;  
                    StopAudioStreamForPlayer(i);
                }
            }
        } else return SendClientMessage(playerid,COLOR_RED,"Das Purge-Event ist bereits deaktiviert.");
    }
	return 1;
}



CMD:pgivegun(playerid, params[]) {
	new wID,wMuni,string[128];
	if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    if(!bPurgeEvent)return SendClientMessage(playerid,COLOR_RED,"Aktuell läuft kein Purge-Event, somit kannst du diesen Befehl nicht nutzen.");
    if(sscanf(params, "ii", wID, wMuni))return SendClientMessage(playerid,COLOR_BLUE,INFO_STRING"/PGiveGun [Waffen-ID] [Munition]");
    format(string,sizeof(string),"[PURGE] "COLOR_HEX_WHITE"%s %s gab jedem Spieler Waffen. (ID: %d, Munition: %d)",GetPlayerAdminRang(playerid),GetName(playerid),wID,wMuni);
    SendClientMessageToAll(COLOR_BLUE,string);
    foreach(new i : Player) {
		GivePlayerWeapon(i, wID, wMuni);
   	}
	return 1;
}



CMD:pgivehealth(playerid, params[]) {
	new health,string[128];
	if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    if(!bPurgeEvent)return SendClientMessage(playerid,COLOR_RED,"Aktuell läuft kein Purge-Event, somit kannst du diesen Befehl nicht nutzen.");
    if(sscanf(params, "i", health))return SendClientMessage(playerid,COLOR_BLUE,INFO_STRING"/PGiveHealth [Health]");
    format(string,sizeof(string),"[PURGE] "COLOR_HEX_WHITE"%s %s gab jedem Spieler %d Prozent Leben.",GetPlayerAdminRang(playerid),GetName(playerid),health);
    SendClientMessageToAll(COLOR_BLUE,string);
    foreach(new i : Player) {
		SetPlayerHealth(i, health);
   	}
	return 1;
}



CMD:pgivearmor(playerid, params[]) {
	new armor,string[128];
	if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    if(!bPurgeEvent)return SendClientMessage(playerid,COLOR_RED,"Aktuell läuft kein Purge-Event, somit kannst du diesen Befehl nicht nutzen.");
    if(sscanf(params, "i", armor))return SendClientMessage(playerid,COLOR_BLUE,INFO_STRING"/PGiveArmor [Armor]");
    format(string,sizeof(string),"[PURGE] "COLOR_HEX_WHITE"%s %s gab jedem Spieler %d Prozent Rüstung.",GetPlayerAdminRang(playerid),GetName(playerid),armor);
    SendClientMessageToAll(COLOR_BLUE,string);
    foreach(new i : Player) {
		SetPlayerArmour(i, armor);
   	}
	return 1;
}



CMD:allesspeichern(playerid,params[]) {
    #pragma unused params
    if(Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    SendClientMessage(playerid,COLOR_YELLOW,"Daten werden zum Speichern gesendet ...");
    //CallLocalFunction("SaveAll", ""); // y_hooks
    SaveAll();
    mysql_pquery("SELECT NOW()",THREAD_SAVEALL,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:sfreischalten(playerid,params[] ) {
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new giveid;
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/SFreischalten [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[giveid][pPremiumCarSlot] == 1 ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat bereits den Premium Fahrzeugslot.");
    new String[128];
    format(String,sizeof(String),"%s %s hat dir einen Premium Fahrzeugslot freigeschaltet!", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    Spieler[giveid][pPremiumCarSlot] = 1;
    return 1;
}



CMD:rauswerfenhotel(playerid,params[]){
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new giveid, query[128], hStr[256], hotel;
    hotel = IsPlayerAtHotel(playerid);
    if(hotel == 999) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keinem Hotelzimmer.");
    if( strcmp(Hotel[hotel][hBesitzer],"Niemand") == 0 )return SendClientMessage(playerid, COLOR_GREY, "Das Hotelzimmer wird nicht gemietet.");
    sscanf( Hotel[hotel][hBesitzer] , "u",giveid);
    if( IsPlayerConnected(giveid) ) {
        // Falls Spieler verbunden,direkt rauswerden
        Spieler[giveid][pSpawnChange] = 0;
        Spieler[giveid][pPlayerHotel] = 999;
        SendClientMessage(giveid,COLOR_RED,"Du wurdest aus dem Hotelzimmer geworfen.");
    }


    format( Hotel[hotel][hBesitzer] , MAX_PLAYER_NAME , "Niemand" );
    Hotel[hotel][hLock] = 1;
    format(query,sizeof(query),"%s %s hat %s aus seinem Hotelzimmer geworfen.", GetPlayerAdminRang(playerid), GetName(playerid),GetName(giveid));
    SendAdminMessage(COLOR_YELLOW, query);
    format(hStr, sizeof(hStr), "Dieses Hotelzimmer ist noch zu vermieten!\n\
                                %s\n\
                                Zimmer Mietpreis: %d$\n\
                                Mit /miethotelraum mietest du ein Hotelzimmer", Hotel[hotel][hName], Hotel[hotel][hMietPreis]);
    UpdateDynamic3DTextLabelText(Hotel[hotel][hText],COLOR_PROP,hStr);
    return 1;
}



CMD:fixveh(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 4) return 0;
    new vehicleid = GetPlayerVehicleID(playerid);
    if (!vehicleid) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist in keinem Fahrzeug.");
    new Float:vehhealth;
    if (isnull(params)) {
        if (IsArmoredVehicle(vehicleid) && FrakCarInfo[vehicleid][f_frak] == 1) RepairVehicle(vehicleid) ,SetVehicleHealth(vehicleid, 2000.0), vehhealth = 2000.0;
        else vehhealth = 1000.0, RepairVehicle(vehicleid);
    }
    else if (sscanf(params, "%f", vehhealth)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Fixveh optional:[Zustand]");

    new string[128];
    format(string, sizeof(string),"%s hat sein Fahrzeug (%s | ID: %d) via /fixveh repariert.", GetName(playerid), CarName[GetVehicleModel(vehicleid) - 400], vehicleid);
    SendModMessage(COLOR_YELLOW ,string);
    SetVehicleHealth(vehicleid, vehhealth);
    return true;
}



CMD:delzeitsperre(playerid, params[]) {
	new zoneidd, zoneText[MAX_ZONE_NAME], string[128];
	if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
	if (sscanf(params, "i", zoneidd)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Delzeitsperre [Gangzone-ID]");
	if (zoneidd < 1 || zoneidd > MAX_GANGZONES) return SendClientMessage(playerid, COLOR_YELLOW, "[FEHLER] {FFFFFF}Keine gültige Gangzone-ID.");
    GetPoint2DZone(g_GangZone[zoneidd][GZ_fIconX], g_GangZone[zoneidd][GZ_fIconY], zoneText, sizeof(zoneText));
	g_GangZone[zoneidd][GZ_iTimeout] = 0;
	format(string,sizeof(string),"[INFO] {FFFFFF}%s %s hat die Zeitsperre in %s [%d] entfernt.",GetPlayerAdminRang(playerid),GetName(playerid),zoneText, zoneidd);
	SendModMessage(COLOR_YELLOW,string);
	return 1;
}



CMD:bfreischalten(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new giveid,String[128];
    if(sscanf(params, "u", giveid))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/bfreischalten [SpielerID/Name]");
    if(!IsPlayerConnected(giveid))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    format(String,sizeof(String),"%s %s hat deinen extra Biz-Slot freigeschaltet", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    format(String,sizeof(String),"Du hast den extra Biz-Slot von %s freigschaltet",GetName(giveid));
    SendClientMessage(playerid,COLOR_YELLOW,String);
    Spieler[giveid][pPremiumBizSlot] = 1;
    Spieler[giveid][pPlayerBizEx] = 999;
    return 1;
}



CMD:delclub(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new name[MAX_PLAYER_NAME],String[128];
    if(sscanf(params, "s[24]", name))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Delclub [SpielerID/Name]");
    mysql_real_escape_string(name,name);
    PlayerSQLExtra(playerid,name);
    format(String,sizeof(String),"SELECT `Name`,`DonateRank` FROM `accounts` WHERE `Name` = '%s' LIMIT 1",name);
    mysql_pquery(String,THREAD_DELCLUB,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:gebefirma(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    new pID, firmenid;
    if (sscanf(params, "ud", pID, firmenid) || !( 0 <= firmenid <= sizeof(g_Firma))) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Gebefirma [SpielerID/Name] [Firmen-ID (1-12)]");
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online.");
    if (Spieler[pID][pPlayerFirma] != 999) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler besitzt schon eine Firma.");
    new message[128], firmenindex = GetJobFirmaIndexByID(firmenid);
    if (strcmp(g_Firma[firmenindex][F_sBesitzer], "Niemand") != 0) return SCMFormatted(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Die Firma %s gehört aktuell noch %s", g_Firma[firmenindex][F_sBezeichnung], g_Firma[firmenindex][F_sBesitzer]);
    Spieler[pID][pPlayerFirma] = firmenindex;
    format(g_Firma[firmenindex][F_sBesitzer], MAX_PLAYER_NAME, GetName(pID));
    format(message, sizeof(message), "[GEWERBEAMT] {FFFFFF}%s ist Firmeninhaber der '%s' geworden!", g_Firma[firmenindex][F_sBesitzer], g_Firma[firmenindex][F_sBezeichnung]);
    return SendClientMessageToAll(COLOR_YELLOW, message);
}



CMD:delfirma(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    new pName[25];
    if (sscanf(params, "s[24]", pName)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Delfirma [Name]");
    for (new x; x < MAX_BIZ; x++) {
        if (!strcmp(pName, g_Firma[x][F_sBesitzer], true)) {
            new message[128], giveid;
            format(g_Firma[x][F_sBesitzer], MAX_PLAYER_NAME, "Niemand");
            format(message, sizeof(message),"[GEWERBEAMT] {FFFFFF}%s ist nicht mehr der Firmeninhaber der Firma '%s'!", pName, g_Firma[x][F_sBezeichnung]);
            SendClientMessageToAll(COLOR_YELLOW, message);
            sscanf(pName, "k<playername>", giveid);
            if (giveid != INVALID_PLAYER_ID) Spieler[giveid][pPlayerFirma] = 999;
            break;
        }
        if (x == MAX_BIZ - 1) return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Der Spieler besitzt keine Firma");
    }
    return 1;
}



CMD:delhouse(playerid, params[]) return cmd_delhaus(playerid, params);

CMD:delhaus(playerid,params[]) {
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    new hids;
    for (new i; i < MAX_HOUSES; i++) {
        if (IsPlayerInRangeOfPoint(playerid, 5.0, Haus[i][EnterX], Haus[i][EnterY], Haus[i][EnterZ])) {
            hids=Haus[i][hID];
            Haus[i][EnterX] = 13337.0; // Invalid Coords, to prevent the user from buying it when spawning
            Haus[i][EnterY] = 13337.0;
            Haus[i][EnterZ] = 13337.0;
            format(Haus[i][hBesitzer], MAX_PLAYER_NAME, "geloescht");
            Haus[i][hMieterMax] = 0;
            Haus[i][hMieterAnzahl] = 0;
            format(Haus[i][hName], 32, "geloescht"); // Muss sein weil ein Autist das so gelöst hat... smh
            Haus[i][hPreis] = 999999999;
            Haus[i][hMieten] = 0;
            Haus[i][hID] = 0;
            Haus[i][hMietPreis] = 999999999;
            Haus[i][hLock] = 1;
            DestroyDynamic3DTextLabel(Haus[i][hText]);
            Haus[i][hText] = Text3D:INVALID_STREAMER_ID;
            DestroyDynamicPickup(Haus[i][hPickup]);
            Haus[i][hPickup] = INVALID_STREAMER_ID;
            DestroyHouseSellObject(i);
            break;
        }
    }
    if (hids != 0) {
        new string[128];
        format(string, sizeof(string), "DELETE FROM `houses` WHERE `ID` = '%d'", hids);
        mysql_oquery(string, THREAD_DUMMY, INVALID_PLAYER_ID, gSQL);
        SendClientMessage(playerid, COLOR_GREEN, "Du hast das Haus vollständig gelöscht!");
        format(string, sizeof(string), "[INFO] %s %s hat das Haus mit der ID %d gelöscht.", GetPlayerAdminRang(playerid), GetName(playerid), hids);
        SendAdminMessage(COLOR_DARKRED, string);
    }
    return 1;
}



CMD:aunlock(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 4) return ERROR_RANG_MSG(playerid);
    new toggleDoors = 0;
    sscanf(params, "i", toggleDoors);
    new vehicleid = IsPlayerInAnyVehicle(playerid) ? GetPlayerVehicleID(playerid) : GetClosestVehicle(playerid, 10.0);
    new engine, light, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, light, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicleid, engine, light, alarm, toggleDoors, bonnet, boot, objective);
    return 1;
}



CMD:delallgvehs(playerid,params[]) {
    #pragma unused params
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new String[128], c = 0;
    for(new i = 0 ; i < MAX_VEHICLES ; i++) {
        if( aiVehicles[i] == VEH_PRIVATVERLEIH ) {
            DestroyVehicleEx(i);
            aiVehicles[i] = VEH_INVALID;
            c++;
        }
    }
    format(String,sizeof(String),"%s %s hat alle aktuell gemieteten Fahrzeuge gelöscht. (Anzahl: %d)", GetPlayerAdminRang(playerid), GetName(playerid),c);
    SendAdminMessage(COLOR_ORANGE,String);
    return 1;
}



CMD:creategutschein(playerid, params[])
{
	new String[256];
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    if(Spieler[playerid][pAdmin] < 4)return ERROR_RANG_MSG(playerid);
    new gutschein, code[32];
    if(sscanf(params,"s[32]d",code,gutschein))return Gutscheinmsg(playerid);
    if(gutschein < 1 || gutschein >= sizeof(g_Gutschein))return SCMFormatted(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Die Gutschein-ID geht nur von 1 bis %d", sizeof(g_Gutschein) - 1);
    mysql_real_escape_string(code,code);
    PlayerSQLExtra(playerid,params);
    format(String,sizeof(String),"SELECT * FROM `gutschein` WHERE `code` = '%s' LIMIT 1", code );
    mysql_pquery( String , THREAD_CREATEGUTSCHEIN_CHECK , playerid, gSQL,MySQLThreadOwner);
    return 1;
}



CMD:nachricht(playerid,params[])
{
    if(!(Spieler[playerid][pAdmin] >= 4))return ERROR_RANG_MSG(playerid);
    new msg[25], ty, time;
    if(sscanf(params, "iis[25]", time, ty, msg)) return SendClientMessage(playerid, -1, "Benutze: /nachricht [Zeit] [Msg Typ] [TEXT]");
    if(ty >= 8 || ty == 0 || ty == 2) return SendClientMessage(playerid, -1, "Nur 1,3,4,5,6,7");
    GameTextForAll(msg, time, ty);
    return 1;
}



CMD:deakaccount(playerid,params[])
{
    new pname[32];
    if(sscanf(params,"s[32]",pname))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Deakaccount [SpielerName]");
    if(Spieler[playerid][pAdmin]>=3)
    {
        new query[256];
        format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `Name` = '%s'",pname);
        if(mysql_pquery(query , THREAD_DEAKTACC , playerid, gSQL,MySQLThreadOwner)<=0)
        {
            if(!IsPlayerConnected(GetPlayerIdFromName(pname)))
            {
                new string[200];
                format(query, sizeof(query), "UPDATE `accounts` SET `Deakacc` = '1' ,`Deakaccadmin` = '%s' WHERE `Name` = '%s'",pname);
                mysql_pquery(query ,THREAD_AKTACC , playerid, gSQL,MySQLThreadOwner);
                SendClientMessage(playerid,COLOR_YELLOW,"Du hast den Account erfolgreich deaktiviert");
                format(string,200,"%s %s hat den Account von %s deaktiviert.", GetPlayerAdminRang(playerid), GetName(playerid), pname);
                SendUCPAktenEintrag(playerid,GetName(playerid),pname,string);
            }
            else
            {
                SendClientMessage(playerid,COLOR_RED,"Dieser Spieler ist online, du kannst nur Spieler die offline sind deaktivieren");
            }
        }
        else
        {
            SendClientMessage(playerid,COLOR_RED,"Du kannst nur Spieler deaktivieren!-");
        }
    }else{
        ERROR_RANG_MSG(playerid);
    }
    return 1;
}



CMD:aktaccount(playerid,params[])
{
    new pname[32];
    if(sscanf(params,"s[32]",pname))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Aktaccount [SpielerName]");
    if(Spieler[playerid][pAdmin]>=3)
    {
        new query[256];
        format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `Name` = '%s'",pname);
        if(mysql_pquery(query , THREAD_AKTACC , playerid, gSQL,MySQLThreadOwner)==100)
        {
            new string[200];
            format(query, sizeof(query), "UPDATE `accounts` SET `Deakacc` = '0' WHERE `Name` = '%s'",pname);
            mysql_pquery(query ,THREAD_AKTACC , playerid, gSQL,MySQLThreadOwner);
            SendClientMessage(playerid,COLOR_YELLOW,"Du hast den Account erfolgreich aktiviert");
            format(string,200,"%s %s hat den Account von %s aktiviert.", GetPlayerAdminRang(playerid), GetName(playerid), pname);
            SendUCPAktenEintrag(playerid,GetName(playerid),pname,string);
        }
    }else{
        ERROR_RANG_MSG(playerid);
    }
    return 1;
}


CMD:gebeskill(playerid,params[]) {
    new pid,skillname[32],skilllevel;
    if(sscanf(params,"us[32]i",pid,skillname,skilllevel))return SendClientMessage(playerid,COLOR_RED,"Befehl: /Gebeskill [playerid] [Skillname] [SkillLevel]");
    if(Spieler[playerid][pAdmin]>=3){
        if(IsPlayerConnected(pid)){
            if(skilllevel<1||skilllevel>6){
                SendClientMessage(playerid,COLOR_RED,"Fehler: Das ausgewählte Level muss mindestens 1 betragen und maximal 6");
            }
            else if(strcmp(skillname,"Hure",true)==0||strcmp(skillname,"Anwalt",true)==0||strcmp(skillname,"Waffendealer",true)==0||strcmp(skillname,"Detektiv",true)==0||strcmp(skillname,"Drogendealer",true)==0||strcmp(skillname,"Samen",true)==0||strcmp(skillname,"Pilot",true)==0) {
                if(strcmp(skillname,"Hure",true)==0){
                    if(skilllevel==6){skilllevel=5;}
                    Spieler[pid][pHurePoints]=skilllevel;
                    new string[200];
                    format(string,200,"%s %s hat dir den Hure Skill auf das Level %i gesetzt", GetPlayerAdminRang(playerid), GetName(playerid), skilllevel);
                    SendClientMessage(pid,COLOR_GREEN,string);
                    format(string,200,"Du hast erfolgreich dem Spieler %s beim Hure Skill das Level auf %i gesetzt",GetName(pid),skilllevel);
                    SendClientMessage(playerid,COLOR_GREEN,string);
                }
                if(strcmp(skillname,"Anwalt",true)==0){
                    new skillpoints;
                    if(skilllevel==1){
                        skillpoints=0;
                    } else if(skilllevel==2){
                        skillpoints=20;
                    } else if(skilllevel==3){
                        skillpoints=80;
                    } else if(skilllevel==4){
                        skillpoints=120;
                    } else if(skilllevel==5){
                        skillpoints=250;
                    } else{
                        skillpoints=420;
                    }
                    Spieler[pid][pLawyerPoints]=skillpoints;
                    new string[200];
                    format(string,200,"%s %s hat dir den Anwalts Skill auf das Level %i gesetzt", GetPlayerAdminRang(playerid), GetName(playerid), skilllevel);
                    SendClientMessage(pid,COLOR_GREEN,string);
                    format(string,200,"Du hast erfolgreich dem Spieler %s beim Anwalts Skill das Level auf %i gesetzt",GetName(pid),skilllevel);
                    SendClientMessage(playerid,COLOR_GREEN,string);
                    new String[140];

                    format(String,sizeof(String),"%s %s hat Spieler %s den Anwalt-Skill %d gesetzt!", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pid), skilllevel);
                    AdminLog(String);
                }
                if(strcmp(skillname,"Detektiv",true)==0) {
                    new skillpoints;
                    if(skilllevel==1){
                        skillpoints=0;
                    } else if(skilllevel==2) {
                        skillpoints=50;
                    } else if(skilllevel==3) {
                        skillpoints=150;
                    } else if(skilllevel==4) {
                        skillpoints=310;
                    } else if(skilllevel==5) {
                        skillpoints=540;
                    } else {
                        skillpoints=540;
                    }
                    Spieler[pid][pDetektivPoints]=skillpoints;
                    new string[200];
                    format(string,200,"%s %s hat dir den Detektiv Skill auf das Level %i gesetzt", GetPlayerAdminRang(playerid), GetName(playerid), skilllevel);
                    SendClientMessage(pid,COLOR_GREEN,string);
                    format(string,200,"Du hast erfolgreich dem Spieler %s beim Detektiv Skill das Level auf %i gesetzt",GetName(pid),skilllevel);
                    SendClientMessage(playerid,COLOR_GREEN,string);
                    new String[140];

                    format(String,sizeof(String),"%s %s hat Spieler %s den Detektiv-Skill %d gesetzt!", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pid), skilllevel);
                    AdminLog(String);
                }
                if(strcmp(skillname,"Drogendealer",true)==0) {
                    if(skilllevel==6){skilllevel=5;}
                    new skillpoints;
                    if(skilllevel==1) {
                        skillpoints=0;
                    } else if(skilllevel==2) {
                        skillpoints=50;
                    } else if(skilllevel==3) {
                        skillpoints=100;
                    } else if(skilllevel==4) {
                        skillpoints=280;
                    } else {
                        skillpoints=510;
                    }
                    Spieler[pid][pDrogenPoints]=skillpoints;
                    new string[200];
                    format(string,200,"%s %s hat dir den Drogendealer Skill auf das Level %i gesetzt", GetPlayerAdminRang(playerid), GetName(playerid), skilllevel);
                    SendClientMessage(pid,COLOR_GREEN,string);
                    format(string,200,"Du hast erfolgreich dem Spieler %s beim Drogendealer Skill das Level auf %i gesetzt",GetName(pid),skilllevel);
                    SendClientMessage(playerid,COLOR_GREEN,string);
                    new String[140];

                    format(String,sizeof(String),"%s %s hat Spieler %s den Drogendealer-Skill %d gesetzt!", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pid), skilllevel);
                    AdminLog(String);
                }
                if(strcmp(skillname,"Waffendealer",true)==0) {
                    if(skilllevel==6){skilllevel=5;}
                    new skillpoints;
                    if(skilllevel==1) {
                        skillpoints=0;
                    } else if(skilllevel==2) {
                        skillpoints=80;
                    } else if(skilllevel==3) {
                        skillpoints=200;
                    } else if(skilllevel==4) {
                        skillpoints=440;
                    } else {
                        skillpoints=710;
                    }
                    Spieler[pid][pWaffenteilePoints]=skillpoints;
                    new string[200];
                    format(string,200,"%s %s hat dir den Waffendealer Skill auf das Level %i gesetzt", GetPlayerAdminRang(playerid), GetName(playerid), skilllevel);
                    SendClientMessage(pid,COLOR_GREEN,string);
                    format(string,200,"Du hast erfolgreich dem Spieler %s beim Waffendealer Skill das Level auf %i gesetzt",GetName(pid),skilllevel);
                    SendClientMessage(playerid,COLOR_GREEN,string);
                    new String[140];

                    format(String,sizeof(String),"%s %s hat Spieler %s den Waffendealer-Skill %d gesetzt!", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pid), skilllevel);
                    AdminLog(String);
                }
                if(strcmp(skillname,"Samen",true)==0) {
                    if(skilllevel==6){skilllevel=5;}
                    new skillpoints;
                    if(skilllevel==1) {
                        skillpoints=0;
                    } else if(skilllevel==2) {
                        skillpoints=500;
                    } else if(skilllevel==3) {
                        skillpoints=1500;
                    } else if(skilllevel==4) {
                        skillpoints=2500;
                    } else {
                        skillpoints=5000;
                    }
                    Spieler[pid][pSpiceSamenPoints]=skillpoints;
                    new string[200];
                    format(string,200,"%s %s hat dir den Samen Skill auf das Level %i gesetzt", GetPlayerAdminRang(playerid), GetName(playerid), skilllevel);
                    SendClientMessage(pid,COLOR_GREEN,string);
                    format(string,200,"Du hast erfolgreich dem Spieler %s beim Samen Skill das Level auf %i gesetzt",GetName(pid),skilllevel);
                    SendClientMessage(playerid,COLOR_GREEN,string);
                    new String[140];

                    format(String,sizeof(String),"%s %s hat Spieler %s den Samen-Skill %d gesetzt!", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pid), skilllevel);
                    AdminLog(String);
                }
                if(strcmp(skillname,"Pilot",true)==0) {
                    if(skilllevel==6){skilllevel=5;}
                    new skillpoints;
                    if(skilllevel==1) {
                        skillpoints=0;
                    } else if(skilllevel==2) {
                        skillpoints=25;
                    } else if(skilllevel==3) {
                        skillpoints=100;
                    } else if(skilllevel==4) {
                        skillpoints=150;
                    } else {
                        skillpoints=300;
                    }
                    Spieler[pid][pPilotPoints]=skillpoints;
                    new string[200];
                    format(string,200,"%s %s hat dir den Piloten Skill auf das Level %i gesetzt", GetPlayerAdminRang(playerid), GetName(playerid), skilllevel);
                    SendClientMessage(pid,COLOR_GREEN,string);
                    format(string,200,"Du hast erfolgreich dem Spieler %s beim Piloten Skill das Level auf %i gesetzt",GetName(pid),skilllevel);
                    SendClientMessage(playerid,COLOR_GREEN,string);
                    new String[140];

                    format(String,sizeof(String),"%s %s hat Spieler %s den Piloten-Skill %d gesetzt!", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pid), skilllevel);
                    AdminLog(String);
                }
            } else {
                SendClientMessage(playerid,COLOR_RED,"Fehler: es muss der Skill 'Hure', 'Waffendealer', 'Drogendealer', 'Anwalt', 'Samen' oder 'Pilot' ausgewählt werden");
            }
        } else {
            SendClientMessage(playerid,COLOR_RED,"Die ausgewählte Spielerid ist nicht Online");
        }
    } else {
        ERROR_RANG_MSG(playerid);
    }
    return 1;
}


CMD:gmsg(playerid, params[])
{
    new text[128];
    if(sscanf(params, "s[128]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Gmsg [Nachricht]");
    if(Spieler[playerid][pAdmin] > 3)
    {
        new string[256];
        format(string, sizeof(string), "** %s %s sagt: %s **", GetPlayerAdminRang(playerid), GetName(playerid), text);
        SendClientMessageToAll(COLOR_PINK, string);
    }else{
        ERROR_RANG_MSG(playerid);
    }
    return 1;
}

CMD:gebietupgrade(playerid,params[]) {
	if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    for(new index;index<MAX_GANGZONES;index++) {
        if(!IsPlayerInRangeOfPoint(playerid , 6.0 , g_GangZone[index][GZ_fIconX],g_GangZone[index][GZ_fIconY],g_GangZone[index][GZ_fIconZ])&&index==MAX_GANGZONES-1) {
            return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der nähe des Icons");
        }
        else if(IsPlayerInRangeOfPoint(playerid , 6.0 , g_GangZone[index][GZ_fIconX],g_GangZone[index][GZ_fIconY],g_GangZone[index][GZ_fIconZ])) {
        	ShowPlayerDialog(playerid,DIALOG_GUP,DIALOG_STYLE_LIST,"Gebietupgrade","Maschine für Waffenteile\nMaschine für Drogen\nVerpachtung","Auswählen","Abbrechen");
            break;
        }
    }
    return 1;
}

CMD:kampfzone(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
	if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
	if (g_aSettings[ASETTING_GANGFIGHTBLOCK][ASETTING_TOGGLE]) return SendClientMessage(playerid, COLOR_RED, "Zurzeit ist die Gangfightsperre aktiviert.");
	if(!kampfzone[1]) {
	    new string[128];
		GangZoneShowForAll(kampfzone[0], 0xFA2326AA);
		kampfzone[1] = true;
		format(string,sizeof(string),"[KAMPFZONE-MELDUNG]: {FFFFFF}%s %s hat die Kampfzone gestartet! Der Kampf dauert 45 Minuten.",GetPlayerAdminRang(playerid),GetName(playerid));
		SendClientMessageToAll(COLOR_YELLOW,string);
		kampfzone[2] = gettime()+45*60;
  		return SendClientMessage(playerid, COLOR_GREEN, "Kampfzone wurde gestartet. Zum beenden tippe den Befehl nochmal.");
	} else {
	    new string[128];
	    GangZoneHideForAll(kampfzone[0]);
	    kampfzone[1] = false;
	    format(string,sizeof(string),"[KAMPFZONE-MELDUNG]: {FFFFFF}%s %s hat die Kampfzone administrativ beendet!",GetPlayerAdminRang(playerid),GetName(playerid));
		SendClientMessageToAll(COLOR_YELLOW,string);
	}
	return SendClientMessage(playerid, COLOR_GREEN, "Du hast die Kampfzone deaktiviert.");
}

CMD:delfcar(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
	new veh = GetPlayerVehicleID(playerid);
    if(!IsPlayerInVehicle(playerid,veh)) return SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Fraktionsfahrzeug.");
    if(FrakCarInfo[veh][f_dbid] == 0 || FrakCarInfo[veh][f_frak] == 0) return SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Fraktionsfahrzeug.");
    new query[256];
    format(query,sizeof(query),"DELETE FROM `"#SERVERFRAKCARS_DB"` WHERE `id`='%i'",FrakCarInfo[veh][f_dbid]);
    mysql_tquery(gSQL,query);
    DestroyVehicle(veh);
    FrakCarInfo[veh][f_veh] = 65535;
    FrakCarInfo[veh][f_world] = 0;
    FrakCarInfo[veh][f_dbid] = 0;
    FrakCarInfo[veh][f_frak] = 0;
    FrakCarInfo[veh][f_Nitro] = 0;
    FrakCarInfo[veh][f_Hyd] = 0;
    FrakCarInfo[veh][f_Wheel] = 0;
    FrakCarInfo[veh][f_Ausp] = 0;
    FrakCarInfo[veh][f_SideL] = 0;
    FrakCarInfo[veh][f_SideR] = 0;
    FrakCarInfo[veh][f_FB] = 0;
    FrakCarInfo[veh][f_RB] = 0;
    FrakCarInfo[veh][f_Spoiler] = 0;
    FrakCarInfo[veh][f_Roof] = 0;
    FrakCarInfo[veh][f_Hood] = 0;
    FrakCarInfo[veh][f_Vents] = 0;
    FrakCarInfo[veh][f_Lamps] = 0;
    SendClientMessage(playerid,COLOR_GREEN,"[INFO] "COLOR_HEX_WHITE"Du hast das Fraktionsfahrzeug gelöscht.");
    return 1;
}

CMD:delallfcars(playerid,params[]) {
    new fraktion;
    if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
	if(sscanf(params,"i",fraktion)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/delallfcars [FraktionsID]");
    for(new veh; veh < MAX_VEHICLES; veh++) {
        if(fraktion == FrakCarInfo[veh][f_frak]) {
            new query[256];
            format(query,sizeof(query),"DELETE FROM `"#SERVERFRAKCARS_DB"` WHERE `id`='%i'",FrakCarInfo[veh][f_dbid]);
            mysql_tquery(gSQL,query);
            DestroyVehicle(veh);
            FrakCarInfo[veh][f_veh] = 65535;
            FrakCarInfo[veh][f_world] = 0;
            FrakCarInfo[veh][f_dbid] = 0;
            FrakCarInfo[veh][f_frak] = 0;
            FrakCarInfo[veh][f_Nitro] = 0;
            FrakCarInfo[veh][f_Hyd] = 0;
            FrakCarInfo[veh][f_Wheel] = 0;
            FrakCarInfo[veh][f_Ausp] = 0;
            FrakCarInfo[veh][f_SideL] = 0;
            FrakCarInfo[veh][f_SideR] = 0;
            FrakCarInfo[veh][f_FB] = 0;
            FrakCarInfo[veh][f_RB] = 0;
            FrakCarInfo[veh][f_Spoiler] = 0;
            FrakCarInfo[veh][f_Roof] = 0;
            FrakCarInfo[veh][f_Hood] = 0;
            FrakCarInfo[veh][f_Vents] = 0;
            FrakCarInfo[veh][f_Lamps] = 0;
        }
    }
    new string[128];
    format(string,sizeof(string),"[INFO] {FFFFFF}%s %s hat alle Fraktionsfahrzeuge der Fraktion %i gelöscht.", GetPlayerAdminRang(playerid), GetName(playerid),GetFactionNameOfFaction(fraktion));
    SendModMessage(COLOR_YELLOW, string);
    return 1;
}

CMD:fcarcolor(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    if(!IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug.");
	new c1,c2;
	if(sscanf(params,"ii",c1,c2)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/FCarcolor [Color 1] [Color 2]");
    new veh = GetPlayerVehicleID(playerid);
	if(FrakCarInfo[veh][f_dbid] != 0) {
		new query[256];
		format(query, sizeof(query), "UPDATE `"#SERVERFRAKCARS_DB"` SET c1 = '%i', c2 = '%i' WHERE `id` = '%i'",c1,c2, FrakCarInfo[veh][f_dbid]);
		mysql_tquery(gSQL,query);

  		ChangeVehicleColor(veh,c1,c2);

  		format(query,sizeof(query),"SELECT * FROM `"#SERVERFRAKCARS_DB"` WHERE `id`='%i'",FrakCarInfo[veh][f_dbid]);
  		DestroyVehicle(veh);
        mysql_tquery(gSQL, query, "Reload_FCars");
        
        SCMFormatted(playerid,COLOR_GREEN,"[INFO] "COLOR_HEX_WHITE"Du hast die Farben des Fahrzeuges auf die Color-IDs %d & %d geändert", c1, c2);
	}
	else {
	    return SendClientMessage(playerid,COLOR_RED,"Kein Fraktionsfahrzeug oder es existiert nicht in der Datenbank.");
	}
    return 1;
}

CMD:createfcar(playerid) {
	new string[256],i=1;
    if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    if(IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du darfst in keinem Fahrzeug sitzen!");
    for(;i<sizeof(factionNames);i++) {
    	if(strlen(string) == 0) { format(string,sizeof(string),"%s\n%s",factionNames[i]); }
 	        else{ format(string,sizeof(string),"%s\n%s",string,factionNames[i]); }
    }
    return ShowPlayerDialog(playerid,DIALOG_CREATE_FRAKCAR,DIALOG_STYLE_LIST,"Fraktionsauswahl",string,"Weiter","Abbrechen");
}

CMD:makeleader(playerid, params[]) {
    new pID, frakid, string[128], fname[50];
    if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "ui", pID, frakid))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Makeleader [SpielerID/Name] [Frak-ID]");
    if(!IsPlayerConnected(playerid))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    //if(Spieler[pID][pFraktion] > 0)return SendClientMessage(playerid, COLOR_RED, "* Der Spieler ist noch in einer Fraktion. Benutze erst /Afkick");
    if(Spieler[pID][pLevel] < 4 ) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst den Spieler nicht einladen, da er unter Level 4 ist!");
        return 1;
    }
    if(Spieler[pID][pFrakSperre]) {
        new String[128];
        format(String,sizeof(String),"%s hat versucht dich zum Leader zu machen. Du hast allerdings noch eine Fraktionssperre!",GetName(playerid));
        SendClientMessage(pID,COLOR_RED,String);
        format(String,sizeof(String),"Du kannst %s nicht zum Leader machen, da er noch eine Fraktions-Sperre hat!",GetName(pID));
        SendClientMessage(playerid,COLOR_RED,String);
        return 1;
    }
    if(frakid >= 1 || frakid <= 22) {
        ReturnFraktionByID(frakid, fname);
        Spieler[pID][pFraktion] = frakid;
        Spieler[pID][pRank] = 6;
        printf("%s %s hat Spieler %s zum Leader von %s gemacht. (FrakID %i)", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), fname, frakid);
        format(string, sizeof(string), "Du hast %s Leaderrechte der Fraktion \"%s\" gegeben.", GetName(pID), fname);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        SCMFormatted(pID, COLOR_LIGHTBLUE, "%s %s gab dir Leaderrechte für die Fraktion \"%s\" - Glückwunsch!", GetPlayerAdminRang(playerid), GetName(playerid), fname);
        SetPVarInt(pID, "SELECT.FRAK.SKIN", 1);
        //StartPlayerSkinSelection(pID);
        SendClientMessage(pID, COLOR_GREEN, "Wähle nun deinen Fraktionsskin!");
        new dialogstr[2056];
        if(Spieler[pID][pFraktion] == 0){
            for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 1){
            for (new i = 0, j = sizeof(skins_pd_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_pd_array[i]);
            }
        } else if(Spieler[playerid][pFraktion] == 2){
    		for (new i= 0, j = sizeof(skins_fbi_array); i < j; i++) {
      			format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_fbi_array[i]);
			}
		} else if(Spieler[pID][pFraktion] == 3){
            for (new i = 0, j = sizeof(skins_samd_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_samd_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 4){
            for (new i = 0, j = sizeof(skins_news_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_news_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 5){
            for (new i = 0, j = sizeof(skins_oamt_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_oamt_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 6){
            for (new i = 0, j = sizeof(skins_gsf_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_gsf_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 7){
            for (new i = 0, j = sizeof(skins_ballas_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_ballas_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 9){
            for (new i = 0, j = sizeof(skins_regierung_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_regierung_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 10){
            for (new i = 0, j = sizeof(skins_yakuza_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_yakuza_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 11){
            for (new i = 0, j = sizeof(skins_aztecas_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_aztecas_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 12){
            for (new i = 0, j = sizeof(skins_cali_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_cali_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 13){
            for (new i = 0, j = sizeof(skins_vagos_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_vagos_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 14){
            for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 15){
            for (new i = 0, j = sizeof(skins_nd_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_nd_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 19){
            for (new i = 0, j = sizeof(skins_terrorist_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_terrorist_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 20){
            for (new i = 0, j = sizeof(skins_lcn_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_lcn_array[i]);
            }
        } else if(Spieler[pID][pFraktion] == 21){
            for (new i = 0, j = sizeof(skins_triaden_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_triaden_array[i]);
            }
        } else if(Spieler[playerid][pFraktion] == 22){
                for (new i = 0, j = sizeof(skins_zollamt_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_zollamt_array[i]);
                }
            } else {
            for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
            }
        }
        ShowPlayerDialog(pID, DIALOG_SKINS_EINGELADEN, DIALOG_STYLE_PREVMODEL, "LyD - Fraktionsskin auswählen", dialogstr, "Ok", "Abbrechen");
        SaveAccount(pID);
    } else {
        SendClientMessage(playerid, COLOR_RED, "Die Fraktions-ID sollte zwischen 1 und 22 liegen.");
        return 1;
    }
    return 1;
}

CMD:setzoneowner(playerid, params[]) {
    new zoneid = -1;
    new owner[32];
    if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "is[32]", zoneid, owner)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /setzoneowner [Gangzone ID] [Fraktionsname]");
    if (zoneid < 0 || zoneid > MAX_GANGZONES) return SendClientMessage(playerid, COLOR_RED, "Keine gültige GangZone-ID.");
    if (g_GangZone[zoneid-1][GZ_iStatus] == 1) return SendClientMessage(playerid, COLOR_RED, "In dem Gebiet findet gerade ein Gangfight statt.");
    new factionID = GetGangFactionIDByName(owner);
    if (factionID == -1) return SendClientMessage(playerid, COLOR_RED, "Der Fraktionsname ist ungültig oder keine Gang.");
    g_GangZone[zoneid-1][GZ_iOwner] = factionID;
    new gangzoneLabel[200];
    if (IsDeagleZone(g_GangZone[zoneid-1][GZ_iID])) {
        format(gangzoneLabel, sizeof(gangzoneLabel), "{FFFFFF}[ {1E90FF}GANGFIGHT {FFFFFF}- {1E90FF}Deagle/Shotgun {FFFFFF}]\n{FFFFFF}Besitzer: {%s}%s\n{FFFFFF}Erobern mit: {1E90FF}/Gangfight\n\n{FFFFFF}({1E90FF}%d{FFFFFF})", GetFactionColor(g_GangZone[zoneid-1][GZ_iOwner]), GetFactionNameOfFaction(g_GangZone[zoneid-1][GZ_iOwner]), g_GangZone[zoneid-1][GZ_iID]);
    } else {
        format(gangzoneLabel, sizeof(gangzoneLabel), "{FFFFFF}[ {1E90FF}GANGFIGHT {FFFFFF}]\n{FFFFFF}Besitzer: {%s}%s\n{FFFFFF}Erobern mit: {1E90FF}/Gangfight\n\n{FFFFFF}({1E90FF}%d{FFFFFF})", GetFactionColor(g_GangZone[zoneid-1][GZ_iOwner]), GetFactionNameOfFaction(g_GangZone[zoneid-1][GZ_iOwner]), g_GangZone[zoneid-1][GZ_iID]);
    }
    UpdateDynamic3DTextLabelText(g_GangZone[zoneid-1][GZ_t3dLabel], 0x1E90FFFF, gangzoneLabel);
    SaveGangZones();
    new adminMessage[128], zoneText[MAX_ZONE_NAME];
    GetPoint2DZone(g_GangZone[zoneid-1][GZ_fIconX], g_GangZone[zoneid-1][GZ_fIconY], zoneText, sizeof(zoneText));
    format(adminMessage, sizeof(adminMessage), "%s %s hat das Gebiet in %s (%d) an die Fraktion %s übertragen.", GetPlayerAdminRang(playerid), GetName(playerid), zoneText, zoneid, owner);
    SendAdminMessage(COLOR_GREEN, adminMessage);
    return 1;
}

CMD:fsbreset(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    new fraktion;
    if (sscanf(params, "d", fraktion) || fraktion < 0 || fraktion > sizeof(factionNames)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Fsbreset [Fraktions-ID]");
    new frak_index = fraktion;
    if (frak_index == -1) return SCMFormatted(playerid, COLOR_RED, "[INFO] {FFFFFF}Die Fraktion %s besitzt keine Safebox.", GetFactionName(fraktion));
    g_fraktion[fraktion][Fr_FSDrogen] = 0;
    g_fraktion[fraktion][Fr_FSWaffenteile] = 0;
    g_fraktion[fraktion][Fr_FSWantedcodes] = 0;
    g_fraktion[fraktion][Fr_FSSpice] = 0;
    //g_fraktion[fraktion][Fr_FSKrauter] = 0;
    g_fraktion[fraktion][Fr_FSGangsamen] = 0;
    new message[145];
    format(message, sizeof(message), "%s %s hat die Safebox der Fraktion %s resettet.", GetPlayerAdminRang(playerid), GetName(playerid), GetFactionName(fraktion));
    SendAdminMessage(COLOR_YELLOW, message);
    return 1;
}