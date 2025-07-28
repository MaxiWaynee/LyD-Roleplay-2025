#include <YSI\y_hooks>


CMD:stopmuell(playerid)
{
    if(!(Spieler[playerid][pJob] == 8))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Müllmann.");
    SendClientMessage(playerid, COLOR_RED, "Du hast die Arbeit abgebrochen.");
    DisablePlayerCheckpointEx(playerid);
    return 1;
}

CMD:startmuell(playerid)
{
    if(!(Spieler[playerid][pJob] == 8))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Müllmann.");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    new
        vehicleid = GetPlayerVehicleID(playerid);
    if( !(aiVehicles[ vehicleid ] & VEH_MUELL) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Müllwagen.");
    }
    Spieler[playerid][pMuell][0] = 0;
    Spieler[playerid][pMuell][1] = 0;
    ShowNextMuellStation(playerid);
    SendClientMessage(playerid, COLOR_GREEN, "Du bist nun im Dienst. Fahre die Marker ab und tue was vorgeschrieben wird!");
    Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    /*
    for(new i=0;i<sizeof(muell);i++)
    {
        new vID = GetPlayerVehicleID(playerid);
        if(vID == muell[i])
        {
            SetPlayerCheckpointEx(playerid, 1998.7909,-2107.2979,13.3496, 5.0, CP_MUELL1);
            SendClientMessage(playerid, COLOR_GREEN, "Du bist nun im Dienst. Fahre die Marker ab und tue was vorgeschrieben wird!");
            return 1;
        }
    }*/
    return 1;
}


CMD:entleeren(playerid,params[]) {
    if(!(Spieler[playerid][pJob] == 8))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Müllmann.");
    if( !(pCheckpoint[playerid] == CP_MUELL_ENTLEEREN) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst jetzt nicht entleeren machen.");
    new
        cp = Spieler[playerid][pMuellCP];
    if( !IsPlayerInRangeOfPoint(playerid,3.0,g_Muell[cp][M_fPosX],g_Muell[cp][M_fPosY],g_Muell[cp][M_fPosZ])) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht an der Mülltonne.");
    }
    if( IsPlayerInAnyVehicle(playerid) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du sitzt in einem Fahrzeug!");
    }
    new
        vehicleid = JobVehicle[playerid],
        Float:x,
        Float:y,
        Float:z,
        Float:face;
    GetVehiclePos(vehicleid,x,y,z);
    GetVehicleZAngle(vehicleid,face);
    SetPlayerSpecialAction(playerid,SPECIAL_ACTION_CARRY);
    GetXYInFrontOfPosition(x, y, face, -4.25 );
    SetPlayerAttachedObject( playerid, 0, 1265, 5, 0.150000, 0.300000, 0.000000, 270.000000, 0.000000, 0.000000, 0.800000, 0.800000, 0.800000 ); // BlackBag2 - trashblabla
    SetPlayerCheckpointEx(playerid,x,y,z,2.0,CP_MUELL_CARRY);
    return 1;
}


