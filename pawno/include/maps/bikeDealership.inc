#include <YSI\y_hooks>

// Global interior define
#define MAPS_BIKEDEALERSHIP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 190.0;

// Bike dealership points
#define BIKEDEALERSHIP_COORDS                   2509.1748, -1514.4324, 24.0000
#define BIKEDEALERSHIP_VEHICLE_SPAWN            2535.8975, -1520.9816, 23.5721
#define BIKEDEALERSHIP_ELEVATOR_DOWN_POINT      2507.6357, -1533.4967, 24.1359
#define BIKEDEALERSHIP_ELEVATOR_UP_POINT        2507.6357, -1533.4967, 28.3439
#define BIKEDEALERSHIP_ELEVATOR_DOWN_FACING     0.0000
#define BIKEDEALERSHIP_ELEVATOR_UP_FACING       0.0000

// Map variables
new object_bikeDealership[386];
new pickup_bikeDealership[2];
new text3D_bikeDealership[1];
new actor_bikeDealership[3];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, BIKEDEALERSHIP_ELEVATOR_DOWN_POINT)) {
			SetPlayerPos(playerid, BIKEDEALERSHIP_ELEVATOR_UP_POINT);
            SetPlayerFacingAngle(playerid, BIKEDEALERSHIP_ELEVATOR_UP_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, BIKEDEALERSHIP_ELEVATOR_UP_POINT)) {
			SetPlayerPos(playerid, BIKEDEALERSHIP_ELEVATOR_DOWN_POINT);
            SetPlayerFacingAngle(playerid, BIKEDEALERSHIP_ELEVATOR_DOWN_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(BIKEDEALERSHIP_COORDS, 55, 0, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR);

    // Pickups
    pickup_bikeDealership[0] = CreateDynamicPickup(19197, 1, BIKEDEALERSHIP_ELEVATOR_DOWN_POINT, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR);
	pickup_bikeDealership[1] = CreateDynamicPickup(19197, 1, BIKEDEALERSHIP_ELEVATOR_UP_POINT, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR);

    // 3DTextLabels
    text3D_bikeDealership[0] = _:CreateDynamic3DTextLabel("Motorradhaus\n" COLOR_HEX_WHITE "Steig in ein beliebiges Motorrad deiner Wahl ein!", COLOR_BLUE, BIKEDEALERSHIP_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BIKEDEALERSHIP_INTERIOR);

    // Actors
    actor_bikeDealership[0] = CreateDynamicActor(50, 2527.6880, -1529.0199, 24.1329, 266.8696, .worldid = VW_MAIN, .interiorid = MAPS_BIKEDEALERSHIP_INTERIOR); // Smoking mechanic
    ApplyDynamicActorAnimation(actor_bikeDealership[0], "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);
    actor_bikeDealership[1] = CreateDynamicActor(192, 2511.1904, -1526.1702, 28.3490, 341.9841, .worldid = VW_MAIN, .interiorid = MAPS_BIKEDEALERSHIP_INTERIOR); // Female customer
    ApplyDynamicActorAnimation(actor_bikeDealership[1], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_bikeDealership[2] = CreateDynamicActor(227, 2512.2053, -1523.6752, 28.3470, 171.7762, .worldid = VW_MAIN, .interiorid = MAPS_BIKEDEALERSHIP_INTERIOR); // rich old asian fuck selling bikes
    ApplyDynamicActorAnimation(actor_bikeDealership[2], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);

    // Objects
    object_bikeDealership[0] = CreateDynamicObject(8661, 2520.6799, -1524.3497, 23.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_bikeDealership[1] = CreateDynamicObject(18762, 2505.1989, -1520.6606, 22.6329, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[1], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[2] = CreateDynamicObject(18762, 2509.1840, -1519.6606, 22.6329, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[2], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[3] = CreateDynamicObject(18980, 2510.6799, -1520.6595, 14.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[3], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[4] = CreateDynamicObject(18980, 2502.1989, -1520.6595, 22.1828, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[4], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[5] = CreateDynamicObject(8661, 2520.6704, -1514.3463, 13.0240, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_bikeDealership[6] = CreateDynamicObject(1649, 2504.9074, -1520.6595, 24.7814, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[6], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[7] = CreateDynamicObject(18762, 2501.1989, -1516.8392, 22.6028, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[7], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[8] = CreateDynamicObject(18762, 2505.1989, -1520.6606, 22.6329, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[8], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[9] = CreateDynamicObject(18762, 2501.1989, -1521.8387, 22.6028, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[9], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[10] = CreateDynamicObject(18762, 2501.1989, -1526.8387, 22.6028, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[10], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[11] = CreateDynamicObject(18980, 2507.6303, -1520.6595, 14.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[11], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[12] = CreateDynamicObject(18762, 2501.1989, -1531.8387, 22.6028, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[12], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[13] = CreateDynamicObject(1649, 2504.9074, -1520.6595, 24.7814, 180.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[13], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[14] = CreateDynamicObject(18762, 2513.6540, -1520.6606, 22.6329, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[14], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[15] = CreateDynamicObject(1649, 2513.3745, -1520.6595, 24.7814, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[15], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[16] = CreateDynamicObject(18762, 2509.1840, -1520.6600, 22.6319, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[16], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[17] = CreateDynamicObject(3051, 2507.1054, -1534.2961, 24.1361, 0.0000, 0.0000, -43.5998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_bikeDealership[17], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0x00000000);
    object_bikeDealership[18] = CreateDynamicObject(18980, 2516.0751, -1520.6595, 14.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[18], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[19] = CreateDynamicObject(18762, 2516.0700, -1523.6500, 22.6319, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[19], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[20] = CreateDynamicObject(19430, 2512.2731, -1523.5692, 22.5995, 77.8999, 35.2000, 95.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_bikeDealership[20], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFAFA);
    object_bikeDealership[21] = CreateDynamicObject(18980, 2516.0751, -1526.0710, 14.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[21], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[22] = CreateDynamicObject(1649, 2516.0700, -1523.3696, 24.7814, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[22], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[23] = CreateDynamicObject(18762, 2519.0456, -1526.0699, 22.6308, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[23], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[24] = CreateDynamicObject(1649, 2518.7473, -1526.0649, 24.7814, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[24], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[25] = CreateDynamicObject(1649, 2518.7473, -1526.0649, 24.7814, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[25], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[26] = CreateDynamicObject(18980, 2521.4399, -1526.0670, 14.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[26], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[27] = CreateDynamicObject(18766, 2510.5759, -1523.6595, 22.6338, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[27], 0, 14476, "carlslounge", "AH_cheapredcarpet", 0xFFFFFAFA);
    object_bikeDealership[28] = CreateDynamicObject(18766, 2510.5759, -1528.6590, 22.6338, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[28], 0, 14476, "carlslounge", "AH_cheapredcarpet", 0xFFFFFAFA);
    object_bikeDealership[29] = CreateDynamicObject(18762, 2524.4194, -1526.0699, 22.6329, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[29], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[30] = CreateDynamicObject(1649, 2524.1225, -1526.0649, 24.7814, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[30], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[31] = CreateDynamicObject(1649, 2524.1225, -1526.0649, 24.7814, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[31], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[32] = CreateDynamicObject(18766, 2504.3339, -1526.1600, 22.6329, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[32], 0, 14476, "carlslounge", "AH_cheapredcarpet", 0xFFFFFAFA);
    object_bikeDealership[33] = CreateDynamicObject(19464, 2513.6560, -1527.1037, 20.5827, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[33], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[34] = CreateDynamicObject(18762, 2534.4201, -1526.0677, 26.8547, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[34], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[35] = CreateDynamicObject(19430, 2513.7761, -1525.2712, 22.5816, 77.8999, 35.2000, 95.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_bikeDealership[35], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFAFA);
    object_bikeDealership[36] = CreateDynamicObject(18762, 2529.8391, -1526.0699, 22.6329, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[36], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[37] = CreateDynamicObject(18980, 2526.8432, -1526.0670, 14.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[37], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[38] = CreateDynamicObject(18766, 2533.9072, -1534.8070, 24.9437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[38], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[39] = CreateDynamicObject(18980, 2527.6020, -1526.5677, 14.7727, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[39], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFAFA);
    object_bikeDealership[40] = CreateDynamicObject(2957, 2530.3330, -1527.8604, 26.2796, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chinaTgarageDoor
    SetDynamicObjectMaterial(object_bikeDealership[40], 0, 9515, "bigboxtemp1", "ws_garagedoor3_white", 0x00000000);
    object_bikeDealership[41] = CreateDynamicObject(18763, 2513.1918, -1528.6529, 21.6361, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[41], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[42] = CreateDynamicObject(18762, 2534.8386, -1526.0699, 22.6329, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[42], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[43] = CreateDynamicObject(18980, 2533.1018, -1526.5677, 14.8027, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[43], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    // Ramp (PCJ-600) .streamdistance = -1
    object_bikeDealership[44] = CreateDynamicObject(19430, 2505.2487, -1523.8480, 23.3425, 0.0000, 80.1998, -151.1000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_bikeDealership[44], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    object_bikeDealership[45] = CreateDynamicObject(2957, 2535.8229, -1526.1562, 24.7411, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chinaTgarageDoor
    SetDynamicObjectMaterial(object_bikeDealership[45], 0, 9515, "bigboxtemp1", "ws_garagedoor3_white", 0x00000000);
    object_bikeDealership[46] = CreateDynamicObject(18766, 2539.3999, -1530.5782, 24.8435, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[46], 0, 16640, "a51", "vgs_shopwall01_128", 0xFFFFFFFF);
    object_bikeDealership[47] = CreateDynamicObject(18762, 2537.3286, -1526.0710, 22.6319, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[47], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[48] = CreateDynamicObject(18763, 2518.1909, -1528.6529, 21.6361, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[48], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[49] = CreateDynamicObject(18762, 2540.4001, -1516.8392, 22.6028, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[49], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[50] = CreateDynamicObject(18763, 2523.1899, -1528.6529, 21.6361, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[50], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[51] = CreateDynamicObject(18762, 2540.4001, -1521.8387, 22.6028, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[51], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[52] = CreateDynamicObject(18762, 2540.4001, -1526.8387, 22.6028, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[52], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[53] = CreateDynamicObject(18762, 2540.4001, -1531.8387, 22.6028, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[53], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[54] = CreateDynamicObject(18766, 2520.5759, -1529.0699, 22.6329, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[54], 0, 14476, "carlslounge", "AH_cheapredcarpet", 0xFFFFFAFA);
    object_bikeDealership[55] = CreateDynamicObject(18763, 2509.1933, -1528.6440, 21.6361, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[55], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[56] = CreateDynamicObject(18980, 2539.3898, -1526.0660, 14.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[56], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[57] = CreateDynamicObject(18763, 2509.1933, -1531.6457, 21.6375, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[57], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[58] = CreateDynamicObject(18766, 2506.8295, -1532.1809, 22.6310, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[58], 0, 14476, "carlslounge", "AH_cheapredcarpet", 0xFFFFFAFA);
    object_bikeDealership[59] = CreateDynamicObject(18980, 2538.5935, -1526.5677, 14.6827, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[59], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[60] = CreateDynamicObject(18766, 2516.8291, -1532.1809, 22.6289, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[60], 0, 14476, "carlslounge", "AH_cheapredcarpet", 0xFFFFFAFA);
    object_bikeDealership[61] = CreateDynamicObject(18763, 2506.1950, -1531.6457, 21.6359, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[61], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[62] = CreateDynamicObject(19430, 2514.0703, -1522.9272, 21.9258, 0.0000, -8.3999, 41.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_bikeDealership[62], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFAFA);
    object_bikeDealership[63] = CreateDynamicObject(18762, 2529.4211, -1526.0677, 26.8547, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[63], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[64] = CreateDynamicObject(18762, 2536.4138, -1526.0666, 26.8528, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[64], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[65] = CreateDynamicObject(18766, 2523.9074, -1534.8070, 24.9437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[65], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[66] = CreateDynamicObject(18766, 2513.9079, -1534.8070, 24.9437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[66], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[67] = CreateDynamicObject(18766, 2506.6987, -1534.8077, 24.9437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[67], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[68] = CreateDynamicObject(18766, 2502.1962, -1530.5782, 24.9437, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[68], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[69] = CreateDynamicObject(18763, 2524.1909, -1531.9038, 21.6340, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[69], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    // Ramp (NRG-500) .streamdistance = -1
    object_bikeDealership[70] = CreateDynamicObject(19430, 2513.3178, -1524.6772, 23.3400, 0.0000, 80.1998, 41.0998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_bikeDealership[70], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    object_bikeDealership[71] = CreateDynamicObject(18980, 2539.4030, -1526.0649, 14.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[71], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    // Ramp (NRG-500) .streamdistance = -1
    object_bikeDealership[72] = CreateDynamicObject(19430, 2512.7077, -1523.9763, 23.3409, 0.0000, 80.1998, 41.0998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_bikeDealership[72], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    object_bikeDealership[73] = CreateDynamicObject(1649, 2513.3745, -1520.6595, 24.7814, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[73], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[74] = CreateDynamicObject(1649, 2516.0700, -1523.3696, 24.7814, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[74], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[75] = CreateDynamicObject(19430, 2514.6091, -1523.5460, 21.9258, 0.0000, -8.3999, 41.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_bikeDealership[75], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFAFA);
    object_bikeDealership[76] = CreateDynamicObject(970, 2514.4741, -1526.5238, 23.6422, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_bikeDealership[76], 0, 14581, "ab_mafiasuitea", "barbersmir1", 0x00000000);
    SetDynamicObjectMaterial(object_bikeDealership[76], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_bikeDealership[77] = CreateDynamicObject(970, 2510.7634, -1522.5522, 23.6422, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_bikeDealership[77], 0, 14581, "ab_mafiasuitea", "barbersmir1", 0x00000000);
    SetDynamicObjectMaterial(object_bikeDealership[77], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_bikeDealership[78] = CreateDynamicObject(18763, 2509.1933, -1523.6440, 21.6361, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[78], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[79] = CreateDynamicObject(19464, 2510.7170, -1524.0206, 20.5820, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[79], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[80] = CreateDynamicObject(19464, 2507.6657, -1524.0206, 20.5820, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[80], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[81] = CreateDynamicObject(19464, 2507.6657, -1526.4918, 20.5830, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[81], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[82] = CreateDynamicObject(1234, 2515.5634, -1526.5334, 23.0599, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bikeDealership[82], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    SetDynamicObjectMaterial(object_bikeDealership[82], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[83] = CreateDynamicObject(19464, 2504.7048, -1531.9724, 20.5879, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[83], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[84] = CreateDynamicObject(19437, 2532.8188, -1526.6358, 28.0125, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall077
    SetDynamicObjectMaterial(object_bikeDealership[84], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[85] = CreateDynamicObject(19464, 2510.6762, -1531.9724, 20.5832, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[85], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[86] = CreateDynamicObject(19464, 2519.5471, -1527.1037, 20.5823, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[86], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[87] = CreateDynamicObject(19464, 2513.6560, -1530.1538, 20.5820, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[87], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[88] = CreateDynamicObject(19464, 2523.8908, -1527.1037, 20.5827, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[88], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[89] = CreateDynamicObject(19464, 2519.5175, -1530.1538, 20.5827, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[89], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[90] = CreateDynamicObject(19604, 2502.7080, -1531.6085, 22.1357, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    object_bikeDealership[91] = CreateDynamicObject(18763, 2524.1909, -1528.6529, 21.6354, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[91], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[92] = CreateDynamicObject(19464, 2519.6105, -1530.1538, 20.5820, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[92], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[93] = CreateDynamicObject(18766, 2517.7099, -1532.1809, 22.6291, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[93], 0, 14476, "carlslounge", "AH_cheapredcarpet", 0xFFFFFAFA);
    object_bikeDealership[94] = CreateDynamicObject(1811, 2524.6499, -1533.9045, 23.7185, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_bikeDealership[95] = CreateDynamicObject(18766, 2530.5751, -1532.0506, 22.6291, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[95], 0, 10023, "bigwhitesfe", "archgrnd1_SFE", 0xFFFFFFFF);
    object_bikeDealership[96] = CreateDynamicObject(18763, 2525.1918, -1531.8337, 21.6347, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_bikeDealership[96], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[97] = CreateDynamicObject(19175, 2509.7736, -1534.3038, 23.1275, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_bikeDealership[97], 0, "3", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 25, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_bikeDealership[97], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[98] = CreateDynamicObject(19464, 2527.0400, -1528.6191, 24.6616, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[98], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFF800000);
    object_bikeDealership[99] = CreateDynamicObject(1234, 2510.7719, -1521.1883, 23.0599, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bikeDealership[99], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    SetDynamicObjectMaterial(object_bikeDealership[99], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[100] = CreateDynamicObject(19464, 2522.7006, -1532.3055, 20.5816, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[100], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[101] = CreateDynamicObject(19789, 2504.9594, -1524.0035, 22.4223, 0.0000, 9.6997, 29.1998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube1mx1m
    SetDynamicObjectMaterial(object_bikeDealership[101], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFAFA);
    // Ramp (FCR-900) .streamdistance = -1
    object_bikeDealership[102] = CreateDynamicObject(19430, 2505.4741, -1527.2187, 23.3362, 0.0000, 80.1998, -151.1000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_bikeDealership[102], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    object_bikeDealership[103] = CreateDynamicObject(19789, 2504.0996, -1524.4846, 22.5907, 0.0000, 9.6997, 29.1998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube1mx1m
    SetDynamicObjectMaterial(object_bikeDealership[103], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFAFA);
    object_bikeDealership[104] = CreateDynamicObject(19789, 2504.4443, -1527.8452, 22.5865, 0.0000, 9.6997, 29.1998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube1mx1m
    SetDynamicObjectMaterial(object_bikeDealership[104], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFAFA);
    object_bikeDealership[105] = CreateDynamicObject(19789, 2505.2880, -1527.3736, 22.4213, 0.0000, 9.6997, 29.1998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube1mx1m
    SetDynamicObjectMaterial(object_bikeDealership[105], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFAFA);
    // Podium for other bikes .streamdistance = -1
    object_bikeDealership[106] = CreateDynamicObject(18766, 2516.7590, -1533.2219, 22.7688, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[106], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    object_bikeDealership[107] = CreateDynamicObject(970, 2505.4526, -1529.0124, 23.6422, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_bikeDealership[107], 0, 14581, "ab_mafiasuitea", "barbersmir1", 0x00000000);
    SetDynamicObjectMaterial(object_bikeDealership[107], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_bikeDealership[108] = CreateDynamicObject(19464, 2521.7299, -1533.6567, 20.7217, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[108], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[109] = CreateDynamicObject(18762, 2503.0661, -1531.4913, 26.3673, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[109], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[110] = CreateDynamicObject(19464, 2511.7880, -1533.6567, 20.7206, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[110], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[111] = CreateDynamicObject(19464, 2518.8710, -1530.8071, 20.7229, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[111], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[112] = CreateDynamicObject(19464, 2514.6486, -1530.8059, 20.7217, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[112], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[113] = CreateDynamicObject(18762, 2501.1989, -1533.8398, 22.6037, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[113], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[114] = CreateDynamicObject(18762, 2504.1989, -1535.8386, 22.6037, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[114], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[115] = CreateDynamicObject(1656, 2515.7712, -1530.4808, 23.0799, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_bikeDealership[115], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    object_bikeDealership[116] = CreateDynamicObject(19464, 2516.5778, -1533.2264, 20.7154, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[116], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[117] = CreateDynamicObject(18762, 2509.1989, -1535.8386, 22.6037, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[117], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[118] = CreateDynamicObject(1656, 2515.7712, -1530.7711, 23.1508, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_bikeDealership[118], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    object_bikeDealership[119] = CreateDynamicObject(19464, 2514.9667, -1533.2264, 20.7129, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[119], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[120] = CreateDynamicObject(18762, 2537.4052, -1535.8386, 22.6028, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[120], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[121] = CreateDynamicObject(18762, 2540.4001, -1533.8391, 22.6037, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[121], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[122] = CreateDynamicObject(18762, 2532.4057, -1535.8386, 22.6028, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[122], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[123] = CreateDynamicObject(18762, 2527.4060, -1535.8386, 22.6028, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[123], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[124] = CreateDynamicObject(18762, 2522.4067, -1535.8386, 22.8127, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[124], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[125] = CreateDynamicObject(18762, 2517.4084, -1535.8386, 22.8127, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[125], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[126] = CreateDynamicObject(18762, 2512.4086, -1535.8386, 22.8127, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[126], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[127] = CreateDynamicObject(18762, 2512.4086, -1536.8382, 22.8127, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[127], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[128] = CreateDynamicObject(18762, 2517.4084, -1536.8382, 22.8127, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[128], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[129] = CreateDynamicObject(18762, 2522.4067, -1536.8382, 22.8127, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[129], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[130] = CreateDynamicObject(2161, 2502.6962, -1532.2674, 28.1674, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_bikeDealership[131] = CreateDynamicObject(18980, 2503.1101, -1533.9499, 14.6827, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[131], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[132] = CreateDynamicObject(18980, 2503.1101, -1529.4696, 14.6827, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[132], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[133] = CreateDynamicObject(19464, 2506.5266, -1534.2728, 20.5839, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[133], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[134] = CreateDynamicObject(19604, 2505.3764, -1531.6485, 23.1354, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    object_bikeDealership[135] = CreateDynamicObject(18766, 2502.1806, -1526.0616, 29.8994, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[135], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[136] = CreateDynamicObject(19464, 2507.5976, -1534.2728, 20.5848, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[136], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[137] = CreateDynamicObject(19464, 2504.7048, -1529.0323, 20.5848, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[137], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[138] = CreateDynamicObject(18762, 2504.9067, -1521.6218, 31.8950, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[138], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[139] = CreateDynamicObject(18762, 2504.7170, -1520.6606, 26.8575, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[139], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[140] = CreateDynamicObject(18762, 2513.5666, -1520.6606, 26.8575, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[140], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[141] = CreateDynamicObject(18762, 2518.8671, -1526.0705, 26.8575, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[141], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[142] = CreateDynamicObject(18762, 2501.1989, -1532.0395, 22.6536, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[142], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[143] = CreateDynamicObject(18762, 2524.2673, -1526.0705, 26.8575, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[143], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[144] = CreateDynamicObject(18762, 2516.0771, -1523.3507, 26.8565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[144], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[145] = CreateDynamicObject(18762, 2501.1989, -1531.5290, 22.6527, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[145], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[146] = CreateDynamicObject(18762, 2500.1984, -1531.5290, 22.6527, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[146], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[147] = CreateDynamicObject(18766, 2507.5832, -1523.2894, 26.8437, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[147], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[148] = CreateDynamicObject(18762, 2500.1975, -1532.0395, 22.6536, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[148], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_bikeDealership[149] = CreateDynamicObject(18766, 2510.8029, -1523.2894, 26.8470, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[149], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[150] = CreateDynamicObject(18766, 2510.8029, -1528.2894, 26.8470, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[150], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[151] = CreateDynamicObject(18766, 2510.8029, -1532.3894, 26.8439, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[151], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[152] = CreateDynamicObject(18766, 2507.5832, -1528.2209, 26.8490, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[152], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[153] = CreateDynamicObject(18766, 2507.5832, -1531.9326, 26.8435, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[153], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[154] = CreateDynamicObject(18762, 2508.4284, -1520.6601, 26.8579, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[154], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[155] = CreateDynamicObject(18766, 2520.7321, -1532.3894, 26.8470, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[155], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[156] = CreateDynamicObject(18766, 2530.7148, -1532.3894, 26.8435, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[156], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[157] = CreateDynamicObject(18766, 2534.1267, -1532.3894, 26.8470, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[157], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[158] = CreateDynamicObject(18766, 2520.7458, -1529.0699, 26.8530, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[158], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[159] = CreateDynamicObject(18766, 2530.7287, -1529.0699, 26.8500, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[159], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[160] = CreateDynamicObject(18766, 2534.1074, -1529.0699, 26.8530, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[160], 0, 18031, "cj_exp", "mp_furn_floor", 0xFFFFFAFA);
    object_bikeDealership[161] = CreateDynamicObject(1811, 2525.5407, -1533.9045, 23.7185, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_bikeDealership[162] = CreateDynamicObject(18766, 2530.5754, -1529.0699, 22.6329, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[162], 0, 10023, "bigwhitesfe", "archgrnd1_SFE", 0xFFFFFFFF);
    object_bikeDealership[163] = CreateDynamicObject(1811, 2523.7390, -1533.9045, 23.7185, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_bikeDealership[164] = CreateDynamicObject(3051, 2508.2741, -1534.2921, 24.1361, 0.0000, 0.0000, 136.2998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_bikeDealership[164], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0x00000000);
    object_bikeDealership[165] = CreateDynamicObject(18766, 2534.5949, -1532.0506, 22.6282, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[165], 0, 10023, "bigwhitesfe", "archgrnd1_SFE", 0xFFFFFFFF);
    object_bikeDealership[166] = CreateDynamicObject(18766, 2534.5949, -1529.0699, 22.6319, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[166], 0, 10023, "bigwhitesfe", "archgrnd1_SFE", 0xFFFFFFFF);
    object_bikeDealership[167] = CreateDynamicObject(1234, 2503.6337, -1529.0240, 23.0599, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bikeDealership[167], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    SetDynamicObjectMaterial(object_bikeDealership[167], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[168] = CreateDynamicObject(2267, 2524.6245, -1534.2738, 25.0561, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_WOOD_3
    SetDynamicObjectMaterial(object_bikeDealership[168], 0, 1560, "7_11_door", "CJ_CHROME2", 0x00000000);
    SetDynamicObjectMaterial(object_bikeDealership[168], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0x00000000);
    object_bikeDealership[169] = CreateDynamicObject(19175, 2509.6835, -1534.3038, 23.2075, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_bikeDealership[169], 0, "1", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 35, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_bikeDealership[169], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[170] = CreateDynamicObject(18766, 2506.7487, -1534.8077, 29.9036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[170], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[171] = CreateDynamicObject(19464, 2526.7849, -1528.6191, 24.6616, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[171], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFF800000);
    object_bikeDealership[172] = CreateDynamicObject(3051, 2508.2741, -1534.2921, 28.6861, 0.0000, 0.0000, 136.2998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_bikeDealership[172], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0x00000000);
    object_bikeDealership[173] = CreateDynamicObject(3051, 2507.1054, -1534.2961, 28.6861, 0.0000, 0.0000, -43.5998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_bikeDealership[173], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0x00000000);
    object_bikeDealership[174] = CreateDynamicObject(19175, 2509.6835, -1534.3038, 27.6574, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_bikeDealership[174], 0, "1", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 35, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_bikeDealership[174], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[175] = CreateDynamicObject(19175, 2508.5524, -1534.3038, 30.0774, 0.0000, -90.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_bikeDealership[175], 0, "3", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 25, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_bikeDealership[175], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[176] = CreateDynamicObject(18014, 2524.0161, -1526.9167, 23.3299, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int_rest_veg03
    object_bikeDealership[177] = CreateDynamicObject(18766, 2508.2397, -1534.8100, 29.9004, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[177], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[178] = CreateDynamicObject(18976, 2526.4946, -1528.2358, 24.4867, 0.0000, -18.6000, 104.6997, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet2
    object_bikeDealership[179] = CreateDynamicObject(18014, 2518.9235, -1526.9167, 23.3299, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int_rest_veg03
    object_bikeDealership[180] = CreateDynamicObject(18766, 2502.1796, -1529.5600, 29.9004, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[180], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[181] = CreateDynamicObject(19903, 2536.2390, -1533.9558, 23.0809, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
    object_bikeDealership[182] = CreateDynamicObject(18762, 2509.9064, -1521.6208, 31.8950, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[182], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[183] = CreateDynamicObject(18762, 2513.0781, -1521.6219, 31.8959, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[183], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[184] = CreateDynamicObject(18762, 2513.0781, -1521.6219, 27.8258, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[184], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[185] = CreateDynamicObject(18762, 2509.1479, -1521.6198, 27.8239, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[185], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[186] = CreateDynamicObject(19921, 2534.6398, -1533.5935, 23.9789, 0.0000, 0.0000, -153.8999, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneToolBox1
    object_bikeDealership[187] = CreateDynamicObject(19900, 2538.3937, -1533.0753, 23.1152, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolCabinet2
    object_bikeDealership[188] = CreateDynamicObject(19899, 2538.4030, -1531.4887, 23.0990, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolCabinet1
    object_bikeDealership[189] = CreateDynamicObject(18762, 2505.0480, -1521.6219, 27.8250, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[189], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[190] = CreateDynamicObject(19893, 2538.4714, -1532.3333, 24.3423, 0.0000, 0.0000, -106.6998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_bikeDealership[191] = CreateDynamicObject(18762, 2515.0686, -1523.6120, 27.8269, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[191], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[192] = CreateDynamicObject(18762, 2515.0690, -1524.0742, 27.8239, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[192], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[193] = CreateDynamicObject(18762, 2515.0686, -1523.6120, 31.8969, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[193], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[194] = CreateDynamicObject(18762, 2515.0690, -1524.0742, 31.8948, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[194], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[195] = CreateDynamicObject(19464, 2515.0500, -1529.5478, 29.7849, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[195], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[196] = CreateDynamicObject(19815, 2533.6191, -1534.3022, 25.0191, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolBoard1
    object_bikeDealership[197] = CreateDynamicObject(19922, 2533.6201, -1533.5737, 23.0983, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_bikeDealership[198] = CreateDynamicObject(1716, 2537.5505, -1532.8874, 23.0958, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_bikeDealership[199] = CreateDynamicObject(19917, 2538.2143, -1529.5804, 23.0739, 0.0000, 0.0000, 109.6000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneEngine1
    object_bikeDealership[200] = CreateDynamicObject(18766, 2510.2312, -1534.8120, 29.9008, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[200], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[201] = CreateDynamicObject(1486, 2534.2258, -1534.0422, 24.0181, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BEER_1
    object_bikeDealership[202] = CreateDynamicObject(1486, 2534.0620, -1534.0355, 23.9185, 90.6998, -0.0998, -143.0998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BEER_1
    object_bikeDealership[203] = CreateDynamicObject(1649, 2505.3579, -1521.6297, 29.9314, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[203], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[204] = CreateDynamicObject(1649, 2505.1376, -1521.6297, 29.9314, 180.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[204], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[205] = CreateDynamicObject(19627, 2538.3962, -1530.5363, 24.3549, 0.0000, 0.0000, -15.9998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Wrench1
    object_bikeDealership[206] = CreateDynamicObject(1649, 2512.7878, -1521.6297, 29.9314, 180.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[206], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[207] = CreateDynamicObject(1649, 2512.6877, -1521.6297, 29.9314, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[207], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[208] = CreateDynamicObject(19089, 2509.1684, -1521.6275, 31.3780, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[208], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[209] = CreateDynamicObject(18762, 2515.0659, -1521.6208, 29.8348, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[209], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[210] = CreateDynamicObject(18762, 2503.1152, -1521.6208, 29.8348, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[210], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[211] = CreateDynamicObject(19354, 2508.9365, -1521.6259, 29.8369, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_bikeDealership[211], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[212] = CreateDynamicObject(18633, 2533.7751, -1533.5068, 23.9127, 1.6000, 90.0000, -96.8999, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAWrench1
    object_bikeDealership[213] = CreateDynamicObject(19894, 2538.5258, -1530.9094, 24.3398, 0.0000, 0.0000, -100.5998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP2
    object_bikeDealership[214] = CreateDynamicObject(19089, 2515.4892, -1521.6275, 31.3780, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[214], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[215] = CreateDynamicObject(19089, 2515.4892, -1521.6275, 28.3479, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[215], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[216] = CreateDynamicObject(2103, 2532.6337, -1533.9406, 23.8854, 0.0000, 0.0000, 158.1000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_HI_FI_1
    object_bikeDealership[217] = CreateDynamicObject(19089, 2509.3979, -1521.6275, 28.3479, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[217], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[218] = CreateDynamicObject(19089, 2509.3979, -1521.6275, 29.9678, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[218], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[219] = CreateDynamicObject(18634, 2533.4091, -1533.6048, 23.9027, 0.0000, 90.0000, -134.6999, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASACrowbar1
    object_bikeDealership[220] = CreateDynamicObject(19089, 2515.3498, -1521.6275, 29.9678, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[220], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[221] = CreateDynamicObject(19631, 2533.5654, -1534.1257, 24.2912, -83.0999, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SledgeHammer1
    object_bikeDealership[222] = CreateDynamicObject(18766, 2506.8088, -1535.0777, 24.9437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[222], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[223] = CreateDynamicObject(1649, 2515.0993, -1524.3399, 29.9314, 180.0000, 0.0000, 270.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[223], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[224] = CreateDynamicObject(18766, 2516.8081, -1535.0777, 24.9437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[224], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[225] = CreateDynamicObject(18766, 2526.8171, -1535.0777, 24.9437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[225], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[226] = CreateDynamicObject(18766, 2534.8566, -1535.0758, 24.9437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[226], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[227] = CreateDynamicObject(1649, 2515.0993, -1524.3399, 29.9314, 180.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[227], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[228] = CreateDynamicObject(19087, 2515.1049, -1525.5793, 30.5790, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[228], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[229] = CreateDynamicObject(19464, 2515.0490, -1531.4598, 29.7849, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[229], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[230] = CreateDynamicObject(18766, 2510.2312, -1535.0720, 29.9008, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[230], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[231] = CreateDynamicObject(18766, 2506.7199, -1535.0728, 29.9008, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[231], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[232] = CreateDynamicObject(18762, 2515.0659, -1526.1009, 29.8348, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[232], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[233] = CreateDynamicObject(18645, 2526.5075, -1528.5927, 24.4785, 0.0000, -27.7999, 149.6000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet1
    object_bikeDealership[234] = CreateDynamicObject(19089, 2515.1088, -1521.6275, 28.3479, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[234], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[235] = CreateDynamicObject(1744, 2526.8513, -1528.5080, 24.0540, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_bikeDealership[236] = CreateDynamicObject(19089, 2515.0891, -1521.6275, 31.3780, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[236], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[237] = CreateDynamicObject(19089, 2515.0891, -1521.3382, 29.9678, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_bikeDealership[237], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[238] = CreateDynamicObject(18762, 2505.3110, -1528.4256, 27.7189, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[238], 0, 14652, "ab_trukstpa", "CJ_WOOD6", 0x00000000);
    object_bikeDealership[239] = CreateDynamicObject(633, 2526.3210, -1530.8454, 24.1051, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_palmkb10
    object_bikeDealership[240] = CreateDynamicObject(18978, 2526.5056, -1528.9555, 24.4685, 0.0000, -23.5000, -146.0998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet4
    SetDynamicObjectMaterial(object_bikeDealership[240], 0, -1, "none", "none", 0xFF008000);
    object_bikeDealership[241] = CreateDynamicObject(18978, 2526.4956, -1529.3352, 24.4657, 0.0000, -23.5000, 152.9998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet4
    SetDynamicObjectMaterial(object_bikeDealership[241], 0, -1, "none", "none", 0xFF696969);
    object_bikeDealership[242] = CreateDynamicObject(18978, 2526.5053, -1529.7059, 24.4857, 0.0000, -23.5000, 175.6000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet4
    SetDynamicObjectMaterial(object_bikeDealership[242], 0, -1, "none", "none", 0xFFFF8C00);
    object_bikeDealership[243] = CreateDynamicObject(18762, 2505.3720, -1528.4228, 27.7000, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[243], 0, 14794, "ab_vegasgymmain", "studiowall2_law", 0x00000000);
    object_bikeDealership[244] = CreateDynamicObject(19175, 2526.6704, -1528.9704, 24.9761, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_bikeDealership[244], 0, "Helme", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 100, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bikeDealership[244], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[245] = CreateDynamicObject(18762, 2505.3730, -1528.4428, 27.7098, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[245], 0, 14794, "ab_vegasgymmain", "studiowall2_law", 0x00000000);
    object_bikeDealership[246] = CreateDynamicObject(18762, 2505.2709, -1528.4239, 27.7119, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[246], 0, 14794, "ab_vegasgymmain", "studiowall2_law", 0x00000000);
    object_bikeDealership[247] = CreateDynamicObject(18762, 2505.2719, -1528.4338, 27.7049, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[247], 0, 14794, "ab_vegasgymmain", "studiowall2_law", 0x00000000);
    object_bikeDealership[248] = CreateDynamicObject(2190, 2505.7209, -1529.6411, 28.2129, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PC_1
    object_bikeDealership[249] = CreateDynamicObject(2190, 2505.7209, -1527.6506, 28.2129, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PC_1
    object_bikeDealership[250] = CreateDynamicObject(19808, 2505.0424, -1527.4135, 28.2350, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_bikeDealership[251] = CreateDynamicObject(19808, 2505.0424, -1529.4139, 28.2350, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_bikeDealership[252] = CreateDynamicObject(1714, 2503.5986, -1527.4924, 27.3525, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_bikeDealership[253] = CreateDynamicObject(1714, 2503.5986, -1529.4926, 27.3525, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_bikeDealership[254] = CreateDynamicObject(2161, 2502.6962, -1524.5770, 28.1674, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_bikeDealership[255] = CreateDynamicObject(2162, 2505.0725, -1534.3098, 27.8946, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_bikeDealership[256] = CreateDynamicObject(2164, 2502.7397, -1527.1396, 27.3320, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    object_bikeDealership[257] = CreateDynamicObject(19087, 2515.1049, -1522.1391, 30.5790, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[257], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[258] = CreateDynamicObject(2164, 2502.6796, -1530.2801, 27.3320, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    object_bikeDealership[259] = CreateDynamicObject(1649, 2509.5073, -1523.8891, 28.9612, 180.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[259], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[260] = CreateDynamicObject(2001, 2503.1918, -1528.3221, 27.3083, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    object_bikeDealership[261] = CreateDynamicObject(19087, 2515.1049, -1522.1391, 31.5289, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[261], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[262] = CreateDynamicObject(19087, 2507.3327, -1521.6295, 31.3990, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[262], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[263] = CreateDynamicObject(1722, 2510.9291, -1526.8642, 27.3327, 0.0000, 0.0000, -19.4999, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_bikeDealership[264] = CreateDynamicObject(1649, 2509.5073, -1523.8891, 28.9612, 180.0000, 0.0000, 270.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[264], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[265] = CreateDynamicObject(1722, 2513.3146, -1526.8299, 27.3327, 0.0000, 0.0000, 18.2999, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_bikeDealership[266] = CreateDynamicObject(1649, 2512.7204, -1529.5189, 28.9613, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[266], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[267] = CreateDynamicObject(19087, 2514.5644, -1521.6295, 31.4790, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[267], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[268] = CreateDynamicObject(1722, 2513.1301, -1534.1462, 27.3327, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_bikeDealership[269] = CreateDynamicObject(19087, 2514.5644, -1521.6295, 30.6889, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[269], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[270] = CreateDynamicObject(1722, 2512.1892, -1534.1462, 27.3327, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_bikeDealership[271] = CreateDynamicObject(19087, 2510.5642, -1521.6295, 30.6889, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[271], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[272] = CreateDynamicObject(2184, 2511.0659, -1525.3341, 27.3288, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_DESK_2
    object_bikeDealership[273] = CreateDynamicObject(1722, 2511.2675, -1534.1462, 27.3327, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_bikeDealership[274] = CreateDynamicObject(1714, 2512.2565, -1523.0002, 27.3525, 0.0000, 0.0000, -6.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_bikeDealership[275] = CreateDynamicObject(19997, 2514.0537, -1530.5097, 27.3470, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneGrgTable1
    SetDynamicObjectMaterial(object_bikeDealership[275], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0x00000000);
    object_bikeDealership[276] = CreateDynamicObject(19087, 2510.5642, -1521.6295, 31.4689, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[276], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[277] = CreateDynamicObject(19087, 2515.1049, -1525.5793, 31.4790, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[277], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[278] = CreateDynamicObject(19087, 2503.6330, -1521.6295, 31.4689, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[278], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[279] = CreateDynamicObject(2002, 2514.1979, -1533.7187, 27.3379, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
    object_bikeDealership[280] = CreateDynamicObject(11743, 2514.3454, -1530.2004, 28.1630, 0.0000, 0.0000, -72.5999, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCoffeeMachine1
    object_bikeDealership[281] = CreateDynamicObject(1722, 2510.3266, -1534.1462, 27.3327, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_bikeDealership[282] = CreateDynamicObject(19087, 2503.6330, -1521.6295, 30.5189, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[282], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[283] = CreateDynamicObject(19087, 2507.3327, -1521.6295, 30.5189, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_bikeDealership[283], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[284] = CreateDynamicObject(1649, 2512.7204, -1529.5189, 28.9613, 180.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_bikeDealership[284], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
    object_bikeDealership[285] = CreateDynamicObject(19825, 2502.7250, -1528.3415, 29.9990, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
    object_bikeDealership[286] = CreateDynamicObject(19565, 2510.5122, -1529.6513, 27.5788, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[286], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[287] = CreateDynamicObject(19835, 2514.4389, -1530.8148, 28.2831, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_bikeDealership[288] = CreateDynamicObject(19835, 2514.4389, -1530.4643, 28.2831, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_bikeDealership[289] = CreateDynamicObject(19835, 2514.4389, -1530.4643, 28.3330, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_bikeDealership[290] = CreateDynamicObject(19835, 2514.4389, -1530.4643, 28.3831, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_bikeDealership[291] = CreateDynamicObject(19835, 2514.4389, -1530.4643, 28.4430, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_bikeDealership[292] = CreateDynamicObject(19565, 2510.5122, -1529.6513, 28.0289, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[292], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[293] = CreateDynamicObject(19565, 2511.1325, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[293], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[294] = CreateDynamicObject(19565, 2510.5122, -1529.6513, 28.4789, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[294], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[295] = CreateDynamicObject(19835, 2505.3864, -1529.9139, 28.3031, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_bikeDealership[296] = CreateDynamicObject(19565, 2510.5122, -1529.6513, 28.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[296], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[297] = CreateDynamicObject(19565, 2510.5122, -1529.6513, 29.3288, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[297], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[298] = CreateDynamicObject(19565, 2510.5122, -1529.6513, 29.7989, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[298], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[299] = CreateDynamicObject(19835, 2505.3864, -1526.9536, 28.3031, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_bikeDealership[300] = CreateDynamicObject(19565, 2510.5122, -1529.6513, 30.2388, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[300], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[301] = CreateDynamicObject(19835, 2511.9494, -1524.8128, 28.1930, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_bikeDealership[302] = CreateDynamicObject(19565, 2510.5122, -1529.6513, 30.4088, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[302], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[303] = CreateDynamicObject(19565, 2510.7124, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[303], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[304] = CreateDynamicObject(19893, 2512.3320, -1524.8028, 28.0937, 0.0000, 0.0000, -162.3999, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_bikeDealership[305] = CreateDynamicObject(19565, 2511.5329, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[305], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[306] = CreateDynamicObject(19565, 2512.0031, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[306], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[307] = CreateDynamicObject(19565, 2512.4536, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[307], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[308] = CreateDynamicObject(19565, 2512.8334, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[308], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[309] = CreateDynamicObject(2001, 2514.1457, -1522.5604, 27.4584, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    object_bikeDealership[310] = CreateDynamicObject(19565, 2513.2939, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[310], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[311] = CreateDynamicObject(19565, 2513.7543, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[311], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[312] = CreateDynamicObject(19565, 2514.1748, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[312], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[313] = CreateDynamicObject(19565, 2514.6350, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[313], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[314] = CreateDynamicObject(19565, 2514.6950, -1529.6513, 30.6298, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[314], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[315] = CreateDynamicObject(19565, 2509.3613, -1526.0819, 27.4988, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[315], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[316] = CreateDynamicObject(19565, 2509.3613, -1526.0819, 27.9088, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[316], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[317] = CreateDynamicObject(19565, 2509.3613, -1526.0819, 28.3789, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[317], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[318] = CreateDynamicObject(19565, 2509.3613, -1526.0819, 30.4489, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[318], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[319] = CreateDynamicObject(19565, 2509.3613, -1526.0819, 28.8089, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[319], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[320] = CreateDynamicObject(19565, 2509.3613, -1526.0819, 29.2089, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[320], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[321] = CreateDynamicObject(19565, 2509.3613, -1526.0819, 29.6389, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[321], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[322] = CreateDynamicObject(19565, 2509.3613, -1526.0819, 30.0289, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[322], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[323] = CreateDynamicObject(19565, 2509.3613, -1525.8819, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[323], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[324] = CreateDynamicObject(19565, 2509.3613, -1525.4316, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[324], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[325] = CreateDynamicObject(19565, 2509.3613, -1524.5212, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[325], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[326] = CreateDynamicObject(19565, 2509.3613, -1524.9915, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[326], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[327] = CreateDynamicObject(19565, 2509.3613, -1524.0611, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[327], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[328] = CreateDynamicObject(19565, 2509.3613, -1523.6711, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[328], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[329] = CreateDynamicObject(19565, 2509.3613, -1523.2412, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[329], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[330] = CreateDynamicObject(19565, 2509.3613, -1522.8409, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[330], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[331] = CreateDynamicObject(18766, 2509.4868, -1530.6311, 33.6402, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[331], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[332] = CreateDynamicObject(19565, 2509.3613, -1522.4207, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[332], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[333] = CreateDynamicObject(19173, 2511.7807, -1534.3055, 29.4981, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_bikeDealership[333], 0, "Warteraum", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 100, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bikeDealership[333], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[334] = CreateDynamicObject(19565, 2509.3613, -1521.9405, 30.6450, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_bikeDealership[334], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[335] = CreateDynamicObject(18762, 2515.0700, -1528.2641, 31.8959, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[335], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[336] = CreateDynamicObject(18762, 2515.0690, -1532.9433, 31.8948, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[336], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[337] = CreateDynamicObject(18766, 2504.5810, -1530.6311, 34.5752, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[337], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[338] = CreateDynamicObject(18766, 2499.6801, -1530.6311, 35.5102, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[338], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[339] = CreateDynamicObject(18766, 2502.1918, -1526.0570, 24.9416, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[339], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[340] = CreateDynamicObject(18766, 2514.3906, -1524.9514, 32.7041, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[340], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[341] = CreateDynamicObject(18766, 2509.4860, -1524.9514, 33.6390, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[341], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[342] = CreateDynamicObject(18766, 2514.3906, -1530.6311, 32.7051, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[342], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[343] = CreateDynamicObject(19437, 2507.7080, -1521.2457, 33.1426, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall077
    SetDynamicObjectMaterial(object_bikeDealership[343], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[344] = CreateDynamicObject(19437, 2511.2072, -1521.2457, 32.5625, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall077
    SetDynamicObjectMaterial(object_bikeDealership[344], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[345] = CreateDynamicObject(18980, 2502.1589, -1535.1289, 22.2728, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[345], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[346] = CreateDynamicObject(18766, 2502.1796, -1526.0616, 32.9094, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[346], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[347] = CreateDynamicObject(18766, 2502.1787, -1530.5750, 32.9094, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[347], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_bikeDealership[348] = CreateDynamicObject(18766, 2504.5822, -1524.9514, 34.5741, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[348], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[349] = CreateDynamicObject(18766, 2499.6743, -1524.9514, 35.5111, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[349], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[350] = CreateDynamicObject(18766, 2538.0620, -1530.5909, 28.1893, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[350], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[351] = CreateDynamicObject(18766, 2533.1579, -1530.5909, 29.1243, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[351], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[352] = CreateDynamicObject(18766, 2528.2531, -1530.5909, 30.0594, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[352], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[353] = CreateDynamicObject(18766, 2523.3508, -1530.5909, 30.9944, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[353], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[354] = CreateDynamicObject(18766, 2518.4399, -1530.5898, 31.9302, 100.8000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[354], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFAFA);
    object_bikeDealership[355] = CreateDynamicObject(19172, 2524.2031, -1522.6346, 22.9953, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bikeDealership[355], 0, "P", OBJECT_MATERIAL_SIZE_256x128, "Arial", 200, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bikeDealership[355], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[356] = CreateDynamicObject(18766, 2516.9030, -1535.0830, 29.3048, 0.0000, 190.8000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[356], 0, 16640, "a51", "vgs_shopwall01_128", 0xFFFFFFFF);
    object_bikeDealership[357] = CreateDynamicObject(18766, 2526.7163, -1535.0830, 27.4330, 0.0000, 190.8000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[357], 0, 16640, "a51", "vgs_shopwall01_128", 0xFFFFFFFF);
    object_bikeDealership[358] = CreateDynamicObject(18766, 2534.5385, -1535.0820, 25.9414, 0.0000, 190.8000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[358], 0, 16640, "a51", "vgs_shopwall01_128", 0xFFFFFFFF);
    object_bikeDealership[359] = CreateDynamicObject(18980, 2539.4030, -1535.0855, 15.4528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[359], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[360] = CreateDynamicObject(18766, 2507.0864, -1535.0830, 31.1769, 0.0000, 190.8000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[360], 0, 16640, "a51", "vgs_shopwall01_128", 0xFFFFFFFF);
    object_bikeDealership[361] = CreateDynamicObject(18980, 2527.4511, -1526.1800, 29.2161, 0.0000, 1000.7999, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[361], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[362] = CreateDynamicObject(19464, 2518.5007, -1526.6689, 28.9748, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[362], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[363] = CreateDynamicObject(19354, 2523.0539, -1526.6357, 28.3670, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_bikeDealership[363], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[364] = CreateDynamicObject(19354, 2526.2568, -1526.6357, 28.3670, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_bikeDealership[364], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[365] = CreateDynamicObject(19354, 2529.4665, -1526.6357, 28.2169, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_bikeDealership[365], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[366] = CreateDynamicObject(19354, 2504.2160, -1521.2457, 33.0069, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_bikeDealership[366], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[367] = CreateDynamicObject(18766, 2502.1672, -1529.9034, 32.1710, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[367], 0, 16640, "a51", "vgs_shopwall01_128", 0xFFFFFFFF);
    object_bikeDealership[368] = CreateDynamicObject(18766, 2502.1672, -1526.0600, 32.1710, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bikeDealership[368], 0, 16640, "a51", "vgs_shopwall01_128", 0xFFFFFFFF);
    object_bikeDealership[369] = CreateDynamicObject(19437, 2513.4291, -1521.2467, 32.2326, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall077
    SetDynamicObjectMaterial(object_bikeDealership[369], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[370] = CreateDynamicObject(18980, 2533.6555, -1514.2585, 13.3527, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[370], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[371] = CreateDynamicObject(2894, 2513.8579, -1530.6300, 28.1888, 0.0000, 0.0000, -55.8998, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_bikeDealership[371], 0, 2266, "picture_frame", "CJ_PAINTING19", 0x00000000);
    object_bikeDealership[372] = CreateDynamicObject(18980, 2527.6247, -1514.2585, 13.3527, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bikeDealership[372], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0x00000000);
    object_bikeDealership[373] = CreateDynamicObject(19464, 2530.6206, -1514.2508, 23.0249, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[373], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
    object_bikeDealership[374] = CreateDynamicObject(18014, 2530.6757, -1515.0255, 23.3299, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int_rest_veg03
    object_bikeDealership[375] = CreateDynamicObject(19172, 2530.1530, -1514.1346, 24.2752, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bikeDealership[375], 0, "Motorradhaus", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 100, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bikeDealership[375], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[376] = CreateDynamicObject(19464, 2521.4494, -1522.9566, 20.4615, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[376], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[377] = CreateDynamicObject(19464, 2526.8508, -1522.9566, 20.4615, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bikeDealership[377], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_bikeDealership[378] = CreateDynamicObject(19172, 2518.8813, -1522.6346, 22.9953, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bikeDealership[378], 0, "P", OBJECT_MATERIAL_SIZE_256x128, "Arial", 200, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bikeDealership[378], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bikeDealership[379] = CreateDynamicObject(18075, 2519.7976, -1530.5634, 26.4172, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bikeDealership[380] = CreateDynamicObject(1215, 2526.9365, -1514.3519, 23.4680, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_bikeDealership[381] = CreateDynamicObject(18075, 2509.1040, -1527.7838, 26.4172, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bikeDealership[382] = CreateDynamicObject(18075, 2509.1206, -1528.1840, 33.2457, 0.0000, 10.8000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bikeDealership[383] = CreateDynamicObject(18075, 2533.2680, -1530.5935, 26.4172, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bikeDealership[384] = CreateDynamicObject(1215, 2534.3186, -1514.3519, 23.4680, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_bikeDealership[385] = CreateDynamicObject(19172, 2531.9733, -1514.1346, 24.2453, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_BIKEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bikeDealership[385], 0, "ß", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 100, 0, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bikeDealership[385], 1, 19297, "matlights", "invisible", 0x00000000);
}
