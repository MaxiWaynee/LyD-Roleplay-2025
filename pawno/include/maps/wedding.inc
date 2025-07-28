#include <YSI\y_hooks>

// Global interior define
#define MAPS_WEDDING_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 140.0;

// Wedding place points
#define WEDDING_COORDS       1310.1578, -1368.4930, 13.5499

// Map variables
new object_wedding[145];
new pickup_wedding[1];
new text3D_wedding[1];
new actor_wedding[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
	return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_wedding[0] = CreateDynamicPickup(1314, 1, WEDDING_COORDS, VW_MAIN, MAPS_WEDDING_INTERIOR); // Wedding point
	
    // 3DTextLabels
    text3D_wedding[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "San Andreas Standesamt\n" COLOR_HEX_GREEN "Tippe /Heiraten um zu heiraten\n" COLOR_HEX_RED "Tippe /Scheiden um dich zu scheiden", COLOR_WHITE, WEDDING_COORDS, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_WEDDING_INTERIOR);
    
    // Actors
    actor_wedding[0] = CreateDynamicActor(68, 1310.0942, -1367.0007, 13.5150, 181.1954, .worldid = VW_MAIN, .interiorid = MAPS_WEDDING_INTERIOR); // Preacher
    ApplyDynamicActorAnimation(actor_wedding[0], "GRAVEYARD", "prst_loopa", 4.0, 0, 0, 0, 1, 0);

	// Objects
    object_wedding[0] = CreateDynamicObject(870, 1314.0999755859, -1369, 12.800000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[1] = CreateDynamicObject(870, 1314, -1369.5999755859, 12.800000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[2] = CreateDynamicObject(870, 1314.0999755859, -1370.8000488281, 12.800000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[3] = CreateDynamicObject(870, 1314, -1371.5, 12.800000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[4] = CreateDynamicObject(870, 1314.0999755859, -1372.5999755859, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[5] = CreateDynamicObject(870, 1314.0999755859, -1373.5, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[6] = CreateDynamicObject(870, 1314, -1374.8000488281, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[7] = CreateDynamicObject(870, 1314, -1375.5, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[8] = CreateDynamicObject(870, 1314, -1376.8000488281, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[9] = CreateDynamicObject(870, 1314.0999755859, -1377.9000244141, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[10] = CreateDynamicObject(870, 1314.0999755859, -1378.8000488281, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[11] = CreateDynamicObject(870, 1314, -1379.8994140625, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[12] = CreateDynamicObject(870, 1313.9000244141, -1380.5, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[13] = CreateDynamicObject(870, 1313.9000244141, -1381.5999755859, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[14] = CreateDynamicObject(870, 1313.9000244141, -1382.3000488281, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[15] = CreateDynamicObject(870, 1313.7998046875, -1383.19921875, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[16] = CreateDynamicObject(870, 1313.8000488281, -1383.6999511719, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[17] = CreateDynamicObject(870, 1313.7998046875, -1383.69921875, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[18] = CreateDynamicObject(870, 1314, -1383.1999511719, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[19] = CreateDynamicObject(870, 1314.1999511719, -1382.4000244141, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[20] = CreateDynamicObject(870, 1314.2998046875, -1381.69921875, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[21] = CreateDynamicObject(870, 1314.3994140625, -1380.3994140625, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[22] = CreateDynamicObject(870, 1314.5999755859, -1379.0999755859, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[23] = CreateDynamicObject(870, 1314.5999755859, -1378.0999755859, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[24] = CreateDynamicObject(870, 1314.69921875, -1376.599609375, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[25] = CreateDynamicObject(870, 1314.69921875, -1376.599609375, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[26] = CreateDynamicObject(870, 1315, -1374.7998046875, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[27] = CreateDynamicObject(870, 1315, -1378.5, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[28] = CreateDynamicObject(870, 1314.9000244141, -1380.4000244141, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[29] = CreateDynamicObject(870, 1314.7998046875, -1383, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[30] = CreateDynamicObject(870, 1305.7998046875, -1369.5, 12.800000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[31] = CreateDynamicObject(870, 1306, -1370.5999755859, 12.800000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[32] = CreateDynamicObject(870, 1305.9000244141, -1371.6999511719, 12.800000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[33] = CreateDynamicObject(870, 1306.2998046875, -1373.19921875, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[34] = CreateDynamicObject(870, 1306.19921875, -1373.7998046875, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[35] = CreateDynamicObject(870, 1306.099609375, -1374.69921875, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[36] = CreateDynamicObject(870, 1306.3000488281, -1375.3000488281, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[37] = CreateDynamicObject(870, 1306.5, -1376.1999511719, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[38] = CreateDynamicObject(870, 1306.5, -1376.19921875, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[39] = CreateDynamicObject(870, 1306.1999511719, -1376.6999511719, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[40] = CreateDynamicObject(870, 1306.4000244141, -1377.5, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[41] = CreateDynamicObject(870, 1306.5, -1378.4000244141, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[42] = CreateDynamicObject(870, 1306.5, -1379.1999511719, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[43] = CreateDynamicObject(870, 1306.5999755859, -1380.5, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[44] = CreateDynamicObject(870, 1306.3000488281, -1380, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[45] = CreateDynamicObject(870, 1306.2998046875, -1381.2998046875, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[46] = CreateDynamicObject(870, 1306.3000488281, -1382.4000244141, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[47] = CreateDynamicObject(870, 1306.3000488281, -1383.6999511719, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[48] = CreateDynamicObject(870, 1306.1999511719, -1384.3000488281, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[49] = CreateDynamicObject(870, 1305.1999511719, -1384.0999755859, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[50] = CreateDynamicObject(870, 1305.19921875, -1384.099609375, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[51] = CreateDynamicObject(870, 1305.1999511719, -1382.5999755859, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[52] = CreateDynamicObject(870, 1305.19921875, -1382.599609375, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[53] = CreateDynamicObject(870, 1305.4000244141, -1381.3000488281, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[54] = CreateDynamicObject(870, 1305.4000244141, -1380.5, 13, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[55] = CreateDynamicObject(870, 1305.2998046875, -1379.5, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[56] = CreateDynamicObject(870, 1305.0999755859, -1378.0999755859, 12.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[57] = CreateDynamicObject(870, 1306, -1369, 12.800000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[58] = CreateDynamicObject(949, 1307.5999755859, -1367.6999511719, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[59] = CreateDynamicObject(949, 1312.6999511719, -1367.5999755859, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[60] = CreateDynamicObject(2345, 1307.8000488281, -1369.9000244141, 17.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[61] = CreateDynamicObject(2345, 1312.5999755859, -1369.9000244141, 17.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[62] = CreateDynamicObject(2345, 1310.1999511719, -1369.9000244141, 17.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[63] = CreateDynamicObject(3520, 1307.4000244141, -1370.1999511719, 12.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[64] = CreateDynamicObject(3520, 1307.1999511719, -1373.5, 12.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[65] = CreateDynamicObject(3520, 1307.1999511719, -1376.6999511719, 12.699999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[66] = CreateDynamicObject(3520, 1307.1999511719, -1380.5, 12.699999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[67] = CreateDynamicObject(3520, 1313.5, -1370.0999755859, 12.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[68] = CreateDynamicObject(3520, 1313.5, -1373.4000244141, 12.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[69] = CreateDynamicObject(3520, 1313.5, -1376.8000488281, 12.699999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[70] = CreateDynamicObject(3520, 1313.4000244141, -1380.0999755859, 12.699999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[71] = CreateDynamicObject(8991, 1307.9000244141, -1367.3000488281, 18.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[72] = CreateDynamicObject(8991, 1312.3000488281, -1366.9000244141, 18.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[73] = CreateDynamicObject(15038, 1306.6999511719, -1369.5999755859, 18.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[74] = CreateDynamicObject(15038, 1305.5999755859, -1367.8000488281, 18.5, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[75] = CreateDynamicObject(15038, 1314.6999511719, -1367.8000488281, 18.5, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[76] = CreateDynamicObject(15038, 1313.5999755859, -1369.5999755859, 18.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[77] = CreateDynamicObject(15038, 1311.4000244141, -1369.5999755859, 18.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[78] = CreateDynamicObject(15038, 1308.8000488281, -1369.5, 18.60000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[79] = CreateDynamicObject(869, 1308.1999511719, -1367.8000488281, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[80] = CreateDynamicObject(869, 1310.5999755859, -1367.9000244141, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[81] = CreateDynamicObject(869, 1309, -1367.6999511719, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[82] = CreateDynamicObject(869, 1311.4000244141, -1367.8000488281, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[83] = CreateDynamicObject(869, 1312.5, -1367.6999511719, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[84] = CreateDynamicObject(869, 1311.6999511719, -1368.0999755859, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[85] = CreateDynamicObject(869, 1308.5999755859, -1367.9000244141, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[86] = CreateDynamicObject(869, 1307.8000488281, -1367.8000488281, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[87] = CreateDynamicObject(869, 1315, -1363.5, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[88] = CreateDynamicObject(869, 1305.5, -1363.3000488281, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[89] = CreateDynamicObject(869, 1307.5, -1365, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[90] = CreateDynamicObject(869, 1311.3000488281, -1365.0999755859, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[91] = CreateDynamicObject(869, 1305.3000488281, -1364.9000244141, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[92] = CreateDynamicObject(869, 1315.4000244141, -1364.4000244141, 18.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[93] = CreateDynamicObject(1232, 1313.4000244141, -1377.5999755859, 15.300000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[94] = CreateDynamicObject(1232, 1307.099609375, -1377.3994140625, 15.300000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[95] = CreateDynamicObject(1232, 1307.1999511719, -1385.1999511719, 15.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[96] = CreateDynamicObject(1232, 1312.9000244141, -1385.0999755859, 15.300000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[97] = CreateDynamicObject(1232, 1315.8000488281, -1385.1999511719, 15.300000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[98] = CreateDynamicObject(2773, 1307.6999511719, -1369.3000488281, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[99] = CreateDynamicObject(2773, 1307.5999755859, -1371.1999511719, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[100] = CreateDynamicObject(2773, 1307.5999755859, -1373.0999755859, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[101] = CreateDynamicObject(2773, 1307.5999755859, -1375, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[102] = CreateDynamicObject(2773, 1307.5999755859, -1376.9000244141, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[103] = CreateDynamicObject(2773, 1307.5, -1378.8000488281, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[104] = CreateDynamicObject(2773, 1307.5, -1380.6999511719, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[105] = CreateDynamicObject(2773, 1307.5, -1382.5999755859, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[106] = CreateDynamicObject(2773, 1307.5999755859, -1384.5, 13.300000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[107] = CreateDynamicObject(1280, 1319, -1373.3000488281, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[108] = CreateDynamicObject(1280, 1319, -1376.4000244141, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[109] = CreateDynamicObject(1280, 1319, -1379.3000488281, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[110] = CreateDynamicObject(1280, 1318.9000244141, -1382.0999755859, 13.300000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[111] = CreateDynamicObject(1280, 1317, -1382, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[112] = CreateDynamicObject(1280, 1317, -1379.1999511719, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[113] = CreateDynamicObject(1280, 1317.0999755859, -1373.3000488281, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[114] = CreateDynamicObject(1280, 1317.0999755859, -1376.4000244141, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[115] = CreateDynamicObject(1280, 1301.5, -1382.5, 13.10000038147, 0, 0, 180, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[116] = CreateDynamicObject(1280, 1301.5, -1379.6999511719, 13.10000038147, 0, 0, 179.99450683594, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[117] = CreateDynamicObject(1280, 1301.5, -1376.8000488281, 13.10000038147, 0, 0, 179.99450683594, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[118] = CreateDynamicObject(1280, 1301.5, -1374, 13.10000038147, 0, 0, 179.99450683594, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[119] = CreateDynamicObject(1280, 1303.3000488281, -1382.5, 13.10000038147, 0, 0, 179.99450683594, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[120] = CreateDynamicObject(1280, 1303.1999511719, -1379.8000488281, 13.10000038147, 0, 0, 179.99450683594, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[121] = CreateDynamicObject(1280, 1303.1999511719, -1377, 13.10000038147, 0, 0, 179.99450683594, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[122] = CreateDynamicObject(1280, 1303.1999511719, -1374.0999755859, 13, 0, 0, 179.99450683594, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[123] = CreateDynamicObject(3872, 1315.4000244141, -1360.8000488281, 28.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[124] = CreateDynamicObject(3872, 1316.5999755859, -1360.8000488281, 24.700000762939, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[125] = CreateDynamicObject(3872, 1316.1999511719, -1363.4000244141, 24.700000762939, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[126] = CreateDynamicObject(3872, 1308.1999511719, -1363.4000244141, 24.700000762939, 0, 0, 176, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[127] = CreateDynamicObject(3872, 1308.1999511719, -1366.5, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[128] = CreateDynamicObject(3872, 1312.5999755859, -1364.9000244141, 13.10000038147, 0, 0, 184, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[129] = CreateDynamicObject(2780, 1315.4000244141, -1361.5, 17.799999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[130] = CreateDynamicObject(2780, 1305.4000244141, -1361.8000488281, 17.89999961853, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[131] = CreateDynamicObject(3515, 1310.1999511719, -1368.1999511719, 19.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[132] = CreateDynamicObject(3515, 1310.1999511719, -1368.1999511719, 19.299999237061, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[133] = CreateDynamicObject(3877, 1303.8000488281, -1367.9000244141, 14.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[134] = CreateDynamicObject(3877, 1316.6999511719, -1367.8000488281, 14.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[135] = CreateDynamicObject(1232, 1304.5, -1385.3000488281, 15.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[136] = CreateDynamicObject(2773, 1312.6999511719, -1368.9000244141, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[137] = CreateDynamicObject(2773, 1312.6999511719, -1370.8000488281, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[138] = CreateDynamicObject(2773, 1312.6999511719, -1372.6999511719, 13.10000038147, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[139] = CreateDynamicObject(2773, 1312.6999511719, -1374.5999755859, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[140] = CreateDynamicObject(2773, 1312.6999511719, -1376.5, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[141] = CreateDynamicObject(2773, 1312.6999511719, -1378.4000244141, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[142] = CreateDynamicObject(2773, 1312.6999511719, -1380.3000488281, 13.199999809265, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[143] = CreateDynamicObject(2773, 1312.5999755859, -1382.3000488281, 13.300000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wedding[144] = CreateDynamicObject(2773, 1312.5999755859, -1384.1999511719, 13.300000190735, 0, 0, 0, VW_MAIN, MAPS_WEDDING_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
