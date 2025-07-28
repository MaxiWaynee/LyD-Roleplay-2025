#include <YSI\y_hooks>

// Global interior define
#define MAPS_BUSSTATION_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

// Bus station in LS points
#define BUSSTATION_JOBSKIN_POINT   1257.3746, -1334.1302, 13.2733
#define BUSSTATION_INFO_POINT1     1257.3948, -1379.4574, 13.2933
#define BUSSTATION_INFO_POINT2     1257.0052, -1297.3274, 13.2804

// Map variables
new object_busStation[22];
new pickup_busStation[1];
new text3D_busStation[3];
new actor_busStation[4];
new vehicle_busStation[4];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_busStation[0] = CreateDynamicPickup(1275, 1, BUSSTATION_JOBSKIN_POINT, VW_MAIN, MAPS_BUSSTATION_INTERIOR); // Job clothes point

    // 3DTextLabels
    text3D_busStation[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Busfahrer\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, BUSSTATION_JOBSKIN_POINT, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BUSSTATION_INTERIOR); // Job clothes point
    text3D_busStation[1] = _:CreateDynamic3DTextLabel("LOS SANTOS - BUSBAHNHOF", COLOR_YELLOW, BUSSTATION_INFO_POINT1, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BUSSTATION_INTERIOR); // Info point
    text3D_busStation[2] = _:CreateDynamic3DTextLabel("LOS SANTOS - BUSBAHNHOF", COLOR_YELLOW, BUSSTATION_INFO_POINT2, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BUSSTATION_INTERIOR); // Info point
    
    // Actors
    actor_busStation[0] = CreateDynamicActor(7, 1256.5770, -1369.8331, 13.2933, 90.4237, .worldid = VW_MAIN, .interiorid = MAPS_BUSSTATION_INTERIOR); // Watch guy
    ApplyDynamicActorAnimation(actor_busStation[0], "MISC", "SEAT_watch", 0.2, 1, 0, 0, 0, 0);
    actor_busStation[1] = CreateDynamicActor(56, 1256.5248, -1349.7919, 13.2933, 93.1852, .worldid = VW_MAIN, .interiorid = MAPS_BUSSTATION_INTERIOR); // Leaning woman
    ApplyDynamicActorAnimation(actor_busStation[1], "MISC", "Plyrlean_loop", 4.0, 1, 0, 0, 0, 0);
    actor_busStation[2] = CreateDynamicActor(255, 1256.7325, -1330.8378, 13.2733, 93.3848, .worldid = VW_MAIN, .interiorid = MAPS_BUSSTATION_INTERIOR); // Smoking driver
    ApplyDynamicActorAnimation(actor_busStation[2], "SMOKING", "M_smkstnd_loop", 4.0, 1, 0, 0, 0, 0);
    actor_busStation[3] = CreateDynamicActor(79, 1257.9977, -1304.9066, 13.4862, 84.9854, .worldid = VW_MAIN, .interiorid = MAPS_BUSSTATION_INTERIOR); // Sleeping hobo
    ApplyDynamicActorAnimation(actor_busStation[3], "CRACK", "crckidle2", 4.0, 1, 0, 0, 0, 0);
    
    // Vehicles
    vehicle_busStation[0] = AddStaticVehicleEx(431, 1252.5062, -1306.5398, 13.2808, 179.3419, 3, 3, 60*10); //Bus
    vehicle_busStation[1] = AddStaticVehicleEx(431, 1252.2013, -1323.8386, 13.2532, 179.7427, 3, 3, 60*10); //Bus
    vehicle_busStation[2] = AddStaticVehicleEx(431, 1252.2871, -1350.3728, 13.2473, 180.2377, 3, 3, 60*10); //Bus
    vehicle_busStation[3] = AddStaticVehicleEx(431, 1252.2953, -1367.1998, 13.2963, 180.0122, 3, 3, 60*10); //Bus

    // Objects
    object_busStation[0] = CreateDynamicObject(8841, 1257.29712, -1316.30408, 15.28890, 0.00000, 0.00000, 270.32339, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[1] = CreateDynamicObject(8841, 1257.35718, -1359.85144, 15.30890, 0.00000, 0.00000, 270.32339, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[2] = CreateDynamicObject(19121, 1257.31323, -1315.53027, 12.88323, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[3] = CreateDynamicObject(19121, 1257.32324, -1300.17322, 12.88323, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[4] = CreateDynamicObject(19121, 1257.24243, -1330.42700, 12.88323, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[5] = CreateDynamicObject(19121, 1257.35754, -1316.55981, 12.88323, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[6] = CreateDynamicObject(19121, 1257.26892, -1343.67639, 12.88323, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[7] = CreateDynamicObject(19121, 1257.25671, -1331.36353, 12.88323, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[8] = CreateDynamicObject(19121, 1257.18958, -1342.71448, 12.88323, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[9] = CreateDynamicObject(19121, 1257.33081, -1358.98279, 12.88323, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[10] = CreateDynamicObject(19121, 1257.39551, -1360.15613, 12.88323, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[11] = CreateDynamicObject(19121, 1257.54321, -1373.91418, 12.88323, 0.00000, 0.00000, 359.73898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[12] = CreateDynamicObject(19121, 1257.49438, -1374.86572, 12.88323, 0.00000, 0.00000, 359.73898, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[13] = CreateDynamicObject(19121, 1257.30981, -1298.94556, 12.88323, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[14] = CreateDynamicObject(1257, 1257.44983, -1304.14331, 13.18869, 0.00000, 0.00000, 359.78564, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[15] = CreateDynamicObject(1280, 1257.21277, -1310.81079, 12.67531, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[16] = CreateDynamicObject(1257, 1257.44983, -1320.43530, 13.18870, 0.00000, 0.00000, 359.78561, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[17] = CreateDynamicObject(1280, 1257.21277, -1326.43066, 12.67530, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[18] = CreateDynamicObject(1257, 1257.44983, -1347.83594, 13.18870, 0.00000, 0.00000, 359.78561, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[19] = CreateDynamicObject(1280, 1257.19177, -1355.09753, 12.67530, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[20] = CreateDynamicObject(1257, 1257.44983, -1363.64429, 13.18870, 0.00000, 0.00000, 359.78561, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStation[21] = CreateDynamicObject(1280, 1257.19177, -1370.01648, 12.67530, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTATION_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}