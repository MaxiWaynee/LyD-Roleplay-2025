#include <YSI\y_hooks>

// Global interior define
#define MAPS_MISC_INTERIOR          0
#define MAPS_MISC_APRISON_INTERIOR  10

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Map variables
new object_misc[4];

hook OnPlayerConnect(playerid) {
    //Werbetafel 5
    RemoveBuildingForPlayer(playerid, 1261, 1408.6563, -1407.1719, 28.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 4239, 1407.9063, -1407.3984, 33.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 1267, 1408.6563, -1407.1719, 28.6250, 0.25);
    //Werbetafel 8
    RemoveBuildingForPlayer(playerid, 3516, 1817.5469, 857.6797, 13.0078, 0.25);
    RemoveBuildingForPlayer(playerid, 1266, 1805.0234, -1692.4453, 25.1484, 0.25);
    RemoveBuildingForPlayer(playerid, 1260, 1805.0234, -1692.4453, 25.1484, 0.25);
    //Army Schranken
    RemoveBuildingForPlayer(playerid, 968, -1526.4375, 481.3828, 6.9063, 0.25);
    RemoveBuildingForPlayer(playerid, 966, -1526.3906, 481.3828, 6.1797, 0.25);
    // LV Oben Rechts Gangfight Gebiet (Zäune)
    RemoveBuildingForPlayer(playerid, 985, 2497.4063, 2777.0703, 11.5313, 0.25);
    RemoveBuildingForPlayer(playerid, 986, 2497.4063, 2769.1094, 11.5313, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
    
    // Werbetafeln
    object_misc[0] = CreateDynamicObject(1260, 1027.98, -1708.35, 25.29,   0.00, 0.00, 180.00, VW_MAIN, MAPS_MISC_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_misc[1] = CreateDynamicObject(1260, 1818.74463, 863.70074, 19.07526,   0.00000, 0.00000, 47.37273, VW_MAIN, MAPS_MISC_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

    // Gangjailtor, Adminprisonwand
    object_misc[2] = CreateDynamicObject(2930, 2162, -98.900001525879, 4.4000000953674, 0, 0, 300.5, VW_MAIN, MAPS_MISC_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Gangjailtor
    object_misc[3] = CreateDynamicObject(2395, 264.39999389648, 112.40000152588, 1003.5999755859, 0, 0, 0, VW_MAIN, MAPS_MISC_APRISON_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Adminprisontor
}