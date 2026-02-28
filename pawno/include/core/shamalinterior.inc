#include <YSI\y_hooks>

new sExplode[MAX_VEHICLES] = {-1, ...};
new bool:tCount[MAX_VEHICLES];
 
#define S_EXPLODE_X 2.4015
#define S_EXPLODE_Y 29.2775
#define S_EXPLODE_Z 1199.593
#define S_EXPLODE_RANGE 13.4
 
forward ExplodeShamal(vehicleid);
 
GetPlayerShamalID(playerid)
{
    return GetPlayerVirtualWorld(playerid) > cellmax-MAX_VEHICLES ? cellmax-GetPlayerVirtualWorld(playerid)+1 : 0;
}
 
hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if (ispassenger != 0 && GetVehicleModel(vehicleid) == 519)
    {
        if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Da du vor kurzem Schaden genommen hast, kannst du die Shamal nicht betreten.");
        if(Spieler[playerid][pTot] > 0) return SendClientMessage(playerid,COLOR_RED,"Du bist tot.");
        SetPlayerVirtualWorld(playerid, cellmax-(vehicleid-1));
        SetPlayerInterior(playerid, 1);
        SetPlayerPos(playerid, 3.839, 22.977, 1199.601);
        SetPlayerFacingAngle(playerid, 90.0);
        SetCameraBehindPlayer(playerid);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    new vehicleid = GetPlayerShamalID(playerid);
    if (newkeys == 16 && vehicleid != 0)
    {
        if(Spieler[playerid][pTot] > 0) return SendClientMessage(playerid,COLOR_RED,"Du bist tot.");
        new Float:x, Float:y, Float:z, Float:a;
        GetVehiclePos(vehicleid, x, y, z);
        GetVehicleZAngle(vehicleid, a);
        x += (5.0*floatsin(-(a-45.0), degrees));
        y += (5.0*floatcos(-(a-45.0), degrees));
        SetPlayerVirtualWorld(playerid, GetVehicleVirtualWorld(vehicleid));
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, x, y, z-0.94);
        SetPlayerFacingAngle(playerid, a);
    }
    return 1;
}
 
hook OnVehicleDeath(vehicleid, killerid)
{
    if (GetVehicleModel(vehicleid) == 519)
    {
        for (new i = 0; i < MAX_PLAYERS; i++)
        {
            if (GetPlayerShamalID(i) == vehicleid)
            {
                CreateExplosion(S_EXPLODE_X, S_EXPLODE_Y, S_EXPLODE_Z, 2, S_EXPLODE_RANGE);
            }
        }
        if (sExplode[vehicleid-1] != -1)
        {
            KillTimer(sExplode[vehicleid-1]);
        }
        sExplode[vehicleid-1] = SetTimerEx("ExplodeShamal", 700, 0, "d", vehicleid);
        tCount[vehicleid-1] = true;
    }
    return 1;
}
 
hook OnVehicleSpawn(vehicleid)
{
    tCount[vehicleid-1] = false;
    return 1;
}
 
hook ExplodeShamal(vehicleid)
{
    KillTimer(sExplode[vehicleid-1]);
    if (tCount[vehicleid-1])
    {
        for (new i = 0; i < MAX_PLAYERS; i++)
        {
            if (GetPlayerShamalID(i) == vehicleid)
            {
                CreateExplosionForPlayer(i, S_EXPLODE_X, S_EXPLODE_Y, S_EXPLODE_Z, 2, S_EXPLODE_RANGE);
            }
        }
        sExplode[vehicleid-1] = SetTimerEx("ExplodeShamal", random(1300) + 100, 0, "d", vehicleid);
    }
    else
    {
        sExplode[vehicleid-1] = -1;
    }
}