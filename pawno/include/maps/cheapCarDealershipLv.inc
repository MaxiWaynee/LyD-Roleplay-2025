#include <YSI\y_hooks>

// Global interior define
#define MAPS_CHEAPCARDEALERSHIPLV_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Cheap car dealership lv points
#define CHEAPCARDEALERSHIPLV_COORDS    2107.6689, 1386.0609, 10.8203

// Map variables
new object_cheapCarDealership_lv[23];
new text3D_cheapCarDealership_lv[1];
new actor_cheapCarDealership_lv[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
	// Map Icon
    CreateDynamicMapIcon(CHEAPCARDEALERSHIPLV_COORDS, 55, 0, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR);
    
    // 3DTextLabels
    text3D_cheapCarDealership_lv[0] = _:CreateDynamic3DTextLabel("Autohaus Günstig - Las Venturas\n" COLOR_HEX_WHITE "Steige in ein beliebiges Fahrzeug deiner Wahl ein!", COLOR_BLUE, CHEAPCARDEALERSHIPLV_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CHEAPCARDEALERSHIPLV_INTERIOR);

    // Actors
    actor_cheapCarDealership_lv[0] = CreateDynamicActor(34, 2091.4482, 1391.3041, 10.8203, 5.1027, .worldid = VW_MAIN, .interiorid = MAPS_CHEAPCARDEALERSHIPLV_INTERIOR); // Cowboy salesman
    ApplyDynamicActorAnimation(actor_cheapCarDealership_lv[0], "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);

	// Objects
	object_cheapCarDealership_lv[0] = CreateDynamicObject(1290, 2097.5915, 1403.4697, 8.9139, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
	object_cheapCarDealership_lv[1] = CreateDynamicObject(8168, 2090.3159, 1387.3153, 11.6360, 0.0000, 0.0000, 106.6999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Vgs_guardhouse01
	object_cheapCarDealership_lv[2] = CreateDynamicObject(1290, 2113.9016, 1403.5561, 8.9139, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
	object_cheapCarDealership_lv[3] = CreateDynamicObject(1290, 2130.3312, 1403.5316, 8.9139, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
	object_cheapCarDealership_lv[4] = CreateDynamicObject(1290, 2148.8112, 1403.3977, 8.9139, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
	object_cheapCarDealership_lv[5] = CreateDynamicObject(3802, 2093.4531, 1383.9360, 12.5887, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
	object_cheapCarDealership_lv[6] = CreateDynamicObject(3802, 2093.4531, 1390.8360, 12.5887, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
	object_cheapCarDealership_lv[7] = CreateDynamicObject(3806, 2093.1525, 1385.3460, 9.8693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_winplant07
	object_cheapCarDealership_lv[8] = CreateDynamicObject(3806, 2093.1525, 1389.3261, 9.8693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_winplant07
	object_cheapCarDealership_lv[9] = CreateDynamicObject(640, 2110.9389, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[10] = CreateDynamicObject(640, 2105.7487, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[11] = CreateDynamicObject(640, 2100.5390, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[12] = CreateDynamicObject(640, 2116.9140, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[13] = CreateDynamicObject(640, 2122.1389, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[14] = CreateDynamicObject(640, 2127.3632, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[15] = CreateDynamicObject(640, 2133.2880, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[16] = CreateDynamicObject(640, 2139.4931, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[17] = CreateDynamicObject(640, 2145.7463, 1403.4492, 10.4912, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	object_cheapCarDealership_lv[18] = CreateDynamicObject(19172, 2090.3688, 1383.6855, 12.4394, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_cheapCarDealership_lv[18], 0, "Autohaus Günstig Las Venturas", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_cheapCarDealership_lv[18], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cheapCarDealership_lv[19] = CreateDynamicObject(19172, 2090.2951, 1390.9577, 12.4394, 0.0000, 0.0000, 179.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_cheapCarDealership_lv[19], 0, "Autohaus Günstig Las Venturas", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_cheapCarDealership_lv[19], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cheapCarDealership_lv[20] = CreateDynamicObject(19172, 2087.8195, 1387.2263, 12.4394, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_cheapCarDealership_lv[20], 0, "Autohaus Günstig Las Venturas", 90, "Arial", 20, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_cheapCarDealership_lv[20], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cheapCarDealership_lv[21] = CreateDynamicObject(2714, 2092.7390, 1385.5913, 11.4954, 0.0000, 0.0000, 89.5999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_OPEN_SIGN_2
	object_cheapCarDealership_lv[22] = CreateDynamicObject(19172, 2092.7006, 1387.9600, 11.2894, 0.0000, 0.0000, 89.8999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_cheapCarDealership_lv[22], 0, "Kasse", 90, "Arial", 15, 1, 0xFF000000, 0x0, 2);
	SetDynamicObjectMaterial(object_cheapCarDealership_lv[22], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
}
