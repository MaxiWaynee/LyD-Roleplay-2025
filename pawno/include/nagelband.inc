////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Credits:
// Script erstellt von Stas
// Offizieller Scripter der Xtreme - RolePlay - Community
// www.xtreme-roleplay.eu
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Einstellungen
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX_NAGELBAENDER 15 // Maximale Anzahl von Nagelbaendern
#define MAX_STRASSENSPERREN 15 // Maximale Anzahl von Strassensperren
#define NAGELBAND_TIMER_INTERVALL 500 // Intervall für das Vergleichen der SpielerPosition und der Nagelband~(in Milliesekunden)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// globale Variablen
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum eNagelBand {
	ID, Float:NagelBandX, Float:NagelBandY, Float:NagelBandZ, nErstellt
};
new NagelBand[MAX_NAGELBAENDER][eNagelBand];
enum eStrassensperre {
	ID, Float:StrassensperreX, Float:StrassensperreY, Float:StrassensperreZ, sErstellt
};
new Strassensperre[MAX_STRASSENSPERREN][eStrassensperre];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CallBacks
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
forward NagelBand_Timer();
public NagelBand_Timer() {
 	for (new playerid = 0; playerid < MAX_PLAYERS; playerid++) {
 		if(!IsPlayerInAnyVehicle(playerid) || IsPlayerNPC(playerid)) continue;
		for(new i = 0; i < sizeof(NagelBand); i++) {
			if(NagelBand[i][nErstellt] == 1) {
				if(IsPlayerInRangeOfPoint(playerid, 4.0, NagelBand[i][NagelBandX], NagelBand[i][NagelBandY], NagelBand[i][NagelBandZ])) {
				    if(IsPlayerInAnyVehicle(playerid)) {
				        new panels, doors, lights, tires;
						GetVehicleDamageStatus(GetPlayerVehicleID(playerid), panels, doors, lights, tires);
						tires = encode_tires(1, 1, 1, 1);
						UpdateVehicleDamageStatus(GetPlayerVehicleID(playerid), panels, doors, lights, tires);
					}
				}
			}
		}
	}
	return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funktionen
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Nagelband
stock AddNagelBand(playerid) {
	new Float:x, Float:y, Float:z, Float:a;
	GetPlayerPos(playerid,x,y,z);
	GetPlayerFacingAngle(playerid, a);
	z -= 0.89;
	for(new i = 0; i < sizeof(NagelBand); i++) {
  	    if(NagelBand[i][nErstellt] == 0) {
			NagelBand[i][NagelBandX] = x;
		    NagelBand[i][NagelBandY] = y;
		    NagelBand[i][NagelBandZ] = z;
		    NagelBand[i][nErstellt] = 1;
		    NagelBand[i][ID] = CreateDynamicObject(2899, x, y, z, 0.0, 0.0, a - 90.0);
		    return 1;
		}
	}
	return 0;
}
stock RemoveNagelBand(playerid) {
   	for(new i = 0; i < sizeof(NagelBand); i++) {
		if(IsPlayerInRangeOfPoint(playerid, 3, NagelBand[i][NagelBandX], NagelBand[i][NagelBandY], NagelBand[i][NagelBandZ])) {
			if(NagelBand[i][nErstellt] == 1) {
				NagelBand[i][nErstellt] = 0;
    			NagelBand[i][NagelBandX] = 0.0;
		        NagelBand[i][NagelBandY] = 0.0;
	         	NagelBand[i][NagelBandZ] = 0.0;
           		DestroyDynamicObject(NagelBand[i][ID]);
             	return 1;
  	        }
  	    }
  	}
   	return 0;
}
stock RemoveAllNagelBand() {
   	for(new i = 0; i < sizeof(NagelBand); i++) {
		if(NagelBand[i][nErstellt] == 1) {
			NagelBand[i][nErstellt] = 0;
			NagelBand[i][NagelBandX] = 0.0;
   			NagelBand[i][NagelBandY] = 0.0;
     		NagelBand[i][NagelBandZ] = 0.0;
    		DestroyDynamicObject(NagelBand[i][ID]);
  	    }
  	}
   	return 0;
}
stock CountNagelBand() {
   	new anzahl = 0;
	for(new i = 0; i < sizeof(NagelBand); i++) {
		if(NagelBand[i][nErstellt] == 1) anzahl++;
  	}
   	return anzahl;
}
// Straßensperre
stock AddStrassensperre(playerid) {
	new Float:x, Float:y, Float:z, Float:a;
	GetPlayerPos(playerid,x,y,z);
	GetPlayerFacingAngle(playerid, a);
	for(new i = 0; i < sizeof(Strassensperre); i++) {
  	    if(Strassensperre[i][sErstellt] == 0) {
			Strassensperre[i][StrassensperreX] = x;
		    Strassensperre[i][StrassensperreY] = y;
		    Strassensperre[i][StrassensperreZ] = z;
		    Strassensperre[i][sErstellt] = 1;
		    Strassensperre[i][ID] = CreateDynamicObject(1459, x, y, z, 0.0, 0.0, a - 180.0);
		    return 1;
		}
	}
	return 0;
}
stock RemoveStrassensperre(playerid) {
   	for(new i = 0; i < sizeof(Strassensperre); i++) {
		if(Strassensperre[i][sErstellt] == 1) {
			if(IsPlayerInRangeOfPoint(playerid, 3, Strassensperre[i][StrassensperreX], Strassensperre[i][StrassensperreY], Strassensperre[i][StrassensperreZ])) {
				Strassensperre[i][sErstellt] = 0;
    			Strassensperre[i][StrassensperreX] = 0.0;
		        Strassensperre[i][StrassensperreY] = 0.0;
	         	Strassensperre[i][StrassensperreZ] = 0.0;
           		DestroyDynamicObject(Strassensperre[i][ID]);
             	return 1;
  	        }
  	    }
  	}
   	return 0;
}
stock RemoveAllStrassensperre() {
   	for(new i = 0; i < sizeof(Strassensperre); i++) {
		if(Strassensperre[i][sErstellt] == 1) {
			Strassensperre[i][sErstellt] = 0;
			Strassensperre[i][StrassensperreX] = 0.0;
   			Strassensperre[i][StrassensperreY] = 0.0;
     		Strassensperre[i][StrassensperreZ] = 0.0;
    		DestroyDynamicObject(Strassensperre[i][ID]);
  	    }
  	}
   	return 0;
}
stock CountStrassensperre() {
   	new anzahl = 0;
	for(new i = 0; i < sizeof(Strassensperre); i++) {
		if(Strassensperre[i][sErstellt] == 1) anzahl++;
  	}
   	return anzahl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// encode - Umwandlung
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
encode_tires(tires1, tires2, tires3, tires4) {

	return tires1 | (tires2 << 1) | (tires3 << 2) | (tires4 << 3);

}
