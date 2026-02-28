
#include <YSI\y_hooks>


enum e_KampfShop {
	Float:KS_fX,
	Float:KS_fY,
	Float:KS_fZ,
	KS_iInterior,
	KS_iVirtualWorld
}
new const g_KampfShop[][e_KampfShop] = {
	{BEACH_FIGHTINGSTYLE_POINT, 0, 0}
};


CMD:einstellungen(playerid){
    new String[1024];
    format(String, sizeof(String), "{FFFFFF}");
    if(Spieler[playerid][pSpawnChange] == 0){
        format(String, sizeof(String), "%sSpawn: Neulingsspawn\n", String);
    }else if(Spieler[playerid][pSpawnChange] == 1){
        format(String, sizeof(String), "%sSpawn: Haus\n", String);
    }else if(Spieler[playerid][pSpawnChange] == 2){
        format(String, sizeof(String), "%sSpawn: Fraktionsspawn\n", String);
    }else if(Spieler[playerid][pSpawnChange] == 3){
        format(String, sizeof(String), "%sSpawn: Alternativer Fraktionsspawn\n", String);
    }

    if(Spieler[playerid][pFRadarStatus] == 0){
        format(String, sizeof(String), "%sFRadar: Ausgeschaltet\n", String);
    }else if(Spieler[playerid][pFRadarStatus] == 1){
        format(String, sizeof(String), "%sFRadar: Eingeschaltet\n", String);
    }

    if(Spieler[playerid][DmgTog] == 0){
        format(String, sizeof(String), "%sDamage Sound: Ausgeschaltet\n", String);
    }else if(Spieler[playerid][DmgTog] == 1){
        format(String, sizeof(String), "%sDamage Sound: Eingeschaltet\n", String);
    }

    ShowPlayerDialog(playerid, DIALOG_SETTINGS, DIALOG_STYLE_LIST, "Einstellungen", String, "Ändern", "Schließen");
    return 1;
}

CMD:fradar(playerid, params[]) {
	if (Spieler[playerid][pFRadarStatus] == 0) {
        if (Spieler[playerid][pFraktion] == 0) return SendClientMessage(playerid, COLOR_RED, "Du kannst diesen Befehl nicht nutzen!");
	    SendClientMessage(playerid, COLOR_GREEN, "[FRADAR] Du hast das FRadar eingeschaltet!");
  		Spieler[playerid][pFRadarStatus] = 1;
	} else {
	    SendClientMessage(playerid, COLOR_RED, "[FRADAR] Du hast das FRadar ausgeschaltet!");
	    Spieler[playerid][pFRadarStatus] = 0;
	}
	return 1;
}

CMD:upgradeinfo(playerid,params[])
{
	new string[516];
	format(string,sizeof(string),"Punkte\tLevel\tJob");
	format(string,sizeof(string),"%s\n%i von %i\t%i von %i\tHure",string,Spieler[playerid][pHurePoints],GetNeededSkill(playerid,1),GetPlayerHureLevel(playerid), sizeof(g_HureSkill));
	format(string,sizeof(string),"%s\n%i von %i\t%i von %i\tAnwalt",string,Spieler[playerid][pLawyerPoints],GetNeededSkill(playerid,2),GetPlayerLawyerLevel(playerid), sizeof(g_LawyerSkills));
	format(string,sizeof(string),"%s\n%i von %i\t%i von %i\tDedektiv",string,Spieler[playerid][pDetektivPoints],GetNeededSkill(playerid,3),GetPlayerDetectivLevel(playerid), sizeof(g_DetektivSkill));
	format(string,sizeof(string),"%s\n%i von %i\t%i von %i\tDrogendealer",string,Spieler[playerid][pDrogenPoints],GetNeededSkill(playerid,4),GetPlayerDrogenSkillLevel(playerid), sizeof(g_DrogenSkills));
	format(string,sizeof(string),"%s\n%i von %i\t%i von %i\tWaffendealer",string,Spieler[playerid][pWaffenteilePoints],GetNeededSkill(playerid,5),GetPlayerWaffenteileSkillLevel(playerid), sizeof(g_WaffenteileSkills));
    format(string,sizeof(string),"%s\n%i von %i\t%i von 5\tSamen-Skill",string,Spieler[playerid][pSpiceSamenPoints],GetNeededSkill(playerid,6),GetPlayerSamenSkillLevel(playerid));
    format(string,sizeof(string),"%s\n%i von %i\t%i von 5\tPiloten-Skill",string,Spieler[playerid][pPilotPoints],GetNeededSkill(playerid,7),GetPlayerSamenSkillLevel(playerid));
	if(IsAFightFaction(Spieler[playerid][pFraktion]))
	{
		format(string,sizeof(string),"%s\n%i von %i\t%i von %i\tGangFight",string,Spieler[playerid][pKillsGangFight],GetNeededSkill(playerid,7),GetPlayerGangFightSkillLevel(playerid), sizeof(g_GangFightSkills));
	}
	ShowPlayerDialog(playerid,0 ,DIALOG_STYLE_TABLIST_HEADERS,""COLOR_HEX_ORANGE"Skill-Level",string,"OK","");
	return 1;
}

CMD:skill(playerid, params[]) {
    new giveid = playerid;
    if (!isnull(params) && sscanf(params, "u", giveid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Skill [Spieler/ID]");
    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid,COLOR_RED, "Der Spieler konnte nicht gefunden werden.");
    if(Spieler[giveid][pAdminDienst]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist im Admindienst.");

    if (giveid != playerid) {
        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);
        if (!IsPlayerInRangeOfPoint(giveid, 5.0, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    }
    
    new String[128];
    if (giveid != playerid) {
        format(String, sizeof(String), "Du siehst nun die Skills von %s {FFFF00}[%d]", GetName(playerid), playerid);
        SendClientMessage(giveid, COLOR_WHITE, String);
    }
    
    new string1[256];
    new string2[256];
    new string3[256];
    new string4[256];
    new string5[256];
    new string6[256];
    new string7[256];
    new string8[256];
    new string9[256];
    new stringGESAMT[1792];
    
    format(string1, sizeof(string1), "{FFFF00}Detektiv-Skill: {FFFFFF}%d/%d (%d Sekunden)", GetPlayerDetectivLevel(playerid), sizeof(g_DetektivSkill), GetPlayerDetectivSkillValue(playerid));
    format(string2, sizeof(string2), "{FFFF00}Huren-Skill: {FFFFFF}%d/%d (%d HP)", GetPlayerHureLevel(playerid), sizeof(g_HureSkill), GetPlayerHureSkillValue(playerid));
    format(string3, sizeof(string3), "{FFFF00}Anwalt-Skill: {FFFFFF}%d/%d (Bis %d Knastzeit)", GetPlayerLawyerLevel(playerid), sizeof(g_LawyerSkills), GetPlayerLawyerSkillValue(playerid));
    format(string4, sizeof(string4), "{FFFF00}Gangfight-Skill: {FFFFFF}%d/%d (Kills: %d)", GetPlayerGangFightSkillLevel(playerid), sizeof(g_GangFightSkills), Spieler[playerid][pKillsGangFight]);
    format(string5, sizeof(string5), "{FFFF00}Drogen-Skill: {FFFFFF}%d/%d (Bis zu %d Päckchen)", GetPlayerDrogenSkillLevel(playerid), sizeof(g_DrogenSkills), GetPlayerDrogenSkillValue(playerid));
    format(string6, sizeof(string6), "{FFFF00}Waffenteile-Skill: {FFFFFF}%d/%d (Bis zu %d Päckchen)", GetPlayerWaffenteileSkillLevel(playerid), sizeof(g_WaffenteileSkills), GetPlayerWaffenteileSkillValue(playerid));
    format(string7, sizeof(string7), "{FFFF00}Streetwar-Kills: {FFFFFF}%d Kills", Spieler[giveid][pKillsStreetwar]);
    format(string8, sizeof(string8), "{FFFF00}Samen-Skill: {FFFFFF}%d/5 (Bis zu %d Päckchen)", GetPlayerSamenSkillLevel(playerid), GetPlayerSamenSkillLevelValue(playerid));
    format(string9, sizeof(string9), "{FFFF00}Piloten-Skill: {FFFFFF}%d/5", GetPlayerPilotSkillLevel(playerid));
    
    format(stringGESAMT,sizeof(stringGESAMT),"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",string1,string2,string3,string4,string5,string6,string7,string8,string9);
    
    ShowPlayerDialog(giveid, DIALOG_DUMMY, DIALOG_STYLE_MSGBOX, ""COLOR_HEX_YELLOW"Skills", stringGESAMT, "Ok", "Abbrechen");
    return 1;
}

CMD:pass(playerid,params[]) {
    new giveid, search[16];
    format(search, sizeof(search), "U(%d)", playerid);
    if (sscanf(params, search, giveid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Pass ([ID/Name])");
    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler wurde nicht gefunden.");
    if(Spieler[giveid][pAdminDienst]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist im Admindienst.");

    new job[50], message[128], Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if (!IsPlayerInRangeOfPoint(giveid, 5.0, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");

    new playerName[MAX_PLAYER_NAME];
    playerName = GetName(playerid);
    if (giveid != playerid) {
        format(message, sizeof(message), "* %s zeigt dir seinen Personalausweis.", playerName);
        SendClientMessage(giveid, COLOR_PURPLE, message);
        format(message, sizeof(message), "Du hast %s deinen Personalausweis gezeigt.", GetName(giveid));
        SendClientMessage(playerid, COLOR_PURPLE, message);
    }
    SendClientMessage(giveid, COLOR_BLUE, "======PERSONALAUSWEIS======");
    format(message, sizeof(message), "Besitzer: %s", playerName);
    SendClientMessage(giveid, COLOR_YELLOW, message);
    ReturnPlayerJob(playerid, job);
    format(message, sizeof(message), "Beruf: %s", job);
    SendClientMessage(giveid, COLOR_YELLOW, message);
    format(message, sizeof(message), "Staatsbürger: %s", Spieler[playerid][pStaat]);
    SendClientMessage(giveid, COLOR_YELLOW, message);
    SendClientMessage(giveid, COLOR_BLUE, "============================");
    return 1;
}

CMD:loben(playerid,params[]) {
    new
        giveid;
    if(sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Loben [Spieler]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid,COLOR_RED,"Der Spieler ist nicht online.");
    }
    if( playerid == giveid ) {
        return SendClientMessage(playerid,COLOR_RED,"Du kannst dich selber nicht loben.");
    }
    if( Spieler[giveid][pAdminDienst] ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist gerade im Admindienst.");
    new
        String[140];
    SetPVarString(playerid,"Loben",params);
    // SpielerGelobt(giveid);
    format(String,sizeof(String),"SELECT COUNT(*) AS `Anzahl` FROM `lob` WHERE `lobender` = '%s'  AND `datum` = CURDATE()",GetName(playerid));
    mysql_pquery( String , THREAD_LOBENSELECT , playerid, gSQL,MySQLThreadOwner );
    return 1;
}



CMD:oldname(playerid, params[]){
    new pID;
    if(sscanf(params,"u",pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Oldname [Name]");
    if (pID == INVALID_PLAYER_ID || !gPlayerLogged[pID]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online.");
    if(!strcmp(Spieler[pID][pOldname], "NULL")){
        SendClientMessage(playerid, COLOR_YELLOW, "[OLDNAME] Der Spieler hat keinen Oldname.");
        return 1;
    }
    SCMFormatted(playerid, COLOR_YELLOW, "[OLDNAME] {FFFFFF}Der Oldname von %s lautet %s.", GetName(pID), Spieler[pID][pOldname]);
    return 1;
}


ocmd:changepw(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist im AFK-Modus.");
	ShowPlayerDialog(playerid, DIALOG_CHANGEPW, DIALOG_STYLE_PASSWORD, "{9B2736}Live Your Dream {FFFFFF}| Passwortchange", "{FFFFFF}Wir haben unseren Sicherheitsstandard geändert.\nDu hast die Möglichkeit dir ein neues Passwort zu erstellen, um deinen Account sicherer zu machen.\nBitte gebe nun dein neues Passwort an:", "Ändern", "Abbrechen");
	return 1;
}


CMD:afk(playerid,params[])
{
    #pragma unused params
    if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du bist Tot.");
    if(damagesperre[playerid]>0 || Tazered[playerid] == 1) return SendClientMessage(playerid, COLOR_RED,"Du kannst jetzt nicht einfach AFK gehen.");
    if(Spieler[playerid][pJailed] == 3)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich im Admin-Prison. Diese Funktion ist hier nicht möglich.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Du bist bereits im AFK-Modus.");

    new Float:vhealth, vid = GetPlayerVehicleID(playerid);
    GetVehicleHealth(vid, vhealth);
    if (vid != 0 && (vhealth < 250 || GetPlayerState(playerid) == PLAYER_STATE_DRIVER && GetPlayerVehicleSpeed(playerid) > 2.0))return SendClientMessage(playerid, COLOR_RED, "Du kannst jetzt nicht einfach afk gehen.");

    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst gerade nicht AFK gehen.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nicht während du fällst AFK gehen.");

    IsAFK[playerid] = 1;
    SendClientMessage(playerid, COLOR_ORANGE, "Du bist nun im AFK-Modus. Deine Zahltag-Zeit(PayDay) läuft nun nicht mehr weiter.");
    SendClientMessage(playerid, COLOR_ORANGE, "Mit /Back verlässt du den AFK-Modus wieder.");
    paydaywait[playerid]=1;
    FreezePlayer(playerid);
    sAFKTimer[playerid] = SetTimerEx("AFKTimer", 1000 ,false,"d",playerid);
    UpdateDynamic3DTextLabelText(Spieler[playerid][pAFKLabel], 0xC2A2DAFF, "Im AFK-Modus\nSeit 0 Sekunden");
    Spieler[playerid][unixAFKNotice] = gettime() + 5*60 ;
    return 1;
}

CMD:back(playerid)
{
    if(Spieler[playerid][pTot] == 1 || Spieler[playerid][pTot] == 2 )return SendClientMessage(playerid, COLOR_RED, "Du bist Tot.");
    if(Spieler[playerid][pJailed] == 3)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich im Admin-Prison. Diese Funktion ist hier nicht möglich.");
    if(IsAFK[playerid] == 1)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Du bist nun nicht mehr im AFK-Modus.");
        SendClientMessage(playerid, COLOR_GREEN, "Dein Zahltag läuft nun weiter.");
        paydaywait[playerid] = 0;
        IsAFK[playerid] = 0;
        UnfreezePlayer(playerid);
        KillTimer(sAFKTimer[playerid]);
        pAFKTimer[playerid] = 0;
        pAFKMinute[playerid] = 0;
        UpdateDynamic3DTextLabelText(Spieler[playerid][pAFKLabel], COLOR_PURPLE, " ");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht im AFK-Modus.");
        return 1;
    }
    return 1;
}



CMD:spawnchange(playerid) return cmd_einstellungen(playerid);



CMD:post(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid,10,822.3183,1.8747,1004.1797))
    {
        ShowPlayerDialog(playerid,DIALOG_POST,DIALOG_STYLE_LIST,"Post","Ungelesene Post\nPost schreiben\nEmpfangene Post\nGesendete Post","Auswählen","Abbrechen");
    }
    return 1;
}


CMD:staatswechsel(playerid) {
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
	if(!IsPlayerInRangeOfPoint(playerid, 2.0, CITYHALL_INTERIOR_STATECHANGE)) return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Du kannst hier nicht deine Staatsangehörigkeit wechseln!");
	if(CheckMoney(playerid) < 100000)return SendClientMessage(playerid, COLOR_ORANGE, "[FEHLER] {FFFFFF}Ein Wechsel der Staatsangehörigkeit kostet dich $100.000.");
	ShowPlayerDialog(playerid,DIALOG_STAATSANGEHORIGKEIT, DIALOG_STYLE_INPUT,""COLOR_HEX_ORANGE"Staatsangehörigkeit","{FFFFFF}Bitte gebe nun deine Staatsangehörigkeit ein:","Akzeptieren","Abbrechen");
	return 1;
}


CMD:zahlen(playerid, params[])
{
    new pID, betrag, string[128], grund[120];
    if(sscanf(params, "uis[120]", pID, betrag,grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Zahlen [SpielerID/Name] [Betrag] [Grund]");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber kein Geld geben.");
    if(betrag < 1 ||  betrag > 50000)return SendClientMessage(playerid, COLOR_RED, "Der Betrag sollte zwischen $1 und $50.000 liegen.");
    if( strlen(grund) < 3 ) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Zahlen [SpielerID/Name] [Betrag] [Grund] ( 3 Zeichen mindestens )");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[playerid][pLevel] < 3 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du musst Level 3 erreicht haben, um diese Funktion nutzen zu können.");
    }
    if(Spieler[pID][pLevel] < 3 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du kannst dem Spieler kein Geld zahlen, da er unter Level 3 ist!");
    }
    if( Spieler[pID][pAdminDienst] ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist gerade im Admindienst");
    }
    if(Spieler[pID][pJailed] == 3) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst Gefangenen kein Geld geben.");
    }
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    if(Spieler[playerid][pJailed] > 1 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst aus dem Gefängnis heraus kein Geld geben.");
    }
    if(!IsPlayerInRangeOfPoint(playerid, 7.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
    if(betrag > CheckMoney(playerid))return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld.");
    GivePlayerCash(playerid, -betrag);
    GivePlayerCash(pID, betrag);
    format(string, sizeof(string), "* %s gab %s Geld.", GetName(playerid), GetName(pID));
    SendRoundMessage(x,y,z, COLOR_PURPLE, string);
    format(string, sizeof(string), "%s hat dir $%s gegeben. Grund: %s", GetName(playerid), AddDelimiters(betrag), grund);
    SendClientMessage(pID, COLOR_YELLOW, string);
    format(string, sizeof(string), "Du hast %s $%s gegeben. Grund: %s", GetName(pID), AddDelimiters(betrag), grund);
    SendClientMessage(playerid, COLOR_YELLOW, string);
    new ort[24], zahlenlog[156], playerIP[16], pIDIP[16];
    GetPlayer2DZone(playerid, ort, 24);
    GetPlayerIp(playerid, playerIP, 16);
    GetPlayerIp(pID, pIDIP, 16);
    format(zahlenlog, sizeof(zahlenlog), "Name: %s (IP: %s) - An: %s (IP: %s) - Geld: %d - Grund: %s - Ort: %s", GetName(playerid), playerIP, GetName(pID), pIDIP, betrag, grund,ort);
    PayLog(zahlenlog);
    if( betrag >= MONEY_ALERT_VALUE ) {
        sendMoneyAlert(playerid,pID, AddDelimiters(betrag),grund);
    }
    return 1;
}


CMD:scheine(playerid, params[]) {
    new pID, string[128];
    if(sscanf(params, "u", pID) || pID == playerid)
    {
        Scheine(playerid, playerid);
        if (Spieler[playerid][pLevel] < 4) SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Scheine [SpielerID/Name] um jemandem die Scheine zu zeigen!");
        return 1;
    }
    if(IsPlayerConnected(pID) && gPlayerLogged[pID] == 1)
    {
        if( Spieler[pID][pAdminDienst] ) {
            return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist im Admindienst.");
        }
        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x,y,z);
        if(IsPlayerInRangeOfPoint(pID, 5.0, x,y,z))
        {
            format(string, sizeof(string), "%s hat dir angeboten seine/ihre Scheine anzuschauen.", GetName(playerid));
            SendClientMessage(pID, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "Du hast %s angeboten deine Scheine anzuschauen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            SendClientMessage(pID, COLOR_LIGHTBLUE, "Nutze '/Accept Scheine' um dir die Scheine anzuschauen.");
            format(string, sizeof(string), "%s %i", GetName(playerid), Spieler[playerid][pLoginTimestamp]);
            SetPVarString(pID, "ACCEPT.LICENSES", string);
            return 1;
        }
        else return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht in deiner Nähe.");
    }

    return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht Online.");
}

CMD:stats(playerid, params[]) {
    if(gPlayerLogged[playerid] == 0) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    new pID;
    if(sscanf(params, "u", pID) || pID == playerid)
    {
        Stats(playerid, playerid);
        if (Spieler[playerid][pLevel] < 4) SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Stats [SpielerID/Name] um jemandem die Stats zu zeigen!");
        return 1;
    }
    if(IsPlayerConnected(pID) && gPlayerLogged[pID] == 1)
    {
        if( Spieler[pID][pAdminDienst] ) {
            return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist im Admindienst.");
        }
        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x,y,z);
        if(IsPlayerInRangeOfPoint(pID, 5.0, x,y,z))
        {
            new string[128];
            format(string, sizeof(string), "%s hat dir angeboten seine/ihre Statistiken anzuschauen.", GetName(playerid));
            SendClientMessage(pID, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "Du hast %s angeboten deine Statistiken anzuschauen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            SendClientMessage(pID, COLOR_LIGHTBLUE, "Nutze '/Accept Stats' um dir die Statistiken anzuschauen.");
            AcceptStats[pID] = playerid;
            return 1;
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht in deiner Nähe.");
            return 1;
        }
    }

    return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht Online.");
}



CMD:accept(playerid, params[])
{
    new entry[30], string[128];
    if(sscanf(params, "s[30]", entry)){
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Accept [Aktion]");
        SendClientMessage(playerid, COLOR_ORANGE, "* Aktionen: Stats, Repair, Heilung, Fraktion, Spice, Drogen, Waffenteile, Wantedcodes, Scheine");
        SendClientMessage(playerid, COLOR_ORANGE, "* Aktionen: Waffen, Angelstats, Eis, Antrag, Pizza, Hotdog, Taxi, Anwalt, Vertrag, Kekse");
        return 1;
    }
    if(!strcmp(entry,"vertrag", true)) {
        new vertragspartner;
        vertragspartner = GetPlayerVertragsPartner(playerid);
        if( !IsPlayerConnected(vertragspartner)) return SendClientMessage(playerid, COLOR_RED, "Dir wurde kein Vertrag angeboten");
        new String[180], Float:x, Float:y, Float:z;
        GetPlayerPos(playerid,x,y,z);
        if( !IsPlayerInRangeOfPoint(vertragspartner,6.0,x,y,z) ) return SendClientMessage(playerid,COLOR_RED,"Dein Vertragspartner ist zu weit entfernt von dir");
        format(String,sizeof(String),"Spieler %s hat den Vertrag unterschrieben und ist mit der Einigung einverstanden!",GetName(playerid));
        SendClientMessage(vertragspartner,COLOR_YELLOW,String);
        format(String,sizeof(String),"Du bist mit der Vertragseinigung einverstanden und hast den Vertrag unterschrieben!");
        SendClientMessage(playerid,COLOR_YELLOW,String);
        format(String,sizeof(String),"Vertragspartner: %s , %s . Bedingung: %s",GetName(vertragspartner),GetName(playerid),Spieler[vertragspartner][pVertragText]);
        VertragLog(String);

        Spieler[vertragspartner][pVertragText][0] = '\0';
        Spieler[vertragspartner][pVertragID] = INVALID_PLAYER_ID;
    }
    if(strcmp(entry, "stats", true) == 0){
        if(!(AcceptStats[playerid] == 999)){
            Stats(playerid, AcceptStats[playerid]);
            format(string, sizeof(string), "%s sieht sich deine Statistiken an.", GetName(playerid));
            SendClientMessage(AcceptStats[playerid], COLOR_LIGHTBLUE, string);
            AcceptStats[playerid] = 999;
        } else {
            SendClientMessage(playerid, COLOR_RED, "Du hast keine Anfrage erhalten.");
            return 1;
        }
        return 1;
    }
    else if(strcmp(entry,"hitman",true) == 0 ) {
        if(Spieler[playerid][pFraktion] != 14 ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied.");
        if(Spieler[playerid][pHitmenAuftragID] != INVALID_PLAYER_ID ) {
            new auftraggeber = Spieler[playerid][pHitmenAuftragID], opfer = Spieler[auftraggeber][pKopfgeldID], String[128];
            format(String, sizeof(String), "Auftraggeber: %s Mordopfer: %s ($%s)", GetName(auftraggeber), GetName(opfer), AddDelimiters(Spieler[auftraggeber][pKopfgeld]));
            SendClientMessage(playerid, COLOR_YELLOW, String );
            return 1;
        }
        ShowPlayerHitmenList(playerid);
        return 1;
    }
    else if(strcmp(entry, "angelstats", true) == 0){
        new pID, pTimestamp, pVarString[40];
        GetPVarString(playerid, "SHOW.ANGELSTATS", pVarString, sizeof(pVarString));
        if (isnull(pVarString) || sscanf(pVarString, "%i %i", pID, pTimestamp))
            return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Niemand hat dir seine Angelstatistiken angeboten.");

        if (Spieler[pID][pLoginTimestamp] != pTimestamp) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht mehr online.");
        ShowAngelStats(playerid, pID);
        SCMFormatted(pID, COLOR_YELLOW, "[INFO] {FFFFFF}%s sieht sich deine Angelstatistiken an.", GetName(playerid));
        SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du siehst dir die Angelstatistiken von %s an.", GetName(pID));
        DeletePVar(playerid, "SHOW.ANGELSTATS");
    }
    else if(strcmp(entry, "carsell", true) == 0) {
        if(AcceptCarSell[playerid] != 999) {
            if(AcceptCarSellPreis[playerid] > 0) {
                new pID = AcceptCarSell[playerid];
                new Float:x, Float:y, Float:z;
                GetPlayerPos(pID, x,y,z);
                if(IsPlayerConnected(pID) && gPlayerLogged[pID]) {
                    if(!IsPlayerInRangeOfPoint(playerid, 5.0, x, y, z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
                    if(PlayerHaveCar[pID][PlayerKey[playerid]]) {
                        if(!PlayerHaveCar[playerid][PlayerKey[pID]]) {
                            if(CheckMoney(playerid) < AcceptCarSellPreis[playerid])return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld.");
                            format(string, sizeof(string), "* %s hat dir sein Fahrzeug gegeben.", GetName(playerid));
                            SendClientMessage(playerid, COLOR_YELLOW, string);
                            format(string, sizeof(string), "* Du hast dein Fahrzeug an %s gegeben.", GetName(pID));
                            SendClientMessage(pID, COLOR_YELLOW, string);
                            // new oldname[128], newname[128];
                            new Float:tx, Float:ty, Float:tz;
                            GetPlayerPos(playerid, tx, ty, tz);
                            // format(oldname, sizeof(oldname), "/Autos/%s_Car_%d.ini", GetName(pID), PlayerKey[pID]);
                            // format(newname, sizeof(newname), "/Autos/%s_Car_%d.ini", GetName(playerid), PlayerKey[playerid]);
                            // fcopy(oldname, newname);
                            // fremove(oldname);
                            if(PlayerCar[pID][PlayerKey[pID]][CarNeon1] > 0 || PlayerCar[pID][PlayerKey[pID]][CarNeon2] > 0) {
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2]);
                                PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon1] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][ObjectIDNeon2] = INVALID_OBJECT_ID;
                            }
                            if(PlayerCar[pID][PlayerKey[pID]][isSpecialTuned] > 0) {
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned2]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned3]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned4]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned5]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned6]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned7]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned8]);
                                DestroyDynamicObject(PlayerCar[pID][PlayerKey[pID]][SpecialTuned9]);
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned1] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned2] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned3] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned4] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned5] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned6] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned7] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned8] = INVALID_OBJECT_ID;
                                PlayerCar[pID][PlayerKey[pID]][SpecialTuned9] = INVALID_OBJECT_ID;
                            }
                            if(vSirene[PlayerCar[pID][PlayerKey[pID]][CarId]] != INVALID_OBJECT_ID) {
                                DestroyDynamicObject(vSirene[PlayerCar[pID][PlayerKey[pID]][CarId]]);
                            }
                            if(vNeon[PlayerCar[pID][PlayerKey[pID]][CarId]] != INVALID_OBJECT_ID) {
                                DestroyDynamicObject(vNeon[PlayerCar[pID][PlayerKey[pID]][CarId]]);
                            }
                            if(OAmtSirene[PlayerCar[pID][PlayerKey[pID]][CarId]] != INVALID_OBJECT_ID) {
                                DestroyDynamicObject(OAmtSirene[PlayerCar[pID][PlayerKey[pID]][CarId]]);
                            }
                            PlayerCar[playerid][PlayerKey[playerid]][CarId] = CreateVehicle(PlayerCar[playerid][PlayerKey[pID]][CarModel], tx, ty, tz, 0.0, PlayerCar[pID][PlayerKey[pID]][CarC1], PlayerCar[pID][PlayerKey[pID]][CarC2], -1);
                            
                            DestroyVehicleEx(PlayerCar[pID][PlayerKey[pID]][CarId]);
                            g_Parkschein[PlayerCar[pID][PlayerKey[pID]][CarId]] = 0;
                            //DestroyPeilsender(pID, PlayerKey[pID] );
                            aiVehicles[ PlayerCar[pID][PlayerKey[pID]][CarId] ] = VEH_INVALID;
                            PlayerHaveCar[pID][PlayerKey[pID]]  =0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarId]         =0;

                            format(PlayerCar[playerid][PlayerKey[playerid]][CarOwner],MAX_PLAYER_NAME,GetName(playerid) );
                            PlayerCar[playerid][PlayerKey[playerid]][Id]            =PlayerCar[pID][PlayerKey[pID]][Id];
                            PlayerCar[playerid][PlayerKey[playerid]][CarModel]      =PlayerCar[pID][PlayerKey[pID]][CarModel];
                            PlayerCar[playerid][PlayerKey[playerid]][CarPos_x]      =tx;
                            PlayerCar[playerid][PlayerKey[playerid]][CarPos_y]      =ty;
                            PlayerCar[playerid][PlayerKey[playerid]][CarPos_z]      =tz;
                            PlayerCar[playerid][PlayerKey[playerid]][CarRotate]     =0.0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarNitro]      =PlayerCar[pID][PlayerKey[pID]][CarNitro];
                            PlayerCar[playerid][PlayerKey[playerid]][CarHyd]        =PlayerCar[pID][PlayerKey[pID]][CarHyd];
                            PlayerCar[playerid][PlayerKey[playerid]][CarWheel]      =PlayerCar[pID][PlayerKey[pID]][CarWheel];
                            PlayerCar[playerid][PlayerKey[playerid]][CarAusp]       =PlayerCar[pID][PlayerKey[pID]][CarAusp];
                            PlayerCar[playerid][PlayerKey[playerid]][CarSideL]      =PlayerCar[pID][PlayerKey[pID]][CarSideL];
                            PlayerCar[playerid][PlayerKey[playerid]][CarSideR]      =PlayerCar[pID][PlayerKey[pID]][CarSideR];
                            PlayerCar[playerid][PlayerKey[playerid]][CarFB]         =PlayerCar[pID][PlayerKey[pID]][CarFB];
                            PlayerCar[playerid][PlayerKey[playerid]][CarRB]         =PlayerCar[pID][PlayerKey[pID]][CarRB];
                            PlayerCar[playerid][PlayerKey[playerid]][CarSpoiler]    =PlayerCar[pID][PlayerKey[pID]][CarSpoiler];
                            PlayerCar[playerid][PlayerKey[playerid]][CarRoof]       =PlayerCar[pID][PlayerKey[pID]][CarRoof];
                            PlayerCar[playerid][PlayerKey[playerid]][CarHood]       =PlayerCar[pID][PlayerKey[pID]][CarHood];
                            PlayerCar[playerid][PlayerKey[playerid]][CarVents]      =PlayerCar[pID][PlayerKey[pID]][CarVents];
                            PlayerCar[playerid][PlayerKey[playerid]][CarLamps]      =PlayerCar[pID][PlayerKey[pID]][CarLamps];
                            PlayerCar[playerid][PlayerKey[playerid]][CarPJ]         =PlayerCar[pID][PlayerKey[pID]][CarPJ];
                            PlayerCar[playerid][PlayerKey[playerid]][CarC1]         =PlayerCar[pID][PlayerKey[pID]][CarC1];
                            PlayerCar[playerid][PlayerKey[playerid]][CarC2]         =PlayerCar[pID][PlayerKey[pID]][CarC2];
                            PlayerCar[playerid][PlayerKey[playerid]][CarPreis]      =PlayerCar[pID][PlayerKey[pID]][CarPreis];
                            PlayerCar[playerid][PlayerKey[playerid]][CarState]      =PlayerCar[pID][PlayerKey[pID]][CarState];
                            PlayerCar[playerid][PlayerKey[playerid]][CarNeon1]      =PlayerCar[pID][PlayerKey[pID]][CarNeon1];
                            PlayerCar[playerid][PlayerKey[playerid]][CarNeon2]      =PlayerCar[pID][PlayerKey[pID]][CarNeon2];
                            PlayerCar[playerid][PlayerKey[playerid]][isSpecialTuned]=PlayerCar[pID][PlayerKey[pID]][isSpecialTuned];
                            PlayerCar[playerid][PlayerKey[playerid]][TUV]       =PlayerCar[pID][PlayerKey[pID]][TUV];
                            aiVehicles[ PlayerCar[playerid][PlayerKey[playerid]][CarId] ] = VEH_PRIVAT;
                            PlayerCar[pID][PlayerKey[pID]][Id] = 0;
                            SavePlayerCar(playerid,PlayerKey[playerid]);
                            if(PlayerCar[playerid][PlayerKey[playerid]][CarNeon1] > 0 || PlayerCar[playerid][PlayerKey[playerid]][CarNeon2] > 0) {
                                PlayerCar[playerid][PlayerKey[playerid]][ObjectIDNeon1] = CreateDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][CarNeon1], 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][ObjectIDNeon2] = CreateDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][CarNeon2], 0,0,0,0,0,0,0);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][ObjectIDNeon1], PlayerCar[playerid][PlayerKey[playerid]][CarId], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][ObjectIDNeon2], PlayerCar[playerid][PlayerKey[playerid]][CarId], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                            }
                            if(PlayerCar[playerid][PlayerKey[playerid]][isSpecialTuned] > 0) {
                                PlayerCar[playerid][PlayerKey[playerid]][isSpecialTuned] = 1;
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1] = CreateDynamicObject(1166, 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned2] = CreateDynamicObject(1168, 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned3] = CreateDynamicObject(1056, 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned4] = CreateDynamicObject(1056, 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned5] = CreateDynamicObject(1056, 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned6] = CreateDynamicObject(1056, 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned7] = CreateDynamicObject(1091, 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned8] = CreateDynamicObject(1164, 0,0,0,0,0,0,0);
                                PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned9] = CreateDynamicObject(1034, 0,0,0,0,0,0,0);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1], PlayerCar[playerid][PlayerKey[playerid]][CarId], 1.024999, 2.080000, -0.090000, 0.000000, 0.000000, 0.000000);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned2], PlayerCar[playerid][PlayerKey[playerid]][CarId],-1.066002, -1.774998, -0.130000, 0.000000, 0.000000, 0.000000);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned3], PlayerCar[playerid][PlayerKey[playerid]][CarId],-0.946998, 0.149999, -0.589998, 0.000000, 0.000000, 0.000000);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned4], PlayerCar[playerid][PlayerKey[playerid]][CarId], -0.981998, -0.169999, -0.589998, 0.000000, 0.000000, 0.000000);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned5], PlayerCar[playerid][PlayerKey[playerid]][CarId],1.008000, -0.169999, -0.589998, 0.000001, -179.995712, 0.000000);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned6], PlayerCar[playerid][PlayerKey[playerid]][CarId],0.978000, 0.174999, -0.589998, 0.000001, -179.995712, 0.000000);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned7], PlayerCar[playerid][PlayerKey[playerid]][CarId],-0.006999, 0.244999, 0.648500, 0.000001, -0.000116, 0.000000);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned8], PlayerCar[playerid][PlayerKey[playerid]][CarId], 0.000000, -2.470009, 0.368500, 0.000001, -0.000116, 0.000000);
                                AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned9], PlayerCar[playerid][PlayerKey[playerid]][CarId],-0.009999, -0.240000, -0.106499, 0.000001, -0.000116, 0.000000);
                            }
                            if(PlayerCar[playerid][PlayerKey[playerid]][isSpecialTuned] > 0) {
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
                            }
                            if(PlayerCar[playerid][PlayerKey[playerid]][isSpecialTuned] > 0) {
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
                            }
                            PlayerHaveCar[playerid][PlayerKey[playerid]] = 1;
                            LockCar(PlayerCar[playerid][PlayerKey[playerid]][CarId]);
                            PlayerCar[pID][PlayerKey[pID]][CarNeon1] = 0;
                            PlayerCar[pID][PlayerKey[pID]][CarNeon2] = 0;
                            PlayerCar[pID][PlayerKey[pID]][isSpecialTuned] = 0;
                            GivePlayerCash(playerid, -AcceptCarSellPreis[playerid]);
                            GivePlayerCash(pID, AcceptCarSellPreis[playerid]);
                            AcceptCarSell[playerid] = 999;
                            AcceptCarSellPreis[playerid] = 0;
                        } else {
                            SendClientMessage(playerid, COLOR_RED, "Der Spieler hat auf dem Schlüssel bereits ein Fahrzeug.");
                            return 1;
                        }
                    } else {
                        SendClientMessage(playerid, COLOR_RED, "Du hast auf dem Schlüssel kein Fahrzeug.");
                        return 1;
                    }
                }
            }
        } else {
            SendClientMessage(playerid, COLOR_RED, "Niemand hat dir angeboten, ein Fahrzeug zu kaufen.");
            return 1;
        }
    }
    else if (strcmp(entry, "scheine", true) == 0) {
        new offerString[128], pID, sessionStamp;
        GetPVarString(playerid, "ACCEPT.LICENSES", offerString, sizeof(offerString));
        if (isnull(offerString)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Dir hat niemand Einsicht in seine Scheine angeboten.");
        if (sscanf(offerString, "k<playername> i", pID, sessionStamp) || pID == INVALID_PLAYER_ID || Spieler[pID][pLoginTimestamp] != sessionStamp) {
            DeletePVar(playerid, "ACCEPT.LICENSES");
            return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Das Angebot ist nicht mehr gültig.");
        }

        if (!IsPlayerInRangeOfPlayer(playerid, pID, 8.0)) return SCMFormatted(playerid, COLOR_RED, "[INFO] {FFFFFF}%s ist nicht mehr in deiner Nähe.", GetName(pID));
        
        format(string, sizeof(string), "* Du siehst dir die Scheine von %s an.", GetName(pID));
        SendClientMessage(playerid, COLOR_PURPLE, string);
        format(string, sizeof(string), "* %s sieht sich deine Scheine an.", GetName(playerid));
        SendClientMessage(pID, COLOR_PURPLE, string);
        Scheine(playerid, pID);
        DeletePVar(playerid, "ACCEPT.LICENSES");
        return 1;
    }
    else if(strcmp(entry, "waffen", true) == 0)
    {
        new offerString[64], pID, sessionStamp, gID, price;
        GetPVarString(playerid, "SELL.GUN.OFFER", offerString, sizeof(offerString));
        if (isnull(offerString)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Dir liegt kein Angebot für Waffen vor.");
        if (sscanf(offerString, "k<playername> i i i", pID, sessionStamp, gID, price) || pID == INVALID_PLAYER_ID || Spieler[pID][pLoginTimestamp] != sessionStamp) {
            DeletePVar(playerid, "SELL.GUN.OFFER");
            return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Das Angebot ist nicht mehr gültig.");
        }

        if (HasWeaponBlock(playerid)) {
            DeletePVar(playerid, "SELL.GUN.OFFER");
            return SendWeaponBlockInfo(playerid);
        }

        if (Spieler[playerid][pCash] < price)
            return SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Du brauchst $%s auf der Hand um das Angebot anzunehmen.", AddDelimiters(price));

        if (!IsPlayerInRangeOfPlayer(playerid, pID, 8.0)) return SCMFormatted(playerid, COLOR_RED, "[INFO] {FFFFFF}%s ist nicht mehr in deiner Nähe.", GetName(pID));
        if (Spieler[pID][pJob] != 18) {
            DeletePVar(playerid, "SELL.GUN.OFFER");
            return SCMFormatted(playerid, COLOR_RED, "[INFO] {FFFFFF}%s ist kein Waffendealer mehr. Das Angebot ist nichtig.", GetName(pID));
        }

        if (Spieler[pID][pWaffenteile] < g_sellGuns[gID][SELL_GUN_MATS])
            return SCMFormatted(pID, COLOR_RED, "[INFO] {FFFFFF}%s hat nicht mehr genügend Waffenteile dabei.", GetName(pID));

        Spieler[pID][pWaffenteile] -= g_sellGuns[gID][SELL_GUN_MATS];
        GivePlayerWeapon(playerid, g_sellGuns[gID][SELL_GUN_ID], g_sellGuns[gID][SELL_GUN_AMMO]);
        GivePlayerCash(playerid, -price);
        GivePlayerCash(pID, price);
        SCMFormatted(playerid, COLOR_LIGHTBLUE, "[INFO] {FFFFFF}Du hast von %s %s %s für $%s gekauft.", GetName(pID), g_sellGuns[gID][SELL_GUN_INDEF_ARTICLE],\
            g_sellGuns[gID][SELL_GUN_NAME], AddDelimiters(price));

        SCMFormatted(pID, COLOR_LIGHTBLUE, "[INFO] {FFFFFF}%s hat dir %s %s für $%s abgekauft.", GetName(playerid), g_sellGuns[gID][SELL_GUN_INDEF_ARTICLE],\
            g_sellGuns[gID][SELL_GUN_NAME], AddDelimiters(price));

        DeletePVar(playerid, "SELL.GUN.OFFER");
        new logString[128], location[24];
        GetPlayer2DZone(playerid, location, sizeof(location));
        format(logString, sizeof(logString), "Name: %s - Käufer: %s - Waffe: %s - Geld: $%s - Ort: %s", GetName(pID), GetName(playerid), g_sellGuns[gID][SELL_GUN_NAME],
            AddDelimiters(price), location);

        LogWDealer(logString);
        return 1;
    }
    else if(strcmp(entry, "drogen", true) == 0)
    {
        if(!(pDrogenID[playerid] == 999))
        {
            if(IsPlayerConnected(pDrogenID[playerid]))
            {
                if(Spieler[pDrogenID[playerid]][pDrugs]>=pDrogenMenge[playerid])
                {
                    if(CheckMoney(playerid) < pDrogenPreis[playerid])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
                    GivePlayerCash(playerid, -pDrogenPreis[playerid]);
                    GivePlayerCash(pDrogenID[playerid], pDrogenPreis[playerid]);
                    //Spieler[pDrogenID[playerid]][pDrugs] -= pDrogenMenge[playerid];
                    Spieler[playerid][pDrugs] += pDrogenMenge[playerid];
                    Spieler[ pDrogenID[playerid] ][pDrugs] -= pDrogenMenge[playerid];
                    format(string, sizeof(string), "Du hast %d Gramm Drogen von %s für $%s abgekauft.", pDrogenMenge[playerid], GetName(pDrogenID[playerid]), AddDelimiters(pDrogenPreis[playerid]));
                    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                    format(string, sizeof(string), "%s hat dir %d Gramm Drogen für $%s abgekauft.", GetName(playerid), pDrogenMenge[playerid], AddDelimiters(pDrogenPreis[playerid]));
                    SendClientMessage(pDrogenID[playerid], COLOR_LIGHTBLUE, string);
                    new ort[24], ddealerlog[128];
                    GetPlayer2DZone(playerid, ort, 24);
                    // ??? format(ddealerlog, sizeof(ddealerlog), "Name: %s - Käufer: %s - Drogen: %d - Geld: %d - Ort: %s", GetName(pDrogenID[playerid]), GetName(playerid), pDrogenMenge[playerid], pDrogenPreis[playerid], ort);
                    format(ddealerlog,sizeof(ddealerlog),"%s hat %s %d Gramm für $%s verkauft.",GetName( pDrogenID[playerid] ) , GetName(playerid), pDrogenMenge[playerid] , AddDelimiters(pDrogenPreis[playerid]) );
                    DrugLog(ddealerlog);
                    pDrogenID[playerid] = 999;
                    pDrogenMenge[playerid] = 0;
                    pDrogenPreis[playerid] = 0;
                    return 1;
                }
                else
                {
                    SendClientMessage(pDrogenID[playerid], COLOR_RED, "Du besitzt nicht mehr die Menge an Drogen, die du verkaufen wolltest.");
                    SendClientMessage(playerid, COLOR_RED, "Der Verkäufer besitzt nicht mehr die Menge an Drogen, die er verkaufen wollte.");
                    return 1;
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
                return 1;
            }
        }
    }
    else if(strcmp(entry, "kekse", true) == 0)
    {
        new pVarString[128], pID, menge, preis;
        GetPVarString(playerid, "BUY_COOKIES", pVarString, sizeof(pVarString));
        if (sscanf(pVarString, "uii", pID, menge, preis)) return SendClientMessage(playerid, COLOR_RED, "Du hast kein Angebot für Kekse erhalten.");
        if(IsPlayerConnected(pID))
        {
            if(Spieler[pID][pKekse] >= menge)
            {
                if(CheckMoney(playerid) < preis) return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
                GivePlayerCash(playerid, -preis);
                GivePlayerCash(pID, preis);
                Spieler[playerid][pKekse] += menge;
                Spieler[pID][pKekse] -= menge;
                format(pVarString, sizeof(pVarString), "Du hast %d Kekse von %s für $%s abgekauft.", menge, GetName(pID), AddDelimiters(preis));
                SendClientMessage(playerid, COLOR_LIGHTBLUE, pVarString);
                format(pVarString, sizeof(pVarString), "%s hat dir %d Kekse für $%s abgekauft.", GetName(playerid), menge, AddDelimiters(preis));
                SendClientMessage(pID, COLOR_LIGHTBLUE, pVarString);
                new ort[24], ddealerlog[128];
                GetPlayer2DZone(playerid, ort, 24);
                // ??? format(ddealerlog, sizeof(ddealerlog), "Name: %s - Käufer: %s - Drogen: %d - Geld: %d - Ort: %s", GetName(pDrogenID[playerid]), GetName(playerid), pDrogenMenge[playerid], pDrogenPreis[playerid], ort);
                format(ddealerlog,sizeof(ddealerlog),"%s hat %s %d Kekse für $%s verkauft.", GetName(pID) , GetName(playerid), menge, AddDelimiters(preis));
                CookiesLog(ddealerlog);
                DeletePVar(playerid, "BUY_COOKIES");

                return 1;
            }
            else
            {
                SendClientMessage(pID, COLOR_RED, "Du besitzt nicht mehr die Menge an Keksen, die du verkaufen wolltest.");
                SendClientMessage(playerid, COLOR_RED, "Der Verkäufer besitzt nicht mehr die Menge an Keksen, die er verkaufen wollte.");
                return 1;
            }
        }
        else
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    }
    else if(strcmp(entry, "wantedcodes", true) == 0)
    {
        new pVarString[128], pID, menge, preis;
        GetPVarString(playerid, "BUY_WCODES", pVarString, sizeof(pVarString));
        if (sscanf(pVarString, "uii", pID, menge, preis)) return SendClientMessage(playerid, COLOR_RED, "Du hast kein Angebot für Wantedcodes erhalten.");
        if(IsPlayerConnected(pID))
        {
            if(Spieler[pID][pWantedCodes] >= menge)
            {
                if(CheckMoney(playerid) < preis) return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
                GivePlayerCash(playerid, -preis);
                GivePlayerCash(pID, preis);
                Spieler[playerid][pWantedCodes] += menge;
                Spieler[pID][pWantedCodes] -= menge;
                format(pVarString, sizeof(pVarString), "Du hast %d Wantedcodes von %s für $%s abgekauft.", menge, GetName(pID), AddDelimiters(preis));
                SendClientMessage(playerid, COLOR_LIGHTBLUE, pVarString);
                format(pVarString, sizeof(pVarString), "%s hat dir %d Wantedcodes für $%s abgekauft.", GetName(playerid), menge, AddDelimiters(preis));
                SendClientMessage(pID, COLOR_LIGHTBLUE, pVarString);
                new ort[24], ddealerlog[128];
                GetPlayer2DZone(playerid, ort, 24);
                // ??? format(ddealerlog, sizeof(ddealerlog), "Name: %s - Käufer: %s - Drogen: %d - Geld: %d - Ort: %s", GetName(pDrogenID[playerid]), GetName(playerid), pDrogenMenge[playerid], pDrogenPreis[playerid], ort);
                format(ddealerlog,sizeof(ddealerlog),"%s hat %s %d Codes für $%s verkauft.", GetName(pID) , GetName(playerid), menge, AddDelimiters(preis));
                WCodeLog(ddealerlog);
                DeletePVar(playerid, "BUY_WCODES");
            }
            else
            {
                SendClientMessage(pID, COLOR_RED, "Du besitzt nicht mehr die Menge an Wantedcodes, die du verkaufen wolltest.");
                SendClientMessage(playerid, COLOR_RED, "Der Verkäufer besitzt nicht mehr die Menge an Wantedcodes, die er verkaufen wollte.");
            }
        }
        else
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    }
    else if(strcmp(entry, "waffenteile", true) == 0)
    {
        if(!(pWTeileID[playerid] == 999))
        {
            if(IsPlayerConnected(pWTeileID[playerid]))
            {
                if(Spieler[pWTeileID[playerid]][pWaffenteile]>=pWTeileMenge[playerid])
                {
                    if(CheckMoney(playerid) < pWTeilePreis[playerid])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
                    GivePlayerCash(playerid, -pWTeilePreis[playerid]);
                    GivePlayerCash(pWTeileID[playerid], pWTeilePreis[playerid]);
                    //Spieler[pDrogenID[playerid]][pDrugs] -= pDrogenMenge[playerid];
                    Spieler[playerid][pWaffenteile] += pWTeileMenge[playerid];
                    Spieler[ pWTeileID[playerid] ][pWaffenteile] -= pWTeileMenge[playerid];
                    format(string, sizeof(string), "Du hast %d Stk. Waffenteile von %s für $%s abgekauft.", pWTeileMenge[playerid], GetName(pWTeileID[playerid]), AddDelimiters(pWTeilePreis[playerid]));
                    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                    format(string, sizeof(string), "%s hat dir %d Stk. Waffenteile für $%s abgekauft.", GetName(playerid), pWTeileMenge[playerid], AddDelimiters(pWTeilePreis[playerid]));
                    SendClientMessage(pWTeileID[playerid], COLOR_LIGHTBLUE, string);
                    new ort[24], waffenteilelog[128];
                    GetPlayer2DZone(playerid, ort, 24);
                    // ??? format(ddealerlog, sizeof(ddealerlog), "Name: %s - Käufer: %s - Drogen: %d - Geld: %d - Ort: %s", GetName(pDrogenID[playerid]), GetName(playerid), pDrogenMenge[playerid], pDrogenPreis[playerid], ort);
                    format(waffenteilelog,sizeof(waffenteilelog),"%s hat %s %dstk. Waffenteile für $%s verkauft.",GetName( pWTeileID[playerid] ) , GetName(playerid), pWTeileMenge[playerid] , AddDelimiters(pWTeilePreis[playerid]) );
                    WaffenteileLog(waffenteilelog);
                    pWTeileID[playerid] = 999;
                    pWTeileMenge[playerid] = 0;
                    pWTeilePreis[playerid] = 0;
                }
                else
                {
                    SendClientMessage(pWTeileID[playerid],COLOR_RED,"Du besitzt nicht mehr die Menge an Waffenteilenm die du verkaufen wolltest.");
                    SendClientMessage(playerid,COLOR_RED,"Der Verkäufer besitzt nicht mehr die Menge an Waffenteilen, die er verkaufen wollte.");
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
                return 1;
            }
        }
    }
    else if(strcmp(entry, "spice", true) == 0)
    {
        if(!(pSpiceID[playerid] == 999))
        {
            if(IsPlayerConnected(pSpiceID[playerid]))
            {
                if(CheckMoney(playerid) < pSpicePreis[playerid])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
                if(pSpiceMenge[playerid]>Spieler[pSpiceID[playerid]][pSpice])return SendClientMessage(playerid, COLOR_RED, "Der Verkäufer besitzt nicht die benötigte Menge an Spice");
                //if(CheckPlayerSpice(playerid,pSpiceMenge[playerid])) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst nur maximal 3.000 Gramm Spice besitzen!");
                GivePlayerCash(playerid, -pSpicePreis[playerid]);
                GivePlayerCash(pSpiceID[playerid], pSpicePreis[playerid]);
                //Spieler[pDrogenID[playerid]][pDrugs] -= pDrogenMenge[playerid];
                Spieler[playerid][pSpice] += pSpiceMenge[playerid];
                Spieler[pSpiceID[playerid]][pSpice] -= pSpiceMenge[playerid];
                format(string, sizeof(string), "Du hast %d Gramm Spice von %s für $%s abgekauft.", pSpiceMenge[playerid], GetName(pSpiceID[playerid]), AddDelimiters(pSpicePreis[playerid]));
                SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                format(string, sizeof(string), "%s hat dir %d Gramm Spice für $%s abgekauft.", GetName(playerid), pSpiceMenge[playerid], AddDelimiters(pSpicePreis[playerid]));
                SendClientMessage(pSpiceID[playerid], COLOR_LIGHTBLUE, string);
                new ort[24], ddealerlog[128];
                GetPlayer2DZone(playerid, ort, 24);
                format(ddealerlog, sizeof(ddealerlog), "Name: %s - Käufer: %s - Spice: %d - Geld: %d - Ort: %s", GetName(pSpiceID[playerid]), GetName(playerid), pSpiceMenge[playerid], pSpicePreis[playerid], ort);
                pSpiceID[playerid] = 999;
                pSpiceMenge[playerid] = 0;
                pSpicePreis[playerid] = 0;
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
                return 1;
            }
        }
    }
    else if(strcmp(entry, "anwalt", true) == 0)
    {

        if(!(AnwaltID[playerid] == 999))
        {
            if(IsPlayerConnected(AnwaltID[playerid]))
            {
                if(Spieler[playerid][pJailed] != 1)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich im Admin Prison und kannst daher nicht von einem Anwalt befreit werden!");
                if(CheckMoney(playerid) < AnwaltPreis[playerid])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
                GivePlayerCash(playerid, -AnwaltPreis[playerid]);
                GivePlayerCash(AnwaltID[playerid], AnwaltPreis[playerid]);
                new anwaltlog[128];
                new stateshare = 40; //GetPlayerLawyerStateShare( AnwaltID[playerid] );
                new staatsanteil = floatround((stateshare / 100.0 ) * AnwaltPreis[playerid]);
                Spieler[ AnwaltID[playerid] ][pLawyerPoints]++;
                format(anwaltlog, sizeof(anwaltlog), "Name: %s - Befreiter: %s - Geld: %d", GetName(AnwaltID[playerid]), GetName(playerid), AnwaltPreis[playerid] + staatsanteil);
                LogAnwalt(anwaltlog);
                format(string, sizeof(string), "Du hast die Befreiung von %s angenommen. (-$%d)", GetName(AnwaltID[playerid]), AnwaltPreis[playerid] + staatsanteil);
                SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                format(string, sizeof(string), "%s hat deine Befreiung angenommen. (+$%d)", GetName(playerid), AnwaltPreis[playerid] + staatsanteil);
                SendClientMessage(AnwaltID[playerid], COLOR_LIGHTBLUE, string);
                format(string, sizeof(string), "Davon erhält die Staatskasse $%d aufgrund deines Anwalt-Skills.", staatsanteil);
                SendClientMessage(AnwaltID[playerid], COLOR_LIGHTBLUE, string);
                GivePlayerCash(playerid,-staatsanteil);
                TreasuryDeposit(staatsanteil);
                AnwaltPreis[playerid] = 0;
                AnwaltID[playerid] = 999;
                Spieler[playerid][pJailTime] = 0;
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
                return 1;
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Niemand hat dir eine Befreiung angeboten.");
            return 1;
        }
    }
	else if(strcmp(entry, "fraktion", true) == 0)
    {
        if(!(FrakInviteID[playerid] == 999))
        {
            Spieler[playerid][pFraktion] = FrakInviteID[playerid];
            new frakid = FrakInviteID[playerid];
            FrakInviteID[playerid] = 999;
            Spieler[playerid][pFrakLohn] = 0;
            Spieler[playerid][pRank] = 0;
            Spieler[playerid][pfrakwarn] = 0;
            SetPVarInt(playerid, "SELECT.FRAK.SKIN", 1);
            //StartPlayerSkinSelection(playerid);
            new dialogstr[2056];
            if(Spieler[playerid][pFraktion] == 0){
                for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 1){
                for (new i = 0, j = sizeof(skins_pd_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_pd_array[i]);
                }
            } else if(Spieler[playerid][pFraktion] == 2){
			    for (new i= 0, j = sizeof(skins_fbi_array); i < j; i++) {
			        format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_fbi_array[i]);
				}
			}else if(Spieler[playerid][pFraktion] == 3){
                for (new i = 0, j = sizeof(skins_samd_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_samd_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 4){
                for (new i = 0, j = sizeof(skins_news_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_news_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 5){
                for (new i = 0, j = sizeof(skins_oamt_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_oamt_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 6){
                for (new i = 0, j = sizeof(skins_gsf_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_gsf_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 7){
                for (new i = 0, j = sizeof(skins_ballas_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_ballas_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 9){
                for (new i = 0, j = sizeof(skins_regierung_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_regierung_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 10){
                for (new i = 0, j = sizeof(skins_yakuza_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_yakuza_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 11){
                for (new i = 0, j = sizeof(skins_aztecas_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_aztecas_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 12){
                for (new i = 0, j = sizeof(skins_cali_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_cali_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 13){
                for (new i = 0, j = sizeof(skins_vagos_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_vagos_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 14){
                for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 15){
                for (new i = 0, j = sizeof(skins_nd_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_nd_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 19){
                for (new i = 0, j = sizeof(skins_terrorist_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_terrorist_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 20){
                for (new i = 0, j = sizeof(skins_lcn_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_lcn_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 21){
                for (new i = 0, j = sizeof(skins_triaden_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_triaden_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 22){
                for (new i = 0, j = sizeof(skins_zollamt_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_zollamt_array[i]);
                }
            }
			else{
                for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
                }
            }
            ShowPlayerDialog(playerid, DIALOG_SKINS_EINGELADEN, DIALOG_STYLE_PREVMODEL, "LyD - Fraktionsskin auswählen", dialogstr, "Ok", "Abbrechen");
            SendClientMessage(playerid, COLOR_GREEN, "Wähle nun deinen Fraktionsskin!");
            if (frakid == 15) AddPlayerToPlantArrayData(playerid);
            if( IsAFightFaction( Spieler[playerid][pFraktion] ) ) AddPlayerToPlantArrayDataGang(playerid);
            SaveAccount(playerid);
        }
    }
    else if(strcmp(entry, "refill", true) == 0)
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            if(!(RefillCar[playerid] == 999))
            {
                if(IsPlayerConnected(RefillCar[playerid]))
                {
                    if(CheckMoney(playerid) >= RefillCarPreis[playerid])
                    {
                        new vID = GetPlayerVehicleID(playerid);
                        GivePlayerCash(playerid, -RefillCarPreis[playerid]);
                        GivePlayerCash(RefillCar[playerid], RefillCarPreis[playerid]);
                        format(string, sizeof(string), "* %s hat die Tankfüllung angenommen. Du erhältst $%s", GetName(playerid), AddDelimiters(RefillCarPreis[playerid]));
                        SendClientMessage(RefillCar[playerid], COLOR_BLUE, string);
                        SendClientMessage(playerid, COLOR_BLUE, "* Du hast die Tankfüllung angenommen.");
                        RefillCarPreis[playerid] = 0;
                        RefillCar[playerid] = 999;
                        gGas[vID] = GetMaxTank(vID);
                        return 1;
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld dabei.");
                        return 1;
                    }
                }
                else
                {
                    SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
                    RefillCarPreis[playerid] = 0;
                    RefillCar[playerid] = 999;
                    return 1;
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Du hast keine Anfrage erhalten.");
                return 1;
            }
        }
    }
    else if(strcmp(entry, "antrag",true) == 0 ) {
        new
            String[128],
            giveid;
        giveid = Spieler[playerid][pHeiratsantragID];

        if(giveid == INVALID_PLAYER_ID) {
            return SendClientMessage(playerid, COLOR_RED, "Dir wurde kein Heiratsantrag gemacht.");
        }
        if(!IsPlayerConnected(giveid)) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht mehr online.");
        }
        if( Spieler[playerid][pMarriage] != INVALID_MARRIAGE ) {
            return SendClientMessage(playerid, COLOR_RED, "Du bist bereits verheiratet.");
        }
        if( Spieler[giveid][pMarriage] != INVALID_MARRIAGE ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist bereits verheiratet.");
        }
        if( IsPlayerInAnyVehicle(playerid) ) {
            return SendClientMessage(playerid, COLOR_RED, "Du kannst nicht in einem Fahrzeug heiraten.");
        }
        if( IsPlayerInAnyVehicle(giveid) ) {
            return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Spieler in einem Fahrzeug heiraten.");
        }
        if( !IsPlayerInRangeOfPoint(playerid,5.0, WEDDING_COORDS) ) {
            return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht am Trau-Platz.");
        }
        if( !IsPlayerInRangeOfPoint(giveid,5.0, WEDDING_COORDS) ) {
            return SendClientMessage(playerid, COLOR_RED, "Dein Partner befindet sich nicht am Trau-Platz.");
        }
        new
            geschlecht_playerid,
            geschlecht_giveid;
        geschlecht_playerid = Spieler[playerid][pSex];
        geschlecht_giveid = Spieler[giveid][pSex];
        if( geschlecht_playerid == geschlecht_giveid ) {
            if( geschlecht_playerid == 1 ) {
                format(String,sizeof(String),"[HOCHZEITSMELDUNG] Wir haben ein neues Schwulenpaar, "#COLOR_HEX_GREENA"%s und "#COLOR_HEX_GREENA"%s "#COLOR_HEX_YELLOW"sind nun verheiratet!",GetName(giveid),GetName(playerid));
            }
            else if( geschlecht_playerid == 2 ) {
                format(String,sizeof(String),"[HOCHZEITSMELDUNG] Wir haben ein neues Lesbenpaar, "#COLOR_HEX_GREENA"%s und "#COLOR_HEX_GREENA"%s "#COLOR_HEX_YELLOW"sind nun verheiratet!",GetName(giveid),GetName(playerid));
            }
        }
        else {
            format(String,sizeof(String),"[HOCHZEITSMELDUNG] Wir haben ein neues Hochzeitspaar, "#COLOR_HEX_GREENA"%s und "#COLOR_HEX_GREENA"%s "#COLOR_HEX_YELLOW"sind nun verheiratet!",GetName(giveid),GetName(playerid));
        }
        SendClientMessageToAll(COLOR_YELLOW,String);
        Spieler[playerid][pHeiratsantragID] = INVALID_PLAYER_ID;

        Spieler[playerid][pMarriage] = Spieler[giveid][ID];
        Spieler[giveid][pMarriage] = Spieler[playerid][ID];
        format(Spieler[playerid][pMarriageName],32,"%s",GetName(giveid));
        format(Spieler[giveid][pMarriageName],32,"%s",GetName(playerid));

        // SQL Vorsichtshalber
        format(String,sizeof(String),"UPDATE `accounts` SET `Marriage` = '%d' ,`MarriageName` = '%s' WHERE `ID` = %d",Spieler[playerid][pMarriage],Spieler[playerid][pMarriageName],Spieler[playerid][ID]);
        mysql_pquery(String,THREAD_ACCEPTMARRIAGE,playerid,gSQL,MySQLThreadOwner);
        format(String,sizeof(String),"UPDATE `accounts` SET `Marriage` = '%d' ,`MarriageName` = '%s' WHERE `ID` = %d",Spieler[giveid][pMarriage],Spieler[giveid][pMarriageName],Spieler[giveid][ID]);
        mysql_pquery(String,THREAD_ACCEPTMARRIAGE,giveid,gSQL,MySQLThreadOwner);
        return 1;
    }
    else if(strcmp(entry, "eis",true,3) == 0 ) {
        new
            String[128],
            vehicleid,
            preis,
            Float:X,
            Float:Y,
            Float:Z,
            giveid;
        giveid = Spieler[playerid][pEisVerkaeufer];
        if(giveid == INVALID_PLAYER_ID) {
            return SendClientMessage(playerid, COLOR_RED, "Dir wurde kein Eis zum Kauf angeboten.");
        }
        if(!IsPlayerConnected(giveid)) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht mehr online.");
        }
        vehicleid = GetPlayerVehicleID(giveid);
        if( !IsEismannVehicle(vehicleid) ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Eisverkäufer ist nicht mehr im Eismann-Fahrzeug");
        }
        GetPlayerPos(playerid,X,Y,Z);
        if( !IsPlayerInRangeOfPoint(giveid,5.0,X,Y,Z) ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Eisverkäufer befindet sich nicht mehr in deiner Nähe.");
        }
        preis = Spieler[playerid][pEisPreis];
        if( CheckMoney(playerid) < preis ) {
            format(String,sizeof(String),"Du besitzt nicht genug Geld um das Eis zu kaufen (Preis: $%s)", AddDelimiters(preis));
            return SendClientMessage(playerid, COLOR_RED, String);
        }
        new
            Float:fHealth;
        GetPlayerHealth(playerid,fHealth);
        fHealth += 40.0;
        if( fHealth > 100.0 ) fHealth = 100.0;
        GivePlayerCash(playerid,-preis);
        GivePlayerCash(giveid,preis);
        format(String,sizeof(String),"Du hast das Eis für $%s gekauft. Deine Energie wurde aufgefüllt", AddDelimiters(preis));
        SendClientMessage(playerid, COLOR_BLUE, String);
        format(String,sizeof(String),"Du hast ein Eis an %s für $%s verkauft. ",GetName(playerid), AddDelimiters(preis));
        SendClientMessage(giveid, COLOR_BLUE, String);

        Spieler[playerid][pEisVerkaeufer] = INVALID_PLAYER_ID;
        Spieler[playerid][pEisPreis] = 0;
        switch( random(3) ) {
            case 0: ApplyAnimation(playerid, "FOOD", "EAT_PIZZA", 4.0, 0, 0, 0, 0, 1); // 
            case 1: ApplyAnimation(playerid, "FOOD", "EAT_BURGER", 4.0, 0, 0, 0, 0, 1); // 
            case 2: ApplyAnimation(playerid, "FOOD", "EAT_CHICKEN", 4.0, 0, 0, 0, 0, 1); // 
        }
        return 1;
    }
    else if(strcmp(entry, "hotdog",true,3) == 0 ) {
        new
            String[128],
            vehicleid,
            preis,
            Float:X,
            Float:Y,
            Float:Z,
            giveid;
        giveid = Spieler[playerid][pHotDogVerkaeufer];
        if(giveid == INVALID_PLAYER_ID) {
            return SendClientMessage(playerid, COLOR_RED, "Dir wurde kein Hotdog zum Kauf angeboten.");
        }
        if(!IsPlayerConnected(giveid)) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht mehr online.");
        }
        vehicleid = GetPlayerVehicleID(giveid);
        if( !IsHotDogVehicle(vehicleid) ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Hotdog-Verkäufer ist nicht mehr in seinem Fahrzeug!");
        }
        GetPlayerPos(playerid,X,Y,Z);
        if( !IsPlayerInRangeOfPoint(giveid,5.0,X,Y,Z) ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Hotdog-Verkäufer befindet sich nicht mehr in deiner Nähe.");
        }
        preis = Spieler[playerid][pHotDogPreis];
        if( CheckMoney(playerid) < preis ) {
            format(String,sizeof(String),"Du besitzt nicht genug Geld um den Hotdog zu kaufen (Preis: $%s)", AddDelimiters(preis));
            return SendClientMessage(playerid, COLOR_RED, String);
        }
        new
            Float:fHealth;
        GetPlayerHealth(playerid,fHealth);
        fHealth += 40.0;
        if( fHealth > 100.0 ) fHealth = 100.0;
        GivePlayerCash(playerid,-preis);
        GivePlayerCash(giveid,preis);
        format(String,sizeof(String),"Du hast ein Hotdog für $%s gekauft. Deine Energie wurde aufgefüllt", AddDelimiters(preis));
        SendClientMessage(playerid, COLOR_BLUE, String);
        format(String,sizeof(String),"Du hast ein Hotdog an %s für $%s verkauft. ",GetName(playerid), AddDelimiters(preis));
        SendClientMessage(giveid, COLOR_BLUE, String);

        Spieler[playerid][pHotDogVerkaeufer] = INVALID_PLAYER_ID;
        Spieler[playerid][pHotDogPreis] = 0;
        switch( random(3) ) {
            case 0: ApplyAnimation(playerid, "FOOD", "EAT_PIZZA", 4.0, 0, 0, 0, 0, 1); // 
            case 1: ApplyAnimation(playerid, "FOOD", "EAT_BURGER", 4.0, 0, 0, 0, 0, 1); // 
            case 2: ApplyAnimation(playerid, "FOOD", "EAT_CHICKEN", 4.0, 0, 0, 0, 0, 1); // 
        }
        return 1;
    }
    else if( strcmp(entry,"arzt",true) == 0 ) {
        if( Spieler[playerid][pSHeilen] != INVALID_PLAYER_ID) {
            new
                arzt = Spieler[playerid][pSHeilen];
            if( IsPlayerConnected(arzt) ) {
                new vID = GetPlayerVehicleID(playerid);
                new pvID = GetPlayerVehicleID(arzt);
                if(pvID == vID) {
                    if( aiVehicles[vID] == VEH_SANICARS ) {
                        // Angenommen und alles iO
                        if( Spieler[playerid][pCash] < 100 ) {
                            return SendClientMessage(playerid,COLOR_RED,"Du besitzt nicht genug Geld (100$)");
                        }
                        new seat1 = GetPlayerVehicleSeat(playerid);
                        new seat2 = GetPlayerVehicleSeat(arzt);
                        if( seat1 != 2 && seat1 != 3 && seat2 != 2 && seat2 != 3 ) {
                            return SendClientMessage(playerid, COLOR_ORANGE, "Für die Behandlung müssen Arzt und Patient im Behandlungsbereich des Wagens sein");
                        }
                        new
                            String[128];
                        format(String,sizeof(String),"* Du lässt dich nun von %s verarzten!",GetName(arzt));
                        SendClientMessage(playerid,COLOR_YELLOW,String);
                        format(String,sizeof(String),"* %s nimmt das Angebot an. Er möchte nun verarztet werden.",GetName(playerid));
                        SendClientMessage(arzt,COLOR_YELLOW,String);
                        Spieler[playerid][pSHeilen] = INVALID_PLAYER_ID;
                        Spieler[playerid][tSHeilen] = SetTimerEx("Pulse_SHeilen",2003,false,"ddd",arzt,playerid,vID);
                        Spieler[playerid][pCash] -= 100;
                        Kasse[Samd] += 100;
                        SetCameraBehindPlayer(playerid);
                        SetCameraBehindPlayer(arzt);
                        TogglePlayerControllable(playerid,false);
                        TogglePlayerControllable(arzt,false);
                    }
                    else {
                        return SendClientMessage(playerid,COLOR_RED,"Du bist nicht in einem Sanitärs Fahrzeug");
                    }
                }
                else {
                    return SendClientMessage(playerid,COLOR_RED,"Du bist nicht im gleichem Fahrzeug wie der Arzt");
                }
            }
            else {
                Spieler[playerid][pSHeilen] = INVALID_PLAYER_ID;
                return SendClientMessage(playerid,COLOR_RED,"Der Arzt ist nicht mehr Online");
            }
        }
        else {
            Spieler[playerid][pSHeilen] = INVALID_PLAYER_ID;
            return SendClientMessage(playerid,COLOR_RED,"Dir wurde nicht angeboten dich zu heilen");
        }
    }
    else if(strcmp(entry, "sex",true) == 0 ) {
        new
            String[128],
            vehicleid,
            preis,
            Float:X,
            Float:Y,
            Float:Z,
            giveid;
        giveid = Spieler[playerid][pHureID];
        if(giveid == INVALID_PLAYER_ID) {
            return SendClientMessage(playerid, COLOR_RED, "Dir wurde kein Sex angeboten.");
        }
        if(!IsPlayerConnected(giveid)) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht mehr online.");
        }
        vehicleid = GetPlayerVehicleID(giveid);
        if( !IsACar( GetVehicleModel(vehicleid)) ) {
            return SendClientMessage(playerid, COLOR_RED, "Die Prostituierte ist nicht mehr in ihrem Auto.");
        }
        if( GetPlayerState(giveid) != PLAYER_STATE_DRIVER ) {
            return SendClientMessage(playerid, COLOR_RED, "Die Prostituierte ist nicht mehr die Fahrer.");
        }
        GetPlayerPos(playerid,X,Y,Z);
        if( !IsPlayerInRangeOfPoint(giveid,5.0,X,Y,Z) ) {
            return SendClientMessage(playerid, COLOR_RED, "Die Prostituierte befindet sich nicht mehr in deiner Nähe.");
        }
        preis = Spieler[playerid][pHurePreis];
        if( CheckMoney(playerid) < preis ) {
            format(String,sizeof(String),"Du besitzt nicht genug Geld um die Sex-Dienstleistung entgegen zu nehmen (Preis: $%s)", AddDelimiters(preis));
            return SendClientMessage(playerid, COLOR_RED, String);
        }
        if( Spieler[playerid][bHasSex] ) {
            return SendClientMessage(playerid, COLOR_RED, "Du hast bereits Sex.");
        }
        GivePlayerCash(playerid,-preis);
        GivePlayerCash(giveid,preis);

        format(String,sizeof(String),"Du hast die Dienstleistung entgegen genommen.Warte 30 Sekunden im Fahrzeug");
        SendClientMessage(playerid, COLOR_BLUE, String);
        format(String,sizeof(String),"Du bietest nun für 30 Sekunden %s deine Dienst für $%s an. ",GetName(playerid), AddDelimiters(preis));
        SendClientMessage(giveid, COLOR_BLUE, String);

        Spieler[playerid][pHureID] = INVALID_PLAYER_ID;
        Spieler[playerid][pHurePreis] = 0;

        Spieler[giveid][tickHure] = gettime() + 30;
        KillTimer( Spieler[giveid][tHure] );
        Spieler[giveid][tHure] = SetTimerEx("Pulse_Hure",683,true,"dd",giveid,playerid);

        PutPlayerInVehicle(playerid,vehicleid,1);

        Spieler[playerid][bHasSex] = true;
        Spieler[giveid][bHasSex] = true;

        FreezePlayer(giveid);
        FreezePlayer(playerid);
        return 1;
    }
    else if(strcmp(entry, "pizza",true,3) == 0 ) {
        new
            String[128],
            vehicleid,
            preis,
            Float:X,
            Float:Y,
            Float:Z,
            giveid;
        giveid = Spieler[playerid][pPizzaVerkaeufer];
        if(giveid == INVALID_PLAYER_ID) {
            return SendClientMessage(playerid, COLOR_RED, "Dir wurde keine Pizza zum Kauf angeboten.");
        }
        if(!IsPlayerConnected(giveid)) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht mehr online.");
        }
        vehicleid = GetPlayerVehicleID(giveid);
        if( !IsPizzaVehicle(vehicleid) ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Pizzalieferant sitzt nicht auf seinem Pizza-Roller");
        }
        GetPlayerPos(playerid,X,Y,Z);
        if( !IsPlayerInRangeOfPoint(giveid,5.0,X,Y,Z) ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Pizzalieferant befindet sich nicht mehr in deiner Nähe.");
        }
        preis = Spieler[playerid][pPizzaPreis];
        if( CheckMoney(playerid) < preis ) {
            format(String,sizeof(String),"Du besitzt nicht genug Geld um die Pizza zu bezahlen (Preis: $%s)", AddDelimiters(preis));
            return SendClientMessage(playerid, COLOR_RED, String);
        }
        new
            Float:fHealth;
        GetPlayerHealth(playerid,fHealth);
        fHealth += 50.0;
        if( fHealth > 100.0 ) fHealth = 100.0;
        GivePlayerCash(playerid,-preis);
        GivePlayerCash(giveid,preis);
        format(String,sizeof(String),"Du hast die Pizza für $%s gekauft. Deine Energie wurde aufgefüll!t", AddDelimiters(preis));
        SendClientMessage(playerid, COLOR_BLUE, String);
        format(String,sizeof(String),"Du hast eine Pizza an %s für $%s verkauft. ",GetName(playerid), AddDelimiters(preis));
        SendClientMessage(giveid, COLOR_BLUE, String);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen

        Spieler[playerid][pPizzaVerkaeufer] = INVALID_PLAYER_ID;
        Spieler[playerid][pPizzaPreis] = 0;
        return 1;
    }
    else if(strcmp(entry, "repair", true) == 0)
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            if( GetPlayerState( playerid ) != PLAYER_STATE_DRIVER ) {
                SendClientMessage(playerid, COLOR_RED, "Du musst der Fahrer sein.");
                return 1;
            }
            if(!(RepairCar[playerid] == 999))
            {
                if(IsPlayerConnected(RepairCar[playerid]))
                {
                    if(CheckMoney(playerid) >= RepairCarPreis[playerid])
                    {
                        if( GetPlayerState( RepairCar[playerid] ) != PLAYER_STATE_ONFOOT ) {
                            SendClientMessage(playerid, COLOR_RED, "Der Mechaniker ist gerade nicht zu Fuß.");
                            return 1;
                        }
                        new vID = GetPlayerVehicleID(playerid);
                        new engine,lights,doors,bonnet,boot,objective,alarm;
                        GetVehicleParamsEx( vID ,engine,lights,alarm,doors,bonnet,boot,objective);
                        if(bonnet != 1 ) {
                            SendClientMessage(playerid, COLOR_RED, "Die Motorhaube ist nicht mehr geöffnet");
                            return 1;
                        }
                        new
                            Float:X,
                            Float:Y,
                            Float:Z;
                        GetVehiclePos( vID , X,Y,Z);
                        if( !IsPlayerInRangeOfPoint( RepairCar[playerid] , 7.0 , X,Y,Z) ) {
                            SendClientMessage(playerid, COLOR_RED, "Der Mechaniker ist zu weit entfern vom Fahrzeug");
                            return 1;
                        }
                        GivePlayerCash(playerid, -RepairCarPreis[playerid]);
                        GivePlayerCash(RepairCar[playerid], RepairCarPreis[playerid]);
                        format(string, sizeof(string), "* %s hat die Reperatur angenommen. Du erhältst $%s", GetName(playerid), AddDelimiters(RepairCarPreis[playerid]));
                        SendClientMessage(RepairCar[playerid], COLOR_BLUE, string);
                        SendClientMessage(playerid, COLOR_BLUE, "* Du hast die Reperatur angenommen.");
                        RepairCarPreis[playerid] = 0;
                        RepairCar[playerid] = 999;
                        SetVehicleHealth(vID, 1000);
                        RepairVehicle(vID);
                        return 1;
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld dabei.");
                        return 1;
                    }
                }
                else
                {
                    SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
                    RepairCarPreis[playerid] = 0;
                    RepairCar[playerid] = 999;
                    return 1;
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Du hast keine Anfrage erhalten.");
                return 1;
            }
        }
    }
    return 1;
}



CMD:heiraten(playerid,params[]) {
    new Float:X, Float:Y, Float:Z, String[128], giveid;
    // Spieler[playerid][ID]
    if(sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Heiraten [Spieler]");
    if( !IsPlayerConnected(giveid) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[playerid][pMarriage] != INVALID_MARRIAGE ) return SendClientMessage(playerid, COLOR_RED, "Du bist bereits verheiratet.");
    if( Spieler[giveid][pMarriage] != INVALID_MARRIAGE ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist bereits Verheiratet.");
    if( playerid == giveid ) return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht selber heiraten.");
    GetPlayerPos(playerid,X,Y,Z);
    if( !IsPlayerInRangeOfPoint(giveid, 3.0 , X, Y, Z ) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist zu weit von dir entfernt.");
    if( IsPlayerInAnyVehicle(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst nicht aus einem Fahrzeug heraus heiraten.");
    if( IsPlayerInAnyVehicle(giveid) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Spieler in einem Fahrzeug einen Heiratsantrag machen.");
    if( !IsPlayerInRangeOfPoint(playerid,5.0, WEDDING_COORDS) ) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht am Trau-Platz.");
    format(String,sizeof(String),"%s hat dir einen Heiratsantrag gemacht, du kannst diesen mit /accept Antrag annehmen!",GetName(playerid));
    SendClientMessage(giveid, COLOR_BLUE, String);
    format(String,sizeof(String),"Du hast %s einen Heiratsantrag gemacht.",GetName(giveid));
    SendClientMessage(playerid, COLOR_GREEN, String);
    Spieler[giveid][pHeiratsantragID] = playerid;
    return 1;
}

CMD:scheiden(playerid,params[]) {
    new String[128], giveid_root, giveid;
    if( Spieler[playerid][pMarriage] == INVALID_MARRIAGE ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht verheiratet.");
    giveid_root = Spieler[playerid][pMarriage];
    if( !IsPlayerInRangeOfPoint(playerid,5.0, WEDDING_COORDS) ) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht am Trau-Platz.");
    giveid = GetPlayerIDByUnique(giveid_root);
    if( CheckMoney(playerid) < PREIS_SCHEIDUNG ) return SendClientMessage(playerid, COLOR_RED, "Du benötigst "#PREIS_SCHEIDUNG"$ um dich scheiden zu lassen.");
    if( IsPlayerInAnyVehicle(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht in einem Fahrzeug scheiden lassen.");
    if(!IsPlayerConnected(giveid))
    {
        // Spieler nicht Online ... Versuchen OFFLINE zu Scheiden
        format(String,sizeof(String),"SELECT `Name`,`ID` FROM `accounts` WHERE `ID` = %d LIMIT 1", giveid_root );
        mysql_pquery(String,THREAD_CHECKSCHEIDEN,playerid,gSQL,MySQLThreadOwner);
        // -> THREADED
        return 1;
    }
    // Online Scheiden
    format(String,sizeof(String),"Dein (Ex)-Partner %s hat sich von dir Scheiden lassen!",GetName(playerid));
    SendClientMessage(giveid, COLOR_RED, String );
    format(String,sizeof(String),"Du hast dich von deinem (Ex)-Partner %s Scheiden lassen. ( Kosten: $%s )",GetName(giveid), AddDelimiters(PREIS_SCHEIDUNG));
    SendClientMessage(playerid, COLOR_WHITE, String );
    Spieler[playerid][pMarriage] = INVALID_MARRIAGE;
    Spieler[giveid][pMarriage] = INVALID_MARRIAGE;
    format(Spieler[playerid][pMarriageName],MAX_PLAYER_NAME,"Niemand");
    format(Spieler[giveid][pMarriageName],MAX_PLAYER_NAME,"Niemand");
    GivePlayerCash(playerid,-PREIS_SCHEIDUNG);
    format(String,sizeof(String),"[HOCHZEITSMELDUNG] "#COLOR_HEX_RED"%s und %s sind nicht mehr Verheiratet. %s hat die Scheidung eingereicht!",GetName(playerid),GetName(giveid),GetName(playerid));
    SendClientMessageToAll(COLOR_BLUE,String);
    // SQL Vorsichtshalber
    format(String,sizeof(String),"UPDATE `accounts` SET `Marriage` = %d WHERE `ID` IN(%d,%d)", INVALID_MARRIAGE ,Spieler[giveid][ID],Spieler[playerid][ID]);
    mysql_pquery(String,THREAD_SCHEIDEN,playerid,gSQL,MySQLThreadOwner);
    return 1;
}


CMD:weihnachtsmuetze(playerid,params[]){
	new wjahr, wmonat, wday;
    getdate(wjahr, wmonat, wday);
	if((wmonat != 12 || wday > 27))
		        return SendClientMessage(playerid,COLOR_RED,"Wir befinden uns nicht in der Adventszeit!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,1) ) {
        RemovePlayerAttachedObject(playerid,1);
        SendClientMessage(playerid,COLOR_YELLOW,"Weihnachtsmütze abgenommen");
    }
    else {
        SetPlayerAttachedObject(playerid, 1, 19065, 2, 0.120000, 0.040000, -0.003500, 0, 100, 100, 1.4, 1.4, 1.4);
        SendClientMessage(playerid,COLOR_YELLOW,"Weihnachtsmütze aufgesetzt");
    }
    return 1;
}


CMD:clubshop(playerid,params[]) {
    //2316.5325,-1010.7850,1054.7188
    //if (!IsPlayerInRangeOfPoint(playerid,5.0,2316.5325,-1010.7850,1054.7188))
        //return SendClientMessage(playerid,COLOR_RED,"Du bist nicht an der Club-Garderobe");

    if( Spieler[playerid][pDonateRank] < 1) {
        return SendClientMessage(playerid,COLOR_RED,"Dieser Shop ist nur für Club-Mitglieder");
    }

    if( IsPlayerAttachedObjectSlotUsed(playerid,ATTACHED_INDEX_CLUB_SHOP) ) {
        // Nur Entfernen
        ShowPlayerDialog(playerid,DIALOG_CLUBSHOP_DEL,DIALOG_STYLE_MSGBOX,"Club-Garderobe","Willst du das Club-Item entfernen?","Entfernen","Abbruch");
    }
    else {
        new
            String[1024];
        for(new i ; i < sizeof(g_ClubShopItems) ; i++) {
            format(String,sizeof(String),"%s%s - $%d\n",String,g_ClubShopItems[i][CSI_sName],g_ClubShopItems[i][CSI_iPrice]);
        }
        ShowPlayerDialog(playerid,DIALOG_CLUBSHOP,DIALOG_STYLE_LIST,"Club-Garderobe",String,"Ausrüsten","Abbruch");

    }
    return 1;
}


CMD:getraenk(playerid,params[]) {
    //if( !IsPlayerInRangeOfPoint(playerid,15.0,499.4468,-20.7656,1000.6797) ) {
    if (!IsPlayerInRangeOfPoint(playerid, 4.0, SHISHABAR_DRINK_POINT) && !IsPlayerInRangeOfPoint(playerid,4.0, ALHAMBRAINTERIOR_BUYDRINK_POINT) && !IsPlayerInRangeOfPoint(playerid,4.0, CLUBINTERIORLOS_DRINKS_POINT) && !IsPlayerInRangeOfPoint(playerid,4.0,1455.8802,-1741.8704,13.5469)
        && !IsPlayerInRangeOfPoint(playerid,4.0,1215.3011,-13.0128,1000.9219) && !IsPlayerInRangeOfPoint(playerid,4.0, CASINO_INTERIOR_BUYDRINK_POINT) && !IsPlayerInRangeOfPoint(playerid,4.0,-2653.6023,1407.0844,906.2734) ) {
        return SendClientMessage(playerid,COLOR_ORANGE,"Du befindest dich nicht in der Bar");
    }
    showDrinks(playerid);
    return 1;
}


CMD:startbonus(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,3.0, NOOBSPAWN_STARTBONUS_POINT) ) {
        return SendClientMessage(playerid,COLOR_RED,"Den Startbonus gibt es hier nicht.");
    }
    if( Spieler[playerid][pStartbonus] ) {
        return SendClientMessage(playerid,COLOR_RED,"Du hast bereits einen Startbonus genommen!");
    }
    ShowPlayerDialog(playerid,DIALOG_STARTBONUS,DIALOG_STYLE_LIST,"Startbonus","+3 Respektpunkte\n+15.000$\nZufallsgeschenk\n1 Level UP + 2 Spielstunden","Annehmen","Abbruch");
    return 1;
}

/*CMD:starterpack(playerid){
    if(Spieler[playerid][pLevel] > 3) return SendClientMessage(playerid, COLOR_RED, "[STARTERPACK] {FFFFFF}Du bist leider nicht für den Starterpack qualifiziert!");
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 808.8542,-1347.3077,13.5416)) return SendClientMessage(playerid, COLOR_RED, "[STARTERPACK] {FFFFFF}Du bist nicht am Starterpack Punkt!");
    new jahr, monat, tag;
    getdate(jahr, monat, tag);
    //if(jahr == 2019 && monat >= 11 && tag >= 15) return SendClientMessage(playerid, COLOR_RED, "[STARTERPACK] {FFFFFF}Die Aktion ist leider abgelaufen!");
    Spieler[playerid][pLevel] = 5;
    Spieler[playerid][pBank] = 10000000;
    Spieler[playerid][pHours] = 15;
    Spieler[playerid][pCarLic] = 1;
    SendClientMessage(playerid, COLOR_GREEN, "[STARTERPACK] {FFFFFF}Du hast folgende Dinge erhalten: Level 5, $10.000.000, 15 Spielstunden und den Führerscheine.");
    return 1;
}*/


CMD:eventpreise(playerid) {
    new dialogText[512], dialogCaption[64];
    format(dialogCaption, sizeof(dialogCaption), "{FF9900}Eventpreise - Du hast {FFFFFF}%d {FF9900}Punkte", Spieler[playerid][pEventPoints]);
    dialogText = "Preis\tPunkte\n";
    for (new i = 0; i < sizeof(g_EventRewards); i++) 
        format(dialogText, sizeof(dialogText), "%s%s\t{FF9900}%d\n", dialogText, g_EventRewards[i][EVENT_REWARD_NAME], g_EventRewards[i][EVENT_REWARD_POINTS]);

    return ShowPlayerDialog(playerid, DIALOG_EVENTREWARDS, DIALOG_STYLE_TABLIST_HEADERS, dialogCaption, dialogText, "Einlösen", "Abbrechen");
}


CMD:id(playerid, params[]) {
    return cmd_suche(playerid, params);
}

CMD:suche(playerid,params[]) {
    new giveid;

    if (sscanf(params, "u", giveid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Suche [ID/Name]");
    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler wurde nicht gefunden");

    new String[128];
    //format(String, sizeof(String), "Spielername: %s, ID: %d, FPS: %d,Ping: %d, Anti-Cheat: %s, Paketverlust: %.2f Prozent", GetName(giveid), giveid, pFPS[giveid],GetPlayerPing(giveid), CAC_GetStatus(giveid) ? "An" : "Aus", NetStats_PacketLossPercent(giveid));
	format(String, sizeof(String), "Spielername: %s, ID: %d, FPS: %d,Ping: %d, Paketverlust: %.2f Prozent", GetName(giveid), giveid, pFPS[giveid],GetPlayerPing(giveid), NetStats_PacketLossPercent(giveid));
    SendClientMessage(playerid, COLOR_BLUE, String);

    return 1;
}


CMD:fahrpruefung(playerid,params[]) {
	//OLD POS: 1234.3380,-1823.9462,13.5909
    if( !IsPlayerInRangeOfPoint(playerid,5.0,-2033.1216,-117.4597,1035.1719)) {
        return SendClientMessage(playerid,COLOR_RED,"Nicht an der Fahrschule");
    }
    ShowPlayerDialog(playerid,DIALOG_FAHRSCHULE_SOLO,DIALOG_STYLE_LIST,"Fahrschule","Autoschein - $20.000\nMotorradschein - $30.000\nLKW-Schein - $70.000\nFlugschein - $100.000\nBootsschein - $40.000\nWaffenschein Klasse A - $120.000\nWaffenschein Klasse B - $240.000","Starten","Abbruch");
    return 1;
}

CMD:sperrefreikaufen(playerid, params[]){
	if( !IsPlayerInRangeOfPoint(playerid,5.0,-2033.1216,-117.4597,1035.1719)) {
        return SendClientMessage(playerid,COLOR_RED,"Nicht an der Fahrschule");
    }
    ShowPlayerDialog(playerid,DIALOG_FAHRSCHULE_REMOVESPERRE,DIALOG_STYLE_LIST,"Fahrschule","Sperre für den Autoschein entfernen - $100.000\nSperre für den Motorradschein entfernen - $120.000\nSperre für den LKW-Schein entfernen - $120.000\nSperre für den Flug-Schein entfernen - $160.000", "Entfernen", "Abbrechen");
	return 1;
}


CMD:gebecheck(playerid,params[]) {
    new
        giveid,
        betrag;
    if(sscanf(params,"ud",giveid,betrag)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Gebecheck [ID/Name] [Betrag]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid,COLOR_RED,"Der Spieler wurde nicht gefunden");
    }
    if( !( 3000 <= betrag <= 1000000 ) ) {
        return SendClientMessage(playerid,COLOR_ORANGE,"Betrag darf maximal von 3.000$ bis 1.000.000$ liegen");
    }
    if( CheckMoney(playerid) < betrag ) {
        return SendClientMessage(playerid,COLOR_RED,"Du besitzt nicht diesen Geldbetrag");
    }
    if( Spieler[playerid][pLevel] < 3 ) {
        return SendClientMessage(playerid, COLOR_RED, "Dein Level ist noch zu niedrig für diese Funktion.");
    }
    if( Spieler[giveid][pLevel] < 3 ) {
        return SendClientMessage(giveid, COLOR_RED, "Der Spieler muss mindestens Level 3 sein!");
    }
    if( Spieler[playerid][pGeldcheckID] != INVALID_PLAYER_ID ) {
        return SendClientMessage(playerid,COLOR_RED,"Du hast noch einen aktiven Geldcheck im Umlauf");
    }
    if( playerid == giveid ) {
        return SendClientMessage(playerid,COLOR_RED,"Du kannst dir selber keinen Check ausstellen");
    }
    new
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,5.0,x,y,z) ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Spieler ist zu weit entfernt von dir");
    }
    new
        String[128];
    format(String,sizeof(String),"Du hast %s einen Geldcheck ausgestellt. Betrag: $%s",GetName(giveid), AddDelimiters(betrag));
    SendClientMessage(playerid,COLOR_YELLOW,String);

    format(String,sizeof(String),"Dir wurde von %s ein Geldcheck in Höhe von $%s ausgestellt! Gehe zur Zentralbank und löse den Geldcheck ein.",GetName(playerid), AddDelimiters(betrag));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    format(String,sizeof(String),"ACHTUNG! Solltest du sterben oder dich ausloggen, geht dein Geldcheck unwiderruflich verloren!");
    SendClientMessage(giveid,COLOR_RED,String);
    Spieler[playerid][pGeldcheckID] = giveid;
    Spieler[playerid][pGeldcheckBetrag] = betrag;
    GivePlayerCash( playerid , -betrag );
    format(String,sizeof(String),"%s hat %s einen Geldcheck in Höhe von $%s ausgestellt",GetName(playerid),GetName(giveid), AddDelimiters(betrag));
    GebeCheckLog(String);

    if( betrag >= 20000 ) {
        format(String,sizeof(String),"[ACHTUNG] %s hat %s einen Geldcheck in Höhe von $%s ausgestellt",GetName(playerid),GetName(giveid), AddDelimiters(betrag));
        SendAdminMessage(COLOR_YELLOW, String);
    }
    return 1;
}


CMD:finanzen(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    new String[128], giveid;
    format(String, sizeof(String), "U(%d)", playerid);
    if (sscanf(params, String, giveid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Finanzen [Spieler]");
    if (playerid != giveid) {
        if (giveid >= MAX_PLAYERS || !gPlayerLogged[giveid]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht online.");
        if (Spieler[giveid][pAdminDienst]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist gerade im Admindienst.");
        if (!IsPlayerInRangeOfPlayer(playerid, giveid, 5.0)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht in deiner Nähe.");
        
        SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du zeigst %s deine Finanzen.", GetName(giveid));
        SCMFormatted(giveid, COLOR_YELLOW, "[INFO] {FFFFFF}%s zeigt dir seine Finanzen.", GetName(playerid));
    }

    SendClientMessage(giveid, COLOR_GREEN, "======= {FFFFFF}[ FINANZEN ] {009D00}=======");
    SCMFormatted(giveid, COLOR_YELLOW, "Finanzen von: {FFFFFF}%s", GetName(playerid));
    SCMFormatted(giveid, COLOR_YELLOW, "Bargeld: {FFFFFF}$%s", AddDelimiters(CheckMoney(playerid)));
    SCMFormatted(giveid, COLOR_YELLOW, "Kontostand: {FFFFFF}$%s", AddDelimiters(Spieler[playerid][pBank]));
    SendClientMessage(giveid, COLOR_GREEN, "=========================");
    return 1;
}


CMD:inventar(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    new string[256], ueberschrift[128];
    if(Spieler[playerid][pDrugs] != 0) { format(string, sizeof(string), "%sDrogen: %i", string, Spieler[playerid][pDrugs]); }
    if(Spieler[playerid][pSpice] != 0) { format(string, sizeof(string), "%s\nSpice: %i", string, Spieler[playerid][pSpice]); }
    if(Spieler[playerid][pDrogenSamen] != 0) { format(string, sizeof(string), "%s\nSpicesamen: %i", string, Spieler[playerid][pDrogenSamen]); }
    //if(Spieler[playerid][pKrauterMische] != 0) { format(string, sizeof(string), "%s\nKräutermischung: %i", string, Spieler[playerid][pKrauterMische]); }
    if(Spieler[playerid][pGangDrogenSamen] != 0) { format(string, sizeof(string), "%s\nDrogensamen: %i", string, Spieler[playerid][pGangDrogenSamen]); }
    if(Spieler[playerid][pWaffenteile] != 0) { format(string, sizeof(string), "%s\nWaffenteile: %i", string, Spieler[playerid][pWaffenteile]); }
    if(Spieler[playerid][pWantedCodes] != 0) { format(string, sizeof(string), "%s\nWanted-Codes: %i", string, Spieler[playerid][pWantedCodes]); }
    if(Spieler[playerid][pKekse] != 0) { format(string, sizeof(string), "%s\nKekse: %i", string, Spieler[playerid][pKekse]); }
    if(Spieler[playerid][pKanister] != 0) { format(string, sizeof(string), "%s\nKanister: %i", string, Spieler[playerid][pKanister]); }
    if(Spieler[playerid][pZigaretten] != 0) { format(string, sizeof(string), "%s\nZigaretten: %i", string, Spieler[playerid][pZigaretten]); }
    if(Spieler[playerid][pPfand] != 0) { format(string, sizeof(string), "%s\nPfandflaschen: %i", string, Spieler[playerid][pPfand]); }
    if(Spieler[playerid][pFische] != 0) { format(string, sizeof(string), "%s\nFisch: %i", string, Spieler[playerid][pFische]); }
    if(Spieler[playerid][pKoeder] != 0) { format(string, sizeof(string), "%s\nKöder %i", string, Spieler[playerid][pKoeder]); }
    if(Spieler[playerid][pZollValid] != 0) { format(string, sizeof(string), "%s\nZollpass: %i", string, Spieler[playerid][pZollValid]); }
    if(Spieler[playerid][pBrecheisen] != 0) { format(string, sizeof(string), "%s\nBrecheisen: %i", string, Spieler[playerid][pBrecheisen]); }
    if(Spieler[playerid][pC4] != 0) { format(string, sizeof(string), "%s\nC4: %i", string, Spieler[playerid][pC4]); }
    if(Spieler[playerid][pBooster] != 0) { format(string, sizeof(string), "%s\nBooster: %i", string, Spieler[playerid][pBooster]); }
    if(Spieler[playerid][pPowerRiegel] != 0) { format(string, sizeof(string), "%s\nPower-Riegel: %i", string, Spieler[playerid][pPowerRiegel]); }
    if(Spieler[playerid][pSchaufel] != 0) { format(string, sizeof(string), "%s\nSchaufel: %i", string, Spieler[playerid][pSchaufel]); }
    format(ueberschrift, sizeof(ueberschrift), "Inventar von: %s", GetName(playerid));
    ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_LIST, ueberschrift, string, "OK", "");
    return 1;
}


CMD:mydata(playerid,params[]) {
    new
        Float:x,
        Float:y,
        Float:z,
        String[128];
    GetPlayerPos(playerid,x,y,z);
    format(String,sizeof(String),"World: %d Interior: %d ",GetPlayerVirtualWorld(playerid),GetPlayerInterior(playerid));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"X: %.1f Y: %.1f Z: %.1f",x,y,z);
    SendClientMessage(playerid,COLOR_WHITE,String);
    return 1;
}



CMD:kampfstyle(playerid,params[]) {
    for(new i ; i < sizeof(g_KampfShop) ; i++) {
        if( GetPlayerInterior(playerid) == g_KampfShop[i][KS_iInterior] ) {
            if( GetPlayerVirtualWorld(playerid) == g_KampfShop[i][KS_iVirtualWorld] ) {
                if( IsPlayerInRangeOfPoint(playerid,5.0,g_KampfShop[i][KS_fX],g_KampfShop[i][KS_fY],g_KampfShop[i][KS_fZ])) {
                    ShowPlayerKampfStyleList(playerid);
                    return 1;
                }
            }
        }
    }
    SendClientMessage(playerid,COLOR_RED,"Hier kannst du keinen Kampfstyle kaufen");
    return 1;
}

CMD:kampfstil(playerid,params[]) {
    return cmd_kampfstyle(playerid,params);
}


CMD:pickwaffe(playerid,params[]) {
    if(Spieler[playerid][pTot] == 1 || Spieler[playerid][pTot] == 2 )return SendClientMessage(playerid, COLOR_RED, "Während du Tot bist, kannst du diese Funktion nicht nutzen.");
    if( Spieler[playerid][pLevel] < 4 ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist unter Level 4 und kannst die Waffe daher nicht aufheben!");
        return 1;
    }
    if(HasWeaponBlock(playerid)) {
        return SendWeaponBlockInfo(playerid);
    }
    for(new i ; i < sizeof(DropItems) ; i++) {
        if( DropItems[i][DI_iExtra] != 0 && DropItems[i][DI_iPlayerID] != INVALID_PLAYER_ID ) {
            if( IsPlayerInRangeOfPoint(playerid,3.0,DropItems[i][DI_fX],DropItems[i][DI_fY],DropItems[i][DI_fZ])) {
                Weapon_OnPlayerPickUpPickup(playerid,i);
                ShowBuyInformation(playerid,"~y~Waffe ~w~aufgehoben!");
            }
        }
    }
    return 1;
}





CMD:kredit(playerid,params[]) {
    if(Spieler[playerid][pKreditwert] != 0 ) {
        return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst keinen zweiten Kredit beantragen.");
    }
    if( !IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLS_CREDIT_POINT) && !IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLV_CREDIT_POINT) ) {
        return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst hier keinen Kredit beantragen.");
    }
    ShowKreditLimitUebersicht(playerid,0);
    return 1;
}


CMD:musik(playerid,params[]) {
    if( !Spieler[playerid][pMP3Player] ) {
        return SendClientMessage(playerid,COLOR_RED,"Du besitzt keinen MP3-Player.");
    }
    ShowPlayerDialog(playerid, DIALOG_MUSIK, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Radiosender", COLOR_HEX_WHITE"Radio ausschalten\n1-Live\nTechnoBase.FM\nHardBase.FM\nI Love Radio\nBreakz.us\nYouFM\nPlanet Radio\nThe Club\nNightWax\nI Love Mashup\nDas Hitradio\nI Love the Battle\nI Love 2Dance\nLogin-Musik\niTunes Hot 40\nRMF MAXXX\nEigener Audiostream", "Auswählen", "Abbrechen");
    return 1;
}
CMD:mp3player(playerid,params[]) {
    return cmd_musik(playerid,params);
}


CMD:wdrop(playerid,params[]) {
    if( GetPlayerWeapon(playerid) == 0 ) {
        SendClientMessage(playerid,COLOR_RED,"Du hast keine Waffe, die du ablegen kannst.");
        return 1;
    }
    if( ForbiddenGun(playerid) ) {
        new string[128];
        SendClientMessage(playerid,COLOR_RED,"Du besitzt eine nicht erlaubte Waffe auf dem Server!");
        SendClientMessage(playerid,COLOR_RED,"Eine Nachricht an das Admin-Team wurde gesendet.");
        format(string,sizeof(string),"Warnung: %s wollte eine verbotene Waffe dropen! Umgehend überprüfen!!",GetName(playerid));
        SendAdminMessage(COLOR_RED,string);
        return 1;
    }
    if( DropWeapon(playerid) == 0 ) {
        SendClientMessage(playerid,COLOR_RED,"Diese Waffe kann nicht abgelegt werden.");
        return 1;
    }
    else {
        SendClientMessage(playerid,COLOR_YELLOW,"Du hast die Waffe weggeworfen.");
    }
    return 1;
}


CMD:bank(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLS_SERVICE_POINT) && !IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLV_SERVICE_POINT) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst diesen Befehl hier nicht ausführen.");
    }
    Spieler[playerid][pPinVergessen] = 0;
    ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Bank", COLOR_HEX_WHITE"Bank-Info\nBankpin ändern\nGeldcheck einlösen\nBankpin vergessen", "Ausführen", "Abbrechen");
    return 1;
}

CMD:koffer(playerid,params[]) {
    if (Spieler[playerid][pKoffer] == false ) return SendClientMessage(playerid, COLOR_RED, "Du besitzt keinen Koffer.");
    if (Spieler[playerid][pTotTime] || Spieler[playerid][bKidnapped] || Cuffed[playerid]) 
        return SendClientMessage(playerid, COLOR_RED, "Du kannst den Koffer jetzt gerade nicht benutzen.");
    if (Spieler[playerid][pJailed] || Spieler[playerid][pPrisonRun] || PlayerIsPaintballing[playerid]) 
        return SendClientMessage(playerid, COLOR_RED, "Du kannst den Koffer hier nicht benutzen.");

    if( IsPlayerAttachedObjectSlotUsed(playerid,ATTACHED_INDEX_KOFFER) ) {
        RemovePlayerAttachedObject(playerid,ATTACHED_INDEX_KOFFER);
    }
    else {
        SetPlayerAttachedObject( playerid, ATTACHED_INDEX_KOFFER, 1210, 5, 0.293532, 0.103431, 0.007843, 340.256103, 257.806579, 0.000000, 1.000000, 1.000000, 1.000000 );
    }
    return 1;
}

CMD:kofferauf(playerid, params[]) {
    if (Spieler[playerid][pKoffer] == false) return SendClientMessage(playerid, COLOR_RED, "Du besitzt keinen Koffer.");
    if (!IsPlayerAttachedObjectSlotUsed(playerid, ATTACHED_INDEX_KOFFER)) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Koffer nur öffnen, wenn du ihn gerade trägst.");
    if (Spieler[playerid][pTotTime] || Spieler[playerid][bKidnapped] || Cuffed[playerid]) 
        return SendClientMessage(playerid, COLOR_RED, "Du kannst den Koffer jetzt gerade nicht benutzen.");
    if (Spieler[playerid][pJailed] || Spieler[playerid][pPrisonRun] || PlayerIsPaintballing[playerid]) 
        return SendClientMessage(playerid, COLOR_RED, "Du kannst den Koffer hier nicht benutzen.");
    ShowKoffer(playerid, playerid);
    return 1;
}



CMD:haustiershop(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,3.0, PETSHOP_COORDS)) {
        return SendClientMessage(playerid,COLOR_RED,"Du bist nicht am Haustier Geschäft.");
    }
    ShowPlayerDialog(playerid,DIALOG_HAUSTIER,DIALOG_STYLE_LIST,"Haustier Geschäft","Hund - $500.000\nPapagei - $400.000\nSchildkröte - $300.000\n1x Futter - $20.000","Kaufen","Abbruch");
    return 1;
}
CMD:haustier(playerid,params[]) {
    if( 1 <= Spieler[playerid][pHaustier] <= 3 ) {
        // Hat n Haustier
        if( Spieler[playerid][pHaustierSpawned] ) {
            Haustier_RemovePlayer(playerid);
            SendClientMessage(playerid,COLOR_ORANGE,"Du gehst nicht mehr mit deinem Haustier spazieren.");
            Spieler[playerid][pHaustierSpawned] = false;
        }
        else {
            SendClientMessage(playerid,COLOR_GREEN,"Du gehst mit deinem Haustier spazieren.");
            Haustier_SetPlayer(playerid);
            Spieler[playerid][pHaustierSpawned] = true;
        }
    }
    else if( Spieler[playerid][pHaustier] == 0 ) {
        SendClientMessage(playerid,COLOR_YELLOW,"Du hast kein Haustier.");
    }
    else {
        SendClientMessage(playerid,COLOR_YELLOW,"Du hast ein Haustierverbot.");
    }
    return 1;
}
CMD:sellhaustier(playerid,params[]) {
    if( 1 <= Spieler[playerid][pHaustier] <= 3 ) {
        new haustier[16];
        new String[128];
        if( Spieler[playerid][pHaustier] == 1 ) {
            haustier = "Hund";
        }
        else if( Spieler[playerid][pHaustier] == 2 ) {
            haustier = "Papagei";
        }
        else if( Spieler[playerid][pHaustier] == 3 ) {
            haustier = "Schildkröte";
        }
        format(String,sizeof(String),"Du hast deine(n) %s verkauft.",haustier);
        SendClientMessage(playerid,COLOR_YELLOW,String);
        Haustier_RemovePlayer(playerid);
        Spieler[playerid][pHaustier] = 0;
        Spieler[playerid][pHaustierCooldown] = 0;
        Spieler[playerid][pHaustierSpawned] = false;
    }
    else {
        SendClientMessage(playerid,COLOR_RED,"Du besitzt kein Haustier.");
    }
    return 1;
}
CMD:fuettern(playerid,params[]) {
    if( 1 <= Spieler[playerid][pHaustier] <= 3 ) {
        if( !Haustier_OnFoot(playerid) ) {
            return SendClientMessage(playerid,COLOR_RED,"Dein Haustier ist nicht mit dir Gassi.");
        }
        new haustier[16];
        new String[128];
        if( Spieler[playerid][pHaustier] == 1 ) {
            haustier = "Hund";
        }
        else if( Spieler[playerid][pHaustier] == 2 ) {
            haustier = "Papagei";
        }
        else if( Spieler[playerid][pHaustier] == 3 ) {
            haustier = "Schildkröte";
        }
        if( Spieler[playerid][pHaustierFutter] > 0 ) {
            if( 80 <= Spieler[playerid][pHaustierCooldown] < 150 ) {
                format(String,sizeof(String),"Du hast deine(n) %s gefüttert, obwohl es keinen Hunger hat.",haustier);
            }
            else if( Spieler[playerid][pHaustierCooldown] >= 150 ) {
                format(String,sizeof(String),"Du kannst deine(n) %s nicht weiter füttern. Es hat keinen Appetit.",haustier);
                SendClientMessage(playerid,COLOR_RED,String);
                return 1;
            }
            else {
                format(String,sizeof(String),"Du hast deine(n) %s gefüttert.",haustier);
                SendClientMessage(playerid,COLOR_YELLOW,String);
            }
            Spieler[playerid][pHaustierFutter]--;
            Spieler[playerid][pHaustierCooldown] += 80; // 80min pro Futter "gut schreiben";
            if( Spieler[playerid][pHaustierCooldown] > 160 ) {
                Spieler[playerid][pHaustierCooldown] = 160;
            }
            return cmd_me(playerid,"füttert sein Haustier");

        }
        else {
            format(String,sizeof(String),"Du hast kein Futter für deine(n) %s.",haustier);
            SendClientMessage(playerid,COLOR_RED,String);
        }
    }
    else {
        SendClientMessage(playerid,COLOR_RED,"Du besitzt kein Haustier.");
    }
    return 1;
}



CMD:ap(playerid,params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    new giveid, now = gettime();
    if (Spieler[playerid][ptickBotTest] > now) return SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Du kannst den Aimbot-Test nur jede Minute durchführen.");
    if (sscanf(params, "u", giveid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Ap [Spieler]");
    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online.");
    if (giveid == playerid) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst dich nicht selbst auf Aimbot testen.");

    new Float:gx, Float:gy, Float:gz;
    GetPlayerPos(giveid, gx, gy, gz);
    if (!IsPlayerInRangeOfPoint(playerid, 11.0, gx, gy, gz)) return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Der Spieler befindet sich nicht in deiner Nähe.");
    GetPlayerFacingAngle(giveid, Spieler[playerid][pAimbotTestValues][0]);
    new Float:px, Float:py, Float:pz, Float:face;
    GetPlayerPos(playerid, px, py, pz);
    GetPlayerFacingAngle(playerid, face);

    Spieler[playerid][ptickBotTest] = now + 1*60;
    new Float:nx = gx, Float:ny = gy, Float:cx, Float:cy, Float:cz;
    GetXYInFrontOfPosition(nx, ny, Spieler[playerid][pAimbotTestValues][0], -9.0);

    GetPlayerCameraPos(playerid, cx, cy, cz);
    SetPlayerPos(playerid, nx, ny, gz);
    SetPlayerCameraPos(playerid, cx, cy, cz);
    SetPlayerCameraLookAt(playerid, gx, gy, gz);
    SetTimerEx("AimbotTest_Reset", 519, false, "ddffff", playerid, giveid, px, py, pz, face);
    return 1;
}



CMD:scheinsperre(playerid,params[]) {
    new
        sperren,
        sekunden,
        minuten,
        stunden,
        time_left,
        String[128],
        unix = gettime();
    SendClientMessage(playerid,COLOR_RED,"=============FAHRSCHEIN-SPERRFRIST=============");
    if( unix < Spieler[playerid][punixFSperre] ) { // car
        time_left = Spieler[playerid][punixFSperre] - unix;
        ConvertSec( time_left , sekunden,minuten,stunden );

        format(String,sizeof(String),"Auto-Lizenzsperre läuft in %d Stunden und %d Minuten aus!",stunden,minuten);
        SendClientMessage(playerid,COLOR_ORANGE,String);

        sperren++;
    }
    if( unix < Spieler[playerid][punixFlSperre] ) { // fly
        time_left = Spieler[playerid][punixFlSperre] - unix;
        ConvertSec( time_left , sekunden,minuten,stunden );

        format(String,sizeof(String),"Flug-Lizenzsperre läuft in %d Stunden und %d Minuten aus!",stunden,minuten);
        SendClientMessage(playerid,COLOR_ORANGE,String);

        sperren++;
    }
    if( unix < Spieler[playerid][punixGunSperre] ) {
        time_left = Spieler[playerid][punixGunSperre] - unix;
        ConvertSec( time_left , sekunden,minuten,stunden );

        format(String,sizeof(String),"Waffen-Lizenzsperre läuft in %d Stunden und %d Minuten aus!",stunden,minuten);
        SendClientMessage(playerid,COLOR_ORANGE,String);

        sperren++;
    }
    if( unix < Spieler[playerid][punixLKWSperre] ) {
        time_left = Spieler[playerid][punixLKWSperre] - unix;
        ConvertSec( time_left , sekunden,minuten,stunden );

        format(String,sizeof(String),"LKW-Lizenzsperre läuft in %d Stunden und %d Minuten aus!",stunden,minuten);
        SendClientMessage(playerid,COLOR_ORANGE,String);

        sperren++;
    }
    if( unix < Spieler[playerid][punixMotoSperre] ) { // motorrad
        time_left = Spieler[playerid][punixMotoSperre] - unix;
        ConvertSec( time_left , sekunden,minuten,stunden );

        format(String,sizeof(String),"Motorrad-Lizenzsperre läuft in %d Stunden und %d Minuten aus!",stunden,minuten);
        SendClientMessage(playerid,COLOR_ORANGE,String);

        sperren++;
    }
    if(!sperren) {
        SendClientMessage(playerid,COLOR_GREEN,"Keiner deiner Scheine ist gesperrt!");
    }
    return 1;
}


CMD:elektromarkt(playerid)
{
    if( IsPlayerInRangeOfPoint(playerid,5.0, ELECTRONICSSHOP_COORDS) )
    {
        if( Spieler[playerid][pHandyGeld] == HANDY_VERTRAG ) {
            ShowPlayerDialog(playerid, DIALOG_HANDYSHOP, DIALOG_STYLE_LIST, "Elektromarkt", "Handy kaufen\nHandyvertrag kündigen\nKamera kaufen ($15000)\nMusikkit (MP3-Player + Ghettoblaster) ($20.500)", "Kaufen", "Abbrechen");
        }
        else {
            ShowPlayerDialog(playerid, DIALOG_HANDYSHOP, DIALOG_STYLE_LIST, "Elektromarkt", "Handy kaufen\nHandy Vertrag ($4.000)\nKamera kaufen ($15000)\nMusikkit (MP3-Player + Ghettoblaster) ($20.500)\nCallYa-Handykarte\nCallYa Guthaben", "Kaufen", "Abbrechen");
        }
        return 1;
    }
    SendClientMessage(playerid, COLOR_RED, "Du musst dich im Elektromarkt an der Kasse befinden!");
    return 1;
}


CMD:zoll(playerid,params[]) {
    new zoll;
    zoll = GetPlayerZollArea(playerid);
    if( zoll == -1 ) return SendClientMessage(playerid,COLOR_RED,"Du befindest dich an keiner Zoll-Station");
    if( g_Zoll[zoll][Z_bSperre] ) return SendClientMessage(playerid,COLOR_RED,"Zollwächter: Die Zollstationen wurden aufgrund einer polizeilichen Maßnahme gesperrt. Sie können die Grenze nicht überqueren!");
    if( !Zoll_Open(zoll,playerid) ) return SendClientMessage(playerid,COLOR_RED,"Zollwächter: Die Bearbeitung eines anderen Fahrer findet noch statt");
    if( Spieler[playerid][pCash] < 5000 && gettime() < Spieler[playerid][pZollValid] ) return SendClientMessage(playerid,COLOR_RED,"Zollwächter: Um die Grenze zu überqueren, müssen Sie die Zollgebühren in Höhe von $5.000 bezahlen!");
    if( Spieler[playerid][pZollValid] < gettime() ) {
        GivePlayerCash(playerid, -5000);
        TreasuryDeposit(500);
        SendClientMessage(playerid,COLOR_YELLOW,"Zollwächter: Vielen Dank! Sie dürfen den Zoll überqueren. Gute Weiterfahrt ( -5.000$ )!");
    }
    else {
        SendClientMessage(playerid,COLOR_YELLOW,"Zollwächter: Vielen Dank! Sie dürfen den Zoll überqueren. Gute Weiterfahrt!");
    }
    return 1;
}


CMD:spielerinfo(playerid,params[]) {
    new  Spielername[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",Spielername))return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Spielerinfo [Spielername]");
    if(strcmp(Spielername,params)) return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Spielerinfo [Spielername (Keine Sonderzeichen)]");
    mysql_real_escape_string(Spielername,Spielername);

    new String[140];
    format(String,sizeof(String),"SELECT `Name`,DATE_FORMAT(`LastSeen`,'%%e.%%m.%%Y %%H:%%i'),`Banned` FROM `accounts` WHERE `Name` = '%s'",Spielername);
    mysql_pquery(String,THREAD_SPIELERINFO,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:gutscheincode(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    ShowPlayerDialog(playerid,DIALOG_GUTSCHEINCODE,DIALOG_STYLE_INPUT,"{4444FF}Gutscheincode","{FFFFFF}Bitte gib den Gutscheincode ein","Einlösen","Abbruch");
    return 1;
}



CMD:sinfo(playerid,params[]) {
    #pragma unused params
    if( Spieler[playerid][t3dSInfo] == Text3D:INVALID_3DTEXT_ID ) {
        SendClientMessage(playerid,COLOR_YELLOW,"Über deinem Kopf werden nun für deine Mitspieler FPS und Ping angezeigt");
        Spieler[playerid][t3dSInfo] = Text3D:CreateDynamic3DTextLabel("Initialisierung...", COLOR_GREY, 0.0, 0.0, 0.0 , 14.0 , .attachedplayer = playerid);
        Streamer_SetFloatData( STREAMER_TYPE_3D_TEXT_LABEL , Spieler[playerid][t3dSInfo] , E_STREAMER_ATTACH_OFFSET_X , 0.0 );
        Streamer_SetFloatData( STREAMER_TYPE_3D_TEXT_LABEL , Spieler[playerid][t3dSInfo] , E_STREAMER_ATTACH_OFFSET_Y , 0.0 );
        Streamer_SetFloatData( STREAMER_TYPE_3D_TEXT_LABEL , Spieler[playerid][t3dSInfo] , E_STREAMER_ATTACH_OFFSET_Z , 0.45 );
    }
    else {
        DestroyDynamic3DTextLabel(Spieler[playerid][t3dSInfo]);
        Spieler[playerid][t3dSInfo] = Text3D:INVALID_3DTEXT_ID;
        SendClientMessage(playerid,COLOR_ORANGE,"Über deinem Kopf werden FPS und Ping nicht mehr angezeigt");
    }
    return 1;
}


CMD:vertrag(playerid,params[]) {
    new giveid, text[128];
    if(sscanf(params,"us[128]",giveid,text)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Vertrag [ID/Name] [Text]");
    if( !IsPlayerConnected(giveid)) return SendClientMessage(playerid,COLOR_RED,"Der Spieler wurde nicht gefunden");
    if( GetPlayerVertragsPartner(playerid) != INVALID_PLAYER_ID ) return SendClientMessage(playerid,COLOR_RED,"Du hast bereits eine Vertrag Anfrage verschickt");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,6.0,x,y,z) ) return SendClientMessage(playerid,COLOR_RED,"Dein Vertragspartner ist zu weit entfernt von dir");
    if( GetPlayerVertragsPartner(giveid) != INVALID_PLAYER_ID )  return SendClientMessage(playerid,COLOR_RED,"Dein Vertragspartner ist bereits in einer Vertragsverhandlung");
    new String[160];
    format(String,sizeof(String),"Spieler %s bietet dir ein Vertrag an.",GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    format(String,sizeof(String),"Bedingung: %s",text);
    SendClientMessage(giveid,COLOR_ORANGE,String);
    SendClientMessage(giveid,COLOR_RED,"Nehmen diesen Vertrag mit '/Accept Vertrag' an! => ACHTUNG! Dieser Vertag ist dann offiziell rechtsfähig und muss eingehalten werden!");
    format(String,sizeof(String),"Du hast Spieler %s ein Vertrag angeboten.",GetName(giveid));
    SendClientMessage(playerid,COLOR_YELLOW,String);
    format(String,sizeof(String),"Bedingung: %s",text);
    SendClientMessage(playerid,COLOR_ORANGE,String);
    Spieler[playerid][pVertragID] = giveid;
    format(Spieler[playerid][pVertragText],128,"%s",text);
    return 1;
}



CMD:findatm(playerid) return cmd_suchatm(playerid);

CMD:suchatm(playerid)
{
    new Float:x, Float:y, Float:z, Float:distance, Float:smallestDistance = 10000, index = 0;
    GetPlayerPos(playerid, x, y, z);
    for (new i = 0; i < sizeof(ATM); i++)
        if ((distance = GetDistance(x, y, z, ATM[i][0], ATM[i][1], ATM[i][2])) < smallestDistance) index = i, smallestDistance = distance;

    SetPlayerCheckpointEx(playerid, ATM[index][0], ATM[index][1], ATM[index][2], 2.0, CP_NAVI1);
    return SendClientMessage(playerid, COLOR_GREEN, "[INFO] {FFFFFF}Der nächste Bankautomat wurde dir auf der Karte Rot markiert.");
}

CMD:delmarker(playerid,params[])
{
    DisablePlayerCheckpointEx(playerid);
    return 1;
}


CMD:kampfzoneinfo(playerid)
{
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    if(!kampfzone[1]) return SendClientMessage(playerid, COLOR_RED,"Es findet momentan kein Kampf in der Kampfzone statt.");
	for(new i;i<MAX_FACTIONS;i++)
	{
	    if(!IsAFightFaction(i))continue;
		SCMFormatted(playerid, COLOR_YELLOW, "Punkte der Fraktion %s : \t\t\t %i",factionNames[i],kampfzonePoints[i]);
	}
	return 1;
}

CMD:gfwette(playerid, params[])
{
    return cmd_gangfightwette(playerid, params);
}


CMD:gangfightwette(playerid,params[])
{
    new gangfightname[64],wetteinsatz;
    if(sscanf(params,"s[64]i",gangfightname,wetteinsatz))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Gangfightwette [Gangname] [ Wetteinsatz (100$ bis 100.000$) ]");
    if(CheckMoney(playerid)>=wetteinsatz)
    {
        if(wetteinsatz<100)
        {
            SendClientMessage(playerid,COLOR_RED,"Der Wetteinsatz muss mindestens 100$ betragen.");
        }
        else if(wetteinsatz>100000)
        {
            SendClientMessage(playerid,COLOR_RED,"Der Wetteinsatz darf maximal 100.000$ betragen.");
        }
        else if(GetPlayerScore(playerid)>=3)
        {
            if(gangfightwettenpp[playerid]<100)
            {
                for(new i;i<4;i++)
                {
                    for(new z;z<2;z++)
                    {
                        new gangname[20];
                        if(strcmp(GFWetteNameFaction(gangfightkampffraks[i][z]),"Grove Street",true)==0)
                        {
                            format(gangname,20,"GroveStreet");
                        }
                        else
                        {
                            format(gangname,20,"%s",GetFactionNameGF(gangfightkampffraks[i][z]));
                        }
                        if(strcmp(gangfightname,GFWetteNameFaction(gangfightkampffraks[i][z]),true)==0&&IsGangInFight(gangfightkampffraks[i][z]))
                        {
                            if(gangfightwetten[i]+180>gettime())
                            {
                                if(gangfightkampffraks[i][0]==Spieler[playerid][pFraktion]||gangfightkampffraks[i][1]==Spieler[playerid][pFraktion])
                                {
                                    SendClientMessage(playerid,COLOR_RED,"Du kannst nicht auf diesen Gangfight wetten, da du selbst in diesen Kampf involviert bist.");
                                }
                                else
                                {
                                    gangfightwettenpot[i]+=wetteinsatz;
                                    GivePlayerCash(playerid,-wetteinsatz);
                                    format(gangfightwettenp[playerid],MAX_PLAYER_NAME,"%s",GetName(i));
                                    gangfightwettenpp[playerid]=wetteinsatz;
                                    gangfightwettenppp[playerid]=gangfightkampffraks[i][z];
                                    new string[200];
                                    format(string,200,"Du hast $%s auf die %s gewettet. Viel Glück!!", AddDelimiters(wetteinsatz),GFWetteNameFaction(gangfightkampffraks[i][z]));
                                    SendClientMessage(playerid,COLOR_YELLOW,string);
                                    i=4,z=2;
                                    break;
                                }
                            }
                            else
                            {
                                SendClientMessage(playerid,COLOR_RED,"Es werden nur 3 Minuten nach Gangfightbeginn Wetten angenommen!");
                                i=4,z=2;
                                break;
                            }
                        }
                        else if(i==3&&z==1)
                        {
                            SendClientMessage(playerid,COLOR_RED,"So eine Gang kämpft aktuell nicht im Gangfight.");
                            SendClientMessage(playerid,COLOR_RED,"Beachte: Grove Street schreibt man als GroveStreet und die Cali Kartell als Cali");
                        }
                    }
                }
            }
            else
            {
                SendClientMessage(playerid,COLOR_RED,"Du hast bereits eine Gangfight-Wette am laufen.");
            }
        }
        else
        {
            SendClientMessage(playerid,COLOR_RED,"Du musst mindestens Level 3 erreicht haben um Wetten abschließen zu können!");
        }
    }
    else
    {
        SendClientMessage(playerid,COLOR_RED,"Du besitzt nicht so viel Geld!");
    }
    return 1;
}




CMD:jailtime(playerid, params[])
{
    if (Spieler[playerid][pJailed] == 0) return SendClientMessage(playerid, COLOR_ORANGE, "Du bist nicht im Gefängnis.");
    new sekunden, minute, stunde;
    new myJailTimeout = JAIL_TIMEOUT - (gettime() - GetPVarInt(playerid, "JAIL.TIMESTAMP"));
    if (myJailTimeout > Spieler[playerid][pJailTime]) myJailTimeout = Spieler[playerid][pJailTime];

    new waitingTimeString[64];
    if (Spieler[playerid][pJailed] != 1) waitingTimeString = "";
    else {
        if (myJailTimeout <= 0) waitingTimeString = " (keine Wartezeit)";
        else if (myJailTimeout == 1) waitingTimeString = " (eine Sekunde Wartezeit)";
        else format(waitingTimeString, sizeof(waitingTimeString), " (%d Sekunden Wartezeit)", myJailTimeout);
    }
    ConvertSec(Spieler[playerid][pJailTime], sekunden, minute, stunde);
    SCMFormatted(playerid, COLOR_WHITE, "Du bist noch für %d Sekunden [%d Min.] im Gefängnis%s.", Spieler[playerid][pJailTime], minute, waitingTimeString);
    return 1;
}

CMD:tottime(playerid, params[])
{
    new string[128];
    if(Spieler[playerid][pTot] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Du bist nicht tot.");
    format(string, sizeof(string), "Du bist noch für %d Sekunden verletzt.", Spieler[playerid][pTotTime]);
    SendClientMessage(playerid, COLOR_WHITE, string);
    return 1;
}

CMD:mutetime(playerid, params[])
{
	new sekunden, minute, stunde;
    if(Spieler[playerid][pMuted] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Du bist nicht gemutet.");
    ConvertSec(Spieler[playerid][pMuteTime], sekunden, minute, stunde);
    SCMFormatted(playerid, COLOR_WHITE, "Dein Mute hält noch %d Sekunden [%d Min.] an.", Spieler[playerid][pMuteTime], minute);
    return 1;
}




CMD:lotto(playerid, params[])
{
    new entry, string[128];
    if(sscanf(params, "i", entry))
    {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Lotto [Nummer] - Ein Ticket kostet $10.000");
        format(string, sizeof(string), "** Lotto-Stand: $%s", AddDelimiters(Lottostand));
        SendClientMessage(playerid, COLOR_GREY, string);
        return 1;
    }
    if( Spieler[playerid][pLevel] < 3 ) return SendClientMessage(playerid, COLOR_RED, "Du musst Level 3 sein, um bei der Lottoziehung teilnehmen zu können.");
    if(Spieler[playerid][pLottoNr] > 0) return SendClientMessage(playerid, COLOR_RED, "Du hast bereits ein Lottoticket.");
    if(CheckMoney(playerid) < 10000) return SendClientMessage(playerid, COLOR_ORANGE, "Ein Lottoticket kostet dich 10.000$.");
    if(entry < 1 || entry > 100)return SendClientMessage(playerid, COLOR_ORANGE, "Die Lotto-Nummer muss zwischen 1 und 100 liegen.");
    format(string, sizeof(string), "* Du hast dir ein Lottoticket mit der Nummer %d gekauft. (-$10.000)", entry);
    SendClientMessage(playerid, COLOR_GREEN, string);
    Spieler[playerid][pLottoNr] = entry;
    Lottostand += 5000;
    TreasuryDeposit(5000);
    GivePlayerCash(playerid, -10000);
    return 1;
}



CMD:isskeks(playerid)
{
    new string[128];
    if(Spieler[playerid][pKekse] < 1)return SendClientMessage(playerid, COLOR_RED, "Du hast keine Kekse mehr.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    new Float:health;
    GetPlayerHealth(playerid, health);
    if (IsEnemyInZone(playerid)) return 1;

    if(damagesperre[playerid]>0)
    {
        SendClientMessage(playerid,COLOR_RED,"Da du Schaden genommen hast, kannst du erst nach 5 Sekunden deine HP wieder pushen.");
    }
    else if( Spieler[playerid][pKekseValue] >= 7 )
    {
        SendClientMessage(playerid,COLOR_RED,"Du hast zu viele Kekse hintereinander gegessen!");
        ApplyAnimation( playerid , "FOOD", "EAT_Vomit_P", 4.1,0,1,1,0,-1,1);
        SetPlayerHealth(playerid, health - 7);
        Spieler[playerid][pKekse]--;
    }
    else if(health<100)
    {
		if(Spieler[playerid][bMaske])
	    {
 			Spieler[playerid][pKekse]--;
			SetPlayerHealth(playerid, health + 2);
			format(string, sizeof(string), "* Ein Maskierter mampft einen Keks.");
			SendRoundMessage(x,y,z, COLOR_PURPLE, string);
			ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
			SetTimerEx("CoolDownKekse",6003,false,"dd",playerid,1);
			Spieler[playerid][pKekseValue]++;
	    }
	    else
	    {
			Spieler[playerid][pKekse]--;
			SetPlayerHealth(playerid, health + 2);
			format(string, sizeof(string), "* %s mampft einen Keks.", GetName(playerid));
			SendRoundMessage(x,y,z, COLOR_PURPLE, string);
			ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
			SetTimerEx("CoolDownKekse",6003,false,"dd",playerid,1);
			Spieler[playerid][pKekseValue]++;
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du kannst keine Kekse mehr essen, da du zuviel Leben hast.");
        return 1;
    }
    return 1;
}

CMD:riegel(playerid)
{
    new string[128];
    if(Spieler[playerid][pPowerRiegel] < 1)return SendClientMessage(playerid, COLOR_RED, "Du hast keine Power-Riegel mehr.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    new Float:health;
    GetPlayerHealth(playerid, health);
    if (IsEnemyInZone(playerid)) return 1;

    if(damagesperre[playerid]>0)
    {
        SendClientMessage(playerid,COLOR_RED,"Da du Schaden genommen hast, kannst du erst nach 5 Sekunden deine HP wieder pushen.");
    }
    else if( Spieler[playerid][pKekseValue] >= 7 )
    {
        SendClientMessage(playerid,COLOR_RED,"Du hast zu viele Power-Riegel hintereinander gegessen!");
        ApplyAnimation( playerid , "FOOD", "EAT_Vomit_P", 4.1,0,1,1,0,-1,1);
        SetPlayerHealth(playerid, health - 7);
        Spieler[playerid][pPowerRiegel]--;
    }
    else if(health<100)
    {
		if(Spieler[playerid][bMaske])
	    {
 			Spieler[playerid][pPowerRiegel]--;
			SetPlayerHealth(playerid, health + 15);
			format(string, sizeof(string), "* Ein Maskierter isst einen Power-Riegel.");
			SendRoundMessage(x,y,z, COLOR_PURPLE, string);
			ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
			SetTimerEx("CoolDownKekse",6003,false,"dd",playerid,1);
			Spieler[playerid][pKekseValue]++;
	    }
	    else
	    {
			Spieler[playerid][pPowerRiegel]--;
			SetPlayerHealth(playerid, health + 15);
			format(string, sizeof(string), "* %s isst einen Power-Riegel.", GetName(playerid));
			SendRoundMessage(x,y,z, COLOR_PURPLE, string);
			ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
			SetTimerEx("CoolDownKekse",6003,false,"dd",playerid,1);
			Spieler[playerid][pKekseValue]++;
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Power-Riegel mehr essen, da du zuviel Leben hast.");
        return 1;
    }
    return 1;
}

CMD:zigweg(playerid)
{
    if (!GetPVarInt(playerid, "SMOKING_CIG")) return SendClientMessage(playerid, COLOR_RED, "Du rauchst doch gar keine Zigarette.");
    new string[128];
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    ClearAnimations(playerid);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    format(string, sizeof(string), "* %s wirft seine Zigarette weg.", GetName(playerid));
    SendRoundMessage(x,y,z, COLOR_PURPLE, string);
    return 1;
}

CMD:rauchzig(playerid)
{
    new string[128];
    if(Spieler[playerid][pZigaretten] < 1)return SendClientMessage(playerid, COLOR_RED, "Du hast keine Zigaretten mehr.");
    if(Spieler[playerid][pPrisonRun] > 0 ) return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Rauchen, wenn du im Straflauf bist!");
    //if(!IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    new Float:health;
    GetPlayerHealth(playerid, health);
    if(health>10)
    {
        Spieler[playerid][pZigaretten] --;
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
        format(string, sizeof(string), "* %s zündet sich eine Zigarette an.", GetName(playerid));
        SendRoundMessage(x,y,z, COLOR_PURPLE, string);
        SendClientMessage(playerid, COLOR_WHITE, "Tippe /Zigweg zum wegwerfen der Zigarette.");
        SetPVarInt(playerid, "SMOKING_CIG", 1);
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Dir geht es gesundheitlich zu schlecht!");
        return 1;
    }
    return 1;
}

CMD:booster(playerid)
{
    new Float:armour, Float:PlayerPos[3],string[128];
    GetPlayerArmour(playerid,armour);
    if (Spieler[playerid][pBooster] < 1) return SendClientMessage(playerid,COLOR_RED,"Du besitzt keinen Booster.");
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid,COLOR_RED,"Du kannst noch keinen Booster benutzen.");
    if (damagesperre[playerid]>0) return SendClientMessage(playerid,COLOR_RED,"Du kannst noch keinen Booster nehmen, da du gerade Schaden genommen hast.");
    if (armour >= 100) return SendClientMessage(playerid,COLOR_RED,"Du bist voller Energie, Du kannst keinen Booster mehr benutzen.");
    if (IsEnemyInZone(playerid)) return 1;

    armour += 50.0;
    if( armour > 100.0 ) armour = 100.0;
    SetPlayerArmour(playerid,armour);
    Spieler[playerid][pBooster] --;
    GetPlayerPos(playerid,PlayerPos[0],PlayerPos[1],PlayerPos[2]);
    format(string,sizeof(string),"* %s nimmt einen Booster zu sich.",GetName(playerid));
    SendRoundMessage(PlayerPos[0],PlayerPos[1],PlayerPos[2], COLOR_PURPLE, string);
    Spieler[playerid][unixSpiceCooldown] = gettime() + 10;
    KillTimer(DrogenTimer[playerid]);
    SetPlayerDrunkLevel(playerid, 2500);
    ApplyAnimation(playerid, "VENDING", "VEND_Drink_P", 4.0, 0, 0, 0, 0, 0);//Drinken
    return 1;
}




CMD:sellkekse(playerid, params[])
{
    new pID, menge, preis, Float:x, Float:y, Float:z, message[128];
    if (sscanf(params, "uii", pID, menge, preis)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Sellkekse [SpielerID/Name] [Menge] [Preis]");
    if (playerid == pID) return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber keine Kekse verkaufen.");
    if (preis < 1 || preis > 100000000) return SendClientMessage(playerid, COLOR_RED, "Der Preis muss zwischen $1 und $100.000.000 liegen.");
    GetPlayerPos(pID, x, y, z);
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (!IsPlayerInRangeOfPoint(playerid, 5.0, x,y,z)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
    if (menge > Spieler[playerid][pKekse]) return SendClientMessage(playerid, COLOR_RED, "Soviele Kekse besitzt du nicht.");
    if (menge <= 0) return SendClientMessage(playerid, COLOR_RED, "Das macht keinen Sinn!");
    if (preis/menge < 25 || preis/menge > 45) return SendClientMessage(playerid, COLOR_RED, "Der aktuelle Stückpreis von Keksen liegt bei $25 - $45 pro Keks.");
    format(message, sizeof(message), "%i %i %i", playerid, menge, preis);
    SetPVarString(pID, "BUY_COOKIES", message);

    format(message, sizeof(message), "Du hast von %s ein Angebot für Kekse erhalten. Menge: %d, Preis: $%s.", GetName(playerid), menge, AddDelimiters(preis));
    SendClientMessage(pID, COLOR_LIGHTBLUE, message);
    SendClientMessage(pID, COLOR_LIGHTBLUE, "Tippe '/Accept Kekse' um das Angebot anzunehmen.");
    format(message, sizeof(message), "Du hast %s deine Kekse angeboten. Menge: %d, Preis: $%s.", GetName(pID), menge, AddDelimiters(preis));
    return SendClientMessage(playerid, COLOR_LIGHTBLUE, message);
}


CMD:ueberweisen(playerid)
{
    if (!(IsPlayerInRangeOfPoint(playerid, 3.0, BANKINTERIORLS_TRANSFER_POINT) || IsPlayerInRangeOfPoint(playerid, 3.0, BANKINTERIORLV_TRANSFER_POINT))) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Bank am Überweisungsschalter.");
    if( Spieler[playerid][pLevel] < 4 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist unter Level 4 und kannst diese deshalb Funktion nicht nutzen!");
    }
    if( !HasBankKonto(playerid) ) {
        ShowPlayerDialog(playerid, DIALOG_BANKKONTO, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Bankautomat", COLOR_HEX_WHITE"Sie haben noch kein Bankkonto eingerichtet,\n um ein Bankkonto für einmalige 1.200$ einzurichten, \nklicken Sie auf \"einrichten\"", "Einrichten", "Abbrechen");
        return 1;
    }
    if( !HasBankKontoPin(playerid) ) {
        ShowPlayerDialog(playerid, DIALOG_BANKKONTO_PIN, DIALOG_STYLE_INPUT, COLOR_HEX_ORANGE"Bankautomat", COLOR_HEX_WHITE"Du musst für dein Bankkonto noch einen Pin festlegen.", "Absenden", "Abbrechen");
        return 1;
    }
    ShowPlayerDialog(playerid, DIALOG_UEBERWEISEN_PIN, DIALOG_STYLE_INPUT, COLOR_HEX_ORANGE"Überweisung", COLOR_HEX_WHITE"Bestätige zunächst mit deinem PIN", "Weiter", "Abbrechen");
    return 1;
}


CMD:automat(playerid,params[])
{
    #pragma unused params
    if(!IsPlayerAtATM(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist an keinem Bankautomat.");
    SetPlayerAutomatAnim(playerid);
    if( !HasBankKonto(playerid) ) {
        ShowPlayerDialog(playerid, DIALOG_BANKKONTO, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Bankautomat", COLOR_HEX_WHITE"Sie haben noch kein Bankkonto eingerichtet,\n um ein Bankkonto für einmalige 1.200$ einzurichten, \nklicken Sie auf \"einrichten\"", "Einrichten", "Abbrechen");
        return 1;
    }
    if( !HasBankKontoPin(playerid) ) {
        ShowPlayerDialog(playerid, DIALOG_BANKKONTO_PIN, DIALOG_STYLE_INPUT, COLOR_HEX_ORANGE"Bankautomat", COLOR_HEX_WHITE"Du musst für dein Bankkonto noch einen Pin festlegen.", "Absenden", "Abbrechen");
        return 1;
    }
    // ShowPlayerDialog(playerid, DIALOG_ATM, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Bankautomat", COLOR_HEX_WHITE"Geld abheben\nGeld anlegen\nKontostand\nBankpin\nGeldcheck einlösen", "Ausführen", "Abbrechen");
    ShowPlayerDialog(playerid, DIALOG_ATM, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Bankautomat", COLOR_HEX_WHITE"Geld abheben\nGeld anlegen\nKontostand\nOnlineBanking\nAutomat hacken", "Ausführen", "Abbrechen");
    return 1;
}



CMD:safebox(playerid,params[]) {
    if (!IsPlayerInRangeOfPoint(playerid, 3.0, SAFEBOX_COORDS_LS) && !IsPlayerInRangeOfPoint(playerid, 3.0, SAFEBOX_COORDS_LV) && !IsPlayerInRangeOfPoint(playerid, 3.0, SAFEBOX_COORDS_SF))
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht in der Nähe der Safebox! /Navi -> Illegale Orte -> Safebox");

    if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du darfst dafür nicht im Fahrzeug sein.");
    if (isnull(params)) return ShowSafeboxDialog(playerid, DIALOG_SAFEBOX_MENU);
    new menge, item, sItem[32], aktion, sAktion[32];
    if (sscanf(params, "s[32]s[32]d", sItem, sAktion, menge) || menge < 0) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Safebox [Drogen/Waffenteile/Wantedcodes/Spice] [rausnehmen/reinlegen] [Anzahl]");
        return SendClientMessage(playerid, COLOR_BLUE, "* Du kannst auch nur /Safebox für das Safebox-Menü benutzen.");
    }

    if (!strcmp(sItem, "drogen", true)) item = 1;
    else if (!strcmp(sItem, "waffenteile", true)) item = 2;
    else if (!strcmp(sItem, "wantedcodes", true)) item = 3;
    else if (!strcmp(sItem, "spice", true)) item = 4;

    if (!item) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Safebox [Drogen/Waffenteile/Wantedcodes/Spice] [rausnehmen/reinlegen] [Anzahl]");
        return SendClientMessage(playerid, COLOR_BLUE, "* Du kannst auch nur /Safebox für das Safebox-Menü benutzen.");
    }

    if (!strcmp(sAktion, "rausnehmen", true)) aktion = 1;
    else if (!strcmp(sAktion, "reinlegen", true)) aktion = 2;

    if (!aktion) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Safebox [Drogen/Waffenteile/Wantedcodes/Spice] [rausnehmen/reinlegen] [Anzahl]");
        return SendClientMessage(playerid, COLOR_BLUE, "* Du kannst auch nur /Safebox für das Safebox-Menü benutzen.");
    }

    SafeboxInteraction(playerid, aktion - 1, item - 1, menge, false);
    return 1;
}


CMD:geben(playerid, params[]) {
    new methode, giveid, inventar[24], anzahl;
    if (sscanf(params, "us[24]d", giveid, inventar, anzahl)) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Geben [SPIELERNAME/ID] [INVENTAR] [ANZAHL]");
        return SendClientMessage(playerid, COLOR_ORANGE, "Inventar = Waffen, Kekse, Zigaretten, Tankkanister, Fische oder Drogensamen, Riegel, Booster oder Schaufel");
    }

    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Der Spieler konnte nicht gefunden werden.");
    if (Spieler[giveid][pAdminDienst]) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist gerade im Admindienst.");
    if (Spieler[playerid][pLevel] < 3) return SendClientMessage(playerid, COLOR_RED, "Du musst Level 3 sein um einem anderen Spieler etwas zu geben!");
    if (Spieler[giveid][pLevel] < 3) return SendClientMessage(giveid, COLOR_RED, "Der Spieler muss mindestens Level 3 sein!");
    if (Spieler[giveid][bMaske]) return SendClientMessage(playerid, COLOR_RED, "Der Spieler kann gerade nichts entgegen nehmen.");
    if (Spieler[playerid][bMaske]) return SendClientMessage(playerid, COLOR_RED, "Du kannst mit einer Maske nichts geben!");
    if (playerid == giveid) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Das ergibt keinen Sinn. Wirklich nicht.");
    if (anzahl <= 0) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Gebe eine gültige Anzahl ein.");

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if (!IsPlayerInRangeOfPoint(giveid, 5.0, x, y, z)) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Der Spieler ist nicht in deiner Nähe.");

    if (!strcmp(inventar, "Waffen", true) || !strcmp(inventar, "waffen", true)) {
        inventar = "Waffen";
        methode = 1;
    }
    else if (!strcmp(inventar, "Kekse", true) || !strcmp(inventar, "kekse", true))
        methode = 2;
    else if (!strcmp(inventar, "Zigaretten", true) || !strcmp(inventar, "zigaretten", true))
        methode = 3;
    else if (!strcmp(inventar, "Kanister", true) || !strcmp(inventar, "kanister", true)) {
        inventar = "Kanister";
        methode = 4;
    }
    else if (!strcmp(inventar, "Fische", true) || !strcmp(inventar, "fische", true))
        methode = 5;
    else if (!strcmp(inventar, "Drogensamen", true) || !strcmp(inventar, "drogensamen", true))
        methode = 6;
    else if (!strcmp(inventar, "Riegel", true) || !strcmp(inventar, "riegel", true))
        methode = 7;
    else if (!strcmp(inventar, "Booster", true) || !strcmp(inventar, "booster", true))
        methode = 8;
    else if (!strcmp(inventar, "Schaufel", true) || !strcmp(inventar, "schaufel", true))
        methode = 9;

    new String[128];
    switch (methode) {
        case 0: {
            SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Geben [SPIELERNAME/ID] [INVENTAR] [ANZAHL]");
            return SendClientMessage(playerid, COLOR_ORANGE, "Inventar = Waffen, Kekse, Zigaretten, Tankkanister, Fische, Drogensamen, Riegel, Booster oder Schaufel");
        }
        case 1: {
            new weapon = GetPlayerWeapon(playerid), muni;
            if (weapon) {
                if (HasWeaponBlock(giveid)) {
                    SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler hat noch eine Waffensperre.");
                    return SendWeaponBlockInfo(giveid);
                }
                if(ForbiddenGun(playerid)) {
                    SendClientMessage(playerid, COLOR_ORANGE, "Du kannst diese Waffe nicht weiter geben!");
                    new stringstring[1024];
                    format(stringstring, sizeof(stringstring), "[{FF0000}ANTI-CHEAT{FFFFFF}] Der Spieler %s (ID: %i) hat versucht eine verbotene Waffe weiter zu geben!", GetName(playerid), playerid);
                    SendAdminMessage(COLOR_WHITE, stringstring);
                    return 1;
				}
                new slot = GetWeaponSlot(weapon);
                GetPlayerWeaponData(playerid, slot, weapon, muni);
                if (muni < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du besitzt nicht genug Munition von dieser Waffe.");
                GivePlayerWeapon(giveid, weapon, anzahl);
                GivePlayerWeapon(playerid, weapon, -anzahl);
                if (IsPlayerInAnyVehicle(giveid)) SetPlayerArmedWeapon(giveid, weapon == 29 || weapon == 31 ? weapon : 0);
                else SetPlayerArmedWeapon(giveid, weapon);
            }
            else 
                return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du musst die Waffe auf der Hand tragen.");
        }
        case 2: {
            if (Spieler[playerid][pKekse] < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du hast nicht genug Kekse.");
            if (anzahl > 100) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du darfst maximal 100 Kekse vergeben.");
            Spieler[playerid][pKekse] -= anzahl;
            Spieler[giveid][pKekse] += anzahl;
        }
        case 3: {
            if (Spieler[playerid][pZigaretten] < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du hast nicht genug Zigaretten.");
            Spieler[playerid][pZigaretten] -= anzahl;
            Spieler[giveid][pZigaretten] += anzahl;
        }
        case 4: {
            if (Spieler[playerid][pKanister] < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du hast nicht genug Tankkanister.");
            if (Spieler[giveid][pKanister] + anzahl > MAX_CANISTER) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Der Spieler kann maximal " #MAX_CANISTER " Kanister haben.");
            Spieler[playerid][pKanister] -= anzahl;
            Spieler[giveid][pKanister] += anzahl;
        }
        case 5: {
            if (Spieler[playerid][pFische] < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du hast nicht genug Fische.");
            Spieler[playerid][pFische] -= anzahl;
            Spieler[giveid][pFische] += anzahl;
        }
        case 6: {
            if (Spieler[playerid][pGangDrogenSamen] < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du hast nicht genug Drogensamen.");
            Spieler[playerid][pGangDrogenSamen] -= anzahl;
            Spieler[giveid][pGangDrogenSamen] += anzahl;
        }
        case 7: {
            if (Spieler[playerid][pPowerRiegel] < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du hast nicht genug Power Riegel.");
            if (Spieler[giveid][pPowerRiegel] + anzahl > 20) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Der Spieler kann keine Riegel mehr besitzen.");
            Spieler[playerid][pPowerRiegel] -= anzahl;
            Spieler[giveid][pPowerRiegel] += anzahl;
        }
        case 8: {
            if (Spieler[playerid][pBooster] < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du hast nicht genug Booster.");
            if (Spieler[giveid][pBooster] + anzahl > 4) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Der Spieler kann keine Booster mehr besitzen.");
            Spieler[playerid][pBooster] -= anzahl;
            Spieler[giveid][pBooster] += anzahl;
        }
        case 9: {
            if (Spieler[playerid][pSchaufel] < anzahl) return SendClientMessage(playerid, COLOR_LIGHTRED2, "Du hast nicht genug Schaufeln.");
            Spieler[playerid][pSchaufel] -= anzahl;
            Spieler[giveid][pSchaufel] += anzahl;
        }
    }

    format(String, sizeof(String), "* %s gab %s %s.", GetName(playerid), GetName(giveid), inventar);
    SendRoundMessage(x, y, z, COLOR_PURPLE, String);

    // ApplyAnimation(playerid,"BAR","Barserve_give",4.1,0,1,1,1,1);
    // ApplyAnimation(giveid,"BAR","Barserve_give",4.1,0,1,1,1,1);

    format(String, sizeof(String), "Du hast %s %d %s gegeben.", GetName(giveid), anzahl, inventar);
    SendClientMessage(playerid, COLOR_GREEN, String);

    format(String,sizeof(String), "Du hast von %s %d %s erhalten!", GetName(playerid), anzahl, inventar);
    SendClientMessage(giveid, COLOR_GREEN, String);

    format(String,sizeof(String), "%s hat %s %d %s gegeben", GetName(playerid), GetName(giveid), anzahl, inventar);
    GebeLog(String);
    return 1;
}
#if defined HALLOWEEN_EVENT
COMMAND:hexenhut(playerid,params[]){

    if( IsPlayerAttachedObjectSlotUsed(playerid,8) ) {
        RemovePlayerAttachedObject(playerid,8);
        SendClientMessage(playerid,COLOR_YELLOW,"Hexen-Hut abgenommen.");
    }
    else {
        SetPlayerAttachedObject(playerid, 8, 19528, 2, 0.114997, 0.006998, 0.001999, 90.000000, -23.199983, 4.999997, 0.615999, 1.008998, 1.222000, 0xFFFF0000, 0xFFFF0000); //hat bottom
        SendClientMessage(playerid,COLOR_GREEN,"Hexen-Hut aufgesetzt.");
    }
    return 1;
}

COMMAND:kurbiskopf(playerid,params[]){

    if( IsPlayerAttachedObjectSlotUsed(playerid,8) ) {
        RemovePlayerAttachedObject(playerid,8);
        SendClientMessage(playerid,COLOR_YELLOW,"Kürbiskopf abgenommen.");
    }
    else {
        SetPlayerAttachedObject(playerid, 8, 19320, 2, 0.162564, 0.009463, 0.003660, 243.790893, 93.450889, 346.318786, 0.699999, 0.699999, 0.699999); //Kürbiskopf
        SendClientMessage(playerid,COLOR_GREEN,"Kürbiskopf aufgesetzt.");
    }
    return 1;
}

COMMAND:messerkopf(playerid,params[]){
    if( IsPlayerAttachedObjectSlotUsed(playerid,8) ) {
        RemovePlayerAttachedObject(playerid,8);
        SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
    }
    else {
        SetPlayerAttachedObject( playerid, 8, 335, 2, 0.392242, -0.182094, 0.153530, 30.000000, 223.276199, 36.263126, 1.500000, 1.500000, 1.200000 ); // TheParrot1 - papagei
        SendClientMessage(playerid,COLOR_YELLOW,"Messer in Kopf gesteckt.");
    }
    return 1;
}
CMD:halloween(playerid,params[]) {
	if( Spieler[playerid][pLevel] < 3 ) {
	    return SendClientMessage(playerid, COLOR_RED, "Du musst Level 3 erreicht haben, um ein Geschenk öffnen zu können.");
	}
	for(new i ; i < sizeof(g_Geschenk); i++) {
	    if( g_Geschenk[i][G_bFound] == false ) {
	        if( IsPlayerInRangeOfPoint(playerid,3.0,g_Geschenk[i][G_fX],g_Geschenk[i][G_fY],g_Geschenk[i][G_fZ]) ) {
				new
				    String[128];
	            g_iGeschenk++;
	            format(String,sizeof(String),"[HALLOWEEN] %s hat ein Kürbis gefunden! Kürbisse: %d/%d",GetName(playerid),g_iGeschenk,sizeof(g_Geschenk));
	            SendClientMessageToAll(COLOR_YELLOW,String);
	            DestroyDynamic3DTextLabel( g_Geschenk[i][G_t3dLabel] );
	            DestroyDynamicObject( g_Geschenk[i][G_iObjectID] );
	            g_Geschenk[i][G_bFound] = true;
				GivePlayerCash(playerid,50000);
				Spieler[playerid][pLevel] += 1;
	            if( g_iGeschenk == sizeof(g_Geschenk) ) {
	                // Alle wurden gefunden
	                SendClientMessageToAll(COLOR_YELLOW,"Alle Kürbisse wurden gefunden! LyD wünscht euch gruselige Halloween!");
	            }
	            return 1;
	        }
	    }
	}
	SendClientMessage(playerid,COLOR_WHITE,"Kein Paket in deiner nähe!");
	return 1;
}
#endif

