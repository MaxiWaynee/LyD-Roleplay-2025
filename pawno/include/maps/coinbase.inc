#include <YSI\y_hooks>

// Global interior define
#define MAPS_COINBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 140.0;

// Coinbase points
#define COINBASE_COORDS     1821.8444, -1401.9004, 13.4267

// Map variables
new object_coinbase[49];
new pickup_coinbase[1];
new text3D_coinbase[1];
new actor_coinbase[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
	return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_coinbase[0] = CreateDynamicPickup(1274, 1, COINBASE_COORDS, VW_MAIN, MAPS_COINBASE_INTERIOR); // Exchange point
	
    // 3DTextLabels
    text3D_coinbase[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Die Münzkassette\n" COLOR_HEX_WHITE "Tippe " COLOR_HEX_LIGHTBLUE "/coinbase " COLOR_HEX_WHITE "um Aktien oder\nKryptowährungen zu kaufen.", COLOR_WHITE, COINBASE_COORDS, 7.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_COINBASE_INTERIOR);
    
    // Actors
    actor_coinbase[0] = CreateDynamicActor(147, 1823.0002, -1399.1378, 13.4263, 180.0000, .worldid = VW_MAIN, .interiorid = MAPS_COINBASE_INTERIOR); // Business man
    ApplyDynamicActorAnimation(actor_coinbase[0], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);

	// Objects
    object_coinbase[0] = CreateDynamicObject(18766, 1817.5566, -1401.2607, 13.9615, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[0], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_coinbase[1] = CreateDynamicObject(18766, 1822.0705, -1406.4344, 13.9624, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[1], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
    object_coinbase[2] = CreateDynamicObject(18766, 1822.0705, -1397.3924, 13.9624, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[2], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_coinbase[3] = CreateDynamicObject(18762, 1827.1367, -1405.9100, 14.7096, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[3], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    object_coinbase[4] = CreateDynamicObject(18766, 1826.5731, -1399.4127, 11.4624, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[4], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_coinbase[5] = CreateDynamicObject(19434, 1822.7135, -1400.3044, 13.1996, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // wall074
    SetDynamicObjectMaterial(object_coinbase[5], 0, 14706, "labig2int2", "whitecarpet01", 0xFFA9A9A9);
    object_coinbase[6] = CreateDynamicObject(18766, 1824.0406, -1402.0415, 11.9104, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[6], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_coinbase[7] = CreateDynamicObject(18766, 1820.4011, -1402.0415, 11.9112, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[7], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_coinbase[8] = CreateDynamicObject(18766, 1827.6042, -1401.8513, 11.9090, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[8], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFA9A9A9);
    object_coinbase[9] = CreateDynamicObject(18766, 1825.1031, -1397.4017, 11.9077, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[9], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFA9A9A9);
    object_coinbase[10] = CreateDynamicObject(18766, 1818.5495, -1401.9311, 11.9090, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[10], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFA9A9A9);
    object_coinbase[11] = CreateDynamicObject(18766, 1818.5483, -1399.8984, 11.9069, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[11], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFA9A9A9);
    object_coinbase[12] = CreateDynamicObject(18766, 1825.1435, -1401.2497, 16.9615, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[12], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    object_coinbase[13] = CreateDynamicObject(18766, 1818.4820, -1401.2497, 16.9615, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[13], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    object_coinbase[14] = CreateDynamicObject(18766, 1821.7312, -1401.2486, 16.9598, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[14], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    object_coinbase[15] = CreateDynamicObject(18762, 1826.5959, -1398.8208, 13.6154, 0.0000, -45.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[15], 0, 14706, "labig2int2", "whitecarpet01", 0xFFB22222);
    object_coinbase[16] = CreateDynamicObject(18762, 1826.5959, -1403.7640, 15.9841, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[16], 0, 14706, "labig2int2", "whitecarpet01", 0xFFB22222);
    object_coinbase[17] = CreateDynamicObject(18762, 1826.5937, -1400.1881, 14.9799, 0.0000, -45.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[17], 0, 14706, "labig2int2", "whitecarpet01", 0xFFB22222);
    object_coinbase[18] = CreateDynamicObject(18766, 1822.0804, -1397.3524, 10.7824, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[18], 0, 14706, "labig2int2", "whitecarpet01", 0xFFB22222);
    object_coinbase[19] = CreateDynamicObject(18766, 1818.4809, -1401.9405, 16.9619, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[19], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    object_coinbase[20] = CreateDynamicObject(1722, 1819.7939, -1405.6944, 12.3934, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // off_chairnu
    object_coinbase[21] = CreateDynamicObject(18766, 1826.5731, -1407.1844, 11.4624, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[21], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_coinbase[22] = CreateDynamicObject(18762, 1826.5759, -1403.7640, 15.9827, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[22], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_coinbase[23] = CreateDynamicObject(1722, 1820.6645, -1405.6944, 12.3934, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // off_chairnu
    object_coinbase[24] = CreateDynamicObject(1722, 1821.5356, -1405.6944, 12.3934, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // off_chairnu
    object_coinbase[25] = CreateDynamicObject(1722, 1822.3863, -1405.6944, 12.3934, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // off_chairnu
    object_coinbase[26] = CreateDynamicObject(2002, 1818.6871, -1403.8824, 12.3759, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // water_coolnu
    object_coinbase[27] = CreateDynamicObject(19786, 1820.6944, -1397.8729, 14.7066, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // LCDTVBig1
    SetDynamicObjectMaterialText(object_coinbase[27], 1, "Münzkassette", OBJECT_MATERIAL_SIZE_256x128, "Courier", 24, 1, 0xFFFFFFFF, 0xFFA52A2A, 1);
    object_coinbase[28] = CreateDynamicObject(18762, 1821.9530, -1400.5675, 12.7496, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[28], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
    object_coinbase[29] = CreateDynamicObject(19434, 1821.1518, -1400.3020, 13.1983, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // wall074
    SetDynamicObjectMaterial(object_coinbase[29], 0, 14706, "labig2int2", "whitecarpet01", 0xFFA9A9A9);
    object_coinbase[30] = CreateDynamicObject(1671, 1822.9299, -1398.6583, 12.8494, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // swivelchair_A
    object_coinbase[31] = CreateDynamicObject(1671, 1820.7093, -1398.6583, 12.8494, 0.0000, 0.0000, 21.0998, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // swivelchair_A
    SetDynamicObjectMaterial(object_coinbase[31], 0, -1, "none", "none", 0x00000000);
    object_coinbase[32] = CreateDynamicObject(19893, 1820.8774, -1399.9038, 13.2798, 0.0000, 0.0000, -172.5997, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // LaptopSAMP1
    object_coinbase[33] = CreateDynamicObject(19893, 1822.8857, -1399.8337, 13.2798, 0.0000, 0.0000, 176.8000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // LaptopSAMP1
    object_coinbase[34] = CreateDynamicObject(2855, 1819.8277, -1400.7309, 13.2718, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // gb_bedmags05
    object_coinbase[35] = CreateDynamicObject(19175, 1827.0732, -1398.2562, 15.2189, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // SAMPPicture4
    SetDynamicObjectMaterialText(object_coinbase[35], 0, "Münzkassette", OBJECT_MATERIAL_SIZE_256x128, "Arial", 40, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_coinbase[35], 1, 19297, "matlights", "invisible", 0x00000000);
    object_coinbase[36] = CreateDynamicObject(19175, 1827.0632, -1396.6927, 14.1490, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // SAMPPicture4
    SetDynamicObjectMaterialText(object_coinbase[36], 0, "B", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 0, 0xFF8B0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_coinbase[36], 1, 19297, "matlights", "invisible", 0x00000000);
    object_coinbase[37] = CreateDynamicObject(19175, 1827.0632, -1398.2142, 13.5389, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // SAMPPicture4
    SetDynamicObjectMaterialText(object_coinbase[37], 0, "-", OBJECT_MATERIAL_SIZE_256x128, "Arial", 60, 0, 0xFF8B0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_coinbase[37], 1, 19297, "matlights", "invisible", 0x00000000);
    object_coinbase[38] = CreateDynamicObject(19175, 1827.0632, -1397.0129, 14.5690, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // SAMPPicture4
    SetDynamicObjectMaterialText(object_coinbase[38], 0, "O", OBJECT_MATERIAL_SIZE_256x128, "Arial", 155, 0, 0xFF8B0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_coinbase[38], 1, 19297, "matlights", "invisible", 0x00000000);
    object_coinbase[39] = CreateDynamicObject(19175, 1827.0632, -1398.0739, 13.5389, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // SAMPPicture4
    SetDynamicObjectMaterialText(object_coinbase[39], 0, "-", OBJECT_MATERIAL_SIZE_256x128, "Arial", 60, 0, 0xFF8B0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_coinbase[39], 1, 19297, "matlights", "invisible", 0x00000000);
    object_coinbase[40] = CreateDynamicObject(19175, 1827.0632, -1398.0739, 12.8389, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // SAMPPicture4
    SetDynamicObjectMaterialText(object_coinbase[40], 0, "-", OBJECT_MATERIAL_SIZE_256x128, "Arial", 60, 0, 0xFF8B0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_coinbase[40], 1, 19297, "matlights", "invisible", 0x00000000);
    object_coinbase[41] = CreateDynamicObject(19175, 1827.0632, -1398.2142, 12.8389, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // SAMPPicture4
    SetDynamicObjectMaterialText(object_coinbase[41], 0, "-", OBJECT_MATERIAL_SIZE_256x128, "Arial", 60, 0, 0xFF8B0000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_coinbase[41], 1, 19297, "matlights", "invisible", 0x00000000);
    object_coinbase[42] = CreateDynamicObject(19786, 1823.2943, -1397.8729, 14.7066, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // LCDTVBig1
    SetDynamicObjectMaterialText(object_coinbase[42], 1, "Münzkassette", OBJECT_MATERIAL_SIZE_256x128, "Courier", 24, 1, 0xFFFFFFFF, 0xFFA52A2A, 1);
    object_coinbase[43] = CreateDynamicObject(18075, 1821.9803, -1404.2332, 16.5094, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // lightD
    object_coinbase[44] = CreateDynamicObject(18766, 1835.1033, -1400.8222, 11.9090, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_coinbase[44], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFA9A9A9);
    object_coinbase[45] = CreateDynamicObject(1215, 1836.5833, -1403.5274, 12.4635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // bollardlight
    object_coinbase[46] = CreateDynamicObject(1215, 1830.3619, -1403.5274, 12.4635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // bollardlight
    object_coinbase[47] = CreateDynamicObject(1215, 1830.3619, -1398.1169, 12.4635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // bollardlight
    object_coinbase[48] = CreateDynamicObject(1215, 1836.5936, -1398.1169, 12.4635, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_COINBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // bollardlight
}
