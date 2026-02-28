#include <YSI\y_hooks>

#define _include_bomb_

#define INVALID_BOMB_INDEX -1

#define BOMB_DISTANCE_DETONATE 100.0

enum {
	Bombe_Inactive = 0,
	Bombe_Planting,
	Bombe_Planted,
	Bombe_Defusing
}
enum e_Bomb {
	B_iStatus,
	B_iObjectID,
	Float:B_fX,
	Float:B_fY,
	Float:B_fZ,
	B_iInterior,
	B_iDraht,
	
	B_iTickBlocked,
	B_iTick,
	B_tBomb,
	B_BombInfo
}

new Bombs[e_Bomb];

stock Bomb_PlantBomb(playerid,draht) {
	if( Bombs[B_iStatus] != Bombe_Inactive ) {
	    return 0;
	}
	new
	    Float:_Face,
	    _Interior,
	    Float:_X,
	    Float:_Y,
	    Float:_Z;
	GetPlayerPos(playerid,_X,_Y,_Z);
	_Interior = GetPlayerInterior(playerid);
	GetPlayerFacingAngle(playerid,_Face);

	GetXYInFrontOfPosition( _X , _Y , _Face , 0.8 );
	_Z -= 0.9;

	Bombs[B_iStatus] = Bombe_Planting;
	Bombs[B_fX] = _X;
	Bombs[B_fY] = _Y;
	Bombs[B_fZ] = _Z;
	Bombs[B_iInterior] = _Interior;
	Bombs[B_iDraht] = draht;
	Bombs[B_iObjectID] = CreateDynamicObject(1252,_X,_Y,_Z,float(random(360)),90.0,0.0,.interiorid = _Interior);//1654

	ApplyAnimation(playerid, "BOMBER", "BOM_PLANT", 4.0, 1, 0, 0, 1, 0); // bombe legen
	SetTimerEx("Bomb_Delay",73,false,"d",playerid);
	Bombs[B_iTickBlocked] = 0;
	return 1;
}

forward Bomb_Delay(playerid);
public Bomb_Delay(playerid) {
	Streamer_Update(playerid);
	//Bombs[B_iTick] = gettime() + 30;
	Bombs[B_iTick] = gettime() + 2*60;
	Bombs[B_tBomb] = SetTimerEx("Bomb_Legen",1319,true,"d",playerid);
	return 1;
}

forward Bomb_Legen(playerid);
public Bomb_Legen(playerid) {
	//printf("Bomb_Legen(%s(%d))",GetName(playerid),playerid);
	if( Bombs[B_iTick] < gettime() ) {
		KillTimer( Bombs[B_tBomb] );
		ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_CROUCH_OUT", 4.0, 1, 0, 0, 1, 0); // bombe ende
		SendClientMessage(playerid,COLOR_YELLOW,"Bombe gelegt!");
		ClearAnimationsEx(playerid,100);
		CallLocalFunction("OnBombPlanted","d",playerid);
		Bombs[B_iStatus] = Bombe_Planted;
		Bombs[B_iTick] = gettime() + 10*60; // Nach dem die Bombe gelegt wurde, wie lange es dauert bis sie explodiert. 10*60 = 10 Minuten
	 	Bombs[B_tBomb] = SetTimer("Bomb_Pulse",1451,true);
		Bombs[B_BombInfo] = SetTimer("Bomb_Info",60003,true);
	 	//printf("Bombs[B_tBomb] = %d",Bombs[B_tBomb]);
	}
	else {
		ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_LOOP", 4.0, 1, 0, 0, 1, 0); // bombe idle
	}
	return 1;
}


forward Bomb_Info();
public Bomb_Info()
{
	new string[128];
	new bombtime = Bombs[B_iTick]-gettime();
	format(string,sizeof(string),"Die Bombe explodiert in %d Minuten", bombtime/60);
	SendFraktionMessage(15,COLOR_RED,string);
	return 1;
}

forward Bomb_Pulse();
public Bomb_Pulse() {
	//printf("Bomb_Pulse() %d", GetTickCount() );
	if( gettime() >= Bombs[B_iTick] ) {
	    //printf("Bomb_Pulse KillTimer(%d)",Bombs[B_tBomb]);
	    SendClientMessageToAll(COLOR_RED,"ACHTUNG! Die Bombe ist explodiert! Es wurde Schaden angerichtet.");
	    Bomb_ExplodeBomb();
	}
	return 1;
}

stock DestroyBomb( ) {
    KillTimer(Bombs[B_tBomb]);
	KillTimer(Bombs[B_BombInfo]);
    Bombs[B_iStatus] = Bombe_Inactive;
    DestroyDynamicObject( Bombs[B_iObjectID] );
    Bombs[B_iTickBlocked] = gettime() + 5*60*60;
	return 1;
}

stock Bomb_ExplodeBomb() {
	//print("Bomb_ExplodeBomb");
	DestroyBomb();
	Bombs[B_tBomb] = SetTimer("Bomb_Explode",79,true);
	Bombs[B_iTick] = GetTickCount() + 750;
	return 1;
}
forward Bomb_Explode();
public Bomb_Explode() {
	//print("Bomb_Explode");
	if( Bombs[B_iTick] < GetTickCount() ) {
	    KillTimer(Bombs[B_tBomb]);
		KillTimer(Bombs[B_BombInfo]);
		//print("Bomb_Explode KillTimer");
	}
	CreateExplosion( Bombs[B_fX] + float(random(8)) - float(random(8)), Bombs[B_fY]  + float(random(8)) - float(random(8)) , ( Bombs[B_fZ] + 2.0 ) + float(random(5)) , 7 , float( random(8) + 5 ) );
	return 1;
}

stock IsPlayerInRangeOfBomb(playerid) {
    if( IsPlayerInRangeOfPoint(playerid,2.5,Bombs[B_fX],Bombs[B_fY],Bombs[B_fZ])) {
        return 1;
    }
	return 0;
}

CMD:entschaerfen(playerid,params[]) {
    if( !IsPlayerExecutive(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist.");
    if( !IsPlayerInRangeOfBomb(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Hier befindet sich keine Bombe.");
    if( Bombs[B_iStatus] == Bombe_Planting ) return SendClientMessage(playerid, COLOR_RED, "Die Bombe ist noch nicht scharf.");
    if( Bombs[B_iStatus] == Bombe_Defusing ) return SendClientMessage(playerid, COLOR_RED, "Die Bombe wird bereits von jemandem entschärft.");
    new String[128];
    GetBombDrahtColorString(String);

    Bombs[B_iStatus] = Bombe_Defusing;
    ApplyAnimation(playerid, "BOMBER", "BOM_PLANT", 4.0, 1, 0, 0, 1, 0); // bombe legen
    SetTimerEx("BombDefuseAnimation",73,false,"d",playerid);

    ShowPlayerDialog(playerid,DIALOG_BOMBDEFUSE,DIALOG_STYLE_LIST,COLOR_HEX_LIGHTBLUE "Bombe - Entschärfen",String,"Weiter","Abbruch");
    return 1;
}

CMD:bombelegen(playerid,params[]) {
    if(Spieler[playerid][pFraktion] != 15 )return SendClientMessage(playerid, COLOR_RED, "Du bist kein Nine Demons.");
    if( Bombs[B_iTickBlocked] > gettime() )return SendClientMessage(playerid, COLOR_RED, "Es kann zur Zeit keine Bombe gelegt werden.");
    if( Bombs[B_iStatus] != Bombe_Inactive )return SendClientMessage(playerid, COLOR_RED, "Eine Bombe ist bereits gelegt worden.");
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist Tot.");
    if(GetPlayerInterior(playerid) > 0)return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Du kannst den Befehl nicht in einem Interior nutzen!");
    if(Spieler[playerid][pJailed] != 0)return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du kannst hier den Befehl nicht nutzen.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Während du gefesselt bist kannst keine Bombe legen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist im AFK-Modus.");
    if (Spieler[playerid][pJailed]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist im Gefängnis.");
    new String[128];
    GetBombDrahtColorString(String);
    ShowPlayerDialog(playerid,DIALOG_BOMBELEGEN,DIALOG_STYLE_LIST,COLOR_HEX_LIGHTBLUE "Bombe Legen - Drahtfarbe", String , "Legen","Abbruch");
    return 1;
}

forward BombDefuseAnimation(playerid);
public BombDefuseAnimation(playerid) {
    ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_CROUCH_OUT", 4.0, 1, 0, 0, 1, 0); // bombe ende
    return 1;
}

forward OnBombPlanted(playerid,bomb);
public OnBombPlanted(playerid,bomb) {
    new
        String[128];
    format(String,sizeof(String),"ACHTUNG! Es wurde von einem NineDemons eine Bombe platziert!");
    SendClientMessageToAll(COLOR_RED,String);
    return 1;
}

stock GetBombDrahtColorString( string[] , size = sizeof(string) ) { // scheiss funktionsname
    for(new i ; i < sizeof(g_BombenDraht) ; i++) {
        format(string,size,"%s%s%s\n",string,GetColorCodeFromHex( g_BombenDraht[i][BD_iColor] ), g_BombenDraht[i][BD_sFarbe] );
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]){
	switch(dialogid){
		case DIALOG_BOMBDEFUSE: {
			if(response) {
				new String[128];
				if( listitem == Bombs[B_iDraht] ) {
					// Entschärft
					format(String,sizeof(String),"Polizist %s konnte die Bombe erfolgreich entschärfen!",GetName(playerid));
					SendClientMessageToAll(COLOR_GREEN,String);
					DestroyBomb();
				} else {
					format(String,sizeof(String),"ACHTUNG! Die Bombe ist explodiert! Polizist %s hat es nicht geschafft die Bombe zu entschärfen!",GetName(playerid));
					SendClientMessageToAll(COLOR_RED,String);
					Bomb_ExplodeBomb();
				}
			} else {
				Bombs[B_iStatus] = Bombe_Planted;
			}
			ClearAnimationsEx(playerid,100);
    	}
		case DIALOG_BOMBELEGEN: {
			if(response) {
				SendClientMessage(playerid,COLOR_YELLOW,"Du platzierst eine Bombe, beweg dich 2 Minuten nicht von der Stelle!");
				if( !Bomb_PlantBomb(playerid,listitem) ) return SendClientMessage(playerid,COLOR_RED,"Die Bombe konnte nicht gelegt werden.");
			}
		}
	}
	return 1;
}