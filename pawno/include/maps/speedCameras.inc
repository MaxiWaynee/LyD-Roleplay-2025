#include <YSI\y_hooks>

// Global interior define
#define MAPS_SPEEDCAMERAS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 250.0;
static Float:DRAWDISTANCE   = 230.0;

// Map variables
new object_speedCameras[24];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
    object_speedCameras[0] = CreateDynamicObject(18880, 329.01627, -1705.38208, 5.75747, 0.00000, 0.00000, 119.65446, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[1] = CreateDynamicObject(18880, 328.58502, -1708.56848, 5.77429, 0.00000, 0.00000, 300.56216, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[2] = CreateDynamicObject(18880, 1406.37256, -1737.93604, 12.53591, 0.00000, 0.00000, 246.45444, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[3] = CreateDynamicObject(18880, 1405.51892, -1726.50623, 12.60703, 0.00000, 0.00000, 61.49541, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[4] = CreateDynamicObject(18880, 2196.93652, -1131.84998, 24.09444, 0.00000, 0.00000, 222.12111, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[5] = CreateDynamicObject(18880, 2189.64453, -1104.10034, 23.32129, 0.00000, 0.00000, 48.99566, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[6] = CreateDynamicObject(18880, 1349.29028, -1383.70361, 12.60892, 0.00000, 0.00000, 195.25826, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[7] = CreateDynamicObject(18880, 1351.21179, -1383.19958, 12.59651, 0.00000, 0.00000, 12.38882, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[8] = CreateDynamicObject(18880, 1119.80762, -1389.87634, 12.39688, 0.00000, 0.00000, 70.23209, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[9] = CreateDynamicObject(18880, 1107.16016, -1411.68970, 12.34994, 0.00000, 0.00000, 251.81029, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[10] = CreateDynamicObject(18880, 1172.08777, -957.80908, 41.37507, 0.00000, 0.00000, 254.38451, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[11] = CreateDynamicObject(18880, 1169.73999, -935.57611, 41.67707, 0.00000, 0.00000, 80.01576, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[12] = CreateDynamicObject(18880, 1132.08179, -1033.56506, 30.77966, 0.00000, 0.00000, 69.95766, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[13] = CreateDynamicObject(18880, 1132.42090, -1045.08362, 30.56423, 0.00000, 0.00000, 245.07968, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[14] = CreateDynamicObject(18880, 1250.13843, -1155.18494, 22.27576, 0.00000, 0.00000, 249.69394, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[15] = CreateDynamicObject(18880, 1250.31616, -1134.99377, 22.42517, 0.00000, 0.00000, 62.77710, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[16] = CreateDynamicObject(18880, 1354.90344, -1100.49561, 22.54472, 0.00000, 0.00000, 2.44716, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[17] = CreateDynamicObject(18880, 1351.35315, -1100.18457, 22.38746, 0.00000, 0.00000, 181.75233, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[18] = CreateDynamicObject(18880, 1857.46997, -1358.27087, 12.24402, 0.00000, 0.00000, 341.00067, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[19] = CreateDynamicObject(18880, 1841.09338, -1358.66992, 12.34628, 0.00000, 0.00000, 160.41360, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[20] = CreateDynamicObject(18880, 2025.37244, -1757.80151, 12.43332, 0.00000, 0.00000, 251.17534, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[21] = CreateDynamicObject(18880, 2024.15332, -1746.79163, 12.43615, 0.00000, 0.00000, 71.90998, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[22] = CreateDynamicObject(18880, 1460.53784, -1316.54688, 12.12626, 0.00000, 0.00000, 332.21469, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_speedCameras[23] = CreateDynamicObject(18880, 1448.87231, -1317.67480, 12.42263, 0.00000, 0.00000, 164.23688, VW_MAIN, MAPS_SPEEDCAMERAS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}