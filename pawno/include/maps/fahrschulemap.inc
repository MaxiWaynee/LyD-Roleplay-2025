#include <YSI\y_hooks>

// Global interior define
#define MAPS_FAHRSCHULE_INTERIOR  0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

new fahrschule_Object[274];
new fahrschule_Actor[2];


hook OnGameModeInit() {
    fahrschule_Object[0] = CreateDynamicObject(1432, 2145.1892, -1726.3144, 16.4780, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_TABLE_2
    fahrschule_Object[1] = CreateDynamicObject(19866, 2136.7199, -1731.5727, 16.3432, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[1], 0, 3306, "cunte_house1", "pinkfence_law", 0xFFB22222);
    fahrschule_Object[2] = CreateDynamicObject(18762, 2140.5607, -1730.5771, 13.5219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[2], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[3] = CreateDynamicObject(19368, 2138.3798, -1733.9975, 14.2826, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[3], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[4] = CreateDynamicObject(19447, 2151.0637, -1724.4410, 14.2833, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[4], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[5] = CreateDynamicObject(19387, 2144.9833, -1731.0050, 14.2826, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[5], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[6] = CreateDynamicObject(19922, 2157.5266, -1725.2451, 12.5254, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    SetDynamicObjectMaterial(fahrschule_Object[6], 0, 3820, "boxhses_sfsx", "sw_barnwoodblu", 0x00000000);
    fahrschule_Object[7] = CreateDynamicObject(19447, 2136.7014, -1729.2700, 14.2833, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[7], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[8] = CreateDynamicObject(19447, 2160.6813, -1724.4410, 14.2833, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[8], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[9] = CreateDynamicObject(19368, 2154.5874, -1731.0040, 14.2826, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[9], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[10] = CreateDynamicObject(19368, 2141.7700, -1731.0069, 14.2826, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[10], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[11] = CreateDynamicObject(19447, 2141.4250, -1724.4410, 14.2833, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[11], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[12] = CreateDynamicObject(19368, 2140.0725, -1732.4624, 14.2826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[12], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[13] = CreateDynamicObject(19387, 2155.8725, -1729.3441, 14.2826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[13], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[14] = CreateDynamicObject(19368, 2165.4099, -1726.1147, 14.2826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[14], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[15] = CreateDynamicObject(19368, 2148.1928, -1731.0050, 14.2826, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[15], 0, 17588, "lae2coast_alpha", "plainglass", 0x00000000);
    fahrschule_Object[16] = CreateDynamicObject(19368, 2165.4099, -1729.3077, 14.2826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[16], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[17] = CreateDynamicObject(1491, 2144.2500, -1730.9851, 12.5333, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[17], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    fahrschule_Object[18] = CreateDynamicObject(19447, 2160.6813, -1731.0050, 14.2833, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[18], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[19] = CreateDynamicObject(19368, 2155.8728, -1726.1534, 14.2826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[19], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[20] = CreateDynamicObject(18762, 2139.6098, -1730.5771, 13.5219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[20], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[21] = CreateDynamicObject(1656, 2137.4438, -1733.2060, 16.0000, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[21], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[22] = CreateDynamicObject(1656, 2137.4438, -1733.6186, 16.2297, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[22], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[23] = CreateDynamicObject(1656, 2137.4438, -1732.7933, 15.7600, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[23], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[24] = CreateDynamicObject(1656, 2137.4438, -1732.3806, 15.5200, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[24], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[25] = CreateDynamicObject(1656, 2137.4438, -1731.9676, 15.2798, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[25], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[26] = CreateDynamicObject(1656, 2137.4438, -1731.5550, 15.0396, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[26], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[27] = CreateDynamicObject(1656, 2137.4438, -1731.1424, 14.8000, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[27], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[28] = CreateDynamicObject(1656, 2137.4438, -1730.7297, 14.5600, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[28], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[29] = CreateDynamicObject(1656, 2137.4438, -1730.3170, 14.3198, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[29], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[30] = CreateDynamicObject(1656, 2136.9934, -1729.4438, 14.0797, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[30], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[31] = CreateDynamicObject(1656, 2138.6442, -1729.4438, 13.8599, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[31], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[32] = CreateDynamicObject(1656, 2139.0571, -1729.4438, 13.6197, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[32], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[33] = CreateDynamicObject(1656, 2139.4697, -1729.4438, 13.3800, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[33], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[34] = CreateDynamicObject(1656, 2139.8825, -1729.4438, 13.1400, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[34], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[35] = CreateDynamicObject(1656, 2140.2951, -1729.4438, 12.8999, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[35], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[36] = CreateDynamicObject(1656, 2140.7080, -1729.4438, 12.6597, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[36], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[37] = CreateDynamicObject(1209, 2145.1267, -1724.8043, 12.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vendmach
    fahrschule_Object[38] = CreateDynamicObject(1656, 2137.4062, -1729.4438, 14.0797, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[38], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[39] = CreateDynamicObject(1656, 2137.8188, -1729.4438, 14.0797, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[39], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[40] = CreateDynamicObject(1656, 2138.2316, -1729.4438, 14.0797, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Esc_step
    SetDynamicObjectMaterial(fahrschule_Object[40], 0, 10871, "blacksky_sfse", "ws_skywinsgreen", 0x00000000);
    fahrschule_Object[41] = CreateDynamicObject(18762, 2138.6198, -1730.6070, 13.7215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[41], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[42] = CreateDynamicObject(18762, 2138.6198, -1731.5483, 13.7819, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[42], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[43] = CreateDynamicObject(18762, 2138.6198, -1732.5290, 13.7517, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[43], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[44] = CreateDynamicObject(18762, 2138.6198, -1733.4599, 13.8119, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[44], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[45] = CreateDynamicObject(18762, 2140.5607, -1728.2762, 13.5017, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[45], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[46] = CreateDynamicObject(18762, 2139.5698, -1728.2762, 13.6618, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[46], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[47] = CreateDynamicObject(18762, 2138.5881, -1728.2762, 13.7018, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[47], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[48] = CreateDynamicObject(18762, 2137.6555, -1728.2762, 13.7018, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[48], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[49] = CreateDynamicObject(18762, 2137.1550, -1728.2762, 13.7018, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(fahrschule_Object[49], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    fahrschule_Object[50] = CreateDynamicObject(19411, 2140.9782, -1726.1759, 14.2833, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall059
    SetDynamicObjectMaterial(fahrschule_Object[50], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[51] = CreateDynamicObject(2165, 2140.4196, -1725.6966, 12.5255, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
    fahrschule_Object[52] = CreateDynamicObject(1671, 2139.4150, -1726.2639, 12.9762, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    fahrschule_Object[53] = CreateDynamicObject(1808, 2140.7253, -1727.4422, 12.5115, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_WATERCOOLER2
    fahrschule_Object[54] = CreateDynamicObject(2136, 2137.2900, -1727.1523, 12.4320, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_K3_SINK
    fahrschule_Object[55] = CreateDynamicObject(2161, 2138.8603, -1724.5527, 12.5276, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    fahrschule_Object[56] = CreateDynamicObject(1491, 2146.4624, -1728.5561, 12.5361, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[56], 0, 1675, "wshxrefhse", "decodoor5256", 0xFFFFFFFF);
    fahrschule_Object[57] = CreateDynamicObject(2139, 2137.3068, -1725.1645, 12.4242, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_K3_LOW_UNIT2
    fahrschule_Object[58] = CreateObject(19329, 2141.1088, -1726.2010, 15.4792, 0.0000, 0.0000, -90.0000); //7_11_sign04
    SetObjectMaterialText(fahrschule_Object[58], "Information", 0, OBJECT_MATERIAL_SIZE_256x128, "Constantia", 24, 1, 0xFF000000, 0x00000000, 1);
    fahrschule_Object[59] = CreateDynamicObject(11743, 2136.9631, -1727.2351, 13.4652, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCoffeeMachine1
    fahrschule_Object[60] = CreateDynamicObject(2500, 2136.8847, -1724.7120, 13.4694, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_COFFEE
    fahrschule_Object[61] = CreateDynamicObject(19835, 2140.3452, -1726.7318, 13.4055, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    fahrschule_Object[62] = CreateDynamicObject(19805, 2138.8481, -1727.7275, 14.6688, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Whiteboard1
    fahrschule_Object[63] = CreateDynamicObject(19368, 2163.6882, -1729.3188, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[63], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[64] = CreateDynamicObject(19368, 2163.6882, -1726.1147, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[64], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[65] = CreateDynamicObject(19368, 2160.1950, -1726.1147, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[65], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[66] = CreateDynamicObject(19368, 2160.1950, -1729.3155, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[66], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[67] = CreateDynamicObject(19368, 2156.7016, -1729.3155, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[67], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[68] = CreateDynamicObject(19368, 2156.7016, -1726.1042, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[68], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[69] = CreateDynamicObject(19368, 2153.2009, -1726.1042, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[69], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[70] = CreateDynamicObject(19368, 2153.2009, -1729.3160, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[70], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[71] = CreateDynamicObject(19368, 2149.7075, -1729.3160, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[71], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[72] = CreateDynamicObject(19368, 2149.7075, -1726.1053, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[72], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[73] = CreateDynamicObject(19368, 2146.2143, -1726.1053, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[73], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[74] = CreateDynamicObject(19368, 2146.2143, -1729.3166, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[74], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[75] = CreateDynamicObject(19368, 2142.7211, -1729.3166, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[75], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[76] = CreateDynamicObject(19368, 2142.7211, -1726.1136, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[76], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[77] = CreateDynamicObject(19368, 2139.2158, -1726.1136, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[77], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[78] = CreateDynamicObject(19368, 2139.2158, -1729.3259, 12.4525, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[78], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFF696969);
    fahrschule_Object[79] = CreateDynamicObject(19387, 2146.4848, -1729.3441, 14.2826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[79], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[80] = CreateObject(19329, 2146.3198, -1729.2927, 15.4193, 0.0000, 0.0000, -90.0000); //7_11_sign04
    SetObjectMaterialText(fahrschule_Object[80], "Schulungsraum", 0, OBJECT_MATERIAL_SIZE_256x128, "Constantia", 24, 1, 0xFF000000, 0x00000000, 1);
    fahrschule_Object[81] = CreateDynamicObject(1999, 2148.0791, -1726.2539, 12.5502, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //officedesk2
    fahrschule_Object[82] = CreateDynamicObject(19411, 2146.4836, -1726.1357, 14.2833, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall059
    SetDynamicObjectMaterial(fahrschule_Object[82], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[83] = CreateDynamicObject(1671, 2147.1916, -1725.2856, 12.9685, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    fahrschule_Object[84] = CreateDynamicObject(2202, 2147.0429, -1728.2093, 12.5417, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PHOTOCOPIER_2
    fahrschule_Object[85] = CreateDynamicObject(2123, 2150.2683, -1727.5738, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[86] = CreateDynamicObject(2123, 2151.0090, -1727.5738, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[87] = CreateDynamicObject(2123, 2151.7397, -1727.5738, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[88] = CreateDynamicObject(2123, 2152.4904, -1727.5738, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[89] = CreateDynamicObject(2123, 2153.2412, -1727.5738, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[90] = CreateDynamicObject(2123, 2153.2412, -1728.9453, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[91] = CreateDynamicObject(2123, 2152.5004, -1728.9453, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[92] = CreateDynamicObject(2123, 2151.7597, -1728.9453, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[93] = CreateDynamicObject(2123, 2151.0290, -1728.9453, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[94] = CreateDynamicObject(2123, 2150.2783, -1728.9453, 13.1681, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[95] = CreateDynamicObject(2115, 2152.3134, -1726.0954, 12.5093, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_1
    fahrschule_Object[96] = CreateDynamicObject(2115, 2150.3417, -1726.0954, 12.5093, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_1
    fahrschule_Object[97] = CreateDynamicObject(2855, 2150.1857, -1726.1285, 13.3275, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags05
    fahrschule_Object[98] = CreateDynamicObject(2855, 2152.0576, -1726.1285, 13.3275, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_bedmags05
    fahrschule_Object[99] = CreateDynamicObject(19805, 2151.9846, -1724.4980, 14.9298, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Whiteboard1
    SetDynamicObjectMaterial(fahrschule_Object[99], 0, 3564, "dockcargo2_las", "lastrk3", 0x00000000);
    fahrschule_Object[100] = CreateDynamicObject(1491, 2155.8784, -1728.5561, 12.5361, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[100], 0, 1675, "wshxrefhse", "decodoor5256", 0xFFFFFFFF);
    fahrschule_Object[101] = CreateObject(19329, 2146.5996, -1729.3127, 15.4193, 0.0000, 0.0000, -90.0000); //7_11_sign04
    SetObjectMaterialText(fahrschule_Object[101], "Eingangsbereich", 0, OBJECT_MATERIAL_SIZE_256x128, "Constantia", 24, 1, 0xFF000000, 0x00000000, 1);
    fahrschule_Object[102] = CreateDynamicObject(1073, 2158.7907, -1725.2954, 13.7791, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wheel_sr6
    fahrschule_Object[103] = CreateDynamicObject(19922, 2160.6596, -1725.2451, 12.5254, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    SetDynamicObjectMaterial(fahrschule_Object[103], 0, 3820, "boxhses_sfsx", "sw_barnwoodblu", 0x00000000);
    fahrschule_Object[104] = CreateDynamicObject(19922, 2163.7927, -1725.2451, 12.5254, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    SetDynamicObjectMaterial(fahrschule_Object[104], 0, 3820, "boxhses_sfsx", "sw_barnwoodblu", 0x00000000);
    fahrschule_Object[105] = CreateDynamicObject(19917, 2157.3234, -1725.2567, 13.3111, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneEngine1
    fahrschule_Object[106] = CreateDynamicObject(18976, 2159.8090, -1725.5830, 13.4109, 0.0000, -14.5000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet2
    fahrschule_Object[107] = CreateDynamicObject(18978, 2160.0585, -1725.5533, 13.4207, 0.0000, -25.3999, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet4
    fahrschule_Object[108] = CreateDynamicObject(18645, 2159.7983, -1725.0826, 13.4048, 0.0000, -24.3999, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet1
    fahrschule_Object[109] = CreateDynamicObject(18977, 2160.0878, -1725.1118, 13.4181, 0.0000, -22.6000, -91.5000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet3
    fahrschule_Object[110] = CreateObject(19329, 2155.9665, -1729.3127, 15.4193, 0.0000, 0.0000, -90.0000); //7_11_sign04
    SetObjectMaterialText(fahrschule_Object[110], "Schulungsraum", 0, OBJECT_MATERIAL_SIZE_256x128, "Constantia", 24, 1, 0xFF000000, 0x00000000, 1);
    fahrschule_Object[111] = CreateObject(19329, 2145.0166, -1730.8757, 15.4193, 0.0000, 0.0000, -180.0000); //7_11_sign04
    SetObjectMaterialText(fahrschule_Object[111], "Ausgang", 0, OBJECT_MATERIAL_SIZE_256x128, "Constantia", 24, 1, 0xFF000000, 0x00000000, 1);
    fahrschule_Object[112] = CreateObject(19329, 2145.0166, -1731.1053, 15.4193, 0.0000, 0.0000, -180.0000); //7_11_sign04
    SetObjectMaterialText(fahrschule_Object[112], "Eingang", 0, OBJECT_MATERIAL_SIZE_256x128, "Constantia", 24, 1, 0xFF000000, 0x00000000, 1);
    fahrschule_Object[113] = CreateObject(19329, 2155.7863, -1729.3127, 15.4193, 0.0000, 0.0000, -90.0000); //7_11_sign04
    SetObjectMaterialText(fahrschule_Object[113], "Ausstellungsraum", 0, OBJECT_MATERIAL_SIZE_256x128, "Constantia", 24, 1, 0xFF000000, 0x00000000, 1);
    fahrschule_Object[114] = CreateDynamicObject(1808, 2155.0927, -1724.7358, 12.6427, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_WATERCOOLER2
    fahrschule_Object[115] = CreateDynamicObject(19468, 2155.5493, -1724.6925, 12.6393, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bucket01
    fahrschule_Object[116] = CreateDynamicObject(2644, 2142.7731, -1725.0622, 12.9792, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BURG_TABLE
    fahrschule_Object[117] = CreateDynamicObject(19468, 2146.0295, -1724.8126, 12.6393, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bucket01
    fahrschule_Object[118] = CreateDynamicObject(2400, 2143.7785, -1730.8487, 12.5298, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SPORTS_WALL01
    fahrschule_Object[119] = CreateDynamicObject(2123, 2143.3437, -1725.0637, 13.1681, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[120] = CreateDynamicObject(2123, 2142.2126, -1725.0637, 13.1681, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_DIN_CHAIR_4
    fahrschule_Object[121] = CreateDynamicObject(19387, 2140.9797, -1729.3441, 14.2826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[121], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[122] = CreateDynamicObject(1491, 2141.0070, -1728.5561, 12.5361, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[122], 0, 1675, "wshxrefhse", "decodoor5256", 0xFFFFFFFF);
    fahrschule_Object[123] = CreateDynamicObject(19866, 2139.1271, -1733.9995, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[123], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[124] = CreateDynamicObject(982, 2162.3010, -1742.2789, 13.2299, 0.0000, 0.0000, 89.9999, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit
    fahrschule_Object[125] = CreateDynamicObject(19368, 2151.3837, -1731.0050, 14.2826, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[125], 0, 17588, "lae2coast_alpha", "plainglass", 0x00000000);
    fahrschule_Object[126] = CreateDynamicObject(982, 2126.3701, -1742.2789, 13.2299, 0.0000, 0.0000, 89.9999, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit
    fahrschule_Object[127] = CreateDynamicObject(983, 2106.5976, -1739.2530, 13.2341, 0.0000, 0.0000, -19.1000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[128] = CreateDynamicObject(983, 2108.6918, -1733.2054, 13.2341, 0.0000, 0.0000, -19.1000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[129] = CreateDynamicObject(983, 2110.7824, -1727.1595, 13.2341, 0.0000, 0.0000, -19.1000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[130] = CreateDynamicObject(983, 2111.8312, -1724.1345, 13.2341, 0.0000, 0.0000, -19.1000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[131] = CreateDynamicObject(19866, 2144.1120, -1733.9995, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[131], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[132] = CreateDynamicObject(19866, 2149.1120, -1733.9995, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[132], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[133] = CreateDynamicObject(983, 2175.0908, -1739.0831, 13.2165, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[134] = CreateDynamicObject(19866, 2154.1120, -1733.9995, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[134], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[135] = CreateDynamicObject(19866, 2159.1120, -1733.9995, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[135], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[136] = CreateDynamicObject(983, 2175.0908, -1732.6793, 13.2165, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[137] = CreateDynamicObject(983, 2175.0908, -1726.2784, 13.2165, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[138] = CreateDynamicObject(19368, 2140.9794, -1726.1136, 16.2625, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[138], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[139] = CreateDynamicObject(19866, 2169.1120, -1733.9995, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[139], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[140] = CreateDynamicObject(19866, 2171.5144, -1731.3990, 15.6006, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[140], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[141] = CreateDynamicObject(19866, 2136.6967, -1731.6074, 15.6006, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[141], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[142] = CreateDynamicObject(19866, 2136.6867, -1726.8453, 15.6006, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[142], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[143] = CreateDynamicObject(19866, 2144.1120, -1724.4442, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[143], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[144] = CreateDynamicObject(19866, 2139.1120, -1724.4442, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[144], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[145] = CreateDynamicObject(982, 2118.3474, -1742.2789, 13.2299, 0.0000, 0.0000, 89.9999, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit
    fahrschule_Object[146] = CreateDynamicObject(19866, 2149.1120, -1724.4442, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[146], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[147] = CreateDynamicObject(19866, 2154.1120, -1724.4442, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[147], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[148] = CreateDynamicObject(19866, 2159.1120, -1724.4442, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[148], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[149] = CreateDynamicObject(19866, 2164.1120, -1724.4442, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[149], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[150] = CreateDynamicObject(19866, 2169.1120, -1724.4442, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[150], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[151] = CreateDynamicObject(19866, 2171.5148, -1726.9869, 15.6006, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[151], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[152] = CreateDynamicObject(19447, 2157.1638, -1732.3348, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[152], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[153] = CreateDynamicObject(19447, 2166.7858, -1732.3348, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[153], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[154] = CreateDynamicObject(19447, 2147.5466, -1732.3348, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[154], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[155] = CreateDynamicObject(19447, 2147.5466, -1728.8542, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[155], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[156] = CreateDynamicObject(19447, 2147.5466, -1726.1136, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[156], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[157] = CreateDynamicObject(19447, 2157.1645, -1726.1136, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[157], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[158] = CreateDynamicObject(19447, 2157.1645, -1728.8559, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[158], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[159] = CreateDynamicObject(19447, 2166.7810, -1728.8658, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[159], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[160] = CreateDynamicObject(19447, 2166.7810, -1726.1153, 16.2730, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[160], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[161] = CreateDynamicObject(1886, 2151.7468, -1729.2817, 16.1804, 7.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    fahrschule_Object[162] = CreateDynamicObject(19368, 2138.3669, -1726.1136, 16.2625, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[162], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[163] = CreateDynamicObject(19368, 2138.3669, -1727.1644, 16.2625, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[163], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[164] = CreateDynamicObject(19368, 2140.9995, -1729.3165, 16.2625, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[164], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[165] = CreateDynamicObject(19368, 2140.9995, -1732.4885, 16.2625, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[165], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[166] = CreateDynamicObject(19368, 2139.8684, -1732.4885, 16.2625, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[166], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[167] = CreateDynamicObject(19368, 2139.8684, -1731.6977, 16.2625, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[167], 0, 10765, "airportgnd_sfse", "white", 0xFF87CEEB);
    fahrschule_Object[168] = CreateDynamicObject(19387, 2148.6015, -1730.6954, 18.1026, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[168], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[169] = CreateDynamicObject(19866, 2136.7199, -1726.8408, 16.3432, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[169], 0, 3306, "cunte_house1", "pinkfence_law", 0xFFB22222);
    fahrschule_Object[170] = CreateDynamicObject(19866, 2139.2924, -1733.9731, 16.3432, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[170], 0, 3306, "cunte_house1", "pinkfence_law", 0xFFB22222);
    fahrschule_Object[171] = CreateDynamicObject(19866, 2144.2924, -1733.9731, 16.3432, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[171], 0, 3306, "cunte_house1", "pinkfence_law", 0xFFB22222);
    fahrschule_Object[172] = CreateDynamicObject(19866, 2144.2924, -1724.4375, 16.3432, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[172], 0, 3306, "cunte_house1", "pinkfence_law", 0xFFB22222);
    fahrschule_Object[173] = CreateDynamicObject(19866, 2139.2924, -1724.4404, 16.3432, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[173], 0, 3306, "cunte_house1", "pinkfence_law", 0xFFB22222);
    fahrschule_Object[174] = CreateDynamicObject(19447, 2151.6142, -1724.4410, 18.1233, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[174], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[175] = CreateDynamicObject(19447, 2161.2321, -1724.4410, 18.1233, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[175], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[176] = CreateDynamicObject(19447, 2151.6142, -1734.0141, 18.1233, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[176], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[177] = CreateDynamicObject(19387, 2146.8955, -1729.3441, 18.1026, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[177], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[178] = CreateDynamicObject(19368, 2146.8723, -1726.1334, 18.1025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[178], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[179] = CreateDynamicObject(19368, 2146.8923, -1732.3282, 18.1025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[179], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[180] = CreateDynamicObject(1491, 2146.8928, -1728.5660, 16.3561, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[180], 0, 1675, "wshxrefhse", "decodoor5256", 0xFFFFFFFF);
    fahrschule_Object[181] = CreateDynamicObject(19368, 2165.9484, -1726.1334, 18.1025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[181], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[182] = CreateDynamicObject(19387, 2165.9484, -1729.3441, 18.1026, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[182], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[183] = CreateDynamicObject(19368, 2165.9489, -1732.3282, 18.1025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[183], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[184] = CreateDynamicObject(1491, 2165.9484, -1728.5660, 16.3561, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[184], 0, 1675, "wshxrefhse", "decodoor5256", 0xFFFFFFFF);
    fahrschule_Object[185] = CreateDynamicObject(19866, 2164.1120, -1733.9995, 15.6006, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[185], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[186] = CreateDynamicObject(19368, 2150.1557, -1732.3282, 18.1025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[186], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[187] = CreateDynamicObject(19387, 2148.6015, -1727.8137, 18.1026, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[187], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[188] = CreateDynamicObject(19368, 2150.1127, -1726.1334, 18.1025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[188], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[189] = CreateDynamicObject(1491, 2149.3598, -1727.8153, 16.3561, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[189], 0, 18008, "intclothesa", "CJ_VICT_DOOR2", 0xFFFFFFFF);
    fahrschule_Object[190] = CreateDynamicObject(1491, 2149.3398, -1730.7026, 16.3561, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[190], 0, 2878, "cj_vic", "CJ_VICT_DOOR", 0xFFFFFFFF);
    fahrschule_Object[191] = CreateDynamicObject(2514, 2148.4746, -1733.4195, 16.3684, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET1
    fahrschule_Object[192] = CreateDynamicObject(2094, 2148.5393, -1731.9355, 16.3684, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_CABINET_4
    fahrschule_Object[193] = CreateDynamicObject(2514, 2148.4746, -1725.0157, 16.3684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOILET1
    fahrschule_Object[194] = CreateDynamicObject(2094, 2148.5393, -1725.6704, 16.3484, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_CABINET_4
    fahrschule_Object[195] = CreateDynamicObject(19873, 2149.9365, -1725.3132, 17.4050, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    fahrschule_Object[196] = CreateDynamicObject(19873, 2149.9365, -1725.4433, 17.4050, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    fahrschule_Object[197] = CreateDynamicObject(19873, 2149.8264, -1725.3730, 17.4050, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    fahrschule_Object[198] = CreateDynamicObject(19873, 2149.9064, -1725.3730, 17.5249, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    fahrschule_Object[199] = CreateDynamicObject(19873, 2149.8435, -1733.3111, 17.4349, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    fahrschule_Object[200] = CreateDynamicObject(19873, 2149.8435, -1733.1811, 17.4349, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    fahrschule_Object[201] = CreateDynamicObject(19873, 2149.7333, -1733.2512, 17.4349, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    fahrschule_Object[202] = CreateDynamicObject(19873, 2149.8034, -1733.2512, 17.5550, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    fahrschule_Object[203] = CreateDynamicObject(2518, 2151.6191, -1733.4134, 16.5219, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_B_SINK2
    fahrschule_Object[204] = CreateDynamicObject(2518, 2152.3698, -1733.4134, 16.5219, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_B_SINK2
    fahrschule_Object[205] = CreateDynamicObject(2518, 2153.1206, -1733.4134, 16.5219, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_B_SINK2
    fahrschule_Object[206] = CreateDynamicObject(2518, 2150.5783, -1725.0505, 16.5219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_B_SINK2
    fahrschule_Object[207] = CreateDynamicObject(2518, 2151.3210, -1725.0505, 16.5219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_B_SINK2
    fahrschule_Object[208] = CreateDynamicObject(2518, 2152.0717, -1725.0505, 16.5219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_B_SINK2
    fahrschule_Object[209] = CreateDynamicObject(19368, 2153.5998, -1732.3282, 18.1025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[209], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[210] = CreateDynamicObject(19387, 2153.5996, -1729.3441, 18.1026, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(fahrschule_Object[210], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[211] = CreateDynamicObject(19368, 2153.5996, -1726.1334, 18.1025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall016
    SetDynamicObjectMaterial(fahrschule_Object[211], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0x00000000);
    fahrschule_Object[212] = CreateDynamicObject(1491, 2153.5996, -1728.5660, 16.3561, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(fahrschule_Object[212], 0, 1675, "wshxrefhse", "decodoor5256", 0xFFFFFFFF);
    fahrschule_Object[213] = CreateDynamicObject(19468, 2153.2839, -1724.8126, 16.4493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bucket01
    fahrschule_Object[214] = CreateDynamicObject(19468, 2153.2839, -1733.7479, 16.4493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bucket01
    fahrschule_Object[215] = CreateDynamicObject(2161, 2154.5400, -1733.9072, 16.3472, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    fahrschule_Object[216] = CreateDynamicObject(2161, 2155.8710, -1733.9072, 16.3472, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    fahrschule_Object[217] = CreateDynamicObject(2161, 2157.2023, -1733.9072, 16.3472, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    fahrschule_Object[218] = CreateDynamicObject(2162, 2158.9660, -1733.9228, 16.3201, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    fahrschule_Object[219] = CreateDynamicObject(2183, 2158.7202, -1729.9394, 16.3544, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE3_DESK_09
    fahrschule_Object[220] = CreateDynamicObject(1714, 2161.1750, -1727.9836, 16.3544, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    fahrschule_Object[221] = CreateDynamicObject(1714, 2159.4641, -1727.9836, 16.3544, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    fahrschule_Object[222] = CreateDynamicObject(1714, 2159.4641, -1730.5655, 16.3544, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    fahrschule_Object[223] = CreateDynamicObject(1714, 2161.1750, -1730.5356, 16.3544, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    fahrschule_Object[224] = CreateDynamicObject(1791, 2160.3679, -1729.0539, 17.0729, 0.0000, 0.0000, 133.5001, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_TV_2
    fahrschule_Object[225] = CreateDynamicObject(19786, 2160.2675, -1724.4193, 18.5489, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    fahrschule_Object[226] = CreateDynamicObject(1791, 2159.9016, -1729.2093, 17.0729, 0.0000, 0.0000, -138.1997, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_TV_2
    fahrschule_Object[227] = CreateDynamicObject(1791, 2160.1582, -1729.4453, 17.0729, 0.0000, 0.0000, -42.5997, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_TV_2
    fahrschule_Object[228] = CreateDynamicObject(1791, 2160.3562, -1729.3265, 17.0729, 0.0000, 0.0000, 48.7000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_TV_2
    fahrschule_Object[229] = CreateDynamicObject(19808, 2161.1645, -1729.9604, 17.1788, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    fahrschule_Object[230] = CreateDynamicObject(19808, 2159.4831, -1729.9604, 17.1788, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    fahrschule_Object[231] = CreateDynamicObject(19808, 2159.4831, -1728.5893, 17.1788, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    fahrschule_Object[232] = CreateDynamicObject(19808, 2161.1347, -1728.5893, 17.1788, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    fahrschule_Object[233] = CreateDynamicObject(19805, 2153.6726, -1726.4884, 18.1688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Whiteboard1
    fahrschule_Object[234] = CreateDynamicObject(983, 2168.3859, -1734.0417, 17.0464, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[235] = CreateDynamicObject(983, 2171.5786, -1727.5808, 17.0464, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[236] = CreateDynamicObject(983, 2168.3859, -1724.3785, 17.0464, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[237] = CreateDynamicObject(983, 2171.5786, -1730.7739, 17.0464, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[238] = CreateDynamicObject(19831, 2166.3615, -1732.1986, 16.3318, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Barbeque1
    fahrschule_Object[239] = CreateDynamicObject(1432, 2168.6933, -1726.3430, 16.4920, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_TABLE_2
    fahrschule_Object[240] = CreateDynamicObject(983, 2113.7932, -1718.0377, 13.2341, 0.0000, 0.0000, -16.7999, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[241] = CreateDynamicObject(983, 2115.1845, -1713.4659, 13.2341, 0.0000, 0.0000, -16.7999, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[242] = CreateDynamicObject(19447, 2148.5629, -1729.2755, 19.7933, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[242], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[243] = CreateDynamicObject(19447, 2152.0563, -1729.2755, 19.7933, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[243], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[244] = CreateDynamicObject(19447, 2155.5588, -1729.2755, 19.7933, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[244], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[245] = CreateDynamicObject(19447, 2159.0405, -1729.2755, 19.7933, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[245], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[246] = CreateDynamicObject(19447, 2162.5239, -1729.2755, 19.7933, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[246], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[247] = CreateDynamicObject(19447, 2166.0166, -1729.2755, 19.7933, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[247], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[248] = CreateDynamicObject(19866, 2167.6818, -1726.9569, 19.1105, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[248], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[249] = CreateDynamicObject(19866, 2167.6799, -1731.5946, 19.1105, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[249], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[250] = CreateDynamicObject(19866, 2165.2675, -1733.9869, 19.1105, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[250], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[251] = CreateDynamicObject(19866, 2165.2875, -1724.4615, 19.1105, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[251], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[252] = CreateDynamicObject(19866, 2134.1281, -1724.4842, 11.7809, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[252], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[253] = CreateDynamicObject(19866, 2134.1281, -1727.9842, 11.8009, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[253], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[254] = CreateDynamicObject(19866, 2134.1281, -1734.7843, 11.8009, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[254], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[255] = CreateDynamicObject(19866, 2134.1281, -1731.4842, 11.8009, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[255], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[256] = CreateDynamicObject(19866, 2136.7304, -1732.3833, 11.8009, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[256], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[257] = CreateDynamicObject(19866, 2121.7773, -1724.4842, 11.8107, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[257], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[258] = CreateDynamicObject(19866, 2121.7773, -1727.9842, 11.8107, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[258], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[259] = CreateDynamicObject(19866, 2121.7773, -1731.4842, 11.8107, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[259], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[260] = CreateDynamicObject(19866, 2121.7773, -1734.7843, 11.8107, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(fahrschule_Object[260], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFF00);
    fahrschule_Object[261] = CreateDynamicObject(1665, 2168.7055, -1726.3990, 17.1415, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propashtray1
    fahrschule_Object[262] = CreateDynamicObject(1670, 2145.2460, -1726.3570, 17.1070, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    fahrschule_Object[263] = CreateDynamicObject(983, 2175.0908, -1721.4862, 13.2165, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    fahrschule_Object[264] = CreateDynamicObject(19447, 2161.2490, -1734.0141, 18.1233, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(fahrschule_Object[264], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    fahrschule_Object[265] = CreateDynamicObject(19976, 2139.1867, -1742.2657, 12.0689, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign29
    fahrschule_Object[266] = CreateDynamicObject(11711, 2145.0080, -1730.9659, 15.1695, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    fahrschule_Object[267] = CreateDynamicObject(11711, 2146.5373, -1729.2945, 15.1695, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    fahrschule_Object[268] = CreateDynamicObject(11711, 2146.9484, -1729.3270, 19.0489, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    fahrschule_Object[269] = CreateDynamicObject(11711, 2155.9140, -1729.2945, 15.1695, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    fahrschule_Object[270] = CreateDynamicObject(11711, 2140.9226, -1729.2945, 15.1695, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    fahrschule_Object[271] = CreateDynamicObject(11711, 2153.6408, -1729.3270, 19.0489, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    fahrschule_Object[272] = CreateDynamicObject(11711, 2148.5859, -1730.7458, 19.0496, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    fahrschule_Object[273] = CreateDynamicObject(11711, 2148.5859, -1727.7683, 19.0496, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FAHRSCHULE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    fahrschule_Actor[0] = CreateActor(150, 2139.7629, -1726.1982, 13.6180, -91.4001); //Businesswoman
    ApplyActorAnimation(fahrschule_Actor[0], "INT_OFFICE", "OFF_SIT_TYPE_LOOP", 4.0998, 1, 0, 0, 0, 0);
    fahrschule_Actor[1] = CreateActor(171, 2147.1520, -1725.5992, 13.0087, -179.1000); //Blackjack Dealer
    ApplyActorAnimation(fahrschule_Actor[1], "INT_OFFICE", "OFF_SIT_IDLE_LOOP", 4.0998, 1, 0, 0, 0, 0);
}

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 1308, 2110.6999, -1742.5799, 12.7031, 0.10); // telgrphpole02
    RemoveBuildingForPlayer(playerid, 5410, 2140.5200, -1735.1400, 15.8906, 0.10); // laecumpstreet
    RemoveBuildingForPlayer(playerid, 5551, 2140.5200, -1735.1400, 15.8906, 0.10); // LOD Model of laecumpstreet
    RemoveBuildingForPlayer(playerid, 1308, 2175.3100, -1730.8900, 12.7031, 0.10); // telgrphpole02
}