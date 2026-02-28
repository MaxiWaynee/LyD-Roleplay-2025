/********************************************** 
								Copyright © 2011 by Pablo_Borsellino
								
Externe Datei,
wurde nicht verrechnet mit Auftrag
*******************************************************************************/

//______________________________________________________________________________
#define forEx(%0,%1) for(new %1=0;%1<%0;%1++)

//_____________________________________________________________________Setting's
#define FERRIS_WHEEL_WAIT_TIME 3000	//Wait Time to enter a Cage
#define FERRIS_WHEEL_SPEED 0.005	//Speed of turn (Standart 0.005)

//______________________________________________________________________________
new Float:gFerrisCageOffsets[10][3]={{0.0699,0.0600,-11.7500},{-6.9100,-0.0899,-9.5000},{11.1600,0.0000,-3.6300},{-11.1600,-0.0399,3.6499},{-6.9100,-0.0899,9.4799},{0.0699,0.0600,11.7500},{6.9599,0.0100,-9.5000},{-11.1600,-0.0399,-3.6300},{11.1600,0.0000,3.6499},{7.0399,-0.0200,9.3600}},
	FerrisWheelObjects[12],
	Float:FerrisWheelAngle=0.0,
	FerrisWheelAlternate=0;

//______________________________________________________________________________
forward RotateFerrisWheel();

//______________________________________________________________________________
Riesenrad_OnPlayerConnect(playerid)
{
	RemoveBuildingForPlayer(playerid, 6463, 389.7734, -2028.4688, 19.8047, 0.5);
	RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2035.3828, 29.9531, 50);
	RemoveBuildingForPlayer(playerid, 6298, 389.7734, -2028.4688, 19.8047, 0.5);
	RemoveBuildingForPlayer(playerid, 6461, 389.7734, -2028.5000, 20.1094, 0.5);
	RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2028.5000, 32.2266, 50);
	return 1;
}

//______________________________________________________________________________
Riesenrad_Init()
{
	FerrisWheelObjects[10]=CreateDynamicObject(18877,389.7734,-2028.4688,22,0,0,90, .drawdistance = 300);
	FerrisWheelObjects[11]=CreateDynamicObject(18878,389.7734,-2028.4688,22,0,0,90, .drawdistance = 300);
	for(new x=0;x<sizeof(FerrisWheelObjects) - 2 ;x++) {
		FerrisWheelObjects[x]=CreateDynamicObject(18879,389.7734,-2028.4688,22,0,0,90, .drawdistance = 300);
		AttachDynamicObjectToObject(FerrisWheelObjects[x], FerrisWheelObjects[10],gFerrisCageOffsets[x][0],gFerrisCageOffsets[x][1],gFerrisCageOffsets[x][2],0.0, 0.0, 90, 0 );}
	SetTimer("RotateFerrisWheel",FERRIS_WHEEL_WAIT_TIME,false);
	forEx(MAX_PLAYERS,playerid){
		RemoveBuildingForPlayer(playerid, 6463, 389.7734, -2028.4688, 19.8047, 0.5);
		RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2035.3828, 29.9531, 50);
		RemoveBuildingForPlayer(playerid, 6298, 389.7734, -2028.4688, 19.8047, 0.5);
		RemoveBuildingForPlayer(playerid, 6461, 389.7734, -2028.5000, 20.1094, 0.5);
		RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2028.5000, 32.2266, 50);
	}
	return 1;
}

//______________________________________________________________________________
Riesenrad_Exit()
{
	for(new x ; x < sizeof(FerrisWheelObjects) ; x++) {
		DestroyDynamicObject(FerrisWheelObjects[x]);
	}
	return 1;
}

//______________________________________________________________________________
Riesenrad_OnObjectMoved(objectid)
{
	if(objectid==FerrisWheelObjects[10]) {
		SetTimer("RotateFerrisWheel",FERRIS_WHEEL_WAIT_TIME,false);
		return 1;
	}
	return 0;
}

//______________________________________________________________________________
public RotateFerrisWheel()
{
	FerrisWheelAngle+=36;
	if(FerrisWheelAngle>=360)FerrisWheelAngle=0;
	if(FerrisWheelAlternate)FerrisWheelAlternate=0;
	else FerrisWheelAlternate=1;
	new Float:FerrisWheelModZPos=0.0;
	if(FerrisWheelAlternate)FerrisWheelModZPos=0.05;
	MoveDynamicObject(FerrisWheelObjects[10],389.7734,-2028.4688,22.0+FerrisWheelModZPos,FERRIS_WHEEL_SPEED,0,FerrisWheelAngle,90);
}
