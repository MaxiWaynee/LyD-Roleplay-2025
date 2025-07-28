#include <YSI\y_hooks>



// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

#define MAPS_ARMY_INTERIOR 0

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
	//Army Base mapped by Snoopy & Fernandez_

    CreateObject(19312,191.13,1870.28,21.45, 0.00,0.00,0.00);//area 51 fence
	CreateDynamicObject(3268,368.16,1961.99,16.64, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(8172,307.85,1997.83,16.81, 0.00,0.00,180.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(8172,307.75,1872.70,16.83, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3526,307.60,2017.65,16.94, 0.00,0.00,270.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3526,307.78,1994.19,16.95, 0.00,0.00,270.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3526,307.65,1967.22,16.94, 0.00,0.00,270.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3526,307.77,1930.06,16.94, 0.00,0.00,270.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3526,307.82,1895.40,16.94, 0.00,0.00,270.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3526,307.64,1858.63,16.94, 0.00,0.00,270.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(10764,307.30,2100.03,16.69, 0.00,0.00,226.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3279,352.02,1809.55,16.60, 0.00,0.00,180.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3279,285.24,1930.50,16.49, 0.00,0.00,179.99, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(10010,222.36,1681.55,2.64, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3037,188.91,1714.53,4.78, 0.00,0.00,268.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3037,188.92,1714.55,8.06, 0.00,0.00,267.99, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(10764,308.19,1770.79,16.79, 0.00,0.00,46.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(13714,120.64,1848.66,30.63, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(8038,378.88,1960.96,20.64, 0.00,0.00,182.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(8419,353.79,1948.48,5.03, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3268,368.16,1932.05,16.68, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(13190,-728.69,2388.20,130.47, 0.00,0.00,332.50, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(13190,-729.46,2387.99,125.74, 0.00,0.00,332.50, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(12911,364.27,1910.34,16.69, 0.00,0.00,103.26, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3279,331.11,1992.85,16.49, 0.00,0.00,179.99, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(3279,330.85,1902.63,16.49, 0.00,0.00,179.99, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19124,357.99,1974.17,17.28, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19124,358.00,1947.03,17.28, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19124,358.13,1919.37,17.28, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,195.84,1873.72,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,204.41,1873.68,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,223.35,1873.69,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,231.89,1873.74,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,231.93,1882.32,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,231.94,1890.91,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,231.95,1899.52,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,231.93,1908.14,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,231.95,1916.72,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,195.77,1882.25,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,195.77,1890.78,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,195.78,1899.31,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,194.67,1902.76,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,189.76,1909.94,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,218.16,1875.80,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,209.64,1875.75,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,208.39,1884.17,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,219.31,1884.30,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,220.48,1892.82,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,207.15,1892.63,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19124,206.03,1901.18,17.19, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19124,221.68,1901.35,17.19, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,231.38,1920.29,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19121,228.73,1922.92,17.15, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19124,224.79,1919.42,17.19, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19124,189.03,1919.40,17.19, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(1278,343.96,1902.08,30.72, 0.00,0.00,180.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(1278,343.93,1994.81,30.72, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(1278,363.14,1994.89,30.72, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19380,268.12,1884.27,16.55, 0.00,90.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19380,218.62,1856.56,18.06, 0.00,90.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	
	CreateDynamicObject(19313,134.85,1941.66,21.19, 0.00,0.00,0.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//army tor fixxed 1
	CreateDynamicObject(19313,285.91,1819.96,19.45, 0.00,0.00,90.00, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//army tor fixxed 2
	CreateDynamicObject(5422,216.13,1875.86,14.05, 0.00,0.00,89.80, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//army garagen tor 1
	CreateDynamicObject(5422,211.92,1875.87,14.05, 0.00,0.00,89.80, VW_MAIN, MAPS_ARMY_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//army garagen tor 1
	
	}
