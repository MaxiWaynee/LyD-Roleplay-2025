#include <YSI\y_hooks>



CMD:stopbauarbeiter(playerid)
{
    if(!(Spieler[playerid][pJob] == 10))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Bauarbeiter.");
    SendClientMessage(playerid, COLOR_RED, "Du hast die Arbeit abgebrochen.");
    DisablePlayerCheckpointEx(playerid);
    return 1;
}


CMD:startbauarbeiter(playerid)
{
    if(!(Spieler[playerid][pJob] == 10))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Bauarbeiter.");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    for(new i=0;i<sizeof(bauarb);i++)
    {
        new vID = GetPlayerVehicleID(playerid);
        if(vID == bauarb[i])
        {
            SetPlayerCheckpointEx(playerid, 799.1427,836.5533,8.1336, 5.0, CP_BAUARBEITER1);
            SendClientMessage(playerid, COLOR_GREEN, "Du bist nun im Dienst. Fahre die Marker ab und tue was vorgeschrieben wird!");
            Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
            return 1;
        }
    }
    SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Baustellenfahrzeug.");
    return 1;
}


CMD:steineladen(playerid)
{
    if(Spieler[playerid][pJob] == 10)
    if(IsPlayerInRangeOfPoint(playerid, 5.0, 635.8752,862.5970,-42.6892) || IsPlayerInRangeOfPoint(playerid, 5.0, 607.7939,863.4465,-42.0452))
    {
       SendClientMessage(playerid, COLOR_GREEN, "Du hast Steine geladen!");
    }
    return 1;
}

CMD:steineentladen(playerid)
{
    if(Spieler[playerid][pJob] == 10)
    if(IsPlayerInRangeOfPoint(playerid, 5.0, 382.3929,871.6203,21.9523))
    {
       SendClientMessage(playerid, COLOR_GREEN, "Du hast die Steine erfolgreich entladen!");
    }
    return 1;
}

