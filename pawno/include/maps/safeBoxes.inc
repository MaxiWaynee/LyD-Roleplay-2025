#include <YSI\y_hooks>

// Global interior define
#define MAPS_SAFEBOXES_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Safebox points
#define SAFEBOX_COORDS_LS   2349.7061, -1246.4760, 22.5000
#define SAFEBOX_COORDS_LV   1685.7469,  1746.1523, 10.8251
#define SAFEBOX_COORDS_SF	-1819.1998, -149.9040, 9.3984

// Map variables
new object_safeBoxes[3];
new pickup_safeBoxes[3];
new text3D_safeBoxes[3];
new actor_safeBoxes[3];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_safeBoxes[0] = CreateDynamicPickup(1279, 1, SAFEBOX_COORDS_LS, VW_MAIN, MAPS_SAFEBOXES_INTERIOR); // Safebox in LS
    pickup_safeBoxes[1] = CreateDynamicPickup(1279, 1, SAFEBOX_COORDS_LV, VW_MAIN, MAPS_SAFEBOXES_INTERIOR); // Safebox in LV
    pickup_safeBoxes[2] = CreateDynamicPickup(1279, 1, SAFEBOX_COORDS_SF, VW_MAIN, MAPS_SAFEBOXES_INTERIOR); // Safebox in SF

    // 3DTextLabels
    text3D_safeBoxes[0] = _:CreateDynamic3DTextLabel("Safebox Drogen/Waffenteile\n" COLOR_HEX_WHITE "Tippe /Safebox", COLOR_YELLOW, SAFEBOX_COORDS_LS, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SAFEBOXES_INTERIOR);
    text3D_safeBoxes[1] = _:CreateDynamic3DTextLabel("Safebox Drogen/Waffenteile\n" COLOR_HEX_WHITE "Tippe /Safebox", COLOR_YELLOW, SAFEBOX_COORDS_LV, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SAFEBOXES_INTERIOR);
    text3D_safeBoxes[2] = _:CreateDynamic3DTextLabel("Safebox Drogen/Waffenteile\n" COLOR_HEX_WHITE "Tippe /Safebox", COLOR_YELLOW, SAFEBOX_COORDS_SF, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SAFEBOXES_INTERIOR);

    // Actors
    actor_safeBoxes[0] = CreateDynamicActor(30, 2351.4250, -1248.0270, 22.5000, 90.00000, .worldid = VW_MAIN, .interiorid = MAPS_SAFEBOXES_INTERIOR); // Drugs guy LS
    ApplyDynamicActorAnimation(actor_safeBoxes[0], "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);
    actor_safeBoxes[1] = CreateDynamicActor(28, 1685.7761, 1745.2592, 10.8248, 4.2496, .worldid = VW_MAIN, .interiorid = MAPS_SAFEBOXES_INTERIOR); // Drugs guy LV
    ApplyDynamicActorAnimation(actor_safeBoxes[1], "GANGS", "leanIDLE", 4.0, 1, 0, 0, 0, 0);
    actor_safeBoxes[2] = CreateDynamicActor(28, -1822.3210,-149.2113,9.4056,176.3818, .worldid = VW_MAIN, .interiorid = MAPS_SAFEBOXES_INTERIOR); // Drugs guy SF
    ApplyDynamicActorAnimation(actor_safeBoxes[2], "GANGS", "leanIDLE", 4.0, 1, 0, 0, 0, 0);

    // Objects
    object_safeBoxes[0] = CreateDynamicObject(964, 1685.77026, 1743.99268, 9.81638,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAFEBOXES_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_safeBoxes[1] = CreateDynamicObject(964, 2351.33643, -1246.47656, 21.49561,   0.00000, 0.00000, 271.03580, VW_MAIN, MAPS_SAFEBOXES_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_safeBoxes[2] = CreateDynamicObject(964, -1819.1212, -148.8414, 8.4056,  0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAFEBOXES_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}