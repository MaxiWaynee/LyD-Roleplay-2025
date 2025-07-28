/*
 $ Latest Update :				22 / 10 / 2010
 $ gDrop by :					Daniel "Goldkiller" ( gta-goldkiller [at] web.de )
 $ Supported SAMP Version:  	( 0.2-* & 0.3a ) 0.3b
 $ Visit :                  	www.san-vice.de.vu
 
 $ Usefull functions :          Mabako
*/
#define MONEY_PACKET 1212
#define MAX_MONEY_DROP 500000
#define MAX_MUNI_DROP 5000

#define MONEY_PACKET_COLOR 0x228B22FE
#define MONEY_PACKET_DISTANCE 18.0

#define DESTROY_COUNT 6

enum e_DropItem {
	DI_iExtra, // Weapon | Munition   ||    Money
	DI_iFlag,
	
	DI_iPlayerID,
	Float:DI_fX,
	Float:DI_fY,
	Float:DI_fZ
};
	
new DropItems[MAX_PICKUPS][e_DropItem];


enum ( <<= 1) {
	e_Flag_MoneyDrop = 1,
	e_Flag_WeaponDrop
}


new const PickupWeapons[] = // by Mabako
{
	-1, // no fists
	331, // - Brass Knuckles
	333, // Golf Club
	334, // Night Stick
	335, // Knife
	336, // baseball bat
	337, // shovel
	338, // pool cue
	339, // katama
	341, // chainsaw
	321, // regular dildo
	322, // white dildo
	323, // Medium, white vibrator
	324, // smaill, silver vibrator
	325, // flowers
	326, // cane
	342, // grendade
	343, // tear gas
	344, // molotov
	-1, // RPG rocket - we can't pick up those, do we oO
	-1, // Heat-Seeking Rocket
	-1, // Hydra rocket
	346, // colt 45
	347, // colt 45 + silencer
	348, // deagle
	349, // shotgun
	350, // sawn-off
	351, // spaz
	352, // micro-uzi
	353, // mp5
	355, // ak47
	356, // m4
	372, // tec9
	357, // country rifle
	358, // sniper rifle
	359, // rocket launcher
	360, // heat-seeking rocket launcher
	361, // flamethrower
	362, // minigun
	363, // sachtel charges
	-1, // detonator
	365, // spray can
	366, // fire extinguisher
	367, // camera
	-1, // night-vision goggles
	-1, // heat-vision goggles
	371 // parachute
};
stock DestroyDropItem(pickup) {
	DropItems[pickup][DI_iExtra] = 0;
	DropItems[pickup][DI_iPlayerID] = INVALID_PLAYER_ID;
	
	DropItems[pickup][DI_fX] = 0.0;
	DropItems[pickup][DI_fY] = 0.0;
	DropItems[pickup][DI_fZ] = 0.0;

    DestroyPickup(pickup);
	return 1;
}

stock DeletePlayerDropItem(playerid) {
	for(new i ; i < sizeof(DropItems) ; i++) {
	    if( DropItems[i][DI_iPlayerID] == playerid ) {
	        DestroyDropItem(playerid);
		    return 1;
	    }
	}
	return 0;
}
stock DropWeapon(playerid) {
	new
	    iPickup,
	    _tmp,
	    iWeapon,
	    iSlot,
	    iMuni,
	    Float:fX,
	    Float:fY,
		Float:fZ;
    iWeapon = GetPlayerWeapon(playerid);
	if(PickupWeapons[iWeapon] == -1) {
	    return 0;
	}
	//printf("iWeapon %d",iWeapon);
    iSlot = GetWeaponSlot(iWeapon);
	switch(iWeapon) {
	    case 27,39,46,40, 1..15: {
	        return 0;
	    }
	}
	GetPlayerWeaponData(playerid,iSlot,_tmp,iMuni);
	//printf("iSlot %d _tmp %d iMuni %d",iSlot,_tmp,iMuni);
	GetPlayerPos(playerid,fX,fY,fZ);
	fX = fX + random(2) - random(2);
	fY = fY + random(2) - random(2);
	if(iMuni > MAX_MUNI_DROP) {
	    iMuni = MAX_MUNI_DROP;
	}
	iPickup = CreatePickup(PickupWeapons[iWeapon],1,fX,fY,fZ, GetPlayerVirtualWorld(playerid) );
	SetTimerEx("pickupidw",15000,false,"i",iPickup);
	if(iPickup == -1) return 0;
	DropItems[iPickup][DI_iFlag]   = e_Flag_WeaponDrop;
	DropItems[iPickup][DI_iExtra]   = iWeapon | ( iMuni << 8 );
	DropItems[iPickup][DI_iPlayerID] = playerid;
	DropItems[iPickup][DI_fX] = fX;
	DropItems[iPickup][DI_fY] = fY;
	DropItems[iPickup][DI_fZ] = fZ;
    SetPlayerAmmo(playerid,iWeapon,0);
	//printf("GivePlayerWeapon(%d,%d,-%d)",playerid,iWeapon,iMuni);

	// ResetPlayerWeapons(playerid);
    return 1;

}
forward pickupidw(pwaf);
public pickupidw(pwaf)
{
	DestroyDropItem(pwaf);
}
stock Weapon_OnPlayerPickUpPickup(playerid, pickupid) {
	new
	    iSlotPicked,
	    iWeapon_picked = (DropItems[pickupid][DI_iExtra] & 0xFF),
	    iAmmo,
	    iMuni = ( DropItems[pickupid][DI_iExtra] >> 8 ) & 0xFF,
	    iArmedWeapon,
	    iWeapon;
	iSlotPicked = GetWeaponSlot(iWeapon_picked);
	GetPlayerWeaponData(playerid,iSlotPicked,iWeapon,iAmmo);
	iArmedWeapon = GetPlayerWeapon(playerid);
	if(iWeapon == iWeapon_picked) {
		GivePlayerWeapon(playerid,iWeapon_picked,iMuni);
		if(iArmedWeapon != iWeapon_picked) {
			SetPlayerArmedWeapon(playerid,iArmedWeapon);
		}
	}
	else {
	    if( (iWeapon == 0) && (iAmmo == 0) ) {
		    GivePlayerWeapon(playerid,iWeapon_picked,iMuni);
	    }
	    else {
			GivePlayerWeapon(playerid,iWeapon,( iMuni + iAmmo ));
			if(iArmedWeapon != iWeapon_picked) {
				SetPlayerArmedWeapon(playerid,iArmedWeapon);
			}
		}
	}
	PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
    DestroyDropItem(pickupid);
    // printf("iWeapon_picked %d iArmedWeapon %d iMuni %d iAmmo %d",iWeapon_picked,iArmedWeapon,iMuni,iAmmo);
    return 1;
}

