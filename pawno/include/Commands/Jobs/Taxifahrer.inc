#include <YSI\y_hooks>


CMD:starttaxi(playerid,params[]) {
    if(Spieler[playerid][pJob] != 16 ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Taxifahrer");
        return 1;
    }
    new
        preis;
    if(sscanf(params,"d",preis)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Starttaxi [Preis]");
    }
    if( !( 10 <= preis <= 500 ) ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Preis muss zwischen 10$ und 500$ liegen");
    }
    new
        vehicleid,
        modelid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid,COLOR_RED,"Du befindest dich in keinem Fahrzeug");
    }
    modelid = GetVehicleModel(vehicleid);
    if( !(( modelid == 420 ) || ( modelid == 438 )) ) {
        return SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht in einem Taxi");
    }
    if( HasPlayerTaxiCustomers(playerid)) {
        return SendClientMessage(playerid,COLOR_RED,"Du hast bereits Fahrgäste. Aktion ist daher nicht möglich.");
    }
    new
        String[64];
    format(String,sizeof(String),"Taxifahrer: %s\nFahrpreis: %d$",GetName(playerid),preis);
    //printf("Starttaxi HasPlayerTaxiCustomers(%d) = %d t3dTaxi[%d] = %d",playerid,HasPlayerTaxiCustomers(playerid),vehicleid,_:g_t3dTaxi[vehicleid]);
    if( _:g_t3dTaxi[vehicleid] != INVALID_3DTEXT_ID ) {
        Update3DTextLabelText( g_t3dTaxi[vehicleid] , 0xFFD700FF,String );
        format(String,sizeof(String),"Du hast deinen Tarif angepasst. Fahrpreis: %d$/100m",preis);
    }
    else {
        g_t3dTaxi[vehicleid] = Create3DTextLabel( String , 0xFFD700FF, 0.0, 0.0, 0.0, 18.0, 0, 1);
        Attach3DTextLabelToVehicle( g_t3dTaxi[vehicleid],vehicleid,0.0,0.0,0.6);
        format(String,sizeof(String),"Du hast deinen Taxidienst gestartet. Fahrpreis: %d$/100m",preis);
        // Nur wenn neuer Start
        Spieler[playerid][pTaxiVehicle] = vehicleid;
        CreateTaxiTextdraw(playerid);
        ClearPlayerTaxiSlots(playerid);
    }
    SendClientMessage(playerid,COLOR_LIGHTRED2,String);
    Spieler[playerid][pTaxiPreis] = preis;
    return 1;
}



CMD:accepttaxi(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Accepttaxi [SpielerID/Name]");
    if(Spieler[playerid][pJob] != 16)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Taxifahrer!");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
    if(GetPlayerInterior(pID) > 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem Gebäude.");
    if(NeedTAXI[pID] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler benötigt keinen Mechatroniker. Verwende /sliste um die Service-Liste zu sehen.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    SetPlayerCheckpointEx(playerid, x,y,z, 5.0, CP_ACCEPTKFZ);
    format(string, sizeof(string), "* Du hast den Service-Anruf von %s angenommen, ein Roter Punkt wurde auf der Karte markiert.", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Taxifahrer %s hat deinen Service-Anruf angenommen und ist nun unterwegs zu dir!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    NeedTAXI[pID] = 0;
    return 1;
}