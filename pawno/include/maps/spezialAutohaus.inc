#include <YSI\y_hooks>

// Global interior define
#define MAPS_SPEZIALAUTOHAUS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 250.0;
static Float:DRAWDISTANCE   = 230.0;

// Map variables
new object_spezialAutohaus[39];


hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 10008, -1671.0899, 1214.6600, 10.9687, 0.10); // fer_cars2_sfe
    RemoveBuildingForPlayer(playerid, 10009, -1670.7500, 1214.6999, 16.9531, 0.10); // fer_cars3_sfe
    RemoveBuildingForPlayer(playerid, 9953, -1668.8399, 1215.7500, 19.2266, 0.10); // ottos_AUTOS_sfe
    RemoveBuildingForPlayer(playerid, 10107, -1668.8399, 1215.7500, 19.2266, 0.10); // LOD Model of ottos_AUTOS_sfe
    RemoveBuildingForPlayer(playerid, 3858, -1654.5500, 1219.4599, 7.5312, 0.10); // ottosmash1
    RemoveBuildingForPlayer(playerid, 3858, -1654.4200, 1219.5899, 15.5859, 0.10); // ottosmash1
    RemoveBuildingForPlayer(playerid, 3858, -1654.4200, 1219.5899, 23.0625, 0.10); // ottosmash1
    RemoveBuildingForPlayer(playerid, 3857, -1645.3100, 1210.4899, 15.5859, 0.10); // ottosmash3
    RemoveBuildingForPlayer(playerid, 3857, -1645.3100, 1210.4899, 23.0625, 0.10); // ottosmash3
    RemoveBuildingForPlayer(playerid, 3857, -1645.4399, 1210.3599, 7.5312, 0.10); // ottosmash3
    RemoveBuildingForPlayer(playerid, 3859, -1642.7099, 1204.0500, 15.5859, 0.10); // ottosmash04
    RemoveBuildingForPlayer(playerid, 3859, -1642.7099, 1204.0500, 23.0625, 0.10); // ottosmash04
}

hook OnGameModeInit() {	
	// Objects
    object_spezialAutohaus[0] = CreateDynamicObject(10008, -1671.0904, 1214.4624, 10.9496, 0.0000, 0.0000, -0.1999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fer_cars2_sfe
    SetDynamicObjectMaterial(object_spezialAutohaus[0], 0, 14629, "ab_chande", "ab_goldpipe", 0x00000000);
    object_spezialAutohaus[1] = CreateDynamicObject(984, -1646.3322, 1218.0843, 6.8032, 0.0000, 0.0000, 45.0999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit2
    object_spezialAutohaus[2] = CreateDynamicObject(10009, -1670.6496, 1214.6632, 16.9238, 0.0000, 0.0000, -0.5000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fer_cars3_sfe
    SetDynamicObjectMaterial(object_spezialAutohaus[2], 0, 14629, "ab_chande", "ab_goldpipe", 0x00000000);
    object_spezialAutohaus[3] = CreateDynamicObject(3858, -1654.7221, 1219.2988, 22.8890, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    object_spezialAutohaus[4] = CreateDynamicObject(18762, -1654.8060, 1220.1018, 30.8275, -89.9999, -3.0999, 41.9999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[4], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[5] = CreateDynamicObject(18762, -1667.9991, 1200.8480, 27.4733, 0.0000, 90.6000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[5], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[6] = CreateDynamicObject(3858, -1654.2517, 1219.4089, 8.8390, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_spezialAutohaus[6], 0, 4887, "downtown_las", "ws_glassnbrassdoor", 0x00000000);
    object_spezialAutohaus[7] = CreateDynamicObject(1361, -1648.0584, 1214.1732, 6.8865, 0.0000, 0.0000, -39.2999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP2
    object_spezialAutohaus[8] = CreateDynamicObject(983, -1653.0932, 1224.8890, 6.8490, 0.0000, 0.0000, 44.3999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    object_spezialAutohaus[9] = CreateDynamicObject(18762, -1663.0269, 1200.8480, 27.4212, 0.0000, 90.6000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[9], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[10] = CreateDynamicObject(18762, -1651.6481, 1216.9539, 30.8275, -89.9999, -3.0999, 41.9999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[10], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[11] = CreateDynamicObject(18762, -1650.9331, 1216.2412, 30.8275, -89.9999, -3.0999, 41.9999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[11], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[12] = CreateDynamicObject(18762, -1656.8945, 1222.1849, 30.8475, -89.9999, -3.0999, 41.9999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[12], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[13] = CreateDynamicObject(14705, -1654.4039, 1207.0866, 7.3135, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int2Vase
    object_spezialAutohaus[14] = CreateDynamicObject(18762, -1661.0855, 1200.8480, 27.4008, 0.0000, 90.6000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[14], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[15] = CreateDynamicObject(18762, -1661.0754, 1200.8480, 28.2608, 0.0000, 90.6000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[15], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[16] = CreateDynamicObject(18762, -1665.9783, 1200.8480, 28.3122, 0.0000, 90.6000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[16], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[17] = CreateDynamicObject(18762, -1672.8999, 1200.8480, 27.5246, 0.0000, 90.6000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[17], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[18] = CreateDynamicObject(18762, -1670.7598, 1200.8480, 28.3623, 0.0000, 90.6000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[18], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[19] = CreateDynamicObject(18762, -1672.8813, 1200.8480, 28.3845, 0.0000, 90.6000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[19], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[20] = CreateDynamicObject(984, -1637.2808, 1209.0637, 6.8032, 0.0000, 0.0000, 45.0999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit2
    object_spezialAutohaus[21] = CreateDynamicObject(2001, -1643.0279, 1201.3082, 6.1990, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    object_spezialAutohaus[22] = CreateDynamicObject(2001, -1641.7280, 1206.7485, 6.2090, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    object_spezialAutohaus[23] = CreateDynamicObject(1361, -1658.9770, 1225.0996, 6.9065, 0.0000, 0.0000, -39.2999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP2
    object_spezialAutohaus[24] = CreateDynamicObject(3858, -1654.7521, 1219.4089, 15.5290, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_spezialAutohaus[24], 0, 4887, "downtown_las", "ws_glassnbrassdoor", 0x00000000);
    object_spezialAutohaus[25] = CreateDynamicObject(18762, -1654.4023, 1219.7006, 30.1675, -89.9999, -3.0999, 41.9999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[25], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[26] = CreateDynamicObject(18762, -1650.9331, 1216.2412, 30.1675, -89.9999, -3.0999, 41.9999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[26], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[27] = CreateDynamicObject(18762, -1656.8945, 1222.1849, 30.1675, -89.9999, -3.0999, 41.9999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_spezialAutohaus[27], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_spezialAutohaus[28] = CreateDynamicObject(19172, -1642.6813, 1204.1265, 11.2696, 0.0000, 0.0000, 73.1000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_spezialAutohaus[28], 1, "Eingang", OBJECT_MATERIAL_SIZE_256x128, "Arial", 70, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_spezialAutohaus[28], 15, 10101, "2notherbuildsfe", "Bow_church_grass_alt", 0x00000000);
    object_spezialAutohaus[29] = CreateDynamicObject(3857, -1645.3399, 1210.5327, 7.5590, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash3
    SetDynamicObjectMaterial(object_spezialAutohaus[29], 0, 4887, "downtown_las", "ws_glassnbrassdoor", 0x00000000);
    object_spezialAutohaus[30] = CreateDynamicObject(3858, -1654.7518, 1219.3298, 22.9690, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_spezialAutohaus[30], 0, 4887, "downtown_las", "ws_glassnbrassdoor", 0x00000000);
    object_spezialAutohaus[31] = CreateDynamicObject(3857, -1645.3399, 1210.5327, 15.5290, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash3
    SetDynamicObjectMaterial(object_spezialAutohaus[31], 0, 4887, "downtown_las", "ws_glassnbrassdoor", 0x00000000);
    object_spezialAutohaus[32] = CreateDynamicObject(3859, -1643.2502, 1204.2841, 15.6590, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash04
    SetDynamicObjectMaterial(object_spezialAutohaus[32], 0, 4887, "downtown_las", "ws_glassnbrassdoor", 0x00000000);
    object_spezialAutohaus[33] = CreateDynamicObject(3857, -1645.3399, 1210.5327, 22.9490, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash3
    SetDynamicObjectMaterial(object_spezialAutohaus[33], 0, 4887, "downtown_las", "ws_glassnbrassdoor", 0x00000000);
    object_spezialAutohaus[34] = CreateDynamicObject(3859, -1643.2502, 1204.2841, 22.9890, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash04
    SetDynamicObjectMaterial(object_spezialAutohaus[34], 0, 4887, "downtown_las", "ws_glassnbrassdoor", 0x00000000);
    object_spezialAutohaus[35] = CreateDynamicObject(1671, -1656.1002, 1207.4606, 6.6371, 0.0000, 0.0000, 132.4999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_spezialAutohaus[36] = CreateDynamicObject(1671, -1658.9910, 1208.0826, 6.6371, 0.0000, 0.0000, -147.7000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_spezialAutohaus[37] = CreateDynamicObject(9953, -1668.8585, 1215.8134, 19.1931, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottos_AUTOS_sfe
    SetDynamicObjectMaterial(object_spezialAutohaus[37], 2, 19598, "sfbuilding1", "darkwood1", 0x00000000);
    SetDynamicObjectMaterial(object_spezialAutohaus[37], 3, 14629, "ab_chande", "ab_goldpipe", 0x00000000);
    SetDynamicObjectMaterial(object_spezialAutohaus[37], 4, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    SetDynamicObjectMaterial(object_spezialAutohaus[37], 5, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    SetDynamicObjectMaterial(object_spezialAutohaus[37], 7, 10765, "airportgnd_sfse", "white", 0x00000000);
    SetDynamicObjectMaterialText(object_spezialAutohaus[37], 9, "LyD Spezialhaus", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF000000, 0x00000000, 0);
    object_spezialAutohaus[38] = CreateDynamicObject(2942, -1642.0250, 1207.7510, 6.8446, 0.0000, 0.0000, 134.5999, VW_MAIN, MAPS_SPEZIALAUTOHAUS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
}
