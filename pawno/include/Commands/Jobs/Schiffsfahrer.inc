#include <YSI\y_hooks>



CMD:startschiff(playerid)
{
    if(!(Spieler[playerid][pJob] == 11))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Schiffs-Fahrer.");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    for(new i=0;i<sizeof(vehicle_boatCargoJob);i++)
    {
        new vID = GetPlayerVehicleID(playerid);
        if(vID == vehicle_boatCargoJob[i])
        {
            ShowPlayerDialog(playerid,DIALOG_SCHIFF,DIALOG_STYLE_LIST,COLOR_HEX_ORANGE"Schiffs-Fahrer",COLOR_HEX_WHITE"Fracht liefern\nFische fangen","Bestätigen","Abbrechen");
            return 1;
        }
    }
    SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Schiff.");
    return 1;
}


CMD:stopschiff(playerid)
{
    if(!(Spieler[playerid][pJob] == 11))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Schiffs-Fahrer.");
    SendClientMessage(playerid, COLOR_RED, "Du hast die Arbeit abgebrochen.");
    DisablePlayerCheckpointEx(playerid);
    return 1;
}


