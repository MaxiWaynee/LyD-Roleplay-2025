/*****************************************************************************
*
*	Projekt:		gF4A
*	Lizenz:			GNU Version 3
*	Datei:			gF4A\0system\spikes.inc
*	Nutzung:        Verwaltung von Spikes / Nagelbettern
*
*       gF4A  -  by Goldkiller
*
*****************************************************************************/

#define _include_spikes_

#define Spikes::\
	Spikes_
	
#define MAX_SPIKES 20
#define MAX_SPIKE_PICKUPS 4

#define INVALID_SPIKE 0xFFFF

#define SPIKES_PICKUP 1007
//#define SPIKES_PICKUP 1212


enum e_Spikes {
	bool:S_bUsed,
	S_iObject,
	S_iPickups[MAX_SPIKE_PICKUPS]
}

new Spikes[MAX_SPIKES][e_Spikes];

Spikes::Spikes() {
	for(new i = 0; i < sizeof(Spikes) ; i++) {
		Spikes[i][S_bUsed] = false;
		Spikes[i][S_iObject] = INVALID_OBJECT_ID;
	}
	return 1;
}

Spikes::SpikesClose() {
	for(new i = 0; i < sizeof(Spikes) ; i++) {
	    if(Spikes[i][S_bUsed]) {
	        DestroySpike(i);
	    }
	}
	return 1;
}

stock DestroySpike(spikeid) {
    Spikes[spikeid][S_bUsed] = false;
    DestroyDynamicObject(Spikes[spikeid][S_iObject]);
	for(new i = 0; i < MAX_SPIKE_PICKUPS ; i++) {
	    DestroyDynamicPickup(Spikes[spikeid][S_iPickups][i]);
	}
    Spikes[spikeid][S_iObject] = INVALID_OBJECT_ID;
	return 1;
}

stock GetClosestSpike(Float:x,Float:y,Float:z) {
	new
	    Float:distance,
	    Float:distance_ex = 10000.0,
	    Float:obj_x,
	    Float:obj_y,
	    Float:obj_z,
	    spike = INVALID_SPIKE;
	for(new i ; i < sizeof(Spikes) ; i++) {
		if( Spikes[i][S_bUsed] ) {
		    Streamer_GetFloatData( STREAMER_TYPE_OBJECT , Spikes[i][S_iObject] , E_STREAMER_X , obj_x );
		    Streamer_GetFloatData( STREAMER_TYPE_OBJECT , Spikes[i][S_iObject] , E_STREAMER_Y , obj_y );
		    Streamer_GetFloatData( STREAMER_TYPE_OBJECT , Spikes[i][S_iObject] , E_STREAMER_Z , obj_z );
		    distance = GetDistance( x , y , z ,obj_x , obj_y , obj_z);
		    if( distance <= distance_ex ) {
		        spike = i;
		        distance_ex = distance;
		    }
		}
	}
	if( distance <= 5.0 ) {
	    return spike;
	}
	return INVALID_SPIKE;
}

stock CreateSpike(Float:x , Float:y , Float:z ,Float:a, vw = -1 , interior = -1 ) {
	new
	    i,
	    spike = INVALID_SPIKE;
	for( i = 0; i < sizeof(Spikes) ; i++) {
	    if(!Spikes[i][S_bUsed]) {
	        spike = i;
	        Spikes[i][S_bUsed] = true;
	        break;
		}
	}
	if(spike == INVALID_SPIKE) return INVALID_SPIKE;
	a += 90.0;
	if( a > 360.0 ) a -= 360.0;
	new
		Float:dis1 = floatsin( -a , degrees),
		Float:dis2 = floatcos( -a , degrees);
	// 1593
	//Spikes[spike][S_iObject] = CreateDynamicObject(2587, x, y, z - 0.9, 0.0, 0.0, a - 90.0 );
	Spikes[spike][S_iObject] = CreateDynamicObject(2899, x, y, z - 0.60 , 0.0 , 0.0,a );

    Spikes[spike][S_iPickups][0] = CreateDynamicPickup( SPIKES_PICKUP , 14, x+(2.2 * dis1), y + ( 2.2 * dis2), z, vw , interior,.streamdistance = 90.0);
    Spikes[spike][S_iPickups][1] = CreateDynamicPickup( SPIKES_PICKUP , 14, x+(0.85 * dis1), y + ( 0.85 * dis2), z, vw , interior,.streamdistance = 90.0);
    Spikes[spike][S_iPickups][2] = CreateDynamicPickup( SPIKES_PICKUP , 14, x-(2.2 * dis1), y - ( 2.2 * dis2), z, vw , interior,.streamdistance = 90.0);
    Spikes[spike][S_iPickups][3] = CreateDynamicPickup( SPIKES_PICKUP , 14, x-(0.85 * dis1), y - ( 0.85 * dis2), z, vw , interior,.streamdistance = 90.0);
	for( i = 0 ; i < MAX_SPIKE_PICKUPS ; i++) {
    	Streamer_SetIntData( STREAMER_TYPE_PICKUP , Spikes[spike][S_iPickups][ i ] , E_STREAMER_EXTRA_ID , ( spike | 0x400 ) );
	}
	return spike;
}

stock Spikes_OnPlayerPickUpPickup(playerid,pickupid) {
	new
	    Float:vx,
	    Float:vy,
	    Float:vz,
	    index,
	    data;
	#pragma unused playerid,index
	data = Streamer_GetIntData( STREAMER_TYPE_PICKUP , pickupid , E_STREAMER_EXTRA_ID );
	//printf("Spikes_OnPlayerPickUpPickup(%d,%d)",playerid,pickupid);
	if( data & 0x400 ) {
	    new
	        speed,
	        vehicleid;
		vehicleid = GetPlayerVehicleID(playerid);
		if(vehicleid) {
		    GetVehicleVelocity(vehicleid,vx,vy,vz);
			speed = floatround(floatround(floatpower((vx * vx) + (vy * vy) + (vz * vz),0.5)*100)*2.0);
			// printf("speed = %d km/h",speed);
			if( speed > 10 ) {
				new panels, doors, lights, tires;
				GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
				//printf("tires davor: %d",tires);
				for(new i ; i < 4 ; i++ ) {
				    if( ! ( ( tires >> i ) & 1 ) ) {
				        tires |= random(2) << i;
				    }
				}
				// printf("tires danach: %d",tires);
				UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
			}
		    index = data & 0x3FF;
		    /*
		    for(new i ; i < 4 ; i++) {
		        if( Spikes[index][S_iPickups][i] == pickupid ) {
		        
		        }
		    }
		    */
		}
		return 1;
	}
	return 0;
}
