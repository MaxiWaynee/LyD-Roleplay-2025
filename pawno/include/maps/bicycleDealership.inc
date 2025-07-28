#include <YSI\y_hooks>

// Global interior define
#define MAPS_BICYCLEDEALERSHIP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Bicycle dealership points
#define BICYCLEDEALERSHIP_COORDS    688.2108, -1181.0293, 15.3516

// Map variables
new object_bicycleDealership[132];
new text3D_bicycleDealership[1];
new actor_bicycleDealership[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Map Icons
    CreateDynamicMapIcon(BICYCLEDEALERSHIP_COORDS, 55, 0, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR);

    // 3DTextLabels
    text3D_bicycleDealership[0] = _:CreateDynamic3DTextLabel("Fahrradladen\n" COLOR_HEX_WHITE "Steig in ein beliebiges Fahrrad deiner Wahl ein!", COLOR_BLUE, BICYCLEDEALERSHIP_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BICYCLEDEALERSHIP_INTERIOR);

    // Actors
    actor_bicycleDealership[0] = CreateDynamicActor(7, 702.7725, -1184.7910, 15.9068, 150.0000, .worldid = VW_MAIN, .interiorid = MAPS_BICYCLEDEALERSHIP_INTERIOR); // Salesman
    
	// Objects
    object_bicycleDealership[0] = CreateDynamicObject(19464, 687.7760, -1186.1932, 16.2590, 0.0000, 0.0000, 149.6000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[0], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_bicycleDealership[1] = CreateDynamicObject(19447, 693.8572, -1179.2493, 14.3651, -0.9000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[1], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[2] = CreateDynamicObject(19447, 696.8250, -1181.0030, 14.5256, -0.4000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[2], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[3] = CreateDynamicObject(19447, 694.9420, -1191.0189, 14.7138, -0.4000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[3], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[4] = CreateDynamicObject(19447, 691.9484, -1189.2486, 14.5923, -0.4000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[4], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[5] = CreateDynamicObject(19447, 688.9439, -1187.4963, 14.4709, -0.4000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[5], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[6] = CreateDynamicObject(19447, 699.8197, -1182.7727, 14.6569, -0.4000, 87.4000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[6], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[7] = CreateDynamicObject(19447, 702.8125, -1184.5412, 14.8149, -0.4000, 87.4000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[7], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[8] = CreateObject(1685, 699.0482, -1192.7293, 14.3708, -5.7999, -1.9000, 6.6999); //blockpallet
    SetObjectMaterial(object_bicycleDealership[8], 0, 2098, "cj_int", "CJ_GREEN_WOOD", 0xFFFFFFFF);
    object_bicycleDealership[9] = CreateDynamicObject(19447, 700.8703, -1194.5233, 14.9541, -0.4000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[9], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[10] = CreateDynamicObject(19447, 708.7229, -1188.0361, 15.0522, 0.2998, 89.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[10], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[11] = CreateDynamicObject(19447, 705.8140, -1186.3154, 14.9932, 0.2998, 88.6999, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[11], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[12] = CreateDynamicObject(19447, 706.8065, -1198.0322, 15.1949, -0.4000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[12], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[13] = CreateDynamicObject(19447, 703.8469, -1196.2823, 15.0749, -0.4000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[13], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[14] = CreateDynamicObject(19447, 711.7177, -1189.8076, 15.1127, 0.2998, 89.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[14], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[15] = CreateDynamicObject(19446, 700.7368, -1200.0113, 14.8646, 0.0000, 0.0000, 59.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_bicycleDealership[15], 0, 3452, "bballvgnint", "carparkwall1_256", 0xFFFFFFFF);
    object_bicycleDealership[16] = CreateDynamicObject(19446, 700.7368, -1200.0113, 18.3346, 0.0000, 0.0000, 59.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_bicycleDealership[16], 0, 3452, "bballvgnint", "carparkwall1_256", 0xFFFFFFFF);
    object_bicycleDealership[17] = CreateDynamicObject(19464, 705.1652, -1184.1899, 17.5690, 0.0000, 0.0000, -28.4999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[17], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_bicycleDealership[18] = CreateDynamicObject(19447, 712.5581, -1180.5777, 13.3985, -0.8999, 176.5001, 58.5999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[18], 0, 17511, "stadium_lae2", "kickbarrier", 0xFFFFFFFF);
    object_bicycleDealership[19] = CreateDynamicObject(19172, 690.5316, -1181.3227, 19.2833, 0.0000, 0.0000, -120.9000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bicycleDealership[19], 0,"Fahrrad", 90, "Arial", 80, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_bicycleDealership[19], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_bicycleDealership[20] = CreateDynamicObject(19447, 711.6079, -1182.0844, 15.0640, -0.8999, 90.0000, 58.5999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[20], 0, 1257, "bustopm", "CJ_GREENMETAL", 0xFFFFFFFF);
    object_bicycleDealership[21] = CreateDynamicObject(19464, 694.5866, -1191.9942, 16.8889, 0.0000, 0.0000, 60.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[21], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_bicycleDealership[22] = CreateDynamicObject(19447, 702.7020, -1195.6485, 20.1641, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[22], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_bicycleDealership[23] = CreateDynamicObject(19447, 705.6693, -1197.3885, 20.1639, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[23], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_bicycleDealership[24] = CreateDynamicObject(19447, 707.5244, -1187.4283, 20.1641, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[24], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_bicycleDealership[25] = CreateDynamicObject(19447, 704.5313, -1185.6722, 20.1641, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[25], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_bicycleDealership[26] = CreateDynamicObject(19464, 699.7329, -1194.9406, 16.8889, 0.0000, 0.0000, 60.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[26], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_bicycleDealership[27] = CreateDynamicObject(19465, 707.4915, -1181.8397, 17.5734, 0.0000, 0.0000, 59.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_bicycleDealership[27], 0, 3452, "bballvgnint", "carparkwall1_256", 0xFFFFFFFF);
    object_bicycleDealership[28] = CreateDynamicObject(19447, 699.7005, -1193.8852, 20.1639, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[28], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_bicycleDealership[29] = CreateDynamicObject(19464, 700.9420, -1181.2999, 16.8889, 0.0000, 0.0000, 60.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[29], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_bicycleDealership[30] = CreateDynamicObject(19465, 707.4301, -1181.9427, 17.5734, 0.0000, 0.0000, 59.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_bicycleDealership[30], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_bicycleDealership[31] = CreateDynamicObject(19447, 710.5344, -1189.1944, 20.1641, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[31], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_bicycleDealership[32] = CreateDynamicObject(19464, 712.1832, -1184.6247, 17.5799, 0.0000, 0.0000, 59.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[32], 0, 3452, "bballvgnint", "carparkwall1_256", 0xFFFFFFFF);
    object_bicycleDealership[33] = CreateDynamicObject(19371, 711.9028, -1184.6828, 16.9939, 0.0000, 0.0000, 59.1999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[33], 0, 10429, "hashblock1_sfs", "ws_suburbansign", 0xFFFFFFFF);
    object_bicycleDealership[34] = CreateDynamicObject(19464, 712.1217, -1184.7270, 17.5799, 0.0000, 0.0000, 59.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[34], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_bicycleDealership[35] = CreateDynamicObject(19464, 706.0878, -1184.2453, 16.3290, 0.0000, 0.0000, 60.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[35], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_bicycleDealership[36] = CreateDynamicObject(19464, 692.6370, -1178.1025, 16.2590, 0.0000, 0.0000, 149.3000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[36], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_bicycleDealership[37] = CreateDynamicObject(19447, 705.7435, -1197.3988, 18.8542, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[37], 0, 11631, "mp_ranchcut", "mpCJ_Black_metal", 0xFFFFFFFF);
    object_bicycleDealership[38] = CreateDynamicObject(19434, 690.1693, -1182.1440, 17.9733, 90.2998, -2.2999, -28.7000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall074
    SetDynamicObjectMaterial(object_bicycleDealership[38], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_bicycleDealership[39] = CreateDynamicObject(19447, 704.5399, -1185.6772, 18.8540, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[39], 0, 11631, "mp_ranchcut", "mpCJ_Black_metal", 0xFFFFFFFF);
    object_bicycleDealership[40] = CreateDynamicObject(19447, 710.5598, -1189.2094, 18.8540, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[40], 0, 11631, "mp_ranchcut", "mpCJ_Black_metal", 0xFFFFFFFF);
    object_bicycleDealership[41] = CreateDynamicObject(19447, 699.7310, -1193.8746, 18.8546, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[41], 0, 11631, "mp_ranchcut", "mpCJ_Black_metal", 0xFFFFFFFF);
    object_bicycleDealership[42] = CreateDynamicObject(19447, 702.7415, -1195.6368, 18.8542, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[42], 0, 11631, "mp_ranchcut", "mpCJ_Black_metal", 0xFFFFFFFF);
    object_bicycleDealership[43] = CreateDynamicObject(19447, 707.5584, -1187.4482, 18.8540, 0.0000, 90.0000, -30.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[43], 0, 11631, "mp_ranchcut", "mpCJ_Black_metal", 0xFFFFFFFF);
    object_bicycleDealership[44] = CreateDynamicObject(19425, 710.8739, -1179.8996, 15.1142, 0.0000, -0.6998, -31.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_bicycleDealership[45] = CreateDynamicObject(19425, 713.6254, -1181.5721, 15.1535, 0.0000, -0.6998, -31.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_bicycleDealership[46] = CreateDynamicObject(19425, 716.3341, -1183.2188, 15.1922, 0.0000, -0.6998, -31.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_bicycleDealership[47] = CreateDynamicObject(19464, 695.7877, -1178.3474, 16.8889, 0.0000, 0.0000, 60.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[47], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_bicycleDealership[48] = CreateDynamicObject(19446, 700.7725, -1199.9514, 18.3346, 0.0000, 0.0000, 59.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_bicycleDealership[48], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_bicycleDealership[49] = CreateDynamicObject(19446, 700.7727, -1199.9516, 14.8646, -179.6000, 0.0000, 59.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_bicycleDealership[49], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_bicycleDealership[50] = CreateDynamicObject(19371, 697.0703, -1179.1512, 16.8640, 0.0000, 0.0000, 60.1999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[50], 0, 10429, "hashblock1_sfs", "ws_suburbansign", 0xFFFFFFFF);
    object_bicycleDealership[51] = CreateDynamicObject(19446, 707.3488, -1198.1352, 18.3346, 0.0000, 0.0000, 149.0997, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_bicycleDealership[51], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_bicycleDealership[52] = CreateDynamicObject(19446, 712.0424, -1190.2918, 18.3346, 0.0000, 0.0000, 149.0997, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_bicycleDealership[52], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_bicycleDealership[53] = CreateDynamicObject(19446, 712.0510, -1190.2971, 15.0346, 0.0000, 0.0000, 149.0997, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_bicycleDealership[53], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_bicycleDealership[54] = CreateDynamicObject(19446, 707.3572, -1198.1405, 14.8545, 0.0000, 0.0000, 149.0997, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall086
    SetDynamicObjectMaterial(object_bicycleDealership[54], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_bicycleDealership[55] = CreateDynamicObject(19464, 699.0623, -1195.4310, 16.8290, 0.0000, 0.0000, -28.4999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[55], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_bicycleDealership[56] = CreateDynamicObject(19464, 689.4494, -1189.0517, 16.8889, 0.0000, 0.0000, 60.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bicycleDealership[56], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_bicycleDealership[57] = CreateDynamicObject(19172, 689.1508, -1183.6312, 19.2833, 0.0000, 0.0000, -120.9000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bicycleDealership[57], 0,"laden", 90, "Arial", 80, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_bicycleDealership[57], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_bicycleDealership[58] = CreateDynamicObject(19371, 691.0979, -1189.9409, 17.0340, 0.0000, 0.0000, -119.8000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[58], 0, 14486, "ab_vegasgymbits01", "bbar_wall2", 0xFFFFFFFF);
    object_bicycleDealership[59] = CreateDynamicObject(2708, 692.1157, -1190.1396, 14.6234, 0.0000, 1.2999, 148.8000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ZIP_SHELF1
    object_bicycleDealership[60] = CreateDynamicObject(2625, 703.3757, -1183.2846, 16.1392, 0.0000, -2.1000, -31.7999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SHOE_URBAN2
    object_bicycleDealership[61] = CreateDynamicObject(2394, 691.5852, -1189.5781, 16.3437, 0.0000, -0.6998, -31.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_CLOTHES_STEP_1
    object_bicycleDealership[62] = CreateDynamicObject(2384, 692.1126, -1190.1463, 15.1738, 0.0000, 0.0000, -33.7999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[63] = CreateDynamicObject(2384, 691.6920, -1189.6966, 15.1738, 0.0000, 0.0000, -33.7999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[64] = CreateDynamicObject(2384, 691.0853, -1189.2905, 15.1738, 0.0000, 0.0000, -33.7999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[65] = CreateDynamicObject(2708, 690.5499, -1188.1549, 14.5721, 0.0000, 0.4999, 57.7000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ZIP_SHELF1
    object_bicycleDealership[66] = CreateDynamicObject(2382, 690.7470, -1188.1104, 16.2530, 0.0000, 0.0000, -24.7999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_Light
    object_bicycleDealership[67] = CreateDynamicObject(2382, 691.2073, -1187.2329, 16.2530, 0.0000, 0.0000, -24.7999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_Light
    object_bicycleDealership[68] = CreateDynamicObject(2384, 690.7043, -1188.1817, 15.1438, 0.0000, 0.0000, -124.1998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[69] = CreateDynamicObject(2384, 691.0693, -1187.6428, 15.1438, 0.0000, 0.0000, -124.1998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[70] = CreateDynamicObject(2384, 691.0693, -1187.6428, 15.1438, 0.0000, 0.0000, -124.1998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[71] = CreateDynamicObject(2384, 691.4174, -1187.1293, 15.1438, 0.0000, 0.0000, -124.1998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[72] = CreateDynamicObject(2384, 691.4174, -1187.1293, 14.7838, 0.0000, 0.0000, -124.1998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[73] = CreateDynamicObject(2384, 691.0350, -1187.6912, 14.7838, 0.0000, 0.0000, -124.1998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[74] = CreateDynamicObject(2384, 690.6414, -1188.2701, 14.7838, 0.0000, 0.0000, -124.1998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_8_JEANS_DARK
    object_bicycleDealership[75] = CreateDynamicObject(19371, 690.4562, -1187.6917, 13.6439, 0.0000, 0.0000, -30.3000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[75], 0, 14486, "ab_vegasgymbits01", "bbar_wall2", 0xFFFFFFFF);
    object_bicycleDealership[76] = CreateDynamicObject(19371, 691.0977, -1189.9414, 13.5739, 0.0000, 0.0000, -119.8000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[76], 0, 14486, "ab_vegasgymbits01", "bbar_wall2", 0xFFFFFFFF);
    object_bicycleDealership[77] = CreateDynamicObject(19371, 690.4559, -1187.6915, 17.0440, 0.0000, 0.0000, -30.3000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[77], 0, 14486, "ab_vegasgymbits01", "bbar_wall2", 0xFFFFFFFF);
    object_bicycleDealership[78] = CreateDynamicObject(2626, 702.8751, -1185.7810, 15.3936, 0.0000, 0.0000, -29.2999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_URB_COUNTER
    object_bicycleDealership[79] = CreateDynamicObject(2625, 701.4315, -1183.8784, 16.1132, 0.0000, 1.2999, 61.9000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SHOE_URBAN2
    object_bicycleDealership[80] = CreateDynamicObject(2625, 700.7200, -1183.4497, 16.1141, 1.3000, 0.7999, -119.0998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SHOE_URBAN2
    object_bicycleDealership[81] = CreateDynamicObject(2625, 700.1403, -1181.4062, 16.0521, 0.4999, -2.9000, -31.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SHOE_URBAN2
    object_bicycleDealership[82] = CreateDynamicObject(2698, 693.7819, -1187.9748, 15.6265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DUDS_RAIL01
    object_bicycleDealership[83] = CreateDynamicObject(1491, 702.5686, -1185.8488, 13.3869, 0.0000, 0.0000, 151.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    object_bicycleDealership[84] = CreateDynamicObject(1661, 698.6456, -1187.8747, 18.4803, 0.0000, 0.0000, -21.6999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //htl_fan_rotate_dy
    object_bicycleDealership[85] = CreateDynamicObject(1491, 706.8435, -1181.3990, 15.0353, 0.0000, 0.0000, -30.8000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_bicycleDealership[85], 0, 14572, "maint1", "ab_maintDoors", 0xFFFFFFFF);
    object_bicycleDealership[86] = CreateDynamicObject(1885, 691.7788, -1186.3057, 14.5668, 0.0000, 0.0000, -30.0000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_baskets
    object_bicycleDealership[87] = CreateObject(1685, 689.3495, -1186.4108, 13.9673, -6.0999, -0.1000, 6.2999); //blockpallet
    SetObjectMaterial(object_bicycleDealership[87], 0, 2098, "cj_int", "CJ_GREEN_WOOD", 0xFFFFFFFF);
    object_bicycleDealership[88] = CreateDynamicObject(1415, 713.9661, -1184.9304, 15.2961, 0.0000, 0.0000, 148.5999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_DUMPSTER
    object_bicycleDealership[89] = CreateDynamicObject(2074, 698.6484, -1187.8709, 18.5126, 0.0000, 0.0000, -25.4999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MLIGHT8
    object_bicycleDealership[90] = CreateDynamicObject(14600, 701.3935, -1199.7702, 16.6608, 1.2999, 0.0000, -128.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paperchase_bits2
    object_bicycleDealership[91] = CreateDynamicObject(2694, 699.0822, -1180.4311, 16.5582, 2.2000, -1.5999, -116.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_shoe_box2
    object_bicycleDealership[92] = CreateDynamicObject(2694, 700.2736, -1181.1723, 15.8950, 2.2000, -1.5999, -116.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_shoe_box2
    SetDynamicObjectMaterial(object_bicycleDealership[92], 0, 10101, "2notherbuildsfe", "sl_vicwall01", 0xFFFFFFFF);
    object_bicycleDealership[93] = CreateDynamicObject(2694, 699.0982, -1180.4609, 15.8390, 2.2000, -1.5999, -116.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_shoe_box2
    object_bicycleDealership[94] = CreateDynamicObject(2694, 700.9241, -1183.6350, 16.6872, -1.3999, 2.8000, 155.5999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_shoe_box2
    SetDynamicObjectMaterial(object_bicycleDealership[94], 0, 14668, "711c", "gun_ceiling3", 0xFFFFFFFF);
    object_bicycleDealership[95] = CreateDynamicObject(2694, 700.2709, -1181.1379, 16.6142, 2.2000, -1.5999, -116.2000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_shoe_box2
    SetDynamicObjectMaterial(object_bicycleDealership[95], 0, 14668, "711c", "gun_ceiling3", 0xFFFFFFFF);
    object_bicycleDealership[96] = CreateDynamicObject(1343, 712.6976, -1184.1042, 15.8439, 0.0000, 0.0000, 151.3000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster3
    object_bicycleDealership[97] = CreateDynamicObject(1343, 711.7591, -1183.5904, 15.8439, 0.0000, 0.0000, 151.3000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster3
    object_bicycleDealership[98] = CreateDynamicObject(2676, 714.8977, -1183.9880, 15.3239, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PROC_RUBBISH_8
    object_bicycleDealership[99] = CreateObject(1685, 693.6057, -1179.2850, 13.8635, -6.6000, 3.2999, 123.5000); //blockpallet
    SetObjectMaterial(object_bicycleDealership[99], 0, 2098, "cj_int", "CJ_GREEN_WOOD", 0xFFFFFFFF);
    object_bicycleDealership[100] = CreateDynamicObject(2694, 703.5601, -1183.0393, 16.7311, -0.5999, 0.5999, 64.0000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_shoe_box2
    SetDynamicObjectMaterial(object_bicycleDealership[100], 0, 16640, "a51", "a51_vent1", 0xFFFFFFFF);
    object_bicycleDealership[101] = CreateDynamicObject(19447, 697.9450, -1192.7944, 14.8357, -0.4000, 88.0000, -30.5998, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_bicycleDealership[101], 0, 14806, "bdupshifi", "Bdup2_wood", 0xFFFFFFFF);
    object_bicycleDealership[102] = CreateDynamicObject(19371, 709.7114, -1194.1021, 17.0137, 0.0000, -0.2999, -30.8000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[102], 0, 14486, "ab_vegasgymbits01", "bbar_wall2", 0xFFFFFFFF);
    object_bicycleDealership[103] = CreateDynamicObject(19371, 708.2014, -1193.2019, 15.1602, 0.0000, 87.9000, -30.8000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[103], 0, 14486, "ab_vegasgymbits01", "bbar_wall2", 0xFFFFFFFF);
    object_bicycleDealership[104] = CreateDynamicObject(19371, 708.1055, -1193.1434, 18.8383, 0.0000, 90.4999, -30.8000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_bicycleDealership[104], 0, 14486, "ab_vegasgymbits01", "bbar_wall2", 0xFFFFFFFF);
    object_bicycleDealership[105] = CreateDynamicObject(2387, 695.5990, -1181.9479, 14.5919, -0.5000, 0.0000, -67.6999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Shop_set_2_Unit5
    object_bicycleDealership[106] = CreateDynamicObject(1720, 707.8980, -1191.8155, 15.1898, 0.0000, 0.0000, -10.1000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_bicycleDealership[107] = CreateDynamicObject(11690, 707.9891, -1193.0621, 15.2296, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable1
    object_bicycleDealership[108] = CreateDynamicObject(1720, 709.5949, -1192.9232, 15.2698, 0.0000, 0.0000, -101.9999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_bicycleDealership[109] = CreateDynamicObject(1720, 708.3993, -1194.6079, 15.2698, 0.0000, 0.0000, -160.5000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_bicycleDealership[110] = CreateDynamicObject(1720, 706.7478, -1193.3565, 15.1798, 0.0000, 0.0000, 113.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_bicycleDealership[111] = CreateDynamicObject(1670, 708.0357, -1192.9986, 16.0271, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    object_bicycleDealership[112] = CreateDynamicObject(1742, 704.5217, -1185.3994, 15.0717, 0.0000, 0.0000, 62.1999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Med_BOOKSHELF
    object_bicycleDealership[113] = CreateDynamicObject(1742, 706.6556, -1184.5584, 15.0817, 0.0000, 0.0000, -29.1000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Med_BOOKSHELF
    object_bicycleDealership[114] = CreateDynamicObject(2608, 713.4455, -1185.9348, 15.6957, 0.0000, 0.0000, -29.1999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLCE_SHELF
    object_bicycleDealership[115] = CreateDynamicObject(1671, 713.0168, -1186.9548, 15.6587, 0.0000, 0.0000, 147.6999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_bicycleDealership[116] = CreateDynamicObject(1233, 693.4573, -1176.4843, 15.4684, 0.0000, 0.0000, -120.7999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //noparkingsign1
    object_bicycleDealership[117] = CreateDynamicObject(1233, 686.5512, -1188.0488, 15.4684, 0.0000, 0.0000, -120.7999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //noparkingsign1
    object_bicycleDealership[118] = CreateDynamicObject(3850, 686.3828, -1179.0982, 14.8204, -1.4000, 0.0000, -30.7000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
    object_bicycleDealership[119] = CreateDynamicObject(3850, 684.0331, -1183.0029, 15.0621, -3.5000, 0.0000, -31.0000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
    object_bicycleDealership[120] = CreateDynamicObject(3850, 688.7084, -1175.1976, 14.7522, 0.4000, 0.0000, -31.5000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
    object_bicycleDealership[121] = CreateDynamicObject(1215, 689.6196, -1173.6407, 14.8134, 0.0000, 0.0000, -27.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_bicycleDealership[122] = CreateDynamicObject(1215, 683.1732, -1184.4472, 15.2534, 0.0000, 0.0000, -27.3999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_bicycleDealership[123] = CreateDynamicObject(1687, 709.8267, -1185.5610, 20.9224, 0.0000, 0.0000, -29.5000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit1
    object_bicycleDealership[124] = CreateDynamicObject(1687, 702.6030, -1198.3286, 20.9824, 0.0000, 0.0000, -29.5000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit1
    object_bicycleDealership[125] = CreateDynamicObject(1697, 704.5341, -1194.7701, 21.4647, 0.0000, 0.0000, -147.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roofstuff16
    object_bicycleDealership[126] = CreateDynamicObject(1697, 707.0516, -1190.4135, 21.4647, 0.0000, 0.0000, -147.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roofstuff16
    object_bicycleDealership[127] = CreateDynamicObject(1697, 700.0265, -1190.0477, 21.5147, 0.0000, 0.0000, -147.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roofstuff16
    object_bicycleDealership[128] = CreateDynamicObject(1697, 702.7827, -1185.9335, 21.5147, 0.0000, 0.0000, -147.0999, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roofstuff16
    object_bicycleDealership[129] = CreateDynamicObject(1549, 709.2689, -1182.3684, 15.0824, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_ASHTRAY_b
    object_bicycleDealership[130] = CreateDynamicObject(921, 707.6875, -1181.6718, 17.9794, 0.0000, -1.3999, 148.5000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_IND_LIGHT
    object_bicycleDealership[131] = CreateDynamicObject(1614, 708.7546, -1182.4384, 19.0653, 0.0000, 0.0000, -120.7000, VW_MAIN, MAPS_BICYCLEDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_alarm1_01
}
