#include <YSI\y_hooks>


CMD:stopzug(playerid)
{
    if(!(Spieler[playerid][pJob] == 23))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Zugfahrer.");
    KillTimer(pilotwait[playerid]);
    pilotwait[playerid] = INVALID_TIMER_ID;

    UnfreezePlayer(playerid);
    PlayerTextDrawHide(playerid, BusMessage[playerid]);
    DisablePlayerCheckpointEx(playerid);
    SendClientMessage(playerid, COLOR_RED, "Zugfahrer abgebrochen!");
    return 1;
}


CMD:startzug(playerid)
{
    if(!(Spieler[playerid][pJob] == 23))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Zugfahrer.");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    for(new i=0;i<sizeof(zugb);i++)
    {
        new vID = GetPlayerVehicleID(playerid);
        if(!(GetPlayerState(playerid) == PLAYER_STATE_DRIVER))return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Zug.");
        if(vID == zugb[i])
        {
            KillTimer(pilotwait[playerid]);
            pilotwait[playerid] = INVALID_TIMER_ID;

            PilotTime[playerid] = 0;
            DisablePlayerCheckpointEx(playerid);
            SetPlayerCheckpointEx(playerid, 2864.8928,1326.3370,10.8203, 7.0, CP_ZUGB1);
            SendClientMessage(playerid, COLOR_LIGHTBLUE, "Nächste Haltestelle: Las Venturas Ost-Bahnhof");
            Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
        }
    }
    return 1;
}