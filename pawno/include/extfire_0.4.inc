#include <a_samp>

#define VERSION "0.4"

#define MAX_FLAMES 4000						// maxmimal flames
#define BurnOthers							// Should other players burn, too, if they are touching a burning player?
//#define EarnMoney							// Do you want to earn money for extinguish a fire?
//#define FireMessageColor 0x00FF55FF			// color used for the extinguish-message
//#define German								// German or English?
//#define MessageToAll						// Should the extinguish-message be sent to all players?

#define FLAME_ZONE 					1.2     // radius in which you start burning if you're too close to a flame
#define ONFOOT_RADIUS				1.6		// radius in which you can extinguish the flames by foot
#define PISSING_WAY					2.0		// radius in which you can extinguish the flames by peeing
#define CAR_RADIUS					8.5		// radius in which you can extinguish the flames by firetruck/SWAT Van
#define Z_DIFFERENCE				2.7		// height which is important for the accurancy of extinguishing. please do not change
#define EXTINGUISH_TIME_VEHICLE		3		// time you have to spray at the fire with a firetruck (seconds)
#define EXTINGUISH_TIME_ONFOOT		7		// time you have to spray at the fire onfoot (seconds)
#define EXTINGUISH_TIME_PEEING		17		// time you have to pee at the fire (seconds)
#define EXTINGUISH_TIME_PLAYER		3		// time it takes to extinguish a player (seconds)
#define FIRE_OBJECT_SLOT			3		// the slot used with SetPlayerAttachedObject and RemovePlayerAttachedObject

#if !defined SPECIAL_ACTION_PISSING
	#define SPECIAL_ACTION_PISSING 68
#endif

//===================== forwards ====================

forward AddFire(Float:x, Float:y, Float:z);
forward KillFire(id);
forward AddSmoke(Float:x, Float:y, Float:z);
forward KillSmoke(id);
forward DestroyTheSmokeFromFlame(id);
forward OnFireUpdate();
forward FireTimer(playerid, id);
forward SetPlayerBurn(playerid);
forward BurningTimer(playerid);
forward StopPlayerBurning(playerid);

//===================== Variables ====================

enum FlameInfo
{
	Flame_id,
	Flame_Exists,
	Float:Flame_pos[3],
	Smoke[5],
}

new Flame[MAX_FLAMES][FlameInfo];
new ExtTimer[MAX_PLAYERS];
new PlayerOnFire[MAX_PLAYERS];
new PlayerOnFireTimer[MAX_PLAYERS];
new PlayerOnFireTimer2[MAX_PLAYERS];
new Float:PlayerOnFireHP[MAX_PLAYERS];

//===================== Normal Publics ====================

stock ExtFire_Init() {
	SetTimer("OnFireUpdate", 521, 1);
	for(new i; i < MAX_PLAYERS; i++)
	{
	    ExtTimer[i] = -1;
	}
	return 1;
}

stock ExtFire_Close()
{
	for(new i; i < MAX_FLAMES; i++)
	{
	    KillFire(i);
	}
	for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		if(PlayerOnFire[playerid] && !CanPlayerBurn(playerid, 1))
		{
			StopPlayerBurning(playerid);
		}
	}
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	return 0;
}

public OnFireUpdate()
{
	new aim;
	for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
        aim = -1;
	    if(!IsPlayerConnected(playerid) || IsPlayerNPC(playerid)) {
			continue;
		}
		if(PlayerOnFire[playerid] && !CanPlayerBurn(playerid, 1))
		{
			StopPlayerBurning(playerid);
		}
        if(Spieler[playerid][pFraktion] != 3 ) { // Kein Feuerwehrmann
            continue;
		}
		if( /* Pissing_at_Flame(playerid) != -1 || */ Aiming_at_Flame(playerid) != -1)
		{
			// piss = Pissing_at_Flame(playerid);
			aim = Aiming_at_Flame(playerid);
			if(ExtTimer[playerid] == -1 && ((aim != -1 && Pressing(playerid) & KEY_FIRE)) )
			{
			    new value, time, Float:x, Float:y, Float:z;
				if(aim != -1)
				{
					value = aim;
					if(GetPlayerWeapon(playerid) == 41)
					{
						CreateExplosion(Flame[value][Flame_pos][0], Flame[value][Flame_pos][1], Flame[value][Flame_pos][2], 2, 5);
						continue;
					}
					if(IsPlayerInAnyVehicle(playerid))
					{
					    time = EXTINGUISH_TIME_VEHICLE;
					}
					else
					{
						time = EXTINGUISH_TIME_ONFOOT;
					}
				}
				if(value < -1) { time = EXTINGUISH_TIME_PLAYER; }
				time *= 1000;
				if(value >= -1)
				{
					x = Flame[value][Flame_pos][0];
				    y = Flame[value][Flame_pos][1];
				    z = Flame[value][Flame_pos][2];
				    DestroyTheSmokeFromFlame(value);
					Flame[value][Smoke][0] = CreateDynamicObject(18727, x, y, z, 0.0, 0.0, 0.0);
					Flame[value][Smoke][1] = CreateDynamicObject(18727, x+1, y, z, 0.0, 0.0, 0.0);
					Flame[value][Smoke][2] = CreateDynamicObject(18727, x-1, y, z, 0.0, 0.0, 0.0);
					Flame[value][Smoke][3] = CreateDynamicObject(18727, x, y+1, z, 0.0, 0.0, 0.0);
					Flame[value][Smoke][4] = CreateDynamicObject(18727, x, y-1, z, 0.0, 0.0, 0.0);
					SetTimerEx("DestroyTheSmokeFromFlame", time, 0, "d", value);
				}
				ExtTimer[playerid] = SetTimerEx("FireTimer", time, 0, "dd", playerid, value);
			}
		}
		if(CanPlayerBurn(playerid) && IsAtFlame(playerid))
		{
			SetPlayerBurn(playerid);
		}
		#if defined BurnOthers
		new Float:x, Float:y, Float:z;
		for(new i; i < MAX_PLAYERS; i++)
	  	{
	  	    if(playerid != i && IsPlayerConnected(i) && !IsPlayerNPC(i))
		  	{
			  	if(CanPlayerBurn(i) && PlayerOnFire[playerid] && !PlayerOnFire[i])
	  	    	{
				  	GetPlayerPos(i, x, y, z);
					if(IsPlayerInRangeOfPoint(playerid, 1, x, y, z))
					{
					    SetPlayerBurn(i);
					}
				}
			}
		}
		#endif
 	}
	return 1;
}


//===================== stocks ====================

stock GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, &Float:z, &Float:a, Float:distance)
{
	GetPlayerPos(playerid, x, y ,z);
	if(IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleZAngle(GetPlayerVehicleID(playerid),a);
	}
	else
	{
		GetPlayerFacingAngle(playerid, a);
	}
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
	return 0;
}


stock Float:GetDistanceBetweenPoints(Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2) //By Gabriel "Larcius" Cordes
{
	return floatadd(floatadd(floatsqroot(floatpower(floatsub(x1,x2),2)),floatsqroot(floatpower(floatsub(y1,y2),2))),floatsqroot(floatpower(floatsub(z1,z2),2)));
}

stock Float:DistanceCameraTargetToLocation(Float:CamX, Float:CamY, Float:CamZ, Float:ObjX, Float:ObjY, Float:ObjZ, Float:FrX, Float:FrY, Float:FrZ)
{
	new Float:TGTDistance;

	// get distance from camera to target
	TGTDistance = floatsqroot((CamX - ObjX) * (CamX - ObjX) + (CamY - ObjY) * (CamY - ObjY) + (CamZ - ObjZ) * (CamZ - ObjZ));

	new Float:tmpX, Float:tmpY, Float:tmpZ;

	tmpX = FrX * TGTDistance + CamX;
	tmpY = FrY * TGTDistance + CamY;
	tmpZ = FrZ * TGTDistance + CamZ;

	return floatsqroot((tmpX - ObjX) * (tmpX - ObjX) + (tmpY - ObjY) * (tmpY - ObjY) + (tmpZ - ObjZ) * (tmpZ - ObjZ));
}

stock IsPlayerAimingAt(playerid, Float:x, Float:y, Float:z, Float:radius)
{
	new Float:cx,Float:cy,Float:cz,Float:fx,Float:fy,Float:fz;
	GetPlayerCameraPos(playerid, cx, cy, cz);
	GetPlayerCameraFrontVector(playerid, fx, fy, fz);
	return (radius >= DistanceCameraTargetToLocation(cx, cy, cz, x, y, z, fx, fy, fz));
}

//===================== Own Publics ====================

public AddFire(Float:x, Float:y, Float:z)
{
	new slot = GetFlameSlot();
	new bool:msgbool;
	new string[128];
	if(slot == -1) {
		return slot;
	}
	Flame[slot][Flame_Exists] = 1;
	Flame[slot][Flame_pos][0] = x;
	Flame[slot][Flame_pos][1] = y;
	Flame[slot][Flame_pos][2] = z - Z_DIFFERENCE;
	Flame[slot][Flame_id] = CreateDynamicObject(18689, Flame[slot][Flame_pos][0], Flame[slot][Flame_pos][1], Flame[slot][Flame_pos][2], 0.0, 0.0, 0.0);
	if(msgbool == true)
	{
		if((x > -992.5172 && x < 4000.0000) && (y < 528.0000 && y > -4000.0000)) //Los Santos
		{
	    	format(string,sizeof(string),"Ein neues Feuer in Los Santos!");
		}
		if((x > -4000.0000 && x< -992.5172) && (y < 4000.0000 && y > -4000.0000)) //San Fierro
		{
			format(string,sizeof(string),"Ein neues Feuer in San Fierro!");
		}
		if((x > -992.5172 && x< 4000.0000) && (y < 4000.0000 && y > 528.0000)) //Las Venturas
		{
	    	format(string,sizeof(string),"Ein neues Feuer in Las Venturas!");
		}
	}
    for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(Spieler[i][pFraktion] == 3)
			{
				if(Spieler[i][pDuty] != 0)
				{
					if(msgbool == true)
					{
						SendClientMessage(i,COLOR_BLUE,string);
					}
			    }
			}
		}
	}
	return slot;
}

public KillFire(id)
{
	if( !( 0 <= id < sizeof(Flame) ) ) return 0;
 	DestroyDynamicObject(Flame[id][Flame_id]);
	Flame[id][Flame_Exists] = 0;
	Flame[id][Flame_pos][0] = 0.0;
	Flame[id][Flame_pos][1] = 0.0;
	Flame[id][Flame_pos][2] = 0.0;
	Flame[id][Flame_id] = INVALID_OBJECT_ID;
	DestroyTheSmokeFromFlame(id);
	flammenupdate(id);
	return -1;
}

//# A suggestion from a user of this script. Very simple functions to add and remove smoke without flames.
//# Think about a way to kill the smoke and use it, if you wish.
//# Maybe you could link smoke on a house with variables to a flame inside a house so if the flame gets extinguished the smoke disappears.

public AddSmoke(Float:x, Float:y, Float:z)
{
	return CreateDynamicObject(18727, x, y, z, 0.0, 0.0, 0.0);
}

public KillSmoke(id)
{
 	DestroyDynamicObject(id);
}

// Destroys extinguishing-smoke
public DestroyTheSmokeFromFlame(id)
{
    for(new i; i < 5; i++) {
		DestroyDynamicObject(Flame[id][Smoke][i]);
        Flame[id][Smoke][i] = INVALID_OBJECT_ID;
	}
}

public FireTimer(playerid,id)
{
	if(id < -1 && Aiming_at_Flame(playerid) == id) { StopPlayerBurning(id+MAX_PLAYERS); }
	else if(id < -1 && Pissing_at_Flame(playerid) == id) { StopPlayerBurning(id+MAX_PLAYERS); }
	else if(Flame[id][Flame_Exists] && ((Pressing(playerid) & KEY_FIRE && Aiming_at_Flame(playerid) == id) || (Pissing_at_Flame(playerid) == id)))
	{
		SendClientMessage(playerid,COLOR_GREEN,"Du hast eine Flamme gelöscht! $+250");
		GivePlayerCash(playerid, 250);
	 	KillFire(id);
	}
	KillTimer(ExtTimer[playerid]);
	ExtTimer[playerid] = -1;
}

public SetPlayerBurn(playerid)
{
    SetPlayerAttachedObject(playerid, FIRE_OBJECT_SLOT, 18690, 2, -1, 0, -1.9, 0, 0);
	PlayerOnFire[playerid] = 1;
	GetPlayerHealth(playerid, PlayerOnFireHP[playerid]);
	KillTimer(PlayerOnFireTimer[playerid]); KillTimer(PlayerOnFireTimer2[playerid]);
	PlayerOnFireTimer[playerid] = SetTimerEx("BurningTimer", 137, 1, "d", playerid);
	PlayerOnFireTimer2[playerid] = SetTimerEx("StopPlayerBurning", 6521, 0, "d", playerid);
	return 1;
}

public BurningTimer(playerid)
{
	if(PlayerOnFire[playerid])
	{
	    new Float:hp;
	    GetPlayerHealth(playerid, hp);
	    if(hp < PlayerOnFireHP[playerid])
	    {
	        PlayerOnFireHP[playerid] = hp;
		}
		hp = Float:(PlayerOnFireHP[playerid] - 1.0);
		if( hp < 1.0 ) { // Nicht sterben lassen bei Brennen...Zerstï¿½rt GM
		    hp = 1.0;
		}
		SetPlayerHealth(playerid,hp);
		// CallRemoteFunction("SetPlayerHealth", "dd", playerid, PlayerOnFireHP[playerid]-1.0);
	    PlayerOnFireHP[playerid] -= 1.0;
	}
	else {
		KillTimer(PlayerOnFireTimer[playerid]);
		KillTimer(PlayerOnFireTimer2[playerid]);
	}
}

public StopPlayerBurning(playerid)
{
	KillTimer(PlayerOnFireTimer[playerid]);
	PlayerOnFire[playerid] = 0;
	RemovePlayerAttachedObject(playerid, FIRE_OBJECT_SLOT);
}

//===================== Other Functions ====================

stock GetFireID(Float:x, Float:y, Float:z, &Float:dist)
{
	new id = -1;
	dist = 99999.99;
	for(new i; i < MAX_FLAMES; i++)
	{
	    if(GetDistanceBetweenPoints(x,y,z,Flame[i][Flame_pos][0],Flame[i][Flame_pos][1],Flame[i][Flame_pos][2]) < dist)
	    {
	        dist = GetDistanceBetweenPoints(x,y,z,Flame[i][Flame_pos][0],Flame[i][Flame_pos][1],Flame[i][Flame_pos][2]);
	        id = i;
		}
	}
	return id;
}

stock CanPlayerBurn(playerid, val = 0)
{
	if(CallRemoteFunction("CanBurn", "d", playerid) >= 0 && !IsPlayerInWater(playerid) && GetPlayerSkin(playerid) != 277 && GetPlayerSkin(playerid) != 278 && GetPlayerSkin(playerid) != 279 && ((!val && !PlayerOnFire[playerid]) || (val && PlayerOnFire[playerid]))) { return 1; }
	return 0;
}

/* //Uncomment or copy to your script.

forward CanBurn(playerid);
public CanBurn(playerid)
{
	if(...)
	{
		return 1;
	}
	return -1; // IMPORTANT!
}

*/

stock IsPlayerInWater(playerid)
{
	new Float:X, Float:Y, Float:Z, an = GetPlayerAnimationIndex(playerid);
	GetPlayerPos(playerid, X, Y, Z);
	if((1544 >= an >= 1538 || an == 1062 || an == 1250) && (Z <= 0 || (Z <= 41.0 && IsPlayerInArea(playerid, -1387, -473, 2025, 2824))) ||
	(1544 >= an >= 1538 || an == 1062 || an == 1250) && (Z <= 2 || (Z <= 39.0 && IsPlayerInArea(playerid, -1387, -473, 2025, 2824))))
	{
	    return 1;
 	}
 	return 0;
}

stock IsPlayerInArea(playerid, Float:MinX, Float:MaxX, Float:MinY, Float:MaxY)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	#pragma unused z
    if(x >= MinX && x <= MaxX && y >= MinY && y <= MaxY) { return 1; }
    return 0;
}

stock GetFlameSlot()
{
	for(new i = 0; i < MAX_FLAMES; i++)
	{
		if(!Flame[i][Flame_Exists]) { return i; }
	}
	return -1;
}

//===================== "Callbacks" ====================

stock IsAtFlame(playerid)
{
	for(new i; i < MAX_FLAMES; i++)
	{
	    
	    if(Flame[i][Flame_Exists])
		{
		    if(!IsPlayerInAnyVehicle(playerid) && (IsPlayerInRangeOfPoint(playerid, FLAME_ZONE, Flame[i][Flame_pos][0], Flame[i][Flame_pos][1], Flame[i][Flame_pos][2]+Z_DIFFERENCE) ||
												   IsPlayerInRangeOfPoint(playerid, FLAME_ZONE, Flame[i][Flame_pos][0], Flame[i][Flame_pos][1], Flame[i][Flame_pos][2]+Z_DIFFERENCE-1)))
		    {
				return 1;
			}
		}
	}
	return 0;
}

new AaF_cache[MAX_PLAYERS] = { -1, ... };
new AaF_cacheTime[MAX_PLAYERS];

stock Aiming_at_Flame(playerid)
{
	if(gettime() - AaF_cacheTime[playerid] < 1)
  	{
  	    return AaF_cache[playerid];
 	}
 	AaF_cacheTime[playerid] = gettime();
 	
	new id = -1;
	new Float:dis = 99999.99;
	new Float:dis2;
	new Float:px, Float:py, Float:pz;
	new Float:x, Float:y, Float:z, Float:a;
	GetXYInFrontOfPlayer(playerid, x, y, z, a, 1);
	z -= Z_DIFFERENCE;
	
	new Float:cx,Float:cy,Float:cz,Float:fx,Float:fy,Float:fz;
	GetPlayerCameraPos(playerid, cx, cy, cz);
	GetPlayerCameraFrontVector(playerid, fx, fy, fz);
	
	for(new i; i < MAX_PLAYERS; i++)
	{
	    if(IsPlayerConnected(i) && PlayerOnFire[i] && (IsInWaterCar(playerid) || HasExtinguisher(playerid) || GetPlayerWeapon(playerid) == 41 || Peeing(playerid)) && PlayerOnFire[i])
	    {
	        GetPlayerPos(i, px, py, pz);
	        if(!Peeing(playerid))
		 	{
	        	dis2 = DistanceCameraTargetToLocation(cx, cy, cz, px, py, pz, fx, fy, fz);
 			}
 			else
 			{
 			    if(IsPlayerInRangeOfPoint(playerid, ONFOOT_RADIUS, px, py, pz))
				{
	        		dis2 = 0.0;
				}
 			}
	        if(dis2 < dis)
	        {
				dis = dis2;
	    		id = i;
	    		if(Peeing(playerid))
	    		{
	    		    return id;
				}
			}
		}
	}
	if(id != -1) { return id-MAX_PLAYERS; }
	for(new i; i < MAX_FLAMES; i++)
	{
		if(Flame[i][Flame_Exists])
		{
		    if(IsInWaterCar(playerid) || HasExtinguisher(playerid) || GetPlayerWeapon(playerid) == 41 || Peeing(playerid))
		    {
		        if(!Peeing(playerid))
				{
					dis2 = DistanceCameraTargetToLocation(cx, cy, cz, Flame[i][Flame_pos][0], Flame[i][Flame_pos][1], Flame[i][Flame_pos][2]+Z_DIFFERENCE, fx, fy, fz);
				}
				else
				{
				    dis2 = GetDistanceBetweenPoints(x,y,z,Flame[i][Flame_pos][0],Flame[i][Flame_pos][1],Flame[i][Flame_pos][2]);
				}
				if((IsPlayerInAnyVehicle(playerid) && dis2 < CAR_RADIUS && dis2 < dis) || (!IsPlayerInAnyVehicle(playerid) && ((dis2 < ONFOOT_RADIUS && dis2 < dis) || (Peeing(playerid) && dis2 < PISSING_WAY && dis2 < dis))))
				{
				    dis = dis2;
				    id = i;
				}
			}
		}
	}
	if(id != -1)
	{
		if
		(
			(
				IsPlayerInAnyVehicle(playerid) && !IsPlayerInRangeOfPoint(playerid, 50, Flame[id][Flame_pos][0], Flame[id][Flame_pos][1], Flame[id][Flame_pos][2])
			)
			||
			(
				!IsPlayerInAnyVehicle(playerid)  && !IsPlayerInRangeOfPoint(playerid, 5, Flame[id][Flame_pos][0], Flame[id][Flame_pos][1], Flame[id][Flame_pos][2])
			)
		)
		{ id = -1; }
	}
	AaF_cache[playerid] = id;
	return id;
}

stock Pissing_at_Flame(playerid)
{
	if(Peeing(playerid))
	{
	    new string[64];
	    return strval(string);
	}
	return -1;
}

stock IsInWaterCar(playerid)
{
    if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 407 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 601) { return 1; }
	return 0;
}

stock HasExtinguisher(playerid)
{
    if(GetPlayerWeapon(playerid) == 42 && !IsPlayerInAnyVehicle(playerid)) { return 1; }
	return 0;
}

stock Peeing(playerid)
{
	return GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_PISSING;
}

stock Pressing(playerid)
{
	new keys, updown, leftright;
	GetPlayerKeys(playerid, keys, updown, leftright);
	return keys;
}

//===================== Important Shit ====================

forward MMF_ExtFire(version[15]);
public MMF_ExtFire(version[15])
{
	if(strcmp(VERSION, version, true) && strlen(version))
	{
	    return 2;
	}
	return 1;
}


