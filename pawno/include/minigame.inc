#include <YSI\y_hooks>

new bool:IsArenaRunning = false;
new NEED_DERBY_PLAYERS = 2;
new MAX_DERBY_PLAYERS = 12;

//SetTimer("DerbyTimer", 500, true);

new Float:spawn_derbyMap1[][] =
{
    {3606.5117,-1999.7643,450.8294,223.3430},
    {3634.6482,-1977.9720,450.8256,179.7553},
    {3669.9558,-1977.8665,450.8243,176.7261},
    {3697.7012,-1999.5433,450.8293,136.3577},
    {3718.0303,-2027.6238,450.8265,89.7445},
    {3718.5322,-2062.9290,450.8260,90.2725},
    {3696.9573,-2090.1960,450.8291,43.5020},
    {3669.8428,-2111.8765,450.8273,359.3956},
    {3634.0977,-2112.7454,450.8268,359.3512},
    {3607.9893,-2089.1321,450.8286,313.6122},
    {3585.7185,-2063.0415,450.8246,269.8091},
    {3583.8855,-2027.4241,450.8253,268.8569}
};

new Float:spawn_derbyMap2[][] =
{
    {-3427.6675,623.8201,120.1559,357.9831},
    {-3426.2915,709.7303,120.1582,179.1345},
    {-3469.6741,667.6922,104.5557,358.2171},
    {-3394.0928,779.4446,104.5554,314.6176},
    {-3312.7952,712.4706,104.5557,224.4341},
    {-3379.5315,629.6620,104.5566,133.1556},
    {-3427.7700,558.9435,148.2212,1.6845},
    {-3274.2126,666.6423,148.2224,358.8217},
    {-3281.6628,835.8379,148.2234,88.8222},
    {-3383.8718,851.5277,168.3062,180.1125},
    {-3388.2791,647.9537,168.3376,179.1103},
    {-3427.1104,589.5142,148.2225,0.3352}
};

CMD:derbyarena(playerid){
    if(!IsPlayerInRangeOfPoint(playerid, 5, 2695.4961, -1704.7928, 11.8438)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du befindest dich nicht an der Derbyarena!");
    SetPVarInt(playerid, "ISDERBY", 1);
    new count;
    if(new i = 0; i < MAX_PLAYERS; i++){
        aliveVar = GetPVarInt(i, "ISALIVE");
        if(aliveVar == 1){
            PlayerSpectateVehicle(playerid, GetPlayerVehicleID(i));

            return 1;
        }
    }
    return 1;
}

forward DerbyTimer();
public DerbyTimer(){
    gettime(stunde, minute, sekunde);
    if(sekunde == 0 && 
}

forward ArenaMSG(color, string[]);
stock ArenaMSG(color, string[]){
    for(new i=0; i<MAX_PLAYERS; i++){
        new ArVar = GetPVarInt(i, "ISDERBY");
        if(ArVar == 1){
            SendClientMessage(i, color, string);
        }
    }
    return 1;
}

new DerbyPlayers[MAX_PLAYERS];
forward getDerbyPlayers();
stock getDerbyPlayers(){
    for()
    new ArVar = GetPVarInt(i, "ISDERBY");

}