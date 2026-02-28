#include <YSI\y_hooks>



CMD:samenpaketeinladen(playerid, params[]){
    new anzahl, string[128];
    if(sscanf(params, "i", anzahl))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Samenpaketeinladen [Anzahl]");
    if(!IsAFightFaction(Spieler[playerid][pFraktion]) && Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "[SAMEN] {FFFFFF}Du bist in keiner Gang oder Mafia!");

    new vehicleid = GetPlayerVehicleID(playerid);
    new fraktion = GetVehicleFraktion(vehicleid);
    if(fraktion != Spieler[playerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "[SAMEN] {FFFFFF}Du bist in keinem Fahrzeug von einer Gang/Mafia!");

    new vehiclemodel = GetVehicleModel(vehicleid);
	if(vehiclemodel != 482) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Gang/Mafia Burrito!");

    if(anzahl < 0 )return SendClientMessage(playerid, COLOR_RED, "Ungültige Anzahl");
    new maxAnzahl = GetPlayerDrogenSkillValue(playerid);
    if(anzahl > maxAnzahl ) {
        new String[80];
        format(String,sizeof(String),"Auf Grund deines Drogen-Skills (%d) kannst du nur maximal %d Päckchen transportieren",GetPlayerDrogenSkillLevel(playerid), maxAnzahl);
        return SendClientMessage(playerid, COLOR_RED, String);
    }
    if(!IsPlayerInRangeOfPoint(playerid, 7.0, -38.4148,56.1184,3.1172))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Lagers. Das Lager wird dir mit /Samenlagerpunkt angezeigt.");
    new vID = GetPlayerVehicleID(playerid);
    new newgeld = anzahl*500;
    if(CheckMoney(playerid) < newgeld)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
    new newanzahl = anzahl+bestand[vID];
    if(newanzahl > maxAnzahl )return SendClientMessage(playerid, COLOR_ORANGE, "Du kannst den Wagen nicht überladen.");
    
    bestand[vID] += anzahl;
    lagerbestand -= anzahl;
    format(string, sizeof(string), "Der Wagen wurde mit %d Paketen aufgeladen.", anzahl);
    SendClientMessage(playerid, COLOR_GREEN, string);
    SendClientMessage(playerid, COLOR_WHITE, "Es wurde ein Checkpoint auf der Karte angezeigt. Bring dort die Pakete hin!");
    SetPlayerCheckpointEx(playerid, -258.9534,-2181.9905,29.0150, 7.0, CP_SHOWJOB12);
    GetPlayerPos(playerid,oldposx[playerid],oldposy[playerid],oldposz[playerid]);
    playertimestamp[playerid]=gettime();
    GivePlayerCash(playerid, -newgeld);
    return 1;
}

CMD:samenpaketentladen(playerid){
    if(!IsPlayerInRangeOfPoint(playerid, 7.0, -258.9534,-2181.9905,29.0150))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Entlagerungspunkts.");
    if(!IsAFightFaction(Spieler[playerid][pFraktion]) && Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "[SAMEN] {FFFFFF}Du bist in keiner Gang oder Mafia!");
    new vID = GetPlayerVehicleID(playerid);
    if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Transporter.");
    if(bestand[vID] < 1)return SendClientMessage(playerid, COLOR_RED, "Du hast nichts beladen!");

    new newdrugs = bestand[vID];
    Spieler[playerid][pGangDrogenSamen] += newdrugs;
    new string[128];
    format(string, sizeof(string), "Du hast %d Pakete abgeliefert und %d Drogensamen erhalten.", bestand[vID], newdrugs);
    SendClientMessage(playerid, COLOR_GREEN, string);
    bestand[vID] = 0;
    PlayerSkillUpgrade(playerid,pDrogenPoints, 4,1);
    return 1;
}


CMD:selldrogen(playerid, params[])
{
    new pID, menge, preis, Float:x, Float:y, Float:z;
    if(sscanf(params, "uii", pID, menge, preis))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Selldrogen [SpielerID/Name] [Menge] [Preis]");
    if (playerid == pID) return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber keine Drogen verkaufen.");
    if(Spieler[playerid][pJob] != 17)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Drogendealer.");
    GetPlayerPos(pID, x,y,z);
    if(preis < 1 || preis > 100000000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Preis muss zwischen $1 und $100.000.000 liegen.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
    if(menge > Spieler[playerid][pDrugs])return SendClientMessage(playerid, COLOR_RED, "Soviel Gramm hast du nicht.");
    if( menge < 0 ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Betrag kann nicht negativ sein!");
    }

    #if !defined NEUE_WIRTSCHAFT
        if(preis/menge < 240||preis/menge > 400) {
            return SendClientMessage(playerid,COLOR_RED,"Der aktuelle Stückpreis bei Drogen liegt im Rahmen von 240$ bis 400$!");
        }
    #endif
    // Goldkiller: WTF ist das ???? :
    // if(menge < 999999999999999 )return SendClientMessage(playerid, COLOR_RED, "Ungültige Anzahl");

    SetPVarString(playerid,"SellDrugs",params);
    /*
    pDrogenID[pID] = playerid;
    pDrogenPreis[pID] = preis;
    pDrogenMenge[pID] = menge;

    //Spieler[pID][pDrugs] += menge;
    //Spieler[playerid][pDrugs] -= menge; // dein komischer bug ( Entfernt 20.05.2013 )
    format(string, sizeof(string), "Du hast von %s eine Anfrage für Drogen erhalten. Menge: %d, Preis: $%d.", GetName(playerid), menge, preis);
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    SendClientMessage(pID, COLOR_LIGHTBLUE, "Tippe '/Accept Drogen' um das Angebot anzunehmen.");
    format(string, sizeof(string), "Du hast %s deine Drogen angeboten. Menge: %d, Preis: $%d.", GetName(pID), menge, preis);
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    */
    #if defined NEUE_WIRTSCHAFT
        ShowPlayerDialog(playerid,DIALOG_SELLDRUGS,DIALOG_STYLE_MSGBOX,"Handelsinformation","\
            Jeder Drogenhandel wird gespeichert und geprüft!","Einverstanden","Ablehnen");
    #else
        ShowPlayerDialog(playerid,DIALOG_SELLDRUGS,DIALOG_STYLE_MSGBOX,"Handelsinformation","\
            Der aktuelle Verkaufspreis je Gramm liegt zwischen 240$ bis 400$.\n\
            Höhere oder niedrigere Beträge sind unzulässig und werden nach Server Regel §11(Geldwäsche) administrativ bestraft!\n\
            Strafmaß: dauerhafte- oder zeitliche Sperrung, Admin-Verwarnung, Prison oder Inventar-/Geldentzug.\n\
            Jeder Drogenhandel wird gespeichert und geprüft!","Einverstanden","Ablehnen");
    #endif
    return 1;
}