#include <YSI\y_hooks>



CMD:startreinigung(playerid)
{
    if(!(Spieler[playerid][pJob] == 7))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Straßenreiniger.");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    for(new i=0;i<sizeof(reinigung);i++)
    {
        new vID = GetPlayerVehicleID(playerid);
        if(vID == reinigung[i])
        {
            SetPlayerCheckpointEx(playerid, 2060.6467,-1930.0806,13.3428, 5.0, CP_REINI1);
            SendClientMessage(playerid, COLOR_GREEN, "Du bist nun im Dienst. Fahre die Marker ab und tue was vorgeschrieben wird!");
            Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
            return 1;
        }
    }
    SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Reinungsfahrzeug.");
    return 1;
}

CMD:stopreinigung(playerid)
{
    if(!(Spieler[playerid][pJob] == 7))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Straßenreiniger.");
    SendClientMessage(playerid, COLOR_RED, "Du hast die Arbeit abgebrochen.");
    DisablePlayerCheckpointEx(playerid);
    return 1;
}