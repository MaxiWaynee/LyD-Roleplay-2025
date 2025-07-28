#include <YSI\y_hooks>

// Global interior define
#define MAPS_HALLOFFAME_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

#define HALL_OF_FAME_COORDS 2490.4829, 928.7290, 10.8279

// Map variables
new object_hallOfFame[172];
new text3D_hallOfFame[1];

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 8678, 2497.1499, 923.2269, 10.3437, 0.10); // wdngchplgrnd01_lvs
    RemoveBuildingForPlayer(playerid, 8777, 2497.1499, 923.2269, 10.3437, 0.10); // LOD Model of wdngchplgrnd01_lvs
    RemoveBuildingForPlayer(playerid, 8675, 2505.4499, 921.2420, 19.0156, 0.10); // wddngchpl02_lvs
    RemoveBuildingForPlayer(playerid, 8728, 2505.4499, 921.2420, 19.0156, 0.10); // LOD Model of wddngchpl02_lvs
    RemoveBuildingForPlayer(playerid, 8676, 2460.2299, 940.1879, 14.7109, 0.10); // wdngchplsgn2_lvs
}

hook OnGameModeInit() {
    // 3DTextLabels
    text3D_hallOfFame[0] = _:CreateDynamic3DTextLabel("LyD\n" COLOR_HEX_YELLOW "Hall Of Fame", COLOR_BLUE, HALL_OF_FAME_COORDS, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_HALLOFFAME_INTERIOR);

    // Objects
    object_hallOfFame[0] = CreateDynamicObject(19172, 2514.0441, 914.4962, 10.7986, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[0], 0, "Wir bedanke", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[0], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[1] = CreateDynamicObject(19175, 2506.5236, 925.4946, 12.7608, 0.0000, 340.2998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_hallOfFame[1], 0, "Fame", OBJECT_MATERIAL_SIZE_256x128, "Arial", 90, 0, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[1], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[2] = CreateDynamicObject(18766, 2518.7900, 913.9948, 9.1752, 0.0000, 70.3000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[2], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[3] = CreateDynamicObject(18766, 2504.2783, 924.9948, 11.6028, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[3], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[4] = CreateDynamicObject(8678, 2497.1484, 923.2265, 10.3437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdngchplgrnd01_lvs
    SetDynamicObjectMaterial(object_hallOfFame[4], 3, 4835, "airoads_las", "grassdry_128HV", 0x00000000);
    SetDynamicObjectMaterial(object_hallOfFame[4], 4, 7420, "vgnglfcrse1", "sandstone2_128", 0x00000000);
    SetDynamicObjectMaterial(object_hallOfFame[4], 5, 4835, "airoads_las", "concretenewb256", 0xFFA9A9A9);
    object_hallOfFame[5] = CreateDynamicObject(18766, 2490.8085, 914.0014, 9.1127, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[5], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[6] = CreateDynamicObject(18766, 2518.8024, 919.4959, 11.5429, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[6], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    object_hallOfFame[7] = CreateDynamicObject(18981, 2505.8039, 914.0042, 1.6318, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_hallOfFame[7], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[8] = CreateDynamicObject(18766, 2488.8066, 919.4959, 11.6028, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[8], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[9] = CreateDynamicObject(18766, 2490.8063, 924.9948, 9.1429, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[9], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[10] = CreateDynamicObject(18766, 2514.2783, 924.9948, 11.6028, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[10], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[11] = CreateDynamicObject(18766, 2514.7277, 919.5020, 14.5810, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[11], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[12] = CreateDynamicObject(18766, 2504.7297, 915.4818, 14.5830, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[12], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[13] = CreateDynamicObject(18766, 2494.7299, 915.4818, 14.5830, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[13], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[14] = CreateDynamicObject(18766, 2492.7280, 915.4829, 14.5839, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[14], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[15] = CreateDynamicObject(18766, 2514.7287, 923.5225, 14.5830, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[15], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[16] = CreateDynamicObject(18766, 2504.7297, 923.5225, 14.5830, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[16], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[17] = CreateDynamicObject(18766, 2494.7299, 923.5225, 14.5830, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[17], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[18] = CreateDynamicObject(18766, 2492.7280, 923.5239, 14.5839, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[18], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[19] = CreateDynamicObject(18766, 2494.7299, 919.5020, 14.5810, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[19], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[20] = CreateDynamicObject(18766, 2504.7297, 919.5020, 14.5810, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[20], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[21] = CreateDynamicObject(18766, 2492.7290, 919.5020, 14.5818, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[21], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[22] = CreateDynamicObject(18766, 2514.0844, 913.9948, 7.4899, 0.0000, 70.3000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[22], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[23] = CreateDynamicObject(18980, 2499.5214, 913.9948, 10.3661, 0.0000, 70.3000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_hallOfFame[23], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[24] = CreateDynamicObject(18766, 2514.7287, 915.4818, 14.5830, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[24], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_hallOfFame[25] = CreateDynamicObject(18766, 2509.3784, 913.9948, 5.8017, 0.0000, 70.3000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[25], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[26] = CreateDynamicObject(18980, 2490.7832, 913.9948, 10.3631, 0.0000, 70.3000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_hallOfFame[26], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[27] = CreateDynamicObject(18980, 2500.7929, 913.9968, 14.3430, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_hallOfFame[27], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[28] = CreateDynamicObject(18980, 2507.1892, 913.9979, 14.3420, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_hallOfFame[28], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[29] = CreateDynamicObject(18980, 2516.7600, 925.0073, 10.3829, 0.0000, -70.3000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_hallOfFame[29], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[30] = CreateDynamicObject(18980, 2511.2131, 925.0073, 10.3500, 0.0000, -70.3000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_hallOfFame[30], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[31] = CreateDynamicObject(18762, 2495.8049, 924.9970, 13.5957, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[31], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[32] = CreateDynamicObject(18762, 2498.1867, 924.9957, 12.2215, 0.0000, -24.7999, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[32], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[33] = CreateDynamicObject(19175, 2509.0397, 925.4946, 11.8606, 0.0000, 340.2998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_hallOfFame[33], 0, "Hall of", OBJECT_MATERIAL_SIZE_256x128, "Arial", 90, 0, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[33], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[34] = CreateDynamicObject(1231, 2498.1684, 927.1198, 10.8638, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_hallOfFame[35] = CreateDynamicObject(18762, 2498.7778, 924.9979, 11.6056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[35], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[36] = CreateDynamicObject(18762, 2497.2792, 924.9957, 11.8023, 0.0000, -24.7999, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[36], 0, 14706, "labig2int2", "whitecarpet01", 0xFF808080);
    object_hallOfFame[37] = CreateDynamicObject(18762, 2495.4445, 925.4649, 9.5354, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[37], 0, 14706, "labig2int2", "whitecarpet01", 0xFFFFFFFF);
    object_hallOfFame[38] = CreateDynamicObject(18762, 2495.4445, 924.4652, 9.5354, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[38], 0, 14706, "labig2int2", "whitecarpet01", 0xFFFFFFFF);
    object_hallOfFame[39] = CreateDynamicObject(18075, 2510.7851, 919.5446, 14.1538, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_hallOfFame[40] = CreateDynamicObject(18075, 2497.9836, 919.5446, 14.1538, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_hallOfFame[41] = CreateDynamicObject(18766, 2506.7919, 919.4959, 9.5260, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[41], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFF808080);
    object_hallOfFame[42] = CreateDynamicObject(18766, 2491.7951, 919.4959, 9.5260, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[42], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFF808080);
    object_hallOfFame[43] = CreateDynamicObject(18766, 2496.7939, 919.4959, 9.5260, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[43], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFF808080);
    object_hallOfFame[44] = CreateDynamicObject(18766, 2501.7932, 919.4959, 9.5260, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[44], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFF808080);
    object_hallOfFame[45] = CreateDynamicObject(18766, 2511.7910, 919.4959, 9.5260, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[45], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFF808080);
    object_hallOfFame[46] = CreateDynamicObject(18766, 2516.7900, 919.4959, 9.5260, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[46], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFF808080);
    object_hallOfFame[47] = CreateDynamicObject(2239, 2517.3354, 923.5784, 10.0009, 0.0000, 0.0000, -40.1999, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MLIGHT16
    object_hallOfFame[48] = CreateDynamicObject(18762, 2492.1225, 924.9863, 12.0552, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[48], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[49] = CreateDynamicObject(18762, 2497.9675, 924.9863, 12.0413, 0.0000, -24.7999, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[49], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[50] = CreateDynamicObject(1231, 2480.0876, 940.9196, 10.8638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_hallOfFame[51] = CreateDynamicObject(8843, 2515.7841, 930.6134, 9.8247, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    object_hallOfFame[52] = CreateDynamicObject(8843, 2503.7661, 910.3129, 9.8247, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    object_hallOfFame[53] = CreateDynamicObject(19967, 2481.6054, 930.6099, 9.6981, 0.0000, 0.0000, -45.9999, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
    object_hallOfFame[54] = CreateDynamicObject(1231, 2533.5866, 940.9196, 10.8638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_hallOfFame[55] = CreateDynamicObject(1231, 2506.1828, 940.9196, 10.8638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_hallOfFame[56] = CreateDynamicObject(19172, 2511.4262, 914.4962, 11.0507, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[56], 0, "n uns bei all", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[56], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[57] = CreateDynamicObject(19172, 2506.1958, 914.4962, 11.5544, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[57], 0, "und ehemali", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[57], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[58] = CreateDynamicObject(19172, 2508.8640, 914.4962, 11.2968, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[58], 0, "en aktuellen", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[58], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[59] = CreateDynamicObject(19172, 2503.6188, 914.4962, 11.8017, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[59], 0, "gen Teammit", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[59], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[60] = CreateDynamicObject(19172, 2500.9187, 914.4962, 12.0618, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[60], 0, "gliedern,", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[60], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[61] = CreateDynamicObject(19172, 2498.9667, 914.4962, 12.2495, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[61], 0, "die das Proj", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[61], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[62] = CreateDynamicObject(19172, 2496.4562, 914.4962, 12.4909, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[62], 0, "ekt unterstü", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[62], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[63] = CreateDynamicObject(19172, 2503.6230, 914.4962, 9.9259, 0.0000, 1.9996, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[63], 0, "Barb", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFF1493, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[63], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[64] = CreateDynamicObject(19172, 2510.4775, 914.4962, 12.9266, 0.0000, -12.1997, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[64], 0, "l3lackLegende", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFFA500, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[64], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[65] = CreateDynamicObject(19172, 2499.2395, 914.4962, 10.2257, 0.0000, -10.0000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[65], 0, "Julian", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF808000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[65], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[66] = CreateDynamicObject(19172, 2510.2463, 914.4962, 11.8613, 0.0000, -0.8999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[66], 0, "VaporPhonix", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF008000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[66], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[67] = CreateDynamicObject(19172, 2493.9052, 914.4962, 11.4680, 0.0000, 4.8997, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[67], 0, "Summer_Jam", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF008000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[67], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[68] = CreateDynamicObject(19172, 2496.7565, 914.4962, 11.1000, 0.0000, -6.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[68], 0, "Shadow", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[68], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[69] = CreateDynamicObject(19172, 2508.8322, 914.4962, 12.5221, 0.0000, -6.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[69], 0, "Lee_Koka", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[69], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[70] = CreateDynamicObject(19172, 2503.0856, 914.4962, 12.4856, 0.0000, 32.1999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[70], 0, "Thoxel", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[70], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[71] = CreateDynamicObject(19172, 2513.5131, 914.4962, 12.3353, 0.0000, -33.9000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[71], 0, "James", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF808000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[71], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[72] = CreateDynamicObject(19172, 2493.9313, 914.4962, 12.7345, 0.0000, -5.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[72], 0, "tzt haben.", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[72], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[73] = CreateDynamicObject(19172, 2505.9704, 914.4962, 10.2292, 0.0000, 4.0998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[73], 0, "IntelCore", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF008000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[73], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[74] = CreateDynamicObject(19172, 2506.1057, 914.4962, 13.0712, 0.0000, 4.9998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[74], 0, "Nico", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFF0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[74], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[75] = CreateDynamicObject(19172, 2501.5756, 914.4962, 10.8908, 0.0000, 15.5999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[75], 0, "Trip", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF696969, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[75], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[76] = CreateDynamicObject(19172, 2500.9716, 914.4962, 13.1619, 0.0000, -4.6999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[76], 0, "ryano", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF696969, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[76], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[77] = CreateDynamicObject(19172, 2510.2912, 914.4962, 10.2999, 0.0000, -3.2999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[77], 0, "StreetKillah", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF696969, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[77], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[78] = CreateDynamicObject(19172, 2496.3227, 914.4962, 11.3758, 0.0000, 15.5999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[78], 0, "Jackson.Lethal", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF696969, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[78], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[79] = CreateDynamicObject(19172, 2514.2404, 914.4962, 12.5424, 0.0000, -13.8000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[79], 0, "InSaNe", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF008000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[79], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[80] = CreateDynamicObject(19172, 2499.8686, 914.4962, 11.1605, 0.0000, -0.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[80], 0, "TheSmokerJoker", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF8B4513, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[80], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[81] = CreateDynamicObject(19172, 2503.4226, 914.4962, 10.9440, 0.0000, -8.3999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[81], 0, "Fleyd", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF808000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[81], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[82] = CreateDynamicObject(19172, 2507.9929, 914.4962, 10.2690, 0.0000, -8.3999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[82], 0, "GibMir500", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF808000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[82], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[83] = CreateDynamicObject(19172, 2511.7617, 914.4962, 13.2410, 0.0000, -8.3999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[83], 0, "John.eX", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF808000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[83], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[84] = CreateDynamicObject(19172, 2502.0288, 914.4962, 10.3113, 0.0000, -2.7000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[84], 0, "Jose", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[84], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[85] = CreateDynamicObject(19172, 2494.8828, 914.4962, 10.4642, 0.0000, -0.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[85], 0, "Kabby", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF8B4513, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[85], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[86] = CreateDynamicObject(19172, 2491.8129, 914.4962, 12.1583, 0.0000, -11.3999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[86], 0, "Tann3rDriv3r", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF8B4513, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[86], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[87] = CreateDynamicObject(19172, 2515.4790, 914.4962, 11.7243, 0.0000, -0.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[87], 0, "Brujah", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF8B4513, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[87], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[88] = CreateDynamicObject(19172, 2492.9970, 914.4962, 10.6808, 0.0000, -3.7999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[88], 0, "Vieira", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFFA500, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[88], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[89] = CreateDynamicObject(19172, 2498.4934, 914.4962, 12.6562, 0.0000, 4.9998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[89], 0, "PatrickJ.", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFB4FF00, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[89], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[90] = CreateDynamicObject(19172, 2491.6501, 914.4962, 13.0691, 0.0000, -3.8001, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[90], 0, "Maka", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFFA500, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[90], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[91] = CreateDynamicObject(19172, 2505.5732, 914.4962, 12.2348, 0.0000, -2.7999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[91], 0, "Puma", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFF0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[91], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[92] = CreateDynamicObject(19172, 2504.3532, 914.4962, 12.2054, 0.0000, 10.0999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[92], 0, "Benny42O", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFF0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[92], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[93] = CreateDynamicObject(19172, 2507.3198, 914.4962, 11.9694, 0.0000, -6.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[93], 0, "ikexx", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF8B4513, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[93], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[94] = CreateDynamicObject(19172, 2491.3645, 914.4962, 10.8318, 0.0000, 6.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[94], 0, "emiLijo", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[94], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[95] = CreateDynamicObject(19172, 2516.4492, 914.4962, 11.1068, 0.0000, -3.2999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[95], 0, "Olex", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF696969, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[95], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[96] = CreateDynamicObject(19172, 2489.3000, 919.4946, 12.7356, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[96], 0, "LyD | Community", OBJECT_MATERIAL_SIZE_256x128, "Arial", 35, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[96], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[97] = CreateDynamicObject(19172, 2512.6057, 914.4962, 11.3667, 0.0000, 6.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[97], 0, "Blunatixnoob", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[97], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[98] = CreateDynamicObject(19172, 2507.8898, 914.4962, 12.9750, 0.0000, 6.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[98], 0, "Speedy", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[98], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[99] = CreateDynamicObject(19172, 2516.1811, 914.4962, 10.3905, 0.0000, -13.8000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[99], 0, "C0dex", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[99], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[100] = CreateDynamicObject(19172, 2516.3718, 914.4962, 12.8393, 0.0000, 6.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[100], 0, "Jack.Parker", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[100], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[101] = CreateDynamicObject(19172, 2505.4060, 914.4962, 10.6848, 0.0000, 6.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[101], 0, "Chriis", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[101], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[102] = CreateDynamicObject(19172, 2489.4489, 914.4962, 13.0262, 0.0000, 6.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[102], 0, "Relatiiv", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[102], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[103] = CreateDynamicObject(19172, 2501.2302, 914.4962, 10.2096, 0.0000, 17.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[103], 0, "Jojoeffekt", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF008000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[103], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[104] = CreateDynamicObject(19172, 2513.2832, 914.4962, 9.8985, 0.0000, 7.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[104], 0, "Shirayama", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[104], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[105] = CreateDynamicObject(19172, 2516.4108, 914.4962, 12.2677, 0.0000, -12.1997, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[105], 0, "EnergieX", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFFA500, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[105], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[106] = CreateDynamicObject(19172, 2502.1340, 914.4962, 11.0892, 0.0000, -12.1997, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[106], 0, "HIB", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFFA500, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[106], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[107] = CreateDynamicObject(19172, 2515.4790, 914.4962, 11.7243, 0.0000, -0.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[107], 0, "Brujah", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF8B4513, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[107], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[108] = CreateDynamicObject(19172, 2515.6398, 914.4962, 11.0334, 0.0000, -12.7999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[108], 0, "Jayden.Asaki", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFFA500, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[108], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[109] = CreateDynamicObject(19172, 2507.0187, 914.4962, 10.5557, 0.0000, 8.0000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[109], 0, "Cem", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFFA500, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[109], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[110] = CreateDynamicObject(19172, 2500.7207, 914.4962, 12.4231, 0.0000, 6.1999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[110], 0, "Jason", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[110], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[111] = CreateDynamicObject(19172, 2495.1340, 914.4962, 13.0311, 0.0000, 5.0998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[111], 0, "Clyde", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF696969, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[111], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[112] = CreateDynamicObject(19172, 2496.8874, 914.4962, 13.0172, 0.0000, 5.0998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[112], 0, "Icii2q", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF008000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[112], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[113] = CreateDynamicObject(19172, 2489.9301, 914.4962, 11.6260, 0.0000, -6.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[113], 0, "Colore", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[113], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[114] = CreateDynamicObject(19172, 2492.0524, 914.4937, 10.0459, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[114], 0, "Und viele", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[114], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[115] = CreateDynamicObject(19172, 2504.0991, 914.4962, 12.8205, 0.0000, 15.5999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[115], 0, "Liam", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF696969, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[115], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[116] = CreateDynamicObject(19172, 2489.9904, 914.4937, 10.0459, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[116], 0, "mehr...", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[116], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[117] = CreateDynamicObject(19172, 2489.6064, 914.4962, 10.6632, 0.0000, 6.5000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[117], 0, "Freazy", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFFFF4500, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[117], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[118] = CreateDynamicObject(19172, 2514.6188, 914.4962, 13.0129, 0.0000, 9.1000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[118], 0, "Superlative", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[118], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[119] = CreateDynamicObject(19172, 2512.8098, 914.4962, 12.6085, 0.0000, -3.2999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[119], 0, "Torres", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF696969, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[119], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[120] = CreateDynamicObject(18766, 2488.8100, 919.4959, 8.4327, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[120], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[121] = CreateDynamicObject(19172, 2489.3000, 919.4946, 11.0000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[121], 0, "gez.", OBJECT_MATERIAL_SIZE_256x128, "Cambria", 16, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[121], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[122] = CreateDynamicObject(19172, 2489.3000, 919.4946, 12.3000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[122], 0, "Ein großer Dank gilt auch Euch!", OBJECT_MATERIAL_SIZE_256x128, "Cambria", 16, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[122], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[123] = CreateDynamicObject(19172, 2489.3000, 919.4946, 12.1000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[123], 0, "Ohne Euch wäre dieses Projekt nichts.", OBJECT_MATERIAL_SIZE_256x128, "Cambria", 16, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[123], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[124] = CreateDynamicObject(19172, 2489.3000, 919.4946, 11.8999, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[124], 0, "Danke, dass wir mit Euch so viele", OBJECT_MATERIAL_SIZE_256x128, "Arial", 16, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[124], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[125] = CreateDynamicObject(19172, 2489.3000, 918.6640, 11.6997, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[125], 0, "spaßige und lustige", OBJECT_MATERIAL_SIZE_256x128, "Cambria", 16, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[125], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[126] = CreateDynamicObject(19172, 2489.3000, 919.4946, 11.5000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[126], 0, "Eure Unterstützung ist uns wichtig,", OBJECT_MATERIAL_SIZE_256x128, "Arial", 16, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[126], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[127] = CreateDynamicObject(19172, 2489.3000, 919.4946, 11.3000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[127], 0, "danke, dass Ihr dabei seid!", OBJECT_MATERIAL_SIZE_256x128, "Cambria", 16, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[127], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[128] = CreateDynamicObject(19172, 2493.6608, 914.4962, 13.0200, 0.0000, 6.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[128], 0, "Isch", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[128], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[129] = CreateDynamicObject(19172, 2489.3000, 919.4946, 10.7299, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[129], 0, "LyD - Team", OBJECT_MATERIAL_SIZE_256x128, "Cambria", 24, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[129], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[130] = CreateDynamicObject(1723, 2513.9072, 923.6259, 9.9863, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mrk_seating1
    object_hallOfFame[131] = CreateDynamicObject(2315, 2514.1269, 921.0765, 10.0171, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE4
    SetDynamicObjectMaterial(object_hallOfFame[131], 0, 14652, "ab_trukstpa", "CJ_WOOD1(EDGE)", 0xFFFFFFFF);
    object_hallOfFame[132] = CreateDynamicObject(1723, 2517.4492, 922.0850, 9.9863, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mrk_seating1
    object_hallOfFame[133] = CreateDynamicObject(1723, 2509.7827, 923.6259, 9.9863, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mrk_seating1
    object_hallOfFame[134] = CreateDynamicObject(1724, 2507.6308, 922.0725, 9.9863, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mrk_seating1b
    object_hallOfFame[135] = CreateDynamicObject(1724, 2508.2893, 919.4907, 9.9863, 0.0000, 0.0000, 135.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mrk_seating1b
    object_hallOfFame[136] = CreateDynamicObject(2315, 2510.0029, 921.0764, 10.0171, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE4
    SetDynamicObjectMaterial(object_hallOfFame[136], 0, 14652, "ab_trukstpa", "CJ_WOOD1(EDGE)", 0xFFFFFFFF);
    object_hallOfFame[137] = CreateDynamicObject(1670, 2510.7766, 921.0833, 10.5249, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    object_hallOfFame[138] = CreateDynamicObject(2964, 2502.9519, 921.9304, 9.9855, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_pooltablesm
    SetDynamicObjectMaterial(object_hallOfFame[138], 4, 14652, "ab_trukstpa", "CJ_WOOD6", 0x00000000);
    object_hallOfFame[139] = CreateDynamicObject(3004, 2503.1821, 921.4589, 10.8767, 0.0000, 0.0000, 78.6999, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolq2
    object_hallOfFame[140] = CreateDynamicObject(3001, 2502.2631, 922.3687, 10.9216, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp07
    object_hallOfFame[141] = CreateDynamicObject(3004, 2501.8540, 921.5819, 11.5718, -90.9000, 0.0000, 90.9000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolq2
    object_hallOfFame[142] = CreateDynamicObject(19835, 2511.3146, 921.2332, 10.6044, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_hallOfFame[143] = CreateDynamicObject(19835, 2514.1638, 921.1932, 10.6044, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_hallOfFame[144] = CreateDynamicObject(19835, 2515.7353, 920.9431, 10.6044, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_hallOfFame[145] = CreateDynamicObject(1670, 2514.9304, 921.0833, 10.5249, 0.0000, 0.0000, -141.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    object_hallOfFame[146] = CreateDynamicObject(3002, 2502.9111, 922.4063, 10.9200, 0.0000, 0.0000, 100.2998, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt01
    object_hallOfFame[147] = CreateDynamicObject(1234, 2510.4624, 918.3214, 13.8157, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_hallOfFame[147], 0, 4833, "airprtrunway_las", "greyground256", 0xFF808080);
    SetDynamicObjectMaterial(object_hallOfFame[147], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[148] = CreateDynamicObject(3003, 2502.3210, 921.9381, 10.9153, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballcue
    object_hallOfFame[149] = CreateDynamicObject(2894, 2514.0739, 924.2277, 10.0206, 0.0000, 0.0000, -4.9000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_hallOfFame[149], 0, 2577, "cj_sex", "CJ_PAINTING9", 0xFFFFFFFF);
    object_hallOfFame[150] = CreateDynamicObject(3106, 2503.4675, 922.3800, 10.9169, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolball8
    object_hallOfFame[151] = CreateDynamicObject(3103, 2503.9929, 922.0036, 10.6708, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt05
    object_hallOfFame[152] = CreateDynamicObject(1234, 2514.7062, 918.3214, 13.8157, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_hallOfFame[152], 0, 4833, "airprtrunway_las", "greyground256", 0xFF808080);
    SetDynamicObjectMaterial(object_hallOfFame[152], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[153] = CreateDynamicObject(2998, 2503.9252, 921.9196, 10.6728, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp04
    object_hallOfFame[154] = CreateDynamicObject(3101, 2502.9196, 921.8129, 10.9246, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt03
    object_hallOfFame[155] = CreateDynamicObject(19786, 2510.4465, 918.3212, 12.6688, 12.5000, 0.0000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_hallOfFame[155], 1, 14581, "ab_mafiasuitea", "ab_pic_bridge", 0x00000000);
    object_hallOfFame[156] = CreateDynamicObject(19786, 2514.7092, 918.3212, 12.6688, 12.5000, 0.0000, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_hallOfFame[156], 1, 14581, "ab_mafiasuitea", "ab_pic_bridge", 0x00000000);
    object_hallOfFame[157] = CreateDynamicObject(3000, 2503.6862, 922.2559, 10.9200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp06
    object_hallOfFame[158] = CreateDynamicObject(2999, 2503.2531, 921.8912, 10.9200, 0.0000, 0.0000, 78.3999, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp05
    object_hallOfFame[159] = CreateDynamicObject(3102, 2503.5468, 921.6063, 10.9200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt04
    object_hallOfFame[160] = CreateDynamicObject(3104, 2502.1743, 921.7371, 10.9200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt06
    object_hallOfFame[161] = CreateDynamicObject(18762, 2495.0341, 924.9873, 14.0652, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[161], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[162] = CreateDynamicObject(19172, 2489.1789, 914.4962, 11.9160, 0.0000, 4.8997, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[162], 0, "BoDo", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF008000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[162], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[163] = CreateDynamicObject(2855, 2509.9877, 921.0803, 10.5137, 0.0000, 0.0000, -173.0998, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags05
    object_hallOfFame[164] = CreateDynamicObject(18762, 2495.0341, 925.0053, 14.0652, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[164], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[165] = CreateDynamicObject(18762, 2492.1225, 925.0073, 12.0552, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[165], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[166] = CreateDynamicObject(18762, 2497.9675, 925.0073, 12.0413, 0.0000, -24.7999, 0.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_hallOfFame[166], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_hallOfFame[167] = CreateDynamicObject(19172, 2489.3000, 920.1337, 11.6997, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[167], 0, "Momente erleben dürfen.", OBJECT_MATERIAL_SIZE_256x128, "Cambria", 16, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hallOfFame[167], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[168] = CreateDynamicObject(19172, 2499.6208, 914.4962, 12.9465, 0.0000, -2.0999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[168], 0, "shinzo", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[168], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[169] = CreateDynamicObject(19172, 2499.0571, 914.4962, 10.6456, 0.0000, -2.0999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[169], 0, "SerbO", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF00BFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[169], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[170] = CreateDynamicObject(19172, 2497.3994, 914.4962, 10.1104, 0.0000, 6.5998, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[170], 0, "MeisterGlenn", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF0000FF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[170], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hallOfFame[171] = CreateDynamicObject(19172, 2490.6794, 914.4962, 12.6063, 0.0000, 17.9999, 180.0000, VW_MAIN, MAPS_HALLOFFAME_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hallOfFame[171], 0, "Bl3ckOut", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF808000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_hallOfFame[171], 1, 19297, "matlights", "invisible", 0x00000000);
}