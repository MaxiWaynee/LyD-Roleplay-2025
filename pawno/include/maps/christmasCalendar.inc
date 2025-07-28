#include <YSI\y_hooks>

// Global interior define
#define MAPS_CHRISTMASCALENDAR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 110.0;
static Float:DRAWDISTANCE   = 100.0;

// Christmas Calendar Coords
#define CHRISTMASCALENDAR_COORDS              1221.01, -1656.45, 13.57

// Map variables
new object_christmasCalendar[287];
new text3D_christmasCalendar[2];

hook OnPlayerConnect(playerid) {
    
}

hook OnGameModeInit() {
    // 3DTextLabels
    text3D_christmasCalendar[0] = _:CreateDynamic3DTextLabel("-> Adventskalender <-\n" COLOR_HEX_YELLOW "Benutze /Adventskalender um ein Türchen zu öffnen", COLOR_GREEN, CHRISTMASCALENDAR_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CHRISTMASCALENDAR_INTERIOR); // Adventskalender
    text3D_christmasCalendar[1] = _:CreateDynamic3DTextLabel("-> Weihnachtsmützen <-\n" COLOR_HEX_YELLOW "Benutze /Weihnachtsmuetze", 0xFF0000FF, 1265.3833, -1661.0238, 13.5663, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CHRISTMASCALENDAR_INTERIOR);

	// Objects
    object_christmasCalendar[0] = CreateDynamicObject(19056, 1240.4448, -1653.4665, 13.1127, 0.0000, 0.0000, -30.2000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox3
    object_christmasCalendar[1] = CreateDynamicObject(18981, 1273.9001, -1647.3520, 12.0663, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[1], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_christmasCalendar[2] = CreateDynamicObject(18981, 1223.9051, -1647.3520, 12.0663, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[2], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_christmasCalendar[3] = CreateDynamicObject(18981, 1223.9051, -1672.3332, 12.0663, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[3], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_christmasCalendar[4] = CreateDynamicObject(18981, 1248.9039, -1672.3332, 12.0663, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[4], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_christmasCalendar[5] = CreateDynamicObject(18981, 1273.8940, -1672.3332, 12.0663, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[5], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_christmasCalendar[6] = CreateDynamicObject(18981, 1273.8940, -1682.5550, 12.0669, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[6], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_christmasCalendar[7] = CreateDynamicObject(19076, 1238.9687, -1653.5377, 12.3472, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasTree1
    object_christmasCalendar[8] = CreateDynamicObject(19357, 1238.9300, -1653.5461, 12.4855, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall005
    SetDynamicObjectMaterial(object_christmasCalendar[8], 0, 4829, "airport_las", "Grass_128HV", 0xFFFFFFFF);
    object_christmasCalendar[9] = CreateDynamicObject(19057, 1239.9322, -1654.8752, 13.1625, 0.0000, 0.0000, 40.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox4
    object_christmasCalendar[10] = CreateDynamicObject(970, 1261.9875, -1644.5996, 13.0933, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[11] = CreateDynamicObject(19055, 1239.4621, -1652.3635, 13.1815, 0.0000, 0.0000, 42.6999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox2
    object_christmasCalendar[12] = CreateDynamicObject(19054, 1237.8050, -1652.3791, 13.1344, 0.0000, 0.0000, -62.5998, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox1
    object_christmasCalendar[13] = CreateDynamicObject(19058, 1237.3530, -1653.9079, 13.1548, 0.0000, 0.0000, -25.1998, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox5
    object_christmasCalendar[14] = CreateDynamicObject(19055, 1238.3480, -1655.0284, 13.0860, 0.0000, 0.0000, -13.8999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox2
    object_christmasCalendar[15] = CreateDynamicObject(18864, 1228.2259, -1645.4864, 6.3720, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FakeSnow1
    object_christmasCalendar[16] = CreateDynamicObject(1312, 1299.3922, -1661.1029, 16.6089, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gen_roadsign2
    object_christmasCalendar[17] = CreateDynamicObject(19172, 1298.4017, -1660.8889, 19.4799, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[17], 0, "Weihnachtsmarkt", 90, "Georgia", 34, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[17], 1, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    object_christmasCalendar[18] = CreateDynamicObject(19172, 1297.4112, -1660.8889, 18.7798, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[18], 0, "--->", 90, "Georgia", 50, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[18], 1, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    object_christmasCalendar[19] = CreateDynamicObject(19172, 1312.2812, -1661.4582, 19.4799, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[19], 0, "Weihnachtsmarkt", 90, "Georgia", 34, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[19], 1, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    object_christmasCalendar[20] = CreateDynamicObject(19172, 1313.1313, -1661.4582, 18.7898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[20], 0, "<---", 90, "Georgia", 50, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[20], 1, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    object_christmasCalendar[21] = CreateDynamicObject(19464, 1238.8891, -1653.6639, 12.4631, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_christmasCalendar[21], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    object_christmasCalendar[22] = CreateDynamicObject(19365, 1244.4621, -1662.1612, 11.9181, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[22], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[23] = CreateDynamicObject(19365, 1242.9410, -1663.6820, 14.2981, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[23], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[24] = CreateDynamicObject(19365, 1247.6717, -1662.1612, 11.9181, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[24], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[25] = CreateDynamicObject(19365, 1242.9510, -1665.3022, 14.2981, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[25], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[26] = CreateDynamicObject(19365, 1249.1916, -1663.6811, 14.2981, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[26], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[27] = CreateDynamicObject(19365, 1244.4809, -1666.8232, 14.2981, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[27], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[28] = CreateDynamicObject(19365, 1249.2119, -1665.2622, 14.2981, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[28], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[29] = CreateDynamicObject(19387, 1247.6864, -1666.8144, 14.2966, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_christmasCalendar[29], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[30] = CreateDynamicObject(19365, 1247.6717, -1662.1612, 17.0881, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[30], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[31] = CreateDynamicObject(19365, 1244.4713, -1662.1612, 17.0881, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[31], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[32] = CreateDynamicObject(19365, 1244.4610, -1663.9619, 15.9882, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[32], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[33] = CreateDynamicObject(19365, 1247.6715, -1663.9619, 15.9882, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[33], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[34] = CreateDynamicObject(19365, 1247.6715, -1665.1229, 15.9982, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[34], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[35] = CreateDynamicObject(19365, 1244.4698, -1665.1229, 15.9982, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[35], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[36] = CreateDynamicObject(19466, 1248.0278, -1662.1739, 15.6688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    object_christmasCalendar[37] = CreateDynamicObject(19466, 1245.7871, -1662.1739, 15.6688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    object_christmasCalendar[38] = CreateDynamicObject(19466, 1244.0262, -1662.1739, 15.6688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    object_christmasCalendar[39] = CreateDynamicObject(1502, 1246.8944, -1666.8310, 12.5544, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT04
    object_christmasCalendar[40] = CreateDynamicObject(19172, 1245.9724, -1662.0760, 16.3341, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[40], 0, "Glüh", 90, "Georgia", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[40], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[41] = CreateDynamicObject(19172, 1244.7419, -1662.0760, 16.3341, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[41], 0, "wein", 90, "Georgia", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[41], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[42] = CreateDynamicObject(1744, 1245.5483, -1666.8747, 13.6962, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_christmasCalendar[43] = CreateDynamicObject(1744, 1242.9475, -1665.3343, 13.6962, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
    object_christmasCalendar[44] = CreateDynamicObject(19922, 1244.5067, -1662.7883, 12.5474, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_christmasCalendar[45] = CreateDynamicObject(19922, 1247.6383, -1662.7883, 12.5474, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_christmasCalendar[46] = CreateDynamicObject(18688, 1250.9930, -1641.2642, 13.2773, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire
    object_christmasCalendar[47] = CreateDynamicObject(1669, 1243.2816, -1665.6341, 14.2004, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[48] = CreateDynamicObject(1669, 1243.2816, -1665.1838, 14.2004, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[49] = CreateDynamicObject(1669, 1243.2816, -1664.7735, 14.2004, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[50] = CreateDynamicObject(1669, 1243.2816, -1664.2038, 14.2004, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[51] = CreateDynamicObject(1669, 1244.3171, -1666.5522, 14.1871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[52] = CreateDynamicObject(1669, 1244.5472, -1666.5522, 14.1871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[53] = CreateDynamicObject(1669, 1244.7873, -1666.5522, 14.1871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[54] = CreateDynamicObject(1669, 1245.0478, -1666.5522, 14.1871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[55] = CreateDynamicObject(1669, 1245.3081, -1666.5522, 14.1871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[56] = CreateDynamicObject(1669, 1245.5483, -1666.5522, 14.1871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[57] = CreateDynamicObject(1669, 1245.8286, -1666.5522, 14.1871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[58] = CreateDynamicObject(1669, 1244.0085, -1662.9111, 13.5270, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[59] = CreateDynamicObject(1669, 1244.1385, -1663.0810, 13.5270, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[60] = CreateDynamicObject(1669, 1244.1385, -1662.7910, 13.5270, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[61] = CreateDynamicObject(1669, 1244.2585, -1662.9011, 13.5270, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propwinebotl1
    object_christmasCalendar[62] = CreateDynamicObject(1666, 1246.0467, -1657.6024, 10.1302, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propbeerglass1
    object_christmasCalendar[63] = CreateDynamicObject(3525, 1251.2099, -1661.4493, 16.7772, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //exbrtorch01
    object_christmasCalendar[64] = CreateDynamicObject(3525, 1241.5592, -1661.3791, 16.7772, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //exbrtorch01
    object_christmasCalendar[65] = CreateDynamicObject(2002, 1245.9449, -1662.5373, 12.1511, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
    object_christmasCalendar[66] = CreateDynamicObject(11706, 1243.3790, -1664.9193, 12.6138, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
    object_christmasCalendar[67] = CreateDynamicObject(19585, 1244.7434, -1662.8714, 13.5284, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MarcosPan1
    object_christmasCalendar[68] = CreateDynamicObject(19453, 1252.2670, -1639.3602, 12.4935, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_christmasCalendar[68], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[69] = CreateDynamicObject(19124, 1248.3525, -1659.7436, 12.7797, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[70] = CreateDynamicObject(19124, 1243.8099, -1659.7436, 12.7797, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[71] = CreateDynamicObject(18981, 1213.0267, -1665.2008, 7.7761, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[71], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_christmasCalendar[72] = CreateDynamicObject(1587, 1213.5356, -1664.1949, 19.4015, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[73] = CreateDynamicObject(1587, 1213.5356, -1664.1949, 16.6714, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[74] = CreateDynamicObject(1587, 1213.5356, -1664.3951, 13.8613, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[75] = CreateDynamicObject(1587, 1213.5356, -1661.6739, 13.8613, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[76] = CreateDynamicObject(1587, 1213.5356, -1658.8636, 13.8613, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[77] = CreateDynamicObject(1587, 1213.5356, -1658.8636, 16.5415, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[78] = CreateDynamicObject(1587, 1213.5356, -1659.0039, 19.4015, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[79] = CreateDynamicObject(1587, 1213.5356, -1656.3033, 19.4015, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[80] = CreateDynamicObject(1587, 1213.5356, -1653.4521, 19.4015, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[81] = CreateDynamicObject(1587, 1213.5356, -1653.4521, 16.6814, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[82] = CreateDynamicObject(1587, 1213.5356, -1653.6623, 13.8315, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[83] = CreateDynamicObject(1587, 1213.5356, -1650.9315, 13.8315, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[84] = CreateDynamicObject(1587, 1213.5356, -1648.1208, 13.7515, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[85] = CreateDynamicObject(1587, 1213.5356, -1648.1208, 16.4314, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[86] = CreateDynamicObject(1587, 1213.5356, -1648.3612, 19.2915, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[87] = CreateDynamicObject(18981, 1213.0267, -1650.1788, 7.7761, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[87], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_christmasCalendar[88] = CreateDynamicObject(1587, 1213.5356, -1645.6706, 19.2915, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[89] = CreateDynamicObject(1587, 1213.5356, -1642.9803, 19.2513, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[90] = CreateDynamicObject(1587, 1213.5356, -1640.1396, 19.4115, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[91] = CreateDynamicObject(1587, 1213.5356, -1639.9294, 16.5515, 0.0000, -90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[92] = CreateDynamicObject(1587, 1213.5333, -1667.0461, 19.0813, 0.3998, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[93] = CreateDynamicObject(1587, 1213.5333, -1669.7474, 19.0813, 0.3998, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[94] = CreateDynamicObject(1587, 1213.5134, -1669.5172, 16.2513, 0.3998, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[95] = CreateDynamicObject(1587, 1213.5155, -1672.3177, 16.5214, 0.3998, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[96] = CreateDynamicObject(1587, 1213.5356, -1642.7700, 16.6714, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tar_frame
    object_christmasCalendar[97] = CreateDynamicObject(19172, 1213.5290, -1670.9477, 16.4379, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[97], 0, "1", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[97], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[98] = CreateDynamicObject(3498, 1213.4106, -1637.9256, 16.0704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdpillar01_lvs
    SetDynamicObjectMaterial(object_christmasCalendar[98], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[98], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[99] = CreateDynamicObject(19172, 1213.5290, -1668.4371, 16.4379, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[99], 0, "2", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[99], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[100] = CreateDynamicObject(19172, 1213.5290, -1668.4371, 19.0979, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[100], 0, "3", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[100], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[101] = CreateDynamicObject(19172, 1213.5290, -1665.7562, 19.1280, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[101], 0, "4", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[101], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[102] = CreateDynamicObject(19172, 1213.5290, -1663.1052, 19.1280, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[102], 0, "5", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[102], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[103] = CreateDynamicObject(19172, 1213.5290, -1663.1650, 16.2080, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[103], 0, "6", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[103], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[104] = CreateDynamicObject(19172, 1213.5290, -1663.0749, 13.8577, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[104], 0, "7", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[104], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[105] = CreateDynamicObject(19172, 1213.5290, -1660.3846, 13.6280, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[105], 0, "8", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[105], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[106] = CreateDynamicObject(19172, 1213.5290, -1657.7938, 14.1379, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[106], 0, "9", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[106], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[107] = CreateDynamicObject(19172, 1213.5290, -1658.0040, 16.7380, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[107], 0, "10", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[107], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[108] = CreateDynamicObject(19172, 1213.5290, -1657.8739, 19.3780, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[108], 0, "11", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[108], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[109] = CreateDynamicObject(19172, 1213.5290, -1655.2031, 19.3780, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[109], 0, "12", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[109], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[110] = CreateDynamicObject(19172, 1213.5290, -1652.6120, 19.1079, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[110], 0, "13", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[110], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[111] = CreateDynamicObject(19172, 1213.5290, -1652.6120, 16.4179, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[111], 0, "14", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[111], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[112] = CreateDynamicObject(19172, 1213.5290, -1652.5920, 13.7980, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[112], 0, "15", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[112], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[113] = CreateDynamicObject(19172, 1213.5290, -1649.8808, 13.6577, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[113], 0, "16", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[113], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[114] = CreateDynamicObject(19172, 1213.5290, -1647.2397, 13.9280, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[114], 0, "17", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[114], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[115] = CreateDynamicObject(19172, 1213.5290, -1647.2799, 16.5680, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[115], 0, "18", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[115], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[116] = CreateDynamicObject(19172, 1213.5290, -1647.2799, 19.3278, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[116], 0, "19", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[116], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[117] = CreateDynamicObject(19172, 1213.5290, -1644.6096, 19.2479, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[117], 0, "20", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[117], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[118] = CreateDynamicObject(19172, 1213.5290, -1641.8386, 19.1979, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[118], 0, "21", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[118], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[119] = CreateDynamicObject(19172, 1213.5290, -1639.3277, 19.1979, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[119], 0, "22", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[119], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[120] = CreateDynamicObject(19172, 1213.5290, -1639.4178, 16.5380, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[120], 0, "23", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[120], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[121] = CreateDynamicObject(19172, 1213.5290, -1642.0483, 16.4080, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[121], 0, "24", 90, "Georgia", 100, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[121], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[122] = CreateDynamicObject(3498, 1213.4106, -1677.3266, 16.0704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdpillar01_lvs
    SetDynamicObjectMaterial(object_christmasCalendar[122], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[122], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[123] = CreateDynamicObject(3498, 1213.4106, -1672.8470, 12.5902, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdpillar01_lvs
    SetDynamicObjectMaterial(object_christmasCalendar[123], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[123], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[124] = CreateDynamicObject(3498, 1213.4106, -1663.8459, 12.5902, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdpillar01_lvs
    SetDynamicObjectMaterial(object_christmasCalendar[124], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[124], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[125] = CreateDynamicObject(3498, 1213.4106, -1654.8658, 12.5902, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdpillar01_lvs
    SetDynamicObjectMaterial(object_christmasCalendar[125], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[125], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[126] = CreateDynamicObject(3498, 1213.4106, -1645.9831, 12.5902, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdpillar01_lvs
    SetDynamicObjectMaterial(object_christmasCalendar[126], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[126], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[127] = CreateDynamicObject(3498, 1213.4106, -1642.2557, 12.5902, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdpillar01_lvs
    SetDynamicObjectMaterial(object_christmasCalendar[127], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[127], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[128] = CreateDynamicObject(19443, 1213.4708, -1661.2135, 17.8796, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall083
    SetDynamicObjectMaterialText(object_christmasCalendar[128], 0, "L", 90, "Georgia", 155, 1, 0xFF840410, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[128], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[129] = CreateDynamicObject(19443, 1213.4425, -1667.0102, 15.9063, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall083
    SetDynamicObjectMaterialText(object_christmasCalendar[129], 0, "e", 90, "Webdings", 150, 1, 0xFFFFFFFF, 0x0, 0);
    object_christmasCalendar[130] = CreateDynamicObject(19443, 1213.4708, -1655.9327, 16.5496, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall083
    SetDynamicObjectMaterialText(object_christmasCalendar[130], 0, "Y", 90, "Georgia", 155, 1, 0xFF840410, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[130], 1, 10023, "bigwhitesfe", "archgrnd1_SFE", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_christmasCalendar[130], 2, "L", 90, "Arial", 150, 1, 0xFFFFFFFF, 0x0, 0);
    object_christmasCalendar[131] = CreateDynamicObject(19443, 1213.4708, -1650.5019, 17.8796, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall083
    SetDynamicObjectMaterialText(object_christmasCalendar[131], 0, "D", 90, "Georgia", 155, 1, 0xFF840410, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[131], 1, 10023, "bigwhitesfe", "archgrnd1_SFE", 0xFFFFFFFF);
    SetDynamicObjectMaterialText(object_christmasCalendar[131], 2, "L", 90, "Arial", 150, 1, 0xFFFFFFFF, 0x0, 0);
    object_christmasCalendar[132] = CreateDynamicObject(19443, 1213.4425, -1645.5295, 15.9063, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall083
    SetDynamicObjectMaterialText(object_christmasCalendar[132], 0, "e", 90, "Webdings", 150, 1, 0xFFFFFFFF, 0x0, 0);
    object_christmasCalendar[133] = CreateDynamicObject(19387, 1254.5080, -1666.7744, 14.2966, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_christmasCalendar[133], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[134] = CreateDynamicObject(19365, 1257.7099, -1666.7617, 14.2782, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[134], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[135] = CreateDynamicObject(19365, 1259.2314, -1665.2403, 14.2782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[135], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[136] = CreateDynamicObject(19365, 1252.9681, -1665.2403, 14.2782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[136], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[137] = CreateDynamicObject(19365, 1252.9581, -1664.0493, 14.2782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[137], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[138] = CreateDynamicObject(3525, 1260.8509, -1661.4493, 16.7772, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //exbrtorch01
    object_christmasCalendar[139] = CreateDynamicObject(19365, 1259.2413, -1664.0493, 14.2782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[139], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[140] = CreateDynamicObject(19365, 1254.4902, -1665.1002, 16.1082, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[140], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[141] = CreateDynamicObject(19365, 1257.6925, -1665.1002, 16.1082, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[141], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[142] = CreateDynamicObject(19365, 1257.6925, -1664.1993, 16.1182, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[142], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[143] = CreateDynamicObject(19365, 1254.4924, -1664.1993, 16.1182, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[143], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[144] = CreateDynamicObject(3041, 1257.6114, -1663.3955, 12.5317, 19.8999, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ct_table
    object_christmasCalendar[145] = CreateDynamicObject(19365, 1254.5102, -1662.5312, 11.5579, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[145], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[146] = CreateDynamicObject(19365, 1257.7098, -1662.5312, 11.5579, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[146], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[147] = CreateDynamicObject(3041, 1254.6811, -1663.3918, 12.5410, 19.8999, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ct_table
    object_christmasCalendar[148] = CreateDynamicObject(19365, 1254.4902, -1662.5312, 17.1681, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[148], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[149] = CreateDynamicObject(19365, 1257.7010, -1662.5312, 17.1681, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[149], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[150] = CreateDynamicObject(19172, 1255.8520, -1662.4564, 16.3341, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[150], 0, "Süß", 90, "Georgia", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[150], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[151] = CreateDynamicObject(19172, 1254.8619, -1662.4364, 16.3341, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[151], 0, "waren", 90, "Georgia", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[151], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[152] = CreateDynamicObject(18688, 1266.1264, -1641.0343, 16.2573, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire
    object_christmasCalendar[153] = CreateDynamicObject(19124, 1253.8033, -1659.7436, 12.7797, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[154] = CreateDynamicObject(19124, 1258.3535, -1659.7436, 12.7797, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[155] = CreateDynamicObject(19453, 1252.2670, -1642.8596, 12.4935, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_christmasCalendar[155], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[156] = CreateDynamicObject(640, 1281.7857, -1671.1384, 13.2082, 0.0000, -0.2998, -88.4999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_christmasCalendar[156], 0, 9223, "newstuff_sfn", "oldflowerbed", 0xFFFFFFFF);
    object_christmasCalendar[157] = CreateDynamicObject(19453, 1261.8983, -1639.3602, 12.4935, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_christmasCalendar[157], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[158] = CreateDynamicObject(19453, 1261.8864, -1642.8596, 12.4935, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_christmasCalendar[158], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[159] = CreateDynamicObject(640, 1282.2807, -1690.0830, 13.3074, 0.0000, -0.2998, -88.4999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_christmasCalendar[159], 0, 9223, "newstuff_sfn", "oldflowerbed", 0xFFFFFFFF);
    object_christmasCalendar[160] = CreateDynamicObject(640, 1282.2635, -1694.7945, 13.3322, 0.0000, -0.2998, -88.4999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_christmasCalendar[160], 0, 9223, "newstuff_sfn", "oldflowerbed", 0xFFFFFFFF);
    object_christmasCalendar[161] = CreateDynamicObject(1502, 1253.7154, -1666.8110, 12.5544, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT04
    object_christmasCalendar[162] = CreateDynamicObject(2764, 1258.5738, -1664.9865, 12.9695, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE03
    object_christmasCalendar[163] = CreateDynamicObject(19578, 1258.9124, -1664.6711, 13.4139, 0.0000, 0.0000, 120.1998, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Banana1
    object_christmasCalendar[164] = CreateDynamicObject(19578, 1258.8940, -1665.0172, 13.4139, 0.0000, 0.0000, 120.1998, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Banana1
    object_christmasCalendar[165] = CreateDynamicObject(19578, 1258.7131, -1664.7059, 13.4139, 0.0000, 0.0000, 120.1998, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Banana1
    object_christmasCalendar[166] = CreateDynamicObject(2821, 1258.6281, -1665.2635, 13.4034, 0.0000, 0.0000, 52.7999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_foodwrap01
    object_christmasCalendar[167] = CreateDynamicObject(2764, 1256.8836, -1666.1274, 12.9695, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE03
    object_christmasCalendar[168] = CreateDynamicObject(1514, 1256.8656, -1666.0627, 13.6240, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_FF_TILL
    object_christmasCalendar[169] = CreateDynamicObject(19124, 1285.1827, -1694.7441, 12.9376, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[170] = CreateDynamicObject(19124, 1285.1827, -1690.0230, 12.9376, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[171] = CreateDynamicObject(19124, 1285.1827, -1683.9923, 12.9376, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[172] = CreateDynamicObject(19124, 1284.7923, -1675.3410, 12.9376, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[173] = CreateDynamicObject(19124, 1284.7923, -1671.0903, 12.9376, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[174] = CreateDynamicObject(19124, 1284.7923, -1665.8402, 12.9376, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[175] = CreateDynamicObject(3286, 1261.1424, -1641.0407, 10.3581, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxrf_watertwr
    SetDynamicObjectMaterial(object_christmasCalendar[175], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[175], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[176] = CreateDynamicObject(3286, 1256.2011, -1641.0407, 11.3680, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxrf_watertwr
    SetDynamicObjectMaterial(object_christmasCalendar[176], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[176], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[177] = CreateDynamicObject(3286, 1266.2728, -1641.0407, 11.9781, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxrf_watertwr
    SetDynamicObjectMaterial(object_christmasCalendar[177], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[177], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[178] = CreateDynamicObject(3286, 1250.9412, -1641.0407, 8.8980, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxrf_watertwr
    SetDynamicObjectMaterial(object_christmasCalendar[178], 0, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    SetDynamicObjectMaterial(object_christmasCalendar[178], 1, 10765, "airportgnd_sfse", "white", 0xFF730E1A);
    object_christmasCalendar[179] = CreateDynamicObject(18688, 1261.0865, -1641.0343, 14.7273, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire
    object_christmasCalendar[180] = CreateDynamicObject(18688, 1256.2155, -1641.2642, 15.6573, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire
    object_christmasCalendar[181] = CreateDynamicObject(970, 1256.0980, -1659.7486, 13.0992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[181], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[182] = CreateDynamicObject(1514, 1247.8326, -1662.9519, 13.5740, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_FF_TILL
    object_christmasCalendar[183] = CreateDynamicObject(970, 1246.0970, -1659.7486, 13.0992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[183], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[184] = CreateDynamicObject(640, 1281.8388, -1665.9156, 13.1808, 0.0000, -0.2998, -88.4999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_christmasCalendar[184], 0, 9223, "newstuff_sfn", "oldflowerbed", 0xFFFFFFFF);
    object_christmasCalendar[185] = CreateDynamicObject(640, 1281.8978, -1675.4173, 13.2306, 0.0000, -0.2998, -88.4999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_christmasCalendar[185], 0, 9223, "newstuff_sfn", "oldflowerbed", 0xFFFFFFFF);
    object_christmasCalendar[186] = CreateDynamicObject(19453, 1271.5261, -1642.8596, 12.4935, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_christmasCalendar[186], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[187] = CreateDynamicObject(640, 1282.1231, -1684.0643, 13.2760, 0.0000, -0.2998, -88.4999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_christmasCalendar[187], 0, 9223, "newstuff_sfn", "oldflowerbed", 0xFFFFFFFF);
    object_christmasCalendar[188] = CreateDynamicObject(19453, 1271.5261, -1639.3791, 12.4935, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall093
    SetDynamicObjectMaterial(object_christmasCalendar[188], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[189] = CreateDynamicObject(18981, 1248.9022, -1647.3520, 12.0663, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasCalendar[189], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_christmasCalendar[189], 1, 4992, "airportdetail", "bevflower1", 0xFFFFFFFF);
    object_christmasCalendar[190] = CreateDynamicObject(970, 1266.1170, -1644.5996, 13.0933, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[191] = CreateDynamicObject(970, 1257.8670, -1644.5996, 13.0933, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[192] = CreateDynamicObject(970, 1249.6262, -1644.5996, 13.0933, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[193] = CreateDynamicObject(970, 1253.7464, -1644.5996, 13.0933, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[194] = CreateDynamicObject(19365, 1269.0023, -1665.2403, 14.2782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[194], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[195] = CreateDynamicObject(19365, 1267.3212, -1666.7617, 14.2782, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[195], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[196] = CreateDynamicObject(19387, 1264.1182, -1666.7744, 14.2966, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    SetDynamicObjectMaterial(object_christmasCalendar[196], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[197] = CreateDynamicObject(19365, 1262.5998, -1665.2403, 14.2782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[197], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[198] = CreateDynamicObject(970, 1270.2376, -1644.5895, 13.0933, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[199] = CreateDynamicObject(970, 1247.5560, -1638.3889, 13.0933, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[200] = CreateDynamicObject(970, 1247.5560, -1642.5096, 13.0933, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[201] = CreateDynamicObject(19365, 1264.1921, -1662.5312, 11.5579, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[201], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[202] = CreateDynamicObject(19365, 1262.5798, -1664.0300, 14.2782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[202], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[203] = CreateDynamicObject(19365, 1269.0223, -1664.0310, 14.2782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[203], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[204] = CreateDynamicObject(19365, 1267.3623, -1662.5312, 11.5579, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[204], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[205] = CreateDynamicObject(1502, 1263.3073, -1666.8215, 12.5544, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT04
    object_christmasCalendar[206] = CreateDynamicObject(19365, 1264.2629, -1662.5312, 17.1681, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[206], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[207] = CreateDynamicObject(19365, 1267.4644, -1662.5312, 17.1681, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[207], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[208] = CreateDynamicObject(19365, 1264.0939, -1664.1993, 16.1182, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[208], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[209] = CreateDynamicObject(19365, 1264.0939, -1664.9595, 16.0881, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[209], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[210] = CreateDynamicObject(19365, 1267.3060, -1664.9595, 16.0881, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[210], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[211] = CreateDynamicObject(19365, 1267.2944, -1664.1993, 16.1182, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall013
    SetDynamicObjectMaterial(object_christmasCalendar[211], 0, 5520, "bdupshouse_lae", "sw_woodflloor", 0xFFFFFFFF);
    object_christmasCalendar[212] = CreateDynamicObject(3041, 1264.3732, -1663.3955, 12.5317, 19.8999, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ct_table
    SetDynamicObjectMaterial(object_christmasCalendar[212], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_christmasCalendar[212], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_christmasCalendar[213] = CreateDynamicObject(3041, 1267.4230, -1663.3852, 12.5599, 19.8999, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ct_table
    SetDynamicObjectMaterial(object_christmasCalendar[213], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_christmasCalendar[213], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_christmasCalendar[214] = CreateDynamicObject(19064, 1264.1018, -1663.2369, 13.4131, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[215] = CreateDynamicObject(19064, 1264.5822, -1663.2238, 13.4047, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[216] = CreateDynamicObject(19064, 1265.0526, -1663.2111, 13.3965, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[217] = CreateDynamicObject(19064, 1263.6219, -1663.2506, 13.4214, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[218] = CreateDynamicObject(19064, 1263.1210, -1663.2504, 13.4288, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[219] = CreateDynamicObject(19064, 1265.5725, -1663.1967, 13.3874, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[220] = CreateDynamicObject(19064, 1266.0328, -1663.1843, 13.3794, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[221] = CreateDynamicObject(19064, 1266.5032, -1663.1712, 13.3712, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[222] = CreateDynamicObject(970, 1265.8911, -1659.7486, 13.0992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[222], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[223] = CreateDynamicObject(19064, 1266.9332, -1663.1595, 13.3637, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[224] = CreateDynamicObject(19064, 1267.3732, -1663.1470, 13.3560, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[225] = CreateDynamicObject(19064, 1267.8236, -1663.1347, 13.3481, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[226] = CreateDynamicObject(2764, 1268.3450, -1665.9672, 12.9695, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE03
    object_christmasCalendar[227] = CreateDynamicObject(1514, 1268.3175, -1665.9626, 13.6240, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_FF_TILL
    object_christmasCalendar[228] = CreateDynamicObject(1574, 1263.1135, -1666.2042, 12.5001, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trashcan
    object_christmasCalendar[229] = CreateDynamicObject(19064, 1268.2637, -1663.1224, 13.3405, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[230] = CreateDynamicObject(19064, 1268.7535, -1663.1085, 13.3319, 0.9999, 50.4999, 91.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[231] = CreateDynamicObject(19124, 1263.6063, -1659.7436, 12.7797, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[232] = CreateDynamicObject(19124, 1268.1474, -1659.7436, 12.7797, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[233] = CreateDynamicObject(19173, 1279.3914, -1668.1391, 17.1639, -7.1999, 0.3000, -87.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_christmasCalendar[233], 0, "plätze", 90, "Tahoma", 90, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[233], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[234] = CreateDynamicObject(19172, 1267.0831, -1662.4564, 16.3341, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[234], 0, "Weihnach", 90, "Georgia", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[234], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[235] = CreateDynamicObject(19173, 1279.4493, -1669.5379, 17.1567, -7.1999, 0.3000, -87.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_christmasCalendar[235], 0, "Park", 90, "Tahoma", 90, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[235], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[236] = CreateDynamicObject(19172, 1264.5134, -1662.4564, 16.3341, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[236], 0, "ts", 90, "Georgia", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[236], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[237] = CreateDynamicObject(19172, 1263.8041, -1662.4564, 16.3341, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_christmasCalendar[237], 0, "Mützen", 90, "Georgia", 55, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[237], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[238] = CreateDynamicObject(19173, 1280.1643, -1686.8729, 17.0666, -7.1999, 0.3000, -87.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_christmasCalendar[238], 0, "plätze", 90, "Tahoma", 90, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[238], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[239] = CreateDynamicObject(19173, 1286.3974, -1660.7619, 14.2959, -0.0999, 0.0000, 90.1000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_christmasCalendar[239], 0, "<--", 90, "Arial", 90, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[239], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[240] = CreateDynamicObject(970, 1286.3940, -1657.5682, 13.1051, 0.0000, 0.0000, -90.1999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[240], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[241] = CreateDynamicObject(19173, 1280.2230, -1688.3131, 17.0591, -7.1999, 0.3000, -87.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_christmasCalendar[241], 0, "Park", 90, "Tahoma", 90, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_christmasCalendar[241], 1, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    object_christmasCalendar[242] = CreateDynamicObject(19436, 1287.3848, -1655.8187, 20.9303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
    SetDynamicObjectMaterialText(object_christmasCalendar[242], 0, "Ha", 90, "Georgia", 90, 1, 0xFF000000, 0x0, 0);
    object_christmasCalendar[243] = CreateDynamicObject(970, 1286.4018, -1646.6971, 13.1051, 0.0000, 0.0000, -90.1999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[243], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[244] = CreateDynamicObject(19124, 1286.3697, -1655.2623, 13.0997, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[245] = CreateDynamicObject(19124, 1286.3697, -1648.9613, 13.0997, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[246] = CreateDynamicObject(19064, 1286.4217, -1655.2413, 13.6162, 0.0000, 35.2999, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[247] = CreateDynamicObject(19064, 1286.4217, -1648.9202, 13.6162, 0.0000, 35.2999, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat1
    object_christmasCalendar[248] = CreateDynamicObject(970, 1284.9919, -1652.1644, 13.1051, 0.0000, 0.0000, -90.1999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[248], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[249] = CreateDynamicObject(19124, 1284.9589, -1654.4417, 13.0997, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[250] = CreateDynamicObject(19124, 1284.9589, -1649.9102, 13.0997, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_christmasCalendar[251] = CreateDynamicObject(19354, 1233.8229, -1669.3486, 12.4876, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_christmasCalendar[251], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[252] = CreateDynamicObject(970, 1234.1165, -1664.7030, 13.1061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[252], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[253] = CreateDynamicObject(837, 1243.8687, -1643.4479, 13.5950, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_1
    object_christmasCalendar[254] = CreateDynamicObject(837, 1233.7076, -1643.4479, 13.5950, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_1
    object_christmasCalendar[255] = CreateDynamicObject(837, 1235.9283, -1641.9975, 13.5950, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_1
    object_christmasCalendar[256] = CreateDynamicObject(837, 1242.5192, -1641.9975, 13.5950, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_1
    object_christmasCalendar[257] = CreateDynamicObject(970, 1234.1165, -1664.7030, 13.1061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasCalendar[258] = CreateDynamicObject(970, 1232.0567, -1666.7733, 13.1061, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[258], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[259] = CreateDynamicObject(19315, 1237.4758, -1642.9630, 13.6954, 0.0000, 0.0000, -23.7000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasCalendar[260] = CreateDynamicObject(19315, 1240.5399, -1642.9442, 13.6954, 0.0000, 0.0000, -143.8000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasCalendar[261] = CreateDynamicObject(970, 1232.0567, -1668.8541, 13.1061, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[261], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[262] = CreateDynamicObject(970, 1240.3081, -1666.7852, 13.1061, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[262], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[263] = CreateDynamicObject(19066, 1237.7563, -1643.0532, 14.1545, 0.0000, 6.4000, -5.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat3
    object_christmasCalendar[264] = CreateDynamicObject(970, 1240.3081, -1668.8767, 13.1061, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[264], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[265] = CreateDynamicObject(19354, 1238.5051, -1669.3486, 12.5076, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_christmasCalendar[265], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[266] = CreateDynamicObject(970, 1234.0968, -1670.9739, 13.1061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[266], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[267] = CreateDynamicObject(19354, 1237.3133, -1666.3280, 12.4776, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_christmasCalendar[267], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[268] = CreateDynamicObject(19354, 1233.8229, -1666.3280, 12.4776, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_christmasCalendar[268], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[269] = CreateDynamicObject(19354, 1238.5144, -1666.3280, 12.4876, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_christmasCalendar[269], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[270] = CreateDynamicObject(970, 1238.2271, -1664.7030, 13.1061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[270], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[271] = CreateDynamicObject(19354, 1237.3240, -1669.3486, 12.4976, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_christmasCalendar[271], 0, 3922, "bistro", "mp_snow", 0xFFFFFFFF);
    object_christmasCalendar[272] = CreateDynamicObject(970, 1238.2271, -1670.9739, 13.1061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_christmasCalendar[272], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_christmasCalendar[273] = CreateDynamicObject(19066, 1240.3023, -1643.1348, 14.1121, 0.0000, 6.4000, -138.7000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat3
    object_christmasCalendar[274] = CreateDynamicObject(837, 1236.5549, -1668.4688, 13.0450, 0.0000, 0.0000, 25.0999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_1
    object_christmasCalendar[275] = CreateDynamicObject(19315, 1233.8814, -1666.1737, 12.9754, 0.0000, 0.0000, -23.7000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasCalendar[276] = CreateDynamicObject(19315, 1233.7597, -1668.8602, 12.9754, 0.0000, 0.0000, -149.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasCalendar[277] = CreateDynamicObject(19315, 1239.0051, -1669.6203, 12.9754, 0.0000, 0.0000, -149.5999, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasCalendar[278] = CreateDynamicObject(19315, 1238.4765, -1666.3066, 12.9754, 0.0000, 0.0000, 20.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasCalendar[279] = CreateDynamicObject(19315, 1235.9592, -1666.2322, 12.9754, 0.0000, 0.0000, 74.9000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasCalendar[280] = CreateDynamicObject(19436, 1287.3848, -1654.3776, 20.9303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
    SetDynamicObjectMaterialText(object_christmasCalendar[280], 0, "pp", 90, "Georgia", 90, 1, 0xFF000000, 0x0, 0);
    object_christmasCalendar[281] = CreateDynamicObject(19436, 1287.3848, -1653.1372, 20.9303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
    SetDynamicObjectMaterialText(object_christmasCalendar[281], 0, "y", 90, "Georgia", 90, 1, 0xFF000000, 0x0, 0);
    object_christmasCalendar[282] = CreateDynamicObject(19436, 1287.3848, -1651.5268, 20.9303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
    SetDynamicObjectMaterialText(object_christmasCalendar[282], 0, "X", 90, "Georgia", 90, 1, 0xFF000000, 0x0, 0);
    object_christmasCalendar[283] = CreateDynamicObject(19436, 1287.3848, -1650.7661, 20.9303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
    SetDynamicObjectMaterialText(object_christmasCalendar[283], 0, "-", 90, "Georgia", 90, 1, 0xFF000000, 0x0, 0);
    object_christmasCalendar[284] = CreateDynamicObject(19436, 1287.3848, -1650.3356, 20.9303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
    SetDynamicObjectMaterialText(object_christmasCalendar[284], 0, "Ma", 90, "Georgia", 90, 1, 0xFF000000, 0x0, 0);
    object_christmasCalendar[285] = CreateDynamicObject(19436, 1287.3848, -1648.7648, 20.9303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
    SetDynamicObjectMaterialText(object_christmasCalendar[285], 0, "s", 90, "Georgia", 90, 1, 0xFF000000, 0x0, 0);
    object_christmasCalendar[286] = CreateDynamicObject(19436, 1287.3848, -1652.6062, 20.9303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASCALENDAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
    SetDynamicObjectMaterialText(object_christmasCalendar[286], 0, "e", 90, "Webdings", 90, 1, 0xFF000000, 0x0, 0);
}

CMD:findekalender(playerid) {
	new wjahr, wmonat, wday;
    getdate(wjahr, wmonat, wday);
	if((wmonat != 12 || wday > 27))
		        return SendClientMessage(playerid,COLOR_RED,"Wir befinden uns nicht in der Adventszeit!");
    SetPlayerCheckpointEx(playerid, CHRISTMASCALENDAR_COORDS, 3.0, CP_SHOWJOB1);
    SendClientMessage(playerid, COLOR_GREEN, "Der Adventskalender wurde dir auf der Karte markiert!");
    return 1;
}

CMD:adventmin(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pLevel] < 2) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du kannst erst ab Level 2 deine Adventminuten einsehen.");//3
    new wjahr, wmonat, wday;
    getdate(wjahr, wmonat, wday);
	if((wmonat != 12 || wday > 27))
		        return SendClientMessage(playerid,COLOR_RED,"Wir befinden uns nicht in der Adventszeit!");
    if (Spieler[playerid][pAdventDay] == wday) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du hast heute bereits ein Türchen geöffnet.");
    new adventmin = 90 - Spieler[playerid][pAdventMin];
    if (adventmin < 1) return SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO] {FFFFFF}Du kannst jetzt ein Adventstürchen öffnen (/Findekalender)");
    return SCMFormatted(playerid, COLOR_LIGHTRED, "[INFO] {FFFFFF}Du musst noch %i/90 Minuten warten, bis du ein Türchen öffnen kannst.", adventmin);
}

CMD:adventskalender(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pLevel] < 2) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Adventskalender ist erst ab Level 2 zugänglich.");
    new wjahr, wmonat, wday;
    getdate(wjahr, wmonat, wday);
	if((wmonat != 12 || wday > 27))
		        return SendClientMessage(playerid,COLOR_RED,"Wir befinden uns nicht in der Adventszeit!");
    // (wmonat != 12) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Adventskalender wurde nur bis zum 31.12.2023 verlängert.");
    if (!IsPlayerInRangeOfPoint(playerid, 5, CHRISTMASCALENDAR_COORDS))
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht am Adventskalender! Mit /Findekalender wird der Adventskalender auf der Karte markiert!");
    
    if (Spieler[playerid][pAdventDay] == wday) return SendClientMessage(playerid, COLOR_RED, "Du hast heute bereits ein Adventstürchen geöffnet.");
    if (Spieler[playerid][pAdventMin] < 90) return SendClientMessage(playerid, COLOR_RED, "Du kannst noch kein Adventstürchen öffnen. Benutze: /Adventmin.");

    Spieler[playerid][pAdventDay] = wday;
    Spieler[playerid][pAdventMin] = 0;
    GivePlayerGift(playerid);
    return 1;
}

stock GivePlayerGift(playerid, rValue = -1) {
    if (rValue == -1) rValue = random(1000);
    new message[245];

    switch (rValue) {
        case 0..169: {
            SetPlayerScore(playerid, ++Spieler[playerid][pLevel]);
            GameTextForPlayer(playerid, "~y~Level UP", 4000, 3);
            GivePlayerCash(playerid, 75000);
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast ein Level-Up und $75.000 hinter dem Türchen gefunden!");
            
            format(message, sizeof(message), "%s hat ein Level-Up und $75.000 im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 170..339: {
            GivePlayerCash(playerid, 100000);
            GivePlayerRP(playerid, 5);
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);

            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}+5 Respektpunkte und $100.000 {FFFFFF}hinter dem Türchen gefunden!");
            format(message, sizeof(message), "%s hat +5 Respektpunkte und $100.000 im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 340..509: {
            GivePlayerCash(playerid, 150000);
            GivePlayerRP(playerid, 3);
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}+3 Respektpunkte und $150.000 {FFFFFF}hinter dem Türchen gefunden!");
            format(message, sizeof(message), "%s hat +3 Respektpunkte und $150.000 im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 510..579: {
            GivePlayerCash(playerid, 100000);
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}$100.000 {FFFFFF}hinter dem Türchen gefunden!");
            format(message, sizeof(message), "%s hat $100.000 im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 580..629: {
            GivePlayerCash(playerid, 250000);
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}$250.000 hinter dem Türchen gefunden!");
            format(message, sizeof(message), "%s hat $250.000 im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 630..659: {
            GivePlayerCash(playerid, 350000);
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}$350.000 hinter dem Türchen gefunden!");
            format(message, sizeof(message), "%s hat $350.000 im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 660..754: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}eine Forum Ranggrafik (Geschenkejäger) {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Melde dich dafür im Forum-Thread: {FF9900}LyD | Adventstürchen (Antrag für die Belohnungen)");

            format(message, sizeof(message), "%s hat eine Forum Ranggrafik im Adventskalender gefunden.", GetName(playerid));
        }

        case 755..824: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}einen freien Namechange {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Melde dich dafür im Forum-Thread: {FF9900}LyD | Adventstürchen (Antrag für die Belohnungen)");

            format(message, sizeof(message), "%s hat einen freien Namechange im Adventskalender gefunden.", GetName(playerid));
        }

        case 825..864: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}einen Skill-Up deiner Wahl {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Melde dich dafür im Forum-Thread: {FF9900}LyD | Adventstürchen (Antrag für die Belohnungen)");

            format(message, sizeof(message), "%s hat einen Skill-Up im Adventskalender gefunden.", GetName(playerid));
        }

        case 865..904: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}Neon-Premium {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Melde dich dafür im Forum-Thread: {FF9900}LyD | Adventstürchen (Antrag für die Belohnungen)");

            format(message, sizeof(message), "%s hat Neon-Premium im Adventskalender gefunden.", GetName(playerid));
        }

        case 905..934: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}ein Wunschfahrzeug {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Melde dich dafür im Forum-Thread: {FF9900}LyD | Adventstürchen (Antrag für die Belohnungen)");

            format(message, sizeof(message), "%s hat ein Wunschfahrzeug im Adventskalender gefunden.", GetName(playerid));
        }

        case 935..949: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}Bronze Premium (1 Monat) {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Melde dich dafür im Forum-Thread: {FF9900}LyD | Adventstürchen (Antrag für die Belohnungen)");

            format(message, sizeof(message), "%s hat Bronze Premium im Adventskalender gefunden.", GetName(playerid));
        }

        case 950..969: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}75 LyD-Coins {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Die LyD-Coins wurden dir automatisch gutgeschrieben.");
            Spieler[playerid][pCoins] += 75;
            format(message, sizeof(message), "%s hat 75 LyD-Coins im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 970..984: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}100 LyD-Coins {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Die LyD-Coins wurden dir automatisch gutgeschrieben.");
            new Query[120];
            format(Query, sizeof(Query), "UPDATE `accounts` SET `userPremium` = `userPremium` + 100 WHERE `Name` = '%s'", GetName(playerid));
            mysql_pquery(Query, THREAD_DUMMY, playerid, gSQL, MySQLThreadOwner);

            format(message, sizeof(message), "%s hat 100 LyD-Coins im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 985..994: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}150 LyD-Coins {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Die LyD-Coins wurden dir automatisch gutgeschrieben.");
            new Query[120];
            format(Query, sizeof(Query), "UPDATE `accounts` SET `userPremium` = `userPremium` + 150 WHERE `Name` = '%s'", GetName(playerid));
            mysql_pquery(Query, THREAD_DUMMY, playerid, gSQL, MySQLThreadOwner);

            format(message, sizeof(message), "%s hat 150 LyD-Coins im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }

        case 995..999: {
			PlayAudioStreamForPlayer(playerid, URL_HOHO);
			ClearChat(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Du hast {FF9900}210 LyD-Coins {FFFFFF}hinter dem Türchen gefunden.");
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Adventskalender] {FFFFFF}Die LyD-Coins wurden dir automatisch gutgeschrieben.");
            new Query[120];
            format(Query, sizeof(Query), "UPDATE `accounts` SET `userPremium` = `userPremium` + 210 WHERE `Name` = '%s'", GetName(playerid));
            mysql_pquery(Query, THREAD_DUMMY, playerid, gSQL, MySQLThreadOwner);

            format(message, sizeof(message), "%s hat 210 LyD-Coins im Adventskalender gefunden. (Automatisch erhalten)", GetName(playerid));
        }
    }

    SendUCPAktenEintrag(playerid, "Server-System", GetName(playerid), message);
    format(message, sizeof(message), "[Adventinfo] {FFFFFF}%s", message);
    SendAdminMessage(COLOR_GREEN, message);
    return 1;
}

CMD:akalender(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 6) return 1;
    new value;
    if (sscanf(params, "i", value) || value < 0 || value > 999) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/akalender [WERT]");
    GivePlayerGift(playerid, value);
    return 1;
}
