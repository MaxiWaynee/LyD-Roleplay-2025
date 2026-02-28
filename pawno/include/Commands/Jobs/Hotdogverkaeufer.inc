#include <YSI\y_hooks>


CMD:hotdogverkaufen(playerid,params[]) {
    #define EISVERKAUFEN_PREIS 50
    if(Spieler[playerid][pJob] == 23) {
        new String[128], preis, Float:X, Float:Y, Float:Z, giveid, vehicleid;
        vehicleid = GetPlayerVehicleID(playerid);
        if( !vehicleid ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in einem Fahrzeug.");
        if( !IsHotDogVehicle(vehicleid) ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Hotdog-Fahrzeug.");
        if(sscanf(params,"ud",giveid,preis)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Hotdogverkaufen [Spieler] [Preis]");
        if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
        if(playerid == giveid) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Hotdog an dich selber Verkaufen.");
        if( !( 0 < preis < 200 ) ) return SendClientMessage(playerid, COLOR_RED, "Der Preis muss zwischen 1$ und 200$ liegen");
        GetPlayerPos(playerid,X,Y,Z);
        if( !IsPlayerInRangeOfPoint(giveid,5.0,X,Y,Z) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler befindet sich nicht in deiner Nähe.");
        if(meslock[playerid]==1)return SendClientMessage(playerid, COLOR_RED, "Du hast den Spieler bereits eine Anfrage gestellt. Warte bis er sie akzeptiert." );
        meslock[playerid]=1;
        SetTimerEx("meslockrelease",20000,false,"i",playerid);
        // Verkaufen ???
        Spieler[giveid][pHotDogVerkaeufer] = playerid;
        Spieler[giveid][pHotDogPreis] = preis;

        format(String,sizeof(String),"Du bietest %s ein Hotdog für $%s zum Kauf an.",GetName(giveid), AddDelimiters(preis));
        SendClientMessage(playerid, COLOR_BLUE,String);

        format(String,sizeof(String),"Hotdog-Verkäufer %s möchte dir ein Hotdog für $%s verkaufen. Nimm es mit '/Accept Hotdog' an!",GetName(playerid), AddDelimiters(preis));
        SendClientMessage(giveid, COLOR_BLUE,String);
    }
    else {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Hotdog-Verkäufer.");
    }
    return 1;
}