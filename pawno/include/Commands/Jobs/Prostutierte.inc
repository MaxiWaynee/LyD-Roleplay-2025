#include <YSI\y_hooks>



CMD:sex(playerid,params[]){
    new giveid, price;
    if(Spieler[playerid][pJob] != 20 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist keine Prostituierte.");
    }
    if(sscanf(params,"ud",giveid,price)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Sex [Spieler] [Preis]");
    }
    if( !( 0 <= price <= 10000 ) ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Preis muss zwischen 1$ und 10000$ liegen");
    }
    if(playerid == giveid) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber keinen Sex anbieten.");
    }
    if(!IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht Online.");
    }
    new
        String[128],
        Float:X,
        Float:Y,
        Float:Z,
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if( !IsACar( GetVehicleModel(vehicleid)) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in einem Auto.");
    }
    if( GetPlayerState(playerid) != PLAYER_STATE_DRIVER ) {
        return SendClientMessage(playerid, COLOR_RED, "Du musst die Fahrerin des Fahrzeuges sein.");
    }
    GetPlayerPos(playerid,X,Y,Z);
    if( !IsPlayerInRangeOfPoint(giveid,5.0,X,Y,Z) ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler befindet sich nicht in deiner Nähe.");
    }
    if( Spieler[playerid][bHasSex] ) {
        return SendClientMessage(playerid, COLOR_RED, "Du hast bereits Sex.");
    }
    new
        Float:health;
    GetPlayerHealth(playerid,health);
    if( health >= 80.0 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst kein Sex haben, deine Energie ist bereits zu hoch.");
    }
    GetPlayerHealth(giveid,health);
    if( health >= 80.0 ) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst kein Sex haben, weil die Energie deines Partners zu hoch ist.");
        return 1;
    }
    Spieler[playerid][bHasSex] = false;
    Spieler[giveid][bHasSex] = false;

    Spieler[giveid][pHureID] = playerid;
    Spieler[giveid][pHurePreis] = price;
    format(String,sizeof(String),"Du bietest deine Sex-Dienste %s für $%s an.",GetName(giveid), AddDelimiters(price));
    SendClientMessage(playerid, COLOR_BLUE,String);
    format(String,sizeof(String),"Prostituierte %s bietet dir Sex für $%s an. Nimm es mit /Accept sex an!",GetName(playerid), AddDelimiters(price));
    SendClientMessage(giveid, COLOR_BLUE,String);
    return 1;
}