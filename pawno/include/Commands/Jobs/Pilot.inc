#include <YSI\y_hooks>



CMD:startflug(playerid)
{
    if(!(Spieler[playerid][pJob] == 4))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Pilot.");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    for(new i=0;i<sizeof(vehicle_airportLs);i++)
    {
        new vID = GetPlayerVehicleID(playerid);
        if(!(GetPlayerState(playerid) == PLAYER_STATE_DRIVER))return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Flugzeug.");
        if(vID == vehicle_airportLs[i])
        {
            KillTimer(pilotwait[playerid]);
            pilotwait[playerid] = INVALID_TIMER_ID;
            Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);

            PilotTime[playerid] = 0;
            DisablePlayerCheckpointEx(playerid);
            SetPlayerCheckpointEx(playerid, 2045.5306,-2593.0469,14.8793, 7.0, CP_PILOT1);
            SendClientMessage(playerid, COLOR_LIGHTBLUE, "Nächster Flughafen: Los Santos Airport");
        }
    }
    return 1;
}

CMD:stopflug(playerid)
{
    if(!(Spieler[playerid][pJob] == 4))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Pilot.");
    KillTimer(pilotwait[playerid]);
    pilotwait[playerid] = INVALID_TIMER_ID;

    UnfreezePlayer(playerid);
    PlayerTextDrawHide(playerid, BusMessage[playerid]);
    DisablePlayerCheckpointEx(playerid);
    SendClientMessage(playerid, COLOR_RED, "Flug abgebrochen!");
    return 1;
}
