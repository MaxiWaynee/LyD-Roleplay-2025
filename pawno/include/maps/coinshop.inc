#include <YSI\y_hooks>

#define COINSHOP_INTERIOR 0
#define COINSHOP_COORDS 1294.0477,-1873.0203,14.2669

static Float:STREAMDISTANCE = 250.0;
static Float:DRAWDISTANCE   = 250.0;

new Coinshop_Map[80];
new Coinshop_Actor[1];

hook OnGameModeInit()
{
    CreateDynamicPickup(1274, 1, COINSHOP_COORDS, VW_MAIN, COINSHOP_INTERIOR);
    CreateDynamic3DTextLabel("{118546}[LyD-Coinshop]\n{FFFFFF}Tippe /Coinshop", COLOR_WHITE, COINSHOP_COORDS , 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = COINSHOP_INTERIOR);

    Coinshop_Map[0] = CreateDynamicObject(2321, 1292.0819, -1873.8618, 13.2981, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE6
    Coinshop_Map[1] = CreateDynamicObject(19448, 1291.5544, -1871.6904, 15.0165, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall088
    SetDynamicObjectMaterial(Coinshop_Map[1], 0, 3314, "ce_burbhouse", "sw_wallbrick_06", 0x00000000);
    Coinshop_Map[2] = CreateDynamicObject(19790, 1296.6357, -1868.2862, 7.9628, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube5mx5m
    SetDynamicObjectMaterial(Coinshop_Map[2], 0, 13007, "sw_bankint", "woodfloor1", 0x00000000);
    Coinshop_Map[3] = CreateDynamicObject(19448, 1301.0150, -1871.7004, 15.0165, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall088
    SetDynamicObjectMaterial(Coinshop_Map[3], 0, 3314, "ce_burbhouse", "sw_wallbrick_06", 0x00000000);
    Coinshop_Map[4] = CreateDynamicObject(2244, 1297.4492, -1867.3725, 13.5305, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_9
    Coinshop_Map[5] = CreateDynamicObject(19394, 1296.2795, -1867.8537, 14.9842, 0.0000, 0.0000, 90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall042
    SetDynamicObjectMaterial(Coinshop_Map[5], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    Coinshop_Map[6] = CreateDynamicObject(19448, 1296.2845, -1876.4305, 15.0165, 0.0000, 0.0000, 90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall088
    SetDynamicObjectMaterial(Coinshop_Map[6], 0, 3314, "ce_burbhouse", "sw_wallbrick_06", 0x00000000);
    Coinshop_Map[7] = CreateDynamicObject(19353, 1299.4117, -1867.4139, 14.9979, 0.0000, 0.0000, -75.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
    SetDynamicObjectMaterial(Coinshop_Map[7], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    Coinshop_Map[8] = CreateDynamicObject(19353, 1293.1579, -1867.4256, 14.9778, 0.0000, 0.0000, -105.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
    SetDynamicObjectMaterial(Coinshop_Map[8], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    Coinshop_Map[9] = CreateDynamicObject(19448, 1299.7275, -1871.6202, 16.8467, 0.0000, 90.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall088
    SetDynamicObjectMaterial(Coinshop_Map[9], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    Coinshop_Map[10] = CreateDynamicObject(2244, 1295.0782, -1867.3725, 13.5305, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_9
    Coinshop_Map[11] = CreateDynamicObject(19790, 1298.8103, -1869.3503, 8.2669, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube5mx5m
    SetDynamicObjectMaterial(Coinshop_Map[11], 0, 13007, "sw_bankint", "woodfloor1", 0x00000000);
    Coinshop_Map[12] = CreateDynamicObject(19448, 1292.7467, -1871.6202, 16.8467, 0.0000, 90.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall088
    SetDynamicObjectMaterial(Coinshop_Map[12], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    Coinshop_Map[13] = CreateDynamicObject(19790, 1293.8188, -1869.3503, 8.2669, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube5mx5m
    SetDynamicObjectMaterial(Coinshop_Map[13], 0, 13007, "sw_bankint", "woodfloor1", 0x00000000);
    Coinshop_Map[14] = CreateDynamicObject(19790, 1293.8288, -1874.3518, 8.2669, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube5mx5m
    SetDynamicObjectMaterial(Coinshop_Map[14], 0, 13007, "sw_bankint", "woodfloor1", 0x00000000);
    Coinshop_Map[15] = CreateDynamicObject(19790, 1298.8188, -1874.3518, 8.2669, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube5mx5m
    SetDynamicObjectMaterial(Coinshop_Map[15], 0, 13007, "sw_bankint", "woodfloor1", 0x00000000);
    Coinshop_Map[16] = CreateDynamicObject(19448, 1296.2368, -1871.6202, 16.8467, 0.0000, 90.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall088
    SetDynamicObjectMaterial(Coinshop_Map[16], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    SetDynamicObjectMaterial(Coinshop_Map[16], 1, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    Coinshop_Map[17] = CreateDynamicObject(2321, 1292.0819, -1873.8618, 13.7783, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE6
    Coinshop_Map[18] = CreateDynamicObject(2321, 1294.4831, -1873.8618, 13.7783, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE6
    Coinshop_Map[19] = CreateDynamicObject(2321, 1294.4831, -1873.8618, 13.2981, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE6
    Coinshop_Map[20] = CreateDynamicObject(912, 1300.4040, -1870.9327, 13.8304, 0.0000, 0.0000, -90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BUST_CABINET_2
    Coinshop_Map[21] = CreateDynamicObject(912, 1300.4040, -1872.4630, 13.8304, 0.0000, 0.0000, -90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BUST_CABINET_2
    Coinshop_Map[22] = CreateDynamicObject(912, 1300.4040, -1873.9829, 13.8304, 0.0000, 0.0000, -90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BUST_CABINET_2
    Coinshop_Map[23] = CreateDynamicObject(19355, 1295.7856, -1876.4145, 15.4869, 0.0000, 0.0000, -90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
    SetDynamicObjectMaterialText(Coinshop_Map[23], 0, "- COINSHOP -", OBJECT_MATERIAL_SIZE_256x128, "Trebuchet MS", 28, 1, 0xFF000080, 0x00000000, 1);
    Coinshop_Map[24] = CreateDynamicObject(19355, 1295.7856, -1876.4145, 16.2868, 0.0000, 0.0000, -90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
    SetDynamicObjectMaterialText(Coinshop_Map[24], 0, "Live your Dream", OBJECT_MATERIAL_SIZE_256x128, "Trebuchet MS", 28, 1, 0xFF0000FF, 0x00000000, 1);
    Coinshop_Map[25] = CreateDynamicObject(19167, 1296.1169, -1873.8697, 14.2868, 0.0000, 0.0000, 43.0998, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap4
    Coinshop_Map[26] = CreateDynamicObject(1550, 1292.0605, -1873.9460, 14.3964, 1.8997, 79.0000, 14.6000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    Coinshop_Map[27] = CreateDynamicObject(3802, 1299.0968, -1875.6422, 15.8268, 0.0000, 0.0000, 90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    Coinshop_Map[28] = CreateDynamicObject(18066, 1294.0517, -1873.3741, 13.8002, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //posterv
    Coinshop_Map[29] = CreateDynamicObject(18066, 1292.5306, -1873.3741, 13.8002, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //posterv
    Coinshop_Map[30] = CreateDynamicObject(1514, 1294.8089, -1873.9012, 14.5123, 0.0000, 0.0000, 180.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_FF_TILL
    Coinshop_Map[31] = CreateDynamicObject(2722, 1321.6645, -1740.7678, 15.0928, 0.0000, 0.0000, -135.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BANNER18
    SetDynamicObjectMaterialText(Coinshop_Map[31], 0, "LyD - Coinshop", OBJECT_MATERIAL_SIZE_256x128, "Arial", 35, 1, 0xFFFFFFFF, 0x00000000, 1);
    Coinshop_Map[32] = CreateDynamicObject(1550, 1291.8767, -1876.1086, 13.6183, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    Coinshop_Map[33] = CreateDynamicObject(1550, 1292.0268, -1875.6081, 13.6183, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    Coinshop_Map[34] = CreateDynamicObject(1550, 1292.4172, -1876.0185, 13.6183, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    Coinshop_Map[35] = CreateDynamicObject(19329, 1295.6279, -1873.3266, 13.8067, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign04
    SetDynamicObjectMaterialText(Coinshop_Map[35], 0, "TAKE!", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFF0000FF, 0x00000000, 1);
    Coinshop_Map[36] = CreateDynamicObject(2714, 1298.5876, -1867.5594, 15.6589, 0.0000, 0.0000, -163.2998, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_OPEN_SIGN_2
    Coinshop_Map[37] = CreateDynamicObject(3802, 1293.0052, -1875.6922, 15.8268, 0.0000, 0.0000, 90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    Coinshop_Map[38] = CreateDynamicObject(3335, 1321.5378, -1741.1395, 12.6162, 0.0000, 0.0000, -135.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CE_roadsign1
    Coinshop_Map[39] = CreateDynamicObject(1364, 1288.3453, -1864.6048, 13.3697, 0.0000, 0.0000, 90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP
    Coinshop_Map[40] = CreateDynamicObject(1364, 1304.0456, -1864.6048, 13.3697, 0.0000, 0.0000, -90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP
    Coinshop_Map[41] = CreateDynamicObject(2722, 1321.6645, -1740.7678, 14.6728, 0.0000, 0.0000, -135.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BANNER18
    SetDynamicObjectMaterialText(Coinshop_Map[41], 0, "50m ->", OBJECT_MATERIAL_SIZE_256x128, "Arial", 35, 1, 0xFFFFFFFF, 0x00000000, 1);
    Coinshop_Map[42] = CreateDynamicObject(1661, 1296.2602, -1870.9516, 16.4193, 0.0000, 0.0000, 20.3999, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //htl_fan_rotate_dy
    Coinshop_Map[43] = CreateDynamicObject(1550, 1300.6479, -1867.5268, 13.6183, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    Coinshop_Map[44] = CreateDynamicObject(1736, 1300.5876, -1872.3896, 15.9884, 0.0000, 0.0000, -90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Stags_head
    Coinshop_Map[45] = CreateDynamicObject(1518, 1300.4204, -1870.6756, 14.6799, 0.0000, 0.0000, -51.2999, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_TV_2
    Coinshop_Map[46] = CreateDynamicObject(11737, 1296.2358, -1867.8363, 13.2600, 0.0000, 0.0000, 180.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RockstarMat1
    Coinshop_Map[47] = CreateDynamicObject(1550, 1300.1175, -1867.6568, 13.6183, 0.0000, 0.0000, 39.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    Coinshop_Map[48] = CreateDynamicObject(1550, 1300.6562, -1868.2751, 13.6183, 0.0000, 0.0000, 39.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    Coinshop_Map[49] = CreateDynamicObject(19165, 1291.6444, -1871.1156, 15.4370, 90.0000, 90.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap2
    Coinshop_Map[50] = CreateDynamicObject(1704, 1292.5273, -1868.6131, 13.2608, 0.0000, 0.0000, 50.5000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair03
    Coinshop_Map[51] = CreateDynamicObject(1704, 1292.3105, -1870.0913, 13.2608, 0.0000, 0.0000, 90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_chair03
    Coinshop_Map[52] = CreateDynamicObject(1820, 1293.1673, -1869.9416, 13.2707, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_LOW_4
    Coinshop_Map[53] = CreateDynamicObject(2363, 1299.1499, -1874.8009, 13.2025, 0.0000, 0.0000, 24.7000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SHOP_SIGN_1
    SetDynamicObjectMaterial(Coinshop_Map[53], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    Coinshop_Map[54] = CreateDynamicObject(19969, 1289.3883, -1862.4886, 12.0859, 0.0000, 0.0000, -180.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign22
    Coinshop_Map[55] = CreateDynamicObject(19969, 1303.3995, -1862.4886, 12.0859, 0.0000, 0.0000, -180.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign22
    Coinshop_Map[56] = CreateDynamicObject(19086, 1300.2851, -1871.3691, 14.2669, 0.0000, 0.0000, 78.0998, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ChainsawDildo1
    Coinshop_Map[57] = CreateDynamicObject(2253, 1297.9272, -1867.1252, 13.5094, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_22
    Coinshop_Map[58] = CreateDynamicObject(2253, 1294.6059, -1867.1252, 13.5297, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_22
    Coinshop_Map[59] = CreateDynamicObject(640, 1301.8343, -1870.3708, 13.2334, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    Coinshop_Map[60] = CreateDynamicObject(640, 1290.8127, -1870.3708, 13.2334, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    Coinshop_Map[61] = CreateDynamicObject(19329, 1294.0267, -1873.3266, 13.8067, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign04
    SetDynamicObjectMaterialText(Coinshop_Map[61], 0, "MY!", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFF0000, 0x00000000, 1);
    Coinshop_Map[62] = CreateDynamicObject(18066, 1295.6008, -1873.3741, 13.8002, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //posterv
    Coinshop_Map[63] = CreateDynamicObject(2364, 1299.0799, -1868.0433, 13.2737, 0.0000, 0.0000, 16.9999, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SHOP_SIGN_2
    Coinshop_Map[64] = CreateDynamicObject(19329, 1292.5257, -1873.3266, 13.8067, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign04
    SetDynamicObjectMaterialText(Coinshop_Map[64], 0, "MONEY!", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFF006400, 0x00000000, 1);
    Coinshop_Map[65] = CreateDynamicObject(1846, 1295.7834, -1875.3625, 15.8169, 90.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf04
    Coinshop_Map[66] = CreateDynamicObject(3035, 1293.0402, -1877.4414, 13.2959, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tmp_bin
    Coinshop_Map[67] = CreateDynamicObject(19329, 1299.0151, -1868.2238, 14.0268, 0.0000, 0.0000, 15.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign04
    SetDynamicObjectMaterialText(Coinshop_Map[67], 0, "LyD", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFF8B008B, 0x00000000, 1);
    Coinshop_Map[68] = CreateDynamicObject(1665, 1293.4542, -1869.3808, 13.7894, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propashtray1
    Coinshop_Map[69] = CreateDynamicObject(19329, 1299.0173, -1868.2231, 13.7267, 0.0000, 0.0000, 16.9999, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign04
    SetDynamicObjectMaterialText(Coinshop_Map[69], 0, " ", OBJECT_MATERIAL_SIZE_256x128, "Arial", 15, 1, 0xFFF8F8FF, 0x00000000, 1);
    Coinshop_Map[70] = CreateDynamicObject(19136, 1294.0871, -1874.7934, 15.0332, 9.9999, -85.8001, -1.2000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Hair4
    Coinshop_Map[71] = CreateDynamicObject(19329, 1299.0170, -1874.9522, 13.9460, 14.5999, 0.0000, 25.5000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign04
    SetDynamicObjectMaterialText(Coinshop_Map[71], 0, "LyD", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFF0F5, 0x00000000, 1);
    Coinshop_Map[72] = CreateDynamicObject(19329, 1298.9739, -1874.9082, 13.7645, 14.5999, -0.5000, 24.8000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign04
    SetDynamicObjectMaterialText(Coinshop_Map[72], 0, "Stammkunde", OBJECT_MATERIAL_SIZE_256x128, "Arial", 14, 1, 0xFFAFEEEE, 0x00000000, 1);
    Coinshop_Map[73] = CreateDynamicObject(19329, 1298.9555, -1874.8641, 13.5806, 14.5999, -0.5000, 24.8000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //7_11_sign04
    SetDynamicObjectMaterialText(Coinshop_Map[73], 0, "Samuel<3", OBJECT_MATERIAL_SIZE_256x128, "Arial", 14, 1, 0xFFAFEEEE, 0x00000000, 1);
    Coinshop_Map[74] = CreateDynamicObject(2690, 1300.6907, -1873.9050, 14.7632, 0.0000, 0.0000, 173.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FIRE_EXT
    Coinshop_Map[75] = CreateDynamicObject(2690, 1300.6480, -1874.2525, 14.7632, 0.0000, 0.0000, 173.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FIRE_EXT
    Coinshop_Map[76] = CreateDynamicObject(1242, 1300.5434, -1872.9255, 14.5638, 0.0000, 0.0000, 90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bodyarmour
    Coinshop_Map[77] = CreateDynamicObject(1242, 1300.5434, -1872.6157, 14.5638, 0.0000, 0.0000, 90.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bodyarmour
    Coinshop_Map[78] = CreateDynamicObject(349, 1300.2691, -1872.6687, 14.3762, 67.7002, -2.0000, 93.5000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chromegun
    Coinshop_Map[79] = CreateDynamicObject(1450, 1295.0770, -1877.2355, 13.1231, 0.0000, 0.0000, 0.0000, VW_MAIN, COINSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_CRATE_3

    Coinshop_Actor[0] = CreateDynamicActor(5, 1294.0810, -1874.8568, 14.2669, 0.0000, .worldid = VW_MAIN, .interiorid = COINSHOP_INTERIOR,.streamdistance = STREAMDISTANCE); //Barry "Big Bear" Tho
    return 1;
}