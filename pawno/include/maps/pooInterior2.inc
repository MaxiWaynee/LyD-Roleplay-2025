#include <YSI\y_hooks>

// Global interior define

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Poo interior points
#define POO_INTERIOR_SPAWN_POINT               1950.7202, -2027.1058, 823.4130
#define POO_INTERIOR_SPAWN_POINT_FACING        180.0
#define POO_INTERIOR_DUTY_POINT                1950.3738, -2032.5636, 823.4130

// Map variables
new object_pooInterior[403];
new pickup_pooInterior[1];
new actor_pooInterior[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, POO_INTERIOR_ROOF_POINT)) { // Roof Exit
            if (Spieler[playerid][pFraktion] != 5) return SendClientMessage(playerid, COLOR_RED, "Du besitzt keine gültige Schlüsselkarte für das Oamt-Gebäude.");
            SetPlayerFacingAngle(playerid, POO_ROOF_POINT_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, POO_ROOF_POINT, MAPS_POOEXTERIOR_INTERIOR, VW_MAIN);
        }
    }
    return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_pooInterior[0] = CreateDynamicPickup(19197, 1, POO_INTERIOR_ROOF_POINT, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR); // Roof Exit

    // Actors
    actor_pooInterior[0] = CreateDynamicActor(71, 1944.6857, -2010.3633, 823.4130, 90.0000, .worldid = VW_POOINTERIOR, .interiorid = MAPS_POOINTERIOR_INTERIOR); // Maindesk
    ApplyDynamicActorAnimation(actor_pooInterior[0], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);

	// Objects
	object_pooInterior[0] = CreateDynamicObject(18981, 1941.1423, -2011.2026, 821.9130, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooInterior[0], 0, 14387, "dr_gsnew", "mp_gs_kitchfloor", 0xFFFFFFFF);
    object_pooInterior[1] = CreateDynamicObject(19450, 1931.8819, -2001.7539, 826.9995, 90.0000, -29.8999, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_pooInterior[1], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[2] = CreateDynamicObject(19450, 1931.0412, -2004.9444, 826.9995, 90.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_pooInterior[2], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[3] = CreateDynamicObject(19450, 1934.4311, -2000.2734, 826.9995, 90.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_pooInterior[3], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[4] = CreateDynamicObject(19464, 1931.0002, -2015.2807, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[4], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[5] = CreateDynamicObject(1522, 1931.6236, -2002.5041, 822.3394, 0.0000, 0.0000, 59.9998, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_pooInterior[5], 0, 11008, "firehouse_sfse", "halldoor01_law", 0xFFFFFFFF);
    object_pooInterior[6] = CreateDynamicObject(19464, 1931.0002, -2009.3409, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[6], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[7] = CreateDynamicObject(19464, 1939.0594, -2000.2308, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[7], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[8] = CreateDynamicObject(19464, 1944.9895, -2000.2308, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[8], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[9] = CreateDynamicObject(19464, 1948.0083, -2003.0799, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[9], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[10] = CreateDynamicObject(19464, 1948.0085, -2008.9427, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[10], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[11] = CreateDynamicObject(19464, 1948.0083, -2014.8497, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[11], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[12] = CreateDynamicObject(19464, 1943.8586, -2017.7508, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[12], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[13] = CreateDynamicObject(19464, 1934.7397, -2017.7508, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[13], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[14] = CreateDynamicObject(19464, 1928.9190, -2017.7448, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[14], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[15] = CreateDynamicObject(19464, 1950.4189, -2003.2601, 826.3865, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[15], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[16] = CreateDynamicObject(19464, 1949.7077, -2017.7448, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[16], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[17] = CreateDynamicObject(19464, 1939.9078, -2017.7448, 828.3369, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[17], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[18] = CreateDynamicObject(19464, 1939.1496, -1997.8210, 826.3865, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[18], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[19] = CreateDynamicObject(18075, 1938.0742, -2008.3333, 826.4345, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_pooInterior[20] = CreateDynamicObject(19464, 1945.0885, -1997.8210, 826.3865, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[20], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[21] = CreateDynamicObject(19464, 1945.0885, -1997.8210, 822.4163, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[21], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[22] = CreateDynamicObject(19464, 1939.1469, -1997.8210, 822.4163, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[22], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[23] = CreateDynamicObject(19464, 1950.4267, -2003.1396, 822.4163, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[23], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[24] = CreateDynamicObject(19464, 1950.4267, -2009.0589, 822.4163, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[24], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[25] = CreateDynamicObject(19464, 1950.4267, -2014.9687, 822.4163, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[25], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[26] = CreateDynamicObject(19464, 1950.4267, -2017.7293, 819.9862, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[26], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[27] = CreateDynamicObject(19464, 1944.4970, -2017.7293, 819.9862, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[27], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[28] = CreateDynamicObject(19464, 1943.8469, -2017.7238, 819.9862, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[28], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[29] = CreateDynamicObject(19464, 1934.7585, -2017.7238, 819.9862, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[29], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[30] = CreateDynamicObject(19464, 1928.8795, -2017.7280, 819.9862, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[30], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[31] = CreateDynamicObject(19464, 1931.0106, -2014.7485, 819.9862, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[31], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[32] = CreateDynamicObject(19464, 1931.0101, -2009.6677, 819.9862, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[32], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[33] = CreateDynamicObject(19387, 1939.3100, -2017.7695, 824.0936, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_pooInterior[33], 0, 6871, "vegascourtbld", "marbletilewal1_256", 0xFFFFFFFF);
    object_pooInterior[34] = CreateDynamicObject(19464, 1950.4189, -2009.1794, 826.3865, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[34], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[35] = CreateDynamicObject(19464, 1950.4189, -2015.1092, 826.3865, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[35], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[36] = CreateDynamicObject(19464, 1944.9880, -2017.7238, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[36], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[37] = CreateDynamicObject(19464, 1939.0571, -2017.7238, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[37], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[38] = CreateDynamicObject(19464, 1933.1263, -2017.7238, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[38], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[39] = CreateDynamicObject(19464, 1931.0063, -2017.7238, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[39], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[40] = CreateDynamicObject(19464, 1931.0063, -2009.6519, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[40], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[41] = CreateDynamicObject(19464, 1931.0058, -2013.2618, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[41], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[42] = CreateDynamicObject(19464, 1948.0083, -2008.9427, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[42], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_pooInterior[43] = CreateDynamicObject(19464, 1950.8393, -2006.0721, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[43], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[44] = CreateDynamicObject(19466, 1945.3288, -2000.3630, 824.5761, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[44], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[45] = CreateDynamicObject(19466, 1931.1352, -2014.7224, 824.4367, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[45], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[46] = CreateDynamicObject(19466, 1931.1352, -2009.3919, 824.4367, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[46], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[47] = CreateDynamicObject(19466, 1947.8762, -2014.7224, 824.4367, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[47], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[48] = CreateDynamicObject(19466, 1947.8762, -2003.2513, 824.4367, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[48], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[49] = CreateDynamicObject(19466, 1945.1754, -2000.3712, 824.4367, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[49], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[50] = CreateDynamicObject(19466, 1939.2452, -2000.3712, 824.4367, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[50], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[51] = CreateDynamicObject(19466, 1931.1297, -2014.5736, 824.5761, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[51], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[52] = CreateDynamicObject(19466, 1931.1306, -2014.5760, 824.2661, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[52], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[53] = CreateDynamicObject(19466, 1931.1301, -2014.8519, 824.2659, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[53], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[54] = CreateDynamicObject(19466, 1931.1291, -2014.8520, 824.5761, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[54], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[55] = CreateDynamicObject(19466, 1947.8800, -2014.8648, 824.5761, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[55], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[56] = CreateDynamicObject(19466, 1947.8792, -2014.8619, 824.2659, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[56], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[57] = CreateDynamicObject(19466, 1947.8790, -2014.5760, 824.2661, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[57], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[58] = CreateDynamicObject(19466, 1947.8797, -2014.5736, 824.5761, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[58], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[59] = CreateDynamicObject(19466, 1947.8792, -2003.3902, 824.2659, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[59], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[60] = CreateDynamicObject(19466, 1947.8797, -2003.0930, 824.5761, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[60], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[61] = CreateDynamicObject(19466, 1931.1306, -2009.5328, 824.5764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[61], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[62] = CreateDynamicObject(19466, 1931.1306, -2009.2358, 824.2661, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[62], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[63] = CreateDynamicObject(19466, 1931.1301, -2009.5328, 824.2659, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[63], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[64] = CreateDynamicObject(19466, 1931.1297, -2009.2325, 824.5761, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[64], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[65] = CreateDynamicObject(19466, 1947.8801, -2003.0930, 824.2659, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[65], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[66] = CreateDynamicObject(19466, 1947.8797, -2003.3933, 824.5761, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[66], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[67] = CreateDynamicObject(19464, 1950.8393, -2011.7928, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[67], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[68] = CreateDynamicObject(19466, 1945.0283, -2000.3658, 824.5761, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[68], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[69] = CreateDynamicObject(19466, 1939.0882, -2000.3658, 824.5761, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[69], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[70] = CreateDynamicObject(19466, 1939.3885, -2000.3620, 824.5761, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[70], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[71] = CreateDynamicObject(19466, 1939.3885, -2000.3690, 824.2860, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[71], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[72] = CreateDynamicObject(19466, 1945.3297, -2000.3690, 824.2860, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[72], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[73] = CreateDynamicObject(19466, 1945.0294, -2000.3708, 824.2860, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[73], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[74] = CreateDynamicObject(19466, 1939.0888, -2000.3708, 824.2860, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[74], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[75] = CreateDynamicObject(18762, 1943.6087, -2015.0974, 822.8247, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[75], 0, 2423, "cj_ff_counters", "shop_floor1", 0xFFFFFFFF);
    object_pooInterior[76] = CreateDynamicObject(18762, 1943.6082, -2010.1262, 822.8242, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[76], 0, 2423, "cj_ff_counters", "shop_floor1", 0xFFFFFFFF);
    object_pooInterior[77] = CreateDynamicObject(2164, 1946.2442, -2017.5842, 822.9909, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    object_pooInterior[78] = CreateDynamicObject(2194, 1943.6085, -2009.0072, 823.6102, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_2
    object_pooInterior[79] = CreateDynamicObject(2194, 1943.6085, -2016.3082, 823.6102, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_2
    object_pooInterior[80] = CreateDynamicObject(1714, 1945.4012, -2015.0083, 822.4008, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_pooInterior[81] = CreateDynamicObject(1714, 1945.4012, -2010.3564, 822.4008, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_pooInterior[82] = CreateDynamicObject(19175, 1947.8846, -2008.0031, 824.8253, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[82], 0, "Los ", 90, "Arial", 60, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[82], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[83] = CreateDynamicObject(19175, 1947.8846, -2009.3636, 824.2346, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[83], 0, "Ordnungs", 90, "Arial", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[83], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[84] = CreateDynamicObject(19175, 1947.8846, -2007.5632, 823.8643, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[84], 0, "_________________________", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[84], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[85] = CreateDynamicObject(19175, 1947.8846, -2011.7745, 824.2448, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[85], 0, "amt", 90, "Arial", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[85], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[86] = CreateDynamicObject(19175, 1947.8846, -2009.1628, 824.8253, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[86], 0, "Santos", 90, "Arial", 60, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[86], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[87] = CreateDynamicObject(19175, 1947.8846, -2010.2630, 823.8643, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[87], 0, "_________________________", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[87], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[88] = CreateDynamicObject(18762, 1931.5827, -2017.2170, 824.3029, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[88], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[89] = CreateDynamicObject(19175, 1947.8846, -2008.7923, 823.1643, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[89], 0, "Herzlich", 90, "Arial", 35, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[89], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[90] = CreateDynamicObject(19175, 1947.8846, -2010.2331, 823.1643, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[90], 0, "Willkommen", 90, "Arial", 35, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[90], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[91] = CreateDynamicObject(18762, 1931.5827, -2007.1164, 824.3029, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[91], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[92] = CreateDynamicObject(18762, 1936.6020, -2000.8244, 824.3029, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[92], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[93] = CreateDynamicObject(18762, 1947.4237, -2000.8244, 824.3029, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[93], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[94] = CreateDynamicObject(18762, 1947.4237, -2017.1656, 824.3029, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[94], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[95] = CreateDynamicObject(18762, 1943.5831, -2017.1656, 824.3029, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[95], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[96] = CreateDynamicObject(18762, 1943.5831, -2008.0948, 824.3029, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[96], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[97] = CreateDynamicObject(18762, 1943.5831, -2012.7257, 824.3029, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[97], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[98] = CreateDynamicObject(1649, 1943.4897, -2010.0434, 826.6370, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_pooInterior[98], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_pooInterior[99] = CreateDynamicObject(1649, 1943.4897, -2010.0434, 826.6370, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_pooInterior[99], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_pooInterior[100] = CreateDynamicObject(1649, 1943.4897, -2014.9422, 826.6370, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_pooInterior[100], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_pooInterior[101] = CreateDynamicObject(1649, 1943.4897, -2014.9422, 826.6370, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_pooInterior[101], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_pooInterior[102] = CreateDynamicObject(19089, 1943.4930, -2008.3397, 824.9729, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_pooInterior[102], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[103] = CreateDynamicObject(19089, 1943.4930, -2009.3603, 824.9729, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_pooInterior[103], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[104] = CreateDynamicObject(19089, 1943.4930, -2008.3397, 826.4230, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_pooInterior[104], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[105] = CreateDynamicObject(19089, 1943.4930, -2009.4803, 826.4230, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_pooInterior[105], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[106] = CreateDynamicObject(19089, 1943.4930, -2008.6096, 832.3527, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_pooInterior[106], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[107] = CreateDynamicObject(19089, 1943.4930, -2012.2210, 832.3527, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_pooInterior[107], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[108] = CreateDynamicObject(19089, 1943.4930, -2016.6513, 832.3527, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_pooInterior[108], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[109] = CreateDynamicObject(19089, 1943.4930, -2013.2298, 832.3527, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_pooInterior[109], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[110] = CreateDynamicObject(19175, 1943.4958, -2011.3033, 825.5548, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[110], 0, "i", 90, "Webdings", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[110], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[111] = CreateDynamicObject(19175, 1943.4958, -2015.8145, 825.5548, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[111], 0, "i", 90, "Webdings", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[111], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[112] = CreateDynamicObject(19175, 1943.4958, -2014.0938, 825.5548, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[112], 0, "i", 90, "Webdings", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[112], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[113] = CreateDynamicObject(19175, 1943.4958, -2009.6313, 825.5548, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[113], 0, "i", 90, "Webdings", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[113], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[114] = CreateDynamicObject(1713, 1935.7373, -2017.0748, 822.3273, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch04
    SetDynamicObjectMaterial(object_pooInterior[114], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_pooInterior[114], 1, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_pooInterior[114], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFBDBEC6);
    object_pooInterior[115] = CreateDynamicObject(1713, 1931.6967, -2015.3957, 822.3273, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch04
    SetDynamicObjectMaterial(object_pooInterior[115], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_pooInterior[115], 1, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_pooInterior[115], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFBDBEC6);
    object_pooInterior[116] = CreateDynamicObject(1713, 1931.6967, -2010.8552, 822.3273, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch04
    SetDynamicObjectMaterial(object_pooInterior[116], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_pooInterior[116], 1, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_pooInterior[116], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFBDBEC6);
    object_pooInterior[117] = CreateDynamicObject(2315, 1934.5404, -2013.1876, 822.3441, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE4
    object_pooInterior[118] = CreateDynamicObject(2852, 1934.4990, -2011.9919, 822.8502, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags02
    object_pooInterior[119] = CreateDynamicObject(19835, 1934.5389, -2013.1512, 822.9199, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_pooInterior[120] = CreateDynamicObject(2002, 1931.6335, -2012.2911, 822.3776, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
    object_pooInterior[121] = CreateDynamicObject(19813, 1931.1263, -2012.8443, 822.6322, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[122] = CreateDynamicObject(19813, 1931.1263, -2011.6933, 822.6322, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[123] = CreateDynamicObject(19813, 1936.4068, -2017.6251, 822.6322, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[124] = CreateDynamicObject(948, 1937.0305, -2017.1101, 822.3707, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
    object_pooInterior[125] = CreateDynamicObject(948, 1932.7701, -2017.1101, 822.3707, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
    object_pooInterior[126] = CreateDynamicObject(948, 1931.6693, -2008.1590, 822.3707, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
    object_pooInterior[127] = CreateDynamicObject(948, 1931.6693, -2016.2496, 822.3707, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
    object_pooInterior[128] = CreateDynamicObject(19464, 1934.0191, -2004.9676, 822.2874, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[128], 0, 15048, "labigsave", "AH_carpet4kb", 0xFFFFFFFF);
    object_pooInterior[129] = CreateDynamicObject(2010, 1943.5125, -2007.1910, 822.4188, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    SetDynamicObjectMaterial(object_pooInterior[129], 1, 16640, "a51", "a51_panels1", 0xFFFFFFFF);
    object_pooInterior[130] = CreateDynamicObject(19464, 1934.0196, -2002.2972, 822.2869, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[130], 0, 15048, "labigsave", "AH_carpet4kb", 0xFFFFFFFF);
    object_pooInterior[131] = CreateDynamicObject(19464, 1934.1092, -1999.9897, 822.2866, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[131], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[132] = CreateDynamicObject(19464, 1934.1092, -2005.0688, 822.2868, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[132], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[133] = CreateDynamicObject(19464, 1928.6660, -2004.4913, 822.3062, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[133], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[134] = CreateDynamicObject(19464, 1934.7264, -1997.9111, 822.3062, 0.0000, 90.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[134], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[135] = CreateDynamicObject(19464, 1929.5041, -2001.1767, 822.3067, 0.0000, 90.0000, -29.7999, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[135], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[136] = CreateDynamicObject(18762, 1931.4124, -2001.9775, 822.4630, 0.0000, 0.0000, -29.8999, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[136], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[137] = CreateDynamicObject(18762, 1931.8177, -2001.2755, 822.4630, 0.0000, 0.0000, -29.8999, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[137], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[138] = CreateDynamicObject(1811, 1942.3702, -2000.8476, 823.0518, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[138], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[139] = CreateDynamicObject(1811, 1941.3100, -2000.8476, 823.0518, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[139], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[140] = CreateDynamicObject(1811, 1943.3706, -2000.8476, 823.0518, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[140], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[141] = CreateDynamicObject(18981, 1941.1423, -2011.2026, 826.9338, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooInterior[141], 0, 3555, "comedhos1_la", "comptroof1", 0xFFFFFFFF);
    object_pooInterior[142] = CreateDynamicObject(18075, 1948.5350, -2008.3333, 826.4345, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_pooInterior[143] = CreateDynamicObject(16779, 1938.2124, -2010.4455, 826.6129, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light02
    object_pooInterior[144] = CreateDynamicObject(16779, 1938.2124, -2006.4144, 826.6129, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light02
    object_pooInterior[145] = CreateDynamicObject(18981, 1948.8735, -2036.2049, 821.9130, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooInterior[145], 0, 14387, "dr_gsnew", "mp_gs_kitchfloor", 0xFFFFFFFF);
    object_pooInterior[146] = CreateDynamicObject(19464, 1943.7790, -2020.7799, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[146], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[147] = CreateDynamicObject(19464, 1934.9964, -2020.7799, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[147], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[148] = CreateDynamicObject(19807, 1943.6428, -2014.0937, 823.3975, 0.0000, 0.0000, 64.3000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Telephone1
    object_pooInterior[149] = CreateDynamicObject(19807, 1943.6827, -2011.6369, 823.3975, 0.0000, 0.0000, 124.5000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Telephone1
    object_pooInterior[150] = CreateDynamicObject(19175, 1934.4543, -2017.5830, 824.5949, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[150], 0, "Los Santos", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[150], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[151] = CreateDynamicObject(19786, 1934.9748, -2017.7254, 824.8582, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_pooInterior[151], 0, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_pooInterior[151], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[152] = CreateDynamicObject(19175, 1933.7740, -2017.6030, 824.4848, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[152], 0, "____________________", 130, "Arial", 25, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[152], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[153] = CreateDynamicObject(19175, 1933.6440, -2017.6030, 824.5949, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[153], 0, "Ordnungsamt", 130, "Arial", 30, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[153], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[154] = CreateDynamicObject(19175, 1934.7646, -2017.6030, 824.4848, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[154], 0, "____________________", 130, "Arial", 25, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[154], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[155] = CreateDynamicObject(19175, 1934.0540, -2017.5830, 824.3048, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[155], 0, "Ankündigung:", 130, "Arial", 25, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[155], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[156] = CreateDynamicObject(19175, 1934.3945, -2017.5830, 824.1046, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[156], 0, "wir rekrutieren neue Ordnungshüter", 130, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[156], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[157] = CreateDynamicObject(19175, 1934.7646, -2017.6030, 823.8543, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[157], 0, "____________________", 130, "Arial", 25, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[157], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[158] = CreateDynamicObject(19175, 1933.7843, -2017.6030, 823.8543, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[158], 0, "____________________", 130, "Arial", 25, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[158], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[159] = CreateDynamicObject(19175, 1934.2641, -2017.5930, 823.6942, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[159], 0, "Web: www.ordnungsamt.gov", 130, "Arial", 20, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[159], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[160] = CreateDynamicObject(19464, 1934.9986, -2025.7091, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[160], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[161] = CreateDynamicObject(2271, 1943.1446, -2025.1291, 824.8555, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_1
    object_pooInterior[162] = CreateDynamicObject(1522, 1935.1911, -2021.6025, 822.3394, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_pooInterior[162], 0, 18008, "intclothesa", "CJ_VICT_DOOR2", 0xFFFFFFFF);
    object_pooInterior[163] = CreateDynamicObject(1811, 1935.5594, -2023.2165, 823.0518, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[163], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[164] = CreateDynamicObject(1522, 1943.6430, -2021.6025, 822.3394, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_pooInterior[164], 0, 2878, "cj_vic", "CJ_VICT_DOOR", 0xFFFFFFFF);
    object_pooInterior[165] = CreateDynamicObject(1811, 1935.5594, -2024.2071, 823.0518, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[165], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[166] = CreateDynamicObject(1811, 1935.5594, -2025.2275, 823.0518, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[166], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[167] = CreateDynamicObject(1811, 1935.5594, -2026.2583, 823.0518, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[167], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[168] = CreateDynamicObject(1811, 1935.5594, -2027.3188, 823.0518, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[168], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[169] = CreateDynamicObject(1811, 1943.2512, -2027.3188, 823.0518, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[169], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[170] = CreateDynamicObject(19464, 1943.7795, -2025.7091, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[170], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[171] = CreateDynamicObject(1811, 1943.2512, -2026.2583, 823.0518, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[171], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[172] = CreateDynamicObject(1811, 1943.2512, -2025.2275, 823.0518, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[172], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[173] = CreateDynamicObject(1811, 1943.2512, -2024.2071, 823.0518, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[173], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[174] = CreateDynamicObject(1811, 1943.2512, -2023.2165, 823.0518, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[174], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[175] = CreateDynamicObject(18762, 1944.0732, -2021.2257, 822.4730, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[175], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[176] = CreateDynamicObject(18762, 1944.0737, -2020.4851, 822.4730, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[176], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[177] = CreateDynamicObject(18762, 1934.7431, -2020.4851, 822.4730, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[177], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[178] = CreateDynamicObject(18762, 1934.7436, -2021.2155, 822.4730, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooInterior[178], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[179] = CreateDynamicObject(19464, 1937.9572, -2017.8039, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[179], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[180] = CreateDynamicObject(19464, 1943.7862, -2017.8039, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[180], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[181] = CreateDynamicObject(19464, 1943.7862, -2017.7539, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[181], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[182] = CreateDynamicObject(19464, 1934.8258, -2017.7539, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[182], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[183] = CreateDynamicObject(2271, 1943.1446, -2023.6385, 824.4652, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_1
    object_pooInterior[184] = CreateDynamicObject(2271, 1943.1446, -2026.6593, 824.4652, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_1
    object_pooInterior[185] = CreateDynamicObject(2256, 1935.1705, -2025.1684, 825.0570, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_Clip_3
    object_pooInterior[186] = CreateDynamicObject(19464, 1935.0360, -2020.8338, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[186], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[187] = CreateDynamicObject(19464, 1943.7462, -2020.8338, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[187], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[188] = CreateDynamicObject(19464, 1943.7462, -2025.7113, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[188], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[189] = CreateDynamicObject(19464, 1935.0360, -2025.7331, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[189], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[190] = CreateDynamicObject(19464, 1935.0072, -2020.7832, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[190], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[191] = CreateDynamicObject(19464, 1935.0072, -2025.6745, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[191], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[192] = CreateDynamicObject(19464, 1943.7573, -2025.6745, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[192], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[193] = CreateDynamicObject(19464, 1943.7573, -2020.8137, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[193], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[194] = CreateDynamicObject(638, 1936.4929, -2018.2619, 822.7227, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_pooInterior[195] = CreateDynamicObject(638, 1942.2237, -2018.2619, 822.7227, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_pooInterior[196] = CreateDynamicObject(18981, 1947.4824, -2036.1613, 826.9338, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooInterior[196], 0, 3555, "comedhos1_la", "comptroof1", 0xFFFFFFFF);
    object_pooInterior[197] = CreateDynamicObject(19565, 1943.6390, -2028.6560, 823.5883, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[197], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[198] = CreateDynamicObject(19565, 1934.8592, -2028.6560, 824.5286, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[198], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[199] = CreateDynamicObject(19565, 1943.6390, -2028.6560, 824.0585, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[199], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[200] = CreateDynamicObject(19565, 1943.6390, -2028.6560, 824.5286, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[200], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[201] = CreateDynamicObject(19565, 1943.6390, -2028.6560, 824.9990, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[201], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[202] = CreateDynamicObject(19565, 1943.6390, -2028.6560, 823.1282, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[202], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[203] = CreateDynamicObject(19565, 1934.8593, -2028.6560, 824.9990, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[203], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[204] = CreateDynamicObject(19565, 1934.8592, -2028.6560, 824.0585, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[204], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[205] = CreateDynamicObject(19565, 1934.8592, -2028.6560, 823.1182, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[205], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[206] = CreateDynamicObject(19565, 1934.8592, -2028.6560, 822.6680, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[206], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[207] = CreateDynamicObject(19565, 1943.6390, -2028.8562, 825.2091, 90.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[207], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[208] = CreateDynamicObject(19565, 1934.8592, -2028.6560, 823.5883, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[208], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[209] = CreateDynamicObject(19565, 1943.6390, -2029.3266, 825.2091, 90.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[209], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[210] = CreateDynamicObject(19565, 1943.6390, -2030.2673, 825.2091, 90.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[210], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[211] = CreateDynamicObject(19565, 1943.6390, -2030.4670, 824.0584, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[211], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[212] = CreateDynamicObject(19565, 1943.6390, -2029.7968, 825.2091, 90.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[212], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[213] = CreateDynamicObject(19565, 1934.8592, -2030.4670, 824.0584, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[213], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[214] = CreateDynamicObject(19565, 1934.8592, -2030.2673, 825.2091, 90.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[214], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[215] = CreateDynamicObject(19565, 1934.8592, -2028.8562, 825.2091, 90.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[215], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[216] = CreateDynamicObject(19565, 1934.8592, -2029.7968, 825.2091, 90.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[216], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[217] = CreateDynamicObject(19565, 1943.6390, -2030.4670, 823.5883, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[217], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[218] = CreateDynamicObject(19565, 1943.6390, -2030.4670, 824.9990, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[218], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[219] = CreateDynamicObject(19565, 1943.6390, -2030.4670, 824.5288, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[219], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[220] = CreateDynamicObject(19565, 1943.6390, -2030.4670, 823.1077, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[220], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[221] = CreateDynamicObject(19565, 1943.6390, -2030.4670, 822.6375, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[221], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[222] = CreateDynamicObject(19565, 1934.8592, -2029.3266, 825.2091, 90.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[222], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[223] = CreateDynamicObject(19565, 1934.8592, -2030.4670, 823.5883, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[223], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[224] = CreateDynamicObject(19565, 1934.8592, -2030.4670, 824.9990, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[224], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[225] = CreateDynamicObject(19565, 1934.8592, -2030.4670, 824.5288, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[225], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[226] = CreateDynamicObject(19565, 1934.8592, -2030.4670, 822.6375, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[226], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[227] = CreateDynamicObject(19565, 1934.8592, -2030.4670, 823.1077, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[227], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[228] = CreateDynamicObject(19565, 1943.6390, -2028.6560, 822.2882, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[228], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[229] = CreateDynamicObject(19565, 1943.6390, -2028.6560, 822.6981, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[229], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[230] = CreateDynamicObject(19464, 1943.7799, -2031.6209, 827.7365, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[230], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[231] = CreateDynamicObject(19464, 1934.9895, -2031.6209, 827.7365, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[231], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[232] = CreateDynamicObject(19464, 1934.9964, -2033.4199, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[232], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[233] = CreateDynamicObject(19464, 1943.7874, -2033.4199, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[233], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[234] = CreateDynamicObject(19464, 1940.6878, -2035.6894, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[234], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[235] = CreateDynamicObject(19464, 1934.7878, -2035.6928, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[235], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[236] = CreateDynamicObject(19464, 1943.7573, -2031.5843, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[236], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[237] = CreateDynamicObject(19464, 1943.7573, -2037.5041, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[237], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[238] = CreateDynamicObject(19464, 1935.0163, -2037.5041, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[238], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[239] = CreateDynamicObject(19464, 1935.0163, -2031.5533, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[239], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[240] = CreateDynamicObject(19464, 1935.0360, -2033.3841, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[240], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[241] = CreateDynamicObject(19464, 1943.7772, -2033.3841, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[241], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[242] = CreateDynamicObject(19464, 1940.6877, -2035.6649, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[242], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[243] = CreateDynamicObject(19464, 1938.1274, -2035.6649, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[243], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[244] = CreateDynamicObject(19464, 1938.1274, -2035.6649, 828.8062, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[244], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[245] = CreateDynamicObject(19464, 1940.6684, -2035.6649, 828.8062, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[245], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[246] = CreateDynamicObject(19466, 1937.3944, -2035.5407, 824.4367, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[246], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[247] = CreateDynamicObject(19466, 1941.4256, -2035.5509, 824.4367, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[247], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[248] = CreateDynamicObject(18981, 1924.0517, -2036.2049, 821.9099, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooInterior[248], 0, 14387, "dr_gsnew", "mp_gs_kitchfloor", 0xFFFFFFFF);
    object_pooInterior[249] = CreateDynamicObject(19464, 1946.8375, -2034.2506, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[249], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[250] = CreateDynamicObject(19464, 1946.8375, -2024.3603, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[250], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[251] = CreateDynamicObject(19464, 1953.7478, -2027.1905, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[251], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[252] = CreateDynamicObject(19464, 1953.7478, -2033.1302, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[252], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[253] = CreateDynamicObject(19464, 1952.7761, -2034.2506, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[253], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[254] = CreateDynamicObject(19464, 1952.7475, -2024.3603, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[254], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[255] = CreateDynamicObject(19464, 1943.7972, -2027.2940, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[255], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[256] = CreateDynamicObject(19464, 1943.7972, -2033.2143, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[256], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[257] = CreateDynamicObject(19464, 1953.7176, -2033.2143, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[257], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[258] = CreateDynamicObject(19464, 1953.7176, -2027.2735, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[258], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[259] = CreateDynamicObject(19464, 1950.7275, -2024.3636, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[259], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[260] = CreateDynamicObject(19464, 1946.8183, -2024.3636, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[260], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[261] = CreateDynamicObject(19464, 1950.7087, -2034.2242, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[261], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[262] = CreateDynamicObject(19464, 1946.8778, -2034.2242, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[262], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[263] = CreateDynamicObject(19464, 1943.8371, -2033.3841, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[263], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[264] = CreateDynamicObject(19464, 1943.8371, -2025.6643, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[264], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[265] = CreateDynamicObject(19464, 1953.7181, -2025.6643, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[265], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[266] = CreateDynamicObject(19464, 1953.7181, -2031.5732, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[266], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[267] = CreateDynamicObject(19464, 1950.7280, -2024.3924, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[267], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[268] = CreateDynamicObject(19464, 1946.9079, -2024.3924, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[268], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[269] = CreateDynamicObject(19464, 1946.9079, -2034.2342, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[269], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[270] = CreateDynamicObject(19464, 1952.7669, -2034.2342, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[270], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[271] = CreateDynamicObject(11729, 1951.0793, -2033.8420, 822.3690, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    object_pooInterior[272] = CreateDynamicObject(11729, 1950.4189, -2033.8420, 822.3690, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    object_pooInterior[273] = CreateDynamicObject(11730, 1949.7464, -2033.8426, 822.3690, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
    object_pooInterior[274] = CreateDynamicObject(11730, 1946.4566, -2033.8426, 822.3690, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
    object_pooInterior[275] = CreateDynamicObject(11729, 1947.1280, -2033.8420, 822.3690, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    object_pooInterior[276] = CreateDynamicObject(1744, 1948.9276, -2034.2625, 822.4575, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_pooInterior[277] = CreateDynamicObject(1744, 1952.9681, -2034.2625, 822.4575, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_pooInterior[278] = CreateDynamicObject(1744, 1945.4985, -2034.2625, 822.4575, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_pooInterior[279] = CreateDynamicObject(14819, 1944.8978, -2024.5760, 823.5524, 0.0000, 0.0000, -180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Door to roof
    object_pooInterior[280] = CreateDynamicObject(1744, 1952.0089, -2024.3210, 822.4575, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_pooInterior[281] = CreateDynamicObject(11729, 1951.0793, -2024.7110, 822.3690, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
    object_pooInterior[282] = CreateDynamicObject(11730, 1950.4068, -2024.7020, 822.3690, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
    object_pooInterior[283] = CreateDynamicObject(11730, 1949.7364, -2024.7020, 822.3690, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
    object_pooInterior[284] = CreateDynamicObject(19175, 1944.4941, -2024.5609, 824.1935, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[284], 0, "Dach", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_pooInterior[284], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[285] = CreateDynamicObject(19565, 1944.4792, -2024.5208, 824.0584, 0.0000, 0.0000, -180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[285], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[286] = CreateDynamicObject(1744, 1947.9284, -2024.3210, 822.4575, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_pooInterior[287] = CreateDynamicObject(1744, 1953.7885, -2030.7523, 823.4077, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_pooInterior[288] = CreateDynamicObject(1744, 1953.7885, -2026.6816, 823.4077, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_pooInterior[289] = CreateDynamicObject(1744, 1953.7885, -2028.6926, 823.8776, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_pooInterior[290] = CreateDynamicObject(365, 1953.4156, -2027.8120, 823.9124, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[291] = CreateDynamicObject(365, 1953.4156, -2027.5816, 823.9124, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[292] = CreateDynamicObject(365, 1953.4156, -2027.3514, 823.9124, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[293] = CreateDynamicObject(365, 1953.4156, -2027.1113, 823.9124, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[294] = CreateDynamicObject(365, 1953.4156, -2026.8811, 823.9124, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[295] = CreateDynamicObject(365, 1953.3355, -2026.9912, 823.9124, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[296] = CreateDynamicObject(365, 1953.3355, -2027.2512, 823.9124, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[297] = CreateDynamicObject(365, 1953.3355, -2027.7115, 823.9124, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[298] = CreateDynamicObject(365, 1953.4056, -2026.5631, 823.7329, 93.1998, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //spraycan
    object_pooInterior[299] = CreateDynamicObject(348, 1953.4553, -2030.0017, 824.2247, 90.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_pooInterior[300] = CreateDynamicObject(348, 1953.4553, -2029.5312, 824.2247, 90.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_pooInterior[301] = CreateDynamicObject(348, 1953.4553, -2029.1108, 824.2247, 90.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_pooInterior[302] = CreateDynamicObject(348, 1953.4553, -2028.6704, 824.2247, 90.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_pooInterior[303] = CreateDynamicObject(19904, 1953.4561, -2031.7790, 824.0313, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ConstructionVest1
    object_pooInterior[304] = CreateDynamicObject(19904, 1953.4561, -2030.6882, 824.0313, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ConstructionVest1
    object_pooInterior[305] = CreateDynamicObject(19904, 1953.4561, -2031.2485, 824.0313, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ConstructionVest1
    object_pooInterior[306] = CreateDynamicObject(11706, 1953.3836, -2029.2302, 822.3718, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
    object_pooInterior[307] = CreateDynamicObject(19565, 1935.0887, -2030.7274, 824.0584, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[307], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[308] = CreateDynamicObject(19565, 1943.6889, -2030.7274, 824.0584, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[308], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[309] = CreateDynamicObject(19175, 1943.6573, -2031.8823, 823.5145, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[309], 0, "Ausrüstungsraum", 130, "Arial", 22, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[309], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[310] = CreateDynamicObject(19565, 1943.6889, -2031.1977, 824.0584, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[310], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[311] = CreateDynamicObject(19175, 1935.1253, -2029.8814, 823.5443, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[311], 0, "Büroraum", 130, "Arial", 28, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[311], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[312] = CreateDynamicObject(19565, 1935.0887, -2031.1977, 824.0584, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[312], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[313] = CreateDynamicObject(2886, 1943.8679, -2028.1568, 823.9624, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sec_keypad
    object_pooInterior[314] = CreateDynamicObject(2886, 1943.6977, -2030.9575, 823.7622, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sec_keypad
    object_pooInterior[315] = CreateDynamicObject(19464, 1928.8575, -2035.6928, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[315], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[316] = CreateDynamicObject(19464, 1925.8066, -2032.6340, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[316], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[317] = CreateDynamicObject(19464, 1925.8072, -2026.7541, 824.8764, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[317], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[318] = CreateDynamicObject(19464, 1928.8575, -2023.7127, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[318], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[319] = CreateDynamicObject(19464, 1931.9477, -2023.7159, 824.8764, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[319], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooInterior[320] = CreateDynamicObject(18981, 1922.4217, -2036.1613, 826.9343, 0.0000, 90.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooInterior[320], 0, 3555, "comedhos1_la", "comptroof1", 0xFFFFFFFF);
    object_pooInterior[321] = CreateDynamicObject(2184, 1931.5860, -2032.2091, 822.3892, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_DESK_2
    object_pooInterior[322] = CreateDynamicObject(2184, 1929.5456, -2026.5476, 822.3892, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_DESK_2
    object_pooInterior[323] = CreateDynamicObject(2190, 1931.2391, -2026.5096, 823.1787, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PC_1
    object_pooInterior[324] = CreateDynamicObject(19808, 1931.2065, -2025.7652, 823.1885, 0.0000, 0.0000, -156.4998, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_pooInterior[325] = CreateDynamicObject(19808, 1929.9553, -2032.9117, 823.1885, 0.0000, 0.0000, 20.9999, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_pooInterior[326] = CreateDynamicObject(2190, 1929.9290, -2032.1699, 823.1787, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PC_1
    object_pooInterior[327] = CreateDynamicObject(2855, 1931.1789, -2032.5782, 823.1754, 0.0000, 0.0000, -22.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags05
    object_pooInterior[328] = CreateDynamicObject(1714, 1930.5550, -2024.4278, 822.3836, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_pooInterior[329] = CreateDynamicObject(1714, 1930.5550, -2034.6490, 822.3836, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_pooInterior[330] = CreateDynamicObject(1811, 1931.3924, -2030.4837, 823.0017, 0.0000, 0.0000, 77.1998, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[330], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[331] = CreateDynamicObject(1811, 1929.7116, -2030.4836, 823.0017, 0.0000, 0.0000, 108.1998, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[331], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[332] = CreateDynamicObject(1811, 1929.6435, -2028.3436, 823.0017, 0.0000, 0.0000, -104.4999, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[332], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[333] = CreateDynamicObject(1811, 1931.1998, -2028.3713, 823.0017, 0.0000, 0.0000, -78.3999, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_pooInterior[333], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
    object_pooInterior[334] = CreateDynamicObject(2161, 1933.2419, -2035.5412, 823.1220, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_pooInterior[335] = CreateDynamicObject(2161, 1928.2502, -2035.5412, 823.1220, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_pooInterior[336] = CreateDynamicObject(2161, 1927.8901, -2023.9310, 823.1220, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_pooInterior[337] = CreateDynamicObject(2161, 1932.8709, -2023.9310, 823.1220, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_pooInterior[338] = CreateDynamicObject(19825, 1930.5844, -2023.9154, 825.1165, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
    object_pooInterior[339] = CreateDynamicObject(19825, 1930.5844, -2035.5257, 825.1165, 0.0000, 0.0000, 180.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
    object_pooInterior[340] = CreateDynamicObject(2162, 1934.8570, -2031.5498, 822.3745, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_pooInterior[341] = CreateDynamicObject(2162, 1934.8570, -2026.7777, 822.3745, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_pooInterior[342] = CreateDynamicObject(2163, 1935.0052, -2024.9505, 823.8087, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_pooInterior[343] = CreateDynamicObject(2163, 1935.0052, -2033.2425, 823.8087, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_pooInterior[344] = CreateDynamicObject(11706, 1934.6125, -2034.0112, 822.3446, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
    object_pooInterior[345] = CreateDynamicObject(11706, 1934.6125, -2025.2097, 822.3446, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
    object_pooInterior[346] = CreateDynamicObject(19466, 1925.9489, -2032.3802, 824.4367, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[346], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[347] = CreateDynamicObject(19466, 1925.9489, -2026.8398, 824.4367, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[347], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooInterior[348] = CreateDynamicObject(18075, 1939.3552, -2027.1855, 826.4345, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_pooInterior[349] = CreateDynamicObject(18075, 1948.6175, -2027.1855, 826.4345, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_pooInterior[350] = CreateDynamicObject(18075, 1930.1966, -2027.1855, 826.4345, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_pooInterior[351] = CreateDynamicObject(19464, 1934.9865, -2033.3841, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[351], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[352] = CreateDynamicObject(19464, 1934.9865, -2025.7127, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[352], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[353] = CreateDynamicObject(19464, 1931.9881, -2023.7330, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[353], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[354] = CreateDynamicObject(19464, 1926.1585, -2023.7330, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[354], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[355] = CreateDynamicObject(19464, 1928.6883, -2035.6743, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[355], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[356] = CreateDynamicObject(19464, 1932.0290, -2035.6743, 819.9758, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[356], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[357] = CreateDynamicObject(19464, 1925.8386, -2032.6345, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[357], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[358] = CreateDynamicObject(19464, 1925.8386, -2026.8232, 819.9758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[358], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[359] = CreateDynamicObject(19464, 1934.9875, -2032.6544, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[359], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[360] = CreateDynamicObject(19464, 1934.9875, -2026.7148, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[360], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[361] = CreateDynamicObject(19464, 1925.8270, -2026.7148, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[361], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[362] = CreateDynamicObject(19464, 1925.8270, -2032.5753, 828.8159, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[362], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[363] = CreateDynamicObject(19464, 1928.9173, -2035.6744, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[363], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[364] = CreateDynamicObject(19464, 1931.9383, -2035.6744, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[364], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[365] = CreateDynamicObject(19464, 1931.9383, -2023.7343, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[365], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[366] = CreateDynamicObject(19464, 1928.8082, -2023.7343, 828.8159, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooInterior[366], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_pooInterior[367] = CreateDynamicObject(19813, 1934.8587, -2030.7943, 822.6386, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[368] = CreateDynamicObject(19813, 1934.8587, -2028.3634, 822.6386, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[369] = CreateDynamicObject(16779, 1939.4023, -2027.0750, 826.6129, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light02
    object_pooInterior[370] = CreateDynamicObject(16779, 1930.0311, -2029.4256, 826.6129, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light02
    object_pooInterior[371] = CreateDynamicObject(19813, 1943.6495, -2028.1141, 822.6386, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[372] = CreateDynamicObject(19813, 1935.1296, -2028.1141, 822.6386, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[373] = CreateDynamicObject(19813, 1942.8797, -2000.3546, 822.6386, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[374] = CreateDynamicObject(19813, 1941.7989, -2000.3546, 822.6386, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet1
    object_pooInterior[375] = CreateDynamicObject(19565, 1943.6883, -2021.9449, 824.0584, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[375], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[376] = CreateDynamicObject(19565, 1935.1367, -2021.9449, 824.0584, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_pooInterior[376], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[377] = CreateDynamicObject(19175, 1935.1655, -2020.8010, 823.5443, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[377], 0, "Damen", 130, "Arial", 28, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[377], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[378] = CreateDynamicObject(2270, 1943.1688, -2033.1207, 824.4390, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    object_pooInterior[379] = CreateDynamicObject(19175, 1943.6472, -2023.1013, 823.5443, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooInterior[379], 0, "Herren", 130, "Arial", 28, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooInterior[379], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooInterior[380] = CreateDynamicObject(2270, 1943.1688, -2032.3299, 823.8886, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    object_pooInterior[381] = CreateDynamicObject(2270, 1943.1688, -2034.0814, 823.9390, 0.0000, 0.0000, -90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    object_pooInterior[382] = CreateDynamicObject(2270, 1935.6179, -2033.9613, 823.9390, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    object_pooInterior[383] = CreateDynamicObject(2270, 1935.6179, -2032.1710, 823.9390, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    object_pooInterior[384] = CreateDynamicObject(2270, 1935.6179, -2033.0611, 824.3491, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_6
    object_pooInterior[385] = CreateDynamicObject(19466, 1941.2397, -2035.5526, 824.5761, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[385], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[386] = CreateDynamicObject(19466, 1941.2392, -2035.5550, 824.2659, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[386], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[387] = CreateDynamicObject(19466, 1941.5997, -2035.5578, 824.2659, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[387], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[388] = CreateDynamicObject(19466, 1941.5997, -2035.5610, 824.5761, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[388], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[389] = CreateDynamicObject(19466, 1937.5791, -2035.5610, 824.5761, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[389], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[390] = CreateDynamicObject(19466, 1937.2287, -2035.5578, 824.5761, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[390], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[391] = CreateDynamicObject(19466, 1937.2287, -2035.5539, 824.2760, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[391], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[392] = CreateDynamicObject(19466, 1937.5792, -2035.5500, 824.2760, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[392], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[393] = CreateDynamicObject(19466, 1925.9384, -2032.4995, 824.2760, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[393], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[394] = CreateDynamicObject(19466, 1925.9388, -2032.4995, 824.5560, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[394], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[395] = CreateDynamicObject(19466, 1925.9389, -2032.2392, 824.5560, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[395], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[396] = CreateDynamicObject(19466, 1925.9394, -2032.2392, 824.2758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[396], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[397] = CreateDynamicObject(19466, 1925.9394, -2026.7076, 824.2758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[397], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[398] = CreateDynamicObject(19466, 1925.9388, -2026.7076, 824.5460, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[398], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[399] = CreateDynamicObject(19466, 1925.9383, -2026.9979, 824.5460, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[399], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[400] = CreateDynamicObject(19466, 1925.9381, -2026.9979, 824.2758, 0.0000, 0.0000, 0.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooInterior[400], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_pooInterior[401] = CreateDynamicObject(19893, 1943.7817, -2010.3653, 823.3293, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_pooInterior[402] = CreateDynamicObject(19893, 1943.7817, -2015.1053, 823.3293, 0.0000, 0.0000, 90.0000, VW_POOINTERIOR, MAPS_POOINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
}