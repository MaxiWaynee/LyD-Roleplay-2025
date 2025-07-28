#include <YSI\y_hooks>

CMD:pufeuer(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 18690, 1, 0.200000, 0.000000, -1.600000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 1.000000 ); // deer01 - haustier
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}
CMD:wasserfallp(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 18720, 1, 1.000000, 0.000000, 0.100000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000 ); // deer01 - haustier
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}
CMD:glanzt(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 18724, 1, 0.000000, 0.000000, -1.700000, 0.000000, 0.000000, 0.000000, 50.000000, 50.000000, 1.000000 ); // deer01 - haustier
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}
CMD:glanzs(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 18710, 1, 0.400000, 0.000000, -1.500000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000 ); // deer01 - haustier
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}
CMD:atanke(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 1676, 1, 0.290895, 0.000000, -0.004422, 357.079620, 86.866310, 358.401214, 1.000000, 1.000000, 1.000000 ); // deer01 - haustier
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}
CMD:ahaare(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 19274, 2, 0.090415, -0.013583, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000 ); //Haare
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}
CMD:akuh(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 11470, 15, -0.043005, 0.000000, 0.160083, 350.285247, 359.338409, 167.046310, 1.000000, 1.000000, 1.000000 ); // des_bigbull - kuhh
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}

CMD:cjkopf(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 18963, 2, 0.091483, -0.012514, 0.000000, 0.000000, 93.091644, 90.000000, 2.000000, 2.000000, 2.000000 ); // CJElvisHead - gesicht cj
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}

CMD:serverengel(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 345, 1, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000 ); // missile - engel
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}

CMD:bankraubtasche(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 1550, 15, 0.000000, 0.280000, -0.310000, 0.000000, 15.000000, 0.000000, 1.000000, 1.000000, 1.000000 );
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}
CMD:aosterei(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 19341, 1, -0.324815, 0.027729, 0.000000, 262.441711, 98.712211, 153.388839, 2.099999, 2.099999, 2.099999  ); // osterei
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}
CMD:papagei(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 19078, 1, -1.200000, -0.226378, -0.024134, 0.000000, 357.571014, 0.000000, 8.000000, 8.000000, 7.000000 ); // TheParrot1 - papagei
	    SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
	}
	return 1;
}

CMD:ageschenk(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 19056, 1, -0.266277, 0.141012, 0.000000, 0.000000, 87.117065, 0.000000, 1.299999, 1.299999, 1.600000 ); // EnExMarker3 - admin marker
	    SendClientMessage(playerid,COLOR_YELLOW,"Aktiviert");
	}
	return 1;
}

CMD:amap(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 19167, 1, 0.328450, 0.412087, 0.000000, 271.398742, 4.000000, 269.222015, 4.000000, 4.000000, 4.000000 ); // EnExMarker3 - admin marker
	    SendClientMessage(playerid,COLOR_YELLOW,"Aktiviert");
	}
	return 1;
}

CMD:asamp(playerid,params[]){
 	if( !(Spieler[playerid][pAdmin] >= 6) ) {
		return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die nötigen Rechte!");
	}
	/*
	if( GetPlayerSkin(playerid) != 280 ) {
		return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
	}
	*/
	if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) {
	    RemovePlayerAttachedObject(playerid,0);
	    SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
	}
	else {
		SetPlayerAttachedObject( playerid, 0, 18749, 1, 1.003577, 0.040898, 0.005981, 191.017028, 92.195304, 344.806304, 1.000000, 1.000000, 1.000000 ); // EnExMarker3 - admin marker
	    SendClientMessage(playerid,COLOR_YELLOW,"Aktiviert");
	}
	return 1;
}