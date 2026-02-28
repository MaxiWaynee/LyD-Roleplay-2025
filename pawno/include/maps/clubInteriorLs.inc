#include <YSI\y_hooks>

// Global interior define
#define MAPS_CLUBEXTERIORLS_INTERIOR      0
#define MAPS_CLUBINTERIORLS_INTERIOR      9

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// Clubvilla Interior points
#define CLUBINTERIORLS_DANCE_POINT        2325.3647, -1021.1942, 1050.2109
#define CLUBINTERIORLS_HEAL_POINT         2313.5750, -1008.9286, 1050.2109
#define CLUBINTERIORLS_WEAPONS_POINT      2324.6904, -1014.0570, 1050.2109
#define CLUBINTERIORLS_PEE_POINT          2321.2417, -1005.3172, 1054.7188
#define CLUBINTERIORLS_CLUBSHOP_POINT     2316.5325, -1010.7850, 1054.7188
#define CLUBINTERIORLOS_DRINKS_POINT      2313.3645, -1013.3300, 1050.2109

// Map variables
new pickup_clubInteriorLs[7];
new text3D_clubInteriorLs[6];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, CLUBINTERIORLS_EXIT_COORDS)) { // Club Exit
            SetPlayerInterior(playerid, MAPS_CLUBEXTERIORLS_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_MAIN);
            SetPlayerPos(playerid, CLUBINTERIORLS_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, CLUBINTERIORLS_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Pickups
    pickup_clubInteriorLs[0] = CreateDynamicPickup(1318, 1, CLUBINTERIORLS_EXIT_COORDS, VW_CLUBINTERIORLS, MAPS_CLUBINTERIORLS_INTERIOR); // Club Exit
    pickup_clubInteriorLs[1] = CreateDynamicPickup(1314, 1, CLUBINTERIORLS_DANCE_POINT, VW_CLUBINTERIORLS, MAPS_CLUBINTERIORLS_INTERIOR); // Club Dance
    pickup_clubInteriorLs[2] = CreateDynamicPickup(1240, 1, CLUBINTERIORLS_HEAL_POINT, VW_CLUBINTERIORLS, MAPS_CLUBINTERIORLS_INTERIOR); // Club Heal
    pickup_clubInteriorLs[3] = CreateDynamicPickup(1239, 1, CLUBINTERIORLS_WEAPONS_POINT, VW_CLUBINTERIORLS, MAPS_CLUBINTERIORLS_INTERIOR); // Club Weapon Shop
    pickup_clubInteriorLs[4] = CreateDynamicPickup(1239, 1, CLUBINTERIORLS_PEE_POINT, VW_CLUBINTERIORLS, MAPS_CLUBINTERIORLS_INTERIOR); // Club Pee
    pickup_clubInteriorLs[5] = CreateDynamicPickup(1275, 1, CLUBINTERIORLS_CLUBSHOP_POINT, VW_CLUBINTERIORLS, MAPS_CLUBINTERIORLS_INTERIOR); // Club shop
    pickup_clubInteriorLs[6] = CreateDynamicPickup(1239, 1, CLUBINTERIORLOS_DRINKS_POINT, VW_CLUBINTERIORLS, MAPS_CLUBINTERIORLS_INTERIOR); // Club drinks

    // 3DTextLabels
    text3D_clubInteriorLs[0] = _:CreateDynamic3DTextLabel("Club Tanzflaeche\n" COLOR_HEX_WHITE "Tippe /Clubdance 1-7", COLOR_YELLOW, CLUBINTERIORLS_DANCE_POINT, 8.0, .testlos = 1, .worldid = VW_CLUBINTERIORLS, .interiorid = MAPS_CLUBINTERIORLS_INTERIOR);
    text3D_clubInteriorLs[1] = _:CreateDynamic3DTextLabel("Club Kueche\n" COLOR_HEX_WHITE "Tippe /Clubheal", COLOR_YELLOW, CLUBINTERIORLS_HEAL_POINT, 8.0, .testlos = 1, .worldid = VW_CLUBINTERIORLS, .interiorid = MAPS_CLUBINTERIORLS_INTERIOR);
    text3D_clubInteriorLs[2] = _:CreateDynamic3DTextLabel("Club Waffenshop\n" COLOR_HEX_WHITE "Tippe /Clubwaffen", COLOR_YELLOW, CLUBINTERIORLS_WEAPONS_POINT, 8.0, .testlos = 1, .worldid = VW_CLUBINTERIORLS, .interiorid = MAPS_CLUBINTERIORLS_INTERIOR);
    text3D_clubInteriorLs[3] = _:CreateDynamic3DTextLabel("Club Toilette\n" COLOR_HEX_WHITE "Tippe /Pee", COLOR_YELLOW, CLUBINTERIORLS_PEE_POINT, 15.0, .testlos = 1, .worldid = VW_CLUBINTERIORLS, .interiorid = MAPS_CLUBINTERIORLS_INTERIOR);
    text3D_clubInteriorLs[4] = _:CreateDynamic3DTextLabel("Club-Garderobe\n" COLOR_HEX_WHITE "Tippe /Clubshop", COLOR_YELLOW, CLUBINTERIORLS_CLUBSHOP_POINT, 8.0, .testlos = 1, .worldid = VW_CLUBINTERIORLS, .interiorid = MAPS_CLUBINTERIORLS_INTERIOR);
    text3D_clubInteriorLs[5] = _:CreateDynamic3DTextLabel("Clubvilla Bar\n" COLOR_HEX_WHITE "Tippe /Getraenk", COLOR_BLUE, CLUBINTERIORLOS_DRINKS_POINT, 10.0, .testlos = 1, .worldid = VW_CLUBINTERIORLS, .interiorid = MAPS_CLUBINTERIORLS_INTERIOR);
}
