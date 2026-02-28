#include <YSI\y_hooks>

// Global interior define
#define MAPS_NINEDEMONSEXTERIOR_INTERIOR      0
#define MAPS_NINEDEMONSINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Nine Demons interior points
#define NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_POINT     750.690491, 380.020233, 945.083594
#define NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_OPEN_Y    377.7439
#define NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_CLOSED_Y  379.2940

// Map variables
new object_nineDemonsInterior[116];

new object_nineDemonsInterior_door;
new ndInterior_pIDControllingDoor = INVALID_PLAYER_ID;

forward ndInterior_closeDoor();
public ndInterior_closeDoor() {
    if (!IsPlayerInRangeOfPoint(ndInterior_pIDControllingDoor, 2.5, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_POINT)) {
        ndInterior_pIDControllingDoor = INVALID_PLAYER_ID;

        new Float:fX, Float:fY, Float:fZ;
        GetDynamicObjectPos(object_nineDemonsInterior_door, fX, fY, fZ);
        MoveDynamicObject(object_nineDemonsInterior_door, fX, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_CLOSED_Y, fZ, 1.0);

        for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) {
            if (GetPlayerVirtualWorld(i) == VW_NINEDEMONSINTERIOR) {
                SetPVarInt(i, "ND_hasDoorSound", 1);
                PlayerPlaySound(i, 1035, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_POINT); // start opening door sound
            }
        }
    } else
        SetTimer("ndInterior_closeDoor", 2500, false);
    
    return 1;
}


hook OnPlayerConnect(playerid) {
    // ---
}

hook OnDynamicObjectMoved(objectid) {
    if (objectid == object_nineDemonsInterior_door) {
        for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) {
            if (GetPVarInt(i, "ND_hasDoorSound") == 1) {
                SetPVarInt(i, "ND_hasDoorSound", 0);
                PlayerPlaySound(i, 1036, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_POINT); // stop sound
            }
        }
    }
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if (IsPlayerInRangeOfPoint(playerid, 1.5, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_POINT)) 
    { // Safebox Room Door
            if (Spieler[playerid][pFraktion] != 15)
                return PlayerPlaySound(playerid, 1085, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_POINT);
            
            new Float:fX, Float:fY, Float:fZ;
            GetDynamicObjectPos(object_nineDemonsInterior_door, fX, fY, fZ);

            if (fX != NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_OPEN_Y && (ndInterior_pIDControllingDoor == playerid || ndInterior_pIDControllingDoor == INVALID_PLAYER_ID))
                MoveDynamicObject(object_nineDemonsInterior_door, fX, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_OPEN_Y, fZ, 1.0);
            else
                return PlayerPlaySound(playerid, 1085, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_POINT);

            ndInterior_pIDControllingDoor = playerid;

            for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) {
                if (GetPlayerVirtualWorld(i) == VW_NINEDEMONSINTERIOR) {
                    SetPVarInt(i, "ND_hasDoorSound", 1);
                    PlayerPlaySound(i, 1035, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_POINT); // start opening door sound
                }
            }

            SetTimer("ndInterior_closeDoor", 2500, false);
            return 1;
        }
    return 1;
}

hook OnGameModeInit() {
	// Pickups

    // 3DTextLabels   
	// Objects
    object_nineDemonsInterior[0] = CreateDynamicObject(1575, 771.4157, 376.6896, 945.3145, 0.0000, 0.0000, -35.4999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_nineDemonsInterior[1] = CreateDynamicObject(19172, 745.8458, 375.2575, 945.4976, 0.0000, -11.4997, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_nineDemonsInterior[1], 0, "Nine", OBJECT_MATERIAL_SIZE_256x128, "Segoe Script", 100, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_nineDemonsInterior[1], 1, 19297, "matlights", "invisible", 0x00000000);
    object_nineDemonsInterior[2] = CreateDynamicObject(19172, 744.0424, 375.2575, 945.8651, 0.0000, -11.4997, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_nineDemonsInterior[2], 0, "Demons", OBJECT_MATERIAL_SIZE_256x128, "Segoe Script", 100, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_nineDemonsInterior[2], 1, 19297, "matlights", "invisible", 0x00000000);
    object_nineDemonsInterior[3] = CreateDynamicObject(2991, 758.0548, 384.6682, 944.7020, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //imy_bbox
    SetDynamicObjectMaterial(object_nineDemonsInterior[3], 0, -1, "none", "none", 0xFFFFFFFF);
    object_nineDemonsInterior[4] = CreateDynamicObject(1575, 772.3502, 376.8460, 945.3145, 0.0000, 0.0000, 104.5000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_nineDemonsInterior[5] = CreateDynamicObject(2991, 772.7965, 376.3511, 944.7025, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //imy_bbox
    SetDynamicObjectMaterial(object_nineDemonsInterior[5], 0, -1, "none", "none", 0xFFFFFFFF);
    object_nineDemonsInterior[6] = CreateDynamicObject(3630, 762.0360, 375.2398, 945.5855, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //crdboxes2_LAs
    SetDynamicObjectMaterial(object_nineDemonsInterior[6], 0, -1, "none", "none", 0xFFFFFFFF);
    object_nineDemonsInterior[7] = CreateDynamicObject(3630, 767.3676, 384.6697, 944.0844, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //crdboxes2_LAs
    SetDynamicObjectMaterial(object_nineDemonsInterior[7], 0, -1, "none", "none", 0xFFFFFFFF);
    object_nineDemonsInterior[8] = CreateDynamicObject(1575, 771.8936, 375.9515, 945.3145, 0.0000, 0.0000, -139.8000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_nineDemonsInterior[9] = CreateDynamicObject(1575, 773.7069, 376.3319, 945.3145, 0.0000, 0.0000, 141.8000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_nineDemonsInterior[10] = CreateDynamicObject(1575, 773.9204, 376.5974, 945.3588, 0.0000, 18.3999, 54.8997, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
    object_nineDemonsInterior[11] = CreateDynamicObject(2991, 754.3051, 374.2575, 944.7020, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //imy_bbox
    SetDynamicObjectMaterial(object_nineDemonsInterior[11], 0, -1, "none", "none", 0xFFFFFFFF);
    object_nineDemonsInterior[12] = CreateDynamicObject(1886, 744.9406, 384.1076, 947.4760, 14.1998, 0.0000, 42.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_nineDemonsInterior[13] = CreateDynamicObject(1886, 750.4550, 375.8753, 947.6051, 14.1998, 0.0000, -100.5998, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_nineDemonsInterior[14] = CreateDynamicObject(19461, 750.4525, 376.6050, 949.2362, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[15] = CreateDynamicObject(19808, 743.6300, 382.2268, 944.8734, 0.0000, 0.0000, -74.9000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_nineDemonsInterior[16] = CreateDynamicObject(19461, 741.1718, 384.7365, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[17] = CreateDynamicObject(19461, 744.5427, 386.2744, 949.2362, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_nineDemonsInterior[17], 0, 3241, "conhooses", "ws_corr_metal1", 0x00000000);
    object_nineDemonsInterior[18] = CreateDynamicObject(8661, 760.1154, 381.9562, 947.5355, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_nineDemonsInterior[18], 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
    object_nineDemonsInterior[19] = CreateDynamicObject(19461, 741.1718, 375.1759, 949.2362, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[20] = CreateDynamicObject(19461, 750.8032, 375.1748, 949.2362, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[21] = CreateDynamicObject(19461, 750.6428, 381.4743, 949.2362, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[22] = CreateDynamicObject(14782, 747.8037, 384.2651, 945.0830, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int3int_boxing30
    object_nineDemonsInterior[23] = CreateDynamicObject(19461, 738.4227, 381.4743, 949.2362, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[24] = CreateDynamicObject(19461, 742.3530, 386.2744, 949.2362, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_nineDemonsInterior[24], 0, 3241, "conhooses", "ws_corr_metal1", 0x00000000);
    object_nineDemonsInterior[25] = CreateDynamicObject(8661, 720.4273, 388.1058, 947.5336, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_nineDemonsInterior[25], 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
    object_nineDemonsInterior[26] = CreateDynamicObject(8661, 752.0247, 381.7864, 950.8764, 0.0000, 180.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_nineDemonsInterior[26], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFD3D3D3);
    object_nineDemonsInterior[27] = CreateDynamicObject(19461, 746.7741, 386.2744, 949.2362, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_nineDemonsInterior[27], 0, 3241, "conhooses", "ws_corr_metal1", 0x00000000);
    object_nineDemonsInterior[28] = CreateDynamicObject(1496, 742.4688, 383.0468, 947.5166, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP02
    SetDynamicObjectMaterial(object_nineDemonsInterior[28], 0, 3241, "conhooses", "trail_wall1", 0x00000000);
    object_nineDemonsInterior[29] = CreateDynamicObject(19461, 736.3729, 379.9045, 945.7761, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[30] = CreateDynamicObject(8661, 756.3104, 379.4660, 944.0836, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_nineDemonsInterior[30], 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
    object_nineDemonsInterior[31] = CreateDynamicObject(8661, 720.4273, 388.1058, 947.3862, 0.0000, 180.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_nineDemonsInterior[31], 0, 16640, "a51", "concretemanky", 0xFF808080);
    object_nineDemonsInterior[32] = CreateDynamicObject(1656, 737.0451, 378.2744, 947.4663, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[32], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[33] = CreateDynamicObject(1656, 737.0451, 378.2734, 947.4663, 0.0000, 180.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[33], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[34] = CreateDynamicObject(1656, 738.4038, 378.2723, 947.4663, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[34], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[35] = CreateDynamicObject(1656, 739.7630, 378.2723, 947.4663, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[35], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[36] = CreateDynamicObject(1656, 740.2498, 377.3869, 947.4663, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[36], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[37] = CreateDynamicObject(1656, 740.2468, 376.0278, 947.4663, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[37], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[38] = CreateDynamicObject(1656, 740.2498, 374.6687, 947.4663, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[38], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[39] = CreateDynamicObject(1437, 739.5996, 376.7434, 943.5902, -19.5000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_LADDER_2
    object_nineDemonsInterior[40] = CreateDynamicObject(1656, 738.4038, 378.2734, 947.4663, 0.0000, 180.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[40], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[41] = CreateDynamicObject(1656, 739.7630, 378.2734, 947.4663, 0.0000, 180.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[41], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[42] = CreateDynamicObject(1656, 740.2479, 377.3869, 947.4663, 0.0000, 180.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[42], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[43] = CreateDynamicObject(1656, 740.2479, 376.0278, 947.4663, 0.0000, 180.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[43], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[44] = CreateDynamicObject(1656, 740.2479, 374.6687, 947.4663, 0.0000, 180.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[44], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[45] = CreateDynamicObject(11743, 737.1770, 383.9465, 944.8897, 0.0000, 0.0000, 37.2999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCoffeeMachine1
    object_nineDemonsInterior[46] = CreateDynamicObject(1656, 740.2468, 377.8088, 947.4674, 0.0000, 180.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(object_nineDemonsInterior[46], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_nineDemonsInterior[47] = CreateDynamicObject(19461, 732.5134, 376.6050, 947.4758, 0.0000, 90.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_nineDemonsInterior[47], 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
    object_nineDemonsInterior[48] = CreateDynamicObject(19461, 741.1718, 375.1770, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[49] = CreateDynamicObject(19461, 750.8060, 384.7365, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[50] = CreateDynamicObject(19461, 750.8060, 375.1770, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[51] = CreateDynamicObject(19461, 760.4409, 384.7365, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[52] = CreateDynamicObject(19461, 760.4409, 375.1770, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[53] = CreateDynamicObject(19461, 774.9525, 379.9045, 945.7761, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[54] = CreateDynamicObject(19461, 770.0759, 384.7365, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[55] = CreateDynamicObject(19461, 770.0759, 375.1770, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[56] = CreateDynamicObject(1723, 737.0789, 380.3728, 944.0336, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mrk_seating1
    object_nineDemonsInterior[57] = CreateDynamicObject(1723, 738.6892, 383.9631, 944.0336, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mrk_seating1
    object_nineDemonsInterior[58] = CreateDynamicObject(2315, 738.8917, 381.4364, 944.0540, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE4
    SetDynamicObjectMaterial(object_nineDemonsInterior[58], 0, 14652, "ab_trukstpa", "CJ_WOOD1(EDGE)", 0x00000000);
    object_nineDemonsInterior[59] = CreateDynamicObject(19997, 737.3010, 383.7141, 944.0712, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneGrgTable1
    object_nineDemonsInterior[60] = CreateDynamicObject(19835, 737.5020, 383.9858, 945.0797, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_nineDemonsInterior[61] = CreateDynamicObject(19835, 737.5020, 383.9858, 945.1196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_nineDemonsInterior[62] = CreateDynamicObject(19835, 737.5020, 383.9858, 945.1597, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_nineDemonsInterior[63] = CreateDynamicObject(19835, 737.5020, 383.3059, 945.0095, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_nineDemonsInterior[64] = CreateDynamicObject(19835, 737.5020, 383.9858, 944.9995, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_nineDemonsInterior[65] = CreateDynamicObject(19835, 737.5020, 383.9858, 945.0296, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_nineDemonsInterior[66] = CreateDynamicObject(19835, 737.1920, 383.5458, 945.0095, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_nineDemonsInterior[67] = CreateDynamicObject(19835, 737.7423, 383.6759, 945.0095, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    object_nineDemonsInterior[68] = CreateDynamicObject(1486, 740.3726, 381.4468, 944.6685, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BEER_1
    object_nineDemonsInterior[69] = CreateDynamicObject(19786, 739.2003, 378.7261, 945.5739, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    object_nineDemonsInterior[70] = CreateDynamicObject(1486, 738.9019, 381.5671, 944.6685, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BEER_1
    object_nineDemonsInterior[71] = CreateDynamicObject(1486, 739.7321, 381.2571, 944.6685, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BEER_1
    object_nineDemonsInterior[72] = CreateDynamicObject(19461, 736.0416, 378.6369, 945.7747, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[73] = CreateDynamicObject(19922, 747.6102, 376.1047, 947.4904, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_nineDemonsInterior[74] = CreateDynamicObject(321, 740.7639, 384.3836, 944.1727, 0.0000, 110.5998, -31.3999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gun_dildo1
    object_nineDemonsInterior[75] = CreateDynamicObject(2894, 739.7069, 381.4981, 944.1129, 0.0000, 0.0000, -160.7998, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_nineDemonsInterior[75], 0, 2577, "cj_sex", "CJ_PAINTING9", 0x00000000);
    object_nineDemonsInterior[76] = CreateDynamicObject(1550, 736.9307, 379.3157, 944.4514, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    object_nineDemonsInterior[77] = CreateDynamicObject(19313, 751.1132, 372.2668, 944.1021, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51fensin
    object_nineDemonsInterior[78] = CreateDynamicObject(19313, 751.1132, 387.8298, 944.1021, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51fensin
    object_nineDemonsInterior[79] = CreateDynamicObject(1495, 751.1237, 379.2940, 944.0598, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT01
    object_nineDemonsInterior[80] = CreateDynamicObject(2973, 773.5562, 383.2416, 944.0598, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_cargo2
    object_nineDemonsInterior[81] = CreateDynamicObject(1536, 751.1195, 380.7951, 949.0587, 0.0000, 180.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT15
    SetDynamicObjectMaterial(object_nineDemonsInterior[81], 0, 10806, "airfence_sfse", "ws_griddyfence", 0x00000000);
    object_nineDemonsInterior[82] = CreateDynamicObject(8661, 760.1154, 381.9562, 947.3853, 0.0000, 180.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_nineDemonsInterior[82], 0, 16640, "a51", "concretemanky", 0xFF808080);
    object_nineDemonsInterior[83] = CreateDynamicObject(2200, 750.2399, 379.7875, 947.5255, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_UNIT_1
    object_nineDemonsInterior[84] = CreateDynamicObject(19461, 736.3040, 376.6050, 949.2362, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[85] = CreateDynamicObject(3800, 735.8646, 377.0332, 948.7620, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    SetDynamicObjectMaterial(object_nineDemonsInterior[85], 0, 13060, "ce_fact01", "des_hooswin2", 0xFFFFFFFF);
    object_nineDemonsInterior[86] = CreateDynamicObject(3800, 741.3947, 374.7333, 948.7620, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    SetDynamicObjectMaterial(object_nineDemonsInterior[86], 0, 13060, "ce_fact01", "des_hooswin2", 0xFFFFFFFF);
    object_nineDemonsInterior[87] = CreateDynamicObject(3800, 747.5352, 374.7333, 948.7620, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    SetDynamicObjectMaterial(object_nineDemonsInterior[87], 0, 13060, "ce_fact01", "des_hooswin2", 0xFFFFFFFF);
    object_nineDemonsInterior[88] = CreateDynamicObject(3800, 750.8748, 376.7933, 948.7620, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    SetDynamicObjectMaterial(object_nineDemonsInterior[88], 0, 13060, "ce_fact01", "des_hooswin2", 0xFFFFFFFF);
    object_nineDemonsInterior[89] = CreateDynamicObject(3800, 747.9456, 381.9035, 948.7620, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    SetDynamicObjectMaterial(object_nineDemonsInterior[89], 0, 13060, "ce_fact01", "des_hooswin2", 0xFFFFFFFF);
    object_nineDemonsInterior[90] = CreateDynamicObject(2991, 738.7634, 381.3959, 948.1640, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //imy_bbox
    SetDynamicObjectMaterial(object_nineDemonsInterior[90], 0, -1, "none", "none", 0xFFFFFFFF);
    object_nineDemonsInterior[91] = CreateDynamicObject(19461, 744.4105, 384.7365, 945.7747, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    object_nineDemonsInterior[92] = CreateDynamicObject(19922, 743.5802, 376.1047, 947.4904, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_nineDemonsInterior[93] = CreateDynamicObject(2605, 743.8480, 381.9501, 944.4478, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLCE_DESK1
    object_nineDemonsInterior[94] = CreateDynamicObject(1724, 745.9370, 380.6798, 944.0570, 0.0000, 0.0000, 141.3999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mrk_seating1b
    object_nineDemonsInterior[95] = CreateDynamicObject(1671, 742.5877, 382.0039, 944.5130, 0.0000, 0.0000, 83.4999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_nineDemonsInterior[96] = CreateDynamicObject(19173, 739.6657, 384.6364, 946.0537, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_nineDemonsInterior[97] = CreateDynamicObject(19121, 763.7952, 380.2962, 953.6594, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_nineDemonsInterior[98] = CreateDynamicObject(19121, 744.4406, 378.3792, 955.4935, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_nineDemonsInterior[99] = CreateDynamicObject(14439, 747.4492, 374.9128, 952.6057, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Carter-light12
    object_nineDemonsInterior[100] = CreateDynamicObject(14699, 749.6585, 377.5603, 945.7971, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights
    object_nineDemonsInterior[101] = CreateDynamicObject(19121, 744.4406, 378.3792, 955.4935, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_nineDemonsInterior[102] = CreateDynamicObject(19121, 773.6740, 380.2962, 953.6594, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_nineDemonsInterior[103] = CreateDynamicObject(14439, 762.8889, 376.4526, 949.1671, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Carter-light12
    object_nineDemonsInterior[104] = CreateDynamicObject(19121, 740.3220, 389.7113, 945.9583, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_nineDemonsInterior[105] = CreateDynamicObject(14699, 742.3986, 379.0802, 945.7971, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights
    object_nineDemonsInterior[106] = CreateDynamicObject(2359, 742.6364, 375.8674, 948.4860, 0.0000, 0.0000, 140.6999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
    object_nineDemonsInterior[107] = CreateDynamicObject(1550, 741.0905, 381.0054, 947.9008, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    object_nineDemonsInterior[108] = CreateDynamicObject(2042, 748.6198, 375.8132, 948.3599, 0.0000, 0.0000, 150.3999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M3
    object_nineDemonsInterior[109] = CreateDynamicObject(371, 745.0377, 376.7973, 947.7570, -4.8998, 0.0000, 156.9001, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gun_para
    object_nineDemonsInterior[110] = CreateDynamicObject(348, 748.4187, 376.3232, 948.2849, 93.0000, 32.7999, 9.1000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_nineDemonsInterior[111] = CreateDynamicObject(353, 747.8541, 376.5462, 948.2620, 82.5998, -84.7997, 51.6999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mp5lng
    object_nineDemonsInterior[112] = CreateDynamicObject(336, 747.4000, 376.5191, 948.2733, 85.1997, 0.0000, -25.2999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bat
    object_nineDemonsInterior[113] = CreateDynamicObject(358, 744.4837, 376.1997, 948.2744, 81.0000, -121.1997, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    object_nineDemonsInterior[114] = CreateDynamicObject(355, 743.2561, 376.1954, 948.2589, 84.5998, -85.0000, 38.7999, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ak47
    object_nineDemonsInterior[115] = CreateDynamicObject(356, 746.5767, 376.1741, 948.2819, 85.5998, -63.3997, 30.6998, VW_NINEDEMONSINTERIOR, MAPS_NINEDEMONSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    object_nineDemonsInterior_door = object_nineDemonsInterior[79];
}