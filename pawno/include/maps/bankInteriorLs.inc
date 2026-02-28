#include <YSI\y_hooks>

// Global interior define
#define MAPS_BANKINTERIORLS_INTERIOR        0
#define MAPS_BANKINTERIORLS2_INTERIOR       1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Bank Interior LS Points
#define BANKINTERIORLS2_EXIT_POINT      2144.2371, 1607.9679, 993.6882
#define BANKINTERIORLS2_EXIT_FACING     0.0
#define BANKINTERIORLS2_ENTER_POINT     1424.0088, -1003.9194, 1639.7843
#define BANKINTERIORLS2_ENTER_FACING    0.0
#define BANKINTERIORLS_TRANSFER_POINT   1683.024658, -1022.939270, 1340.750854
#define BANKINTERIORLS_CREDIT_POINT     1683.024658, -1022.939270, 1340.750854
#define BANKINTERIORLS_SERVICE_POINT    1683.024658, -1022.939270, 1340.750854    

// Map variables
new object_bankInteriorLs[200];
new HP_bankInteriorLs[6];
new Text3D:Label_HP_bankInteriorLs[6];
new HP_Tresor[6];
new Text3D:Label_bankInteriorLs[10];
new bool:Wertpap[4];
new bool:Tresor[4];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLS2_ENTER_POINT)) {
            if(g_iBankraubStatus == Bankraub_Aktiv) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Bank nicht betreten, da aktuell ein Bankraub läuft!");
            Streamer_UpdateEx(playerid, BANKINTERIORLS2_EXIT_POINT, VW_BANKINTERIORLS2, MAPS_BANKINTERIORLS2_INTERIOR, STREAMER_TYPE_OBJECT);
            SetPlayerVirtualWorld(playerid, VW_BANKINTERIORLS2);
            SetPlayerInterior(playerid, MAPS_BANKINTERIORLS2_INTERIOR);
            SetPlayerPos(playerid, BANKINTERIORLS2_EXIT_POINT);
            SetPlayerFacingAngle(playerid, BANKINTERIORLS2_EXIT_FACING);
            SetCameraBehindPlayer(playerid);

            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLS_EXIT_COORDS)) {
            if(g_iBankraubStatus == Bankraub_Aktiv) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Bank nicht verlassen! Die Türen sind abgeschlossen!");
            Streamer_UpdateEx(playerid, BANKINTERIORLS_ENTER_COORDS, VW_MAIN, MAPS_BANKEXTERIORLS_INTERIOR, STREAMER_TYPE_OBJECT);            
            SetPlayerVirtualWorld(playerid, VW_MAIN);
            SetPlayerInterior(playerid, MAPS_BANKEXTERIORLS_INTERIOR);
            SetPlayerPos(playerid, BANKINTERIORLS_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, BANKINTERIORLS_ENTER_FACING);
            SetCameraBehindPlayer(playerid);

            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {    
    // Pickups
    
    // 3DTextLabels

    // Objects
    object_bankInteriorLs[0] = CreateDynamicObject(18981, 1686.2314, -1027.9580, 1339.2508, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[0], 0, 16640, "a51", "ws_metalpanel1", 0x00000000);
    object_bankInteriorLs[1] = CreateDynamicObject(1569, 1674.7983, -1019.3010, 1339.7535, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    object_bankInteriorLs[2] = CreateDynamicObject(19464, 1665.9852, -1027.4615, 1341.6308, 0.0000, -40.7999, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[2], 0, 14581, "ab_mafiasuitea", "goldPillar", 0x00000000);
    object_bankInteriorLs[3] = CreateDynamicObject(18980, 1688.5649, -1022.9370, 1340.8552, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[3], 0, 16023, "des_trainstuff", "ws_stoneblock", 0x00000000);
    object_bankInteriorLs[4] = CreateDynamicObject(19464, 1666.2391, -1030.7545, 1341.5992, 0.0000, -40.7999, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[4], 0, 1355, "break_s_bins", "marble1", 0x00000000);
    object_bankInteriorLs[5] = CreateDynamicObject(19894, 1684.3697, -1024.3935, 1340.7939, 0.0000, 0.0000, 90.9999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP2
    object_bankInteriorLs[6] = CreateDynamicObject(19175, 1693.6966, -1044.4930, 1342.7270, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    object_bankInteriorLs[7] = CreateDynamicObject(18981, 1669.2380, -1062.9670, 1339.2508, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[7], 0, 16640, "a51", "ws_metalpanel1", 0x00000000);
    object_bankInteriorLs[8] = CreateDynamicObject(2166, 1690.5450, -1022.9625, 1339.7369, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_2
    object_bankInteriorLs[9] = CreateDynamicObject(1569, 1677.7906, -1019.2949, 1339.7535, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    object_bankInteriorLs[10] = CreateDynamicObject(18981, 1655.4962, -1018.8447, 1339.2508, 90.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[10], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[11] = CreateDynamicObject(2423, 1684.2490, -1026.1505, 1339.7397, 0.0000, 0.0000, -90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_CONTER_1b
    object_bankInteriorLs[12] = CreateDynamicObject(18981, 1661.2673, -1027.9580, 1339.2508, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[12], 0, 16640, "a51", "ws_metalpanel1", 0x00000000);
    object_bankInteriorLs[13] = CreateDynamicObject(18981, 1676.5826, -1018.8447, 1339.2508, 90.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[13], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[14] = CreateDynamicObject(19439, 1675.0493, -1033.7480, 1339.9875, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall079
    SetDynamicObjectMaterial(object_bankInteriorLs[14], 0, 2176, "casino_props", "marblebox", 0x00000000);
    object_bankInteriorLs[15] = CreateDynamicObject(2942, 1674.3127, -1033.3083, 1340.3857, 0.0000, 0.0000, -180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_bankInteriorLs[16] = CreateDynamicObject(19439, 1674.1584, -1033.7480, 1339.9875, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall079
    SetDynamicObjectMaterial(object_bankInteriorLs[16], 0, 2176, "casino_props", "marblebox", 0x00000000);
    object_bankInteriorLs[17] = CreateDynamicObject(19893, 1690.6407, -1022.9370, 1340.5240, 0.0000, 0.0000, 174.5997, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_bankInteriorLs[18] = CreateDynamicObject(19604, 1665.8454, -1025.2740, 1342.0603, 49.2998, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    SetDynamicObjectMaterial(object_bankInteriorLs[18], 0, 16434, "des_stwnsigns1", "des_banksign", 0x00000000);
    object_bankInteriorLs[19] = CreateDynamicObject(18075, 1683.7335, -1029.6385, 1345.1435, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bankInteriorLs[20] = CreateDynamicObject(1234, 1688.5909, -1024.0229, 1343.5224, 0.0000, 90.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[20], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[20], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[21] = CreateDynamicObject(18981, 1682.0843, -1052.9602, 1327.2054, 90.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[21], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[22] = CreateDynamicObject(18766, 1693.7027, -1032.3492, 1341.8160, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[22], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[23] = CreateDynamicObject(2166, 1695.9787, -1022.9625, 1339.7369, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_2
    object_bankInteriorLs[24] = CreateDynamicObject(18981, 1690.1251, -1053.4729, 1339.2508, 90.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[24], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[25] = CreateDynamicObject(18981, 1677.2307, -1052.6499, 1339.2845, 90.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[25], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[26] = CreateDynamicObject(18981, 1694.2386, -1052.9580, 1339.2508, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[26], 0, 16640, "a51", "ws_metalpanel1", 0x00000000);
    object_bankInteriorLs[27] = CreateDynamicObject(19172, 1679.6584, -1040.4620, 1339.1407, 180.0000, 180.0000, -180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bankInteriorLs[27], 0, "Zum Tresorraum", OBJECT_MATERIAL_SIZE_256x128, "Arial", 35, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bankInteriorLs[27], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[28] = CreateDynamicObject(19604, 1665.8454, -1036.2602, 1342.0603, 49.2998, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    SetDynamicObjectMaterial(object_bankInteriorLs[28], 0, 16434, "des_stwnsigns1", "des_banksign", 0x00000000);
    object_bankInteriorLs[29] = CreateDynamicObject(19172, 1688.5727, -1029.0227, 1342.8531, 180.0000, 180.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bankInteriorLs[29], 0, "Zentralbank", OBJECT_MATERIAL_SIZE_256x128, "Arial", 40, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bankInteriorLs[29], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[30] = CreateDynamicObject(19172, 1688.5760, -1029.0288, 1343.4029, 180.0000, 180.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bankInteriorLs[30], 0, "Los Santos", OBJECT_MATERIAL_SIZE_256x128, "Arial", 56, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bankInteriorLs[30], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[31] = CreateDynamicObject(11691, 1691.2069, -1031.7998, 1333.3033, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    SetDynamicObjectMaterial(object_bankInteriorLs[31], 0, 16640, "a51", "scratchedmetal", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[31], 1, 16640, "a51", "scratchedmetal", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[31], 2, 16640, "a51", "Metalox64", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[31], 3, 16640, "a51", "Metal3_128", 0x00000000);
    object_bankInteriorLs[32] = CreateDynamicObject(19325, 1688.5852, -1028.5456, 1342.4344, 90.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_bankInteriorLs[32], 0, -1, "none", "none", 0xFFC0C0C0);
    object_bankInteriorLs[33] = CreateDynamicObject(14407, 1700.6428, -1038.5808, 1336.3977, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs01
    SetDynamicObjectMaterial(object_bankInteriorLs[33], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0x00000000);
    object_bankInteriorLs[34] = CreateDynamicObject(1234, 1688.5903, -1033.1656, 1342.4814, 0.0000, 90.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[34], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[34], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[35] = CreateDynamicObject(18981, 1698.2507, -1043.9670, 1327.2204, 90.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[35], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[36] = CreateDynamicObject(14407, 1679.6905, -1048.4410, 1336.3977, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs01
    SetDynamicObjectMaterial(object_bankInteriorLs[36], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0x00000000);
    object_bankInteriorLs[37] = CreateDynamicObject(18981, 1703.0948, -1040.9344, 1339.4361, 90.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[37], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[38] = CreateDynamicObject(1234, 1688.5909, -1034.7198, 1341.2402, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[38], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[38], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[39] = CreateDynamicObject(1234, 1688.5909, -1034.7198, 1343.8785, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[39], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[39], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[40] = CreateDynamicObject(1234, 1688.5909, -1034.7198, 1346.5412, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[40], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[40], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[41] = CreateDynamicObject(1234, 1688.5903, -1020.9237, 1342.4814, 0.0000, 90.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[41], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[41], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[42] = CreateDynamicObject(1234, 1688.5903, -1018.2542, 1342.4814, 0.0000, 90.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[42], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[42], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[43] = CreateDynamicObject(18766, 1681.8028, -1052.4516, 1333.8481, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[43], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[44] = CreateDynamicObject(19464, 1666.2391, -1022.2827, 1341.5992, 0.0000, -40.7999, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[44], 0, 1355, "break_s_bins", "marble1", 0x00000000);
    object_bankInteriorLs[45] = CreateDynamicObject(19464, 1666.2391, -1039.2292, 1341.5992, 0.0000, -40.7999, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[45], 0, 1355, "break_s_bins", "marble1", 0x00000000);
    object_bankInteriorLs[46] = CreateDynamicObject(19464, 1694.8458, -1026.3259, 1342.2683, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[46], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFA9A9A9);
    object_bankInteriorLs[47] = CreateDynamicObject(19464, 1665.9587, -1034.7635, 1341.6612, 0.0000, -40.7999, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[47], 0, 14581, "ab_mafiasuitea", "goldPillar", 0x00000000);
    object_bankInteriorLs[48] = CreateDynamicObject(18981, 1694.2292, -1052.9527, 1338.2641, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[48], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFF808080);
    object_bankInteriorLs[49] = CreateDynamicObject(18766, 1683.0754, -1047.9919, 1333.8481, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[49], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[50] = CreateDynamicObject(1234, 1688.5903, -1027.6208, 1342.4814, 0.0000, 90.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[50], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[50], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[51] = CreateDynamicObject(19464, 1665.1164, -1022.2827, 1344.1412, 0.0000, 48.3997, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[51], 0, 1355, "break_s_bins", "marble1", 0x00000000);
    object_bankInteriorLs[52] = CreateDynamicObject(19464, 1694.8758, -1028.7978, 1340.5566, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[52], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFA9A9A9);
    object_bankInteriorLs[53] = CreateDynamicObject(19464, 1665.1164, -1030.7547, 1344.1412, 0.0000, 48.3997, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[53], 0, 1355, "break_s_bins", "marble1", 0x00000000);
    object_bankInteriorLs[54] = CreateDynamicObject(19172, 1688.5919, -1028.9792, 1341.6540, 180.0000, 180.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bankInteriorLs[54], 0, "C", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 150, 0, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bankInteriorLs[54], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[55] = CreateDynamicObject(2942, 1674.2822, -1034.2076, 1340.3857, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_bankInteriorLs[56] = CreateDynamicObject(19439, 1675.0493, -1028.0034, 1339.9875, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall079
    SetDynamicObjectMaterial(object_bankInteriorLs[56], 0, 2176, "casino_props", "marblebox", 0x00000000);
    object_bankInteriorLs[57] = CreateDynamicObject(2942, 1675.4840, -1028.0058, 1340.3857, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_bankInteriorLs[58] = CreateDynamicObject(1742, 1691.1057, -1019.3748, 1339.7591, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Med_BOOKSHELF
    object_bankInteriorLs[59] = CreateDynamicObject(18981, 1690.1251, -1027.9858, 1327.2191, 90.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[59], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[60] = CreateDynamicObject(19464, 1694.9156, -1028.9881, 1340.5566, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[60], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFA9A9A9);
    object_bankInteriorLs[61] = CreateDynamicObject(2010, 1687.7325, -1022.9525, 1339.7362, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_bankInteriorLs[62] = CreateDynamicObject(18980, 1693.9759, -1022.9370, 1340.8552, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[62], 0, 16023, "des_trainstuff", "ws_stoneblock", 0x00000000);
    object_bankInteriorLs[63] = CreateDynamicObject(638, 1688.1765, -1027.8950, 1340.0760, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_bankInteriorLs[64] = CreateDynamicObject(18766, 1687.1140, -1030.8050, 1335.7500, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[64], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFE0FFFF);
    object_bankInteriorLs[65] = CreateDynamicObject(18766, 1694.1579, -1052.0118, 1333.8481, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[65], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[66] = CreateDynamicObject(2424, 1684.2478, -1023.3607, 1339.7408, 0.0000, 0.0000, -90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_CONTER_1
    object_bankInteriorLs[67] = CreateDynamicObject(18766, 1686.1319, -1052.0118, 1333.8481, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[67], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[68] = CreateDynamicObject(18980, 1688.5649, -1026.0288, 1340.8552, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[68], 0, 16023, "des_trainstuff", "ws_stoneblock", 0x00000000);
    object_bankInteriorLs[69] = CreateDynamicObject(19325, 1693.9896, -1020.4110, 1342.4344, 90.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_bankInteriorLs[69], 0, -1, "none", "none", 0xFFC0C0C0);
    object_bankInteriorLs[70] = CreateDynamicObject(1714, 1696.2818, -1021.6671, 1339.7286, 0.0000, 0.0000, -33.7999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_bankInteriorLs[71] = CreateDynamicObject(18766, 1693.5925, -1019.0006, 1341.8160, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[71], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[72] = CreateDynamicObject(18766, 1690.1062, -1052.0118, 1333.8481, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[72], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[73] = CreateDynamicObject(11691, 1692.1175, -1051.1235, 1333.2733, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    SetDynamicObjectMaterial(object_bankInteriorLs[73], 0, 16640, "a51", "scratchedmetal", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[73], 1, 16640, "a51", "scratchedmetal", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[73], 2, 16640, "a51", "Metalox64", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[73], 3, 16640, "a51", "Metal3_128", 0x00000000);
    object_bankInteriorLs[74] = CreateDynamicObject(11691, 1688.0759, -1051.1235, 1333.2733, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    SetDynamicObjectMaterial(object_bankInteriorLs[74], 0, 16640, "a51", "scratchedmetal", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[74], 1, 16640, "a51", "scratchedmetal", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[74], 2, 16640, "a51", "Metalox64", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[74], 3, 16640, "a51", "Metal3_128", 0x00000000);
    object_bankInteriorLs[75] = CreateDynamicObject(18981, 1701.0958, -1031.9819, 1344.8138, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[75], 0, 14706, "labig2int2", "whitecarpet01", 0xFFFFFFFF);
    object_bankInteriorLs[76] = CreateDynamicObject(2423, 1684.3188, -1021.3989, 1339.7397, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_CONTER_1b
    object_bankInteriorLs[77] = CreateDynamicObject(2424, 1684.2478, -1024.2915, 1339.7408, 0.0000, 0.0000, -90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_CONTER_1
    object_bankInteriorLs[78] = CreateDynamicObject(2424, 1684.2478, -1022.4298, 1339.7408, 0.0000, 0.0000, -90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_CONTER_1
    object_bankInteriorLs[79] = CreateDynamicObject(2942, 1675.4840, -1033.7684, 1340.3857, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_bankInteriorLs[80] = CreateDynamicObject(19325, 1690.3972, -1026.0854, 1346.8558, 90.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_bankInteriorLs[80], 0, -1, "none", "none", 0xFFC0C0C0);
    object_bankInteriorLs[81] = CreateDynamicObject(638, 1688.1765, -1030.5067, 1340.0760, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_bankInteriorLs[82] = CreateDynamicObject(18980, 1688.5649, -1018.9959, 1340.8552, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[82], 0, 16023, "des_trainstuff", "ws_stoneblock", 0x00000000);
    object_bankInteriorLs[83] = CreateDynamicObject(2773, 1682.4613, -1026.1091, 1340.2530, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_bankInteriorLs[84] = CreateDynamicObject(19356, 1687.7640, -1019.0874, 1346.5998, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall004
    SetDynamicObjectMaterial(object_bankInteriorLs[84], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFD2B48C);
    object_bankInteriorLs[85] = CreateDynamicObject(19356, 1684.5527, -1019.0874, 1346.5998, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall004
    SetDynamicObjectMaterial(object_bankInteriorLs[85], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFD2B48C);
    object_bankInteriorLs[86] = CreateDynamicObject(19356, 1681.3414, -1019.0874, 1346.5998, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall004
    SetDynamicObjectMaterial(object_bankInteriorLs[86], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFD2B48C);
    object_bankInteriorLs[87] = CreateDynamicObject(1550, 1689.0494, -1051.1097, 1334.3974, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Geldsack
    object_bankInteriorLs[88] = CreateDynamicObject(1550, 1688.3087, -1051.5902, 1334.2573, -90.0000, -15.8999, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Geldsack
    object_bankInteriorLs[89] = CreateDynamicObject(1550, 1687.3288, -1051.1097, 1334.3974, 0.0000, 0.0000, 92.9999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Geldsack
    object_bankInteriorLs[90] = CreateDynamicObject(18981, 1676.0941, -1031.2569, 1345.5847, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[90], 0, 14706, "labig2int2", "whitecarpet01", 0xFFFFFFFF);
    object_bankInteriorLs[91] = CreateDynamicObject(18766, 1698.2230, -1024.4703, 1341.8160, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[91], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[92] = CreateDynamicObject(18980, 1691.3575, -1026.0288, 1340.8552, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[92], 0, 16023, "des_trainstuff", "ws_stoneblock", 0x00000000);
    object_bankInteriorLs[93] = CreateDynamicObject(1550, 1693.0913, -1050.8087, 1334.3974, 0.0000, 0.0000, 92.9999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Geldsack
    object_bankInteriorLs[94] = CreateDynamicObject(1704, 1670.8553, -1025.0505, 1339.6959, 0.0000, 0.0000, 177.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair03
    object_bankInteriorLs[95] = CreateDynamicObject(1550, 1692.0814, -1050.8614, 1334.3974, 0.0000, 0.0000, 42.1999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Geldsack
    object_bankInteriorLs[96] = CreateDynamicObject(1550, 1692.0637, -1050.9919, 1333.4265, 90.0000, -10.1997, 177.1000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Geldsack
    object_bankInteriorLs[97] = CreateDynamicObject(18981, 1677.2307, -1027.6479, 1326.2523, 90.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[97], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[98] = CreateDynamicObject(18981, 1699.2264, -1044.9930, 1351.9155, 90.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[98], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[99] = CreateDynamicObject(19464, 1665.1164, -1039.2258, 1344.1412, 0.0000, 48.3997, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[99], 0, 1355, "break_s_bins", "marble1", 0x00000000);
    object_bankInteriorLs[100] = CreateDynamicObject(18981, 1687.1512, -1057.0238, 1352.0278, 90.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[100], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[101] = CreateDynamicObject(1616, 1686.9238, -1044.1003, 1343.9687, 0.0000, 0.0000, -92.6996, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_bankInteriorLs[102] = CreateDynamicObject(2773, 1682.4613, -1021.6478, 1340.2530, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_bankInteriorLs[103] = CreateDynamicObject(1704, 1669.7148, -1019.9926, 1339.6959, 0.0000, 0.0000, -6.7999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair03
    object_bankInteriorLs[104] = CreateDynamicObject(19604, 1664.9842, -1036.2602, 1343.9492, 139.0001, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    SetDynamicObjectMaterial(object_bankInteriorLs[104], 0, 16434, "des_stwnsigns1", "des_banksign", 0x00000000);
    object_bankInteriorLs[105] = CreateDynamicObject(19325, 1688.5852, -1024.4641, 1346.8558, 90.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_bankInteriorLs[105], 0, -1, "none", "none", 0xFFC0C0C0);
    object_bankInteriorLs[106] = CreateDynamicObject(1616, 1688.2347, -1019.7824, 1343.7298, 0.0000, 0.0000, 76.0998, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_bankInteriorLs[107] = CreateDynamicObject(2424, 1684.2478, -1025.2219, 1339.7408, 0.0000, 0.0000, -90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_CONTER_1
    object_bankInteriorLs[108] = CreateDynamicObject(1703, 1668.5240, -1023.3350, 1339.6921, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
    object_bankInteriorLs[109] = CreateDynamicObject(1234, 1689.7020, -1026.0742, 1343.5224, 0.0000, 90.0000, -180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[109], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[109], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[110] = CreateDynamicObject(19325, 1688.5852, -1020.4110, 1342.4344, 90.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_bankInteriorLs[110], 0, -1, "none", "none", 0xFFC0C0C0);
    object_bankInteriorLs[111] = CreateDynamicObject(1616, 1687.6866, -1032.5653, 1343.9687, 0.0000, 0.0000, -2.7999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_bankInteriorLs[112] = CreateDynamicObject(1616, 1686.2558, -1052.4304, 1343.9687, 0.0000, 0.0000, -2.7999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_bankInteriorLs[113] = CreateDynamicObject(19325, 1688.5852, -1032.6667, 1342.4344, 90.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_bankInteriorLs[113], 0, -1, "none", "none", 0xFFC0C0C0);
    object_bankInteriorLs[114] = CreateDynamicObject(1616, 1702.2374, -1043.9929, 1343.9687, 0.0000, 0.0000, -4.2996, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_bankInteriorLs[115] = CreateDynamicObject(18981, 1689.0483, -1031.9819, 1356.8125, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[115], 0, 14706, "labig2int2", "whitecarpet01", 0xFFFFFFFF);
    object_bankInteriorLs[116] = CreateDynamicObject(18981, 1676.0941, -1056.2606, 1345.5847, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[116], 0, 14706, "labig2int2", "whitecarpet01", 0xFFFFFFFF);
    object_bankInteriorLs[117] = CreateDynamicObject(1893, 1679.6483, -1038.2645, 1337.7353, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_bankInteriorLs[118] = CreateDynamicObject(18981, 1690.1450, -1040.5078, 1332.7904, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[118], 0, 16640, "a51", "ws_metalpanel1", 0x00000000);
    object_bankInteriorLs[119] = CreateDynamicObject(1893, 1684.2408, -1038.2645, 1337.7353, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_bankInteriorLs[120] = CreateDynamicObject(1893, 1688.6948, -1038.2645, 1337.7353, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_bankInteriorLs[121] = CreateDynamicObject(18766, 1687.6958, -1036.3199, 1335.7500, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[121], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFE0FFFF);
    object_bankInteriorLs[122] = CreateDynamicObject(1616, 1697.4753, -1051.8155, 1337.3309, 0.0000, 0.0000, -3.7999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_bankInteriorLs[123] = CreateDynamicObject(18981, 1686.2314, -1027.9680, 1338.2641, 0.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[123], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFF808080);
    object_bankInteriorLs[124] = CreateDynamicObject(1616, 1682.9383, -1040.7397, 1337.3646, -2.0000, 0.0000, -178.1002, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_bankInteriorLs[125] = CreateDynamicObject(18766, 1698.2230, -1034.4713, 1341.8160, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[125], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[126] = CreateDynamicObject(18981, 1703.0898, -1032.1787, 1352.2137, 90.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[126], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[127] = CreateDynamicObject(18981, 1711.0561, -1027.9930, 1352.2137, 90.0000, -90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[127], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[128] = CreateDynamicObject(14455, 1692.5704, -1028.7169, 1341.3651, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gs_BOOKCASE
    object_bankInteriorLs[129] = CreateDynamicObject(1234, 1688.5903, -1030.2928, 1342.4814, 0.0000, 90.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
    SetDynamicObjectMaterial(object_bankInteriorLs[129], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_bankInteriorLs[129], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[130] = CreateDynamicObject(18981, 1674.2657, -1053.4636, 1351.9155, 90.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[130], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[131] = CreateDynamicObject(18980, 1688.5649, -1032.3341, 1340.8552, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[131], 0, 16023, "des_trainstuff", "ws_stoneblock", 0x00000000);
    object_bankInteriorLs[132] = CreateDynamicObject(18981, 1677.2318, -1052.6595, 1352.2180, 90.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[132], 0, 3922, "bistro", "mottled_grey_64HV", 0x00000000);
    object_bankInteriorLs[133] = CreateDynamicObject(638, 1688.1765, -1020.9719, 1340.0760, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_bankInteriorLs[134] = CreateDynamicObject(19604, 1664.9315, -1027.7828, 1343.9029, 139.0001, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    SetDynamicObjectMaterial(object_bankInteriorLs[134], 0, 16434, "des_stwnsigns1", "des_banksign", 0x00000000);
    object_bankInteriorLs[135] = CreateDynamicObject(19464, 1665.1036, -1027.4615, 1344.2738, 0.0000, 49.5998, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[135], 0, 14581, "ab_mafiasuitea", "goldPillar", 0x00000000);
    object_bankInteriorLs[136] = CreateDynamicObject(1714, 1690.8702, -1021.7675, 1339.7286, 0.0000, 0.0000, -23.7999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_bankInteriorLs[137] = CreateDynamicObject(1742, 1696.7972, -1019.3942, 1339.7591, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Med_BOOKSHELF
    object_bankInteriorLs[138] = CreateDynamicObject(19439, 1674.1584, -1027.9654, 1339.9875, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall079
    SetDynamicObjectMaterial(object_bankInteriorLs[138], 0, 2176, "casino_props", "marblebox", 0x00000000);
    object_bankInteriorLs[139] = CreateDynamicObject(19464, 1665.1036, -1035.5893, 1344.2738, 0.0000, 49.5998, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_bankInteriorLs[139], 0, 14581, "ab_mafiasuitea", "goldPillar", 0x00000000);
    object_bankInteriorLs[140] = CreateDynamicObject(1616, 1697.5925, -1038.3442, 1336.7103, 0.0000, 0.0000, 49.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam1_01
    object_bankInteriorLs[141] = CreateDynamicObject(19172, 1682.5598, -1052.9543, 1342.5876, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_bankInteriorLs[141], 0, 14489, "carlspics", "AH_landscap1", 0x00000000);
    object_bankInteriorLs[142] = CreateDynamicObject(14455, 1696.9228, -1029.0769, 1341.3651, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gs_BOOKCASE
    object_bankInteriorLs[143] = CreateDynamicObject(14455, 1692.5704, -1031.7097, 1341.3651, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gs_BOOKCASE
    object_bankInteriorLs[144] = CreateDynamicObject(2010, 1686.9718, -1044.0201, 1339.7362, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_bankInteriorLs[145] = CreateDynamicObject(2010, 1686.1910, -1052.4731, 1339.7362, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_bankInteriorLs[146] = CreateDynamicObject(2010, 1668.9344, -1024.3431, 1339.7469, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_bankInteriorLs[147] = CreateDynamicObject(2942, 1674.3127, -1027.5454, 1340.3857, 0.0000, 0.0000, -180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_bankInteriorLs[148] = CreateDynamicObject(2942, 1674.2822, -1028.3839, 1340.3857, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_bankInteriorLs[149] = CreateDynamicObject(11728, 1671.9874, -1019.2457, 1340.9477, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PaperChasePhone1
    object_bankInteriorLs[150] = CreateDynamicObject(14455, 1696.9327, -1026.4045, 1341.3651, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gs_BOOKCASE
    object_bankInteriorLs[151] = CreateDynamicObject(18981, 1667.5107, -1027.9580, 1351.2408, 0.0000, 180.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[151], 0, 16640, "a51", "a51_glass", 0xFFFFFF00);
    object_bankInteriorLs[152] = CreateDynamicObject(2311, 1670.2165, -1021.8010, 1339.7091, 0.0000, 0.0000, -84.8000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE2
    object_bankInteriorLs[153] = CreateDynamicObject(2202, 1691.0571, -1033.4112, 1339.6910, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PHOTOCOPIER_2
    object_bankInteriorLs[154] = CreateDynamicObject(2010, 1678.0981, -1052.4731, 1339.7362, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_bankInteriorLs[155] = CreateDynamicObject(2010, 1701.6534, -1044.0201, 1339.7362, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_bankInteriorLs[156] = CreateDynamicObject(18075, 1682.0616, -1046.4090, 1345.1435, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bankInteriorLs[157] = CreateDynamicObject(1703, 1697.2191, -1034.7287, 1339.6921, 0.0000, 0.0000, -90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
    object_bankInteriorLs[158] = CreateDynamicObject(1704, 1695.1627, -1033.5200, 1339.6959, 0.0000, 0.0000, -22.6998, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair03
    object_bankInteriorLs[159] = CreateDynamicObject(18075, 1692.1628, -1038.6960, 1344.3525, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bankInteriorLs[160] = CreateDynamicObject(2311, 1695.2380, -1035.4470, 1339.7091, 0.0000, 0.0000, -84.8000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE2
    object_bankInteriorLs[161] = CreateDynamicObject(19173, 1697.7298, -1034.8714, 1342.0974, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_bankInteriorLs[162] = CreateDynamicObject(2010, 1687.7325, -1026.1153, 1339.7362, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
    object_bankInteriorLs[163] = CreateDynamicObject(19441, 1698.6605, -1029.9571, 1338.9177, -90.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_bankInteriorLs[163], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_bankInteriorLs[164] = CreateDynamicObject(19172, 1700.5897, -1028.4781, 1337.6495, 180.0000, 180.0000, -180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_bankInteriorLs[164], 0,"Zum Tresorraum", OBJECT_MATERIAL_SIZE_256x128, "Arial", 35, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_bankInteriorLs[164], 1, 19297, "matlights", "invisible", 0x00000000);
    object_bankInteriorLs[165] = CreateDynamicObject(970, 1679.6483, -1040.3736, 1340.2956, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_bankInteriorLs[166] = CreateDynamicObject(970, 1681.7103, -1046.6070, 1340.2956, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_bankInteriorLs[167] = CreateDynamicObject(970, 1681.7103, -1042.4438, 1340.2956, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_bankInteriorLs[168] = CreateDynamicObject(2423, 1685.2895, -1026.2204, 1339.7397, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_CONTER_1b
    object_bankInteriorLs[169] = CreateDynamicObject(2423, 1685.3596, -1021.4708, 1339.7397, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_CONTER_1b
    object_bankInteriorLs[170] = CreateDynamicObject(19172, 1694.3192, -1032.8404, 1342.1323, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    object_bankInteriorLs[171] = CreateDynamicObject(1893, 1693.7373, -1038.2645, 1337.7353, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_bankInteriorLs[172] = CreateDynamicObject(18075, 1693.5083, -1027.0167, 1344.2927, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bankInteriorLs[173] = CreateDynamicObject(18075, 1674.3009, -1029.6385, 1345.1435, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_bankInteriorLs[174] = CreateDynamicObject(2002, 1671.3183, -1019.8626, 1339.7303, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
    object_bankInteriorLs[175] = CreateDynamicObject(2855, 1670.2099, -1022.6397, 1340.2020, 0.0000, 0.0000, -107.7994, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags05
    object_bankInteriorLs[176] = CreateDynamicObject(19174, 1669.9393, -1019.3416, 1342.5311, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterial(object_bankInteriorLs[176], 0, 14420, "dr_gsbits", "mp_apt1_pic6", 0x00000000);
    object_bankInteriorLs[177] = CreateDynamicObject(18766, 1687.0976, -1029.9350, 1333.8481, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[177], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[178] = CreateDynamicObject(18766, 1687.7065, -1035.3349, 1333.8481, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[178], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[179] = CreateDynamicObject(18766, 1697.2696, -1047.9919, 1333.8481, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[179], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[180] = CreateDynamicObject(18766, 1688.5953, -1030.8050, 1335.7500, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[180], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFE0FFFF);
    object_bankInteriorLs[181] = CreateDynamicObject(18766, 1682.0849, -1028.2795, 1335.7500, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[181], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFE0FFFF);
    object_bankInteriorLs[182] = CreateDynamicObject(18766, 1691.7966, -1052.4516, 1333.8481, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[182], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[183] = CreateDynamicObject(18766, 1688.6186, -1030.3548, 1333.8481, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_bankInteriorLs[183], 0, 14576, "mafiacasinovault01", "ab_vaultboxes", 0xFFE6E6FA);
    object_bankInteriorLs[184] = CreateDynamicObject(11691, 1682.6765, -1031.7998, 1333.3033, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    SetDynamicObjectMaterial(object_bankInteriorLs[184], 0, 16640, "a51", "scratchedmetal", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[184], 1, 16640, "a51", "scratchedmetal", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[184], 2, 16640, "a51", "Metalox64", 0x00000000);
    SetDynamicObjectMaterial(object_bankInteriorLs[184], 3, 16640, "a51", "Metal3_128", 0x00000000);
    object_bankInteriorLs[185] = CreateDynamicObject(1721, 1690.5533, -1032.8818, 1333.2806, 0.0000, 0.0000, -7.8000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    object_bankInteriorLs[186] = CreateDynamicObject(1721, 1691.8214, -1032.9311, 1333.2806, 0.0000, 0.0000, 7.0998, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    object_bankInteriorLs[187] = CreateDynamicObject(1721, 1683.3581, -1033.0279, 1333.2806, 0.0000, 0.0000, 7.0998, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    object_bankInteriorLs[188] = CreateDynamicObject(1721, 1681.9801, -1032.9610, 1333.2806, 0.0000, 0.0000, -12.3999, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    object_bankInteriorLs[189] = CreateDynamicObject(2059, 1690.7635, -1031.8248, 1334.1070, 0.0000, 0.0000, -4.9998, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_GUNSTUFF1
    object_bankInteriorLs[190] = CreateDynamicObject(1893, 1690.7071, -1031.8443, 1337.7556, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_bankInteriorLs[191] = CreateDynamicObject(1893, 1681.6849, -1031.8443, 1337.4353, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_bankInteriorLs[192] = CreateDynamicObject(19893, 1684.4062, -1022.8405, 1340.7884, 0.0000, 0.0000, 85.6996, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_bankInteriorLs[193] = CreateDynamicObject(18981, 1664.2895, -1040.6512, 1339.2508, 90.0000, 90.0000, 0.0000, VW_BANKINTERIORLS, MAPS_BANKINTERIORLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_bankInteriorLs[193], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);


    HP_bankInteriorLs[0] = CreateDynamicObject(2332, 1686.8259, -1031.4426, 1333.7956, 0.0000, 0.0000, -90.0000, VW_BANKINTERIORLS); //Tresorzu
    HP_Tresor[0] = 5000;
    HP_bankInteriorLs[1] = CreateDynamicObject(2332, 1689.5681, -1019.7673, 1340.2413, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS); //Tresorzu
    HP_Tresor[1] = 5000;
    HP_bankInteriorLs[2] = CreateDynamicObject(2332, 1684.2133, -1035.0657, 1333.7956, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS); //Tresorzu
    HP_Tresor[2] = 5000;
    HP_bankInteriorLs[3] = CreateDynamicObject(2332, 1695.2431, -1019.7673, 1340.2413, 0.0000, 0.0000, 0.0000, VW_BANKINTERIORLS); //Tresorzu
    HP_Tresor[3] = 5000;
    HP_bankInteriorLs[4] = CreateDynamicObject(2332, 1691.2214, -1035.0546, 1333.7956, 0.0000, 0.0000, 180.0000, VW_BANKINTERIORLS); //Tresorzu
    HP_Tresor[4] = 5000;
    HP_bankInteriorLs[5] = CreateDynamicObject(2332, 1688.9193, -1030.3500, 1333.7956, 0.0000, 0.0000, 90.0000, VW_BANKINTERIORLS); //Tresorzu
    HP_Tresor[5] = 5000;

    Label_HP_bankInteriorLs[0] = Create3DTextLabel("{FFFFFF}- Kleiner Tresor -\n\n{CB2720}Verschlossen", 0x008080FF, 1686.8259, -1031.4426, 1333.7956, 7.0, VW_BANKINTERIORLS, 0);
    Label_HP_bankInteriorLs[1] = Create3DTextLabel("{FFFFFF}- Kleiner Tresor -\n\n{CB2720}Verschlossen", 0x008080FF, 1689.5681, -1019.7673, 1340.2413, 7.0, VW_BANKINTERIORLS, 0);
    Label_HP_bankInteriorLs[2] = Create3DTextLabel("{FFFFFF}- Kleiner Tresor -\n\n{CB2720}Verschlossen", 0x008080FF, 1684.2133, -1035.0657, 1333.7956, 7.0, VW_BANKINTERIORLS, 0);
    Label_HP_bankInteriorLs[3] = Create3DTextLabel("{FFFFFF}- Kleiner Tresor -\n\n{CB2720}Verschlossen", 0x008080FF, 1695.2431, -1019.7673, 1340.2413, 7.0, VW_BANKINTERIORLS, 0);
    Label_HP_bankInteriorLs[4] = Create3DTextLabel("{FFFFFF}- Kleiner Tresor -\n\n{CB2720}Verschlossen", 0x008080FF, 1691.2214, -1035.0546, 1333.7956, 7.0, VW_BANKINTERIORLS, 0);
    Label_HP_bankInteriorLs[5] = Create3DTextLabel("{FFFFFF}- Kleiner Tresor -\n\n{CB2720}Verschlossen", 0x008080FF, 1688.9193, -1030.3500, 1333.7956, 7.0, VW_BANKINTERIORLS, 0);

    Label_bankInteriorLs[0] = Create3DTextLabel("{FFFFFF}- Wertpapiere stehlen -\n\n{CB2720}Benutze /Wertpapiere", 0x008080FF, 1696.2445,-1031.0490,1340.7509, 7.0, VW_BANKINTERIORLS, 0);
    Wertpap[0] = false;
    Label_bankInteriorLs[1] = Create3DTextLabel("{FFFFFF}- Wertpapiere stehlen -\n\n{CB2720}Benutze /Wertpapiere", 0x008080FF, 1693.9166,-1029.7340,1340.7509, 7.0, VW_BANKINTERIORLS, 0);
    Wertpap[1] = false;
    Label_bankInteriorLs[2] = Create3DTextLabel("{FFFFFF}- Wertpapiere stehlen -\n\n{CB2720}Benutze /Wertpapiere", 0x008080FF, 1692.5431,-1027.2142,1340.7509, 7.0, VW_BANKINTERIORLS, 0);
    Wertpap[2] = false;
    Label_bankInteriorLs[3] = Create3DTextLabel("{FFFFFF}- Wertpapiere stehlen -\n\n{CB2720}Benutze /Wertpapiere", 0x008080FF, 1696.9338,-1028.0938,1340.7509, 7.0, VW_BANKINTERIORLS, 0);
    Wertpap[3] = false;

    Label_bankInteriorLs[4] = Create3DTextLabel("{FFFFFF}- Banksystem hacken -\n\n{CB2720}Benutze /Bankhacken", 0x008080FF, 1690.5631,-1022.4385,1340.7509, 7.0, VW_BANKINTERIORLS, 0);

    Label_bankInteriorLs[5] = Create3DTextLabel("{FFFFFF}- Tresore sprengen -\n\n{CB2720}Benutze /C4legen", 0x008080FF, 1695.7092,-1049.6833,1334.2904, 7.0, VW_BANKINTERIORLS, 0);
    Tresor[0] = false;
    Label_bankInteriorLs[6] = Create3DTextLabel("{FFFFFF}- Tresore sprengen -\n\n{CB2720}Benutze /C4legen", 0x008080FF, 1692.2316,-1048.0509,1334.2904, 7.0, VW_BANKINTERIORLS, 0);
    Tresor[1] = false;
    Label_bankInteriorLs[7] = Create3DTextLabel("{FFFFFF}- Tresore sprengen -\n\n{CB2720}Benutze /C4legen", 0x008080FF, 1687.9445,-1047.8927,1334.2904, 7.0, VW_BANKINTERIORLS, 0);
    Tresor[2] = false;
    Label_bankInteriorLs[8] = Create3DTextLabel("{FFFFFF}- Tresore sprengen -\n\n{CB2720}Benutze /C4legen", 0x008080FF, 1684.5870,-1049.8440,1334.2904, 7.0, VW_BANKINTERIORLS, 0);
    Tresor[3] = false;
}