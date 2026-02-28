#include <YSI\y_hooks>


CMD:pizzaverkaufen(playerid,params[]) {
    #define PIZZAVERKAUFEN_PREIS 50
    if(Spieler[playerid][pJob] == 15) {
        new String[128], preis, Float:X, Float:Y, Float:Z, giveid, vehicleid;
        vehicleid = GetPlayerVehicleID(playerid);
        if( !vehicleid ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in einem Fahrzeug.");
        if( !IsPizzaVehicle(vehicleid) ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in einem Pizza-Fahrzeug");
        if(sscanf(params,"ud",giveid,preis)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Pizzaverkaufen [Spieler] [Preis]");
        if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
        if(playerid == giveid) return SendClientMessage(playerid, COLOR_RED, "Du kannst kein Eis an dich selber Verkaufen.");
        if( !( 0 < preis < 200 ) ) return SendClientMessage(playerid, COLOR_RED, "Der Preis muss zwischen 1$ und 200$ liegen");
        GetPlayerPos(playerid,X,Y,Z);
        if( !IsPlayerInRangeOfPoint(giveid,5.0,X,Y,Z) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler befindet sich nicht in deiner Nähe.");
        if(meslock[playerid]==1)return SendClientMessage(playerid, COLOR_RED, "Du hast den Spieler bereits eine Anfrage gestellt. Warte bis er sie akzeptiert." );
        meslock[playerid]=1;
        SetTimerEx("meslockrelease",20000,false,"i",playerid);
        // Verkaufen ???
        Spieler[giveid][pPizzaVerkaeufer] = playerid;
        Spieler[giveid][pPizzaPreis] = preis;

        format(String,sizeof(String),"Du bietest %s eine Pizza für $%s zum Kauf an.",GetName(giveid), AddDelimiters(preis));
        SendClientMessage(playerid, COLOR_BLUE,String);

        format(String,sizeof(String),"Pizzalieferant %s möchte dir eine Pizza für $%s verkaufen. Nimm es mit '/Accept Pizza' an!",GetName(playerid), AddDelimiters(preis));
        SendClientMessage(giveid, COLOR_BLUE,String);
    }
    else {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Pizzalieferant.");
    }
    return 1;
}