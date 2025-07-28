#include <YSI\y_hooks>

// Global interior define
#define WEAPONFABRIKINSEL      0
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

new wfabrikinsel_object[146];
//new g_Vehicle[1];
new wfabrikinsel_Actor[3];

hook OnGameModeInit() {
    wfabrikinsel_object[0] = CreateDynamicObject(3799, 262.1720, 3302.3828, 9.3549, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox2_SFS
    wfabrikinsel_object[1] = CreateDynamicObject(3533, 247.5066, 3286.8906, 4.4299, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[1], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[2] = CreateDynamicObject(3533, 247.5066, 3286.8906, -4.3597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[2], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[3] = CreateDynamicObject(3533, 247.5066, 3286.8906, -13.1798, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[3], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[4] = CreateDynamicObject(3533, 247.5066, 3286.8906, -22.1597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[4], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[5] = CreateDynamicObject(3533, 247.5066, 3286.8906, -31.0498, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[5], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[6] = CreateDynamicObject(3533, 247.5066, 3286.8906, -40.0297, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[6], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[7] = CreateDynamicObject(3533, 247.5066, 3286.8906, -57.7695, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[7], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[8] = CreateDynamicObject(3533, 247.5066, 3286.8906, -48.9597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[8], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[9] = CreateDynamicObject(3533, 247.5066, 3286.8906, -66.5794, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[9], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[10] = CreateDynamicObject(18769, 256.0657, 3295.4528, 8.8148, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SkyDivePlatform1a
    SetDynamicObjectMaterial(wfabrikinsel_object[10], 0, 16640, "a51", "sl_metalwalk", 0x00000000);
    wfabrikinsel_object[11] = CreateDynamicObject(3533, 247.5066, 3304.0327, 4.4299, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[11], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[12] = CreateDynamicObject(3533, 247.5066, 3304.0327, -4.3597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[12], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[13] = CreateDynamicObject(3533, 247.5066, 3304.0327, -13.1798, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[13], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[14] = CreateDynamicObject(3533, 247.5066, 3304.0327, -22.1597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[14], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[15] = CreateDynamicObject(3533, 247.5066, 3304.0327, -31.0498, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[15], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[16] = CreateDynamicObject(3533, 247.5066, 3304.0327, -40.0297, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[16], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[17] = CreateDynamicObject(3533, 247.5066, 3304.0327, -48.9597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[17], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[18] = CreateDynamicObject(3533, 247.5066, 3304.0327, -57.7695, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[18], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[19] = CreateDynamicObject(3533, 247.5066, 3304.0327, -66.5794, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[19], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[20] = CreateDynamicObject(3533, 264.5964, 3304.0327, 4.4299, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[20], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[21] = CreateDynamicObject(3533, 264.5964, 3304.0327, -4.3597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[21], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[22] = CreateDynamicObject(3533, 264.5964, 3304.0327, -13.1798, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[22], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[23] = CreateDynamicObject(3533, 264.5964, 3304.0327, -22.1597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[23], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[24] = CreateDynamicObject(3533, 264.5964, 3304.0327, -31.0498, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[24], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[25] = CreateDynamicObject(3533, 264.5964, 3304.0327, -40.0297, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[25], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[26] = CreateDynamicObject(3533, 264.5964, 3304.0327, -48.9597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[26], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[27] = CreateDynamicObject(3533, 264.5964, 3304.0327, -57.7695, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[27], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[28] = CreateDynamicObject(3533, 264.5964, 3304.0327, -66.5794, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[28], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[29] = CreateDynamicObject(3533, 264.5964, 3286.9780, 4.4299, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[29], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[30] = CreateDynamicObject(3533, 264.5964, 3286.9780, -4.3597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[30], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[31] = CreateDynamicObject(3533, 264.5964, 3286.9780, -13.1798, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[31], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[32] = CreateDynamicObject(3533, 264.5964, 3286.9780, -22.1597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[32], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[33] = CreateDynamicObject(3533, 264.5964, 3286.9780, -31.0498, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[33], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[34] = CreateDynamicObject(3533, 264.5964, 3286.9780, -40.0297, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[34], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[35] = CreateDynamicObject(3533, 264.5964, 3286.9780, -48.9597, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[35], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[36] = CreateDynamicObject(3533, 264.5964, 3286.9780, -57.7695, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[36], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[37] = CreateDynamicObject(3533, 264.5964, 3286.9780, -66.5794, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trdpillar01
    SetDynamicObjectMaterial(wfabrikinsel_object[37], 0, 16640, "a51", "redmetal", 0x00000000);
    wfabrikinsel_object[38] = CreateDynamicObject(18762, 250.1524, 3282.2536, 1.3342, 0.0000, 90.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(wfabrikinsel_object[38], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    wfabrikinsel_object[39] = CreateDynamicObject(983, 266.0156, 3288.7104, 10.1588, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[40] = CreateDynamicObject(5820, 262.1458, 3283.8947, 5.9899, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //odrampbit02
    wfabrikinsel_object[41] = CreateDynamicObject(19447, 261.0683, 3283.4860, 1.7644, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[41], 0, 16640, "a51", "sl_metalwalk", 0x00000000);
    wfabrikinsel_object[42] = CreateDynamicObject(19447, 251.4483, 3283.4860, 1.7644, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[42], 0, 16640, "a51", "sl_metalwalk", 0x00000000);
    wfabrikinsel_object[43] = CreateDynamicObject(18762, 255.1623, 3282.2536, 1.3342, 0.0000, 90.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(wfabrikinsel_object[43], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    wfabrikinsel_object[44] = CreateDynamicObject(18762, 260.1622, 3282.2536, 1.3342, 0.0000, 90.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(wfabrikinsel_object[44], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    wfabrikinsel_object[45] = CreateDynamicObject(18762, 263.1625, 3282.2536, 1.3342, 0.0000, 90.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(wfabrikinsel_object[45], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    wfabrikinsel_object[46] = CreateDynamicObject(18762, 264.1729, 3284.9462, -2.4156, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(wfabrikinsel_object[46], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    wfabrikinsel_object[47] = CreateDynamicObject(18762, 247.1526, 3284.2656, 1.3242, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(wfabrikinsel_object[47], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    wfabrikinsel_object[48] = CreateDynamicObject(18762, 265.1632, 3284.9462, -2.4156, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(wfabrikinsel_object[48], 0, 14776, "genintintcarint3", "ab_steelFrame", 0x00000000);
    wfabrikinsel_object[49] = CreateDynamicObject(984, 252.7259, 3285.6674, 10.1330, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit2
    wfabrikinsel_object[50] = CreateDynamicObject(983, 262.6347, 3281.7375, 2.5464, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[51] = CreateDynamicObject(983, 256.2644, 3281.7375, 2.5464, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[52] = CreateDynamicObject(983, 266.0151, 3295.3278, 10.1752, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[53] = CreateDynamicObject(983, 266.0050, 3301.9414, 10.1752, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[54] = CreateDynamicObject(983, 262.7749, 3305.1342, 10.1752, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[55] = CreateDynamicObject(983, 256.1448, 3305.1342, 10.1752, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[56] = CreateDynamicObject(983, 249.5249, 3305.1342, 10.1752, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[57] = CreateDynamicObject(983, 246.3251, 3301.9414, 10.1752, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[58] = CreateDynamicObject(983, 246.3251, 3295.4179, 10.1752, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[59] = CreateDynamicObject(983, 246.3251, 3288.8933, 10.1752, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[60] = CreateDynamicObject(983, 262.6347, 3285.2910, 2.5464, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[61] = CreateDynamicObject(983, 260.7150, 3285.6809, 10.1752, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    wfabrikinsel_object[62] = CreateDynamicObject(984, 253.0370, 3285.2829, 2.4644, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit2
    wfabrikinsel_object[63] = CreateDynamicObject(19447, 247.7899, 3291.9299, 13.9787, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[63], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[64] = CreateDynamicObject(19447, 247.7920, 3291.9299, 11.2388, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[64], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[65] = CreateDynamicObject(19447, 247.7879, 3299.0439, 11.2388, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[65], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[66] = CreateDynamicObject(19447, 247.7799, 3299.0439, 13.9787, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[66], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[67] = CreateDynamicObject(19368, 249.4772, 3303.7800, 11.2388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[67], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[68] = CreateDynamicObject(19368, 249.4772, 3303.7810, 13.9488, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[68], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[69] = CreateDynamicObject(19447, 249.4275, 3299.0439, 15.6788, 0.0000, 90.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[69], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[70] = CreateDynamicObject(19447, 249.4476, 3291.9272, 15.6899, 0.0000, 90.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[70], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[71] = CreateDynamicObject(19368, 249.4770, 3287.2099, 11.2388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[71], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[72] = CreateDynamicObject(19368, 249.4772, 3287.2048, 13.9488, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[72], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[73] = CreateDynamicObject(19447, 251.1179, 3299.0439, 14.0087, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[73], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[74] = CreateDynamicObject(19447, 251.1199, 3291.9418, 13.9787, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[74], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[75] = CreateDynamicObject(19447, 255.8917, 3287.2163, 11.2388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[75], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[76] = CreateDynamicObject(19447, 255.8917, 3303.7844, 11.2388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[76], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[77] = CreateDynamicObject(19368, 260.6010, 3288.9038, 11.2388, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[77], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[78] = CreateDynamicObject(19368, 260.6010, 3292.1064, 11.2388, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[78], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[79] = CreateDynamicObject(19387, 260.6010, 3295.3022, 11.2388, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(wfabrikinsel_object[79], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[80] = CreateDynamicObject(19368, 260.6010, 3298.5085, 11.2388, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[80], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[81] = CreateDynamicObject(19368, 260.6004, 3301.7116, 11.2388, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[81], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[82] = CreateDynamicObject(19368, 260.6000, 3302.2521, 11.2388, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(wfabrikinsel_object[82], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[83] = CreateDynamicObject(1491, 260.6184, 3294.5612, 9.4988, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(wfabrikinsel_object[83], 0, 3922, "bistro", "sw_door11", 0xFFFFFFFF);
    wfabrikinsel_object[84] = CreateDynamicObject(3800, 248.3849, 3297.5634, 9.4652, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    wfabrikinsel_object[85] = CreateDynamicObject(19447, 255.8917, 3302.1127, 12.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[85], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[86] = CreateDynamicObject(1271, 261.0335, 3300.5583, 9.8087, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    wfabrikinsel_object[87] = CreateDynamicObject(2969, 262.7520, 3300.6767, 9.5830, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //level_ammobox
    wfabrikinsel_object[88] = CreateDynamicObject(1271, 261.9136, 3300.5583, 9.8087, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    wfabrikinsel_object[89] = CreateDynamicObject(1271, 261.4336, 3299.7075, 9.8087, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    wfabrikinsel_object[90] = CreateDynamicObject(1271, 261.4336, 3300.1579, 10.5087, 0.0000, 0.0000, 40.5999, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    wfabrikinsel_object[91] = CreateDynamicObject(2969, 262.7520, 3300.1662, 9.5830, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //level_ammobox
    wfabrikinsel_object[92] = CreateDynamicObject(2040, 262.0987, 3299.8232, 9.6147, 0.0000, 0.0000, -41.8998, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M1
    wfabrikinsel_object[93] = CreateDynamicObject(2040, 255.8917, 3303.7844, 11.2388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M1
    wfabrikinsel_object[94] = CreateDynamicObject(19447, 255.8917, 3298.6293, 12.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[94], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[95] = CreateDynamicObject(2040, 255.8917, 3302.1127, 12.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M1
    wfabrikinsel_object[96] = CreateDynamicObject(19447, 255.8917, 3295.1284, 12.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[96], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[97] = CreateDynamicObject(2040, 255.8917, 3298.6293, 12.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M1
    wfabrikinsel_object[98] = CreateDynamicObject(19447, 255.8917, 3291.6267, 12.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[98], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[99] = CreateDynamicObject(2040, 255.8917, 3295.1284, 12.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M1
    wfabrikinsel_object[100] = CreateDynamicObject(19447, 255.8930, 3288.8840, 12.9118, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(wfabrikinsel_object[100], 0, 16271, "des_factory", "corr_2_plaintiledblue", 0x00000000);
    wfabrikinsel_object[101] = CreateDynamicObject(2040, 255.8917, 3291.6267, 12.9188, 0.0000, 90.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M1
    wfabrikinsel_object[102] = CreateDynamicObject(19922, 258.9408, 3289.6645, 9.4743, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    wfabrikinsel_object[103] = CreateDynamicObject(19922, 255.8110, 3289.6645, 9.4743, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    wfabrikinsel_object[104] = CreateDynamicObject(19922, 252.6811, 3289.6645, 9.4743, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    wfabrikinsel_object[105] = CreateDynamicObject(19922, 252.6811, 3293.2680, 9.4743, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    wfabrikinsel_object[106] = CreateDynamicObject(19922, 255.8108, 3293.2680, 9.4743, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    wfabrikinsel_object[107] = CreateDynamicObject(19922, 258.9408, 3293.2680, 9.4743, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    wfabrikinsel_object[108] = CreateDynamicObject(359, 258.7225, 3292.7243, 10.2788, 90.0000, 0.0000, 180.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rocketla
    wfabrikinsel_object[109] = CreateDynamicObject(359, 260.2326, 3293.3549, 10.2788, 90.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rocketla
    wfabrikinsel_object[110] = CreateDynamicObject(359, 260.1123, 3293.3549, 10.2788, 90.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rocketla
    wfabrikinsel_object[111] = CreateDynamicObject(356, 255.5160, 3292.6977, 10.3388, -90.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    wfabrikinsel_object[112] = CreateDynamicObject(356, 256.6261, 3292.9880, 10.3388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    wfabrikinsel_object[113] = CreateDynamicObject(356, 256.5361, 3292.9880, 10.3388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    wfabrikinsel_object[114] = CreateDynamicObject(356, 256.7163, 3292.9880, 10.3388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
    wfabrikinsel_object[115] = CreateDynamicObject(349, 252.5184, 3292.7788, 10.3101, 0.0000, 10.7999, 180.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chromegun
    wfabrikinsel_object[116] = CreateDynamicObject(349, 251.3695, 3292.9770, 10.3218, -65.0998, 16.4999, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chromegun
    wfabrikinsel_object[117] = CreateDynamicObject(349, 251.4584, 3292.9665, 10.3466, -65.0998, 16.4999, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chromegun
    wfabrikinsel_object[118] = CreateDynamicObject(363, 255.3305, 3289.1933, 10.3487, -90.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //satchel
    wfabrikinsel_object[119] = CreateDynamicObject(363, 256.5003, 3290.0642, 10.3487, -90.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //satchel
    wfabrikinsel_object[120] = CreateDynamicObject(363, 256.5003, 3289.8659, 10.3838, -63.9001, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //satchel
    wfabrikinsel_object[121] = CreateDynamicObject(363, 256.5003, 3289.7270, 10.3940, -63.9001, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //satchel
    wfabrikinsel_object[122] = CreateDynamicObject(352, 252.3365, 3289.2751, 10.3187, -90.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //micro_uzi
    wfabrikinsel_object[123] = CreateDynamicObject(352, 253.3665, 3290.1560, 10.3187, -90.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //micro_uzi
    wfabrikinsel_object[124] = CreateDynamicObject(352, 253.3665, 3289.8156, 10.3187, -90.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //micro_uzi
    wfabrikinsel_object[125] = CreateDynamicObject(352, 253.3665, 3289.4653, 10.3187, -90.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //micro_uzi
    wfabrikinsel_object[126] = CreateDynamicObject(358, 258.8086, 3289.1137, 10.3176, -83.1997, 10.5999, -0.8999, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    wfabrikinsel_object[127] = CreateDynamicObject(358, 260.3833, 3289.5620, 10.3388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    wfabrikinsel_object[128] = CreateDynamicObject(358, 260.2828, 3289.5620, 10.3388, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    wfabrikinsel_object[129] = CreateDynamicObject(3066, 255.5108, 3302.3110, 10.5117, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ammotrn_obj
    wfabrikinsel_object[130] = CreateDynamicObject(2359, 249.4703, 3301.2727, 9.7018, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
    wfabrikinsel_object[131] = CreateDynamicObject(2359, 248.4008, 3301.2727, 9.7018, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
    wfabrikinsel_object[132] = CreateDynamicObject(2358, 249.3206, 3301.9157, 9.5832, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    wfabrikinsel_object[133] = CreateDynamicObject(2358, 249.3206, 3302.7165, 9.5832, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    wfabrikinsel_object[134] = CreateDynamicObject(2358, 248.2407, 3302.7165, 9.5832, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    wfabrikinsel_object[135] = CreateDynamicObject(2358, 248.2407, 3301.9658, 9.5832, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c2
    wfabrikinsel_object[136] = CreateDynamicObject(3800, 248.3849, 3296.4624, 9.4652, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    wfabrikinsel_object[137] = CreateDynamicObject(3800, 248.3849, 3295.3715, 9.4652, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    wfabrikinsel_object[138] = CreateDynamicObject(3800, 248.3849, 3296.4626, 10.5552, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //acbox4_SFS
    wfabrikinsel_object[139] = CreateDynamicObject(18885, 248.2937, 3290.2250, 10.5874, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GunVendingMachine1
    wfabrikinsel_object[140] = CreateDynamicObject(1691, 249.6566, 3299.9465, 16.0153, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit5
    wfabrikinsel_object[141] = CreateDynamicObject(1691, 249.6566, 3291.2316, 16.0153, 0.0000, 0.0000, 0.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit5
    wfabrikinsel_object[142] = CreateDynamicObject(1691, 256.2467, 3301.9584, 13.2553, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit5
    wfabrikinsel_object[143] = CreateDynamicObject(1691, 256.2467, 3298.1757, 13.2553, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit5
    wfabrikinsel_object[144] = CreateDynamicObject(1691, 256.2467, 3293.3713, 13.2553, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit5
    wfabrikinsel_object[145] = CreateDynamicObject(1691, 256.2467, 3289.4484, 13.2553, 0.0000, 0.0000, 90.0000, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roofbit5
    //g_Vehicle[0] = CreateVehicle(454, 253.6838, 2935.0187, 0.3175, 0.9987, 113, 113, -1, VW_MAIN, WEAPONFABRIKINSEL, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Tropic
    wfabrikinsel_Actor[0] = CreateActor(220, 252.3150, 3292.4160, 10.4787, 0.0000); //Cab Driver
    ApplyActorAnimation(wfabrikinsel_Actor[0], "BD_FIRE", "BD_PANIC_LOOP", 4.0998, 1, 0, 0, 0, 0);
    wfabrikinsel_Actor[1] = CreateActor(221, 258.6387, 3292.4392, 9.6887, 0.0000); //Normal Ped
    ApplyActorAnimation(wfabrikinsel_Actor[1], "BD_FIRE", "BD_PANIC_LOOP", 4.0998, 1, 0, 0, 0, 0);
    wfabrikinsel_Actor[2] = CreateActor(222, 255.6510, 3288.7966, 10.4787, 0.0000); //Normal Ped
    ApplyActorAnimation(wfabrikinsel_Actor[2], "BD_FIRE", "BD_PANIC_LOOP", 4.0998, 1, 0, 0, 0, 0);
    AttachObjectToObject(wfabrikinsel_object[92], wfabrikinsel_object[76], 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000);
    AttachObjectToObject(wfabrikinsel_object[93], wfabrikinsel_object[85], 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000);
    AttachObjectToObject(wfabrikinsel_object[95], wfabrikinsel_object[94], 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000);
    AttachObjectToObject(wfabrikinsel_object[97], wfabrikinsel_object[96], 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000);
    AttachObjectToObject(wfabrikinsel_object[99], wfabrikinsel_object[98], 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000);
    AttachObjectToObject(wfabrikinsel_object[101], wfabrikinsel_object[100], 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000);
}