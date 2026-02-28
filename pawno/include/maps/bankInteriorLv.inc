#include <YSI\y_hooks>

// Global interior define
#define MAPS_BANKEXTERIORLV_INTERIOR      0
#define MAPS_BANKINTERIORLV_INTERIOR      3

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Bank Interior LV Points
#define BANKINTERIORLV_TRANSFER_POINT   290.2410, 185.7422, 1007.1794
#define BANKINTERIORLV_CREDIT_POINT     298.9642, 179.2220, 1007.1719
#define BANKINTERIORLV_SERVICE_POINT    292.4491, 180.1878, 1007.1794
#define BANKINTERIORLV_ROB_POINT        296.8997, 188.5367, 1007.1719

// Map variables
new object_bankInteriorLv[40];
new pickup_bankInteriorLv[4];
new text3D_bankInteriorLv[4];
new object_bankInteriorLv_vault;

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 14886, 268.4375, 186.9297, 1006.8828, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLV_EXIT_COORDS)) {
            SetPlayerVirtualWorld(playerid, VW_MAIN);
            SetPlayerInterior(playerid, MAPS_BANKEXTERIORLV_INTERIOR);
            SetPlayerPos(playerid, BANKINTERIORLV_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, BANKINTERIORLV_ENTER_FACING);
            SetCameraBehindPlayer(playerid);

            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {    
    // Pickups
    pickup_bankInteriorLv[0] = CreateDynamicPickup(19197, 1, BANKINTERIORLV_EXIT_COORDS, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR); // Bank interior exit
    pickup_bankInteriorLv[1] = CreateDynamicPickup(1239, 1, BANKINTERIORLV_TRANSFER_POINT, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR); // Transfer Point
    pickup_bankInteriorLv[2] = CreateDynamicPickup(1239, 1, BANKINTERIORLV_CREDIT_POINT, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR); // Credit Point
    pickup_bankInteriorLv[3] = CreateDynamicPickup(1239, 1, BANKINTERIORLV_SERVICE_POINT, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR); // Service Point

    // 3DTextLabels
    text3D_bankInteriorLv[0] = _:CreateDynamic3DTextLabel("Bankservice\n" COLOR_HEX_WHITE "Tippe /Bank", COLOR_BLUE, BANKINTERIORLV_SERVICE_POINT, 15.0, .testlos = 1, .worldid = VW_BANKINTERIORLV, .interiorid = MAPS_BANKINTERIORLV_INTERIOR);
    text3D_bankInteriorLv[1] = _:CreateDynamic3DTextLabel("Kredit aufnehmen\n" COLOR_HEX_WHITE "Tippe /Kredit", COLOR_BLUE, BANKINTERIORLV_CREDIT_POINT, 10.0, .testlos = 1, .worldid = VW_BANKINTERIORLV, .interiorid = MAPS_BANKINTERIORLV_INTERIOR);
    text3D_bankInteriorLv[2] = _:CreateDynamic3DTextLabel("Überweisung\n" COLOR_HEX_WHITE "Tippe /Ueberweisen", COLOR_BLUE, BANKINTERIORLV_TRANSFER_POINT, 10.0, .testlos = 1, .worldid = VW_BANKINTERIORLV, .interiorid = MAPS_BANKINTERIORLV_INTERIOR);
    text3D_bankInteriorLv[3] = _:CreateDynamic3DTextLabel("Starte einen Banküberfall mit\n" COLOR_HEX_RED "/Tresoraufbrechen", COLOR_WHITE, BANKINTERIORLV_ROB_POINT, 10.0, .testlos = 1, .worldid = VW_BANKINTERIORLV, .interiorid = MAPS_BANKINTERIORLV_INTERIOR);
    
    // Objects
    object_bankInteriorLv[0] = CreateDynamicObject(19457, 272.49860, 179.69322, 1007.64050, 0.00000, 0.00000, 0.00000, VW_ALL, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[1] = CreateDynamicObject(19457, 272.51422, 172.65694, 1007.64600, 0.00000, 0.00000, 0.00000, VW_ALL, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[2] = CreateDynamicObject(19457, 272.49069, 179.56940, 1009.77252, 0.00000, 0.00000, 0.20100, VW_ALL, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[3] = CreateDynamicObject(19457, 272.51291, 171.53223, 1009.77380, 0.00000, 0.00000, 0.00000, VW_ALL, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[4] = CreateDynamicObject(19457, 275.55716, 189.36101, 1006.16827, 90.00000, 0.00000, 269.00000, VW_ALL, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[5] = CreateDynamicObject(19457, 292.45447, 194.18227, 1007.27826, 0.00000, 0.00000, 0.00000, VW_ALL, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[6] = CreateDynamicObject(19457, 292.45502, 194.05728, 1008.36072, 0.00000, 0.00000, 0.00000, VW_ALL, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[7] = CreateDynamicObject(2921, 302.02777, 179.87236, 1010.31476, 0.00000, 0.00000, 69.12570, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[8] = CreateDynamicObject(2921, 291.46216, 183.63889, 1009.99377, 0.00000, 0.00000, 100.53683, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[9] = CreateDynamicObject(1829, 301.06540, 190.80725, 1006.60797, 0.00000, 0.00000, 270.44464, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[10] = CreateDynamicObject(1829, 301.06494, 192.40521, 1006.60718, 0.00000, 0.00000, 268.94769, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[11] = CreateDynamicObject(1723, 301.79401, 173.01161, 1006.03052, 0.00000, 0.00000, 269.77567, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[12] = CreateDynamicObject(1723, 300.97119, 170.19960, 1006.02948, 0.00000, 0.00000, 178.41310, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[13] = CreateDynamicObject(630, 301.93088, 170.06752, 1006.98535, 0.00000, 0.00000, 0.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[14] = CreateDynamicObject(630, 301.81052, 173.98270, 1007.12158, 0.00000, 0.00000, 0.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[15] = CreateDynamicObject(630, 298.07697, 170.24442, 1007.08221, 0.00000, 0.00000, 0.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[16] = CreateDynamicObject(2357, 281.99664, 179.04456, 1006.51025, 0.00000, 0.00000, 90.87962, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[17] = CreateDynamicObject(1663, 280.77536, 179.99532, 1006.55945, 0.00000, 0.00000, 74.89742, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[18] = CreateDynamicObject(1663, 280.90802, 178.19998, 1006.59039, 0.00000, 0.00000, 95.10068, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[19] = CreateDynamicObject(2357, 283.29160, 179.07072, 1006.50427, 0.00000, 0.00000, 270.87180, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[20] = CreateDynamicObject(1663, 284.39240, 178.00470, 1006.57819, -360.00000, -360.00000, 236.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[21] = CreateDynamicObject(1663, 284.33344, 179.85361, 1006.55560, 0.00000, 0.00000, 266.63489, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[22] = CreateDynamicObject(2332, 301.38495, 191.58102, 1006.61353, 0.00000, 0.00000, -89.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[23] = CreateDynamicObject(2332, 301.40970, 189.92949, 1006.61560, 0.00000, 0.00000, 270.20526, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[24] = CreateDynamicObject(2332, 301.45807, 192.38974, 1007.46558, 0.00000, 0.00000, 269.62131, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[25] = CreateDynamicObject(2332, 301.45920, 191.57401, 1007.46552, 0.00000, 0.00000, 270.82858, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[26] = CreateDynamicObject(2332, 301.46225, 190.75410, 1007.46881, 0.00000, 0.00000, 270.62531, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[27] = CreateDynamicObject(2332, 301.47675, 189.91713, 1007.46808, 0.00000, 0.00000, -89.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[28] = CreateDynamicObject(2332, 301.52386, 192.40283, 1008.31519, 0.00000, 0.00000, -91.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[29] = CreateDynamicObject(2332, 301.51862, 191.57817, 1008.31360, 0.00000, 0.00000, 269.99911, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[30] = CreateDynamicObject(2332, 301.51862, 190.76453, 1008.30957, 0.00000, 0.00000, 270.26831, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[31] = CreateDynamicObject(2332, 301.51733, 189.92683, 1008.31030, 0.00000, 0.00000, -91.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[32] = CreateDynamicObject(2332, 301.61899, 189.90680, 1009.15033, 0.00000, 0.00000, -91.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[33] = CreateDynamicObject(2332, 301.61832, 190.75906, 1009.14899, 0.00000, 0.00000, 269.32330, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[34] = CreateDynamicObject(2332, 301.60730, 191.59740, 1009.14832, 0.00000, 0.00000, 270.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[35] = CreateDynamicObject(2332, 301.63574, 192.42056, 1009.14972, 0.00000, 0.00000, 271.98380, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[36] = CreateDynamicObject(1550, 300.87418, 192.05063, 1006.47394, 0.00000, 0.00000, 0.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[37] = CreateDynamicObject(1550, 300.74078, 189.74612, 1006.57404, 0.00000, 0.00000, 0.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[38] = CreateDynamicObject(1550, 300.15744, 189.82227, 1006.60535, 0.00000, 0.00000, 0.00000, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLv[39] = CreateDynamicObject(2963, 296.91638, 189.45781, 1008.11816, 0.00000, 0.00000, 90.07359, VW_BANKINTERIORLV, MAPS_BANKINTERIORLV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    
    // Tresortür
    object_bankInteriorLv_vault = object_bankInteriorLv[39];
}