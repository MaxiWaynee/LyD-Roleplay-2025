/*
    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	>> ******   *******  *******  **   **  *****   *******  **    **  **   *  ******* >>
	>> **  ***  **       **       **   **  **  **  **   **  ***   **  **  *   **      >>
	>> **   **  **       **       **   **  *****   **   **  ** *  **  ** *    **      >>
	>> ******   *******  **       *******  ***     *******  **  * **  ***     ******* >>
	>> **  ***       **  **       **   **  ** *    **   **  **   ***  ** *    **      >>
	>> **   **       **  **       **   **  **  *   **   **  **    **  **  *   **      >>
    >> ******   *******  *******  **   **  **   *  **   **  **    **  **   *  ******* >>
    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    
	Schrankeninclude by Beavis
	http://forum.sa-mp.de/index.php?page=User&userID=23390
	    (C) 2013

	Diese Include darf von jeden verwendet werden
	Ihr könnt die auch bearbeiten nur bitte lasst die Credit´s enthalten.
	Die weiterveröffentlichung bedarf nur mit meiner erlaubnis
*/

#if defined B_Schranken_included
	#endinput
#endif
#define B_Schranken_included

/*
	native CreateSchranke(objectid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:DrawDistance = 0.0, Float:Speed = 0.005);
	native MoveSchranke(schrankenid);
	native DestroySchranke(schrankenid);
	native SetSchranke(schrankenid, bool:openclose);
	native IsPlayerInRangeOfSchranke(playerid,schrankenid,Float:range);
*/

#define MAX_B_SCHRANKEN 300

enum _SchrankenEnum
{
	SchrankenID,
	Float:SchrankenX,
	Float:SchrankenY,
	Float:SchrankenZ,
	Float:SchrankenRX,
	Float:SchrankenRY,
	Float:SchrankenRZ,
	bool:SchrankeOpen,
	bool:SchrankeErstellt,
	Float:SchrankenSpeed
};

new B_Schranke[MAX_B_SCHRANKEN][_SchrankenEnum];

stock CreateSchranke(objectid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:DrawDistance = 0.0, Float:Speed = 0.005)
{
	for(new i = 0; i < MAX_B_SCHRANKEN; i++)
	{
	    if(!B_Schranke[i][SchrankeErstellt])
	    {
	        #if defined Streamer_OnPlayerDisconnect
	            #pragma unused DrawDistance
	            B_Schranke[i][SchrankenID] = CreateDynamicObject(objectid, x, y, z, rx, ry, rz);
	        #else
	        	B_Schranke[i][SchrankenID] = CreateObject(objectid, x, y, z, rx, ry, rz, DrawDistance);
	        #endif
	        B_Schranke[i][SchrankenX] = x;
	        B_Schranke[i][SchrankenY] = y;
	        B_Schranke[i][SchrankenZ] = z;
	        B_Schranke[i][SchrankenRX] = rx;
	        B_Schranke[i][SchrankenRY] = ry;
	        B_Schranke[i][SchrankenRZ] = rz;
	        B_Schranke[i][SchrankeOpen] = false;
	        B_Schranke[i][SchrankeErstellt] = true;
	        B_Schranke[i][SchrankenSpeed] = Speed;
	        return i;
	    }
	}
	return print(">> Fehler beim erstellen der Schranke!") & -1;
}

stock MoveSchranke(schrankenid)
{
	if(!B_Schranke[schrankenid][SchrankeErstellt])
	    return print("Schrankenid ist ungueltig");
	if(!B_Schranke[schrankenid][SchrankeOpen])
	{
	    #if defined Streamer_OnPlayerDisconnect
	        if(B_Schranke[schrankenid][SchrankenRY] > 180.0)
	            MoveDynamicObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] - 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],359.9,B_Schranke[schrankenid][SchrankenRZ]);
	        else
	        	MoveDynamicObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] - 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],4.0,B_Schranke[schrankenid][SchrankenRZ]);
	    #else
	        if(B_Schranke[schrankenid][SchrankenRY] > 180.0)
	    		MoveObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] - 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],359.9,B_Schranke[schrankenid][SchrankenRZ]);
			else
			    MoveObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] - 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],4.0,B_Schranke[schrankenid][SchrankenRZ]);
		#endif
		B_Schranke[schrankenid][SchrankeOpen]=true;
	}
	else
	{
	    #if defined Streamer_OnPlayerDisconnect
	        MoveDynamicObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] + 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],B_Schranke[schrankenid][SchrankenRY],B_Schranke[schrankenid][SchrankenRZ]);
	    #else
	    	MoveObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] + 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],B_Schranke[schrankenid][SchrankenRY],B_Schranke[schrankenid][SchrankenRZ]);
        #endif
		B_Schranke[schrankenid][SchrankeOpen]=false;
	}
	return 1;
}

stock SetSchranke(schrankenid, bool:openclose)
{
    if(!B_Schranke[schrankenid][SchrankeErstellt])
	    return print("Schrankenid ist ungueltig");
	if(openclose)
	{
	    #if defined Streamer_OnPlayerDisconnect
	        if(B_Schranke[schrankenid][SchrankenRY] > 180.0)
	            MoveDynamicObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] - 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],359.9,B_Schranke[schrankenid][SchrankenRZ]);
	        else
	        	MoveDynamicObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] - 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],0.1,B_Schranke[schrankenid][SchrankenRZ]);
	    #else
	        if(B_Schranke[schrankenid][SchrankenRY] > 180.0)
	    		MoveObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] - 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],359.9,B_Schranke[schrankenid][SchrankenRZ]);
			else
			    MoveObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] - 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],0.1,B_Schranke[schrankenid][SchrankenRZ]);
		#endif
		B_Schranke[schrankenid][SchrankeOpen]=openclose;
	}
	else
	{
	    #if defined Streamer_OnPlayerDisconnect
	        MoveDynamicObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] + 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],B_Schranke[schrankenid][SchrankenRY],B_Schranke[schrankenid][SchrankenRZ]);
	    #else
	    	MoveObject(B_Schranke[schrankenid][SchrankenID],B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ] + 0.01,B_Schranke[schrankenid][SchrankenSpeed],B_Schranke[schrankenid][SchrankenRX],B_Schranke[schrankenid][SchrankenRY],B_Schranke[schrankenid][SchrankenRZ]);
        #endif
		B_Schranke[schrankenid][SchrankeOpen]=openclose;
	}
	return 1;
}

stock IsPlayerInRangeOfSchranke(playerid,schrankenid,Float:range)
{
	if(!B_Schranke[schrankenid][SchrankeErstellt])
	    return print("Schrankenid ist ungueltig") & 0;
	if(IsPlayerInRangeOfPoint(playerid,range,B_Schranke[schrankenid][SchrankenX],B_Schranke[schrankenid][SchrankenY],B_Schranke[schrankenid][SchrankenZ]))
	    return 1;
	return 0;
}

stock DestroySchranke(schrankenid)
{
    if(!B_Schranke[schrankenid][SchrankeErstellt])
	    return print("Schrankenid ist ungueltig");
    #if defined Streamer_OnPlayerDisconnect
        DestroyDynamicObject(B_Schranke[schrankenid][SchrankenID]);
    #else
        DestroyObject(B_Schranke[schrankenid][SchrankenID]);
    #endif
    B_Schranke[schrankenid][SchrankenID] = -1;
    B_Schranke[schrankenid][SchrankenX] = 0.0;
    B_Schranke[schrankenid][SchrankenY] = 0.0;
    B_Schranke[schrankenid][SchrankenZ] = 0.0;
    B_Schranke[schrankenid][SchrankenRX] = 0.0;
    B_Schranke[schrankenid][SchrankenRY] = 0.0;
    B_Schranke[schrankenid][SchrankenRZ] = 0.0;
    B_Schranke[schrankenid][SchrankeOpen] = false;
    B_Schranke[schrankenid][SchrankeErstellt] = false;
    B_Schranke[schrankenid][SchrankenSpeed] = 0.0;
	return 1;
}