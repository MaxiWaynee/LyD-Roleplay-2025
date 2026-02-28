#include <YSI\y_hooks>

// Global interior define
#define MAPS_NOOBSPAWN_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 250.0;
static Float:DRAWDISTANCE   = 230.0;

// Noob spawn in LS points
#define NOOBSPAWN_STARTBONUS_POINT   820.1830, -1355.1726, 13.5494
#define NOOBSPAWN_SERVERINFO_POINT   816.1649, -1355.1726, 13.5494
#define NOOBSPAWN_EINFUEHRUNG_POINT  809.3212, -1339.9855, 13.5408

// Map variables
new neulingSpawn_Obj[80];
new pickup_noobSpawn[3];
new text3D_noobSpawn[3];
//new actor_noobSpawn[2];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(NOOBSPAWN_STARTBONUS_POINT, 38, 0, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // S icon for spawn

    // Pickups
    pickup_noobSpawn[0] = CreateDynamicPickup(1239, 1, NOOBSPAWN_SERVERINFO_POINT, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // Server info point
    pickup_noobSpawn[1] = CreateDynamicPickup(1239, 1, NOOBSPAWN_STARTBONUS_POINT, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // Start bonus point
    pickup_noobSpawn[2] = CreateDynamicPickup(1239, 1, NOOBSPAWN_EINFUEHRUNG_POINT, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // Einführung point

    // 3DTextLabels
    text3D_noobSpawn[0] = _:CreateDynamic3DTextLabel("Server Informationen\n" COLOR_HEX_WHITE "Tippe /Info", COLOR_GREEN, NOOBSPAWN_SERVERINFO_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR);
    text3D_noobSpawn[1] = _:CreateDynamic3DTextLabel("Startbonus\n" COLOR_HEX_WHITE "Tippe: /Startbonus", COLOR_GREEN, NOOBSPAWN_STARTBONUS_POINT, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR);	
    text3D_noobSpawn[2] = _:CreateDynamic3DTextLabel("Einführung\n" COLOR_HEX_WHITE "Tippe: /Einfuehrung", COLOR_GREEN, NOOBSPAWN_EINFUEHRUNG_POINT, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR);

    // Actors

	// Objects
	neulingSpawn_Obj[0] = CreateDynamicObject(18980, 845.3684, -1338.0811, 5.5471, 0.0000, -59.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[0], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[1] = CreateDynamicObject(8661, 827.6936, -1354.5528, 12.5494, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(neulingSpawn_Obj[1], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
	neulingSpawn_Obj[2] = CreateDynamicObject(18766, 819.4906, -1341.3597, 12.0424, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(neulingSpawn_Obj[2], 0, 10023, "bigwhitesfe", "archgrnd1_SFE", 0xFFFFFFFF);
	neulingSpawn_Obj[3] = CreateDynamicObject(18766, 812.4500, -1341.3597, 12.0509, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(neulingSpawn_Obj[3], 0, 10023, "bigwhitesfe", "archgrnd1_SFE", 0xFFFFFFFF);
	neulingSpawn_Obj[4] = CreateDynamicObject(18980, 819.9182, -1337.8640, 12.0551, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[4], 0, 10023, "bigwhitesfe", "archgrnd2_SFE", 0xFFD3D3D3);
	neulingSpawn_Obj[5] = CreateDynamicObject(18980, 844.9174, -1338.3702, 12.0558, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[5], 0, 10023, "bigwhitesfe", "archgrnd2_SFE", 0xFFD3D3D3);
	neulingSpawn_Obj[6] = CreateDynamicObject(18980, 819.9182, -1338.3702, 12.0558, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[6], 0, 10023, "bigwhitesfe", "archgrnd2_SFE", 0xFFD3D3D3);
	neulingSpawn_Obj[7] = CreateDynamicObject(19455, 822.6688, -1337.4499, 17.8596, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[7], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[8] = CreateDynamicObject(19441, 827.5247, -1337.9056, 14.2319, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
	SetDynamicObjectMaterial(neulingSpawn_Obj[8], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[9] = CreateDynamicObject(18980, 807.6784, -1350.3331, 19.3852, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[9], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[10] = CreateDynamicObject(18980, 819.6782, -1337.3332, 19.3852, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[10], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[11] = CreateDynamicObject(18980, 819.6782, -1337.3332, 16.3351, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[11], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[12] = CreateDynamicObject(18980, 807.6784, -1350.3331, 16.3351, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[12], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[13] = CreateDynamicObject(19455, 822.1240, -1356.9227, 14.1996, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[13], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[14] = CreateDynamicObject(19455, 813.0343, -1337.4499, 17.8596, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[14], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[15] = CreateDynamicObject(19455, 808.1347, -1342.1789, 17.8596, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[15], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[16] = CreateDynamicObject(19455, 808.1347, -1351.8105, 17.8596, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[16], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[17] = CreateDynamicObject(8661, 827.6798, -1347.3697, 15.8815, 0.0000, 180.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(neulingSpawn_Obj[17], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	neulingSpawn_Obj[18] = CreateDynamicObject(19455, 812.4940, -1356.9227, 14.1996, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[18], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[19] = CreateDynamicObject(19455, 812.4940, -1356.9227, 18.0095, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[19], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[20] = CreateDynamicObject(19455, 808.1347, -1361.4449, 17.8596, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[20], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[21] = CreateDynamicObject(19455, 831.7578, -1356.9227, 14.1996, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[21], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[22] = CreateDynamicObject(18980, 819.9182, -1344.3520, 12.0558, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[22], 0, 10023, "bigwhitesfe", "archgrnd2_SFE", 0xFFD3D3D3);
	neulingSpawn_Obj[23] = CreateDynamicObject(18980, 844.9174, -1344.3520, 12.0558, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[23], 0, 10023, "bigwhitesfe", "archgrnd2_SFE", 0xFFD3D3D3);
	neulingSpawn_Obj[24] = CreateDynamicObject(19455, 827.5247, -1348.8901, 14.1996, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[24], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[25] = CreateDynamicObject(19455, 827.5247, -1358.5240, 14.1996, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[25], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[26] = CreateDynamicObject(18980, 819.9182, -1344.8625, 12.0570, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[26], 0, 10023, "bigwhitesfe", "archgrnd2_SFE", 0xFFD3D3D3);
	neulingSpawn_Obj[28] = CreateDynamicObject(19455, 832.3646, -1344.3193, 14.1996, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[28], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[29] = CreateDynamicObject(19455, 832.3646, -1338.4702, 14.1996, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[29], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[30] = CreateDynamicObject(19455, 830.8432, -1344.4736, 9.8996, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[30], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[31] = CreateDynamicObject(19455, 827.5260, -1343.0808, 17.0596, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[31], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[32] = CreateDynamicObject(19455, 830.8432, -1344.4736, 6.4000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[32], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[33] = CreateDynamicObject(18980, 807.9180, -1351.3619, 12.0579, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[33], 0, 10023, "bigwhitesfe", "archgrnd2_SFE", 0xFFD3D3D3);
	neulingSpawn_Obj[34] = CreateDynamicObject(19455, 830.8126, -1338.4836, 9.8996, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[34], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[35] = CreateDynamicObject(19455, 840.4470, -1338.4836, 9.8996, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[35], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[36] = CreateDynamicObject(19455, 836.4671, -1338.4836, 6.4000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[36], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[37] = CreateDynamicObject(18980, 840.2777, -1338.0811, 5.6413, 0.0000, -59.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[37], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[38] = CreateDynamicObject(19172, 836.7374, -1338.5638, 9.2442, 0.0000, 31.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[38], 0, "LyD", OBJECT_MATERIAL_SIZE_256x128, "Arial", 140, 1, 0xFFFFFFFF, 0x00000000, 1);
	SetDynamicObjectMaterial(neulingSpawn_Obj[38], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[39] = CreateDynamicObject(19455, 833.5446, -1342.4300, 12.4560, 0.0000, -63.0998, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[39], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[40] = CreateDynamicObject(19455, 829.0770, -1342.4300, 14.7227, 0.0000, -63.0998, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[40], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[41] = CreateDynamicObject(19455, 831.2363, -1342.4300, 13.6260, 0.0000, -63.0998, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall095
	SetDynamicObjectMaterial(neulingSpawn_Obj[41], 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	neulingSpawn_Obj[42] = CreateDynamicObject(8661, 855.0697, -1346.8994, 11.6213, 0.0000, 180.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(neulingSpawn_Obj[42], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	neulingSpawn_Obj[43] = CreateDynamicObject(18980, 828.8510, -1337.3332, 9.8639, 0.0000, -11.6998, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[43], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[44] = CreateDynamicObject(3657, 814.4553, -1350.6170, 13.0150, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //airseata_LAS
	SetDynamicObjectMaterial(neulingSpawn_Obj[44], 2, 642, "canopy", "wood02", 0x00000000);
	neulingSpawn_Obj[45] = CreateDynamicObject(18980, 827.9301, -1337.3332, 1.7839, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(neulingSpawn_Obj[45], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	neulingSpawn_Obj[46] = CreateDynamicObject(3657, 821.7160, -1352.1683, 13.0150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //airseata_LAS
	SetDynamicObjectMaterial(neulingSpawn_Obj[46], 2, 642, "canopy", "wood02", 0x00000000);
	neulingSpawn_Obj[47] = CreateDynamicObject(3657, 814.4553, -1352.1683, 13.0150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //airseata_LAS
	SetDynamicObjectMaterial(neulingSpawn_Obj[47], 2, 642, "canopy", "wood02", 0x00000000);
	neulingSpawn_Obj[48] = CreateDynamicObject(638, 826.9304, -1347.5963, 12.8874, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	neulingSpawn_Obj[49] = CreateDynamicObject(3657, 821.7160, -1350.6170, 13.0150, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //airseata_LAS
	SetDynamicObjectMaterial(neulingSpawn_Obj[49], 2, 642, "canopy", "wood02", 0x00000000);
	neulingSpawn_Obj[50] = CreateDynamicObject(638, 826.9304, -1350.8875, 12.8874, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	neulingSpawn_Obj[51] = CreateDynamicObject(638, 821.7199, -1351.4160, 12.8874, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	neulingSpawn_Obj[52] = CreateDynamicObject(638, 814.4097, -1351.4160, 12.8874, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	neulingSpawn_Obj[53] = CreateDynamicObject(19786, 820.0714, -1356.9149, 14.3070, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
	neulingSpawn_Obj[54] = CreateDynamicObject(19786, 816.1217, -1356.9149, 14.3070, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
	neulingSpawn_Obj[55] = CreateDynamicObject(640, 811.4406, -1356.2734, 12.8915, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	neulingSpawn_Obj[56] = CreateDynamicObject(19172, 819.6715, -1356.7824, 13.7559, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[56], 0, "Für Fragen > /Sup", OBJECT_MATERIAL_SIZE_512x256, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[56], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[57] = CreateDynamicObject(19172, 819.6715, -1356.7824, 14.0360, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[57], 0, "Willkommen auf LyD!", OBJECT_MATERIAL_SIZE_512x256, "Arial", 40, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[57], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[58] = CreateDynamicObject(19172, 819.6715, -1356.7824, 13.6560, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[58], 0, "Für Cheatermeldungen > /Admin", OBJECT_MATERIAL_SIZE_512x256, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[58], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[59] = CreateDynamicObject(19172, 819.6715, -1356.7824, 13.5558, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[59], 0, "Für Orientierung > /Navi", OBJECT_MATERIAL_SIZE_512x256, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[59], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[60] = CreateDynamicObject(19172, 819.6715, -1356.7824, 13.4560, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[60], 0, "Für eine Übersicht > /Help", OBJECT_MATERIAL_SIZE_512x256, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[60], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[61] = CreateDynamicObject(19172, 815.6411, -1356.7824, 14.0360, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[61], 0, "Unsere Plattformen:", OBJECT_MATERIAL_SIZE_512x256, "Arial", 40, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[61], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[62] = CreateDynamicObject(19172, 815.6411, -1356.7824, 13.7559, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[62], 0, "Forum: www.LyD-Roleplay.de", OBJECT_MATERIAL_SIZE_512x256, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[62], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[63] = CreateDynamicObject(19172, 815.6411, -1356.7824, 13.6560, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[63], 0, "UCP: ucp.LyD-Roleplay.de", OBJECT_MATERIAL_SIZE_512x256, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[63], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[64] = CreateDynamicObject(19172, 815.6411, -1356.7824, 13.5558, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[64], 0, "Teamspeak: TS.LyD-Roleplay.de", OBJECT_MATERIAL_SIZE_512x256, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[64], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[65] = CreateDynamicObject(19378, 807.8546, -1352.0086, 10.5855, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(neulingSpawn_Obj[65], 0, 17588, "lae2coast_alpha", "plainglass", 0xFF000000);
	neulingSpawn_Obj[66] = CreateDynamicObject(19378, 807.8555, -1352.0100, 10.8155, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(neulingSpawn_Obj[66], 0, 17588, "lae2coast_alpha", "plainglass", 0xFF000000);
	neulingSpawn_Obj[67] = CreateDynamicObject(19378, 829.0070, -1337.9291, 10.8155, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(neulingSpawn_Obj[67], 0, 17588, "lae2coast_alpha", "plainglass", 0xFF000000);
	neulingSpawn_Obj[68] = CreateDynamicObject(19378, 819.3740, -1337.9291, 10.8155, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(neulingSpawn_Obj[68], 0, 17588, "lae2coast_alpha", "plainglass", 0xFF000000);
	neulingSpawn_Obj[69] = CreateDynamicObject(19378, 819.3729, -1337.9281, 10.6355, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(neulingSpawn_Obj[69], 0, 17588, "lae2coast_alpha", "plainglass", 0xFF000000);
	neulingSpawn_Obj[70] = CreateDynamicObject(19378, 829.0079, -1337.9281, 10.6355, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(neulingSpawn_Obj[70], 0, 17588, "lae2coast_alpha", "plainglass", 0xFF000000);
	neulingSpawn_Obj[71] = CreateDynamicObject(2942, 827.0036, -1355.3913, 13.2144, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Neulingspawn Geldautomat
	neulingSpawn_Obj[72] = CreateDynamicObject(19172, 820.8120, -1337.3712, 17.6660, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[72], 0, "Leb", OBJECT_MATERIAL_SIZE_512x256, "Arial", 190, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[72], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[73] = CreateDynamicObject(19172, 808.0327, -1345.4797, 17.6660, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[73], 0, "e dein", OBJECT_MATERIAL_SIZE_512x256, "Arial", 190, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[73], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[74] = CreateDynamicObject(19172, 808.0327, -1348.0003, 17.6660, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[74], 0, "en Tra", OBJECT_MATERIAL_SIZE_512x256, "Arial", 190, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[74], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[75] = CreateDynamicObject(19172, 808.0327, -1343.9002, 17.6660, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[75], 0, "Leb", OBJECT_MATERIAL_SIZE_512x256, "Arial", 190, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[75], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[76] = CreateDynamicObject(19172, 816.7005, -1337.3702, 17.6660, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[76], 0, "en Tra", OBJECT_MATERIAL_SIZE_512x256, "Arial", 190, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[76], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[77] = CreateDynamicObject(19172, 819.2423, -1337.3702, 17.6660, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[77], 0, "e dein", OBJECT_MATERIAL_SIZE_512x256, "Arial", 190, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[77], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[78] = CreateDynamicObject(19172, 814.0902, -1337.3702, 17.6660, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[78], 0, "um", OBJECT_MATERIAL_SIZE_512x256, "Arial", 190, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[78], 1, 19297, "matlights", "invisible", 0x00000000);
	neulingSpawn_Obj[79] = CreateDynamicObject(19172, 808.0327, -1350.5814, 17.6660, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(neulingSpawn_Obj[79], 0, "um", OBJECT_MATERIAL_SIZE_512x256, "Arial", 190, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(neulingSpawn_Obj[79], 1, 19297, "matlights", "invisible", 0x00000000);
}
