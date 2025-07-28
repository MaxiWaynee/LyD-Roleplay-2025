#include <YSI\y_hooks>

// Global interior define
#define MAPS_LSPDEXTERIOR_INTERIOR      0
#define MAPS_LSPDINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// LSPD interior points
#define LSPD_INTERIOR_SPAWN_POINT               1639.5917, -1387.0795, 1962.5164
#define LSPD_INTERIOR_SPAWN_POINT_FACING        270.0
#define LSPD_INTERIOR_DUTY_POINT                1639.1198, -1381.8534, 1962.5164
#define LSPD_INTERIOR_DUTY_ROOM_DOOR_POINT      1644.0115, -1380.5968, 1962.6067
#define LSPD_INTERIOR_DUTY_ROOM_DOOR_OPEN_X     1641.9896
#define LSPD_INTERIOR_DUTY_ROOM_DOOR_CLOSED_X   1643.2508
#define LSPD_INTERIOR_LAWYER_SKIN_POINT         1642.0588, -1359.2144, 1962.5068
#define LSPD_INTERIOR_WANTED_TICKET_POINT       1630.1555, -1371.1027, 1962.5068
#define LSPD_INTERIOR_ERGEBEN_POINT				1633.0670, -1370.9982, 1962.5068

// Map variables
new object_lspdInterior[538];
new pickup_lspdInterior[5];
new text3D_lspdInterior[3];
new actor_lspdInterior[7];
new object_duty_door_lspdInterior;
new lspdInterior_pIDControllingDoor = INVALID_PLAYER_ID;

new const Float:lspdInterior_jailSpawnPoints[][] = {
    { 1656.9424, -1372.0476, 1962.5168 },
    { 1656.9424, -1373.8616, 1962.5168 },
    { 1656.9424, -1374.9132, 1962.5168 },
    { 1656.9424, -1376.6982, 1962.5168 }
};

forward lspdInterior_closeDutyDoor();
public lspdInterior_closeDutyDoor() {
    if (!IsPlayerInRangeOfPoint(lspdInterior_pIDControllingDoor, 2.5, LSPD_INTERIOR_DUTY_ROOM_DOOR_POINT)) {
        lspdInterior_pIDControllingDoor = INVALID_PLAYER_ID;

        new Float:fX, Float:fY, Float:fZ;
        GetDynamicObjectPos(object_duty_door_lspdInterior, fX, fY, fZ);
        MoveDynamicObject(object_duty_door_lspdInterior, LSPD_INTERIOR_DUTY_ROOM_DOOR_CLOSED_X, fY, fZ, 1.0);

        for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) {
            if (GetPlayerVirtualWorld(i) == VW_LSPDINTERIOR) {
                SetPVarInt(i, "LSPD_hasDutyDoorSound", 1);
                PlayerPlaySound(i, 1035, LSPD_INTERIOR_DUTY_ROOM_DOOR_POINT); // start opening door sound
            }
        }
    } else
        SetTimer("lspdInterior_closeDutyDoor", 2500, false);
    
    return 1;
}

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnDynamicObjectMoved(objectid) {
    if (objectid == object_duty_door_lspdInterior) {
        for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) {
            if (GetPVarInt(i, "LSPD_hasDutyDoorSound") == 1) {
                SetPVarInt(i, "LSPD_hasDutyDoorSound", 0);
                PlayerPlaySound(i, 1036, LSPD_INTERIOR_DUTY_ROOM_DOOR_POINT); // stop sound
            }
        }
    }
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if (newkeys & KEY_SECONDARY_ATTACK) 
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, LSPD_INTERIOR_HELI_STAIRS_POINT)) 
        { // Helicopter Stairway
            if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18))
                return SendClientMessage(playerid, COLOR_RED, "Du besitzt keine gültige Schlüsselkarte für das LSPD-Gebäude.");
            
            SetPlayerFacingAngle(playerid, LSPD_HELI_STAIRS_POINT_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, LSPD_HELI_STAIRS_POINT, MAPS_LSPDEXTERIOR_INTERIOR, VW_MAIN);
            return 1;
        } 
        else if (IsPlayerInRangeOfPoint(playerid, 1.5, LSPD_INTERIOR_GARAGE_POINT)) 
        { // Garage Door
            SetPlayerFacingAngle(playerid, LSPD_GARAGE_POINT_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, LSPD_GARAGE_POINT, MAPS_LSPDEXTERIOR_INTERIOR, VW_MAIN);
            return 1;
        } 
        else if (IsPlayerInRangeOfPoint(playerid, 1.5, LSPD_INTERIOR_DUTY_ROOM_DOOR_POINT)) 
        { // Duty Room Door
            if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18))
                return PlayerPlaySound(playerid, 1085, LSPD_INTERIOR_DUTY_ROOM_DOOR_POINT);
            
            new Float:fX, Float:fY, Float:fZ;
            GetDynamicObjectPos(object_duty_door_lspdInterior, fX, fY, fZ);

            if (fX != LSPD_INTERIOR_DUTY_ROOM_DOOR_OPEN_X && (lspdInterior_pIDControllingDoor == playerid || lspdInterior_pIDControllingDoor == INVALID_PLAYER_ID))
                MoveDynamicObject(object_duty_door_lspdInterior, LSPD_INTERIOR_DUTY_ROOM_DOOR_OPEN_X, fY, fZ, 1.0);
            else
                return PlayerPlaySound(playerid, 1085, LSPD_INTERIOR_DUTY_ROOM_DOOR_POINT);

            lspdInterior_pIDControllingDoor = playerid;

            for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) 
            {
                if (GetPlayerVirtualWorld(i) == VW_LSPDINTERIOR) 
                {
                    SetPVarInt(i, "LSPD_hasDutyDoorSound", 1);
                    PlayerPlaySound(i, 1035, LSPD_INTERIOR_DUTY_ROOM_DOOR_POINT); // start opening door sound
                }
            }
            SetTimer("lspdInterior_closeDutyDoor", 2500, false);
            return 1;
        }
    }
    return 1;
}

hook OnGameModeInit() {
    // Pickups
    pickup_lspdInterior[0] = CreateDynamicPickup(19197, 1, LSPD_INTERIOR_HELI_STAIRS_POINT, VW_LSPDINTERIOR, MAPS_LSPDEXTERIOR_INTERIOR); // Helicopter Stairway
    pickup_lspdInterior[1] = CreateDynamicPickup(1275, 1, LSPD_INTERIOR_LAWYER_SKIN_POINT, VW_LSPDINTERIOR, MAPS_LSPDEXTERIOR_INTERIOR); // Lawyer Skin Point
    pickup_lspdInterior[2] = CreateDynamicPickup(1239, 1, LSPD_INTERIOR_WANTED_TICKET_POINT, VW_LSPDINTERIOR, MAPS_LSPDEXTERIOR_INTERIOR); // Wanted Ticket Point
    pickup_lspdInterior[3] = CreateDynamicPickup(19197, 1, LSPD_INTERIOR_GARAGE_POINT, VW_LSPDINTERIOR, MAPS_LSPDEXTERIOR_INTERIOR); // Garage Point
	pickup_lspdInterior[4] = CreateDynamicPickup(1247, 1, LSPD_INTERIOR_ERGEBEN_POINT, VW_LSPDINTERIOR, MAPS_LSPDEXTERIOR_INTERIOR); // Ergeben Point

    // 3DTextLabels
    text3D_lspdInterior[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Anwälte\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, LSPD_INTERIOR_LAWYER_SKIN_POINT, 25.0, .testlos = 1, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // Lawyer Skin Point
    text3D_lspdInterior[1] = _:CreateDynamic3DTextLabel("1-3 Wanteds freikaufen\n" COLOR_HEX_WHITE "Tippe /Wantedticket", COLOR_BLUE, LSPD_INTERIOR_WANTED_TICKET_POINT, 25.0, .testlos = 1, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // Wanted Ticket Point
	text3D_lspdInterior[2] = _:CreateDynamic3DTextLabel("Für Gesuchte Straftäter, um sich zu stellen\n" COLOR_HEX_WHITE "Tippe /Ergeben", COLOR_BLUE, LSPD_INTERIOR_ERGEBEN_POINT, 25.0, .testlos = 1, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // Wanted Ticket Point
	
   // Actors
    actor_lspdInterior[0] = CreateDynamicActor(301, 1640.9191, -1365.2317, 1962.5068, 180.0000, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // 
    ApplyDynamicActorAnimation(actor_lspdInterior[0], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_lspdInterior[1] = CreateDynamicActor(309, 1630.3597, -1368.3477, 1962.5068, 180.0000, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // 
    ApplyDynamicActorAnimation(actor_lspdInterior[1], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_lspdInterior[2] = CreateDynamicActor(281, 1633.1843, -1368.3740, 1962.5068, 180.0000, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // 
    ApplyDynamicActorAnimation(actor_lspdInterior[2], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_lspdInterior[3] = CreateDynamicActor(280, 1645.4669, -1374.7523, 1962.5068, 45.0000, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // 
    ApplyDynamicActorAnimation(actor_lspdInterior[3], "COP_AMBIENT", "Coplook_loop", 4.0, 1, 0, 0, 0, 0);
    actor_lspdInterior[4] = CreateDynamicActor(280, 1653.4335, -1374.9639, 1962.4168, 180.0000, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // Cop taking mug shot
    ApplyDynamicActorAnimation(actor_lspdInterior[4], "CAMERA", "picstnd_take", 4.0, 1, 0, 0, 0, 0);
    actor_lspdInterior[5] = CreateDynamicActor(0, 1653.5098, -1377.3226, 1962.5168, 0.0000, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // CJ getting mug shot taken
    actor_lspdInterior[6] = CreateDynamicActor(31, 1625.1361, -1384.8080, 1962.4068, 0.0000, .worldid = VW_LSPDINTERIOR, .interiorid = MAPS_LSPDINTERIOR_INTERIOR); // Old woman waiting
    ApplyDynamicActorAnimation(actor_lspdInterior[6], "MISC", "SEAT_LR", 4.0, 1, 0, 0, 0, 0);

    // Objects
    object_lspdInterior[0] = CreateDynamicObject(18981, 1631.1151, -1348.8780, 1961.0068, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[0], 0, 14853, "gen_pol_vegas", "blue_carpet_256", 0xFFFFFFFF);
    object_lspdInterior[1] = CreateDynamicObject(18981, 1656.0627, -1348.8780, 1961.0068, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[1], 0, 14853, "gen_pol_vegas", "blue_carpet_256", 0xFFFFFFFF);
    object_lspdInterior[2] = CreateDynamicObject(18981, 1656.0627, -1373.7082, 1961.0068, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[2], 0, 14853, "gen_pol_vegas", "blue_carpet_256", 0xFFFFFFFF);
    object_lspdInterior[3] = CreateDynamicObject(18981, 1631.1042, -1373.7082, 1961.0068, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[3], 0, 14853, "gen_pol_vegas", "blue_carpet_256", 0xFFFFFFFF);
    object_lspdInterior[4] = CreateDynamicObject(19464, 1618.7115, -1383.2573, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[4], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[5] = CreateDynamicObject(19464, 1618.7115, -1377.3277, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[5], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[6] = CreateDynamicObject(19464, 1618.7115, -1371.3985, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[6], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[7] = CreateDynamicObject(19464, 1616.6207, -1385.6312, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[7], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[8] = CreateDynamicObject(19464, 1616.6207, -1369.0201, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[8], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[9] = CreateDynamicObject(19464, 1619.4803, -1388.4919, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[9], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[10] = CreateDynamicObject(19464, 1619.4803, -1366.1639, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[10], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[11] = CreateDynamicObject(19464, 1622.5710, -1368.3210, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[11], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[12] = CreateDynamicObject(19464, 1622.5710, -1386.0991, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[12], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[13] = CreateDynamicObject(19464, 1622.5727, -1386.0809, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[13], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[14] = CreateDynamicObject(19464, 1622.5727, -1386.0809, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[14], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[15] = CreateDynamicObject(19464, 1622.5727, -1368.3314, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[15], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[16] = CreateDynamicObject(18981, 1631.0345, -1373.7082, 1967.0561, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[16], 0, 13628, "8stad", "stadroof", 0xFFBDBEC6);
    object_lspdInterior[17] = CreateDynamicObject(19464, 1622.5727, -1368.3413, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[17], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[18] = CreateDynamicObject(19464, 1624.4906, -1368.3186, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[18], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[19] = CreateDynamicObject(14819, 1625.5345, -1368.5604, 1962.6611, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //OG_Door
    object_lspdInterior[20] = CreateDynamicObject(19464, 1627.3304, -1365.4681, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[20], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[21] = CreateDynamicObject(19464, 1627.3343, -1365.5013, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[21], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[22] = CreateDynamicObject(19464, 1624.2541, -1368.3360, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[22], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[23] = CreateDynamicObject(19464, 1627.3352, -1365.4808, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[23], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[24] = CreateDynamicObject(19464, 1624.2523, -1368.3459, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[24], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[25] = CreateDynamicObject(19176, 1618.9471, -1377.3686, 1962.9714, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LSOffice1Door1
    SetDynamicObjectMaterial(object_lspdInterior[25], 0, 9514, "711_sfw", "staddoors1", 0xFFFFFFFF);
    object_lspdInterior[26] = CreateDynamicObject(19466, 1618.8426, -1373.7016, 1964.1124, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[26], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[27] = CreateDynamicObject(11711, 1618.8553, -1378.1617, 1964.5810, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    object_lspdInterior[28] = CreateDynamicObject(19466, 1618.8426, -1370.8498, 1964.1124, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[28], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[29] = CreateDynamicObject(19466, 1644.5738, -1364.2685, 1963.8221, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[29], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[30] = CreateDynamicObject(19466, 1624.2043, -1385.9602, 1964.1124, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[30], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[31] = CreateDynamicObject(19464, 1618.7325, -1382.7209, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[31], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[32] = CreateDynamicObject(19464, 1618.7325, -1376.8133, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[32], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[33] = CreateDynamicObject(19464, 1618.7325, -1370.9139, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[33], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[34] = CreateDynamicObject(19464, 1618.7136, -1382.6208, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[34], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[35] = CreateDynamicObject(19464, 1618.7136, -1376.7198, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[35], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[36] = CreateDynamicObject(19464, 1618.7136, -1370.8785, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[36], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[37] = CreateDynamicObject(2616, 1622.9176, -1368.5273, 1963.4825, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB04
    object_lspdInterior[38] = CreateDynamicObject(2615, 1623.0251, -1368.5378, 1963.4071, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB3
    object_lspdInterior[39] = CreateDynamicObject(19464, 1628.4908, -1386.0991, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[39], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[40] = CreateDynamicObject(19464, 1628.4929, -1386.0809, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[40], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[41] = CreateDynamicObject(19464, 1634.4123, -1386.0991, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[41], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[42] = CreateDynamicObject(19464, 1634.3934, -1386.0809, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[42], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[43] = CreateDynamicObject(19464, 1628.5144, -1386.0809, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[43], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[44] = CreateDynamicObject(19464, 1634.4459, -1386.0809, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[44], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[45] = CreateDynamicObject(2612, 1627.5422, -1364.0931, 1963.5909, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB2
    object_lspdInterior[46] = CreateDynamicObject(2690, 1627.5454, -1365.4770, 1962.5096, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FIRE_EXT
    object_lspdInterior[47] = CreateDynamicObject(2611, 1627.5227, -1366.7447, 1963.5913, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB1
    object_lspdInterior[48] = CreateDynamicObject(19089, 1627.4516, -1368.4449, 1966.7480, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[48], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[49] = CreateDynamicObject(19089, 1627.4516, -1362.5539, 1966.7480, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[49], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[50] = CreateDynamicObject(19464, 1630.3990, -1362.4068, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[50], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[51] = CreateDynamicObject(19464, 1636.3193, -1362.4068, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[51], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[52] = CreateDynamicObject(19464, 1630.3642, -1362.4111, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[52], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[53] = CreateDynamicObject(19464, 1636.2850, -1362.4111, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[53], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[54] = CreateDynamicObject(19464, 1630.3946, -1362.4101, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[54], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[55] = CreateDynamicObject(19464, 1636.3149, -1362.4101, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[55], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[56] = CreateDynamicObject(19089, 1639.2435, -1362.5427, 1966.7480, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[56], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[57] = CreateDynamicObject(18762, 1627.7241, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[57], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[58] = CreateDynamicObject(18762, 1627.7241, -1368.9416, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[58], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[59] = CreateDynamicObject(18762, 1629.7237, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[59], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[60] = CreateDynamicObject(18762, 1628.7248, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[60], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[61] = CreateDynamicObject(18762, 1630.7237, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[61], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[62] = CreateDynamicObject(18762, 1631.7242, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[62], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[63] = CreateDynamicObject(18762, 1632.7253, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[63], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[64] = CreateDynamicObject(18762, 1633.7263, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[64], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[65] = CreateDynamicObject(18762, 1634.7269, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[65], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[66] = CreateDynamicObject(18762, 1635.7275, -1369.9427, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[66], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[67] = CreateDynamicObject(18762, 1635.7275, -1368.9416, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[67], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[68] = CreateDynamicObject(18762, 1635.7275, -1367.9508, 1960.0858, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[68], 0, 10765, "airportgnd_sfse", "sf_pave2", 0xFFFFFFFF);
    object_lspdInterior[69] = CreateDynamicObject(18762, 1627.7441, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[69], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[70] = CreateDynamicObject(18762, 1627.7441, -1368.9516, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[70], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[71] = CreateDynamicObject(18762, 1628.7451, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[71], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[72] = CreateDynamicObject(18762, 1629.7358, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[72], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[73] = CreateDynamicObject(18762, 1630.7270, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[73], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[74] = CreateDynamicObject(18762, 1631.7180, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[74], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[75] = CreateDynamicObject(18762, 1632.7087, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[75], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[76] = CreateDynamicObject(18762, 1633.6993, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[76], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[77] = CreateDynamicObject(18762, 1634.6800, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[77], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[78] = CreateDynamicObject(18762, 1635.6706, -1369.9327, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[78], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[79] = CreateDynamicObject(18762, 1635.7209, -1369.9527, 1960.1058, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[79], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[80] = CreateDynamicObject(18762, 1627.7480, -1369.9527, 1960.1058, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[80], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[81] = CreateDynamicObject(18762, 1635.7163, -1368.9516, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[81], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[82] = CreateDynamicObject(18762, 1635.7163, -1367.9609, 1960.0958, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[82], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[83] = CreateDynamicObject(19464, 1631.1942, -1370.3221, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[83], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[84] = CreateDynamicObject(19464, 1632.2551, -1370.3321, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[84], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[85] = CreateDynamicObject(19565, 1630.1374, -1369.8834, 1965.3651, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[85], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[86] = CreateDynamicObject(19565, 1629.9272, -1369.8834, 1965.3642, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[86], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[87] = CreateDynamicObject(19565, 1629.9372, -1369.9134, 1965.3751, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[87], 0, 10765, "airportgnd_sfse", "white", 0xFF2A77A1);
    object_lspdInterior[88] = CreateDynamicObject(19565, 1633.2882, -1369.8834, 1965.3651, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[88], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[89] = CreateDynamicObject(19565, 1630.1274, -1369.9134, 1965.3751, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[89], 0, 10765, "airportgnd_sfse", "white", 0xFF2A77A1);
    object_lspdInterior[90] = CreateDynamicObject(19089, 1629.7032, -1369.9034, 1972.7674, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[90], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[91] = CreateDynamicObject(19089, 1630.3541, -1369.9034, 1972.7878, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[91], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[92] = CreateDynamicObject(19175, 1630.0505, -1369.9538, 1965.5194, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[92], 0, "Front Desk", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[92], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[93] = CreateDynamicObject(19565, 1633.5184, -1369.8834, 1965.3642, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[93], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[94] = CreateDynamicObject(19175, 1633.4116, -1369.9538, 1965.5194, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[94], 0, "Front Desk", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[94], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[95] = CreateDynamicObject(19565, 1633.2884, -1369.9134, 1965.3751, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[95], 0, 10765, "airportgnd_sfse", "white", 0xFF2A77A1);
    object_lspdInterior[96] = CreateDynamicObject(19565, 1633.5085, -1369.9134, 1965.3751, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[96], 0, 10765, "airportgnd_sfse", "white", 0xFF2A77A1);
    object_lspdInterior[97] = CreateDynamicObject(19089, 1633.0749, -1369.9034, 1972.7878, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[97], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[98] = CreateDynamicObject(19089, 1633.7452, -1369.9034, 1972.7878, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[98], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[99] = CreateDynamicObject(19175, 1630.9101, -1362.5233, 1965.5194, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[99], 0, "Police", 90, "Arial", 70, 1, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[99], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[100] = CreateDynamicObject(19175, 1633.1612, -1362.5233, 1965.5194, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[100], 0, "Depart", 90, "Arial", 70, 1, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[100], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[101] = CreateDynamicObject(2161, 1637.6855, -1362.5532, 1962.8354, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    SetDynamicObjectMaterial(object_lspdInterior[101], 1, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[102] = CreateDynamicObject(19175, 1634.9427, -1362.5233, 1965.5194, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[102], 0, "ment", 90, "Arial", 70, 1, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[102], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[103] = CreateDynamicObject(1714, 1630.1572, -1364.3984, 1961.4881, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_lspdInterior[104] = CreateDynamicObject(2164, 1635.5920, -1362.5985, 1961.9886, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    SetDynamicObjectMaterial(object_lspdInterior[104], 1, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[105] = CreateDynamicObject(2164, 1632.8120, -1362.5985, 1961.9886, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    SetDynamicObjectMaterial(object_lspdInterior[105], 1, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[106] = CreateDynamicObject(1714, 1630.2873, -1367.7185, 1961.4881, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_lspdInterior[107] = CreateDynamicObject(1714, 1633.1186, -1367.6883, 1961.4881, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_lspdInterior[108] = CreateDynamicObject(18762, 1635.7163, -1367.9609, 1964.9576, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_lspdInterior[108], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[109] = CreateDynamicObject(19464, 1639.3913, -1365.3680, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[109], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[110] = CreateDynamicObject(19089, 1639.2435, -1368.3326, 1966.7480, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[110], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[111] = CreateDynamicObject(19464, 1639.3857, -1365.3608, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[111], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[112] = CreateDynamicObject(19464, 1639.3846, -1365.3718, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[112], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[113] = CreateDynamicObject(2611, 1639.2132, -1366.8049, 1963.5913, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB1
    object_lspdInterior[114] = CreateDynamicObject(2612, 1639.2121, -1364.0931, 1963.5909, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB2
    object_lspdInterior[115] = CreateDynamicObject(2690, 1639.2237, -1365.4372, 1962.5096, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FIRE_EXT
    object_lspdInterior[116] = CreateDynamicObject(19089, 1639.5135, -1368.3326, 1966.7480, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[116], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[117] = CreateDynamicObject(2008, 1629.3675, -1363.0063, 1961.4809, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //officedesk1
    SetDynamicObjectMaterial(object_lspdInterior[117], 4, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[118] = CreateDynamicObject(19089, 1639.5135, -1366.8210, 1966.7480, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[118], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[119] = CreateDynamicObject(19565, 1625.5096, -1368.4659, 1962.3055, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[119], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[120] = CreateDynamicObject(19565, 1625.5096, -1368.4659, 1961.8349, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[120], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[121] = CreateDynamicObject(19565, 1625.5096, -1368.4659, 1962.7757, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[121], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[122] = CreateDynamicObject(19565, 1625.5096, -1368.4659, 1963.2363, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[122], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[123] = CreateDynamicObject(19565, 1625.5096, -1368.4659, 1963.7065, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[123], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[124] = CreateDynamicObject(19565, 1625.5096, -1368.4659, 1963.8769, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[124], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[125] = CreateDynamicObject(19565, 1627.0610, -1368.4659, 1963.8769, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[125], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[126] = CreateDynamicObject(19565, 1627.0610, -1368.4659, 1963.4062, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[126], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[127] = CreateDynamicObject(19565, 1627.0610, -1368.4659, 1962.9260, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[127], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[128] = CreateDynamicObject(19565, 1627.0610, -1368.4659, 1962.4554, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[128], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[129] = CreateDynamicObject(19565, 1627.0610, -1368.4659, 1961.9852, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[129], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[130] = CreateDynamicObject(19565, 1627.0610, -1368.4659, 1961.5051, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[130], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[131] = CreateDynamicObject(19565, 1626.8608, -1368.4560, 1964.0759, 90.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[131], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[132] = CreateDynamicObject(19565, 1625.7207, -1368.4560, 1964.0759, 90.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[132], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[133] = CreateDynamicObject(19565, 1626.1910, -1368.4560, 1964.0759, 90.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[133], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[134] = CreateDynamicObject(19565, 1626.6516, -1368.4560, 1964.0759, 90.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[134], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[135] = CreateDynamicObject(2310, 1629.0273, -1385.4549, 1962.0439, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[135], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[135], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[136] = CreateDynamicObject(2125, 1628.9912, -1385.4748, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[136], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[137] = CreateDynamicObject(2125, 1628.9912, -1384.5841, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[137], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[138] = CreateDynamicObject(2125, 1628.9912, -1383.6932, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[138], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[139] = CreateDynamicObject(2125, 1628.9912, -1382.7723, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[139], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[140] = CreateDynamicObject(2125, 1628.9912, -1381.8114, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[140], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[141] = CreateDynamicObject(2310, 1629.0273, -1384.5738, 1962.0439, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[141], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[141], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[142] = CreateDynamicObject(2310, 1629.0273, -1383.6633, 1962.0439, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[142], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[142], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[143] = CreateDynamicObject(2310, 1629.0273, -1382.7624, 1962.0439, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[143], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[143], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[144] = CreateDynamicObject(2310, 1629.0273, -1381.8016, 1962.0439, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[144], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[144], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[145] = CreateDynamicObject(2125, 1634.3902, -1385.4748, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[145], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[146] = CreateDynamicObject(2125, 1634.3924, -1384.5841, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[146], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[147] = CreateDynamicObject(2125, 1634.4017, -1383.6932, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[147], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[148] = CreateDynamicObject(2125, 1634.4322, -1382.7723, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[148], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[149] = CreateDynamicObject(2125, 1634.4624, -1381.8114, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[149], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[150] = CreateDynamicObject(2310, 1634.4576, -1384.5738, 1962.0439, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[150], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[150], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[151] = CreateDynamicObject(2310, 1634.4576, -1385.4748, 1962.0439, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[151], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[151], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[152] = CreateDynamicObject(2310, 1634.4576, -1383.7137, 1962.0439, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[152], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[152], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[153] = CreateDynamicObject(2310, 1634.4576, -1382.7928, 1962.0439, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[153], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[153], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[154] = CreateDynamicObject(2310, 1634.4576, -1381.8220, 1962.0439, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[154], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[154], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[155] = CreateDynamicObject(2310, 1631.3564, -1381.8220, 1962.0439, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[155], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[155], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[156] = CreateDynamicObject(2310, 1632.0173, -1381.8220, 1962.0439, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[156], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[156], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[157] = CreateDynamicObject(2310, 1631.3564, -1382.7928, 1962.0439, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[157], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[157], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[158] = CreateDynamicObject(2310, 1631.3564, -1383.6938, 1962.0439, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[158], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[158], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[159] = CreateDynamicObject(2125, 1623.5621, -1368.7502, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[159], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[160] = CreateDynamicObject(2010, 1631.6754, -1381.3055, 1961.4975, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    SetDynamicObjectMaterial(object_lspdInterior[160], 4, 2247, "plants_galss", "CJ_willow", 0xFFFFFFFF);
    object_lspdInterior[161] = CreateDynamicObject(2310, 1632.0173, -1382.7921, 1962.0439, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[161], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[161], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[162] = CreateDynamicObject(2310, 1632.0173, -1383.6927, 1962.0439, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[162], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[162], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[163] = CreateDynamicObject(2125, 1621.7716, -1368.7502, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[163], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[164] = CreateDynamicObject(2125, 1622.6822, -1368.7502, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[164], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[165] = CreateDynamicObject(2310, 1623.5771, -1368.7701, 1962.0439, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[165], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[165], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[166] = CreateDynamicObject(2310, 1622.7065, -1368.7701, 1962.0439, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[166], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[166], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[167] = CreateDynamicObject(2310, 1621.7861, -1368.7701, 1962.0439, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[167], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[167], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[168] = CreateDynamicObject(2125, 1632.0024, -1383.6932, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[168], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[169] = CreateDynamicObject(2125, 1632.0024, -1382.7923, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[169], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[170] = CreateDynamicObject(2125, 1632.0024, -1381.8215, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[170], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[171] = CreateDynamicObject(19464, 1623.8431, -1377.3309, 1958.9619, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[171], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[172] = CreateDynamicObject(2125, 1631.3216, -1383.6932, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[172], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[173] = CreateDynamicObject(2125, 1631.3216, -1382.7923, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[173], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[174] = CreateDynamicObject(2125, 1631.3216, -1381.8214, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[174], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[175] = CreateDynamicObject(19464, 1649.3415, -1370.8166, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[175], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[176] = CreateDynamicObject(19786, 1631.7104, -1386.0909, 1963.6435, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_lspdInterior[176], 0, 10765, "airportgnd_sfse", "white", 0xFF46597A);
    SetDynamicObjectMaterial(object_lspdInterior[176], 1, 7009, "vgndwntwn1", "newpolice_sa", 0xFFFFFFFF);
    object_lspdInterior[177] = CreateDynamicObject(19464, 1649.3718, -1377.9980, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[177], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[178] = CreateDynamicObject(19464, 1621.3205, -1377.3277, 1961.4029, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[178], 0, 15048, "labigsave", "AH_carpet4kb", 0xFFFFFFFF);
    object_lspdInterior[179] = CreateDynamicObject(19464, 1621.0028, -1374.3702, 1958.9719, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[179], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[180] = CreateDynamicObject(19464, 1621.0028, -1380.2519, 1958.9719, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[180], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[181] = CreateDynamicObject(2008, 1630.8376, -1368.9875, 1961.4809, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //officedesk1
    SetDynamicObjectMaterial(object_lspdInterior[181], 4, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[182] = CreateDynamicObject(2008, 1633.8884, -1368.9875, 1961.4809, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //officedesk1
    SetDynamicObjectMaterial(object_lspdInterior[182], 4, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[183] = CreateDynamicObject(19466, 1626.9554, -1385.9499, 1964.1124, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[183], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[184] = CreateDynamicObject(19466, 1618.8426, -1381.0222, 1964.1124, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[184], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[185] = CreateDynamicObject(19466, 1639.5360, -1360.2883, 1963.8221, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[185], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[186] = CreateDynamicObject(19464, 1639.3946, -1365.3718, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[186], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[187] = CreateDynamicObject(19464, 1639.3957, -1365.3608, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[187], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[188] = CreateDynamicObject(19464, 1642.4339, -1366.6767, 1966.4836, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[188], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[189] = CreateDynamicObject(19464, 1645.9414, -1365.8188, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[189], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[190] = CreateDynamicObject(19464, 1648.7740, -1368.7899, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[190], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[191] = CreateDynamicObject(19464, 1644.7248, -1364.2064, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[191], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[192] = CreateDynamicObject(1738, 1646.2495, -1374.8774, 1962.0415, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Radiator_old
    SetDynamicObjectMaterial(object_lspdInterior[192], 0, 1738, "cjtemp", "cj_radiatorOLD", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdInterior[192], 1, 1738, "cjtemp", "cj_radiatorOLD", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdInterior[192], 2, 14704, "lahss2_2int2", "HS_radiator1", 0xFFFFFFFF);
    object_lspdInterior[193] = CreateDynamicObject(19464, 1646.4825, -1367.9670, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[193], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[194] = CreateDynamicObject(19464, 1647.5749, -1367.0394, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[194], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[195] = CreateDynamicObject(19464, 1648.2036, -1367.9891, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[195], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[196] = CreateDynamicObject(19464, 1646.4825, -1376.8669, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[196], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[197] = CreateDynamicObject(19464, 1637.4835, -1383.3891, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[197], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[198] = CreateDynamicObject(1495, 1643.2508, -1380.5179, 1961.5764, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT01
    object_lspdInterior[199] = CreateDynamicObject(19464, 1640.3232, -1380.5478, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[199], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[200] = CreateDynamicObject(19464, 1645.3531, -1365.1368, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[200], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[201] = CreateDynamicObject(19464, 1645.8420, -1382.7965, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[201], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[202] = CreateDynamicObject(19464, 1648.6833, -1379.9460, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[202], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[203] = CreateDynamicObject(1738, 1646.2495, -1369.9471, 1962.0415, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Radiator_old
    SetDynamicObjectMaterial(object_lspdInterior[203], 0, 1738, "cjtemp", "cj_radiatorOLD", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdInterior[203], 1, 1738, "cjtemp", "cj_radiatorOLD", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdInterior[203], 2, 14704, "lahss2_2int2", "HS_radiator1", 0xFFFFFFFF);
    object_lspdInterior[204] = CreateDynamicObject(11711, 1618.8553, -1376.4619, 1964.5810, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    object_lspdInterior[205] = CreateDynamicObject(19565, 1624.9206, -1368.4420, 1963.1772, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[205], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[206] = CreateDynamicObject(19565, 1625.1606, -1368.4420, 1963.1772, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[206], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[207] = CreateDynamicObject(18981, 1655.9934, -1373.7082, 1967.0561, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[207], 0, 13628, "8stad", "stadroof", 0xFFBDBEC6);
    object_lspdInterior[208] = CreateDynamicObject(2125, 1623.5621, -1385.6783, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[208], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[209] = CreateDynamicObject(2125, 1624.3326, -1385.6783, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[209], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[210] = CreateDynamicObject(2125, 1625.1230, -1385.6783, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[210], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[211] = CreateDynamicObject(2125, 1625.8736, -1385.6783, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[211], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[212] = CreateDynamicObject(2125, 1622.7729, -1385.6783, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[212], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[213] = CreateDynamicObject(2125, 1626.6639, -1385.6783, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[213], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[214] = CreateDynamicObject(2125, 1621.9332, -1385.6783, 1961.8031, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_lspdInterior[214], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[215] = CreateDynamicObject(2310, 1623.5771, -1385.6485, 1962.0439, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[215], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[215], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[216] = CreateDynamicObject(2310, 1624.3580, -1385.6485, 1962.0439, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[216], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[216], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[217] = CreateDynamicObject(2310, 1625.1488, -1385.6485, 1962.0439, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[217], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[217], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[218] = CreateDynamicObject(2310, 1625.8894, -1385.6485, 1962.0439, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[218], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[218], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[219] = CreateDynamicObject(2310, 1626.6700, -1385.6485, 1962.0439, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[219], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[219], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[220] = CreateDynamicObject(2310, 1622.7685, -1385.6485, 1962.0439, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[220], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[220], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[221] = CreateDynamicObject(2310, 1621.9377, -1385.6485, 1962.0439, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIKE_DIN_CHAIR
    SetDynamicObjectMaterial(object_lspdInterior[221], 0, 4010, "lanblokb2", "bluewhitebuildwall2drt", 0xFF3B4E78);
    SetDynamicObjectMaterial(object_lspdInterior[221], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[222] = CreateDynamicObject(2010, 1627.4448, -1385.6457, 1961.4975, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    SetDynamicObjectMaterial(object_lspdInterior[222], 4, 2247, "plants_galss", "CJ_willow", 0xFFFFFFFF);
    object_lspdInterior[223] = CreateDynamicObject(2010, 1621.1439, -1385.6457, 1961.4975, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    SetDynamicObjectMaterial(object_lspdInterior[223], 4, 2247, "plants_galss", "CJ_willow", 0xFFFFFFFF);
    object_lspdInterior[224] = CreateDynamicObject(19430, 1623.1462, -1386.0255, 1961.4320, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[224], 0, 15048, "labigsave", "AH_carpet4kb", 0xFFFFFFFF);
    object_lspdInterior[225] = CreateDynamicObject(19430, 1622.6357, -1368.4481, 1961.4320, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[225], 0, 15048, "labigsave", "AH_carpet4kb", 0xFFFFFFFF);
    object_lspdInterior[226] = CreateDynamicObject(19430, 1625.3674, -1386.0255, 1961.4320, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[226], 0, 15048, "labigsave", "AH_carpet4kb", 0xFFFFFFFF);
    object_lspdInterior[227] = CreateDynamicObject(19464, 1624.2535, -1385.2606, 1958.9619, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[227], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[228] = CreateDynamicObject(19464, 1621.4117, -1388.3424, 1958.9619, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[228], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[229] = CreateDynamicObject(19464, 1627.0937, -1388.3424, 1958.9619, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[229], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[230] = CreateDynamicObject(19464, 1624.3541, -1366.4110, 1958.9619, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[230], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[231] = CreateDynamicObject(19464, 1620.9117, -1366.4110, 1958.9619, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[231], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[232] = CreateDynamicObject(19430, 1622.6357, -1369.2889, 1960.7113, 90.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[232], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[233] = CreateDynamicObject(1491, 1646.4167, -1370.9134, 1961.4892, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_lspdInterior[233], 0, 12805, "ce_loadbay", "sw_waredoor", 0xFFFFFFFF);
    object_lspdInterior[234] = CreateDynamicObject(1491, 1646.4370, -1373.9343, 1961.4892, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_lspdInterior[234], 0, 12805, "ce_loadbay", "sw_waredoor", 0xFFFFFFFF);
    object_lspdInterior[235] = CreateDynamicObject(19464, 1646.4925, -1371.6583, 1966.5240, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[235], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[236] = CreateDynamicObject(19565, 1646.3913, -1370.3408, 1963.1772, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[236], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[237] = CreateDynamicObject(19175, 1625.0428, -1368.4736, 1963.3292, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[237], 0, "Treppen", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[237], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[238] = CreateDynamicObject(19565, 1646.3913, -1370.5410, 1963.1772, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[238], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[239] = CreateDynamicObject(19565, 1646.3913, -1374.3115, 1963.1772, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[239], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[240] = CreateDynamicObject(19565, 1646.3913, -1374.4814, 1963.1772, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[240], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[241] = CreateDynamicObject(19175, 1646.3540, -1374.3950, 1963.3292, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[241], 0, "Zellen", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[241], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[242] = CreateDynamicObject(19175, 1646.3540, -1370.4632, 1963.3292, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[242], 0, "Zellen", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[242], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[243] = CreateDynamicObject(19825, 1633.1417, -1362.5671, 1964.5328, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
    SetDynamicObjectMaterial(object_lspdInterior[243], 0, 1654, "dynamite", "clock64", 0xFFFFFFFF);
    object_lspdInterior[244] = CreateDynamicObject(2662, 1637.3138, -1384.8138, 1963.9803, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BANNER08
    SetDynamicObjectMaterial(object_lspdInterior[244], 0, 2655, "cj_banner", "CJ_ERIS1", 0xFFFFFFFF);
    object_lspdInterior[245] = CreateDynamicObject(2662, 1637.3138, -1381.3929, 1963.9803, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BANNER08
    SetDynamicObjectMaterial(object_lspdInterior[245], 0, 2655, "cj_banner", "CJ_ERIS1", 0xFFFFFFFF);
    object_lspdInterior[246] = CreateDynamicObject(3808, 1646.2937, -1374.4294, 1965.1412, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_alarms04
    object_lspdInterior[247] = CreateDynamicObject(3808, 1646.2937, -1370.4781, 1965.1412, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_alarms04
    object_lspdInterior[248] = CreateDynamicObject(19464, 1646.4764, -1367.9597, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[248], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[249] = CreateDynamicObject(19464, 1646.4764, -1376.8913, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[249], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[250] = CreateDynamicObject(19464, 1644.2557, -1380.5367, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[250], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[251] = CreateDynamicObject(19464, 1640.3249, -1380.5323, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[251], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[252] = CreateDynamicObject(19464, 1637.4642, -1383.3739, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[252], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[253] = CreateDynamicObject(19464, 1642.4648, -1366.6827, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[253], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[254] = CreateDynamicObject(19464, 1642.4453, -1366.6810, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[254], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[255] = CreateDynamicObject(19464, 1644.0764, -1380.5212, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[255], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[256] = CreateDynamicObject(19464, 1640.3248, -1380.5260, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[256], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[257] = CreateDynamicObject(19464, 1637.4637, -1383.3620, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[257], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[258] = CreateDynamicObject(19464, 1646.4648, -1377.7419, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[258], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[259] = CreateDynamicObject(19464, 1646.4648, -1371.8214, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[259], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[260] = CreateDynamicObject(18075, 1642.0743, -1373.9438, 1966.6258, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_lspdInterior[261] = CreateDynamicObject(18075, 1632.0533, -1373.9438, 1966.6258, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_lspdInterior[262] = CreateDynamicObject(18075, 1632.0533, -1386.9737, 1966.6258, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_lspdInterior[263] = CreateDynamicObject(18075, 1623.2727, -1386.9737, 1966.6258, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_lspdInterior[264] = CreateDynamicObject(18075, 1623.2727, -1373.9530, 1966.6258, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_lspdInterior[265] = CreateDynamicObject(16780, 1630.0400, -1366.9552, 1966.6279, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light03
    object_lspdInterior[266] = CreateDynamicObject(16780, 1633.3111, -1366.9552, 1966.6279, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light03
    object_lspdInterior[267] = CreateDynamicObject(19464, 1647.7148, -1380.5478, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[267], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[268] = CreateDynamicObject(1491, 1644.2999, -1366.7242, 1961.4708, 0.0000, 0.0000, -53.2999, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_lspdInterior[268], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    object_lspdInterior[269] = CreateDynamicObject(19565, 1642.4510, -1366.7910, 1963.1772, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[269], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[270] = CreateDynamicObject(19565, 1642.3011, -1366.7910, 1963.1772, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[270], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[271] = CreateDynamicObject(19565, 1642.3011, -1380.4327, 1963.1772, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[271], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[272] = CreateDynamicObject(19565, 1642.5511, -1380.4327, 1963.1772, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[272], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[273] = CreateDynamicObject(19175, 1642.4233, -1380.4034, 1963.3292, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[273], 0, "Dienstraum", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[273], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[274] = CreateDynamicObject(19403, 1641.0477, -1366.7071, 1962.8852, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall051
    SetDynamicObjectMaterial(object_lspdInterior[274], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[275] = CreateDynamicObject(2008, 1648.6009, -1375.4283, 1961.4769, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //officedesk1
    object_lspdInterior[276] = CreateDynamicObject(1714, 1649.0986, -1376.6195, 1961.4812, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_lspdInterior[277] = CreateDynamicObject(2197, 1647.3747, -1377.3265, 1961.4681, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FILLING_CABINET
    object_lspdInterior[278] = CreateDynamicObject(2197, 1648.0555, -1377.3265, 1961.4681, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FILLING_CABINET
    object_lspdInterior[279] = CreateDynamicObject(2163, 1646.5649, -1375.4365, 1961.4824, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_lspdInterior[280] = CreateDynamicObject(2197, 1650.1368, -1377.3265, 1961.4681, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FILLING_CABINET
    object_lspdInterior[281] = CreateDynamicObject(2197, 1650.8176, -1377.3265, 1961.4681, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FILLING_CABINET
    object_lspdInterior[282] = CreateDynamicObject(19464, 1655.1616, -1377.9930, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[282], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[283] = CreateDynamicObject(2163, 1646.5649, -1377.1468, 1961.4824, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_lspdInterior[284] = CreateDynamicObject(2251, 1646.6992, -1376.7092, 1963.2502, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_20
    object_lspdInterior[285] = CreateDynamicObject(2251, 1646.6992, -1374.8879, 1963.2502, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_20
    object_lspdInterior[286] = CreateDynamicObject(19303, 1656.3231, -1375.2534, 1962.7353, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge19
    SetDynamicObjectMaterial(object_lspdInterior[286], 0, 14842, "genintintpolicea", "copcell_bars", 0xFFFFFFFF);
    object_lspdInterior[287] = CreateDynamicObject(19303, 1656.3231, -1371.7618, 1962.7353, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge19
    SetDynamicObjectMaterial(object_lspdInterior[287], 0, 14842, "genintintpolicea", "copcell_bars", 0xFFFFFFFF);
    object_lspdInterior[288] = CreateDynamicObject(19466, 1635.1130, -1385.9626, 1964.1124, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[288], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[289] = CreateDynamicObject(19302, 1656.3254, -1373.5155, 1962.7287, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    SetDynamicObjectMaterial(object_lspdInterior[289], 0, 14842, "genintintpolicea", "copcell_bars", 0xFFFFFFFF);
    object_lspdInterior[290] = CreateDynamicObject(19464, 1655.1523, -1370.8110, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[290], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[291] = CreateDynamicObject(19464, 1655.8520, -1369.4973, 1966.5334, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[291], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[292] = CreateDynamicObject(19464, 1658.7132, -1375.4178, 1964.0736, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[292], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
    object_lspdInterior[293] = CreateDynamicObject(19464, 1661.0915, -1377.9980, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[293], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[294] = CreateDynamicObject(19464, 1661.0915, -1370.8083, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[294], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[295] = CreateDynamicObject(19303, 1657.2126, -1374.3934, 1962.7353, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge19
    SetDynamicObjectMaterial(object_lspdInterior[295], 0, 14842, "genintintpolicea", "copcell_bars", 0xFFFFFFFF);
    object_lspdInterior[296] = CreateDynamicObject(19302, 1656.3254, -1376.9964, 1962.7287, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    SetDynamicObjectMaterial(object_lspdInterior[296], 0, 14842, "genintintpolicea", "copcell_bars", 0xFFFFFFFF);
    object_lspdInterior[297] = CreateDynamicObject(19466, 1618.9029, -1383.7932, 1964.1124, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[297], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[298] = CreateDynamicObject(19466, 1644.5738, -1360.0570, 1963.8221, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[298], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[299] = CreateDynamicObject(19303, 1658.9543, -1374.3917, 1962.7353, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge19
    SetDynamicObjectMaterial(object_lspdInterior[299], 0, 14842, "genintintpolicea", "copcell_bars", 0xFFFFFFFF);
    object_lspdInterior[300] = CreateDynamicObject(19466, 1621.4934, -1385.9702, 1964.1124, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdInterior[300], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdInterior[301] = CreateDynamicObject(19464, 1659.9508, -1373.8586, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[301], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[302] = CreateDynamicObject(19464, 1659.9404, -1379.7779, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[302], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[303] = CreateDynamicObject(1812, 1657.3192, -1377.4399, 1961.4880, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_5
    object_lspdInterior[304] = CreateDynamicObject(1812, 1657.3192, -1371.4073, 1961.4880, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_5
    object_lspdInterior[305] = CreateDynamicObject(19464, 1658.7135, -1370.3249, 1964.0736, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[305], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
    object_lspdInterior[306] = CreateDynamicObject(19464, 1655.8525, -1375.4178, 1966.5334, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[306], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[307] = CreateDynamicObject(1744, 1650.2851, -1370.7783, 1961.6634, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[307], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[308] = CreateDynamicObject(1744, 1652.6656, -1370.7783, 1961.6634, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[308], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[309] = CreateDynamicObject(1744, 1647.9951, -1370.7783, 1961.6634, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[309], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[310] = CreateDynamicObject(19786, 1650.7298, -1370.8304, 1963.9338, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_lspdInterior[310], 0, 10765, "airportgnd_sfse", "white", 0xFF46597A);
    SetDynamicObjectMaterial(object_lspdInterior[310], 1, 7009, "vgndwntwn1", "newpolice_sa", 0xFFFFFFFF);
    object_lspdInterior[311] = CreateDynamicObject(19175, 1652.9549, -1377.8658, 1962.8177, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[311], 0, "___________________", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[311], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[312] = CreateDynamicObject(19464, 1654.9049, -1377.9731, 1959.0524, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[312], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[313] = CreateDynamicObject(19175, 1652.9549, -1377.8658, 1963.2082, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[313], 0, "___________________", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[313], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[314] = CreateDynamicObject(19175, 1652.9549, -1377.8559, 1962.4276, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[314], 0, "___________________", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[314], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[315] = CreateDynamicObject(19175, 1652.9549, -1377.8658, 1962.0172, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[315], 0, "___________________", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[315], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[316] = CreateDynamicObject(19175, 1652.7646, -1377.8658, 1962.2174, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[316], 0, "_______________", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[316], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[317] = CreateDynamicObject(19175, 1652.7646, -1377.8658, 1962.6278, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[317], 0, "_______________", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[317], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[318] = CreateDynamicObject(19175, 1652.7646, -1377.8459, 1963.0080, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[318], 0, "_______________", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[318], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[319] = CreateDynamicObject(19175, 1652.2939, -1377.8658, 1963.1684, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[319], 0, "2.00 m", 90, "Arial", 15, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[319], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[320] = CreateDynamicObject(19175, 1652.2939, -1377.8459, 1961.9770, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[320], 0, "1.40 m", 90, "Arial", 15, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[320], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[321] = CreateDynamicObject(19175, 1652.2939, -1377.8658, 1962.3977, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[321], 0, "1.60 m", 90, "Arial", 15, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[321], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[322] = CreateDynamicObject(19089, 1654.3076, -1377.8657, 1963.7668, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[322], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_lspdInterior[323] = CreateDynamicObject(19089, 1655.1495, -1377.8757, 1964.7076, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[323], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[324] = CreateDynamicObject(19089, 1651.6472, -1377.8757, 1964.7076, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[324], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[325] = CreateDynamicObject(19087, 1655.1457, -1377.8608, 1964.6905, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[325], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[326] = CreateDynamicObject(19087, 1654.0954, -1377.8608, 1964.6905, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[326], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[327] = CreateDynamicObject(367, 1653.2967, -1375.1130, 1963.2183, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //camera
    object_lspdInterior[328] = CreateDynamicObject(19089, 1653.4066, -1375.1756, 1963.2182, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[328], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_lspdInterior[329] = CreateDynamicObject(19089, 1652.5061, -1377.8657, 1963.7668, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[329], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_lspdInterior[330] = CreateDynamicObject(19089, 1653.4066, -1375.1756, 1963.2182, 6.0998, 6.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[330], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_lspdInterior[331] = CreateDynamicObject(19089, 1653.4066, -1375.1756, 1963.2182, 6.0998, -5.7999, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[331], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_lspdInterior[332] = CreateDynamicObject(19089, 1653.4066, -1375.1756, 1963.0660, -6.2999, -5.7999, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[332], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_lspdInterior[333] = CreateDynamicObject(19089, 1653.4066, -1375.1756, 1963.2182, -6.2999, 6.5998, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[333], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_lspdInterior[334] = CreateDynamicObject(19464, 1649.3153, -1370.8221, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[334], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[335] = CreateDynamicObject(19464, 1653.3369, -1370.8270, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[335], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[336] = CreateDynamicObject(19464, 1653.3369, -1377.9980, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[336], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[337] = CreateDynamicObject(19464, 1649.3249, -1377.9930, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[337], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[338] = CreateDynamicObject(19464, 1646.4847, -1376.8623, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[338], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[339] = CreateDynamicObject(19464, 1649.5445, -1377.9902, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[339], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[340] = CreateDynamicObject(19464, 1655.4758, -1377.9902, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[340], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[341] = CreateDynamicObject(19464, 1655.8360, -1374.9101, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[341], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[342] = CreateDynamicObject(19464, 1655.8360, -1368.9903, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[342], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[343] = CreateDynamicObject(19464, 1652.8360, -1370.8470, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[343], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[344] = CreateDynamicObject(19464, 1649.5366, -1370.8420, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[344], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[345] = CreateDynamicObject(19464, 1646.5063, -1373.8629, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[345], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[346] = CreateDynamicObject(19464, 1646.5063, -1379.7926, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[346], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[347] = CreateDynamicObject(2264, 1649.0410, -1377.3508, 1963.2928, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_5
    object_lspdInterior[348] = CreateDynamicObject(2270, 1647.1311, -1375.7425, 1963.4145, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    SetDynamicObjectMaterial(object_lspdInterior[348], 0, 14489, "carlspics", "AH_picture3", 0xFFFFFFFF);
    object_lspdInterior[349] = CreateDynamicObject(2264, 1650.4309, -1377.3508, 1964.2429, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_5
    SetDynamicObjectMaterial(object_lspdInterior[349], 1, 2254, "picture_frame_clip", "CJ_PAINTING4", 0xFFFFFFFF);
    object_lspdInterior[350] = CreateDynamicObject(2264, 1647.6804, -1377.3508, 1964.2429, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_5
    SetDynamicObjectMaterial(object_lspdInterior[350], 1, 2254, "picture_frame_clip", "CJ_PAINTING26", 0xFFFFFFFF);
    object_lspdInterior[351] = CreateDynamicObject(19464, 1645.7447, -1380.5500, 1966.6241, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[351], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[352] = CreateDynamicObject(1744, 1637.7347, -1383.0589, 1961.4934, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[352], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[353] = CreateDynamicObject(18981, 1649.8636, -1393.1092, 1961.0163, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[353], 0, 15034, "genhotelsave", "bathtile05_int", 0xFFFFFFFF);
    object_lspdInterior[354] = CreateDynamicObject(1744, 1638.5649, -1380.7884, 1961.5034, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[354], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[355] = CreateDynamicObject(11729, 1637.6395, -1384.4748, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[355], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[356] = CreateDynamicObject(1744, 1637.7347, -1385.5893, 1961.4934, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[356], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[357] = CreateDynamicObject(19464, 1637.4835, -1389.3093, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[357], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[358] = CreateDynamicObject(1744, 1637.7347, -1388.0809, 1961.4934, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[358], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[359] = CreateDynamicObject(19464, 1645.3337, -1385.9410, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[359], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[360] = CreateDynamicObject(19464, 1645.3238, -1383.5522, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[360], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[361] = CreateDynamicObject(19464, 1640.5028, -1388.9624, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[361], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[362] = CreateDynamicObject(19464, 1646.4344, -1388.9624, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[362], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[363] = CreateDynamicObject(1744, 1640.3961, -1388.7314, 1961.4934, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[363], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[364] = CreateDynamicObject(14819, 1643.2189, -1388.7459, 1962.6756, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Door to garage
    // object_lspdInterior[364] = CreateDynamicObject(1744, 1643.6877, -1388.7314, 1961.4934, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    // SetDynamicObjectMaterial(object_lspdInterior[364], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[365] = CreateDynamicObject(11729, 1637.6395, -1385.1153, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[365], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[366] = CreateDynamicObject(11729, 1637.6395, -1385.7557, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[366], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[367] = CreateDynamicObject(11729, 1637.6395, -1386.9560, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[367], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[368] = CreateDynamicObject(11729, 1637.6395, -1387.6068, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[368], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[369] = CreateDynamicObject(11729, 1637.6395, -1388.2574, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[369], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[370] = CreateDynamicObject(11729, 1637.6395, -1383.2458, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[370], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[371] = CreateDynamicObject(11729, 1637.6395, -1382.5854, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[371], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[372] = CreateDynamicObject(11729, 1637.6395, -1381.9249, 1961.5113, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[372], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[373] = CreateDynamicObject(11729, 1639.2500, -1388.8243, 1961.5113, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[373], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[374] = CreateDynamicObject(11729, 1639.9006, -1388.8243, 1961.5113, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[374], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[375] = CreateDynamicObject(11729, 1640.5611, -1388.8243, 1961.5113, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[375], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    // object_lspdInterior[376] = CreateDynamicObject(11729, 1642.5421, -1388.8243, 1961.5113, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    // SetDynamicObjectMaterial(object_lspdInterior[376], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    // object_lspdInterior[377] = CreateDynamicObject(11729, 1643.1921, -1388.8243, 1961.5113, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    // SetDynamicObjectMaterial(object_lspdInterior[377], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF2A77A1);
    // object_lspdInterior[378] = CreateDynamicObject(11729, 1643.8625, -1388.8243, 1961.5113, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    // SetDynamicObjectMaterial(object_lspdInterior[378], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);

    object_lspdInterior[376] = CreateDynamicObject(19565, 1644.1601, -1388.8129, 1963.1772, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[376], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[377] = CreateDynamicObject(19565, 1643.6998, -1388.8131, 1963.1772, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdInterior[377], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[378] = CreateDynamicObject(19175, 1643.9245, -1388.7736, 1963.3092, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[378], 0, "Garage", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[378], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);

    object_lspdInterior[379] = CreateDynamicObject(1744, 1641.2054, -1380.7584, 1961.4934, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    SetDynamicObjectMaterial(object_lspdInterior[379], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[380] = CreateDynamicObject(11729, 1639.6794, -1380.6943, 1961.5113, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[380], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[381] = CreateDynamicObject(11729, 1639.0185, -1380.6943, 1961.5113, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[381], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[382] = CreateDynamicObject(11729, 1641.6910, -1380.6943, 1961.5113, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[382], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[383] = CreateDynamicObject(11729, 1638.3780, -1380.6943, 1961.5113, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[383], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[384] = CreateDynamicObject(11729, 1642.3114, -1380.6843, 1961.5113, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[384], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[385] = CreateDynamicObject(11729, 1641.0504, -1380.6943, 1961.5113, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    SetDynamicObjectMaterial(object_lspdInterior[385], 0, 14788, "ab_sfgymbits01", "lockers", 0xFF4C75B7);
    object_lspdInterior[386] = CreateDynamicObject(19450, 1645.2751, -1386.4105, 1960.5980, 90.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_lspdInterior[386], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[387] = CreateDynamicObject(19450, 1645.2751, -1382.9106, 1960.5980, 90.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_lspdInterior[387], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdInterior[388] = CreateDynamicObject(19089, 1645.1883, -1388.1645, 1965.4486, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[388], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[389] = CreateDynamicObject(19089, 1645.1883, -1381.1550, 1965.4486, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_lspdInterior[389], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[390] = CreateDynamicObject(19087, 1645.1958, -1381.1512, 1965.4366, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[390], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[391] = CreateDynamicObject(19087, 1645.1958, -1383.5808, 1965.4366, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[391], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[392] = CreateDynamicObject(19087, 1645.1958, -1385.7126, 1965.4366, 0.0000, 90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[392], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[393] = CreateDynamicObject(18637, 1645.1678, -1381.5461, 1962.6164, 90.0000, 90.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceShield1
    object_lspdInterior[394] = CreateDynamicObject(18637, 1645.1678, -1382.3269, 1962.6164, 90.0000, 90.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceShield1
    object_lspdInterior[395] = CreateDynamicObject(18637, 1645.1678, -1382.3269, 1964.3371, 90.0000, 90.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceShield1
    object_lspdInterior[396] = CreateDynamicObject(18637, 1645.1678, -1381.5362, 1964.3371, 90.0000, 90.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceShield1
    object_lspdInterior[397] = CreateDynamicObject(334, 1645.2082, -1382.2193, 1964.1505, 0.0000, 3.5000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nitestick
    object_lspdInterior[398] = CreateDynamicObject(334, 1645.2082, -1382.2054, 1962.4056, 0.0000, 3.5000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nitestick
    object_lspdInterior[399] = CreateDynamicObject(348, 1645.1883, -1383.9813, 1964.2097, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_lspdInterior[400] = CreateDynamicObject(348, 1645.1883, -1384.6617, 1964.2097, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_lspdInterior[401] = CreateDynamicObject(348, 1645.1883, -1385.3326, 1964.2097, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_lspdInterior[402] = CreateDynamicObject(348, 1645.1883, -1386.0333, 1964.2097, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_lspdInterior[403] = CreateDynamicObject(356, 1645.1793, -1384.3935, 1963.7054, 0.0000, 0.0000, 95.3000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    object_lspdInterior[404] = CreateDynamicObject(356, 1645.1854, -1385.7602, 1963.7054, 0.0000, 0.0000, 95.3000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    object_lspdInterior[405] = CreateDynamicObject(353, 1645.2010, -1385.7302, 1962.9720, 0.0000, 5.8000, 97.3000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mp5lng
    object_lspdInterior[406] = CreateDynamicObject(353, 1645.2072, -1384.9875, 1962.9880, 0.0000, 5.8000, 97.3000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mp5lng
    object_lspdInterior[407] = CreateDynamicObject(353, 1645.1942, -1384.2575, 1963.0151, 0.0000, 5.8000, 97.3000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mp5lng
    object_lspdInterior[408] = CreateDynamicObject(358, 1645.1978, -1385.5676, 1962.1920, 0.0000, 0.0000, 96.9999, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    object_lspdInterior[409] = CreateDynamicObject(358, 1645.1950, -1384.4793, 1962.1920, 0.0000, 0.0000, 96.9999, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    object_lspdInterior[410] = CreateDynamicObject(19430, 1646.5992, -1387.3509, 1963.4410, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[410], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[411] = CreateDynamicObject(19430, 1646.5992, -1387.3398, 1962.5301, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[411], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[412] = CreateDynamicObject(19430, 1646.6008, -1386.5200, 1961.8094, 90.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[412], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[413] = CreateDynamicObject(19430, 1646.6003, -1386.5255, 1962.7298, 90.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[413], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[414] = CreateDynamicObject(19430, 1646.6009, -1388.0909, 1962.7298, 90.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[414], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[415] = CreateDynamicObject(19430, 1646.6003, -1388.0865, 1961.2905, 90.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_lspdInterior[415], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[416] = CreateDynamicObject(1672, 1645.0483, -1386.8608, 1962.7159, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gasgrenade
    object_lspdInterior[417] = CreateDynamicObject(1672, 1645.0483, -1387.0312, 1962.7159, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gasgrenade
    object_lspdInterior[418] = CreateDynamicObject(1672, 1645.0483, -1387.2014, 1962.7159, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gasgrenade
    object_lspdInterior[419] = CreateDynamicObject(1672, 1645.0483, -1387.3614, 1962.7159, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gasgrenade
    object_lspdInterior[420] = CreateDynamicObject(342, 1645.0156, -1387.5476, 1962.6693, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    object_lspdInterior[421] = CreateDynamicObject(342, 1645.0156, -1387.6977, 1962.6693, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    object_lspdInterior[422] = CreateDynamicObject(342, 1645.0156, -1387.8376, 1962.6693, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    object_lspdInterior[423] = CreateDynamicObject(19142, 1645.0030, -1387.7735, 1961.7624, 0.0000, -90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWATArmour1
    object_lspdInterior[424] = CreateDynamicObject(19142, 1645.0030, -1387.2829, 1961.7624, 0.0000, -90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWATArmour1
    object_lspdInterior[425] = CreateDynamicObject(19142, 1645.0030, -1386.8326, 1961.7624, 0.0000, -90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWATArmour1
    object_lspdInterior[426] = CreateDynamicObject(19141, 1644.9538, -1386.7895, 1963.6086, 0.0000, -90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWATHelmet1
    object_lspdInterior[427] = CreateDynamicObject(19141, 1644.9538, -1387.0898, 1963.6086, 0.0000, -90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWATHelmet1
    object_lspdInterior[428] = CreateDynamicObject(19141, 1644.9538, -1387.8104, 1963.6086, 0.0000, -90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWATHelmet1
    object_lspdInterior[429] = CreateDynamicObject(19141, 1644.9538, -1387.5201, 1963.6086, 0.0000, -90.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWATHelmet1
    object_lspdInterior[430] = CreateDynamicObject(18981, 1649.6750, -1393.1748, 1967.0461, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[430], 0, 13628, "8stad", "stadroof", 0xFFBDBEC6);
    object_lspdInterior[431] = CreateDynamicObject(18075, 1641.3214, -1386.8641, 1966.6058, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_lspdInterior[432] = CreateDynamicObject(19942, 1645.1745, -1382.5206, 1963.3708, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceRadio1
    object_lspdInterior[433] = CreateDynamicObject(19942, 1645.1745, -1381.7298, 1963.3708, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceRadio1
    object_lspdInterior[434] = CreateDynamicObject(19797, 1645.1478, -1382.1208, 1963.3841, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceVisorStrobe1
    object_lspdInterior[435] = CreateDynamicObject(2612, 1646.2829, -1377.8448, 1963.5909, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB2
    object_lspdInterior[436] = CreateDynamicObject(1738, 1646.2495, -1379.0083, 1962.0415, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Radiator_old
    SetDynamicObjectMaterial(object_lspdInterior[436], 0, 1738, "cjtemp", "cj_radiatorOLD", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdInterior[436], 1, 1738, "cjtemp", "cj_radiatorOLD", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdInterior[436], 2, 14704, "lahss2_2int2", "HS_radiator1", 0xFFFFFFFF);
    object_lspdInterior[437] = CreateDynamicObject(19786, 1640.0102, -1380.5511, 1963.6435, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_lspdInterior[437], 0, 10765, "airportgnd_sfse", "white", 0xFF46597A);
    SetDynamicObjectMaterial(object_lspdInterior[437], 1, 7009, "vgndwntwn1", "newpolice_sa", 0xFFFFFFFF);
    object_lspdInterior[438] = CreateDynamicObject(19814, 1637.9331, -1380.4250, 1961.9316, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[439] = CreateDynamicObject(19814, 1642.8540, -1380.4150, 1961.9316, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[440] = CreateDynamicObject(19814, 1633.8525, -1385.9248, 1961.9316, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[441] = CreateDynamicObject(19814, 1629.7021, -1385.9248, 1961.9316, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[442] = CreateDynamicObject(19814, 1622.1909, -1368.4742, 1961.9316, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[443] = CreateDynamicObject(19814, 1623.1318, -1368.4742, 1961.9316, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[444] = CreateDynamicObject(19814, 1631.1728, -1362.5344, 1961.9316, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[445] = CreateDynamicObject(19814, 1631.4232, -1362.5344, 1961.9316, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[446] = CreateDynamicObject(19814, 1632.0238, -1369.4051, 1961.9316, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[447] = CreateDynamicObject(19814, 1631.6534, -1369.4051, 1961.9316, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[448] = CreateDynamicObject(2613, 1629.0378, -1368.2159, 1961.4884, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_WASTEBIN
    object_lspdInterior[449] = CreateDynamicObject(2613, 1635.0987, -1368.2159, 1961.4884, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_WASTEBIN
    object_lspdInterior[450] = CreateDynamicObject(19814, 1649.2419, -1377.8653, 1961.9316, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[451] = CreateDynamicObject(19814, 1648.8717, -1377.8653, 1961.9316, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[452] = CreateDynamicObject(18981, 1658.9824, -1373.7082, 1961.0168, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[452], 0, 14846, "genintintpoliceb", "cop_cellfloor", 0xFFFFFFFF);
    object_lspdInterior[453] = CreateDynamicObject(19464, 1646.4759, -1373.4604, 1958.9819, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[453], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[454] = CreateDynamicObject(1775, 1637.0963, -1383.0931, 1962.5981, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SPRUNK1
    object_lspdInterior[455] = CreateDynamicObject(19464, 1615.9416, -1379.0793, 1961.9132, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[455], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[456] = CreateDynamicObject(2611, 1646.2928, -1376.0858, 1963.5913, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB1
    object_lspdInterior[457] = CreateDynamicObject(2247, 1635.6103, -1369.8376, 1962.9455, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_15
    SetDynamicObjectMaterial(object_lspdInterior[457], 1, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_lspdInterior[458] = CreateDynamicObject(2247, 1627.7286, -1369.8376, 1962.9455, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_15
    SetDynamicObjectMaterial(object_lspdInterior[458], 1, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_lspdInterior[459] = CreateDynamicObject(2922, 1643.0710, -1380.4187, 1963.0279, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_keypad
    object_lspdInterior[460] = CreateDynamicObject(2922, 1643.0909, -1380.6689, 1963.0279, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_keypad
    object_lspdInterior[461] = CreateDynamicObject(19464, 1640.3249, -1380.5522, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[461], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[462] = CreateDynamicObject(19464, 1637.4940, -1383.5113, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[462], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[463] = CreateDynamicObject(19464, 1637.4940, -1389.0924, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[463], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[464] = CreateDynamicObject(19464, 1637.4940, -1388.9333, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[464], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[465] = CreateDynamicObject(19464, 1643.2738, -1388.9377, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[465], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[466] = CreateDynamicObject(19464, 1645.3044, -1388.9333, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[466], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[467] = CreateDynamicObject(19464, 1645.3039, -1383.4641, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[467], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[468] = CreateDynamicObject(19464, 1647.6842, -1380.5642, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[468], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[469] = CreateDynamicObject(19464, 1648.1446, -1383.1942, 1962.8924, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[469], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[470] = CreateDynamicObject(19464, 1648.1446, -1386.4847, 1962.8924, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[470], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[471] = CreateDynamicObject(19464, 1647.7049, -1385.1827, 1964.9228, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[471], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[472] = CreateDynamicObject(19464, 1647.7054, -1384.1334, 1964.9233, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[472], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[473] = CreateDynamicObject(19464, 1640.3248, -1380.5614, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[473], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[474] = CreateDynamicObject(19464, 1646.1745, -1380.5614, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[474], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[475] = CreateDynamicObject(19464, 1642.3646, -1388.9426, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[475], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[476] = CreateDynamicObject(19464, 1640.5134, -1388.9377, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[476], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[477] = CreateDynamicObject(19464, 1637.5023, -1388.9426, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[477], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[478] = CreateDynamicObject(19464, 1637.5023, -1383.6131, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[478], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[479] = CreateDynamicObject(19464, 1645.2917, -1383.6131, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[479], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[480] = CreateDynamicObject(19464, 1645.2917, -1389.5030, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[480], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[481] = CreateDynamicObject(19384, 1643.5489, -1366.7102, 1963.2298, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall032
    SetDynamicObjectMaterial(object_lspdInterior[481], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[482] = CreateDynamicObject(19087, 1641.9315, -1366.7746, 1964.2242, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[482], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[483] = CreateDynamicObject(19175, 1642.4132, -1366.8519, 1963.3292, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[483], 0, "Büro", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_lspdInterior[483], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[484] = CreateDynamicObject(19087, 1640.1706, -1366.7746, 1964.2242, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[484], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[485] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1963.7436, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[485], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[486] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1962.3326, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[486], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[487] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1963.6833, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[487], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[488] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1963.6230, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[488], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[489] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1963.5632, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[489], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[490] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1963.5030, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[490], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[491] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1963.4427, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[491], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[492] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1962.6219, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[492], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[493] = CreateDynamicObject(19087, 1642.0417, -1366.7746, 1963.3830, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[493], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[494] = CreateDynamicObject(19087, 1640.3706, -1366.7746, 1962.6323, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[494], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[495] = CreateDynamicObject(19087, 1641.7307, -1366.7746, 1962.6323, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdInterior[495], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[496] = CreateDynamicObject(2008, 1641.5284, -1366.1229, 1961.4718, 0.0000, 0.0000, -180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //officedesk1
    object_lspdInterior[497] = CreateDynamicObject(1714, 1640.9188, -1364.6970, 1961.4952, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_lspdInterior[498] = CreateDynamicObject(2161, 1639.5107, -1364.7187, 1962.4150, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_lspdInterior[499] = CreateDynamicObject(2165, 1644.1412, -1361.8990, 1961.4643, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    object_lspdInterior[500] = CreateDynamicObject(2165, 1640.9499, -1361.8990, 1961.4643, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    object_lspdInterior[501] = CreateDynamicObject(1714, 1640.4482, -1360.4260, 1961.4952, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_lspdInterior[502] = CreateDynamicObject(1714, 1643.5190, -1360.4260, 1961.4952, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_lspdInterior[503] = CreateDynamicObject(19464, 1641.6982, -1357.8857, 1964.0235, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[503], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[504] = CreateDynamicObject(19464, 1639.3878, -1359.5974, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[504], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[505] = CreateDynamicObject(19464, 1644.7065, -1363.6782, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[505], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[506] = CreateDynamicObject(19464, 1644.7065, -1357.7563, 1964.0235, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[506], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdInterior[507] = CreateDynamicObject(2164, 1641.7391, -1358.0559, 1961.4836, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    object_lspdInterior[508] = CreateDynamicObject(2163, 1639.9870, -1357.8946, 1961.4897, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_lspdInterior[509] = CreateDynamicObject(2163, 1643.4775, -1357.8946, 1961.4897, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_lspdInterior[510] = CreateDynamicObject(2201, 1643.1750, -1361.7242, 1962.2540, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PRINTER_1
    object_lspdInterior[511] = CreateDynamicObject(1811, 1643.6511, -1363.6794, 1962.0710, 0.0000, 0.0000, -74.5998, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_lspdInterior[512] = CreateDynamicObject(1811, 1640.3397, -1363.2750, 1962.0710, 0.0000, 0.0000, -109.3000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_lspdInterior[513] = CreateDynamicObject(19464, 1639.3946, -1359.5626, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[513], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[514] = CreateDynamicObject(19464, 1644.6933, -1359.5626, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[514], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[515] = CreateDynamicObject(19464, 1644.6938, -1363.6627, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[515], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[516] = CreateDynamicObject(19464, 1639.3957, -1359.6208, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[516], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[517] = CreateDynamicObject(19464, 1644.6849, -1359.6208, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[517], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[518] = CreateDynamicObject(19464, 1644.6854, -1363.6324, 1969.0024, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[518], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[519] = CreateDynamicObject(19464, 1642.2441, -1366.6529, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[519], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[520] = CreateDynamicObject(19464, 1641.7436, -1357.9648, 1969.0024, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[520], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[521] = CreateDynamicObject(18981, 1634.0173, -1349.7186, 1967.0561, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdInterior[521], 0, 13628, "8stad", "stadroof", 0xFFBDBEC6);
    object_lspdInterior[522] = CreateDynamicObject(19814, 1639.5327, -1361.2049, 1961.9316, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[523] = CreateDynamicObject(2270, 1640.5412, -1358.5721, 1963.4145, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    SetDynamicObjectMaterial(object_lspdInterior[523], 0, 14489, "carlspics", "AH_picture3", 0xFFFFFFFF);
    object_lspdInterior[524] = CreateDynamicObject(2270, 1643.8116, -1358.5721, 1963.4145, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    SetDynamicObjectMaterial(object_lspdInterior[524], 0, 14489, "carlspics", "AH_picture3", 0xFFFFFFFF);
    object_lspdInterior[525] = CreateDynamicObject(2264, 1642.1417, -1358.5290, 1963.6627, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_5
    SetDynamicObjectMaterial(object_lspdInterior[525], 1, 2254, "picture_frame_clip", "CJ_PAINTING4", 0xFFFFFFFF);
    object_lspdInterior[526] = CreateDynamicObject(2264, 1640.0644, -1362.6391, 1963.5224, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_5
    SetDynamicObjectMaterial(object_lspdInterior[526], 1, 7009, "vgndwntwn1", "newpolice_sa", 0xFFFFFFFF);
    object_lspdInterior[527] = CreateDynamicObject(2264, 1644.0727, -1362.1788, 1963.5224, 0.0000, 0.0000, -90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_5
    SetDynamicObjectMaterial(object_lspdInterior[527], 1, 7009, "vgndwntwn1", "newpolice_sa", 0xFFFFFFFF);
    object_lspdInterior[528] = CreateDynamicObject(19814, 1644.5638, -1361.2049, 1961.9316, 0.0000, 0.0000, 270.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_lspdInterior[529] = CreateDynamicObject(18075, 1644.7314, -1360.2226, 1966.6258, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_lspdInterior[530] = CreateDynamicObject(18075, 1651.1346, -1372.1223, 1966.6258, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_lspdInterior[531] = CreateDynamicObject(19464, 1615.9416, -1375.6787, 1961.9132, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[531], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[532] = CreateDynamicObject(19358, 1617.1573, -1377.3592, 1964.3702, 0.0000, 90.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall006
    SetDynamicObjectMaterial(object_lspdInterior[532], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[533] = CreateDynamicObject(19175, 1652.2939, -1377.8459, 1962.7779, 0.0000, 0.0000, 180.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdInterior[533], 0, "1.80 m", 90, "Arial", 15, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdInterior[533], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdInterior[534] = CreateDynamicObject(19464, 1660.2447, -1377.9731, 1959.0524, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[534], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[535] = CreateDynamicObject(19464, 1659.9351, -1374.9729, 1959.0524, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[535], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[536] = CreateDynamicObject(19464, 1659.9355, -1369.0579, 1959.0520, 0.0000, 0.0000, 0.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[536], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdInterior[537] = CreateDynamicObject(19464, 1659.2553, -1370.8281, 1959.0520, 0.0000, 0.0000, 90.0000, VW_LSPDINTERIOR, MAPS_LSPDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdInterior[537], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);

    object_duty_door_lspdInterior = object_lspdInterior[198];
}