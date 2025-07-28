#include <YSI\y_hooks>

// Global interior define
#define MAPS_CASINOEXTERIOR_INTERIOR      0
#define MAPS_CASINOINTERIOR_INTERIOR      10

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

// Casino points
#define CASINOEXTERIOR_INFO_POINT     1498.3309, -1585.8683, 13.5469


// Map variables
new object_casinoExterior[36];
new text3D_casinoExterior[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // Entrances/Exits of BIZ are handled im lyd.pwn

    return 1;
}

hook OnGameModeInit() {
    // Map Icons
    CreateDynamicMapIcon(CASINOEXTERIOR_INFO_POINT, 12, 0, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR);

    // 3DTextLabels
    text3D_casinoExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "-> LS - GROßES CASINO <-", COLOR_WHITE, CASINOEXTERIOR_INFO_POINT, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CASINOEXTERIOR_INTERIOR); // Casino Info

    // Objects
    object_casinoExterior[0] = CreateDynamicObject(7231, 1498.83, -1577.36, 35.61, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[1] = CreateDynamicObject(7232, 1498.17, -1579.05, 25.05, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[2] = CreateDynamicObject(7230, 1498.78, -1577.24, 35.61, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[3] = CreateDynamicObject(7392, 1456.19, -1578.56, 43.26, 0.00, 0.00, -89.02, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[4] = CreateDynamicObject(7073, 1538.92, -1577.70, 46.29, 0.00, 0.00, 90.37, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[5] = CreateDynamicObject(7315, 1458.67, -1554.76, 37.96, 0.00, 0.00, -31.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[6] = CreateDynamicObject(7072, 1539.71, -1578.24, 43.64, 0.00, 0.00, 90.37, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[7] = CreateDynamicObject(3437, 1494.11, -1582.58, 14.08, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[8] = CreateDynamicObject(3437, 1502.71, -1582.59, 14.08, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[9] = CreateDynamicObject(6986, 1512.27, -1577.18, 49.65, 0.00, 0.00, 90.33, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[10] = CreateDynamicObject(3437, 1484.57, -1582.59, 14.08, 0.00, 0.00, -1.32, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[11] = CreateDynamicObject(6986, 1483.38, -1577.29, 49.65, 0.00, 0.00, -90.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[12] = CreateDynamicObject(3437, 1475.26, -1582.59, 14.08, 0.00, 0.00, -0.12, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[13] = CreateDynamicObject(3437, 1466.04, -1582.59, 14.08, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[14] = CreateDynamicObject(3437, 1456.70, -1582.60, 14.08, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[15] = CreateDynamicObject(3437, 1447.24, -1582.60, 14.08, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[16] = CreateDynamicObject(3437, 1512.26, -1582.60, 14.08, 0.00, 0.00, 0.30, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[17] = CreateDynamicObject(3437, 1521.60, -1582.59, 14.08, 0.00, 0.00, 0.06, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[18] = CreateDynamicObject(3437, 1530.87, -1582.60, 14.08, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[19] = CreateDynamicObject(3437, 1540.18, -1582.60, 14.08, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[20] = CreateDynamicObject(3437, 1549.61, -1582.59, 14.08, 0.00, 0.00, -0.30, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[21] = CreateDynamicObject(1297, 1440.32, -1583.38, 15.70, 0.00, 0.00, 91.22, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[22] = CreateDynamicObject(1215, 1555.13, -1582.68, 12.94, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[23] = CreateDynamicObject(19377, 1498.03, -1581.24, 14.21, 0.00, 0.00, 89.88, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[24] = CreateDynamicObject(1557, 1496.93, -1581.33, 12.49, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[25] = CreateDynamicObject(1557, 1499.95, -1581.33, 12.49, 0.00, 0.00, 180.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[26] = CreateDynamicObject(1215, 1497.12, -1581.35, 16.67, 90.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[27] = CreateDynamicObject(1215, 1498.40, -1581.33, 16.63, 90.00, 0.00, 0.06, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[28] = CreateDynamicObject(1215, 1499.73, -1581.34, 16.64, 90.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[29] = CreateDynamicObject(7288, 1497.80, -1578.41, 45.71, 0.00, 0.00, 89.92, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[30] = CreateDynamicObject(2773, 1496.44, -1583.20, 13.07, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[31] = CreateDynamicObject(2773, 1500.45, -1583.20, 13.07, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[32] = CreateDynamicObject(2773, 1500.46, -1585.53, 13.07, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[33] = CreateDynamicObject(2773, 1496.44, -1585.55, 13.07, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[34] = CreateDynamicObject(3461, 1496.43, -1586.83, 13.72, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_casinoExterior[35] = CreateDynamicObject(3461, 1500.45, -1586.83, 13.72, 0.00, 0.00, 0.00, VW_MAIN, MAPS_CASINOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}