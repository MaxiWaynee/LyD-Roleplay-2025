#include <YSI\y_hooks>


//HELFER-SYSTEM
CMD:experte(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,3.0,808.7208,-1350.4906,13.5418)) return SendClientMessage(playerid, COLOR_RED, "An diesem Ort kannst du dich nicht als 'Experte' (Neulingshelfer) freischalten!");
    if( Spieler[playerid][pLevel] < 20 ) return SendClientMessage(playerid, COLOR_RED, "Du musst Level 20 sein, um dich als Helfer freischalten zu können.");//20
    if( Spieler[playerid][pWarns] > 2 ) return SendClientMessage(playerid, COLOR_RED, "Mit mehr als zwei Admin Verwarnungen, kannst du dich nicht als Helfer freischalten!");
    if(Spieler[playerid][pAutomatik] > 0)return SendClientMessage(playerid, COLOR_RED, "Du bist bereits ein Server-Experte.");
    new String[128];
    format(String,sizeof(String),"[EXPERTE] %s ist nun auch ein Experte!",GetName(playerid));
    SendHelferMessage(COLOR_YELLOW,String);
    SendClientMessage(playerid, COLOR_GREEN, "[EXPERTE] Du bist nun ein Server-Experte!");
    ShowPlayerDialog(playerid, DIALOG_SPAWNMELDUNG, DIALOG_STYLE_MSGBOX, "SERVER-EXPERTE", "Du bist nun ein Server-Experte!\nDeine Aufgabe ist es, Neulingen zu helfen.\n\nDu wirst über Neuregistrierungen informiert.\nMit /Neulingfinden kannst du dir den Standort eines Neulings anzeigen lassen\nund ihm helfen. Mit /Danke kann sich der Neuling bei dir bedanken.\n", "OK", "");
    Spieler[playerid][pAutomatik] = 1;
    return 1;
}
CMD:einfuehrung(playerid,params[]) {
    if( Spieler[playerid][pLevel] > 5 ) return SendClientMessage(playerid, COLOR_RED, "Nur Spieler unter Level 5 können diese Funktion nutzen");
    if( !IsPlayerInRangeOfPoint(playerid,10.0,809.3212,-1339.9855,13.5408) ) return SendClientMessage(playerid, COLOR_RED, "Diese Funktion kannst du nur am Neulingsspawn benutzen.");
    new String[128];
    format(String,sizeof(String),"[EXPERTE] Neuling %s benötigt für den Start eine Einführung! Standort: Neulingsspawn",GetName(playerid));
    SendHelferMessage(COLOR_YELLOW, String);
    format(String,sizeof(String),"[EXPERTE] Neuling %s benötigt für den Start eine Einführung! Standort: Neulingsspawn",GetName(playerid));
    SendAdminMessage(COLOR_YELLOW, String);
    SendClientMessage(playerid, COLOR_GREEN, "Du möchtest eine Einführung. Alle Helfer wurden informiert. In Kürze wird einer zu dir kommen.");
    return 1;
}

CMD:expertenausweis(playerid, params[])
{
    new pID, string[130];
    if(!(Spieler[playerid][pAutomatik] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Server-Experte");
    if(sscanf(params, "uis[64]", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Expertenausweis [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[pID][pAdminDienst] ) {
            return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist gerade im Admindienst!");
    }
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(IsPlayerInRangeOfPoint(pID, 10.0, x,y,z))
    {
        format(string, sizeof(string), "Du hast %s dein Abzeichen als Experten gezeigt.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        SendClientMessage(pID, COLOR_YELLOW, "==============================================");
        SendClientMessage(pID, COLOR_BLUE, "******** SERVER - EXPERTE ********");
        SendClientMessage(pID, COLOR_WHITE, "Server-Experten sind Spieler, die Spieler helfen.");
        format(string , sizeof(string), "Server-Experte: {FFFFFF}%s", GetName(playerid));
        SendClientMessage(pID, COLOR_BLUE,string);
        SendClientMessage(pID, COLOR_YELLOW, "==============================================");
        //ShowPlayerDialog(pID, DIALOG_SZETTEL, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Polizeidienstmarke", string, "OK", "Abbrechen");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Umgebung.");
        return 1;
    }
    return 1;
}
CMD:danke(playerid, params[])
{
    new pID, string[130];
    if(Spieler[playerid][pLevel] > 5)return SendClientMessage(playerid, COLOR_RED, "Du musst unter Level 5 sein, um diesen Befehl nutzen zu können.");
    if(Spieler[playerid][pRaketen] == 1 )return SendClientMessage(playerid, COLOR_RED, "Du hast dich bereits bei einem Server-Experten bedankt.");
    if(sscanf(params, "uis[64]", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Danke [SpielerID/Name vom Experten]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Server-Experte ist nicht online.");
    if(!(Spieler[pID][pAutomatik] == 1))return SendClientMessage(playerid, COLOR_RED, "Der Spieler, bei dem du dich für die Hilfe bedanken möchtest, ist kein Server-Experte.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(IsPlayerInRangeOfPoint(pID, 15.0, x,y,z))
    {
        Spieler[playerid][pRaketen] = 1;
        format(string, sizeof(string), "Du hast dich beim Server-Experten %s für seine Hilfe bedankt.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        format(string , sizeof(string), "Der Neuling %s hat sich für deine Hilfe bedankt! Du erhältst 3.000$ als Belohnung.", GetName(playerid));
        SendClientMessage(pID, COLOR_GREEN,string);
        Spieler[pID][pCash] += 3000;
        //ShowPlayerDialog(pID, DIALOG_SZETTEL, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Polizeidienstmarke", string, "OK", "Abbrechen");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Der Server-Experte, bei dem du dich bedanken möchtest, ist nicht in deiner Umgebung.");
        return 1;
    }
    return 1;
}
CMD:neulingfinden(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Neulingfinden [SpielerID/Name]");
    if(!(Spieler[playerid][pAutomatik] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Server-Experte!");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[pID][pLevel] > 5 ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Spieler ist kein Neuling mehr!");
    }
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    SetPlayerCheckpointEx(playerid, x,y,z,5.0, CP_FINDEN);
    format(string, sizeof(string), "* %s wurde auf der Karte Rot markiert, Gebäude-Komplex: %d.", GetName(pID), GetPlayerInterior(pID));
    SendClientMessage(playerid, COLOR_YELLOW, string);
    return 1;
}


CMD:expertefarbe(playerid)
{
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt.");
	if(Spieler[playerid][pDuty] == 1 ) return SendClientMessage(playerid,COLOR_RED,"Du bist noch im Frakdienst.");
    if(!(Spieler[playerid][pAutomatik] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Server-Experte!");
    {
        if(Spieler[playerid][pBenutzerfarbe]==0)
        {
            SendClientMessage(playerid,COLOR_GREEN,"Benutzerfarbe als Server-Experte wurde aktiviert.");
            SetPlayerColor(playerid, TEAM_STAAT_COLOR);
            Spieler[playerid][pBenutzerfarbe] = 1;
        }
        else
        {
            SendClientMessage(playerid,COLOR_YELLOW,"Benutzerfarbe als Server-Experte wurde deaktiviert.");
            Spieler[playerid][pBenutzerfarbe] = 0;
            SetPlayerColor(playerid, COLOR_WHITE);
        }
    }
    return 1;
}


CMD:expertehelp(playerid)
{
    if(Spieler[playerid][pAutomatik] != 1)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Server-Experte!");
    SendClientMessage(playerid, COLOR_BLUE, "* SERVER-EXPERTE *: {FFFFFF}Die Aufgabe des Server-Experten ist es, Neulingen zu helfen. Über Neuregistrierungen wird man informiert.");
    SendClientMessage(playerid, COLOR_BLUE, "* SERVER-EXPERTE *: {FFFFFF}/Expertenausweis - Du kannst dich bei Neulingen als Helfer ausweisen.");
    SendClientMessage(playerid, COLOR_BLUE, "* SERVER-EXPERTE *: {FFFFFF}/Neulingfinden - Du kannst dir den Standort eines Neulings anzeigen lassen und zu ihm fahren.");
    SendClientMessage(playerid, COLOR_BLUE, "* SERVER-EXPERTE *: {FFFFFF}/Expertefarbe - Aktivierst du deine spezielle Benutzerfarbe, um dich als Server-Experte erkenntlich zu machen.");
    //SendClientMessage(playerid, COLOR_BLUE, "* SERVER-EXPERTE *: {FFFFFF}/EC - Du kannst mit anderen Server-Experten kommunizieren.");
    SendClientMessage(playerid, COLOR_BLUE, "* SERVER-EXPERTE *: {FFFFFF}/Danke - Diesen Befehl können nur die Neulinge ausführen, um sich bei dir für deine Hilfe zu bedanken.");
    return 1;
}
// HELFER-SYSTEM ENDE