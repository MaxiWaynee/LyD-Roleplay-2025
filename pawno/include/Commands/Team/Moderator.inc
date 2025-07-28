#include <YSI\y_hooks>

enum e_DetektivSkill {
    DS_iLevel,
    DS_iSec,
    DS_iPoints
}
new const g_DetektivSkill[][e_DetektivSkill] = {
    {1,80,0},
    {2,65,50},
    {3,40,150},
    {4,25,310},
    {5,10,540}
};



CMD:setkasse(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new money;
    if (sscanf(params, "i", money) || money < 1 || money > 1500000000) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Setkasse [$1-$1.500.000.000]");
    Kasse[Staat] = money;
    new message[144];
    format(message, sizeof(message), "%s %s hat die Staatskasse auf $%s gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), AddDelimiters(money));
    SendAdminMessage(COLOR_YELLOW, message);
    return 1;
}


CMD:vw(playerid) {
	if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
	new message[30];
	format(message, sizeof(message), "Virtual World: %i", GetPlayerVirtualWorld(playerid));
	return SendClientMessage(playerid, COLOR_WHITE, message);
}



CMD:setvw(playerid, params[]) {
    new pID,vID;
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "ui", pID,vID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Setvw [Name/ID] [VW-ID]");
    SetPlayerVirtualWorld(pID, vID);
    return 1;
}


CMD:adminwarnung(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new pID, string[128];
    if(sscanf(params, "us[96]", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Adminwarnung [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online."); {
        SendClientMessage(pID, COLOR_RED, "Nachricht vom MODERATOR:");
        SendClientMessage(pID, COLOR_ORANGE, "[ADMIN-TEAM]"COLOR_HEX_ORANGE" Wir haben Ihre Nachricht erhalten!");
        SendClientMessage(pID, COLOR_ORANGE, "[ADMIN-TEAM]"COLOR_HEX_ORANGE" Unsere eingerichtete Funktion '/Admin' dient nur für äußerst");
        SendClientMessage(pID, COLOR_ORANGE, "[ADMIN-TEAM]"COLOR_HEX_ORANGE" wichtigen Notfällen - Cheatermeldung, Melden von Regelverstößen und ähnlichem.");
        new string1[256];
        new string2[256];
        new string3[256];
        new string4[768];
        format(string1, sizeof(string1), "Nachricht vom MODERATOR:\n\nWir haben deine Meldung erhalten!\nBitte hab Verständnis dafür, dass der Befehl '/Admin' nur\n");
        format(string2, sizeof(string2), "für äußerst wichtige Notfälle dieser Art:\n\n- Cheatermeldung\n- Melden von Regelverstößen\n");
        format(string3, sizeof(string3), "- Melden von Spielfehlern\n\noder ähnlichem eingerichtet wurde.");
        format(string4, sizeof(string4), "\n\nForum Adresse: www.LyD-Roleplay.de\nTeamspeak Adresse: TS.LyD-Roleplay.de\nUser Panel: www.UCP.LyD-Roleplay.de");
        format(string4, sizeof(string4), "%s%s%s%s", string1, string2, string3, string4);
        ShowPlayerDialog(pID, DIALOG_SPAWNMELDUNG, DIALOG_STYLE_MSGBOX, "LyD", string4, "OK", "");
        format(string, sizeof(string), "%s %s hat Spieler %s wegen seinem Admin-Notruf ermahnt.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID));
        SendAdminMessage(COLOR_ORANGE, string);
    }
    return 1;
}


CMD:loadfrak(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3) return SendClientMessage(playerid,COLOR_RED,ERROR_ADMIN);
    ReloadFrak();
    return 1;
}


CMD:tban(playerid, params[]) {
    new pID, grund[64], time;
    if(sscanf(params, "uis[64]", pID, time, grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Tban [SpielerID/Name] [Zeit in Min.] [Grund]");
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pAdmin] > 0)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Supporter bzw. Admins bannen.");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    if(time < 1 || time > 14400)return SendClientMessage(playerid, COLOR_ORANGE, "Die Zeit sollte sich zwischen 1 und 14400 liegen. (1 Minute oder 10 Tage)");
    new tBanTime = time * 60;
    tBanTime = tBanTime + gettime();
    // -> THREADED
    mysql_real_escape_string(grund,grund);
    PlayerSQLExtra(playerid,params);
    new query[128];
    format(query, 128, "SELECT FROM_UNIXTIME(%d, '%s.%s.%s %s')", tBanTime, "%e", "%M", "%Y", "%T");
    mysql_pquery(query,THREAD_CONVERTUNIX,playerid,gSQL,MySQLThreadOwner);
    new String[256];
    format(String,sizeof(String),"[TIME-BAN] %s %s hat Spieler %s für %d Minuten gebannt, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), time, grund);
    AdminLog(String);
    return 1;
}



CMD:changeweather(playerid) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    ChangeWeather();
    new string[128];
    format(string, sizeof(string), "Wetter wurde geändert. (ID: %d)", CurWeather);
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}



CMD:setinterior(playerid, params[]) {
	new interior, pID;
	if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
	if(sscanf(params, "ui", pID,interior))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Setinterior [Spieler/ID] [Interior-ID]");
	SetPlayerInterior(pID,interior);
	SCMFormatted(playerid,COLOR_GREEN,"[INFO] {FFFFFF}Du hast von %s die Interior-ID auf %d geändert.",GetName(pID),interior);
	SCMFormatted(pID,COLOR_YELLOW,"[INFO] {FFFFFF}%s %s hat deine Interior-ID auf %d geändert.",GetPlayerAdminRang(playerid),GetName(playerid),interior);
	return 1;
}



CMD:bwstrafen(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    SetPVarInt(playerid, "BW.PAGE", 0);
    mysql_pquery("SELECT `Name`, `BWStrafe`, `BWStrafeGrund` FROM `accounts` WHERE `BWStrafe` > 0 ORDER BY `BWStrafe` DESC LIMIT 0,21", THREAD_BWSTRAFEN, playerid, gSQL,MySQLThreadOwner);
    return 1;
}



CMD:bwstrafe(playerid, params[]) {
    if (isnull(params) || Spieler[playerid][pAdmin] < 3) {
        if (Spieler[playerid][pSuspendedSentence] <= 0) SendClientMessage(playerid, COLOR_GREEN, "[INFO] {FFFFFF}Du hast keine Bewährungsstrafe.");
        else {
            SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Deine Bewährungsstrafe beträgt noch %i Spielstunden.", Spieler[playerid][pSuspendedSentence]);
            SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Grund: %s", Spieler[playerid][pSusSentenceReason]);
        }
        return 1;
    }
    new pID;
    if (sscanf(params, "u", pID) || pID == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht online.");
    if (Spieler[pID][pSuspendedSentence] <= 0) return SCMFormatted(playerid, COLOR_GREEN, "[INFO] {FFFFFF}%s hat keine Bewährungsstrafe.", GetName(pID));
    SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Die Bewährungsstrafe von %s beträgt noch %i Spielstunden.", GetName(pID), Spieler[pID][pSuspendedSentence]);
    SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Grund: %s", Spieler[pID][pSusSentenceReason]);
    return 1;
}



CMD:lastdamage(playerid, params[]) return cmd_lastdmg(playerid, params);
CMD:lastdmg(playerid, params[]) {
    new pID;
    if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    if (sscanf(params, "u", pID))
        return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Lastdmg [SpielerID/Name]");

    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler wurde nicht gefunden.");
    if (!GetPVarInt(pID, "DAMAGE.TIME")) return SCMFormatted(playerid, COLOR_ORANGE, "[DAMAGE] {FFFFFF}%s hat noch keinen Schaden von einem Spieler erhalten.", GetName(pID));

    new pName[MAX_PLAYER_NAME], sWeapon[32];
    GetWeaponNameEx(GetPVarInt(pID, "DAMAGE.WEAPON"), sWeapon, sizeof(sWeapon));
    GetPVarString(pID, "DAMAGE.NAME", pName, sizeof(pName));
    if (isnull(sWeapon)) sWeapon = "Fist";
    return SCMFormatted(playerid, COLOR_ORANGE, "[DAMAGE] {FFFFFF}%s hat zuletzt von %s %.0f Schaden erhalten, vor %i Sekunden (Waffe: %s).", GetName(pID),\
        pName, GetPVarFloat(pID, "DAMAGE.AMOUNT"), gettime() - GetPVarInt(pID, "DAMAGE.TIME"), sWeapon);
}


ocmd:flip(playerid,params[])//@Sascha
{
    if(!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_WHITE, ERROR_LOGGED);
	if(Spieler[playerid][pAdmin] < 3)return SendClientMessage(playerid, COLOR_WHITE, ERROR_ADMIN);
	new vehicleid = GetPlayerVehicleID(playerid);
    if (!vehicleid) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist in keinem Fahrzeug.");
	if(IsPlayerInAnyVehicle(playerid)) {
		new Float:x, Float:y, Float:z, Float:za, aid = GetPlayerVehicleID(playerid);
		GetVehiclePos(aid, x, y, z); GetVehicleZAngle(aid, za);
		SetVehiclePos(aid, x, y, z); SetVehicleZAngle(aid, za);
		new string[256];
    	format(string, sizeof(string),"%s hat sein Fahrzeug via /flip gedreht.",GetName(playerid));
    	SendModMessage(COLOR_YELLOW ,string);
	}
	return 1;
}

CMD:configplayer(playerid, params[]) {
    new pID, string[140], entry[32], wert, avalstr[32];
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "us[32]i", pID, entry, wert)) {
        if (sscanf(params, "us[32]s[32]", pID, entry, avalstr)) return ShowConfigPlayerInfo(playerid);
        if (!strcmp(entry, "fraktion", true)) {
            wert = GetFactionIDByName(avalstr);
            if (wert == -1) return SendClientMessage(playerid, COLOR_ORANGE, "* Die Fraktion konnte nicht gefunden werden.");
        }
        else if (!strcmp(entry, "job", true)) {
            wert = GetJobIDByName(avalstr);
            if (wert == -1) return SendClientMessage(playerid, COLOR_ORANGE, "* Der Job konnte nicht gefunden werden.");
        }
        else return ShowConfigPlayerInfo(playerid);
    }
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler nicht online.");
    // >= Developer
    if (Spieler[playerid][pAdmin] > 4) {
        if (!strcmp(entry, "adventmin", true)) {
            if (wert < 0) return SendClientMessage(playerid, COLOR_RED, "Gebe einen positiven Wert an.");
            Spieler[pID][pAdventMin] = wert;
            SCMFormatted(pID, COLOR_LIGHTBLUE, "Deine Adventminuten wurden von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
            SCMFormatted(playerid, COLOR_LIGHTBLUE, "Du hast die Adventminuten von %s auf %d gesetzt.", GetName(pID), wert);
            return 1;
        }
        else if (!strcmp(entry, "adventday", true)) {
            if (wert < 1 || wert > 31) return SendClientMessage(playerid, COLOR_RED, "Gebe einen Wert von 1-31 an.");
            Spieler[pID][pAdventDay] = wert;
            SCMFormatted(pID, COLOR_LIGHTBLUE, "Dein Adventstag wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
            SCMFormatted(playerid, COLOR_LIGHTBLUE, "Du hast den Adventstag von %s auf %d gesetzt.", GetName(pID), wert);
            return 1;
        }
    }

    // >= Administrator
    /*if (Spieler[playerid][pAdmin] > 3) {
        if (!strcmp(entry, "mustuseac", true)) {
            if (wert <= 0 && wert >= 1) return SendClientMessage(playerid, COLOR_RED, "Gebe entweder 0 für Aus oder 1 für An ein.");
            Spieler[pID][pMustUseAC] = wert;
            if (Spieler[pID][pMustUseAC]) {
                SCMFormatted(pID, COLOR_RED, "%s %s hat dir eine Anti-Cheat Pflicht verhängt.", GetPlayerAdminRang(playerid), GetName(playerid));
                SCMFormatted(playerid, COLOR_LIGHTBLUE, "Du hast dem Spieler %s eine Anti-Cheat Pflicht verhängt.", GetName(pID));
                if (!CAC_GetStatus(pID)) {
                    SendClientMessage(pID, COLOR_RED, "Lade den Anti-Cheat im Forum herunter, um weiterspielen zu können.");
                    AC_kick(pID, "Anti-Cheat Client Pflicht");
                }
            } else {
                SCMFormatted(pID, COLOR_RED, "%s %s hat deine Anti-Cheat Pflicht aufgehoben.", GetPlayerAdminRang(playerid), GetName(playerid));
                SendClientMessage(pID, COLOR_RED, "Du kannst nun wieder ohne Anti-Cheat spielen, sofern du nicht in einer Fraktion mit einer AC-Pflicht bist.");
                SCMFormatted(playerid, COLOR_LIGHTBLUE, "Du hast dem Spieler %s seine Anti-Cheat Pflicht aufgehoben.", GetName(pID));
            }

            return 1;
        }
    }*/

    // >= Moderator
    if(strcmp(entry, "eventpunkte", true) == 0) {
        Spieler[pID][pEventPoints] = wert;
        format(string, sizeof(string), "Deine Eventpunkte wurden von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Eventpunkte von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Eventpunkte von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string, sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "level", true) == 0) {
        if(wert < 1 || wert > 100)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 100 liegen.");
        Spieler[pID][pLevel] = wert;
        SetPlayerScore(pID, wert);
        format(string, sizeof(string), "Dein Level wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast das Level von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Level von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "gehalt", true) == 0) {
        if(wert < 0 || wert > 100000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 100.000 liegen.");
        Spieler[pID][pPayCheck] = wert;
        format(string, sizeof(string), "Dein Gehalt wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast das Gehalt von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Gehalt von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "respektpunkte", true) == 0) {
        if(wert < 0 || wert > 1000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 1.000 liegen.");
        Spieler[pID][pExp] = wert;
        format(string, sizeof(string), "Deine Respektpunkte wurden von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Respektpunkte von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Respekt von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        if (Spieler[pID][pExp] >= Spieler[pID][pLevel] * 4) {
            Spieler[pID][pLevel]++;
            SetPlayerScore(pID, Spieler[pID][pLevel]);
            Spieler[pID][pExp] = 0;
            GameTextForPlayer(pID, "~y~Level UP", 4000, 3);
        }

        return 1;
    }
    else if(strcmp(entry, "fraktionsrank", true) == 0)
    {
        if(wert < 0 || wert > 6)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 6 liegen.");
        Spieler[pID][pRank] = wert;
        format(string, sizeof(string), "Dein Fraktionsrank wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Fraktionsrank von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Fraktionsrank von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "fraktion", true) == 0) {
        if(wert < 0 || wert > 22) return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 22 liegen.");
        Spieler[pID][pFraktion] = wert;
        if (wert == 15) AddPlayerToPlantArrayData(pID);
        if( IsAFightFaction( Spieler[pID][pFraktion] ) ) AddPlayerToPlantArrayDataGang(pID);
        else RemovePlayerFromPlantArrayData(pID);
        format(string, sizeof(string), "Deine Fraktion wurde von %s %s auf %s gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), factionNames[wert]);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Fraktion von %s auf %s [%d] gesetzt.", GetName(pID), factionNames[wert], wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Fraktion von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "job", true) == 0) {
        if(wert < 0 || wert > 24)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 24 liegen.");
        Spieler[pID][pJob] = wert;
        format(string, sizeof(string), "Dein Job wurde von %s %s auf %s gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), jobNames[wert]);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Job von %s auf %s [%d] gesetzt.", GetName(pID), jobNames[wert], wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändern Job von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "skin", true) == 0) {
        if(wert < 0 || wert > 311)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 311 liegen.");
        SetPlayerSkinEx(pID, wert);
        format(string, sizeof(string), "Dein Skin wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Skin von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Skin von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "spielstunden", true) == 0) {
        if(wert < 0 || wert > 10000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 10.000 liegen.");
        Spieler[pID][pHours] = wert;
        format(string, sizeof(string), "Dein Spielstunden wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Spielstunden von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s setzt Spielstunden von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "geld", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        SetPlayerCash(pID, wert);
        format(string, sizeof(string), "Dein Geld wurde von %s %s auf $%s gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), AddDelimiters(wert));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast das Geld von %s auf $%s gesetzt.", GetName(pID), AddDelimiters(wert));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Geld von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "drogen", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pDrugs] = wert;
        format(string, sizeof(string), "Dein Drogenbestand wurde von %s %s auf %d Stk gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Drogenbestand von %s auf %d Stk gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Drogenbestand von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "waffenteile", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pWaffenteile] = wert;
        format(string, sizeof(string), "Dein Bestand an Waffenteilen wurde von %s %s auf %d Stk gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Waffenteile Bestand von %s auf %d Stk gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Matsbestand von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "spice", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pSpice] = wert;
        //if(CheckPlayerSpice(pID,wert)) return SendClientMessage(pID, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst nur maximal 3.000 Gramm Spice besitzen!");
        format(string, sizeof(string), "Dein Spicebestand wurde von %s %s auf %d Stk gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Spicebestand von %s auf %d Stk gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Spicebestand von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "bankkonto", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pBank] = wert;
        format(string, sizeof(string), "Dein Geld auf der Bank wurde von %s %s auf $%s gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), AddDelimiters(wert));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast das Geld von %s Bankkonto auf $%s gesetzt.", GetName(pID), AddDelimiters(wert));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Geld auf Bankkonto von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "kekse", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pKekse] = wert;
        format(string, sizeof(string), "Dein Bestand an Keksen wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Bestand an Keksen von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Bestand an Keksen von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "pfand", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pPfand] = wert;
        format(string, sizeof(string), "Dein Bestand an Pfandflaschen wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Bestand an Pfandflaschen von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Bestand an Pfandflaschen von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "wantedcodes", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pWantedCodes] = wert;
        format(string, sizeof(string), "Deine Wantedcodes wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Wantedcodes von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Bestand an Wantedcodes von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "safewantedcodes", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pSafeWantedCodes] = wert;
        format(string, sizeof(string), "Deine Wantedcodes in der Safebox wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Wantedcodes in der Safebox von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Bestand an Wantedcodes in Safebox von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "alizsperre", true) == 0) {
        if(wert < 0 || wert > 10000000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 10.000.000 liegen.");
        Spieler[pID][punixFSperre] = wert;
        format(string, sizeof(string), "Deine Auto-Lizenzsperre wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Auto-Lizenzsperre von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "mlizsperre", true) == 0) {
        if(wert < 0 || wert > 10000000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 10.000.000 liegen.");
        Spieler[pID][punixMotoSperre] = wert;
        format(string, sizeof(string), "Deine Motorrad-Lizenzsperre wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Motorrad-Lizenzsperre von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "flizsperre", true) == 0) {
        if(wert < 0 || wert > 10000000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 10.000.000 liegen.");
        Spieler[pID][punixFlSperre] = wert;
        format(string, sizeof(string), "Deine Flug-Lizenzsperre wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Flug-Lizenzsperre von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "glizsperre", true) == 0) {
        if(wert < 0 || wert > 10000000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 10.000.000 liegen.");
        Spieler[pID][punixGunSperre] = wert;
        format(string, sizeof(string), "Deine Waffen-Lizenzsperre wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Waffen-Lizenzsperre von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "lkwlizsperre", true) == 0) {
        if(wert < 0 || wert > 10000000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 0 und 10.000.000 liegen.");
        Spieler[pID][punixLKWSperre] = wert;
        format(string, sizeof(string), "Deine LKW-Lizenzsperre wurde von %s %s auf %d gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die LKW-Lizenzsperre von %s auf %d gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "geschlecht", true) == 0) {
        if(wert < 0 || wert > 2)return SendClientMessage(playerid, COLOR_ORANGE, "Wert zwischen 1 bis 2! 1 = Männlich, 2 = Weiblich");
        Spieler[pID][pSex] = wert;
        format(string, sizeof(string), "Dein Geschlecht wurde von %s %s geändert.", GetPlayerAdminRang(playerid), GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast das Geschlecht von %s geändert.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Geschlecht von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "bankpin", true) == 0) {
        if(wert < 0 || wert > 1)return SendClientMessage(playerid, COLOR_ORANGE, "Wert zwischen 0 bis 1! 0 = BankPIN reset, 1 = Bankkonto sperren");
        Spieler[pID][pBankKontoPin] = wert;
        format(string, sizeof(string), "Deine Bankpin wurde von %s %s resettet.", GetPlayerAdminRang(playerid), GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Bankpin von %s resettet.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s reset Bankpin von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "safedrogen", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pSafeDrogen] = wert;
        format(string, sizeof(string), "Dein Drogenbestand in der Safebox wurde von %s %s auf %d Stk gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Safebox Drogenbestand von %s auf %d Stk gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Safebox Drogenbestand von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "safespice", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pSafeSpice] = wert;
        //if(CheckPlayerSpice(pID,wert)) return SendClientMessage(pID, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler kann maximal 3.000 Gramm Spice besitzen!");
        format(string, sizeof(string), "Dein Spicebestand in der Safebox wurde von %s %s auf %d Stk gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Safebox Spicebestand von %s auf %d Stk gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Safebox Spicebestand von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "safewaffenteile", true) == 0) {
        if(wert > 999999999)return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert sollte zwischen 1 und 999.999.999 liegen.");
        Spieler[pID][pSafeTeile] = wert;
        format(string, sizeof(string), "Dein Bestand an Waffenteilen in der Safebox wurde von %s %s auf %d Stk gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Safebox Waffenteilenbestand von %s auf %d Stk gesetzt.", GetName(pID), wert);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert Safebox Waffenteilenbestand von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "premium", true) == 0) {
        if(wert < 0 || wert > 1)return SendClientMessage(playerid, COLOR_ORANGE, "Wert zwischen 0 bis 1! 0 = Keine Club, 1 = Clubstatus");
        Spieler[pID][pDonateRank] = wert;
        format(string, sizeof(string), "Dein Clubstatus wurde durch %s %s geändert.", GetPlayerAdminRang(playerid), GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Clubstatus von Spieler %s geändert.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert den Premiumstatus von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "waffensperre", true) == 0) {
        if(wert < 0 || wert > 10000000)return SendClientMessage(playerid, COLOR_ORANGE, "Wert zwischen 0 bis 1! 0 = Entziehen, 1 = NICHTS");
        Spieler[pID][pWaffenSperre] = wert;
        format(string, sizeof(string), "Dein Waffensperre wurde durch %s %s geändert.", GetPlayerAdminRang(playerid), GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die Waffensperre von Spieler %s geändert.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert den Status der Waffensperre von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if(strcmp(entry, "neonpremium", true) == 0) {
        if(wert < 0 || wert > 1)return SendClientMessage(playerid, COLOR_ORANGE, "Wert zwischen 0 bis 1! 0 = Kein Neon Premium, 1 = Neon Premium");
        Spieler[pID][pPremiumNeon] = wert;
        format(string, sizeof(string), "Dein Neon-Premium wurde durch %s %s geändert.", GetPlayerAdminRang(playerid), GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast den Neon-Premium von Spieler %s geändert.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        printf("%s ändert den Neon Premium von %s in %d", GetName(playerid), GetName(pID), wert);
        format(string,sizeof(string),"%s %s hat die Daten von Spieler %s überarbeitet! ( [%s gesetzt auf: %d] )", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), entry, wert);
        AdminLog(string);
        return 1;
    }
    else if (!strcmp(entry, "payday", true) && Spieler[playerid][pAdmin] >= 5) {
        if (wert < 0 || wert > 59) return SendClientMessage(playerid, COLOR_ORANGE, "Der Wert muss zwischen 0 und 59 liegen.");
        Spieler[pID][pPayDay] = wert;
        format(string, sizeof(string), "Deine PayDay-Zeit wurde von %s %s auf %i Minuten geändert.", GetPlayerAdminRang(playerid), GetName(playerid), wert);
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "Du hast die PayDay-Zeit von Spieler %s auf %i Minuten geändert.", GetName(pID), wert);
        UpdatePayDayTextdraw(pID);
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    }
    SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Configplayer [SpielerID/Name] [Eingabe] [Wert]");
    SendClientMessage(playerid, COLOR_ORANGE, "* EINGABEN *: Level, Respektpunkte, Geld, Job, Fraktion, Fraktionsrank, Gehalt, NeonPremium, Spice, Drogen,");
    SendClientMessage(playerid, COLOR_ORANGE, "* EINGABEN *: Safewantedcodes, Waffenteile, Wantedcodes, SafeSpice, SafeDrogen, SafeWaffenteile, Waffensperre");
    SendClientMessage(playerid, COLOR_ORANGE, "* EINGABEN *: Bankpin, Bankkonto, Skin, Geschlecht, Premium, Spielstunden, Kekse");
    SendClientMessage(playerid, COLOR_ORANGE, "* EINGABEN *: Alizsperre, Flizsperre, Glizsperre, Lkwlizsperre, Mlizsperre, Eventpunkte");
    return 1;
}



CMD:fallover(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new nr;
    if(sscanf(params, "i", nr))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Fallover [1-5]");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausführen während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausführen.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausführen.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausführen.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausführen, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausführen.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausführen.");
    if(nr > 5 || nr < 1)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Fallover [1-5]");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    if(nr == 1) {
        ApplyAnimation(playerid,"PED", "KO_shot_stom", 4.0, 0, 1, 1, 1, 0, 1);
    }
    else if(nr == 2) {
        ApplyAnimation(playerid,"PED", "BIKE_fallR", 4.1, 0, 1, 1, 1, 0, 1);
    }
    else if(nr == 3) {
        ApplyAnimation(playerid,"PED", "BIKE_fall_off", 4.1, 0, 1, 1, 1, 0, 1);
    }
    else if(nr == 4) {
        ApplyAnimation(playerid,"PED","getup",4.0,0,0,0,0,0);
    }
    else if(nr == 5) {
        ApplyAnimation(playerid, "PARACHUTE", "FALL_skyDive_DIE", 4.0, 0, 1, 1, 1, -1);
    }
    return 1;
}




CMD:givecar(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new pID, vID, color1, color2, neon, stuned;
    if(sscanf(params, "uiiiii", pID, vID, color1, color2, neon, stuned)){SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Givecar [SpielerID/Name] [Vehicle-ID] [Color-1] [Color-2] [Neon] [Special-Tuned]"); SendClientMessage(playerid, COLOR_ORANGE, "Neon-Farben: 0 = Keins, 1 = Blau, 2 = Rot, 3 = Grün, 4 = Weiß, 5 = Pink, 6 = Gelb"); SendClientMessage(playerid, COLOR_ORANGE, "Special-Tuned Typen: 1 = Infernus-Tuned"); return 1;}
    if (vID > 611 || vID < 400) return SendClientMessage(playerid, COLOR_RED, "Die Fahrzeug ID muss zwischen 400 und 611 liegen.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    if(!PlayerHaveCar[pID][PlayerKey[pID]]) {
        CreatePlayerCar(pID,x,y,z,0.0,vID,color1,color2);
        PlayerCar[pID][PlayerKey[pID]][Id]=0;
        PlayerCar[pID][PlayerKey[pID]][CarId]=0;
        PlayerCar[pID][PlayerKey[pID]][CarOwner]=GetName(pID);
        PlayerCar[pID][PlayerKey[pID]][CarModel]=vID;
        PlayerCar[pID][PlayerKey[pID]][CarPos_x]=x;
        PlayerCar[pID][PlayerKey[pID]][CarPos_y]=y;
        PlayerCar[pID][PlayerKey[pID]][CarPos_z]=z;
        PlayerCar[pID][PlayerKey[pID]][CarRotate]=0.0;
        PlayerCar[pID][PlayerKey[pID]][CarNitro]=0;
        PlayerCar[pID][PlayerKey[pID]][CarHyd]=0;
        PlayerCar[pID][PlayerKey[pID]][CarWheel]=0;
        PlayerCar[pID][PlayerKey[pID]][CarAusp]=0;
        PlayerCar[pID][PlayerKey[pID]][CarSideL]=0;
        PlayerCar[pID][PlayerKey[pID]][CarSideR]=0;
        PlayerCar[pID][PlayerKey[pID]][CarFB]=0;
        PlayerCar[pID][PlayerKey[pID]][CarRB]=0;
        PlayerCar[pID][PlayerKey[pID]][CarSpoiler]=0;
        PlayerCar[pID][PlayerKey[pID]][CarRoof]=0;
        PlayerCar[pID][PlayerKey[pID]][CarHood]=0;
        PlayerCar[pID][PlayerKey[pID]][CarVents]=0;
        PlayerCar[pID][PlayerKey[pID]][CarLamps]=0;
        PlayerCar[pID][PlayerKey[pID]][CarPJ]=-1;
        PlayerCar[pID][PlayerKey[pID]][CarC1]=color1;
        PlayerCar[pID][PlayerKey[pID]][CarC2]=color2;
        PlayerCar[pID][PlayerKey[pID]][CarPreis]=0;
        PlayerCar[pID][PlayerKey[pID]][CarState]=0;
        format(PlayerCar[pID][PlayerKey[pID]][CarNumberplate] ,32, KEIN_KENNZEICHEN );
        PlayerCar[pID][PlayerKey[pID]][CarId] = CreateVehicle(PlayerCar[pID][PlayerKey[pID]][CarModel],PlayerCar[pID][PlayerKey[pID]][CarPos_x],PlayerCar[pID][PlayerKey[pID]][CarPos_y],PlayerCar[pID][PlayerKey[pID]][CarPos_z],PlayerCar[pID][PlayerKey[pID]][CarRotate],PlayerCar[pID][PlayerKey[pID]][CarC1],PlayerCar[pID][PlayerKey[pID]][CarC2], -1);/*vehicle spawn*/
        aiVehicles[ PlayerCar[pID][PlayerKey[pID]][CarId] ] = VEH_PRIVAT;
        FrakCarInfo[PlayerCar[pID][PlayerKey[pID]][CarId]][f_frak] = 0;
        FrakCarInfo[PlayerCar[pID][PlayerKey[pID]][CarId]][f_dbid] = 0;
        // printf("CarId %d",PlayerCar[pID][PlayerKey[pID]][CarId]);
        // new vnp[46];
        // format(vnp, sizeof(vnp), "{CB1107}%s", GetName(pID));
        SetVehicleNumberPlate(PlayerCar[pID][PlayerKey[pID]][CarId], "");
        PlayerHaveCar[pID][PlayerKey[pID]] = 1;
        //DestroyPeilsender(playerid, PlayerKey[playerid] );
        gGas[PlayerCar[pID][PlayerKey[pID]][CarId]] = GetMaxTank(PlayerCar[pID][PlayerKey[pID]][CarId]);
        gMaxGas[PlayerCar[pID][PlayerKey[pID]][CarId]] = GetMaxTank(PlayerCar[pID][PlayerKey[pID]][CarId]);
        PlayerCar[pID][PlayerKey[pID]][CarTank] = GetMaxTank(PlayerCar[pID][PlayerKey[pID]][CarId]);
        g_VehicleDistance[ PlayerCar[pID][PlayerKey[pID]][CarId] ] = 0;
        PlayerCar[pID][PlayerKey[pID]][TUV] = 0;
        LockCar(PlayerCar[pID][PlayerKey[pID]][CarId]);
        PutPlayerInVehicle(pID, PlayerCar[pID][PlayerKey[pID]][CarId], 0);
        if(stuned == 0) {
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned1] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned2] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned3] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned4] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned5] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned6] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned7] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned8] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned9] = INVALID_OBJECT_ID;
            SendClientMessage(playerid, COLOR_YELLOW, "Kein Spezial-Tuning ausgewählt!");
            PlayerCar[pID][PlayerKey[pID]][isSpecialTuned] = 0;
        }
        else if(stuned == 1) {
            PlayerCar[pID][PlayerKey[pID]][isSpecialTuned] = 1;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned1] = CreateDynamicObject(1166, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned2] = CreateDynamicObject(1168, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned3] = CreateDynamicObject(1056, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned4] = CreateDynamicObject(1056, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned5] = CreateDynamicObject(1056, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned6] = CreateDynamicObject(1056, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned7] = CreateDynamicObject(1091, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned8] = CreateDynamicObject(1164, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned9] = CreateDynamicObject(1034, 0,0,0,0,0,0,0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1], PlayerCar[pID][PlayerKey[pID]][CarId], 1.024999, 2.080000, -0.090000, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned2], PlayerCar[pID][PlayerKey[pID]][CarId],-1.066002, -1.774998, -0.130000, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned3], PlayerCar[pID][PlayerKey[pID]][CarId],-0.946998, 0.149999, -0.589998, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned4], PlayerCar[pID][PlayerKey[pID]][CarId], -0.981998, -0.169999, -0.589998, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned5], PlayerCar[pID][PlayerKey[pID]][CarId],1.008000, -0.169999, -0.589998, 0.000001, -179.995712, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned6], PlayerCar[pID][PlayerKey[pID]][CarId],0.978000, 0.174999, -0.589998, 0.000001, -179.995712, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned7], PlayerCar[pID][PlayerKey[pID]][CarId],-0.006999, 0.244999, 0.648500, 0.000001, -0.000116, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned8], PlayerCar[pID][PlayerKey[pID]][CarId], 0.000000, -2.470009, 0.368500, 0.000001, -0.000116, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned9], PlayerCar[pID][PlayerKey[pID]][CarId],-0.009999, -0.240000, -0.106499, 0.000001, -0.000116, 0.000000);
            SendClientMessage(playerid, COLOR_YELLOW, "Spezial-Tuning für Infernus ausgewählt. (Tuning: 1)");
        }
        else if(stuned == 2) {
            PlayerCar[pID][PlayerKey[pID]][isSpecialTuned] = 2;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned1] = CreateDynamicObject(18702, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned2] = CreateDynamicObject(18702, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned3] = CreateDynamicObject(18702, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned4] = CreateDynamicObject(18702, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned5] = CreateDynamicObject(18700, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned6] = CreateDynamicObject(18700, 0,0,0,0,0,0,0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1], PlayerCar[pID][PlayerKey[pID]][CarId], -0.199999, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned2], PlayerCar[pID][PlayerKey[pID]][CarId], -0.199999, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned3], PlayerCar[pID][PlayerKey[pID]][CarId], 0.300000, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned4], PlayerCar[pID][PlayerKey[pID]][CarId], 0.300000, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned5], PlayerCar[pID][PlayerKey[pID]][CarId], -0.199999, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned6], PlayerCar[pID][PlayerKey[pID]][CarId], 0.300000, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
            SendClientMessage(playerid, COLOR_YELLOW, "Spezial-Tuning für Infernus ausgewählt. (Tuning: 2)");
        }
        else if(stuned == 3) {
            PlayerCar[pID][PlayerKey[pID]][isSpecialTuned] = 3;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned1] = CreateDynamicObject(18729, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned2] = CreateDynamicObject(18729, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned3] = CreateDynamicObject(18700, 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][SpecialTuned4] = CreateDynamicObject(18700, 0,0,0,0,0,0,0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1], PlayerCar[pID][PlayerKey[pID]][CarId], -0.199999, -1.100000, -1.300000, 0.000000, 0.000000, 180.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned2], PlayerCar[pID][PlayerKey[pID]][CarId], 0.300000, -1.100000, -1.300000, 0.000000, 0.000000, 180.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned3], PlayerCar[pID][PlayerKey[pID]][CarId], -0.199999, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][SpecialTuned4], PlayerCar[pID][PlayerKey[pID]][CarId], 0.300000, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
            SendClientMessage(playerid, COLOR_YELLOW, "Spezial-Tuning für Infernus ausgewählt. (Tuning: 3)");
        }
        if(neon == 0) {
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2]);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1] = INVALID_OBJECT_ID;
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2] = INVALID_OBJECT_ID;
            SendClientMessage(playerid, COLOR_YELLOW, "Kein Neon ausgewählt!");
            PlayerCar[pID][PlayerKey[pID]][CarNeon1] = 0;
            PlayerCar[pID][PlayerKey[pID]][CarNeon2] = 0;
        }
        else if(neon == 1) {
            PlayerCar[pID][PlayerKey[pID]][CarNeon1] = 18648;
            PlayerCar[pID][PlayerKey[pID]][CarNeon2] = 18648;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2]);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1] = CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon1], 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2] =CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon2], 0,0,0,0,0,0,0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1], PlayerCar[pID][PlayerKey[pID]][CarId], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2], PlayerCar[pID][PlayerKey[pID]][CarId], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
        }
        else if(neon == 2) {
            PlayerCar[pID][PlayerKey[pID]][CarNeon1] = 18647;
            PlayerCar[pID][PlayerKey[pID]][CarNeon2] = 18647;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2]);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1] = CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon1], 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2] =CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon2], 0,0,0,0,0,0,0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1], PlayerCar[pID][PlayerKey[pID]][CarId], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2], PlayerCar[pID][PlayerKey[pID]][CarId], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
        }
        else if(neon == 3) {
            PlayerCar[pID][PlayerKey[pID]][CarNeon1] = 18649;
            PlayerCar[pID][PlayerKey[pID]][CarNeon2] = 18649;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2]);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1] = CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon1], 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2] =CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon2], 0,0,0,0,0,0,0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1], PlayerCar[pID][PlayerKey[pID]][CarId], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2], PlayerCar[pID][PlayerKey[pID]][CarId], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
        }
        else if(neon == 4) {
            PlayerCar[pID][PlayerKey[pID]][CarNeon1] = 18652;
            PlayerCar[pID][PlayerKey[pID]][CarNeon2] = 18652;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2]);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1] = CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon1], 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2] =CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon2], 0,0,0,0,0,0,0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1], PlayerCar[pID][PlayerKey[pID]][CarId], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2], PlayerCar[pID][PlayerKey[pID]][CarId], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
        }
        else if(neon == 5) {
            PlayerCar[pID][PlayerKey[pID]][CarNeon1] = 18651;
            PlayerCar[pID][PlayerKey[pID]][CarNeon2] = 18651;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2]);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1] = CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon1], 0,0,0,0,0,0,0);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2] =CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon2], 0,0,0,0,0,0,0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1], PlayerCar[pID][PlayerKey[pID]][CarId], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2], PlayerCar[pID][PlayerKey[pID]][CarId], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
        }
        else if(neon == 6) {
            PlayerCar[pID][PlayerKey[pID]][CarNeon1] = 18650;
            PlayerCar[pID][PlayerKey[pID]][CarNeon2] = 18650;
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1]);
            DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2]);
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1] = CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon1], 0,0,0,0,0,0,0);print("Object1 erstellt");
            PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2] =CreateDynamicObject(PlayerCar[pID][PlayerKey[pID]][CarNeon2], 0,0,0,0,0,0,0);print("Object2 erstellt");
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1], PlayerCar[pID][PlayerKey[pID]][CarId], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);print("Object1 angeheftet");
            AttachDynamicObjectToVehicle(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2], PlayerCar[pID][PlayerKey[pID]][CarId], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);print("Object2 angeheftet");
        }
        new String[128];
        format(String,sizeof(String),"%s %s hat Spieler %s das Fahrzeug (%d) gesetzt", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), vID);
        AdminLog(String);
    } else {
        return SendClientMessage(playerid, COLOR_RED, "* Der Spieler hat auf dem Autoschlüssel bereits ein Fahrzeug.");
    }
    return 1;
}



CMD:prison(playerid, params[]) {
    new pID, time, string[256], reason[64];
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "uis[64]", pID, time, reason))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Prison [SpielerID/Name] [Zeit in Min.] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    new MinuteTime = time;
    format(string, sizeof(string), "[PRISON] Spieler %s wurde von %s %s für %d Minuten ins Prison eingesperrt, Grund: %s", GetName(pID), GetPlayerAdminRang(playerid), GetName(playerid), MinuteTime, reason);
    SendAdminMessage(COLOR_DARKRED, string);
    format(string, sizeof(string), "[PRISON] Du wurdest von %s %s für %d Minuten ins Prison eingesperrt, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), MinuteTime, reason);
    SendClientMessage(pID, COLOR_DARKRED, string);
    Spieler[pID][pJailed] = 3;
    Spieler[pID][pJailTime] = time*60;
    SpawnPlayerEx(pID);
    paydaywait[pID]=1;
    format(string,sizeof(string),"%s wurde von %s %s für %d Minuten ins Admin-Prison gesteckt, Grund: %s", GetName(pID), GetPlayerAdminRang(playerid), GetName(playerid), time, reason);
    SendUCPAktenEintrag( playerid,GetName(playerid) , GetName(pID) , string );
    return 1;
}



CMD:afkick(playerid, params[])
{
    new pID, string[128];
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Afkick [SpielerID/Name]");
    if(!IsPlayerConnected(playerid))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pFraktion] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist bereits Zivilist.");
    RemovePlayerFromFaction(pID);
    format(string, sizeof(string), "* Du wurdest von %s %s zum Zivilist gemacht.", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessage(pID, COLOR_DARKRED, string);
    format(string, sizeof(string), "* Du hast %s zum Zivilist gemacht.", GetName(pID));
    SendClientMessage(playerid, COLOR_DARKRED, string);
    return 1;
}



CMD:ipban(playerid, params[]) {
    new pID, grund[64], string[128], string1[128];
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "us[64]", pID, grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Ipban [SpielerID/Name] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pAdmin] > 0)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Supporter bzw. Admins bannen.");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    format(string, sizeof(string), "[BANNED]: Spieler %s wurde von %s %s dauerhaft aus dem Server gebannt, Grund: %s", GetName(pID), GetPlayerAdminRang(playerid), GetName(playerid), grund);
    SendAdminMessage(COLOR_RED, string);
    format(string, sizeof(string), "[BANNED] Du wurdest soeben von %s %s dauerhaft aus dem Server gebannt. Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), grund);
    SendClientMessage(pID, COLOR_RED, string);
    format(string1, sizeof(string1), "Sind Sie der Meinung das diese Sperre falsch war? Dann schreiben Sie auf www.LyD-Roleplay.de ein Entbannantrag!");
    SendClientMessage(pID, COLOR_RED, string1);
    mysql_real_escape_string(grund,grund);
    new query[256];
    format(query,sizeof(query),"UPDATE `accounts` SET `GebanntVon` = '%s' ,`BanGrund` = '%s' , `Banned` = 1 WHERE `Name` = '%s'",GetName(playerid),grund,GetName(pID));
    mysql_pquery(query,THREAD_IPBAN,pID,gSQL,MySQLThreadOwner);
    format(query,sizeof(query),"Gebannt: %s von: %s, Grund: %s, Dauer: %s, IP-Sperre",GetName(pID),GetName(playerid),grund,("Immer"));
    BanLog( query );
    new String[160];
    format(String,sizeof(String),"%s %s hat Spieler %s dauerhaft mit einer IP-Sperre gebannt, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), grund);
    AdminLog(String);
    format(query,sizeof(query),"%s wurde von %s %s dauerhaft gebannt mit IP-Sperre, Grund: %s", GetName(pID), GetPlayerAdminRang(playerid), GetName(playerid), grund);
    SendUCPAktenEintrag( playerid,GetName(playerid) , GetName(pID) , query );
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



/*CMD:giveac(playerid, params[]) {
	new pID, wert, string[128];
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
	if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "uu", pID, wert))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/giveac [SpielerID/Name] [0 - 1]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (wert <= 0 && wert >= 1) return SendClientMessage(playerid, COLOR_RED, "Gebe entweder 0 für Aus oder 1 für An ein.");
    Spieler[pID][pMustUseAC] = wert;
    if(Spieler[pID][pMustUseAC]) {
        SendClientMessage(playerid, COLOR_WHITE, "Dir wurde eine Anti-Cheat Pflicht verhängt!");
        SCMFormatted(playerid, COLOR_LIGHTBLUE, "Du hast dem Spieler %s eine Anti-Cheat Pflicht verhängt.", GetName(pID));
   	    format(string, sizeof(string), "Cheatbeauftragter %s hat %s eine Anti-Cheat Pflicht verhängt!", GetName(playerid), GetName(pID));
	    SendModMessage(COLOR_RED, string);
        if (!CAC_GetStatus(pID)) {
            SendClientMessage(pID, COLOR_RED, "Lade den Anti-Cheat im Forum herunter, um weiterspielen zu können.");
            AC_kick(pID, "Anti-Cheat Client Pflicht");
        }
    } else {
        SendClientMessage(pID, COLOR_WHITE, "Dir wurde deine Anti-Cheat Pflicht aufgehoben.");
        SendClientMessage(pID, COLOR_RED, "Du kannst nun wieder ohne Anti-Cheat spielen, sofern du nicht in einer Fraktion mit einer AC-Pflicht bist.");
        SCMFormatted(playerid, COLOR_LIGHTBLUE, "Du hast dem Spieler %s seine Anti-Cheat Pflicht aufgehoben.", GetName(pID));
   	    format(string, sizeof(string), "Cheatbeauftragter %s hat %s seine Anti-Cheat Pflicht aufgehoben!", GetName(playerid), GetName(pID));
	    SendModMessage(COLOR_RED, string);
	    return 1;
    }
	return 1;
}*/



CMD:gcoff(playerid)
{
    if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    return ToggleASetting(playerid, ASETTING_GLOBALCHAT, false);
}



CMD:regsperre(playerid)
{
    return cmd_asettings(playerid);
}



CMD:giveallscheine(playerid, params[]) {
	new pID, string[128];
	if( Spieler[playerid][pAdmin] < 3 ) return ERROR_RANG_MSG(playerid);
	if(sscanf(params, "u", pID))return SendClientMessage(playerid,COLOR_BLUE,INFO_STRING"/Giveallscheine [SpielerID/Name]");
	if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
	Spieler[pID][pCarLic] = 1;
	Spieler[pID][pMotoLic] = 1;
	Spieler[pID][pFlyLic] = 1;
	Spieler[pID][pBoatLic] = 1;
	Spieler[pID][pGunLic] = 1;
	Spieler[pID][pGunLicB] = 1;
	Spieler[pID][pLKWLic] = 1;
    Spieler[pID][pFishLic] = 1;
	SCMFormatted(playerid, COLOR_WHITE,"Spieler "COLOR_HEX_ORANGE"%s "COLOR_HEX_WHITE"hat alle Scheine erhalten!",GetName(pID));
	SCMFormatted(playerid, COLOR_WHITE,"Beachte, dass "COLOR_HEX_ORANGE"%s "COLOR_HEX_WHITE"auch die jeweiligen Level dazu besitzt!",GetName(pID));
	SCMFormatted(pID, COLOR_WHITE,""COLOR_HEX_ORANGE"%s %s "COLOR_HEX_WHITE"gab dir alle Scheine!",GetPlayerAdminRang(playerid),GetName(playerid));
	format(string,sizeof(string),"%s %s gab %s alle Scheine!",GetPlayerAdminRang(playerid),GetName(playerid),GetName(pID));
	SendAdminMessage(COLOR_RED,string);
	return 1;
}



CMD:giveschein(playerid, params[]) {
    new pID, schein[32], string[128];
    if(sscanf(params, "us[32]", pID, schein)) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Giveschein [SpielerID/Name] [Schein]");
        SendClientMessage(playerid, COLOR_ORANGE, "* Scheine *: Fahrschein, Motorradschein, Lkwschein, Flugschein, Bootsschein, Awaffenschein, Bwaffenschein");
        return 1;
    }
    if( ( Spieler[playerid][pFraktion] != 8 ) && ( Spieler[playerid][pAdmin] < 3 ) )return SendClientMessage(playerid, COLOR_RED, "Du bist kein Fahrlehrer.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(strcmp(schein, "fahrschein", true) == 0) {
        if(Spieler[pID][pCarLic] == 1)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat den Führerschein bereits!");
        if( gettime() < Spieler[pID][punixFSperre] ) {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat noch eine Lizenzsperre");
        }
        format(string, sizeof(string), "* Du hast den Führerschein von Fahrlehrer %s erhalten.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast %s den Führerschein gegeben.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pCarLic] = 1;
    } else if(strcmp(schein, "motorradschein", true) == 0) {
        if(Spieler[pID][pMotoLic] == 1)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat den Motorradschein bereits!");
        if( gettime() < Spieler[pID][punixMotoSperre] ) {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat noch eine Lizenzsperre");
        }
        format(string, sizeof(string), "* Du hast den Motorradschein von Fahrlehrer %s erhalten.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast %s den Motorradschein gegeben.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pMotoLic] = 1;
    } else if(strcmp(schein, "flugschein", true) == 0) {
        if(Spieler[pID][pFlyLic] == 1)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat den Flugschein bereits!");
        if( gettime() < Spieler[pID][punixFlSperre] ) {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat noch eine Lizenzsperre");
        }
        format(string, sizeof(string), "* Du hast den Flugschein von Fahrlehrer %s erhalten.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast %s den Flugschein gegeben.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pFlyLic] = 1;
    } else if(strcmp(schein, "bootsschein", true) == 0) {
        if(Spieler[pID][pBoatLic] == 1)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat den Bootsschein bereits!");
        format(string, sizeof(string), "* Du hast den Bootsschein von Fahrlehrer %s erhalten.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast %s den Bootsschein gegeben.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pBoatLic] = 1;
    } else if(strcmp(schein, "awaffenschein", true) == 0) {
        if(Spieler[pID][pGunLic] == 1)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat den Waffenschein Klasse A bereits!");
        if(Spieler[pID][pLevel] < 5)return SendClientMessage(playerid, COLOR_RED, "Der Spieler muss mindestens Level 5 sein!");
        if( gettime() < Spieler[pID][punixGunSperre] ) {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat noch eine Lizenzsperre");
        }
        format(string, sizeof(string), "* Du hast den Waffenschein Klasse A von Fahrlehrer %s erhalten.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast %s den Waffenschein Klasse A gegeben.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pGunLic] = 1;
    } else if(strcmp(schein, "bwaffenschein", true) == 0) {
        if(Spieler[pID][pGunLicB] == 1)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat den Waffenschein Klasse B bereits!");
        if(Spieler[pID][pLevel] < 7)return SendClientMessage(playerid, COLOR_RED, "Der Spieler muss mindestens Level 7 sein!");
        if( gettime() < Spieler[pID][punixGunSperre] ) {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat noch eine Lizenzsperre");
        }
        format(string, sizeof(string), "* Du hast den Waffenschein Klasse B von Fahrlehrer %s erhalten.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast %s den Waffenschein Klasse B gegeben.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pGunLicB] = 1;
    } else if(strcmp(schein, "lkwschein", true) == 0) {
        if(Spieler[pID][pLKWLic] == 1)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat den LKW-Schein bereits!");
        if( gettime() < Spieler[pID][punixLKWSperre] ) {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat noch eine Lizenzsperre");
        }
        format(string, sizeof(string), "* Du hast den LKW-Schein von Fahrlehrer %s erhalten.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast %s den LKW-Schein gegeben.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pLKWLic] = 1;
    } else {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Giveschein [SpielerID/Name] [Schein]");
        SendClientMessage(playerid, COLOR_ORANGE, "* Scheine *: Fahrschein, Motorradschein, Lkwschein, Flugschein, Bootsschein, Awaffenschein, Bwaffenschein");
    }
    return 1;
}







CMD:verwarnen(playerid, params[]) {
    new giveid, punkte, sGrund[128], string[128];
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "uds[128]",giveid,punkte,sGrund)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Verwarnen [Spieler/ID] [Verwarnungen] [Grund]");
    if (giveid == INVALID_PLAYER_ID || !gPlayerLogged[giveid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online.");
    if( punkte < 0 ) {
        if( punkte < -5 ) {
            return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst maximal 5 Punkte abziehen!");
        }
        SCMFormatted(giveid, COLOR_RED,"[ACHTUNG] %s %s hat dir %d Verwarnungen entfernt!", GetPlayerAdminRang(playerid), GetName(playerid), punkte);
        SCMFormatted(giveid, COLOR_RED,"Anzahl der Verwarnungen die Gelöscht wurden: %d, Grund: %s",punkte, sGrund);
        format(string, sizeof(string),"[A-WARN]: %s %s hat %d Verwarnungen von Spieler %s entfernt, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), punkte, GetName(giveid), sGrund);
        SendModMessage(COLOR_RED, string);
        Spieler[giveid][pWarns] += punkte;
        SCMFormatted(playerid, COLOR_BLUE,"[INFO] {FFFFFF}Du hast %d Verwarnungen bei Spieler %s erfolgreich gelöscht.", punkte, GetName(giveid));
    }
    else if ( punkte > 0 ) {
        if( punkte > 5 ) {
            return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst maximal 5 Punkte vergeben!");
        }
        SCMFormatted(giveid, COLOR_RED,"[INFO] {FFFFFF}%s %s hat dir %d Verwarnungen verhängt, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), punkte, sGrund);
        SCMFormatted(playerid, COLOR_BLUE,"[INFO] {FFFFFF}Du hast %d Verwarnungen gegen den Spieler %s ausgesprochen, Grund: %s",punkte, GetName(giveid), sGrund);
        format(string,sizeof(string),"[A-WARN] %s %s hat Spieler %s %d Verwarnungen ausgesprochen, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), GetName(giveid), punkte, sGrund);
        SendModMessage(COLOR_RED, string);
        Spieler[giveid][pWarns] += punkte;
    }
    return 1;
}



CMD:entbannen(playerid,params[]) {
    new Spielername[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",Spielername)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Entbannen [Spielername]");
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new String[256], Query[170];
    mysql_real_escape_string(Spielername,Spielername);
    format(Query,sizeof(Query),"UPDATE `accounts` SET `Banned` = 0 , `TimeBan` = 0,`GebanntVon` = '' , `BanGrund` = ''  WHERE `Name` = '%s'",Spielername);
    mysql_pquery(Query,THREAD_ENTBANNEN,playerid,gSQL,MySQLThreadOwner);
    format(String,sizeof(String),"%s %s hat den Spieler %s entbannt", GetPlayerAdminRang(playerid), GetName(playerid), Spielername);
    SendAdminMessage(COLOR_YELLOW, String);
    format(Query,sizeof(Query),"SELECT `ipadresse` FROM `accounts` WHERE `Name` = '%s'",Spielername);
    mysql_pquery(Query,THREAD_ENTBANNEN_IP,playerid,gSQL,MySQLThreadOwner);
    format(String,sizeof(String),"%s %s hat Spieler %s entbannt.", GetPlayerAdminRang(playerid), GetName(playerid), Spielername);
    AdminLog(String);
    format(Query,sizeof(Query),"%s wurde von %s %s entbannt!",Spielername, GetPlayerAdminRang(playerid), GetName(playerid));
    SendUCPAktenEintrag( playerid,GetName(playerid),Spielername , Query );
    return 1;
}



CMD:delfraksperre(playerid,params[]) {
    new sName[MAX_PLAYER_NAME], giveid;
    if(sscanf(params,"s[24]",sName)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Delfraksperre [Spieler] ");
    sscanf(sName,"u",giveid);
    //if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
	if(Spieler[playerid][pAdmin] < 3 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    mysql_real_escape_string(sName,sName);
    if( IsPlayerConnected(giveid) ) {
        new
            String[128];
        format(String,sizeof(String),"Du hast dem Spieler %s erfolgreich die Fraktionssperre entfernt.",GetName(giveid));
        SendClientMessage(playerid,COLOR_GREEN,String);
        format(String,sizeof(String),"[SPERRE] Deine Fraktionssperre wurde von %s aufgehoben!",GetName(playerid));
        SendClientMessage(giveid,COLOR_GREEN,String);
        Spieler[giveid][pFrakSperre] = 0;
        new query[256];
        format(query,sizeof(query),"%s's Fraktionssperre wurde von %s %s aufgehoben!", GetName(giveid), GetPlayerAdminRang(playerid), GetName(playerid) );
        SendUCPAktenEintrag( playerid,GetName(playerid) , GetName(giveid) , query );
    } else {
        new String[128];
        format(String,sizeof(String),"Du hast dem Spieler %s erfolgreich die Fraktionssperre entfernt.",sName);
        SendClientMessage(playerid,COLOR_GREEN,String);
        format(String,sizeof(String),"UPDATE `accounts` SET `FrakSperre` = 0 WHERE `Name` = '%s'",sName);
        mysql_oquery(String,THREAD_DUMMY,playerid,gSQL);
        String[0] = '\0';
        format(String,sizeof(String),"%s's Fraktionssperre wurde von %s %s aufgehoben!", sName, GetPlayerAdminRang(playerid), GetName(playerid) );
        SendUCPAktenEintrag( playerid,GetName(playerid) ,sName , String );
    }
    return 1;
}



CMD:fraksperre(playerid,params[]) {
    new giveid = INVALID_PLAYER_ID, sName[MAX_PLAYER_NAME], reason[128];
    if(sscanf(params,"ss[128]",sName,reason)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Fraksperre [Spieler] [Grund]");
    sscanf(sName,"u",giveid);
    //if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
	if(Spieler[playerid][pAdmin] < 3 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    if( playerid == giveid ) return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber keine Fraktionssperre geben.");
    if( IsPlayerConnected(giveid)) {
        new query[300], String[180];
        format(String,sizeof(String),"Du hast dem Spieler %s erfolgreich eine Fraktionssperre verpasst.",GetName(giveid));
        SendClientMessage(playerid,COLOR_YELLOW,String);
        format(String,sizeof(String),"[SPERRE] Du hast von %s eine Fraktionssperre erhalten",GetName(playerid));
        SendClientMessage(giveid,COLOR_RED,String);
        format(String,sizeof(String),"Begründung: %s",reason);
        SendClientMessage(giveid,COLOR_RED,String);
        Spieler[giveid][pFrakSperre] = 1;
        format(query,sizeof(query),"%s erhielt von %s %s eine Fraktionssperre, Grund und Dauer: %s!", GetName(giveid), GetPlayerAdminRang(playerid), GetName(playerid), reason);
        mysql_real_escape_string(String,String);
        SendUCPAktenEintrag( playerid,GetName(playerid) , GetName(giveid) , query , THREAD_FRAKSPERRE);
    } else {
        new query[300], String[180];
        format(String,sizeof(String),"Du hast dem Spieler %s erfolgreich eine Fraktionssperre verpasst.",sName);
        SendClientMessage(playerid,COLOR_YELLOW,String);
        format(String,sizeof(String),"UPDATE `accounts` SET `FrakSperre` = 1 WHERE `Name` = '%s'",sName);
        mysql_oquery(String,THREAD_DUMMY,playerid,gSQL);
        format(query,sizeof(query),"%s erhielt von %s %s eine Fraktionssperre, Grund und Dauer: %s!", sName, GetPlayerAdminRang(playerid), GetName(playerid), reason);
        mysql_real_escape_string(String,String);
        SendUCPAktenEintrag( playerid,GetName(playerid) , sName , query , THREAD_FRAKSPERRE);
    }
    return 1;
}



CMD:settime(playerid,params[]) {
    new time;
    if(sscanf(params,"i",time)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Settime [Uhrzeit]");
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    if( !(0 <= time <= 24 ) ) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Settime [Uhrzeit ( 0 - 24 )]");
    new String[128];
    format(String,sizeof(String),"Die Uhrzeit wurde auf %02d:00 Uhr gesetzt",time);
    SendClientMessage(playerid, COLOR_YELLOW,String);
    SetWorldTime(time);
    return 1;
}



CMD:offageld(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new sSpieler[MAX_PLAYER_NAME], pID, amount;
    GetPVarString(playerid, "OFFAGELD.NAME", sSpieler, sizeof(sSpieler));
    if (!isnull(sSpieler)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du gibst gerade noch jemandem offline Geld.");
    if (sscanf(params, "s[24]i", sSpieler, amount) || !amount) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Offageld [Spielername] [Betrag]");
    if (!sscanf(sSpieler, "u", pID) && IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist zurzeit online. Benutze /Ageld.");
    new query[256];
    mysql_real_escape_string(sSpieler, sSpieler);
    SetPVarString(playerid, "OFFAGELD.NAME", sSpieler);
    SetPVarInt(playerid, "OFFAGELD.AMOUNT", amount);
    format(query, sizeof(query), "SELECT `Name` FROM `accounts` WHERE `Name` = '%s' LIMIT 1", sSpieler);
    mysql_pquery(query, THREAD_OFFAGELD_CHECK, playerid, gSQL, MySQLThreadOwner);
    return 1;
}



CMD:offbannen(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new sSpieler[MAX_PLAYER_NAME], sGrund[128];
    if(sscanf(params,"s[24]s[128]",sSpieler,sGrund)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Offbannen [Spieler] [Grund]");
    new query[256];
    mysql_real_escape_string(sSpieler,sSpieler);
    format(query,sizeof(query),"UPDATE `accounts` SET `Banned` = 1,`BanGrund` = '%s',`GebanntVon` = '%s' WHERE `Name` = '%s'", sGrund,GetName(playerid),sSpieler);
    mysql_pquery(query,THREAD_OFFBANNEN,playerid,gSQL,MySQLThreadOwner);
    format(query,sizeof(query),"[OFFLINE-BAN] Spieler %s wurde von %s dauerhaft vom Server gebannt! ( OFFLINE BAN )",sSpieler,GetName(playerid) );
    SendAdminMessage(COLOR_RED, query);
    format(query,sizeof(query),"%s wurde von %s %s offline dauerhaft gebannt, Grund: %s", sSpieler, GetPlayerAdminRang(playerid), GetName(playerid), sGrund);
    SendUCPAktenEintrag( playerid, GetName(playerid) , sSpieler , query );
    return 1;
}



CMD:oafkick(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die benötigten Rechte.");
    new sSpieler[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",sSpieler)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Oafkick [Spieler]");
    new query[128];
    mysql_real_escape_string(sSpieler,sSpieler);
    format(query,sizeof(query),"UPDATE `accounts` SET `Fraktion` = 0,`Rank` = 0,`Skin` = 2, `SpawnChange` = 0 WHERE `Name` = '%s'",sSpieler);
    mysql_pquery(query,THREAD_OAFKICK,playerid,gSQL,MySQLThreadOwner);
    format(query,sizeof(query),"[FKICK] Der Spieler %s wurde von %s aus seiner Fraktion gekickt ( OFFLINE )",sSpieler,GetName(playerid) );
    SendAdminMessage(COLOR_YELLOW, query);
    return 1;
}


CMD:rangeban(playerid,params[]) {
    new giveid;
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Rangeban [Spieler/ID]");
    if( !IsPlayerConnected(giveid)) return SendClientMessage(playerid,COLOR_RED,"Der Spieler wurde nicht gefunden");
    if(Spieler[giveid][pAdmin] > 0)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Supporter bzw. Admins bannen.");
    new String[256], _ip[16], ip[16];
    GetPlayerIp(giveid,ip,sizeof(ip));
    _ip = IP2RootIP( ip , 2);
    if( IsIPBanned(ip)) {
        format(String,sizeof(String),"Die IP %s ist bereits gebannt",_ip);
        return SendClientMessage(playerid,COLOR_BLUE,String);
    }
    AddIPBan( ip );
    format(String,sizeof(String),"Die IP %s wurde erfolgreich gebannt.",_ip);
    SendClientMessage(playerid,COLOR_LIGHTRED2,String);
    format(String,sizeof(String),"%s %s",params,("Aufgrund eines Regelverstoßes wurdest du aus dem Projekt komplett ausgeschlossen!"));
    return cmd_ban(playerid,String);
}



CMD:addwhitelist(playerid,params[]) {
    new name[MAX_PLAYER_NAME];
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    if( sscanf(params,"s[24]",name)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Addwhitelist [Name]");
    IsWhitelist(name,playerid);
    return 1;
}



CMD:checkskill(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new pID;
    if (sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/checkskill [Spieler ID/Name]");
    if (!gPlayerLogged[pID]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht online.");
    new String[128];
    SendClientMessage(playerid, COLOR_GREEN, "============= {FFFFFF}[ SKILLS ] {009D00}=============");
    format(String, sizeof(String), "Spieler: %s (%d)", GetName(pID), pID);
    SendClientMessage(playerid, COLOR_WHITE, String);
    format(String, sizeof(String), "Detektiv-Skill: {FFFFFF}%d/%d (%d Sekunden)", GetPlayerDetectivLevel(pID), sizeof(g_DetektivSkill), GetPlayerDetectivSkillValue(pID));
    SendClientMessage(playerid, COLOR_YELLOW, String);
    format(String, sizeof(String), "Huren-Skill: {FFFFFF}%d/%d (%d HP)", GetPlayerHureLevel(pID), sizeof(g_HureSkill), GetPlayerHureSkillValue(pID));
    SendClientMessage(playerid, COLOR_YELLOW, String);
    format(String, sizeof(String), "Anwalt-Skill: {FFFFFF}%d/%d (Bis %d Knastzeit)", GetPlayerLawyerLevel(pID), sizeof(g_LawyerSkills), GetPlayerLawyerSkillValue(pID));
    SendClientMessage(playerid, COLOR_YELLOW, String);
    format(String, sizeof(String), "Gangfight-Skill: {FFFFFF}%d/%d (Kills: %d)", GetPlayerGangFightSkillLevel(pID), sizeof(g_GangFightSkills), Spieler[pID][pKillsGangFight]);
    SendClientMessage(playerid, COLOR_YELLOW, String);
    format(String, sizeof(String), "Drogen-Skill: {FFFFFF}%d/%d (Bis zu %d Päckchen)", GetPlayerDrogenSkillLevel(pID), sizeof(g_DrogenSkills), GetPlayerDrogenSkillValue(pID));
    SendClientMessage(playerid, COLOR_YELLOW, String);
    format(String, sizeof(String), "Waffenteile-Skill: {FFFFFF}%d/%d (Bis zu %d Päckchen)", GetPlayerWaffenteileSkillLevel(pID), sizeof(g_WaffenteileSkills), GetPlayerWaffenteileSkillValue(pID));
    SendClientMessage(playerid, COLOR_YELLOW, String);
	format(String, sizeof(String), "Samen-Skill: {FFFFFF}%d/5 (Bis zu %d Päckchen)", GetPlayerSamenSkillLevel(pID), GetPlayerSamenSkillLevelValue(pID));
	SendClientMessage(playerid, COLOR_YELLOW, String);
	format(String, sizeof(String), "{FFFF00}Piloten-Skill: {FFFFFF}%d/5", GetPlayerPilotSkillLevel(pID));
	SendClientMessage(playerid, COLOR_YELLOW, String);
    return 1;
}



CMD:nameblacklist(playerid,params[]) {
    new name[MAX_PLAYER_NAME];
    if(Spieler[playerid][pAdmin] < 3 )return ERROR_RANG_MSG(playerid);
    if(sscanf(params,"s[24]",name)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Nameblacklist [Name]");
    new String[128];
    format(String,sizeof(String),"[BLACKLIST] Der Name %s wurde auf die Blacklist gesetzt!",name);
    SendAdminMessage(COLOR_YELLOW, String);
    AddBlacklistName(name);
    return 1;
}



CMD:akteneintrag(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new Spielername[MAX_PLAYER_NAME], String[128], query[300];
    mysql_real_escape_string(params,params,gSQL,strlen(params) );
    if(sscanf(params,"s[24]s[128]",Spielername,String)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Akteneintrag [SPIELERNAME] [EINTRAG]");
    format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `Name` = '%s'",Spielername);
    mysql_pquery(query,THREAD_AKTENEINTRAG_EXISTS,playerid,gSQL,MySQLThreadOwner);
    SetPVarString(playerid,"Akteneintrag",params);
    return 1;
}



CMD:offprison(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new Spielername[MAX_PLAYER_NAME], String[128], time, query[300];
    mysql_real_escape_string(params,String,gSQL, strlen(params) );
    if(sscanf(params,"s[24]is[128]",Spielername,time,String)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Offprison [SPIELERNAME] [MINUTEN-ZEIT] [GRUND]");
    if( time < 0 ) return SendClientMessage(playerid, COLOR_RED, "Ungültige Zeit.");
    format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `Name` = '%s'",Spielername);
    mysql_pquery(query,THREAD_OFFPRISON_EXISTS,playerid,gSQL,MySQLThreadOwner);
    SetPVarString(playerid,"OffPrison",params);
    return 1;
}



CMD:hwban(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new grund[128],giveid;
    if(sscanf(params,"us[128]",giveid,grund)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Hwban [Spieler] [Grund]");
    if( !IsPlayerConnected(giveid)) return SendClientMessage(playerid,COLOR_RED,"Der Spieler wurde nicht gefunden.");
    if(Spieler[giveid][pAdmin] > 2) return SendClientMessage(playerid,COLOR_RED,"Du kansnt keine Admins bannen.");
    new serial[128],query[256];
    gpci(giveid, serial,sizeof( serial ) );
    format(query,sizeof(query),"INSERT INTO `hwban` (`id`, `hwid`, `Name`, `Gebannt von`, `Grund`) VALUES (NULL, '%s', '%s', '%s', '%s')",serial,GetName(giveid),GetName(playerid),grund );
    mysql_pquery(query,THREAD_HWBAN_INSERT,playerid,gSQL,MySQLThreadOwner);
    format(query,sizeof(query),"[HW-BANNED]: Spieler %s wurde von %s %s dauerhaft aus dem Server gebannt, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid),GetName(giveid), grund);
    SendAdminMessage(COLOR_YELLOW, query);
    format(query,sizeof(query),"%s hat von %s %s einen HW-Ban bekommen, Grund: %s", GetName(giveid), GetPlayerAdminRang(playerid), GetName(playerid), grund);
    SendUCPAktenEintrag( playerid,GetName(playerid) , GetName(giveid) , query );
    format(query,sizeof(query),"SELECT * FROM `hwban` WHERE `hwid` = '%s'",serial );
    mysql_pquery(query,THREAD_HWBAN,giveid,gSQL,MySQLThreadOwner);
    // Haus vom Gebannten freimachen
	new pHouse = GetPlayerHouse(giveid);
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
    	WHERE `HouseMieteKey` = %d", Spieler[giveid][pPlayerHouse]);
    mysql_pquery(query,THREAD_DUMMY,playerid,gSQL,MySQLThreadOwner);
    Haus[pHouse][hMieterAnzahl] = 0;
    Haus[pHouse][hKasse] = 0;
    return 1;
}



CMD:hwunban(playerid,params[]) {
    new Spielername[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",Spielername)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/hwunban [Spielername]");
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new String[256],Query[170];
    mysql_real_escape_string(Spielername,Spielername);
    format(Query,sizeof(Query),"DELETE FROM `hwban` WHERE `Name` = '%s'",Spielername);
    mysql_pquery(Query,THREAD_DUMMY,playerid,gSQL,MySQLThreadOwner);
    format(String,sizeof(String),"%s %s hat die HW-ID von Spieler %s entbannt", GetPlayerAdminRang(playerid), GetName(playerid), Spielername);
    SendAdminMessage(COLOR_YELLOW, String);
    format(String,sizeof(String),"%s %s hat die HW-ID von Spieler %s entbannt.", GetPlayerAdminRang(playerid), GetName(playerid), Spielername);
    AdminLog(String);
    format(Query,sizeof(Query),"%s %s hat die HW-ID von %s entsperrt!", GetPlayerAdminRang(playerid), GetName(playerid),Spielername);
    SendUCPAktenEintrag( playerid,GetName(playerid),Spielername , Query );
    return 1;
}



CMD:stopkredit(playerid, params[]) {
	new pID, reason[64], string[128], finalmoney = Spieler[pID][pKreditwert];
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
	if(sscanf(params, "us[64]", pID, reason)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Stopkredit [SpielerID/Name] [Grund]");
	if(strlen(reason) < 3 ) return SendClientMessage(playerid, COLOR_RED,"Der Grund muss mind. 3 Zeichen beinhalten.");
	if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
	if(Spieler[pID][pKreditwert] == 0) return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen offenen Kredit.");
	SCMFormatted(playerid,COLOR_GREEN,"[INFO] {FFFFFF}Du hast den Kredit von %s i.H.v. $%s erfolgreich gestoppt, Grund: %s",GetName(pID), AddDelimiters(finalmoney), reason);
	SCMFormatted(pID,COLOR_YELLOW,"[INFO] {FFFFFF}%s %s hat deinen Kredit i.H.v. $%s gestoppt, Grund: %s",GetPlayerAdminRang(playerid), GetName(playerid), AddDelimiters(finalmoney), reason);
	format(string,sizeof(string),"[STOPKREDIT] %s %s hat den Kredit von %s i.H.v. $%s gestoppt, Grund: %s",GetPlayerAdminRang(playerid),GetName(playerid),GetName(pID), AddDelimiters(finalmoney), reason);
	SendModMessage(COLOR_RED,string);
	Kasse[Staat] += finalmoney; // <== Staatskasse erhält den restlichen Kreditbetrag zurück
	Spieler[pID][pKreditGezahlt] = 0;
	Spieler[pID][pKreditwert] = 0;
	// Log
	format(string,sizeof(string),"%s %s hat von %s den Kredit gestoppt, Grund: %s",GetPlayerAdminRang(playerid),GetName(playerid),GetName(pID),reason);
	AdminLog(string);
	return 1;
}



CMD:spielerip(playerid,params[]) {
    new giveid;
    if(Spieler[playerid][pAdmin] < 6 )return ERROR_RANG_MSG(playerid);//3
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Spielerip [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new ip[16], String[128];
    GetPlayerIp(giveid,ip,sizeof(ip));
    format(String,sizeof(String),"%s - IP: %s",GetName(giveid),ip);
    SendClientMessage(playerid,COLOR_YELLOW,String);
    return 1;
}



CMD:multiacc(playerid,params[])
{
    new hwid[256],giveid;
    if(Spieler[playerid][pAdmin] < 3 )return ERROR_RANG_MSG(playerid);
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/multiaccount [Spieler]");
    format(hwid,sizeof(hwid),"SELECT `hwid` FROM `accounts` WHERE `Name` = '%s'",giveid);
    mysql_pquery(hwid,THREAD_HWID_CHECK,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:inballon(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new Float:x,Float:y,Float:z;
    GetDynamicObjectPos(  g_BallonConfig[BC_iObject] , x ,y ,z);
    SetPlayerPos(playerid,x,y,z  + 0.75 );
    return 1;
}



CMD:savehausupgrade(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new String[160], house_index, vw;
    vw = GetPlayerVirtualWorld(playerid);
    house_index = vw;
    //printf("vw %d house_index %d",vw,house_index);
    if( !( 0 <= vw < MAX_HOUSES )  ) return SendClientMessage(playerid,COLOR_RED,"Du stehst in keinem Haus-Upgrade Pickup.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid,x,y,z);
    format(String,sizeof(String),"UPDATE `houseinterior` SET \
        `PickupX` = %.2f,\
        `PickupY` = %.2f,\
        `PickupZ` = %.2f \
        WHERE `ID` = %d",
        x,y,z, Haus[house_index][HouseInteriorID]);
    //print(String);
    mysql_pquery(String,THREAD_SAVEHOUSEUPGRADE,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:clearchat(playerid,params[])
{
    new string[128];
	if(Spieler[playerid][pAdmin] < 3)return SendClientMessage(playerid, COLOR_WHITE, ERROR_ADMIN); 
    for(new MSG = 0; MSG <= 120; MSG++) SendClientMessageToAll(COLOR_WHITE, " ");
    format(string,sizeof(string),"Der Chat wurde von %s %s gecleart.", GetPlayerAdminRang(playerid),GetName(playerid));
    SendClientMessageToAll(COLOR_WHITE, string);
	return 1;
}



CMD:gotozone(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new gfindex = -1;
    if (sscanf(params, "i", gfindex) || gfindex < 1 || gfindex > MAX_GANGZONES) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Gotozone [1-28]");

    format(params, 128, "%f %f %f", g_GangZone[gfindex-1][GZ_fIconX], g_GangZone[gfindex-1][GZ_fIconY], g_GangZone[gfindex-1][GZ_fIconZ]);
    return cmd_gotopos(playerid, params);
}



CMD:ageld(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new pID, cash, string[128];
    if(sscanf(params, "ud", pID,cash))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Ageld [SpielerID/Name] [BETRAG]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    format(string,sizeof(string),"%s %s gab $%s an Spieler %s.", GetPlayerAdminRang(playerid), GetName(playerid), AddDelimiters(cash), GetName(pID));
    SendAdminMessage(COLOR_YELLOW, string);
    format(string,sizeof(string),"%s %s gab dir $%s.", GetPlayerAdminRang(playerid), GetName(playerid), AddDelimiters(cash));
    Spieler[pID][pCash] += cash;
    SendClientMessage(pID,COLOR_GREEN,string);
    return 1;
}



CMD:alevel(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new pID, level, string[128];
    if(sscanf(params, "ud", pID,level))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Alevel [SpielerID/Name] [Anzahl]");
    if(!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (level + Spieler[pID][pLevel] < 0 || level + Spieler[pID][pLevel] > 100) return SendClientMessage(playerid, COLOR_RED, "Der Spieler kann nicht unter 0 oder über 100 Level haben.");
    format(string,sizeof(string),"%s %s gab %d Level an Spieler %s.", GetPlayerAdminRang(playerid), GetName(playerid), level, GetName(pID));
    SendAdminMessage(COLOR_YELLOW, string);
    format(string,sizeof(string),"%s %s gab dir %d Level.", GetPlayerAdminRang(playerid), GetName(playerid), level);
    Spieler[pID][pLevel] += level;
    SetPlayerScore(pID, Spieler[pID][pLevel]);
    SendClientMessage(pID,COLOR_GREEN,string);
    return 1;
}



CMD:arp(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new pID, respect, string[128];
    if(sscanf(params, "ud", pID,respect))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Arp [SpielerID/Name] [Anzahl]");
    if(!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (respect + Spieler[pID][pExp] < 0) return SendClientMessage(playerid, COLOR_RED, "Der Spieler kann nicht unter 0 Respektpunkte haben.");
    format(string,sizeof(string),"%s %s gab %d Respektpunkte an Spieler %s.", GetPlayerAdminRang(playerid), GetName(playerid), respect, GetName(pID));
    SendAdminMessage(COLOR_YELLOW, string);
    format(string,sizeof(string),"%s %s gab dir %d Respektpunkte.", GetPlayerAdminRang(playerid), GetName(playerid), respect);
    GivePlayerRP(pID, respect);
    SendClientMessage(pID,COLOR_GREEN,string);
    return 1;
}



CMD:cprison(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new pID, grund[64], anzahl;
    if(sscanf(params, "uis[64]", pID, anzahl,grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/cprison [SpielerID/Name] [Anzahl] [Grund]");
    if(!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    return GiveCheckpointPrison(pID, anzahl, grund, playerid);
}



CMD:gebeclub(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new giveid, option, name[MAX_PLAYER_NAME], Spielername[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]d",Spielername,option)) {
        SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Gebeclub [Spielername] [Option]");
        SendClientMessage(playerid, COLOR_ORANGE, "1 = 1 Monat Club");
        SendClientMessage(playerid, COLOR_ORANGE, "2 = 3 Monate Club");
        SendClientMessage(playerid, COLOR_ORANGE, "3 = 6 Monate Club");
        SendClientMessage(playerid, COLOR_ORANGE, "4 = Life-Time Club");
        return 1;
    }
    if( !( 1 <= option <= 4) ) {
        SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Gebeclub [Spielername] [Option]");
        SendClientMessage(playerid, COLOR_ORANGE, "1 = 1 Monat Club");
        SendClientMessage(playerid, COLOR_ORANGE, "2 = 3 Monate Club");
        SendClientMessage(playerid, COLOR_ORANGE, "3 = 6 Monate Club");
        SendClientMessage(playerid, COLOR_ORANGE, "4 = Life-Time Club");
        return 1;
    }
    mysql_real_escape_string(Spielername,name);
    if(strcmp(Spielername,name))return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Gebeclub [Spielername (Keine Sonderzeichen)] [Option]");
    Spielername = name;
    sscanf(Spielername,"u",giveid);
    if( IsPlayerConnected(giveid) ) {
        new year, month, day, unix, m, d, h,
            minute, sec, timestr[16], String[200];
        getdate(year,month,day);
        switch(option) {
            case 1: {
                unix = gettime() + MonthTimes[ month - 1][0 + IsLeapYear(year)]*24*60*60;
            }
            case 2: {
                new
                    days = 0;
                for(new i = 0 ; i < 3 ; i++) {
                    days += MonthTimes[ month - 1 + i][0 + IsLeapYear(year)];
                }
                unix = gettime() + days*24*60*60;
            }
            case 3: {
                new
                    days = 0;
                for(new i = 0 ; i < 6 ; i++) {
                    days += MonthTimes[ month - 1 + i][0 + IsLeapYear(year)];
                }
                unix = gettime() + days*24*60*60;
            }
            case 4: {
                if( IsLeapYear(year) ) {
                    unix = gettime() + 1825*24*60*60;
                } else {
                    unix = gettime() + 1825*24*60*60;
                }
            }
        }
        TimestampToDate( unix , year,m,d,h,minute,sec,1,0);
        format(timestr, sizeof(timestr), "%d/%d/%d", d,m,year);
        format(String,sizeof(String),"Deine Clubmitgliedschaft wurde freigeschaltet und läuft am %s ab.",timestr);
        SendClientMessage(giveid,COLOR_YELLOW,String);
        format(String,sizeof(String),"Du hast die Clubmitgliedschaft für %s bis zum %s (Option %d) freigeschaltet.",GetName(giveid),timestr,option);
        SendClientMessage(playerid,COLOR_YELLOW,String);
        Spieler[giveid][pDonateRank] = 1;
        Spieler[giveid][pLevel] += 1;
        Spieler[giveid][pExp] += 10;
        Spieler[giveid][pCash] += 200000;
        format(String,sizeof(String),"%s %s hat die Clubmitgliedschaft für %s bis zum %s (Option %d) freigeschaltet.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(giveid), timestr, option);
        ClubLog(String);
    } else {
        new String[70];
        PlayerSQLExtra(playerid,params);
        format(String,sizeof(String),"SELECT `Name` FROM `accounts` WHERE `Name` = '%s' LIMIT 1",Spielername);
        mysql_pquery(String,THREAD_GEBECLUB,playerid,gSQL,MySQLThreadOwner);

    }
    return 1;
}



CMD:waffensperre(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new giveid, Spielername[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",Spielername)) return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Waffensperre [Spielername]");
    mysql_real_escape_string(Spielername,Spielername);
    if(strcmp(Spielername,params)) return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Waffensperre [Spielername (Keine Sonderzeichen)]");
    new String[128];
    sscanf(Spielername,"u",giveid);
    if( IsPlayerConnected(giveid) ) {
        new query[256];
        format(String,sizeof(String),"Du hast Spieler %s eine Waffensperre für 2 Tage vergeben",GetName(giveid));
        SendClientMessage(playerid,COLOR_RED,String);
        format(String,sizeof(String),"%s %s hat dir eine Waffensperre für 2 Tage erteilt", GetPlayerAdminRang(playerid), GetName(playerid));
        SendClientMessage(giveid,COLOR_RED,String);
        Spieler[giveid][pWaffenSperre] = gettime() + 2*24*60*60;
        format(query,sizeof(query),"%s erhielt von %s %s eine Waffensperre, Dauer: 2 Tage", GetName(giveid), GetPlayerAdminRang(playerid), GetName(playerid));
        SendUCPAktenEintrag( playerid,GetName(playerid) , GetName(giveid) , query );
    } else {
        new playerName[MAX_PLAYER_NAME];
        GetPVarString(playerid, "WEAPON.BLOCK", playerName, sizeof(playerName));
        if (!isnull(playerName)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du erteilst gerade noch jemandem offline eine Waffensperre.");
        SetPVarString(playerid, "WEAPON.BLOCK", Spielername);
        format(String,sizeof(String),"SELECT `Name` FROM `accounts` WHERE `Name` = '%s' LIMIT 1",Spielername);
        mysql_pquery(String,THREAD_WAFFENSPERRE,playerid,gSQL,MySQLThreadOwner);
    }
    return 1;
}



CMD:carowner(playerid) {
    if (Spieler[playerid][pAdmin] < 3) return ERROR_RANG_MSG(playerid);
    new vehicleid = IsPlayerInAnyVehicle(playerid) ? GetPlayerVehicleID(playerid) : GetClosestVehicle(playerid, 10.0);
    if (vehicleid == INVALID_VEHICLE_ID ) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht in der Nähe eines Fahrzeuges.");
    new besitzer = GetCarOwner(vehicleid);
    if (!IsPlayerConnected(besitzer)) return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug gehört keinem Spieler.");
    return SCMFormatted(playerid, COLOR_ORANGE, "Dieses Fahrzeug gehört %s [%s (ID: %i)].", GetName(besitzer), GetVehicleName(GetVehicleModel(vehicleid)), vehicleid);
}



CMD:offtban(playerid, params[]) {
    new sName[24], grund[64], time;
    if(sscanf(params, "s[24]is[64]", sName, time, grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/offtban [Name] [Zeit in Min.] [Grund]");
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    if(time < 1 || time > 14400)return SendClientMessage(playerid, COLOR_ORANGE, "Die Zeit sollte sich zwischen 1 und 14400 liegen. (1 Minute oder 10 Tage)");
    // -> THREADED
    new query[256], tBanTime = time * 60;
    tBanTime = tBanTime + gettime();
    mysql_real_escape_string(sName,sName);
    mysql_real_escape_string(grund,grund);
    format(query,sizeof(query),"UPDATE `accounts` SET `GebanntVon` = '%s' ,`BanGrund` = '%s' ,`TimeBan` = %d WHERE `Name` = '%s'",GetName(playerid),grund,tBanTime,sName);
    mysql_pquery(query,THREAD_OFFTBAN,playerid,gSQL,MySQLThreadOwner);
    query[0] = '\0';
    format(query,sizeof(query),"[OFFLINE-TBAN] Spieler %s wurde von %s für %d Minuten vom Server gebannt! ( OFFLINE TBAN )",sName,GetName(playerid) ,time);
    SendAdminMessage(COLOR_RED, query);
    query[0] = '\0';
    format(query,sizeof(query),"%s wurde von %s %s offline für %d Minuten gebannt, Grund: %s", sName, GetPlayerAdminRang(playerid), GetName(playerid), time, grund);
    SendUCPAktenEintrag( playerid, GetName(playerid) , sName , query );
    return 1;
}



CMD:offcprison(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 3)return ERROR_RANG_MSG(playerid);
    new sName[MAX_PLAYER_NAME], grund[64], anzahl;
    if(sscanf(params, "s[24]is[64]", sName, anzahl,grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/offcprison [Name] [Anzahl] [Grund]");
    new String[256];
    format(String,sizeof(String),"[OFFLINE-CPRISON] Spieler %s wurde von %s %s zum Checkpoint-Lauf verdonnert!", sName, GetPlayerAdminRang(playerid), GetName(playerid));
    SendAdminMessage(COLOR_RED,String);
    format(String,sizeof(String),"[OFFLINE-CPRISON] Checkpoints: %d, Grund: %s",anzahl,grund);
    SendAdminMessage(COLOR_RED,String);
    mysql_real_escape_string(sName,sName);
    mysql_real_escape_string(grund,grund);
    format(String,sizeof(String),"Spieler %s wurde von %s %s zum Checkpoint-Lauf verdonnert! Checkpoints: %d, Grund: %s", sName, GetPlayerAdminRang(playerid), GetName(playerid), anzahl, grund);
    SendUCPAktenEintrag( playerid, GetName(playerid) ,  sName , String );
    String[0] = '\0';
    format(String,sizeof(String),"UPDATE `accounts` SET `PrisonRunCount` = %d ,`PrisonRun` = %d WHERE `Name` = '%s'",0,anzahl,sName);
    mysql_pquery(String,THREAD_OFFCPRISON,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:offverwarnen(playerid,params[]) {
    new giveid, spieler[MAX_PLAYER_NAME], punkte,reason[500];
    if(Spieler[playerid][pAdmin] >= 3) {
        if( sscanf(params,"s[32]ds",spieler,punkte,reason)) {
            return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Offverwarnen [Spieler] [Anzahl] [Grund]");
        }
        sscanf(spieler,"u",giveid);
        if(IsPlayerConnected(giveid)) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist gerade online.");
        }
        new String[128+32];
        if(strlen(reason)!=0) {
            if( punkte > 0 ) {
                if( punkte > 5 ) {
                    return SendClientMessage(playerid, COLOR_RED, "Du kannst maximale 5 Verwarnungen vergeben!");
                }
                format(String,sizeof(String),"Du hast %d Verwarnungen gegen den Spieler %s ausgesprochen.",punkte, spieler);
                SendClientMessage(playerid,COLOR_GREEN,String);
                format(String, sizeof(String), "[OFF-A-WARN]: %s %s hat %d Verwarnungen gegen den Spieler %s ausgesprochen, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), abs(punkte), spieler, reason);
                SendAdminMessage(COLOR_RED, String);
                // Spieler[giveid][pWarns] += punkte;
            } else if ( punkte < 0 ) {
                if( punkte < -5 ) {
                    return SendClientMessage(playerid, COLOR_RED, "Du kannst maximale 5 Verwarnungen abziehen!");
                }
                format(String,sizeof(String),"Du hast %d Verwarnungen bei Spieler %s gelöscht",abs(punkte), spieler);
                SendClientMessage(playerid,COLOR_GREEN,String);
                format(String, sizeof(String), "[OFF-A-WARN]: %s %s hat %d Verwarnungen von Spieler %s entfernt, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), abs(punkte), spieler, reason);
                SendAdminMessage(COLOR_RED, String);
            } else {
                return SendClientMessage(playerid, COLOR_RED, "Diese Aktion ist sinnlos.");
            }
        } else {
            SendClientMessage(playerid,COLOR_RED,"Du musst einen Grund angeben.");
        }
        mysql_real_escape_string(spieler,spieler);
        format(String,sizeof(String),"UPDATE `accounts` SET `Warns` = `Warns` + %d WHERE `Name` = '%s'",punkte,spieler);
        mysql_pquery(String,THREAD_OFFVERWARNEN,playerid,gSQL,MySQLThreadOwner);
    }
    else return ERROR_RANG_MSG(playerid);
    new query[256];
    format(query,sizeof(query),"%s %s hat %d Adminverwarnung(en) gegen den Spieler %s ausgesprochen, Grund: %s", GetPlayerAdminRang(playerid), GetName(playerid), punkte, spieler, reason);
    SendUCPAktenEintrag( playerid, GetName(playerid) , spieler , query );

    return 1;
}