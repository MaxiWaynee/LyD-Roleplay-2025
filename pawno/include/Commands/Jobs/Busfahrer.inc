#include <YSI\y_hooks>

CMD:stoplinie(playerid)
{
    if(!(Spieler[playerid][pJob] == 2))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Busfahrer.");
    KillTimer(buswait[playerid]);
    buswait[playerid] = INVALID_TIMER_ID;
    UnfreezePlayer(playerid);
    PlayerTextDrawHide(playerid, BusMessage[playerid]);
    DisablePlayerCheckpointEx(playerid);
    SendClientMessage(playerid, COLOR_RED, "Linie abgebrochen!");
    return 1;
}

CMD:startlinie(playerid)
{
    if(!(Spieler[playerid][pJob] == 2))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Busfahrer.");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    if(!(GetPlayerState(playerid) == PLAYER_STATE_DRIVER))return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Bus!");
    for(new i=0;i<sizeof(vehicle_busStation);i++)
    {
        new vID = GetPlayerVehicleID(playerid);
        if(vID == vehicle_busStation[i])
        {
            ShowPlayerDialog(playerid, DIALOG_LINIE, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Busfahrer Linien Auswahl", "Linie 1\nLinie 2\nLinie 3\nLinie 4\nSchienenersatzverkehr", "Starten", "Abbrechen");

            return 1;
        }
    }
    return 1;
}