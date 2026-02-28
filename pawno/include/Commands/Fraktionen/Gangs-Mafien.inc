#include <YSI\y_hooks>



CMD:gangwaffen(playerid)
{
    if(HasWeaponBlock(playerid)) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst diesen Befehl nicht ausführen");
        return SendWeaponBlockInfo(playerid);
    }
    for (new i; i < MAX_FACTIONS; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, g_fraktion[i][Fr_WaffenX],g_fraktion[i][Fr_WaffenY],g_fraktion[i][Fr_WaffenZ]))
        {
            if(IsAFightFaction(g_fraktion[i][Fr_FrakID]) || g_fraktion[i][Fr_FrakID] == 17)
            {
                if(CheckMoney(playerid) < 4000)return SendClientMessage(playerid, COLOR_RED, "Du benötigst $4000.");
                if(!(Spieler[playerid][pFraktion] == g_fraktion[i][Fr_FrakID]))return SCMFormatted(playerid, COLOR_RED, "Du bist kein %s Mitglied.",g_fraktion[i][Fr_FrakID]);
                GiveGangWeapons(playerid);
            }
        }
    }
    return 1;
}


CMD:fesseln(playerid, params[])
{
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 6 || Spieler[playerid][pFraktion] == 7 || Spieler[playerid][pFraktion] == 10 || Spieler[playerid][pFraktion] == 11 || Spieler[playerid][pFraktion] == 12 || Spieler[playerid][pFraktion] == 13
     || Spieler[playerid][pFraktion] == 17 || Spieler[playerid][pFraktion] == 19 || Spieler[playerid][pFraktion] == 20 || Spieler[playerid][pFraktion] == 21 || Spieler[playerid][pFraktion] == 15))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Gang/Mafia Mitglied.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Fesseln [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid,COLOR_RED,"Du musst der Fahrer eines Fahrzeuges sein!");
    if(IsPlayerInAnyVehicle(pID) && GetPlayerVehicleID(pID) != GetPlayerVehicleID(playerid))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem anderen Fahrzeug.");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(!IsPlayerInRangeOfPoint(pID, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    FreezePlayer(pID);
    Cuffed[pID] = 1;
    format(string, sizeof(string), "* %s hat %s gefesselt.", GetName(playerid), GetName(pID));
    foreach(new i : Player)
    {
        if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z))
        {
            SendClientMessage(i, COLOR_LIGHTRED2, string);
        }
    }
    return 1;
}


CMD:gheilen(playerid)
{
    for (new i; i < MAX_FACTIONS; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, g_fraktion[i][Fr_WaffenX],g_fraktion[i][Fr_WaffenY],g_fraktion[i][Fr_WaffenZ]))
        {
            if(IsAFightFaction(g_fraktion[i][Fr_FrakID]) || g_fraktion[i][Fr_FrakID] == 14 || g_fraktion[i][Fr_FrakID] == 15)
            {
                if(!(Spieler[playerid][pFraktion] == g_fraktion[i][Fr_FrakID]))return SCMFormatted(playerid, COLOR_RED, "Du bist kein %s Mitglied.",GetFactionName(g_fraktion[i][Fr_FrakID]));
                if(Spieler[playerid][pHeilReady] == 0)return SendClientMessage(playerid, COLOR_RED, "Du kannst dich noch nicht heilen.");
                Spieler[playerid][pHeilReady] = 0;
                SetPlayerHealth(playerid, 100);
                SetTimerEx("HeilReady", 60000, 0, "i", playerid);
            }
        }
    }
    return 1;
}



CMD:gebietinfo(playerid,params[]){
    new gebiet = GetPlayerGangZone(playerid);
	if(gebiet == -1) return SendClientMessage(playerid, COLOR_RED, "Du bist in keine Gangfight-Gebiet!");
	SendClientMessage(playerid,COLOR_YELLOW,"=====GEBIETINFO=====");
	if(g_GangZone[gebiet][GZ_igupgrade]==3){
  		SendClientMessage(playerid, COLOR_YELLOW, "Dieses Gangfight-Gebiet erwirtschaftet Geld!");
    }
   	if(g_GangZone[gebiet][GZ_igupgrade]==1){
      	SendClientMessage(playerid, COLOR_YELLOW, "Dieses Gangfight-Gebiet erwirtschaftet Waffenteile!");
    }
    if(g_GangZone[gebiet][GZ_igupgrade]==2){
		SendClientMessage(playerid, COLOR_YELLOW, "Das Gangfight-Gebiet erwirtschaftet Drogen!");
	}
	if (gettime() < g_GangZone[gebiet][GZ_iTimeout]) {
   		new diff = g_GangZone[gebiet][GZ_iTimeout] - gettime();
     	new h = diff / 3600 % 24;
    	new m = diff / 60 % 60;
		SCMFormatted(playerid, COLOR_RED, "Dieses Ganggebiet hat noch %i Stunden %i Minuten lang eine Zeitsperre.", h, m);
	}else{
  		SendClientMessage(playerid, COLOR_GREEN, "Dieses Ganggebiet hat keine gültige Zeitsperre und ist angreifbar.");
	}
	SendClientMessage(playerid,COLOR_YELLOW,"====================");
	return 1;
}


CMD:gfinfo(playerid) return cmd_gangfightinfo(playerid);
CMD:gangfightinfo(playerid)
{
    new string[400], bool:gangfightRunning = false;
    for(new i;i<MAX_GANGZONES;i++)
    {
        if(g_GangZone[i][GZ_iAttacker]!=0)
        {
            new wartime;
            wartime=gettime()-g_GangZone[i][GZ_iGangWarEnd];
            format(string,400,"%s (%i Punkte) vs. %s (%i Punkte), Gangfightende: in %02i:%02i Minuten.",
            GetFactionNameOfFaction(g_GangZone[i][GZ_iAttacker]),g_GangZone[i][GZ_iAttackerScore],
            GetFactionNameOfFaction(g_GangZone[i][GZ_iOwner]),g_GangZone[i][GZ_iOwnerScore], floatround(-wartime / 60, floatround_floor), floatround(-wartime % 60, floatround_floor));
            SendClientMessage(playerid,COLOR_YELLOW,string);
            gangfightRunning = true;
        }
    }
    if (!gangfightRunning) SendClientMessage(playerid, COLOR_YELLOW, "Zur Zeit läuft kein Gangfight.");
    return 1;
}


CMD:waffenlagerstatus(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    new index = GetWaffenLagerIndex(Spieler[playerid][pFraktion]);
    if (index == -1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Deine Fraktion hat kein Waffenlager.");
    if (Spieler[playerid][pRank] < 5) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst Leader/Co-Leader sein um auf diesen Befehl zugreifen zu können.");
    if (isnull(params)) {
        SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Das Waffenlager ist %s.", g_fraktion[index][Fr_WaffenlagerStatus] ? "geschlossen" : "geöffnet");
        return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Waffenlagerstatus [AUF/ZU]");
    }

    new status[5];
    if (sscanf(params, "s[5]", status)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Waffenlagerstatus [AUF/ZU]");
    if (!strcmp(status, "auf", true)) {
        if (!g_fraktion[index][Fr_WaffenlagerStatus]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Das Waffenlager ist bereits geöffnet.");
        g_fraktion[index][Fr_WaffenlagerStatus] = false;
        return SendClientMessage(playerid, COLOR_GREEN, "[INFO] {FFFFFF}Du hast das Waffenlager geöffnet.");
    }
    else if (!strcmp(status, "zu", true)) {
        if (g_fraktion[index][Fr_WaffenlagerStatus]) return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Das Waffenlager ist bereits geschlossen.");
        g_fraktion[index][Fr_WaffenlagerStatus] = true;
        return SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Du hast das Waffenlager geschlossen.");
    }
    
    return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Waffenlagerstatus [AUF/ZU]");
}



CMD:kidnap(playerid, params[])
{
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 6 || Spieler[playerid][pFraktion] == 7 || Spieler[playerid][pFraktion] == 10 || Spieler[playerid][pFraktion] == 11 || Spieler[playerid][pFraktion] == 12 || Spieler[playerid][pFraktion] == 13
     || Spieler[playerid][pFraktion] == 15 || Spieler[playerid][pFraktion] == 17 || Spieler[playerid][pFraktion] == 19 || Spieler[playerid][pFraktion] == 20 || Spieler[playerid][pFraktion] == 21))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Gang/Mafia Mitglied.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Kidnap [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[pID][pAdminDienst] ) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist gerade im Admindienst.");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht selbst entführen!");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(!IsPlayerInRangeOfPoint(pID, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    if(!IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug.");
    new maxSeats = GetVehicleMaxPassengers(GetVehicleModel(GetPlayerVehicleID(playerid)));
    if (!maxSeats || maxSeats == 0xF) return SendClientMessage(playerid, COLOR_RED, "Dieses Fahrzeug hat keinen Beifahrersitz.");
    if(IsPlayerInAnyVehicle(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem anderen Fahrzeug.");
    if( Spieler[pID][pLevel] < 3 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Neuling entführen!");
    }

    // Buguse
    if (Spieler[pID][pJailed] == 2)
        return GiveCheckpointPrison(playerid, 120, "Bugusing, Gruß das Entwickler-Team (Gangjail).");

    if( Spieler[playerid][tKidnap] != INVALID_TIMER_ID ) {
        return SendClientMessage(playerid, COLOR_RED, "Du versuchst gerade noch einen Spieler zu entführen.");
    }
    if( Spieler[pID][bKidnapped] ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler wird bereits entführt.");
    }
    Spieler[playerid][tickKidnap] = gettime() + 7;
    Spieler[playerid][tKidnap] = SetTimerEx("Pulse_Kidnap",1627,true,"dd",playerid,pID );
    format(string,sizeof(string),"%s versucht %s ins Fahrzeug zu zerren.",GetName(playerid),GetName(pID));
    SendRoundMessage(x,y,z, COLOR_LIGHTRED2, string);

    Spieler[playerid][iKidnapID] = pID;
    return 1;
}


CMD:entfesseln(playerid, params[])
{
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 6 || Spieler[playerid][pFraktion] == 7 || Spieler[playerid][pFraktion] == 10 || Spieler[playerid][pFraktion] == 11 || Spieler[playerid][pFraktion] == 12 || Spieler[playerid][pFraktion] == 13
     || Spieler[playerid][pFraktion] == 17 || Spieler[playerid][pFraktion] == 15 || Spieler[playerid][pFraktion] == 19 || Spieler[playerid][pFraktion] == 20 || Spieler[playerid][pFraktion] == 21))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Gang/Mafia Mitglied.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Entfesseln [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    if( playerid == pID ) return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht selber befreien.");
    if( Spieler[playerid][bKidnapped] ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht ausführen,da du gekidnappt wirst");
    if(Cuffed[pID] == 0) return SCMFormatted(playerid,COLOR_RED,"%s ist nicht gefesselt.",GetName(pID));

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(!IsPlayerInRangeOfPoint(pID, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    UnfreezePlayer(pID);
    Cuffed[pID] = 0;
    Spieler[playerid][iKidnapID] = INVALID_PLAYER_ID;
    format(string, sizeof(string), "* %s hat %s entfesselt!", GetName(playerid), GetName(pID));
    foreach(new i : Player)
    {
        if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z))
        {
            SendClientMessage(i, COLOR_LIGHTRED2, string);
        }
    }
    return 1;
}


CMD:gangitem(playerid,params[]) 
{
    for (new i; i < MAX_FACTIONS; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, g_fraktion[i][Fr_GangitemX],g_fraktion[i][Fr_GangitemY],g_fraktion[i][Fr_GangitemZ]))
        {
            if( IsPlayerAttachedObjectSlotUsed(playerid,ATTACHED_INDEX_GANG_SHOP) ) {
                // Nur Entfernen
               ShowPlayerDialog(playerid,DIALOG_GANGSHOP_DEL,DIALOG_STYLE_MSGBOX,"Gang-Skin","Willst du das Gang-Item entfernen?","Entfernen","Abbruch");
            }
            else 
            {
                new String[128];
                for(new e ; e < sizeof(g_GangShopItems) ; e++) 
                {
                    format(String,sizeof(String),"%s%s - $%d\n",String,g_GangShopItems[e][GSI_sName],g_GangShopItems[e][GSI_iPrice]);
                }
                ShowPlayerDialog(playerid,DIALOG_GANGSHOP,DIALOG_STYLE_LIST,"Gang-Skin",String,"Ausrüsten","Abbruch");
            }
        }
    }
    return 1;
}



CMD:fsafebox(playerid,params[]) {

    new frak_index = Spieler[playerid][pFraktion];

    if (frak_index == -1) return SendClientMessage(playerid, COLOR_RED, "Deine Fraktion besitzt keine Safebox.");
    if (!IsPlayerInRangeOfPoint(playerid, 5.0, g_fraktion[frak_index][Fr_FSafeboxX], g_fraktion[frak_index][Fr_FSafeboxY], g_fraktion[frak_index][Fr_FSafeboxZ]))
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht bei der Safebox deiner Fraktion.");

    if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du darfst dafür nicht im Fahrzeug sein.");
    if (isnull(params)) return ShowFSafeboxDialog(playerid, DIALOG_FSAFEBOX_MENU);

    new menge, item, sItem[32], aktion, sAktion[32];
    if (sscanf(params, "s[32]s[32]d", sItem, sAktion, menge) || menge < 0) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /FSafebox [Drogen/Waffenteile/Wantedcodes/Spice/Krauter] [rausnehmen/reinlegen] [Anzahl]");
        return SendClientMessage(playerid, COLOR_BLUE, "* Du kannst auch nur /FSafebox für das FSafebox-Menü benutzen.");
    }

    if (!strcmp(sItem, "drogen", true)) item = 1;
    else if (!strcmp(sItem, "waffenteile", true)) item = 2;
    else if (!strcmp(sItem, "wantedcodes", true)) item = 3;
    else if (!strcmp(sItem, "spice", true)) item = 4;
    else if (!strcmp(sItem, "krauter", true)) item = 5;

    if (!item) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /FSafebox [Drogen/Waffenteile/Wantedcodes/Spice/Krauter] [rausnehmen/reinlegen] [Anzahl]");
        return SendClientMessage(playerid, COLOR_BLUE, "* Du kannst auch nur /FSafebox für das FSafebox-Menü benutzen.");
    }

    if (!strcmp(sAktion, "rausnehmen", true)) aktion = 1;
    else if (!strcmp(sAktion, "reinlegen", true)) aktion = 2;

    if (!aktion) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /FSafebox [Drogen/Waffenteile/Wantedcodes/Spice/Krauter] [rausnehmen/reinlegen] [Anzahl]");
        return SendClientMessage(playerid, COLOR_BLUE, "* Du kannst auch nur /FSafebox für das FSafebox-Menü benutzen.");
    }

    FSafeboxInteraction(playerid, aktion - 1, item - 1, menge, false);
    return 1;
}

CMD:ggd(playerid, params[]) return cmd_givegangdrugs(playerid, params);
CMD:givegangdrugs(playerid, params[])
{
	new methode, giveid, inventar[24], anzahl, String[128];
	if(sscanf(params,"us[24]d",giveid,inventar,anzahl)) {
		SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Givegangdrugs [Spielername/ID] [Inventar] [Anzahl]");
		return SendClientMessage(playerid,COLOR_ORANGE,"Inventar = Drogen, Spice");
	}
	new frak = Spieler[playerid][pFraktion];
    if( !IsAFightFaction(frak) && frak != 15) {
		return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist kein Gangs/Mafien-Mitglied.");
    }
	if( !IsPlayerConnected(giveid)) {
		return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Der Spieler ist nicht Online.");
	}
	if( anzahl <= 0 ) {
		return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Die Anzahl ist ungültig.");
	}
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid,x,y,z);
	if( !IsPlayerInRangeOfPoint(giveid,5.0,x,y,z)) {
		return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Der Spieler ist nicht in deiner Nähe.");
	}
	if (Spieler[giveid][pAdminDienst]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist gerade im Admindienst.");
	if(!strcmp(inventar,"Drogen") || !strcmp(inventar,"Drugs")) {
	    methode = 1;
	}
	else if(!strcmp(inventar,"Spice")) {
	    methode = 2;
	}
	if( methode == 0 ) {
		SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Givegangdrugs [Spielername/ID] [Inventar] [Anzahl]");
		return SendClientMessage(playerid,COLOR_ORANGE,"Inventar = Drogen, Spice");
	}
	else if( methode == 1 ) {
	    //Drogen
	    if( Spieler[playerid][pDrugs] < anzahl ) {
			return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Du hast nicht genug Drogen.");
	    }
	    Spieler[playerid][pDrugs] -= anzahl;
	    Spieler[giveid][pDrugs] += anzahl;
	}
	else if( methode == 2 ) {
	    //Spice
	    if( Spieler[playerid][pSpice] < anzahl ) {
	        return SendClientMessage(playerid, COLOR_RED,"[INFO] {FFFFFF}Du hast nicht genug Spice.");
		}
        //if(CheckPlayerSpice(giveid,anzahl)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler kann maximal 3.000 Gramm Spice besitzen!");
		Spieler[playerid][pSpice] -= anzahl;
		Spieler[giveid][pSpice] += anzahl;
	}
	format(String,sizeof(String),"%s gibt %s %s",GetName(playerid),GetName(giveid),inventar);
	SendRoundMessage(x,y,z, COLOR_LIGHTGREY, String);
	//ApplyAnimation(playerid,"BAR","Barserve_give",4.1,0,1,1,1,1);
	//ApplyAnimation(giveid,"BAR","Barserve_give",4.1,0,1,1,1,1);
	format(String,sizeof(String),"Du hast %s %d %s geben",GetName(giveid),anzahl,inventar);
	SendClientMessage(playerid,COLOR_GREEN,String);
	format(String,sizeof(String),"Du hast von %s %d %s erhalten!",GetName(playerid),anzahl,inventar);
	SendClientMessage(giveid,COLOR_GREEN,String);
	format(String,sizeof(String),"%s hat %s %d %s gegeben",GetName(playerid),GetName(giveid),anzahl,inventar);
	GebeLog(String);
	return 1;
}


CMD:frakblacklist(playerid,params[]) {
    if(Spieler[playerid][pFraktion] != 6 && Spieler[playerid][pFraktion] != 7 && Spieler[playerid][pFraktion] != 10 && Spieler[playerid][pFraktion] != 11 && Spieler[playerid][pFraktion] != 12 && Spieler[playerid][pFraktion] != 13 && Spieler[playerid][pFraktion] != 14 && Spieler[playerid][pFraktion] != 20 && Spieler[playerid][pFraktion] != 21 ) {
        return SendClientMessage(playerid, COLOR_RED, "Deine Fraktion bietet diese Funktion nicht an");
    }
    new
        query[128];
    format(query,sizeof(query),"SELECT `name` FROM `frakblacklist` WHERE `fraktion` = %d",Spieler[playerid][pFraktion]);
    mysql_pquery(query,THREAD_FRAKBLACKLIST,playerid,gSQL,MySQLThreadOwner);
    return 1;
}


CMD:addfrakblacklist(playerid,params[]) {
    if(Spieler[playerid][pFraktion] != 6 && Spieler[playerid][pFraktion] != 7 && Spieler[playerid][pFraktion] != 10 && Spieler[playerid][pFraktion] != 11 && Spieler[playerid][pFraktion] != 12 && Spieler[playerid][pFraktion] != 13 && Spieler[playerid][pFraktion] != 14 && Spieler[playerid][pFraktion] != 20 && Spieler[playerid][pFraktion] != 21 ) {
        return SendClientMessage(playerid, COLOR_RED, "Deine Fraktion bietet diese Funktion nicht an");
    }
    if(Spieler[playerid][pRank] < 4 ) {
        return SendClientMessage(playerid, COLOR_RED, "Dein Fraktionsrang ist zu niedrig für diese Funktion");
    }
    new
        name[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",name)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Addfrakblacklist [ID/Name]");
    }
    new
        querys[128];
    PlayerSQLExtra(playerid,name);
    format(querys,sizeof(querys),"SELECT `name` FROM `frakblacklist` WHERE `fraktion` = %d",Spieler[playerid][pFraktion]);
    mysql_pquery(querys,THREAD_ADDFRAKBLACKLIST_COUNT,playerid,gSQL,MySQLThreadOwner);
    // -> THREADED
    return 1;
}


CMD:delfrakblacklist(playerid,params[]) {
    if(Spieler[playerid][pFraktion] != 6 && Spieler[playerid][pFraktion] != 7 && Spieler[playerid][pFraktion] != 10 && Spieler[playerid][pFraktion] != 11 && Spieler[playerid][pFraktion] != 12 && Spieler[playerid][pFraktion] != 13 && Spieler[playerid][pFraktion] != 14 && Spieler[playerid][pFraktion] != 20 && Spieler[playerid][pFraktion] != 21 ) {
        return SendClientMessage(playerid, COLOR_RED, "Deine Fraktion bietet diese Funktion nicht an");
    }
    if(Spieler[playerid][pRank] < 4 ) {
        return SendClientMessage(playerid, COLOR_RED, "Dein Fraktionsrang ist zu niedrig für diese Funktion");
    }
    new
        name[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",name)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Delfrakblacklist [ID/Name]");
    }
    new
        query[128];
    PlayerSQLExtra(playerid,name);
    format(query,sizeof(query),"SELECT * FROM `frakblacklist` WHERE `fraktion` = %d AND `name` = '%s'",Spieler[playerid][pFraktion],name);
    mysql_pquery(query,THREAD_DELFRAKBLACKLIST_COUNT,playerid,gSQL,MySQLThreadOwner);
    // -> THREADED
    return 1;
}



CMD:gf(playerid, params[]) return cmd_gangfight(playerid, params);

CMD:gangfight(playerid, params[]) {
    new frak = Spieler[playerid][pFraktion];
    new gzcount = GetGangZoneCount(Spieler[playerid][pFraktion]);
    if (!IsAGFFaction(frak)) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang Fraktion.");
    if (g_aSettings[ASETTING_GANGFIGHTBLOCK][ASETTING_TOGGLE]) return SendClientMessage(playerid, COLOR_RED, "Zurzeit ist die Gangfightsperre aktiviert.");
    if (Spieler[playerid][pRank] < 4) return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens Rang 4 in deiner Gang sein.");
    if (Spieler[playerid][pTot] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst nicht angreifen wenn du tot bist.");
    new index = GetPlayerGangZone(playerid);
    if (index == -1) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Ganggebiet.");
    if (frak == g_GangZone[index][GZ_iOwner]) return SendClientMessage(playerid, COLOR_RED, "Dieses Ganggebiet gehört bereits deiner Gang.");
    if (IsGangInFight(frak)) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich zur Zeit in einem Gangfight.");
    if (HasBizfight(frak)) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich zur Zeit in einem Bizfight.");
    if (HasBizfight(g_GangZone[index][GZ_iOwner])) return SendClientMessage(playerid, COLOR_RED, "Die Gang ist bereits in einem Bizfight involviert.");
    if (IsGangInFight(g_GangZone[index][GZ_iOwner])) return SendClientMessage(playerid, COLOR_RED, "Die Gang ist bereits in einem Gangfight involviert.");
    if (!IsPlayerInRangeOfPoint(playerid, 6.0, g_GangZone[index][GZ_fIconX], g_GangZone[index][GZ_fIconY], g_GangZone[index][GZ_fIconZ])) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Icons.");
    if (gzcount > MAX_GANGZONES *0.75 ) return SendClientMessage(playerid, COLOR_RED,"Ihr könnt keine Gebiete mehr erobern.");
    new hour, minute, second, time = gettime(hour, minute, second);

    if (time < g_GangZone[index][GZ_iTimeout]) {
        new diff = g_GangZone[index][GZ_iTimeout] - time;
        new h = diff / 3600 % 24;
        new m = diff / 60 % 60;

        return SCMFormatted(playerid, COLOR_RED, "Dieses Ganggebiet hat noch %i Stunden %i Minuten lang eine Zeitsperre.", h, m);
    }

    new day = GetWeekDayNumber(),
        minimumPlayers = (day == WEEKDAY_MONDAY && hour >= 19 && hour < 21) ||
                         (day == WEEKDAY_WEDNESDAY && hour >= 19 && hour < 21) ||
                         (day == WEEKDAY_FRIDAY && hour >= 19 && hour < 21) ||
                         (day == WEEKDAY_SATURDAY && hour >= 19 && hour < 21) ||
                         (day == WEEKDAY_SUNDAY && hour >= 18 && hour < 21) ? 0 : GANG_FIGHT_PLAYERS;

    if (GetFactionOnlinePlayers(frak) < minimumPlayers) return SCMFormatted(playerid, COLOR_RED, "Es müssen mindestens %d Gangmitglieder deiner Fraktion online sein.", minimumPlayers);

    new onlineCount, pPoolSize = GetPlayerPoolSize();
    for (new z ; z <= pPoolSize; z++) {
        if (!IsPlayerConnected(z)) continue;
        if (Spieler[z][pFraktion] == g_GangZone[index][GZ_iOwner] && time - Spieler[z][pLoginTimestamp] > 30 && Spieler[z][pAdminDienst] == 0) onlineCount++;
    }

    if (onlineCount < minimumPlayers) return SCMFormatted(playerid, COLOR_RED, "Von der Besitzerfraktion sind nicht genug Spieler (%d) online bzw. lange genug eingeloggt.", minimumPlayers);
    if (gangfightpause[frak] >= time) return SendClientMessage(playerid,COLOR_RED,"Ihr habt eine 10 minütige Gangfightpause, da ihr vor kurzem einen Gangfight hattet.");
    if (gangfightpause[g_GangZone[index][GZ_iOwner]] >= time) return SCMFormatted(playerid, COLOR_RED, "Die %s kann nicht angegriffen werden, da sie vor 10 Minuten zuletzt einen Gangfight hatten.",\
    GetFactionNameOfFaction(g_GangZone[index][GZ_iOwner]));

    // Start GF
    new String[128];
    format(String, sizeof(String), "Gangfight gegen %s wird gestartet! Der Kampf dauert " #GANGFIGHT_DURATION " Minuten.", GetFactionNameOfFaction(g_GangZone[index][GZ_iOwner]));
    SendFraktionMessage(frak, COLOR_RED, String);
    format(String, sizeof(String), "%s startet einen Gangfight. Der Kampf dauert " #GANGFIGHT_DURATION " Minuten.", GetFactionNameOfFaction(frak));
    SendFraktionMessage(g_GangZone[index][GZ_iOwner], COLOR_RED, String);
    format(String, sizeof(String), "[GANGFIGHT-MELDUNG] {FFFFFF}Die %s startet ein Gangfight gegen die %s! Der Kampf dauert " #GANGFIGHT_DURATION " Minuten.", GetFactionNameOfFaction(frak), GetFactionNameOfFaction(g_GangZone[index][GZ_iOwner]));
    SendClientMessageToAll(COLOR_YELLOW, String);
    SendClientMessageToAll(COLOR_YELLOW, "Mit /Gangfightwette kannst du für den Sieg einer Gangfraktion wetten!");
    
    for (new i; i < 4; i++) {
        if (!gangfightwetten[i]) {
            gangfightwetten[i] = time;
            gangfightkampffraks[i][0] = g_GangZone[index][GZ_iOwner];
            gangfightkampffraks[i][1] = frak;
            break;
        }
    }

    g_GangZone[index][GZ_iStatus] = 1;
    g_GangZone[index][GZ_iAttacker] = frak;
    g_GangZone[index][GZ_iAttackerScore] = 0;
    g_GangZone[index][GZ_iOwnerScore] = 0;
    g_GangZone[index][GZ_iGangWarEnd] = time + GANGFIGHT_DURATION * 60;
    g_GangZone[index][GZ_iFlagge] = -1;
    g_GangZone[index][GZ_iFlaggePlayer] = INVALID_PLAYER_ID;
    g_GangZone[index][GZ_iCounter] = 0;
    AStopTimer = SetTimerEx("GFCheck",1000,true,"ddd",index,frak,g_GangZone[index][GZ_iOwner]);
    

    UpdateGangFightInfo(index);

    for (new z ; z <= pPoolSize; z++) {
        if (!IsPlayerConnected(z)) continue;
        if (Spieler[z][pFraktion] == frak || Spieler[z][pFraktion] == g_GangZone[index][GZ_iOwner]) {
            TextDrawShowForPlayer(z, tdGangZoneHeader);
            TextDrawShowForPlayer(z, g_GangZone[index][GZ_tdInfo]);
            Spieler[z][pKillsGangFightSession] = 0;
        }
    }

    return 1;
}

CMD:gfstop(playerid, params[]) return cmd_gangfightstop(playerid, params);

CMD:gangfightstop(playerid,params[]) {
    new frak = Spieler[playerid][pFraktion];
    if( !IsAFightFaction(frak) )return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang-Fraktion.");
    if( Spieler[playerid][pRank] < 4 ) return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens Rang 4 sein in deiner Gang.");
    if( !IsGangInFight(frak) ) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich in keinem Gangfight.");
    new index = GetGangFight( Spieler[playerid][pFraktion] );
    if( index == -1 ) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich in keinem Gangfight.");
    #if defined NEUE_WIRTSCHAFT
        new betrag = 25000,winner,loser,String[200];
    #else
        new betrag = 50000,winner,loser,String[200];
    #endif
    if( Spieler[playerid][pFraktion] == g_GangZone[index][GZ_iAttacker] ) {
        winner = g_GangZone[index][GZ_iOwner];
        loser = g_GangZone[index][GZ_iAttacker];
    } else  {
        loser = g_GangZone[index][GZ_iOwner];
        winner = g_GangZone[index][GZ_iAttacker];
    }
    g_GangZone[index][GZ_iStatus] = 0;
    g_GangZone[index][GZ_iGangWarEnd] = 0;
    g_GangZone[index][GZ_iOwner] = winner;
    g_GangZone[index][GZ_iAttacker] = 0;
    g_GangZone[index][GZ_iTimeout] = gettime() + 2*60*60;
    g_GangZone[index][GZ_iCounter] = 0;
    g_GangZone[index][GZ_iFlaggePlayer] = INVALID_PLAYER_ID;
    g_GangZone[index][GZ_iFlagge] = -1;
    g_GangZone[index][GZ_iFlaggeEnd] = 0;
    KillTimer(AStopTimer);

    if(winner == 6)Kasse[Grove] += betrag;
    else if(winner == 7) Kasse[Ballas] += betrag;
    else if(winner == 10) Kasse[Yakuza] += betrag;
    else if(winner == 11) Kasse[Aztecas] += betrag;
    else if(winner == 12) Kasse[LCN] += betrag;
    else if(winner == 13) Kasse[Vagos] += betrag;
    else if(winner == 14) Kasse[Hitman] += betrag;
    else if(winner == 20) Kasse[OutlawzK] += betrag;
    else if(winner == 21) Kasse[ndgradethaK] += betrag;

    if(loser == 6)Kasse[Grove] -= betrag;
    else if(loser == 7) Kasse[Ballas] -= betrag;
    else if(loser == 10) Kasse[Yakuza] -= betrag;
    else if(loser == 11) Kasse[Aztecas] -= betrag;
    else if(loser == 12) Kasse[LCN] -= betrag;
    else if(loser == 13) Kasse[Vagos] -= betrag;
    else if(loser == 14) Kasse[Hitman] -= betrag;
    else if(loser == 20) Kasse[OutlawzK] -= betrag;
    else if(loser == 21) Kasse[ndgradethaK] -= betrag;
    gangfightpause[loser]=gettime()+600;
    gangfightpause[winner]=gettime()+600;
    #if !defined NEUE_WIRTSCHAFT
        g_fraktion[winner][Fr_FSWaffenteile]+=25000;
    #endif
    new arrayid,teamid[2];
    for(new z;z<2;z++) {
        if(gangfightkampffraks[0][z]==winner) {
            arrayid=0;
            teamid[0]=z;
        }
        else if(gangfightkampffraks[1][z]==winner) {
            arrayid=1;
            teamid[0]=z;
        }
        else if(gangfightkampffraks[2][z]==winner) {
            arrayid=2;
            teamid[0]=z;
        }
        else if(gangfightkampffraks[3][z]==winner) {
            arrayid=3;
            teamid[0]=z;
        }
    }
    if(teamid[0]==1) {
        teamid[1]=0;
    } else {
        teamid[1]=1;
    }
    new winpot,losepot,i;
    foreach( i : Player) {
        if(gangfightwettenppp[i]==winner) {
            winpot+=gangfightwettenpp[i];
        }
    }
    losepot=gangfightwettenpot[arrayid]-winpot;
    new gwstring[400];
    format(gwstring,400,
    "Die Wetten für den Gangfight zwischen %s und %s betragen insgesamt $%s\nEs wurden $%s für die %s gewettet und $%s für die %s.",
    GetFactionNameOfFaction(winner),GetFactionNameOfFaction(loser),AddDelimiters(gangfightwettenpot[arrayid]),AddDelimiters(winpot),GetFactionNameOfFaction(winner),AddDelimiters(losepot),GetFactionNameOfFaction(loser));
    SendClientMessageToAll(COLOR_YELLOW,gwstring);
    foreach( i : Player) {
        if(gangfightwettenppp[i]==winner) {
            gangfightwettenpot[arrayid]-=gangfightwettenpp[i];
        }
    }
    foreach( i : Player) {
        if(gangfightwettenppp[i]==winner) {
            if(IsPlayerConnected(i)) {
                Spieler[i][pBank] += gangfightwettenpp[i] * 2;
                new gewinnstr[200];
                format(gewinnstr,200,"Du hast die Gangfight-Wette gewonnen und deinen Gewinn in Höhe von $%s auf die Bank überwiesen bekommen!", AddDelimiters(gangfightwettenpp[i] * 2));
                SendClientMessage(i,COLOR_GREEN,gewinnstr);
            } else {
                bankchange[i]=-128391;
                new query[256];
                format(query,sizeof(query),"SELECT `Bank` FROM `accounts` WHERE `Name` = '%s'",gangfightwettenp[i]);
                mysql_pquery(query , THREAD_BANKCHANGE , i, gSQL,MySQLThreadOwner);
                if(bankchange[i]!=-128391) {
                    format(query,sizeof(query),"UPDATE `accounts` SET `Bank` = '%i' WHERE `Name` = '%s'",gangfightwettenpp[i]+bankchange[i],gangfightwettenp[i]);
                    mysql_tquery(gSQL,query);
                }
            }
            gangfightwettenppp[i]=0,gangfightwettenpp[i]=0;
        } else if(gangfightwettenppp[i]==loser) {
            gangfightwettenppp[i]=0,gangfightwettenpp[i]=0;
        }
    }
    gangfightwetten[arrayid]=0,gangfightwettenpot[arrayid]=0,gangfightkampffraks[arrayid][0]=0,gangfightkampffraks[arrayid][1]=0;
    foreach(new b : Player) {
        format(gangfightwettenp[b],32,"");
    }

    format(String,sizeof(String),"->GANGFIGHT<- {FFFFFF} Die %s haben den Gangfight aufgegeben. Die %s haben gewonnen!",GetFactionNameOfFaction(loser),GetFactionNameOfFaction(winner));
    SendFraktionMessage( winner , COLOR_YELLOW, String );
    SendFraktionMessage( loser , COLOR_YELLOW, String );
    #if defined NEUE_WIRTSCHAFT
        format(String,sizeof(String),"->GANGFIGHT<- {00FF00}$25.000 und das Gebiet geht an die %s. ",GetFactionNameOfFaction(winner));
    #else
        format(String,sizeof(String),"->GANGFIGHT<- {00FF00}$50.000 + 25.000 Waffenteile und das Gebiet geht an die %s. ",GetFactionNameOfFaction(winner));
    #endif
    SendFraktionMessage( winner , COLOR_YELLOW, String );
    SendFraktionMessage( loser , COLOR_YELLOW, String );
    format(String,sizeof(String),"[GANGFIGHT-MELDUNG] {FFFFFF}Die %s haben den Gangfight aufgegeben. Die %s haben somit gewonnen!",GetFactionNameOfFaction(loser),GetFactionNameOfFaction(winner));
    SendClientMessageToAll(COLOR_YELLOW, String);
    GangZoneStopFlashForAll( g_GangZone[index][GZ_iGangZoneID] );
	new team1_killer = GZ_GetBestKiller(winner);
    new team2_killer = GZ_GetBestKiller(loser);
    if( IsPlayerConnected(team1_killer)) {
    	format(String,sizeof(String),"->GANGFIGHT<- %s aus der %s hat mit %d die meisten Kills gemacht.",GetName(team1_killer),GetFactionNameOfFaction(winner),Spieler[team1_killer][pKillsGangFightSession] );
    	SendClientMessageToAll(COLOR_YELLOW, String);
    }
	if( IsPlayerConnected(team2_killer)) {
		format(String,sizeof(String),"->GANGFIGHT<- %s aus der %s hat mit %d die meisten Kills gemacht.",GetName(team2_killer),GetFactionNameOfFaction(loser),Spieler[team2_killer][pKillsGangFightSession] );
		SendClientMessageToAll(COLOR_YELLOW, String);
	}

    foreach( i : Player)
        if(IsPlayerConnected(i))
            if(Spieler[i][pFraktion] == winner || Spieler[i][pFraktion] == loser)
                TextDrawHideForPlayer(i, tdGangZoneHeader);

    TextDrawHideForAll(g_GangZone[index][GZ_tdInfo]);
    return 1;
}


CMD:flaggeerobern(playerid,params[]) return cmd_fge(playerid,params);
CMD:fge(playerid,params[]) {
    new frak = Spieler[playerid][pFraktion];
    if( !IsAFightFaction(frak) ) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang/Mafia.");
    if( !IsGangInFight(frak) ) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich in keinem Gangfight.");
    new fightzone;
    fightzone = GetPlayerGangZone(playerid);
    if( fightzone == -1 ) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Gangfightgebiet.");
    if( Spieler[playerid][pTot] != 0 ) return SendClientMessage(playerid, COLOR_RED, "Du bist tot.");
    new String[128], index;
    index = GetGangFight(frak);
    if( index == -1 ) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich in keinem Gangfight.");
    if( fightzone != index ) return SendClientMessage(playerid, COLOR_RED, "Der Gangwar findet in einem anderem Gebiet statt.");
    if( frak == g_GangZone[index][GZ_iOwner] && g_GangZone[index][GZ_iFlagge] == 0 ||
        frak == g_GangZone[index][GZ_iAttacker] && g_GangZone[index][GZ_iFlagge] == 1 ) return SendClientMessage(playerid, COLOR_RED, "Deine Gang hält bereits die Flagge.");
    if( IsPlayerConnected(g_GangZone[index][GZ_iFlaggePlayer]) ) {
        format(String,sizeof(String),"Die Flagge wird bereits erobert von %s",GetName(g_GangZone[index][GZ_iFlaggePlayer]));
        return SendClientMessage(playerid, COLOR_RED, String );
    }
    if (!IsPlayerInRangeOfPoint(playerid, 4.0 , g_GangZone[index][GZ_fIconX],g_GangZone[index][GZ_fIconY],g_GangZone[index][GZ_fIconZ]))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht an der Flagge!");
    format(String,sizeof(String)," ->GANGFIGHT<- {FFFFFF}%s der Gang/Mafia %s versucht die Flagge zu erobern.",GetName(playerid),GetFactionNameOfFaction(frak));
    SendFraktionMessage( g_GangZone[index][GZ_iOwner] , COLOR_YELLOW, String );
    SendFraktionMessage( g_GangZone[index][GZ_iAttacker] , COLOR_YELLOW, String );
    SendClientMessage(playerid,COLOR_ORANGE,"Du musst 60 Sekunden an der Flagge aushalten.");
    g_GangZone[index][GZ_iFlaggePlayer] = playerid;
    g_GangZone[index][GZ_iFlaggeEnd] = gettime() + 60;
    return 1;
}



CMD:zeitsperre(playerid, params[]) {
    new fightzone = GetPlayerGangZone(playerid);
    if (fightzone == -1) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Gangfightgebiet.");
    if (gettime() < g_GangZone[fightzone][GZ_iTimeout]) {
        new diff = g_GangZone[fightzone][GZ_iTimeout] - gettime();
        new h = diff / 3600 % 24;
        new m = diff / 60 % 60;
        return SCMFormatted(playerid, COLOR_RED, "Dieses Ganggebiet hat noch %i Stunden %i Minuten lang eine Zeitsperre.", h, m);
    }
    return SendClientMessage(playerid, COLOR_GREEN, "Dieses Ganggebiet hat keine gültige Zeitsperre und ist angreifbar.");
}


CMD:buendnisanfrage(playerid,params[]) {
    new frak = GetPlayerFaction(playerid);
    if( !IsAFightFaction( frak ) ) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang bzw. Mafia.");
    new partner;
    if(sscanf(params,"d",partner)) return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Buendnisanfrage [/gangids]");
    if( frak == partner ) return SendClientMessage(playerid, COLOR_RED, "Das geht nicht");
    if( !IsAFightFaction( partner ) ) return SendClientMessage(playerid, COLOR_RED, "Die Angegebene Fraktion ist keine Gang bzw. Mafia.");
    if( Spieler[playerid][pRank] < 6 ) return SendClientMessage(playerid, COLOR_RED, "Diese Funktion kann NUR der Leader ausführen");
    if( g_fraktion[frak][Fr_Partner] != -1 ) return SendClientMessage(playerid, COLOR_RED, "Deine Fraktion hat bereits ein Bündnis");
    if( g_fraktion[partner][Fr_Partner] != -1 ) return SendClientMessage(playerid, COLOR_RED, "Die Angegeben Fraktion hat bereits ein Bündnis");
    new frakname[50], String[128];
    ReturnFraktionByID(partner,frakname);
    format(String,sizeof(String),"Du hast der %s eine Bündnisanfrage gesendet!",frakname);
    SendClientMessage(playerid,COLOR_YELLOW,String);
    ReturnFraktionByID(frak,frakname);
    format(String,sizeof(String),"Die %s hat euch ein Bündnis angeboten! Bündnis zustimmen mit: /Buendnisannehmen",frakname);
    SendFraktionMessage(partner, COLOR_YELLOW, String);
    g_fraktion[frak][Fr_PartnerRequest] = partner;
    return 1;
}

CMD:buendnisannehmen(playerid,params[]) {
    new frak = GetPlayerFaction(playerid);
    if( !IsAFightFaction( frak ) ) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang bzw. Mafia.");
    new partner;
    if(sscanf(params,"d",partner)) return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Buendnisannehmen [Fraktion]");
    if( !IsAFightFaction( partner ) ) return SendClientMessage(playerid, COLOR_RED, "Die Angegebene Fraktion ist keine Gang bzw. Mafia.");
    if( Spieler[playerid][pRank] < 6 ) return SendClientMessage(playerid, COLOR_RED, "Diese Funktion kann der Leader ausführen");
    if( g_fraktion[frak][Fr_Partner] != -1 ) return SendClientMessage(playerid, COLOR_RED, "Deine Fraktion hat bereits ein Bündnis");
    if( g_fraktion[partner][Fr_PartnerRequest] != frak ) return SendClientMessage(playerid, COLOR_RED, "Die Angegeben Fraktion hat keine Bündnisanfrage offen an deine Gang bzw. Mafia");
    new frakname[50], frakname2[50], String[128];
    ReturnFraktionByID(partner,frakname);
    ReturnFraktionByID(frak,frakname2);
    format(String,sizeof(String),"Die %s und die %s haben offiziell ein Bündnis abgeschlossen!",frakname,frakname2);
    SendFraktionMessage(partner, COLOR_GREEN, String);
    SendFraktionMessage(frak, COLOR_GREEN, String);
    g_fraktion[frak][Fr_PartnerRequest] = -1;
    g_fraktion[partner][Fr_PartnerRequest] = -1;
    g_fraktion[frak][Fr_Partner] = partner;
    g_fraktion[partner][Fr_Partner] = frak;
    return 1;
}


CMD:buendnis(playerid,params[]) {
    new frak = GetPlayerFaction(playerid);
    if( !IsAFightFaction( frak ) ) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang bzw. Mafia.");
    new partner, frakname[50], String[128];
    partner = g_fraktion[frak][Fr_Partner];
    SendClientMessage(playerid,COLOR_GREEN,"======BÜNDNIS-LISTE======");
    if(partner == -1 ) {
        SendClientMessage(playerid,COLOR_YELLOW,"Ihr seid mit niemanden verbündet!");
    } else {
        ReturnFraktionByID(partner,frakname);
        format(String,sizeof(String),"Ihr seid mit der %s offiziell verbündet!",frakname);
        SendClientMessage(playerid,COLOR_YELLOW,String);
    }
    return 1;
}


CMD:bg(playerid,params[]) {
    new frak = GetPlayerFaction(playerid);
    if( !IsAFightFaction( frak ) ) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang bzw. Mafia.");
    if( isnull(params) ) return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Bg [Nachricht]");
    if(g_fraktion[frak][Fr_Partner] == -1 ) return SendClientMessage(playerid, COLOR_RED, "Deine Gang bzw Mafia hat kein Bündnis");
    new partner, frakname[50], String[128+36];
    partner = g_fraktion[frak][Fr_Partner];
    ReturnFraktionByID(frak,frakname);
    format(String,sizeof(String),"[BG](%s,%s):%s",frakname,GetName(playerid),params);
    SendFraktionMessage(frak, COLOR_WHITE, String);
    SendFraktionMessage(partner, COLOR_WHITE, String);
    return 1;
}


CMD:buendnisabbrechen(playerid,params[]) {
    new frak = GetPlayerFaction(playerid);
    if( !IsAFightFaction( frak ) ) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang bzw. Mafia.");
    if( Spieler[playerid][pRank] < 6 ) return SendClientMessage(playerid, COLOR_RED, "Diese Funktion kann der Leader ausführen");
    if( g_fraktion[frak][Fr_Partner] == -1 ) return SendClientMessage(playerid, COLOR_RED, "Deine Fraktion hat bereits kein Bündnis");
    new partner, frakname[50], frakname2[50], String[128];
    partner = g_fraktion[frak][Fr_Partner];
    ReturnFraktionByID(partner,frakname);
    ReturnFraktionByID(frak,frakname2);
    format(String,sizeof(String),"Die %s hat offiziell das Bündnis mit %s beendet!",frakname2,frakname);
    SendFraktionMessage(partner, COLOR_RED, String);
    SendFraktionMessage(frak, COLOR_RED, String);
    g_fraktion[frak][Fr_PartnerRequest] = -1;
    g_fraktion[partner][Fr_PartnerRequest] = -1;
    g_fraktion[frak][Fr_Partner] = -1;
    g_fraktion[partner][Fr_Partner] = -1;
    return 1;
}


CMD:augenbinde(playerid,params[]) {
    new giveid;
    giveid = Spieler[playerid][iKidnapID];
    if(!(Spieler[playerid][pFraktion] == 6 || Spieler[playerid][pFraktion] == 7 || Spieler[playerid][pFraktion] == 10 || Spieler[playerid][pFraktion] == 11 || Spieler[playerid][pFraktion] == 12 || Spieler[playerid][pFraktion] == 13
    || Spieler[playerid][pFraktion] == 15 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 20 || Spieler[playerid][pFraktion] == 21))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Gang/Mafia Mitglied.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if( Spieler[playerid][pFraktion] == 17 ) {
        // Falls Wheelman,giveid anders auslesen
        giveid = Spieler[playerid][iWheelmanID];
        if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Kein Spieler Online dem du die Augenbinde abnehmen kannst");
    }
    if (!IsPlayerInRangeOfPlayer(playerid, giveid, 5.0)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    if(!IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug.");
    if( GetPlayerVehicleID(playerid) != GetPlayerVehicleID(giveid) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem anderen Fahrzeug.");
    new String[128];
    if( Spieler[giveid][bAugenbinde]) {
        new Float:X, Float:Y, Float:Z;
        GetPlayerPos(playerid,X,Y,Z);
        format(String,sizeof(String),"Du hast Spieler %s die Augenbinde abgenommen",GetName(giveid));
        SendClientMessage(playerid,COLOR_YELLOW,String);
        format(String,sizeof(String),"%s hat deine Augenbinde abgenommen, du kannst wieder sehen",GetName(playerid));
        SendClientMessage(giveid,COLOR_YELLOW,String);
        format(String,sizeof(String),"%s hat %s die Augenbinde abgenommen",GetName(playerid),GetName(giveid));
        SendRoundMessage(x,y,z,COLOR_LIGHTGREY,String);

        ResetAugenbinde(giveid);
        Spieler[giveid][bAugenbinde] = false;
    } else {
        if( Spieler[playerid][pFraktion] == 17 ) return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat keine Augenbinde auf");
        new Float:X, Float:Y, Float:Z;
        GetPlayerPos(playerid,X,Y,Z);
        format(String,sizeof(String),"Du hast Spieler %s die Augenbinde aufgesetzt",GetName(giveid));
        SendClientMessage(playerid,COLOR_YELLOW,String);
        format(String,sizeof(String),"%s hat dir eine Augenbinde aufgesetzt, du kannst nichts mehr sehen",GetName(playerid));
        SendClientMessage(giveid,COLOR_YELLOW,String);
        format(String,sizeof(String),"%s hat %s eine Augenbinde ausgesetzt",GetName(playerid),GetName(giveid));
        SendRoundMessage(x,y,z,COLOR_LIGHTGREY,String);

        SetPlayerCameraPos(giveid,3500.0,-2000.0,0.0);
        SetPlayerCameraLookAt(giveid,0.0,0.0,0.0);
        TextDrawShowForPlayer(giveid,BlackBox);
        Spieler[giveid][bAugenbinde] = true;
    }
    return 1;
}



CMD:mundbinde(playerid,params[]) {
    new giveid;
    giveid = Spieler[playerid][iKidnapID];
    if(!(Spieler[playerid][pFraktion] == 6 || Spieler[playerid][pFraktion] == 7 || Spieler[playerid][pFraktion] == 10 || Spieler[playerid][pFraktion] == 11 || Spieler[playerid][pFraktion] == 12 || Spieler[playerid][pFraktion] == 13
    || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 20 || Spieler[playerid][pFraktion] == 21))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Gang/Mafia Mitglied.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if( Spieler[playerid][pFraktion] == 17 ) {
        // Falls Wheelman,giveid anders auslesen
        giveid = Spieler[playerid][iWheelmanID];
        if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Kein Spieler Online dem du die Augenbinde abnehmen kannst");
    }
    if(!IsPlayerInRangeOfPoint(giveid, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    if(!IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug.");
    if( GetPlayerVehicleID(playerid) != GetPlayerVehicleID(giveid) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem anderen Fahrzeug.");
    new String[128];
    if( Spieler[giveid][bMundbinde]) {
        new Float:X, Float:Y, Float:Z;
        GetPlayerPos(playerid,X,Y,Z);
        format(String,sizeof(String),"Du hast Spieler %s die Mundbinde abgenommen",GetName(giveid));
        SendClientMessage(playerid,COLOR_YELLOW,String);
        format(String,sizeof(String),"%s hat deine Mundbinde abgenommen, du kannst wieder schreiben",GetName(playerid));
        SendClientMessage(giveid,COLOR_YELLOW,String);
        format(String,sizeof(String),"%s hat %s die Mundbinde abgenommen",GetName(playerid),GetName(giveid));
        SendRoundMessage(x,y,z,COLOR_LIGHTGREY,String);

        Spieler[giveid][bMundbinde] = false;
    } else {
        if( Spieler[playerid][pFraktion] == 17 ) {
            SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat keine Mundbinde");
            return 1;
        }
        new Float:X, Float:Y, Float:Z;
        GetPlayerPos(playerid,X,Y,Z);
        format(String,sizeof(String),"Du hast Spieler %s die Mundbinde aufgesetzt",GetName(giveid));
        SendClientMessage(playerid,COLOR_YELLOW,String);
        format(String,sizeof(String),"%s hat dir eine Munde aufgesetzt, du kannst nichts mehr schreiben",GetName(playerid));
        SendClientMessage(giveid,COLOR_YELLOW,String);
        format(String,sizeof(String),"%s hat %s eine Mundbinde aufgesetzt",GetName(playerid),GetName(giveid));
        SendRoundMessage(x,y,z,COLOR_LIGHTGREY,String);
        Spieler[giveid][bMundbinde] = true;
    }
    return 1;
}



CMD:gangjail(playerid,params[]) {
    new giveid;
    if(sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Gangjail [Spieler]");
    if(!(Spieler[playerid][pFraktion] == 6 || Spieler[playerid][pFraktion] == 7 || Spieler[playerid][pFraktion] == 10 || Spieler[playerid][pFraktion] == 11 || Spieler[playerid][pFraktion] == 12
    || Spieler[playerid][pFraktion] == 13 || Spieler[playerid][pFraktion] == 20 || Spieler[playerid][pFraktion] == 21))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Gang/Mafia Mitglied.");
    if(!IsPlayerInRangeOfPoint(playerid,5.0,2160.4111,-98.0815,2.8239)) return SendClientMessage(playerid,COLOR_GREEN,"Du bist nicht am Gangjail");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid,COLOR_GREEN,"Ungültiger Spieler");
    if(giveid != Spieler[playerid][iKidnapID] ) return SendClientMessage(playerid,COLOR_GREEN,"Du hast diesen Spieler nicht entführt");
    new Float:X, Float:Y, Float:Z, String[128];
    GetPlayerPos(playerid,X,Y,Z);
    format(String,sizeof(String),"Du hast %s ins Gangjail gesperrt",GetName(giveid));
    SendClientMessage(playerid,COLOR_YELLOW,String);
    format(String,sizeof(String),"Du wurdest von %s ins Gangjail eingesperrt",GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    format(String,sizeof(String),"%s hat %s ins Gangjail gesperrt",GetName(playerid),GetName(giveid));
    SendRoundMessage(X,Y,Z,COLOR_LIGHTRED2,String);
    format(String,sizeof(String),"%s wurde von %s ins Gangjail gesperrt",GetName(giveid),GetName(playerid));
    SendFraktionMessage(1, COLOR_LIGHTRED2, String);
    SendFraktionMessage(2, COLOR_LIGHTRED2, String);
    SendFraktionMessage(16, COLOR_LIGHTRED2, String);
    SendFraktionMessage(18, COLOR_LIGHTRED2, String);
    SendFraktionMessage(22, COLOR_LIGHTRED2, String);
    SetPlayerPos(giveid,2162.6523,-102.3127,2.7500);
    ResetAugenbinde(giveid);
    Spieler[giveid][bAugenbinde] = false;
    Spieler[giveid][bMundbinde] = false;
    UnfreezePlayer(giveid);
    Spieler[giveid][pJailed] = 4;
    Spieler[giveid][bKidnapped] = false;
    Spieler[playerid][iKidnapID] = INVALID_PLAYER_ID;
    return 1;
}


CMD:waffenlager(playerid, params[]) {
    if (!Spieler[playerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Fraktion.");
    if (HasWeaponBlock(playerid)) {
        SendClientMessage(playerid, COLOR_RED, "Du kannst diesen Befehl nicht ausführen!");
        return SendWeaponBlockInfo(playerid);
    }

    switch (IsPlayerAtWaffenlager(playerid)) {
        case WEAPON_DEPOT_OWN: return ShowWaffenLager(playerid, 0);
        case WEAPON_DEPOT_OTHER: return SendClientMessage(playerid, COLOR_RED, "Das ist nicht das Waffenlager deiner Fraktion.");
        case WEAPON_DEPOT_CLOSED: return SendClientMessage(playerid, COLOR_RED, "Das Waffenlager ist geschlossen!");
        case WEAPON_DEPOT_NONE: return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht in der Nähe eines Waffenlagers.");
    }

    return 1;
}