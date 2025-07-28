#include <YSI\y_hooks>

// Global interior define
#define MAPS_BEACH_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 100.0;
static Float:DRAWDISTANCE   = 100.0;

// Beach points
#define BEACH_FIGHTINGSTYLE_POINT    660.3523, -1869.5139, 5.5537

// Map variables
new object_beach[75];
new pickup_beach[1];
new text3D_beach[1];
new actor_beach[3];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 1255, 658.2813, -1879.4688, 3.7734, 0.25);
    RemoveBuildingForPlayer(playerid, 1255, 660.3516, -1879.4688, 3.7734, 0.25);
    RemoveBuildingForPlayer(playerid, 1255, 672.6953, -1879.4688, 3.7734, 0.25);
    RemoveBuildingForPlayer(playerid, 1255, 674.7656, -1879.4688, 3.7734, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_beach[0] = CreateDynamicPickup(1985, 1, BEACH_FIGHTINGSTYLE_POINT + 2.0, VW_MAIN, MAPS_BEACH_INTERIOR);

    // 3DTextLabels
    text3D_beach[0] = _:CreateDynamic3DTextLabel("Kampfstil - lernen\n" COLOR_HEX_WHITE "Tippe /Kampfstil", COLOR_GREEN, BEACH_FIGHTINGSTYLE_POINT, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BEACH_INTERIOR);
    
    // Actors
    actor_beach[0] = CreateDynamicActor(49, 654.3685, -1869.4066, 5.5537, 181.1411, .worldid = VW_MAIN, .interiorid = MAPS_BEACH_INTERIOR); // old taichi man
    ApplyDynamicActorAnimation(actor_beach[0], "PARK", "Tai_Chi_Loop", 4.1, 1, 0, 0, 0, 0);
    actor_beach[1] = CreateDynamicActor(80, 658.9488, -1869.5322, 5.5537, 270.8179, .worldid = VW_MAIN, .interiorid = MAPS_BEACH_INTERIOR); // shadow boxing guy
    ApplyDynamicActorAnimation(actor_beach[1], "GYMNASIUM", "GYMshadowbox", 4.1, 1, 0, 0, 0, 0);
    actor_beach[2] = CreateDynamicActor(138, 674.3245, -1887.7700, 4.4291, 180.1046, .worldid = VW_MAIN, .interiorid = MAPS_BEACH_INTERIOR); // sun bathing bikini girl
    ApplyDynamicActorAnimation(actor_beach[2], "BEACH", "bather", 4.1, 1, 0, 0, 0, 0);
 
    // Objects
    object_beach[0] = CreateDynamicObject(18688,673.3351,-1892.4934,4.0405-2.0,0.0,0.0,0.0, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//Lagerfeuer
    object_beach[1] = CreateDynamicObject(18688,673.1330,-1893.4014,4.1773-2.0,0.0,0.0,0.0, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//Feuer2
    object_beach[2] = CreateDynamicObject(18688,674.7161,-1892.1681,4.1654-2.0,0.0,0.0,0.0, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//Feuer2
    object_beach[3] = CreateDynamicObject(18688,672.7610,-1891.5331,4.2136-2.0,0.0,0.0,0.0, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//Feuer2
    object_beach[4] = CreateDynamicObject(18688,672.7187,-1892.2153,4.0543-2.0,0.0,0.0,0.0, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//Feuer2
    object_beach[5] = CreateDynamicObject(1463, 673.09, -1893.05, 2.99, 8.00, 0.00, 0.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[6] = CreateDynamicObject(1463, 673.02, -1891.75, 2.99, 8.00, 0.00, 156.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[7] = CreateDynamicObject(1463, 674.16, -1892.40, 2.99, 8.00, 0.00, 69.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[8] = CreateDynamicObject(1255, 666.85, -1889.79, 3.43, 4.00, 0.00, -25.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[9] = CreateDynamicObject(1255, 666.85, -1893.29, 3.22, 4.00, 0.00, 25.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[10] = CreateDynamicObject(1255, 669.85, -1897.79, 2.93, 4.00, 0.00, 62.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[11] = CreateDynamicObject(1255, 674.41, -1897.79, 2.93, 4.00, 0.00, 113.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[12] = CreateDynamicObject(1255, 679.35, -1893.29, 3.18, -3.00, 0.00, -193.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[13] = CreateDynamicObject(1255, 678.35, -1889.79, 3.39, -4.00, 0.00, -156.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[14] = CreateDynamicObject(1255, 674.25, -1887.79, 3.50, 1.00, 0.00, -91.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[15] = CreateDynamicObject(1255, 671.85, -1887.79, 3.48, 2.00, 0.00, -91.00, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[16] = CreateDynamicObject(620, 662.45, -1887.27, -2.40, 356.86, 0.00, -2.86, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[17] = CreateDynamicObject(620, 662.45, -1891.27, -4.40, 356.86, 0.00, -2.86, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[18] = CreateDynamicObject(621, 656.63, -1889.43, 0.05, 356.86, 0.00, -3.14, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[19] = CreateDynamicObject(647, 655.41, -1889.78, 4.41, 356.86, 0.00, -2.30, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[20] = CreateDynamicObject(647, 658.41, -1889.78, 4.41, 356.86, 0.00, -2.30, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[21] = CreateDynamicObject(647, 658.41, -1887.28, 4.41, 356.86, 0.00, -2.30, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[22] = CreateDynamicObject(620, 662.45, -1899.27, -2.40, 356.86, 0.00, -2.86, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[23] = CreateDynamicObject(621, 659.63, -1896.43, 0.05, 356.86, 0.00, -3.14, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[24] = CreateDynamicObject(647, 661.91, -1895.78, 4.41, 356.86, 0.00, -2.30, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[25] = CreateDynamicObject(647, 661.91, -1891.78, 4.41, 356.86, 0.00, -2.30, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[26] = CreateDynamicObject(647, 660.91, -1893.78, 4.41, 356.86, 0.00, -2.30, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_beach[27] = CreateDynamicObject(712, 686.45, -1877.07, 12.83, 3.14, 0.00, 2.71, VW_MAIN, MAPS_BEACH_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}