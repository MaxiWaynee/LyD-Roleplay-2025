#include <YSI\y_hooks>


CMD:autoknacken(playerid,params[]) {
    if(Spieler[playerid][pJob] != 22 ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Autoknacker");
        return 1;
    }
    new
        vehicleid;
    vehicleid = GetClosestVehicle(playerid,4.0);
    if( vehicleid == INVALID_VEHICLE_ID ) {
        SendClientMessage(playerid, COLOR_RED, "Du befindest dich in direkter Nähe zu einem Fahrzeug");
        return 1;
    }
    if( Spieler[playerid][pAutoknackerVehicleID] != INVALID_VEHICLE_ID ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist bereits am knacken eines Autos oder hast gerade eines geknackt.");
        return 1;
    }
    new
        Float:X,
        Float:Y,
        Float:Z,
        String[128];
    GetPlayerPos(playerid,X,Y,Z);
    format(String,sizeof(String),"%s versucht ein Fahrzeug aufzubrechen",GetName(playerid));
    SendRoundMessage( X,Y,Z , COLOR_LIGHTRED2, String);

    Spieler[playerid][pAutoknackerVehicleID] = vehicleid;
    Spieler[playerid][tAutoknacken] = SetTimerEx("pulse_Autoknacken",1046,true,"dd",playerid,vehicleid);
    Spieler[playerid][punixAutoknacken] = gettime() + 10;
    return 1;
}



