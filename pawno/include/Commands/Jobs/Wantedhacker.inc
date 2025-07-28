#include <YSI\y_hooks>


CMD:wantedhacken(playerid,params[])
{
    new modelid, vehicleid = GetPlayerVehicleID(playerid);
    if (Spieler[playerid][pJob] != 21) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Wantedhacker.");
    if (!IsPlayerInDynamicArea(playerid,g_iWantedHackerZone)) return SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht hinter dem Polizei Präsidium.");
    modelid = GetVehicleModel(vehicleid);
    if ((modelid != 413) && (modelid != 459) && (modelid != 482)) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Van.");
    if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid,COLOR_RED,"Du musst der Fahrer des Wagens sein.");
    if(Spieler[playerid][pWantedCodes]<=0) return SendClientMessage(playerid,COLOR_RED,"Du hast keine Wantedcodes auf der Hand.");
 
    return ShowPlayerDialog(playerid,DIALOG_WANTEDCODES,DIALOG_STYLE_LIST,"Wantedhacking","Wanteds löschen\nGesuchten-Liste anzeigen\nAlle Cops anzeigen","Auswählen","Abbrechen");
}


CMD:wcodes(playerid,params[]) {
    if(Spieler[playerid][pJob] != 21 ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Wantedhacker.");
        return 1;
    }
    if( !IsPlayerInRangeOfPoint(playerid,3.0, WANTEDHACKERBASE_POINT) ) {
        return SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht am Wantedhacker Platz.");
    }
    if( gettime() < Spieler[playerid][punixWantedCodes] ) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst noch warten bis du erneut Wantedcodes erhältst.");
    }
    new String[128], codes;
    codes = 5 + random(5);
    Spieler[playerid][punixWantedCodes] = gettime() + 10*60;
    Spieler[playerid][pWantedCodes] += codes;
    format(String,sizeof(String),"Du hast %d Wantedcodes erhalten (Hand: %d).",codes,Spieler[playerid][pWantedCodes]);
    SendClientMessage(playerid,COLOR_GREEN,String);
    return 1;
}


CMD:sellwantedcodes(playerid, params[])
{
    if (Spieler[playerid][pJob] != 21) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Wanted-Hacker.");
    new pID, menge, preis, Float:x, Float:y, Float:z;
    if (sscanf(params, "uii", pID, menge, preis)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Sellwantedcodes [SpielerID/Name] [Menge] [Preis]");
    if (playerid == pID) return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber keine Wantedcodes verkaufen.");
    if (preis < 1 || preis > 100000000) return SendClientMessage(playerid, COLOR_ORANGE, "Der Preis sollte zwischen $1 und $100.000.000 liegen.");
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");

    GetPlayerPos(pID, x, y, z);
    if (!IsPlayerInRangeOfPoint(playerid, 5.0, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
    if (menge < 0) return SendClientMessage(playerid,COLOR_RED,"Der Betrag kann nicht negativ sein!");
    if (menge > Spieler[playerid][pWantedCodes]) return SendClientMessage(playerid, COLOR_RED, "Soviele Wantedcodes hast du nicht.");

    if (preis / menge < 2000 || preis / menge > 2500) {
        return SendClientMessage(playerid, COLOR_RED, "Der aktuelle Stückpreis bei Wantedcodes liegt im Rahmen von 2.000$ bis 2.500$!");
    }

    SetPVarString(playerid, "SELL_WCODES", params);
    ShowPlayerDialog(playerid, DIALOG_SELLWCODES, DIALOG_STYLE_MSGBOX, "Handelsinformation","\
        Der aktuelle Verkaufspreis je Code liegt zwischen 2.000$ bis 2.500$.\n\
        Höhere oder niedrigere Beträge sind unzulässig und werden nach Server Regel §11 (Geldwäsche) administrativ bestraft!\n\
        Strafmaß: dauerhafte- oder zeitliche Sperrung, Admin-Verwarnung, Prison oder Inventar-/Geldentzug.\n\
        Jeder Wantedcodehandel wird gespeichert und geprüft!", "Einverstanden", "Ablehnen");
    return 1;
}
