#include <YSI\y_hooks>

// Global interior define
#define MAPS_BOATDEALERSHIPSF_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Boat dealership in SF points
#define BOATDEALERSHIPSF_COORDS    -1489.6615, 712.7635, 7.1807

// Map variables
new object_boatDealershipSf[21];
new text3D_boatDealershipSf[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(BOATDEALERSHIPSF_COORDS, 9, 0, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR);

    // 3DTextLabels
    text3D_boatDealershipSf[0] = _:CreateDynamic3DTextLabel("Bootshaus - San Fierro\n" COLOR_HEX_WHITE "Steige in ein beliebiges Boot deiner Wahl ein!", COLOR_BLUE, BOATDEALERSHIPSF_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BOATDEALERSHIPSF_INTERIOR);

	// Objects
	object_boatDealershipSf[0] = CreateDynamicObject(3406, -1474.4681, 685.2744, -1.7446, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxref_woodjetty
    object_boatDealershipSf[1] = CreateDynamicObject(3406, -1465.6678, 685.2744, -1.7446, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxref_woodjetty
    object_boatDealershipSf[2] = CreateDynamicObject(3406, -1456.8968, 685.2744, -1.7446, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxref_woodjetty
    object_boatDealershipSf[3] = CreateDynamicObject(3406, -1465.0874, 691.1950, -1.7446, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxref_woodjetty
    object_boatDealershipSf[4] = CreateDynamicObject(3406, -1465.0874, 680.4052, -1.7446, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxref_woodjetty
    object_boatDealershipSf[5] = CreateDynamicObject(900, -1466.9875, 673.4528, -9.7437, 19.9999, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //searock04
    object_boatDealershipSf[6] = CreateDynamicObject(900, -1441.9162, 687.8781, -18.2418, 5.6999, 31.8999, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //searock04
    object_boatDealershipSf[7] = CreateDynamicObject(900, -1467.0876, 684.4920, -7.9081, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //searock04
    object_boatDealershipSf[8] = CreateDynamicObject(900, -1442.1114, 667.8330, -19.7884, 5.6999, 31.8999, -50.6999, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //searock04
    object_boatDealershipSf[9] = CreateDynamicObject(900, -1483.8077, 674.3125, -29.4274, 2.4999, 97.2997, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //searock04
    object_boatDealershipSf[10] = CreateDynamicObject(900, -1482.6308, 683.0136, -27.8866, 2.4999, 97.2997, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //searock04
    object_boatDealershipSf[11] = CreateDynamicObject(902, -1471.8415, 692.6536, -6.0352, -30.8999, -9.3999, 13.4997, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Starfish
    object_boatDealershipSf[12] = CreateDynamicObject(900, -1481.3415, 689.9542, -27.7488, 2.4999, 97.2997, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //searock04
    object_boatDealershipSf[13] = CreateDynamicObject(9361, -1488.0764, 720.6367, 8.5775, 0.0000, 0.0000, -45.5000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //boatoffice_sfn
    object_boatDealershipSf[14] = CreateDynamicObject(9362, -1486.3303, 721.6610, 6.9310, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //boatoffice2_sfn
    object_boatDealershipSf[15] = CreateDynamicObject(1215, -1464.0189, 686.2246, 0.9372, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_boatDealershipSf[16] = CreateDynamicObject(1215, -1466.1789, 686.2246, 0.9372, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_boatDealershipSf[17] = CreateDynamicObject(1215, -1466.1789, 684.2749, 0.9372, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_boatDealershipSf[18] = CreateDynamicObject(1215, -1464.0189, 684.2750, 0.9372, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_boatDealershipSf[19] = CreateDynamicObject(19172, -1483.4001, 711.2286, 6.8390, 0.0000, 0.0000, 90.4999, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_boatDealershipSf[19], 0, 1355, "break_s_bins", "CJ_WOOD_DARK", 0xFFFFFFFF);
    object_boatDealershipSf[20] = CreateDynamicObject(19172, -1483.4501, 711.2283, 6.8490, 0.0000, 0.0000, 90.4999, VW_MAIN, MAPS_BOATDEALERSHIPSF_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_boatDealershipSf[20], 0, 1355, "break_s_bins", "CJ_WOOD_DARK", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_boatDealershipSf[20], 1, "LyD - Bootsverkauf", 90, "Arial", 20, 1, 0xFF000000, 0x0, 1);
}
