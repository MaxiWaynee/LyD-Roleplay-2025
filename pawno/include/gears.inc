
enum e_VehicleGear {
	VG_iGearshift, // 0 manuell, 1 automatik
	VG_iGear,
	VG_hasAutomatic
}

enum e_GearSpeedRange {
	GSR_iStart,
	GSR_iEnd,
	Float:GSR_fSpeedCap
}

#define NO_SPEED_CAP 100.0
#define TOO_HIGH_GEAR_FACTOR 0.925
#define SHIFT_DOWN_FACTOR 0.910
#define SHIFT_DOWN_UPDATE_BLOCK 60  // 60ms noch runterschalten kein OnPlayerUpdate durchlassen für gears
#define GEARSHIFT_UPDATE_BLOCK 500 // alle 500ms kann man schalten
#define TOO_HIGH_GEAR_RANDOM 6 // bzw 5, da immer -1

new const g_GearSpeedRange[][e_GearSpeedRange] = {
	{0,30,0.18},
	{31,90,0.60},
	{91,300,NO_SPEED_CAP}
};

#define GEARSHIT_INVALID -1
#define GEARSHIFT_NORMAL 0
#define GEARSHIFT_AUTOMATIC 1

#define GEARSHIFT_SHIFT_UP KEY_ANALOG_UP
#define GEARSHIFT_SHIFT_DOWN KEY_ANALOG_DOWN

new ai_VehicleGear[MAX_VEHICLES][e_VehicleGear];
new ai_BlockGearUpdate[MAX_PLAYERS];
new ai_BlockGearshiftUpdate[MAX_PLAYERS];


stock Gears_Init() {
	for(new i = 0 ; i < sizeof(ai_VehicleGear); i++) {
	    ai_VehicleGear[i][VG_iGearshift] = GEARSHIFT_NORMAL;
	    ai_VehicleGear[i][VG_iGear] = 1;
	    ai_VehicleGear[i][VG_hasAutomatic] = 0;
	}
	return 1;
}
stock Gears_GetBestGearForSpeed(speed) {
	for(new i ; i < sizeof(g_GearSpeedRange); i++) {
	    if( g_GearSpeedRange[i][GSR_iStart] <= speed <= g_GearSpeedRange[i][GSR_iEnd] ) {
	        return (i+1);
	    }
	}
	return 1;
}
stock Gears_OnVehicleSpawn(vehicleid) {
	new
	    modelid;
	modelid = GetVehicleModel(vehicleid);
	if(!Gears_ValidVehicle(modelid)) {
	    ai_VehicleGear[vehicleid][VG_iGearshift] = GEARSHIT_INVALID;
	}
    ai_VehicleGear[vehicleid][VG_iGear] = 1;
	return 1;
}
stock Gears_OnPlayerUpdate(playerid) {
	new
	    tick,
		vehicleid;
	tick = GetTickCount();
	if ( GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
		if ( (vehicleid = GetPlayerVehicleID( playerid ))) {
			if( ai_VehicleGear[vehicleid][VG_iGearshift] == GEARSHIFT_NORMAL ) {
			    if( tick <= ai_BlockGearUpdate[playerid] ) {
			        //SendClientMessage(playerid, (random(0xFFFFFF) << 8 | 0xFF),"Gears_OnPlayerUpdate ai_BlockGearUpdate");
			        return 1;
			    }
				new
				    speed,
				    gear,
				    best_gear;
			    speed = GetPlayerVehicleSpeed(playerid);
			    if(speed) {
					gear = ai_VehicleGear[vehicleid][VG_iGear];
					best_gear = Gears_GetBestGearForSpeed(speed);
					if( 1 <= gear < best_gear ) {
					    new
					        Float:fLength,
					        Float:fSpeedCap,
							Float:fX,
							Float:fY,
							Float:fZ,
							Float:fVX,
							Float:fVY,
							Float:fVZ;
						GetVehiclePos(vehicleid, fX, fY, fZ );
						GetVehicleVelocity(vehicleid, fVX, fVY, fVZ );
						fSpeedCap = g_GearSpeedRange[( gear - 1 )][GSR_fSpeedCap];
						if ( !IsPlayerInRangeOfPoint( playerid, fSpeedCap + 0.05, fX + fVX, fY + fVY, fZ + fVZ ) ) {
							fLength = floatsqroot( ( fVX * fVX ) + ( fVY * fVY ) + ( fVZ * fVZ ) );
							if( fLength != 0.0 ) {
							    if( fSpeedCap < NO_SPEED_CAP ) {
									fVX = ( fVX / fLength ) * fSpeedCap;
									fVY = ( fVY / fLength ) * fSpeedCap;
									fVZ = ( fVZ / fLength ) * fSpeedCap;
							    }
								SetVehicleVelocity(vehicleid,fVX,fVY,fVZ);
								//format(String,sizeof(String),"** fLength %.4f fNewLength %.4f GSR_fSpeedCap %.3f",fLength,fNewLength,fSpeedCap);
							    //SendClientMessage(playerid, (random(0xFFFFFF) << 8 | 0xFF),String);
							}
						}
					}
					else if( gear > best_gear ) {
					    if( speed <= ( g_GearSpeedRange[( gear - 1 )][GSR_iStart] - 5)) {
						    // Zu hoher Gang.
						    // Je weiter der optimale Gang vom aktuellen entfernt ist,desto öfter wird beschleunigung gebremst
						    new
						        rvalue = TOO_HIGH_GEAR_RANDOM - abs( best_gear - gear );
							if( random(rvalue) == 0 ) {
							    new
							        Float:fLength,
							        Float:fSpeedCap,
									Float:fVX,
									Float:fVY,
									Float:fVZ;
								GetVehicleVelocity(vehicleid, fVX, fVY, fVZ );
								fSpeedCap = g_GearSpeedRange[( gear - 1 )][GSR_fSpeedCap];

								fLength = floatsqroot( ( fVX * fVX ) + ( fVY * fVY ) + ( fVZ * fVZ ) );
								fSpeedCap = TOO_HIGH_GEAR_FACTOR * fLength;
								if( fLength != 0.0 ) {
									fVX = ( fVX / fLength ) * fSpeedCap;
									fVY = ( fVY / fLength ) * fSpeedCap;
									fVZ = ( fVZ / fLength ) * fSpeedCap;

									SetVehicleVelocity(vehicleid,fVX,fVY,fVZ);
								}
							}
				   		}
					}
				}
			}
		}
	}
	return 0;
}
stock Gears_OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
	    new
	        tick,
	        vehicleid = GetPlayerVehicleID(playerid);
		if( ai_VehicleGear[vehicleid][VG_iGearshift] == GEARSHIFT_NORMAL ) {
		    if( PRESSED(GEARSHIFT_SHIFT_UP) || PRESSED(GEARSHIFT_SHIFT_DOWN)) {
				tick = GetTickCount();
				if( ai_BlockGearshiftUpdate[playerid] > tick ) {
				    return SendClientMessage(playerid,COLOR_RED,"Schaltung blockiert");
				}
				//
			    if( PRESSED(GEARSHIFT_SHIFT_UP)) {
					if( ai_VehicleGear[vehicleid][VG_iGear] >= sizeof(g_GearSpeedRange)) {
					    // maximum erreicht
					    return 0;
					}
			        ai_VehicleGear[vehicleid][VG_iGear]++;
			    }
			    else if( PRESSED(GEARSHIFT_SHIFT_DOWN) ) {
					if( ai_VehicleGear[vehicleid][VG_iGear] <= 1 ) {
					    // minimum erreicht
					    return 0;
					}
				    new
				        Float:fSpeedCap,
				        Float:fLength,
						Float:fVX,
						Float:fVY,
						Float:fVZ;
					GetVehicleVelocity(vehicleid, fVX, fVY, fVZ );
					
					fLength = floatsqroot( ( fVX * fVX ) + ( fVY * fVY ) + ( fVZ * fVZ ) );
					fSpeedCap = SHIFT_DOWN_FACTOR * fLength;
					if( fLength != 0.0 ) {
						fVX = ( fVX / fLength ) * fSpeedCap;
						fVY = ( fVY / fLength ) * fSpeedCap;
						fVZ = ( fVZ / fLength ) * fSpeedCap;
						SetVehicleVelocity(vehicleid,fVX,fVY,fVZ);
						ai_BlockGearUpdate[playerid] = tick + SHIFT_DOWN_UPDATE_BLOCK; //
					}
			        ai_VehicleGear[vehicleid][VG_iGear]--;
			    }
		     	ai_BlockGearshiftUpdate[playerid] = tick + GEARSHIFT_UPDATE_BLOCK;
		        Gear_UpdateGearDraw(playerid,vehicleid);
		    }
		}
	}
	return 1;
}

stock Gear_UpdateGearDraw(playerid,vehicleid) {
	new
	    gear,
	    String[24];
	if( ai_VehicleGear[vehicleid][VG_iGearshift] == GEARSHIFT_NORMAL ) {
	    gear = ai_VehicleGear[vehicleid][VG_iGear];
	    for(new i = 1 ; i < ( sizeof(g_GearSpeedRange) + 1 ) ; i++) {
			if( i == gear ) {
				format(String,sizeof(String),"%s~g~%d ",String,i);
			}
			else {
				format(String,sizeof(String),"%s~w~%d ",String,i);
			}
	    }
	    strtrim(String,"",string_edges:trim_right);
	    format(String,sizeof(String),String);
	}
	else if( ai_VehicleGear[vehicleid][VG_iGearshift] == GEARSHIFT_AUTOMATIC ) {
		String = "   ~p~D";
	}
	PlayerTextDrawSetString(playerid,g_PlayerTacho[playerid][pt_Gear],String);
	return 1;
}

stock Gears_ValidVehicle(modelid) {
	if( IsACar(modelid)) {
	    return 1;
	}
	if( IsATruck(modelid)) {
	    return 1;
	}
	if( IsABike(modelid)) {
	    return 1;
	}
	if( IsACarmA(modelid)) {
	    return 1;
	}
	return 0;
}

COMMAND:automatikgetriebe(playerid,params[]) {
	#pragma unused params
	new
	    vehicleid,
	    modelid,
		speed;
	if( !IsPlayerInRangeOfPoint(playerid,15.0,1359.5510,-1651.0251,13.4164)) {
	    return SendClientMessage(playerid,COLOR_RED,"Hier kannst du kein Automatikgetriebe kaufen");
	}
	vehicleid = GetPlayerVehicleID(playerid);
	if(!vehicleid) {
	    return SendClientMessage(playerid,COLOR_RED,"Du kannst diese Funktion nur in einem Fahrzeug nutzen");
	}
	speed = GetPlayerVehicleSpeed(playerid);
	if(speed > 0) {
	    return SendClientMessage(playerid,COLOR_RED,"Du kannst diese Funktion nur in einem stehendem Fahrzeug anwenden");
	}
	modelid = GetVehicleModel(vehicleid);
	if(!Gears_ValidVehicle(modelid)) {
	    return SendClientMessage(playerid,COLOR_RED,"Dieses Fahrzeug kann keine zusätzliche Automatikschaltung besitzen");
	}
    /*
    if( ai_VehicleGear[vehicleid][VG_hasAutomatic] == 1 ) {
	    return SendClientMessage(playerid, COLOR_RED, "Dieses Fahrzeug besitzt bereits eine Automatik Schaltung");
    }
    */

    if( Spieler[playerid][pCash] < 50000 ) {
    	return SendClientMessage(playerid,COLOR_RED,"Du besitzt nicht genug Geld für den Kauf des Automatikgetriebes (50.000$)");
    }
    GivePlayerCash(playerid,-50000);
    ai_VehicleGear[vehicleid][VG_hasAutomatic] = 1;
    Spieler[playerid][pAutomatik] = 1;
    SendClientMessage(playerid,COLOR_GREEN,"Du hast das Automatikgetriebe für das Fahrzeug gekauft! Befehl: /At (-50.000$)");
    Gear_UpdateGearDraw(playerid,vehicleid);
	return 1;
}

COMMAND:at(playerid,params[]) {
	#pragma unused params
	new
	    vehicleid,
	    modelid,
		speed;
	vehicleid = GetPlayerVehicleID(playerid);
	if(!vehicleid) {
	    return SendClientMessage(playerid,COLOR_RED,"Du kannst diese Funktion nur in einem Fahrzeug nutzen");
	}
	if(Spieler[playerid][pAutomatik] == 0 ) {
 		return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Automatikgetriebe!");
	}
	speed = GetPlayerVehicleSpeed(playerid);
	if(speed > 0) {
	    return SendClientMessage(playerid,COLOR_RED,"Du kannst diese Funktion nur in einem stehendem Fahrzeug anwenden");
	}
	modelid = GetVehicleModel(vehicleid);
	if(!Gears_ValidVehicle(modelid)) {
	    return SendClientMessage(playerid,COLOR_RED,"Dieses Fahrzeug hat keine Schaltung");
	}
    /*
    if( ai_VehicleGear[vehicleid][VG_hasAutomatic] == 0 ) {
	    return SendClientMessage(playerid, COLOR_RED, "Dieses Fahrzeug besitzt bereits keine Automatik Schaltung");
    }
	*/

	if( ai_VehicleGear[vehicleid][VG_iGearshift] == GEARSHIFT_AUTOMATIC ) {
	    ai_VehicleGear[vehicleid][VG_iGearshift] = GEARSHIFT_NORMAL;
	    ai_VehicleGear[vehicleid][VG_iGear] = 1;
		SendClientMessage(playerid,COLOR_YELLOW,"Schaltung geändert auf: Manuell");
	}
	else if(ai_VehicleGear[vehicleid][VG_iGearshift] == GEARSHIFT_NORMAL) {
	    ai_VehicleGear[vehicleid][VG_iGearshift] = GEARSHIFT_AUTOMATIC;
		SendClientMessage(playerid,COLOR_YELLOW,"Schaltung geändert auf: Automatik");
	}
	Gear_UpdateGearDraw(playerid,vehicleid);
	return 1;
}
