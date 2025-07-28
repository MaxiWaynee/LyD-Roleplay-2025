#include <YSI\y_hooks>

// Global interior define
#define MAPS_EVIDENCEROOMEXTERIOR_INTERIOR  0
#define MAPS_EVIDENCEROOMINTERIOR_INTERIOR 18

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Evidence room interior points
#define EVIDENCEROOM_INTERIOR_EXIT_COORDS   1249.2776, -14.6761, 1001.0366
#define EVIDENCEROOM_INTERIOR_ENTER_COORDS  1798.3326, -1578.8495, 14.0915
#define EVIDENCEROOM_INTERIOR_HEIST_P       1253.3943, -14.9542, 1001.0326

#define EVIDENCEROOM_INTERIOR_ENTER_FACING  270.0
#define EVIDENCEROOM_INTERIOR_EXIT_FACING   270.0

// Map variables
new object_evidenceroomInterior[328];
new pickup_evidenceroomInterior[2];
new text3D_evidenceroomInterior[2];
new object_door_evroomInterior;
new object_door_evroomInterior2;

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, EVIDENCEROOM_INTERIOR_EXIT_COORDS)) { // Exit
            SetPlayerPos(playerid, EVIDENCEROOM_INTERIOR_ENTER_COORDS);
            SetPlayerInterior(playerid, MAPS_EVIDENCEROOMEXTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_MAIN);
            SetPlayerFacingAngle(playerid, EVIDENCEROOM_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            if (g_evidenceRoomHeist[EVIDENCEROOM_HEIST_STATUS] == EVIDENCEROOM_STATUS_ONGOING && g_evidenceRoomHeist[EVIDENCEROOM_HEIST_RAIDER] == playerid) {
                KillTimer(g_evidenceRoomHeist[EVIDENCEROOM_HEIST_TIMER]);
                g_evidenceRoomHeist[EVIDENCEROOM_HEIST_TIMER] = INVALID_TIMER_ID;
                EvidenceRoomHeistFinished();
            }
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 2.0, EVIDENCEROOM_INTERIOR_ENTER_COORDS)) { // Enter
            if (g_evidenceRoomHeist[EVIDENCEROOM_HEIST_STATUS] == EVIDENCEROOM_STATUS_ONGOING && !IsPlayerExecutive(playerid))
                return SendClientMessage(playerid,COLOR_RED,"Du kannst die Asservatenkammer nicht betreten, weil die Polizei aufgrund eines Überfalles die Kammer gesperrt hat!");
            
            Streamer_UpdateEx(playerid, EVIDENCEROOM_INTERIOR_EXIT_COORDS, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, STREAMER_TYPE_OBJECT);
            SetPlayerPos(playerid, EVIDENCEROOM_INTERIOR_EXIT_COORDS);
            SetPlayerInterior(playerid, MAPS_EVIDENCEROOMINTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_EVIDENCEROOMINTERIOR);
            SetPlayerFacingAngle(playerid, EVIDENCEROOM_INTERIOR_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_evidenceroomInterior[0] = CreateDynamicPickup(19197, 1, EVIDENCEROOM_INTERIOR_EXIT_COORDS, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR); // Exit
    pickup_evidenceroomInterior[1] = CreateDynamicPickup(19197, 1, EVIDENCEROOM_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_EVIDENCEROOMEXTERIOR_INTERIOR); // Enter

    // 3DTextLabels
    text3D_evidenceroomInterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "ASSERVATENKAMMER\nDER BEHÖRDEN\n" COLOR_HEX_BLUE "Betreten mit 'Enter'", COLOR_WHITE, EVIDENCEROOM_INTERIOR_ENTER_COORDS, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_EVIDENCEROOMEXTERIOR_INTERIOR); // Entrance
    text3D_evidenceroomInterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_WHITE "Starte einen Überfall mit\n" COLOR_HEX_RED "/Kammerausrauben", COLOR_WHITE, EVIDENCEROOM_INTERIOR_HEIST_P, 13.0, .testlos = 1, .worldid = VW_EVIDENCEROOMINTERIOR, .interiorid = MAPS_EVIDENCEROOMINTERIOR_INTERIOR); // Heist Point

	// Objects
    object_evidenceroomInterior[0] = CreateDynamicObject(19465, 1263.0842, -17.7056, 1002.4569, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[0], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[1] = CreateDynamicObject(1499, 1248.1499, -15.3849, 999.8004, 0.0000, 0.0000, 90.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT05
    object_evidenceroomInterior[2] = CreateDynamicObject(19381, 1252.8332, -32.2686, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[2], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[3] = CreateDynamicObject(19381, 1262.4631, -32.2686, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[3], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[4] = CreateDynamicObject(19381, 1252.8332, -7.3586, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[4], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[5] = CreateDynamicObject(19381, 1272.0920, -32.2686, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[5], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[6] = CreateDynamicObject(19381, 1262.4625, -7.3586, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[6], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[7] = CreateDynamicObject(19381, 1281.7115, -32.2686, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[7], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[8] = CreateDynamicObject(19381, 1272.0631, -7.3586, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[8], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[9] = CreateDynamicObject(19381, 1291.3319, -32.2686, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[9], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[10] = CreateDynamicObject(19381, 1281.6944, -7.3586, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[10], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[11] = CreateDynamicObject(19381, 1291.3266, -7.3586, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[11], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[12] = CreateDynamicObject(19381, 1300.9564, -7.3586, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[12], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[13] = CreateDynamicObject(19381, 1305.1645, -12.2051, 1005.1035, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[13], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[14] = CreateDynamicObject(19381, 1300.9521, -32.2686, 1005.1035, 0.0000, 0.0000, -89.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[14], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[15] = CreateDynamicObject(19381, 1305.1639, -21.8334, 1005.1035, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[15], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[16] = CreateDynamicObject(19381, 1248.0155, -12.2334, 1005.1035, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[16], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[17] = CreateDynamicObject(19381, 1305.1604, -31.4619, 1005.1035, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[17], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[18] = CreateDynamicObject(19381, 1248.0155, -21.8435, 1005.1035, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[18], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[19] = CreateDynamicObject(19381, 1248.0155, -31.4636, 1005.1035, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[19], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[20] = CreateDynamicObject(19464, 1251.3020, -17.7296, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[20], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[21] = CreateDynamicObject(19464, 1257.0018, -12.0396, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[21], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[22] = CreateDynamicObject(19381, 1273.9748, -8.2136, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[22], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[23] = CreateDynamicObject(19465, 1260.3557, -20.5757, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[23], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[24] = CreateDynamicObject(2886, 1248.0848, -13.6927, 1001.3966, 0.0000, 0.0000, 91.1997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sec_keypad
    object_evidenceroomInterior[25] = CreateDynamicObject(19465, 1260.3557, -26.5158, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[25], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[26] = CreateDynamicObject(19464, 1265.9123, -20.5496, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[26], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[27] = CreateDynamicObject(19464, 1257.2320, -17.7296, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[27], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[28] = CreateDynamicObject(19464, 1260.3514, -32.4496, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[28], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[29] = CreateDynamicObject(19464, 1257.4914, -23.5496, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[29], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[30] = CreateDynamicObject(19464, 1245.5903, -23.5496, 1002.4641, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[30], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[31] = CreateDynamicObject(19465, 1251.5642, -23.5457, 1002.4569, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[31], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[32] = CreateDynamicObject(19464, 1245.3911, -17.7296, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[32], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[33] = CreateDynamicObject(19465, 1265.9156, -26.4757, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[33], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[34] = CreateDynamicObject(19464, 1265.9123, -32.4196, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[34], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[35] = CreateDynamicObject(19464, 1263.1225, -32.1696, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[35], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[36] = CreateDynamicObject(19465, 1265.9156, -14.8758, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[36], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[37] = CreateDynamicObject(1495, 1262.1549, -12.0230, 999.9484, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT01
    object_evidenceroomInterior[38] = CreateDynamicObject(19464, 1257.0018, -12.0396, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[38], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[39] = CreateDynamicObject(19464, 1265.9123, -8.9496, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[39], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[40] = CreateDynamicObject(19464, 1268.9626, -32.1696, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[40], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[41] = CreateDynamicObject(19464, 1271.7928, -29.0694, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[41], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[42] = CreateDynamicObject(19464, 1271.7928, -11.2896, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[42], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[43] = CreateDynamicObject(19465, 1271.8065, -23.1357, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[43], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[44] = CreateDynamicObject(19465, 1271.8065, -17.2056, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[44], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[45] = CreateDynamicObject(19464, 1271.7928, -5.3796, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[45], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[46] = CreateDynamicObject(19464, 1268.9626, -7.3895, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[46], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[47] = CreateDynamicObject(19464, 1274.8514, -20.2595, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[47], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[48] = CreateDynamicObject(19464, 1280.7613, -20.2595, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[48], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[49] = CreateDynamicObject(19464, 1286.6716, -20.2595, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[49], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[50] = CreateDynamicObject(19465, 1289.7568, -29.0858, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[50], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[51] = CreateDynamicObject(19465, 1289.7370, -11.2856, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[51], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[52] = CreateDynamicObject(19464, 1289.7342, -17.2096, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[52], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[53] = CreateDynamicObject(19464, 1289.7342, -5.3596, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[53], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[54] = CreateDynamicObject(19464, 1289.7342, -23.1595, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[54], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[55] = CreateDynamicObject(1271, 1255.2412, -20.7891, 1000.2357, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    object_evidenceroomInterior[56] = CreateDynamicObject(19465, 1274.8640, -26.3257, 1002.4569, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[56], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[57] = CreateDynamicObject(19464, 1277.7430, -29.4095, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[57], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[58] = CreateDynamicObject(19465, 1262.9162, -12.0657, 1002.4569, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[58], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[59] = CreateDynamicObject(19464, 1274.8629, -32.1696, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[59], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[60] = CreateDynamicObject(19465, 1292.8634, -26.2458, 1002.4569, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[60], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[61] = CreateDynamicObject(19465, 1295.7174, -29.0858, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[61], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[62] = CreateDynamicObject(19464, 1295.7246, -23.1595, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[62], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[63] = CreateDynamicObject(2921, 1248.3402, -17.6056, 1003.9207, 0.0000, 0.0000, -91.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_evidenceroomInterior[64] = CreateDynamicObject(19464, 1292.8115, -20.2595, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[64], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[65] = CreateDynamicObject(19464, 1295.7053, -17.2096, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[65], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[66] = CreateDynamicObject(19465, 1277.6966, -11.2458, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[66], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[67] = CreateDynamicObject(19464, 1277.7032, -17.1795, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[67], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[68] = CreateDynamicObject(19464, 1277.7032, -5.3495, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[68], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[69] = CreateDynamicObject(1616, 1265.4062, -16.5265, 1004.4063, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[70] = CreateDynamicObject(19465, 1277.7463, -23.2558, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[70], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[71] = CreateDynamicObject(19464, 1298.8116, -26.2595, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[71], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[72] = CreateDynamicObject(19465, 1304.1518, -26.2558, 1002.4569, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[72], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[73] = CreateDynamicObject(1616, 1259.8209, -22.7324, 1004.7515, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[74] = CreateDynamicObject(19465, 1295.7174, -11.2856, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[74], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[75] = CreateDynamicObject(19464, 1274.8027, -7.3895, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[75], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[76] = CreateDynamicObject(19464, 1280.8127, -7.3895, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[76], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[77] = CreateDynamicObject(1616, 1248.4842, -24.0466, 1004.5017, 0.0000, 0.0000, -179.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[78] = CreateDynamicObject(2969, 1297.7253, -7.6953, 1000.0197, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //level_ammobox
    object_evidenceroomInterior[79] = CreateDynamicObject(19464, 1286.6925, -7.3895, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[79], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[80] = CreateDynamicObject(1622, 1271.1103, -31.5711, 1004.2506, 0.0000, 0.0000, -86.8000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam2_01
    object_evidenceroomInterior[81] = CreateDynamicObject(1622, 1266.5781, -7.8400, 1004.7512, 0.0000, 0.0000, 98.6997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam2_01
    object_evidenceroomInterior[82] = CreateDynamicObject(19464, 1295.7053, -5.3596, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[82], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[83] = CreateDynamicObject(19465, 1304.1518, -14.1156, 1002.4569, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[83], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[84] = CreateDynamicObject(19464, 1298.8116, -14.1096, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[84], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[85] = CreateDynamicObject(19464, 1305.1550, -29.0396, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[85], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[86] = CreateDynamicObject(19465, 1301.7370, -23.1457, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[86], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[87] = CreateDynamicObject(1616, 1277.2119, -19.8099, 1004.5772, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[88] = CreateDynamicObject(19464, 1301.7353, -17.2096, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[88], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[89] = CreateDynamicObject(1616, 1289.2231, -14.6799, 1004.5772, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[90] = CreateDynamicObject(19464, 1305.1461, -17.2096, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[90], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[91] = CreateDynamicObject(19464, 1305.1550, -23.1196, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[91], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[92] = CreateDynamicObject(19175, 1265.7945, -14.9134, 1003.1707, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterial(object_evidenceroomInterior[92], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_evidenceroomInterior[92], 1, "Asservatenkammer", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
    object_evidenceroomInterior[93] = CreateDynamicObject(1616, 1295.2059, -14.7944, 1004.5261, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[94] = CreateDynamicObject(19464, 1302.0517, -32.0796, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[94], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[95] = CreateDynamicObject(19464, 1296.1114, -32.0796, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[95], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[96] = CreateDynamicObject(1616, 1300.7800, -7.7651, 1004.5261, 0.0000, 0.0000, 82.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[97] = CreateDynamicObject(19464, 1290.1617, -32.0796, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[97], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[98] = CreateDynamicObject(19464, 1284.2303, -32.0796, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[98], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[99] = CreateDynamicObject(19464, 1278.3404, -32.0996, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[99], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[100] = CreateDynamicObject(1616, 1296.1853, -19.7437, 1004.5261, 0.0000, 0.0000, -176.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[101] = CreateDynamicObject(19464, 1292.7817, -7.3895, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[101], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[102] = CreateDynamicObject(19464, 1298.8116, -7.3895, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[102], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[103] = CreateDynamicObject(1616, 1296.1899, -26.9090, 1004.5261, 0.0000, 0.0000, -176.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[104] = CreateDynamicObject(19464, 1304.7226, -7.3895, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[104], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[105] = CreateDynamicObject(1616, 1282.0854, -31.5993, 1004.5261, 0.0000, 0.0000, -94.7001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[106] = CreateDynamicObject(19464, 1305.1456, -11.0495, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[106], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[107] = CreateDynamicObject(19464, 1305.1456, -5.1096, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[107], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[108] = CreateDynamicObject(1616, 1260.7854, -31.7816, 1004.5261, 0.0000, 0.0000, -97.2997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_evidenceroomInterior[109] = CreateDynamicObject(3066, 1283.8105, -18.6949, 1000.9472, 0.0000, 0.0000, 90.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ammotrn_obj
    object_evidenceroomInterior[110] = CreateDynamicObject(19464, 1257.2021, -32.1696, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[110], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[111] = CreateDynamicObject(19464, 1251.2821, -32.1696, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[111], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[112] = CreateDynamicObject(19464, 1245.3409, -32.1696, 1002.4541, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[112], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[113] = CreateDynamicObject(19464, 1248.0107, -20.8096, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[113], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[114] = CreateDynamicObject(19464, 1248.0107, -26.7296, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[114], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[115] = CreateDynamicObject(19464, 1248.0107, -32.6394, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[115], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[116] = CreateDynamicObject(19464, 1248.0107, -9.0495, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[116], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[117] = CreateDynamicObject(2359, 1257.0288, -18.1165, 1002.0880, 0.0000, 0.0000, -4.3000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
    object_evidenceroomInterior[118] = CreateDynamicObject(14782, 1257.0842, -18.2465, 1000.8427, 0.0000, 0.0000, 0.1000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int3int_boxing30
    object_evidenceroomInterior[119] = CreateDynamicObject(2502, 1253.0040, -17.9927, 999.4946, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_5
    object_evidenceroomInterior[120] = CreateDynamicObject(2002, 1276.9095, -31.4158, 999.9165, 0.0000, 0.0000, -135.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
    object_evidenceroomInterior[121] = CreateDynamicObject(19419, 1273.3160, -30.8927, 1001.9552, 0.0000, 0.0000, 63.7000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_lights01
    object_evidenceroomInterior[122] = CreateDynamicObject(1421, 1269.0559, -31.3484, 1000.6566, 0.0000, 0.0000, 174.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BOXES
    object_evidenceroomInterior[123] = CreateDynamicObject(19419, 1274.1682, -31.5349, 1000.6785, 0.0000, 72.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_lights01
    object_evidenceroomInterior[124] = CreateDynamicObject(19419, 1272.2301, -31.1798, 1001.9453, 0.0000, 0.0000, -80.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_lights01
    object_evidenceroomInterior[125] = CreateDynamicObject(1436, 1249.3645, -31.2653, 1000.5855, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_SCAFFOLD_2
    object_evidenceroomInterior[126] = CreateDynamicObject(2463, 1260.1208, -28.0083, 1000.2689, 0.0000, 0.0000, -89.4000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_2
    object_evidenceroomInterior[127] = CreateDynamicObject(2737, 1277.5826, -28.5317, 1001.6890, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB_car
    object_evidenceroomInterior[128] = CreateDynamicObject(348, 1252.7154, -18.3176, 1000.5781, -94.0998, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_evidenceroomInterior[129] = CreateDynamicObject(2463, 1260.1489, -30.4682, 1000.2689, 0.0000, 0.0000, -89.4000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_2
    object_evidenceroomInterior[130] = CreateDynamicObject(2060, 1296.3785, -16.5876, 1000.9890, 0.0000, 0.0000, -11.6997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SANDBAG
    object_evidenceroomInterior[131] = CreateDynamicObject(2060, 1296.3785, -17.2276, 1000.9890, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SANDBAG
    object_evidenceroomInterior[132] = CreateDynamicObject(1893, 1251.0433, -19.6926, 1005.0167, 0.0000, 0.0000, -90.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[133] = CreateDynamicObject(2043, 1253.4425, -18.2108, 1000.6643, 0.0000, 0.0000, 62.7000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M4
    object_evidenceroomInterior[134] = CreateDynamicObject(3013, 1259.9890, -27.7807, 1001.1942, 0.0000, 0.0000, -89.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_ammobox
    object_evidenceroomInterior[135] = CreateDynamicObject(19464, 1248.0107, -14.9794, 1002.4541, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[135], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[136] = CreateDynamicObject(2358, 1296.9829, -7.7052, 1000.4863, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    object_evidenceroomInterior[137] = CreateDynamicObject(19464, 1251.1009, -7.4696, 1002.4541, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[137], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[138] = CreateDynamicObject(3800, 1296.4033, -20.5508, 999.8828, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[139] = CreateDynamicObject(2038, 1252.6285, -18.0060, 1000.6279, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_S2
    object_evidenceroomInterior[140] = CreateDynamicObject(3013, 1259.9890, -28.3994, 1001.1942, 0.0000, 0.0000, -89.9999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_ammobox
    object_evidenceroomInterior[141] = CreateDynamicObject(19464, 1257.0310, -7.4696, 1002.4541, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[141], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[142] = CreateDynamicObject(19464, 1262.9503, -7.4696, 1002.4541, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_evidenceroomInterior[142], 0, 14846, "genintintpoliceb", "breezewall2", 0xFFFFFFFF);
    object_evidenceroomInterior[143] = CreateDynamicObject(3013, 1259.9890, -28.3994, 1000.8637, 0.0000, 0.0000, -89.9999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_ammobox
    object_evidenceroomInterior[144] = CreateDynamicObject(1575, 1259.9587, -27.8756, 1001.7669, 0.0000, 0.0000, -89.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_evidenceroomInterior[145] = CreateDynamicObject(3013, 1259.9890, -27.7695, 1000.8637, 0.0000, 0.0000, -89.9999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_ammobox
    object_evidenceroomInterior[146] = CreateDynamicObject(1421, 1270.7154, -31.3504, 1000.6566, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BOXES
    object_evidenceroomInterior[147] = CreateDynamicObject(1421, 1267.2502, -31.2462, 1000.6566, 0.0000, 0.0000, 18.7000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BOXES
    object_evidenceroomInterior[148] = CreateDynamicObject(1575, 1259.9658, -28.5956, 1001.7669, 0.0000, 0.0000, -89.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_evidenceroomInterior[149] = CreateDynamicObject(2475, 1248.2458, -18.8773, 1000.6151, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
    object_evidenceroomInterior[150] = CreateDynamicObject(1575, 1259.9658, -28.5956, 1001.3964, 0.0000, 0.0000, -89.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_evidenceroomInterior[151] = CreateDynamicObject(1575, 1259.9571, -27.8358, 1001.3964, 0.0000, 0.0000, -89.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_evidenceroomInterior[152] = CreateDynamicObject(1578, 1260.0063, -30.4337, 1001.0498, 0.0000, 0.0000, -90.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
    object_evidenceroomInterior[153] = CreateDynamicObject(2475, 1248.2458, -20.3673, 1000.6151, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
    object_evidenceroomInterior[154] = CreateDynamicObject(2475, 1248.2458, -21.8572, 1000.6151, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
    object_evidenceroomInterior[155] = CreateDynamicObject(3796, 1279.7357, -30.1452, 999.9019, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox1_SFS
    object_evidenceroomInterior[156] = CreateDynamicObject(362, 1248.3957, -22.0027, 1001.2708, 0.0000, 30.5000, 94.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun
    object_evidenceroomInterior[157] = CreateDynamicObject(1576, 1278.3625, -31.6170, 999.9796, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
    object_evidenceroomInterior[158] = CreateDynamicObject(1578, 1260.0052, -31.0837, 1001.0498, 0.0000, 0.0000, -90.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
    object_evidenceroomInterior[159] = CreateDynamicObject(1576, 1278.9132, -31.6170, 999.9796, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
    object_evidenceroomInterior[160] = CreateDynamicObject(1578, 1260.0052, -31.0837, 1001.3900, 0.0000, 0.0000, -90.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
    object_evidenceroomInterior[161] = CreateDynamicObject(1576, 1279.4536, -31.6170, 999.9796, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
    object_evidenceroomInterior[162] = CreateDynamicObject(1576, 1279.9934, -31.6170, 999.9796, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
    object_evidenceroomInterior[163] = CreateDynamicObject(1578, 1260.0052, -30.3537, 1001.3900, 0.0000, 0.0000, -90.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
    object_evidenceroomInterior[164] = CreateDynamicObject(1576, 1278.3332, -31.4869, 1000.0797, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
    object_evidenceroomInterior[165] = CreateDynamicObject(1575, 1278.3717, -31.2663, 999.9545, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_evidenceroomInterior[166] = CreateDynamicObject(1575, 1278.9022, -31.2663, 999.9545, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_evidenceroomInterior[167] = CreateDynamicObject(1575, 1279.4123, -31.2663, 999.9545, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_evidenceroomInterior[168] = CreateDynamicObject(1579, 1260.0063, -31.0701, 1001.7730, 0.0000, 0.0000, -93.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_blue
    object_evidenceroomInterior[169] = CreateDynamicObject(1436, 1251.7949, -31.2653, 1000.5855, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_SCAFFOLD_2
    object_evidenceroomInterior[170] = CreateDynamicObject(1579, 1260.0455, -30.3512, 1001.7730, 0.0000, 0.0000, -93.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_blue
    object_evidenceroomInterior[171] = CreateDynamicObject(1436, 1254.2248, -31.2653, 1000.5855, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_SCAFFOLD_2
    object_evidenceroomInterior[172] = CreateDynamicObject(1436, 1256.6551, -31.2653, 1000.5855, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_SCAFFOLD_2
    object_evidenceroomInterior[173] = CreateDynamicObject(14782, 1286.3822, -31.5676, 1000.9193, 0.0000, 0.0000, 179.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int3int_boxing30
    object_evidenceroomInterior[174] = CreateDynamicObject(2605, 1289.0765, -21.4073, 1000.2998, 0.0000, 0.0000, -89.2997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLCE_DESK1
    object_evidenceroomInterior[175] = CreateDynamicObject(358, 1256.5958, -31.1135, 1000.8618, 64.5000, -5.0000, 11.9997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    object_evidenceroomInterior[176] = CreateDynamicObject(362, 1248.4503, -19.3983, 1001.1823, 0.0000, 30.5000, 94.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun
    object_evidenceroomInterior[177] = CreateDynamicObject(2607, 1289.1341, -23.3913, 1000.2902, 0.0000, 0.0000, 89.6996, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLCE_DESK2
    object_evidenceroomInterior[178] = CreateDynamicObject(2043, 1248.4333, -18.2658, 1001.5338, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M4
    object_evidenceroomInterior[179] = CreateDynamicObject(2608, 1289.3957, -21.3715, 1002.1776, 0.0000, 0.0000, -88.9999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLCE_SHELF
    object_evidenceroomInterior[180] = CreateDynamicObject(356, 1248.2497, -19.7457, 1001.5711, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    object_evidenceroomInterior[181] = CreateDynamicObject(348, 1253.7651, -31.2455, 1000.8300, 87.0998, 1.3998, -61.5998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_evidenceroomInterior[182] = CreateDynamicObject(351, 1248.3363, -21.8798, 1001.5125, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shotgspa
    object_evidenceroomInterior[183] = CreateDynamicObject(2356, 1287.9499, -21.7758, 999.9135, 0.0000, 0.0000, -64.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_OFF_CHAIR
    object_evidenceroomInterior[184] = CreateDynamicObject(348, 1254.2181, -31.2278, 1000.8892, -90.5998, 5.8997, -126.3000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_evidenceroomInterior[185] = CreateDynamicObject(2356, 1288.7568, -23.3936, 999.8967, 0.0000, 0.0000, -91.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_OFF_CHAIR
    object_evidenceroomInterior[186] = CreateDynamicObject(353, 1248.2950, -21.3556, 1002.2738, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mp5lng
    object_evidenceroomInterior[187] = CreateDynamicObject(353, 1248.2950, -20.4556, 1002.2738, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mp5lng
    object_evidenceroomInterior[188] = CreateDynamicObject(353, 1248.2950, -19.4957, 1002.2738, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mp5lng
    object_evidenceroomInterior[189] = CreateDynamicObject(2616, 1292.7104, -31.9183, 1002.2163, 0.0000, 0.0000, 179.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB04
    object_evidenceroomInterior[190] = CreateDynamicObject(353, 1248.2950, -18.6056, 1002.2738, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mp5lng
    object_evidenceroomInterior[191] = CreateDynamicObject(2043, 1255.0266, -31.4437, 1000.9238, 0.0000, 0.0000, -113.5998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M4
    object_evidenceroomInterior[192] = CreateDynamicObject(348, 1248.4027, -20.7905, 1001.5499, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_evidenceroomInterior[193] = CreateDynamicObject(2615, 1293.1722, -31.9160, 1002.2163, 0.0000, 0.0000, 179.6999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB3
    object_evidenceroomInterior[194] = CreateDynamicObject(3800, 1290.3730, -21.1096, 999.9027, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[195] = CreateDynamicObject(3800, 1291.4829, -21.1096, 999.9027, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[196] = CreateDynamicObject(3800, 1290.4023, -22.3596, 999.9027, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[197] = CreateDynamicObject(3800, 1290.4023, -21.1096, 1001.0133, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[198] = CreateDynamicObject(2567, 1302.3806, -8.6252, 1001.7929, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ab_warehouseShelf
    object_evidenceroomInterior[199] = CreateDynamicObject(3800, 1295.0428, -20.9696, 999.9027, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[200] = CreateDynamicObject(3800, 1295.0428, -22.2096, 999.9027, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[201] = CreateDynamicObject(3800, 1295.0428, -22.2096, 1000.9926, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[202] = CreateDynamicObject(2358, 1296.2220, -7.7052, 1000.0258, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    object_evidenceroomInterior[203] = CreateDynamicObject(2358, 1296.9929, -7.7052, 1000.0258, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    object_evidenceroomInterior[204] = CreateDynamicObject(2358, 1296.2722, -7.7052, 1000.2561, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    object_evidenceroomInterior[205] = CreateDynamicObject(2358, 1297.0727, -7.7052, 1000.2561, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    object_evidenceroomInterior[206] = CreateDynamicObject(2358, 1296.2220, -7.7052, 1000.4863, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    object_evidenceroomInterior[207] = CreateDynamicObject(3800, 1296.4033, -19.3509, 999.8828, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[208] = CreateDynamicObject(3800, 1296.4033, -16.8908, 999.8828, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[209] = CreateDynamicObject(3800, 1296.4033, -18.1408, 999.8828, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    object_evidenceroomInterior[210] = CreateDynamicObject(3798, 1272.8797, -31.0590, 999.9013, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox3_SFS
    object_evidenceroomInterior[211] = CreateDynamicObject(2060, 1296.3691, -18.0153, 1000.9890, 0.0000, 0.0000, 13.1000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SANDBAG
    object_evidenceroomInterior[212] = CreateDynamicObject(2060, 1296.3105, -18.7784, 1000.9890, 0.0000, 0.0000, -1.2999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SANDBAG
    object_evidenceroomInterior[213] = CreateDynamicObject(2060, 1296.2976, -19.3483, 1000.9890, 0.0000, 0.0000, -1.2999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SANDBAG
    object_evidenceroomInterior[214] = CreateDynamicObject(2060, 1296.3077, -19.0284, 1001.1593, 0.0000, 0.0000, -91.7997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SANDBAG
    object_evidenceroomInterior[215] = CreateDynamicObject(2060, 1297.2312, -19.4493, 1000.3850, 0.0000, 63.1999, -1.2999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SANDBAG
    object_evidenceroomInterior[216] = CreateDynamicObject(1264, 1296.4564, -20.5708, 1001.3770, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlackBag1
    object_evidenceroomInterior[217] = CreateDynamicObject(3015, 1298.4105, -7.7522, 1000.0155, 0.0000, 0.0000, 179.6000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_cratestack
    object_evidenceroomInterior[218] = CreateDynamicObject(1264, 1296.4564, -21.7607, 1000.3765, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlackBag1
    object_evidenceroomInterior[219] = CreateDynamicObject(19419, 1274.2976, -30.9647, 1000.6146, 0.0000, 60.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_lights01
    object_evidenceroomInterior[220] = CreateDynamicObject(1264, 1297.5566, -20.9407, 1000.3765, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlackBag1
    object_evidenceroomInterior[221] = CreateDynamicObject(3015, 1299.1412, -7.7571, 1000.0255, 0.0000, 0.0000, 179.6000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_cratestack
    object_evidenceroomInterior[222] = CreateDynamicObject(19166, 1297.1645, -13.9455, 1002.3972, 90.4999, 96.0998, 83.0998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap3
    object_evidenceroomInterior[223] = CreateDynamicObject(19942, 1288.8553, -22.6665, 1000.7332, -90.5998, 2.4999, -53.2999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceRadio1
    object_evidenceroomInterior[224] = CreateDynamicObject(18637, 1288.6866, -22.0207, 1000.5170, 82.2997, 0.0000, -86.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceShield1
    object_evidenceroomInterior[225] = CreateDynamicObject(2985, 1259.8037, -23.0611, 999.8997, 0.0000, 0.0000, 178.5000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun_base
    object_evidenceroomInterior[226] = CreateDynamicObject(19970, 1300.3072, -15.2171, 999.8311, -20.7999, 20.5000, -2.4000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign23
    object_evidenceroomInterior[227] = CreateDynamicObject(1722, 1272.1236, -27.7509, 999.9143, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_evidenceroomInterior[228] = CreateDynamicObject(2567, 1269.0677, -8.5228, 1001.8281, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ab_warehouseShelf
    object_evidenceroomInterior[229] = CreateDynamicObject(1722, 1272.1236, -28.4909, 999.9143, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_evidenceroomInterior[230] = CreateDynamicObject(19970, 1300.2939, -15.5391, 999.7708, -20.7999, 20.5000, -2.4000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign23
    object_evidenceroomInterior[231] = CreateDynamicObject(1722, 1272.1236, -29.5109, 999.9143, 0.0000, 0.0000, -69.4000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_evidenceroomInterior[232] = CreateDynamicObject(19970, 1300.3044, -15.6175, 999.5665, -20.7999, 20.5000, -2.4000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign23
    object_evidenceroomInterior[233] = CreateDynamicObject(1722, 1272.1236, -27.0009, 999.9143, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_evidenceroomInterior[234] = CreateDynamicObject(2977, 1288.9648, -8.1801, 999.7954, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
    object_evidenceroomInterior[235] = CreateDynamicObject(2977, 1287.3840, -8.1801, 999.7954, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
    object_evidenceroomInterior[236] = CreateDynamicObject(19419, 1272.5843, -31.0610, 1001.9552, 0.0000, 0.0000, 101.5000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_lights01
    object_evidenceroomInterior[237] = CreateDynamicObject(19965, 1299.9801, -15.6878, 999.8892, -26.6000, 20.8999, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign18
    object_evidenceroomInterior[238] = CreateDynamicObject(19419, 1272.8514, -31.0277, 1002.1054, 0.0000, 0.0000, -8.1997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_lights01
    object_evidenceroomInterior[239] = CreateDynamicObject(964, 1286.1307, -8.1985, 999.8861, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_METAL_CRATE
    object_evidenceroomInterior[240] = CreateDynamicObject(1237, 1296.3164, -26.9199, 999.8839, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_evidenceroomInterior[241] = CreateDynamicObject(964, 1284.5594, -8.1985, 999.9061, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_METAL_CRATE
    object_evidenceroomInterior[242] = CreateDynamicObject(1237, 1297.3270, -26.9199, 999.8839, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_evidenceroomInterior[243] = CreateDynamicObject(964, 1283.0185, -8.2285, 999.8861, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_METAL_CRATE
    object_evidenceroomInterior[244] = CreateDynamicObject(1237, 1298.3175, -26.9199, 999.8839, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_evidenceroomInterior[245] = CreateDynamicObject(1424, 1296.8392, -31.6168, 1000.4459, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_2
    object_evidenceroomInterior[246] = CreateDynamicObject(1459, 1300.3288, -30.7900, 1000.5048, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_6
    object_evidenceroomInterior[247] = CreateDynamicObject(1424, 1296.8392, -31.3568, 1000.4459, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_2
    object_evidenceroomInterior[248] = CreateDynamicObject(1424, 1296.8392, -31.0368, 1000.4459, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_2
    object_evidenceroomInterior[249] = CreateDynamicObject(1424, 1296.8392, -30.6968, 1000.4459, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_2
    object_evidenceroomInterior[250] = CreateDynamicObject(1238, 1274.9958, -31.6658, 1000.2238, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
    object_evidenceroomInterior[251] = CreateDynamicObject(362, 1251.1595, -31.0948, 1001.0758, 0.0000, 25.4999, 6.2999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun
    object_evidenceroomInterior[252] = CreateDynamicObject(1459, 1300.3288, -31.5000, 1000.5048, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_6
    object_evidenceroomInterior[253] = CreateDynamicObject(1238, 1295.1180, -22.2059, 1002.3732, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
    object_evidenceroomInterior[254] = CreateDynamicObject(1459, 1302.8000, -31.5000, 1000.5048, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_6
    object_evidenceroomInterior[255] = CreateDynamicObject(1459, 1302.8000, -30.8099, 1000.5048, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_6
    object_evidenceroomInterior[256] = CreateDynamicObject(350, 1248.6468, -31.0559, 1000.8552, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sawnoff
    object_evidenceroomInterior[257] = CreateDynamicObject(1238, 1301.1594, -14.9856, 1000.2224, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
    object_evidenceroomInterior[258] = CreateDynamicObject(350, 1249.5278, -31.0960, 1000.8552, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sawnoff
    object_evidenceroomInterior[259] = CreateDynamicObject(1238, 1290.3873, -21.1159, 1002.4132, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
    object_evidenceroomInterior[260] = CreateDynamicObject(1238, 1300.1291, -14.5356, 1000.2324, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
    object_evidenceroomInterior[261] = CreateDynamicObject(1238, 1296.2187, -14.5356, 1000.2324, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
    object_evidenceroomInterior[262] = CreateDynamicObject(1238, 1299.6966, -26.7658, 1000.2373, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
    object_evidenceroomInterior[263] = CreateDynamicObject(19381, 1253.0705, -27.4636, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[263], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[264] = CreateDynamicObject(19381, 1253.0710, -17.8334, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[264], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[265] = CreateDynamicObject(1238, 1299.1368, -26.7658, 1000.2373, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
    object_evidenceroomInterior[266] = CreateDynamicObject(3386, 1277.0582, -14.3956, 999.8862, 0.0000, 0.0000, 91.2997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack2_
    object_evidenceroomInterior[267] = CreateDynamicObject(19381, 1253.0710, -8.1934, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[267], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[268] = CreateDynamicObject(1421, 1264.7617, -29.4661, 1000.6690, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BOXES
    object_evidenceroomInterior[269] = CreateDynamicObject(2567, 1276.5279, -17.4575, 1001.7669, 0.0000, 0.0000, -90.1997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ab_warehouseShelf
    object_evidenceroomInterior[270] = CreateDynamicObject(1892, 1263.4537, -11.5705, 999.9099, 0.0000, 0.0000, 179.9998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //security_gatsh
    object_evidenceroomInterior[271] = CreateDynamicObject(1491, 1301.7401, -23.9125, 999.9025, 0.0000, 0.0000, 90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_evidenceroomInterior[271], 0, 10778, "airportcpark_sfse", "vgsclubdoor02_128", 0xFFFFFFFF);
    object_evidenceroomInterior[272] = CreateDynamicObject(3386, 1277.0339, -13.3759, 999.8862, 0.0000, 0.0000, 91.2997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack2_
    object_evidenceroomInterior[273] = CreateDynamicObject(1421, 1262.4626, -30.8402, 1000.6690, 0.0000, 0.0000, -87.7997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BOXES
    object_evidenceroomInterior[274] = CreateDynamicObject(3675, 1272.4991, -7.5696, 1001.0253, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
    object_evidenceroomInterior[275] = CreateDynamicObject(3675, 1273.4698, -7.5696, 1001.0253, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
    object_evidenceroomInterior[276] = CreateDynamicObject(3675, 1264.4868, -31.3076, 1001.2500, 0.0000, 0.0000, 177.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
    object_evidenceroomInterior[277] = CreateDynamicObject(1892, 1253.7760, -14.3551, 999.9019, 0.0000, 0.0000, -90.2997, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //security_gatsh
    object_evidenceroomInterior[278] = CreateDynamicObject(3675, 1263.4575, -31.2609, 1001.2500, 0.0000, 0.0000, 177.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
    object_evidenceroomInterior[279] = CreateDynamicObject(1893, 1274.3635, -23.2875, 1005.0167, 0.0000, 0.0000, 178.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[280] = CreateDynamicObject(2991, 1292.6798, -8.6077, 1000.5413, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //imy_bbox
    object_evidenceroomInterior[281] = CreateDynamicObject(14782, 1266.4593, -20.9706, 1000.9050, 0.0000, 0.0000, 89.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int3int_boxing30
    object_evidenceroomInterior[282] = CreateDynamicObject(1271, 1265.3194, -18.2810, 1000.2800, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    object_evidenceroomInterior[283] = CreateDynamicObject(1271, 1265.3194, -19.1410, 1000.2800, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    object_evidenceroomInterior[284] = CreateDynamicObject(1271, 1264.4798, -18.2810, 1000.2800, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    object_evidenceroomInterior[285] = CreateDynamicObject(1271, 1265.2906, -18.3402, 1000.9406, 0.0000, 0.0000, -9.3999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    object_evidenceroomInterior[286] = CreateDynamicObject(19381, 1263.5655, -27.4636, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[286], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[287] = CreateDynamicObject(3630, 1253.0677, -32.1772, 999.2852, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //crdboxes2_LAs
    object_evidenceroomInterior[288] = CreateDynamicObject(19381, 1263.5655, -17.8435, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[288], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[289] = CreateDynamicObject(19381, 1263.5655, -8.2136, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[289], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[290] = CreateDynamicObject(19381, 1273.9951, -27.4636, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[290], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[291] = CreateDynamicObject(19381, 1284.4248, -27.4636, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[291], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[292] = CreateDynamicObject(19381, 1294.8940, -27.4636, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[292], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[293] = CreateDynamicObject(19381, 1305.3940, -27.4636, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[293], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[294] = CreateDynamicObject(19381, 1273.9748, -17.8435, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[294], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[295] = CreateDynamicObject(1893, 1261.4304, -14.8114, 1005.0167, 0.0000, 0.0000, -1.2999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[296] = CreateDynamicObject(19381, 1284.4248, -17.8635, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[296], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[297] = CreateDynamicObject(19465, 1254.1341, -14.8758, 1002.4569, 0.0000, 0.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_evidenceroomInterior[297], 0, 10806, "airfence_sfse", "ws_griddyfence", 0xFFFFFFFF);
    object_evidenceroomInterior[298] = CreateDynamicObject(19381, 1284.4248, -8.2434, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[298], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[299] = CreateDynamicObject(1893, 1257.5498, -14.7231, 1005.0167, 0.0000, 0.0000, -1.2999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[300] = CreateDynamicObject(19381, 1294.8940, -18.0335, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[300], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[301] = CreateDynamicObject(1893, 1250.9322, -26.8218, 1005.0167, 0.0000, 0.0000, -90.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[302] = CreateDynamicObject(19381, 1294.8940, -8.4134, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[302], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[303] = CreateDynamicObject(1893, 1256.4613, -26.9386, 1005.0167, 0.0000, 0.0000, -90.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[304] = CreateDynamicObject(19381, 1305.3841, -18.0335, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[304], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[305] = CreateDynamicObject(19381, 1305.3940, -8.4134, 1004.9337, 0.0000, 90.0000, 0.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(object_evidenceroomInterior[305], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_evidenceroomInterior[306] = CreateDynamicObject(1893, 1263.0887, -27.2527, 1005.0167, 0.0000, 0.0000, -90.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[307] = CreateDynamicObject(1893, 1263.1894, -20.8535, 1005.0167, 0.0000, 0.0000, -90.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[308] = CreateDynamicObject(1893, 1269.4814, -25.3952, 1005.0167, 0.0000, 0.0000, 178.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[309] = CreateDynamicObject(1893, 1269.6014, -15.5242, 1005.0167, 0.0000, 0.0000, 178.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[310] = CreateDynamicObject(1893, 1274.7202, -29.3719, 1005.0167, 0.0000, 0.0000, 178.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[311] = CreateDynamicObject(1893, 1284.7666, -29.0571, 1005.0167, 0.0000, 0.0000, 178.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[312] = CreateDynamicObject(1893, 1274.6745, -12.6422, 1005.0167, 0.0000, 0.0000, 178.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[313] = CreateDynamicObject(1893, 1285.1512, -13.7889, 1005.0167, 0.0000, 0.0000, 90.0999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[314] = CreateDynamicObject(1893, 1284.9333, -23.7297, 1005.0167, 0.0000, 0.0000, 178.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[315] = CreateDynamicObject(1893, 1281.4040, -23.6189, 1005.0167, 0.0000, 0.0000, 178.2001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[316] = CreateDynamicObject(1893, 1281.7904, -13.7947, 1005.0167, 0.0000, 0.0000, 90.0999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[317] = CreateDynamicObject(1893, 1292.9217, -13.7754, 1005.0167, 0.0000, 0.0000, 90.0999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[318] = CreateDynamicObject(1893, 1299.0688, -19.6700, 1005.0167, 0.0000, 0.0000, -89.3998, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[319] = CreateDynamicObject(1893, 1300.2790, -11.4756, 1005.0167, 0.0000, 0.0000, 1.5001, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[320] = CreateDynamicObject(1893, 1301.0024, -29.5578, 1005.0167, 0.0000, 0.0000, 179.6000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[321] = CreateDynamicObject(1893, 1293.1756, -29.2931, 1005.0167, 0.0000, 0.0000, 179.6000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[322] = CreateDynamicObject(1893, 1303.5493, -24.7940, 1005.0167, 0.0000, 0.0000, 91.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[323] = CreateDynamicObject(1893, 1293.5860, -23.5058, 1005.0167, 0.0000, 0.0000, 179.6000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[324] = CreateDynamicObject(1893, 1303.3277, -18.1177, 1005.0167, 0.0000, 0.0000, 91.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[325] = CreateDynamicObject(1893, 1257.4138, -19.7926, 1005.0167, 0.0000, 0.0000, -90.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_evidenceroomInterior[326] = CreateDynamicObject(19172, 1248.1330, -20.2768, 1003.5676, 0.0000, 0.0000, -90.0000, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_evidenceroomInterior[326], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_evidenceroomInterior[326], 1, "Waffen", 90, "Arial", 90, 1, 0xFFFFFFFF, 0x0, 0);
    object_evidenceroomInterior[327] = CreateDynamicObject(1495, 1254.1525, -14.1255, 999.9403, 0.0000, 0.0000, -90.8999, VW_EVIDENCEROOMINTERIOR, MAPS_EVIDENCEROOMINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

    object_door_evroomInterior = object_evidenceroomInterior[327];
    object_door_evroomInterior2 = object_evidenceroomInterior[37];
}