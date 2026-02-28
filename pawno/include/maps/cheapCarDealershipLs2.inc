#include <YSI\y_hooks>

// Global interior define
#define MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Cheap car dealership points
#define CHEAPCARDEALERSHIPLS2_COORDS    2126.9578, -1124.4517, 25.4636

// Map variables
new object_cheapCarDealershipLs2[12]; // Coutt and Schutz
new text3D_cheapCarDealershipLs2[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(CHEAPCARDEALERSHIPLS2_COORDS, 55, 0, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR);
    
    // 3DTextLabels
    text3D_cheapCarDealershipLs2[0] = _:CreateDynamic3DTextLabel("Autohaus - Coutt And Schutz\n" COLOR_HEX_WHITE "Steige in ein beliebiges Fahrzeug deiner Wahl ein!", COLOR_BLUE, CHEAPCARDEALERSHIPLS2_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR);
	
    // Objects
	object_cheapCarDealershipLs2[0] = CreateDynamicObject(19366, 2133.9816, -1124.0836, 25.1826, 0.0000, 0.0000, 82.5998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
    SetDynamicObjectMaterial(object_cheapCarDealershipLs2[0], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_cheapCarDealershipLs2[1] = CreateDynamicObject(2011, 2130.4936, -1151.0114, 23.0713, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant2_ofc
    object_cheapCarDealershipLs2[2] = CreateDynamicObject(2011, 2132.9936, -1151.0114, 23.0713, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant2_ofc
    object_cheapCarDealershipLs2[3] = CreateDynamicObject(1536, 2131.0920, -1151.7303, 22.8414, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT15
    object_cheapCarDealershipLs2[4] = CreateDynamicObject(2345, 2123.9213, -1149.6402, 24.6257, 0.0000, -88.5000, -87.4999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_cheapCarDealershipLs2[5] = CreateDynamicObject(2345, 2123.9238, -1149.6989, 26.8750, 0.0000, -88.5000, -87.4999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_cheapCarDealershipLs2[6] = CreateDynamicObject(2203, 2123.9819, -1149.2639, 23.4134, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_1
    object_cheapCarDealershipLs2[7] = CreateDynamicObject(19366, 2137.1628, -1124.4970, 25.1826, 0.0000, 0.0000, 82.5998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
    SetDynamicObjectMaterial(object_cheapCarDealershipLs2[7], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_cheapCarDealershipLs2[8] = CreateDynamicObject(19366, 2137.7412, -1124.5739, 25.1826, 0.0000, 0.0000, 82.5998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
    SetDynamicObjectMaterial(object_cheapCarDealershipLs2[8], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_cheapCarDealershipLs2[9] = CreateDynamicObject(19366, 2118.1701, -1119.5301, 25.1826, 0.0000, 0.0000, 72.1999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
    SetDynamicObjectMaterial(object_cheapCarDealershipLs2[9], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    object_cheapCarDealershipLs2[10] = CreateDynamicObject(19172, 2135.7407, -1124.2064, 25.2077, 0.0000, 0.0000, 173.3000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_cheapCarDealershipLs2[10], 0,"LyD | Autohaus Günstig", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 0);
    object_cheapCarDealershipLs2[11] = CreateDynamicObject(19172, 2117.9904, -1119.3697, 25.1184, 0.0000, 0.0000, 163.5998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_cheapCarDealershipLs2[11], 0, "<--- Günstige Autos!", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 0);
}
