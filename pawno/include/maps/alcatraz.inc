#include <YSI\y_hooks>

// Global interior define
#define MAPS_ALCATRAZ_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Alcatraz points
#define ALCATRAZ_ENTER_COORDS                       2870.9389, 1906.0322, 11.5510
#define ALCATRAZ_EXIT_COORDS                        2871.0166, 1902.7819, 11.5510
#define ALCATRAZ_ENTER_FACING                       0.0
#define ALCATRAZ_EXIT_FACING                        180.0
#define ALCATRAZ_JAIL_SPAWN_POINT                   2871.1125, 1898.9609, 11.5510
#define ALCATRAZ_JAIL_SPAWN_FACING                  180.0
#define ALCATRAZ_ENTRANCEGATE_FOR_RANGE_COORDS      2884.3974, 1979.0788, 13.2719
#define ALCATRAZ_ENTRANCEGATE_OPEN_Z				7.7619
#define ALCATRAZ_ENTRANCEGATE_CLOSED_Z			    13.2719
#define ALCATRAZ_GARAGEGATE_FOR_RANGE_COORDS        2876.6022, 1934.2126, 11.5500
#define ALCATRAZ_GARAGEGATE_OPEN_Z				    8.8078
#define ALCATRAZ_GARAGEGATE_CLOSED_Z			    12.2278
#define ALCATRAZ_JAILEDGATE_COORDS                  2882.5500, 1875.3200, 12.1500
#define ALCATRAZ_FREED_COORDS                       2885.0900, 1875.3900, 11.5500
#define ALCATRAZ_FREED_FACING                       270.0

// Map variables
new object_alcatraz[411];
new pickup_alcatraz[2];
new object_alcatraz_entranceGate;
new object_alcatraz_garageGate;
// using vehicle_lspdExterior for the alcatraz vehicles

CMD:agate(playerid, params[]) {
    if (!IsPlayerExecutive(playerid))
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Staatsbeamter.");

	if (IsPlayerInRangeOfPoint(playerid, 10.0, ALCATRAZ_ENTRANCEGATE_FOR_RANGE_COORDS)) {
        new Float:fX, Float:fY, Float:fZ;
        GetDynamicObjectPos(object_alcatraz_entranceGate, fX, fY, fZ);
        
        if (fZ == ALCATRAZ_ENTRANCEGATE_OPEN_Z) {
            if (alcatrazGateHackTimeout > gettime())
                return SendClientMessage(playerid, COLOR_RED, "Das Tor wurde gehackt und kann noch nicht wieder geschlossen werden.");

            MoveDynamicObject(object_alcatraz_entranceGate, fX, fY, ALCATRAZ_ENTRANCEGATE_CLOSED_Z, 2.0);
        }
        else
            MoveDynamicObject(object_alcatraz_entranceGate, fX, fY, ALCATRAZ_ENTRANCEGATE_OPEN_Z, 2.0);

        return 1;
    } else if (IsPlayerInRangeOfPoint(playerid, 10.0, ALCATRAZ_GARAGEGATE_FOR_RANGE_COORDS)) {
        new Float:fX, Float:fY, Float:fZ;
        GetDynamicObjectPos(object_alcatraz_garageGate, fX, fY, fZ);
        
        if (fZ == ALCATRAZ_GARAGEGATE_OPEN_Z)
            MoveDynamicObject(object_alcatraz_garageGate, fX, fY, ALCATRAZ_GARAGEGATE_CLOSED_Z, 2.0);
        else
            MoveDynamicObject(object_alcatraz_garageGate, fX, fY, ALCATRAZ_GARAGEGATE_OPEN_Z, 2.0);

        return 1;
    }
    
    return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Tores.");
}

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerExecutive(playerid) && IsPlayerInRangeOfPoint(playerid, 2.0, ALCATRAZ_ENTER_COORDS)) {
            SetPlayerFacingAngle(playerid, ALCATRAZ_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPos(playerid, ALCATRAZ_EXIT_COORDS);
			return 1;
        } else if (IsPlayerExecutive(playerid) && IsPlayerInRangeOfPoint(playerid, 2.0, ALCATRAZ_EXIT_COORDS)) {
            SetPlayerFacingAngle(playerid, ALCATRAZ_ENTER_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPos(playerid, ALCATRAZ_ENTER_COORDS);
			return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Pickups    
    pickup_alcatraz[0] = CreateDynamicPickup(19197, 1, ALCATRAZ_ENTER_COORDS, VW_MAIN, MAPS_ALCATRAZ_INTERIOR); // Enter point
    pickup_alcatraz[1] = CreateDynamicPickup(19197, 1, ALCATRAZ_EXIT_COORDS, VW_MAIN, MAPS_ALCATRAZ_INTERIOR); // Exit point

    // 3DTextLabels

    // Vehicles

    // Objects
    object_alcatraz[0] = CreateDynamicObject(2961, 2869.3137, 1853.4460, 11.9336, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire_break
    object_alcatraz[1] = CreateDynamicObject(19340, 2859.4611, 1893.7888, 6.8010, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //cslab01
    object_alcatraz[2] = CreateDynamicObject(19446, 2879.7856, 1858.5615, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[2], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[3] = CreateDynamicObject(987, 2815.0717, 1807.0278, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[4] = CreateDynamicObject(18450, 2885.3989, 2170.0874, 10.2327, 0.0000, 0.0000, -89.8999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cs_roadbridge04
    object_alcatraz[5] = CreateDynamicObject(987, 2815.1718, 1818.9195, 10.5452, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[6] = CreateDynamicObject(18803, 2884.9411, 2055.2976, 10.2313, 0.0000, 0.0000, -90.4000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MBridge150m1
    object_alcatraz[7] = CreateDynamicObject(18450, 2885.2675, 2238.7780, 10.2131, 0.0000, 0.0000, -89.8999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cs_roadbridge04
    object_alcatraz[8] = CreateDynamicObject(18802, 2885.1970, 2286.7246, 8.1246, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MBridgeRamp1
    object_alcatraz[9] = CreateDynamicObject(987, 2815.1718, 1854.9237, 10.5452, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[10] = CreateDynamicObject(987, 2815.1718, 1830.9211, 10.5452, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[11] = CreateDynamicObject(987, 2815.1718, 1842.9228, 10.5452, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[12] = CreateDynamicObject(987, 2815.1718, 1866.9259, 10.5452, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[13] = CreateDynamicObject(987, 2815.1718, 1878.9267, 10.5452, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[14] = CreateDynamicObject(10932, 2843.7797, 1875.1197, 16.4794, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //station03_SFS
    object_alcatraz[15] = CreateDynamicObject(987, 2815.1718, 1890.9272, 10.5452, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[16] = CreateDynamicObject(987, 2875.0703, 1807.0278, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[17] = CreateDynamicObject(987, 2815.1718, 1902.9267, 10.5452, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[18] = CreateDynamicObject(987, 2865.2607, 1979.8288, 10.5389, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[19] = CreateDynamicObject(3601, 2896.0292, 1973.2441, 18.0631, 0.0000, 0.0000, -0.7997, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hillhouse04_LA
    SetDynamicObjectMaterial(object_alcatraz[19], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_alcatraz[19], 1, 14534, "ab_wooziea", "mcstraps_window", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_alcatraz[19], 3, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_alcatraz[19], 4, 13077, "cunte_bar1", "alleydoor4", 0xFFFFFFFF);
    object_alcatraz[20] = CreateDynamicObject(11353, 2824.2119, 1875.2330, 13.5850, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //station5new
    object_alcatraz[21] = CreateDynamicObject(3268, 2866.6491, 1934.1815, 10.5256, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mil_hangar1_
    object_alcatraz[22] = CreateDynamicObject(10763, 2837.3813, 1898.8264, 13.5710, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //controltower_SFSe
    object_alcatraz[23] = CreateDynamicObject(987, 2853.3203, 1967.9344, 10.5192, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[24] = CreateDynamicObject(987, 2853.3203, 1955.9322, 10.5192, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[25] = CreateDynamicObject(987, 2903.7297, 1955.9277, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[26] = CreateDynamicObject(987, 2903.7297, 1943.9282, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[27] = CreateDynamicObject(987, 2903.7297, 1931.9276, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[28] = CreateDynamicObject(17969, 2870.7089, 1980.7783, 13.2454, 6.3000, 0.0000, -90.9000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hub_graffitti
    object_alcatraz[29] = CreateDynamicObject(987, 2903.7297, 1919.9276, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[30] = CreateDynamicObject(987, 2827.0717, 1807.0278, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[31] = CreateDynamicObject(987, 2851.0703, 1807.0278, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[32] = CreateDynamicObject(987, 2839.0703, 1807.0278, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[33] = CreateDynamicObject(987, 2903.7897, 1979.8288, 10.5389, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[34] = CreateDynamicObject(987, 2863.0710, 1807.0278, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[35] = CreateDynamicObject(10763, 2921.1630, 1803.1252, 13.5710, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //controltower_SFSe
    object_alcatraz[36] = CreateDynamicObject(987, 2887.0673, 1807.0278, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[37] = CreateDynamicObject(987, 2877.2614, 1979.8288, 10.5389, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[38] = CreateDynamicObject(3601, 2872.2707, 1973.1892, 18.0631, 0.0000, 0.0000, -0.7997, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hillhouse04_LA
    SetDynamicObjectMaterial(object_alcatraz[38], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_alcatraz[38], 1, 14534, "ab_wooziea", "mcstraps_window", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_alcatraz[38], 3, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_alcatraz[38], 4, 13077, "cunte_bar1", "alleydoor4", 0xFFFFFFFF);
    object_alcatraz[39] = CreateDynamicObject(987, 2853.3203, 1979.9333, 10.5192, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[40] = CreateDynamicObject(987, 2853.3203, 1943.9316, 10.5192, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[41] = CreateDynamicObject(987, 2853.3203, 1931.9331, 10.5192, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[42] = CreateDynamicObject(987, 2853.3203, 1919.9333, 10.5192, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[43] = CreateDynamicObject(987, 2832.0446, 1908.0666, 10.5452, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[44] = CreateDynamicObject(987, 2841.0322, 1908.0666, 10.5452, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[45] = CreateDynamicObject(987, 2853.0314, 1908.0666, 10.5452, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[46] = CreateDynamicObject(18980, 2884.3395, 1979.0726, 16.5450, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_alcatraz[46], 0, 18065, "ab_sfammumain", "pavea256", 0xFFFFFFFF);
    object_alcatraz[47] = CreateDynamicObject(987, 2903.7297, 1967.9276, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[48] = CreateDynamicObject(987, 2903.7297, 1907.9300, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[49] = CreateDynamicObject(987, 2903.7297, 1895.9305, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[50] = CreateDynamicObject(987, 2903.7297, 1883.9322, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[51] = CreateDynamicObject(987, 2903.7297, 1871.9322, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[52] = CreateDynamicObject(987, 2903.7297, 1859.9320, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[53] = CreateDynamicObject(987, 2903.7297, 1847.9322, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[54] = CreateDynamicObject(987, 2903.7297, 1835.9342, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[55] = CreateDynamicObject(987, 2903.7297, 1823.9349, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[56] = CreateDynamicObject(987, 2903.7297, 1811.9353, 10.5389, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //elecfence_BAR
    object_alcatraz[57] = CreateDynamicObject(19379, 2881.4548, 1854.7159, 13.6251, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[57], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[58] = CreateDynamicObject(8661, 2844.7614, 1902.3714, 8.1049, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_alcatraz[58], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[59] = CreateDynamicObject(19362, 2863.8256, 1851.6086, 9.0232, 0.0000, 0.0000, 0.1999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    SetDynamicObjectMaterial(object_alcatraz[59], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[60] = CreateDynamicObject(19446, 2867.6977, 1855.2226, 14.3267, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[60], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[61] = CreateDynamicObject(19446, 2877.3266, 1855.2226, 14.3247, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[61], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[62] = CreateDynamicObject(8661, 2844.7614, 1902.3714, 8.1049, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_alcatraz[62], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[63] = CreateDynamicObject(8661, 2845.1818, 1848.0913, 8.1049, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_alcatraz[63], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[64] = CreateDynamicObject(8661, 2845.1818, 1848.0913, 8.1049, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_alcatraz[64], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[65] = CreateDynamicObject(19446, 2867.6879, 1851.7226, 14.3247, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[65], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[66] = CreateDynamicObject(19379, 2863.8393, 1851.5793, 13.8149, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[66], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[67] = CreateDynamicObject(1523, 2869.4760, 1853.9947, 10.5368, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT10
    object_alcatraz[68] = CreateDynamicObject(19408, 2869.3967, 1851.5810, 12.3079, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall056
    SetDynamicObjectMaterial(object_alcatraz[68], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[69] = CreateDynamicObject(19446, 2879.7856, 1868.1920, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[69], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[70] = CreateDynamicObject(19381, 2863.8093, 1853.0909, 12.8399, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[70], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[71] = CreateDynamicObject(19381, 2862.9284, 1853.0909, 12.8399, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[71], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[72] = CreateDynamicObject(19379, 2881.4548, 1864.3454, 13.6251, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[72], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[73] = CreateDynamicObject(19381, 2882.3110, 1853.0909, 12.8399, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[73], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[74] = CreateDynamicObject(2337, 2868.3344, 1855.7353, 10.5207, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH1_WASHER
    object_alcatraz[75] = CreateDynamicObject(19355, 2867.8864, 1856.3038, 9.9357, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
    SetDynamicObjectMaterial(object_alcatraz[75], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[76] = CreateDynamicObject(19355, 2864.6762, 1856.3038, 9.9357, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
    SetDynamicObjectMaterial(object_alcatraz[76], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[77] = CreateDynamicObject(2336, 2866.3444, 1855.7381, 10.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH1_SINK
    object_alcatraz[78] = CreateDynamicObject(2158, 2864.3566, 1853.7452, 10.5080, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH1_L
    object_alcatraz[79] = CreateDynamicObject(2334, 2865.3442, 1855.7263, 10.5270, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH1_M
    object_alcatraz[80] = CreateDynamicObject(2338, 2864.3540, 1855.7508, 10.5228, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH1_CORNER
    object_alcatraz[81] = CreateDynamicObject(2334, 2864.3645, 1854.7469, 10.5270, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH1_M
    object_alcatraz[82] = CreateDynamicObject(2170, 2864.3342, 1852.9079, 10.4602, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH1_COOKER
    object_alcatraz[83] = CreateDynamicObject(2336, 2864.3510, 1851.0936, 10.5115, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH1_SINK
    object_alcatraz[84] = CreateDynamicObject(19446, 2867.7478, 1851.5406, 14.1443, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[84], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[85] = CreateDynamicObject(19379, 2881.4528, 1868.1562, 13.6251, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[85], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[86] = CreateDynamicObject(19381, 2882.3110, 1884.6422, 12.8399, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[86], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[87] = CreateDynamicObject(1409, 2868.8798, 1850.3603, 10.6176, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dump1_LOW
    object_alcatraz[88] = CreateDynamicObject(19379, 2881.4528, 1882.4278, 13.6251, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[88], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[89] = CreateDynamicObject(1409, 2868.0097, 1850.3603, 10.6176, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dump1_LOW
    object_alcatraz[90] = CreateDynamicObject(19381, 2882.3110, 1865.9211, 12.8399, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[90], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[91] = CreateDynamicObject(19381, 2882.3110, 1897.5201, 12.8399, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[91], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[92] = CreateDynamicObject(19304, 2878.3359, 1853.0727, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[93] = CreateDynamicObject(19387, 2869.4040, 1854.7513, 12.3056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_alcatraz[93], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[94] = CreateDynamicObject(19446, 2864.6586, 1851.5426, 14.1485, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[94], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[95] = CreateDynamicObject(19379, 2867.6892, 1849.8879, 14.3746, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[95], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[96] = CreateDynamicObject(19446, 2879.7856, 1882.2928, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[96], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[97] = CreateDynamicObject(19446, 2879.7980, 1888.5749, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[97], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[98] = CreateDynamicObject(19446, 2879.7856, 1891.9227, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[98], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[99] = CreateDynamicObject(19446, 2879.7856, 1900.2922, 14.3247, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[99], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[100] = CreateDynamicObject(2421, 2863.9675, 1854.9737, 11.9608, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_MICROW
    object_alcatraz[101] = CreateDynamicObject(2425, 2868.6110, 1856.0865, 11.5675, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_JUICE
    object_alcatraz[102] = CreateDynamicObject(11305, 2870.8781, 1874.0179, 15.7052, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //station
    object_alcatraz[103] = CreateDynamicObject(19304, 2878.3359, 1853.0638, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[104] = CreateDynamicObject(2451, 2866.8256, 1850.6191, 10.4736, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_WORKTOP_3
    object_alcatraz[105] = CreateDynamicObject(19304, 2878.3359, 1856.7341, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[106] = CreateDynamicObject(19446, 2879.7980, 1858.5432, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[106], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[107] = CreateDynamicObject(19304, 2878.3359, 1860.3745, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[108] = CreateDynamicObject(19302, 2878.3000, 1855.8376, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[109] = CreateDynamicObject(19302, 2878.3000, 1859.5079, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[110] = CreateDynamicObject(19446, 2879.7980, 1862.2031, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[110], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[111] = CreateDynamicObject(19304, 2878.3359, 1864.0350, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[112] = CreateDynamicObject(19302, 2878.3000, 1863.1777, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[113] = CreateDynamicObject(19446, 2879.7980, 1865.8631, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[113], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[114] = CreateDynamicObject(19304, 2878.3359, 1867.7054, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[115] = CreateDynamicObject(19446, 2879.7980, 1869.5439, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[115], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[116] = CreateDynamicObject(19304, 2878.3359, 1871.2153, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[117] = CreateDynamicObject(19446, 2879.7980, 1872.9245, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[117], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[118] = CreateDynamicObject(19302, 2878.3000, 1866.8474, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[119] = CreateDynamicObject(19302, 2878.3000, 1870.3575, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[120] = CreateDynamicObject(19446, 2879.7980, 1877.5550, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[120], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[121] = CreateDynamicObject(19304, 2878.3359, 1879.3946, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[122] = CreateDynamicObject(19302, 2878.3000, 1878.5277, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[123] = CreateDynamicObject(19446, 2879.7980, 1881.2248, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[123], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[124] = CreateDynamicObject(19304, 2878.3359, 1883.0644, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[125] = CreateDynamicObject(19302, 2878.3000, 1882.2076, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[126] = CreateDynamicObject(19446, 2879.7980, 1884.8946, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[126], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[127] = CreateDynamicObject(19304, 2878.3359, 1886.7347, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[128] = CreateDynamicObject(19302, 2878.3000, 1885.8680, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[129] = CreateDynamicObject(5816, 2869.5476, 1906.5279, 16.3001, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //odrampbit
    object_alcatraz[130] = CreateDynamicObject(3934, 2833.8237, 1820.1500, 10.5430, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_alcatraz[131] = CreateDynamicObject(3934, 2853.9689, 1820.1500, 10.5430, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_alcatraz[132] = CreateDynamicObject(19304, 2878.3359, 1890.4150, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[133] = CreateDynamicObject(3934, 2853.9689, 1835.6396, 10.5430, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_alcatraz[134] = CreateDynamicObject(3934, 2833.8237, 1835.6396, 10.5430, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_alcatraz[135] = CreateDynamicObject(19302, 2878.3000, 1889.5582, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[136] = CreateDynamicObject(19446, 2879.7980, 1892.2346, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[136], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[137] = CreateDynamicObject(19304, 2878.3359, 1894.0754, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[138] = CreateDynamicObject(19302, 2878.3000, 1893.2275, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[139] = CreateDynamicObject(19446, 2879.7980, 1895.9045, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[139], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[140] = CreateDynamicObject(19304, 2878.3359, 1897.7458, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[141] = CreateDynamicObject(19302, 2878.3000, 1896.8873, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[142] = CreateDynamicObject(19446, 2879.7980, 1899.5648, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[142], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[143] = CreateDynamicObject(19446, 2878.1164, 1901.2447, 14.2377, -90.0000, -90.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[143], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[144] = CreateDynamicObject(3279, 2821.1938, 1813.4034, 10.5150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_spottower
    object_alcatraz[145] = CreateDynamicObject(3279, 2898.2575, 1831.0251, 10.5150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_spottower
    object_alcatraz[146] = CreateDynamicObject(19446, 2879.7980, 1854.9050, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[146], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[147] = CreateDynamicObject(3279, 2898.2575, 1891.9648, 10.5150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_spottower
    object_alcatraz[148] = CreateDynamicObject(19304, 2865.6801, 1853.0638, 17.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[149] = CreateDynamicObject(19445, 2876.5358, 1939.0277, 15.6920, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_alcatraz[149], 0, 16093, "a51_ext", "corugwall_sandy", 0xFF3A3A0B);
    object_alcatraz[150] = CreateDynamicObject(3279, 2898.2575, 1951.6235, 10.5150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_spottower
    object_alcatraz[151] = CreateDynamicObject(19304, 2878.3359, 1897.7458, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[152] = CreateDynamicObject(3279, 2858.4653, 1912.6435, 10.5150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_spottower
    object_alcatraz[153] = CreateDynamicObject(19304, 2878.3359, 1894.0754, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[154] = CreateDynamicObject(3279, 2858.4653, 1974.8155, 10.5150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_spottower
    object_alcatraz[155] = CreateDynamicObject(19302, 2878.3000, 1893.2275, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[156] = CreateDynamicObject(19304, 2878.3359, 1890.4150, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[157] = CreateDynamicObject(19304, 2878.3359, 1886.7347, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[158] = CreateDynamicObject(19304, 2878.3359, 1883.0644, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[159] = CreateDynamicObject(19304, 2878.3359, 1879.3946, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[160] = CreateDynamicObject(19304, 2878.3359, 1871.2153, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[161] = CreateDynamicObject(19304, 2878.3359, 1867.7242, 17.5265, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[162] = CreateDynamicObject(19304, 2878.3359, 1864.0350, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[163] = CreateDynamicObject(19304, 2878.3359, 1860.3745, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[164] = CreateDynamicObject(19304, 2878.3359, 1856.7341, 13.6166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[165] = CreateDynamicObject(19302, 2878.3000, 1852.1864, 15.6527, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[166] = CreateDynamicObject(19302, 2878.3000, 1896.8873, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[167] = CreateDynamicObject(19302, 2878.3000, 1889.5582, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[168] = CreateDynamicObject(19302, 2878.3000, 1885.8680, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[169] = CreateDynamicObject(19302, 2878.3000, 1882.2076, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[170] = CreateDynamicObject(19302, 2878.3000, 1878.5277, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[171] = CreateDynamicObject(19302, 2878.3000, 1870.3575, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[172] = CreateDynamicObject(19302, 2878.3000, 1866.8474, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[173] = CreateDynamicObject(19302, 2878.3000, 1863.1777, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[174] = CreateDynamicObject(19302, 2878.3000, 1859.5079, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[175] = CreateDynamicObject(19302, 2878.3000, 1855.8376, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[176] = CreateDynamicObject(19446, 2879.7980, 1851.2353, 14.2679, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[176], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[177] = CreateDynamicObject(19445, 2876.5358, 1929.3978, 15.6920, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_alcatraz[177], 0, 16093, "a51_ext", "corugwall_sandy", 0xFF3A3A0B);
    object_alcatraz[178] = CreateDynamicObject(19446, 2878.1364, 1849.5737, 14.2679, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[178], 0, 16640, "a51", "pavegrey128", 0xFFFFFFFF);
    object_alcatraz[179] = CreateDynamicObject(19302, 2878.3000, 1852.1750, 11.7629, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[180] = CreateDynamicObject(19446, 2877.3159, 1851.7226, 14.3247, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[180], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[181] = CreateDynamicObject(19446, 2876.2922, 1858.5615, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[181], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[182] = CreateDynamicObject(19446, 2876.2922, 1868.1920, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[182], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[183] = CreateDynamicObject(19446, 2876.2922, 1877.8203, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[183], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[184] = CreateDynamicObject(19446, 2876.2922, 1887.4493, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[184], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[185] = CreateDynamicObject(19446, 2876.2922, 1897.0792, 14.3226, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_alcatraz[185], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[186] = CreateDynamicObject(18980, 2878.2028, 1889.9720, 18.6350, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_alcatraz[186], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[187] = CreateDynamicObject(19379, 2881.4528, 1892.0566, 13.6251, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[187], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[188] = CreateDynamicObject(18980, 2878.2028, 1860.5111, 18.6350, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_alcatraz[188], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[189] = CreateDynamicObject(19379, 2881.4548, 1900.3044, 13.6251, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[189], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[190] = CreateDynamicObject(997, 2864.1225, 1856.8763, 14.4568, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[191] = CreateDynamicObject(997, 2871.0693, 1856.8763, 14.4568, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[192] = CreateDynamicObject(997, 2867.5964, 1856.8763, 14.4568, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[193] = CreateDynamicObject(997, 2874.6186, 1856.8763, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[194] = CreateDynamicObject(997, 2874.6186, 1860.3365, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[195] = CreateDynamicObject(997, 2874.6186, 1863.8176, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[196] = CreateDynamicObject(997, 2874.6186, 1867.2772, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[197] = CreateDynamicObject(997, 2874.6186, 1870.7373, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[198] = CreateDynamicObject(997, 2874.6186, 1874.2170, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[199] = CreateDynamicObject(997, 2874.6186, 1877.6584, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[200] = CreateDynamicObject(997, 2874.6186, 1881.0893, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[201] = CreateDynamicObject(997, 2874.6186, 1884.5095, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[202] = CreateDynamicObject(997, 2874.6186, 1887.9488, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[203] = CreateDynamicObject(997, 2874.6186, 1891.3498, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[204] = CreateDynamicObject(997, 2874.6186, 1894.7402, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[205] = CreateDynamicObject(997, 2877.9587, 1874.3985, 14.4568, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[206] = CreateDynamicObject(997, 2877.9667, 1872.8656, 14.4547, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[207] = CreateDynamicObject(13011, 2874.0170, 1894.8868, 11.0232, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cos_sbanksteps04
    object_alcatraz[208] = CreateDynamicObject(19443, 2885.7290, 1877.0467, 13.8584, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall083
    SetDynamicObjectMaterial(object_alcatraz[208], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[209] = CreateDynamicObject(19443, 2885.7290, 1873.5467, 13.8584, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall083
    SetDynamicObjectMaterial(object_alcatraz[209], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[210] = CreateDynamicObject(19172, 2885.8073, 1874.8194, 13.7433, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_alcatraz[210], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_alcatraz[210], 1, "Alca", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    object_alcatraz[211] = CreateDynamicObject(19172, 2885.8073, 1876.7003, 13.7433, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_alcatraz[211], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_alcatraz[211], 1, "traz", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    object_alcatraz[212] = CreateDynamicObject(18980, 2884.3395, 1979.0726, 17.5450, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_alcatraz[212], 0, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_alcatraz[213] = CreateDynamicObject(366, 2869.2812, 1852.5268, 11.9062, 0.0000, 40.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire_ex
    object_alcatraz[214] = CreateDynamicObject(1800, 2882.3227, 1851.8479, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[215] = CreateDynamicObject(19381, 2854.6064, 1849.9187, 5.7399, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[215], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[216] = CreateDynamicObject(19381, 2859.9101, 1855.0804, 5.7399, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[216], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[217] = CreateDynamicObject(19381, 2844.1054, 1849.9189, 5.7399, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[217], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[218] = CreateDynamicObject(19381, 2833.6054, 1849.9189, 5.7399, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[218], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[219] = CreateDynamicObject(19381, 2828.2656, 1855.0782, 5.7399, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[219], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[220] = CreateDynamicObject(19381, 2828.2656, 1861.3066, 5.7399, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[220], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[221] = CreateDynamicObject(19381, 2859.9101, 1861.3066, 5.7399, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[221], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[222] = CreateDynamicObject(19381, 2854.5764, 1866.4696, 5.7399, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[222], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[223] = CreateDynamicObject(19381, 2844.0883, 1866.4696, 5.7399, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[223], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[224] = CreateDynamicObject(19381, 2833.5900, 1866.4696, 5.7399, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[224], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_alcatraz[225] = CreateDynamicObject(19381, 2862.9284, 1862.9720, 12.8399, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_alcatraz[225], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_alcatraz[226] = CreateDynamicObject(19379, 2863.8393, 1861.2081, 13.8149, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[226], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[227] = CreateDynamicObject(19379, 2863.8374, 1867.6363, 13.8149, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[227], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[228] = CreateDynamicObject(947, 2859.0034, 1858.3288, 12.6702, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bskballhub_lax01
    object_alcatraz[229] = CreateDynamicObject(947, 2829.0981, 1858.3288, 12.6702, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bskballhub_lax01
    object_alcatraz[230] = CreateDynamicObject(1800, 2882.3227, 1855.5295, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[231] = CreateDynamicObject(1800, 2882.3227, 1859.1103, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[232] = CreateDynamicObject(1800, 2882.3227, 1862.7706, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[233] = CreateDynamicObject(1800, 2882.3227, 1866.4311, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[234] = CreateDynamicObject(1800, 2882.3227, 1870.1020, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[235] = CreateDynamicObject(1800, 2882.3227, 1878.1141, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[236] = CreateDynamicObject(1800, 2882.3227, 1881.7961, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[237] = CreateDynamicObject(1800, 2882.3227, 1885.4659, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[238] = CreateDynamicObject(1800, 2882.3227, 1889.1368, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[239] = CreateDynamicObject(1800, 2882.3227, 1892.7967, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[240] = CreateDynamicObject(1800, 2882.3227, 1896.5090, 10.4967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[241] = CreateDynamicObject(1800, 2882.3227, 1896.5090, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[242] = CreateDynamicObject(1800, 2882.3227, 1892.8094, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[243] = CreateDynamicObject(1800, 2882.3227, 1889.1462, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[244] = CreateDynamicObject(1800, 2882.3227, 1885.4571, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[245] = CreateDynamicObject(1800, 2882.3227, 1881.7961, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[246] = CreateDynamicObject(1800, 2882.3227, 1878.1246, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[247] = CreateDynamicObject(1800, 2882.3227, 1870.1024, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[248] = CreateDynamicObject(1800, 2882.3227, 1866.4316, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[249] = CreateDynamicObject(1800, 2882.3227, 1862.7906, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[250] = CreateDynamicObject(1800, 2882.3227, 1859.1297, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[251] = CreateDynamicObject(1800, 2882.3227, 1855.4791, 14.3964, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[252] = CreateDynamicObject(2627, 2831.1647, 1901.1905, 10.5274, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_treadmill
    object_alcatraz[253] = CreateDynamicObject(19464, 2867.5434, 1850.2496, 16.8276, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_alcatraz[253], 0, 18065, "ab_sfammumain", "pavea256", 0xFFFFFFFF);
    object_alcatraz[254] = CreateDynamicObject(19304, 2869.4106, 1853.0638, 17.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[255] = CreateDynamicObject(19464, 2871.2863, 1850.2496, 16.8276, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_alcatraz[255], 0, 18065, "ab_sfammumain", "pavea256", 0xFFFFFFFF);
    object_alcatraz[256] = CreateDynamicObject(19304, 2873.1638, 1853.0638, 17.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge20
    object_alcatraz[257] = CreateDynamicObject(19464, 2875.0375, 1850.2496, 16.8276, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_alcatraz[257], 0, 18065, "ab_sfammumain", "pavea256", 0xFFFFFFFF);
    object_alcatraz[258] = CreateDynamicObject(18762, 2871.2131, 1853.0721, 18.6277, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_alcatraz[258], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[259] = CreateDynamicObject(18762, 2876.2058, 1853.0721, 18.6277, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_alcatraz[259], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[260] = CreateDynamicObject(18762, 2866.2128, 1853.0721, 18.6277, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_alcatraz[260], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[261] = CreateDynamicObject(19302, 2872.2858, 1853.0660, 15.6527, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[262] = CreateDynamicObject(19302, 2868.5322, 1853.0660, 15.6527, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[263] = CreateDynamicObject(19302, 2864.7888, 1853.0660, 15.6527, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge07
    object_alcatraz[264] = CreateDynamicObject(1800, 2882.3227, 1851.8479, 14.3766, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[265] = CreateDynamicObject(1800, 2871.9411, 1849.2856, 14.3766, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[266] = CreateDynamicObject(1800, 2868.1501, 1849.2856, 14.3766, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[267] = CreateDynamicObject(1800, 2864.4169, 1849.2856, 14.3766, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_BED_1
    object_alcatraz[268] = CreateDynamicObject(2525, 2866.6330, 1850.4658, 14.4054, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[269] = CreateDynamicObject(2525, 2870.5166, 1850.4658, 14.4054, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[270] = CreateDynamicObject(2525, 2874.2302, 1850.4658, 14.4054, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[271] = CreateDynamicObject(2525, 2880.8720, 1854.2563, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[272] = CreateDynamicObject(2525, 2880.8720, 1857.7961, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[273] = CreateDynamicObject(2525, 2880.8720, 1861.4093, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[274] = CreateDynamicObject(2525, 2880.8720, 1865.2308, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[275] = CreateDynamicObject(2525, 2880.8720, 1868.8518, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[276] = CreateDynamicObject(2525, 2880.8720, 1872.1435, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[277] = CreateDynamicObject(2525, 2880.8720, 1880.5439, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[278] = CreateDynamicObject(2525, 2880.8720, 1884.0969, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[279] = CreateDynamicObject(2525, 2880.8720, 1887.8979, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[280] = CreateDynamicObject(2525, 2880.8720, 1891.4095, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[281] = CreateDynamicObject(2525, 2880.8720, 1895.1302, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[282] = CreateDynamicObject(2525, 2880.8720, 1898.7612, 14.4054, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[283] = CreateDynamicObject(2525, 2880.8720, 1898.7612, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[284] = CreateDynamicObject(2525, 2880.8720, 1895.1302, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[285] = CreateDynamicObject(2525, 2880.8720, 1891.4095, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[286] = CreateDynamicObject(2525, 2880.8720, 1887.8979, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[287] = CreateDynamicObject(2525, 2880.8720, 1884.0969, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[288] = CreateDynamicObject(2525, 2880.8720, 1880.5439, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[289] = CreateDynamicObject(2525, 2880.8720, 1872.1435, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[290] = CreateDynamicObject(2525, 2880.8720, 1868.8518, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[291] = CreateDynamicObject(2525, 2880.8720, 1865.2308, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[292] = CreateDynamicObject(2525, 2880.8720, 1861.4093, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[293] = CreateDynamicObject(2525, 2880.8720, 1857.7961, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[294] = CreateDynamicObject(2525, 2880.8720, 1854.2563, 10.5354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET4
    object_alcatraz[295] = CreateDynamicObject(1495, 2856.7053, 1920.2364, 10.5276, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT01
    object_alcatraz[296] = CreateDynamicObject(1234, 2856.7246, 1920.2170, 12.0670, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    object_alcatraz[297] = CreateDynamicObject(1234, 2856.7246, 1920.1770, 12.0670, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    object_alcatraz[298] = CreateDynamicObject(1495, 2856.7053, 1946.5769, 10.5276, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT01
    object_alcatraz[299] = CreateDynamicObject(1234, 2856.7246, 1946.5777, 12.0670, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    object_alcatraz[300] = CreateDynamicObject(1495, 2872.6301, 1949.0854, 10.5276, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT01
    object_alcatraz[301] = CreateDynamicObject(16095, 2898.7478, 1922.0821, 10.5207, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //des_a51guardbox02
    object_alcatraz[302] = CreateDynamicObject(19379, 2877.3142, 1849.8879, 14.3746, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall027
    SetDynamicObjectMaterial(object_alcatraz[302], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    object_alcatraz[303] = CreateDynamicObject(16093, 2871.2390, 1892.1247, 23.8917, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_gatecontrol
    object_alcatraz[304] = CreateDynamicObject(16093, 2871.2390, 1858.0349, 23.8917, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_gatecontrol
    object_alcatraz[305] = CreateDynamicObject(16638, 2870.2663, 1892.0467, 22.1403, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_gatecon_a
    object_alcatraz[306] = CreateDynamicObject(16638, 2870.2663, 1857.9575, 22.1403, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_gatecon_a
    object_alcatraz[307] = CreateDynamicObject(14791, 2834.0175, 1883.4935, 12.5571, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a_vgsGymBoxa
    object_alcatraz[308] = CreateDynamicObject(2627, 2833.4553, 1901.1905, 10.5274, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_treadmill
    object_alcatraz[309] = CreateDynamicObject(2627, 2835.6274, 1901.1905, 10.5274, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_treadmill
    object_alcatraz[310] = CreateDynamicObject(2628, 2841.6708, 1901.3089, 10.5347, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench2
    object_alcatraz[311] = CreateDynamicObject(2628, 2843.5825, 1901.3089, 10.5347, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench2
    object_alcatraz[312] = CreateDynamicObject(14791, 2853.3447, 1883.4935, 12.5571, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a_vgsGymBoxa
    object_alcatraz[313] = CreateDynamicObject(2628, 2845.4526, 1901.3089, 10.5347, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench2
    object_alcatraz[314] = CreateDynamicObject(2629, 2851.2473, 1901.2668, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench1
    object_alcatraz[315] = CreateDynamicObject(2629, 2853.9975, 1901.2668, 10.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench1
    object_alcatraz[316] = CreateDynamicObject(2629, 2857.0183, 1901.2668, 10.5354, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench1
    object_alcatraz[317] = CreateDynamicObject(1985, 2844.8908, 1879.5310, 13.1829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //punchbagnu
    object_alcatraz[318] = CreateDynamicObject(2630, 2852.7211, 1894.8950, 10.5282, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bike
    object_alcatraz[319] = CreateDynamicObject(2630, 2855.5217, 1894.8950, 10.5282, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bike
    object_alcatraz[320] = CreateDynamicObject(2631, 2854.1083, 1894.8664, 10.5031, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_alcatraz[321] = CreateDynamicObject(2632, 2833.6311, 1895.1003, 10.5865, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat02
    object_alcatraz[322] = CreateDynamicObject(2112, 2866.0097, 1859.9101, 10.9243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DINNING_4
    object_alcatraz[323] = CreateDynamicObject(2112, 2866.0097, 1862.9327, 10.9243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DINNING_4
    object_alcatraz[324] = CreateDynamicObject(2112, 2866.0097, 1865.9433, 10.9243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DINNING_4
    object_alcatraz[325] = CreateDynamicObject(2112, 2866.0097, 1868.9333, 10.9243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DINNING_4
    object_alcatraz[326] = CreateDynamicObject(2112, 2869.3395, 1861.4300, 10.9243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DINNING_4
    object_alcatraz[327] = CreateDynamicObject(2112, 2869.3395, 1864.4604, 10.9243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DINNING_4
    object_alcatraz[328] = CreateDynamicObject(2112, 2869.3395, 1867.4405, 10.9243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DINNING_4
    object_alcatraz[329] = CreateDynamicObject(2112, 2869.3395, 1870.3905, 10.9243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DINNING_4
    object_alcatraz[330] = CreateDynamicObject(2628, 2841.6708, 1894.6291, 10.5747, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench2
    object_alcatraz[331] = CreateDynamicObject(2628, 2843.5825, 1894.6291, 10.6246, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench2
    object_alcatraz[332] = CreateDynamicObject(1805, 2869.4609, 1871.8608, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[333] = CreateDynamicObject(2628, 2845.4526, 1894.6291, 10.5347, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench2
    object_alcatraz[334] = CreateDynamicObject(1805, 2870.8122, 1870.2912, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[335] = CreateDynamicObject(1805, 2870.8122, 1867.8111, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[336] = CreateDynamicObject(1805, 2870.8122, 1864.1788, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[337] = CreateDynamicObject(1805, 2870.8122, 1861.4787, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[338] = CreateDynamicObject(2915, 2832.5585, 1895.7683, 10.7444, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_dumbbell2
    object_alcatraz[339] = CreateDynamicObject(2915, 2835.2004, 1895.7683, 10.7444, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_dumbbell2
    object_alcatraz[340] = CreateDynamicObject(1805, 2864.5698, 1863.1180, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[341] = CreateDynamicObject(2915, 2833.8896, 1895.7683, 10.7444, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_dumbbell2
    object_alcatraz[342] = CreateDynamicObject(1805, 2864.5698, 1859.4466, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[343] = CreateDynamicObject(1805, 2864.5500, 1865.9394, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[344] = CreateDynamicObject(1805, 2864.5500, 1869.1097, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[345] = CreateDynamicObject(1805, 2865.8413, 1870.3708, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[346] = CreateDynamicObject(1805, 2867.8811, 1864.1788, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[347] = CreateDynamicObject(1805, 2867.8811, 1861.2269, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[348] = CreateDynamicObject(1805, 2867.8811, 1867.4980, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[349] = CreateDynamicObject(1805, 2867.8811, 1870.5589, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[350] = CreateDynamicObject(1805, 2867.4506, 1868.8889, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[351] = CreateDynamicObject(1805, 2867.4506, 1865.9283, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[352] = CreateDynamicObject(1805, 2867.4506, 1862.7065, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[353] = CreateDynamicObject(1805, 2869.3825, 1859.9664, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[354] = CreateDynamicObject(1805, 2867.4716, 1859.9664, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[355] = CreateDynamicObject(1805, 2865.9018, 1861.4559, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[356] = CreateDynamicObject(1805, 2865.9018, 1864.3957, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[357] = CreateDynamicObject(1805, 2865.9018, 1867.4864, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[358] = CreateDynamicObject(1805, 2869.3217, 1868.9167, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[359] = CreateDynamicObject(1805, 2869.3217, 1865.9160, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[360] = CreateDynamicObject(1805, 2869.3217, 1862.8552, 10.7762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL
    object_alcatraz[361] = CreateDynamicObject(997, 2878.3403, 1875.2469, 10.6167, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_alcatraz[362] = CreateDynamicObject(14782, 2866.3105, 1899.8901, 11.4863, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int3int_boxing30
    object_alcatraz[363] = CreateDynamicObject(1985, 2844.8908, 1883.0312, 13.1829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //punchbagnu
    object_alcatraz[364] = CreateDynamicObject(19376, 2843.5378, 1883.0616, 8.0488, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall024
    SetDynamicObjectMaterial(object_alcatraz[364], 0, 14486, "ab_vegasgymbits01", "bbar_wall2", 0xFFFFFFFF);
    object_alcatraz[365] = CreateDynamicObject(19445, 2843.5439, 1883.0583, 13.2184, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_alcatraz[365], 0, 14794, "ab_vegasgymmain", "bbar_wall3", 0xFFFFFFFF);
    object_alcatraz[366] = CreateDynamicObject(1985, 2844.8908, 1886.6025, 13.1829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //punchbagnu
    object_alcatraz[367] = CreateDynamicObject(1985, 2842.2683, 1879.5310, 13.1829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //punchbagnu
    object_alcatraz[368] = CreateDynamicObject(1985, 2842.2683, 1883.0312, 13.1829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //punchbagnu
    object_alcatraz[369] = CreateDynamicObject(1985, 2842.2683, 1886.6025, 13.1829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //punchbagnu
    object_alcatraz[370] = CreateDynamicObject(1886, 2895.0800, 1948.3082, 20.5002, 13.6997, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[371] = CreateDynamicObject(3819, 2836.7504, 1869.9444, 11.5080, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bleacher_SFSx
    object_alcatraz[372] = CreateDynamicObject(1368, 2862.3227, 1878.9626, 11.2227, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[373] = CreateDynamicObject(1368, 2862.3227, 1882.2336, 11.2227, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[374] = CreateDynamicObject(1368, 2862.3227, 1889.8553, 11.2227, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[375] = CreateDynamicObject(1368, 2862.3227, 1893.0268, 11.2227, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[376] = CreateDynamicObject(1368, 2862.3227, 1900.6676, 11.2227, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[377] = CreateDynamicObject(1368, 2825.1796, 1900.6676, 11.2227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[378] = CreateDynamicObject(1368, 2825.1796, 1893.0764, 11.2227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[379] = CreateDynamicObject(1368, 2825.1796, 1889.8160, 11.2227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[380] = CreateDynamicObject(1368, 2825.1796, 1882.2751, 11.2227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[381] = CreateDynamicObject(1368, 2825.1796, 1878.9541, 11.2227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_alcatraz[382] = CreateDynamicObject(3819, 2850.5041, 1869.9444, 11.5080, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bleacher_SFSx
    object_alcatraz[383] = CreateDynamicObject(1886, 2895.3254, 1949.1612, 20.5153, 13.6997, 0.0000, -150.1999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[384] = CreateDynamicObject(1886, 2889.5522, 1972.2423, 25.5391, 27.1998, 0.0000, -170.6999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[385] = CreateDynamicObject(1886, 2878.8769, 1972.3181, 25.5391, 27.1998, 0.0000, 170.6999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[386] = CreateDynamicObject(1886, 2854.8061, 1971.1556, 20.4871, 27.1998, 0.0000, -26.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[387] = CreateDynamicObject(1886, 2855.4777, 1971.0378, 20.5055, 19.0998, 0.0000, 1.0999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[388] = CreateDynamicObject(1886, 2895.0908, 1888.6606, 20.4740, 28.7000, 0.0000, -35.4000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[389] = CreateDynamicObject(1886, 2895.3122, 1834.5769, 22.7033, 21.2000, 0.0000, -164.1999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[390] = CreateDynamicObject(1886, 2895.6723, 1833.4195, 22.7019, 21.2000, 0.0000, -90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[391] = CreateDynamicObject(1886, 2901.6208, 1949.7368, 18.0132, 13.6997, 0.0000, -55.7999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[392] = CreateDynamicObject(3279, 2867.2990, 1813.4034, 10.5150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_spottower
    object_alcatraz[393] = CreateDynamicObject(1886, 2818.3862, 1809.9305, 20.4925, 15.3999, 0.0000, -58.0998, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[394] = CreateDynamicObject(1886, 2825.6235, 1810.6579, 18.0426, 15.3999, 0.0000, 108.0998, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[395] = CreateDynamicObject(1886, 2817.8657, 1811.0853, 20.5062, 15.3999, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[396] = CreateDynamicObject(1886, 2864.3591, 1811.0853, 20.5062, 15.3999, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[397] = CreateDynamicObject(1886, 2843.7465, 1901.5450, 23.7917, 34.0998, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[398] = CreateDynamicObject(1886, 2843.7866, 1848.7705, 23.7919, 28.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[399] = CreateDynamicObject(1886, 2864.2358, 1899.4775, 18.8355, 34.5998, 0.0000, 20.1000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[400] = CreateDynamicObject(1886, 2864.6928, 1899.7069, 18.8355, 34.5998, 0.0000, 45.7999, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[401] = CreateDynamicObject(1886, 2877.2387, 1899.5852, 18.8687, 12.4996, 0.0000, -13.8000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[402] = CreateDynamicObject(1886, 2865.0112, 1854.2082, 18.7989, 14.8000, 0.0000, 158.4998, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[403] = CreateDynamicObject(1886, 2864.4094, 1854.1346, 18.8439, 14.8000, 0.0000, 173.1997, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[404] = CreateDynamicObject(1886, 2855.2939, 1972.1340, 20.4815, 27.1998, 0.0000, -128.5997, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_alcatraz[405] = CreateDynamicObject(2947, 2870.2524, 1905.1759, 10.5394, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_door_01

    object_alcatraz[406] = CreateDynamicObject(19912, 2882.0168, 1878.5587, 10.3259, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Alc Tor zum Aufbrechen
    object_alcatraz[407] = CreateDynamicObject(7657, 2876.6022, 1934.2126, 12.2278, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Garage gate
    object_alcatraz[408] = CreateDynamicObject(980, 2884.3974, 1979.0788, 13.2719, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Maingate

    object_alcatraz[409] = CreateDynamicObject(19368, 2876.8391, 1978.6291, 21.0545, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    object_alcatraz[410] = CreateDynamicObject(19368, 2900.6591, 1978.7092, 21.0545, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ALCATRAZ_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016

    object_alcatraz_entranceGate = object_alcatraz[408];
    object_alcatraz_garageGate = object_alcatraz[407];
}
