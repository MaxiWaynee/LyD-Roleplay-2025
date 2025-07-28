#include <YSI\y_hooks>

// Global interior define
#define MAPS_SANABASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 250.0;
static Float:DRAWDISTANCE   = 230.0;

// SA-NA donation, spawn and duty point
#define SANABASE_DONATION_POINT             -26.9868, -2499.7585, 36.6484
#define SANABASE_DUTY_POINT                 -41.6871, -2501.5251, 36.7248
#define SANABASE_DUTY_POINT_FACING          305.0879
#define SANABASE_HELICOPTER_DOWN_POINT      -28.7642, -2493.7893, 36.8448
#define SANABASE_HELICOPTER_UP_POINT        -28.9242, -2493.6992, 40.2647
#define SANABASE_HELICOPTER_DOWN_FACING     33.1628
#define SANABASE_HELICOPTER_UP_FACING       33.1628
#define SANABASE_GARAGE_FOR_RANGE_COORDS    -6.7410, -2508.9094, 37.4948
#define SANABASE_GARAGE_OPEN_Z              33.8548
#define SANABASE_GARAGE_CLOSED_Z            37.4948


// Map variables
new object_sanaBase[438];
new pickup_sanaBase[3];
new text3D_sanaBase[1];
new object_sanaBase_garageDoor;

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 17445, -11.2734, -2498.9766, 35.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17446, -34.8594, -2486.6016, 35.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17447, -10.1719, -2526.5859, 37.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 17041, -34.8594, -2486.6016, 35.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17042, -24.3203, -2528.1641, 35.5469, 0.25);
    RemoveBuildingForPlayer(playerid, 17070, -23.3750, -2507.1250, 35.6719, 0.25);
    RemoveBuildingForPlayer(playerid, 17044, -11.2734, -2498.9766, 35.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17045, -10.1719, -2526.5859, 37.2500, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, SANABASE_HELICOPTER_DOWN_POINT) && GetPlayerVirtualWorld(playerid) == VW_MAIN) { // Down
            SetPlayerFacingAngle(playerid, SANABASE_HELICOPTER_UP_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, SANABASE_HELICOPTER_UP_POINT, MAPS_SANABASE_INTERIOR, VW_MAIN);
        } else if (IsPlayerInRangeOfPoint(playerid, 2.0, SANABASE_HELICOPTER_UP_POINT) && GetPlayerVirtualWorld(playerid) == VW_MAIN) { // Up
            SetPlayerFacingAngle(playerid, SANABASE_HELICOPTER_DOWN_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, SANABASE_HELICOPTER_DOWN_POINT, MAPS_SANABASE_INTERIOR, VW_MAIN);
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Pickups
    pickup_sanaBase[0] = CreateDynamicPickup(1274, 1, SANABASE_DONATION_POINT, VW_MAIN, MAPS_SANABASE_INTERIOR); // Donations
    pickup_sanaBase[1] = CreateDynamicPickup(19197, 1, SANABASE_HELICOPTER_DOWN_POINT, VW_MAIN, MAPS_SANABASE_INTERIOR); // Teleport to Helicopter
    pickup_sanaBase[2] = CreateDynamicPickup(19197, 1, SANABASE_HELICOPTER_UP_POINT, VW_MAIN, MAPS_SANABASE_INTERIOR); // Teleport from Helicopter

    // 3DTextLabels
    text3D_sanaBase[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "SA-NA - SPENDENKASSE\n" COLOR_HEX_BLUE "/Newsspenden", COLOR_WHITE, SANABASE_DONATION_POINT, 28.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SANABASE_INTERIOR); // Donations
    
    // Vehicles

    // Objects
    object_sanaBase[0] = CreateDynamicObject(19464, -8.0312, -2491.2834, 37.4416, 180.0000, 0.0000, -60.2999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[0], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[1] = CreateDynamicObject(1886, -29.2042, -2486.4641, 36.2607, 180.0000, 0.0000, 32.1002, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_sanaBase[2] = CreateDynamicObject(18981, -4.8544, -2491.8571, 27.7178, 0.0000, 0.0000, 29.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_sanaBase[2], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[3] = CreateDynamicObject(18766, -48.9421, -2494.3701, 35.7159, 0.0000, 0.0000, -55.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[3], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[4] = CreateDynamicObject(18766, -38.9319, -2481.6171, 36.7106, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[4], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[5] = CreateDynamicObject(18766, -28.9150, -2499.0129, 33.2400, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[5], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[6] = CreateDynamicObject(18981, -28.6455, -2474.1992, 26.7103, 0.0000, 0.0000, -54.2098, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_sanaBase[6], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[7] = CreateDynamicObject(19431, -19.4377, -2506.5134, 37.4118, 90.0000, 0.0000, 29.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[7], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[8] = CreateDynamicObject(18766, -13.4469, -2476.6120, 37.7182, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[8], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[9] = CreateDynamicObject(18766, -16.6154, -2470.9916, 37.7182, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[9], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[10] = CreateDynamicObject(18766, -22.5748, -2501.0449, 34.2364, 0.0000, 0.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[10], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[11] = CreateDynamicObject(18766, -17.7884, -2509.5415, 34.2364, 0.0000, 0.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[11], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[12] = CreateDynamicObject(18981, 6.0176, -2511.1259, 24.8281, 0.0000, 0.0000, 29.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_sanaBase[12], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[13] = CreateDynamicObject(18766, -26.8892, -2497.5490, 33.2178, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[13], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[14] = CreateDynamicObject(18766, -23.3934, -2534.8361, 34.8300, 0.0000, 0.0000, -61.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[14], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[15] = CreateDynamicObject(18762, -22.2873, -2501.5725, 36.8273, 0.0000, 37.5998, 299.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[15], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[16] = CreateDynamicObject(18766, -0.9351, -2528.2612, 34.8300, 0.0000, 0.0000, 27.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[16], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[17] = CreateDynamicObject(18766, 7.9429, -2523.6645, 34.8300, 0.0000, 0.0000, 27.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[17], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[18] = CreateDynamicObject(18766, -9.8128, -2532.8620, 34.8300, 0.0000, 0.0000, 27.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[18], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[19] = CreateDynamicObject(1491, -28.9046, -2498.9980, 35.7144, 0.0000, 0.0000, 215.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_sanaBase[19], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    object_sanaBase[20] = CreateDynamicObject(18766, -16.9402, -2536.5551, 34.8278, 0.0000, 0.0000, 27.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[20], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[21] = CreateDynamicObject(18766, -28.2416, -2526.0905, 34.8278, 0.0000, 0.0000, -61.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[21], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[22] = CreateDynamicObject(3660, -21.6734, -2506.1582, 37.5326, 0.0000, 0.0000, -240.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_sanaBase[23] = CreateDynamicObject(18766, -0.7501, -2505.2434, 35.2074, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[23], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[24] = CreateDynamicObject(18766, -47.0424, -2487.4638, 36.7106, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[24], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[25] = CreateDynamicObject(18766, -12.9856, -2512.0275, 35.2070, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[25], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[26] = CreateDynamicObject(18766, -36.4883, -2504.4755, 34.2378, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[26], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[27] = CreateDynamicObject(1491, -31.3726, -2500.7480, 35.7144, 0.0000, 0.0000, 35.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_sanaBase[27], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    object_sanaBase[28] = CreateDynamicObject(18766, -35.3922, -2503.6831, 34.2377, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[28], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[29] = CreateDynamicObject(18766, -43.2639, -2502.5983, 35.7159, 0.0000, 0.0000, -55.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[29], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[30] = CreateDynamicObject(19173, -28.6079, -2483.9978, 35.7257, -90.0000, 0.0000, 37.2000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[30], 0, "Kamerazone Nicht BETRETEN!!", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[30], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[31] = CreateDynamicObject(19431, -33.5928, -2502.3110, 37.4121, 90.0000, 0.0000, 125.8000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[31], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[32] = CreateDynamicObject(10183, -9.3332, -2527.4733, 35.6506, -0.1999, 0.1999, -107.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_sanaBase[33] = CreateDynamicObject(18762, -31.7364, -2501.0537, 35.7204, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[33], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[34] = CreateDynamicObject(19431, -38.3455, -2505.7414, 37.4121, 90.0000, 0.0000, 125.8000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[34], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[35] = CreateDynamicObject(18762, -40.1309, -2507.1108, 35.7204, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[35], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[36] = CreateDynamicObject(18762, -35.4197, -2503.7106, 36.7032, 0.0000, 37.5998, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[36], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[37] = CreateDynamicObject(18762, -36.4085, -2504.4240, 36.7587, 0.0000, 37.5998, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[37], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[38] = CreateDynamicObject(18762, -37.5461, -2505.2424, 36.5764, 0.0000, 37.5998, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[38], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[39] = CreateDynamicObject(18762, -34.4533, -2503.0144, 38.7103, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[39], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[40] = CreateDynamicObject(18762, -30.3980, -2500.0910, 38.7103, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[40], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[41] = CreateDynamicObject(18762, -38.5087, -2505.9365, 38.7103, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[41], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[42] = CreateDynamicObject(18762, -26.8941, -2497.5622, 38.7103, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[42], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[43] = CreateDynamicObject(19431, -33.5984, -2502.3029, 37.4121, -90.0000, 0.0000, 125.8000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[43], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[44] = CreateDynamicObject(19175, -26.7583, -2498.0874, 36.4424, 0.0000, 0.0000, -144.1996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterial(object_sanaBase[44], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_sanaBase[44], 1, "Agency", 90, "Calibri", 32, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[44], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[45] = CreateDynamicObject(19431, -38.3512, -2505.7326, 37.4121, -90.0000, 0.0000, 125.8000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[45], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[46] = CreateDynamicObject(18762, -41.8386, -2504.6557, 38.7103, 0.0000, 90.0000, -55.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[46], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[47] = CreateDynamicObject(18762, -44.6780, -2500.5390, 38.7103, 0.0000, 90.0000, -55.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[47], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[48] = CreateDynamicObject(18762, -47.5172, -2496.4230, 38.7103, 0.0000, 90.0000, -55.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[48], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[49] = CreateDynamicObject(18762, -50.3563, -2492.3081, 38.7103, 0.0000, 90.0000, -55.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[49], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[50] = CreateDynamicObject(18762, -50.1389, -2489.6789, 37.0362, 0.0000, 45.0000, 215.8000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[50], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[51] = CreateDynamicObject(19173, -47.7116, -2487.3234, 38.1035, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[51], 0, "San", 90, "Arial", 110, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[51], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[52] = CreateDynamicObject(19173, -48.0116, -2487.5395, 37.5536, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[52], 0, "Agency", 90, "Calibri", 64, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[52], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[53] = CreateDynamicObject(19173, -48.9953, -2488.2609, 38.1035, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[53], 0,"News", 90, "Arial", 110, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[53], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[54] = CreateDynamicObject(2985, -26.1016, -2484.2746, 35.6548, 0.0000, 0.0000, 126.8993, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun_base
    SetDynamicObjectMaterial(object_sanaBase[54], 0, 1560, "7_11_door", "CJ_CHROME2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[54], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[54], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[55] = CreateDynamicObject(18766, -23.7828, -2498.9125, 33.2177, 0.0000, 90.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[55], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[56] = CreateDynamicObject(18762, -21.3414, -2503.2624, 38.7098, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[56], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[57] = CreateDynamicObject(18762, -18.8868, -2507.6166, 38.7098, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[57], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[58] = CreateDynamicObject(19431, -21.1560, -2503.4641, 37.4118, 90.0000, 0.0000, 29.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[58], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[59] = CreateDynamicObject(18762, -17.1403, -2510.7158, 36.8557, 0.0000, 37.5998, 299.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[59], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[60] = CreateDynamicObject(18762, -16.5699, -2511.7338, 38.7098, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[60], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[61] = CreateDynamicObject(18762, -22.9090, -2500.4665, 36.8054, 0.0000, 37.5998, 299.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[61], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[62] = CreateDynamicObject(18762, -23.7812, -2498.9306, 38.7098, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[62], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[63] = CreateDynamicObject(1491, -17.6194, -2478.8166, 35.6850, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_sanaBase[63], 0, 3922, "bistro", "sw_door11", 0xFFFFFFFF);
    object_sanaBase[64] = CreateDynamicObject(18766, -0.3287, -2499.8920, 37.7182, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[64], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[65] = CreateDynamicObject(1703, -34.7308, -2481.6711, 35.7126, 0.0000, 0.0000, 75.3000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
    object_sanaBase[66] = CreateDynamicObject(1703, -32.8311, -2478.9648, 35.7126, 0.0000, 0.0000, -12.9996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
    object_sanaBase[67] = CreateDynamicObject(19143, -26.1021, -2481.9799, 39.1542, 0.0000, 0.0000, 36.6096, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[68] = CreateDynamicObject(18762, -16.0760, -2512.6059, 35.7136, 0.0000, 0.0000, 299.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[68], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[69] = CreateDynamicObject(19431, -17.7196, -2509.5590, 37.4118, 90.0000, 0.0000, 29.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[69], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[70] = CreateDynamicObject(2894, -32.2521, -2480.6948, 36.5676, 0.0000, 0.0000, -12.1997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    object_sanaBase[71] = CreateDynamicObject(19893, -32.9051, -2481.1328, 36.5577, 0.0000, 0.0000, -100.3000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_sanaBase[72] = CreateDynamicObject(18762, -15.5852, -2513.4755, 35.7136, 0.0000, 0.0000, 299.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[72], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[73] = CreateDynamicObject(18762, -16.5669, -2511.7365, 35.7136, 0.0000, 0.0000, 299.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[73], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[74] = CreateDynamicObject(18762, -17.0480, -2510.8803, 34.6938, 0.0000, 0.0000, 299.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[74], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[75] = CreateDynamicObject(2011, -33.6847, -2479.1650, 35.6622, 0.0000, 0.0000, 38.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant2_ofc
    object_sanaBase[76] = CreateDynamicObject(2251, -34.5475, -2482.4501, 36.5600, 0.0000, 0.0000, 36.6999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_20
    object_sanaBase[77] = CreateDynamicObject(19464, -33.3129, -2481.4226, 35.6072, 0.0000, 90.0000, -144.2097, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[77], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_sanaBase[78] = CreateDynamicObject(19143, -31.3519, -2485.8730, 39.1542, 0.0000, 0.0000, 36.6096, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[79] = CreateDynamicObject(19143, -28.6949, -2483.9008, 39.1542, 0.0000, 0.0000, 36.6096, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[80] = CreateDynamicObject(19172, -35.6389, -2489.3110, 37.0329, 0.0000, 0.0000, 36.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[80], 0, "Interviewstudio >", 90, "Arial", 22, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[80], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[81] = CreateDynamicObject(1886, -21.3801, -2480.5832, 36.2607, 180.0000, 0.0000, 37.8003, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_sanaBase[82] = CreateDynamicObject(19431, -21.1473, -2503.4592, 37.4118, 90.0000, 0.0000, 210.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[82], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[83] = CreateDynamicObject(19431, -19.4291, -2506.5073, 37.4121, 90.0000, 0.0000, 210.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[83], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[84] = CreateDynamicObject(19431, -17.7157, -2509.5515, 37.4118, 90.0000, 0.0000, 210.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall071
    SetDynamicObjectMaterial(object_sanaBase[84], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[85] = CreateDynamicObject(19464, -35.1030, -2483.0961, 36.6473, 0.0000, 0.0000, 35.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[85], 0, 10765, "airportgnd_sfse", "white", 0xFF2E5B20);
    object_sanaBase[86] = CreateDynamicObject(19464, -34.3473, -2478.8747, 36.6473, 0.0000, 0.0000, -54.2098, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[86], 0, 10765, "airportgnd_sfse", "white", 0xFF2E5B20);
    object_sanaBase[87] = CreateDynamicObject(19464, -27.3192, -2477.5148, 36.6473, 0.0000, 0.0000, 35.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[87], 0, 10765, "airportgnd_sfse", "white", 0xFF2E5B20);
    object_sanaBase[88] = CreateDynamicObject(19464, -31.3936, -2476.7429, 36.6473, 0.0000, 0.0000, -54.2098, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[88], 0, 10765, "airportgnd_sfse", "white", 0xFF2E5B20);
    object_sanaBase[89] = CreateDynamicObject(3388, -19.0102, -2469.0112, 35.7271, 0.0000, 0.0000, 29.4001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[90] = CreateDynamicObject(18762, -3.3754, -2506.6931, 36.7103, 0.0000, 0.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[90], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[91] = CreateDynamicObject(3388, -18.5093, -2469.8994, 35.7271, 0.0000, 0.0000, 29.4001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[92] = CreateDynamicObject(3388, -23.0617, -2471.6599, 35.7271, 0.0000, 0.0000, 215.1997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[93] = CreateDynamicObject(3388, -22.4678, -2472.5017, 35.7271, 0.0000, 0.0000, 215.1997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[94] = CreateDynamicObject(3388, -21.8798, -2473.3349, 35.7271, 0.0000, 0.0000, 215.1997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[95] = CreateDynamicObject(3388, -21.2863, -2474.1748, 35.7271, 0.0000, 0.0000, 215.1997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[96] = CreateDynamicObject(1840, -50.3427, -2490.8391, 38.6108, 0.0000, -11.6997, 173.2998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speaker_2
    object_sanaBase[97] = CreateDynamicObject(2165, -38.0926, -2500.8334, 35.6607, 0.0000, 0.0000, -54.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    SetDynamicObjectMaterial(object_sanaBase[97], 5, 15040, "cuntcuts", "csnewspaper02", 0xFFFFFFFF);
    object_sanaBase[98] = CreateDynamicObject(2205, -37.7927, -2496.9277, 35.7220, 0.0000, 0.0000, 35.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE8_DESK_1
    object_sanaBase[99] = CreateDynamicObject(2205, -39.6916, -2498.2751, 35.7220, 0.0000, 0.0000, 35.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE8_DESK_1
    object_sanaBase[100] = CreateDynamicObject(2165, -33.8395, -2500.0485, 35.6607, 0.0000, 0.0000, -46.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    SetDynamicObjectMaterial(object_sanaBase[100], 5, 15040, "cuntcuts", "csnewspaper02", 0xFFFFFFFF);
    object_sanaBase[101] = CreateDynamicObject(2165, -36.7052, -2501.0756, 35.6607, 0.0000, 0.0000, 125.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    SetDynamicObjectMaterial(object_sanaBase[101], 5, 15040, "cuntcuts", "csnewspaper02", 0xFFFFFFFF);
    object_sanaBase[102] = CreateDynamicObject(2165, -35.5671, -2502.6599, 35.6607, 0.0000, 0.0000, 125.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    SetDynamicObjectMaterial(object_sanaBase[102], 5, 2577, "cj_sex", "CJ_PAINTING9", 0xFFFFFFFF);
    object_sanaBase[103] = CreateDynamicObject(19395, -41.8222, -2490.5190, 37.4382, 0.0000, 0.0000, 125.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall043
    SetDynamicObjectMaterial(object_sanaBase[103], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[104] = CreateDynamicObject(19359, -44.4499, -2492.3652, 35.0564, 0.0000, 0.0000, -54.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[104], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[105] = CreateDynamicObject(2165, -36.9491, -2502.4138, 35.6607, 0.0000, 0.0000, -54.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    SetDynamicObjectMaterial(object_sanaBase[105], 5, 15040, "cuntcuts", "newspaper1", 0xFFFFFFFF);
    object_sanaBase[106] = CreateDynamicObject(19359, -39.1161, -2491.9008, 37.4463, 0.0000, 0.0000, 32.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[106], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[107] = CreateDynamicObject(19414, -35.3535, -2497.3083, 37.4463, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall062
    SetDynamicObjectMaterial(object_sanaBase[107], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[108] = CreateDynamicObject(19359, -39.4361, -2494.2009, 37.4463, 0.0000, 0.0000, -54.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[108], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[109] = CreateDynamicObject(19359, -42.7759, -2502.5341, 37.4463, 0.0000, 0.0000, -145.2998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[109], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[110] = CreateDynamicObject(14391, -44.6762, -2493.6977, 36.6100, 0.0000, 0.0000, -54.6999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Dr_GsNEW07
    object_sanaBase[111] = CreateDynamicObject(19359, -47.0760, -2494.2114, 35.0564, 0.0000, 0.0000, -54.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[111], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[112] = CreateDynamicObject(2685, -41.3893, -2488.1369, 37.1417, 0.0000, 0.0000, 122.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post1
    object_sanaBase[113] = CreateDynamicObject(2200, -43.9971, -2500.3044, 35.7304, 0.0000, 0.0000, 124.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_UNIT_1
    object_sanaBase[114] = CreateDynamicObject(2637, -42.1873, -2485.9860, 36.0680, 0.0000, 0.0000, -56.1999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE2
    object_sanaBase[115] = CreateDynamicObject(19610, -46.2541, -2490.8889, 37.3502, 0.0000, 0.0000, 36.2000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Microphone1
    object_sanaBase[116] = CreateDynamicObject(19610, -33.0908, -2481.4626, 36.5890, 0.0000, 0.0000, -134.3000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Microphone1
    object_sanaBase[117] = CreateDynamicObject(19359, -42.5698, -2486.4958, 37.4463, 0.0000, 0.0000, 32.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[117], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[118] = CreateDynamicObject(19610, -31.6979, -2480.7390, 36.5890, 0.0000, 0.0000, 127.7994, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Microphone1
    object_sanaBase[119] = CreateDynamicObject(19426, -46.9942, -2495.1418, 35.8623, 0.0000, 0.0000, -29.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_sanaBase[119], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_sanaBase[120] = CreateDynamicObject(19359, -40.8456, -2489.1965, 37.4463, 0.0000, 0.0000, 32.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[120], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[121] = CreateDynamicObject(2653, -33.3250, -2480.7565, 39.8941, 0.0000, 0.0000, -54.2098, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_aircon3
    object_sanaBase[122] = CreateDynamicObject(18762, -10.3676, -2510.5793, 36.7103, 0.0000, 0.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[122], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[123] = CreateDynamicObject(2607, -19.6606, -2476.2609, 36.0867, 0.0000, 0.0000, -55.2000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLCE_DESK2
    object_sanaBase[124] = CreateDynamicObject(18762, -4.2501, -2507.1772, 36.7103, 0.0000, 0.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[124], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[125] = CreateDynamicObject(2653, -39.7172, -2485.3664, 39.8941, 0.0000, 0.0000, -54.2098, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_aircon3
    object_sanaBase[126] = CreateDynamicObject(2309, -32.9271, -2499.8103, 35.7107, 0.0000, 0.0000, -53.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR2
    object_sanaBase[127] = CreateDynamicObject(3470, -16.0799, -2474.3264, 40.2989, -0.2000, 0.0000, -150.7998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasaircon1
    SetDynamicObjectMaterial(object_sanaBase[127], 0, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    object_sanaBase[128] = CreateDynamicObject(3934, -38.5438, -2495.7536, 39.2252, 0.0000, -0.0996, -55.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_sanaBase[129] = CreateDynamicObject(2653, -26.9332, -2476.1481, 39.8941, 0.0000, 0.0000, -54.2098, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_aircon3
    object_sanaBase[130] = CreateDynamicObject(1688, -44.1930, -2488.5922, 40.2084, 0.0000, 0.0000, -144.2097, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit2
    object_sanaBase[131] = CreateDynamicObject(1806, -37.9193, -2503.4370, 35.7145, 0.0000, 0.0000, -64.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[132] = CreateDynamicObject(2653, -16.2089, -2477.8015, 39.8941, 0.0000, 0.0000, -150.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_aircon3
    object_sanaBase[133] = CreateDynamicObject(19464, -29.5979, -2478.7446, 35.6026, 0.0000, 90.0000, -144.2097, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[133], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_sanaBase[134] = CreateDynamicObject(2184, -13.1005, -2484.6557, 35.7751, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_DESK_2
    SetDynamicObjectMaterial(object_sanaBase[134], 0, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    object_sanaBase[135] = CreateDynamicObject(1688, -13.5458, -2482.5532, 40.2084, 0.0000, 0.0000, -60.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit2
    object_sanaBase[136] = CreateDynamicObject(2309, -33.3320, -2499.2897, 35.7107, 0.0000, 0.0000, -53.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR2
    object_sanaBase[137] = CreateDynamicObject(2309, -33.7335, -2498.7900, 35.7107, 0.0000, 0.0000, -53.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR2
    object_sanaBase[138] = CreateDynamicObject(2776, -38.6257, -2482.8715, 36.1954, 0.0000, 0.0000, 36.3997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR2
    object_sanaBase[139] = CreateDynamicObject(19143, -23.3006, -2479.8967, 39.1542, 0.0000, 0.0000, 36.6096, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[140] = CreateDynamicObject(2011, -38.2490, -2493.8884, 35.7178, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant2_ofc
    object_sanaBase[141] = CreateDynamicObject(2686, -41.5638, -2487.8525, 37.1417, 0.0000, 0.0000, 122.8999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post2
    object_sanaBase[142] = CreateDynamicObject(19359, -50.1534, -2491.8330, 37.4463, 0.0000, 0.0000, -145.6999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[142], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[143] = CreateDynamicObject(1806, -34.5648, -2501.1455, 35.7145, 0.0000, 0.0000, -64.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[144] = CreateDynamicObject(1806, -34.6739, -2501.6855, 35.6845, 0.0000, 0.0000, 105.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[145] = CreateDynamicObject(1806, -34.9998, -2499.4541, 35.7145, 0.0000, 0.0000, -64.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[146] = CreateDynamicObject(1806, -35.8358, -2500.0886, 35.7042, 0.0000, 0.0000, 105.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[147] = CreateDynamicObject(2165, -38.6856, -2504.9018, 35.6607, 0.0000, 0.0000, 125.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    SetDynamicObjectMaterial(object_sanaBase[147], 5, 15040, "cuntcuts", "newspaper1", 0xFFFFFFFF);
    object_sanaBase[148] = CreateDynamicObject(2165, -39.8236, -2503.3188, 35.6607, 0.0000, 0.0000, 125.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    SetDynamicObjectMaterial(object_sanaBase[148], 5, 15040, "cuntcuts", "csnewspaper", 0xFFFFFFFF);
    object_sanaBase[149] = CreateDynamicObject(19359, -44.6804, -2497.8879, 37.4463, 0.0000, 0.0000, -54.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[149], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[150] = CreateDynamicObject(19359, -40.9850, -2505.1367, 37.4463, 0.0000, 0.0000, -145.2998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[150], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[151] = CreateDynamicObject(19359, -44.6030, -2499.8959, 37.4463, 0.0000, 0.0000, -145.2998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[151], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[152] = CreateDynamicObject(19395, -42.0554, -2496.0505, 37.4482, 0.0000, 0.0000, 125.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall043
    SetDynamicObjectMaterial(object_sanaBase[152], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[153] = CreateDynamicObject(1491, -41.4575, -2495.6093, 35.6897, 0.0000, 0.0000, -144.7998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_sanaBase[153], 0, 2879, "cj_ds_door", "CJ_DS_DOOR_256_", 0xFFFFFFFF);
    object_sanaBase[154] = CreateDynamicObject(19359, -33.3343, -2499.7810, 37.4463, 0.0000, 0.0000, 42.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[154], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[155] = CreateDynamicObject(1806, -37.8549, -2503.9013, 35.6845, 0.0000, 0.0000, 105.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[156] = CreateDynamicObject(1806, -38.3437, -2501.5400, 35.7042, 0.0000, 0.0000, 62.7000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[157] = CreateDynamicObject(1806, -38.9061, -2502.3671, 35.7042, 0.0000, 0.0000, 105.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[158] = CreateDynamicObject(2165, -35.0577, -2498.5756, 35.6585, 0.0000, 0.0000, -51.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    SetDynamicObjectMaterial(object_sanaBase[158], 5, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_sanaBase[159] = CreateDynamicObject(19786, -42.0102, -2503.6076, 38.0727, 0.0000, 0.0000, 124.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_sanaBase[159], 1, 14802, "lee_bdupsflat", "Bdup_news", 0xFFFFFFFF);
    object_sanaBase[160] = CreateDynamicObject(2010, -39.8530, -2505.9685, 35.7210, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_sanaBase[161] = CreateDynamicObject(2010, -39.2731, -2505.5681, 35.7210, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_sanaBase[162] = CreateDynamicObject(19359, -49.9020, -2490.0520, 37.4463, 0.0000, 0.0000, -54.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[162], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[163] = CreateDynamicObject(1491, -37.6785, -2494.0698, 35.6897, 0.0000, 0.0000, -54.3997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_sanaBase[163], 0, 2879, "cj_ds_door", "CJ_DS_DOOR_256_", 0xFFFFFFFF);
    object_sanaBase[164] = CreateDynamicObject(1234, -26.0552, -2495.5375, 42.8628, 180.0000, 0.0000, 37.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_sanaBase[164], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_sanaBase[165] = CreateDynamicObject(19359, -28.8910, -2496.4077, 37.4463, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[165], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[166] = CreateDynamicObject(19359, -19.8838, -2468.5822, 37.4463, 0.0000, 0.0000, -54.2999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[166], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[167] = CreateDynamicObject(19359, -26.1534, -2494.4353, 40.9463, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[167], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_sanaBase[168] = CreateDynamicObject(19359, -28.4055, -2494.1953, 37.4463, 0.0000, 0.0000, -54.1999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[168], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[169] = CreateDynamicObject(19359, -26.1534, -2494.4353, 37.4463, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[169], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[170] = CreateDynamicObject(2421, -43.0007, -2485.5793, 36.4169, 0.0000, 0.0000, 122.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_MICROW
    object_sanaBase[171] = CreateDynamicObject(2924, -27.9181, -2493.7675, 36.9165, 0.0000, 0.0000, 35.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_crash3door
    SetDynamicObjectMaterial(object_sanaBase[171], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_sanaBase[172] = CreateDynamicObject(1491, -41.2154, -2490.0891, 35.6795, 0.0000, 0.0000, 215.0997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_sanaBase[172], 0, 2879, "cj_ds_door", "CJ_DS_DOOR_256_", 0xFFFFFFFF);
    object_sanaBase[173] = CreateDynamicObject(1582, -42.4664, -2485.4785, 35.7243, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pizzabox
    object_sanaBase[174] = CreateDynamicObject(3069, -0.9569, -2519.4575, 34.4458, 0.0000, 0.0000, 29.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d9_ramp
    SetDynamicObjectMaterial(object_sanaBase[174], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[175] = CreateDynamicObject(2924, -27.9297, -2493.7514, 40.3865, 0.0000, 0.0000, 35.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_crash3door
    SetDynamicObjectMaterial(object_sanaBase[175], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_sanaBase[176] = CreateDynamicObject(19359, -22.9715, -2472.6489, 37.4463, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[176], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[177] = CreateDynamicObject(19395, -37.2206, -2494.7001, 37.4482, 0.0000, 0.0000, 35.7000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall043
    SetDynamicObjectMaterial(object_sanaBase[177], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[178] = CreateDynamicObject(18762, -9.4930, -2510.0971, 36.7103, 0.0000, 0.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[178], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[179] = CreateDynamicObject(3388, -20.6923, -2475.0161, 35.7271, 0.0000, 0.0000, 215.1997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[180] = CreateDynamicObject(19786, -29.3498, -2477.7082, 37.0564, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_sanaBase[180], 1, 14803, "bdupsnew", "Bdup2_poster", 0xFFFFFFFF);
    object_sanaBase[181] = CreateDynamicObject(19957, -28.9053, -2477.7421, 37.0629, 180.0000, 0.0000, 42.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    SetDynamicObjectMaterial(object_sanaBase[181], 1, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_sanaBase[182] = CreateDynamicObject(19359, -14.9511, -2474.9853, 37.4463, 0.0000, 0.0000, -150.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[182], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[183] = CreateDynamicObject(19359, -19.2436, -2477.8776, 37.4463, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[183], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[184] = CreateDynamicObject(19359, -14.6934, -2476.6982, 37.4364, 0.0000, 0.0000, 125.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[184], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[185] = CreateDynamicObject(19359, -22.4906, -2470.4558, 37.4463, 0.0000, 0.0000, -54.2999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[185], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[186] = CreateDynamicObject(1582, -42.4664, -2485.4785, 35.7938, 0.0000, 0.0000, 36.6999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pizzabox
    object_sanaBase[187] = CreateDynamicObject(3388, -18.0086, -2470.7885, 35.7271, 0.0000, 0.0000, 29.4001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[188] = CreateDynamicObject(3388, -17.5079, -2471.6772, 35.7271, 0.0000, 0.0000, 29.4001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[189] = CreateDynamicObject(3388, -17.0072, -2472.5668, 35.7271, 0.0000, 0.0000, 29.4001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack4_
    object_sanaBase[190] = CreateDynamicObject(18762, -5.1199, -2507.6660, 39.7103, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[190], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[191] = CreateDynamicObject(19175, -6.6430, -2509.0715, 39.2821, 0.0000, 0.0000, -151.0001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterial(object_sanaBase[191], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_sanaBase[191], 1, "San News", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[191], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[192] = CreateDynamicObject(2453, -42.4388, -2486.0961, 36.8684, 0.0000, 0.0000, 32.3997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_DISPf
    object_sanaBase[193] = CreateDynamicObject(2190, -19.8302, -2476.3928, 36.4897, 0.0000, 0.0000, 125.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PC_1
    object_sanaBase[194] = CreateDynamicObject(2985, -17.8199, -2485.5312, 35.6548, 0.0000, 0.0000, 29.1998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun_base
    SetDynamicObjectMaterial(object_sanaBase[194], 0, 1560, "7_11_door", "CJ_CHROME2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[194], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[194], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[195] = CreateDynamicObject(19359, -21.1075, -2475.2624, 37.4463, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[195], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[196] = CreateDynamicObject(19143, -21.1333, -2478.2871, 39.1542, 0.0000, 0.0000, 36.6096, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[197] = CreateDynamicObject(1806, -36.3353, -2497.6345, 35.7042, 0.0000, 0.0000, 49.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[198] = CreateDynamicObject(19359, -48.3445, -2494.4846, 37.4463, 0.0000, 0.0000, -145.6999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[198], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[199] = CreateDynamicObject(19359, -46.5218, -2497.1259, 37.4463, 0.0000, 0.0000, -145.2998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[199], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[200] = CreateDynamicObject(1806, -38.6291, -2499.1894, 35.7042, 0.0000, 0.0000, 20.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
    object_sanaBase[201] = CreateDynamicObject(19893, -39.1632, -2498.0539, 36.6510, 0.0000, 0.0000, 20.8999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_sanaBase[202] = CreateDynamicObject(19893, -37.4463, -2496.7695, 36.6510, 0.0000, 0.0000, 47.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_sanaBase[203] = CreateDynamicObject(1541, -42.2299, -2486.7561, 37.0287, 0.0000, 0.0000, -57.1996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_sanaBase[204] = CreateDynamicObject(19143, -16.9416, -2484.1870, 39.1542, 0.0000, 0.0000, -60.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[205] = CreateDynamicObject(1666, -42.0680, -2486.7580, 36.5764, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propbeerglass1
    object_sanaBase[206] = CreateDynamicObject(1666, -42.0680, -2486.5778, 36.5764, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propbeerglass1
    object_sanaBase[207] = CreateDynamicObject(1666, -42.2583, -2486.5178, 36.5764, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propbeerglass1
    object_sanaBase[208] = CreateDynamicObject(19143, -16.0139, -2485.8334, 39.1542, 0.0000, 0.0000, -60.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[209] = CreateDynamicObject(18762, -36.6369, -2488.1940, 36.6500, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[209], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[210] = CreateDynamicObject(18762, -38.0270, -2487.9741, 36.6500, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[210], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[211] = CreateDynamicObject(18762, -37.4477, -2488.7800, 36.6500, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[211], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[212] = CreateDynamicObject(18762, -37.2159, -2487.3881, 36.6500, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[212], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[213] = CreateDynamicObject(18762, -36.8628, -2489.5917, 36.6500, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[213], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[214] = CreateDynamicObject(18762, -36.0517, -2489.0036, 36.6500, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[214], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[215] = CreateDynamicObject(2862, -41.6315, -2486.3151, 36.4714, 0.0000, 0.0000, 110.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GB_kitchplatecln02
    object_sanaBase[216] = CreateDynamicObject(2132, -40.8945, -2488.1811, 35.5816, 0.0000, 0.0000, 122.4999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_KITCH2_SINK
    object_sanaBase[217] = CreateDynamicObject(19464, -26.5750, -2473.2683, 36.6473, 0.0000, 0.0000, -54.2098, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[217], 0, 10765, "airportgnd_sfse", "white", 0xFF2E5B20);
    object_sanaBase[218] = CreateDynamicObject(19464, -22.3213, -2473.8979, 36.6473, 0.0000, 0.0000, 35.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[218], 0, 10765, "airportgnd_sfse", "white", 0xFF2E5B20);
    object_sanaBase[219] = CreateDynamicObject(19168, -27.0270, -2473.7497, 38.2596, 90.0000, 0.5999, 35.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap5
    object_sanaBase[220] = CreateDynamicObject(19169, -25.8152, -2472.8698, 38.2630, 90.0000, 35.7999, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap6
    object_sanaBase[221] = CreateDynamicObject(19170, -27.0270, -2473.7490, 36.7616, 90.0000, 36.0998, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap7
    object_sanaBase[222] = CreateDynamicObject(19171, -25.8183, -2472.8691, 36.7620, 90.0000, 3.2999, 32.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap8
    object_sanaBase[223] = CreateDynamicObject(2184, -26.3915, -2477.0725, 35.6952, 0.0000, 0.0000, 19.1000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_DESK_2
    SetDynamicObjectMaterial(object_sanaBase[223], 0, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    object_sanaBase[224] = CreateDynamicObject(2894, -25.4330, -2476.1181, 36.4542, 0.0000, 0.0000, -150.8999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    object_sanaBase[225] = CreateDynamicObject(19893, -26.2537, -2476.2170, 36.4542, 0.0000, 0.0000, 159.6000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_sanaBase[226] = CreateDynamicObject(19611, -46.2559, -2490.8842, 35.7154, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MicrophoneStand1
    object_sanaBase[227] = CreateDynamicObject(19172, -24.6088, -2476.6320, 36.1324, 0.0000, 0.0000, 39.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[227], 0, "Wetter", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_sanaBase[227], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[228] = CreateDynamicObject(19172, -35.4286, -2489.1579, 36.7929, 0.0000, 0.0000, 36.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[228], 0, "Wetterstudio >", 90, "Arial", 22, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[228], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[229] = CreateDynamicObject(1234, -46.2495, -2490.8774, 35.7947, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_sanaBase[229], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[230] = CreateDynamicObject(19172, -35.8818, -2489.4868, 36.5527, 0.0000, 0.0000, 36.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[230], 0, "Nachrichtenstudio >", 90, "Arial", 22, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[230], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[231] = CreateDynamicObject(19395, -17.0268, -2478.3652, 37.4379, 0.0000, 0.0000, -54.2999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall043
    SetDynamicObjectMaterial(object_sanaBase[231], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[232] = CreateDynamicObject(19172, -35.8572, -2489.4692, 37.5527, 0.0000, 0.0000, 36.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[232], 0, "< Aufnahmestudio", 90, "Arial", 22, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[232], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[233] = CreateDynamicObject(19172, -35.8572, -2489.4692, 37.2829, 0.0000, 0.0000, 36.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[233], 0, "< Redaktion", 90, "Arial", 22, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[233], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[234] = CreateDynamicObject(2985, -16.5711, -2487.7705, 35.6548, 0.0000, 0.0000, 29.1998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun_base
    SetDynamicObjectMaterial(object_sanaBase[234], 0, 1560, "7_11_door", "CJ_CHROME2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[234], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[234], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[235] = CreateDynamicObject(19617, -39.2597, -2494.0063, 37.7476, 0.0000, 0.0000, -144.7998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldRecord1
    object_sanaBase[236] = CreateDynamicObject(19617, -40.6514, -2495.0000, 37.7476, 0.0000, 0.0000, -144.7998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldRecord1
    object_sanaBase[237] = CreateDynamicObject(19617, -43.4355, -2496.9526, 37.7476, 0.0000, 0.0000, -144.7998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldRecord1
    object_sanaBase[238] = CreateDynamicObject(19617, -45.0918, -2498.1083, 37.7476, 0.0000, 0.0000, -144.9998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldRecord1
    object_sanaBase[239] = CreateDynamicObject(1962, -42.7224, -2492.2402, 36.8171, -89.5998, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //record1
    object_sanaBase[240] = CreateDynamicObject(1961, -42.9126, -2492.1335, 36.8264, -89.5998, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //record3
    object_sanaBase[241] = CreateDynamicObject(19174, -14.9593, -2476.9807, 36.8801, 0.0000, 0.0000, 35.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_sanaBase[241], 0, "Serverraum", 90, "Calibri", 17, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[241], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[242] = CreateDynamicObject(19174, -15.1138, -2477.0917, 36.6901, 0.0000, 0.0000, 35.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_sanaBase[242], 0, "Zutritt nur Befugten", 90, "Calibri", 17, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[242], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[243] = CreateDynamicObject(19174, -14.8858, -2476.9277, 36.5000, 0.0000, 0.0000, 35.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_sanaBase[243], 0, "gestattet", 90, "Calibri", 17, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[243], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[244] = CreateDynamicObject(19953, -15.7454, -2477.5292, 35.4006, 0.0000, 0.0000, 35.7000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign6
    SetDynamicObjectMaterial(object_sanaBase[244], 2, 14593, "papaerchaseoffice", "sign_noCamera", 0xFFFFFFFF);
    object_sanaBase[245] = CreateDynamicObject(11737, -36.7868, -2494.3947, 35.7192, 0.0000, 0.0000, 123.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RockstarMat1
    SetDynamicObjectMaterial(object_sanaBase[245], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFF2E2D33);
    object_sanaBase[246] = CreateDynamicObject(19173, -24.4036, -2480.0751, 35.7210, -89.3999, 0.0000, -9.8999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[246], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[246], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[247] = CreateDynamicObject(1234, -27.7984, -2496.7814, 42.8628, 180.0000, 0.0000, 37.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_sanaBase[247], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_sanaBase[248] = CreateDynamicObject(19359, -27.5226, -2495.4111, 42.0898, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[248], 0, 2669, "cj_chris", "cj_metalplate2", 0xFF656A79);
    object_sanaBase[249] = CreateDynamicObject(16332, -28.9860, -2495.5708, 45.3967, 0.0000, 0.0000, -53.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //quarry_cranhook
    object_sanaBase[250] = CreateDynamicObject(16332, -26.9169, -2494.1318, 45.3967, 0.0000, 0.0000, -53.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //quarry_cranhook
    object_sanaBase[251] = CreateDynamicObject(16332, -25.9603, -2495.4387, 45.3967, 0.0000, 0.0000, -53.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //quarry_cranhook
    object_sanaBase[252] = CreateDynamicObject(16332, -28.0615, -2496.9023, 45.3967, 0.0000, 0.0000, -53.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //quarry_cranhook
    object_sanaBase[253] = CreateDynamicObject(1389, -27.4127, -2495.4980, 44.5862, 0.0000, 0.0000, 35.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TwrCrane_S_01
    object_sanaBase[254] = CreateDynamicObject(921, -28.5223, -2494.0397, 38.2607, 0.0000, 0.0000, -142.8999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_IND_LIGHT
    object_sanaBase[255] = CreateDynamicObject(19359, -26.6389, -2496.6452, 40.7663, 0.0000, 0.0000, -54.1999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[255], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[256] = CreateDynamicObject(1234, -26.9843, -2494.3093, 42.8628, 180.0000, 0.0000, 37.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_sanaBase[256], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_sanaBase[257] = CreateDynamicObject(1234, -28.7215, -2495.5107, 42.8628, 180.0000, 0.0000, 37.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_sanaBase[257], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_sanaBase[258] = CreateDynamicObject(19359, -26.1534, -2494.4353, 44.4462, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[258], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_sanaBase[259] = CreateDynamicObject(2924, -27.8365, -2493.8803, 40.3865, 0.0000, 0.0000, 35.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_crash3door
    SetDynamicObjectMaterial(object_sanaBase[259], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_sanaBase[260] = CreateDynamicObject(19359, -28.8910, -2496.4077, 44.4462, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[260], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_sanaBase[261] = CreateDynamicObject(19359, -26.6389, -2496.6452, 44.2662, 0.0000, 0.0000, -54.1999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[261], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[262] = CreateDynamicObject(19359, -27.5226, -2495.4111, 41.9098, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[262], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[263] = CreateDynamicObject(19173, -32.2374, -2485.6396, 35.7196, -89.3999, 0.0000, -9.8999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[263], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[263], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[264] = CreateDynamicObject(19173, -30.2817, -2485.1628, 35.7205, -89.3999, 0.0000, 37.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[264], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[264], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[265] = CreateDynamicObject(19173, -28.5662, -2483.8666, 35.7201, -90.0000, 0.0000, 37.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[265], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[265], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[266] = CreateDynamicObject(19173, -26.8411, -2482.5678, 35.7201, -89.3999, 0.0000, 37.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[266], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[266], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[267] = CreateDynamicObject(19359, -27.5226, -2495.4111, 41.7397, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[267], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[268] = CreateDynamicObject(19173, -25.7910, -2480.8337, 35.7190, -89.3999, 0.0000, 80.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[268], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[268], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[269] = CreateDynamicObject(2985, -15.2489, -2490.1389, 35.6049, 0.0000, 0.0000, 29.1998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun_base
    SetDynamicObjectMaterial(object_sanaBase[269], 0, 1560, "7_11_door", "CJ_CHROME2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[269], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[269], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[270] = CreateDynamicObject(1886, -17.7383, -2485.4587, 36.2607, 180.0000, 0.0000, -79.9991, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_sanaBase[271] = CreateDynamicObject(1886, -16.4934, -2487.6855, 36.2607, 180.0000, 0.0000, -61.5996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_sanaBase[272] = CreateDynamicObject(8661, -29.4242, -2487.5527, 35.7248, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_sanaBase[272], 0, 14714, "vghss1int2", "HS1_2Floor1", 0xFFFFFFFF);
    object_sanaBase[273] = CreateDynamicObject(19359, -27.4818, -2495.4675, 39.1197, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[273], 0, 14714, "vghss1int2", "HS1_2Floor1", 0xFFFFFFFF);
    object_sanaBase[274] = CreateDynamicObject(19359, -16.5317, -2472.1914, 37.4463, 0.0000, 0.0000, -150.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[274], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[275] = CreateDynamicObject(19957, -29.8108, -2477.7380, 37.0545, 180.0000, 0.0000, 42.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    SetDynamicObjectMaterial(object_sanaBase[275], 1, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_sanaBase[276] = CreateDynamicObject(19359, -18.1075, -2469.4064, 37.4463, 0.0000, 0.0000, -150.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[276], 0, 3820, "boxhses_sfsx", "stonewall_la", 0xFFFFFFFF);
    object_sanaBase[277] = CreateDynamicObject(8661, -29.4078, -2487.5410, 39.1347, 180.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_sanaBase[277], 0, 11301, "carshow_sfse", "ws_officy_ceiling", 0xFF9CA1A3);
    object_sanaBase[278] = CreateDynamicObject(19173, -22.4538, -2479.5993, 35.7201, -90.0000, 0.0000, 37.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[278], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[278], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[279] = CreateDynamicObject(19173, -21.8628, -2479.1569, 35.7201, -90.0000, 0.0000, 37.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[279], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[279], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[280] = CreateDynamicObject(19173, -20.8083, -2477.4262, 35.7233, -89.3999, 0.0000, 80.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[280], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[280], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[281] = CreateDynamicObject(19464, -13.1826, -2494.2209, 37.4416, 0.0000, 0.0000, -60.2999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[281], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[282] = CreateDynamicObject(19173, -22.0941, -2479.4309, 35.7257, -90.0000, 0.0000, 37.2000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[282], 0, "Kamerazone Nicht BETRETEN!!", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[282], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[283] = CreateDynamicObject(19464, -8.2789, -2486.5959, 36.6118, 180.0000, 0.0000, -150.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[283], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[284] = CreateDynamicObject(19464, -11.1899, -2481.4296, 36.6118, 0.0000, 0.0000, -150.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[284], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[285] = CreateDynamicObject(19611, -12.0642, -2485.2766, 35.1277, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MicrophoneStand1
    object_sanaBase[286] = CreateDynamicObject(19610, -12.0790, -2485.2817, 36.7681, 11.8000, 0.0000, -60.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Microphone1
    object_sanaBase[287] = CreateDynamicObject(19175, -11.5038, -2482.3789, 35.8115, -90.0000, 90.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[287], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[287], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[288] = CreateDynamicObject(19175, -10.4974, -2482.9006, 38.6818, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[288], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[288], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[289] = CreateDynamicObject(19175, -10.9637, -2482.0739, 36.9416, 0.0000, 90.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[289], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[289], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[290] = CreateDynamicObject(19175, -9.1716, -2485.2514, 38.6818, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[290], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[290], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[291] = CreateDynamicObject(19175, -8.3619, -2486.6923, 36.9416, 0.0000, 90.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[291], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[291], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[292] = CreateDynamicObject(19950, -18.1044, -2544.5048, 36.7406, 0.0000, 0.0000, -144.7998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_sanaBase[293] = CreateDynamicObject(19950, -28.8747, -2551.3583, 36.7406, 0.0000, 0.0000, -158.4998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_sanaBase[294] = CreateDynamicObject(19464, -11.9224, -2485.2656, 35.6916, 0.0000, 90.0000, -150.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[294], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFF58595A);
    object_sanaBase[295] = CreateDynamicObject(19175, -9.5304, -2484.6171, 37.3516, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[295], 0, "ß", 90, "Webdings", 130, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[295], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[296] = CreateDynamicObject(19175, -13.8472, -2483.7009, 35.8115, -90.0000, 90.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[296], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[296], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[297] = CreateDynamicObject(19957, -57.9566, -2483.7192, 33.8432, 0.0000, 0.0000, 41.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_sanaBase[298] = CreateDynamicObject(19957, -67.2406, -2491.8164, 33.8432, 0.0000, 0.0000, 41.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_sanaBase[299] = CreateDynamicObject(19175, -8.8823, -2485.7631, 36.2416, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[299], 0, "San Andreas", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[299], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[300] = CreateDynamicObject(19175, -9.8444, -2484.0583, 37.3619, 0.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[300], 0, "News", 90, "Arial", 32, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[300], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[301] = CreateDynamicObject(19949, -30.8159, -2521.4008, 35.0760, 0.0000, 0.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign2
    object_sanaBase[302] = CreateDynamicObject(19175, -14.1646, -2485.0715, 35.8128, -90.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[302], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[302], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[303] = CreateDynamicObject(19175, -8.9020, -2486.9975, 35.8115, -90.0000, 90.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[303], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[303], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[304] = CreateDynamicObject(19175, -11.2454, -2488.3183, 35.8115, -90.0000, 90.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[304], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[304], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[305] = CreateDynamicObject(19175, -12.9273, -2487.2678, 35.8128, -90.0000, 0.0000, -60.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_sanaBase[305], 0, "________________", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[305], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[306] = CreateDynamicObject(1671, -11.0017, -2484.4406, 36.2535, 0.0000, 0.0000, -49.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_sanaBase[307] = CreateDynamicObject(19893, -12.3802, -2484.7814, 36.5441, 0.0000, 0.0000, 99.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_sanaBase[308] = CreateDynamicObject(18762, -11.9277, -2493.5703, 39.7000, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[308], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[309] = CreateDynamicObject(18762, -7.5545, -2491.1477, 39.7000, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[309], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[310] = CreateDynamicObject(18762, -16.3008, -2495.9931, 39.7000, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[310], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[311] = CreateDynamicObject(18762, -20.6739, -2498.4165, 39.7000, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[311], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[312] = CreateDynamicObject(19359, -28.5587, -2494.2707, 40.9463, 0.0000, 0.0000, -54.1999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[312], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_sanaBase[313] = CreateDynamicObject(18762, -18.8868, -2507.6166, 39.7097, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[313], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[314] = CreateDynamicObject(18762, -16.5699, -2511.7338, 39.7097, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[314], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[315] = CreateDynamicObject(18762, -21.3414, -2503.2624, 39.7097, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[315], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[316] = CreateDynamicObject(18762, -18.6828, -2497.3239, 37.4486, 0.0000, -33.5000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[316], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[317] = CreateDynamicObject(18762, -20.6187, -2498.4035, 37.4225, 0.0000, -33.5000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[317], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[318] = CreateDynamicObject(8661, -29.4078, -2487.5410, 39.2047, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_sanaBase[318], 0, 8420, "carpark3_lvs", "greystones01_128", 0xFFD6DAD6);
    object_sanaBase[319] = CreateDynamicObject(18762, -8.8624, -2482.1088, 39.6301, 0.0000, 90.0000, -60.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[319], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[320] = CreateDynamicObject(18762, -9.7334, -2482.5971, 39.6301, 0.0000, 90.0000, -60.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[320], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[321] = CreateDynamicObject(18762, -11.6934, -2478.1672, 39.6301, 0.0000, 90.0000, -47.9995, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[321], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[322] = CreateDynamicObject(18762, -13.3908, -2476.0019, 39.6301, 0.0000, 90.0000, -54.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[322], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[323] = CreateDynamicObject(18762, -10.9413, -2479.4887, 39.6301, 0.0000, 90.0000, -54.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[323], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[324] = CreateDynamicObject(18762, -22.2791, -2501.5976, 39.7097, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[324], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_sanaBase[325] = CreateDynamicObject(367, -44.1940, -2500.0871, 37.6483, 0.0000, 2.0999, -2.3998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //camera
    object_sanaBase[326] = CreateDynamicObject(18766, -16.1961, -2496.1147, 40.5273, 90.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[326], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[327] = CreateDynamicObject(19464, -35.0932, -2483.1262, 36.6473, 0.0000, 0.0000, 35.8997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_sanaBase[327], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[328] = CreateDynamicObject(367, -44.4500, -2499.1726, 37.6581, 0.0000, 4.4998, 152.5001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //camera
    object_sanaBase[329] = CreateDynamicObject(19359, -44.6994, -2486.3098, 37.4463, 0.0000, 0.0000, -54.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[329], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[330] = CreateDynamicObject(19359, -47.3101, -2488.1765, 37.4463, 0.0000, 0.0000, -54.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[330], 0, 9583, "bigshap_sfw", "bridge_walls2_sfw", 0xFFFFFFFF);
    object_sanaBase[331] = CreateDynamicObject(19359, -28.8910, -2496.4077, 40.9463, 0.0000, 0.0000, 35.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[331], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_sanaBase[332] = CreateDynamicObject(1841, -43.3684, -2485.7668, 38.6058, 0.0000, -11.8999, 73.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speaker_1
    object_sanaBase[333] = CreateDynamicObject(19359, -28.3013, -2494.0832, 40.9463, 0.0000, 0.0000, -54.1999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[333], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_sanaBase[334] = CreateDynamicObject(19359, -28.4055, -2494.1953, 44.4462, 0.0000, 0.0000, -54.1999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[334], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_sanaBase[335] = CreateDynamicObject(19173, -16.1166, -2482.7651, 35.7210, -89.3999, 0.0000, 29.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[335], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[335], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[336] = CreateDynamicObject(19173, -13.3226, -2489.7971, 35.7220, -89.3999, 0.0000, 119.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[336], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[336], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[337] = CreateDynamicObject(19173, -11.8668, -2490.2778, 35.7206, -89.3999, 0.0000, 29.5000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[337], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[337], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[338] = CreateDynamicObject(19173, -14.3830, -2487.9152, 35.7220, -89.3999, 0.0000, 119.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[338], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[338], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[339] = CreateDynamicObject(19173, -15.4385, -2486.0429, 35.7220, -89.3999, 0.0000, 119.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[339], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[339], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[340] = CreateDynamicObject(18766, -15.7257, -2507.2727, 40.5273, 90.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[340], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[341] = CreateDynamicObject(19173, -16.4992, -2484.1623, 35.7220, -89.3999, 0.0000, 119.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[341], 0, "_____________________", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[341], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[342] = CreateDynamicObject(18766, -11.8232, -2493.6872, 40.5273, 90.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[342], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[343] = CreateDynamicObject(19173, -15.1934, -2486.9252, 35.7262, -90.0000, 0.0000, -60.3997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_sanaBase[343], 0, "Kamerazone Nicht BETRETEN!!", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[343], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[344] = CreateDynamicObject(18766, -3.4065, -2500.4604, 40.5273, 90.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[344], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[345] = CreateDynamicObject(18766, -6.9751, -2502.4348, 40.5273, 90.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[345], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[346] = CreateDynamicObject(18766, -8.2594, -2491.7087, 40.5273, 90.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[346], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[347] = CreateDynamicObject(2985, -29.1086, -2486.5349, 35.6548, 0.0000, 0.0000, 126.8993, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun_base
    SetDynamicObjectMaterial(object_sanaBase[347], 0, 1560, "7_11_door", "CJ_CHROME2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[347], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[347], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[348] = CreateDynamicObject(18766, -11.3577, -2504.8415, 40.5273, 90.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[348], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[349] = CreateDynamicObject(18766, -20.5694, -2498.5339, 40.5273, 90.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[349], 0, 10765, "airportgnd_sfse", "white", 0xFF656A79);
    object_sanaBase[350] = CreateDynamicObject(18762, -16.5699, -2511.7338, 40.7097, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[350], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[351] = CreateDynamicObject(18762, -19.0242, -2507.3798, 40.7097, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[351], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[352] = CreateDynamicObject(18762, -21.4789, -2503.0227, 40.7097, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[352], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[353] = CreateDynamicObject(18762, -23.7278, -2499.0373, 39.7518, 0.0000, 66.4001, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[353], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[354] = CreateDynamicObject(18762, -22.5415, -2501.1440, 39.7164, 0.0000, 66.4001, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[354], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[355] = CreateDynamicObject(1886, -15.1885, -2490.0478, 36.2607, 180.0000, 0.0000, -37.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_sanaBase[356] = CreateDynamicObject(19172, -29.1280, -2486.5468, 36.7961, 0.0000, 0.0000, 32.2999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[356], 0, "<", 90, "Webdings", 40, 0, 0xFF515459, 0x0, 1);
    SetDynamicObjectMaterial(object_sanaBase[356], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[357] = CreateDynamicObject(19172, -26.1345, -2484.2590, 36.7961, 0.0000, 0.0000, 51.5998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[357], 0, "<", 90, "Webdings", 40, 0, 0xFF515459, 0x0, 1);
    SetDynamicObjectMaterial(object_sanaBase[357], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[358] = CreateDynamicObject(18762, -8.6183, -2509.6098, 39.7103, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[358], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[359] = CreateDynamicObject(18762, -0.7652, -2505.2265, 39.5203, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[359], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[360] = CreateDynamicObject(18762, -12.9924, -2512.0061, 39.5203, 0.0000, 90.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[360], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[361] = CreateDynamicObject(18762, -16.9291, -2510.9489, 39.1240, 80.5000, 0.0000, 28.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[361], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[362] = CreateDynamicObject(19359, -44.4359, -2492.3674, 37.3861, 0.0000, 0.0000, -54.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[362], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[363] = CreateDynamicObject(19359, -47.0620, -2494.2143, 37.3861, 0.0000, 0.0000, -54.9000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[363], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_sanaBase[364] = CreateDynamicObject(18762, -12.9645, -2512.0209, 40.7097, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[364], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[365] = CreateDynamicObject(18762, -8.5916, -2509.5971, 40.7097, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[365], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[366] = CreateDynamicObject(18762, -4.2185, -2507.1708, 40.7097, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[366], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[367] = CreateDynamicObject(18762, 0.1280, -2504.7619, 40.7097, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[367], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[368] = CreateDynamicObject(18762, 0.4059, -2501.1833, 40.7097, 0.0000, 90.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[368], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[369] = CreateDynamicObject(18762, -2.0483, -2496.8300, 40.7097, 0.0000, 90.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[369], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[370] = CreateDynamicObject(18762, -4.4980, -2492.4792, 40.7097, 0.0000, 90.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[370], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[371] = CreateDynamicObject(18762, -6.9524, -2488.1235, 40.7097, 0.0000, 90.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[371], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[372] = CreateDynamicObject(18762, -9.3149, -2483.9282, 40.1413, 0.0000, 103.5998, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[372], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[373] = CreateDynamicObject(18762, -22.8777, -2495.0153, 39.6197, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[373], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[374] = CreateDynamicObject(18762, -18.5048, -2492.5922, 39.6197, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[374], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[375] = CreateDynamicObject(18762, -14.1316, -2490.1684, 39.6197, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[375], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[376] = CreateDynamicObject(18762, -9.7585, -2487.7453, 39.6197, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[376], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[377] = CreateDynamicObject(18762, -23.3052, -2494.1203, 39.6197, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[377], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[378] = CreateDynamicObject(18762, -18.9321, -2491.6953, 39.6197, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[378], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[379] = CreateDynamicObject(18762, -14.5591, -2489.2705, 39.6197, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[379], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[380] = CreateDynamicObject(18762, -10.1906, -2486.8403, 39.6197, 90.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[380], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[381] = CreateDynamicObject(18762, -10.9032, -2487.0236, 39.6197, 90.0000, 0.0000, 123.4998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[381], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[382] = CreateDynamicObject(18762, -23.3992, -2497.6223, 39.5820, 0.0000, 90.0000, -60.6001, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_sanaBase[382], 0, 10765, "airportgnd_sfse", "white", 0xFF2E2D33);
    object_sanaBase[383] = CreateDynamicObject(19359, -27.5279, -2495.4379, 46.0998, 0.0000, 90.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall007
    SetDynamicObjectMaterial(object_sanaBase[383], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_sanaBase[384] = CreateDynamicObject(638, -17.6877, -2482.7004, 39.8554, 0.0000, 0.0000, 28.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[385] = CreateDynamicObject(19175, -26.9776, -2498.2456, 37.0223, 0.0000, 0.0000, -144.1996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterial(object_sanaBase[385], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_sanaBase[385], 1, "San News", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_sanaBase[385], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[386] = CreateDynamicObject(19121, -50.1380, -2490.9541, 39.7061, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_sanaBase[387] = CreateDynamicObject(19121, -19.1958, -2468.6362, 39.7061, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_sanaBase[388] = CreateDynamicObject(19121, -9.9811, -2485.0710, 39.7061, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_sanaBase[389] = CreateDynamicObject(2653, -19.9895, -2474.1679, 39.9042, 0.0000, 0.0000, -93.3998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_aircon3
    object_sanaBase[390] = CreateDynamicObject(19121, -39.9294, -2505.8068, 39.7061, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_sanaBase[391] = CreateDynamicObject(2985, -21.2796, -2480.6518, 35.6548, 0.0000, 0.0000, 126.8993, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun_base
    SetDynamicObjectMaterial(object_sanaBase[391], 0, 1560, "7_11_door", "CJ_CHROME2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[391], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_sanaBase[391], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[392] = CreateDynamicObject(1886, -26.2087, -2484.2255, 36.2607, 180.0000, 0.0000, 51.5003, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_sanaBase[393] = CreateDynamicObject(19172, -21.2912, -2480.6486, 36.7862, 0.0000, 0.0000, 37.4000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[393], 0, "<", 90, "Webdings", 40, 0, 0xFF515459, 0x0, 1);
    SetDynamicObjectMaterial(object_sanaBase[393], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[394] = CreateDynamicObject(19172, -17.8145, -2485.4985, 36.7961, 0.0000, 0.0000, -80.2995, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[394], 0, "<", 90, "Webdings", 40, 0, 0xFF515459, 0x0, 1);
    SetDynamicObjectMaterial(object_sanaBase[394], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[395] = CreateDynamicObject(19172, -16.5634, -2487.7558, 36.7961, 0.0000, 0.0000, -62.0998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[395], 0, "<", 90, "Webdings", 40, 0, 0xFF515459, 0x0, 1);
    SetDynamicObjectMaterial(object_sanaBase[395], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[396] = CreateDynamicObject(19172, -15.2339, -2490.1523, 36.7961, 0.0000, 0.0000, -37.6999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_sanaBase[396], 0, "<", 90, "Webdings", 40, 0, 0xFF515459, 0x0, 1);
    SetDynamicObjectMaterial(object_sanaBase[396], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_sanaBase[397] = CreateDynamicObject(2370, -32.7583, -2481.5161, 35.7164, 0.0000, 0.0000, -11.8999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Shop_set_1_Table
    SetDynamicObjectMaterial(object_sanaBase[397], 0, 14786, "ab_sfgymbeams", "knot_wood128", 0xFFFFFFFF);
    object_sanaBase[398] = CreateDynamicObject(19143, -14.7719, -2488.0351, 39.1542, 0.0000, 0.0000, -60.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[399] = CreateDynamicObject(19143, -13.9076, -2489.5693, 39.1542, 0.0000, 0.0000, -60.5997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinSpotLight1
    object_sanaBase[400] = CreateDynamicObject(18075, -37.7061, -2498.3786, 39.1058, 0.0000, 0.0000, 125.7994, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_sanaBase[401] = CreateDynamicObject(18075, -27.0000, -2490.6577, 39.1058, 0.0000, 0.0000, 125.7994, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_sanaBase[402] = CreateDynamicObject(18075, -10.8611, -2501.3823, 40.0059, 0.0000, 0.0000, 118.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_sanaBase[403] = CreateDynamicObject(18075, -42.9472, -2491.1125, 39.1058, 0.0000, 0.0000, 125.7994, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_sanaBase[404] = CreateDynamicObject(638, -16.4130, -2485.0561, 39.8554, 0.0000, 0.0000, 28.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[405] = CreateDynamicObject(638, -15.1429, -2487.4028, 39.8554, 0.0000, 0.0000, 28.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[406] = CreateDynamicObject(638, -18.9624, -2480.3442, 39.8554, 0.0000, 0.0000, 28.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[407] = CreateDynamicObject(638, -22.1357, -2478.8869, 39.8554, 0.0000, 0.0000, 126.6092, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[408] = CreateDynamicObject(638, -24.2870, -2480.4836, 39.8554, 0.0000, 0.0000, 126.6092, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[409] = CreateDynamicObject(638, -26.4384, -2482.0803, 39.8554, 0.0000, 0.0000, 126.6092, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[410] = CreateDynamicObject(638, -28.5897, -2483.6799, 39.8554, 0.0000, 0.0000, 126.6092, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[411] = CreateDynamicObject(638, -30.7329, -2485.2751, 39.8554, 0.0000, 0.0000, 126.6092, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[412] = CreateDynamicObject(1280, -17.1539, -2486.2214, 39.5988, 0.0000, 0.0000, 28.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_sanaBase[413] = CreateDynamicObject(1280, -19.0673, -2482.6428, 39.5988, 0.0000, 0.0000, 28.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_sanaBase[414] = CreateDynamicObject(1280, -23.0323, -2481.1320, 39.5988, 0.0000, 0.0000, 126.7996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_sanaBase[415] = CreateDynamicObject(1280, -25.9790, -2483.3352, 39.5988, 0.0000, 0.0000, 126.7996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_sanaBase[416] = CreateDynamicObject(1280, -29.0618, -2485.6484, 39.5988, 0.0000, 0.0000, 126.7996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_sanaBase[417] = CreateDynamicObject(19121, -25.6215, -2494.3811, 39.7061, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_sanaBase[418] = CreateDynamicObject(19121, -28.6182, -2497.7099, 39.7061, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_sanaBase[419] = CreateDynamicObject(638, -19.6651, -2491.1098, 39.8554, 0.0000, 0.0000, -61.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[420] = CreateDynamicObject(638, -22.0090, -2492.4096, 39.8554, 0.0000, 0.0000, -61.0000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_sanaBase[421] = CreateDynamicObject(1280, -21.3680, -2490.7717, 39.5988, 0.0000, 0.0000, -60.4999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_sanaBase[422] = CreateDynamicObject(1663, -25.2852, -2485.1223, 36.1584, 0.0000, 0.0000, -137.9998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_B
    object_sanaBase[423] = CreateDynamicObject(2637, -38.1436, -2484.6315, 36.1211, 0.0000, 0.0000, 35.6999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE2
    object_sanaBase[424] = CreateDynamicObject(1663, -28.5501, -2487.5627, 36.1584, 0.0000, 0.0000, -152.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_B
    object_sanaBase[425] = CreateDynamicObject(1663, -20.6366, -2481.4882, 36.1584, 0.0000, 0.0000, -140.1999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_B
    object_sanaBase[426] = CreateDynamicObject(1663, -18.8735, -2485.8002, 36.1584, 0.0000, 0.0000, 105.6996, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_B
    object_sanaBase[427] = CreateDynamicObject(1663, -17.5352, -2488.3217, 36.1584, 0.0000, 0.0000, 117.9999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_B
    object_sanaBase[428] = CreateDynamicObject(1663, -15.9889, -2491.1240, 36.1584, 0.0000, 0.0000, 140.6000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_B
    object_sanaBase[429] = CreateDynamicObject(2776, -39.5270, -2483.5341, 36.1954, 0.0000, 0.0000, 36.3997, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR2
    object_sanaBase[430] = CreateDynamicObject(2776, -39.8097, -2485.8457, 36.1954, 0.0000, 0.0000, 123.3000, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR2
    object_sanaBase[431] = CreateDynamicObject(2776, -36.4508, -2483.3762, 36.1954, 0.0000, 0.0000, -56.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR2
    object_sanaBase[432] = CreateDynamicObject(2776, -37.0373, -2481.4628, 36.1954, 0.0000, 0.0000, 23.1998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR2
    object_sanaBase[433] = CreateDynamicObject(2776, -37.0373, -2481.4628, 36.2854, 0.0000, 0.0000, 23.1998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR2
    object_sanaBase[434] = CreateDynamicObject(2776, -37.0373, -2481.4628, 36.3656, 0.0000, 0.0000, 23.1998, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR2
    object_sanaBase[435] = CreateDynamicObject(8661, -16.8097, -2491.7189, 35.7229, 0.0000, 0.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_sanaBase[435], 0, 14714, "vghss1int2", "HS1_2Floor1", 0xFFFFFFFF);

    // Solid ground
    object_sanaBase[436] = CreateDynamicObject(8661, -29.4078, -2487.5410, 39.1747, 0.0000, 0.0000, 35.7999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); // Helipad Ground
    
    object_sanaBase[437] = CreateDynamicObject(17951, -6.7410, -2508.9094, 37.4948, 0.0000, 0.0000, 119.3999, VW_MAIN, MAPS_SANABASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Garage door

    object_sanaBase_garageDoor = object_sanaBase[437];
}
