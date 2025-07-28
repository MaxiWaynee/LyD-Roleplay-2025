#include <YSI\y_hooks>


CMD:bizverkaufen(playerid,params[]) {
    new
        giveid,
        price;
    if(sscanf(params,"ud",giveid,price)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Bizverkaufen [ID] [PREIS] (800.000$ bis 80.000.000$)");
    }
    if( !( 800000 <= price <= 80000000 )) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Bizverkaufen [ID] [PREIS] (800.000$ bis 80.000.000$)");
    }
    new indexbiz = Spieler[playerid][pPlayerBiz];
    if( indexbiz == 999) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Biz!");
    }
    if( !IsPlayerConnected(giveid) || giveid == playerid) {
        SendClientMessage(playerid,COLOR_RED,"Ungültiger Spieler");
        return 1;
    }
    if( Spieler[playerid][pBizAngebot][0] != INVALID_PLAYER_ID ) {
        SendClientMessage(playerid,COLOR_RED,"Du hast das Geschäft bereits einem Spieler angeboten.");
        return 1;
    }
    if( Spieler[giveid][pLevel] < 5 ) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst ein Geschäft nur an Spieler verkaufen, dessen Level über 5 liegt.");
        return 1;
    }
    new
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(playerid,5.0,x,y,z)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler muss sich in deiner Nähe befinden.");
    }
    ShowPlayerDialog(playerid,DIALOG_BESTAETIGEN,DIALOG_STYLE_MSGBOX,"Möchtest du diesen Befehl genauso ausführen?",
    "Um Fehleingaben zu vermeiden, wird bei diesem Befehl sicherheitshalber nochmal um Bestätigung gebeten.",
    "AUSFÜHREN","ABBRECHEN");
    sichervar[playerid][4]=1,sichervar[playerid][5]=giveid,sichervar[playerid][6]=price;
    return 1;
}

CMD:bizverstaatlichen(playerid)
{
    new message[145], b = IsPlayerAtBiz(playerid);
    if (b == 999) return SendClientMessage(playerid, COLOR_RED, "Du stehst an keinem BIZ.");

    if (Spieler[playerid][pPlayerBiz] != b) return SendClientMessage(playerid, COLOR_RED, "Dieses BIZ hast du nicht ausgewählt (/Bizkey).");
    format(Biz[b][bBesitzer], MAX_PLAYER_NAME, "Niemand");
    Spieler[playerid][pPlayerBiz] = 999;

    if (Biz[b][bKasse] > 0) {
        Spieler[playerid][pBank] += Biz[b][bKasse];
        format(message, sizeof(message), "In deiner Bizkasse waren noch $%s. Du erhältst diese noch vor dem Verkauf zurück.", AddDelimiters(Biz[b][bKasse]));
        SendClientMessage(playerid, COLOR_YELLOW, message);
    }

    Biz[b][bKasse] = 0;
    Spieler[playerid][pBank] += Biz[b][bPreis] / 4;
    format(message, sizeof(message), "Du hast dein Biz '%s' an den Staat für $%s verkauft.", Biz[b][bName], AddDelimiters(Biz[b][bPreis] / 4));
    UpdateBizText(b);
    return SendClientMessage(playerid, COLOR_WHITE, message);
}


CMD:bizankaufen(playerid,params[]) {
    new
        giveid;
    if(sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Bizankaufen [ID]");
    }
    if( !IsPlayerConnected(giveid) || giveid == playerid) {
        SendClientMessage(playerid,COLOR_RED,"Ungültiger Spieler.");
        return 1;
    }
    if( Spieler[playerid][pPlayerBiz] != 999) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits ein Geschäft.");
    }
    new indexbiz = Spieler[giveid][pPlayerBiz];
    if( indexbiz == 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Verkäufer ist nicht mehr in Besitz des angebotenen Geschäftes.");
    }
    if( Spieler[giveid][pBizAngebot][0] != playerid ) {
        SendClientMessage(playerid,COLOR_RED,"Dieser Spieler hat dir kein Geschäft zum Verkauf angeboten.");
        return 1;
    }
    new
        string[128],
        price,
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,5.0,x,y,z)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Verkäufer muss sich in deiner Nähe befinden.");
    }
    price = Spieler[giveid][pBizAngebot][1];
    if( price > Spieler[playerid][pCash] ) {
        format(string,sizeof(string),"Du hast nicht genug Geld auf der Hand um das Geschäft zu kaufen ($%s).", AddDelimiters(price));
        return SendClientMessage(playerid, COLOR_RED, string);
    }
    format(string,sizeof(string),"Du hast dein Geschäft an %s verkauft! Er hat dein Angebot angenommen und ist nun der neue Besitzer.",GetName(playerid));
    SendClientMessage(giveid,COLOR_GREEN,string);
    format(string,sizeof(string),"Du(%s) hast das Geschäft erfolgreich von %s abgekauft!",GetName(giveid));
    SendClientMessage(playerid,COLOR_GREEN,string);
    SendClientMessage(playerid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");
    SendClientMessage(giveid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");

    format(string,sizeof(string),"[BIZKAUF] Verkäufer: %s, Käufer: %s, Preis: %d",GetName(giveid),GetName(playerid),price);
    KaufLog(string);

    Spieler[giveid][pBizAngebot][0] = INVALID_PLAYER_ID;
    Spieler[giveid][pBizAngebot][1] = 0;
    Spieler[giveid][pPlayerBiz] = 999;

    Biz[indexbiz][bErpresserFraktion] = 0;
    Biz[indexbiz][bErpresserForderung] = 0;
    Biz[indexbiz][bErpresserState] = 0;
    Biz[indexbiz][bKasse] = 0;

    Spieler[playerid][pPlayerBiz] = indexbiz;
    format( Biz[indexbiz][bBesitzer] , MAX_PLAYER_NAME , GetName(playerid) );
    GivePlayerCash(playerid, -price);
    GivePlayerCash(giveid, price);

    UpdateBizText(indexbiz);
    return 1;
}


CMD:warenkaufen(playerid,params[]) {
    new idx = -1, menge;
    if (sscanf(params, "d", menge) || menge < 1) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Warenkaufen [Menge]");
    if (IsPlayerInRangeOfPoint(playerid, 6.0, 2187.6926, -2263.8967, 13.4674)) {
        idx = 0;
    }
    if( IsPlayerInRangeOfPoint(playerid,6.0, 2571.6233, -2226.6980, 13.3550) ) {
        idx = 1;
    }
    if( idx == -1 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keinem Ort, wo du Benzin kaufen kannst.");
    }
    new indexbiz = Spieler[playerid][pPlayerBiz];
    if( indexbiz == 999) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein BIZ!");
    }
    if( StaticBiz[idx][SBD_iWaren] < menge ) {
        return SendClientMessage(playerid, COLOR_RED, "Das Lager kann deinen Bedarf an Waren nicht decken.");
    }
    new
        String[128];
    if( Biz[indexbiz][bMaxWaren] < Biz[indexbiz][bWaren] + menge ) {
        format(String,sizeof(String),"Diese Menge kannst du nicht kaufen, da dein BIZ nur maximal %d Waren halten kann (noch %d).",Biz[indexbiz][bMaxWaren],( Biz[indexbiz][bMaxWaren] - Biz[indexbiz][bWaren] ) );
        return SendClientMessage(playerid, COLOR_RED, String );
    }
    new price = menge * 20;
    if( Spieler[playerid][pCash] < price ) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht genug Geld. Jede Ware kostet $20.");
    }
    format(String,sizeof(String),"Du hast für dein BIZ %d Waren für je $20 pro Ware gekauft (-$%s).",menge, AddDelimiters(price));
    SendClientMessage(playerid,COLOR_YELLOW,String);
    GivePlayerCash(playerid,-price);
    Biz[indexbiz][bWaren] += menge;
    StaticBiz[idx][SBD_iWaren] -= menge;
    UpdateStaticBizText(idx);
    return 1;
}


CMD:bizkey(playerid,params[]) {
    new String[256];
    if( Spieler[playerid][pPlayerBiz] != 999 ) {
        format(String,sizeof(String),"%s - {00FF00}Schluessel ausgewählt{FFFFFF}",Biz[ Spieler[playerid][pPlayerBiz] ][bName] );
    }
    else {
        format(String,sizeof(String),"Leerer Slot - {00FF00}Schluessel ausgewählt{FFFFFF}");
    }
    if( Spieler[playerid][pPremiumBizSlot] == 1 ) {
        if( Spieler[playerid][pPlayerBizEx] != 999 ) {
            format(String,sizeof(String),"%s\n%s",String,Biz[ Spieler[playerid][pPlayerBizEx] ][bName] );
        }
        else {
            format(String,sizeof(String),"%s\nExtra Bizkey freigeschaltet | Kein Geschäft vorhanden",String);
        }
    }
    else {
        format(String,sizeof(String),"%s\n(Zweiter Geschäftsschlüssel nicht freischaltet)",String);
    }
    ShowPlayerDialog(playerid,DIALOG_BIZKEY,DIALOG_STYLE_LIST,"Geschäftsschlüssel",String,"Auswählen","Abbruch");
    return 1;
}



CMD:kleidung(playerid)
{
    new tempCurBiz = GetPlayerVirtualWorld(playerid);
	if(IsPlayerInRangeOfPoint(playerid, 2.0, 207.3304,-101.0623,1005.2578) || IsPlayerInRangeOfPoint(playerid, 2.0, 206.3741,-8.2514,1001.2109) || IsPlayerInRangeOfPoint(playerid, 2.0, 161.4904,-83.8694,1001.8047)) {
		if(tempCurBiz == 25 || tempCurBiz == 26  || tempCurBiz == 27 || tempCurBiz == 28 || tempCurBiz == 29 || tempCurBiz == 30 || tempCurBiz == 31 || tempCurBiz == 32 || tempCurBiz == 33 || tempCurBiz == 34 || tempCurBiz == 35 ) {
			pCurrentBiz[playerid] = tempCurBiz;

            if(Biz[GetBizIndexByID(tempCurBiz)][bWaren] < 1){
                SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat nicht mehr genügend Waren.");
                return 1;
            }

            //StartPlayerSkinSelection(playerid);
            GivePlayerCash(playerid, -2500);
            Biz[GetBizIndexByID(tempCurBiz)][bKasse] += 2500;
            Biz[GetBizIndexByID(tempCurBiz)][bWaren] -= 2;

            SendClientMessage(playerid, COLOR_DARKGREEN, "[SKIN] {FFFFFF}Du zahlst $2.500 Servicepauschale für die Benutzung der Umkleide.");

            new dialogstr[2056];
            if(Spieler[playerid][pFraktion] == 0){
                for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 1){
                for (new i = 0, j = sizeof(skins_pd_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_pd_array[i]);
                }
			}else if(Spieler[playerid][pFraktion] == 2){
			    for (new i= 0, j = sizeof(skins_fbi_array); i < j; i++) {
			        format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_fbi_array[i]);
				}
			}else if(Spieler[playerid][pFraktion] == 3){
                for (new i = 0, j = sizeof(skins_samd_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_samd_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 4){
                for (new i = 0, j = sizeof(skins_news_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_news_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 5){
                for (new i = 0, j = sizeof(skins_oamt_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_oamt_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 6){
                for (new i = 0, j = sizeof(skins_gsf_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_gsf_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 7){
                for (new i = 0, j = sizeof(skins_ballas_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_ballas_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 9){
                for (new i = 0, j = sizeof(skins_regierung_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_regierung_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 10){
                for (new i = 0, j = sizeof(skins_yakuza_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_yakuza_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 11){
                for (new i = 0, j = sizeof(skins_aztecas_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_aztecas_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 12){
                for (new i = 0, j = sizeof(skins_cali_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_cali_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 13){
                for (new i = 0, j = sizeof(skins_vagos_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_vagos_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 14){
                for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 15){
                for (new i = 0, j = sizeof(skins_nd_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_nd_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 19){
                for (new i = 0, j = sizeof(skins_terrorist_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_terrorist_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 20){
                for (new i = 0, j = sizeof(skins_lcn_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_lcn_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 21){
                for (new i = 0, j = sizeof(skins_triaden_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_triaden_array[i]);
                }
            }else if(Spieler[playerid][pFraktion] == 22){
                for (new i = 0, j = sizeof(skins_zollamt_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_zollamt_array[i]);
                }
            }
			else{
                for (new i = 0, j = sizeof(skins_array); i < j; i++) {
                    format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[i]);
                }
            }
            ShowPlayerDialog(playerid, DIALOG_SKINS, DIALOG_STYLE_PREVMODEL, "LyD - Kleidungsladen", dialogstr, "Ok", "Abbrechen");
        }
    }
    return 1;
}



CMD:supermarkt(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 3.0, 2.3256,-29.0143,1003.5494) && GetPlayerInterior(playerid) == 10 || IsPlayerInRangeOfPoint(playerid, 3.0, 2.2309,-29.0142,1003.5494) && GetPlayerInterior(playerid) == 10 || IsPlayerInRangeOfPoint(playerid, 3.0, 2.1795,-29.0144,1003.5494) && GetPlayerInterior(playerid) == 10 ||
 	   IsPlayerInRangeOfPoint(playerid, 3.0, 2.0509,-29.0145,1003.5494) && GetPlayerInterior(playerid) == 10 || IsPlayerInRangeOfPoint(playerid, 3.0, 2.2932,-29.0144,1003.5494) && GetPlayerInterior(playerid) == 10)
    {
    	ShowPlayerDialog(playerid, DIALOG_MARKT, DIALOG_STYLE_LIST, "Super Markt", "Telefonbuch ($15000)\nKekse ($750)\n10 Zigaretten ($2250)\nHelm ($10.000)\nMusikkit (MP3-Player + Ghettoblaster) ($22.500)\nKoffer ($10.500)\nFallschirm ($10.200)\nPfandflaschen verkaufen (+$1.500)\nBooster ($20.000)\nPower-Riegel ($5.000)\nSchaufel ($25.000)", "Kaufen", "Abbrechen");
     	return 1;
        }
     else
	{
	    SendClientMessage(playerid, COLOR_RED,"Du bist nicht an der Kasse eines 24/7!");
	}
	return 1;
}

CMD:drivein(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 5.0, SUBWAY_DRIVEIN_COORDS)) // Burgershot North
    {
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[GetBizIndexByID(2)][bKasse] += 50;
        Biz[GetBizIndexByID(2)][bWaren] -= 1;
        return SendClientMessage(playerid, COLOR_ORANGE, "[DRIVE-IN] {FFFFFF}Du hast dir ein Chicken Teriyaki Sub am Drive-In bestellt.");
    }

    return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist an keinem Drive-In.");
}

CMD:essen(playerid)
{
    new pVW = GetPlayerVirtualWorld(playerid), bIndex;
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 373.7167,-119.1190,1001.4922) && pVW == 5) // Pizza Stack Idlewood
    {
        bIndex = GetBizIndexByID(5);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 373.7167,-119.1190,1001.4922) && pVW == 6) // Pizza Stack - Shopping Market
    {
        bIndex = GetBizIndexByID(6);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 373.7167,-119.1190,1001.4922) && pVW == 7) // Pizza Stack Palomino Creek
    {
        bIndex = GetBizIndexByID(7);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 373.7167,-119.1190,1001.4922) && pVW == 8) // Pizza Stack Emerald Isle
    {
        bIndex = GetBizIndexByID(8);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
        ClearAnimations(playerid);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 373.7167,-119.1190,1001.4922) && pVW == 9) // Pizza Stack - Blue Berry
    {
        bIndex = GetBizIndexByID(9);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 368.1664,-6.0193,1001.8516) && pVW == 10) // Cluckin Bell Old Venturas Strip
    {
        bIndex = GetBizIndexByID(10);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 368.1664,-6.0193,1001.8516) && pVW == 11) // Cluckin Bell - Shopping Market
    {
        bIndex = GetBizIndexByID(11);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 368.1664,-6.0193,1001.8516) && pVW == 12) // Cluckin Bell Emerald Isle
    {
        bIndex = GetBizIndexByID(12);
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 368.1664,-6.0193,1001.8516) && pVW == 13) // Cluckin Bell Willowfield
    {
        bIndex = GetBizIndexByID(13);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 368.1664,-6.0193,1001.8516) && pVW == 14) // Cluckin Bell East Los Santos
    {
        bIndex = GetBizIndexByID(14);
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 376.5080,-67.6393,1001.5151) && pVW == 15) // Burger Shot Redsands East
    {
        bIndex = GetBizIndexByID(15);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 376.5080,-67.6393,1001.5151) && pVW == 16) // Burger Shot Whitewood Estates
    {
        bIndex = GetBizIndexByID(16);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 376.5080,-67.6393,1001.5151) && pVW == 17) // Burger Shot Garcia
    {
        bIndex = GetBizIndexByID(17);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 376.5080,-67.6393,1001.5151) && pVW == 18) // Burger Shot Verona Beach
    {
        bIndex = GetBizIndexByID(18);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 376.5080,-67.6393,1001.5151) && pVW == 19) // Burger Shot San Fierro Downtown
    {
        bIndex = GetBizIndexByID(19);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 376.5080,-67.6393,1001.5151) && pVW == 20) // Subway
    {
        bIndex = GetBizIndexByID(20);
        SendClientMessage(playerid, COLOR_WHITE, "Verkäufer sagt: Guten Appetit! Besuchen Sie uns bald wieder.");
        if(Biz[bIndex][bWaren] < 1)return SendClientMessage(playerid, COLOR_RED, "Das Geschäft hat keine Waren mehr.");
        if(CheckMoney(playerid) < 50)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Geld!");
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        SetPlayerHealth(playerid, 100);
        GivePlayerCash(playerid, -50);
        Biz[bIndex][bKasse] += 50;
        Biz[bIndex][bWaren] -= 1;
        ShowBuyInformation(playerid,"~y~Essen ~w~gekauft!");
    }
    return 1;
}

CMD:wmenu(playerid)
{
    if(HasWeaponBlock(playerid)) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst keine Waffen erwerben.");
        return SendWeaponBlockInfo(playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 296.4476,-37.9833,1001.5156) || IsPlayerInRangeOfPoint(playerid, 2.0, 312.1370,-165.9137,999.6010) || IsPlayerInRangeOfPoint(playerid, 2.0, 295.5200,-80.3668,1001.5156) || IsPlayerInRangeOfPoint(playerid, 2.0, 313.3604,-139.3339,1004.0625))
    {
        ShowPlayerDialog(playerid, DIALOG_WMENU, DIALOG_STYLE_LIST, "Waffenmenu", "\
        Schlagring (1500$)\n\
        Baseball Schläger (1800$)\n\
        Schaufel (1800$)\n\
        Schutzweste (4.000$)\n\
        9mm (4.200$ - 50 Munition) [A]\n\
        Silenced 9mm (5.200$ - 50 Munition) [A]\n\
        Desert Eagle (6.600$ - 50 Munition) [A]\n\
        Shotgun (12.800$ - 20 Munition) [A]\n\
        MP5 (13.600$ - 130 Munition) [B]\n\
        M4 (22.000$ - 130 Munition) [B]\n\
        AK-47 (22.400$ - 130 Munition) [B]\n\
        Rifle (24.000$ - 30 Munition) [B]\n\
        Waffenbündel\n\
        Spawn Schutzweste(5.000.000$ - 10 Tage)", "Kaufen", "Abbrechen");
    }
    return 1;
}

CMD:shisha(playerid, params[]) {
    if (isnull(params)) {
        for (new i = 0; i < sizeof(g_shishaPoints); i++) {
            if (IsPlayerInRangeOfPoint(playerid, 5.0, g_shishaPoints[i][0], g_shishaPoints[i][1], g_shishaPoints[i][2])) {
                new dialogText[512] = COLOR_HEX_WHITE "Sorte\t" COLOR_HEX_WHITE "Preis\n";
                for (i = 0; i < sizeof(g_shishaPipes); i++)
                    format(dialogText, sizeof(dialogText), "%s%s%s\t{FFFFFF}$%s\n", dialogText, g_shishaPipes[i][SHISHA_PIPE_HEX_COLOR], g_shishaPipes[i][SHISHA_PIPE_NAME], AddDelimiters(g_shishaPipes[i][SHISHA_PIPE_COST]));

                return ShowPlayerDialog(playerid, DIALOG_SHISHA, DIALOG_STYLE_TABLIST_HEADERS, COLOR_HEX_ORANGE "Shisha bestellen", dialogText, "Kaufen", "Abbrechen");
            }
        }

        return SendClientMessage(playerid, COLOR_RED, "Hier kannst du keine Shisha bestellen.");
    }

    if (!strcmp(params, "aus", true)) {
        if (!GetPVarInt(playerid, "SHISHA.SMOKING")) return SendClientMessage(playerid, COLOR_RED, "Du rauchst doch gar keine Shisha.");
        SetPVarInt(playerid, "SHISHA.SMOKING", 0);
        if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        RemovePlayerAttachedObject(playerid, 0);
        new message[128], Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x ,y ,z);
        format(message, sizeof(message), "* %s hat mit dem Shisharauchen aufgehört.", GetName(playerid));
        return SendRoundMessage(x, y, z, COLOR_PURPLE, message);
    }

    return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /shisha oder /shisha Aus");
}

CMD:clubwaffen(playerid)
{
    if(HasWeaponBlock(playerid)) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst keine Waffen erwerben.");
        return SendWeaponBlockInfo(playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, CLUBINTERIORLS_WEAPONS_POINT) && GetPlayerInterior(playerid) == 9 || IsPlayerInRangeOfPoint(playerid, 2.0, -2656.1047,1416.0248,906.2734) && GetPlayerInterior(playerid) == 3)
    {
        //if(Spieler[playerid][pGunLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Du besitzt keinen Waffenschein.");
        ShowPlayerDialog(playerid, CDIALOG_WMENU, DIALOG_STYLE_LIST, "Club Waffenmenu", "\
        Schlagring (800$)\n\
        Baseball Schläger (1200$)\n\
        Schaufel (1200$)\n\
        Schutzweste (2.400$)\n\
        9mm (3.000$ - 100 Munition) [A]\n\
        Silenced 9mm (3.600$ - 100 Munition) [A]\n\
        Desert Eagle (5.200$ - 100 Munition) [A]\n\
        Shotgun (10.000$ - 50 Munition) [A]\n\
        MP5 (10.400$ - 150 Munition) [B]\n\
        M4 (16.400$ - 200 Munition) [B]\n\
        AK-47 (18.400$ - 200 Munition) [B]\n\
        Rifle (24.000$ - 30 Munition) [B]\n\
        Waffenbündel\n\
        Spawn Schutzweste(3.750.000$ - 10 Tage)", "Kaufen", "Abbrechen");
    }
    return 1;
}



CMD:bizkaufen(playerid, params[])
{
    #if defined NEUE_WIRTSCHAFT
        return SendClientMessage(playerid, COLOR_RED, "Diese Funktion ist momentan deaktiviert!");
    #else
        if(Spieler[playerid][pPlayerBiz] != 999 )return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits ein Geschäft!");
        for(new i=1;i<sizeof(Biz);i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, Biz[i][EnterX], Biz[i][EnterY], Biz[i][EnterZ]))
            {
                if( Spieler[playerid][pLevel] < 5 ) {
                    return SendClientMessage(playerid, COLOR_RED, "Dein Level ist zu niedrig um ein Geschäft zu kaufen! Du musst Level 5 erreichen um ein Geschäft kaufen zu können.");
                }
                if(strcmp(Biz[i][bBesitzer], "Niemand", true) == 0)
                {
                    if(Spieler[playerid][pPerso] == 0)return SendClientMessage(playerid, COLOR_RED, "Du benötigst einen Personalausweis.");
                    if(CheckMoney(playerid) < Biz[i][bPreis])return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht genügend Geld.");
                    new string[128];
                    Spieler[playerid][pPlayerBiz] = i;
                    strmid(Biz[i][bBesitzer], GetName(playerid), 0, MAX_PLAYER_NAME, 255);
                    GivePlayerCash(playerid, -Biz[i][bPreis]);
                    if(Biz[i][bInterior] > 0)
                    {
                        SetPlayerInterior(playerid, Biz[i][bInterior]);
                        SetPlayerVirtualWorld(playerid, Biz[i][bID]);
                        SetPlayerPos(playerid, Biz[i][ExitX], Biz[i][ExitY], Biz[i][ExitZ]);
                    }
                    format(string, sizeof(string), "Du hast erfolgreich dieses Geschäft gekauft. (-$%s)", AddDelimiters(Biz[i][bPreis]));
                    SendClientMessage(playerid, COLOR_GREEN, string);
                    SendClientMessage(playerid, COLOR_WHITE, "Wichtige Befehle um dein Geschäft zu verwalten findest du unter /Help -> Geschäfts-Befehle.");
                    SendClientMessage(playerid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");
                    ShowBuyInformation(playerid,"~y~Geschaeft ~w~gekauft!");
                    UpdateBizText(i);
                }
            }
        }
        return 1;
    #endif
}

CMD:warenpreis(playerid, params[])
{
    new preis, string[128];
    if(sscanf(params, "i", preis))return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Warenpreis [Betrag]");
    new b = IsPlayerAtBiz(playerid);
    if(b == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Geschäftes.");
    if(preis < 10 || preis > 20)return SendClientMessage(playerid, COLOR_ORANGE, "Der Preis muss zwischen $10 und $25 liegen!");
    if(strcmp(GetName(playerid), Biz[b][bBesitzer], true) == 0)
    {
        Biz[b][bWarenPreis] = preis;
        format(string, sizeof(string), "Du hast den Warenpreis in $%d geändert.", preis);
        SendClientMessage(playerid, COLOR_GREEN, string);
        UpdateBizText(b);
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer des Geschäftes.");
        return 1;
    }
    return 1;
}


CMD:biztuer(playerid, params[])
{
    new status[12];
    if(sscanf(params, "s[12]", status))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Biztuer [Auf/Zu]");
    if(strcmp(status, "AUF", true) == 0)
    {
        for(new h = 1; h < MAX_BIZES; h++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, Biz[h][EnterX], Biz[h][EnterY], Biz[h][EnterZ]) || (IsPlayerInRangeOfPoint(playerid, 4.0, Biz[h][ExitX], Biz[h][ExitY], Biz[h][ExitZ]) && GetPlayerVirtualWorld(playerid) == h))
            {
                if(Spieler[playerid][pPlayerBiz] == h)
                {
                    if(Biz[h][bLock] == 1)
                    {
                        Biz[h][bLock] = 0;
                        GameTextForPlayer(playerid, "~w~Geschaeft ~g~Auf", 5000, 6);
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_ORANGE, "Das Geschäft ist bereits offen.");
                        return 1;
                    }
                }
                else
                {
                    SendClientMessage(playerid, COLOR_RED, "Dieses Geschäft gehört dir nicht.");
                    return 1;
                }
            }
        }
    }
    else if(strcmp(status, "ZU", true) == 0)
    {
        for(new h = 1; h < MAX_BIZES; h++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, Biz[h][EnterX], Biz[h][EnterY], Biz[h][EnterZ]) || (IsPlayerInRangeOfPoint(playerid, 4.0, Biz[h][ExitX], Biz[h][ExitY], Biz[h][ExitZ]) && GetPlayerVirtualWorld(playerid) == h))
            {
                if(Spieler[playerid][pPlayerBiz] == h)
                {
                    if(Biz[h][bLock] == 0)
                    {
                        Biz[h][bLock] = 1;
                        GameTextForPlayer(playerid, "~w~Geschaeft ~r~Zu", 5000, 6);
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_ORANGE, "Das Geschäft ist bereits zu.");
                        return 1;
                    }
                }
                else
                {
                    SendClientMessage(playerid, COLOR_RED, "Dieses Geschäft gehört dir nicht.");
                    return 1;
                }
            }
        }
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/biztuer [Auf/Zu]");
    return 1;
}




CMD:maxwaren(playerid, params[])
{
    new b = IsPlayerAtBiz(playerid);
    if(b == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Geschäftes.");
    if(strcmp(GetName(playerid), Biz[b][bBesitzer], true) == 0)
    {
        ShowPlayerDialog(playerid, DIALOG_MAXWAREN, DIALOG_STYLE_LIST, "Maximale Waren Anzahl ändern", "100 Waren ($5000)\n200 Waren ($10.000)\n300 Waren ($15.000)\n400 Waren ($20.000)\n500 Waren ($25.000)", "Auswählen", "Abbrechen");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieses Geschäftes.");
        return 1;
    }
    return 1;
}


CMD:clubheal(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, CLUBINTERIORLS_HEAL_POINT) || IsPlayerInRangeOfPoint(playerid, 2.0, -2653.5183,1413.5085,906.2734))//Clubheilen
    {
        if(Spieler[playerid][pHeilReady] == 0)return SendClientMessage(playerid, COLOR_YELLOW, "In der Clubküche wird gerade für dich gekocht, warte einen Moment.");
        Spieler[playerid][pHeilReady] = 0;
        SetPlayerHealth(playerid, 100);
        SetTimerEx("HeilReady", 6000, 0, "i", playerid);
    }
    return 1;
}


CMD:bizkasse(playerid, params[])
{
    new entry, string[128], eingabe[16];
    if(sscanf(params, "s[16]i", eingabe, entry))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Bizkasse [Anlegen/Nehmen] [Betrag]");
    new h=IsPlayerAtBiz(playerid);
    if(h==999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich vor keinem Geschäft.");
    if(entry < 1 || entry > 100000000)return SendClientMessage(playerid, COLOR_RED, "Der Betrag sollte zwischen $1 und $100.000.000 liegen.");
    if(strcmp(eingabe, "anlegen", true) == 0)
    {
        if(CheckMoney(playerid) < entry)return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
        if(strcmp(GetName(playerid), Biz[h][bBesitzer], true) == 0)
        {
            GivePlayerCash(playerid, -entry);
            Biz[h][bKasse] += entry;
            format(string, sizeof(string), "Du hast $%s in die Geschäftskasse eingezahlt. Neuer Stand: $%s.", AddDelimiters(entry), AddDelimiters(Biz[h][bKasse]));
            SendClientMessage(playerid, COLOR_WHITE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieses Geschäftes.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "nehmen", true) == 0)
    {
        if(strcmp(GetName(playerid), Biz[h][bBesitzer], true) == 0)
        {
            if(entry > Biz[h][bKasse])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            GivePlayerCash(playerid, entry);
            Biz[h][bKasse] -= entry;
            format(string, sizeof(string), "Du hast $%s aus der Geschäftskasse ausgezahlt. Neuer Stand: $%s.", AddDelimiters(entry), AddDelimiters(Biz[h][bKasse]));
            SendClientMessage(playerid, COLOR_WHITE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieses Geschäftes.");
            return 1;
        }
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Bizkasse [Anlegen/Nehmen] [Betrag]");
    return 1;
}


CMD:bizkassestand(playerid)
{
    new h=IsPlayerAtBiz(playerid);
    if(h==999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich vor keinem Geschäft.");
    if(Spieler[playerid][pAdmin] > 2 || strcmp(GetName(playerid), Biz[h][bBesitzer], true) == 0)
    {
        new string[128];
        format(string, sizeof(string), "* Geschäfts-Kasse: $%s *", AddDelimiters(Biz[h][bKasse]));
        SendClientMessage(playerid, COLOR_GREEN, string);
        SendClientMessage(playerid, COLOR_WHITE, "Um Geld von der Kasse zu nehmen oder anzulegen tippe /Bizkasse [Anlegen/Nehmen].");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Da du nicht der Besitzer bist, kannst du auch nicht auf die Kasse schauen.");
        return 1;
    }
    return 1;
}



CMD:eintritt(playerid, params[])
{
    new preis, string[128], b=IsPlayerAtBiz(playerid);
    if(b==999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich vor keinem Geschäft.");
    if(sscanf(params, "i", preis))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Eintritt [Preis]");
    if(preis < 1 || preis > 1000)return SendClientMessage(playerid, COLOR_RED, "Der Eintrittspreis muss zwischen $1 und $1.000 liegen.");
    if(strcmp(GetName(playerid), Biz[b][bBesitzer], true) == 0)
    {
        Biz[b][bEintritt] = preis;
        format(string, sizeof(string), "Du hast den Eintritt des Geschäftes auf $%s gesetzt.", AddDelimiters(preis));
        SendClientMessage(playerid, COLOR_WHITE, string);
        UpdateBizText(b);
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieses Geschäftes.");
        return 1;
    }
    return 1;
}



