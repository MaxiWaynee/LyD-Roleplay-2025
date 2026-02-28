#include <YSI\y_hooks>

// Global interior define
#define MAPS_PAINTBALLBASEMENT_INTERIOR      1

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

#define PAINTBALLBASEMENT_SPAWN_POINT          2169.4611, 1618.7983, 999.9765
#define PAINTBALLBASEMENT_SPAWN_POINT_FACING   90.0

// Map variables

new pickup_paintballBasement[1];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 1775, 2209.9063, 1607.1953, 1000.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 1776, 2202.4531, 1617.0078, 1000.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 2681, 2206.7266, 1615.7734, 998.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1776, 2209.2422, 1621.2109, 1000.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 1776, 2222.3672, 1602.6406, 1000.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 1775, 2222.2031, 1606.7734, 1000.0547, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, PAINTBALLBASEMENT_SPAWN_POINT)) { // Exit
            ExitPaintballArena(playerid);
        }
    }

    return 1;
}

hook OnGameModeInit() {
    pickup_paintballBasement[0] = CreateDynamicPickup(19197, 1, PAINTBALLBASEMENT_SPAWN_POINT, VW_PAINTBALLBASEMENT, MAPS_PAINTBALLBASEMENT_INTERIOR); // Exit
    // Objects
}

stock ExitPaintballArena(playerid) {
    SetPlayerInterior(playerid, MAPS_PAINTBALLLOBBYINTERIOR_INTERIOR);
    SetPlayerVirtualWorld(playerid, VW_PAINTBALLLOBBY);
    SetPlayerPos(playerid, PAINTBALLLOBBYINTERIOR_SPAWN_POINT1);
    SetPlayerFacingAngle(playerid, PAINTBALLLOBBYINTERIOR_SPAWN_FACING);
    SetCameraBehindPlayer(playerid);
    ResetPlayerWeapons(playerid);
    ReStore_PlayerWeapons(playerid);
    new message[145];
    format(message, sizeof(message), "%s hat die Paintball-Halle verlassen.", GetName(playerid));
    SendPaintballMessage(COLOR_ORANGE, message);
    PlayerIsPaintballing[playerid] = 0;
    for (new i = 0; i < 5; i++) SendDeathMessageToPlayer(playerid, 1001, 1001, 200);
    return 1;
}