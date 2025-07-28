#include <YSI\y_hooks>

// Global interior define
#define MAPS_ALHAMBRAINTERIOR_INTERIOR      17

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Alhambra interior points
#define ALHAMBRAINTERIOR_BUYDRINK_POINT        499.7624, -20.8934, 1000.6797

// Map variables
new object_alhambraInterior[14];
new pickup_alhambraInterior[1];
new text3D_alhambraInterior[1];
new actor_alhambraInterior[2];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 1775, 496.0843, -23.5310,1000.6797, 50.0);
    RemoveBuildingForPlayer(playerid, 1776, 501.1219,- 2.1968,1000.6797, 50.0);
    RemoveBuildingForPlayer(playerid, 1436, 479.7224, -5.8711, 1002.0781, 50.0);
    RemoveBuildingForPlayer(playerid, 2670, 486.2123, -13.3752, 1000.6996, 100.0);
}
 
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_alhambraInterior[0] = CreateDynamicPickup(1239, 1, ALHAMBRAINTERIOR_BUYDRINK_POINT, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR);

    // 3DTextLabels
    text3D_alhambraInterior[0] = _:CreateDynamic3DTextLabel("Discobar\n" COLOR_HEX_WHITE "Tippe /Getraenk", COLOR_BLUE, ALHAMBRAINTERIOR_BUYDRINK_POINT, 17.0, .testlos = 1, .worldid = VW_ALHAMBRAINTERIOR, .interiorid = MAPS_ALHAMBRAINTERIOR_INTERIOR);

    // Actors
    actor_alhambraInterior[0] = CreateDynamicActor(12, 486.2123, -13.3752, 1000.6996, 355.5102, .worldid = VW_ALHAMBRAINTERIOR, .interiorid = MAPS_ALHAMBRAINTERIOR_INTERIOR); // dancing party girl
    ApplyDynamicActorAnimation(actor_alhambraInterior[0], "DANCING", "dnce_M_e", 2.1, 1, 0, 0, 0, 0);
    actor_alhambraInterior[1] = CreateDynamicActor(19, 487.4032, -2.0732, 1002.3828, 171.9808, .worldid = VW_ALHAMBRAINTERIOR, .interiorid = MAPS_ALHAMBRAINTERIOR_INTERIOR); // dancing DJ
    ApplyDynamicActorAnimation(actor_alhambraInterior[1], "DANCING", "dnce_M_b", 2.1, 1, 0, 0, 0, 0);

    // Objects
    object_alhambraInterior[0] = CreateDynamicObject(19128, 489.812439, -8.917880, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[1] = CreateDynamicObject(19128, 489.812439, -16.891893, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[2] = CreateDynamicObject(19128, 489.812439, -12.907896, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    
    object_alhambraInterior[3] = CreateDynamicObject(19128, 485.837738, -8.917880, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[4] = CreateDynamicObject(19128, 485.837738, -16.891893, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[5] = CreateDynamicObject(19128, 485.837738, -12.907896, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    
    object_alhambraInterior[6] = CreateDynamicObject(19128, 481.852570, -8.917880, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[7] = CreateDynamicObject(19128, 481.852570, -16.891893, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[8] = CreateDynamicObject(19128, 481.852570, -12.907896, 999.619324, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    
    object_alhambraInterior[9] = CreateDynamicObject(19926, 487.522675, -2.995593, 1001.368713, 0.000000, 0.000000, -90.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

    object_alhambraInterior[10] = CreateDynamicObject(1954, 487.204742, -3.001033, 1002.392822, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[11] = CreateDynamicObject(1958, 488.061249, -3.000943, 1002.342773, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[12] = CreateDynamicObject(1775, 503.035461, -1.404744, 1000.679688, 0.000000, 0.000000, 0.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraInterior[13] = CreateDynamicObject(1775, 496.272827, -24.374458, 1000.769775, 0.000000, 0.000000, 180.000000, VW_ALHAMBRAINTERIOR, MAPS_ALHAMBRAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}