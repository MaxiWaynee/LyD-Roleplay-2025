/*
	System kierunkowskazów by xqz
	24.06.2013r. 13:17 :)
*/

#include a_samp

new Indicators_xqz[MAX_VEHICLES][6];
new Indicators_timer[MAX_VEHICLES];

stock Blinker_Init() {
	for (new i = 0; i < sizeof(Indicators_xqz); i++) {
		Indicators_timer[i] = INVALID_TIMER_ID;
		for (new j; j < 6; j++) Indicators_xqz[i][j] = INVALID_OBJECT_ID;
	}
	return 1;
}

stock SetVehicleIndicator(vehicleid, leftindicator = 0, rightindicator = 0) {
	if (!leftindicator && !rightindicator) return false;
	new Float:_vX[2], Float:_vY[2], Float:_vZ[2];
	if (Indicators_timer[vehicleid] != INVALID_TIMER_ID) {
		DestroyBlinker(vehicleid, 0);
		DestroyBlinker(vehicleid, 1);
	}

	if (rightindicator && leftindicator) {
	    if (IsTrailerAttachedToVehicle(vehicleid)) {
	        new omg = GetVehicleModel(GetVehicleTrailer(vehicleid));
            GetVehicleModelInfo(omg, VEHICLE_MODEL_INFO_SIZE, _vX[0], _vY[0], _vZ[0]);
 			Indicators_xqz[vehicleid][4] = CreateObject(19294, 0, 0, 0,0,0,0);
			AttachObjectToVehicle(Indicators_xqz[vehicleid][4], GetVehicleTrailer(vehicleid),  _vX[0]/2.4, -_vY[0]/3.35, -1.0 ,0,0,0);

 			Indicators_xqz[vehicleid][5] = CreateObject(19294, 0, 0, 0,0,0,0);
			AttachObjectToVehicle(Indicators_xqz[vehicleid][5], GetVehicleTrailer(vehicleid),  -_vX[0]/2.4, -_vY[0]/3.35, -1.0 ,0,0,0);
		}

	    GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, _vX[0], _vY[0], _vZ[0]);
 		Indicators_xqz[vehicleid][0] = CreateObject(19294, 0, 0, 0,0,0,0);
		AttachObjectToVehicle(Indicators_xqz[vehicleid][0], vehicleid,  _vX[0]/2.25, _vY[0]/2.25, 0.1 ,0,0,0);
 		Indicators_xqz[vehicleid][1] = CreateObject(19294, 0, 0, 0,0,0,0);
		AttachObjectToVehicle(Indicators_xqz[vehicleid][1], vehicleid,  _vX[0]/2.25, -_vY[0]/2.25, 0.1 ,0,0,0);
		// rechts
	    GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, _vX[0], _vY[0], _vZ[0]);
 		Indicators_xqz[vehicleid][2] = CreateObject(19294, 0, 0, 0,0,0,0);
		AttachObjectToVehicle(Indicators_xqz[vehicleid][2], vehicleid,  -_vX[0]/2.25, _vY[0]/2.25, 0.1 ,0,0,0);
 		Indicators_xqz[vehicleid][3] = CreateObject(19294, 0, 0, 0,0,0,0);
		AttachObjectToVehicle(Indicators_xqz[vehicleid][3], vehicleid,  -_vX[0]/2.25, -_vY[0]/2.25, 0.1 ,0,0,0);
	}
	else if(rightindicator)
	{
	    if(IsTrailerAttachedToVehicle(vehicleid))
	    {
	        new omg = GetVehicleModel(GetVehicleTrailer(vehicleid));
            GetVehicleModelInfo(omg, VEHICLE_MODEL_INFO_SIZE, _vX[0], _vY[0], _vZ[0]);
 			Indicators_xqz[vehicleid][4] = CreateObject(19294, 0, 0, 0,0,0,0);
			AttachObjectToVehicle(Indicators_xqz[vehicleid][4], GetVehicleTrailer(vehicleid),  _vX[0]/2.4, -_vY[0]/3.35, -1.0 ,0,0,0);
		}
		
	    GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, _vX[0], _vY[0], _vZ[0]);
 		Indicators_xqz[vehicleid][0] = CreateObject(19294, 0, 0, 0,0,0,0);
		AttachObjectToVehicle(Indicators_xqz[vehicleid][0], vehicleid,  _vX[0]/2.25, _vY[0]/2.25, 0.1 ,0,0,0);
 		Indicators_xqz[vehicleid][1] = CreateObject(19294, 0, 0, 0,0,0,0);
		AttachObjectToVehicle(Indicators_xqz[vehicleid][1], vehicleid,  _vX[0]/2.25, -_vY[0]/2.25, 0.1 ,0,0,0);
		Indicators_timer[vehicleid] = SetTimerEx("DestroyBlinker",2000,false,"dd",vehicleid,1);
	}
	else if(leftindicator)
	{
	    if(IsTrailerAttachedToVehicle(vehicleid))
	    {
	    	new omg = GetVehicleModel(GetVehicleTrailer(vehicleid));
            GetVehicleModelInfo(omg, VEHICLE_MODEL_INFO_SIZE, _vX[0], _vY[0], _vZ[0]);
 			Indicators_xqz[vehicleid][5] = CreateObject(19294, 0, 0, 0,0,0,0);
			AttachObjectToVehicle(Indicators_xqz[vehicleid][5], GetVehicleTrailer(vehicleid),  -_vX[0]/2.4, -_vY[0]/3.35, -1.0 ,0,0,0);
		}

	    GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, _vX[0], _vY[0], _vZ[0]);
 		Indicators_xqz[vehicleid][2] = CreateObject(19294, 0, 0, 0,0,0,0);
		AttachObjectToVehicle(Indicators_xqz[vehicleid][2], vehicleid,  -_vX[0]/2.25, _vY[0]/2.25, 0.1 ,0,0,0);
 		Indicators_xqz[vehicleid][3] = CreateObject(19294, 0, 0, 0,0,0,0);
		AttachObjectToVehicle(Indicators_xqz[vehicleid][3], vehicleid,  -_vX[0]/2.25, -_vY[0]/2.25, 0.1 ,0,0,0);
		Indicators_timer[vehicleid] = SetTimerEx("DestroyBlinker",2000,false,"dd",vehicleid,0);
	}

	Streamer_ProcessActiveItems();
	return 1;
}

stock Blinker_OnPlayerKeyStateChange(playerid,newkeys, oldkeys)
{
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == 2)
	{
		new
		    vid = GetPlayerVehicleID(playerid);
	   	if( IsACar(vid) )
	   	{
			if(PRESSED(KEY_LOOK_RIGHT))
			{
                DestroyBlinker(vid,0);
				SetVehicleIndicator(vid,0,1);
			}
			if(PRESSED(KEY_LOOK_LEFT))
			{
                DestroyBlinker(vid,1);
				SetVehicleIndicator(vid,1,0);
			}
			return 1;
		}
	}
	return 0;
}

stock GetVehicleIndicator(vehicleid) {
	if( Indicators_xqz[vehicleid][2] != INVALID_OBJECT_ID && Indicators_xqz[vehicleid][0] != INVALID_OBJECT_ID ) {
	    return 3;
	}
	if( Indicators_xqz[vehicleid][0] != INVALID_OBJECT_ID ) {
	    return 1;
	}
	if( Indicators_xqz[vehicleid][2] != INVALID_OBJECT_ID ) {
	    return 2;
	}
    return 0;
}

forward DestroyBlinker(vehicleid,modus);
public DestroyBlinker(vehicleid,modus) {
	if (Indicators_timer[vehicleid] != INVALID_TIMER_ID) KillTimer(Indicators_timer[vehicleid]);
	Indicators_timer[vehicleid] = INVALID_TIMER_ID;
	if(modus == 0 ) {
		if(Indicators_xqz[vehicleid][2]) {
			DestroyObject(Indicators_xqz[vehicleid][2]);
			Indicators_xqz[vehicleid][2] = INVALID_OBJECT_ID;
			DestroyObject(Indicators_xqz[vehicleid][3]);
			Indicators_xqz[vehicleid][3] = INVALID_OBJECT_ID;
			DestroyObject(Indicators_xqz[vehicleid][5]);
			Indicators_xqz[vehicleid][5] = INVALID_OBJECT_ID;
		}
	}
	else if(modus == 1 ) {
		if(Indicators_xqz[vehicleid][0]) {
			DestroyObject(Indicators_xqz[vehicleid][0]);
			Indicators_xqz[vehicleid][0] = INVALID_OBJECT_ID;
			DestroyObject(Indicators_xqz[vehicleid][1]);
			Indicators_xqz[vehicleid][1] = INVALID_OBJECT_ID;
			DestroyObject(Indicators_xqz[vehicleid][4]);
			Indicators_xqz[vehicleid][4] = INVALID_OBJECT_ID;
		}
	}
	return 1;
}

stock Blinker_OnVehicleDeath(vehicleid,killerid) {
	#pragma unused killerid
	DestroyBlinker(vehicleid,0);
	DestroyBlinker(vehicleid,1);
	return 1;
}

/*
stock IsAPlane(carid2)
{
	new carid = GetVehicleModel(carid2);
	if(carid == 592 || carid == 577 || carid == 511 || carid == 512 || carid == 593 || carid == 520 || carid == 553 || carid == 476 || carid == 519 || carid == 460 || carid == 513) return 1;
	return 0;
}

stock IsABoat(carid)
{
	new modelid = GetVehicleModel(carid);
	if(modelid == 430 || modelid == 446 || modelid == 452 || modelid == 453 || modelid == 454 || modelid == 472 || modelid == 473 || modelid == 484 || modelid == 493 || modelid == 595)
	{
		return 1;
	}
	return 0;
}*/
