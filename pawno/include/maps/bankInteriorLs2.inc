#include <YSI\y_hooks>

// Global interior define
#define MAPS_BANKINTERIORLS2_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Bank Interior 2 LS Points
#define BANKINTERIORLS2_ROB_POINT       2144.2129, 1641.7505, 993.5761

// Map variables
new object_bankInteriorLs2[27];
new pickup_bankInteriorLs2[2];
new text3D_bankInteriorLs2[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLS2_EXIT_POINT)) {
            Streamer_UpdateEx(playerid, BANKINTERIORLS2_ENTER_POINT, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, STREAMER_TYPE_OBJECT);
            SetPlayerVirtualWorld(playerid, VW_BANKINTERIORLS);
            SetPlayerInterior(playerid, MAPS_BANKINTERIORLS_INTERIOR);
            SetPlayerPos(playerid, BANKINTERIORLS2_ENTER_POINT);
            SetPlayerFacingAngle(playerid, BANKINTERIORLS2_ENTER_FACING);
            SetCameraBehindPlayer(playerid);

            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {    
    // Pickups
	pickup_bankInteriorLs2[0] = CreateDynamicPickup(19197, 1, BANKINTERIORLS2_EXIT_POINT, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR); // Bank interior 2 exit
    pickup_bankInteriorLs2[1] = CreateDynamicPickup(1550, 1, BANKINTERIORLS2_ROB_POINT, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR); // Robbing point
    
    // 3DTextLabels
    text3D_bankInteriorLs2[0] = _:CreateDynamic3DTextLabel("Banktresor der Zentralbank\n" COLOR_HEX_WHITE "Tippe /Bankausrauben", COLOR_YELLOW, BANKINTERIORLS2_ROB_POINT, 10.0, .testlos = 1, .worldid = VW_BANKINTERIORLS2, .interiorid = MAPS_BANKINTERIORLS2_INTERIOR);

    // Objects
    object_bankInteriorLs2[0] = CreateDynamicObject(2963, 2145, 1606.5, 994, 0, 0, 270.75, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[1] = CreateDynamicObject(944, 2148.1000976563, 1623.3000488281, 993.40002441406, 0, 0, 341.75, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[2] = CreateDynamicObject(944, 2146, 1628.3000488281, 993.40002441406, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[3] = CreateDynamicObject(944, 2137.8999023438, 1616.4000244141, 993.40002441406, 0, 0, 19.746215820313, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[4] = CreateDynamicObject(922, 2139.1999511719, 1620.6999511719, 993.59997558594, 0, 0, 20, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[5] = CreateDynamicObject(2975, 2142.3999023438, 1626.0999755859, 992.70001220703, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[6] = CreateDynamicObject(2975, 2141.6999511719, 1642.4000244141, 992.59997558594, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[7] = CreateDynamicObject(2973, 2140.3000488281, 1625.5, 992.70001220703, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[8] = CreateDynamicObject(2973, 2138.3000488281, 1625.5, 992.70001220703, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[9] = CreateDynamicObject(3798, 2149.5, 1616, 992.70001220703, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[10] = CreateDynamicObject(3798, 2149.5, 1616, 994.70001220703, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[11] = CreateDynamicObject(5269, 2129.6999511719, 1610.9000244141, 994.90002441406, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[12] = CreateDynamicObject(5269, 2158, 1622.8000488281, 994.90002441406, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[13] = CreateDynamicObject(5269, 2129.6999511719, 1627, 994.90002441406, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[14] = CreateDynamicObject(942, 2148, 1608.0999755859, 995.09997558594, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[15] = CreateDynamicObject(942, 2153.3000488281, 1608, 995.09997558594, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[16] = CreateDynamicObject(942, 2134.8000488281, 1608.0999755859, 995.09997558594, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[17] = CreateDynamicObject(923, 2141, 1614.0999755859, 993.59997558594, 0, 0, 54, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[18] = CreateDynamicObject(923, 2142, 1615.5, 993.59997558594, 0, 0, 53.997802734375, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[19] = CreateDynamicObject(922, 2148.3999023438, 1618.5, 993.5, 0, 0, 320, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[20] = CreateDynamicObject(5269, 2129.69921875, 1619, 994.90002441406, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[21] = CreateDynamicObject(5269, 2158, 1614.6999511719, 994.90002441406, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[22] = CreateDynamicObject(5269, 2158, 1606.5999755859, 994.90002441406, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[23] = CreateDynamicObject(944, 2140.8999023438, 1607.5, 993.59997558594, 0, 0, 1.242431640625, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[24] = CreateDynamicObject(3798, 2146.5, 1632, 994.59997558594, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bankInteriorLs2[25] = CreateDynamicObject(3798, 2146.5, 1632, 992.59997558594, 0, 0, 0, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

    // Banktresor
    object_bankInteriorLs2[26] = CreateDynamicObject(2963, 2144.2492675781, 1606.7133789063, 994.75732421875, 0, 0, 270.67565917969, VW_ALL, MAPS_BANKINTERIORLS2_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}