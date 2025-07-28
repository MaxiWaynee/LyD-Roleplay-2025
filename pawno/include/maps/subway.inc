#include <YSI\y_hooks>

// Global interior define
#define MAPS_SUBWAYEXTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Subway drivein point
#define SUBWAY_DRIVEIN_COORDS           1214.3331, -902.6706, 42.9207

// Map variables
new object_subway[338];
new pickup_subway[1];
new text3D_subway[1];

// TODO: Peek adjust BSN /gotoliste 1218.5142,-919.5847,43.0938 and maybe bus points?

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 5843, 1196.8438, -914.8672, 41.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 5858, 1214.1484, -913.4453, 43.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 5741, 1196.8438, -914.8672, 41.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1522, 1199.9688, -917.6406, 42.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 5844, 1206.1406, -900.9766, 42.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 6010, 1214.1484, -913.4453, 43.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 5742, 1197.3203, -899.2109, 45.0938, 0.25);

	// Map Icon // TODO: Peek add coords here
    // SetPlayerMapIcon(playerid, 9, SUBWAY_INTERIOR_ENTER_COORDS, 10, 0, 0);
}

hook OnGameModeInit() {
    // Map Icons
    CreateDynamicMapIcon(SUBWAY_DRIVEIN_COORDS, 36, 0, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR);

	// Pickups
	pickup_subway[0] = CreateDynamicPickup(2769, 1, SUBWAY_DRIVEIN_COORDS, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR); // Drivein

	// 3DTextLabels
	text3D_subway[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_GREEN "Subway - Drive-In\n" COLOR_HEX_WHITE "Tippe /Drivein", COLOR_WHITE, SUBWAY_DRIVEIN_COORDS, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SUBWAYEXTERIOR_INTERIOR); // Drivein

	// Objects
	object_subway[0] = CreateDynamicObject(19377, 1193.4819, -915.7315, 42.2330, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[0], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[1] = CreateDynamicObject(19327, 1209.6070, -925.2733, 50.2765, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[1], 0, "eat fresh.", 90, "Arial", 55, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[2] = CreateDynamicObject(19377, 1194.4990, -894.4016, 42.2318, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[2], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[3] = CreateDynamicObject(19377, 1205.4764, -903.4625, 42.2345, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[3], 0, 4835, "airoads_las", "concretenewb256", 0xFFD6DAD6);
    object_subway[4] = CreateDynamicObject(19377, 1204.0157, -893.0642, 42.2336, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[4], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[5] = CreateDynamicObject(19377, 1184.9626, -895.7415, 42.2108, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[5], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[6] = CreateDynamicObject(19377, 1181.0327, -896.2941, 42.2350, 0.4000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[6], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[7] = CreateDynamicObject(19377, 1192.0211, -905.3438, 42.2345, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[7], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[8] = CreateDynamicObject(19377, 1182.4936, -906.6826, 42.2369, 0.2398, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[8], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[9] = CreateDynamicObject(19377, 1206.9372, -913.8507, 42.2318, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[9], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[10] = CreateDynamicObject(19377, 1202.9759, -914.4196, 42.2336, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[10], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[11] = CreateDynamicObject(14410, 1214.0034, -916.1917, 39.1767, 0.0000, 0.0000, 97.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs03
    SetDynamicObjectMaterial(object_subway[11], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[11], 1, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[12] = CreateDynamicObject(19430, 1199.1046, -921.4254, 40.5918, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[12], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[13] = CreateDynamicObject(19377, 1187.5000, -921.8140, 37.0988, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[13], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[14] = CreateDynamicObject(19377, 1207.1988, -915.7625, 42.2299, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[14], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    object_subway[15] = CreateDynamicObject(19327, 1209.5871, -925.4234, 50.5367, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterial(object_subway[15], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[16] = CreateDynamicObject(5741, 1196.8479, -914.9467, 41.9687, 0.0000, 0.0000, 9.7079, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lawnstuff21
    SetDynamicObjectMaterial(object_subway[16], 0, 13681, "lahillshilhs1e", "veg_hedge1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[16], 1, 9524, "blokmodb", "Grass", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[16], 2, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[16], 3, 6312, "beacliff_law2", "concretebigblu4256128", 0xFFBDBEC6);
    object_subway[17] = CreateDynamicObject(19327, 1209.6173, -925.3234, 48.8767, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[17], 0, "SubDrive", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[18] = CreateDynamicObject(19327, 1209.5970, -925.6535, 48.8767, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[18], 0, "SubDrive", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[19] = CreateDynamicObject(19952, 1218.9787, -922.4636, 40.2154, 0.0000, 0.0000, 99.7994, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    object_subway[20] = CreateDynamicObject(19430, 1179.2143, -912.4492, 40.5960, 0.4000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[20], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[21] = CreateDynamicObject(19377, 1201.5113, -904.0205, 42.2336, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[21], 0, 4835, "airoads_las", "concretenewb256", 0xFFFFFFFF);
    object_subway[22] = CreateDynamicObject(1308, 1209.4952, -924.3557, 53.2038, 0.0000, 180.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //telgrphpole02
    SetDynamicObjectMaterial(object_subway[22], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[22], 1, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[22], 2, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[22], 4, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_subway[23] = CreateDynamicObject(19327, 1209.5871, -925.4234, 52.7167, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterial(object_subway[23], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[24] = CreateDynamicObject(19327, 1209.5871, -925.4234, 52.7167, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterial(object_subway[24], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[25] = CreateDynamicObject(19327, 1209.5871, -925.4234, 51.8967, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterial(object_subway[25], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[26] = CreateDynamicObject(19327, 1209.5871, -925.4234, 51.8967, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterial(object_subway[26], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[27] = CreateDynamicObject(19327, 1209.5871, -925.4234, 50.5367, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterial(object_subway[27], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[28] = CreateDynamicObject(19327, 1209.5472, -925.9935, 52.4266, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[28], 0, "Sub", 90, "Arial", 90, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[29] = CreateDynamicObject(19327, 1209.6070, -924.9530, 52.4266, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[29], 0, "Sub", 90, "Arial", 90, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[30] = CreateDynamicObject(19327, 1209.6070, -925.4235, 49.1767, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterial(object_subway[30], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[31] = CreateDynamicObject(19327, 1209.5771, -925.6533, 50.2765, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[31], 0, "eat fresh.", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[32] = CreateDynamicObject(19327, 1209.5970, -924.9829, 51.8166, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[32], 0, "way", 90, "Arial", 90, 1, 0xFFD78E10, 0x0, 0);
    object_subway[33] = CreateDynamicObject(19984, 1225.4641, -921.6063, 41.7644, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign37
    object_subway[34] = CreateDynamicObject(19430, 1191.7458, -910.5330, 43.4602, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[34], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[35] = CreateDynamicObject(19327, 1209.3177, -912.1942, 43.7308, 0.0000, -9.1997, 8.2999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[35], 0, "eat fresh.", 90, "Arial", 40, 1, 0xFF335F3F, 0x0, 0);
    object_subway[36] = CreateDynamicObject(19952, 1218.9675, -922.4552, 40.2154, 0.0000, 0.0000, -81.2994, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    object_subway[37] = CreateDynamicObject(618, 1218.7180, -921.0488, 42.2154, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[38] = CreateDynamicObject(19377, 1203.7690, -919.6782, 37.0984, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[38], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[39] = CreateDynamicObject(19377, 1181.9704, -916.8438, 37.1080, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[39], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[40] = CreateDynamicObject(19377, 1204.0196, -921.4602, 37.0970, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[40], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[41] = CreateDynamicObject(19430, 1191.5028, -908.8004, 43.4602, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[41], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[42] = CreateDynamicObject(19327, 1209.5472, -925.9935, 51.8166, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[42], 0, "way", 90, "Arial", 90, 1, 0xFFD78E10, 0x0, 0);
    object_subway[43] = CreateDynamicObject(618, 1171.1876, -930.7988, 42.4957, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[44] = CreateDynamicObject(19377, 1203.2596, -916.3170, 42.2280, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[44], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    object_subway[45] = CreateDynamicObject(19377, 1207.6727, -919.1394, 37.0970, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[45], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_subway[46] = CreateDynamicObject(19377, 1177.8530, -907.7600, 37.1058, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[46], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[47] = CreateDynamicObject(19430, 1180.4530, -912.2847, 40.5918, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[47], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[48] = CreateDynamicObject(19430, 1211.7292, -914.3552, 40.5699, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[48], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[49] = CreateDynamicObject(19377, 1208.3342, -919.0358, 37.0988, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[49], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[50] = CreateDynamicObject(19377, 1209.3243, -896.5786, 37.1058, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[50], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[51] = CreateDynamicObject(19951, 1168.8802, -880.8306, 40.5559, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign4
    object_subway[52] = CreateDynamicObject(19377, 1207.9123, -920.9229, 37.0988, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[52], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[53] = CreateDynamicObject(19328, 1170.2762, -923.7175, 50.9071, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[53], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[54] = CreateDynamicObject(1308, 1170.4737, -918.9257, 53.7238, 0.0000, 180.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //telgrphpole02
    SetDynamicObjectMaterial(object_subway[54], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[54], 1, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[54], 2, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[54], 4, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_subway[55] = CreateDynamicObject(19328, 1170.7530, -923.7996, 50.8670, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[55], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[56] = CreateDynamicObject(19328, 1170.7530, -923.7996, 52.9271, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[56], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[57] = CreateDynamicObject(19328, 1170.7530, -923.7996, 48.8269, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[57], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[58] = CreateDynamicObject(19328, 1170.2762, -923.7175, 48.8269, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[58], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[59] = CreateDynamicObject(19328, 1170.2916, -918.2316, 48.8670, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[59], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[60] = CreateDynamicObject(19328, 1170.2762, -923.7175, 52.9169, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[60], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[61] = CreateDynamicObject(19327, 1209.6070, -925.4235, 49.1767, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterial(object_subway[61], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[62] = CreateDynamicObject(19328, 1170.4051, -924.1602, 52.0471, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[62], 0, "L", 100, "Arial", 160, 1, 0xFF335F3F, 0x0, 0);
    object_subway[63] = CreateDynamicObject(19377, 1210.6363, -906.0379, 37.1068, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[63], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[64] = CreateDynamicObject(618, 1169.9477, -912.8587, 42.4957, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[65] = CreateDynamicObject(618, 1168.7773, -897.6486, 42.4957, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[66] = CreateDynamicObject(618, 1167.6169, -882.5584, 42.4957, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[67] = CreateDynamicObject(19377, 1194.2425, -920.8643, 37.0988, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[67], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[68] = CreateDynamicObject(19430, 1192.5688, -909.5382, 45.1220, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[68], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[69] = CreateDynamicObject(970, 1189.6352, -913.1206, 42.8969, 0.0000, 0.0000, 7.8997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[69], 0, 5631, "apartmentalpha", "ws_railing1", 0xFF000000);
    object_subway[70] = CreateDynamicObject(19377, 1196.5411, -908.9993, 46.6136, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[70], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[71] = CreateDynamicObject(19430, 1191.3507, -909.6834, 43.2891, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[71], 0, 13363, "cephotoblockcs_t", "sw_door16", 0xFFFFFFFF);
    object_subway[72] = CreateDynamicObject(970, 1182.8468, -913.9918, 42.8969, 0.0000, 0.0000, -82.1996, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[72], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[73] = CreateDynamicObject(970, 1177.6214, -906.3496, 42.8969, 0.0000, 0.0000, -82.1996, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[73], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[74] = CreateDynamicObject(970, 1180.5340, -912.2034, 42.8969, 0.0000, 0.0000, 7.8997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[74], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[75] = CreateDynamicObject(970, 1178.1810, -910.4317, 42.8969, 0.0000, 0.0000, -82.1996, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[75], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[76] = CreateDynamicObject(970, 1177.0583, -902.2376, 42.8969, 0.0000, 0.0000, -82.1996, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[76], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[77] = CreateDynamicObject(970, 1176.4989, -898.1558, 42.8969, 0.0000, 0.0000, -82.1996, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[77], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[78] = CreateDynamicObject(970, 1175.9366, -894.0443, 42.8969, 0.0000, 0.0000, -82.1996, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[78], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[79] = CreateDynamicObject(970, 1185.1739, -915.7396, 42.8969, 0.0000, 0.0000, 7.8997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[79], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[80] = CreateDynamicObject(19430, 1205.7490, -887.5770, 40.5787, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[80], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_subway[81] = CreateDynamicObject(19430, 1193.9394, -888.5321, 40.5787, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[81], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[82] = CreateDynamicObject(19377, 1189.1958, -889.9077, 37.0978, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[82], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[83] = CreateDynamicObject(19377, 1184.2839, -890.5969, 37.0988, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[83], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[84] = CreateDynamicObject(19377, 1180.3143, -891.1646, 37.1086, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[84], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[85] = CreateDynamicObject(19377, 1176.2722, -896.5203, 37.1068, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[85], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[86] = CreateDynamicObject(19377, 1177.5964, -906.0593, 37.1068, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[86], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[87] = CreateDynamicObject(19377, 1182.1035, -917.8004, 37.1068, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[87], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[88] = CreateDynamicObject(19430, 1199.0372, -920.9495, 40.5937, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[88], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[89] = CreateDynamicObject(1825, 1187.2746, -905.9003, 42.3367, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_table_chairs1
    SetDynamicObjectMaterial(object_subway[89], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[89], 2, 2799, "castable", "cl_ashtray", 0xFFFFFFFF);
    object_subway[90] = CreateDynamicObject(19430, 1207.3331, -887.3546, 40.5787, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[90], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_subway[91] = CreateDynamicObject(19430, 1204.5987, -887.7376, 40.5777, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[91], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_subway[92] = CreateDynamicObject(1720, 1186.9494, -904.6445, 42.2910, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[93] = CreateDynamicObject(970, 1178.1158, -891.4901, 42.8969, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[93], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[94] = CreateDynamicObject(970, 1191.7762, -889.5955, 42.8969, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[94], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[95] = CreateDynamicObject(970, 1187.1616, -890.2374, 42.8969, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[95], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[96] = CreateDynamicObject(19327, 1210.4422, -904.7293, 44.2340, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[96], 0, "way", 130, "Arial", 30, 1, 0xFF335F3F, 0x0, 0);
    object_subway[97] = CreateDynamicObject(2230, 1209.7364, -903.0922, 43.2373, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_SPEAKER_2
    SetDynamicObjectMaterial(object_subway[97], 2, 14584, "ab_abbatoir01", "cj_sheetmetal", 0xFFFFFFFF);
    object_subway[98] = CreateDynamicObject(2642, 1210.5819, -905.9254, 44.2224, 0.0000, 0.0000, 97.9999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BURGER_POSTER2
    SetDynamicObjectMaterial(object_subway[98], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
    object_subway[99] = CreateDynamicObject(2642, 1211.1175, -909.6231, 44.2122, 0.0000, 0.0000, 98.0998, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BURGER_POSTER2
    SetDynamicObjectMaterial(object_subway[99], 0, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
    SetDynamicObjectMaterial(object_subway[99], 1, 14584, "ab_abbatoir01", "cj_sheetmetal", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[99], 2, 2430, "cj_burg_sign", "CJ_BS_MENU1", 0xFFFFFFFF);
    object_subway[100] = CreateDynamicObject(19327, 1210.9936, -908.6599, 43.6040, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[100], 0, "Sub", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[101] = CreateDynamicObject(19327, 1210.9632, -908.4420, 43.6040, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[101], 0, "way", 130, "Arial", 30, 1, 0xFF335F3F, 0x0, 0);
    object_subway[102] = CreateDynamicObject(19327, 1210.1590, -902.2990, 44.6239, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[102], 0, "Bestellung", 130, "Arial", 40, 1, 0xFFD78E10, 0x0, 0);
    object_subway[103] = CreateDynamicObject(19327, 1210.4735, -904.9569, 44.2340, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[103], 0, "Sub", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[104] = CreateDynamicObject(19377, 1204.9571, -900.0695, 45.8134, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[104], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[105] = CreateDynamicObject(19327, 1210.2480, -902.9328, 44.6138, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[105], 0, "Drive-IN", 130, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[106] = CreateDynamicObject(19377, 1204.9482, -900.0717, 42.4235, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[106], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[107] = CreateDynamicObject(19377, 1205.9704, -907.3311, 42.4239, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[107], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[108] = CreateDynamicObject(19377, 1205.9746, -907.3609, 45.8138, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[108], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[109] = CreateDynamicObject(10183, 1221.0047, -885.9816, 41.9146, 0.0000, 0.0000, -34.7000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_subway[110] = CreateDynamicObject(8843, 1215.2110, -909.2854, 41.8860, 0.4999, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    object_subway[111] = CreateDynamicObject(19967, 1225.4648, -921.5084, 41.9123, 0.0000, 0.0000, -157.5000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
    object_subway[112] = CreateDynamicObject(19967, 1209.7209, -924.2293, 42.0023, 0.0000, 0.0000, 99.3000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
    object_subway[113] = CreateDynamicObject(19976, 1209.3431, -924.2874, 42.0573, 0.0000, 0.0000, -89.3999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign29
    object_subway[114] = CreateDynamicObject(19966, 1218.3624, -923.1616, 41.7997, 0.0000, 0.0000, -165.1999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign19
    object_subway[115] = CreateDynamicObject(19967, 1218.3841, -923.2548, 41.7821, 0.0000, 0.0000, 14.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
    object_subway[116] = CreateDynamicObject(19430, 1196.1932, -914.2335, 43.2891, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[116], 0, 13363, "cephotoblockcs_t", "sw_door16", 0xFFFFFFFF);
    object_subway[117] = CreateDynamicObject(737, 1182.7457, -875.8186, 42.4048, 0.0000, 0.0000, 12.3000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //aw_streettree3
    object_subway[118] = CreateDynamicObject(737, 1205.8459, -871.5488, 42.2849, 0.0000, 0.0000, 9.3999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //aw_streettree3
    object_subway[119] = CreateDynamicObject(8991, 1215.2967, -869.7595, 42.3879, 0.0000, 0.0000, 10.6000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush12_lvs
    SetDynamicObjectMaterial(object_subway[119], 0, 701, "badlands", "newtreeleaves128", 0xFFFFFFFF);
    object_subway[120] = CreateDynamicObject(970, 1182.7248, -890.8532, 42.8969, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[120], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[121] = CreateDynamicObject(8991, 1195.6473, -872.8197, 42.3879, 0.0000, 0.0000, 9.5999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush12_lvs
    SetDynamicObjectMaterial(object_subway[121], 0, 701, "badlands", "newtreeleaves128", 0xFFFFFFFF);
    object_subway[122] = CreateDynamicObject(8991, 1174.2165, -876.4821, 42.3879, 0.0000, 0.0000, 9.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush12_lvs
    SetDynamicObjectMaterial(object_subway[122], 0, 701, "badlands", "newtreeleaves128", 0xFFFFFFFF);
    object_subway[123] = CreateDynamicObject(1825, 1186.4825, -900.8513, 42.3367, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_table_chairs1
    SetDynamicObjectMaterial(object_subway[123], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[123], 2, 2799, "castable", "cl_ashtray", 0xFFFFFFFF);
    object_subway[124] = CreateDynamicObject(970, 1205.8203, -887.6458, 42.8969, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[124], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[125] = CreateDynamicObject(1825, 1185.8868, -895.9155, 42.3367, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_table_chairs1
    SetDynamicObjectMaterial(object_subway[125], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[125], 2, 2799, "castable", "cl_ashtray", 0xFFFFFFFF);
    object_subway[126] = CreateDynamicObject(1825, 1179.8155, -896.7583, 42.3367, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_table_chairs1
    SetDynamicObjectMaterial(object_subway[126], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[126], 2, 2799, "castable", "cl_ashtray", 0xFFFFFFFF);
    object_subway[127] = CreateDynamicObject(1825, 1180.5019, -901.7008, 42.3367, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_table_chairs1
    SetDynamicObjectMaterial(object_subway[127], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[127], 2, 2799, "castable", "cl_ashtray", 0xFFFFFFFF);
    object_subway[128] = CreateDynamicObject(19377, 1186.7690, -916.6749, 42.2350, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[128], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    object_subway[129] = CreateDynamicObject(1685, 1206.5716, -893.0087, 43.0466, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //blockpallet
    object_subway[130] = CreateDynamicObject(1280, 1193.3647, -895.6624, 42.7280, 0.0000, 0.0000, -81.3999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_subway[131] = CreateDynamicObject(19450, 1198.6479, -886.8131, 41.9313, 0.0000, -80.0998, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_subway[131], 0, 16008, "des_n", "drvin_ground1", 0xFFFFFFFF);
    object_subway[132] = CreateDynamicObject(19328, 1170.3570, -918.5272, 51.6170, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[132], 0, "R", 100, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[133] = CreateDynamicObject(19328, 1170.2916, -918.2316, 52.9771, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[133], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[134] = CreateDynamicObject(19328, 1170.2916, -918.2316, 50.9071, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[134], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[135] = CreateDynamicObject(19328, 1170.7657, -918.2443, 50.8969, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[135], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[136] = CreateDynamicObject(19328, 1170.7657, -918.2443, 48.8269, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[136], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[137] = CreateDynamicObject(19328, 1170.7657, -918.2443, 52.9771, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterial(object_subway[137], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[138] = CreateDynamicObject(19328, 1170.9155, -917.9630, 51.6370, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[138], 0, "R", 100, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[139] = CreateDynamicObject(3532, 1209.6435, -919.7896, 42.3478, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //triadbush
    object_subway[140] = CreateDynamicObject(19377, 1211.9582, -915.5667, 37.1068, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[140], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[141] = CreateDynamicObject(19464, 1210.8569, -908.9545, 44.5516, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[141], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[142] = CreateDynamicObject(19464, 1191.6915, -911.6098, 44.5503, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[142], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[143] = CreateDynamicObject(19464, 1194.8999, -914.0609, 44.5516, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[143], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[144] = CreateDynamicObject(19464, 1200.7724, -913.2357, 44.5516, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[144], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[145] = CreateDynamicObject(19464, 1206.6522, -912.4093, 44.5516, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[145], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[146] = CreateDynamicObject(970, 1208.2801, -889.7222, 42.8969, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[146], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[147] = CreateDynamicObject(970, 1208.9145, -894.2280, 42.8969, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[147], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[148] = CreateDynamicObject(618, 1225.7380, -882.5584, 42.4957, 0.0000, 0.0000, 6.3997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[149] = CreateDynamicObject(618, 1227.7381, -894.2138, 42.4957, 0.0000, 0.0000, 9.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[150] = CreateDynamicObject(618, 1229.8479, -906.3010, 42.4957, 0.0000, 0.0000, 9.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[151] = CreateDynamicObject(618, 1232.1987, -919.7677, 42.4957, 0.0000, 0.0000, 9.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_subway[152] = CreateDynamicObject(8991, 1224.6545, -876.1234, 42.3879, 0.0000, 0.0000, -80.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush12_lvs
    SetDynamicObjectMaterial(object_subway[152], 0, 701, "badlands", "newtreeleaves128", 0xFFFFFFFF);
    object_subway[153] = CreateDynamicObject(8991, 1227.6368, -894.5537, 42.3879, 0.0000, 0.0000, -80.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush12_lvs
    SetDynamicObjectMaterial(object_subway[153], 0, 701, "badlands", "newtreeleaves128", 0xFFFFFFFF);
    object_subway[154] = CreateDynamicObject(8991, 1230.2237, -910.1303, 42.3879, 0.0000, 0.0000, -80.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush12_lvs
    SetDynamicObjectMaterial(object_subway[154], 0, 701, "badlands", "newtreeleaves128", 0xFFFFFFFF);
    object_subway[155] = CreateDynamicObject(1294, 1199.8813, -873.1469, 46.7107, 0.0000, 0.0000, 96.5998, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mlamppost
    object_subway[156] = CreateDynamicObject(1294, 1175.7373, -877.2890, 46.7107, 0.0000, 0.0000, 96.5998, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mlamppost
    object_subway[157] = CreateDynamicObject(1294, 1226.7563, -889.2592, 46.5606, 0.0000, 0.0000, 8.6997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mlamppost
    object_subway[158] = CreateDynamicObject(1294, 1230.5594, -912.8557, 46.5606, 0.0000, 0.0000, 8.6997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mlamppost
    object_subway[159] = CreateDynamicObject(19951, 1176.9239, -929.8712, 40.5559, 0.0000, 0.0000, -171.6999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign4
    object_subway[160] = CreateDynamicObject(19951, 1178.0019, -929.7139, 40.5559, 0.0000, 0.0000, -171.6999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign4
    object_subway[161] = CreateDynamicObject(19951, 1175.7955, -930.0363, 40.5559, 0.0000, 0.0000, -171.6999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign4
    object_subway[162] = CreateDynamicObject(19464, 1208.4144, -912.1723, 44.5503, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[162], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[163] = CreateDynamicObject(19464, 1210.0422, -903.0808, 44.5516, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[163], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[164] = CreateDynamicObject(19464, 1190.8774, -905.7498, 44.5516, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[164], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[165] = CreateDynamicObject(19325, 1195.2434, -914.1503, 43.7859, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[165], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[166] = CreateDynamicObject(19325, 1191.5113, -911.3034, 43.7859, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[166], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[167] = CreateDynamicObject(19325, 1201.7490, -913.2349, 43.7859, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[167], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[168] = CreateDynamicObject(19325, 1202.8183, -913.0819, 43.7859, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[168], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[169] = CreateDynamicObject(19377, 1199.9648, -910.8964, 45.8125, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[169], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[170] = CreateDynamicObject(19377, 1195.0329, -911.5822, 45.8134, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[170], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[171] = CreateDynamicObject(19325, 1191.4084, -910.5703, 43.7859, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[171], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[172] = CreateDynamicObject(19377, 1193.9575, -906.9464, 40.6436, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[172], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[173] = CreateDynamicObject(19377, 1205.0870, -910.1868, 40.6436, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[173], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[174] = CreateDynamicObject(19430, 1195.2495, -913.8441, 43.4602, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[174], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[175] = CreateDynamicObject(19430, 1195.9974, -912.7788, 45.1202, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[175], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[176] = CreateDynamicObject(19430, 1191.5168, -908.8087, 43.4592, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[176], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_subway[177] = CreateDynamicObject(19430, 1197.0024, -913.6005, 43.4602, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[177], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[178] = CreateDynamicObject(19430, 1191.7563, -910.5211, 43.4592, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[178], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_subway[179] = CreateDynamicObject(19430, 1192.5698, -909.5382, 45.1119, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[179], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_subway[180] = CreateDynamicObject(19121, 1193.8061, -887.7307, 42.5321, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_subway[181] = CreateDynamicObject(19430, 1195.2552, -913.8106, 43.2900, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[181], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_subway[182] = CreateDynamicObject(19430, 1195.9930, -912.7492, 45.1100, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[182], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_subway[183] = CreateDynamicObject(19430, 1196.9881, -913.5692, 43.2900, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[183], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_subway[184] = CreateDynamicObject(19327, 1190.8398, -906.4926, 44.4840, 0.0000, 0.0000, -82.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[184], 0, "way", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[185] = CreateDynamicObject(19327, 1190.7058, -905.6035, 44.4538, 0.0000, 0.0000, -82.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[185], 0, "u", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[186] = CreateDynamicObject(19327, 1190.7613, -906.0092, 44.4538, 0.0000, 0.0000, -82.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[186], 0, "b", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[187] = CreateDynamicObject(19327, 1209.9420, -912.1088, 44.4840, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[187], 0, "way", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[188] = CreateDynamicObject(19464, 1192.4875, -896.6577, 44.5516, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[188], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[189] = CreateDynamicObject(19327, 1208.6185, -912.3134, 44.4840, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[189], 0, "Sub", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[190] = CreateDynamicObject(19464, 1208.4166, -912.1821, 43.3515, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[190], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[191] = CreateDynamicObject(19464, 1190.0560, -899.8662, 43.3515, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[191], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[192] = CreateDynamicObject(19377, 1205.4073, -907.7697, 46.6146, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[192], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[193] = CreateDynamicObject(19464, 1210.8646, -908.9625, 43.3515, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[193], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[194] = CreateDynamicObject(19464, 1210.0476, -903.0786, 43.3515, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[194], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[195] = CreateDynamicObject(19377, 1204.2978, -899.7669, 46.6136, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[195], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[196] = CreateDynamicObject(19464, 1190.0605, -899.8662, 44.5516, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[196], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[197] = CreateDynamicObject(19464, 1190.6772, -904.3433, 43.3515, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[197], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[198] = CreateDynamicObject(19464, 1198.3623, -895.8336, 44.5516, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[198], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[199] = CreateDynamicObject(19464, 1204.2309, -895.0078, 44.5503, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[199], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[200] = CreateDynamicObject(19464, 1205.9847, -894.7598, 44.5516, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[200], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[201] = CreateDynamicObject(19464, 1209.2290, -897.2075, 44.5503, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[201], 0, 14785, "gen_offtrackint", "otb_rooftile1", 0xFF335F3F);
    object_subway[202] = CreateDynamicObject(19464, 1209.2301, -897.1950, 43.3515, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[202], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[203] = CreateDynamicObject(19464, 1206.0223, -894.7498, 43.3515, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[203], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[204] = CreateDynamicObject(19464, 1200.1489, -895.5748, 43.3515, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[204], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[205] = CreateDynamicObject(19464, 1194.2862, -896.3983, 43.3515, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[205], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[206] = CreateDynamicObject(19464, 1192.7121, -896.6206, 43.3515, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_subway[206], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[207] = CreateDynamicObject(19377, 1195.4637, -900.9935, 46.6124, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[207], 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0xFFFFFFFF);
    object_subway[208] = CreateDynamicObject(994, 1192.1048, -914.4846, 46.5844, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_subway[209] = CreateDynamicObject(994, 1190.5218, -903.2163, 46.5844, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_subway[210] = CreateDynamicObject(994, 1209.6833, -900.5233, 46.5844, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_subway[211] = CreateDynamicObject(994, 1211.2701, -911.8129, 46.5844, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_subway[212] = CreateDynamicObject(994, 1205.0887, -912.6699, 46.5844, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_subway[213] = CreateDynamicObject(994, 1192.0743, -914.4771, 46.5844, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_subway[214] = CreateDynamicObject(994, 1189.6556, -897.0446, 46.5844, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_subway[215] = CreateDynamicObject(994, 1202.6308, -895.2435, 46.5844, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_subway[216] = CreateDynamicObject(19354, 1203.5366, -912.8839, 45.7447, 35.5998, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_subway[216], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[217] = CreateDynamicObject(19327, 1198.0139, -895.7271, 47.3740, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[217], 0, "way", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[218] = CreateDynamicObject(19354, 1199.7961, -913.4094, 45.7453, -35.5998, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_subway[218], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[219] = CreateDynamicObject(19327, 1201.6601, -913.2393, 47.3740, 0.0000, 0.0000, 8.5000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[219], 0, "Sub", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[220] = CreateDynamicObject(19354, 1201.6761, -913.1458, 46.3512, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_subway[220], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[221] = CreateDynamicObject(19327, 1202.9692, -913.0676, 47.3740, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[221], 0, "way", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[222] = CreateDynamicObject(19327, 1200.3254, -913.4442, 47.1539, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[222], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[223] = CreateDynamicObject(19327, 1200.9870, -913.3416, 47.6039, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[223], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[224] = CreateDynamicObject(19327, 1204.5299, -912.8378, 47.6039, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[224], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[225] = CreateDynamicObject(19327, 1205.1860, -912.7492, 47.1539, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[225], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[226] = CreateDynamicObject(19327, 1204.8581, -912.7932, 47.3739, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[226], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[227] = CreateDynamicObject(19377, 1194.7353, -899.5565, 40.6436, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[227], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[228] = CreateDynamicObject(19377, 1194.9947, -901.4697, 42.3936, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[228], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[229] = CreateDynamicObject(19377, 1195.1883, -902.7841, 40.6436, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[229], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[230] = CreateDynamicObject(19377, 1194.2882, -896.3682, 40.6436, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[230], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[231] = CreateDynamicObject(19377, 1194.9940, -901.4597, 45.8134, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[231], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[232] = CreateDynamicObject(19325, 1189.9770, -900.2489, 43.7859, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[232], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[233] = CreateDynamicObject(19354, 1199.2209, -895.6779, 46.3512, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_subway[233], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[234] = CreateDynamicObject(19354, 1201.0837, -895.4260, 45.7447, 35.5998, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_subway[234], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[235] = CreateDynamicObject(19354, 1197.3415, -895.9508, 45.7453, -35.5998, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_subway[235], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[236] = CreateDynamicObject(19327, 1195.7165, -896.0540, 47.2238, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[236], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[237] = CreateDynamicObject(19327, 1199.3000, -895.5443, 47.3740, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[237], 0, "Sub", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[238] = CreateDynamicObject(19327, 1200.4875, -895.3754, 47.2238, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[238], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[239] = CreateDynamicObject(19327, 1196.3596, -895.9628, 47.7038, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[239], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[240] = CreateDynamicObject(19327, 1199.9244, -895.4552, 47.7038, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[240], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[241] = CreateDynamicObject(19327, 1200.2010, -895.4157, 47.4538, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[241], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[242] = CreateDynamicObject(19327, 1196.0338, -896.0089, 47.4538, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[242], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[243] = CreateDynamicObject(19327, 1200.6595, -913.3862, 47.3638, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[243], 0, ".", 90, "Arial", 80, 1, 0xFFD78E10, 0x0, 0);
    object_subway[244] = CreateDynamicObject(19327, 1200.4670, -913.4458, 43.8339, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[244], 0, "Neuerö", 90, "Arial", 60, 1, 0xFFD78E10, 0x0, 1);
    object_subway[245] = CreateDynamicObject(19327, 1201.9525, -913.2393, 43.8339, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[245], 0, "ffnung", 90, "Arial", 60, 1, 0xFFD78E10, 0x0, 1);
    object_subway[246] = CreateDynamicObject(19430, 1202.5826, -911.3814, 43.8418, 90.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[246], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[247] = CreateDynamicObject(19430, 1201.1474, -913.2567, 43.8418, 90.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[247], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_subway[248] = CreateDynamicObject(19430, 1199.2552, -911.8441, 43.8418, 90.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[248], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[249] = CreateDynamicObject(19430, 1201.0421, -912.5556, 44.5718, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[249], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[250] = CreateDynamicObject(19430, 1201.0421, -912.5556, 43.1119, 0.0000, 90.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[250], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[251] = CreateDynamicObject(19327, 1190.7353, -905.8811, 43.7607, 0.0000, -9.1997, -82.3000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[251], 0, "eat fresh.", 90, "Arial", 40, 1, 0xFF335F3F, 0x0, 0);
    object_subway[252] = CreateDynamicObject(19327, 1190.9117, -907.1821, 43.9734, 0.0000, -9.1997, -82.3000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[252], 0, "TM", 90, "Arial", 20, 1, 0xFF335F3F, 0x0, 0);
    object_subway[253] = CreateDynamicObject(19327, 1210.6164, -912.0051, 43.9435, 0.0000, -9.1997, 8.2999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[253], 0, "TM", 90, "Arial", 20, 1, 0xFF335F3F, 0x0, 0);
    object_subway[254] = CreateDynamicObject(19325, 1209.4073, -897.5233, 43.7859, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[254], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[255] = CreateDynamicObject(19429, 1210.1844, -903.3977, 44.0549, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall069
    SetDynamicObjectMaterial(object_subway[255], 0, 3119, "cs_ry_props", "lightgrey", 0xFF335F3F);
    object_subway[256] = CreateDynamicObject(2720, 1210.8918, -907.7476, 44.1347, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BANNER16
    SetDynamicObjectMaterial(object_subway[256], 0, 2719, "cj_banner3", "CJ_BINC_1", 0xFFFFFFFF);
    object_subway[257] = CreateDynamicObject(19450, 1207.2668, -912.4108, 37.7042, 90.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_subway[257], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[258] = CreateDynamicObject(19450, 1209.7331, -912.0637, 37.7042, 90.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_subway[258], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[259] = CreateDynamicObject(19377, 1205.1302, -901.3870, 40.6440, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[259], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[260] = CreateDynamicObject(19377, 1204.2303, -894.9713, 40.6436, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[260], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[261] = CreateDynamicObject(19377, 1204.6750, -898.1306, 40.6436, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[261], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[262] = CreateDynamicObject(19430, 1203.6103, -887.1574, 40.5787, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[262], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_subway[263] = CreateDynamicObject(19430, 1203.5262, -886.5537, 40.5777, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_subway[263], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[264] = CreateDynamicObject(19377, 1208.6959, -891.9810, 37.1068, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[264], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
    object_subway[265] = CreateDynamicObject(19377, 1200.0821, -900.7446, 45.8125, 0.0000, 90.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_subway[265], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_subway[266] = CreateDynamicObject(17951, 1199.2021, -895.6118, 44.0633, 0.0000, 0.0000, -82.4598, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cjgaragedoor
    SetDynamicObjectMaterial(object_subway[266], 0, 17562, "coast_apts", "ws_garagedoor4_peach", 0xFFFFFFFF);
    object_subway[267] = CreateDynamicObject(19325, 1192.7972, -896.4780, 43.7559, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[267], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[268] = CreateDynamicObject(19325, 1205.6214, -894.6762, 43.7559, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_subway[268], 0, 13724, "docg01_lahills", "sw_mansionwin", 0xFFFFFFFF);
    object_subway[269] = CreateDynamicObject(19327, 1200.5660, -895.3646, 46.1338, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[269], 0, "Lieferanten", 90, "Arial", 56, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[270] = CreateDynamicObject(970, 1190.0173, -891.9556, 42.8969, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[270], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[271] = CreateDynamicObject(19327, 1197.9331, -895.7387, 46.1338, 0.0000, 0.0000, -171.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[271], 0, "-  Einfahrt", 90, "Arial", 56, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[272] = CreateDynamicObject(970, 1189.4498, -896.2376, 42.8969, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[272], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[273] = CreateDynamicObject(1308, 1170.4737, -924.3557, 53.7238, 0.0000, 180.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //telgrphpole02
    SetDynamicObjectMaterial(object_subway[273], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[273], 1, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[273], 2, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[273], 4, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_subway[274] = CreateDynamicObject(19328, 1170.9560, -923.2888, 48.9971, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[274], 0, "D", 100, "Arial", 160, 1, 0xFF335F3F, 0x0, 0);
    object_subway[275] = CreateDynamicObject(19328, 1170.9560, -923.2888, 51.8969, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[275], 0, "L", 100, "Arial", 160, 1, 0xFF335F3F, 0x0, 0);
    object_subway[276] = CreateDynamicObject(19328, 1170.9155, -917.9630, 50.0470, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[276], 0, "P", 100, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[277] = CreateDynamicObject(19328, 1170.4051, -924.1602, 49.2070, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[277], 0, "D", 100, "Arial", 160, 1, 0xFF335F3F, 0x0, 0);
    object_subway[278] = CreateDynamicObject(19328, 1170.4051, -924.1602, 50.8670, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[278], 0, "y", 100, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[279] = CreateDynamicObject(19328, 1170.3570, -918.5272, 49.9971, 0.0000, 0.0000, -70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[279], 0, "P", 100, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[280] = CreateDynamicObject(3532, 1201.8813, -920.8812, 42.3478, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //triadbush
    object_subway[281] = CreateDynamicObject(737, 1205.8553, -920.2827, 42.3548, 0.0000, 0.0000, 9.3999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //aw_streettree3
    object_subway[282] = CreateDynamicObject(970, 1205.6308, -919.3131, 42.8969, 0.0000, 0.0000, 7.8997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_subway[282], 0, 5631, "apartmentalpha", "ws_railing1", 0xFFFFFFFF);
    object_subway[283] = CreateDynamicObject(1257, 1188.3857, -877.2800, 43.2602, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bustopm
    SetDynamicObjectMaterial(object_subway[283], 1, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_subway[284] = CreateDynamicObject(19951, 1169.0151, -881.7910, 40.5559, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign4
    object_subway[285] = CreateDynamicObject(19951, 1169.2397, -880.0213, 40.5559, 0.0000, 0.0000, 51.5000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign4
    object_subway[286] = CreateDynamicObject(747, 1167.3525, -885.9852, 42.1976, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrub_rock3
    object_subway[287] = CreateDynamicObject(747, 1167.8580, -892.7501, 42.1976, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrub_rock3
    object_subway[288] = CreateDynamicObject(747, 1168.4122, -901.5476, 42.1976, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrub_rock3
    object_subway[289] = CreateDynamicObject(747, 1169.0384, -907.6596, 42.1976, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrub_rock3
    object_subway[290] = CreateDynamicObject(1294, 1169.2657, -888.7269, 46.5606, 0.0000, 0.0000, 187.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mlamppost
    object_subway[291] = CreateDynamicObject(1294, 1170.5532, -904.3286, 46.5606, 0.0000, 0.0000, 187.8999, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mlamppost
    object_subway[292] = CreateDynamicObject(19328, 1170.9698, -923.2512, 50.5471, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign03
    SetDynamicObjectMaterialText(object_subway[292], 0, "y", 100, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[293] = CreateDynamicObject(19121, 1203.4155, -885.7517, 42.5321, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_subway[294] = CreateDynamicObject(1308, 1195.1743, -904.3458, 50.9337, 0.0000, 180.0000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //telgrphpole02
    SetDynamicObjectMaterial(object_subway[294], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[294], 1, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[294], 2, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[294], 4, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_subway[295] = CreateDynamicObject(19790, 1195.1081, -904.4744, 50.4561, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube5mx5m
    SetDynamicObjectMaterial(object_subway[295], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
    object_subway[296] = CreateDynamicObject(19327, 1194.4166, -907.1226, 53.1338, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[296], 0, "Sub", 90, "Arial", 150, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[297] = CreateDynamicObject(19327, 1196.7574, -906.8236, 53.1338, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[297], 0, "way", 90, "Arial", 140, 1, 0xFFD78E10, 0x0, 0);
    object_subway[298] = CreateDynamicObject(19327, 1197.7530, -905.1790, 53.1338, 0.0000, 0.0000, 98.1997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[298], 0, "Sub", 90, "Arial", 150, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[299] = CreateDynamicObject(19327, 1197.4145, -902.8239, 53.1338, 0.0000, 0.0000, 98.1997, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[299], 0, "way", 90, "Arial", 140, 1, 0xFFD78E10, 0x0, 0);
    object_subway[300] = CreateDynamicObject(19327, 1195.8403, -901.8220, 53.1338, 0.0000, 0.0000, -172.0001, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[300], 0, "Sub", 90, "Arial", 150, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[301] = CreateDynamicObject(19327, 1193.4344, -902.1605, 53.1338, 0.0000, 0.0000, -172.0001, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[301], 0, "way", 90, "Arial", 140, 1, 0xFFD78E10, 0x0, 0);
    object_subway[302] = CreateDynamicObject(19327, 1192.4720, -903.7396, 53.1338, 0.0000, 0.0000, -82.3001, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[302], 0, "Sub", 90, "Arial", 150, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[303] = CreateDynamicObject(19327, 1192.7956, -906.1276, 53.1338, 0.0000, 0.0000, -82.3001, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[303], 0, "way", 90, "Arial", 140, 1, 0xFFD78E10, 0x0, 0);
    object_subway[304] = CreateDynamicObject(1688, 1204.5483, -908.3073, 47.6856, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit2
    object_subway[305] = CreateDynamicObject(1687, 1203.3028, -899.0557, 47.4906, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit1
    object_subway[306] = CreateDynamicObject(1691, 1203.8740, -903.6812, 47.1086, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit5
    object_subway[307] = CreateDynamicObject(1685, 1205.9687, -888.7216, 43.0466, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //blockpallet
    object_subway[308] = CreateDynamicObject(1685, 1206.2458, -890.6917, 43.0466, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //blockpallet
    object_subway[309] = CreateDynamicObject(1685, 1206.2447, -890.6917, 44.5265, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //blockpallet
    object_subway[310] = CreateDynamicObject(1685, 1206.5726, -893.0087, 44.5368, 0.0000, 0.0000, 98.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //blockpallet
    object_subway[311] = CreateDynamicObject(19327, 1190.6466, -905.1779, 44.4538, 0.0000, 0.0000, -82.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign02
    SetDynamicObjectMaterialText(object_subway[311], 0, "S", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    object_subway[312] = CreateDynamicObject(1825, 1181.1955, -906.6928, 42.3367, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_table_chairs1
    SetDynamicObjectMaterial(object_subway[312], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_subway[312], 2, 2799, "castable", "cl_ashtray", 0xFFFFFFFF);
    object_subway[313] = CreateDynamicObject(1720, 1185.8308, -906.0322, 42.2910, 0.0000, 0.0000, 97.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[314] = CreateDynamicObject(1720, 1187.2967, -907.1926, 42.2910, 0.0000, 0.0000, 188.8000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[315] = CreateDynamicObject(1720, 1188.4655, -905.6439, 42.2910, 0.0000, 0.0000, 279.7000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[316] = CreateDynamicObject(1720, 1184.9179, -901.0606, 42.2910, 0.0000, 0.0000, 97.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[317] = CreateDynamicObject(1720, 1184.2330, -896.1279, 42.2910, 0.0000, 0.0000, 97.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[318] = CreateDynamicObject(1720, 1178.3208, -896.9490, 42.2910, 0.0000, 0.0000, 97.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[319] = CreateDynamicObject(1720, 1179.0072, -901.8919, 42.2910, 0.0000, 0.0000, 97.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[320] = CreateDynamicObject(1720, 1179.6971, -906.8638, 42.2910, 0.0000, 0.0000, 97.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[321] = CreateDynamicObject(1720, 1187.8491, -900.6065, 42.2910, 0.0000, 0.0000, 279.7000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[322] = CreateDynamicObject(1720, 1187.1844, -895.7706, 42.2910, 0.0000, 0.0000, 279.7000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[323] = CreateDynamicObject(1720, 1181.0980, -896.5979, 42.2910, 0.0000, 0.0000, 279.6000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[324] = CreateDynamicObject(1720, 1181.8620, -901.4696, 42.2910, 0.0000, 0.0000, 279.6000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[325] = CreateDynamicObject(1720, 1182.6341, -906.3908, 42.2910, 0.0000, 0.0000, 279.6000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[326] = CreateDynamicObject(1720, 1186.5439, -902.3305, 42.2910, 0.0000, 0.0000, 188.8000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[327] = CreateDynamicObject(1720, 1185.9598, -897.3814, 42.2910, 0.0000, 0.0000, 188.8000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[328] = CreateDynamicObject(1720, 1179.8822, -898.2097, 42.2910, 0.0000, 0.0000, 188.8000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[329] = CreateDynamicObject(1720, 1180.6673, -903.2700, 42.2910, 0.0000, 0.0000, 188.8000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[330] = CreateDynamicObject(1720, 1181.3178, -908.0988, 42.2910, 0.0000, 0.0000, 188.8000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[331] = CreateDynamicObject(1720, 1186.1102, -899.4003, 42.2910, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[332] = CreateDynamicObject(1720, 1185.4929, -894.4476, 42.2910, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[333] = CreateDynamicObject(1720, 1179.4416, -895.2882, 42.2910, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[334] = CreateDynamicObject(1720, 1180.1163, -900.1516, 42.2910, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[335] = CreateDynamicObject(1720, 1180.8321, -905.3024, 42.2910, 0.0000, 0.0000, 7.9000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
    object_subway[336] = CreateDynamicObject(2214, 1187.0278, -906.2078, 43.2845, -22.6998, 16.1998, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //burgermed
    SetDynamicObjectMaterial(object_subway[336], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_subway[337] = CreateDynamicObject(2354, 1180.1446, -901.9141, 43.2929, -29.0998, 23.2000, 0.0000, VW_MAIN, MAPS_SUBWAYEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //burger_healthy
    SetDynamicObjectMaterial(object_subway[337], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
}