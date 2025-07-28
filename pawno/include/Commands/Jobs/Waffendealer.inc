#include <YSI\y_hooks>


CMD:paketentladen(playerid)
{
    if(Spieler[playerid][pJob] == 18)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 7.0, -1857.4130,-1618.9630,21.9022))return SendClientMessage(playerid, COLOR_RED, "[SAMEN] {FFFFFF}Du bist nicht in der Nähe des Entlagerungspunkts.");
        new vID = GetPlayerVehicleID(playerid);
        if(!IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Transporter.");
        if(bestand[vID] < 1)return SendClientMessage(playerid, COLOR_RED, "Du hast nichts beladen!");
        if( aiVehicles[vID] == VEH_WDEALER ) {
            for(new i=0;i<sizeof(wdealer);i++)
            {
                if(vID == wdealer[i])
                {
                    new newteile = bestand[vID]*100;
                    Spieler[playerid][pWaffenteile] += newteile;
                    new string[128];
                    format(string, sizeof(string), "Du hast %d Pakete abgeliefert und %d Waffenteile erhalten.", bestand[vID], newteile);
                    SendClientMessage(playerid, COLOR_GREEN, string);
                    bestand[vID] = 0;
                    PlayerSkillUpgrade(playerid,pWaffenteilePoints,5,1);
                    return 1;
                }
            }
        }
        SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Transporter!");
        return 1;
    }
    else if(Spieler[playerid][pFraktion] == 15)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 7.0, -66.3187,-1121.1329,0.6501))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Entlagerungspunkts.");
        new vehicleid = GetPlayerVehicleID(playerid);
        new vehiclemodel = GetVehicleModel(vehicleid);
    	new fraktion = GetVehicleFraktion(vehicleid);
		if(fraktion != Spieler[playerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Nine-Demons Burrito!");
		if(vehiclemodel != 482) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Nine-Demons Burrito!");
        if(bestand[vehicleid] < 1)return SendClientMessage(playerid, COLOR_RED, "Du hast nichts beladen!");
        //new newteile = bestand[vID]*100;
        new samenpakete = bestand[vehicleid];
        new string[128];
        Spieler[playerid][pDrogenSamen] += samenpakete;
        format(string, sizeof(string), "Du hast %d Pakete abgeliefert und %d Samen erhalten.", bestand[vehicleid], samenpakete);
        SendClientMessage(playerid, COLOR_GREEN, string);
        bestand[vehicleid] = 0;
        //PlayerSkillUpgrade(playerid,pWaffenteilePoints,5,1);
        return 1;
    }
    return 1;
}


CMD:paketeinladen(playerid, params[])
{
    if(Spieler[playerid][pFraktion] == 15 && IsPlayerInRangeOfPoint(playerid, 7.0, -111.0688,1133.3749,19.7422)){
        new anzahl, string[128];
        if(sscanf(params, "i", anzahl))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Paketeinladen [Anzahl]");
        if(!IsPlayerInRangeOfPoint(playerid, 7.0, -111.0688,1133.3749,19.7422))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Samen-Lagers!");
        if(anzahl < 0 )return SendClientMessage(playerid, COLOR_RED, "Ungültige Anzahl");
        new vehicleid = GetPlayerVehicleID(playerid);
        new vehiclemodel = GetVehicleModel(vehicleid);
    	new fraktion = GetVehicleFraktion(vehicleid);
    	new maxAnzahl = GetPlayerSamenSkillLevelValue(playerid);
		if(fraktion != Spieler[playerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Nine-Demons Burrito!");
		if(vehiclemodel != 482) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Nine-Demons Burrito!");
		//if(Spieler[playerid][pDrogenSamen] != 0) return SendClientMessage(playerid, COLOR_RED, "Du hast zu viele Samen dabei! Lager die Samen in einem Zwischenlager.");
        new newanzahl = anzahl+bestand[vehicleid];
        if(newanzahl > maxAnzahl) return SendClientMessage(playerid, COLOR_ORANGE, "Du kannst den Wagen nicht überladen.");
		bestand[vehicleid] += anzahl;
  		format(string, sizeof(string), "Der Wagen wurde mit %d Paketen aufgeladen.", anzahl);
    	SendClientMessage(playerid, COLOR_GREEN, string);
     	SendClientMessage(playerid, COLOR_WHITE, "Bringe die Pakete in einen Samenpunkt!");
      	//SetPlayerCheckpoint(playerid, -66.3187,-1121.1329,0.6501, 7.0);
       	GivePlayerCash(playerid, -500*anzahl);
   		return 1;
	}
    else if(Spieler[playerid][pJob] == 18)
    {
        new anzahl, string[128];
        if(sscanf(params, "i", anzahl))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Paketeinladen [Anzahl]");
        if(Spieler[playerid][pLevel] < 3)return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens Level 3 sein!");
        if(!IsPlayerInRangeOfPoint(playerid, 7.0, 2348.1086,-2302.4243,13.5469))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Lagers. Das Lager wird dir mit /Lagerpunkt angezeigt.");
        if(anzahl < 0 )return SendClientMessage(playerid, COLOR_RED, "Ungültige Anzahl");
        new maxAnzahl = GetPlayerWaffenteileSkillValue(playerid);
        if(anzahl > maxAnzahl ) {
            new String[120];
            format(String,sizeof(String),"Auf Grund deines Waffendealer-Skills (%d) kannst du nur maximal %d Päckchen transportieren",GetPlayerWaffenteileSkillLevel(playerid), maxAnzahl);
            return SendClientMessage(playerid, COLOR_RED, String);
        }
        new vID = GetPlayerVehicleID(playerid);
        new newgeld = anzahl*500;
        if(CheckMoney(playerid) < newgeld)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        new newanzahl = anzahl+bestand[vID];
        if(newanzahl > maxAnzahl) return SendClientMessage(playerid, COLOR_ORANGE, "Du kannst den Wagen nicht überladen.");
        if( aiVehicles[vID] == VEH_WDEALER ) {
            for(new i=0;i<sizeof(wdealer);i++)
            {
                if(vID == wdealer[i])
                {
                    bestand[vID] += anzahl;
                    format(string, sizeof(string), "Der Wagen wurde mit %d Paketen aufgeladen.", anzahl);
                    SendClientMessage(playerid, COLOR_GREEN, string);
                    SendClientMessage(playerid, COLOR_WHITE, "Es wurde ein Checkpoint auf der Karte angezeigt. Bring dort die Pakete hin!");
                    SetPlayerCheckpointEx(playerid, -1857.4130,-1618.9630,21.9022, 7.0, CP_SHOWJOB12);
                    GetPlayerPos(playerid,oldposx[playerid],oldposy[playerid],oldposz[playerid]);
                    playertimestamp[playerid]=gettime();
                    GivePlayerCash(playerid, -newgeld);
                    return 1;
                }
            }
        }
        SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Waffen-Transporter.");
        return 1;
    }
	return 1;
}


CMD:sellgun(playerid, params[])
{
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pJob] != 18) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist kein Waffendealer.");
    new dialogText[256];
    dialogText = "Waffe\tWaffen-ID\tWaffenteile\tMunition\n";
    for (new i; i < sizeof(g_sellGuns); i++) format(dialogText, sizeof(dialogText), "%s%s\t%d\t%d\t%d\n", dialogText, g_sellGuns[i][SELL_GUN_NAME],
        g_sellGuns[i][SELL_GUN_ID], g_sellGuns[i][SELL_GUN_MATS], g_sellGuns[i][SELL_GUN_AMMO]);

    return ShowPlayerDialog(playerid, DIALOG_SELLGUN_MAIN, DIALOG_STYLE_TABLIST_HEADERS, "{BDBDBD}Waffenverkauf - Waffenübersicht", dialogText, "Auswählen", "Abbrechen");
}


CMD:sellwaffenteile(playerid, params[])
{
    new pID, menge, preis, Float:x, Float:y, Float:z;
    if(sscanf(params, "uii", pID, menge, preis))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Sellwaffenteile [SpielerID/Name] [Menge] [Preis]");
    if (playerid == pID) return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber keine Waffenteile verkaufen.");
    if(Spieler[playerid][pJob] != 18)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Waffendealer.");
    GetPlayerPos(pID, x,y,z);
    if(preis < 1 || preis > 100000000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Preis sollte zwischen $1 und $100.000.000 liegen.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
    if(menge > Spieler[playerid][pWaffenteile])return SendClientMessage(playerid, COLOR_RED, "Soviele Waffenteile besitzt du nicht.");
    if( menge < 0 ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Betrag kann nicht negativ sein!");
    }

    #if !defined NEUE_WIRTSCHAFT
        if(preis/menge < 20||preis/menge > 25) {
            return SendClientMessage(playerid,COLOR_RED,"Der aktuelle Stückpreis bei Waffenteilen liegt im Rahmen von 20$ bis 25$!");
        }
    #endif
    // Goldkiller: WTF ist das ???? :
    // if(menge < 999999999999999 )return SendClientMessage(playerid, COLOR_RED, "Ungültige Anzahl");

    SetPVarString(playerid,"SellWTeile",params);
    /*
    pDrogenID[pID] = playerid;
    pDrogenPreis[pID] = preis;
    pDrogenMenge[pID] = menge;

    //Spieler[pID][pDrugs] += menge;
    //Spieler[playerid][pDrugs] -= menge; // dein komischer bug ( Entfernt 20.05.2013 )
    format(string, sizeof(string), "Du hast von %s eine Anfrage für Waffenteile erhalten. Menge: %d, Preis: $%d.", GetName(playerid), menge, preis);
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    SendClientMessage(pID, COLOR_LIGHTBLUE, "Tippe '/Accept Waffenteile' um das Angebot anzunehmen.");
    format(string, sizeof(string), "Du hast %s deine Waffenteile angeboten. Menge: %d, Preis: $%d.", GetName(pID), menge, preis);
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    */
    #if defined NEUE_WIRTSCHAFT
        ShowPlayerDialog(playerid,DIALOG_SELLWTEILE,DIALOG_STYLE_MSGBOX,"Handelsinformation","\
            Jeder Handel wird gespeichert und geprüft!","Einverstanden","Ablehnen");
    #else
        ShowPlayerDialog(playerid,DIALOG_SELLWTEILE,DIALOG_STYLE_MSGBOX,"Handelsinformation","\
            Der aktuelle Stückpreis bei Waffenteilen liegt zwischen 20$ bis 25$.\n\
            Höhere oder niedrigere Beträge sind unzulässig und werden nach Server Regel §11(Geldwäsche) administrativ bestraft!\n\
            Strafmaß: dauerhafte- oder zeitliche Sperrung, Admin-Verwarnung, Prison oder Inventar-/Geldentzug.\n\
            Jeder Handel wird gespeichert und geprüft!","Einverstanden","Ablehnen");
    #endif
    return 1;
}