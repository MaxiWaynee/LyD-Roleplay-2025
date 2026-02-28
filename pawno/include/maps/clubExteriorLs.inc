#include <YSI\y_hooks>

// Global interior define
#define MAPS_CLUBEXTERIORLS_INTERIOR      0
#define MAPS_CLUBINTERIORLS_INTERIOR      9

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Clubvilla Exterior points
#define CLUBINTERIORLS_ENTER_COORDS        1022.4622, -1121.5886, 23.8720
#define CLUBINTERIORLS_EXIT_COORDS         2317.6533, -1026.3449, 1050.2177
#define CLUBINTERIORLS_ENTER_FACING        180.0
#define CLUBINTERIORLS_EXIT_FACING         0.0

// Map variables
new object_clubExteriorLs[30];
new pickup_clubExteriorLs[1];
new text3D_clubExteriorLs[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, CLUBINTERIORLS_ENTER_COORDS)) { // Club Entrance
            if (Spieler[playerid][pDonateRank] == 0) return SendClientMessage(playerid, COLOR_RED, "Der Zutritt ist dir untersagt, weil du kein CLUBMITGLIED bist.");
            SetPlayerInterior(playerid, MAPS_CLUBINTERIORLS_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_CLUBINTERIORLS);
            SetPlayerPos(playerid, CLUBINTERIORLS_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, CLUBINTERIORLS_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(CLUBINTERIORLS_ENTER_COORDS, 48, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR); // Disc icon

    // Pickups
    pickup_clubExteriorLs[0] = CreateDynamicPickup(1318, 1, CLUBINTERIORLS_ENTER_COORDS, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR); // Club Entrance
    
    // 3DTextLabels
    text3D_clubExteriorLs[0] = _:CreateDynamic3DTextLabel("Die Clubvilla\n" COLOR_HEX_WHITE "Zutritt nur für Clubmitglieder", COLOR_GREEN, CLUBINTERIORLS_ENTER_COORDS, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CLUBEXTERIORLS_INTERIOR);
    
    // Actors

    // Objects
    object_clubExteriorLs[0] = CreateDynamicObject(1568, 1030.6999511719, -1115.5, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[1] = CreateDynamicObject(1568, 1027.3000488281, -1122.1999511719, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[2] = CreateDynamicObject(1568, 1027.3994140625, -1130.599609375, 22.799999237061, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[3] = CreateDynamicObject(1568, 1005.0999755859, -1125.5999755859, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[4] = CreateDynamicObject(1568, 1017.3994140625, -1122.2998046875, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[5] = CreateDynamicObject(1568, 1040, -1125.5, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[6] = CreateDynamicObject(1568, 1005.099609375, -1119.2998046875, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[7] = CreateDynamicObject(1568, 1040, -1119.4000244141, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[8] = CreateDynamicObject(2773, 1017.4000244141, -1126.1999511719, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[9] = CreateDynamicObject(2773, 1017.3994140625, -1128.7998046875, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[10] = CreateDynamicObject(2773, 1017.4000244141, -1123.6999511719, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[11] = CreateDynamicObject(2773, 1027.3000488281, -1129, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[12] = CreateDynamicObject(2773, 1027.3000488281, -1126.5, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[13] = CreateDynamicObject(2773, 1027.3000488281, -1124, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[14] = CreateDynamicObject(2773, 1005.0999755859, -1117.4000244141, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[15] = CreateDynamicObject(2773, 1005.099609375, -1127.2998046875, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[16] = CreateDynamicObject(2773, 1005.099609375, -1123.7998046875, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[17] = CreateDynamicObject(2773, 1005.099609375, -1120.8994140625, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[18] = CreateDynamicObject(2773, 1040, -1127.3000488281, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[19] = CreateDynamicObject(2773, 1039.9000244141, -1123.9000244141, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[20] = CreateDynamicObject(2773, 1039.9000244141, -1121.1999511719, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[21] = CreateDynamicObject(2773, 1039.9000244141, -1117.3000488281, 23.39999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[22] = CreateDynamicObject(2773, 1038.0999755859, -1130.6999511719, 23.39999961853, 0, 0, 269.5, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[23] = CreateDynamicObject(2773, 1006.799987793, -1130.5999755859, 23.39999961853, 0, 0, 271.74462890625, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[24] = CreateDynamicObject(2773, 1035.599609375, -1130.69921875, 23.39999961853, 0, 0, 269.49462890625, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[25] = CreateDynamicObject(2773, 1009.4000244141, -1130.5, 23.39999961853, 0, 0, 271.74133300781, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[26] = CreateDynamicObject(1568, 1017.5, -1130.3994140625, 22.799999237061, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[27] = CreateDynamicObject(1568, 1010.19921875, -1115.69921875, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[28] = CreateDynamicObject(1568, 1014.2998046875, -1115.7998046875, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_clubExteriorLs[29] = CreateDynamicObject(1568, 1034.6999511719, -1115.4000244141, 22.89999961853, 0, 0, 0, VW_MAIN, MAPS_CLUBEXTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
