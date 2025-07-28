#include <YSI\y_hooks>

// Global interior define
#define MAPS_CITYHALLEXTERIOR_INTERIOR      0
#define MAPS_CITYHALLINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Cityhall Interior Points
#define CITYHALL_INTERIOR_STADTHALLE                    918.8224, -1463.4082, 2754.3459
#define CITYHALL_INTERIOR_DESK1                         943.6100, -1464.4445, 2761.0164
#define CITYHALL_INTERIOR_DESK2                         943.6100, -1466.8085, 2761.0164
#define CITYHALL_INTERIOR_ELEVATOR_1_DOWN_L_COORDS      906.7859, -1457.6291, 2754.3218
#define CITYHALL_INTERIOR_ELEVATOR_2_DOWN_L_COORDS      909.7402, -1457.6291, 2754.3218
#define CITYHALL_INTERIOR_ELEVATOR_1_UP_L_COORDS        906.7859, -1457.6291, 2761.0164
#define CITYHALL_INTERIOR_ELEVATOR_2_UP_L_COORDS        909.7402, -1457.6291, 2761.0164
#define CITYHALL_INTERIOR_ELEVATOR_DOWN_FACING          180.0
#define CITYHALL_INTERIOR_ELEVATOR_UP_FACING            180.0
#define CITYHALL_INTERIOR_ELEVATOR_1_DOWN_R_COORDS      929.6517, -1457.6291, 2754.3318
#define CITYHALL_INTERIOR_ELEVATOR_2_DOWN_R_COORDS      932.7280, -1457.6291, 2754.3318
#define CITYHALL_INTERIOR_ELEVATOR_1_UP_R_COORDS        929.6517, -1457.6291, 2761.0063
#define CITYHALL_INTERIOR_ELEVATOR_2_UP_R_COORDS        932.7280, -1457.6291, 2761.0164
#define CITYHALL_INTERIOR_STATECHANGE                   941.7469, -1469.0323, 2761.0164

// Map variables
new object_cityhallInterior[732];
new pickup_cityhallInterior[13];
new text3D_cityhallInterior[4];
new actor_cityhallInterior[10];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, CITYHALL_INTERIOR_EXIT_COORDS)) { // Exit
            if(pCheckpoint[playerid] == CP_TUTORIAL3) {
				SetPlayerCheckpointEx(playerid, CITYHALL_INTERIOR_STADTHALLE, 5.0, CP_TUTORIAL4);
				SendClientMessage(playerid, COLOR_GREEN, "Gehe nun zum Informationspunkt, beantrage einen Personalausweis und suche dir einen Job aus.");
			}
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ENTER_COORDS, MAPS_CITYHALLEXTERIOR_INTERIOR, VW_MAIN);
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, CITYHALL_INTERIOR_ELEVATOR_1_DOWN_L_COORDS) && GetPlayerVirtualWorld(playerid) == VW_CITYHALLINTERIOR) { // Elevator 1 left down
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ELEVATOR_UP_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ELEVATOR_1_UP_L_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, CITYHALL_INTERIOR_ELEVATOR_2_DOWN_L_COORDS) && GetPlayerVirtualWorld(playerid) == VW_CITYHALLINTERIOR) { // Elevator 2 left down
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ELEVATOR_UP_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ELEVATOR_2_UP_L_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, CITYHALL_INTERIOR_ELEVATOR_1_DOWN_R_COORDS) && GetPlayerVirtualWorld(playerid) == VW_CITYHALLINTERIOR) { // Elevator 1 right down
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ELEVATOR_UP_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ELEVATOR_1_UP_R_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, CITYHALL_INTERIOR_ELEVATOR_2_DOWN_R_COORDS) && GetPlayerVirtualWorld(playerid) == VW_CITYHALLINTERIOR) { // Elevator 2 right down
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ELEVATOR_UP_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ELEVATOR_2_UP_R_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, CITYHALL_INTERIOR_ELEVATOR_1_UP_L_COORDS) && GetPlayerVirtualWorld(playerid) == VW_CITYHALLINTERIOR) { // Elevator 1 left up
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ELEVATOR_DOWN_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ELEVATOR_1_DOWN_L_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, CITYHALL_INTERIOR_ELEVATOR_2_UP_L_COORDS) && GetPlayerVirtualWorld(playerid) == VW_CITYHALLINTERIOR) { // Elevator 2 left up
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ELEVATOR_DOWN_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ELEVATOR_2_DOWN_L_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, CITYHALL_INTERIOR_ELEVATOR_1_UP_R_COORDS) && GetPlayerVirtualWorld(playerid) == VW_CITYHALLINTERIOR) { // Elevator 1 right up
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ELEVATOR_DOWN_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ELEVATOR_1_DOWN_R_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, CITYHALL_INTERIOR_ELEVATOR_2_UP_R_COORDS) && GetPlayerVirtualWorld(playerid) == VW_CITYHALLINTERIOR) { // Elevator 2 right up
            SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_ELEVATOR_DOWN_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, CITYHALL_INTERIOR_ELEVATOR_2_DOWN_R_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
	// Pickups
	pickup_cityhallInterior[0] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_EXIT_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Exit point
    pickup_cityhallInterior[1] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ELEVATOR_1_DOWN_L_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Elevator 1 left down
    pickup_cityhallInterior[2] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ELEVATOR_2_DOWN_L_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Elevator 2 left down
    pickup_cityhallInterior[3] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ELEVATOR_1_DOWN_R_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Elevator 1 right down
    pickup_cityhallInterior[4] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ELEVATOR_2_DOWN_R_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Elevator 2 right down
    pickup_cityhallInterior[5] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ELEVATOR_1_UP_L_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Elevator 1 left up
    pickup_cityhallInterior[6] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ELEVATOR_2_UP_L_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Elevator 2 left up
    pickup_cityhallInterior[7] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ELEVATOR_1_UP_R_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Elevator 1 right up
    pickup_cityhallInterior[8] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ELEVATOR_2_UP_R_COORDS, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Elevator 2 right up
    pickup_cityhallInterior[9] = CreateDynamicPickup(1210, 1, CITYHALL_INTERIOR_STADTHALLE, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // /stadthalle point
    pickup_cityhallInterior[10] = CreateDynamicPickup(1581, 1, CITYHALL_INTERIOR_DESK1, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Desk 1 (Zollamt Schalter)
    pickup_cityhallInterior[11] = CreateDynamicPickup(1239, 1, CITYHALL_INTERIOR_DESK2, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Desk 2 (Rechtsschutzversicherung)
    pickup_cityhallInterior[12] = CreateDynamicPickup(1239, 1, CITYHALL_INTERIOR_STATECHANGE, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR); // Statechange

	// 3DTextLabels
    text3D_cityhallInterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Stadthalle\n" COLOR_HEX_WHITE "Tippe /Stadthalle", COLOR_WHITE, CITYHALL_INTERIOR_STADTHALLE, 25.0, .testlos = 1, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // /stadthalle point
    text3D_cityhallInterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Zollamt Schalter\n" COLOR_HEX_WHITE "Tippe /Zollpass", COLOR_WHITE, CITYHALL_INTERIOR_DESK1, 15.0, .testlos = 1, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Desk 1 (Zollamt Schalter)
    text3D_cityhallInterior[2] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Rechtsschutzversicherung\n" COLOR_HEX_WHITE "62 Tage - Preis: $1.000.000\n" COLOR_HEX_ORANGE "Tippe /Rechtsschutz", COLOR_WHITE, CITYHALL_INTERIOR_DESK2, 15.0, .testlos = 1, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Desk 2 (Rechtsschutzversicherung)
    text3D_cityhallInterior[3] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staatsangehörigkeit\n" COLOR_HEX_ORANGE "Tippe /Staatswechsel\n" COLOR_HEX_WHITE "Preis: $100.000\n", COLOR_WHITE, CITYHALL_INTERIOR_STATECHANGE,25.0, .testlos = 1, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Statechange Point

    // Actors
    actor_cityhallInterior[0] = CreateDynamicActor(141, 918.6574, -1461.5676, 2754.3459, 180.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Maindesk
    ApplyDynamicActorAnimation(actor_cityhallInterior[0], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_cityhallInterior[1] = CreateDynamicActor(150, 945.6470, -1464.4348, 2761.0164, 90.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Desk 1
    actor_cityhallInterior[2] = CreateDynamicActor(219, 945.6470, -1466.8208, 2761.0164, 90.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Desk 2
    actor_cityhallInterior[3] = CreateDynamicActor(0, 937.3201, -1461.5175, 2761.0164, 90.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Actor 1
    ApplyDynamicActorAnimation(actor_cityhallInterior[3], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_cityhallInterior[4] = CreateDynamicActor(25, 937.3339, -1468.8611, 2761.0164, 90.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Actor 2
    ApplyDynamicActorAnimation(actor_cityhallInterior[4], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_cityhallInterior[5] = CreateDynamicActor(21, 937.3348, -1474.0236, 2761.0164, 90.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Actor 3
    ApplyDynamicActorAnimation(actor_cityhallInterior[5], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_cityhallInterior[6] = CreateDynamicActor(16, 931.6931, -1468.6628, 2761.0164, 270.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Actor 4
    ApplyDynamicActorAnimation(actor_cityhallInterior[6], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_cityhallInterior[7] = CreateDynamicActor(66, 913.4384, -1458.1715, 2761.0063, 180.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Actor 5
    ApplyDynamicActorAnimation(actor_cityhallInterior[7], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_cityhallInterior[8] = CreateDynamicActor(12, 925.7977, -1458.1758, 2761.0063, 180.0000, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Actor 6
    ApplyDynamicActorAnimation(actor_cityhallInterior[8], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    actor_cityhallInterior[9] = CreateDynamicActor(78, 909.2499, -1473.5173, 2761.4895, 83.8666, .worldid = VW_CITYHALLINTERIOR, .interiorid = MAPS_CITYHALLINTERIOR_INTERIOR); // Actor 7 (Homeless dude easter egg)
    ApplyDynamicActorAnimation(actor_cityhallInterior[9], "CRACK", "crckidle2", 4.0, 1, 0, 0, 0, 0);

	// Objects
	object_cityhallInterior[0] = CreateDynamicObject(19464, 908.9829, -1475.7220, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[0], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[1] = CreateDynamicObject(18981, 917.3012, -1463.5339, 2752.8217, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[1], 0, 15034, "genhotelsave", "bathtile05_int", 0xFFFFFFFF);
    object_cityhallInterior[2] = CreateDynamicObject(1536, 920.2229, -1476.0039, 2753.0510, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT15
    SetDynamicObjectMaterial(object_cityhallInterior[2], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    object_cityhallInterior[3] = CreateDynamicObject(1536, 920.1928, -1476.0039, 2753.0510, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT15
    SetDynamicObjectMaterial(object_cityhallInterior[3], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    object_cityhallInterior[4] = CreateDynamicObject(19464, 921.7540, -1478.8221, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[4], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[5] = CreateDynamicObject(19464, 918.6541, -1478.8221, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[5], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[6] = CreateDynamicObject(19464, 915.8043, -1475.9718, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[6], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[7] = CreateDynamicObject(19464, 909.8748, -1475.9718, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[7], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[8] = CreateDynamicObject(19450, 913.7258, -1472.9619, 2753.2600, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[8], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[9] = CreateDynamicObject(19450, 920.3264, -1477.5727, 2753.2399, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[9], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[10] = CreateDynamicObject(19464, 918.6643, -1475.7132, 2751.6335, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[10], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[11] = CreateDynamicObject(19565, 918.5355, -1475.3172, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[11], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[12] = CreateDynamicObject(19565, 918.5355, -1475.7860, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[12], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[13] = CreateDynamicObject(19565, 918.5355, -1474.8469, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[13], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[14] = CreateDynamicObject(19565, 918.5355, -1474.3763, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[14], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[15] = CreateDynamicObject(19565, 918.5355, -1473.9061, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[15], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[16] = CreateDynamicObject(19565, 918.5355, -1473.4455, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[16], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[17] = CreateDynamicObject(19565, 918.5355, -1472.9752, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[17], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[18] = CreateDynamicObject(19464, 918.6243, -1475.6832, 2750.9328, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[18], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[19] = CreateDynamicObject(19464, 918.6743, -1475.6832, 2750.9328, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[19], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[20] = CreateDynamicObject(19450, 913.7258, -1476.4620, 2753.2500, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[20], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[21] = CreateDynamicObject(1708, 917.9519, -1473.0107, 2753.2717, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair02
    SetDynamicObjectMaterial(object_cityhallInterior[21], 1, 1746, "cj_sofa", "CJ_FAB4", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[21], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[22] = CreateDynamicObject(2315, 914.4351, -1472.9880, 2753.3161, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE4
    object_cityhallInterior[23] = CreateDynamicObject(1708, 917.9519, -1471.4803, 2753.2717, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair02
    SetDynamicObjectMaterial(object_cityhallInterior[23], 1, 1746, "cj_sofa", "CJ_FAB4", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[23], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[24] = CreateDynamicObject(1708, 912.3715, -1472.4554, 2753.2717, 0.0000, 0.0000, 89.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair02
    SetDynamicObjectMaterial(object_cityhallInterior[24], 1, 1746, "cj_sofa", "CJ_FAB4", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[24], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[25] = CreateDynamicObject(1708, 912.3646, -1473.9858, 2753.2717, 0.0000, 0.0000, 89.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair02
    SetDynamicObjectMaterial(object_cityhallInterior[25], 1, 1746, "cj_sofa", "CJ_FAB4", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[25], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[26] = CreateDynamicObject(2001, 912.7150, -1475.1645, 2753.3142, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    SetDynamicObjectMaterial(object_cityhallInterior[26], 1, 630, "gta_potplants", "kb_teracota_pot64", 0xFFFFFFFF);
    object_cityhallInterior[27] = CreateDynamicObject(2001, 917.7155, -1475.1645, 2753.3142, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    SetDynamicObjectMaterial(object_cityhallInterior[27], 1, 630, "gta_potplants", "kb_teracota_pot64", 0xFFFFFFFF);
    object_cityhallInterior[28] = CreateDynamicObject(1753, 916.2219, -1475.3032, 2753.2915, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[28], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[29] = CreateDynamicObject(19786, 915.2346, -1475.9768, 2755.8620, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[29], 0, 14570, "traidaqua", "ab_tv", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[29], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[30] = CreateDynamicObject(2816, 915.4837, -1472.9720, 2753.8125, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags01
    object_cityhallInterior[31] = CreateDynamicObject(2855, 914.5407, -1472.9958, 2753.8032, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags05
    object_cityhallInterior[32] = CreateDynamicObject(955, 909.4804, -1473.5239, 2753.6857, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_EXT_SPRUNK
    object_cityhallInterior[33] = CreateDynamicObject(956, 909.4525, -1474.9178, 2753.7165, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_EXT_CANDY
    object_cityhallInterior[34] = CreateDynamicObject(19825, 911.2739, -1475.8176, 2756.0183, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
    object_cityhallInterior[35] = CreateDynamicObject(19565, 906.5717, -1457.0998, 2756.3854, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[35], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[36] = CreateDynamicObject(19565, 907.0421, -1457.0998, 2756.3854, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[36], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[37] = CreateDynamicObject(19464, 906.1342, -1472.8424, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[37], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[38] = CreateDynamicObject(19464, 901.8338, -1466.9337, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[38], 0, 10765, "airportgnd_sfse", "white", 0xFF998F4E);
    object_cityhallInterior[39] = CreateDynamicObject(19464, 904.7039, -1469.8027, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[39], 0, 10765, "airportgnd_sfse", "white", 0xFF998F4E);
    object_cityhallInterior[40] = CreateDynamicObject(19464, 904.6939, -1458.9835, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[40], 0, 10765, "airportgnd_sfse", "white", 0xFF998F4E);
    object_cityhallInterior[41] = CreateDynamicObject(19464, 903.8833, -1463.8735, 2754.3547, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[41], 0, 10765, "airportgnd_sfse", "white", 0xFF692015);
    object_cityhallInterior[42] = CreateDynamicObject(19464, 901.8338, -1461.8331, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[42], 0, 10765, "airportgnd_sfse", "white", 0xFF998F4E);
    object_cityhallInterior[43] = CreateDynamicObject(19464, 901.8338, -1464.5334, 2756.9982, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[43], 0, 10765, "airportgnd_sfse", "white", 0xFF998F4E);
    object_cityhallInterior[44] = CreateDynamicObject(19565, 929.6234, -1457.1499, 2756.6357, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[44], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[45] = CreateDynamicObject(18981, 892.3007, -1463.5339, 2752.8217, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[45], 0, 15034, "genhotelsave", "bathtile05_int", 0xFFFFFFFF);
    object_cityhallInterior[46] = CreateDynamicObject(1337, 903.8958, -1462.4918, 2754.5273, 31.9999, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BinNt07_LA
    SetDynamicObjectMaterial(object_cityhallInterior[46], 1, 1328, "labins01_la", "bins9_LAe2", 0xFFFFFFFF);
    object_cityhallInterior[47] = CreateDynamicObject(1337, 903.8958, -1463.2926, 2754.5273, 31.9999, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BinNt07_LA
    SetDynamicObjectMaterial(object_cityhallInterior[47], 1, 1328, "labins01_la", "bins9_LAe2", 0xFFFFFFFF);
    object_cityhallInterior[48] = CreateDynamicObject(2593, 904.4027, -1465.8520, 2754.1142, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roleplay_rack
    object_cityhallInterior[49] = CreateDynamicObject(2593, 904.4027, -1464.6418, 2754.1142, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roleplay_rack
    object_cityhallInterior[50] = CreateDynamicObject(19450, 911.7766, -1461.8607, 2752.3906, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[50], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[51] = CreateDynamicObject(1569, 911.7252, -1459.2601, 2753.2839, 0.0000, 0.0000, -122.0998, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    object_cityhallInterior[52] = CreateDynamicObject(19174, 904.8389, -1469.5666, 2755.6752, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterial(object_cityhallInterior[52], 0, 2266, "picture_frame", "CJ_PAINTING3", 0xFFFFFFFF);
    object_cityhallInterior[53] = CreateDynamicObject(19174, 904.8389, -1459.3762, 2755.6752, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterial(object_cityhallInterior[53], 0, 2266, "picture_frame", "CJ_PAINTING16", 0xFFFFFFFF);
    object_cityhallInterior[54] = CreateDynamicObject(19450, 915.3461, -1463.5118, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[54], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[55] = CreateDynamicObject(19450, 913.4473, -1463.5218, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[55], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[56] = CreateDynamicObject(2162, 926.0319, -1463.4350, 2753.2990, 0.0000, 0.0000, -180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_cityhallInterior[57] = CreateDynamicObject(19565, 909.4722, -1457.0998, 2756.3854, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[57], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[58] = CreateDynamicObject(19402, 918.8341, -1462.7749, 2755.0104, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall050
    SetDynamicObjectMaterial(object_cityhallInterior[58], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[59] = CreateDynamicObject(19450, 917.1854, -1464.6108, 2753.2399, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[59], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[60] = CreateDynamicObject(19450, 916.5449, -1464.6108, 2753.2500, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[60], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[61] = CreateDynamicObject(19466, 918.9342, -1462.7762, 2756.4970, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    object_cityhallInterior[62] = CreateDynamicObject(19087, 919.7230, -1462.7740, 2756.3122, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[62], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[63] = CreateDynamicObject(19087, 917.9428, -1462.7740, 2756.3122, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[63], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[64] = CreateDynamicObject(19087, 919.8325, -1462.7740, 2755.5312, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[64], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[65] = CreateDynamicObject(19087, 919.8325, -1462.7740, 2755.8715, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[65], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[66] = CreateDynamicObject(19087, 919.8325, -1462.7740, 2754.4501, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[66], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[67] = CreateDynamicObject(19087, 918.8919, -1462.7740, 2755.5412, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[67], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[68] = CreateDynamicObject(18762, 916.7473, -1463.0930, 2754.7031, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[68], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[69] = CreateDynamicObject(19385, 911.7733, -1458.5091, 2755.0256, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall033
    SetDynamicObjectMaterial(object_cityhallInterior[69], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[70] = CreateDynamicObject(19464, 907.7542, -1456.9422, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[70], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[71] = CreateDynamicObject(19464, 908.7846, -1456.9621, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[71], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[72] = CreateDynamicObject(3051, 910.3054, -1457.1009, 2754.6354, 0.0000, 0.0000, 135.6000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[72], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[73] = CreateDynamicObject(3051, 907.3848, -1457.0985, 2754.6354, 0.0000, 0.0000, 135.6000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[73], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[74] = CreateDynamicObject(19565, 909.9224, -1457.0998, 2756.3854, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[74], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[75] = CreateDynamicObject(3051, 909.0891, -1457.1036, 2754.6354, 0.0000, 0.0000, -43.9000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[75], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[76] = CreateDynamicObject(3051, 906.1680, -1457.0931, 2754.6354, 0.0000, 0.0000, -43.9000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[76], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[77] = CreateDynamicObject(19565, 909.9323, -1457.1499, 2756.4155, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[77], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[78] = CreateDynamicObject(19565, 909.4622, -1457.1499, 2756.4155, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[78], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[79] = CreateDynamicObject(19565, 909.4622, -1457.1499, 2756.6357, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[79], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[80] = CreateDynamicObject(19565, 909.9326, -1457.1499, 2756.6357, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[80], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[81] = CreateDynamicObject(19565, 909.2525, -1456.9095, 2756.4055, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[81], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[82] = CreateDynamicObject(19565, 910.1328, -1456.9095, 2756.4055, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[82], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[83] = CreateDynamicObject(19565, 907.2523, -1456.9095, 2756.4055, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[83], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[84] = CreateDynamicObject(19565, 906.3621, -1456.9095, 2756.4055, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[84], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[85] = CreateDynamicObject(19565, 906.5822, -1457.1499, 2756.4055, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[85], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[86] = CreateDynamicObject(19565, 907.0526, -1457.1499, 2756.4055, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[86], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[87] = CreateDynamicObject(19565, 906.5623, -1457.1499, 2756.6455, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[87], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[88] = CreateDynamicObject(19565, 907.0327, -1457.1499, 2756.6455, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[88], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[89] = CreateDynamicObject(19565, 906.5625, -1457.1499, 2756.4052, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[89], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[90] = CreateDynamicObject(19174, 909.6889, -1457.1361, 2756.5361, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[90], 0, "1. Stock", 90, "Arial Black", 14, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[90], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[91] = CreateDynamicObject(19174, 906.8087, -1457.1361, 2756.5361, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[91], 0, "1. Stock", 90, "Arial Black", 14, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[91], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[92] = CreateDynamicObject(19174, 915.0288, -1463.6440, 2755.8454, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[92], 0, "Cityhall", 90, "Times New Roman", 40, 1, 0xFFA5A9A7, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[92], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[93] = CreateDynamicObject(19174, 915.0288, -1463.6440, 2755.4851, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[93], 0, "Los Santos", 90, "Times New Roman", 25, 1, 0xFFA5A9A7, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[93], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[94] = CreateDynamicObject(1753, 908.0017, -1472.2602, 2753.2915, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[94], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[95] = CreateDynamicObject(19174, 909.4691, -1457.0837, 2754.0336, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[95], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[95], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[96] = CreateDynamicObject(19174, 907.0280, -1457.0837, 2754.9841, 0.0000, 180.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[96], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[96], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[97] = CreateDynamicObject(2315, 924.1851, -1472.9880, 2753.3061, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE4
    object_cityhallInterior[98] = CreateDynamicObject(19464, 921.7551, -1475.7132, 2751.6335, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[98], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[99] = CreateDynamicObject(19464, 921.7249, -1475.6832, 2750.9328, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[99], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[100] = CreateDynamicObject(19464, 921.7951, -1475.6933, 2750.9328, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[100], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[101] = CreateDynamicObject(19565, 921.6159, -1475.3172, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[101], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[102] = CreateDynamicObject(19565, 921.6159, -1475.7873, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[102], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[103] = CreateDynamicObject(19565, 921.6159, -1474.8465, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[103], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[104] = CreateDynamicObject(19565, 921.6159, -1474.3763, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[104], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[105] = CreateDynamicObject(19565, 921.6159, -1473.9056, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[105], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[106] = CreateDynamicObject(19565, 921.6159, -1473.4355, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[106], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[107] = CreateDynamicObject(19565, 921.6159, -1472.9753, 2754.1630, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[107], 0, 15048, "labigsave", "ah_carpet2kb", 0xFFFFFFFF);
    object_cityhallInterior[108] = CreateDynamicObject(19450, 926.7258, -1472.9619, 2753.2500, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[108], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[109] = CreateDynamicObject(19450, 926.7258, -1476.4620, 2753.2700, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[109], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[110] = CreateDynamicObject(19464, 924.8234, -1475.9718, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[110], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[111] = CreateDynamicObject(19464, 930.7633, -1475.9718, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[111], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[112] = CreateDynamicObject(19464, 931.2830, -1475.7220, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[112], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[113] = CreateDynamicObject(2001, 922.5961, -1475.1645, 2753.3142, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    SetDynamicObjectMaterial(object_cityhallInterior[113], 1, 630, "gta_potplants", "kb_teracota_pot64", 0xFFFFFFFF);
    object_cityhallInterior[114] = CreateDynamicObject(1753, 925.8120, -1475.3032, 2753.2915, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[114], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[115] = CreateDynamicObject(2001, 926.9959, -1475.1645, 2753.3142, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    SetDynamicObjectMaterial(object_cityhallInterior[115], 1, 630, "gta_potplants", "kb_teracota_pot64", 0xFFFFFFFF);
    object_cityhallInterior[116] = CreateDynamicObject(19786, 924.9046, -1475.9768, 2755.8620, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[116], 0, 14570, "traidaqua", "ab_tv", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[116], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[117] = CreateDynamicObject(19825, 929.0645, -1475.8176, 2756.0183, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
    object_cityhallInterior[118] = CreateDynamicObject(1708, 922.4799, -1472.6322, 2753.2717, 0.0000, 0.0000, 89.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair02
    SetDynamicObjectMaterial(object_cityhallInterior[118], 1, 1746, "cj_sofa", "CJ_FAB4", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[118], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[119] = CreateDynamicObject(1708, 922.4628, -1474.1623, 2753.2717, 0.0000, 0.0000, 89.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair02
    SetDynamicObjectMaterial(object_cityhallInterior[119], 1, 1746, "cj_sofa", "CJ_FAB4", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[119], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[120] = CreateDynamicObject(1708, 927.5222, -1473.0107, 2753.2717, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair02
    SetDynamicObjectMaterial(object_cityhallInterior[120], 1, 1746, "cj_sofa", "CJ_FAB4", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[120], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[121] = CreateDynamicObject(1708, 927.5123, -1471.4803, 2753.2717, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair02
    SetDynamicObjectMaterial(object_cityhallInterior[121], 1, 1746, "cj_sofa", "CJ_FAB4", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[121], 2, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[122] = CreateDynamicObject(955, 930.7802, -1473.5239, 2753.6857, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_EXT_SPRUNK
    object_cityhallInterior[123] = CreateDynamicObject(956, 930.8322, -1474.9178, 2753.7165, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_EXT_CANDY
    object_cityhallInterior[124] = CreateDynamicObject(2816, 924.3339, -1472.9720, 2753.8125, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags01
    object_cityhallInterior[125] = CreateDynamicObject(2855, 925.5050, -1472.9338, 2753.8032, 0.0000, 0.0000, -48.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags05
    object_cityhallInterior[126] = CreateDynamicObject(19450, 927.4669, -1461.8607, 2752.3906, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[126], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[127] = CreateDynamicObject(18762, 920.9376, -1463.0930, 2754.7031, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[127], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[128] = CreateDynamicObject(19450, 922.2877, -1463.5218, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[128], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[129] = CreateDynamicObject(19174, 924.0399, -1463.6440, 2755.5251, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[129], 0, "Los Santos", 90, "Times New Roman", 25, 1, 0xFFA5A9A7, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[129], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[130] = CreateDynamicObject(19174, 924.0399, -1463.6440, 2755.8454, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[130], 0, "Cityhall", 90, "Times New Roman", 40, 1, 0xFFA5A9A7, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[130], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[131] = CreateDynamicObject(19385, 927.4738, -1458.5091, 2755.0256, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall033
    SetDynamicObjectMaterial(object_cityhallInterior[131], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[132] = CreateDynamicObject(1569, 927.4956, -1459.2479, 2753.2839, 0.0000, 0.0000, -48.7999, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    object_cityhallInterior[133] = CreateDynamicObject(19174, 918.8895, -1462.8747, 2756.3559, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[133], 0, "i", 90, "Webdings", 70, 1, 0xFFA5A9A7, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[133], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[134] = CreateDynamicObject(18981, 918.0518, -1454.1363, 2757.7150, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[134], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[135] = CreateDynamicObject(18981, 897.3908, -1463.8270, 2757.7150, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[135], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[136] = CreateDynamicObject(18981, 943.0202, -1463.8270, 2757.7150, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[136], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[137] = CreateDynamicObject(19464, 934.9027, -1464.8940, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[137], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[138] = CreateDynamicObject(18981, 923.0510, -1463.5339, 2752.8317, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[138], 0, 15034, "genhotelsave", "bathtile05_int", 0xFFFFFFFF);
    object_cityhallInterior[139] = CreateDynamicObject(19450, 922.7354, -1464.6108, 2753.2600, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[139], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[140] = CreateDynamicObject(19464, 934.1234, -1472.8424, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[140], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[141] = CreateDynamicObject(19464, 934.9027, -1470.8310, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[141], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[142] = CreateDynamicObject(1753, 934.0222, -1472.2602, 2753.2915, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[142], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[143] = CreateDynamicObject(3034, 934.7407, -1465.0699, 2755.4609, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bd_window
    SetDynamicObjectMaterial(object_cityhallInterior[143], 0, 9901, "ferry_building", "skylight_windows", 0xFFFFFFFF);
    object_cityhallInterior[144] = CreateDynamicObject(19430, 934.8759, -1466.7534, 2757.2348, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[144], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[145] = CreateDynamicObject(19450, 925.7769, -1463.5218, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[145], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[146] = CreateDynamicObject(19430, 934.8759, -1462.4420, 2757.2348, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[146], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[147] = CreateDynamicObject(19174, 934.7780, -1459.5168, 2755.6752, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterial(object_cityhallInterior[147], 0, 2266, "picture_frame", "CJ_PAINTING16", 0xFFFFFFFF);
    object_cityhallInterior[148] = CreateDynamicObject(19174, 934.7780, -1470.5576, 2755.6752, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterial(object_cityhallInterior[148], 0, 2254, "picture_frame_clip", "CJ_PAINTING15", 0xFFFFFFFF);
    object_cityhallInterior[149] = CreateDynamicObject(19450, 933.2952, -1476.0218, 2753.2500, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[149], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[150] = CreateDynamicObject(19450, 906.5750, -1476.0218, 2753.2500, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[150], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[151] = CreateDynamicObject(19450, 913.1157, -1472.9416, 2753.2800, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[151], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[152] = CreateDynamicObject(3051, 929.1109, -1457.0914, 2754.6354, 0.0000, 0.0000, -43.9000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[152], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[153] = CreateDynamicObject(3051, 930.3195, -1457.1086, 2754.6354, 0.0000, 0.0000, 134.6999, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[153], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[154] = CreateDynamicObject(3051, 933.3319, -1457.0992, 2754.6354, 0.0000, 0.0000, 136.6000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[154], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[155] = CreateDynamicObject(3051, 932.1450, -1457.0965, 2754.6354, 0.0000, 0.0000, -43.9000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[155], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[156] = CreateDynamicObject(19174, 930.0083, -1457.0837, 2754.9841, 0.0000, 180.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[156], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[156], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[157] = CreateDynamicObject(19174, 932.4487, -1457.0837, 2754.0231, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[157], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[157], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[158] = CreateDynamicObject(19464, 934.9027, -1458.9647, 2755.7070, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[158], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[159] = CreateDynamicObject(18766, 925.5288, -1463.5604, 2758.5424, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[159], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
    object_cityhallInterior[160] = CreateDynamicObject(19464, 931.9254, -1456.9621, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[160], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[161] = CreateDynamicObject(19464, 926.0551, -1456.9422, 2755.7070, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[161], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[162] = CreateDynamicObject(18766, 914.8186, -1463.5604, 2758.5424, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[162], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
    object_cityhallInterior[163] = CreateDynamicObject(18766, 924.1887, -1463.5604, 2758.5424, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[163], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
    object_cityhallInterior[164] = CreateDynamicObject(18766, 907.2075, -1470.9383, 2758.5424, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[164], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
    object_cityhallInterior[165] = CreateDynamicObject(18766, 907.3577, -1461.0788, 2758.5424, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[165], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
    object_cityhallInterior[166] = CreateDynamicObject(18766, 933.2080, -1470.9383, 2758.5424, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[166], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
    object_cityhallInterior[167] = CreateDynamicObject(18981, 918.0518, -1454.1363, 2759.4965, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[167], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[168] = CreateDynamicObject(18981, 897.3908, -1463.8270, 2759.4863, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[168], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[169] = CreateDynamicObject(18981, 942.9807, -1463.8270, 2759.4863, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[169], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[170] = CreateDynamicObject(18762, 913.1666, -1473.9322, 2759.4521, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[170], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[171] = CreateDynamicObject(18762, 913.1666, -1469.0615, 2759.4519, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[171], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[172] = CreateDynamicObject(18762, 927.4771, -1473.9322, 2759.5019, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[172], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[173] = CreateDynamicObject(18762, 927.4771, -1468.9621, 2759.5019, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[173], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[174] = CreateDynamicObject(19464, 924.8234, -1475.9615, 2760.7905, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[174], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[175] = CreateDynamicObject(19464, 918.8933, -1475.9615, 2760.7905, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[175], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[176] = CreateDynamicObject(19464, 912.9534, -1475.9615, 2760.7905, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[176], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[177] = CreateDynamicObject(19464, 910.1743, -1475.9914, 2762.0214, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[177], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[178] = CreateDynamicObject(19464, 939.3153, -1475.9914, 2762.0214, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[178], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[179] = CreateDynamicObject(19464, 918.8933, -1476.1118, 2757.9890, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[179], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[180] = CreateDynamicObject(18766, 933.0078, -1461.0710, 2758.5424, 90.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[180], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
    object_cityhallInterior[181] = CreateDynamicObject(3858, 909.8286, -1473.8785, 2762.0288, 0.0000, 0.0000, -45.2000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_cityhallInterior[181], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[182] = CreateDynamicObject(3859, 912.4848, -1466.5985, 2762.0224, 0.0000, 0.0000, 106.8000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash04
    SetDynamicObjectMaterial(object_cityhallInterior[182], 0, 1717, "cj_tv", "green_glass_64", 0xFF9F9D94);
    object_cityhallInterior[183] = CreateDynamicObject(3859, 917.5772, -1466.6174, 2762.0224, 0.0000, 0.0000, 106.8000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash04
    SetDynamicObjectMaterial(object_cityhallInterior[183], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[184] = CreateDynamicObject(3859, 922.6889, -1466.6313, 2762.0224, 0.0000, 0.0000, 107.0998, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash04
    SetDynamicObjectMaterial(object_cityhallInterior[184], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[185] = CreateDynamicObject(3858, 930.5883, -1473.8929, 2762.0288, 0.0000, 0.0000, -44.7000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_cityhallInterior[185], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[186] = CreateDynamicObject(1897, 920.0504, -1466.5904, 2761.1047, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[187] = CreateDynamicObject(1897, 920.0504, -1466.5904, 2763.3256, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[188] = CreateDynamicObject(1897, 920.0504, -1466.5904, 2763.8161, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[189] = CreateDynamicObject(1897, 925.1815, -1466.5904, 2763.8161, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[190] = CreateDynamicObject(1897, 925.1810, -1466.5904, 2763.3256, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[191] = CreateDynamicObject(1897, 925.1810, -1466.5904, 2761.1057, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[192] = CreateDynamicObject(1897, 930.4218, -1466.5904, 2761.1047, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[193] = CreateDynamicObject(1897, 930.4212, -1466.5904, 2763.3256, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[194] = CreateDynamicObject(1897, 930.4212, -1466.5904, 2763.8161, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[195] = CreateDynamicObject(1897, 914.9406, -1466.5904, 2763.8161, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[196] = CreateDynamicObject(1897, 914.9406, -1466.5904, 2763.3256, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[197] = CreateDynamicObject(1897, 914.9412, -1466.5904, 2761.1057, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[198] = CreateDynamicObject(1897, 909.9411, -1466.5904, 2761.1057, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[199] = CreateDynamicObject(1897, 909.9409, -1466.5904, 2763.3256, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[200] = CreateDynamicObject(1897, 909.9403, -1466.5904, 2763.8161, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[201] = CreateDynamicObject(19087, 914.9141, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[201], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[202] = CreateDynamicObject(19087, 912.5037, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[202], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[203] = CreateDynamicObject(19087, 917.4243, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[203], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[204] = CreateDynamicObject(19087, 919.8441, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[204], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[205] = CreateDynamicObject(19087, 922.2941, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[205], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[206] = CreateDynamicObject(19087, 924.7442, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[206], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[207] = CreateDynamicObject(19087, 927.1638, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[207], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[208] = CreateDynamicObject(19087, 929.5642, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[208], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[209] = CreateDynamicObject(19087, 930.3847, -1466.5832, 2764.9125, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[209], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[210] = CreateDynamicObject(19087, 930.3350, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[210], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[211] = CreateDynamicObject(19087, 927.8847, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[211], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[212] = CreateDynamicObject(19087, 925.4448, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[212], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[213] = CreateDynamicObject(1897, 909.8302, -1475.7408, 2763.8161, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[214] = CreateDynamicObject(19087, 920.5443, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[214], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[215] = CreateDynamicObject(19087, 918.1032, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[215], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[216] = CreateDynamicObject(19087, 915.6630, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[216], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[217] = CreateDynamicObject(19087, 913.2529, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[217], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[218] = CreateDynamicObject(19087, 912.5025, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[218], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[219] = CreateDynamicObject(19087, 912.5025, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[219], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[220] = CreateDynamicObject(19087, 914.9229, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[220], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[221] = CreateDynamicObject(19087, 917.5131, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[221], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[222] = CreateDynamicObject(19087, 919.9437, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[222], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[223] = CreateDynamicObject(19087, 922.6140, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[223], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[224] = CreateDynamicObject(19087, 925.0349, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[224], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[225] = CreateDynamicObject(19087, 927.4047, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[225], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[226] = CreateDynamicObject(19087, 929.8048, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[226], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[227] = CreateDynamicObject(19087, 930.3850, -1466.5832, 2762.2011, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[227], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[228] = CreateDynamicObject(19087, 923.0048, -1466.5832, 2764.4221, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[228], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[229] = CreateDynamicObject(1897, 909.8308, -1475.7419, 2763.3256, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[230] = CreateDynamicObject(1897, 909.8308, -1475.7419, 2761.1062, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[231] = CreateDynamicObject(1897, 909.8308, -1471.2009, 2761.1062, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[232] = CreateDynamicObject(1897, 909.8308, -1471.2010, 2763.3256, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[233] = CreateDynamicObject(1897, 909.8302, -1471.2004, 2763.8161, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[234] = CreateDynamicObject(19087, 909.8543, -1468.6241, 2764.4221, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[234], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[235] = CreateDynamicObject(19087, 909.8543, -1466.6048, 2764.4221, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[235], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[236] = CreateDynamicObject(19087, 909.8543, -1471.3337, 2764.4221, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[236], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[237] = CreateDynamicObject(19087, 909.8543, -1473.1749, 2764.4221, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[237], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[238] = CreateDynamicObject(19087, 909.8543, -1473.1749, 2764.9125, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[238], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[239] = CreateDynamicObject(19087, 909.8543, -1470.7441, 2764.9125, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[239], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[240] = CreateDynamicObject(19087, 909.8543, -1468.3044, 2764.9125, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[240], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[241] = CreateDynamicObject(19087, 909.8543, -1466.6335, 2764.9125, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[241], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[242] = CreateDynamicObject(19087, 909.8543, -1473.2651, 2762.2016, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[242], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[243] = CreateDynamicObject(19087, 909.8543, -1470.8254, 2762.2016, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[243], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[244] = CreateDynamicObject(19087, 909.8543, -1468.4858, 2762.2016, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[244], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[245] = CreateDynamicObject(19087, 909.8543, -1466.6445, 2762.2016, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[245], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[246] = CreateDynamicObject(3859, 927.8892, -1466.6334, 2762.0224, 0.0000, 0.0000, 107.0998, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash04
    SetDynamicObjectMaterial(object_cityhallInterior[246], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[247] = CreateDynamicObject(1897, 930.5916, -1471.2004, 2763.8161, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[248] = CreateDynamicObject(1897, 930.5916, -1471.2010, 2763.3256, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[249] = CreateDynamicObject(1897, 930.5913, -1471.2009, 2761.1062, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[250] = CreateDynamicObject(1897, 930.5913, -1475.7423, 2761.1062, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[251] = CreateDynamicObject(1897, 930.5905, -1475.7419, 2763.3256, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[252] = CreateDynamicObject(1897, 930.5902, -1475.7408, 2763.8161, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_support
    object_cityhallInterior[253] = CreateDynamicObject(19087, 930.5562, -1466.6445, 2762.2016, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[253], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[254] = CreateDynamicObject(19087, 930.5562, -1468.9952, 2762.2016, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[254], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[255] = CreateDynamicObject(19087, 930.5562, -1471.4339, 2762.2016, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[255], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[256] = CreateDynamicObject(19087, 930.5562, -1473.8431, 2762.2016, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[256], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[257] = CreateDynamicObject(19087, 930.5562, -1473.8431, 2764.4338, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[257], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[258] = CreateDynamicObject(19087, 930.5562, -1471.3935, 2764.4338, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[258], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[259] = CreateDynamicObject(19087, 930.5562, -1469.0124, 2764.4338, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[259], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[260] = CreateDynamicObject(19087, 930.5562, -1466.5511, 2764.4338, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[260], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[261] = CreateDynamicObject(19087, 930.5562, -1466.5511, 2764.9143, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[261], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[262] = CreateDynamicObject(19087, 930.5562, -1468.9724, 2764.9143, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[262], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[263] = CreateDynamicObject(19087, 930.5562, -1471.3735, 2764.9143, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[263], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[264] = CreateDynamicObject(19087, 930.5562, -1473.8155, 2764.9143, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_cityhallInterior[264], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[265] = CreateDynamicObject(19565, 929.9935, -1457.1499, 2756.6357, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[265], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[266] = CreateDynamicObject(19565, 932.5051, -1457.1499, 2756.6357, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[266], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[267] = CreateDynamicObject(19565, 932.8754, -1457.1499, 2756.6357, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[267], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[268] = CreateDynamicObject(19565, 929.6226, -1457.1499, 2756.4155, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[268], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[269] = CreateDynamicObject(19565, 929.9931, -1457.1499, 2756.4155, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[269], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[270] = CreateDynamicObject(19565, 932.5037, -1457.1499, 2756.4155, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[270], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[271] = CreateDynamicObject(19565, 932.8837, -1457.1499, 2756.4155, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[271], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[272] = CreateDynamicObject(19174, 929.8189, -1457.1361, 2756.5361, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[272], 0, "1. Stock", 90, "Arial Black", 14, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[272], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[273] = CreateDynamicObject(19174, 932.6793, -1457.1361, 2756.5361, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[273], 0, "1. Stock", 90, "Arial Black", 14, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[273], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[274] = CreateDynamicObject(19565, 929.4240, -1456.9095, 2756.3754, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[274], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[275] = CreateDynamicObject(19565, 930.1942, -1456.9095, 2756.3754, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[275], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[276] = CreateDynamicObject(19565, 932.2946, -1456.9095, 2756.3754, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[276], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[277] = CreateDynamicObject(19565, 933.0853, -1456.9095, 2756.3754, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[277], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[278] = CreateDynamicObject(11711, 920.2321, -1475.9582, 2756.0922, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    object_cityhallInterior[279] = CreateDynamicObject(19450, 915.3059, -1457.0123, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[279], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[280] = CreateDynamicObject(19450, 913.4359, -1457.0023, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[280], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[281] = CreateDynamicObject(19450, 925.8062, -1456.9923, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[281], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[282] = CreateDynamicObject(19450, 922.7467, -1457.0123, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[282], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[283] = CreateDynamicObject(19450, 918.8057, -1457.0223, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[283], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[284] = CreateDynamicObject(19450, 916.5449, -1461.1208, 2753.2600, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[284], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[285] = CreateDynamicObject(19450, 916.5449, -1457.8409, 2753.2500, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[285], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[286] = CreateDynamicObject(19450, 922.7354, -1461.1175, 2753.2500, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[286], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[287] = CreateDynamicObject(19450, 922.7354, -1457.6269, 2753.2600, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[287], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[288] = CreateDynamicObject(19450, 922.2871, -1457.0223, 2752.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[288], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF3D4A68);
    object_cityhallInterior[289] = CreateDynamicObject(19430, 918.8248, -1462.7816, 2757.2348, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[289], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF46597A);
    object_cityhallInterior[290] = CreateDynamicObject(2162, 923.5117, -1463.4350, 2753.2990, 0.0000, 0.0000, -180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_cityhallInterior[291] = CreateDynamicObject(2162, 915.5119, -1463.4350, 2753.2990, 0.0000, 0.0000, -180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_cityhallInterior[292] = CreateDynamicObject(2162, 913.4514, -1463.4350, 2753.2990, 0.0000, 0.0000, -180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_cityhallInterior[293] = CreateDynamicObject(2199, 927.3060, -1460.9044, 2753.1269, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_MC_1
    SetDynamicObjectMaterial(object_cityhallInterior[293], 2, 14650, "ab_trukstpc", "sa_wood08_128", 0xFFFFFFFF);
    object_cityhallInterior[294] = CreateDynamicObject(2199, 911.9057, -1461.3148, 2753.1269, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_MC_1
    SetDynamicObjectMaterial(object_cityhallInterior[294], 2, 14650, "ab_trukstpc", "sa_wood08_128", 0xFFFFFFFF);
    object_cityhallInterior[295] = CreateDynamicObject(1671, 918.5828, -1460.8330, 2753.7797, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_cityhallInterior[296] = CreateDynamicObject(2817, 914.6895, -1473.4670, 2753.7687, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedrug01
    SetDynamicObjectMaterial(object_cityhallInterior[296], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[297] = CreateDynamicObject(2817, 914.6895, -1473.4670, 2753.8088, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedrug01
    SetDynamicObjectMaterial(object_cityhallInterior[297], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[298] = CreateDynamicObject(2817, 914.6895, -1473.4770, 2753.7687, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedrug01
    SetDynamicObjectMaterial(object_cityhallInterior[298], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[299] = CreateDynamicObject(2817, 924.4199, -1473.4770, 2753.7687, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedrug01
    SetDynamicObjectMaterial(object_cityhallInterior[299], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[300] = CreateDynamicObject(2817, 924.4199, -1473.4770, 2753.7988, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedrug01
    SetDynamicObjectMaterial(object_cityhallInterior[300], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[301] = CreateDynamicObject(1999, 919.2733, -1462.1870, 2753.2299, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //officedesk2
    SetDynamicObjectMaterial(object_cityhallInterior[301], 0, 18232, "cw_truckstopcs_t", "des_roswin3", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[301], 1, 14802, "lee_bdupsflat", "Bdup_table", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[301], 2, 14802, "lee_bdupsflat", "Bdup_table", 0xFFFFFFFF);
    object_cityhallInterior[302] = CreateDynamicObject(2163, 924.7196, -1456.9438, 2754.5229, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_cityhallInterior[303] = CreateDynamicObject(2163, 922.4096, -1456.9438, 2754.5229, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_cityhallInterior[304] = CreateDynamicObject(2163, 913.0283, -1456.9438, 2754.5229, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_cityhallInterior[305] = CreateDynamicObject(2163, 915.2387, -1456.9438, 2754.5229, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_cityhallInterior[306] = CreateDynamicObject(19825, 919.1264, -1457.1561, 2756.2692, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
    object_cityhallInterior[307] = CreateDynamicObject(2200, 918.3737, -1457.1142, 2753.3464, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_UNIT_1
    object_cityhallInterior[308] = CreateDynamicObject(16780, 914.5795, -1460.3094, 2757.3347, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light03
    object_cityhallInterior[309] = CreateDynamicObject(16780, 923.9711, -1460.3094, 2757.3347, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light03
    object_cityhallInterior[310] = CreateDynamicObject(14687, 921.2670, -1462.5118, 2755.5612, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[311] = CreateDynamicObject(14687, 934.2390, -1458.7705, 2755.5612, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[312] = CreateDynamicObject(14687, 934.2490, -1463.6103, 2755.5612, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[313] = CreateDynamicObject(14687, 934.2188, -1468.0317, 2755.5612, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[314] = CreateDynamicObject(14687, 910.8579, -1463.6103, 2755.5612, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[315] = CreateDynamicObject(14687, 910.8579, -1458.7292, 2755.5612, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[316] = CreateDynamicObject(14687, 910.8579, -1468.0600, 2755.5612, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[317] = CreateDynamicObject(14687, 926.0379, -1465.9333, 2755.5612, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[318] = CreateDynamicObject(14687, 916.5460, -1465.9333, 2755.5612, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights02
    object_cityhallInterior[319] = CreateDynamicObject(3051, 910.3054, -1457.1009, 2761.3532, 0.0000, 0.0000, 135.6000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[319], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[320] = CreateDynamicObject(3051, 907.3848, -1457.0985, 2761.3666, 0.0000, 0.0000, 135.6000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[320], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[321] = CreateDynamicObject(3051, 909.0891, -1457.1036, 2761.3569, 0.0000, 0.0000, -43.9000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[321], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[322] = CreateDynamicObject(3051, 906.1680, -1457.0931, 2761.3669, 0.0000, 0.0000, -43.9000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[322], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[323] = CreateDynamicObject(3051, 929.1109, -1457.0914, 2761.3395, 0.0000, 0.0000, -43.9000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[323], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[324] = CreateDynamicObject(3051, 930.3195, -1457.1086, 2761.3398, 0.0000, 0.0000, 134.6999, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[324], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[325] = CreateDynamicObject(3051, 933.3319, -1457.0992, 2761.3481, 0.0000, 0.0000, 136.6000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[325], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[326] = CreateDynamicObject(3051, 932.1450, -1457.0965, 2761.3471, 0.0000, 0.0000, -43.9000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_cityhallInterior[326], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_cityhallInterior[327] = CreateDynamicObject(19464, 932.2858, -1456.9621, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[327], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[328] = CreateDynamicObject(19464, 930.2645, -1456.9421, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[328], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[329] = CreateDynamicObject(19464, 907.3543, -1456.9421, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[329], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[330] = CreateDynamicObject(19464, 909.2437, -1456.9521, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[330], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[331] = CreateDynamicObject(19174, 930.0083, -1457.0837, 2761.5593, 0.0000, 180.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[331], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[331], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[332] = CreateDynamicObject(19174, 907.0269, -1457.0837, 2761.5593, 0.0000, 180.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[332], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[332], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[333] = CreateDynamicObject(19174, 909.4674, -1457.0837, 2760.6384, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[333], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[333], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[334] = CreateDynamicObject(19174, 932.4478, -1457.0837, 2760.6384, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[334], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[334], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[335] = CreateDynamicObject(19174, 932.7396, -1457.1361, 2763.1921, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[335], 0, "E.G.", 90, "Arial Black", 20, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[335], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[336] = CreateDynamicObject(19174, 906.8192, -1457.1361, 2763.1921, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[336], 0, "E.G.", 90, "Arial Black", 20, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[336], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[337] = CreateDynamicObject(19174, 909.7092, -1457.1361, 2763.1921, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[337], 0, "E.G.", 90, "Arial Black", 20, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[337], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[338] = CreateDynamicObject(19565, 907.0526, -1457.1499, 2763.0705, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[338], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[339] = CreateDynamicObject(19565, 906.5822, -1457.1499, 2763.0705, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[339], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[340] = CreateDynamicObject(19565, 909.5128, -1457.1499, 2763.0705, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[340], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[341] = CreateDynamicObject(19565, 909.9533, -1457.1499, 2763.0705, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[341], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[342] = CreateDynamicObject(19565, 909.9533, -1457.1499, 2763.3208, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[342], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[343] = CreateDynamicObject(19565, 909.5128, -1457.1499, 2763.3208, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[343], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[344] = CreateDynamicObject(19565, 907.0526, -1457.1499, 2763.3208, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[344], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[345] = CreateDynamicObject(19565, 906.5825, -1457.1499, 2763.3208, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[345], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[346] = CreateDynamicObject(19565, 929.6544, -1457.1499, 2763.3208, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[346], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[347] = CreateDynamicObject(19565, 930.0045, -1457.1499, 2763.3208, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[347], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[348] = CreateDynamicObject(19565, 932.5454, -1457.1499, 2763.3208, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[348], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[349] = CreateDynamicObject(19565, 932.9459, -1457.1499, 2763.3208, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[349], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[350] = CreateDynamicObject(19565, 932.9459, -1457.1499, 2763.0905, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[350], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[351] = CreateDynamicObject(19565, 932.5454, -1457.1499, 2763.0905, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[351], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[352] = CreateDynamicObject(19565, 929.9940, -1457.1499, 2763.0905, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[352], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[353] = CreateDynamicObject(19565, 929.6536, -1457.1499, 2763.0905, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[353], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[354] = CreateDynamicObject(19565, 929.4539, -1456.9095, 2763.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[354], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[355] = CreateDynamicObject(19565, 930.2045, -1456.9095, 2763.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[355], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[356] = CreateDynamicObject(19565, 932.3449, -1456.9095, 2763.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[356], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[357] = CreateDynamicObject(19565, 933.1455, -1456.9095, 2763.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[357], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[358] = CreateDynamicObject(19565, 910.1544, -1456.9095, 2763.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[358], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[359] = CreateDynamicObject(19565, 909.3046, -1456.9095, 2763.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[359], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[360] = CreateDynamicObject(19565, 907.2540, -1456.9095, 2763.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[360], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[361] = CreateDynamicObject(19565, 906.3842, -1456.9095, 2763.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_cityhallInterior[361], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[362] = CreateDynamicObject(19387, 922.6312, -1457.0212, 2761.6650, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_cityhallInterior[362], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[363] = CreateDynamicObject(19464, 917.4323, -1456.9128, 2765.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[363], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[364] = CreateDynamicObject(19464, 927.1738, -1456.9331, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[364], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[365] = CreateDynamicObject(19464, 911.5225, -1456.9331, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[365], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[366] = CreateDynamicObject(19464, 921.2628, -1456.9331, 2765.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[366], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[367] = CreateDynamicObject(19387, 916.0405, -1457.0412, 2761.6650, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_cityhallInterior[367], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[368] = CreateDynamicObject(19174, 921.0272, -1457.1136, 2761.4895, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[368], 0, "Damen ", 90, "Arial", 15, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[368], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[369] = CreateDynamicObject(1753, 925.3228, -1457.5426, 2759.9807, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[369], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[370] = CreateDynamicObject(1753, 911.7719, -1457.5426, 2759.9807, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[370], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[371] = CreateDynamicObject(19464, 938.5737, -1461.3734, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[371], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[372] = CreateDynamicObject(19464, 901.4240, -1456.9521, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[372], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[373] = CreateDynamicObject(19464, 901.0338, -1466.3739, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[373], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[374] = CreateDynamicObject(19464, 901.0341, -1458.5622, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[374], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[375] = CreateDynamicObject(19387, 938.5313, -1465.9105, 2761.6650, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_cityhallInterior[375], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[376] = CreateDynamicObject(3858, 927.8206, -1473.8166, 2764.9653, -45.5998, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_cityhallInterior[376], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[377] = CreateDynamicObject(3858, 922.0006, -1473.8166, 2764.9653, -45.5998, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_cityhallInterior[377], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[378] = CreateDynamicObject(3858, 916.1806, -1473.8166, 2764.9653, -45.5998, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_cityhallInterior[378], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[379] = CreateDynamicObject(3858, 910.3609, -1473.8166, 2764.9653, -45.5998, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ottosmash1
    SetDynamicObjectMaterial(object_cityhallInterior[379], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_cityhallInterior[380] = CreateDynamicObject(18981, 897.3908, -1463.8270, 2765.3720, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[380], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[381] = CreateDynamicObject(18981, 943.0200, -1463.8270, 2765.3720, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[381], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[382] = CreateDynamicObject(18981, 920.8698, -1454.0860, 2765.3720, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[382], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[383] = CreateDynamicObject(19430, 911.7835, -1458.6311, 2757.2348, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[383], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF46597A);
    object_cityhallInterior[384] = CreateDynamicObject(19430, 927.4541, -1458.6311, 2757.2348, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[384], 0, 1376, "cranes_dyn2_cj", "ws_oldpaintedblue", 0xFF46597A);
    object_cityhallInterior[385] = CreateDynamicObject(18981, 897.3609, -1463.8270, 2759.5163, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[385], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[386] = CreateDynamicObject(18981, 943.0114, -1463.8270, 2759.5163, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[386], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[387] = CreateDynamicObject(18981, 919.9412, -1454.1279, 2759.5063, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[387], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[388] = CreateDynamicObject(19464, 901.0841, -1473.3723, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[388], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[389] = CreateDynamicObject(19464, 938.5737, -1473.3653, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[389], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[390] = CreateDynamicObject(19464, 938.5836, -1470.4040, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[390], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[391] = CreateDynamicObject(19464, 938.6038, -1466.2845, 2765.8708, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[391], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[392] = CreateDynamicObject(19464, 938.1936, -1456.9521, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[392], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[393] = CreateDynamicObject(19464, 938.5936, -1455.4936, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[393], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[394] = CreateDynamicObject(19464, 934.8055, -1476.1616, 2762.3205, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[394], 0, 14801, "lee_bdupsmain", "Bdup_Blinds", 0xFFFFFFFF);
    object_cityhallInterior[395] = CreateDynamicObject(19464, 905.7351, -1476.1616, 2762.3205, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[395], 0, 14801, "lee_bdupsmain", "Bdup_Blinds", 0xFFFFFFFF);
    object_cityhallInterior[396] = CreateDynamicObject(19464, 900.7233, -1475.9814, 2762.0214, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[396], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[397] = CreateDynamicObject(19464, 912.9534, -1475.9814, 2762.4321, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[397], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[398] = CreateDynamicObject(19464, 918.8842, -1475.9814, 2762.4321, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[398], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[399] = CreateDynamicObject(19464, 924.8151, -1475.9814, 2762.4321, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[399], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[400] = CreateDynamicObject(19464, 929.9545, -1475.9914, 2762.0214, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[400], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[401] = CreateDynamicObject(19464, 929.9545, -1475.9914, 2756.0769, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[401], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[402] = CreateDynamicObject(19464, 907.5247, -1475.9914, 2756.1970, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[402], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[403] = CreateDynamicObject(1753, 937.9417, -1468.2910, 2759.9807, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[403], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[404] = CreateDynamicObject(1753, 937.9417, -1459.7016, 2759.9807, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[404], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[405] = CreateDynamicObject(1753, 937.9417, -1472.6518, 2759.9807, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[405], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[406] = CreateDynamicObject(1753, 901.6710, -1475.1933, 2759.9807, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[406], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[407] = CreateDynamicObject(1753, 901.6710, -1471.3133, 2759.9807, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[407], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[408] = CreateDynamicObject(19464, 901.0640, -1470.4338, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[408], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[409] = CreateDynamicObject(19464, 901.0139, -1461.3629, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[409], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[410] = CreateDynamicObject(19786, 901.1464, -1470.2236, 2762.4023, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[410], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[410], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[411] = CreateDynamicObject(19786, 901.1464, -1474.1933, 2762.4023, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[411], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[411], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[412] = CreateDynamicObject(19786, 901.1464, -1460.6839, 2762.4023, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[412], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[412], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[413] = CreateDynamicObject(1753, 901.6710, -1461.7126, 2759.9807, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[413], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[414] = CreateDynamicObject(19786, 938.5164, -1460.6839, 2762.4023, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[414], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[414], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[415] = CreateDynamicObject(19786, 938.5164, -1469.3752, 2762.4023, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[415], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[415], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[416] = CreateDynamicObject(19786, 938.5164, -1473.5050, 2762.4023, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[416], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[416], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[417] = CreateDynamicObject(2002, 937.9525, -1471.5343, 2759.9567, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
    object_cityhallInterior[418] = CreateDynamicObject(2002, 901.6923, -1472.2650, 2759.9567, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
    object_cityhallInterior[419] = CreateDynamicObject(948, 901.5866, -1462.8619, 2759.9685, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
    object_cityhallInterior[420] = CreateDynamicObject(948, 901.5866, -1458.4813, 2759.9685, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
    object_cityhallInterior[421] = CreateDynamicObject(948, 937.9970, -1458.4813, 2759.9685, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
    object_cityhallInterior[422] = CreateDynamicObject(948, 937.9224, -1462.8619, 2759.9685, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
    object_cityhallInterior[423] = CreateDynamicObject(2010, 920.5430, -1457.4154, 2759.9716, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    SetDynamicObjectMaterial(object_cityhallInterior[423], 1, 6490, "tvstudio_law2", "tvstud03_LAw2", 0xFFFFFFFF);
    object_cityhallInterior[424] = CreateDynamicObject(2010, 918.2318, -1457.4154, 2759.9716, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    SetDynamicObjectMaterial(object_cityhallInterior[424], 1, 6490, "tvstudio_law2", "tvstud03_LAw2", 0xFFFFFFFF);
    object_cityhallInterior[425] = CreateDynamicObject(19174, 920.0172, -1457.1037, 2760.9187, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[425], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[425], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[426] = CreateDynamicObject(19174, 918.8164, -1457.0937, 2763.3608, 0.0000, -90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[426], 0, "y", 90, "Wingdings", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[426], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[427] = CreateDynamicObject(19174, 921.5076, -1457.1037, 2761.8898, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[427], 0, "__", 90, "Arial Black", 50, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[427], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[428] = CreateDynamicObject(19174, 919.6466, -1457.0937, 2761.8898, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[428], 0, "__", 90, "Arial Black", 50, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[428], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[429] = CreateDynamicObject(19464, 915.5947, -1475.9527, 2750.9528, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[429], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[430] = CreateDynamicObject(1491, 921.8579, -1457.0078, 2760.0092, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_cityhallInterior[430], 0, 18008, "intclothesa", "CJ_VICT_DOOR2", 0xFFFFFFFF);
    object_cityhallInterior[431] = CreateDynamicObject(19174, 920.1066, -1457.1335, 2761.4895, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[431], 0, "Herren", 90, "Arial", 15, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[431], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[432] = CreateDynamicObject(19174, 920.4569, -1457.1135, 2762.3503, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[432], 0, "WC", 90, "Arial Black", 50, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[432], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[433] = CreateDynamicObject(1491, 915.2772, -1457.0078, 2760.0092, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_cityhallInterior[433], 0, 2878, "cj_vic", "CJ_VICT_DOOR", 0xFFFFFFFF);
    object_cityhallInterior[434] = CreateDynamicObject(19464, 909.6546, -1475.9527, 2750.9528, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[434], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[435] = CreateDynamicObject(19464, 919.3026, -1456.9730, 2760.4577, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[435], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_cityhallInterior[436] = CreateDynamicObject(19464, 924.8046, -1475.9527, 2750.9528, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[436], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[437] = CreateDynamicObject(19464, 930.7351, -1475.9527, 2750.9528, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[437], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[438] = CreateDynamicObject(19464, 931.2553, -1475.6628, 2750.9528, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[438], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[439] = CreateDynamicObject(19464, 909.0150, -1475.6628, 2750.9528, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[439], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[440] = CreateDynamicObject(19464, 906.1853, -1472.7926, 2750.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[440], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[441] = CreateDynamicObject(19464, 934.0755, -1472.7926, 2750.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[441], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[442] = CreateDynamicObject(19464, 902.6057, -1456.9630, 2750.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[442], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[443] = CreateDynamicObject(19464, 934.8853, -1464.3923, 2750.9729, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[443], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[444] = CreateDynamicObject(19464, 934.8853, -1458.4527, 2750.9729, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[444], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[445] = CreateDynamicObject(19464, 904.7053, -1458.9631, 2750.9729, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[445], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[446] = CreateDynamicObject(19464, 904.7053, -1469.7829, 2750.9729, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[446], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[447] = CreateDynamicObject(19464, 934.8853, -1470.3321, 2750.9729, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[447], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[448] = CreateDynamicObject(19464, 910.9254, -1456.9630, 2750.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[448], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[449] = CreateDynamicObject(19464, 936.8955, -1456.9630, 2750.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[449], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[450] = CreateDynamicObject(19464, 930.4655, -1456.9630, 2750.9729, 0.0000, 0.0000, 89.8999, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[450], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[451] = CreateDynamicObject(19464, 901.8554, -1461.8431, 2750.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[451], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[452] = CreateDynamicObject(19464, 901.8554, -1466.9239, 2750.9729, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[452], 0, 5042, "bombshop_las", "greymetal", 0xFFFFFFFF);
    object_cityhallInterior[453] = CreateDynamicObject(19089, 936.7622, -1476.0279, 2765.0139, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[453], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[454] = CreateDynamicObject(19089, 905.3505, -1476.0279, 2765.1140, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[454], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[455] = CreateDynamicObject(19464, 911.6925, -1448.0040, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[455], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[456] = CreateDynamicObject(19089, 934.6113, -1476.0279, 2765.1140, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[456], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[457] = CreateDynamicObject(19089, 932.5114, -1476.0279, 2765.1140, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[457], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[458] = CreateDynamicObject(19089, 935.6959, -1476.0279, 2764.8884, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[458], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[459] = CreateDynamicObject(19089, 907.6110, -1476.0279, 2765.1140, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[459], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[460] = CreateDynamicObject(19089, 903.2706, -1476.0279, 2765.1140, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[460], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[461] = CreateDynamicObject(19089, 933.5557, -1476.0279, 2764.8884, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[461], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[462] = CreateDynamicObject(18981, 918.2313, -1463.8270, 2765.3820, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_cityhallInterior[462], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[463] = CreateDynamicObject(19464, 911.6925, -1453.9134, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[463], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[464] = CreateDynamicObject(18763, 911.5178, -1450.7408, 2758.4553, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[464], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[465] = CreateDynamicObject(18763, 911.5178, -1454.4918, 2758.4553, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[465], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[466] = CreateDynamicObject(2515, 912.4298, -1451.4028, 2761.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BS_SINK
    SetDynamicObjectMaterial(object_cityhallInterior[466], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[466], 1, 11301, "carshow_sfse", "ws_rollerdoor_silver", 0xFFFFFFFF);
    object_cityhallInterior[467] = CreateDynamicObject(2515, 912.4298, -1450.0821, 2761.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BS_SINK
    SetDynamicObjectMaterial(object_cityhallInterior[467], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[467], 1, 11301, "carshow_sfse", "ws_rollerdoor_silver", 0xFFFFFFFF);
    object_cityhallInterior[468] = CreateDynamicObject(2515, 912.4298, -1453.8331, 2761.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BS_SINK
    SetDynamicObjectMaterial(object_cityhallInterior[468], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[468], 1, 11301, "carshow_sfse", "ws_rollerdoor_silver", 0xFFFFFFFF);
    object_cityhallInterior[469] = CreateDynamicObject(2515, 912.4298, -1455.2136, 2761.0720, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BS_SINK
    SetDynamicObjectMaterial(object_cityhallInterior[469], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[469], 1, 11301, "carshow_sfse", "ws_rollerdoor_silver", 0xFFFFFFFF);
    object_cityhallInterior[470] = CreateDynamicObject(19786, 926.8073, -1450.6240, 2762.2639, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[470], 0, 10765, "airportgnd_sfse", "white", 0xFF5E7072);
    SetDynamicObjectMaterial(object_cityhallInterior[470], 1, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    object_cityhallInterior[471] = CreateDynamicObject(19786, 911.7078, -1454.4040, 2762.2639, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[471], 0, 10765, "airportgnd_sfse", "white", 0xFF5E7072);
    SetDynamicObjectMaterial(object_cityhallInterior[471], 1, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    object_cityhallInterior[472] = CreateDynamicObject(19089, 906.5056, -1476.0279, 2764.8884, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[472], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[473] = CreateDynamicObject(19089, 904.2954, -1476.0279, 2764.8884, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[473], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[474] = CreateDynamicObject(19786, 911.7078, -1450.7137, 2762.2639, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[474], 0, 10765, "airportgnd_sfse", "white", 0xFF5E7072);
    SetDynamicObjectMaterial(object_cityhallInterior[474], 1, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    object_cityhallInterior[475] = CreateDynamicObject(19786, 926.8577, -1454.5439, 2762.2639, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[475], 0, 10765, "airportgnd_sfse", "white", 0xFF5E7072);
    SetDynamicObjectMaterial(object_cityhallInterior[475], 1, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    object_cityhallInterior[476] = CreateDynamicObject(2741, 911.9041, -1452.5372, 2761.9111, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SOAP_DISP
    object_cityhallInterior[477] = CreateDynamicObject(11706, 912.6079, -1452.6064, 2759.8071, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
    object_cityhallInterior[478] = CreateDynamicObject(11707, 911.9008, -1448.4228, 2760.9423, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TowelRack1
    object_cityhallInterior[479] = CreateDynamicObject(11707, 913.8812, -1456.6722, 2760.9423, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TowelRack1
    object_cityhallInterior[480] = CreateDynamicObject(19464, 911.5319, -1456.8735, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[480], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[481] = CreateDynamicObject(19464, 917.4118, -1456.8935, 2765.9201, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[481], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[482] = CreateDynamicObject(19464, 923.3214, -1456.8935, 2765.9201, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[482], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[483] = CreateDynamicObject(19464, 919.2819, -1456.8735, 2762.5297, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[483], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[484] = CreateDynamicObject(19387, 922.6309, -1456.8415, 2761.6650, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_cityhallInterior[484], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[485] = CreateDynamicObject(19387, 916.0405, -1456.8415, 2761.6650, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_cityhallInterior[485], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[486] = CreateDynamicObject(19464, 919.2819, -1454.2237, 2762.5297, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[486], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[487] = CreateDynamicObject(19464, 919.2819, -1449.1544, 2762.5297, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[487], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[488] = CreateDynamicObject(2602, 918.8112, -1454.3535, 2760.4091, 0.0000, 0.0000, -92.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Police_cell_Toilet
    object_cityhallInterior[489] = CreateDynamicObject(2602, 918.7774, -1452.1710, 2760.4091, 0.0000, 0.0000, -92.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Police_cell_Toilet
    object_cityhallInterior[490] = CreateDynamicObject(2602, 918.7683, -1450.1290, 2760.4091, 0.0000, 0.0000, -92.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Police_cell_Toilet
    object_cityhallInterior[491] = CreateDynamicObject(2528, 917.0606, -1445.8050, 2760.0144, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET3
    object_cityhallInterior[492] = CreateDynamicObject(19464, 915.8820, -1445.1855, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[492], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[493] = CreateDynamicObject(19464, 912.8524, -1444.4643, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[493], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[494] = CreateDynamicObject(19464, 915.5230, -1444.4941, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[494], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[495] = CreateDynamicObject(1491, 916.2495, -1447.5289, 2759.9321, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    object_cityhallInterior[496] = CreateDynamicObject(1491, 913.3394, -1447.5289, 2759.9321, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    object_cityhallInterior[497] = CreateDynamicObject(19464, 920.3118, -1447.4841, 2762.5297, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[497], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[498] = CreateDynamicObject(19464, 910.8120, -1447.4841, 2762.5297, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[498], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[499] = CreateDynamicObject(19464, 915.2119, -1447.4741, 2765.3906, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[499], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[500] = CreateDynamicObject(19464, 918.5029, -1444.4145, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[500], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[501] = CreateDynamicObject(19430, 915.5341, -1447.5362, 2760.7014, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[501], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[502] = CreateDynamicObject(2528, 914.2509, -1445.7755, 2760.0144, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET3
    object_cityhallInterior[503] = CreateDynamicObject(18075, 915.5850, -1450.0450, 2764.8454, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_cityhallInterior[504] = CreateDynamicObject(16779, 915.4411, -1452.3680, 2764.8708, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light02
    object_cityhallInterior[505] = CreateDynamicObject(19814, 911.8272, -1452.5699, 2761.1025, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[506] = CreateDynamicObject(19814, 911.8272, -1452.5699, 2761.2126, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[507] = CreateDynamicObject(19814, 911.8272, -1452.5699, 2760.9824, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[508] = CreateDynamicObject(19464, 926.8728, -1453.9134, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[508], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[509] = CreateDynamicObject(19464, 926.7316, -1456.8741, 2762.5297, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[509], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[510] = CreateDynamicObject(11707, 924.6409, -1456.6822, 2760.9423, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TowelRack1
    object_cityhallInterior[511] = CreateDynamicObject(18763, 927.2877, -1454.4918, 2758.4553, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[511], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[512] = CreateDynamicObject(18763, 927.2877, -1450.5815, 2758.4553, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[512], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[513] = CreateDynamicObject(19464, 926.8828, -1448.0235, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[513], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[514] = CreateDynamicObject(2515, 926.2197, -1455.2136, 2761.0720, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BS_SINK
    SetDynamicObjectMaterial(object_cityhallInterior[514], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[514], 1, 11301, "carshow_sfse", "ws_rollerdoor_silver", 0xFFFFFFFF);
    object_cityhallInterior[515] = CreateDynamicObject(2515, 926.2197, -1453.7335, 2761.0720, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BS_SINK
    SetDynamicObjectMaterial(object_cityhallInterior[515], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[515], 1, 11301, "carshow_sfse", "ws_rollerdoor_silver", 0xFFFFFFFF);
    object_cityhallInterior[516] = CreateDynamicObject(2515, 926.2197, -1451.2635, 2761.0720, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BS_SINK
    SetDynamicObjectMaterial(object_cityhallInterior[516], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[516], 1, 11301, "carshow_sfse", "ws_rollerdoor_silver", 0xFFFFFFFF);
    object_cityhallInterior[517] = CreateDynamicObject(2515, 926.2197, -1449.8236, 2761.0720, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BS_SINK
    SetDynamicObjectMaterial(object_cityhallInterior[517], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[517], 1, 11301, "carshow_sfse", "ws_rollerdoor_silver", 0xFFFFFFFF);
    object_cityhallInterior[518] = CreateDynamicObject(11706, 926.1981, -1452.5063, 2759.8071, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
    object_cityhallInterior[519] = CreateDynamicObject(2741, 926.6439, -1452.5472, 2761.9111, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SOAP_DISP
    object_cityhallInterior[520] = CreateDynamicObject(19174, 929.8189, -1457.1361, 2763.1921, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[520], 0, "E.G.", 90, "Arial Black", 20, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[520], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[521] = CreateDynamicObject(11707, 926.6912, -1448.4228, 2760.9423, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TowelRack1
    object_cityhallInterior[522] = CreateDynamicObject(19814, 926.7271, -1452.5400, 2760.9824, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[523] = CreateDynamicObject(19814, 926.7271, -1452.5400, 2761.1225, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[524] = CreateDynamicObject(19814, 926.7271, -1452.5400, 2761.2626, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[525] = CreateDynamicObject(2528, 919.8004, -1449.7551, 2760.0144, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET3
    object_cityhallInterior[526] = CreateDynamicObject(2528, 919.8004, -1452.9956, 2760.0144, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET3
    object_cityhallInterior[527] = CreateDynamicObject(2528, 919.8004, -1455.6451, 2760.0144, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET3
    object_cityhallInterior[528] = CreateDynamicObject(19464, 925.4016, -1447.4841, 2762.5297, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[528], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[529] = CreateDynamicObject(1753, 931.0811, -1470.3409, 2759.9807, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[529], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[530] = CreateDynamicObject(1491, 921.5900, -1450.5792, 2759.9321, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    object_cityhallInterior[531] = CreateDynamicObject(1491, 921.5869, -1453.6593, 2759.9321, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    object_cityhallInterior[532] = CreateDynamicObject(1491, 921.5869, -1456.7395, 2759.9321, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    object_cityhallInterior[533] = CreateDynamicObject(19430, 921.5739, -1454.4365, 2760.6806, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[533], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[534] = CreateDynamicObject(19430, 920.7645, -1454.4365, 2760.6806, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[534], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[535] = CreateDynamicObject(19430, 919.9735, -1451.3664, 2760.7014, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[535], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[536] = CreateDynamicObject(19430, 920.7636, -1451.3763, 2760.7014, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[536], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[537] = CreateDynamicObject(19430, 921.5739, -1448.2961, 2760.6806, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[537], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[538] = CreateDynamicObject(19430, 920.1641, -1454.4265, 2760.6806, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[538], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[539] = CreateDynamicObject(19430, 921.5739, -1451.3564, 2760.6806, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[539], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[540] = CreateDynamicObject(19430, 920.7636, -1448.4566, 2760.7014, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[540], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[541] = CreateDynamicObject(19430, 920.1535, -1448.4565, 2760.7014, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[541], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[542] = CreateDynamicObject(19464, 921.5219, -1449.1544, 2765.3295, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[542], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[543] = CreateDynamicObject(19464, 921.5020, -1454.2047, 2765.3295, 90.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[543], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[544] = CreateDynamicObject(18075, 926.6956, -1450.3454, 2764.8454, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_cityhallInterior[545] = CreateDynamicObject(16779, 923.8812, -1452.3680, 2764.8708, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light02
    object_cityhallInterior[546] = CreateDynamicObject(19175, 924.2739, -1447.6396, 2762.4118, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterial(object_cityhallInterior[546], 0, 2266, "picture_frame", "CJ_PAINTING18", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[546], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[547] = CreateDynamicObject(19089, 930.4857, -1451.8974, 2759.9978, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[547], 0, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    object_cityhallInterior[548] = CreateDynamicObject(19089, 930.4857, -1459.2679, 2759.9978, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[548], 0, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    object_cityhallInterior[549] = CreateDynamicObject(1753, 931.1015, -1474.7010, 2759.9807, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[549], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[550] = CreateDynamicObject(1753, 909.3314, -1472.6711, 2759.9807, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[550], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[551] = CreateDynamicObject(1753, 909.3314, -1468.1905, 2759.9807, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_COUCH_1
    SetDynamicObjectMaterial(object_cityhallInterior[551], 0, 1726, "mrk_couches2", "kb_sofa5_256", 0xFFFFFFFF);
    object_cityhallInterior[552] = CreateDynamicObject(19089, 909.8756, -1451.8974, 2759.9978, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[552], 0, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    object_cityhallInterior[553] = CreateDynamicObject(19089, 909.8756, -1459.2375, 2759.9978, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_cityhallInterior[553], 0, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    object_cityhallInterior[554] = CreateDynamicObject(19174, 901.1901, -1465.8480, 2762.9099, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[554], 0, "___________", 90, "Arial", 24, 1, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[554], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[555] = CreateDynamicObject(19174, 901.1901, -1465.8480, 2763.1000, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[555], 0, "___________", 90, "Arial", 24, 1, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[555], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[556] = CreateDynamicObject(19174, 938.4401, -1465.8480, 2763.1000, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[556], 0, "___________", 90, "Arial", 24, 1, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[556], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[557] = CreateDynamicObject(19174, 938.4398, -1465.8580, 2762.9018, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[557], 0, "Personalverwaltung", 90, "Arial Black", 14, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[557], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[558] = CreateDynamicObject(19174, 938.4503, -1465.8480, 2762.9299, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[558], 0, "___________", 90, "Arial", 24, 1, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[558], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[559] = CreateDynamicObject(1491, 938.5797, -1465.1302, 2760.0092, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_cityhallInterior[559], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    object_cityhallInterior[560] = CreateDynamicObject(1536, 901.1024, -1465.1301, 2759.9863, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT15
    SetDynamicObjectMaterial(object_cityhallInterior[560], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    object_cityhallInterior[561] = CreateDynamicObject(19814, 908.2202, -1475.8642, 2760.3498, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[562] = CreateDynamicObject(19814, 908.4503, -1475.8642, 2760.3498, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[563] = CreateDynamicObject(19814, 902.2800, -1475.8642, 2760.3498, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[564] = CreateDynamicObject(19814, 902.5399, -1475.8642, 2760.3498, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[565] = CreateDynamicObject(19814, 901.1403, -1462.3841, 2760.3098, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[566] = CreateDynamicObject(19814, 901.1604, -1458.9731, 2760.3098, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[567] = CreateDynamicObject(19814, 901.1903, -1468.3935, 2760.3098, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[568] = CreateDynamicObject(19814, 938.4500, -1459.0124, 2760.3098, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[569] = CreateDynamicObject(19814, 938.4500, -1462.3730, 2760.3098, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[570] = CreateDynamicObject(19814, 938.4500, -1471.0437, 2760.3098, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[571] = CreateDynamicObject(19814, 938.4500, -1472.0240, 2760.3098, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[572] = CreateDynamicObject(19814, 936.9995, -1475.8741, 2760.3098, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[573] = CreateDynamicObject(19814, 937.2398, -1475.8741, 2760.3098, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[574] = CreateDynamicObject(2961, 904.8776, -1457.0854, 2761.3278, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire_break
    object_cityhallInterior[575] = CreateDynamicObject(2961, 934.5474, -1457.0854, 2761.3278, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire_break
    object_cityhallInterior[576] = CreateDynamicObject(2962, 934.5465, -1457.0898, 2761.3232, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire_break_glass
    object_cityhallInterior[577] = CreateDynamicObject(2962, 904.8767, -1457.0898, 2761.3232, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire_break_glass
    object_cityhallInterior[578] = CreateDynamicObject(19826, 917.0244, -1456.6499, 2761.3168, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LightSwitch1
    SetDynamicObjectMaterial(object_cityhallInterior[578], 0, 14706, "labig2int2", "lightswitch01_int", 0xFFFFFFFF);
    object_cityhallInterior[579] = CreateDynamicObject(19826, 917.1646, -1456.6499, 2761.3168, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LightSwitch1
    SetDynamicObjectMaterial(object_cityhallInterior[579], 0, 14706, "labig2int2", "lightswitch01_int", 0xFFFFFFFF);
    object_cityhallInterior[580] = CreateDynamicObject(19826, 923.6148, -1456.6499, 2761.3168, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LightSwitch1
    SetDynamicObjectMaterial(object_cityhallInterior[580], 0, 14706, "labig2int2", "lightswitch01_int", 0xFFFFFFFF);
    object_cityhallInterior[581] = CreateDynamicObject(19826, 923.8048, -1456.6499, 2761.3168, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LightSwitch1
    SetDynamicObjectMaterial(object_cityhallInterior[581], 0, 14706, "labig2int2", "lightswitch01_int", 0xFFFFFFFF);
    object_cityhallInterior[582] = CreateDynamicObject(19814, 913.2304, -1475.8453, 2753.5849, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[583] = CreateDynamicObject(19814, 916.9713, -1475.8453, 2753.5849, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[584] = CreateDynamicObject(19814, 923.0114, -1475.8453, 2753.5849, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[585] = CreateDynamicObject(19814, 926.5117, -1475.8453, 2753.5849, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[586] = CreateDynamicObject(19814, 918.1419, -1462.6749, 2753.4748, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[587] = CreateDynamicObject(19814, 918.5722, -1462.6749, 2753.4748, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_cityhallInterior[588] = CreateDynamicObject(19786, 906.7141, -1472.8266, 2755.8620, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[588], 0, 14570, "traidaqua", "ab_tv", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[588], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[589] = CreateDynamicObject(19786, 932.9738, -1472.8266, 2755.8620, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_cityhallInterior[589], 0, 14570, "traidaqua", "ab_tv", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[589], 1, 14571, "chinese_furn", "ab_tv_noise", 0xFFFFFFFF);
    object_cityhallInterior[590] = CreateDynamicObject(19387, 938.6716, -1465.9105, 2761.6650, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_cityhallInterior[590], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[591] = CreateDynamicObject(19464, 938.6436, -1470.4040, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[591], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[592] = CreateDynamicObject(19464, 938.6436, -1461.3641, 2762.5297, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[592], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[593] = CreateDynamicObject(19464, 938.6337, -1466.0638, 2765.7199, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[593], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[594] = CreateDynamicObject(19430, 944.8953, -1468.0417, 2759.9421, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[594], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[595] = CreateDynamicObject(18762, 944.7965, -1465.6184, 2760.4494, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_cityhallInterior[595], 0, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
    object_cityhallInterior[596] = CreateDynamicObject(19430, 944.8953, -1463.2016, 2759.9421, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[596], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[597] = CreateDynamicObject(19430, 944.8953, -1465.6627, 2759.9421, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[597], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[598] = CreateDynamicObject(19430, 944.3754, -1466.4621, 2760.1323, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[598], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[599] = CreateDynamicObject(19430, 944.3754, -1464.9720, 2760.1323, 90.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[599], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[600] = CreateDynamicObject(1714, 946.6273, -1466.6816, 2759.9899, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_cityhallInterior[601] = CreateDynamicObject(19175, 944.2650, -1465.4127, 2759.8366, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_cityhallInterior[601], 0, "Schalter l", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[601], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[602] = CreateDynamicObject(19175, 944.2650, -1467.7425, 2759.8366, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_cityhallInterior[602], 0, "Schalter ll", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_cityhallInterior[602], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[603] = CreateDynamicObject(1714, 946.6273, -1464.5013, 2759.9899, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_cityhallInterior[604] = CreateDynamicObject(19808, 945.0086, -1464.4233, 2760.9680, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_cityhallInterior[605] = CreateDynamicObject(19808, 945.0086, -1466.7937, 2760.9680, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_cityhallInterior[606] = CreateDynamicObject(2601, 944.5239, -1464.4315, 2760.9790, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_cityhallInterior[606], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[607] = CreateDynamicObject(2601, 944.6040, -1466.7921, 2760.9790, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_cityhallInterior[607], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[608] = CreateDynamicObject(2263, 945.0792, -1464.4593, 2761.1420, -16.7000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_cityhallInterior[608], 0, 3881, "apsecurity_sfxrf", "WIN_DESKTOP", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[608], 1, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[609] = CreateDynamicObject(2601, 944.6040, -1464.4322, 2760.9189, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_cityhallInterior[609], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[610] = CreateDynamicObject(2263, 944.1259, -1466.7998, 2760.9052, 16.4999, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_cityhallInterior[610], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[610], 1, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[611] = CreateDynamicObject(2263, 944.1373, -1464.4189, 2760.8666, 16.4999, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_cityhallInterior[611], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[611], 1, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[612] = CreateDynamicObject(2263, 945.0676, -1466.8298, 2761.1801, -16.7000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_cityhallInterior[612], 0, 3881, "apsecurity_sfxrf", "WIN_DESKTOP", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[612], 1, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[613] = CreateDynamicObject(2601, 944.6040, -1466.7922, 2760.9189, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_cityhallInterior[613], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_cityhallInterior[614] = CreateDynamicObject(19513, 944.8659, -1463.8675, 2760.9340, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //whitephone
    object_cityhallInterior[615] = CreateDynamicObject(19513, 944.8659, -1466.2380, 2760.9340, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //whitephone
    object_cityhallInterior[616] = CreateDynamicObject(1811, 939.2077, -1463.7757, 2760.5717, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[617] = CreateDynamicObject(1811, 939.2077, -1462.7456, 2760.5717, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[618] = CreateDynamicObject(1811, 939.2077, -1461.7054, 2760.5717, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[619] = CreateDynamicObject(1811, 939.2077, -1467.8857, 2760.5717, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[620] = CreateDynamicObject(1811, 939.2077, -1468.9260, 2760.5717, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[621] = CreateDynamicObject(1811, 939.2077, -1469.9460, 2760.5717, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[622] = CreateDynamicObject(19175, 938.7739, -1462.8496, 2762.4118, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterial(object_cityhallInterior[622], 0, 2266, "picture_frame", "CJ_PAINTING16", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[622], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[623] = CreateDynamicObject(19175, 938.7739, -1468.7794, 2762.4118, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterial(object_cityhallInterior[623], 0, 2266, "picture_frame", "CJ_PAINTING16", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[623], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[624] = CreateDynamicObject(19464, 941.5139, -1471.3243, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[624], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[625] = CreateDynamicObject(19464, 947.4340, -1471.3243, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[625], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[626] = CreateDynamicObject(19464, 947.4340, -1460.3436, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[626], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[627] = CreateDynamicObject(19464, 941.7039, -1460.3232, 2762.5297, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[627], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[628] = CreateDynamicObject(19464, 949.9140, -1463.3531, 2762.5297, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[628], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[629] = CreateDynamicObject(19464, 949.9140, -1469.2729, 2762.5297, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[629], 0, 15041, "bigsfsave", "wall6", 0xFFFFFFFF);
    object_cityhallInterior[630] = CreateDynamicObject(1811, 940.7675, -1460.8951, 2760.5717, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[631] = CreateDynamicObject(1811, 942.0974, -1460.8951, 2760.5717, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[632] = CreateDynamicObject(1811, 943.3975, -1460.8951, 2760.5717, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[633] = CreateDynamicObject(1811, 943.3975, -1470.7954, 2760.5717, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[634] = CreateDynamicObject(1811, 942.0269, -1470.7954, 2760.5717, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[635] = CreateDynamicObject(1811, 940.6666, -1470.7954, 2760.5717, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_cityhallInterior[636] = CreateDynamicObject(2010, 939.3461, -1470.7407, 2759.9838, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    SetDynamicObjectMaterial(object_cityhallInterior[636], 1, 18012, "genintgeneric", "planterbox128", 0xFFFFFFFF);
    object_cityhallInterior[637] = CreateDynamicObject(2010, 939.3461, -1460.8907, 2759.9838, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    SetDynamicObjectMaterial(object_cityhallInterior[637], 1, 18012, "genintgeneric", "planterbox128", 0xFFFFFFFF);
    object_cityhallInterior[638] = CreateDynamicObject(2161, 944.8826, -1460.4896, 2760.8225, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_cityhallInterior[639] = CreateDynamicObject(2161, 945.2528, -1471.2099, 2760.8225, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_cityhallInterior[640] = CreateDynamicObject(2162, 949.7091, -1469.1296, 2760.9421, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_cityhallInterior[641] = CreateDynamicObject(2162, 949.7091, -1461.5295, 2760.9421, 0.0000, 0.0000, 270.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_cityhallInterior[642] = CreateDynamicObject(2164, 949.7589, -1464.0985, 2759.9963, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    object_cityhallInterior[643] = CreateDynamicObject(2167, 946.9199, -1460.2558, 2759.9951, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
    object_cityhallInterior[644] = CreateDynamicObject(2167, 948.2697, -1460.2558, 2759.9951, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
    object_cityhallInterior[645] = CreateDynamicObject(2167, 948.2697, -1471.3559, 2759.9951, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
    object_cityhallInterior[646] = CreateDynamicObject(2167, 946.9196, -1471.3559, 2759.9951, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
    object_cityhallInterior[647] = CreateDynamicObject(2186, 949.3242, -1466.6075, 2759.9931, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PHOTOCOPIER_1
    object_cityhallInterior[648] = CreateDynamicObject(19464, 941.5139, -1471.3044, 2767.2912, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[648], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[649] = CreateDynamicObject(19464, 946.9442, -1471.3044, 2767.2912, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[649], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[650] = CreateDynamicObject(19464, 946.9442, -1460.3536, 2767.2912, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[650], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[651] = CreateDynamicObject(19464, 941.7042, -1460.3536, 2767.2912, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[651], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[652] = CreateDynamicObject(19464, 938.6845, -1463.3634, 2767.2912, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[652], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[653] = CreateDynamicObject(19464, 938.7045, -1468.3736, 2767.2912, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[653], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[654] = CreateDynamicObject(19464, 949.8944, -1468.3736, 2767.2912, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[654], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[655] = CreateDynamicObject(19464, 949.8944, -1462.4427, 2767.2912, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[655], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[656] = CreateDynamicObject(19464, 949.8944, -1462.4427, 2757.5200, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[656], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[657] = CreateDynamicObject(19464, 949.8944, -1468.3530, 2757.5200, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[657], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[658] = CreateDynamicObject(19464, 949.8944, -1471.3038, 2757.5200, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[658], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[659] = CreateDynamicObject(19464, 943.5642, -1471.3038, 2757.5200, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[659], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[660] = CreateDynamicObject(19464, 941.6843, -1471.3038, 2757.5200, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[660], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[661] = CreateDynamicObject(19464, 941.6843, -1460.3537, 2757.5200, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[661], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[662] = CreateDynamicObject(19464, 947.6240, -1460.3537, 2757.5200, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[662], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[663] = CreateDynamicObject(19464, 938.6441, -1462.1734, 2757.5200, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[663], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[664] = CreateDynamicObject(18075, 944.4329, -1465.8193, 2764.8713, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_cityhallInterior[665] = CreateDynamicObject(16780, 943.8864, -1467.9200, 2764.9145, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light03
    object_cityhallInterior[666] = CreateDynamicObject(16780, 943.8864, -1464.1998, 2764.9145, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_light03
    object_cityhallInterior[667] = CreateDynamicObject(3034, 946.9309, -1460.4698, 2762.8015, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bd_window
    SetDynamicObjectMaterial(object_cityhallInterior[667], 0, 9901, "ferry_building", "skylight_windows", 0xFFFFFFFF);
    object_cityhallInterior[668] = CreateDynamicObject(3034, 941.9708, -1460.4698, 2762.8015, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bd_window
    SetDynamicObjectMaterial(object_cityhallInterior[668], 0, 9901, "ferry_building", "skylight_windows", 0xFFFFFFFF);
    object_cityhallInterior[669] = CreateDynamicObject(3034, 946.9309, -1471.2000, 2762.8015, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bd_window
    SetDynamicObjectMaterial(object_cityhallInterior[669], 0, 9901, "ferry_building", "skylight_windows", 0xFFFFFFFF);
    object_cityhallInterior[670] = CreateDynamicObject(3034, 941.9207, -1471.1904, 2762.8015, 0.0000, 0.0000, 180.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bd_window
    SetDynamicObjectMaterial(object_cityhallInterior[670], 0, 9901, "ferry_building", "skylight_windows", 0xFFFFFFFF);
    object_cityhallInterior[671] = CreateDynamicObject(19450, 909.2650, -1461.9305, 2764.9331, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[671], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[672] = CreateDynamicObject(19825, 949.6734, -1466.1933, 2762.9707, 0.0000, 0.0000, -90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
    SetDynamicObjectMaterial(object_cityhallInterior[672], 0, 1654, "dynamite", "clock64", 0xFFFFFFFF);
    object_cityhallInterior[673] = CreateDynamicObject(19450, 918.8350, -1461.9305, 2764.9331, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[673], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[674] = CreateDynamicObject(19450, 928.3848, -1461.9305, 2764.9331, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[674], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[675] = CreateDynamicObject(19450, 930.5847, -1461.9305, 2764.9331, 0.0000, 90.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[675], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[676] = CreateDynamicObject(19450, 934.5548, -1465.0008, 2764.9331, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[676], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[677] = CreateDynamicObject(19450, 934.5551, -1471.1998, 2764.9331, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[677], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[678] = CreateDynamicObject(19450, 905.3654, -1471.1998, 2764.9331, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[678], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[679] = CreateDynamicObject(19450, 905.3654, -1464.9895, 2764.9331, 0.0000, 90.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[679], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[680] = CreateDynamicObject(19450, 933.1546, -1471.1811, 2766.5825, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[680], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[681] = CreateDynamicObject(19450, 936.0051, -1471.1811, 2766.5825, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[681], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[682] = CreateDynamicObject(19450, 936.0150, -1465.2004, 2766.5925, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[682], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[683] = CreateDynamicObject(19450, 933.1547, -1468.3299, 2766.5925, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[683], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[684] = CreateDynamicObject(19450, 931.2150, -1460.4696, 2766.5925, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[684], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[685] = CreateDynamicObject(19450, 921.5955, -1460.4696, 2766.5925, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[685], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[686] = CreateDynamicObject(19450, 911.9658, -1460.4696, 2766.5925, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[686], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[687] = CreateDynamicObject(19450, 908.7152, -1460.4593, 2766.5825, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[687], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[688] = CreateDynamicObject(19450, 928.4057, -1463.4294, 2766.5825, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[688], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[689] = CreateDynamicObject(19450, 918.7656, -1463.4294, 2766.5825, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[689], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[690] = CreateDynamicObject(19450, 911.6956, -1463.4294, 2766.5625, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[690], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[691] = CreateDynamicObject(19450, 903.9754, -1465.1798, 2766.5725, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[691], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[692] = CreateDynamicObject(19450, 903.9754, -1471.2004, 2766.5725, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[692], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[693] = CreateDynamicObject(19450, 906.8054, -1468.1510, 2766.5725, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[693], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[694] = CreateDynamicObject(19450, 906.8054, -1471.1826, 2766.5727, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[694], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[695] = CreateDynamicObject(945, 911.4801, -1462.0312, 2772.0705, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[695], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[695], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[695], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[695], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[696] = CreateDynamicObject(945, 907.9799, -1462.0312, 2772.0705, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[696], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[696], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[696], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[696], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[697] = CreateDynamicObject(945, 915.2000, -1462.0312, 2772.0705, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[697], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[697], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[697], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[697], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[698] = CreateDynamicObject(945, 919.0300, -1462.0312, 2772.0705, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[698], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[698], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[698], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[698], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[699] = CreateDynamicObject(945, 923.3801, -1462.0312, 2772.0705, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[699], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[699], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[699], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[699], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[700] = CreateDynamicObject(945, 927.1604, -1462.0312, 2772.0705, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[700], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[700], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[700], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[700], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[701] = CreateDynamicObject(945, 931.3502, -1462.0312, 2772.0705, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[701], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[701], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[701], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[701], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[702] = CreateDynamicObject(945, 934.5601, -1464.2613, 2772.0705, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[702], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[702], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[702], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[702], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[703] = CreateDynamicObject(945, 934.5601, -1468.5815, 2772.0705, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[703], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[703], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[703], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[703], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[704] = CreateDynamicObject(945, 934.5601, -1473.1910, 2772.0705, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[704], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[704], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[704], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[704], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[705] = CreateDynamicObject(945, 905.3192, -1473.1910, 2772.0705, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[705], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[705], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[705], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[705], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[706] = CreateDynamicObject(945, 905.3192, -1464.6014, 2772.0705, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[706], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[706], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[706], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[706], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[707] = CreateDynamicObject(945, 905.3192, -1468.9615, 2772.0705, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WS_CF_LAMPS
    SetDynamicObjectMaterial(object_cityhallInterior[707], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[707], 1, 12850, "cunte_block1", "lightwall256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[707], 2, 8482, "csrspalace02", "casinolightsyel_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cityhallInterior[707], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[708] = CreateDynamicObject(19450, 901.1259, -1471.0997, 2766.5539, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[708], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[709] = CreateDynamicObject(19450, 901.1259, -1461.4602, 2766.5539, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[709], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[710] = CreateDynamicObject(19450, 901.1259, -1461.4602, 2758.2934, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[710], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[711] = CreateDynamicObject(19450, 901.1259, -1471.1606, 2758.2934, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[711], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[712] = CreateDynamicObject(19450, 905.7857, -1457.0102, 2766.5637, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[712], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[713] = CreateDynamicObject(19450, 915.4157, -1457.0102, 2766.5637, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[713], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[714] = CreateDynamicObject(19450, 925.0053, -1457.0102, 2766.5637, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[714], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[715] = CreateDynamicObject(19450, 934.6154, -1457.0102, 2766.5637, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[715], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[716] = CreateDynamicObject(19450, 938.5158, -1461.8902, 2766.5637, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[716], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[717] = CreateDynamicObject(19450, 938.5158, -1471.4997, 2766.5637, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[717], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[718] = CreateDynamicObject(19450, 938.5158, -1471.4298, 2758.2827, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[718], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[719] = CreateDynamicObject(19450, 938.5158, -1460.3293, 2758.2827, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[719], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[720] = CreateDynamicObject(19450, 940.1759, -1457.0283, 2760.3825, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[720], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[721] = CreateDynamicObject(19450, 899.4359, -1457.0283, 2760.3825, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[721], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[722] = CreateDynamicObject(19450, 899.4655, -1475.8977, 2760.3825, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[722], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[723] = CreateDynamicObject(19450, 940.1760, -1475.8878, 2760.3825, 90.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_cityhallInterior[723], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_cityhallInterior[724] = CreateDynamicObject(11721, 936.6129, -1457.0749, 2760.5214, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Radiator1
    SetDynamicObjectMaterial(object_cityhallInterior[724], 1, 14704, "lahss2_2int2", "HS_radiator2", 0xFFFFFFFF);
    object_cityhallInterior[725] = CreateDynamicObject(11721, 902.9525, -1457.0749, 2760.5214, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Radiator1
    SetDynamicObjectMaterial(object_cityhallInterior[725], 1, 14704, "lahss2_2int2", "HS_radiator2", 0xFFFFFFFF);
    object_cityhallInterior[726] = CreateDynamicObject(19174, 901.1901, -1465.8580, 2762.9018, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[726], 0, "Besprechungsraum", 90, "Arial Black", 14, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[726], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[727] = CreateDynamicObject(19174, 901.1901, -1465.8580, 2762.7216, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_cityhallInterior[727], 0, "nur für Befugte!", 90, "Arial Black", 14, 0, 0xFF000000, 0x0, 1);
    SetDynamicObjectMaterial(object_cityhallInterior[727], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_cityhallInterior[728] = CreateDynamicObject(19464, 938.6441, -1469.6035, 2757.5200, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[728], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_cityhallInterior[729] = CreateDynamicObject(19464, 938.5836, -1464.4644, 2765.7199, 0.0000, 0.0000, 0.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_cityhallInterior[729], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_cityhallInterior[730] = CreateDynamicObject(19430, 920.7636, -1448.4466, 2763.5612, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[730], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);
    object_cityhallInterior[731] = CreateDynamicObject(19430, 920.1735, -1448.4266, 2763.5612, 0.0000, 0.0000, 90.0000, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_cityhallInterior[731], 0, 17049, "cuntwf", "sw_walltile", 0xFFFFFFFF);

    // Windows Fix (Blinds)
    //object_cityhallInterior[736] = CreateDynamicObject(10184, 934.944946, -1476.197998, 2761.81665, 0.000000, 0.000000, -90.0, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    //object_cityhallInterior[737] = CreateDynamicObject(10184, 909.404236, -1476.197998, 2761.81665, 0.000000, 0.000000, -90.0, VW_CITYHALLINTERIOR, MAPS_CITYHALLINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
