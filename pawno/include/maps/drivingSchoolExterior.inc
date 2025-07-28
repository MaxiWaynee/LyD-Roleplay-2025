#include <YSI\y_hooks>

// Global interior define
#define MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR      0
#define MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR      6

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 190.0;

// Map variables
new object_drivingSchoolExterior[235];
new object_drivingSchoolInterior[65];
new fstor[6];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 673, 1200.8828, -1839.1250, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 1215, 1153.1953, -1833.5156, 13.1484, 0.25);
    RemoveBuildingForPlayer(playerid, 1215, 1162.0781, -1829.1406, 13.2109, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1192.8281, -1829.2813, 14.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 1290, 1177.0703, -1828.4063, 18.5781, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1192.6172, -1826.9531, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 1215, 1164.5938, -1782.3594, 13.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 1215, 1190.2891, -1782.2734, 13.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 1215, 1164.5938, -1769.3359, 13.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 1290, 1177.0703, -1767.3359, 18.5781, 0.25);
    RemoveBuildingForPlayer(playerid, 1215, 1190.2891, -1769.3359, 13.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 1290, 1177.0703, -1733.4063, 18.5781, 0.25);
    RemoveBuildingForPlayer(playerid, 1215, 1190.2891, -1754.7891, 13.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 1215, 1190.2891, -1741.2422, 13.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 1798, 1274.4766, -820.8516, 1088.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 1798, 1274.4766, -817.6250, 1088.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 2139, 1281.2656, -817.2891, 1084.6406, 0.25);
    RemoveBuildingForPlayer(playerid, 2307, 1272.4844, -814.8438, 1088.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 1282.8438, -815.8984, 1085.5313, 0.25);
    RemoveBuildingForPlayer(playerid, 14456, 1282.2500, -805.2266, 1093.2344, 0.25);
    RemoveBuildingForPlayer(playerid, 1536, 1260.2188, -783.9141, 1090.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 14401, 1264.6016, -781.0078, 1083.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 14468, 1255.3125, -773.6328, 1083.9531, 0.25);
    RemoveBuildingForPlayer(playerid, 14469, 1275.2188, -777.1563, 1090.5156, 0.25);
    //Entfernte Palmen an der Fahrschule für Landebahn
    RemoveBuildingForPlayer(playerid, 620, 1075.3750, -1826.4766, 12.3516, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1075.3750, -1797.3594, 12.3516, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
    object_drivingSchoolExterior[0] = CreateDynamicObject(0, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Unknown Model
    object_drivingSchoolExterior[1] = CreateDynamicObject(0, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Unknown Model
    object_drivingSchoolExterior[2] = CreateDynamicObject(970, 1259.7359, -1808.7922, 12.8943, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[2], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_drivingSchoolExterior[3] = CreateDynamicObject(970, 1259.7359, -1813.1336, 12.8943, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[3], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_drivingSchoolExterior[4] = CreateDynamicObject(970, 1259.7359, -1817.4937, 12.8943, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[4], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_drivingSchoolExterior[5] = CreateDynamicObject(970, 1259.7359, -1821.8747, 12.8943, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[5], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_drivingSchoolExterior[6] = CreateDynamicObject(974, 1193.2827, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[6], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[6], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[7] = CreateDynamicObject(974, 1164.9870, -1832.2396, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[7], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[7], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[8] = CreateDynamicObject(974, 1164.9870, -1825.6295, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[8], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[8], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[9] = CreateDynamicObject(974, 818.3840, -2973.2854, -42.6559, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    object_drivingSchoolExterior[10] = CreateDynamicObject(970, 1187.8139, -1842.2677, 13.0843, 0.0000, 0.0000, -0.2000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[10], 0, 16093, "a51_ext", "ws_whitewall2_bottom", 0xFFFFFFFF);
    object_drivingSchoolExterior[11] = CreateDynamicObject(974, 1199.9234, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[11], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[11], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[12] = CreateDynamicObject(19124, 1177.9494, -1842.3459, 12.9612, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[13] = CreateDynamicObject(18452, 1247.9366, -1833.7103, 15.3647, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cw_tscanopy01
    SetDynamicObjectMaterial(object_drivingSchoolExterior[13], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[13], 1, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[13], 2, 16322, "a51_stores", "steel64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[13], 3, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_drivingSchoolExterior[14] = CreateDynamicObject(970, 1259.7359, -1800.0998, 12.8943, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[14], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_drivingSchoolExterior[15] = CreateDynamicObject(974, 1284.1109, -1842.3021, 11.6535, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[15], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[15], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[16] = CreateDynamicObject(974, 1203.2956, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[16], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[16], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[17] = CreateDynamicObject(974, 1189.9487, -1838.9384, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[17], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[17], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[18] = CreateDynamicObject(19124, 1189.9676, -1825.4500, 13.1014, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[19] = CreateDynamicObject(19124, 1189.9676, -1821.8596, 13.1014, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[20] = CreateDynamicObject(974, 1189.0726, -1762.5302, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[20], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[20], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[21] = CreateDynamicObject(970, 1167.1036, -1842.1959, 13.0843, 0.0000, 0.0000, -0.2000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[21], 0, 16093, "a51_ext", "ws_whitewall2_bottom", 0xFFFFFFFF);
    object_drivingSchoolExterior[22] = CreateDynamicObject(974, 1164.9870, -1819.0178, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[22], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[22], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[23] = CreateDynamicObject(974, 1195.7528, -1762.5302, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[23], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[23], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[24] = CreateDynamicObject(974, 1164.9870, -1812.4278, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[24], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[24], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[25] = CreateDynamicObject(974, 1202.4234, -1762.5302, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[25], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[25], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[26] = CreateDynamicObject(19124, 1177.1594, -1762.5737, 12.9614, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[27] = CreateDynamicObject(3749, 1213.6767, -1842.3662, 18.2133, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ClubGate01_LAx
    SetDynamicObjectMaterial(object_drivingSchoolExterior[27], 3, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_drivingSchoolExterior[28] = CreateDynamicObject(974, 1165.9484, -1762.5302, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[28], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[28], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[29] = CreateDynamicObject(970, 1259.7359, -1804.4217, 12.8943, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[29], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_drivingSchoolExterior[30] = CreateDynamicObject(974, 818.3840, -2973.2854, -42.6559, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    object_drivingSchoolExterior[31] = CreateDynamicObject(19984, 1219.0903, -1842.7237, 12.6227, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign37
    object_drivingSchoolExterior[32] = CreateDynamicObject(19984, 1208.3004, -1842.7237, 12.6227, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign37
    object_drivingSchoolExterior[33] = CreateDynamicObject(1676, 1248.0852, -1830.9431, 14.0860, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //washgaspump
    object_drivingSchoolExterior[34] = CreateDynamicObject(19987, 1264.6700, -1842.7126, 12.6429, 0.0000, 0.0000, -178.6999, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign40
    object_drivingSchoolExterior[35] = CreateDynamicObject(19984, 1275.4405, -1842.7237, 12.6227, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign37
    object_drivingSchoolExterior[36] = CreateDynamicObject(19987, 1219.1068, -1842.6859, 12.6429, 0.0000, 0.0000, -178.6999, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign40
    object_drivingSchoolExterior[37] = CreateDynamicObject(19126, 1287.1009, -1786.1096, 12.5721, 0.0000, 0.0000, -38.7000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight6
    object_drivingSchoolExterior[38] = CreateDynamicObject(970, 1259.7359, -1795.6993, 12.8943, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_drivingSchoolExterior[38], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_drivingSchoolExterior[39] = CreateDynamicObject(19987, 1208.2946, -1842.7008, 12.6429, 0.0000, 0.0000, -178.6999, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign40
    object_drivingSchoolExterior[40] = CreateDynamicObject(9697, 1198.5810, -1785.4553, 12.4421, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carspaces3_sfw
    object_drivingSchoolExterior[41] = CreateDynamicObject(19984, 1264.6711, -1842.7839, 12.6227, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign37
    object_drivingSchoolExterior[42] = CreateDynamicObject(19987, 1275.4632, -1842.7076, 12.6429, 0.0000, 0.0000, -178.6999, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign40
    object_drivingSchoolExterior[43] = CreateDynamicObject(974, 818.3840, -2973.2854, -42.6559, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    object_drivingSchoolExterior[44] = CreateDynamicObject(9697, 1256.1140, -1771.6031, 12.4421, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carspaces3_sfw
    object_drivingSchoolExterior[45] = CreateDynamicObject(9697, 1239.7945, -1772.3961, 12.4421, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carspaces3_sfw
    object_drivingSchoolExterior[46] = CreateDynamicObject(9697, 1263.4271, -1771.6351, 12.4421, 0.0000, 0.0000, -270.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carspaces3_sfw
    object_drivingSchoolExterior[47] = CreateDynamicObject(8843, 1181.7320, -1823.5599, 12.5432, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    SetDynamicObjectMaterial(object_drivingSchoolExterior[47], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_drivingSchoolExterior[48] = CreateDynamicObject(9697, 1279.1040, -1784.6461, 12.4421, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carspaces3_sfw
    object_drivingSchoolExterior[49] = CreateDynamicObject(8843, 1181.9959, -1773.0427, 12.5432, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    SetDynamicObjectMaterial(object_drivingSchoolExterior[49], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_drivingSchoolExterior[50] = CreateDynamicObject(1290, 1271.2595, -1793.1611, 18.4316, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_drivingSchoolExterior[51] = CreateDynamicObject(1215, 1259.6943, -1793.4686, 12.8837, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[52] = CreateDynamicObject(8843, 1173.0168, -1773.0427, 12.5432, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    SetDynamicObjectMaterial(object_drivingSchoolExterior[52], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_drivingSchoolExterior[53] = CreateDynamicObject(8843, 1247.9365, -1833.9924, 12.4252, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    SetDynamicObjectMaterial(object_drivingSchoolExterior[53], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_drivingSchoolExterior[54] = CreateDynamicObject(19124, 1233.5588, -1792.7668, 33.1837, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[55] = CreateDynamicObject(8843, 1172.9090, -1823.5599, 12.5432, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    SetDynamicObjectMaterial(object_drivingSchoolExterior[55], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_drivingSchoolExterior[56] = CreateDynamicObject(1290, 1177.3875, -1776.7447, 18.4316, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_drivingSchoolExterior[57] = CreateDynamicObject(4100, 1233.7348, -1793.7651, 33.3456, 0.0000, 0.0000, 50.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //meshfence1_LAn
    object_drivingSchoolExterior[58] = CreateDynamicObject(19124, 1227.0793, -1792.7884, 32.5512, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[59] = CreateDynamicObject(19124, 1233.5588, -1795.0764, 33.1837, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[60] = CreateDynamicObject(19124, 1217.8286, -1792.8061, 32.5512, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[61] = CreateDynamicObject(2942, 1225.3293, -1811.6839, 16.2460, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_drivingSchoolExterior[62] = CreateDynamicObject(19124, 1233.5588, -1797.4738, 33.1837, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[63] = CreateDynamicObject(19124, 1208.8374, -1792.8593, 32.5512, 0.0000, 0.0000, 15.8400, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[64] = CreateDynamicObject(19124, 1233.5588, -1799.9310, 33.1837, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[65] = CreateDynamicObject(4100, 1233.7423, -1800.6140, 33.3055, 0.0000, 0.0000, 50.2999, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //meshfence1_LAn
    object_drivingSchoolExterior[66] = CreateDynamicObject(19124, 1199.6179, -1792.7871, 32.5512, 0.0000, 0.0000, 15.8400, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[67] = CreateDynamicObject(974, 1280.7899, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[67], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[67], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[68] = CreateDynamicObject(19124, 1233.5588, -1802.2043, 33.1837, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[69] = CreateDynamicObject(974, 1287.4516, -1838.9304, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[69], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[69], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[70] = CreateDynamicObject(19124, 1227.0793, -1802.1887, 32.5512, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[71] = CreateDynamicObject(1215, 1186.6926, -1792.4996, 13.1014, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[72] = CreateDynamicObject(19124, 1188.6964, -1792.8131, 32.5512, 0.0000, 0.0000, 16.1399, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[73] = CreateDynamicObject(19124, 1217.8286, -1802.1712, 32.5512, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[74] = CreateDynamicObject(974, 1287.4516, -1832.2884, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[74], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[74], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[75] = CreateDynamicObject(19124, 1208.8374, -1802.1571, 32.5512, 0.0000, 0.0000, 15.8400, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[76] = CreateDynamicObject(647, 1284.9572, -1810.1490, 14.1086, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //new_bushsm
    object_drivingSchoolExterior[77] = CreateDynamicObject(19124, 1176.9549, -1792.7851, 32.5512, 0.0000, 0.0000, 8.7600, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[78] = CreateDynamicObject(974, 1287.4516, -1825.6270, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[78], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[78], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[79] = CreateDynamicObject(19124, 1199.6179, -1802.1767, 32.5512, 0.0000, 0.0000, 15.8400, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[80] = CreateDynamicObject(974, 1287.4516, -1818.9770, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[80], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[80], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[81] = CreateDynamicObject(647, 1285.1203, -1815.5467, 14.1086, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //new_bushsm
    object_drivingSchoolExterior[82] = CreateDynamicObject(19124, 1188.6964, -1802.1661, 32.5512, 0.0000, 0.0000, 15.8400, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[83] = CreateDynamicObject(974, 1287.4516, -1805.7263, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[83], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[83], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[84] = CreateDynamicObject(1215, 1186.9450, -1802.5191, 13.1014, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[85] = CreateDynamicObject(19124, 1165.1806, -1792.8142, 32.5512, 0.0000, 0.0000, 8.7600, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[86] = CreateDynamicObject(18766, 1226.3337, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[86], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[87] = CreateDynamicObject(974, 1287.4516, -1812.3465, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[87], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[87], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[88] = CreateDynamicObject(19124, 1176.9549, -1802.1805, 32.5512, 0.0000, 0.0000, 15.8400, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[89] = CreateDynamicObject(974, 1287.4516, -1799.0750, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[89], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[89], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[90] = CreateDynamicObject(19124, 1153.5407, -1792.8037, 32.5512, 0.0000, 0.0000, 8.7600, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[91] = CreateDynamicObject(1215, 1259.7409, -1824.1324, 12.8837, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[92] = CreateDynamicObject(19124, 1165.1806, -1802.1654, 32.5512, 0.0000, 0.0000, 15.8400, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[93] = CreateDynamicObject(19124, 1143.7369, -1792.7937, 32.5512, 0.0000, 0.0000, 8.7600, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[94] = CreateDynamicObject(19124, 1153.5407, -1802.1456, 32.5512, 0.0000, 0.0000, 15.8400, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[95] = CreateDynamicObject(1290, 1204.2037, -1823.4167, 18.4316, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_drivingSchoolExterior[96] = CreateDynamicObject(1215, 1249.5295, -1830.9892, 13.1457, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[97] = CreateDynamicObject(974, 1287.4516, -1792.4138, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[97], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[97], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[98] = CreateDynamicObject(1215, 1246.3138, -1830.9162, 13.1457, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[99] = CreateDynamicObject(717, 1186.8243, -1818.4055, 12.7272, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_drivingSchoolExterior[100] = CreateDynamicObject(19124, 1134.5069, -1792.8089, 32.5512, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[101] = CreateDynamicObject(647, 1284.9304, -1832.9377, 14.1086, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //new_bushsm
    object_drivingSchoolExterior[102] = CreateDynamicObject(974, 1287.4516, -1789.0914, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[102], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[102], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[103] = CreateDynamicObject(974, 1284.0693, -1785.7138, 11.6535, 0.0000, 0.0000, -0.8999, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[103], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[103], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[104] = CreateDynamicObject(19124, 1143.7369, -1802.1762, 32.5512, 0.0000, 0.0000, 8.7600, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[105] = CreateDynamicObject(1676, 1247.9240, -1836.4239, 14.0860, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //washgaspump
    object_drivingSchoolExterior[106] = CreateDynamicObject(1215, 1249.3319, -1836.5417, 13.1457, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[107] = CreateDynamicObject(1215, 1246.3847, -1836.4782, 13.1457, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[108] = CreateDynamicObject(19124, 1125.3315, -1792.7894, 32.5512, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[109] = CreateDynamicObject(974, 1277.3786, -1785.5371, 11.6535, 0.0000, 0.0000, -2.0999, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[109], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[109], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[110] = CreateDynamicObject(1290, 1241.8175, -1837.6457, 18.4316, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_drivingSchoolExterior[111] = CreateDynamicObject(1290, 1177.4470, -1822.8154, 18.4316, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_drivingSchoolExterior[112] = CreateDynamicObject(647, 1253.7469, -1839.4345, 14.1086, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //new_bushsm
    object_drivingSchoolExterior[113] = CreateDynamicObject(717, 1167.6290, -1819.4409, 12.7272, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_drivingSchoolExterior[114] = CreateDynamicObject(19124, 1263.9771, -1840.0577, 13.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[115] = CreateDynamicObject(19124, 1275.9294, -1840.0985, 13.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[116] = CreateDynamicObject(19124, 1134.0540, -1802.2257, 32.5511, 0.0000, 0.0000, 0.1199, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[117] = CreateDynamicObject(19452, 1284.8293, -1788.4184, 14.8914, 90.0000, 49.5999, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall092
    SetDynamicObjectMaterial(object_drivingSchoolExterior[117], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_drivingSchoolExterior[118] = CreateDynamicObject(647, 1230.7231, -1839.3220, 14.1086, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //new_bushsm
    object_drivingSchoolExterior[119] = CreateDynamicObject(647, 1192.7949, -1831.1947, 14.0703, 356.8583, 0.0000, -0.1045, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //new_bushsm
    object_drivingSchoolExterior[120] = CreateDynamicObject(19974, 1283.8526, -1787.4466, 17.3708, 90.0000, 49.7999, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign27
    SetDynamicObjectMaterial(object_drivingSchoolExterior[120], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[120], 1, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[120], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_drivingSchoolExterior[121] = CreateDynamicObject(19124, 1275.9194, -1844.5987, 13.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[122] = CreateDynamicObject(19124, 1264.0362, -1844.5888, 13.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[123] = CreateDynamicObject(19124, 1219.6136, -1840.1519, 13.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[124] = CreateDynamicObject(19172, 1284.7983, -1788.2867, 17.6828, 0.0000, 0.0000, 139.7998, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[124], 0, "o",90, "Webdings", 70, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[124], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[125] = CreateDynamicObject(19124, 1219.5902, -1844.5925, 13.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[126] = CreateDynamicObject(19124, 1207.7043, -1840.1401, 13.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[127] = CreateDynamicObject(717, 1193.0256, -1835.3394, 12.7272, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_drivingSchoolExterior[128] = CreateDynamicObject(717, 1186.9779, -1833.1870, 12.7272, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_drivingSchoolExterior[129] = CreateDynamicObject(647, 1200.1101, -1839.8319, 14.0581, 356.8583, 0.0000, -0.1045, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //new_bushsm
    object_drivingSchoolExterior[130] = CreateDynamicObject(19124, 1207.7331, -1844.6147, 13.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[131] = CreateDynamicObject(974, 818.3840, -2973.2854, -42.6559, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    object_drivingSchoolExterior[132] = CreateDynamicObject(717, 1167.8885, -1832.3293, 12.7272, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_drivingSchoolExterior[133] = CreateDynamicObject(19453, 1138.9245, -1808.9984, 32.5494, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_drivingSchoolExterior[133], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[134] = CreateDynamicObject(19453, 1138.9245, -1812.4791, 32.5494, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_drivingSchoolExterior[134], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[135] = CreateDynamicObject(19124, 1126.2724, -1802.1734, 32.5511, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[136] = CreateDynamicObject(19453, 1138.9245, -1815.9508, 32.5494, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_drivingSchoolExterior[136], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[137] = CreateDynamicObject(19453, 1138.9245, -1819.4403, 32.5494, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_drivingSchoolExterior[137], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[138] = CreateDynamicObject(19124, 1116.1787, -1792.8155, 32.5512, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[139] = CreateDynamicObject(19898, 1136.0948, -1819.1103, 32.7187, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //OilFloorStain1
    object_drivingSchoolExterior[140] = CreateDynamicObject(19124, 1117.1795, -1802.1778, 32.5511, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[141] = CreateDynamicObject(19453, 1138.9245, -1822.9306, 32.5494, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_drivingSchoolExterior[141], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[142] = CreateDynamicObject(19453, 1138.9245, -1826.4112, 32.5494, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_drivingSchoolExterior[142], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[143] = CreateDynamicObject(18766, 1231.3039, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[143], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[144] = CreateDynamicObject(18766, 1221.3541, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[144], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[145] = CreateDynamicObject(18766, 1186.6944, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[145], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[146] = CreateDynamicObject(18766, 1216.3739, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[146], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[147] = CreateDynamicObject(18766, 1211.3939, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[147], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[148] = CreateDynamicObject(1324, 1066.3000, -2289.6999, 13.6000, 0.0000, 0.0000, 298.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_roadwarning_04
    object_drivingSchoolExterior[149] = CreateDynamicObject(2942, 1585.6999, -2286.6000, 13.1998, 0.0000, 0.0000, 269.9887, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_drivingSchoolExterior[150] = CreateDynamicObject(1324, 1043.6999, -2302.0000, 13.6000, 0.0000, 0.0000, 118.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_roadwarning_04
    object_drivingSchoolExterior[151] = CreateDynamicObject(18766, 1206.4044, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[151], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[152] = CreateDynamicObject(19124, 1177.9494, -1762.5737, 12.9612, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[153] = CreateDynamicObject(966, 1169.5295, -1762.5439, 12.3936, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebar01
    object_drivingSchoolExterior[154] = CreateDynamicObject(19124, 1162.3537, -1762.5040, 12.9614, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_drivingSchoolExterior[155] = CreateDynamicObject(1290, 1177.4384, -1744.4925, 18.4316, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_drivingSchoolExterior[156] = CreateDynamicObject(19172, 1284.7906, -1788.2802, 18.2329, 0.0000, 0.0000, 139.7998, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[156], 0, "Los Santos", 90, "Georgia", 50, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[156], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[157] = CreateDynamicObject(19974, 1283.8526, -1787.4466, 16.6208, 90.0000, 49.7999, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign27
    SetDynamicObjectMaterial(object_drivingSchoolExterior[157], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[157], 1, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[157], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_drivingSchoolExterior[158] = CreateDynamicObject(19974, 1283.8526, -1787.4466, 18.3708, 90.0000, 49.7999, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign27
    SetDynamicObjectMaterial(object_drivingSchoolExterior[158], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[158], 1, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[158], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_drivingSchoolExterior[159] = CreateDynamicObject(19974, 1283.8526, -1787.4466, 19.0508, 90.0000, 49.7999, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign27
    SetDynamicObjectMaterial(object_drivingSchoolExterior[159], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[159], 1, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[159], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_drivingSchoolExterior[160] = CreateDynamicObject(974, 1256.7888, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[160], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[160], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[161] = CreateDynamicObject(974, 1243.4970, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[161], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[161], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[162] = CreateDynamicObject(974, 1250.1480, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[162], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[162], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[163] = CreateDynamicObject(974, 1223.5645, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[163], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[163], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[164] = CreateDynamicObject(974, 1236.8465, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[164], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[164], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[165] = CreateDynamicObject(974, 1230.1855, -1842.3021, 11.6635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[165], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[165], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[166] = CreateDynamicObject(19126, 1287.1009, -1786.1096, 12.5721, 0.0000, 0.0000, -38.7000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight6
    object_drivingSchoolExterior[167] = CreateDynamicObject(974, 1189.9487, -1832.3375, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[167], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[167], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[168] = CreateDynamicObject(19172, 1283.4112, -1787.0877, 17.5228, 0.0000, 0.0000, 139.7998, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[168], 0, "v", 90, "Webdings", 70, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[168], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[169] = CreateDynamicObject(974, 1189.9487, -1828.9764, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[169], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[169], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[170] = CreateDynamicObject(974, 1189.9487, -1818.3260, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[170], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[170], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[171] = CreateDynamicObject(974, 1189.9487, -1811.7446, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[171], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[171], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[172] = CreateDynamicObject(974, 1164.9870, -1838.9002, 11.6535, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_drivingSchoolExterior[172], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[172], 1, 4829, "airport_las", "fencekb_64h", 0xFFFFFFFF);
    object_drivingSchoolExterior[173] = CreateDynamicObject(19172, 1138.7553, -1828.4327, 35.0203, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[173], 0, "j", 90, "Webdings", 100, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[173], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[174] = CreateDynamicObject(18766, 1201.4442, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[174], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[175] = CreateDynamicObject(966, 1169.5296, -1842.3459, 12.3936, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebar01
    object_drivingSchoolExterior[176] = CreateDynamicObject(18766, 1196.4738, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[176], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[177] = CreateDynamicObject(18766, 1191.5832, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[177], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[178] = CreateDynamicObject(18766, 1176.8543, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[178], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[179] = CreateDynamicObject(18766, 1181.8244, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[179], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[180] = CreateDynamicObject(18766, 1171.9443, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[180], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[181] = CreateDynamicObject(18766, 1166.9841, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[181], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[182] = CreateDynamicObject(18766, 1152.1225, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[182], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[183] = CreateDynamicObject(18766, 1162.0537, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[183], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[184] = CreateDynamicObject(18766, 1157.0931, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[184], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[185] = CreateDynamicObject(18766, 1127.4229, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[185], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[186] = CreateDynamicObject(18766, 1147.1925, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[186], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[187] = CreateDynamicObject(18766, 1142.2330, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[187], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[188] = CreateDynamicObject(18766, 1137.3028, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[188], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[189] = CreateDynamicObject(18766, 1132.3631, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[189], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[190] = CreateDynamicObject(19455, 1143.8160, -1823.0031, 31.2675, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
    SetDynamicObjectMaterial(object_drivingSchoolExterior[190], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_drivingSchoolExterior[191] = CreateDynamicObject(18766, 1122.4626, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[191], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[192] = CreateDynamicObject(18766, 1117.5731, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[192], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[193] = CreateDynamicObject(19455, 1143.8160, -1812.4238, 31.2675, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
    SetDynamicObjectMaterial(object_drivingSchoolExterior[193], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_drivingSchoolExterior[194] = CreateDynamicObject(18766, 1114.8026, -1797.3830, 32.1437, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_drivingSchoolExterior[194], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[195] = CreateDynamicObject(19357, 1143.8330, -1805.0841, 31.2478, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall005
    SetDynamicObjectMaterial(object_drivingSchoolExterior[195], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_drivingSchoolExterior[196] = CreateDynamicObject(19357, 1134.0096, -1805.0841, 31.2478, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall005
    SetDynamicObjectMaterial(object_drivingSchoolExterior[196], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_drivingSchoolExterior[197] = CreateDynamicObject(1215, 1143.7945, -1817.4370, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[198] = CreateDynamicObject(1215, 1143.7945, -1818.0274, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[199] = CreateDynamicObject(1215, 1143.7945, -1828.0074, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[200] = CreateDynamicObject(19455, 1134.0141, -1823.0031, 31.2675, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
    SetDynamicObjectMaterial(object_drivingSchoolExterior[200], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_drivingSchoolExterior[201] = CreateDynamicObject(1215, 1133.9952, -1828.0074, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[202] = CreateDynamicObject(19455, 1134.0147, -1812.4238, 31.2675, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
    SetDynamicObjectMaterial(object_drivingSchoolExterior[202], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_drivingSchoolExterior[203] = CreateDynamicObject(1215, 1134.0014, -1818.0274, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[204] = CreateDynamicObject(1215, 1134.0014, -1817.4068, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[205] = CreateDynamicObject(19898, 1140.5456, -1819.1103, 32.7187, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //OilFloorStain1
    object_drivingSchoolExterior[206] = CreateDynamicObject(19898, 1138.6148, -1821.4207, 32.7187, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //OilFloorStain1
    object_drivingSchoolExterior[207] = CreateDynamicObject(19453, 1138.9245, -1805.4980, 32.5494, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_drivingSchoolExterior[207], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[208] = CreateDynamicObject(19453, 1138.9245, -1801.9968, 32.5494, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_drivingSchoolExterior[208], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_drivingSchoolExterior[209] = CreateDynamicObject(19455, 1138.9039, -1828.2138, 31.2675, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
    SetDynamicObjectMaterial(object_drivingSchoolExterior[209], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_drivingSchoolExterior[210] = CreateDynamicObject(19172, 1137.5855, -1828.4327, 34.7703, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[210], 0, "Repair", 90, "Georgia", 50, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[210], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[211] = CreateDynamicObject(1676, 1142.3044, -1827.4027, 34.1161, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //washgaspump
    object_drivingSchoolExterior[212] = CreateDynamicObject(19903, 1138.6478, -1827.5522, 32.6525, 0.0000, 0.0000, 89.8000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
    object_drivingSchoolExterior[213] = CreateDynamicObject(19355, 1138.7052, -1828.5362, 34.2514, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
    SetDynamicObjectMaterial(object_drivingSchoolExterior[213], 0, 14652, "ab_trukstpa", "mp_diner_wood", 0xFFFFFFFF);
    object_drivingSchoolExterior[214] = CreateDynamicObject(1676, 1135.2442, -1827.4027, 34.1161, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //washgaspump
    object_drivingSchoolExterior[215] = CreateDynamicObject(19172, 1217.6955, -1811.3514, 19.2840, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[215], 0, "Fahr", 90, "Georgia", 70, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[215], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[216] = CreateDynamicObject(1215, 1143.7945, -1807.1668, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[217] = CreateDynamicObject(1215, 1133.9742, -1807.1668, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[218] = CreateDynamicObject(1215, 1133.9742, -1803.2163, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[219] = CreateDynamicObject(1215, 1143.8260, -1803.2163, 33.1645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_drivingSchoolExterior[220] = CreateDynamicObject(3749, 1269.9771, -1842.3492, 18.2133, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ClubGate01_LAx
    SetDynamicObjectMaterial(object_drivingSchoolExterior[220], 3, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_drivingSchoolExterior[221] = CreateDynamicObject(19172, 1219.2866, -1811.3514, 19.2840, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[221], 0, "schule", 90, "Georgia", 70, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[221], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[222] = CreateDynamicObject(19172, 1221.2265, -1811.3514, 20.2740, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[222], 0, "j", 90, "Webdings", 150, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[222], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[223] = CreateDynamicObject(19172, 1284.8289, -1788.3126, 16.5828, 0.0000, 0.0000, 139.7998, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[223], 0, "Fahrschule", 90, "Georgia", 50, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[223], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[224] = CreateDynamicObject(19126, 1287.1009, -1786.1096, 12.5721, 0.0000, 0.0000, -38.7000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight6
    object_drivingSchoolExterior[225] = CreateDynamicObject(19172, 1284.1007, -1787.6700, 17.5228, 0.0000, 0.0000, 139.7998, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_drivingSchoolExterior[225], 0, "j", 90, "Webdings", 70, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_drivingSchoolExterior[225], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_drivingSchoolExterior[226] = CreateDynamicObject(966, 1185.3535, -1762.5439, 12.3936, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebar01
    object_drivingSchoolExterior[227] = CreateDynamicObject(966, 1185.3535, -1842.3459, 12.3936, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebar01
    object_drivingSchoolExterior[228] = CreateDynamicObject(19124, 1177.1594, -1842.3459, 12.9614, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4

    // Tore
    fstor[0] = object_drivingSchoolExterior[229] = CreateDynamicObject(968, 1185.3404, -1842.3459, 13.1983, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    fstor[1] = object_drivingSchoolExterior[230] = CreateDynamicObject(968, 1185.3404, -1762.5439, 13.1983, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    fstor[2] = object_drivingSchoolExterior[231] = CreateDynamicObject(968, 1169.5295, -1762.5439, 13.1983, 0.0000, -90.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    fstor[3] = object_drivingSchoolExterior[232] = CreateDynamicObject(968, 1169.5295, -1842.3459, 13.1983, 0.0000, -90.0000, 180.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    fstor[4] = object_drivingSchoolExterior[233] = CreateDynamicObject(984, 1213.4050, -1842.1458, 13.0299, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    fstor[5] = object_drivingSchoolExterior[234] = CreateDynamicObject(984, 1270.3653, -1842.2629, 13.0299, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_DRIVINGSCHOOLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);


















    //Schiessstand in Fahrschule
    object_drivingSchoolInterior[0] = CreateDynamicObject(1586, 298.68085, -142.06290, 998.57440, -0.02000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[1] = CreateDynamicObject(3018, 293.17230, -161.02029, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[2] = CreateDynamicObject(3019, 293.17230, -161.03600, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[3] = CreateDynamicObject(3020, 293.17230, -161.03630, 1002.21912, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[4] = CreateDynamicObject(3021, 293.17230, -161.02020, 1002.21381, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[5] = CreateDynamicObject(3024, 288.17230, -161.03200, 1002.20892, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[6] = CreateDynamicObject(3023, 293.17230, -161.03430, 1002.21301, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[7] = CreateDynamicObject(3022, 293.17230, -161.02690, 1002.20709, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[8] = CreateDynamicObject(3018, 293.17230, -162.65990, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[9] = CreateDynamicObject(3019, 293.17230, -162.66040, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[10] = CreateDynamicObject(3021, 293.17230, -162.65829, 1002.21381, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[11] = CreateDynamicObject(3020, 293.17230, -162.66110, 1002.21912, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[12] = CreateDynamicObject(3023, 293.17230, -162.65910, 1002.21100, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[13] = CreateDynamicObject(3024, 293.17230, -162.65430, 1002.21490, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[14] = CreateDynamicObject(3022, 293.17230, -162.65210, 1002.21509, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[15] = CreateDynamicObject(3018, 293.17233, -166.75284, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[16] = CreateDynamicObject(3019, 293.17230, -166.75410, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[17] = CreateDynamicObject(3021, 293.17230, -166.75470, 1002.21381, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[18] = CreateDynamicObject(3020, 293.17230, -166.75639, 1002.21912, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[19] = CreateDynamicObject(3023, 293.17230, -166.75710, 1002.21100, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[20] = CreateDynamicObject(3022, 293.17230, -166.75369, 1002.21307, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[21] = CreateDynamicObject(3024, 293.17230, -166.75191, 1002.21692, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[22] = CreateDynamicObject(3018, 293.17230, -164.55380, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[23] = CreateDynamicObject(3019, 293.17230, -164.55510, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[24] = CreateDynamicObject(3021, 293.17230, -164.55569, 1002.21381, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[25] = CreateDynamicObject(3020, 293.17230, -164.55530, 1002.21912, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[26] = CreateDynamicObject(3022, 293.17230, -164.55470, 1002.21307, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[27] = CreateDynamicObject(3023, 293.17230, -164.55800, 1002.21100, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[28] = CreateDynamicObject(3024, 293.17230, -164.55690, 1002.20093, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[29] = CreateDynamicObject(3018, 288.17233, -166.76047, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[30] = CreateDynamicObject(3019, 288.17230, -166.76210, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[31] = CreateDynamicObject(3021, 288.17230, -166.76260, 1002.21381, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[32] = CreateDynamicObject(3020, 288.17230, -166.76430, 1002.21912, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[33] = CreateDynamicObject(3023, 288.17230, -166.79510, 1002.21100, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[34] = CreateDynamicObject(3022, 288.17230, -166.79170, 1002.21307, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[35] = CreateDynamicObject(3024, 288.17230, -166.78990, 1002.21692, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[36] = CreateDynamicObject(3018, 288.17230, -164.55380, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[37] = CreateDynamicObject(3019, 288.17230, -164.55510, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[38] = CreateDynamicObject(3021, 288.17230, -164.55569, 1002.21381, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[39] = CreateDynamicObject(3020, 288.17230, -164.55530, 1002.21912, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[40] = CreateDynamicObject(3022, 288.17230, -164.55470, 1002.21307, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[41] = CreateDynamicObject(3023, 288.17230, -164.55800, 1002.21100, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[42] = CreateDynamicObject(3024, 288.17230, -164.55690, 1002.20093, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[43] = CreateDynamicObject(3018, 288.17230, -162.65990, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[44] = CreateDynamicObject(3019, 288.17230, -162.66040, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[45] = CreateDynamicObject(3020, 288.17230, -162.66110, 1002.21912, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[46] = CreateDynamicObject(3021, 288.17230, -162.65829, 1002.21381, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[47] = CreateDynamicObject(3023, 288.17230, -162.65910, 1002.21100, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[48] = CreateDynamicObject(3024, 288.17230, -162.65430, 1002.21490, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[49] = CreateDynamicObject(3022, 288.17230, -162.65210, 1002.21509, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[50] = CreateDynamicObject(3018, 288.17230, -161.02029, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[51] = CreateDynamicObject(3019, 288.17230, -161.03600, 1002.22028, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[52] = CreateDynamicObject(3021, 288.17230, -161.02020, 1002.21381, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[53] = CreateDynamicObject(3020, 288.17230, -161.03630, 1002.21912, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[54] = CreateDynamicObject(3023, 288.17230, -161.03430, 1002.21301, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[55] = CreateDynamicObject(3022, 288.17230, -161.02690, 1002.20709, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[56] = CreateDynamicObject(3024, 293.17230, -161.03200, 1002.20892, 0.00000, 0.00000, 90.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[57] = CreateDynamicObject(1215, 298.24203, -170.25116, 999.14551, 0.00000, 0.00000, 0.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[58] = CreateDynamicObject(1215, 272.94196, -170.26842, 999.14551, 0.00000, 0.00000, 0.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[59] = CreateDynamicObject(1215, 272.94199, -158.56680, 999.14551, 0.00000, 0.00000, 0.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[60] = CreateDynamicObject(1215, 298.24200, -158.55589, 999.14551, 0.00000, 0.00000, 0.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[61] = CreateDynamicObject(1215, 286.42758, -170.30922, 999.14551, 0.00000, 0.00000, 0.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[62] = CreateDynamicObject(1215, 286.42761, -158.55820, 999.14551, 0.00000, 0.00000, 0.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[63] = CreateDynamicObject(1215, 299.08359, -170.28430, 999.14551, 0.00000, 0.00000, 0.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_drivingSchoolInterior[64] = CreateDynamicObject(1215, 299.08356, -158.59465, 999.14551, 0.00000, 0.00000, 0.00000, -1, MAPS_DRIVINGSCHOOLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}