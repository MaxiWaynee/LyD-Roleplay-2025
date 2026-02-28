#include <YSI\y_hooks>

#define CASINO_INTERIOR_BUYDRINK_POINT        1139.7220, -3.8690,    1000.6719
#define CASINO_INTERIOR_DICE_POINT            1125.2020, -5.0443,    1000.6797
#define CASINO_INTERIOR_CARDS_POINT           1125.2571,  1.6034,    1000.6797
#define CASINO_INTERIOR_WHEEL_POINT           1119.0223, -1.7730,    1000.6910
#define CASINO_INTERIOR_SLOT1_POINT           1132.8966, -1.6311,    1000.6797
#define CASINO_INTERIOR_BLACKJACK_POINT       1128.7091, -1.8011,    1000.6797
#define MAX_BJTISCHE 						  7

new pickup_casinoInterior[1];
new text3D_casinoInterior[5];
new PlayerText:Blackjack[MAX_PLAYERS][45];

enum BJack {
	BJ_Player = INVALID_PLAYER_ID,
	bool: BJ_Besetzt
}
new BJPlayer[MAX_BJTISCHE][BJack];

 

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == Blackjack[playerid][43]) {
        for(new i; i < 45; i++) {
            PlayerTextDrawHide(playerid, Blackjack[playerid][i]);
        }
		for(new o; o < MAX_BJTISCHE; o++) {
			BJPlayer[o][BJ_Player] = INVALID_PLAYER_ID;				
			BJPlayer[o][BJ_Besetzt] = false;
			new slot,sitz;
			GetBlackjackSlot(playerid,slot,sitz);
			PlayerTextDrawSetString(playerid, Blackjack[playerid][slot], "_");
			PlayerTextDrawSetString(playerid, Blackjack[playerid][sitz], "Frei");
		}
        CancelSelectTextDraw(playerid);
        SetCameraBehindPlayer(playerid);
    }
    if(playertextid == Blackjack[playerid][33]) {
		if(BJPlayer[0][BJ_Besetzt] == true) return SendClientMessage(playerid,COLOR_RED,"Dieser Platz ist bereits besetzt.");
        BJPlayer[0][BJ_Player] = playerid;
        BJPlayer[0][BJ_Besetzt] = true;
        PlayerTextDrawHide(playerid, Blackjack[playerid][34]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][35]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][36]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][37]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][38]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][39]);
        PlayerTextDrawSetString(playerid, Blackjack[playerid][26], GetName(playerid));
        PlayerTextDrawSetString(playerid, Blackjack[playerid][33], "Besetzt");
    }
    if(playertextid == Blackjack[playerid][34]) {
		if(BJPlayer[1][BJ_Besetzt] == true) return SendClientMessage(playerid,COLOR_RED,"Dieser Platz ist bereits besetzt.");
        BJPlayer[1][BJ_Player] = playerid;
        BJPlayer[1][BJ_Besetzt] = true;
        PlayerTextDrawHide(playerid, Blackjack[playerid][33]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][35]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][36]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][37]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][38]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][39]);
        PlayerTextDrawSetString(playerid, Blackjack[playerid][27], GetName(playerid));
        PlayerTextDrawSetString(playerid, Blackjack[playerid][34], "Besetzt");
    }
    if(playertextid == Blackjack[playerid][35]) {
		if(BJPlayer[2][BJ_Besetzt] == true) return SendClientMessage(playerid,COLOR_RED,"Dieser Platz ist bereits besetzt.");
        BJPlayer[2][BJ_Player] = playerid;
        BJPlayer[2][BJ_Besetzt] = true;
        PlayerTextDrawHide(playerid, Blackjack[playerid][33]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][34]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][36]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][37]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][38]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][39]);
        PlayerTextDrawSetString(playerid, Blackjack[playerid][28], GetName(playerid));
        PlayerTextDrawSetString(playerid, Blackjack[playerid][35], "Besetzt");
    }
    if(playertextid == Blackjack[playerid][36]) {
		if(BJPlayer[3][BJ_Besetzt] == true) return SendClientMessage(playerid,COLOR_RED,"Dieser Platz ist bereits besetzt.");
        BJPlayer[3][BJ_Player] = playerid;
        BJPlayer[3][BJ_Besetzt] = true;
        PlayerTextDrawHide(playerid, Blackjack[playerid][33]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][34]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][35]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][37]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][38]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][39]);
        PlayerTextDrawSetString(playerid, Blackjack[playerid][29], GetName(playerid));
        PlayerTextDrawSetString(playerid, Blackjack[playerid][36], "Besetzt");
    }
    if(playertextid == Blackjack[playerid][37]) {
		if(BJPlayer[4][BJ_Besetzt] == true) return SendClientMessage(playerid,COLOR_RED,"Dieser Platz ist bereits besetzt.");
        BJPlayer[4][BJ_Player] = playerid;
        BJPlayer[4][BJ_Besetzt] = true;
        PlayerTextDrawHide(playerid, Blackjack[playerid][33]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][34]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][35]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][36]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][38]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][39]);
        PlayerTextDrawSetString(playerid, Blackjack[playerid][30], GetName(playerid));
        PlayerTextDrawSetString(playerid, Blackjack[playerid][37], "Besetzt");
    }
    if(playertextid == Blackjack[playerid][38]) {
		if(BJPlayer[5][BJ_Besetzt] == true) return SendClientMessage(playerid,COLOR_RED,"Dieser Platz ist bereits besetzt.");
        BJPlayer[5][BJ_Player] = playerid;
        BJPlayer[5][BJ_Besetzt] = true;
        PlayerTextDrawHide(playerid, Blackjack[playerid][33]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][34]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][35]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][36]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][37]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][39]);
        PlayerTextDrawSetString(playerid, Blackjack[playerid][31], GetName(playerid));
        PlayerTextDrawSetString(playerid, Blackjack[playerid][38], "Besetzt");
    }
    if(playertextid == Blackjack[playerid][39]) {
		if(BJPlayer[6][BJ_Besetzt] == true) return SendClientMessage(playerid,COLOR_RED,"Dieser Platz ist bereits besetzt.");
        BJPlayer[6][BJ_Player] = playerid;
        BJPlayer[6][BJ_Besetzt] = true;
        PlayerTextDrawHide(playerid, Blackjack[playerid][33]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][34]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][35]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][36]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][37]);
        PlayerTextDrawHide(playerid, Blackjack[playerid][38]);
        PlayerTextDrawSetString(playerid, Blackjack[playerid][32], GetName(playerid));
        PlayerTextDrawSetString(playerid, Blackjack[playerid][39], "Besetzt");
    }
    return 1;
}



CMD:gluecksrad(playerid,params[]) {
    new zahl,einsatz;
    if(sscanf(params,"dd",zahl,einsatz)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Gluecksrad [Zahl] [Einsatz(Min. $1.000)]");
    if( !IsPlayerInRangeOfPoint(playerid,5.0, CASINO_INTERIOR_WHEEL_POINT)) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht beim Glücksrad!");
    if( Spieler[playerid][pCash] >= einsatz) {
        new dice = random(10)+1;
        if(zahl > 10 || zahl < 1 )return SendClientMessage(playerid, COLOR_RED, "Die geschätzte Zahl muss zwischen 1 und 10 liegen.");
        if(einsatz < 1000) return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens 1.000$ setzten.");
        if(zahl == dice) {
            new string[128];
            format(string,sizeof(string), "Du hast auf die %d getippt und gewonnen! Dein Einsatz verfünffacht sich.",zahl);
            SendClientMessage(playerid,COLOR_GREEN,string);
            GameTextForPlayer(playerid, "~g~GEWONNEN!!!", 4000, 1);
            GivePlayerCash(playerid, 5 * einsatz);
            Biz[CasinoBiz_Index][bKasse] -= 5 * einsatz;
            ApplyAnimation(playerid,"CASINO","Roulette_win",4.1,0,1,1,0,5,1);
        } else {
            new string[128];
            format(string,sizeof(string), "Du hast auf die %d getippt, doch die richtige lautete %d. Dein Einsatz hat sich in Luft aufgelöst.", zahl,dice);
            GivePlayerCash(playerid,-einsatz);
            Biz[CasinoBiz_Index][bKasse] += einsatz;
            GameTextForPlayer(playerid, "~r~Leider VERLOREN", 4000, 1);
            SendClientMessage(playerid,COLOR_RED,string);
            ApplyAnimation(playerid,"CASINO","Roulette_lose",4.0,0,1,1,1,1,1);
        }
    } else {
        new string[128];
        format(string,sizeof(string),"Du benötigst mehr Geld für deinen Einsatz (%d) oder Du setzt einen niedrigeren ein.",einsatz);
        SendClientMessage(playerid,COLOR_RED,string);
    }
    return 1;
}

CMD:kartenspiel(playerid,params[]) {
    new farbe[16],einsatz;
    if(sscanf(params,"s[16]d",farbe,einsatz)) return SendClientMessage(playerid,COLOR_ORANGE,INFO_STRING"/Kartenspiel [Schwarz/Rot/Gelb/Blau/Pink] [Einsatz(Min. $1.000)]");
    if( !IsPlayerInRangeOfPoint(playerid,5.0, CASINO_INTERIOR_CARDS_POINT) ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht am Kartentisch!");
    new auswahl;
    new const ai_Farben[][] = {
        {"Rot"},
        {"Schwarz"},
        {"Gelb"},
        {"Blau"},
        {"Pink"}
    };
    for(new i = 0 ; i < sizeof(ai_Farben); i++) {
        if( !strcmp(ai_Farben[i],farbe,true) ) auswahl = i+1;
    }
    if( auswahl == 0 )return SendClientMessage(playerid,COLOR_ORANGE,INFO_STRING"/Kartenspiel [Schwarz/Rot/Gelb/Blau/Pink] [Einsatz(Min. $1.000)]");
    if( Spieler[playerid][pCash] >= einsatz) {
        new dice = random( sizeof(ai_Farben) ) + 1;
        if(einsatz < 1000) return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens 1.000$ setzten.");
        if(auswahl == dice) {
            new string[128];
            format(string,sizeof(string), "Du hast auf die Farbe %s getippt und gewonnen. Dein Einsatz verdreifacht sich.",farbe);
            SendClientMessage(playerid,COLOR_GREEN,string);
            GameTextForPlayer(playerid, "~g~GEWONNEN!!!", 4000, 1);
            GivePlayerCash(playerid, 3 * einsatz);
            Biz[CasinoBiz_Index][bKasse] -= 3 * einsatz;
            ApplyAnimation(playerid,"CASINO","Roulette_win",4.0,0,1,1,1,1,1);
        } else {
            new string[128];
            format(string,sizeof(string), "Du hast auf die Farbe %s getippt, doch die richtige Farbe war %s. Dein Einsatz hat sich in Luft aufgelöst.", farbe, ai_Farben[dice-1] );
            GivePlayerCash(playerid,-einsatz);
            Biz[CasinoBiz_Index][bKasse] += einsatz;
            GameTextForPlayer(playerid, "~r~Leider VERLOREN", 4000, 1);
            SendClientMessage(playerid,COLOR_RED,string);
            ApplyAnimation(playerid,"CASINO","Roulette_lose",4.0,0,1,1,1,1,1);
        }
    } else {
        new string[128];
        format(string,sizeof(string),"Du benötigst mehr Geld für deinen Einsatz (%d) oder Du setzt einen niedrigeren ein.",einsatz);
        SendClientMessage(playerid,COLOR_RED,string);
    }
    return 1;
}

CMD:wuerfelspiel(playerid,params[]) {
    new zahl,einsatz;
    if(sscanf(params,"dd",zahl,einsatz)) return SendClientMessage(playerid,COLOR_ORANGE,INFO_STRING"/Wuerfelspiel [1/2/3/4/5/6] [Einsatz($1.000)]");
    if( !IsPlayerInRangeOfPoint(playerid,5.0, CASINO_INTERIOR_DICE_POINT)) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht am Würfeltisch!");
    if( Spieler[playerid][pCash] >= einsatz) {
        new dice = random(6)+1;
        if(zahl > 6 || zahl < 1 ) SendClientMessage(playerid, COLOR_RED, "Die geschätzte Zahl beim Würfel muss zwischen 1 und 6 liegen.");
        if(einsatz < 1000) return SendClientMessage(playerid,COLOR_RED,"Du musst mindestens 1.000$ setzen.");
        if(zahl == dice) {
            new string[128];
            format(string,sizeof(string), "Du hast auf die Zahl %d getippt gewonnen. Dein Einsatz hat sich vervierfacht!",zahl);
            SendClientMessage(playerid,COLOR_GREEN,string);
            GameTextForPlayer(playerid, "~g~GEWONNEN!!!", 4000, 1);
            GivePlayerCash(playerid, 4 * einsatz);
            Biz[CasinoBiz_Index][bKasse] -= 4 * einsatz;
            ApplyAnimation(playerid,"CASINO","Slot_win_out",4.0,0,1,1,1,1,1);
        } else {
            new string[128];
            format(string,sizeof(string), "Du hast auf die Zahl %d getippt, jedoch hat der Croupier eine %d gewürfelt. Dein Einsatz hat sich in Luft aufgelöst!", zahl,dice);
            GivePlayerCash(playerid,-einsatz);
            Biz[CasinoBiz_Index][bKasse] += einsatz;
            GameTextForPlayer(playerid, "~r~Leider VERLOREN", 4000, 1);
            SendClientMessage(playerid,COLOR_RED,string);
            ApplyAnimation(playerid,"CASINO","Roulette_lose",4.0,0,1,1,1,1,1);
        }
    } else {
        new string[128];
        format(string,sizeof(string),"Du benötigst mehr Geld für deinen Einsatz (%d) oder Du setzt einen niedrigeren ein.",einsatz);
        SendClientMessage(playerid,COLOR_RED,string);
    }
    return 1;
}

/*
CMD:blackjack(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,5.0, CASINO_INTERIOR_BLACKJACK_POINT)) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht am Blackjack Tisch!");
    SetPlayerCameraPos(playerid, 1129.4247,-1.6027,1002.6797);
    SetPlayerCameraLookAt(playerid,1127.9832,-1.6027,1000.7029);
	if(BJPlayer[0][BJ_Besetzt] == false) {
        PlayerTextDrawShow(playerid, Blackjack[playerid][26]);
        PlayerTextDrawShow(playerid, Blackjack[playerid][33]);
    } else {
		PlayerTextDrawSetString(playerid, Blackjack[playerid][26], GetName(BJPlayer[0][BJ_Player]));
		PlayerTextDrawSetString(playerid, Blackjack[playerid][33], "_");
	}
	if(BJPlayer[1][BJ_Besetzt] == false) {
        PlayerTextDrawShow(playerid, Blackjack[playerid][27]);
        PlayerTextDrawShow(playerid, Blackjack[playerid][34]);
    } else {
		PlayerTextDrawSetString(playerid, Blackjack[playerid][27], GetName(BJPlayer[1][BJ_Player]));
		PlayerTextDrawSetString(playerid, Blackjack[playerid][34], "_");
    }
	if(BJPlayer[2][BJ_Besetzt] == false) {
        PlayerTextDrawShow(playerid, Blackjack[playerid][28]);
        PlayerTextDrawShow(playerid, Blackjack[playerid][35]);
    } else {
		PlayerTextDrawSetString(playerid, Blackjack[playerid][28], GetName(BJPlayer[2][BJ_Player]));
		PlayerTextDrawSetString(playerid, Blackjack[playerid][35], "_");
    }
	if(BJPlayer[3][BJ_Besetzt] == false) {
        PlayerTextDrawShow(playerid, Blackjack[playerid][29]);
        PlayerTextDrawShow(playerid, Blackjack[playerid][36]);
    } else {
		PlayerTextDrawSetString(playerid, Blackjack[playerid][29], GetName(BJPlayer[3][BJ_Player]));
		PlayerTextDrawSetString(playerid, Blackjack[playerid][36], "_");
    }
	if(BJPlayer[4][BJ_Besetzt] == false) {
        PlayerTextDrawShow(playerid, Blackjack[playerid][30]);
        PlayerTextDrawShow(playerid, Blackjack[playerid][37]);
    } else {
		PlayerTextDrawSetString(playerid, Blackjack[playerid][30], GetName(BJPlayer[4][BJ_Player]));
		PlayerTextDrawSetString(playerid, Blackjack[playerid][37], "_");
    }
	if(BJPlayer[5][BJ_Besetzt] == false) {
        PlayerTextDrawShow(playerid, Blackjack[playerid][31]);
        PlayerTextDrawShow(playerid, Blackjack[playerid][38]);
    } else {
		PlayerTextDrawSetString(playerid, Blackjack[playerid][31], GetName(BJPlayer[5][BJ_Player]));
		PlayerTextDrawSetString(playerid, Blackjack[playerid][38], "_");
    }
	if(BJPlayer[6][BJ_Besetzt] == false) {
        PlayerTextDrawShow(playerid, Blackjack[playerid][32]);
        PlayerTextDrawShow(playerid, Blackjack[playerid][39]);
    } else {
		PlayerTextDrawSetString(playerid, Blackjack[playerid][32], GetName(BJPlayer[6][BJ_Player]));
		PlayerTextDrawSetString(playerid, Blackjack[playerid][39], "_");
    }
	PlayerTextDrawShow(playerid, Blackjack[playerid][43]);
	SelectTextDraw(playerid, 0xFF0000FF);
    return 1;
}
*/


CMD:spielautomat(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,5.0,1998.4296,1014.8951,994.8906) && !IsPlayerInRangeOfPoint(playerid,5.0,1996.2943,1014.8025,994.8906) && !IsPlayerInRangeOfPoint(playerid,5.0,1989.8939,1014.8328,994.8906) && !IsPlayerInRangeOfPoint(playerid,5.0,1988.7532,1020.4262,994.8906) && !IsPlayerInRangeOfPoint(playerid,5.0,1991.1975,1020.7736,994.8906)
        && !IsPlayerInRangeOfPoint(playerid, 5.0, CASINO_INTERIOR_SLOT1_POINT) && !IsPlayerInRangeOfPoint(playerid,5.0,1996.0505,1020.6999,994.8906) && !IsPlayerInRangeOfPoint(playerid, 5.0, SHISHABAR_SLOTS_POINT) && !IsPlayerInRangeOfPoint(playerid,5.0,1998.2787,1020.6613,994.8906)) {
        return SendClientMessage(playerid,COLOR_RED,"Hier befindet sich kein Spielautomat!");
    }
    if( Spieler[playerid][pCash] < OAB_MONEY_AT_PLAYCOST ) {
        SendClientMessage(playerid,COLOR_RED,"Du besitzt nicht genug Geld ( "#OAB_MONEY_AT_PLAYCOST "$ ) um am Spielautomaten zu spielen!");
        return 1;
    }
    SendClientMessage(playerid,COLOR_GREEN,"Jede Spielrunde kostet 300$. Bei 3 gleichen Bilder erhält man 10.000$ Gewinn!");
    SendClientMessage(playerid,COLOR_WHITE,"Mit Leertaste kannst du die Rollen stoppen");
    SendClientMessage(playerid,COLOR_WHITE,"Um das Spiel zu beenden, gib /Spielautomatstop ein");
    ShowBuyInformation(playerid,"~r~-"#OAB_MONEY_AT_PLAYCOST"$");
    StartOnArmedBanditForPlayer(playerid);
    SetCameraBehindPlayer(playerid);
    TogglePlayerControllable(playerid,false);
    GivePlayerCash(playerid,-OAB_MONEY_AT_PLAYCOST);
    Biz[CasinoBiz_Index][bKasse] += OAB_MONEY_AT_PLAYCOST;
    return 1;
}

CMD:spielautomatstop(playerid,params[]) {
	if (_OAB_PlayerPlays[playerid]) {
	    StopOnArmedBanditForPlayer(playerid);
	    TogglePlayerControllable(playerid,true);
	}
    return 1;
}



hook OnPlayerConnect(playerid)
{
    Blackjack[playerid][0] = CreatePlayerTextDraw(playerid, 144.000000, 163.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][0], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][0], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][0], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][0], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][0], 0);

	Blackjack[playerid][1] = CreatePlayerTextDraw(playerid, 148.000000, 168.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][1], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][1], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][1], 0);

	Blackjack[playerid][2] = CreatePlayerTextDraw(playerid, 154.000000, 174.000000, "ld_card:cd11s");
	PlayerTextDrawFont(playerid, Blackjack[playerid][2], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][2], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][2], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][2], 0);

	Blackjack[playerid][3] = CreatePlayerTextDraw(playerid, 181.000000, 195.000000, "ld_card:cd10h");
	PlayerTextDrawFont(playerid, Blackjack[playerid][3], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][3], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][3], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][3], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][3], 0);

	Blackjack[playerid][4] = CreatePlayerTextDraw(playerid, 186.000000, 200.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][4], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][4], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][4], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][4], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][4], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][4], 0);

	Blackjack[playerid][5] = CreatePlayerTextDraw(playerid, 230.000000, 217.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][5], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][5], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][5], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][5], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][5], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][5], 0);

	Blackjack[playerid][6] = CreatePlayerTextDraw(playerid, 236.000000, 223.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][6], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][6], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][6], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][6], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][6], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][6], 0);

	Blackjack[playerid][7] = CreatePlayerTextDraw(playerid, 192.000000, 206.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][7], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][7], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][7], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][7], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][7], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][7], 0);

	Blackjack[playerid][8] = CreatePlayerTextDraw(playerid, 242.000000, 229.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][8], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][8], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][8], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][8], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][8], 0);

	Blackjack[playerid][9] = CreatePlayerTextDraw(playerid, 286.000000, 217.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][9], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][9], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][9], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][9], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][9], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][9], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][9], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][9], 0);

	Blackjack[playerid][10] = CreatePlayerTextDraw(playerid, 292.000000, 222.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][10], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][10], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][10], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][10], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][10], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][10], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][10], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][10], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][10], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][10], 0);

	Blackjack[playerid][11] = CreatePlayerTextDraw(playerid, 298.000000, 228.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][11], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][11], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][11], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][11], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][11], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][11], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][11], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][11], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][11], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][11], 0);

	Blackjack[playerid][12] = CreatePlayerTextDraw(playerid, 348.000000, 216.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][12], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][12], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][12], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][12], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][12], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][12], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][12], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][12], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][12], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][12], 0);

	Blackjack[playerid][13] = CreatePlayerTextDraw(playerid, 354.000000, 222.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][13], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][13], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][13], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][13], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][13], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][13], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][13], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][13], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][13], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][13], 0);

	Blackjack[playerid][14] = CreatePlayerTextDraw(playerid, 360.000000, 228.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][14], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][14], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][14], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][14], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][14], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][14], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][14], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][14], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][14], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][14], 0);

	Blackjack[playerid][15] = CreatePlayerTextDraw(playerid, 397.000000, 196.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][15], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][15], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][15], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][15], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][15], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][15], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][15], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][15], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][15], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][15], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][15], 0);

	Blackjack[playerid][16] = CreatePlayerTextDraw(playerid, 403.000000, 201.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][16], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][16], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][16], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][16], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][16], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][16], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][16], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][16], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][16], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][16], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][16], 0);

	Blackjack[playerid][17] = CreatePlayerTextDraw(playerid, 409.000000, 207.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, Blackjack[playerid][17], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][17], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][17], 21.000000, 34.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][17], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][17], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][17], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][17], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][17], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][17], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][17], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][17], 0);

	Blackjack[playerid][18] = CreatePlayerTextDraw(playerid, 433.000000, 163.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][18], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][18], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][18], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][18], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][18], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][18], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][18], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][18], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][18], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][18], 0);

	Blackjack[playerid][19] = CreatePlayerTextDraw(playerid, 439.000000, 168.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][19], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][19], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][19], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][19], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][19], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][19], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][19], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][19], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][19], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][19], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][19], 0);

	Blackjack[playerid][20] = CreatePlayerTextDraw(playerid, 445.000000, 174.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][20], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][20], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][20], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][20], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][20], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][20], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][20], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][20], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][20], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][20], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][20], 0);

	Blackjack[playerid][21] = CreatePlayerTextDraw(playerid, 248.000000, 131.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][21], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][21], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][21], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][21], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][21], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][21], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][21], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][21], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][21], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][21], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][21], 0);

	Blackjack[playerid][22] = CreatePlayerTextDraw(playerid, 273.000000, 131.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][22], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][22], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][22], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][22], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][22], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][22], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][22], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][22], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][22], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][22], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][22], 0);

	Blackjack[playerid][23] = CreatePlayerTextDraw(playerid, 298.000000, 131.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][23], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][23], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][23], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][23], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][23], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][23], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][23], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][23], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][23], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][23], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][23], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][23], 0);

	Blackjack[playerid][24] = CreatePlayerTextDraw(playerid, 322.000000, 131.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][24], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][24], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][24], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][24], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][24], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][24], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][24], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][24], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][24], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][24], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][24], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][24], 0);

	Blackjack[playerid][25] = CreatePlayerTextDraw(playerid, 346.000000, 131.000000, "ld_card:cd5c");
	PlayerTextDrawFont(playerid, Blackjack[playerid][25], 4);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][25], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][25], 21.000000, 33.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][25], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][25], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][25], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][25], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][25], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][25], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][25], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][25], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][25], 0);

	Blackjack[playerid][26] = CreatePlayerTextDraw(playerid, 147.000000, 141.000000, "_"); // 1
	PlayerTextDrawFont(playerid, Blackjack[playerid][26], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][26], 0.133331, 1.700000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][26], 168.000000, 47.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][26], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][26], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][26], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][26], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][26], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][26], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][26], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][26], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][26], 0);

	Blackjack[playerid][27] = CreatePlayerTextDraw(playerid, 190.000000, 174.000000, "_"); // 2
	PlayerTextDrawFont(playerid, Blackjack[playerid][27], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][27], 0.133331, 1.700000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][27], 215.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][27], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][27], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][27], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][27], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][27], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][27], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][27], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][27], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][27], 0);

	Blackjack[playerid][28] = CreatePlayerTextDraw(playerid, 236.000000, 194.000000, "_"); // 3
	PlayerTextDrawFont(playerid, Blackjack[playerid][28], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][28], 0.133331, 1.700000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][28], 260.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][28], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][28], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][28], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][28], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][28], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][28], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][28], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][28], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][28], 0);

	Blackjack[playerid][29] = CreatePlayerTextDraw(playerid, 288.000000, 194.000000, "_"); // 4
	PlayerTextDrawFont(playerid, Blackjack[playerid][29], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][29], 0.133331, 1.700000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][29], 310.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][29], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][29], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][29], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][29], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][29], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][29], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][29], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][29], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][29], 0);

	Blackjack[playerid][30] = CreatePlayerTextDraw(playerid, 351.000000, 194.000000, "_"); // 5
	PlayerTextDrawFont(playerid, Blackjack[playerid][30], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][30], 0.133331, 1.700000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][30], 373.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][30], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][30], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][30], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][30], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][30], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][30], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][30], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][30], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][30], 0);

	Blackjack[playerid][31] = CreatePlayerTextDraw(playerid, 404.000000, 174.000000, "_"); // 6
	PlayerTextDrawFont(playerid, Blackjack[playerid][31], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][31], 0.133331, 1.700000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][31], 431.000000, -3.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][31], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][31], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][31], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][31], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][31], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][31], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][31], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][31], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][31], 0);

	Blackjack[playerid][32] = CreatePlayerTextDraw(playerid, 452.000000, 141.000000, "_"); // 7
	PlayerTextDrawFont(playerid, Blackjack[playerid][32], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][32], 0.133331, 1.700000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][32], 475.000000, 31.500000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][32], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][32], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][32], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][32], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][32], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][32], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][32], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][32], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][32], 0);

	Blackjack[playerid][33] = CreatePlayerTextDraw(playerid, 157.000000, 219.000000, "Frei"); // 1
	PlayerTextDrawFont(playerid, Blackjack[playerid][33], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][33], 0.133331, 1.250000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][33], 18.500000, 19.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][33], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][33], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][33], 2);
	PlayerTextDrawColor(playerid, Blackjack[playerid][33], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][33], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][33], 200);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][33], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][33], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][33], 1);

	Blackjack[playerid][34] = CreatePlayerTextDraw(playerid, 194.000000, 252.000000, "Frei"); // 2
	PlayerTextDrawFont(playerid, Blackjack[playerid][34], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][34], 0.133331, 1.250000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][34], 16.500000, 22.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][34], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][34], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][34], 2);
	PlayerTextDrawColor(playerid, Blackjack[playerid][34], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][34], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][34], 200);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][34], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][34], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][34], 1);

	Blackjack[playerid][35] = CreatePlayerTextDraw(playerid, 247.000000, 277.000000, "Frei"); // 3
	PlayerTextDrawFont(playerid, Blackjack[playerid][35], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][35], 0.133331, 1.250000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][35], 16.500000, 20.500000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][35], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][35], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][35], 2);
	PlayerTextDrawColor(playerid, Blackjack[playerid][35], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][35], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][35], 200);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][35], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][35], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][35], 1);

	Blackjack[playerid][36] = CreatePlayerTextDraw(playerid, 307.000000, 277.000000, "Frei"); // 4
	PlayerTextDrawFont(playerid, Blackjack[playerid][36], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][36], 0.133331, 1.250000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][36], 16.500000, 20.500000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][36], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][36], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][36], 2);
	PlayerTextDrawColor(playerid, Blackjack[playerid][36], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][36], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][36], 200);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][36], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][36], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][36], 1);

	Blackjack[playerid][37] = CreatePlayerTextDraw(playerid, 366.000000, 277.000000, "Frei"); // 5
	PlayerTextDrawFont(playerid, Blackjack[playerid][37], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][37], 0.133331, 1.250000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][37], 16.500000, 30.500000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][37], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][37], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][37], 2);
	PlayerTextDrawColor(playerid, Blackjack[playerid][37], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][37], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][37], 200);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][37], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][37], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][37], 1);

	Blackjack[playerid][38] = CreatePlayerTextDraw(playerid, 417.000000, 252.000000, "Frei"); // 6
	PlayerTextDrawFont(playerid, Blackjack[playerid][38], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][38], 0.133331, 1.250000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][38], 16.500000, 25.500000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][38], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][38], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][38], 2);
	PlayerTextDrawColor(playerid, Blackjack[playerid][38], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][38], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][38], 200);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][38], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][38], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][38], 1);

	Blackjack[playerid][39] = CreatePlayerTextDraw(playerid, 454.000000, 222.000000, "Frei"); // 7
	PlayerTextDrawFont(playerid, Blackjack[playerid][39], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][39], 0.133331, 1.250000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][39], 16.500000, 20.500000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][39], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][39], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][39], 2);
	PlayerTextDrawColor(playerid, Blackjack[playerid][39], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][39], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][39], 200);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][39], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][39], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][39], 1);

	Blackjack[playerid][40] = CreatePlayerTextDraw(playerid, 557.000000, 352.000000, "Einsatz");
	PlayerTextDrawFont(playerid, Blackjack[playerid][40], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][40], 0.349999, 1.500000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][40], 620.500000, 27.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][40], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][40], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][40], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][40], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][40], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][40], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][40], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][40], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][40], 1);

	Blackjack[playerid][41] = CreatePlayerTextDraw(playerid, 33.000000, 211.000000, "Karte");
	PlayerTextDrawFont(playerid, Blackjack[playerid][41], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][41], 0.349999, 1.500000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][41], 80.500000, 27.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][41], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][41], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][41], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][41], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][41], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][41], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][41], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][41], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][41], 1);

	Blackjack[playerid][42] = CreatePlayerTextDraw(playerid, 33.000000, 274.000000, "Stop");
	PlayerTextDrawFont(playerid, Blackjack[playerid][42], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][42], 0.349999, 1.500000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][42], 74.000000, 27.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][42], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][42], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][42], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][42], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][42], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][42], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][42], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][42], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][42], 1);

	Blackjack[playerid][43] = CreatePlayerTextDraw(playerid, 557.000000, 389.000000, "Beenden");
	PlayerTextDrawFont(playerid, Blackjack[playerid][43], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][43], 0.349999, 1.500000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][43], 625.500000, 27.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][43], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][43], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][43], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][43], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][43], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][43], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][43], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][43], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][43], 1);

	Blackjack[playerid][44] = CreatePlayerTextDraw(playerid, 33.000000, 242.000000, "Verdoppeln");
	PlayerTextDrawFont(playerid, Blackjack[playerid][44], 2);
	PlayerTextDrawLetterSize(playerid, Blackjack[playerid][44], 0.349999, 1.500000);
	PlayerTextDrawTextSize(playerid, Blackjack[playerid][44], 129.500000, 27.000000);
	PlayerTextDrawSetOutline(playerid, Blackjack[playerid][44], 1);
	PlayerTextDrawSetShadow(playerid, Blackjack[playerid][44], 0);
	PlayerTextDrawAlignment(playerid, Blackjack[playerid][44], 1);
	PlayerTextDrawColor(playerid, Blackjack[playerid][44], -1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack[playerid][44], 255);
	PlayerTextDrawBoxColor(playerid, Blackjack[playerid][44], 50);
	PlayerTextDrawUseBox(playerid, Blackjack[playerid][44], 0);
	PlayerTextDrawSetProportional(playerid, Blackjack[playerid][44], 1);
	PlayerTextDrawSetSelectable(playerid, Blackjack[playerid][44], 1);

    RemoveBuildingForPlayer(playerid, 1978, 1963.7109, 1025.6953, 992.5078, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1978, 1959.3984, 1025.6953, 992.5078, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1978, 1963.7109, 1010.1172, 992.5078, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1978, 1959.3984, 1010.1172, 992.5078, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 2188, 1962.3438, 1020.1797, 992.4688, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 1960.3672, 1020.1719, 992.4688, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 1962.3438, 1015.6641, 992.4688, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 1960.3672, 1015.6641, 992.4688, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 1895, 1943.2188, 986.5234, 992.8828, 1.0); // wheel_o_fortune
    RemoveBuildingForPlayer(playerid, 1895, 1940.6875, 989.1719, 992.8828, 1.0); // wheel_o_fortune
    RemoveBuildingForPlayer(playerid, 1895, 1938.0469, 986.6250, 992.8828, 1.0); // wheel_o_fortune
//
    RemoveBuildingForPlayer(playerid, 2785, 1941.8438, 1029.1328, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1940.5547, 1029.4766, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1941.0234, 1021.4141, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1939.6953, 1021.4141, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1941.0234, 1014.2266, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1939.6953, 1014.2188, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1942.1250, 1006.5703, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1940.8828, 1006.1094, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1968.7344, 1029.6641, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1967.4063, 1029.6563, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1968.7344, 1021.6875, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1967.4063, 1021.6875, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1968.7344, 1014.0000, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1967.4063, 1014.0000, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1968.7344, 1006.3438, 992.3125, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 1967.4063, 1006.3438, 992.3125, 1.0); // CJ_SLOT_BANK
 
    RemoveBuildingForPlayer(playerid, 2325, 1965.09, 1037.35, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1964.55, 1037.28, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1962.4, 1043.63, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1961.92, 1043.36, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1957.66, 1048.41, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1957.32, 1047.98, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1957.72, 987.195, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1957.45, 987.672, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1962.41, 991.875, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1961.96, 992.203, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1965.1, 998.305, 992.984, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 1964.57, 998.453, 992.984, 0.25); // kb_bandit_U
 
    RemoveBuildingForPlayer(playerid, 1978, 2230.5703, 1619.6563, 1006.2266, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1978, 2230.5703, 1614.5938, 1006.2266, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 2188, 2230.3750, 1606.2734, 1006.1563, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 2228.4922, 1604.4531, 1006.1563, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 2230.3750, 1602.7500, 1006.1563, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 2232.1875, 1604.4375, 1006.1563, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 1978, 2230.5703, 1594.7578, 1006.2266, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1978, 2230.5703, 1589.1875, 1006.2266, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1978, 2241.4453, 1619.6094, 1006.2266, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1978, 2241.4453, 1614.5547, 1006.2266, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 2188, 2241.3125, 1606.2734, 1006.1563, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 2239.4297, 1604.4531, 1006.1563, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 2241.3125, 1602.7500, 1006.1563, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 2243.1250, 1604.4375, 1006.1563, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 1978, 2242.3672, 1594.7578, 1006.2266, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1978, 2242.3672, 1589.1875, 1006.2266, 1.0); // roulette_tbl
    RemoveBuildingForPlayer(playerid, 1895, 2252.0313, 1584.4219, 1007.1094, 1.0); // wheel_o_fortune
    RemoveBuildingForPlayer(playerid, 1895, 2261.6328, 1584.4297, 1007.1094, 1.0); // wheel_o_fortune
    RemoveBuildingForPlayer(playerid, 1895, 2271.7266, 1584.4219, 1007.1094, 1.0); // wheel_o_fortune
//
    RemoveBuildingForPlayer(playerid, 2785, 2253.2344, 1596.4844, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2254.1797, 1596.4844, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2253.2344, 1589.7969, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2254.1563, 1589.7969, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2258.2578, 1596.4766, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2259.2188, 1596.4844, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2258.2578, 1589.7969, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2259.1875, 1589.7969, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2263.6563, 1596.4844, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2264.6250, 1596.4844, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2263.6563, 1589.7969, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2264.6094, 1589.7891, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2268.7188, 1596.4688, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2269.6719, 1596.4844, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2268.7188, 1589.7969, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2269.6563, 1589.7891, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2273.4609, 1596.4766, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2274.4063, 1596.4844, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2273.4609, 1589.7969, 1006.0156, 1.0); // CJ_SLOT_BANK
    RemoveBuildingForPlayer(playerid, 2785, 2274.4063, 1589.7891, 1006.0156, 1.0); // CJ_SLOT_BANK
 
    RemoveBuildingForPlayer(playerid, 2325, 2218.66, 1619.09, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2218.63, 1618.56, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2218.66, 1614.75, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2218.63, 1614.23, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2217.02, 1603.93, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2217.55, 1603.9, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2220.68, 1603.93, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2221.2, 1603.9, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2218.66, 1592.91, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2218.63, 1592.38, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2218.66, 1588.6, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2218.63, 1588.08, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2255.19, 1618.07, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2255.16, 1617.55, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2255.19, 1614.17, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2255.16, 1613.65, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2255.19, 1610.12, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2255.16, 1609.6, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2269.25, 1606.68, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2269.77, 1606.65, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2273.3, 1606.68, 1006.77, 0.25); // kb_bandit_U
    RemoveBuildingForPlayer(playerid, 2325, 2273.82, 1606.65, 1006.77, 0.25); // kb_bandit_U
 
    RemoveBuildingForPlayer(playerid, 2188, 1125.1406, -3.4141, 1000.5781, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 1127.0781, -1.6797, 1000.5781, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 2188, 1125.1484, -0.0313, 1000.5781, 1.0); // blck_jack
    RemoveBuildingForPlayer(playerid, 1895, 1117.2813, -1.6484, 1002.0781, 1.0); // wheel_o_fortune
//
    RemoveBuildingForPlayer(playerid, 2640, 1135.0469, -3.0781, 1000.5234, 1.0); // NEIL_SLOT
    RemoveBuildingForPlayer(playerid, 2640, 1133.6875, -1.6250, 1000.5234, 1.0); // NEIL_SLOT
    RemoveBuildingForPlayer(playerid, 2640, 1135.0000, -0.1797, 1000.5234, 1.0); // NEIL_SLOT
    RemoveBuildingForPlayer(playerid, 2640, 1127.8828, 3.7969, 1000.5234, 1.0); // NEIL_SLOT
    RemoveBuildingForPlayer(playerid, 2640, 1126.8828, 3.7969, 1000.5234, 1.0); // NEIL_SLOT
    RemoveBuildingForPlayer(playerid, 2640, 1125.8672, 3.7969, 1000.5234, 1.0); // NEIL_SLOT
    RemoveBuildingForPlayer(playerid, 2640, 1124.8203, 3.7969, 1000.5234, 1.0); // NEIL_SLOT
	return 1;
}


hook OnPlayerDisconnect(playerid, reason)
{
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][0]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][1]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][2]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][3]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][4]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][5]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][6]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][7]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][8]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][9]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][10]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][11]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][12]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][13]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][14]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][15]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][16]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][17]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][18]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][19]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][20]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][21]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][22]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][23]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][24]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][25]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][26]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][27]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][28]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][29]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][30]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][31]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][32]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][33]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][34]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][35]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][36]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][37]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][38]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][39]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][40]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][41]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][42]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][43]);
	PlayerTextDrawDestroy(playerid, Blackjack[playerid][44]);
	return 1;
}


hook OnGameModeInit2()
{
	// Pickups
	pickup_casinoInterior[0] = CreateDynamicPickup(1239, 1, CASINO_INTERIOR_BUYDRINK_POINT, VW_CASINOINTERIOR, MAPS_CASINOINTERIOR_INTERIOR); // /Getraenk

    // 3DTextLabels
    text3D_casinoInterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Casino Bar\n" COLOR_HEX_WHITE "Tippe /Getraenk", COLOR_WHITE, CASINO_INTERIOR_BUYDRINK_POINT, 15.0, .testlos = 1);
    text3D_casinoInterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_ORANGE "Würfeltisch\n" COLOR_HEX_YELLOW "Tippe /Wuerfelspiel", COLOR_WHITE, CASINO_INTERIOR_DICE_POINT, 15.0, .testlos = 1);
    text3D_casinoInterior[2] = _:CreateDynamic3DTextLabel(COLOR_HEX_ORANGE "Kartentisch\n" COLOR_HEX_YELLOW "Tippe /Kartenspiel", COLOR_WHITE, CASINO_INTERIOR_CARDS_POINT, 15.0, .testlos = 1);
    text3D_casinoInterior[3] = _:CreateDynamic3DTextLabel(COLOR_HEX_ORANGE "Wett-Tisch\n" COLOR_HEX_YELLOW "Tippe /Gluecksrad", COLOR_WHITE, CASINO_INTERIOR_WHEEL_POINT, 15.0, .testlos = 1);
    text3D_casinoInterior[4] = _:CreateDynamic3DTextLabel(COLOR_HEX_ORANGE "Spielautomat\n" COLOR_HEX_YELLOW "Tippe /Spielautomat", COLOR_WHITE, CASINO_INTERIOR_SLOT1_POINT, 15.0, .testlos = 1);
    //text3D_casinoInterior[5] = _:CreateDynamic3DTextLabel(COLOR_HEX_ORANGE "Blackjack\n" COLOR_HEX_YELLOW "Tippe /Blackjack", COLOR_WHITE, CASINO_INTERIOR_BLACKJACK_POINT, 15.0, .testlos = 1);

    CreateDynamicObject(1978, 1963.7109, 1025.6953, 992.5078, 0.0, 0.0, 0.0, -1, 10, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1978, 1959.3984, 1025.6953, 992.5078, 0.0, 0.0, 0.0, -1, 10, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1978, 1963.7109, 1010.1172, 992.5078, 0.0, 0.0, 0.0, -1, 10, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1978, 1959.3984, 1010.1172, 992.5078, 0.0, 0.0, 0.0, -1, 10, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(2188, 1962.3438, 1020.1797, 992.4688, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 1960.3672, 1020.1719, 992.4688, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 1962.3438, 1015.6641, 992.4688, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 1960.3672, 1015.6641, 992.4688, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(1895, 1943.2188, 986.5234, 992.8828, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD); // wheel_o_fortune
    CreateDynamicObject(1895, 1940.6875, 989.1719, 992.8828, 0.0, 0.0, 180.0, -1, 10, -1, STREAMER_OBJECT_SD); // wheel_o_fortune
    CreateDynamicObject(1895, 1938.0469, 986.6250, 992.8828, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD); // wheel_o_fortune
//
    CreateDynamicObject(2785, 1941.8438, 1029.1328, 992.3125, 0.0, 0.0, 75.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1940.5547, 1029.4766, 992.3125, 0.0, 0.0, 255.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1941.0234, 1021.4141, 992.3125, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1939.6953, 1021.4141, 992.3125, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1941.0234, 1014.2266, 992.3125, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1939.6953, 1014.2188, 992.3125, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1942.1250, 1006.5703, 992.3125, 0.0, 0.0, 110.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1940.8828, 1006.1094, 992.3125, 0.0, 0.0, 290.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1968.7344, 1029.6641, 992.3125, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1967.4063, 1029.6563, 992.3125, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1968.7344, 1021.6875, 992.3125, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1967.4063, 1021.6875, 992.3125, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1968.7344, 1014.0000, 992.3125, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1967.4063, 1014.0000, 992.3125, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1968.7344, 1006.3438, 992.3125, 0.0, 0.0, 90.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 1967.4063, 1006.3438, 992.3125, 0.0, 0.0, 270.0, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
 
    CreateDynamicObject(2325, 1965.09, 1037.35, 992.984, 0.0, 0.0, 100.654, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1964.55, 1037.28, 992.984, 0.0, 0.0, 281.654, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1962.4, 1043.63, 992.984, 0.0, 0.0, 123.766, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1961.92, 1043.36, 992.984, 0.0, 0.0, 303.766, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1957.66, 1048.41, 992.984, 0.0, 0.0, 145.243, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1957.32, 1047.98, 992.984, 0.0, 0.0, 325.243, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1957.72, 987.195, 992.984, 0.0, 0.0, 33.7662, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1957.45, 987.672, 992.984, 0.0, 0.0, 213.7662, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1962.41, 991.875, 992.984, 0.0, 0.0, 55.2429, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1961.96, 992.203, 992.984, 0.0, 0.0, 235.2429, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1965.1, 998.305, 992.984, 0.0, 0.0, 79.1016, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 1964.57, 998.453, 992.984, 0.0, 0.0, 259.1016, -1, 10, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
 
    CreateDynamicObject(1978, 2230.5703, 1619.6563, 1006.2266, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1978, 2230.5703, 1614.5938, 1006.2266, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(2188, 2230.3750, 1606.2734, 1006.1563, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 2228.4922, 1604.4531, 1006.1563, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 2230.3750, 1602.7500, 1006.1563, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 2232.1875, 1604.4375, 1006.1563, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(1978, 2230.5703, 1594.7578, 1006.2266, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1978, 2230.5703, 1589.1875, 1006.2266, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1978, 2241.4453, 1619.6094, 1006.2266, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1978, 2241.4453, 1614.5547, 1006.2266, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(2188, 2241.3125, 1606.2734, 1006.1563, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 2239.4297, 1604.4531, 1006.1563, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 2241.3125, 1602.7500, 1006.1563, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 2243.1250, 1604.4375, 1006.1563, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(1978, 2242.3672, 1594.7578, 1006.2266, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1978, 2242.3672, 1589.1875, 1006.2266, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD); // roulette_tbl
    CreateDynamicObject(1895, 2252.0313, 1584.4219, 1007.1094, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD); // wheel_o_fortune
    CreateDynamicObject(1895, 2261.6328, 1584.4297, 1007.1094, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD); // wheel_o_fortune
    CreateDynamicObject(1895, 2271.7266, 1584.4219, 1007.1094, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD); // wheel_o_fortune
//
    CreateDynamicObject(2785, 2253.2344, 1596.4844, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2254.1797, 1596.4844, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2253.2344, 1589.7969, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2254.1563, 1589.7969, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2258.2578, 1596.4766, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2259.2188, 1596.4844, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2258.2578, 1589.7969, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2259.1875, 1589.7969, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2263.6563, 1596.4844, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2264.6250, 1596.4844, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2263.6563, 1589.7969, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2264.6094, 1589.7891, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2268.7188, 1596.4688, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2269.6719, 1596.4844, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2268.7188, 1589.7969, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2269.6563, 1589.7891, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2273.4609, 1596.4766, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2274.4063, 1596.4844, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2273.4609, 1589.7969, 1006.0156, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
    CreateDynamicObject(2785, 2274.4063, 1589.7891, 1006.0156, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // CJ_SLOT_BANK
 
    CreateDynamicObject(2325, 2218.66, 1619.09, 1006.77, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2218.63, 1618.56, 1006.77, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2218.66, 1614.75, 1006.77, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2218.63, 1614.23, 1006.77, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2217.02, 1603.93, 1006.77, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2217.55, 1603.9, 1006.77, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2220.68, 1603.93, 1006.77, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2221.2, 1603.9, 1006.77, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2218.66, 1592.91, 1006.77, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2218.63, 1592.38, 1006.77, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2218.66, 1588.6, 1006.77, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2218.63, 1588.08, 1006.77, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2255.19, 1618.07, 1006.77, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2255.16, 1617.55, 1006.77, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2255.19, 1614.17, 1006.77, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2255.16, 1613.65, 1006.77, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2255.19, 1610.12, 1006.77, 0.0, 0.0, 180.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2255.16, 1609.6, 1006.77, 0.0, 0.0, 0.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2269.25, 1606.68, 1006.77, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2269.77, 1606.65, 1006.77, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2273.3, 1606.68, 1006.77, 0.0, 0.0, 270.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
    CreateDynamicObject(2325, 2273.82, 1606.65, 1006.77, 0.0, 0.0, 90.0, -1, 1, -1, STREAMER_OBJECT_SD, 50.0); // kb_bandit_U
 
    CreateDynamicObject(2188, 1125.1406, -3.4141, 1000.5781, 0.0, 0.0, 0.0, -1, 12, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 1127.0781, -1.6797, 1000.5781, 0.0, 0.0, 90.0, -1, 12, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(2188, 1125.1484, -0.0313, 1000.5781, 0.0, 0.0, 180.0, -1, 12, -1, STREAMER_OBJECT_SD); // blck_jack
    CreateDynamicObject(1895, 1117.2813, -1.6484, 1002.0781, 0.0, 0.0, 90.0, -1, 12, -1, STREAMER_OBJECT_SD); // wheel_o_fortune
//
    CreateDynamicObject(2640, 1135.0469, -3.0781, 1000.5234, 0.0, 0.0, 0.0, -1, 12, -1, STREAMER_OBJECT_SD); // NEIL_SLOT
    CreateDynamicObject(2640, 1133.6875, -1.6250, 1000.5234, 0.0, 0.0, 270.0, -1, 12, -1, STREAMER_OBJECT_SD); // NEIL_SLOT
    CreateDynamicObject(2640, 1135.0000, -0.1797, 1000.5234, 0.0, 0.0, 180.0, -1, 12, -1, STREAMER_OBJECT_SD); // NEIL_SLOT
    CreateDynamicObject(2640, 1127.8828, 3.7969, 1000.5234, 0.0, 0.0, 0.0, -1, 12, -1, STREAMER_OBJECT_SD); // NEIL_SLOT
    CreateDynamicObject(2640, 1126.8828, 3.7969, 1000.5234, 0.0, 0.0, 0.0, -1, 12, -1, STREAMER_OBJECT_SD); // NEIL_SLOT
    CreateDynamicObject(2640, 1125.8672, 3.7969, 1000.5234, 0.0, 0.0, 0.0, -1, 12, -1, STREAMER_OBJECT_SD); // NEIL_SLOT
    CreateDynamicObject(2640, 1124.8203, 3.7969, 1000.5234, 0.0, 0.0, 0.0, -1, 12, -1, STREAMER_OBJECT_SD); // NEIL_SLOT
}


stock GetBlackjackSlot(playerid, &slot, &sitz) {
    if(BJPlayer[0][BJ_Player] == playerid) slot = 26, sitz = 33;
    if(BJPlayer[1][BJ_Player] == playerid) slot = 27, sitz = 34;
    if(BJPlayer[2][BJ_Player] == playerid) slot = 28, sitz = 35;
    if(BJPlayer[3][BJ_Player] == playerid) slot = 29, sitz = 36;
    if(BJPlayer[4][BJ_Player] == playerid) slot = 30, sitz = 37;
    if(BJPlayer[5][BJ_Player] == playerid) slot = 31, sitz = 38;
    if(BJPlayer[6][BJ_Player] == playerid) slot = 32, sitz = 39;
    return 1;
}