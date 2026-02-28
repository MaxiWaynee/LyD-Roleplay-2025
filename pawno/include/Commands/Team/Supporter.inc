#include <YSI\y_hooks>

// Supporter

CMD:goto(playerid, params[]) {
    new pID, string[128];
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Goto [SpielerID/Name]");
    new Float:x, Float:y, Float:z;
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (playerid == pID) return SendClientMessage(playerid, COLOR_RED, "Warum willst du dich zu dir selbst teleportieren?");
    if(GetPlayerState(pID) == PLAYER_STATE_SPECTATING)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist am spectaten.");
    GetPlayerPos(pID, x,y,z);
    new pVW, pInt;
    pVW = GetPlayerVirtualWorld(pID);
    pInt = GetPlayerInterior(pID);
    new vID = GetPlayerVehicleID(playerid);
    if(IsPlayerInAnyVehicle(playerid)) {
        foreach(new i : Player) {
            if(IsPlayerConnected(i) && gPlayerLogged[i]) {
                if(GetPlayerVehicleID(i) == vID) {
                    new Seat = GetPlayerVehicleSeat(i);
                    SetPlayerInterior(i, pInt);
                    SetPlayerVirtualWorld(i, pVW);
                    LinkVehicleToInterior(vID, pInt);
                    SetVehiclePos(vID, x,y,z);
                    SetVehicleVirtualWorld(vID, pVW);
                    PutPlayerInVehicle(i, vID, Seat);
                    if(IsTrailerAttachedToVehicle(vID)) {
                        new trID = GetVehicleTrailer(vID);
                        LinkVehicleToInterior(trID, pInt);
                        SetVehicleVirtualWorld(trID, pVW);
                        SetVehiclePos(trID, x,y,z);
                        AttachTrailerToVehicle(trID, vID);
                    }
                }
            }
        }
    } else {
        SetPlayerPos(playerid, x,y,z);
        SetPlayerInterior(playerid, pInt );
        SetPlayerVirtualWorld(playerid, pVW );
        Streamer_UpdateEx(playerid,x,y,z,pVW,pInt);
    }
    format(string, sizeof(string), "%s %s hat sich zu Spieler %s teleportiert.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID));
    SendAdminMessage(COLOR_BLUE, string);
    format(string, sizeof(string), "%s %s hat sich zu dir teleportiert.", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessage(pID, COLOR_DARKRED, string);
    return 1;
}



CMD:gethere(playerid, params[])
{
    new pID, string[128];
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Gethere [SpielerID/Name]");
    if (pID == INVALID_PLAYER_ID || !gPlayerLogged[pID]) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (pID == playerid) return SendClientMessage(playerid, COLOR_RED, "Warum willst du dich selbst zu dir teleportieren?");
    if(GetPlayerState(pID) == PLAYER_STATE_SPECTATING)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist am spectaten.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    new vID = GetPlayerVehicleID(pID);
    new pInt = GetPlayerInterior(playerid);
    new pVW = GetPlayerVirtualWorld(playerid);
    if(IsPlayerInAnyVehicle(pID)) {
        foreach(new i : Player) {
            if(IsPlayerConnected(i) && gPlayerLogged[i]) {
                if(GetPlayerVehicleID(i) == vID) {
                    new Seat = GetPlayerVehicleSeat(i);
                    SetPlayerInterior(i, pInt);
                    SetPlayerVirtualWorld(i, pVW);
                    LinkVehicleToInterior(vID, pInt);
                    SetVehiclePos(vID, x,y,z);
                    SetVehicleVirtualWorld(vID, pVW);
                    PutPlayerInVehicle(i, vID, Seat);
                    if(IsTrailerAttachedToVehicle(vID)) {
                        new trID = GetVehicleTrailer(vID);
                        LinkVehicleToInterior(trID, pInt);
                        SetVehicleVirtualWorld(trID, pVW);
                        SetVehiclePos(trID, x,y,z);
                        AttachTrailerToVehicle(trID, vID);
                    }
                }
            }
        }
    } else {
        SetPlayerPos(pID, x,y,z);
        SetPlayerInterior(pID, GetPlayerInterior(playerid));
        SetPlayerVirtualWorld(pID, GetPlayerVirtualWorld(playerid));
    }
    format(string, sizeof(string), "%s %s hat %s zu sich teleportiert.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID));
    SendAdminMessage(COLOR_BLUE, string);
    SCMFormatted(pID, COLOR_LIGHTGREY,"%s %s hat dich zu sich teleportiert.", GetPlayerAdminRang(playerid), GetName(playerid));
    return 1;
}



CMD:gotobiz(playerid,params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
	new BizID, string[128];
    if(sscanf(params,"i",BizID))return SendClientMessage(playerid, COLOR_RED, "* Benutze: /gotobiz [Biz ID]");
    new BizID2 = GetBizIndexByID(BizID);
    format(string, sizeof(string), "%s %s hat sich zu einem Biz (%d) teleportiert.", GetPlayerAdminRang(playerid), GetName(playerid), BizID);
    SendAdminMessage(COLOR_BLUE, string);
	SetPlayerPos(playerid,Biz[BizID2][EnterX],Biz[BizID2][EnterY],Biz[BizID2][EnterZ]);
	return 1;
}



CMD:gotopos(playerid, params[]) {
    new Float:x, Float:y, Float:z, string[128];
    if(sscanf(params, "fff", x,y,z))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Gotopos [Float-X] [Float-Y] [Float-Z]");
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    new vID = GetPlayerVehicleID(playerid);
    if(IsPlayerInAnyVehicle(playerid)) {
        foreach(new i : Player) {
            if(IsPlayerConnected(i) && gPlayerLogged[i]) {
                if(GetPlayerVehicleID(i) == vID) {
                    new Seat = GetPlayerVehicleSeat(i);
                    SetVehiclePos(vID, x,y,z);
                    PutPlayerInVehicle(i, vID, Seat);
                    if(IsTrailerAttachedToVehicle(vID)) {
                        new trID = GetVehicleTrailer(vID);
                        SetVehiclePos(trID, x,y,z);
                        AttachTrailerToVehicle(trID, vID);
                    }
                }
            }
        }
    } else {
        SetPlayerPos(playerid, x,y,z);
    }
    format(string, sizeof(string), "Du hast dich zur folgenden Koordinate teleportiert: %f, %f, %f", x,y,z);
    SendClientMessage(playerid, COLOR_GREEN, string);
    format(string, sizeof(string), "%s %s hat sich zur folgenden Koordinate teleportiert: %f, %f, %f", GetPlayerAdminRang(playerid),GetName(playerid), x,y,z);
    SendAdminMessage(COLOR_GREEN, string);
    return 1;
}



CMD:gotoliste(playerid)
{
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    if(Spieler[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_WHITE, ERROR_ADMIN);
    ShowPlayerDialog(playerid, DIALOG_NAVI, DIALOG_STYLE_LIST, "Navigation - Admin", "Ämter und Behörden\nPolizei u. Notdienste\nFahrschule\nFahrzeugverkauf\nCarSharing-Stationen\nHotel\nBanken\nVersicherungen\n24/7 Shops\nTankstellen\nKleidungsgeschäfte\nRestaurant\nCasinos\nWaffenverkauf\nVerkaufshäuser\nTuning-Garagen\nArbeitsstellen\nGang/Mafien Base\nIllegale Orte\nWeitere Orte\nNächster ATM", "Markieren", "Abbrechen");
    adminnavi[playerid] = true;
    return 1;
}



CMD:gotocar(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new vehicleid, message[128];
    if (sscanf(params, "i", vehicleid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Gotocar [Fahrzeug-ID]");
    if (!GetVehicleModel(vehicleid)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Keine gültige Fahrzeug-ID.");
    new Float:x, Float:y, Float:z, virtualworld;
    GetVehiclePos(vehicleid, x, y, z);
    virtualworld = GetVehicleVirtualWorld(vehicleid);
    SetPlayerPos(playerid, x, y, z + 3.0);
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, virtualworld);
    Streamer_UpdateEx(playerid, x, y, z, virtualworld, 0);
    format(message, sizeof(message), "%s %s hat sich zur Fahrzeug-ID %d teleportiert.", GetPlayerAdminRang(playerid), GetName(playerid), vehicleid);
    SendAdminMessage(COLOR_BLUE, message);
    return 1;
}



CMD:getcar(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new vehicleid, message[128];
    if (sscanf(params, "i", vehicleid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Getcar [Fahrzeug-ID]");
    if (!GetVehicleModel(vehicleid)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Keine gültige Fahrzeug-ID.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    SetVehiclePos(vehicleid, x, y, z);
    LinkVehicleToInterior(vehicleid, GetPlayerInterior(playerid));
    SetVehicleVirtualWorld(playerid, GetPlayerVirtualWorld(playerid));
    format(message, sizeof(message), "%s %s hat Fahrzeug-ID %d zu sich teleportiert.", GetPlayerAdminRang(playerid), GetName(playerid), vehicleid);
    SendAdminMessage(COLOR_BLUE, message);
    return 1;
}



CMD:spawncar(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new vehid;
    if (sscanf(params, "i", vehid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Spawncar [VehicleID]");
    if (!SetVehicleToRespawn(vehid)) return SendClientMessage(playerid, COLOR_RED, "Die Fahrzeug-ID gibt es nicht.");
    new message[128];
    format(message, sizeof(message), "%s %s hat ein Fahrzeug respawnt (CarID: %i)", GetPlayerAdminRang(playerid), GetName(playerid), vehid);
    SendAdminMessage(COLOR_YELLOW, message);
    return 1;
}



CMD:respawncar(playerid)
{
    if(Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new vID,string[128];
    vID = GetPlayerVehicleID(playerid);
    if(IsPlayerInAnyVehicle(playerid)) {
        SetVehicleToRespawn(vID);
        format(string,sizeof(string),"%s %s hat das Fahrzeug mit der ID: %i respawnt.",GetPlayerAdminRang(playerid),GetName(playerid),vID);
        SendAdminMessage(COLOR_YELLOW,string);
    } else {
        SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Fahrzeug.");
        return 1;
    }
    return 1;
}



CMD:rallcars(playerid, params[]) return cmd_respawnallcars(playerid, params);
CMD:respawnallcars(playerid, params[]) {
    new hour, minu, sec;
    gettime(hour, minu, sec);
    if (Spieler[playerid][pAdmin] < 3 && hour < 23 && hour > 9)
        return ERROR_RANG_MSG(playerid);
    else if (Spieler[playerid][pAdmin] < 1)
        return ERROR_RANG_MSG(playerid);

    new trailerid, bool:excludeVehicles[MAX_VEHICLES];
    for (new i = 0; i < sizeof(vehicle_truckerBase); i++)
        if (IsVehicleOccupied(vehicle_truckerBase[i]) && (trailerid = GetVehicleTrailer(vehicle_truckerBase[i]))) excludeVehicles[trailerid] = true;

    for (new i = 1; i < GetVehiclePoolSize(); i++)
        if (!IsVehicleOccupied(i) && !excludeVehicles[i])
            SetVehicleToRespawn(i);
    
    new String[128];
    format(String, sizeof(String), "%s %s hat alle unbesetzten Fahrzeuge zurückgespawnt.", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessageToAll(COLOR_YELLOW, String);
    return 1;
}



CMD:rjobcars(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new jobID;
    if (sscanf(params, "%i", jobID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Rjobcars [Job-ID]");
    if (!RespawnJobCars(jobID)) return SendClientMessage(playerid, COLOR_RED, "Keine gültige Job-ID oder der Job hat keine Fahrzeuge, siehe /Jobs.");
    new message[128];
    format(message, sizeof(message), "%s hat die Jobfahrzeuge des Jobs %s [ID: %i] respawnt." , GetName(playerid), jobNames[jobID], jobID);
    return SendAdminMessage(COLOR_YELLOW, message);
}



CMD:rfrakcars(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new factionID;
    if (sscanf(params, "%i", factionID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Rfrakcars [Fraktions-ID]");
    if (factionID < 1 || factionID > 22) return SendClientMessage(playerid, COLOR_ORANGE, "Keine gültige Fraktions-ID, siehe /Fraktionen.");
    for(new i=0;i<GetVehiclePoolSize();i++){
 		if(!IsValidVehicle(i)) continue;
 		if(FrakCarInfo[i][f_frak] != factionID) continue;
		if(!IsVehicleOccupied(i)){
		    if(!GetTowedCar(i)){
				SetVehicleToRespawn(i);
			}
		}
	}
    new message[128];
    format(message, sizeof(message), "%s hat die Fraktionsfahrzeuge der Fraktion %s [ID: %i] respawnt." , GetName(playerid), factionNames[factionID], factionID);
    return SendAdminMessage(COLOR_YELLOW, message);
}


CMD:slap(playerid, params[]) return cmd_aschlagen(playerid, params);
CMD:aschlagen(playerid,params[])
{
    new giveid,height;
    if(sscanf(params,"uD(5)",giveid,height)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Slap [Spieler] Optional: [Höhe]");
    if(Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    if( !IsPlayerConnected(giveid) ) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online.");
    if(height > 25)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Die Höhe darf nicht über 25 gehen.");
    new String[128], Float:X, Float:Y,  Float:Z;
    GetPlayerPos(giveid,X,Y,Z);
    SetPlayerPos(giveid,X,Y,Z + height);
    format(String,sizeof(String),"%s %s hat %s geschlagen. Höhe: %d", GetPlayerAdminRang(playerid), GetName(playerid),GetName(giveid), height);
    SendAdminMessage(COLOR_YELLOW, String);
    PlayerPlaySound(giveid,1190,0.0,0.0,0.0);
    return 1;
}



CMD:fraktionen(playerid) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new dialogText[512];
    for (new i = 0; i < sizeof(factionNames); i++) format(dialogText, sizeof(dialogText), "%sID: %i\t%s\n", dialogText, i, factionNames[i]);
	if(Spieler[playerid][pAdmin] < 3){
	    ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_LIST, "{FFFFFF}Fraktionsübersicht", dialogText, "", "Schließen");
	}else{
	    ShowPlayerDialog(playerid, DIALOG_FRAKTIONEN_LIST, DIALOG_STYLE_LIST, "{FFFFFF}Fraktionsübersicht", dialogText, "Setzen", "Schließen");
	}
	return 1;
}



CMD:jobs(playerid) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new dialogText[512];
    for (new i = 0; i < sizeof(jobNames); i++) format(dialogText, sizeof(dialogText), "%sID: %i\t%s\n", dialogText, i, jobNames[i]);
    if(Spieler[playerid][pAdmin] < 3){
		ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_LIST, "{FFFFFF}Jobübersicht", dialogText, "Setzen", "Schließen");
    }else{
        ShowPlayerDialog(playerid, DIALOG_JOB_LIST, DIALOG_STYLE_LIST, "{FFFFFF}Jobübersicht", dialogText, "Setzen", "Schließen");
	}
	return 1;
}



CMD:kick(playerid, params[]) {
    new pID, grund[64], string[128];
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "us[64]", pID, grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Kick [SpielerID/Name] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pAdmin] > 0 && Spieler[playerid][pAdmin] < 5)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Supporter bzw. Admins kicken.");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    mysql_real_escape_string(grund,grund);
    format(string, sizeof(string), "[KICK]: Spieler %s wurde von %s aus dem Server gekickt, Grund: %s", GetName(pID), GetName(playerid), grund);
    SendAdminMessage(COLOR_RED, string);
    format(string, sizeof(string), "[KICK] Du wurdest soeben von %s %s aus dem Server gekickt. Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), grund);
    SendClientMessage(pID, COLOR_RED, string);
    new String[256];
    format(String,sizeof(String),"Sie wurden aufgrund eines Regelverstoßes (oder einem anderen Grund) aus dem Server gekickt!\nSie wurdest vom %s %s aus dem Server gekickt!\nGrund: %s", GetPlayerAdminRang(playerid), GetName(playerid), grund);
    ShowPlayerDialog(pID,0,DIALOG_STYLE_MSGBOX,"Kick Information",String,"Exit","");
    KickDelay(pID);
    return 1;
}




CMD:ban(playerid, params[]) {
    new pID, grund[64], string[128], string1[128];
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "us[64]", pID, grund)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Ban [SpielerID/Name] [Grund]");
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (gPlayerLogged[playerid] != 1 && Spieler[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist noch nicht eingeloggt."); // Spieler nicht bannen wenn noch nicht eingeloggt?
    if (Spieler[pID][pAdmin] > 0) return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Supporter bzw. Admins bannen.");
    if (Spieler[pID][pLevel] > 6 && Spieler[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur Spieler von Level 1-6 bannen.");
    #if defined USE_NPCS
        if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    format(string, sizeof(string), "[BANNED]: Spieler %s wurde von %s %s dauerhaft aus dem Server gebannt, Grund: %s", GetName(pID), GetPlayerAdminRang(playerid), GetName(playerid), grund);
    SendAdminMessage(COLOR_RED, string);
    format(string, sizeof(string), "[BANNED] Du wurdest soeben von %s %s dauerhaft aus dem Server gebannt. Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), grund);
    SendClientMessage(pID, COLOR_RED, string);
    format(string1, sizeof(string1), "Sind Sie der Meinung das diese Sperre falsch war? Dann schreiben Sie auf www.LyD-Roleplay.de ein Entbannantrag!");
    SendClientMessage(pID, COLOR_RED, string1);
    //Ban(pID);
    mysql_real_escape_string(grund,grund);
    new query[256];
    format(query,sizeof(query),"UPDATE `accounts` SET `GebanntVon` = '%s' ,`BanGrund` = '%s' , `Banned` = 1 WHERE `Name` = '%s'",GetName(playerid),grund,GetName(pID));
    mysql_pquery(query,THREAD_BAN,pID,gSQL,MySQLThreadOwner);
    format(query,sizeof(query),"Gebannt: %s von: %s, Grund: %s, Dauer: %s",GetName(pID),GetName(playerid),grund,("Immer"));
    BanLog( query );
    format(query,sizeof(query),"%s wurde von %s %s dauerhaft gebannt, Grund: %s", GetName(pID), GetPlayerAdminRang(playerid), GetName(playerid), grund);
    SendUCPAktenEintrag( playerid,GetName(playerid) , GetName(pID) , query );
    new String[256];
    format(String,sizeof(String),"%s %s hat Spieler %s dauerhaft gebannt, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), grund);
    AdminLog(String);
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



CMD:spawn(playerid, params[]) {
    new pID, string[128];
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Spawn [SpielerID/Name] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pTot] == 1) {
        Spieler[pID][pTot] = 0;
        Spieler[pID][pTotTime] = 0;
    }
    SpawnPlayerEx(pID);
    SCMFormatted(pID, COLOR_LIGHTGREY, "Du wurdest von %s %s gespawnt!", GetPlayerAdminRang(playerid), GetName(playerid));
    format(string, sizeof(string), "* %s %s hat Spieler %s gespawnt.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID));
    SendAdminMessage(COLOR_YELLOW, string);
    return 1;
}



CMD:supcar(playerid, params[]) return cmd_supauto(playerid, "");
CMD:supauto(playerid, params[]) {
    new string[128];
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    new Float:x, Float:y, Float:z, Float:angle;
    GetPlayerFacingAngle(playerid, angle);
    GetPlayerPos(playerid, x,y,z);
    new vehicle;
    vehicle = CreateVehicle(560, x, y, z, angle, 3, 3, -1);
    SetVehicleNumberPlate(vehicle, "SUPPORT");
    SetVehicleVirtualWorld(vehicle, GetPlayerVirtualWorld(playerid));
    LinkVehicleToInterior(vehicle, GetPlayerInterior(playerid));
    PutPlayerInVehicle(playerid, vehicle, 0);
    gGas[vehicle] = GetMaxTank(vehicle);
    gMaxGas[vehicle] = GetMaxTank(vehicle);
    aiVehicles[ vehicle ] = VEH_SUPCAR;
    FrakCarInfo[vehicle][f_dbid] = 0;
    FrakCarInfo[vehicle][f_frak] = 0;
    format(string, sizeof(string), "%s %s hat einen Sultan gespawnt (CarID: 560)", GetPlayerAdminRang(playerid), GetName(playerid));
    SendAdminMessage(COLOR_BLUE, string);
    return 1;
}



CMD:check(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    new pID;
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Check [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    Stats(playerid, pID);
    return 1;
}



CMD:tickets(playerid, params[]) {
    new string[128], str2[2048];
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    new bool:IsOnline;
    foreach(new i : Player) {
        if(IsPlayerConnected(i) && gPlayerLogged[i] == 1) {
            if(PlayerNeedsHelp[i] == 1) {
                format(string, sizeof(string), "Name: %s (ID: %i) - Meldung: %s\n", GetName(i), i, SupText[i]);
                strcat(str2, string);
                IsOnline = true;
            }
        }
    }
    if(!IsOnline)return SendClientMessage(playerid, COLOR_RED, "Niemand hat ein Ticket geschrieben!");
    ShowPlayerDialog(playerid, DIALOG_TICKETS, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Ticket-Liste", str2, "Schließen", "");
    return 1;
}



CMD:closeticket(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Closeticket [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(ReportCall[playerid] == pID && ReportCall[pID] == playerid) {
        format(string, sizeof(string), "> Ticket < - %s hat dein Ticket geschlossen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTGREEN, string);
        format(string, sizeof(string), "> Ticket < - %s hat das Ticket von %s geschlossen.", GetName(playerid), GetName(pID));
        SendAdminMessage(COLOR_GREEN, string);
        ReportCall[playerid] = 999;
        ReportCall[pID] = 999;
        SaveReportData(pID,playerid);
        ShowPlayerDialog(pID,DIALOG_RATESUPPORTER,DIALOG_STYLE_MSGBOX,"Bewerte Supporter",
        "Wie hat Ihnen der Support gefallen? Wenn Ihnen die Auskunft geholfen hat, drücken Sie auf \"POSITIV\".\n\
        Wenn die Auskunft vom Supporter nicht hilfreich war, drücken Sie auf \"NEGATIV\".\n\
        Ihre Meinung ist uns wichtig!","Positiv","Negativ");
    } else {
        return SendClientMessage(playerid, COLOR_ORANGE, "Das Ticket von diesem Spieler wird derzeit bearbeitet oder das Ticket wurde noch nicht bearbeitet, oder es gibt keins!");
    }
    return 1;
}



CMD:delticket(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Delticket [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(PlayerNeedsHelp[pID] == 1) {
        PlayerNeedsHelp[pID] = 0;
        format(string, sizeof(string), "> Ticket < - %s hat dein Ticket gelöscht.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTGREEN, string);
        format(string, sizeof(string), "> Ticket < - %s hat das Ticket von %s gelöscht.", GetName(playerid), GetName(pID));
        SendAdminMessage(COLOR_ORANGE, string);
    }
    else {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat kein Ticket geschrieben.");
    }
    return 1;
}



CMD:dticket(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new pID, string[128];
    if(sscanf(params, "us[96]", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Dticket [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(PlayerNeedsHelp[pID] == 1) {
        PlayerNeedsHelp[pID] = 0;
        SendClientMessage(pID, COLOR_ORANGE, "[SUPPORT-TEAM]"COLOR_HEX_ORANGE" Wir haben Ihre Nachricht erhalten! Leider können Support Nachrichten");
        SendClientMessage(pID, COLOR_ORANGE, "[SUPPORT-TEAM]"COLOR_HEX_ORANGE" dieser Art nicht vom 'im Spiel'-Support beantwortet/geklärt werden oder");
        SendClientMessage(pID, COLOR_ORANGE, "[SUPPORT-TEAM]"COLOR_HEX_ORANGE" Sie haben Ihr Anliegen nicht direkt unter /SUP geschildert.");
        SendClientMessage(pID, COLOR_ORANGE, "[SUPPORT-TEAM]"COLOR_HEX_ORANGE" Wenden Sie sich bei einem Teammitglied im Teamspeak oder stellen Sie Ihre Anfrage im Forum.");
        ShowPlayerDialog(pID, DIALOG_SPAWNMELDUNG, DIALOG_STYLE_MSGBOX, "LyD", "Nachricht vom SUPPORT-TEAM:\n\nWir haben Ihre Nachricht erhalten! Leider können Support Nachrichten\ndieser Art nicht vom 'im Spiel'-Support beantwortet/geklärt werden!\nWenden Sie sich bei einem Teammitglied im Teamspeak oder stellen Sie Ihre Anfrage im Forum.\n\nForum Adresse: www.LyD-Roleplay.de\nTeamspeak Adresse: TS.LyD-Roleplay.de", "OK", "");
        format(string, sizeof(string), "> Ticket < - %s hat das Ticket von %s ermahnt und gelöscht.", GetName(playerid), GetName(pID));
        SendAdminMessage(COLOR_ORANGE, string);
    } else {
        SendClientMessage(playerid, COLOR_RED, "Der Spieler hat kein Ticket geschrieben.");
        return 1;
    }
    return 1;
}



CMD:aticket(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new pID, string[128];
    if(sscanf(params, "us[96]", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Aticket [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(PlayerNeedsHelp[pID] == 1) {
        PlayerNeedsHelp[pID] = 0;
        SendClientMessage(pID, COLOR_ORANGE, "[SUPPORT-TEAM]"COLOR_HEX_ORANGE" Deine Frage wurde schon einmal uns gestellt, weshalb wir die Antwort zu dieser wichtigen Frage");
        SendClientMessage(pID, COLOR_ORANGE, "[SUPPORT-TEAM]"COLOR_HEX_ORANGE" in unserer Hilfekonsole beantwortet haben. Uns erreichen täglich eine Vielzahl von Anfragen und Hilferufen,");
        SendClientMessage(pID, COLOR_ORANGE, "[SUPPORT-TEAM]"COLOR_HEX_ORANGE" weshalb wir nicht auf jede Fragestellung reagieren können. Um den Support etwas zu entlasten, wurde eine Hilfekonsole eingerichtet,");
        SendClientMessage(pID, COLOR_ORANGE, "[SUPPORT-TEAM]"COLOR_HEX_ORANGE" wo viele typsiche Fragen beantwortet sind. Befehl: /Help");
        new string1[256];
        new string2[256];
        new string3[256];
        new string4[768];
        format(string1, sizeof(string1), "Nachricht vom SUPPORT-TEAM:\n\nWir haben deine Nachricht erhalten!\nDeine Frage wurde schon einmal uns gestellt,");
        format(string2, sizeof(string2), " weshalb wir die Antwort zu\ndieser wichtigen Frage in unserer Hilfekonsole beantwortet haben. \nUns erreichen täglich eine Vielzahl von Anfragen");
        format(string3, sizeof(string3), " und Hilferufen,\nweshalb wir nicht auf jede Fragestellung reagieren können.\nUm den Support etwas zu entlasten, wurde eine Hilfekonsole eingerichtet,");
        format(string4, sizeof(string4), "\nwo viele typische Fragen beantwortet sind.\n\nBefehl: /Help\n\nForum Adresse: www.LyD-Roleplay.de\nTeamspeak Adresse: TS.LyD-Roleplay.de\nUser Panel: www.UCP.LyD-Roleplay.de");
        format(string4, sizeof(string4), "%s%s%s%s", string1, string2, string3, string4);
        ShowPlayerDialog(pID, DIALOG_SPAWNMELDUNG, DIALOG_STYLE_MSGBOX, "LyD", string4, "OK", "");
        format(string, sizeof(string), "> Ticket < - %s hat das Ticket von %s gelöscht und H. auf Hilfekonsole.", GetName(playerid), GetName(pID));
        SendAdminMessage(COLOR_ORANGE, string);
    } else {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat kein Ticket geschrieben.");
    }
    return 1;
}



CMD:gebannt(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    new Spielername[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",Spielername)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Gebannt [Spielername]");
    }
    mysql_real_escape_string(Spielername,Spielername);
    if(strcmp(Spielername,params)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Gebannt [Spielername (Keine Sonderzeichen)]");
    }
    new String[200];
    format(String,sizeof(String),"SELECT `Name`,`Banned`,`TimeBan`,FROM_UNIXTIME(`TimeBan`,'%%d.%%m.%%Y %%H:%%i'),`GebanntVon`,`BanGrund` FROM `accounts` WHERE `Name` = '%s' LIMIT 1",Spielername);
    mysql_pquery(String,THREAD_GEBANNT,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:gotohaus(playerid,params[] ){
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    new index,hausid;
    if(sscanf(params,"d",hausid)) return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Gotohaus [Hausnummer]");
    if( hausid < 1 || hausid > 10000 ) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Gotohaus [ID] ( 1 - 10000 )");
    for(new i ; i < MAX_HOUSES ; i++) {
        if( Haus[i][hID] == hausid ) {
            index = i;
            break;
        }
    }
    if( index == -1 ) return SendClientMessage(playerid,COLOR_RED,"Kein Haus mit der genannten ID gefunden");
    new String[128];
    format(String,sizeof(String),"%s %s hat sich zu Hausnummer: %d teleportiert.", GetPlayerAdminRang(playerid), GetName(playerid), hausid);
    SendAdminMessage(COLOR_BLUE,String);
    SetPlayerPos(playerid, Haus[index][EnterX], Haus[index][EnterY], Haus[index][EnterZ] + 0.5 );
    Streamer_Update(playerid);
    return 1;
}



CMD:delveh(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    new vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Du musst in dem Fahrzeug sitzen welches du löschen möchtest.");
    if( aiVehicles[ vehicleid ] != VEH_CAR && aiVehicles[ vehicleid ] != VEH_SUPCAR ) return SendClientMessage(playerid, COLOR_RED, "Dieses Fahrzeug wurde nicht per /Veh erstellt.");
    new String[100], driver = VehicleDriverID(vehicleid);
    if( IsPlayerConnected(driver) ) {
        RemovePlayerFromVehicle(driver);
        if(driver != playerid ) {
            SendClientMessage(driver,COLOR_RED,"Dein Fahrzeug wurde von einem Teammitglied gelöscht");
        }
    }
    format(String, sizeof(String), "%s %s hat ein Fahrzeug entfernt (CarID: %d)", GetPlayerAdminRang(playerid), GetName(playerid), vehicleid);
    SendAdminMessage(COLOR_YELLOW, String);
    DestroyVehicleEx(vehicleid);
    DestroyDynamicObject(vSirene[vehicleid]);
    aiVehicles[ vehicleid ] = VEH_INVALID;
    return 1;
}



/*CMD:ngeld(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new pID, money;
    if (sscanf(params, "ui", pID, money)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Ngeld [Spieler ID/Name] [$1 - $30.000]");
    if (!gPlayerLogged[pID]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht eingeloggt.");
    if (Spieler[pID][pLevel] > 3) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist über Level 3.");
    if (money < 1 || money > 30000) return SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Der Geldbetrag muss zwischen $1 und $30.000 liegen.");
    GivePlayerCash(pID, money);
    SCMFormatted(pID, COLOR_ORANGE, "%s %s hat dir einen Startbonus in Höhe von $%s gegeben.", GetPlayerAdminRang(playerid), GetName(playerid), AddDelimiters(money));
    new message[145];
    format(message, sizeof(message), "%s hat %s einen Startbonus in Höhe von $%s gegeben.", GetName(playerid), GetName(pID), AddDelimiters(money));
    SendAdminMessage(COLOR_ORANGE, message);
    return 1;
}*/



CMD:entwicklung(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(isnull(params)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Technikabteilung [Nachricht]");
    new String[256];
    mysql_real_escape_string(params,String,gWebSQL,sizeof(String) );
    format(String,sizeof(String),"INSERT INTO `notizen` (`admin`, `content`) VALUES ('%s', '%s')",GetName(playerid),String);
    mysql_pquery(String,THREAD_TECHNIKABTEILUNG,playerid,gWebSQL,MySQLThreadOwner);
    return 1;
}



CMD:checkscheine(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new pID;
    if (sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Checkscheine [SpielerID/Name]");
    if (IsPlayerConnected(pID) && gPlayerLogged[pID] == 1) {
        SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Du siehst dir die Scheine von %s an.", GetName(pID));
        Scheine(playerid, pID, 1);
    }

    return 1;
}



CMD:sichercode(playerid,params[]) {
    new giveid;
    if(Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Sichercode [ID/Name]");
    if( Spieler[giveid][pSecureCodeLevel] != -1 ) return SendClientMessage(playerid,COLOR_RED,"Der Spieler wird bereits nach seinem Sicherheitscode abgefragt");
    new String[128];
    format(String,sizeof(String),"[KONTROLLE] %s %s prüft den SicherheitsCode von Spieler %s", GetPlayerAdminRang(playerid), GetName(playerid),GetName(giveid));
    SendAdminMessage(COLOR_YELLOW, String);
    format(String,sizeof(String),"[KONTROLLE] %s %s möchte, dass du deinen SicherheitsCode zu identifizierung eingibst! Du hast 3 Versuche!", GetPlayerAdminRang(playerid), GetName(playerid), GetName(giveid));
    SendClientMessage(giveid,COLOR_RED, String);
    Spieler[giveid][pSecureCodeLevel] = 0;
    format(String,sizeof(String),"Ein %s möchte dich identifizieren.\n\nGib deinen SicherheitsCode ein ( %d/3 ):", GetPlayerAdminRang(playerid), Spieler[giveid][pSecureCodeLevel] + 1);
    ShowPlayerDialog(giveid, DIALOG_CHECK_SECURECODE , DIALOG_STYLE_INPUT , COLOR_HEX_LIGHTBLUE"Sicherheitscode:", String , "Absenden" , "");
    return 1;
}



CMD:freeze(playerid, params[]) {
    new pID, string[128];
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Freeze [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    FreezePlayer(pID);
    format(string, sizeof(string), "Du hast Spieler %s gefreezed.", GetName(pID));
    SendClientMessage(playerid, COLOR_ORANGE, string);
    format(string, sizeof(string), "%s %s hat Spieler %s gefreezed.",GetPlayerAdminRang(playerid),GetName(playerid), GetName(pID));
    SendAdminMessage(COLOR_YELLOW,string);
    return 1;
}



CMD:unfreeze(playerid, params[]) {
    new pID, string[128];
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Unfreeze [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    UnfreezePlayer(pID);
    Cuffed[pID] = 0;
    format(string, sizeof(string), "Du hast Spieler %s entfreezed.", GetName(pID));
    SendClientMessage(playerid, COLOR_GREEN, string);
    format(string, sizeof(string), "%s %s hat Spieler %s entfreezed.",GetPlayerAdminRang(playerid),GetName(playerid), GetName(pID));
    SendAdminMessage(COLOR_YELLOW,string);
    return 1;
}



CMD:setafk(playerid,params[])
{
    new pID;
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(sscanf(params,"u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Setafk [SpielerID]");
    if(Spieler[pID][pTot] == 1 || Spieler[pID][pTot] == 2 )return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist Tot.");
    if(IsAFK[pID] == 1)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist bereits im AFK-Modus.");
	if(Spieler[playerid][pAdmin] < 7 && Spieler[pID][pAdmin] > 7)//6
	    return SendClientMessage(playerid,COLOR_RED,"Du kannst diesen Befehl auf keinen Administrator nutzen welcher Projektverwaltung und höher ist!");
    IsAFK[pID] = 1;
    new string[200];
    format(string,200, "Du wurdest durch %s %s in den AFK-Modus versetzt. Dein PayDay läuft nun nicht mehr weiter.", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessage(pID, COLOR_ORANGE,string);
    format(string,200,"Du hast den Spieler %s erfolgreich in den AFK-Modus versetzt. Sein PayDay läuft nun nicht mehr weiter.",
    GetName(pID));
    SendClientMessage(playerid, COLOR_ORANGE, string);
    paydaywait[pID]=1;
    FreezePlayer(pID);
    UpdateDynamic3DTextLabelText(Spieler[pID][pAFKLabel], 0xC2A2DAFF, "Im AFK-Modus\nSeit 0 Sekunden");
    sAFKTimer[pID] = SetTimerEx("AFKTimer", 1000 ,false,"d",pID);
    Spieler[pID][unixAFKNotice] = gettime() + 5*60 ;
    return 1;
}



CMD:setback(playerid,params[])
{
    new pID;
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(sscanf(params,"u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Setback [SpielerID]");
    if(Spieler[pID][pTot] == 1 || Spieler[pID][pTot] == 2 )return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist Tot.");
    if(IsAFK[pID] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht im AFK-Modus.");
    IsAFK[pID] = 0;
    new string[200];
    format(string,200, "Du wurdest durch %s %s aus den AFK-Modus versetzt. Dein PayDay läuft nun weiter.", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessage(pID, COLOR_ORANGE,string);
    format(string,200,"Du hast den Spieler %s erfolgreich aus den AFK-Modus versetzt. Sein PayDay läuft nun weiter.",
    GetName(pID));
    SendClientMessage(playerid, COLOR_ORANGE, string);
    paydaywait[pID]=1;
    UnfreezePlayer(pID);
    KillTimer(sAFKTimer[pID]);
    pAFKTimer[pID] = 0;
    pAFKMinute[pID] = 0;
    UpdateDynamic3DTextLabelText(Spieler[pID][pAFKLabel], COLOR_PURPLE, " ");
    Spieler[pID][unixAFKNotice] = gettime() + 5*60 ;
    return 1;
}



CMD:guncheck(playerid, params[])
{
    new pID, string[128];
    if(Spieler[playerid][pAdmin] < 1)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Guncheck [SpielerID/Name]");
    new weapons[13][2];
    new wpName1[32], wpName2[32], wpName3[32], wpName4[32], wpName5[32], wpName6[32], wpName7[32];
    new wpName8[32], wpName9[32], wpName10[32], wpName11[32], wpName12[32], wpName13[32];
    for(new i=0;i<13;i++)
    {
        GetPlayerWeaponData(pID, i, weapons[i][0], weapons[i][1]);
    }
    GetWeaponNameEx(weapons[0][0], wpName1, 32);
    GetWeaponNameEx(weapons[1][0], wpName2, 32);
    GetWeaponNameEx(weapons[2][0], wpName3, 32);
    GetWeaponNameEx(weapons[3][0], wpName4, 32);
    GetWeaponNameEx(weapons[4][0], wpName5, 32);
    GetWeaponNameEx(weapons[5][0], wpName6, 32);
    GetWeaponNameEx(weapons[6][0], wpName7, 32);
    GetWeaponNameEx(weapons[7][0], wpName8, 32);
    GetWeaponNameEx(weapons[8][0], wpName9, 32);
    GetWeaponNameEx(weapons[9][0], wpName10, 32);
    GetWeaponNameEx(weapons[10][0], wpName11, 32);
    GetWeaponNameEx(weapons[11][0], wpName12, 32);
    GetWeaponNameEx(weapons[12][0], wpName13, 32);
    format(string, sizeof(string), "Waffen von "COLOR_HEX_BLUE"%s", GetName(pID));
    SendClientMessage(playerid, COLOR_WHITE, string);
    format(string, sizeof(string), "Waffen-Slot 1: %s [%d], Waffen-Slot 2: %s [%d], Waffen-Slot 3: %s [%d]", wpName1,weapons[0][1], wpName2,weapons[1][1], wpName3,weapons[2][1]);
    SendClientMessage(playerid, COLOR_LIGHTGREY, string);
    format(string, sizeof(string), "Waffen-Slot 4: %s [%d], Waffen-Slot 5: %s [%d], Waffen-Slot 6: %s [%d]", wpName4,weapons[3][1], wpName5,weapons[4][1], wpName6,weapons[5][1]);
    SendClientMessage(playerid, COLOR_LIGHTGREY, string);
    format(string, sizeof(string), "Waffen-Slot 7: %s [%d], Waffen-Slot 8: %s [%d], Waffen-Slot 9: %s [%d]", wpName7,weapons[6][1], wpName8,weapons[7][1], wpName9,weapons[8][1]);
    SendClientMessage(playerid, COLOR_LIGHTGREY, string);
    format(string, sizeof(string), "Waffen-Slot 10: %s[%d] , Waffen-Slot 11: %s [%d], Waffen-Slot 12: %s [%d]", wpName10,weapons[9][1], wpName11,weapons[10][1], wpName12,weapons[11][1]);
    SendClientMessage(playerid, COLOR_LIGHTGREY, string);
    format(string, sizeof(string), "Waffen-Slot 13: %s [%d]", wpName13,weapons[12][1]);
    SendClientMessage(playerid, COLOR_ORANGE, string);

    return 1;
}



CMD:regelwarnung(playerid, params[])
{
    if(Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new pID, string[128];
    if(sscanf(params, "us[96]", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Regelwarnung [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    {
        SendClientMessage(pID, COLOR_RED, "Nachricht vom MODERATOR:");
        SendClientMessage(pID, COLOR_ORANGE, "[ADMIN-TEAM]"COLOR_HEX_ORANGE" Deine Spielweise entspricht nicht den Regeln!");
        SendClientMessage(pID, COLOR_ORANGE, "[ADMIN-TEAM]"COLOR_HEX_ORANGE" Du stehst kurz davor wegen den Verstoß gegen die Regeln bestraft zu werden!");
        SendClientMessage(pID, COLOR_ORANGE, "[ADMIN-TEAM]"COLOR_HEX_ORANGE" Die Spielregeln findest du in unserem Forum unter 'Regeln'.");
        new string1[256];
        new string2[256];
        new string3[256];
        new string4[768];
        format(string1, sizeof(string1), "Nachricht vom MODERATOR:\n\nDeine Spielweise entspricht nicht den Regeln!\nDu stehst kurz davor wegen einem Regelverstoß bestraft zu werden.");
        format(string2, sizeof(string2), "\nWir fordern dich unverzüglich auf, deine Spielweise den Regeln anzupassen.\nAndernfalls musst du mit Sanktionen rechnen. Dies ist erstmals eine Ermahnung!");
        format(string3, sizeof(string3), "\nDie Spielregeln findest du in unserem Forum unter 'Regeln'.");
        format(string4, sizeof(string4), "\n\nForum Adresse: www.LyD-Roleplay.de\nTeamspeak Adresse: TS.LyD-Roleplay.de\nUser Panel: www.UCP.LyD-Roleplay.de");
        format(string4, sizeof(string4), "%s%s%s%s", string1, string2, string3, string4);
        ShowPlayerDialog(pID, DIALOG_SPAWNMELDUNG, DIALOG_STYLE_MSGBOX, "LyD", string4, "OK", "");
        format(string, sizeof(string), "%s %s hat Spieler %s auf seine negative Spielweise hingewiesen.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID));
        SendAdminMessage(COLOR_ORANGE, string);
    }
    return 1;
}



CMD:asettings(playerid) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    new dialogText[256];
    dialogText = "Einstellung\tStatus\n";
    for (new i = 0; i < sizeof(g_aSettings); i++)
        format(dialogText, sizeof(dialogText), "%s%s\t%s\n", dialogText, g_aSettings[i][ASETTING_NAME], g_aSettings[i][ASETTING_TOGGLE] ? "{00FF00}AN" : "{FF0000}AUS");
    
    ShowPlayerDialog(playerid, DIALOG_ASETTINGS, DIALOG_STYLE_TABLIST_HEADERS, "{FF9900}Admineinstellungen", dialogText, "Ändern", "Schließen");
    return 1;
}


CMD:admn(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1) return ERROR_RANG_MSG(playerid);
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    new text[96], pID, string[128];
    if(sscanf(params, "us[96]", pID, text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Admn [SpielerID/Name] [Nachricht]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[playerid][pAdmin] == 0) {
        if(Spieler[pID][pAdmin] < 1) {
            SendClientMessage(playerid, COLOR_RED, "Du kannst nur an Teammitgliedern schreiben.");
            return 1;
        }
    }
    format(string, sizeof(string), "[ADMIN] %s schrieb dir: %s", GetName(playerid), text);
    SendClientMessage(pID, COLOR_LIGHTRED, string);
    format(string, sizeof(string), "[ADMIN] %s schrieb zu %s: %s", GetName(playerid), GetName(pID), text);
    SendAdminMessage(COLOR_LIGHTRED, string);
    return 1;
}


CMD:aduty(playerid, params[]) return cmd_adienst(playerid);
CMD:adienst(playerid)
{
    new string[128];
    if(!(Spieler[playerid][pAdmin] >= 1)) return ERROR_RANG_MSG(playerid);
    {
        if(Spieler[playerid][pAdminDienst]==0)
        {
            if(Spieler[playerid][pAdmin] >= 1)SetPlayerColor(playerid, TEAM_SANI_COLOR);
            format(string, sizeof(string), "* %s arbeitet nun als %s im Dienst *", GetName(playerid), GetPlayerAdminRang(playerid));
            SendAdminMessage(COLOR_RED, string);
            Spieler[playerid][pAdminDienst] = 1;
        }
        else
        {
            if(Spieler[playerid][pAdmin] >= 1)SetPlayerColor(playerid, COLOR_WHITE);
            if (Spieler[playerid][pDuty] == 1) SetPlayerColor(playerid, COLOR_BLUE);
            format(string, sizeof(string), "* %s arbeitet nicht mehr als %s im Dienst *", GetName(playerid), GetPlayerAdminRang(playerid));
            SendAdminMessage(COLOR_RED, string);
            SetPlayerHealth(playerid, 100);
            Spieler[playerid][pAdminDienst] = 0;
        }
    }
    return 1;
}


CMD:ah(playerid) return cmd_adminhelp(playerid, "");
CMD:ahelp(playerid) return cmd_adminhelp(playerid, "");
CMD:adminhelp(playerid, params[]){
    new String[1024];
    if(Spieler[playerid][pFV] == 1) format(String, sizeof(String), "%s\nFraktionsverwalter Befehle\n", String);
    if(Spieler[playerid][pAdmin] > 0) format(String, sizeof(String), "%sSupporter Befehle", String);
    if(Spieler[playerid][pAdmin] > 1) format(String, sizeof(String), "%s\nEvent-Supporter Befehle", String);
    if(Spieler[playerid][pAdmin] > 2) format(String, sizeof(String), "%s\nModerator Befehle", String);
    if(Spieler[playerid][pAdmin] > 3) format(String, sizeof(String), "%s\nAdministrator Befehle", String);
    if(Spieler[playerid][pAdmin] > 3) format(String, sizeof(String), "%s\nProjektleitung Vertretung Befehle", String);
    if(Spieler[playerid][pAdmin] > 4) format(String, sizeof(String), "%s\nServer-Manager Befehle", String);
    if(Spieler[playerid][pAdmin] > 5) format(String, sizeof(String), "%s\nProjektleiter Befehle", String);

    ShowPlayerDialog(playerid, DIALOG_AHELP, DIALOG_STYLE_LIST, "Admin Help", String, "Öffnen", "Schließen");
    return 1;
}


CMD:sc(playerid, params[])
{
    new text[128];
    if(sscanf(params, "s[128]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Sc [Nachricht]");
    if(Spieler[playerid][pAdmin] > 0)
    {
        new string[144];
        format(string, sizeof(string), "( [SUPPORTER-CHAT] %s %s sagt: %s )", GetPlayerAdminRang(playerid), GetName(playerid), text);
        SendAdminMessage(COLOR_GREEN, string);
        format(string, sizeof(string), "Name: %s - %s", GetName(playerid), text);
        LogAdminChat(string);
    }else{
        ERROR_RANG_MSG(playerid);
    }
    return 1;
}

CMD:openticket(playerid, params[])
{
    new pID, string[128];
    if(Spieler[playerid][pAdmin] > 0)
    {
        if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Openticket [SpielerID/Name]");
        if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
        if(PlayerNeedsHelp[pID] == 1)
        {
            PlayerNeedsHelp[pID] = 0;
            format(string, sizeof(string), "> Ticket < - %s hat das Ticket von %s angenommen.", GetName(playerid), GetName(pID));
            SendAdminMessage(COLOR_LIGHTGREEN, string);
            SendClientMessage(playerid, COLOR_ORANGE, "Schreibe nun mit dem Spieler. Nutze dazu einfach den normalen Chat!");
            SendClientMessage(playerid, COLOR_ORANGE, "Du kannst das Ticket mit \"/closeticket [SpielerID/Name]\" schließen.");
            format(string, sizeof(string), "> Ticket < - Dein Ticket wurde von %s %s angenommen.", GetPlayerAdminRang(playerid), GetName(playerid));
            SendClientMessage(pID, COLOR_LIGHTGREEN, string);
            SendClientMessage(pID, COLOR_LIGHTGREEN, "Du kannst nun mit dem Teammitglied reden. Nutze dazu einfach den normalen Chat!");
            ReportCall[pID] = playerid;
            ReportCall[playerid] = pID;
        }
        else
        {
            if(Spieler[playerid][pAdmin] > 2){
                PlayerNeedsHelp[pID] = 0;
                format(string, sizeof(string), "> Ticket < - %s hat ein Ticket mit %s erstellt.", GetName(playerid), GetName(pID));
                SendAdminMessage(COLOR_LIGHTGREEN, string);
                SendClientMessage(playerid, COLOR_ORANGE, "Du kannst das Ticket mit \"/closeticket [SpielerID/Name]\" schließen.");
                format(string, sizeof(string), "> Ticket < - Teammitglied %s hat ein Ticket mit dir eröffnet.", GetName(playerid));
                SendClientMessage(pID, COLOR_LIGHTGREEN, string);
                SendClientMessage(pID, COLOR_LIGHTGREEN, "Du kannst mit dem Teammitglied reden. Nutze dazu einfach den normalen Chat!");
                ReportCall[pID] = playerid;
                ReportCall[playerid] = pID;
                return 1;
            }
            SendClientMessage(playerid, COLOR_RED, "Der Spieler hat kein Ticket geschrieben!");
        }
    }
    else
    {
        ERROR_RANG_MSG(playerid);
        return 1;
    }
    return 1;
}


CMD:mute(playerid, params[])
{
    new pID, grund[64], time, string[128];
    if(Spieler[playerid][pAdmin] < ADMIN_RANK_SUP) return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "uis[64]", pID, time, grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Mute [SpielerID/Name] [Zeit in Min.] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    format(string, sizeof(string), "%s wurde von %s für %d Minuten gemutet, Grund: %s", GetName(pID), GetName(playerid), time, grund);
    SendAdminMessage(COLOR_DARKRED, string);
    SCMFormatted(pID, COLOR_DARKRED, "Du wurdest von %s %s für %d Minuten gemuted, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), time, grund);
    SendClientMessage(pID, COLOR_WHITE, "Mit /mutetime kannst du sehen wielange du noch gemutet bist.");
    new rightTime = time*60;
    Spieler[pID][pMuteTime] = rightTime;
    Spieler[pID][pMuted] = 1;
    return 1;
}