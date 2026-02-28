#include <YSI\y_hooks>

// Global interior define
#define MAPS_SCHWARZMARKT      0

static Float:STREAMDISTANCE = 100.0;
static Float:DRAWDISTANCE   = 90.0;

//Mapvariables
new object_Schwarzmarkt[128];
new Schwarzmarkt_Actor[8];


hook OnGameModeInit() {
    object_Schwarzmarkt[0] = CreateDynamicObject(2042, -1102.5125, -2861.7880, 61.2055, 0.0000, 0.0000, 24.3000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M3
    object_Schwarzmarkt[1] = CreateDynamicObject(19457, -1131.9635, -2856.8342, 60.0126, 0.0000, -90.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[1], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[2] = CreateDynamicObject(19172, -1105.0480, -2853.8127, 60.5585, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[2], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[2], 1,"SIM-Karten", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[3] = CreateDynamicObject(1518, -1097.4586, -2857.8649, 61.1959, 0.0000, 0.0000, -72.6999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_TV_2
    SetDynamicObjectMaterial(object_Schwarzmarkt[3], 2, 18996, "mattextures", "policeshield", 0x00000000);
    object_Schwarzmarkt[4] = CreateDynamicObject(19507, -1101.9001, -2858.1650, 62.3692, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lshouse2
    object_Schwarzmarkt[5] = CreateDynamicObject(19508, -1101.9001, -2858.1650, 62.3692, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lshouse2int
    SetDynamicObjectMaterial(object_Schwarzmarkt[5], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    SetDynamicObjectMaterial(object_Schwarzmarkt[5], 1, 10891, "bakery_sfse", "ws_altz_wall4", 0x00000000);
    object_Schwarzmarkt[6] = CreateDynamicObject(2180, -1104.4792, -2861.9614, 60.1248, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    object_Schwarzmarkt[7] = CreateDynamicObject(2180, -1101.4561, -2861.9614, 60.1248, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    object_Schwarzmarkt[8] = CreateDynamicObject(2180, -1098.2630, -2861.9614, 60.1248, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    object_Schwarzmarkt[9] = CreateDynamicObject(2180, -1097.3421, -2857.8874, 60.1248, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    object_Schwarzmarkt[10] = CreateDynamicObject(2180, -1097.3421, -2855.2248, 60.1248, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    object_Schwarzmarkt[11] = CreateDynamicObject(1576, -1105.4530, -2861.9316, 60.8967, 0.0000, 0.0000, -1.8998, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
    object_Schwarzmarkt[12] = CreateDynamicObject(1579, -1105.5982, -2861.7253, 60.9622, -30.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_blue
    object_Schwarzmarkt[13] = CreateDynamicObject(355, -1101.1317, -2861.7465, 60.9206, 85.4000, -84.4999, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ak47
    object_Schwarzmarkt[14] = CreateDynamicObject(355, -1101.1888, -2861.7641, 60.9421, 85.4000, -72.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ak47
    object_Schwarzmarkt[15] = CreateDynamicObject(1578, -1098.0843, -2861.7270, 60.8876, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
    object_Schwarzmarkt[16] = CreateDynamicObject(1578, -1098.0843, -2862.1174, 60.8876, 0.0000, 0.0000, -7.9998, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
    object_Schwarzmarkt[17] = CreateDynamicObject(1578, -1098.0573, -2861.9172, 61.0377, 0.0000, 0.0000, 55.2999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
    object_Schwarzmarkt[18] = CreateDynamicObject(19435, -1095.5736, -2854.7370, 61.4505, -74.4999, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall075
    SetDynamicObjectMaterial(object_Schwarzmarkt[18], 0, 2589, "ab_ab", "ab_sheetSteel", 0x00000000);
    object_Schwarzmarkt[19] = CreateDynamicObject(19786, -1095.4418, -2858.3410, 61.9164, 0.0000, -1.1000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_Schwarzmarkt[19], 1, 7009, "vgndwntwn1", "newpolice_sa", 0x00000000);
    object_Schwarzmarkt[20] = CreateDynamicObject(2180, -1099.2440, -2853.3833, 60.1248, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    object_Schwarzmarkt[21] = CreateDynamicObject(2180, -1102.3367, -2853.3833, 60.1248, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    object_Schwarzmarkt[22] = CreateDynamicObject(2180, -1105.5098, -2853.3833, 60.1248, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    object_Schwarzmarkt[23] = CreateDynamicObject(19172, -1104.9868, -2861.5302, 60.6085, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[23], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[23], 1, "Drogen", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[24] = CreateDynamicObject(19172, -1101.9348, -2861.5302, 60.6085, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[24], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[24], 1, "Waffenteile", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[25] = CreateDynamicObject(19172, -1098.7320, -2861.5302, 60.6085, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[25], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[25], 1, "Spice", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[26] = CreateDynamicObject(19172, -1097.7811, -2858.3671, 60.6085, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[26], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[26], 1, "Wantedcodes", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[27] = CreateDynamicObject(19172, -1097.7811, -2855.7246, 60.6085, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[27], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[27], 1, "Waffen", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[28] = CreateDynamicObject(19172, -1097.7811, -2855.2617, 60.7509, 0.0000, 16.0000, 90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[28], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[28], 1, "illegale", OBJECT_MATERIAL_SIZE_256x128, "Arial", 20, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[29] = CreateDynamicObject(19172, -1098.7220, -2853.8527, 60.5584, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[29], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[29], 1, "Gegenstände", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[30] = CreateDynamicObject(19172, -1099.3510, -2853.8227, 60.7513, 0.0000, 17.7000, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[30], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[30], 1, "illegale", OBJECT_MATERIAL_SIZE_256x128, "Arial", 20, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[31] = CreateDynamicObject(356, -1097.5703, -2854.8200, 60.9317, 86.9000, -63.3000, 61.9001, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    object_Schwarzmarkt[32] = CreateDynamicObject(356, -1097.6030, -2854.8281, 60.9804, 86.9000, -63.3000, 69.8001, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    object_Schwarzmarkt[33] = CreateDynamicObject(359, -1097.4881, -2855.8830, 60.8955, 86.5999, 0.0000, 111.4998, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rocketla
    object_Schwarzmarkt[34] = CreateDynamicObject(359, -1097.6054, -2855.8864, 60.8990, 86.5999, 0.0000, 111.4998, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rocketla
    object_Schwarzmarkt[35] = CreateDynamicObject(342, -1097.2951, -2855.1123, 60.9786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    object_Schwarzmarkt[36] = CreateDynamicObject(342, -1097.2951, -2855.2124, 60.9786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    object_Schwarzmarkt[37] = CreateDynamicObject(342, -1097.3952, -2855.1123, 60.9786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    object_Schwarzmarkt[38] = CreateDynamicObject(342, -1097.3952, -2855.2023, 60.9786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    object_Schwarzmarkt[39] = CreateDynamicObject(1672, -1097.5529, -2855.0302, 61.0074, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gasgrenade
    object_Schwarzmarkt[40] = CreateDynamicObject(1672, -1097.5529, -2855.1403, 61.0074, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gasgrenade
    object_Schwarzmarkt[41] = CreateDynamicObject(1672, -1097.6630, -2855.1403, 61.0074, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gasgrenade
    object_Schwarzmarkt[42] = CreateDynamicObject(1672, -1097.6630, -2855.0302, 61.0074, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gasgrenade
    object_Schwarzmarkt[43] = CreateDynamicObject(373, -1097.3973, -2856.3977, 61.3523, -23.9000, -66.2000, 122.3002, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //armour
    object_Schwarzmarkt[44] = CreateDynamicObject(19921, -1102.4803, -2862.0517, 61.0190, 0.0000, 0.0000, 17.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneToolBox1
    object_Schwarzmarkt[45] = CreateDynamicObject(1650, -1097.9991, -2853.4948, 61.2236, 0.0000, 0.0000, 156.0990, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //petrolcanm
    object_Schwarzmarkt[46] = CreateDynamicObject(1650, -1097.9628, -2853.6850, 61.2236, 0.0000, 0.0000, 156.0990, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //petrolcanm
    object_Schwarzmarkt[47] = CreateDynamicObject(19172, -1101.8349, -2853.8227, 60.5584, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[47], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[47], 1, "Kennzeichen", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[48] = CreateDynamicObject(19172, -1102.2912, -2853.8327, 60.7588, 0.0000, 6.9998, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[48], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[48], 1, "Gefälschte", OBJECT_MATERIAL_SIZE_256x128, "Arial", 20, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[49] = CreateDynamicObject(18637, -1099.2606, -2853.3151, 60.8894, 0.0000, 0.0000, 18.2000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceShield1
    object_Schwarzmarkt[50] = CreateDynamicObject(19172, -1105.4870, -2853.8127, 60.7449, 0.0000, 9.6999, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_Schwarzmarkt[50], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    SetDynamicObjectMaterialText(object_Schwarzmarkt[50], 1, "Gefälschte", OBJECT_MATERIAL_SIZE_256x128, "Arial", 20, 1, 0xFF000000, 0x00000000, 1);
    object_Schwarzmarkt[51] = CreateDynamicObject(19086, -1098.0461, -2853.1354, 61.1770, 0.0000, 0.0000, -124.6995, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ChainsawDildo1
    object_Schwarzmarkt[52] = CreateDynamicObject(19941, -1099.5645, -2853.5551, 60.9275, 0.0000, 0.0000, -35.2999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
    object_Schwarzmarkt[53] = CreateDynamicObject(19941, -1099.5129, -2853.4826, 60.9275, 0.0000, 0.0000, -35.2999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
    object_Schwarzmarkt[54] = CreateDynamicObject(19941, -1099.4498, -2853.3940, 60.9275, 0.0000, 0.0000, -35.2999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
    object_Schwarzmarkt[55] = CreateDynamicObject(19941, -1099.5072, -2853.4746, 60.9675, 0.0000, 0.0000, 15.9999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
    object_Schwarzmarkt[56] = CreateDynamicObject(18075, -1101.2016, -2857.7453, 63.1564, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_Schwarzmarkt[57] = CreateDynamicObject(19792, -1105.7493, -2853.4892, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[58] = CreateDynamicObject(18637, -1099.2606, -2853.3151, 60.9294, 0.0000, 0.0000, 10.9000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceShield1
    object_Schwarzmarkt[59] = CreateDynamicObject(2190, -1101.4599, -2853.7614, 60.9015, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PC_1
    SetDynamicObjectMaterial(object_Schwarzmarkt[59], 2, 14654, "ab_trukstpe", "bbar_plates2", 0x00000000);
    object_Schwarzmarkt[60] = CreateDynamicObject(19792, -1105.7493, -2853.5493, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[61] = CreateDynamicObject(19792, -1105.7493, -2853.6093, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[62] = CreateDynamicObject(19792, -1105.7493, -2853.6794, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[63] = CreateDynamicObject(19792, -1105.7493, -2853.7395, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[64] = CreateDynamicObject(19792, -1105.6292, -2853.4892, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[65] = CreateDynamicObject(19792, -1105.6292, -2853.5493, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[66] = CreateDynamicObject(19792, -1105.6292, -2853.6193, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[67] = CreateDynamicObject(19792, -1105.6292, -2853.6894, 60.9346, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPKeycard1
    object_Schwarzmarkt[68] = CreateDynamicObject(330, -1105.4400, -2853.5739, 60.8988, 90.0000, 0.0000, -180.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cellphone
    object_Schwarzmarkt[69] = CreateDynamicObject(330, -1105.3499, -2853.5739, 60.8988, 90.0000, 0.0000, -166.8000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cellphone
    object_Schwarzmarkt[70] = CreateDynamicObject(330, -1105.2620, -2853.5537, 60.8988, 90.0000, 0.0000, -175.0002, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cellphone
    object_Schwarzmarkt[71] = CreateDynamicObject(18865, -1105.8950, -2853.7385, 60.9090, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MobilePhone1
    object_Schwarzmarkt[72] = CreateDynamicObject(18865, -1105.8950, -2853.4582, 60.9090, 0.0000, 0.0000, -8.9999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MobilePhone1
    object_Schwarzmarkt[73] = CreateDynamicObject(18873, -1105.2412, -2853.4228, 60.9092, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MobilePhone9
    object_Schwarzmarkt[74] = CreateDynamicObject(18873, -1105.2412, -2853.6330, 60.9092, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MobilePhone9
    object_Schwarzmarkt[75] = CreateDynamicObject(19422, -1104.3656, -2853.6137, 60.9160, 0.0000, 0.0000, -29.6000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones02
    object_Schwarzmarkt[76] = CreateDynamicObject(19422, -1104.1821, -2853.7133, 60.9160, 0.0000, 0.0000, -19.5000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones02
    object_Schwarzmarkt[77] = CreateDynamicObject(19422, -1104.1781, -2853.4577, 60.9160, 0.0000, 0.0000, -19.5000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones02
    object_Schwarzmarkt[78] = CreateDynamicObject(2894, -1102.1884, -2853.3115, 60.9176, 0.0000, 0.0000, 172.3998, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_Schwarzmarkt[78], 0, 14654, "ab_trukstpe", "bbar_plates2", 0x00000000);
    object_Schwarzmarkt[79] = CreateDynamicObject(19457, -1122.3381, -2856.8342, 60.0126, 0.0000, -90.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[79], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[80] = CreateDynamicObject(18980, -1127.3494, -2857.9912, 59.4876, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_Schwarzmarkt[80], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[81] = CreateDynamicObject(19457, -1141.5974, -2856.8342, 60.0126, 0.0000, -90.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[81], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[82] = CreateDynamicObject(19457, -1151.1995, -2856.8342, 60.0126, 0.0000, -90.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[82], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[83] = CreateDynamicObject(19457, -1160.8355, -2856.8342, 60.0126, 0.0000, -90.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[83], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[84] = CreateDynamicObject(19457, -1175.8803, -2849.0749, 60.0326, 0.0000, -90.0000, -138.8002, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[84], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[85] = CreateDynamicObject(19457, -1168.9899, -2854.6838, 60.0226, 0.0000, -90.0000, -119.4000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[85], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[86] = CreateDynamicObject(19457, -1112.7052, -2856.8342, 60.0126, 0.0000, -90.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[86], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[87] = CreateDynamicObject(18762, -1151.6882, -2851.6562, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[87], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[88] = CreateDynamicObject(18762, -1140.4190, -2851.6562, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[88], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[89] = CreateDynamicObject(18762, -1140.4190, -2856.6311, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[89], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[90] = CreateDynamicObject(18762, -1140.4190, -2861.6359, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[90], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[91] = CreateDynamicObject(18762, -1140.4190, -2865.6198, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[91], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[92] = CreateDynamicObject(18762, -1151.6882, -2856.6403, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[92], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[93] = CreateDynamicObject(18762, -1151.6882, -2861.6252, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[93], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[94] = CreateDynamicObject(18762, -1151.6882, -2865.6091, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[94], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[95] = CreateDynamicObject(18762, -1162.3521, -2851.6562, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[95], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[96] = CreateDynamicObject(18762, -1162.3521, -2856.6411, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[96], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[97] = CreateDynamicObject(18762, -1162.3521, -2861.6157, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[97], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[98] = CreateDynamicObject(18762, -1162.3521, -2865.5996, 59.1755, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[98], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[99] = CreateDynamicObject(18765, -1182.6577, -2849.4697, 50.2430, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[99], 0, 8391, "ballys01", "greyground256128", 0x00000000);
    object_Schwarzmarkt[100] = CreateDynamicObject(18765, -1182.6577, -2849.4697, 60.2529, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[100], 0, 8391, "ballys01", "greyground256128", 0x00000000);
    object_Schwarzmarkt[101] = CreateDynamicObject(19457, -1182.4055, -2846.3818, 60.0226, 0.0000, -90.0000, -86.1000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall097
    SetDynamicObjectMaterial(object_Schwarzmarkt[101], 0, 1717, "cj_tv", "CJ_STEEL", 0x00000000);
    object_Schwarzmarkt[102] = CreateDynamicObject(18980, -1174.9348, -2848.3918, 59.4876, 90.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_Schwarzmarkt[102], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    object_Schwarzmarkt[103] = CreateDynamicObject(19172, -1107.9594, -2857.0607, 62.7694, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_Schwarzmarkt[103], 0, "Terror | Schwarzmarkt", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_Schwarzmarkt[103], 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    object_Schwarzmarkt[104] = CreateDynamicObject(996, -1178.8433, -2848.0278, 60.7583, 0.0000, 0.0000, -49.0999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[105] = CreateDynamicObject(996, -1178.5578, -2844.5290, 60.7784, 0.0000, 0.0000, -177.5998, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[106] = CreateDynamicObject(996, -1172.5985, -2854.4816, 60.7583, 0.0000, 0.0000, -29.3000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[107] = CreateDynamicObject(996, -1164.9459, -2858.4250, 60.7583, 0.0000, 0.0000, -0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[108] = CreateDynamicObject(996, -1156.2438, -2858.4250, 60.7583, 0.0000, 0.0000, -0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[109] = CreateDynamicObject(996, -1147.6607, -2858.4450, 60.7583, 0.0000, 0.0000, -0.4000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[110] = CreateDynamicObject(996, -1138.9890, -2858.4851, 60.7583, 0.0000, 0.0000, -0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[111] = CreateDynamicObject(996, -1130.1983, -2858.4851, 60.7583, 0.0000, 0.0000, -0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[112] = CreateDynamicObject(996, -1121.2666, -2858.4851, 60.7583, 0.0000, 0.0000, -0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[113] = CreateDynamicObject(996, -1171.2852, -2851.5017, 60.7583, 0.0000, 0.0000, -29.3000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[114] = CreateDynamicObject(996, -1163.7064, -2855.1970, 60.7583, 0.0000, 0.0000, 0.2999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[115] = CreateDynamicObject(996, -1155.0147, -2855.1545, 60.7583, 0.0000, 0.0000, -0.4000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[116] = CreateDynamicObject(996, -1146.1741, -2855.2199, 60.7583, 0.0000, 0.0000, -0.4000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[117] = CreateDynamicObject(996, -1137.3498, -2855.1926, 60.7583, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[118] = CreateDynamicObject(996, -1128.5297, -2855.1926, 60.7583, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[119] = CreateDynamicObject(996, -1119.7048, -2855.1926, 60.7583, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[120] = CreateDynamicObject(19834, -1111.1910, -2855.2514, 60.8235, 0.0000, -14.4000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceLineTape1
    object_Schwarzmarkt[121] = CreateDynamicObject(997, -1113.5772, -2858.4907, 60.1433, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_Schwarzmarkt[122] = CreateDynamicObject(997, -1110.2640, -2855.1875, 60.1033, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_Schwarzmarkt[123] = CreateDynamicObject(997, -1110.2462, -2858.4907, 60.1433, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_Schwarzmarkt[124] = CreateDynamicObject(19834, -1111.1910, -2855.2714, 60.8235, 0.0000, 11.6999, 0.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PoliceLineTape1
    object_Schwarzmarkt[125] = CreateDynamicObject(996, -1177.2495, -2845.0734, 60.7784, 0.0000, 0.0000, -49.0999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_Schwarzmarkt[126] = CreateDynamicObject(18765, -1182.6577, -2849.4697, 40.2430, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
    SetDynamicObjectMaterial(object_Schwarzmarkt[126], 0, 8391, "ballys01", "greyground256128", 0x00000000);
    object_Schwarzmarkt[127] = CreateDynamicObject(14407, -1184.7955, -2846.8732, 63.3305, 0.0000, 0.0000, -89.3999, VW_MAIN, MAPS_SCHWARZMARKT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs01
    Schwarzmarkt_Actor[0] = CreateActor(146, -1098.9150, -2862.6140, 61.2534, 0.0000); //Crack Maker
    ApplyActorAnimation(Schwarzmarkt_Actor[0], "COP_AMBIENT", "COPLOOK_LOOP", 4.0999, 1, 0, 0, 0, 0);
    Schwarzmarkt_Actor[1] = CreateActor(179, -1101.9033, -2862.8227, 61.4835, 0.0000); //Ammunation Salesman
    ApplyActorAnimation(Schwarzmarkt_Actor[1], "COP_AMBIENT", "COPLOOK_LOOP", 4.0999, 1, 0, 0, 0, 0);
    Schwarzmarkt_Actor[2] = CreateActor(29, -1104.7207, -2862.8164, 61.7064, 0.0000); //Drug Dealer
    ApplyActorAnimation(Schwarzmarkt_Actor[2], "COP_AMBIENT", "COPLOOK_LOOP", 4.0999, 1, 0, 0, 0, 0);
    Schwarzmarkt_Actor[3] = CreateActor(266, -1096.4255, -2858.7048, 61.6728, 88.5999); //Officer Eddie Pulask
    ApplyActorAnimation(Schwarzmarkt_Actor[3], "COP_AMBIENT", "COPLOOK_LOOP", 4.0999, 1, 0, 0, 0, 0);
    Schwarzmarkt_Actor[4] = CreateActor(254, -1096.4591, -2855.7150, 61.7650, 86.8999); //Biker Drug Dealer
    ApplyActorAnimation(Schwarzmarkt_Actor[4], "COP_AMBIENT", "COPLOOK_LOOP", 4.0999, 1, 0, 0, 0, 0);
    Schwarzmarkt_Actor[5] = CreateActor(34, -1098.5789, -2852.5439, 61.3521, 178.8001); //Farm-Town inhabitant
    ApplyActorAnimation(Schwarzmarkt_Actor[5], "COP_AMBIENT", "COPLOOK_LOOP", 4.0999, 1, 0, 0, 0, 0);
    Schwarzmarkt_Actor[6] = CreateActor(289, -1104.8634, -2852.5781, 61.2924, 178.0993); //Zero
    ApplyActorAnimation(Schwarzmarkt_Actor[6], "COP_AMBIENT", "COPLOOK_LOOP", 4.0999, 1, 0, 0, 0, 0);
    Schwarzmarkt_Actor[7] = CreateActor(141, -1101.8408, -2852.7163, 61.6667, 173.8998); //Businesswoman
}