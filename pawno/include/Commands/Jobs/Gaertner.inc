#include <YSI\y_hooks>


CMD:stopgarten(playerid)
{
    if(!(Spieler[playerid][pJob] == 9))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Gärtner.");
    SendClientMessage(playerid, COLOR_RED, "Du hast die Arbeit abgebrochen.");
    DisablePlayerCheckpointEx(playerid);
    return 1;
}


CMD:startgarten(playerid)
{
    if(!(Spieler[playerid][pJob] == 9))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Gärtner.");
    //if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
      //  return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    //}
    new vID = GetPlayerVehicleID(playerid);
    new model = GetVehicleModel(vID);
    if(model == 572)
    {
        SetPlayerCheckpointEx(playerid, 1559.7780,17.8068,24.1641, 5.0, CP_GARTEN1);
        SendClientMessage(playerid, COLOR_GREEN, "Du bist nun im Dienst. Pflege mit dem Rasenmäher die Wiese.");
        Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
        return 1;
    }
    SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Rasenmäher.");
    return 1;
}