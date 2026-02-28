#include <YSI\y_hooks>


enum e_coinshop {
    Coinshop_Name[128],
    Coinshop_Preis,
    Coinshop_Dauer[128]
}

new const g_coinshop[][e_coinshop] = {
    {"Skill-UP",                        30,   "Life-Time"},
    {"Deagle, MP5 Spawpaket",           50,    "14 Tage"},
    {"1 Level-UP",                      50,    "/"},
    {"Deagle,SG,M4,Sniper Spawnpaket",  100,   "14 Tage"},
    {"Club Bronze",                     100,   "30 Tage"},
    {"Spezial-NRG",                     100,   "/"},
    {"Wunschcar",                       100,   "Life-Time"},
    {"Neon-Premium",                    150,   "Life-Time"},
    {"Spawnweste",                      150,   "30 Tage"},
    {"Premium-Carkey",                  150,   "Life-Time"},
    {"Club Silber",                     200,   "6 Monate"},
    {"Namechange",                      200,   "/"},
    {"Premium-Bizkey",                  200,   "Life-Time"},
    {"Club Gold",                       300,   "Life-Time"}
};


CMD:coinshop(playerid,params[]) {
    if(!IsPlayerInRangeOfPoint(playerid, Float:2.0, COINSHOP_COORDS)) return SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht am LyD-Coinshop.");
    new dialogtext[2056] = COLOR_HEX_WHITE "Artikel\t" COLOR_HEX_WHITE "Preis\t" COLOR_HEX_WHITE "Dauer\n";
    for (new i = 0; i < sizeof(g_coinshop); i++)
        format(dialogtext, sizeof(dialogtext), "%s{FFFFFF}%s\t%d Coins\t%s\n",dialogtext, g_coinshop[i][Coinshop_Name], g_coinshop[i][Coinshop_Preis],g_coinshop[i][Coinshop_Dauer]);

    return ShowPlayerDialog(playerid, DIALOG_COINSHOP, DIALOG_STYLE_TABLIST_HEADERS, "{118546}LyD-Coinshop", dialogtext, "Auswählen", "Abbrechen");
}


hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    switch(dialogid) {
        case DIALOG_COINSHOP: {
            if(response) {
                switch(listitem) {
                    case 0: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        ShowPlayerDialog(playerid, DIALOG_COINSHOP_SKILL, DIALOG_STYLE_LIST, "{118546}LyD-Coinshop | Skillauswahl", "Hure\nDetektiv\nAnwalt\nDrogendealer\nWaffendealer", "Auswählen", "Abbrechen");
                    } case 1: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        Spieler[playerid][pSpawnWaffen] = 1;
                        Spieler[playerid][pSpawnWaffenUnix] = gettime() + 14*24*60*60;
                        new string[128];
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                    } case 2: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        Spieler[playerid][pLevel] += 1;
                        new string[128];
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                        
                    } case 3: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        Spieler[playerid][pSpawnWaffen] = 2;
                        Spieler[playerid][pSpawnWaffenUnix] = gettime() + 14*24*60*60;
                        new string[128];
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                    } case 4: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new year, month, day, unix, m, d, h,minute, sec, timestr[16];
                        getdate(year,month,day);
                        unix = gettime() + MonthTimes[ month - 1][0 + IsLeapYear(year)]*24*60*60;
                        TimestampToDate( unix , year,m,d,h,minute,sec,1,0);
                        format(timestr, sizeof(timestr), "%d/%d/%d", d,m,year);
                        SCMFormatted(playerid,COLOR_YELLOW,"Deine Clubmitgliedschaft wurde freigeschaltet und läuft am %s ab.",timestr);
                        Spieler[playerid][pDonateRank] = 1;
                        new string[128];
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                        
                    } case 5: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        
                        if(!PlayerHaveCar[playerid][PlayerKey[playerid]]) {
                            CreatePlayerCar(playerid,1310.1656,1857.9419,13.5469,0.0,522,1,1);
                            PlayerCar[playerid][PlayerKey[playerid]][Id]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarId]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarOwner]=GetName(playerid);
                            PlayerCar[playerid][PlayerKey[playerid]][CarModel]=522;
                            PlayerCar[playerid][PlayerKey[playerid]][CarPos_x]=1310.1656;
                            PlayerCar[playerid][PlayerKey[playerid]][CarPos_y]=-1857.9419;
                            PlayerCar[playerid][PlayerKey[playerid]][CarPos_z]=13.5469;
                            PlayerCar[playerid][PlayerKey[playerid]][CarRotate]=90.0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarNitro]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarHyd]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarWheel]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarAusp]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarSideL]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarSideR]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarFB]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarRB]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarSpoiler]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarRoof]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarHood]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarVents]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarLamps]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarPJ]=-1;
                            PlayerCar[playerid][PlayerKey[playerid]][CarC1]=1;
                            PlayerCar[playerid][PlayerKey[playerid]][CarC2]=1;
                            PlayerCar[playerid][PlayerKey[playerid]][CarPreis]=0;
                            PlayerCar[playerid][PlayerKey[playerid]][CarState]=0;
                            format(PlayerCar[playerid][PlayerKey[playerid]][CarNumberplate] ,32, KEIN_KENNZEICHEN );
                            PlayerCar[playerid][PlayerKey[playerid]][CarId] = CreateVehicle(PlayerCar[playerid][PlayerKey[playerid]][CarModel],PlayerCar[playerid][PlayerKey[playerid]][CarPos_x],PlayerCar[playerid][PlayerKey[playerid]][CarPos_y],PlayerCar[playerid][PlayerKey[playerid]][CarPos_z],PlayerCar[playerid][PlayerKey[playerid]][CarRotate],PlayerCar[playerid][PlayerKey[playerid]][CarC1],PlayerCar[playerid][PlayerKey[playerid]][CarC2], -1);/*vehicle spawn*/
                            aiVehicles[ PlayerCar[playerid][PlayerKey[playerid]][CarId] ] = VEH_PRIVAT;
                            FrakCarInfo[PlayerCar[playerid][PlayerKey[playerid]][CarId]][f_frak] = 0;
                            FrakCarInfo[PlayerCar[playerid][PlayerKey[playerid]][CarId]][f_dbid] = 0;
                            SetVehicleNumberPlate(PlayerCar[playerid][PlayerKey[playerid]][CarId], "");
                            PlayerHaveCar[playerid][PlayerKey[playerid]] = 1;
                            gGas[PlayerCar[playerid][PlayerKey[playerid]][CarId]] = GetMaxTank(PlayerCar[playerid][PlayerKey[playerid]][CarId]);
                            gMaxGas[PlayerCar[playerid][PlayerKey[playerid]][CarId]] = GetMaxTank(PlayerCar[playerid][PlayerKey[playerid]][CarId]);
                            PlayerCar[playerid][PlayerKey[playerid]][CarTank] = GetMaxTank(PlayerCar[playerid][PlayerKey[playerid]][CarId]);
                            g_VehicleDistance[ PlayerCar[playerid][PlayerKey[playerid]][CarId] ] = 0;
                            PlayerCar[playerid][PlayerKey[playerid]][TUV] = 0;
                            LockCar(PlayerCar[playerid][PlayerKey[playerid]][CarId]);
                            
                            PlayerCar[playerid][PlayerKey[playerid]][isSpecialTuned] = 3;
                            DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                            DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                            DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                            DestroyDynamicObject(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1]);
                            PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1] = CreateDynamicObject(18729, 0,0,0,0,0,0,0);
                            PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned2] = CreateDynamicObject(18729, 0,0,0,0,0,0,0);
                            PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned3] = CreateDynamicObject(18700, 0,0,0,0,0,0,0);
                            PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned4] = CreateDynamicObject(18700, 0,0,0,0,0,0,0);
                            AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned1], PlayerCar[playerid][PlayerKey[playerid]][CarId], -0.199999, -1.100000, -1.300000, 0.000000, 0.000000, 180.000000);
                            AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned2], PlayerCar[playerid][PlayerKey[playerid]][CarId], 0.300000, -1.100000, -1.300000, 0.000000, 0.000000, 180.000000);
                            AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned3], PlayerCar[playerid][PlayerKey[playerid]][CarId], -0.199999, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
                            AttachDynamicObjectToVehicle(PlayerCar[playerid][PlayerKey[playerid]][SpecialTuned4], PlayerCar[playerid][PlayerKey[playerid]][CarId], 0.300000, -1.100000, -1.300000, 0.000000, 0.000000, 0.000000);
                            Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                            new string[128];
                            SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                            format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                            CoinShopLog(string);
                        } else {
                            return SendClientMessage(playerid, COLOR_RED, "* Du hast auf dem Autoschlüssel bereits ein Fahrzeug.");
                        }
                    } case 6: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new string[128];
                        SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Mach einen Screen und Melde dich bei einem Administrator für dein Wunschfahrzeug.");
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                    } case 7: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new string[128];
                        Spieler[playerid][pPremiumNeon] = 1;
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                        
                    } case 8: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new string[128];
                        Spieler[playerid][pSpawnWeste] = gettime() + 30*24*60*60;
                        Spieler[playerid][pDonateRank] = 1;
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                    } case 9: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new string[128];
                        Spieler[playerid][pPremiumCarSlot] = 1;
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                        
                    } case 10: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new string[128];
                        new year, month, day, unix, m, d, h,minute, sec, timestr[16];
                        getdate(year,month,day);
                        new days = 0;
                        for(new i = 0 ; i < 6 ; i++) {
                            days += MonthTimes[ month - 1 + i][0 + IsLeapYear(year)];
                        }
                        unix = gettime() + days*24*60*60;
                        TimestampToDate( unix , year,m,d,h,minute,sec,1,0);
                        format(timestr, sizeof(timestr), "%d/%d/%d", d,m,year);
                        Spieler[playerid][pDonateRank] = 1;
                        SCMFormatted(playerid,COLOR_YELLOW,"Deine Clubmitgliedschaft wurde freigeschaltet und läuft am %s ab.",timestr);
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                        
                    } case 11: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new string[128];
                        SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Mach einen Screen und Melde dich bei einem Administrator für deinen Namechange.");
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                        
                    } case 12: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new string[128];
                        Spieler[playerid][pPremiumBizSlot] = 1;
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                        
                    } case 13: {
                        if(Spieler[playerid][pCoins] < g_coinshop[listitem][Coinshop_Preis]) return SendClientMessage(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast nicht genügend LyD-Coins.");
                        Spieler[playerid][pCoins] -= g_coinshop[listitem][Coinshop_Preis];
                        new string[128];
                        new year, month, day, unix, m, d, h,minute, sec, timestr[16];
                        getdate(year,month,day);
                        if( IsLeapYear(year) ) {
                            unix = gettime() + 1825*24*60*60;
                        } else {
                            unix = gettime() + 1825*24*60*60;
                        }
                        TimestampToDate( unix , year,m,d,h,minute,sec,1,0);
                        format(timestr, sizeof(timestr), "%d/%d/%d", d,m,year);
                        SCMFormatted(playerid,COLOR_YELLOW,"Deine Clubmitgliedschaft wurde freigeschaltet und läuft am %s ab.",timestr);
                        SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        format(string,sizeof(string),"%s hat sich %s um %d Coins im Coinshop gekauft.",GetName(playerid),g_coinshop[listitem][Coinshop_Name],g_coinshop[listitem][Coinshop_Preis]);
                        CoinShopLog(string);
                    }
                }
            }
        } case DIALOG_COINSHOP_SKILL: {
            if(response) {
                switch(listitem) {
                    case 0: {
                        if(GetPlayerHureLevel(playerid) == 5) return SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast schon den maximalen Skill erreicht.");
                        SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast den Skill Hure gewählt.");
                        PlayerSkillUpgrade(playerid,pHurePoints,0,GetNeededSkill(playerid,1));
                    } case 1: {
                        if(GetPlayerDetectivLevel(playerid) == 5) return SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast schon den maximalen Skill erreicht.");
                        SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast den Skill Detektiv gewählt.");
                        PlayerSkillUpgrade(playerid,pDetektivPoints,1,GetNeededSkill(playerid,3));
                    } case 2: {
                        if(GetPlayerLawyerLevel(playerid) == 6) return SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast schon den maximalen Skill erreicht.");
                        SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast den Skill Anwalt gewählt.");
                        PlayerSkillUpgrade(playerid,pLawyerPoints,2,GetNeededSkill(playerid,2));
                    } case 3: {
                        if(GetPlayerDrogenSkillLevel(playerid) == 5) return SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast schon den maximalen Skill erreicht.");
                        SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast den Skill Drogendealer gewählt.");
                        PlayerSkillUpgrade(playerid,pDrogenPoints,4,GetNeededSkill(playerid,4));
                    } case 4: {
                        if(GetPlayerWaffenteileSkillLevel(playerid) == 5) return SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast schon den maximalen Skill erreicht.");
                        SendClientMessage(playerid,COLOR_ORANGE,"{118546}LyD-Coinshop{FFFFFF} Du hast den Skill Waffendealer gewählt.");
                        PlayerSkillUpgrade(playerid,pWaffenteilePoints,5,GetNeededSkill(playerid,5));
                    }
                }
                Spieler[playerid][pCoins] -= g_coinshop[0][Coinshop_Preis];
                SCMFormatted(playerid,COLOR_RED,"{118546}LyD-Coinshop{FFFFFF} Du hast dir den Artikel %s für %d Coins gekauft",g_coinshop[0][Coinshop_Name],g_coinshop[0][Coinshop_Preis]);
            }
        }
    }
    return 1;
}