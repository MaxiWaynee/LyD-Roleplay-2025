#include <YSI\y_hooks>

// Global interior define
#define MAPS_PETSHOP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 160.0;
static Float:DRAWDISTANCE   = 150.0;

// Pet shop points
#define PETSHOP_COORDS  1805.2650, -1709.8883, 13.5630

// Map variables
new object_petShop[166];
new pickup_petShop[1];
new text3D_petShop[1];
new actor_petShop[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_petShop[0] = CreateDynamicPickup(1239, 1, PETSHOP_COORDS, VW_MAIN, MAPS_PETSHOP_INTERIOR); // Pet shop buy point
    
    // 3DTextLabels
    text3D_petShop[0] = _:CreateDynamic3DTextLabel("Tierhandel\n" COLOR_HEX_WHITE "Tippe /Haustiershop", COLOR_BLUE, PETSHOP_COORDS, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_PETSHOP_INTERIOR);
    
    // Actors
    actor_petShop[0] = CreateDynamicActor(233, 1805.9585, -1707.3210, 13.5630, 175.6588, .worldid = VW_MAIN, .interiorid = MAPS_PETSHOP_INTERIOR); // Pet shop saleswoman

    // Objects
    object_petShop[0] = CreateDynamicObject(19464, 1808.6805, -1721.7884, 13.7718, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[0], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    object_petShop[1] = CreateDynamicObject(19426, 1810.8774, -1717.0572, 17.1219, -90.0998, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[1], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[2] = CreateDynamicObject(19426, 1810.8774, -1706.5566, 17.1035, -90.0998, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[2], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[3] = CreateDynamicObject(19426, 1810.8850, -1720.4150, 17.1277, -90.0998, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[3], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[4] = CreateDynamicObject(19426, 1810.8774, -1713.5572, 17.1158, -90.0998, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[4], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[5] = CreateDynamicObject(19447, 1800.2652, -1717.3830, 17.6772, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[5], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[6] = CreateDynamicObject(19464, 1811.5405, -1707.5018, 13.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[6], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[7] = CreateDynamicObject(19464, 1811.5405, -1719.3625, 13.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[7], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[8] = CreateDynamicObject(19447, 1806.8293, -1716.9527, 17.8500, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[8], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_petShop[9] = CreateDynamicObject(19447, 1806.8293, -1710.0437, 17.6772, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[9], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[10] = CreateDynamicObject(19447, 1795.9720, -1706.6136, 12.4771, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[10], 0, 18022, "genintintfasta", "ceilingtile1_128", 0xFFFFFFFF);
    object_petShop[11] = CreateDynamicObject(19363, 1809.0660, -1718.2751, 14.3013, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_petShop[11], 0, 7367, "vegasnefnc", "ws_griddyfence_64", 0xFFFFFFFF);
    object_petShop[12] = CreateDynamicObject(19464, 1802.0902, -1704.9289, 15.0621, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[12], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[13] = CreateDynamicObject(19426, 1810.8774, -1710.0572, 17.1096, -90.0998, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[13], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[14] = CreateDynamicObject(19464, 1797.1256, -1706.9748, 15.0621, 0.0000, 0.0000, -45.0998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[14], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[15] = CreateDynamicObject(19464, 1808.6899, -1722.1978, 13.8017, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[15], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[16] = CreateDynamicObject(19363, 1809.0620, -1721.4548, 14.3013, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_petShop[16], 0, 7367, "vegasnefnc", "ws_griddyfence_64", 0xFFFFFFFF);
    object_petShop[17] = CreateDynamicObject(19363, 1809.0788, -1711.9145, 14.3013, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_petShop[17], 0, 7367, "vegasnefnc", "ws_griddyfence_64", 0xFFFFFFFF);
    object_petShop[18] = CreateDynamicObject(19464, 1799.0521, -1719.2309, 15.0621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[18], 0, 16639, "a51_labs", "a51_labwall1", 0xFFFFFFFF);
    object_petShop[19] = CreateDynamicObject(19363, 1807.5422, -1719.7866, 14.3013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_petShop[19], 0, 7367, "vegasnefnc", "ws_griddyfence_64", 0xFFFFFFFF);
    object_petShop[20] = CreateDynamicObject(19315, 1808.5423, -1720.5030, 13.1162, 0.0000, 0.0000, 132.6000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    SetDynamicObjectMaterial(object_petShop[20], 0, 14407, "carter_block", "zebra_skin", 0xFFFFFFFF);
    object_petShop[21] = CreateDynamicObject(840, 1809.4427, -1714.8540, 13.8500, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_12
    object_petShop[22] = CreateDynamicObject(19363, 1807.5422, -1713.4155, 14.3013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_petShop[22], 0, 7367, "vegasnefnc", "ws_griddyfence_64", 0xFFFFFFFF);
    object_petShop[23] = CreateDynamicObject(19447, 1806.8293, -1706.5533, 17.8572, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[23], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_petShop[24] = CreateDynamicObject(19447, 1806.8293, -1706.5533, 17.6772, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[24], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[25] = CreateDynamicObject(19447, 1800.2652, -1709.6223, 17.8553, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[25], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_petShop[26] = CreateDynamicObject(19447, 1806.8293, -1713.5340, 17.6772, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[26], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[27] = CreateDynamicObject(19447, 1800.2652, -1717.3830, 17.8572, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[27], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_petShop[28] = CreateDynamicObject(19447, 1809.1839, -1717.0832, 16.0550, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[28], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[29] = CreateDynamicObject(19447, 1806.8293, -1709.9829, 17.8551, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[29], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_petShop[30] = CreateDynamicObject(19447, 1806.8293, -1713.4726, 17.8572, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[30], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_petShop[31] = CreateDynamicObject(19447, 1809.2060, -1716.6429, 12.5551, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[31], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_petShop[32] = CreateDynamicObject(19447, 1806.8293, -1720.4525, 17.8572, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[32], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
    object_petShop[33] = CreateDynamicObject(19447, 1803.9885, -1720.5694, 12.4771, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[33], 0, 18022, "genintintfasta", "ceilingtile1_128", 0xFFFFFFFF);
    object_petShop[34] = CreateDynamicObject(19447, 1806.8293, -1720.4438, 17.6772, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[34], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[35] = CreateDynamicObject(19447, 1806.8293, -1717.0139, 17.6791, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[35], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[36] = CreateDynamicObject(19447, 1803.9787, -1717.0760, 12.4771, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[36], 0, 18022, "genintintfasta", "ceilingtile1_128", 0xFFFFFFFF);
    object_petShop[37] = CreateDynamicObject(19464, 1810.5893, -1713.4427, 13.7720, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[37], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    object_petShop[38] = CreateDynamicObject(19464, 1799.0521, -1708.0621, 15.0621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[38], 0, 16639, "a51_labs", "a51_labwall1", 0xFFFFFFFF);
    object_petShop[39] = CreateDynamicObject(19464, 1799.0500, -1713.9919, 15.0621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[39], 0, 16639, "a51_labs", "a51_labwall1", 0xFFFFFFFF);
    object_petShop[40] = CreateDynamicObject(19464, 1798.7917, -1719.2309, 15.0621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[40], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[41] = CreateDynamicObject(19464, 1811.5405, -1713.4327, 13.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[41], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[42] = CreateDynamicObject(19426, 1809.2043, -1722.0830, 17.1305, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[42], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[43] = CreateDynamicObject(19426, 1802.3581, -1722.0830, 17.1305, -90.0000, -90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[43], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[44] = CreateDynamicObject(19465, 1807.9990, -1704.9000, 15.0621, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_petShop[44], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[45] = CreateDynamicObject(19447, 1803.9692, -1713.5777, 12.4771, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[45], 0, 18022, "genintintfasta", "ceilingtile1_128", 0xFFFFFFFF);
    object_petShop[46] = CreateDynamicObject(19447, 1800.6662, -1722.1142, 12.7692, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[46], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[47] = CreateDynamicObject(19447, 1805.6007, -1710.0865, 12.4771, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[47], 0, 18022, "genintintfasta", "ceilingtile1_128", 0xFFFFFFFF);
    object_petShop[48] = CreateDynamicObject(19078, 1809.8612, -1716.6142, 15.2760, 13.3000, -89.5000, 91.0998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TheParrot1
    object_petShop[49] = CreateDynamicObject(19464, 1802.1102, -1705.1394, 15.0621, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[49], 0, 16639, "a51_labs", "a51_labwall1", 0xFFFFFFFF);
    object_petShop[50] = CreateDynamicObject(19447, 1805.5998, -1706.6135, 12.4771, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[50], 0, 18022, "genintintfasta", "ceilingtile1_128", 0xFFFFFFFF);
    object_petShop[51] = CreateDynamicObject(19447, 1795.9707, -1710.0865, 12.4771, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[51], 0, 18022, "genintintfasta", "ceilingtile1_128", 0xFFFFFFFF);
    object_petShop[52] = CreateDynamicObject(19363, 1807.5450, -1716.6257, 14.3013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_petShop[52], 0, 7367, "vegasnefnc", "ws_griddyfence_64", 0xFFFFFFFF);
    object_petShop[53] = CreateDynamicObject(19465, 1807.9990, -1705.1550, 15.0621, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(object_petShop[53], 0, 16639, "a51_labs", "a51_labwall1", 0xFFFFFFFF);
    object_petShop[54] = CreateDynamicObject(19464, 1810.5793, -1707.9422, 13.7720, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[54], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    object_petShop[55] = CreateDynamicObject(19464, 1810.5893, -1719.3227, 13.7720, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[55], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    object_petShop[56] = CreateDynamicObject(19412, 1808.8088, -1708.5206, 14.2959, 0.0000, 0.0000, -89.5000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall060
    object_petShop[57] = CreateDynamicObject(19363, 1809.0788, -1708.4432, 14.3013, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_petShop[57], 0, 7367, "vegasnefnc", "ws_griddyfence_64", 0xFFFFFFFF);
    object_petShop[58] = CreateDynamicObject(19412, 1808.8066, -1708.3404, 14.2959, 0.0000, 0.0000, -89.5000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall060
    object_petShop[59] = CreateDynamicObject(19366, 1805.7596, -1708.3613, 11.9343, 0.0000, 0.0000, -89.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
    object_petShop[60] = CreateDynamicObject(19363, 1807.5422, -1710.2253, 14.3013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_petShop[60], 0, 7367, "vegasnefnc", "ws_griddyfence_64", 0xFFFFFFFF);
    object_petShop[61] = CreateDynamicObject(19447, 1800.6662, -1721.9342, 12.7692, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[61], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[62] = CreateDynamicObject(19464, 1808.6805, -1721.5382, 13.7718, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[62], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    object_petShop[63] = CreateDynamicObject(19366, 1805.7596, -1708.5312, 11.9343, 0.0000, 0.0000, -89.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
    object_petShop[64] = CreateDynamicObject(1215, 1805.7364, -1722.1790, 12.4989, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_petShop[65] = CreateDynamicObject(19426, 1805.4680, -1708.4697, 13.6042, -0.1000, -90.0000, 0.2000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[65], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_petShop[66] = CreateDynamicObject(19464, 1811.5405, -1701.5720, 13.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[66], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[67] = CreateDynamicObject(19464, 1811.5405, -1695.6428, 13.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[67], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[68] = CreateDynamicObject(19464, 1811.5389, -1689.3730, 13.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[68], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[69] = CreateDynamicObject(1885, 1804.0854, -1708.9466, 12.5492, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_baskets
    object_petShop[70] = CreateDynamicObject(19464, 1811.5405, -1689.7132, 13.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[70], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[71] = CreateDynamicObject(1959, 1804.8790, -1708.1916, 13.6716, 0.0000, 0.0000, 179.4998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_till
    object_petShop[72] = CreateDynamicObject(19464, 1796.8613, -1686.1850, 13.7917, 0.0000, 0.0000, 89.5998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[72], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[73] = CreateDynamicObject(19464, 1808.7010, -1686.2572, 13.7917, 0.0000, 0.0000, 89.5998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[73], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[74] = CreateDynamicObject(2164, 1810.4532, -1706.3032, 12.5452, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    object_petShop[75] = CreateDynamicObject(19464, 1802.7906, -1686.2164, 13.7917, 0.0000, 0.0000, 89.5998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[75], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[76] = CreateDynamicObject(19464, 1790.9515, -1686.1440, 13.7819, 0.0000, 0.0000, 89.5998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[76], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[77] = CreateDynamicObject(19439, 1802.0268, -1722.1186, 18.3903, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall079
    SetDynamicObjectMaterial(object_petShop[77], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_petShop[78] = CreateDynamicObject(19464, 1796.8613, -1686.1850, 13.7917, 0.0000, 0.0000, 89.5998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[78], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[79] = CreateDynamicObject(19439, 1805.5179, -1722.1186, 18.3903, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall079
    SetDynamicObjectMaterial(object_petShop[79], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_petShop[80] = CreateDynamicObject(2894, 1804.1634, -1708.7895, 13.6862, 0.0000, 0.0000, -35.2999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_petShop[80], 0, 2543, "cj_ss_3", "CJ_DOG_FOOD2", 0xFFFFFFFF);
    object_petShop[81] = CreateDynamicObject(19172, 1802.8767, -1705.2685, 15.3409, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterial(object_petShop[81], 0, 6357, "sunstrans_law2", "dogbill01", 0xFFFFFFFF);
    object_petShop[82] = CreateDynamicObject(19464, 1785.0223, -1686.1030, 13.7819, 0.0000, 0.0000, 89.5998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[82], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[83] = CreateDynamicObject(19172, 1805.0727, -1722.2225, 18.1791, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_petShop[83], 0,"laden", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_petShop[83], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_petShop[84] = CreateDynamicObject(19464, 1779.0926, -1686.0620, 13.7819, 0.0000, 0.0000, 89.5998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[84], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[85] = CreateDynamicObject(19464, 1773.1627, -1686.0511, 13.7819, 0.0000, 0.0000, 90.0998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[85], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[86] = CreateDynamicObject(19464, 1767.2425, -1686.0705, 13.7819, 0.0000, 0.0000, 90.1996, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[86], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[87] = CreateDynamicObject(19172, 1803.6717, -1722.2225, 18.1791, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_petShop[87], 0,"Tier", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_petShop[87], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_petShop[88] = CreateDynamicObject(1843, 1799.7104, -1717.2657, 12.3936, 0.0000, 0.0000, 89.9999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf02
    SetDynamicObjectMaterial(object_petShop[88], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    object_petShop[89] = CreateDynamicObject(1843, 1799.7104, -1714.2563, 12.3936, 0.0000, 0.0000, 89.9999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf02
    SetDynamicObjectMaterial(object_petShop[89], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    object_petShop[90] = CreateDynamicObject(1601, 1801.8269, -1717.0185, 13.0572, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fish3s
    object_petShop[91] = CreateDynamicObject(19464, 1763.8620, -1686.0815, 13.7819, 0.0000, 0.0000, 90.1996, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[91], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[92] = CreateDynamicObject(1344, 1797.5295, -1704.8785, 13.2842, 0.0000, 0.0000, -179.8000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster2
    object_petShop[93] = CreateDynamicObject(1491, 1808.7679, -1704.8618, 12.5254, 0.0000, 0.0000, 179.6999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(object_petShop[93], 0, 14666, "genintintsex", "backdoor_128", 0xFFFFFFFF);
    object_petShop[94] = CreateDynamicObject(1600, 1802.7375, -1718.1810, 12.8493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fish2single
    object_petShop[95] = CreateDynamicObject(1842, 1802.1252, -1714.0494, 12.2901, 0.0000, 0.0000, -89.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf05
    SetDynamicObjectMaterial(object_petShop[95], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_petShop[95], 1, 3474, "freightcrane", "bluecab4_256", 0xFFFFFFFF);
    object_petShop[96] = CreateDynamicObject(1842, 1802.1312, -1717.2794, 12.2901, 0.0000, 0.0000, -89.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf05
    SetDynamicObjectMaterial(object_petShop[96], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_petShop[96], 1, 3474, "freightcrane", "bluecab4_256", 0xFFFFFFFF);
    object_petShop[97] = CreateDynamicObject(19560, 1805.2629, -1709.0378, 13.6871, -3.0999, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MeatTray1
    object_petShop[98] = CreateDynamicObject(1842, 1802.1312, -1717.2794, 13.0101, 0.0000, 0.0000, -89.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf05
    SetDynamicObjectMaterial(object_petShop[98], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_petShop[98], 1, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[99] = CreateDynamicObject(1600, 1802.6761, -1717.6214, 12.8493, 0.0000, 0.0000, 173.6000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fish2single
    object_petShop[100] = CreateDynamicObject(19315, 1809.2115, -1710.9111, 13.0418, 0.0000, 0.0000, 137.6000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_petShop[101] = CreateDynamicObject(1599, 1801.6999, -1718.2696, 12.9326, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fish1single
    object_petShop[102] = CreateDynamicObject(1599, 1802.3304, -1717.1794, 12.9326, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fish1single
    object_petShop[103] = CreateDynamicObject(1233, 1806.3552, -1722.3000, 13.4847, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //noparkingsign1
    object_petShop[104] = CreateDynamicObject(19315, 1808.8833, -1709.7445, 13.0418, 0.0000, 0.0000, -143.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_petShop[105] = CreateDynamicObject(19315, 1808.7185, -1710.4348, 13.0418, 0.0000, 0.1999, 169.5000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_petShop[106] = CreateDynamicObject(997, 1807.4438, -1701.4332, 12.5289, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_petShop[107] = CreateDynamicObject(997, 1804.2336, -1701.4332, 12.5289, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_petShop[108] = CreateDynamicObject(997, 1801.0433, -1701.4332, 12.5289, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_petShop[109] = CreateDynamicObject(8041, 1762.9864, -1696.1842, 18.0226, 0.0000, 0.0000, 179.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //apbarriergate06_lvS
    object_petShop[110] = CreateDynamicObject(968, 1763.5504, -1688.0284, 13.3774, 0.0000, -20.5998, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //barrierturn
    object_petShop[111] = CreateDynamicObject(968, 1763.3608, -1704.4477, 13.5146, 0.0000, -20.5998, -88.9000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //barrierturn
    object_petShop[112] = CreateDynamicObject(1663, 1762.5694, -1695.8457, 12.8509, 0.0000, 0.0000, 23.1998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_B
    object_petShop[113] = CreateDynamicObject(2599, 1800.6146, -1723.9604, 12.9870, 0.0000, 0.0000, -87.2997, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SEX_SHOP_SIGN
    SetDynamicObjectMaterial(object_petShop[113], 0, 2543, "cj_ss_3", "CJ_DOOG_FOOD", 0xFFFFFFFF);
    object_petShop[114] = CreateDynamicObject(1842, 1802.1251, -1714.0495, 13.0101, 0.0000, 0.0000, -89.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf05
    SetDynamicObjectMaterial(object_petShop[114], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_petShop[114], 1, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[115] = CreateDynamicObject(1603, 1801.4730, -1713.6312, 13.2614, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //jellyfish01
    object_petShop[116] = CreateDynamicObject(19630, 1801.8835, -1712.8114, 13.0412, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Fish1
    object_petShop[117] = CreateDynamicObject(1602, 1802.3828, -1713.0410, 13.1913, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //jellyfish
    object_petShop[118] = CreateDynamicObject(1602, 1801.5118, -1714.9903, 13.1913, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //jellyfish
    object_petShop[119] = CreateDynamicObject(1603, 1802.0571, -1714.3155, 13.2722, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //jellyfish01
    object_petShop[120] = CreateDynamicObject(19315, 1808.1451, -1719.3326, 13.1162, 0.0000, 0.0000, 44.7999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    SetDynamicObjectMaterial(object_petShop[120], 0, 14407, "carter_block", "zebra_skin", 0xFFFFFFFF);
    object_petShop[121] = CreateDynamicObject(19315, 1809.5310, -1719.3658, 13.1162, 0.0000, 0.0000, -156.1999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    SetDynamicObjectMaterial(object_petShop[121], 0, 14407, "carter_block", "zebra_skin", 0xFFFFFFFF);
    object_petShop[122] = CreateDynamicObject(19078, 1809.4062, -1717.1672, 15.2643, -4.8997, -89.5000, 71.2997, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TheParrot1
    object_petShop[123] = CreateDynamicObject(19078, 1809.6186, -1716.0467, 12.9221, -4.8997, -89.5000, 71.2997, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TheParrot1
    object_petShop[124] = CreateDynamicObject(19078, 1808.9193, -1716.6048, 12.9139, -2.4999, -88.3000, 109.4000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TheParrot1
    object_petShop[125] = CreateDynamicObject(19078, 1809.8088, -1715.3293, 14.5305, -2.4999, -88.3000, -95.0998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TheParrot1
    object_petShop[126] = CreateDynamicObject(19078, 1809.3846, -1712.9731, 13.0663, -2.4999, -88.3000, -59.5000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TheParrot1
    object_petShop[127] = CreateDynamicObject(1344, 1795.2403, -1704.8863, 13.2842, 0.0000, 0.0000, -179.8000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster2
    object_petShop[128] = CreateDynamicObject(1344, 1792.9403, -1704.8946, 13.2842, 0.0000, 0.0000, -179.8000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster2
    object_petShop[129] = CreateDynamicObject(1430, 1791.3408, -1704.8891, 12.8344, 0.0000, 0.0000, -179.5997, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dump1_LOW01
    object_petShop[130] = CreateDynamicObject(2777, 1799.5775, -1709.1970, 13.0447, 0.0000, 0.0000, 89.3999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR1
    object_petShop[131] = CreateDynamicObject(2777, 1799.5842, -1708.4973, 13.0447, 0.0000, 0.0000, 89.3999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR1
    object_petShop[132] = CreateDynamicObject(2777, 1799.5914, -1707.8270, 13.0447, 0.0000, 0.0000, 89.3999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR1
    object_petShop[133] = CreateDynamicObject(2777, 1799.5981, -1707.1666, 13.0447, 0.0000, 0.0000, 89.3999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LEE_stripCHAIR1
    object_petShop[134] = CreateDynamicObject(2002, 1800.0615, -1705.8282, 12.5496, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
    object_petShop[135] = CreateDynamicObject(19447, 1800.2652, -1709.6223, 17.6753, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[135], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[136] = CreateDynamicObject(19447, 1809.1850, -1713.1335, 16.0552, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_petShop[136], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
    object_petShop[137] = CreateDynamicObject(18980, 1801.9433, -1721.6999, 3.8396, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_petShop[137], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_petShop[138] = CreateDynamicObject(19426, 1805.7756, -1722.0885, 17.1305, -90.0998, -90.3000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_petShop[138], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_petShop[139] = CreateDynamicObject(19464, 1808.6805, -1722.0385, 13.7718, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_petShop[139], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    object_petShop[140] = CreateDynamicObject(19174, 1799.1853, -1715.7535, 15.5387, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    object_petShop[141] = CreateDynamicObject(19425, 1761.0500, -1701.8409, 12.4010, 0.0000, 0.0000, -90.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_petShop[142] = CreateDynamicObject(19425, 1761.1020, -1698.5511, 12.4010, 0.0000, 0.0000, -90.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_petShop[143] = CreateDynamicObject(19425, 1761.2258, -1690.6219, 12.4010, 0.0000, 0.0000, -90.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_petShop[144] = CreateDynamicObject(19425, 1761.1738, -1693.9315, 12.4010, 0.0000, 0.0000, -90.8999, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_petShop[145] = CreateDynamicObject(3850, 1799.6809, -1727.1037, 13.0165, 0.0000, 0.0000, -89.7997, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
    object_petShop[146] = CreateDynamicObject(3850, 1803.1107, -1727.0927, 13.0165, 0.0000, 0.0000, -89.7997, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
    object_petShop[147] = CreateDynamicObject(3850, 1806.5607, -1727.0797, 13.0165, 0.0000, 0.0000, -89.7997, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
    object_petShop[148] = CreateDynamicObject(3850, 1809.9914, -1727.0673, 13.0165, 0.0000, 0.0000, -89.7997, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
    object_petShop[149] = CreateDynamicObject(1893, 1807.6778, -1715.0830, 17.8271, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_petShop[150] = CreateDynamicObject(1893, 1807.6778, -1719.5129, 17.8271, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_petShop[151] = CreateDynamicObject(1893, 1807.6778, -1710.3835, 17.8271, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_petShop[152] = CreateDynamicObject(1893, 1801.5775, -1715.0830, 17.8271, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_petShop[153] = CreateDynamicObject(1893, 1801.5775, -1714.0725, 17.8271, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_petShop[154] = CreateDynamicObject(1893, 1801.5775, -1716.4820, 17.8271, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_petShop[155] = CreateDynamicObject(1893, 1801.5775, -1717.4028, 17.8271, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_petShop[156] = CreateDynamicObject(921, 1808.0572, -1704.9289, 15.7832, 0.0000, 0.0000, 179.9998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_IND_LIGHT
    object_petShop[157] = CreateDynamicObject(1615, 1806.6512, -1704.8392, 17.2432, 0.0000, 0.0000, -90.1998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_alarm2_01
    object_petShop[158] = CreateDynamicObject(1215, 1802.3873, -1722.0791, 12.4989, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_petShop[159] = CreateDynamicObject(638, 1807.0776, -1722.6518, 13.1953, 0.0000, 0.0000, -90.1998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_petShop[160] = CreateDynamicObject(638, 1800.4969, -1722.5504, 13.1953, 0.0000, 0.0000, -90.1998, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_petShop[161] = CreateDynamicObject(1688, 1802.6910, -1719.0550, 18.8980, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit2
    object_petShop[162] = CreateDynamicObject(1688, 1802.6910, -1709.0351, 18.8980, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit2
    object_petShop[163] = CreateDynamicObject(1695, 1806.9415, -1713.5655, 18.4080, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roofstuff14
    object_petShop[164] = CreateDynamicObject(1691, 1810.3314, -1713.7893, 18.1280, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit5
    object_petShop[165] = CreateDynamicObject(18980, 1806.2031, -1721.8122, 3.8396, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_PETSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_petShop[165], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
}
