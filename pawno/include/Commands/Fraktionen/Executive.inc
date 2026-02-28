#include <YSI\y_hooks>



CMD:sp(playerid)
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 4 ||Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 16
        || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist oder Ordnungsbeamter.");
    if (Spieler[playerid][pRank] < 1) return SendClientMessage(playerid, COLOR_RED, "Dein Rang reicht dafür nicht aus.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(Spieler[playerid][pFraktion] == 4) return ShowPlayerDialog(playerid,DIALOG_RB,DIALOG_STYLE_LIST,"Straßensperren","Kleine Sperre\nSperre Entfernen","Wählen","Abbrechen");
    else return ShowPlayerDialog(playerid,DIALOG_RB,DIALOG_STYLE_LIST,"Straßensperren","Kleine Sperre\nGroße Sperre\nVerkehrskegel\nUmleitungsschild\nGelbe Barriere\nStraßensperre entfernen\nAlle Straßensperren entfernen\nNagelband platzieren\nNagelband entfernen\nAlle Nagelbänder entfernen","Wählen","Abbrechen");
}

CMD:nagelband(playerid) return cmd_sp(playerid);


CMD:vk(playerid) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if(Spieler[playerid][pDuty] == 0)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist.");
    new string[128];
    new ort[28];
    GetPlayer2DZone(playerid, ort, 28);
    new Rang[32];
    if(Spieler[playerid][pFraktion] == 1){Rang="LSPD-Officer";}
    else if(Spieler[playerid][pFraktion] == 2){Rang="Agent";}
    else if(Spieler[playerid][pFraktion] == 16){Rang="LVPD-Officer";}
    else if(Spieler[playerid][pFraktion] == 18){Rang="Soldat";}
    format(string, sizeof(string), "HQ: %s %s (ID: %d) benötigt dringend Verstärkung in %s, over.", Rang, GetName(playerid), playerid, ort);
    SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Nach 30 Sekunden verschwindet der Marker automatisch für alle Polizisten wieder.");
    SendFraktionMessage(1, COLOR_RED, string);
    SendFraktionMessage(2, COLOR_RED, string);
    SendFraktionMessage(16, COLOR_RED, string);
    SendFraktionMessage(18, COLOR_RED, string);
    SendFraktionMessage(22, COLOR_RED, string);
    PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    foreach(new i : Player) {
        if(Spieler[i][pFraktion] == 1 || Spieler[i][pFraktion] == 2 || Spieler[i][pFraktion] == 16 || Spieler[i][pFraktion] == 18) {
            if(Spieler[i][pDuty] == 0)continue;
            if(i != playerid) {
                KillTimer(pBackupTimer[i]);
                SetPlayerCheckpointEx(i, x, y, z, 5.0, CP_BACKUP);
                pBackupTimer[i] = SetTimerEx("RemoveBackupCP", 30000, 0, "i", i);
            }
        }
    }
    return 1;
}


CMD:rank(playerid) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(Spieler[playerid][pRank] == 0){//Rank 0
        SetPlayerAttachedObject(playerid, 8, 19783, 3, 0.116000, 0.015999, 0.047999, -17.899951, -2.000002, -88.100028, 0.474000, 0.547000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19783, 4, 0.094999, 0.000000, -0.046000, -0.300000, 1.700000, -86.499977, 0.513999, 0.571000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 1){//Rank 1
        SetPlayerAttachedObject(playerid, 8, 19784, 3, 0.116000, 0.015999, 0.047999, -17.899951, -2.000002, -88.100028, 0.474000, 0.547000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19784, 4, 0.094999, 0.000000, -0.046000, -0.300000, 1.700000, -86.499977, 0.513999, 0.571000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 2){//Rank 2
        SetPlayerAttachedObject(playerid, 8, 19781, 3, 0.116000, 0.015999, 0.047999, -17.899951, -2.000002, -88.100028, 0.474000, 0.547000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19781, 4, 0.094999, 0.000000, -0.046000, -0.300000, 1.700000, -86.499977, 0.513999, 0.571000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 3){//Rank 3
        SetPlayerAttachedObject(playerid, 8, 19779, 3, 0.116000, 0.015999, 0.047999, -17.899951, -2.000002, -88.100028, 0.474000, 0.547000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19779, 4, 0.094999, 0.000000, -0.046000, -0.300000, 1.700000, -86.499977, 0.513999, 0.571000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 4){//Rank 4
        SetPlayerAttachedObject(playerid, 8, 19782, 3, 0.116000, 0.015999, 0.047999, -17.899951, -2.000002, -88.100028, 0.474000, 0.547000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19782, 4, 0.094999, 0.000000, -0.046000, -0.300000, 1.700000, -86.499977, 0.513999, 0.571000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 5){//Rank 5
        SetPlayerAttachedObject(playerid, 8, 19780, 3, 0.116000, 0.015999, 0.047999, -17.899951, -2.000002, -88.100028, 0.474000, 0.547000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19780, 4, 0.094999, 0.000000, -0.046000, -0.300000, 1.700000, -86.499977, 0.513999, 0.571000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 6){//Rank 6
        SetPlayerAttachedObject(playerid, 8, 19780, 3, 0.116000, 0.015999, 0.047999, -17.899951, -2.000002, -88.100028, 0.474000, 0.547000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19780, 4, 0.094999, 0.000000, -0.046000, -0.300000, 1.700000, -86.499977, 0.513999, 0.571000, 1.000000, 0, 0); //Wappen RECHTS
    }
    return 1;
}

CMD:rankfrau(playerid){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(Spieler[playerid][pRank] == 0){//Rank 0
        SetPlayerAttachedObject(playerid, 8, 19783, 3, 0.115999, 0.015999, 0.045999, 172.000091, -3.700002, -93.900077, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19783, 4, 0.109000, 0.014999, -0.039000, 12.100017, -4.400001, -84.700019, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 1){//Rank 1
        SetPlayerAttachedObject(playerid, 8, 19784, 3, 0.115999, 0.015999, 0.045999, 172.000091, -3.700002, -93.900077, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19784, 4, 0.109000, 0.014999, -0.039000, 12.100017, -4.400001, -84.700019, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 2){//Rank 2
        SetPlayerAttachedObject(playerid, 8, 19781, 3, 0.115999, 0.015999, 0.045999, 172.000091, -3.700002, -93.900077, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19781, 4, 0.109000, 0.014999, -0.039000, 12.100017, -4.400001, -84.700019, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 3){//Rank 3
        SetPlayerAttachedObject(playerid, 8, 19779, 3, 0.115999, 0.015999, 0.045999, 172.000091, -3.700002, -93.900077, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19779, 4, 0.109000, 0.014999, -0.039000, 12.100017, -4.400001, -84.700019, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 4){//Rank 4
        SetPlayerAttachedObject(playerid, 8, 19782, 3, 0.115999, 0.015999, 0.045999, 172.000091, -3.700002, -93.900077, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19782, 4, 0.109000, 0.014999, -0.039000, 12.100017, -4.400001, -84.700019, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 5){//Rank 5
        SetPlayerAttachedObject(playerid, 8, 19780, 3, 0.115999, 0.015999, 0.045999, 172.000091, -3.700002, -93.900077, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19780, 4, 0.109000, 0.014999, -0.039000, 12.100017, -4.400001, -84.700019, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen RECHTS
    }
    if(Spieler[playerid][pRank] == 6){//Rank 6 
        SetPlayerAttachedObject(playerid, 8, 19780, 3, 0.115999, 0.015999, 0.045999, 172.000091, -3.700002, -93.900077, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen LINKS
        SetPlayerAttachedObject(playerid, 9, 19780, 4, 0.109000, 0.014999, -0.039000, 12.100017, -4.400001, -84.700019, 0.394000, 0.503000, 1.000000, 0, 0); //Wappen RECHTS
    }
    return 1;
}

CMD:dienst(playerid) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(HasWeaponBlock(playerid)) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst diesen Befehl nicht ausführen");
        return SendWeaponBlockInfo(playerid);
    }
    new string[128], frak = Spieler[playerid][pFraktion];
    if(Spieler[playerid][pDuty] == 1 || Spieler[playerid][pfDuty] == 1) {
        pUnderCover[playerid] = 0;
        Spieler[playerid][pDutyTask] = 0;
        Spieler[playerid][pDuty] = 0;
        Spieler[playerid][pfDuty] = 0;
        ResetPlayerWeapons(playerid);
        SetPlayerArmour(playerid, 0);
        SetPlayerSkin(playerid,Spieler[playerid][pSkin]);
        TextDrawHideForPlayer(playerid,g_Zentralmeldung[Z_tdVerfuegbar]);
        TextDrawHideForPlayer(playerid,g_Zentralmeldung[Z_tdNichtVerfuegbar]);
		SetPlayerColor(playerid, COLOR_WHITE);
        return 1;
    } else {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, LSPD_INTERIOR_DUTY_POINT)){//LSPD Duty
            if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Nur für LSPD/FBI verfügbar.");
			Spieler[playerid][pDuty] = 1;
            Spieler[playerid][pDutyTask] = 0;
            pUnderCover[playerid] = 0;
            format(string, sizeof(string), "* %s ist nun als %s Beamter im Dienst.", GetName(playerid), GetFactionName(frak));
            SendFraktionMessage(1, COLOR_YELLOW, string);
            SendFraktionMessage(2, COLOR_YELLOW, string);
            SendFraktionMessage(16, COLOR_YELLOW, string);
            SendFraktionMessage(18, COLOR_YELLOW, string);
            SendFraktionMessage(22, COLOR_YELLOW, string);
            GiveCopWeapons(playerid);
			SetPlayerColor(playerid, COLOR_BLUE);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, GOVERNMENT_INTERIOR_DUTY_POINT)){ //Staat Duty
            if(!(Spieler[playerid][pFraktion] == 9))return SendClientMessage(playerid, COLOR_RED, "Du gehörst nicht dem Staat an!");
            if(Spieler[playerid][pRank] == 0){//Praktikant
                GivePlayerWeapon(playerid, 41, 2000);
                GivePlayerWeapon(playerid, 24, 500);
                SetPlayerHealth(playerid, 100);
                SetPlayerArmour(playerid, 50);
                Spieler[playerid][pDuty] = 1;
            }
            else if(Spieler[playerid][pRank] == 1){// Bodyguard
                GivePlayerWeapon(playerid, 5, 1);
                SetPlayerHealth(playerid, 100);
                SetPlayerArmour(playerid, 50);
                Spieler[playerid][pDuty] = 1;
            }
            else if(Spieler[playerid][pRank] == 2){//SC
                GivePlayerWeapon(playerid, 41, 2000);
                GivePlayerWeapon(playerid, 24, 500);
                SetPlayerArmour(playerid, 100);
                SetPlayerHealth(playerid, 100);
                Spieler[playerid][pDuty] = 1;
            }
            else if(Spieler[playerid][pRank] == 3){//SCCHIEF
                GivePlayerWeapon(playerid, 41, 2000);
                GivePlayerWeapon(playerid, 24, 500);
                SetPlayerArmour(playerid, 100);
                SetPlayerHealth(playerid, 100);
                Spieler[playerid][pDuty] = 1;
            }
            else if(Spieler[playerid][pRank] == 4){//Bürgermeister
                SetPlayerHealth(playerid, 100);
                SetPlayerArmour(playerid, 100);
                GivePlayerWeapon(playerid, 41, 2000);
                GivePlayerWeapon(playerid, 24, 200);
                Spieler[playerid][pDuty] = 1;
            }
            else if(Spieler[playerid][pRank] == 5){//Minister
                GivePlayerWeapon(playerid, 41, 2000);
                GivePlayerWeapon(playerid, 24, 500);
                SetPlayerArmour(playerid, 100);
                SetPlayerHealth(playerid, 100);
                Spieler[playerid][pDuty] = 1;
            }
            else if(Spieler[playerid][pRank] == 6) {//Präsident
                GivePlayerWeapon(playerid, 41, 2000);
                GivePlayerWeapon(playerid, 24, 500);
                SetPlayerArmour(playerid, 100);
                SetPlayerHealth(playerid, 100);
                Spieler[playerid][pDuty] = 1;
            }
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, FBI_INTERIOR_DUTY_POINT)){//FBI Duty
            if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16))return SendClientMessage(playerid, COLOR_RED, "Nur für LSPD/FBI verfügbar.");
            Spieler[playerid][pDuty] = 1;
            pUnderCover[playerid] = 0;
            format(string, sizeof(string), "* %s ist nun als %s Beamter im Dienst.", GetName(playerid), GetFactionName(frak));
            SendFraktionMessage(1, COLOR_YELLOW, string);
            SendFraktionMessage(2, COLOR_YELLOW, string);
            SendFraktionMessage(16, COLOR_YELLOW, string);
            SendFraktionMessage(18, COLOR_YELLOW, string);
            SendFraktionMessage(22, COLOR_YELLOW, string);
            GiveCopWeapons(playerid);
			SetPlayerColor(playerid, COLOR_DARKBLUE);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 2279.9548,2423.4844,3.4766)) {//LVPD Duty
            if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16))return SendClientMessage(playerid, COLOR_RED, "Nur für LSPD/FBI verfügbar.");
            Spieler[playerid][pDuty] = 1;
            pUnderCover[playerid] = 0;
            format(string, sizeof(string), "* %s ist nun als %s Beamter im Dienst.", GetName(playerid), GetFactionName(frak));
            SendFraktionMessage(1, COLOR_YELLOW, string);
            SendFraktionMessage(2, COLOR_YELLOW, string);
            SendFraktionMessage(16, COLOR_YELLOW, string);
            SendFraktionMessage(18, COLOR_YELLOW, string);
            SendFraktionMessage(22, COLOR_YELLOW, string);
            GiveCopWeapons(playerid);
			SetPlayerColor(playerid, COLOR_BLUE);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 309.2354,-135.8690,999.6016)) {//Army Duty
            if(!(Spieler[playerid][pFraktion] == 18))return SendClientMessage(playerid, COLOR_RED, "Nur für Army verfügbar.");
            Spieler[playerid][pDuty] = 1;
            pUnderCover[playerid] = 0;
            format(string, sizeof(string), "* %s ist nun als Army-Soldat im Dienst.", GetName(playerid));
            SendFraktionMessage(1, COLOR_YELLOW, string);
            SendFraktionMessage(2, COLOR_YELLOW, string);
            SendFraktionMessage(16, COLOR_YELLOW, string);
            SendFraktionMessage(18, COLOR_YELLOW, string);
            SendFraktionMessage(22, COLOR_YELLOW, string);
            GiveArmyWeapons(playerid);
			SetPlayerColor(playerid, COLOR_BLUE);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 326.7928,307.7375,999.1484)) {//Zollamt Duty
            if(!(Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Nur für Zollbeamte verfügbar.");
            Spieler[playerid][pDuty] = 1;
            pUnderCover[playerid] = 0;
            format(string, sizeof(string), "* %s ist nun als Zollbeamter im Dienst.", GetName(playerid));
            SendFraktionMessage(1, COLOR_YELLOW, string);
            SendFraktionMessage(2, COLOR_YELLOW, string);
            SendFraktionMessage(16, COLOR_YELLOW, string);
            SendFraktionMessage(18, COLOR_YELLOW, string);
            SendFraktionMessage(22, COLOR_YELLOW, string);
            GiveCopWeapons(playerid);
			SetPlayerColor(playerid, COLOR_BLUE);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, SANABASE_DUTY_POINT)) {//News Duty
            if(!(Spieler[playerid][pFraktion] == 4))return SendClientMessage(playerid, COLOR_RED, "Nur für SA-NA verfügbar.");
            GiveNewsWeapons(playerid);
            Spieler[playerid][pfDuty] = 1;
            format(string, sizeof(string), "* %s ist nun als News Reporter im Dienst.", GetName(playerid));
            SendFraktionMessage(4, COLOR_YELLOW, string);
            GivePlayerWeapon(playerid, 43, 100);
			SetPlayerColor(playerid, COLOR_ORANGE);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, POO_INTERIOR_DUTY_POINT)) { //O-Amt
            if (Spieler[playerid][pFraktion] != 5) return SendClientMessage(playerid, COLOR_RED, "Nur für Ordnungsamt verfügbar.");
            Spieler[playerid][pDuty] = 1;
            GiveOAmtWeapons(playerid);
            format(string, sizeof(string), "* %s ist nun als Ordnungsbeamter im Dienst.", GetName(playerid));
            SendFraktionMessage(5, COLOR_YELLOW, string);
			SetPlayerColor(playerid, COLOR_TURKIS);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, SAMD_INTERIOR_DUTY_POINT)) {//Sanitäter
            if (Spieler[playerid][pFraktion] != 3) return SendClientMessage(playerid, COLOR_RED, "Nur für Sanitäter verfügbar.");
            Spieler[playerid][pDuty] = 1;
            GiveSaniWeapons(playerid);
            format(string, sizeof(string), "* %s ist nun als Sanitäter im Dienst.", GetName(playerid));
            SendFraktionMessage(3, COLOR_YELLOW, string);
			SetPlayerColor(playerid, COLOR_DARKRED);
        }
    }
    return 1;
}


CMD:ticket(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, grund[64], preis, string[256];
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied oder Ordnungsbeamter.");
    if(sscanf(params, "uis[64]", pID, preis, grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Ticket [SpielerID/Name] [Preis] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(preis < 1 || preis > 500000)return SendClientMessage(playerid, COLOR_RED, "Der Preis sollte zwischen 1 und 500.000$ liegen.");
    if(IsPlayerInRangeOfPoint(pID, 10.0, x,y,z))
    {
        format(string, sizeof(string), "Du hast %s eine Geldstrafe in Höhe von $%s gegeben. Grund: %s", GetName(pID), AddDelimiters(preis), grund);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        ZettelID[pID] = playerid;
        ZettelPreis[pID] = preis;
        format(string, sizeof(string), COLOR_HEX_BLUE"Von: "COLOR_HEX_WHITE"%s\n"COLOR_HEX_BLUE"Preis: "COLOR_HEX_WHITE"$%s\n"COLOR_HEX_BLUE"Grund: "COLOR_HEX_WHITE"%s\nNehme diese Geldstrafe an, indem du auf \"Annehmen\" klickst.", GetName(playerid), AddDelimiters(preis), grund);
        ShowPlayerDialog(pID, DIALOG_SZETTEL, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"AMTLICHE GELDSTRAFE", string, "Annehmen", "Abbrechen");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Umgebung.");
        return 1;
    }
    return 1;
}


CMD:marke(playerid,params[]) return cmd_dienstmarke(playerid,params);

CMD:dienstmarke(playerid, params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
	new pID,fname[50],frakid = Spieler[playerid][pFraktion];
	if(!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
	if(!IsPlayerExecutive(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Staatsbeamter!");
	if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Dienstmarke [SpielerID/Name]");
	if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
	if(!IsPlayerInRangeOfPlayer(playerid, pID, 5.0))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Umgebung.");
	ExekutiveDMID(frakid, fname); // <== Only for /Dienstmarke
	SendClientMessage(pID, COLOR_YELLOW, "===========================================");
    SCMFormatted(pID, COLOR_BLUE, "Offizielle Dienstmarke %s",fname);
    SCMFormatted(pID, COLOR_BLUE, "Besitzer: {FFFFFF}%s %s",GetRankName(Spieler[playerid][pFraktion], Spieler[playerid][pRank]),GetName(playerid));
    SendClientMessage(pID, COLOR_YELLOW, "===========================================");
	return 1;
}

stock ExekutiveDMID(frakid, frak[50]) {
	if(frakid == 0)frak ="Zivilist";
	else if(frakid == 1)frak ="vom Los Santos Police Department";
	else if(frakid == 2)frak ="vom FBI";
	else if(frakid == 5)frak ="vom Ordnungsamt";
	else if(frakid == 9)frak ="der Regierung";
	else if(frakid == 16)frak ="vom Las Venturas Police Department";
	else if(frakid == 18)frak ="der Bundeswehr";
	return frak;
}


CMD:pmsg(playerid, params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
	new text[256], string[256], frak = Spieler[playerid][pFraktion];
	if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    if(Spieler[playerid][pRank] < 5)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist kein Leader.");
    if(sscanf(params, "s[96]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Pmsg [Nachricht]");
    if (Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 22) {
		format(string,sizeof(string), COLOR_HEX_ORANGE"[%s] %s %s: {FFFFFF}%s", GetFactionName(frak), GetRankName(Spieler[playerid][pFraktion], Spieler[playerid][pRank]), GetName(playerid), text);
	    SendClientMessageToAll(COLOR_WHITE, string);
    } else {
        return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Du bist kein Beamter.");
    }
	return 1;
}


CMD:uclight(playerid) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22) {
        new vID = GetPlayerVehicleID(playerid);
        new model = GetVehicleModel(vID);
        if(model == 426 || model == 560 || model == 445) {
            if(vSirene[vID] == INVALID_OBJECT_ID) {
                vSirene[vID] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                AttachDynamicObjectToVehicle(vSirene[vID],vID,0.499999, 0.799999, 0.400000, 0.000000, 0.000000, 0.000000);
            } else {
                DestroyDynamicObject(vSirene[vID]);
                vSirene[vID] = INVALID_OBJECT_ID;
            }
        } else {
            SendClientMessage(playerid, COLOR_RED, "Dazu musst du in einem Sultan sitzen.");
        }
    }
    return 1;
}


CMD:undercover(playerid) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if (pUnderCover[playerid] == 1) {
        SendClientMessage(playerid, COLOR_YELLOW, "* Du bist nun nicht mehr im Undercover Modus.");
        ResetPlayerWeapons(playerid);
        pUnderCover[playerid] = 0;
        Spieler[playerid][pDuty] = 0;
        Spieler[playerid][pDutyTask] = 0;
        SetPlayerSkin(playerid, Spieler[playerid][pSkin]);
        return 1;
    } else {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, 244.3387,192.4503,1008.1719) || IsPlayerInRangeOfPoint(playerid, 2.0, LSPD_INTERIOR_DUTY_POINT)) {
            if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16)) return SendClientMessage(playerid, COLOR_RED, "Nur für LSPD/FBI verfügbar!");
            if (GetOnlineExekutive(playerid) < 2) return SendClientMessage(playerid, COLOR_RED, "Es sind nicht genug Polizisten online!");
            pUnderCover[playerid] = 1;
            Spieler[playerid][pDuty] = 1;
            Spieler[playerid][pDutyTask] = 0;
            GivePlayerWeapon(playerid, 31, 200);
            GivePlayerWeapon(playerid, 24, 80);
            SetPlayerArmour(playerid, 100);
            SetPlayerHealth(playerid, 100);
            if (Spieler[playerid][pSex] == 1) SetPlayerSkin(playerid, 2);
            else if (Spieler[playerid][pSex] == 2) SetPlayerSkin(playerid, 2);
            SendClientMessage(playerid, COLOR_YELLOW, "* Du bist nun im Under-Cover Modus.");
        }
    }
    return 1;
}


CMD:durchsuchen(playerid, params[])
{
    new pID, string[1024];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Durchsuche [SpielerID/Name]");
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Beamter.");
    if(IsAFK[pID]) return SCMFormatted(playerid,COLOR_RED,"%s ist im AFK-Modus",GetName(pID));
    if(Spieler[pID][pAdminDienst] == 1) return SCMFormatted(playerid,COLOR_RED,"%s ist im Admindienst.",GetName(pID));
    SetPVarInt(playerid, "DURCHSUCHENID", pID);
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    if(IsPlayerInRangeOfPoint(playerid, 7.0, x,y,z)){
        new weapons[13][2];
        new wpName1[32], wpName2[32], wpName3[32], wpName4[32], wpName5[32], wpName6[32], wpName7[32];
        new wpName8[32], wpName9[32], wpName10[32], wpName11[32], wpName12[32], wpName13[32];
        for(new i=0;i<13;i++){
            GetPlayerWeaponData(pID, i, weapons[i][0], weapons[i][1]);
        }
        GetWeaponNameEx(weapons[0][0], wpName1, 32);
        GetWeaponNameEx(weapons[1][0], wpName2, 32);
        GetWeaponNameEx(weapons[2][0], wpName3, 32);
        GetWeaponNameEx(weapons[3][0], wpName4, 32);
        GetWeaponNameEx(weapons[4][0], wpName5, 32);
        GetWeaponNameEx(weapons[5][0], wpName6, 32);
        GetWeaponNameEx(weapons[6][0], wpName7, 32);
        GetWeaponNameEx(weapons[7][0], wpName8, 32);
        GetWeaponNameEx(weapons[8][0], wpName9, 32);
        GetWeaponNameEx(weapons[9][0], wpName10, 32);
        GetWeaponNameEx(weapons[10][0], wpName11, 32);
        GetWeaponNameEx(weapons[11][0], wpName12, 32);
        GetWeaponNameEx(weapons[12][0], wpName13, 32);
        //Dialog erstellen
        new /*string[256], */ueberschrift[128];
        format(string, sizeof(string), "%sDrogen: %i", string, Spieler[pID][pDrugs]);
        format(string, sizeof(string), "%s\nSpice: %i", string, Spieler[pID][pSpice]);
        format(string, sizeof(string), "%s\nSpicesamen: %i", string, Spieler[pID][pDrogenSamen]);
        //format(string, sizeof(string), "%s\nKräutermischung: %i", string, Spieler[pID][pKrauterMische]);
        format(string, sizeof(string), "%s\nDrogensamen: %i", string, Spieler[pID][pGangDrogenSamen]);
        format(string, sizeof(string), "%s\nWaffenteile: %i", string, Spieler[pID][pWaffenteile]);
        format(string, sizeof(string), "%s\nWanted-Codes: %i", string, Spieler[pID][pWantedCodes]);
        format(string, sizeof(string), "%s\nBrecheisen: %i", string, Spieler[pID][pBrecheisen]);
        format(string, sizeof(string), "%s\nC4: %i", string, Spieler[pID][pC4]);
        format(string, sizeof(string), "%s\nSchaufel: %i", string, Spieler[pID][pSchaufel]);
        //Waffen anzeigen
        format(string, sizeof(string), "%s\nWaffen-Slot 1: %s [%d]", string, wpName1, weapons[0][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 2: %s [%d]", string, wpName2, weapons[1][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 3: %s [%d]", string, wpName3, weapons[2][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 4: %s [%d]", string, wpName4, weapons[3][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 5: %s [%d]", string, wpName5, weapons[4][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 6: %s [%d]", string, wpName6, weapons[5][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 7: %s [%d]", string, wpName7, weapons[6][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 8: %s [%d]", string, wpName8, weapons[7][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 9: %s [%d]", string, wpName9, weapons[8][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 10: %s [%d]", string, wpName10, weapons[9][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 11: %s [%d]", string, wpName11, weapons[10][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 12: %s [%d]", string, wpName12, weapons[11][1]);
        format(string, sizeof(string), "%s\nWaffen-Slot 13: %s [%d]", string, wpName13, weapons[12][1]);
        format(ueberschrift, sizeof(ueberschrift), "Durchsuchung von: %s", GetName(pID));
        ShowPlayerDialog(playerid, DIALOG_DURCHSUCHEN, DIALOG_STYLE_LIST, ueberschrift, string, "OK", "");
        format(string, sizeof(string), "* Beamter %s hat %s nach Gegenständen durchsucht.", GetName(playerid), GetName(pID));
        SendRoundMessage(x, y, z, COLOR_PURPLE, string);
    }else{
        SendClientMessage(playerid, COLOR_RED, "[DURCHSUCHEN] {FFFFFF}Du bist nicht in der Nähe des Spielers.");
    }
    return 1;
}


CMD:acceptcop(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Acceptcop [SpielerID/Name]");
    if( !(( Spieler[playerid][pFraktion] == 1) || ( Spieler[playerid][pFraktion] == 2) || ( Spieler[playerid][pFraktion] == 16)) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Beamter!");
    }
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
    if(GetPlayerInterior(pID) > 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem Gebäude.");
    if(NeedCop[pID] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler benötigt keinen Polizist. Verwende /sliste um den Notruf Computer einzuschalten.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    SetPlayerCheckpointEx(playerid, x,y,z, 5.0, CP_ACCEPTCOP);
    format(string, sizeof(string), "Ein Streifenwagen hat dein Notruf übernommen. Die Polizei ist unterwegs zu dir!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "HQ: Polizist %s hat den Notruf von %s (ID: %d) angenommen.", GetName(playerid), GetName(pID), pID);
    SendFraktionMessage(1, COLOR_COP_MELDUNG, string);
    NeedCop[pID] = 0;
    return 1;
}


CMD:scheinentziehen(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, schein[32], string[128];
    if(sscanf(params, "us[32]", pID, schein))
    {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Scheinentziehen [SpielerID/Name] [Schein]");
        SendClientMessage(playerid, COLOR_ORANGE, "* Scheine *: Fahrschein, Motorradschein, Flugschein, Bootsschein, Awaffenschein, Bwaffenschein");
        SendClientMessage(playerid, COLOR_ORANGE, "* Scheine *: Lkwschein, Angelschein");
        return 1;
    }
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Beamter.");
    if(Spieler[pID][pFraktion] == 1 || Spieler[pID][pFraktion] == 2 || Spieler[pID][pFraktion] == 5 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22 )return SendClientMessage(playerid, COLOR_RED, "Du kannst anderen Beamten keine Scheine entziehen.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(strcmp(schein, "fahrschein", true) == 0)
    {
        if(Spieler[pID][pCarLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen Führerschein!");
        format(string, sizeof(string), "* Dein Führerschein wurde vom Beamten %s abgenommen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast den Führerschein von %s abgenommen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pCarLic] = 0;
    }
    else if(strcmp(schein, "angelschein", true) == 0)
    {
        if(Spieler[pID][pFishLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen Angelschein.");
        format(string, sizeof(string), "* Dein Angelschein wurde vom Beamten %s abgenommen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast den Angelschein von %s abgenommen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pFishLic] = 0;
    }
    else if(strcmp(schein, "motorradschein", true) == 0)
    {
        if(Spieler[pID][pMotoLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen Motorradschein!");
        format(string, sizeof(string), "* Dein Motorradschein wurde vom Beamten %s abgenommen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast den Motorradschein von %s abgenommen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pMotoLic] = 0;
    }
    else if(strcmp(schein, "flugschein", true) == 0)
    {
        if(Spieler[pID][pFlyLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen Flugschein!");
        format(string, sizeof(string), "* Dein Flugschein wurde vom Beamten %s abgenommen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast den Flugschein von %s abgenommen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pFlyLic] = 0;
    }
    else if(strcmp(schein, "bootsschein", true) == 0)
    {
        if(Spieler[pID][pBoatLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen Bootsschein!");
        format(string, sizeof(string), "* Dein Bootsschein wurde vom Beamten %s abgenommen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast den Bootsschein von %s abgenommen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pBoatLic] = 0;
    }
    else if(strcmp(schein, "awaffenschein", true) == 0)
    {
        if(Spieler[pID][pGunLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen Waffenschein Klasse A!");
        format(string, sizeof(string), "* Dein Waffenschein Klasse A wurde vom Beamten %s abgenommen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast den Waffenschein Klasse A von %s abgenommen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pGunLic] = 0;
    }
    else if(strcmp(schein, "bwaffenschein", true) == 0)
    {
        if(Spieler[pID][pGunLicB] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen Waffenschein Klasse B!");
        format(string, sizeof(string), "* Dein Waffenschein Klasse B wurde vom Beamten %s abgenommen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast den Waffenschein Klasse B von %s abgenommen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pGunLic] = 0;
    }
    else if(strcmp(schein, "lkwschein", true) == 0)
    {
        if(Spieler[pID][pLKWLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen LKW-Schein!");
        format(string, sizeof(string), "* Dein LKW-Schein wurde vom Beamten %s abgenommen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTBLUE, string);
        format(string, sizeof(string), "* Du hast den LKW-Schein von %s abgenommen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        Spieler[pID][pLKWLic] = 0;
    }
    return 1;
}


CMD:pakte(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid, job[50], String[128];
    if( Spieler[playerid][pFraktion] != 5 && Spieler[playerid][pFraktion] != 1 && Spieler[playerid][pFraktion] != 2 && Spieler[playerid][pFraktion] != 16 && Spieler[playerid][pFraktion] != 18 || Spieler[playerid][pFraktion] == 22) return SendClientMessage(playerid,COLOR_RED,"Du bist kein Polizist oder Ordnungsbeamter");
    if(sscanf(params, "u", giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Pakte [Spieler]");
    if( !IsPlayerConnected(giveid) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( playerid == giveid ) return SendClientMessage(playerid, COLOR_RED, "Du kannst deine eigene Polizei-Akte nicht einsehen.");
    SendClientMessage(playerid,COLOR_RED,"=========POLIZEI-COMPUTER=========");
    format(String,sizeof(String),"Polizeiakte von: "#COLOR_HEX_ORANGE"%s",GetName(giveid));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Begangene Verbrechen: "#COLOR_HEX_ORANGE"%d",Spieler[giveid][pCrimes]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Begangene Morde: "#COLOR_HEX_ORANGE"%d",Spieler[giveid][pKills]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Wantedanzahl: "#COLOR_HEX_ORANGE"%d",Spieler[giveid][pWanteds]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    ReturnPlayerJob(giveid,job);
    format(String,sizeof(String),"Beruf: %s",job);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Staatsbürger: %s", Spieler[giveid][pStaat] );
    SendClientMessage(playerid,COLOR_WHITE,String);
    return 1;
}


CMD:fskin(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    #pragma unused params
    new frak = Spieler[playerid][pFraktion];

    if(frak) {
        for(new i; i < MAX_FACTIONS; i++) {
            if(frak == g_fraktion[i][Fr_FrakID])
            {
                if(g_fraktion[i][Fr_HasSkin])
                {
                    if(IsPlayerInRangeOfPoint(playerid, 5.0, g_fraktion[i][Fr_FSkinX], g_fraktion[i][Fr_FSkinY], g_fraktion[i][Fr_FSkinZ])) 
                    {
                        new dialogstr[2056];
                        if(Spieler[playerid][pFraktion] == 1){
                            for (new e = 0, j = sizeof(skins_pd_array); e < j; e++) {
                                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_pd_array[e]);
                            }
                        }else if(Spieler[playerid][pFraktion] == 2){
                            for (new e = 0, j = sizeof(skins_fbi_array); e < j; e++) {
                                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_fbi_array[e]);
                            }
                        }else if(Spieler[playerid][pFraktion] == 3){
                            for (new e = 0, j = sizeof(skins_samd_array); e < j; e++) {
                                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_samd_array[e]);
                            }
                        }
						else if(Spieler[playerid][pFraktion] == 4){
                            for (new e = 0, j = sizeof(skins_news_array); e < j; e++) {
                                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_news_array[e]);
                            }
                        }else if(Spieler[playerid][pFraktion] == 5){
                            for (new e = 0, j = sizeof(skins_oamt_array); e < j; e++) {
                                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_oamt_array[e]);
                            }
                        }else if(Spieler[playerid][pFraktion] == 14){
                            for (new e = 0, j = sizeof(skins_array); e < j; e++) {
                                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[e]);
                            }
                        }else if(Spieler[playerid][pFraktion] == 22){
                            for (new e = 0, j = sizeof(skins_zollamt_array); e < j; e++) {
                                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_zollamt_array[e]);
                            }
                        }else{
                            for (new e = 0, j = sizeof(skins_array); e < j; e++) {
                                format(dialogstr, sizeof(dialogstr), "%s%d\n\n", dialogstr, skins_array[e]);
                            }
                        }
                        ShowPlayerDialog(playerid, DIALOG_SKINS, DIALOG_STYLE_PREVMODEL, "Fraktionsskin", dialogstr, "Ok", "Abbrechen");
                    }
                    else
                        SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst hier nicht deinen Fraktionsskin wechseln.");

                    break;
                }
            }
        }
    }
    return 1;
}


CMD:knastzeit(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid, modus, zeit;
    if(sscanf(params,"ucd",giveid,modus,zeit)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Knastzeit [Spieler] [+/-] [Sekunden]");
    if(zeit <= 0 ) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Knastzeit [Spieler] [+/-] [Sekunden]");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22) )return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( !IsPlayerConnected(giveid) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( playerid == giveid ) return SendClientMessage(playerid, COLOR_RED, "Du kannst deine Knastzeit nicht selber setzen.");
    if(Spieler[giveid][pJailed] == 0 || Spieler[giveid][pJailed] == 3) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht im Gefängnis.");
    if(modus == '+') Spieler[giveid][pJailTime] += zeit;
    else if(modus == '-') Spieler[giveid][pJailTime] -= zeit;
    else return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Knastzeit [Spieler] [+/-] [Sekunden]");
    new String[128];
    format(String,sizeof(String),"Polizeibeamter %s hat die Knastzeit von %s %c %d gesetzt ( Total: %d)",GetName(playerid),GetName(giveid),modus,zeit,Spieler[giveid][pJailTime]);
    SendFraktionMessage(1, COLOR_BLUE, String);
    SendFraktionMessage(2, COLOR_BLUE, String);
    SendFraktionMessage(16, COLOR_BLUE, String);
    SendFraktionMessage(18, COLOR_BLUE, String);
    SendFraktionMessage(22, COLOR_BLUE, String);
    format(String,sizeof(String),"Polizeibeamter %s hat deine Knastzeit auf %c %d gesetzt ( Total: %d)",GetName(playerid),modus,zeit,Spieler[giveid][pJailTime]);
    SendClientMessage(giveid,COLOR_ORANGE,String);
    return 1;
}


CMD:swat(playerid) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if(Spieler[playerid][pRank] < 1) return SendClientMessage(playerid, COLOR_RED, "Dein Rang reicht dafür nicht aus!");
    new poolSize = GetPlayerPoolSize();
    Spieler[playerid][abMaske] = !Spieler[playerid][abMaske];
    if (!Spieler[playerid][abMaske]) {
        SetPlayerColor(playerid, GetPlayerColor(playerid) | 0xFF);
        for (new i; i <= poolSize; i++) ShowPlayerNameTagForPlayer(i, playerid, 1);
        return SendClientMessage(playerid, COLOR_ORANGE, "Du hast deine SWAT-Maske abgenommen.");
    }

    SendClientMessage(playerid, COLOR_GREEN, "Du hast deine SWAT-Maske aufgezogen.");
    SetPlayerColor(playerid, GetPlayerColor(playerid) & 0xFFFFFF00);
    for (new i; i < MAX_PLAYERS; i++)  ShowPlayerNameTagForPlayer(i, playerid, 0);
    return 1;
}


CMD:pswat(playerid)
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,0) ) 
    {
        RemovePlayerAttachedObject(playerid,0);
        SendClientMessage(playerid,COLOR_YELLOW,"SWAT-Weste entfernt");
    }
    else {
        SetPlayerAttachedObject(playerid,0,19142,1,0.000000,0.044999,0.013000,0.000000,0.000000,0.000000,1.288999,1.148000,1.252999);
        SendClientMessage(playerid,COLOR_YELLOW,"SWAT-Weste angezogen.");
    }
    return 1;
}


CMD:phelm(playerid)
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,1) ) 
    {
        RemovePlayerAttachedObject(playerid,1);
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Helm entfernt");
    }
    else {
        SetPlayerAttachedObject(playerid,1,19141,2,0.123999,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.070001);
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Helm aufgesetzt.");
    }
    return 1;
}


CMD:copbrille(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    }
    /*
    if( GetPlayerSkin(playerid) != 280 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
    }
    */
    if( IsPlayerAttachedObjectSlotUsed(playerid,7) ) {
        RemovePlayerAttachedObject(playerid,7);
        SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
    }
    else {
        SetPlayerAttachedObject( playerid, 7, 19138, 2, 0.097560, 0.028507, 0.001079, 0.000000, 89.436622, 87.944313, 1.000000, 1.000000, 1.332124 ); // PoliceGlasses1 - brille
        SendClientMessage(playerid,COLOR_YELLOW,"Angesteckt");
    }
    return 1;
}

CMD:tcop(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    }
    /*
    if( GetPlayerSkin(playerid) != 280 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
    }
    */
    if( IsPlayerAttachedObjectSlotUsed(playerid,1) ) {
        RemovePlayerAttachedObject(playerid,1);
        RemovePlayerAttachedObject(playerid,2);
        RemovePlayerAttachedObject(playerid,3);
        RemovePlayerAttachedObject(playerid,4);
        RemovePlayerAttachedObject(playerid,5);
        RemovePlayerAttachedObject(playerid,6);
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Inventare entfernt");
    }
    else {
        SetPlayerAttachedObject( playerid, 1, 334, 1, -0.065741, 0.160072, 0.172787, 270.569549, 232.509368, 179.829772, 1.000000, 1.000000, 1.000000 ); // nitestick - temp schlagstock
        SetPlayerAttachedObject( playerid, 2, 365, 1, 0.063731, -0.160821, -0.047001, 0.000000, 66.562774, 356.750793, 1.131842, 1.000000, 1.000000 ); // spraycan - temp spray
        SetPlayerAttachedObject( playerid, 3, 348, 1, 0.121761, -0.053540, -0.227441, 265.897705, 17.023633, 180.622070, 1.000000, 1.000000, 1.000000 ); // desert_eagle - temp waffe
        SetPlayerAttachedObject( playerid, 4, 19418, 1, 0.027343, -0.141089, 0.049022, 0.000000, 285.274627, 0.000000, 1.000000, 1.000000, 1.000000 ); // handcuffs01 - temp handschellen
        SetPlayerAttachedObject( playerid, 5, 18642, 1, 0.038319, 0.181583, -0.080996, 350.396789, 291.574859, 186.331298, 1.133488, 1.000000, 0.707106 ); // Taser1 - temp tazer
        SetPlayerAttachedObject( playerid, 6, 19077, 2, 0.078594, -0.013809, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000 ); // Hair3 - haare
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Inventare genommen");
    }
    return 1;
}

CMD:copman(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    }
    if( IsPlayerAttachedObjectSlotUsed(playerid,1) ) {
        RemovePlayerAttachedObject(playerid,1);
        RemovePlayerAttachedObject(playerid,2);
        RemovePlayerAttachedObject(playerid,3);
        RemovePlayerAttachedObject(playerid,4);
        RemovePlayerAttachedObject(playerid,5);
        RemovePlayerAttachedObject(playerid,8);
        RemovePlayerAttachedObject(playerid,9);
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Inventare entfernt");
    }
    else {
        SetPlayerAttachedObject(playerid, 1, 19942, 1, -0.125000, 0.198000, -0.112999, 172.599914, 85.399932, 2.500000, 1.116999, 1.385999, 0.883999, 0, 0); //Funkgerät Mann
        SetPlayerAttachedObject(playerid, 2, 19773, 1, -0.143000, 0.026999, -0.177999, 84.899955, 90.099967, 93.599998, 1.423998, 1.141999, 0.988000, 0, 0); //Holster
        SetPlayerAttachedObject(playerid, 3, 334, 1, -0.157210, -0.015581, 0.224168, 79.199546, 276.988647, 171.322982, 0.899999, 1.500000, 0.899999 ); // Schlagstock
        SetPlayerAttachedObject(playerid, 4, 365, 1, -0.104437, -0.049196, 0.147933, 297.971160, 102.321350, 351.918975, 1.100000, 1.100000, 0.949999 ); // Spray Mann
        SetPlayerAttachedObject(playerid, 5, 19418, 1, -0.187242, -0.061019, -0.076611, 0.000000, 280.079772, 350.378234, 1.000000, 1.000000, 1.000000 ); //Handschellen Mann
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Inventare genommen");
    }
    return 1;
}

CMD:copfrau(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    }
    if( IsPlayerAttachedObjectSlotUsed(playerid,1) ) {
        RemovePlayerAttachedObject(playerid,1);
        RemovePlayerAttachedObject(playerid,2);
        RemovePlayerAttachedObject(playerid,3);
        RemovePlayerAttachedObject(playerid,4);
        RemovePlayerAttachedObject(playerid,5);
        RemovePlayerAttachedObject(playerid,8);
        RemovePlayerAttachedObject(playerid,9);
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Inventare entfernt");
    }
    else {
        SetPlayerAttachedObject(playerid, 1, 19942, 1, -0.114000, 0.133999, -0.112999, 172.599914, 85.399932, 2.500000, 1.116999, 1.385999, 0.883999, 0, 0); //Funkgerät Frau
        SetPlayerAttachedObject(playerid, 2, 19773, 1, -0.143000, 0.032999, -0.177999, 84.899955, 90.099967, 93.599998, 1.423998, 1.141999, 0.928000, 0, 0); //Holster
        SetPlayerAttachedObject(playerid, 3, 334, 1, -0.157210, -0.025581, 0.219168, 79.199546, 276.988647, 171.322982, 0.899999, 1.500000, 0.899999 ); // Schlagstock
        SetPlayerAttachedObject(playerid, 4, 365, 1, -0.062999, -0.127000, 0.107999, 7.499993, 95.599967, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0); //Spray Frau
        SetPlayerAttachedObject(playerid, 5, 19418, 1, -0.143005, -0.100765, -0.064808, 0.000000, 282.527740, 347.844085, 1.000000, 1.000000, 1.000000 ); // Handschellen Frau
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Inventare genommen");
    }
    return 1;
}

CMD:armyitem(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Army Mitglied!");
    }
    /*
    if( GetPlayerSkin(playerid) != 280 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
    }
    */
    if( IsPlayerAttachedObjectSlotUsed(playerid,1) ) {
        RemovePlayerAttachedObject(playerid,1);
        RemovePlayerAttachedObject(playerid,2);
        RemovePlayerAttachedObject(playerid,3);
        RemovePlayerAttachedObject(playerid,4);
        RemovePlayerAttachedObject(playerid,5);
        RemovePlayerAttachedObject(playerid,6);
        SendClientMessage(playerid,COLOR_YELLOW,"Army-Inventare entfernt");
    }
    else {
        SetPlayerAttachedObject( playerid, 1, 356, 1, -0.107171, -0.195649, 0.042077, 0.000000, 24.433380, 0.000000, 1.000000, 1.000000, 1.000000 ); // m4 - army m4
        SetPlayerAttachedObject(playerid, 2, 19942, 1, -0.125000, 0.198000, -0.112999, 172.599914, 85.399932, 2.500000, 1.116999, 1.385999, 0.883999, 0, 0); //Funkgerät Mann
        SetPlayerAttachedObject(playerid, 3, 19773, 1, -0.143000, 0.026999, -0.177999, 84.899955, 90.099967, 93.599998, 1.423998, 1.141999, 0.988000, 0, 0); //Holster
        SetPlayerAttachedObject(playerid, 4, 334, 1, -0.157210, -0.015581, 0.224168, 79.199546, 276.988647, 171.322982, 0.899999, 1.500000, 0.899999 ); // Schlagstock
        SetPlayerAttachedObject(playerid, 5, 343, 1, -0.104437, -0.049196, 0.147933, 297.971160, 102.321350, 351.918975, 1.100000, 1.100000, 0.949999 ); // teargas
        SetPlayerAttachedObject(playerid, 6, 19418, 1, -0.187242, -0.061019, -0.076611, 0.000000, 280.079772, 350.378234, 1.000000, 1.000000, 1.000000 ); //Handschellen Mann
        SendClientMessage(playerid,COLOR_YELLOW,"Army-Inventare genommen");
    }
    return 1;
}

CMD:copcap(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,6) ) {
        RemovePlayerAttachedObject(playerid,6);
        SendClientMessage(playerid,COLOR_ORANGE,"Polizei-Cap abgenommen");
    } else {
        SetPlayerAttachedObject( playerid, 6, 19161, 2, 0.085200, 0.009999, 0.000000, 0.000000, 356.292083, 346.747100, 1.000000, 1.000000, 1.100000 ); // PoliceHat1 - polizeihut
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Cap aufgesetzt");
    }
    return 1;
}

CMD:cophut(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,6) ) {
        RemovePlayerAttachedObject(playerid,6);
        SendClientMessage(playerid,COLOR_ORANGE,"Polizei-Cap abgenommen");
    } else {
        SetPlayerAttachedObject(playerid, 6, 19099, 2, 0.168000, 0.002000, -0.001000, 0.000000, 0.699999, 5.800001, 0.962999, 1.166999, 1.235000, 0, 0 );
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Cap aufgesetzt");
    }
    return 1;
}

CMD:copmuetze(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,6) ) {
        RemovePlayerAttachedObject(playerid,6);
        SendClientMessage(playerid,COLOR_ORANGE,"Polizei-Cap abgenommen");
    } else {
        SetPlayerAttachedObject(playerid, 6, 19521, 2, 0.168000, 0.002000, -0.001000, 0.000000, 0.699999, 5.800001, 0.962999, 1.166999, 1.235000, 0, 0 );
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Cap aufgesetzt");
    }
    return 1;
}

CMD:copcapf(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,6) ) {
        RemovePlayerAttachedObject(playerid,6);
        SendClientMessage(playerid,COLOR_ORANGE,"Polizei-Cap abgenommen");
    } else {
        SetPlayerAttachedObject( playerid, 6, 19161, 2, 0.073311, -0.008209, 0.000000, 0.000000, 0.000000, 0.000000, 1.100000, 1.100000, 1.100000 ); // PoliceHat1 - polizeimütze woman
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Cap aufgesetzt");
    }
    return 1;
}

CMD:pcopcap(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,6) ) {
        RemovePlayerAttachedObject(playerid,6);
        SendClientMessage(playerid,COLOR_ORANGE,"Polizei-Cap abgenommen");
    } else {
        SetPlayerAttachedObject( playerid, 6, 19161, 2, 0.085200, -0.014271, 0.000000, 0.000000, 356.292083, 346.747100, 1.000000, 1.000000, 1.100000 ); // PoliceHat1 - polizeigut vor puma
        SendClientMessage(playerid,COLOR_YELLOW,"Polizei-Cap aufgesetzt");
    }
    return 1;
}

CMD:pschild(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( IsPlayerAttachedObjectSlotUsed(playerid,9) ) {
        RemovePlayerAttachedObject(playerid,9);
        SendClientMessage(playerid,COLOR_ORANGE,"Polizeischild angesteckt");
    } else {
        SetPlayerAttachedObject(playerid,9, 18637, 4, 0.3, 0, 0, 0, 170, 270, 1, 1, 1);
        SendClientMessage(playerid,COLOR_YELLOW,"Polizeischild abgesteckt");
    }
    return 1;
}


CMD:vrk(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    new modelid, vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if (!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur in einem Fahrzeug nutzen.");
    modelid = GetVehicleModel(vehicleid);
    if ((modelid != 596) &&  (modelid != 560) &&  (modelid != 561) &&  (modelid != 598) &&  (modelid != 525) &&  (modelid != 599) ) return SendClientMessage(playerid, COLOR_RED, "Kein Polizei Auto ");
    if (_:g_t3dPolizeiKontrolle[vehicleid] != INVALID_3DTEXT_ID ) {
        // Entfernen
        Delete3DTextLabel(g_t3dPolizeiKontrolle[vehicleid]);
        g_t3dPolizeiKontrolle[vehicleid] = Text3D:INVALID_3DTEXT_ID;
    } else {
        g_t3dPolizeiKontrolle[vehicleid] = Create3DTextLabel("Allgemeine Verkehrskontrolle\nBitte folgen Sie dem Fahrzeug", 0xFF4500FF, 0.0, 0.0, 0.0, 25.0, 0, 1);
        Attach3DTextLabelToVehicle( g_t3dPolizeiKontrolle[vehicleid],vehicleid,0.0,0.0,0.5);
    }
    return 1;
}


CMD:pein(playerid,params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    new modelid, vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur in einem Fahrzeug nutzen");
    modelid = GetVehicleModel(vehicleid);
    if( (modelid != 596) &&  (modelid != 560) &&  (modelid != 561) &&  (modelid != 598) &&  (modelid != 525) &&  (modelid != 599) ) return SendClientMessage(playerid, COLOR_RED, "Kein Polizei Auto ");
    if( _:g_t3dPolizeiKontrolle[vehicleid] != INVALID_3DTEXT_ID ) {
        // Entfernen
        Delete3DTextLabel( g_t3dPolizeiKontrolle[vehicleid] );
        g_t3dPolizeiKontrolle[vehicleid] = Text3D:INVALID_3DTEXT_ID;
    } else {
        g_t3dPolizeiKontrolle[vehicleid] = Create3DTextLabel(">> POLIZEI IM EINSATZ <<\nÜberholen erlaubt!", 0xFF4500FF, 0.0, 0.0, 0.0, 25.0, 0, 1);
        Attach3DTextLabelToVehicle( g_t3dPolizeiKontrolle[vehicleid],vehicleid,0.0,0.0,0.5);
    }
    return 1;
}


CMD:beamteon(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !IsBeamter(playerid)) return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du bist kein Beamter");
    new frak[50], String[128], bool:bBeamteOnline = false; 
    String[0] = '\0';
    for(new i ; i < MAX_PLAYERS ; i++) {
        if(IsPlayerConnected(i)) {
            //if( i != playerid ) {
                if( IsBeamter(i) ) {
                    if(!bBeamteOnline) {
                        bBeamteOnline = true;
                        SendClientMessage(playerid,COLOR_YELLOW,"========BEAMTEN-LISTE========");
                    }
                    ReturnPlayerFraktion( i, frak );
                    if( String[0] ) {
                        format(String,sizeof(String),"%s,[%d] %s - %s",String,i,GetName(i), frak );
                    } else {
                        format(String,sizeof(String),"[%d] %s - %s",i,GetName(i), frak );
                    }
                    if( strlen(String) > 100 ) {
                        SendClientMessage(playerid,COLOR_GREEN,String);
                        String[0] = '\0';
                    }
                }
            //}
        }
    }
    if(!bBeamteOnline) SendClientMessage(playerid,COLOR_LIGHTRED2,"Es sind keine Beamten online!");
    else SendClientMessage(playerid,COLOR_GREY,String);
    return 1;
}


CMD:suicidearrest(playerid, params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID;
    if(!IsCop(playerid)) return SendClientMessage(playerid,COLOR_RED,"Du bist kein Polizist.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Suicidearrest [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (Spieler[playerid][pTot]) return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Verbrecher verhaften, während du tot bist.");
    if (Spieler[pID][pWanteds] < 4) return SendClientMessage(playerid, COLOR_RED, "Du kannst Verbrecher erst ab 4 Wanteds suizidverhaften.");
    if(IsAFK[pID] == 1)return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler befindet sich im AFK-Modus.");
    if(Spieler[pID][pAdminDienst]) return SCMFormatted(playerid,COLOR_RED,"%s ist im Admindienst.",GetName(pID));
    if(Spieler[pID][pWanteds] < 1) return SendClientMessage(playerid,COLOR_RED,"Der Spieler hat keine Wanteds.");
    if(SuicidePlayer[pID] != INVALID_TIMER_ID) return SendClientMessage(playerid,COLOR_RED,"Der Spieler wurde bereits arrestet.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x, y, z);
    if(!IsPlayerInRangeOfPoint(playerid, 10, x, y, z)) return SCMFormatted(playerid,COLOR_RED,"Du bist nicht in der nähe von %s.",GetName(pID));
    if(IsPlayerAFK(pID)) {
        new message[256];
        SuicidePlayer[pID] = SetTimerEx("Suicidearrest",300000,false,"dd",playerid,pID);
        format(message,sizeof(message),"Polizeibeamter %s will dich arresten.\nBist du 5 Minuten Abwesend wirst du eingesperrt.\n\nSolltest du Anwesend sein bestätige.",GetName(playerid));
        ShowPlayerDialog(pID, DIALOG_SUICIDEARREST, DIALOG_STYLE_MSGBOX, "Suicide Arrest", message, "Anwesend", "");
    } else if(!IsPlayerAFK(pID) && Spieler[pID][pTot] != 0) {
        SuicidePlayer[pID] = SetTimerEx("Suicidearrest",1003,false,"dd",playerid,pID);
    }
    return 1;
}


CMD:arrest(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
	new pID, Zeit, string[128];
	if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
	if(sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Arrest [SpielerID/Name]");
	if(!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_WHITE, "{AA3333}Der Spieler ist nicht online.");
    if( Spieler[pID][pAdminDienst] ) return SCMFormatted(playerid,COLOR_RED,"%s ist im Admindienst.",GetName(pID));
	if(pID == playerid)return SendClientMessage(playerid, COLOR_WHITE, "{AA3333}Du kannst dich nicht selber einsperren.");
	if(!IsPlayerInRangeOfPoint(pID, 10, LSPD_ARREST_COORDS) || IsPlayerInRangeOfPoint(pID, 10, LSPD_INTERIOR_ERGEBEN_POINT) || IsPlayerInRangeOfPoint(pID, 10, 2268.1128,2448.0073,3.5313)) return SCMFormatted(playerid,COLOR_RED,"%s ist nicht in der Nähe vom Arrest Punkt.",GetName(pID));
	if(!IsPlayerInRangeOfPoint(playerid, 10, LSPD_ARREST_COORDS) || IsPlayerInRangeOfPoint(playerid, 10, LSPD_INTERIOR_ERGEBEN_POINT) || IsPlayerInRangeOfPoint(playerid, 10, 2268.1128,2448.0073,3.5313) ) return SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht am Arrest Punkt.");
    if(IsAFK[pID] == 1)return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler befindet sich im AFK-Modus.");
	if(Spieler[pID][pWanteds] > 0) {
	    format(string, sizeof(string), "{AA3333}>> %s %s hat den Verbrecher %s eingesperrt. <<", GetRankName(Spieler[playerid][pFraktion], Spieler[playerid][pRank]), GetName(playerid), GetName(pID));
		SendClientMessageToAll(COLOR_DARKRED, string);
		SendClientMessage(pID, COLOR_GREEN, "* Da du dich gestellt hast, wirst du je Wanted 150 Sekunden anstatt 220 Sekunden je Wanted sitzen!");
		new gehalt = (200*Spieler[pID][pWanteds]);
		new pStaatGehalt = (200*Spieler[pID][pWanteds]);
		TreasuryDeposit(pStaatGehalt);
		format(string, sizeof(string), "~w~Gesuchten ~g~eingesperrt~n~+$%s", AddDelimiters( gehalt));
		GameTextForPlayer(playerid, string, 3000, 6);
		Spieler[playerid][pPayCheck] += gehalt;
		GivePlayerCash(pID, -gehalt);
        if( Spieler[pID][pWanteds] >= ALCATRAZ_WANTEDS ) Spieler[pID][pJailed] = 2;
        else Spieler[pID][pJailed] = 1;
        Spieler[pID][pTot] = 0;
        Spieler[pID][pJailTime] = 40*Spieler[pID][pWanteds];
        Spieler[pID][pCrimes] ++;
        Spieler[pID][pTotTime] = 0;
        Spieler[pID][pTotX] = 0.0;
        Spieler[pID][pTotY] = 0.0;
        Spieler[pID][pTotZ] = 0.0;
        Spieler[pID][pWanteds] = 0;
        DestroyDeathIcon(pID);
        Cuffed[pID] = 0;
        SpawnPlayerEx(pID);
        Zeit = Spieler[pID][pJailTime]/60;
		format(string, sizeof(string), "{8D8DFF}[HQ]: %s %s hat den Verdächtigen %s eingesperrt.", GetRankName(Spieler[playerid][pFraktion], Spieler[playerid][pRank]), GetName(playerid), GetName(pID));
		SendFraktionMessage(1, COLOR_WHITE, string);
		SendFraktionMessage(2, COLOR_WHITE, string);
		SendFraktionMessage(16, COLOR_WHITE, string);
		SendFraktionMessage(18, COLOR_WHITE, string);
		SendFraktionMessage(22, COLOR_WHITE, string);
		format(string, sizeof(string), "{8D8DFF}[HQ]: Haftzeit: %d Minuten, Geldstrafe: %d$", Zeit,gehalt);
		SendFraktionMessage(1, COLOR_WHITE, string);
		SendFraktionMessage(2, COLOR_WHITE, string);
		SendFraktionMessage(16, COLOR_WHITE, string);
		SendFraktionMessage(18, COLOR_WHITE, string);
		SendFraktionMessage(22, COLOR_WHITE, string);
    }
    else return SCMFormatted(playerid,COLOR_RED,"%s hat keine Wanteds.",GetName(pID));
    return 1;
}


CMD:caufbrechen(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new biz, house;
    if(!IsPlayerExecutive(playerid)) return SendClientMessage(playerid,COLOR_RED,"Du bist kein Polizist");
    new String[128], Float:x, Float:y, Float:z;
    house = GetClosestHouse(playerid);
    if(house == 999 ) {
        biz = GetClosestBiz(playerid);
        if( biz != 999 ) {
            GetPlayerPos(playerid,x,y,z);
            SetPlayerInterior(playerid, Biz[biz][bInterior]);
            SetPlayerVirtualWorld(playerid, Biz[biz][bID]);
            SetPlayerPos(playerid, Biz[biz][ExitX], Biz[biz][ExitY], Biz[biz][ExitZ]);
            format(String,sizeof(String),"** Beamter %s bricht in ein Geschäft ein **",GetName(playerid));
            SendRoundMessage(x,y,z, COLOR_PURPLE, String);
        }
        else return SendClientMessage(playerid,COLOR_RED,"Du bist an keinem Biz");
    } else {
        GetPlayerPos(playerid,x,y,z);
        new index;
        index = GetHouseInteriorIndexByID( Haus[house][HouseInteriorID] );
        SetPlayerInterior(playerid, g_HouseInterior[index][HI_iInterior] );
        SetPlayerPos(playerid, g_HouseInterior[index][HI_fExitX], g_HouseInterior[index][HI_fExitY], g_HouseInterior[index][HI_fExitZ]);
        // SetPlayerInterior(playerid, Haus[house][hInterior]);
        SetPlayerVirtualWorld(playerid, house );
        // SetPlayerPos(playerid, Haus[house][ExitX], Haus[house][ExitY], Haus[house][ExitZ]);
        format(String,sizeof(String),"** Beamter %s bricht in ein Haus ein **",GetName(playerid));
        SendRoundMessage(x,y,z, COLOR_PURPLE, String);
    }
    return 1;
}



CMD:acceptcpartner(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Acceptcpartner [Spieler]");
    if( !IsPlayerExecutive(playerid) ) return SendClientMessage(playerid, COLOR_RED,"Du bist kein Polizist!");
    if( !IsPlayerExecutive(giveid) ) return SendClientMessage(playerid, COLOR_RED,"Der Spieler ist kein Polizist!");
    if( g_PolizeiPartner[playerid][PP_iStatus] == PolizeiPartner_Active ) return SendClientMessage(playerid, COLOR_RED,"Du hast bereits einen Streifenpartner!");
    if( g_PolizeiPartner[giveid][PP_iStatus] == PolizeiPartner_Active ) return SendClientMessage(playerid, COLOR_RED,"Der Spieler hat bereits einen Streifenpartner!");
    if( g_PolizeiPartner[giveid][PP_iStatus] != PolizeiPartner_Wait ) return SendClientMessage(playerid, COLOR_RED,"Der Spieler hat keinen Streifenpartner-Anfrage versendet!");
    if( g_PolizeiPartner[giveid][PP_iPartner] != playerid ) return SendClientMessage(playerid, COLOR_RED,"Der Spieler hat keinen Streifenpartner-Anfrage an dich versendet!");
    new String[128];
    format(String,sizeof(String),"Polizeibeamter %s und %s sind zusammen auf Streife!",GetName(giveid),GetName(playerid));
    SendExecutiveMessage(COLOR_YELLOW,String);
    g_PolizeiPartner[giveid][PP_iPartner] = playerid;
    g_PolizeiPartner[giveid][PP_iStatus] = PolizeiPartner_Active;
    g_PolizeiPartner[playerid][PP_iPartner] = giveid;
    g_PolizeiPartner[playerid][PP_iStatus] = PolizeiPartner_Active;
    SetPlayerMarkerForPlayer(playerid,giveid,COLOR_COPPARTNER);
    SetPlayerMarkerForPlayer(giveid,playerid,COLOR_COPPARTNER);
    return 1;
}


CMD:cpartner(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Cpartner [Spieler]");
    if( !IsPlayerExecutive(playerid) ) return SendClientMessage(playerid, COLOR_RED,"Du bist kein Polizist!");
    if( !IsPlayerExecutive(giveid) ) return SendClientMessage(playerid, COLOR_RED,"Der Spieler ist kein Polizist!");
    if( g_PolizeiPartner[playerid][PP_iStatus] == PolizeiPartner_Wait )  return SendClientMessage(playerid, COLOR_RED,"Du hast bereits eine Partneranfrage gesendet!");
    if( g_PolizeiPartner[playerid][PP_iStatus] == PolizeiPartner_Active ) return SendClientMessage(playerid, COLOR_RED,"Du hast bereits einen Streifenpartner!");
    if( g_PolizeiPartner[giveid][PP_iStatus] == PolizeiPartner_Wait && g_PolizeiPartner[giveid][PP_iPartner] == playerid) return cmd_acceptcpartner(playerid,params);
    if( g_PolizeiPartner[giveid][PP_iStatus] == PolizeiPartner_Active ) return SendClientMessage(playerid, COLOR_RED,"Der Spieler hat bereits einen Streifenpartner!");
    new String[128];
    format(String,sizeof(String),"Du hast an Polizeibeamten %s eine Streifenpartnerschafts-Anfrage gesendet!",GetName(giveid));
    SendClientMessage(playerid,COLOR_YELLOW,String);
    format(String,sizeof(String),"Polizeibeamter %s möchte mit dir zusammen auf Streife fahren! Akzeptieren mit /Acceptcpartner",GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    g_PolizeiPartner[playerid][PP_iPartner] = giveid;
    g_PolizeiPartner[playerid][PP_iStatus] = PolizeiPartner_Wait;
    return 1;
}


CMD:kofferdurchsuchen(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(!IsPlayerExecutive(playerid) && Spieler[playerid][pFraktion] != 5 )return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist oder Ordnungsbeamter.");
    new giveid;
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Kofferdurchsuchen [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,4.0,x,y,z) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist zu weit entfernt von dir.");
    if(Spieler[giveid][pKoffer] == false ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler besitzt keinen Koffer.");
    if( !IsPlayerAttachedObjectSlotUsed(giveid,ATTACHED_INDEX_KOFFER) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler trägst seinen Koffer nicht.");
    new String[128];
    format(String, sizeof(String), "* Officer %s durchsucht den Koffer von %s.", GetName(playerid), GetName(giveid));
    SendRoundMessage(x, y, z, COLOR_PURPLE, String);
    // Kofferinhalt
    SendKofferInfo(playerid,giveid);
    return 1;
}

CMD:koffereinziehen(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(!IsPlayerExecutive(playerid) && Spieler[playerid][pFraktion] != 5 )return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist oder Ordnungsbeamter.");
    new giveid;
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Koffereinziehen [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,4.0,x,y,z) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist zu weit entfernt von dir.");
    if(Spieler[giveid][pKoffer] == false ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler besitzt keinen Koffer.");
    if( !IsPlayerAttachedObjectSlotUsed(giveid,ATTACHED_INDEX_KOFFER) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler trägst seinen Koffer nicht.");
    new String[128];
    format(String, sizeof(String), "* Officer %s entzieht den Koffer von %s.", GetName(playerid), GetName(giveid));
    SendRoundMessage(x, y, z, COLOR_PURPLE, String);
    // Kofferinhalt
    format(String,sizeof(String),"%s hat den Koffer von %s eingezogen.",GetName(playerid),GetName(giveid));
    SendFraktionMessage(1, COLOR_YELLOW, String);
    SendFraktionMessage(2, COLOR_YELLOW, String);
    SendFraktionMessage(16, COLOR_YELLOW, String);
    SendFraktionMessage(18, COLOR_YELLOW, String);
    SendFraktionMessage(22, COLOR_YELLOW, String);
    ResetKoffer(giveid);
    Spieler[giveid][pKoffer] = false;
    if( IsPlayerAttachedObjectSlotUsed(giveid,ATTACHED_INDEX_KOFFER) ) {
        RemovePlayerAttachedObject(giveid,ATTACHED_INDEX_KOFFER);
    }
    return 1;
}



CMD:inthaft(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( !IsPlayerExecutive(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Inthaft [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[giveid][pWanteds] < 1 ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keine Wanted Punkte.");
    new String[128];
    format(String,sizeof(String),"[FAHNDUNG] Die Polizei schreibt eine öffentliche Fahndung gegen %s aus.",GetName(giveid),Spieler[giveid][pWanteds]);
    SendClientMessageToAll(COLOR_ORANGE,String);
    format(String,sizeof(String),"Die Bevölkerung wird um Mithilfe zur Ergreifung des Täters gebeten. Belohnung: $50.000");
    SendClientMessageToAll(COLOR_ORANGE,String);
    return 1;
}


CMD:pnotrufinfo(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( !IsPlayerExecutive(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Notrufinfo [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new String[128];
    format(String,sizeof(String),"[STAAT] Bürgerstreit, Verbrechen oder Verkehrsdelikt - POLIZEI NOTRUF: /Anrufen 110.");
    SendClientMessageToAll(COLOR_ORANGE,String);
    return 1;
}



CMD:ermitteln(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( !IsPlayerExecutive(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Ermitteln [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[giveid][pWanteds] < 1 ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keine Wanted Punkte.");
    new String[128];
    format(String,sizeof(String),"Polizeibeamter %s nimmt die Ermittlungen gegen Straftäter %s, Wantedanzahl: %d auf!",GetName(playerid),GetName(giveid),Spieler[giveid][pWanteds]);
    SendFraktionMessage(1, COLOR_YELLOW, String);
    SendFraktionMessage(2, COLOR_YELLOW, String);
    SendFraktionMessage(16, COLOR_YELLOW, String);
    SendFraktionMessage(18, COLOR_YELLOW, String);
    SendFraktionMessage(22, COLOR_YELLOW, String);
    Spieler[playerid][pDutyTask] = 1;
    return 1;
}


CMD:pvk(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( !IsPlayerExecutive(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Pvk [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[giveid][pWanteds] < 1 )return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keine Wanted Punkte.");
    new String[128];
    format(String,sizeof(String),"Polizeibeamter %s benötigt dringende Verstärkung beim Straftäter %s, Wantedanzahl: %d!",GetName(playerid),GetName(giveid),Spieler[giveid][pWanteds]);
    SendFraktionMessage(1, COLOR_RED, String);
    SendFraktionMessage(2, COLOR_RED, String);
    SendFraktionMessage(16, COLOR_RED, String);
    SendFraktionMessage(18, COLOR_RED, String);
    SendFraktionMessage(22, COLOR_RED, String);
    PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
    return 1;
}



CMD:zvk(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( !IsPlayerExecutive(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Zvk [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[giveid][pWanteds] < 1 ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keine Wanted Punkte.");
    new String[128];
    format(String,sizeof(String),"Zollbeamter %s benötigt dringende Verstärkung beim Straftäter %s, Wantedanzahl: %d!",GetName(playerid),GetName(giveid),Spieler[giveid][pWanteds]);
    SendFraktionMessage(1, COLOR_RED, String);
    SendFraktionMessage(2, COLOR_RED, String);
    SendFraktionMessage(16, COLOR_RED, String);
    SendFraktionMessage(18, COLOR_RED, String);
    SendFraktionMessage(22, COLOR_RED, String);
    return 1;
}

CMD:meldestelle(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( !IsPlayerExecutive(playerid) && Spieler[playerid][pFraktion] != 5) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Meldestelle [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new String[128];
    SendClientMessage(playerid,COLOR_YELLOW,"=========MELDEREGISTER=========");
    format(String,sizeof(String),"Eintrag von: %s",GetName(giveid));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Staatsbürger: %s",Spieler[giveid][pStaat]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    if( GetPlayerHouse(giveid) == 999 && Spieler[giveid][pPlayerHotel] == 999 ) {
        SendClientMessage(playerid,COLOR_WHITE,"Obdachlos: Ja");
    } else {
        SendClientMessage(playerid,COLOR_WHITE,"Obdachlos: Nein");
    }
    new pHouse = GetPlayerHouse(giveid);
    if( pHouse == 999 ) {
        SendClientMessage(playerid,COLOR_WHITE,"Wohnhaft: Unbekannt");
    } else {
        format(String,sizeof(String),"Wohnhaft: %s",Haus[pHouse][hName]);
        SendClientMessage(playerid,COLOR_WHITE,String);
        SendClientMessage(playerid,COLOR_YELLOW,"Der Wohnort vom Spieler wurde dir auf der Map markiert!");
        SetPlayerCheckpointEx(playerid, Haus[pHouse][EnterX],Haus[pHouse][EnterY],Haus[pHouse][EnterZ], 3.0, CP_MELDESTELLE);
    }
    return 1;
}




CMD:verhaften(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Verhaften [SpielerID/Name]");
    if(Spieler[pID][pAdminDienst]) return SCMFormatted(playerid,COLOR_RED,"%s ist im Admindienst.",GetName(pID));
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    if(playerid == pID ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an dir selbst ausführen!");
    if(IsPlayerExecutive(pID)) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Beamten der Exekutive verhaften!");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(!IsPlayerInRangeOfPoint(pID, 3.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    if( IsPlayerAttachedObjectSlotUsed(pID,ATTACHED_INDEX_HANDSCHELLE) ) {
        format(string, sizeof(string), "* Polizeibeamter %s hat %s die Handschellen abgemacht.", GetName(playerid), Spieler[pID][bMaske] ? "<Unbekannt>" : GetName(pID));
        foreach(new i : Player) {
            if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z)) {
                SendClientMessage(i, COLOR_LIGHTRED2, string);
            }
        }
        SetPlayerSpecialAction(pID,SPECIAL_ACTION_NONE);
        RemovePlayerAttachedObject(pID,ATTACHED_INDEX_HANDSCHELLE);
        Cuffed[pID] = 0;
    } else {
        format(string, sizeof(string), "* Polizeibeamter %s hat %s die Handschellen angelegt.", GetName(playerid), Spieler[pID][bMaske] ? "<Unbekannt>" : GetName(pID));
        foreach(new i : Player) {
            if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z)) {
                SendClientMessage(i, COLOR_LIGHTRED2, string);
            }
        }

        new isInVeh = IsPlayerInAnyVehicle(pID);

        SetPlayerAttachedObject(pID, ATTACHED_INDEX_HANDSCHELLE, 19418, 6, -0.011000, 0.028000, -0.022000, -15.600012, -33.699977, -81.700035, 0.891999, 1.000000, 1.168000);
        SetPlayerSpecialAction(pID,SPECIAL_ACTION_CUFFED);
        
        Cuffed[pID] = 1;
        
        if(isInVeh)
            PutPlayerInVehicle(pID, GetPlayerVehicleID(playerid), GetFreeVehicleSeat(GetPlayerVehicleID(playerid)));
    }

    if(IsPlayerInAnyVehicle(pID))
        UnfreezePlayer(pID);
    else
        UnFreeze(pID);
        
    return 1;
}



new TazerWeapon[MAX_PLAYERS];

CMD:tazer(playerid, params[]){
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22 || !(Spieler[playerid][pAdmin] < 5))) return SendClientMessage(playerid, COLOR_RED, "Du kannst diesen Befehl nicht nutzen!");
    if(!Spieler[playerid][pDuty] && Spieler[playerid][pAdmin] < 5) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst!");
    if(IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Diese Funktion ist nicht in einem Fahrzeug möglich.");
	new weaponid, weaponamo;
	GetPlayerWeaponData(playerid, 2, weaponid, weaponamo);
	if(weaponid == 24){
     	cmd_me(playerid, "steckt seine Dienstwaffe ins Holster und holt seinen Tazer heraus!");
     	TazerWeapon[playerid] = weaponamo;
     	GivePlayerWeapon(playerid, 23, 99999);
     	SetPlayerArmedWeapon(playerid, 23);
	}else if(weaponid == 23){
	    cmd_me(playerid, "steckt seinen Tazer weg und holt seine Dienstwaffe aus dem Holster heraus!");
     	GivePlayerWeapon(playerid, 24, TazerWeapon[playerid]);
     	SetPlayerArmedWeapon(playerid, 24);
     	TazerWeapon[playerid] = 0;
	}
	return 1;
}



CMD:hsirene(playerid, params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new vehicleid,panels,doors,lights,tires;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!Flasher[vehicleid]) {
        if (!GetVehicleModel(vehicleid)) return SendClientMessage(playerid, -1, "Du sitzt in keinem Fahrzeug!");
        if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, -1, "Du bist nicht der Fahrer!");
        if(!IsPoliceVehicleAllowed(Spieler[playerid][pFraktion],GetVehicleFraktion(vehicleid))) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur in Fahrzeugen der Exekutive eine Sirene aktivieren.");
        if (IsValidDynamicObject(sireneobj[vehicleid][0]) || IsValidDynamicObject(sireneobj[vehicleid][1]) || IsValidDynamicObject(sireneobj[vehicleid][2])) {
                SendClientMessage(playerid, -1, "Sirene deaktiviert");
                for(new i ; i < sizeof(sireneobj[]); i++) {
                    DestroyDynamicObject(sireneobj[vehicleid][i]);
                    sireneobj[vehicleid][i] = INVALID_OBJECT_ID;
                }
                if(LightPwr[vehicleid] == 1) {
                    UpdateVehicleDamageStatus(vehicleid, panels, doors, 0, tires);
                } else {
                    UpdateVehicleDamageStatus(vehicleid, panels, doors, 5, tires);
                }
                Flasher[vehicleid] = 0;
        }
        switch (GetVehicleModel(vehicleid)) {
            case 560: {
                if(!IsBeamter(playerid))
                    return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Sultan nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000, 0.850341, 0.388433, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 528: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem FBI-TRUCK nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000,0.000000,0.950000,0.000000,0.000000,0.000000);
                Flasher[vehicleid] = 1;
            }
            case 541: {
                if(!IsBeamter(playerid))
                    return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Bullet nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000, 0.652832, 0.314574, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 411: {
                if(!IsBeamter(playerid))
                    return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Infernus nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid,0.500000,0.250000,0.700000,0.000000,0.000000,0.000000);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid,-0.500000,0.250000,0.700000,0.000000,0.000000,0.000000); 
                Flasher[vehicleid] = 1;
            }
            case 451: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Turismo nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0],vehicleid,-0.450000,-0.300000,0.600000,0.000000,0.000000,0.000000);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1],vehicleid,0.450000,-0.300000,0.600000,0.000000,0.000000,0.000000); 
                Flasher[vehicleid] = 1;
            }
            case 522: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem NRG-500 nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0],vehicleid,0.000000,0.300000,0.650000,0.000000,0.000000,0.000000);
                Flasher[vehicleid] = 1;
            }
            case 544: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Firetruck nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000, 2.520202, 1.507225, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 427: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Enforcer nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, -0.311401, 1.151977, 1.421513, 0.000000, 0.000000, 0.000000);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid, 0.389526, 1.151977, 1.421513, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 426: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Premier nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000, 0.882019, 0.343078, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 407: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Firetruck nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.686279, 3.204040, 1.289827, 0.000000, 0.000000, 0.000000);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid, -0.645385, 3.204040, 1.289827, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 601: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem S.W.A.T nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000, 0.000000, 1.959999, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 596: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Police Car (LSPD) nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646 , 0.0 , 0.0 , 0.0, 0.0 , 0.0, 0.0);
                sireneobj[vehicleid][2] = CreateDynamicObject(18646 , 0.0 , 0.0 , 0.0, 0.0 , 0.0, 0.0 );
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, -0.02, 2.18, -0.15,   0.00, 0.00, 0.00);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid, 0.399999, -0.400000, 0.899999, 0.000000, 0.000000, 0.000000);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][2], vehicleid, -0.499999, -0.400000, 0.899999, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 597: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Police Car (SFPD) nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646 , 0.0 , 0.0 , 0.0, 0.0 , 0.0, 0.0);
                sireneobj[vehicleid][2] = CreateDynamicObject(18646 , 0.0 , 0.0 , 0.0, 0.0 , 0.0, 0.0 );
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, -0.02, 2.18, -0.15,   0.00, 0.00, 0.00);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid, 0.399999, -0.400000, 0.899999, 0.000000, 0.000000, 0.000000);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][2], vehicleid, -0.499999, -0.400000, 0.899999, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 598: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Police Car (LVPD) nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 10.0, 10.0, 10.0, 0, 0, 0);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646 , 0.0 , 0.0 , 0.0, 0.0 , 0.0, 0.0);
                sireneobj[vehicleid][2] = CreateDynamicObject(18646 , 0.0 , 0.0 , 0.0, 0.0 , 0.0, 0.0 );
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, -0.02, 2.18, -0.15,   0.00, 0.00, 0.00);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid, 0.399999, -0.400000, 0.899999, 0.000000, 0.000000, 0.000000);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][2], vehicleid, -0.499999, -0.400000, 0.899999, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 599: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Police Ranger nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.524999,0.000000,1.125000,0.000000,0.000000,0.000000);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid, -0.524999,0.000000,1.125000,0.000000,0.000000,0.000000);
                Flasher[vehicleid] = 1;
            }
            case 490: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem FBI-Ranger nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000, 1.191101, 0.559186, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 432: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Rhino nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 1.600000, 3.899998, 0.600000, 0.000000, 0.000000, 0.000000);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid, 1.600000, -4.099998, 0.799999, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 523: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem HPV1000 nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                sireneobj[vehicleid][1] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000, 0.599999, 0.600000, 0.000000, 0.000000, 0.000000);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][1], vehicleid, 0.000000, -1.100000, 1.000000, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            case 579: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Huntley nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.6299, -0.0000, 1.2599, 0.0000, 0.0000, 360.0000);
                Flasher[vehicleid] = 1;
            }
            case 415: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Cheetah nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.3400, 0.5399, 0.2200, 0.0000, 360.0000, 0.0000);
                Flasher[vehicleid] = 1;
            }
            case 525: {
                if(!IsBeamter(playerid))
                return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Tow-Truck nur als Beamter die Sirene aktivieren.");
                sireneobj[vehicleid][0] = CreateDynamicObject(11701, 0.0, 0.0, 0.0, 0.0, 0.0, 80.0);
                AttachDynamicObjectToVehicle(sireneobj[vehicleid][0], vehicleid, 0.000000, -0.500000, 1.500000, 0.000000, 0.000000, 0.000000);
                Flasher[vehicleid] = 1;
            }
            default: {
                return SendClientMessage(playerid, COLOR_RED, "Auf diesem Fahrzeug kannst du keine Sirene platzieren.");
            }
        }
        return SendClientMessage(playerid, -1, "Sirene aktiviert");
    } else {
        if (IsValidDynamicObject(sireneobj[vehicleid][0]) || IsValidDynamicObject(sireneobj[vehicleid][1]) || IsValidDynamicObject(sireneobj[vehicleid][2])) {
            SendClientMessage(playerid, -1, "Sirene deaktiviert");
            for(new i ; i < sizeof(sireneobj[]) ; i++) {
                DestroyDynamicObject(sireneobj[vehicleid][i]);
                sireneobj[vehicleid][i] = INVALID_OBJECT_ID;
            }
        }
        GetVehicleDamageStatus(vehicleid,panels,doors,lights,tires);
        if(LightPwr[vehicleid] == 1)
            UpdateVehicleDamageStatus(vehicleid, panels, doors, 0, tires);
        else
            UpdateVehicleDamageStatus(vehicleid, panels, doors, 5, tires);
        Flasher[vehicleid] = 0;
    }
    return 1;
}


CMD:offlinearrest(playerid, params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !IsPlayerExecutive(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    new sLowerName[MAX_PLAYER_NAME], sName[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",sName)) return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/offlinearrest [Name]");

    if (IsPlayerConnected(GetPlayerIdFromName(sName))) return SendClientMessage(playerid, COLOR_RED,"Der Spieler ist noch online");

    strcat(sLowerName,sName);
    strtolower(sLowerName);
    
    mysql_real_escape_string(sName,sName);

    new sqlString[140];
    format(sqlString,sizeof(sqlString),"SELECT LOWER(`Name`), `Wanteds` FROM accounts WHERE Name = '%s'",sName);
    mysql_pquery(sqlString,THREAD_OFFLINEARREST2,playerid,gSQL,MySQLThreadOwner);
    return 1;
}


CMD:vamt(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( !IsPlayerExecutive(playerid) && Spieler[playerid][pFraktion] != 5) return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    new giveid;
    if(sscanf(params,"u",giveid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Vamt [ID/SPIELERNAME]");
    if( !IsPlayerConnected(giveid) ) return SendClientMessage(playerid,COLOR_RED,"Ungültiger Spieler.");
    Scheine(playerid,giveid,1);
    return 1;
}



CMD:ve(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    #pragma unused params
    if( !IsPlayerExecutive(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if( Spieler[playerid][pDuty] == 0 ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    new String[128];
    if( Spieler[playerid][pDutyTask] == 1 ) {
        format(String,sizeof(String),"[LEITZENTRALE] Polizeibeamter %s ist wieder verfügbar!",GetName(playerid));
        SendFraktionMessage(1, COLOR_GREEN, String);
        SendFraktionMessage(2, COLOR_GREEN, String);
        SendFraktionMessage(16, COLOR_GREEN, String);
        Spieler[playerid][pDutyTask] = 0;
    } else {
        format(String,sizeof(String),"[LEITZENTRALE] Polizeibeamter %s meldet sich als nicht verfügbar!",GetName(playerid));
        SendFraktionMessage(1, COLOR_ORANGE, String);
        SendFraktionMessage(2, COLOR_ORANGE, String);
        SendFraktionMessage(16, COLOR_ORANGE, String);
        Spieler[playerid][pDutyTask] = 1;
    }
    return 1;
}


CMD:strafzettel(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    #pragma unused params
    if( Spieler[playerid][pFraktion] != 1 &&
        Spieler[playerid][pFraktion] != 5 &&
        Spieler[playerid][pFraktion] != 16 ) {
        SendClientMessage(playerid, COLOR_RED, "Dieser Befehl ist nur für das Ordnungsamt und Polizisten möglich");
        return 1;
    }
    new vehicleid = GetClosestVehicle(playerid,4.0);
    if( vehicleid == INVALID_VEHICLE_ID ) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht in der nähe eines Fahrzeuges");
    new besitzer;
    besitzer = GetCarOwner(vehicleid);
    if( IsPlayerConnected(besitzer)) {
        new
            String[128];
        if( g_Parkschein[vehicleid] > gettime() ) return SendClientMessage(playerid,COLOR_RED,"Das Fahrzeug hat noch einen gültigen Parkschein");
        format(String,sizeof(String),"Bußgeld wurde an Fahrzeughalter %s ausgestellt, wegen Parken auf Halteverbot.",GetName(besitzer));
        SendFraktionMessage(1, COLOR_YELLOW, String);
        SendFraktionMessage(16, COLOR_YELLOW, String);
        SendFraktionMessage(5, COLOR_YELLOW, String);
        SendClientMessage(playerid,COLOR_YELLOW, "* Strafzettel wurde ausgestellt");
        format(String,sizeof(String),"[BUßGELD] Sie haben ein Bußgeld in Höhe von 2.000$ von Beamten %s erhalten!",GetName(playerid));
        SendClientMessage(besitzer,COLOR_RED,String);
        format(String,sizeof(String),"Ihr Fahrzeug (%s) steht auf Halteverbot.", CarName[ GetVehicleModel(vehicleid) - 400]);
        SendClientMessage(besitzer,COLOR_RED,String);
        Spieler[besitzer][pBank] -= 2000;
        Kasse[Oamt] += 2000;
    }
    else SendClientMessage(playerid,COLOR_RED,"Dieses Fahrzeug hat keinen Besitzer");
    return 1;
}


CMD:parkstrafe(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    #pragma unused params
    if( Spieler[playerid][pFraktion] != 1 &&
        Spieler[playerid][pFraktion] != 5 &&
        Spieler[playerid][pFraktion] != 16 ) {
        SendClientMessage(playerid, COLOR_RED, "Dieser Befehl ist nur für das Ordnungsamt und Polizisten möglich");
        return 1;
    }
    new vehicleid = GetClosestVehicle(playerid,4.0);
    if( vehicleid == INVALID_VEHICLE_ID ) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht in der nähe eines Fahrzeuges");
    new besitzer;
    besitzer = GetCarOwner(vehicleid);
    if( IsPlayerConnected(besitzer)) {
        new
            String[128];
        if( g_Parkschein[vehicleid] > gettime() ) {
            return SendClientMessage(playerid,COLOR_RED,"Das Fahrzeug hat noch einen gültigen Parkschein");
        }
        format(String,sizeof(String),"Bußgeld wurde an Fahrzeughalter %s ausgestellt, wegen Parken ohne Parkschein.",GetName(besitzer));
        SendFraktionMessage(1, COLOR_YELLOW, String);
        SendFraktionMessage(16, COLOR_YELLOW, String);
        SendFraktionMessage(5, COLOR_YELLOW, String);
        SendClientMessage(playerid,COLOR_YELLOW, "* Parkstrafe wurde verhängt");
        format(String,sizeof(String),"[BUßGELD] Sie haben ein Bußgeld in Höhe von 3.000$ von Beamten %s erhalten!",GetName(playerid));
        SendClientMessage(besitzer,COLOR_RED,String);
        format(String,sizeof(String),"Ihr Fahrzeug (%s) war ohne gültigem Parkschein an der Stadthalle abgestellt.", CarName[ GetVehicleModel(vehicleid) - 400]);
        SendClientMessage(besitzer,COLOR_RED,String);
        Spieler[besitzer][pBank] -= 3000;
        Kasse[Oamt] += 3000;
    } else {
        SendClientMessage(playerid,COLOR_RED,"Dieses Fahrzeug hat keinen Besitzer");
    }
    return 1;
}


CMD:clear(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, punkte, sGrund[128], string[128];
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(sscanf(params, "udS(Ohne Angabe)[128]", pID,punkte,sGrund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Clear [SpielerID/Name] [Punkte] [Grund]");
    if(pID == playerid) return SendClientMessage(playerid, COLOR_RED, "Du kannst deine eigene Akte nicht bereinigen");
    if(punkte < 1 || punkte > 20)return SendClientMessage(playerid, COLOR_RED, "Du kannst nicht mehr als 20 Wanteds aufeinmal vergeben!");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    //if(!IsPlayerInRangeOfPoint(playerid, 3.0, 238.3031,71.3587,1005.0391) || !IsPlayerInRangeOfPoint(playerid, 3.0, 251.4832,187.7063,1008.1719))return SendClientMessage(playerid, COLOR_GREY, "Du bist nicht im LSPD am Computer.");
    Spieler[pID][pWanteds] -= punkte;
    //SetPlayerWantedLevel(pID,0);
    if( Spieler[pID][pWanteds] < 0 ) {
        Spieler[pID][pWanteds] = 0;
    }
    format(string, sizeof(string), "Polizeibeamter %s hat %d Punkte deiner Akte gelöscht. ( Grund: %s )", GetName(playerid),punkte,sGrund);
    SendClientMessage(pID, COLOR_LIGHTRED2, string);
    format(string, sizeof(string), "Du hast %d Punkte in der Akte von Spieler %s gelöscht. ( Grund: %s )", punkte,GetName(pID),sGrund);
    SendClientMessage(playerid, COLOR_LIGHTRED2, string);
    format(string, sizeof(string), "Polizeibeamter %s hat %d Punkte in der Akte von Spieler %s gelöscht. ( Grund: %s )", GetName(playerid), punkte,GetName(pID),sGrund);
    SendFraktionMessage(1, COLOR_LIGHTRED2, string);
    SendFraktionMessage(2, COLOR_LIGHTRED2, string);
    SendFraktionMessage(16, COLOR_LIGHTRED2, string);
    SendFraktionMessage(18, COLOR_LIGHTRED2, string);
    SendFraktionMessage(22, COLOR_LIGHTRED2, string);
    return 1;
}


CMD:m(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new msg[96], string[128];
	if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
    if(Spieler[playerid][pMuted] == 1) return SendClientMessage(playerid, COLOR_WHITE, "{AFAFAF}Du bist gemutet.");
	if(Spieler[playerid][bMundbinde]){
		SendClientMessage(playerid, COLOR_WHITE, "{AFAFAF}Du hast eine Mundbinde.");
		return 0;
	}

    if(!IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_WHITE, "{AFAFAF}Du bist in keinem Fahrzeug!");

	if(sscanf(params, "s[96]", msg))return SendClientMessage(playerid, COLOR_WHITE, "{247BA6}* Benutze: {00CC00}(/m)egaphone [Nachricht]");
	format(string, sizeof(string), "{FFFF00}[ %s %s: >> %s << ]", GetRankName(Spieler[playerid][pFraktion], Spieler[playerid][pRank]), GetName(playerid), msg);
	RoundMessage(playerid, COLOR_WHITE, string, 75.0);
	return 1;
}


CMD:setsteuern(playerid, params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new steuern, string[128];
    if(sscanf(params, "i", steuern))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Setsteuern [Steuern]");
    if(Spieler[playerid][pFraktion] == 9) {
        if(Spieler[playerid][pRank] > 4) {
            if(steuern < 0 || steuern > 50)return SendClientMessage(playerid, COLOR_RED, "Die Steuern sollten zwischen 0 Prozent und 50 Prozent liegen.");
            gSteuern = steuern;
            format(string, sizeof(string), COLOR_HEX_ORANGE"[STAATS-NACHRICHT] "COLOR_HEX_WHITE"Regierungsbeamter %s hat die Steuern auf {FF0000}%d Prozent{FFFFFF} gesetzt!", GetName(playerid), steuern);
            SendClientMessageToAll(COLOR_WHITE, string);
        } else {
            return SendClientMessage(playerid, COLOR_RED, "Dein Fraktionsrang reicht für diese Aktion nicht aus.");
        }
    } else {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Regierungsbeamter.");
    }
    return 1;
}



CMD:smsg(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new text[126], string[128];
    if(sscanf(params, "s[96]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Smsg [Nachricht]");
    if(Spieler[playerid][pFraktion] == 9) {
        if(Spieler[playerid][pRank] >= 5) {
            format(string, sizeof(string), COLOR_HEX_ORANGE"[REGIERUNG] %s %s: "COLOR_HEX_WHITE"%s", GetRankName(Spieler[playerid][pFraktion], Spieler[playerid][pRank]), GetName(playerid), text);
            SendClientMessageToAll(COLOR_WHITE, string);
        } else {
            return SendClientMessage(playerid, COLOR_RED, "Du bist kein Bürgermeister bzw. Präsident.");
        }
    } else {
        return SendClientMessage(playerid, COLOR_RED, "Du gehörst nicht dem Staat an.");
    }
    return 1;
}


CMD:rausziehen(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Rausziehen [SpielerID/Name]");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst dich selber nicht rausziehen.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(!IsPlayerInAnyVehicle(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in keinem Fahrzeug.");
    new vID= GetPlayerVehicleID(pID);
    new Float:x, Float:y, Float:z;
    GetVehiclePos(vID, x,y,z);
    if(IsPlayerInRangeOfPoint(playerid, 5.0, x,y,z))
    {
        UnfreezePlayer(pID);
        RemovePlayerFromVehicle(pID);
        format(string, sizeof(string), "Du wurdest von Polizeibeamter %s aus dem Fahrzeug gezogen.", GetName(playerid));
        SendClientMessage(pID, COLOR_LIGHTRED2, string);
        format(string, sizeof(string), "Du hast Spieler %s aus dem Fahrzeug gezogen.", GetName(pID));
        SendClientMessage(playerid, COLOR_LIGHTRED2, string);
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Fahrzeugs.");
        return 1;
    }
    return 1;
}

CMD:reinziehen(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Reinziehen [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst dich selbst nicht ins Fahrzeug reinziehen.");
    if(Spieler[pID][pAdminDienst]) return SCMFormatted(playerid,COLOR_RED,"%s ist im Admindienst.",GetName(pID));
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(!IsPlayerInRangeOfPoint(pID, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    if(!IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug.");
    if(IsPlayerInAnyVehicle(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem anderen Fahrzeug.");
    PutPlayerInVehicle(pID, GetPlayerVehicleID(playerid), 1);
    format(string, sizeof(string), "* %s hat %s in sein Fahrzeug gezogen.", GetName(playerid), GetName(pID));
    for(new i = 0 ; i < MAX_PLAYERS ; i++)
    {
        if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z))
        {
            SendClientMessage(i, COLOR_LIGHTRED2, string);
        }
    }
    return 1;
}


CMD:freilassen(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Freilassen [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Tazered[pID]) return SendClientMessage(playerid,COLOR_RED,"Die Person ist getazert.");
    if(playerid == pID) return SendClientMessage(playerid,COLOR_RED,"Du kannst dich nicht selbst freilassen.");
    if(Cuffed[pID] == 0) return SCMFormatted(playerid,COLOR_RED,"%s ist nicht gefesselt.",GetName(pID));
    if( IsPlayerAttachedObjectSlotUsed(pID,ATTACHED_INDEX_HANDSCHELLE) ) return SCMFormatted(playerid,COLOR_RED,"%s wurde verhaftet. Nutze: /verhaften.",GetName(pID));
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(!IsPlayerInRangeOfPoint(pID, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    UnfreezePlayer(pID);
    Cuffed[pID] = 0;
    ResetAugenbinde(pID);
    Spieler[pID][bMundbinde] = false;
    format(string, sizeof(string), "* Polizeibeamter %s hat %s entfesselt.", GetName(playerid), GetName(pID));
    for(new i = 0 ; i < MAX_PLAYERS ; i++)
    {
        if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z))
        {
            SendClientMessage(i, COLOR_LIGHTRED2, string);
        }
    }
    return 1;
}


CMD:gesuchte(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new count = 0;
    if (Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 22 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 18) {
        SendClientMessage(playerid, COLOR_YELLOW, "|____ Gesuchte Spieler ____|");
        foreach(new i : Player) {
            if (IsPlayerConnected(i)) {
                if (Spieler[i][pWanteds] != 0) {
                    new giveplayer[MAX_PLAYER_NAME], string[128];
                    GetPlayerName(i, giveplayer, sizeof(giveplayer));
                    if (Spieler[i][pWanteds] == 1) {
                        if (Spieler[i][bMaske]) {
                            format(string, sizeof(string), "<Unbekannt> [ID: N/A]: %d Wanted", Spieler[i][pWanteds]);
                        } else {
                            format(string, sizeof(string), "%s [ID: %d]: %d Wanted", giveplayer, i, Spieler[i][pWanteds]);
                        }
                    } else {
                        if (Spieler[i][bMaske]) {
                            format(string, sizeof(string), "<Unbekannt> [ID: N/A]: %d Wanteds", Spieler[i][pWanteds]);
                        } else {
                            format(string, sizeof(string), "%s [ID: %d]: %d Wanteds", giveplayer, i, Spieler[i][pWanteds]);
                        }
                    }
                    SendClientMessage(playerid, COLOR_YELLOW, string);
                    count++;
                }
            }
        }
        if (count == 0) return SendClientMessage(playerid, COLOR_RED, "Es wird niemand gesucht!");
    } else {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Cop!");
    }
    return 1;
}


CMD:gefangene(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new count = 0;
    new bool:bPlayerExecutive = (Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22);
    if (bPlayerExecutive || Spieler[playerid][pJob] == 6 || Spieler[playerid][pFraktion] == 17) {
        SendClientMessage(playerid, COLOR_YELLOW, "|____ Inhaftierte Spieler ____|");
        foreach(new i : Player) {
            if (!IsPlayerConnected(i))
                continue;

            if (Spieler[i][pJailed] == 1 && (Spieler[playerid][pJob] == 6 || bPlayerExecutive) || Spieler[i][pJailed] == 2 && (bPlayerExecutive || Spieler[playerid][pFraktion] == 17) || Spieler[i][pJailed] == 4 && bPlayerExecutive) {
                new giveplayer[MAX_PLAYER_NAME], string[144], jailTypeString[128];
                GetPlayerName(i, giveplayer, sizeof(giveplayer));
                format(jailTypeString, sizeof(jailTypeString), "%s", Spieler[i][pJailed] == 1 ? "Knast" : (Spieler[i][pJailed] == 4 ? "Gangjail" : "Alcatraz"));
                new playerJailTimeout = JAIL_TIMEOUT - (gettime() - GetPVarInt(i, "JAIL.TIMESTAMP"));
                if (playerJailTimeout > 0) {
                    if (playerJailTimeout == 1) format(jailTypeString, sizeof(jailTypeString), "%s - eine Sekunde Wartezeit", jailTypeString);
                    else format(jailTypeString, sizeof(jailTypeString), "%s - %d Sekunden Wartezeit", jailTypeString, playerJailTimeout);
                }

                format(string, sizeof(string), "%s [ID: %d]: %d Sekunden [%s]", giveplayer, i, Spieler[i][pJailTime], jailTypeString);
                SendClientMessage(playerid, COLOR_YELLOW, string);
                count++;
            }
        }
        if (count == 0) return SendClientMessage(playerid, COLOR_RED, "Es ist niemand inhaftiert!");
    } else {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Exekutivbeamter oder Anwalt!");
    }
    return 1;
}


CMD:finden(playerid, params[])
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Finden [SpielerID/Name]");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( Spieler[pID][pHandyState] == 0 ) {
        return SendClientMessage(playerid,COLOR_RED,"Das Handy der gesuchten Person ist aus. Die Ortung ist daher nicht möglich!");
    }

    if( Spieler[pID][pAdminDienst] || bIsSpectating[pID]) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler kann nicht geortet werden.");
    }
    new Float:x, Float:y, Float:z, zoneText[MAX_ZONE_NAME];
    GetPlayerPos(pID, x,y,z);
    SetPlayerCheckpointEx(playerid, x,y,z, 1.0, CP_FINDEN);
    GetPlayer2DZone(pID, zoneText, sizeof(zoneText));
    format(string, sizeof(string), "* %s wurde in %s gesichtet und auf der Karte Rot markiert, Gebäude-Komplex: %d", GetName(pID), zoneText, GetPlayerInterior(pID));
    SendClientMessage(playerid, COLOR_RED, string);
    return 1;
}

/*
CMD:waffenspind(playerid,params[]) {

		return cmd_waffenspint(playerid, params);
}

CMD:waffenspint(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    for (new i; i < MAX_FACTIONS; i++) 
    {
        if (IsPlayerInRangeOfPoint(playerid, 3.0, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ]))
        {
            if( !IsBeamter(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Beamter!");
            ShowPlayerDialog(playerid,DIALOG_WLAGERCOP,DIALOG_STYLE_LIST,"Waffenspind","Deagle - Schuss: 100\nM4 - Schuss: 150\nShotgun - Schuss: 200\nSniper - Schuss: 200\nRauchbombe - Anzahl: 10\nKamera - Anzahl: 30\nFallschirm","Annehmen","Abbruch");
        }
    }
    return 1;
}*/


CMD:w(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid;
    if( !IsPlayerExecutive(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    if(sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/W [ID/Name]");
    if( !IsPlayerConnected(giveid)) return SendClientMessage(playerid,COLOR_RED,"Der Spieler wurde nicht gefunden");
    if( 1 <= Spieler[giveid][pJailed] <= 3 ) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinem inhaftierten Wanteds geben!");
    if(Spieler[giveid][pAdminDienst]) return SCMFormatted(playerid,COLOR_RED,"%s ist im Admindienst",GetName(giveid));
    if(Spieler[giveid][pFraktion] == 1 || Spieler[giveid][pFraktion] == 2 || Spieler[giveid][pFraktion] == 16 || Spieler[giveid][pFraktion] == 18 || Spieler[giveid][pFraktion] == 22 )return SendClientMessage(playerid, COLOR_RED, "Du kannst Polizeibeamten keine Wanteds geben!");
    SelectedPlayer[playerid] = giveid;
    new string1[256];
    new string2[256];
    new string3[256];
    new string4[256];
    new string5[1024];
    format(string1, sizeof(string1), "Beschuss auf Beamte\nBeschuss auf Zivilisten\nAngriff auf Beamte\nAngriff auf Zivilisten\nWiderstand gegen Beamte\nErweit.Widerstand gegen Beamte\nBeihilfe zur Flucht\n");
    format(string2, sizeof(string2), "Behinderung der Justiz\nStVO Verstoß\nÜberfall/Raub\nEntführung\nEinsperren ins GJ\nSachbeschädigung\nBeleidigung/Bedrohung\nVerkehrsunfallflucht\nFahren ohne Lizenz\n");
    format(string3, sizeof(string3), "Illeg. Eindringen ins Polizeisystem\nIlleg. Waffen/Drogen/Waffenteile/Codes/Samen/Pakete\nFahrzeugdiebstahl\nDiebstahl eines Dienstfahrzeuges\nSach-Diebstahl\nBeamten-/Zivilisten Mord\n");
    format(string4, sizeof(string4), "Illeg. Straßenrennen\nNotruf-Missbrauch\nEinbruch in fremde Grundstücke\nAnschlag\nBestechungsversuch\nIlleg. züchten von Spicepflanzen\nBrandstiftung\nGefangenenbefreiung\nGefängnisausbruch");
    format(string5, sizeof(string5), "%s%s%s%s", string1, string2, string3, string4);
    ShowPlayerDialog(playerid, DIALOG_TABMENU_VK, DIALOG_STYLE_LIST, "Verbrecherkatalog", string5, "Auswählen", "Abbrechen");
    return 1;
}


CMD:promille(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new
        giveid;
    if(sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Promille [Spieler]");
    }
    if( !IsPlayerConnected(giveid) ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    }
    if( !(( Spieler[playerid][pFraktion] == 1) || ( Spieler[playerid][pFraktion] == 2) || ( Spieler[playerid][pFraktion] == 5) || ( Spieler[playerid][pFraktion] == 16 ) || ( Spieler[playerid][pFraktion] == 22 )) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Exekutivbeamter.");
    }

    if (!IsPlayerInRangeOfPlayer(playerid, giveid, 5.0)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");

    new String[128];
    if( pDrogenEinfluss[playerid] == 1 ) {
        format(String,sizeof(String),"Spieler %s steht unter Drogen Einfluss.",GetName(giveid));
        SendClientMessage(playerid,COLOR_YELLOW,String);
    }
    else if( GetPlayerDrunkLevel(giveid) >= 2000 ) {
        format(String,sizeof(String),"Spieler %s steht unter Alkohol Einfluss.",GetName(giveid));
        SendClientMessage(playerid,COLOR_YELLOW,String);
    }
    else {
        format(String,sizeof(String),"Spieler %s steht nicht unter Alkohol- noch Drogeneinfluss",GetName(giveid));
        SendClientMessage(playerid,COLOR_YELLOW,String);
    }

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid,x,y,z);
    format(String,sizeof(String),"Beamter %s prüft den Alkohol-Drogeneinfluss von %s",GetName(playerid),GetName(giveid));
    SendRoundMessage(x,y,z, COLOR_PURPLE, String);
    return 1;
}


CMD:sendfs(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new
        giveid;
    if( sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Sendfs [Spieler]");
    }
    if(!IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    }
    if( !IsFriendSlotFree(playerid) ) {
        return SendClientMessage(playerid,COLOR_RED, "Du hast keinen Platz für weitere Freunde in deiner List!");
    }
    if( !IsFriendSlotFree(giveid) ) {
        return SendClientMessage(playerid,COLOR_RED, "Der Spieler hat keinen Platz für weitere Freunde in seiner List!");
    }
    if( IsPlayerOnFriendList(playerid,giveid,FriendList_Wait) ) {
        return SendClientMessage(playerid,COLOR_RED, "Du hast diesem Spieler bereits eine Anfrage gesendet!");
    }
    if( IsPlayerOnFriendList(playerid,giveid,FriendList_Active) ) {
        return SendClientMessage(playerid,COLOR_RED, "Der Spieler ist bereits auf deiner Freundesliste!");
    }
    if( IsPlayerOnFriendList(playerid,giveid,FriendList_Approval) ) {
        return cmd_acceptfs(playerid,GetName(giveid));
    }
    new
        String[128],
        flslot = GetFreeFriendSlot(playerid);
    format( g_FriendList[playerid][flslot][FL_sSpieler] , MAX_PLAYER_NAME , "%s", GetName(giveid) );
    g_FriendList[playerid][flslot][FL_iStatus] = FriendList_Wait;
    flslot = GetFreeFriendSlot(giveid);
    format( g_FriendList[giveid][flslot][FL_sSpieler] , MAX_PLAYER_NAME , "%s", GetName(playerid) );
    g_FriendList[giveid][flslot][FL_iStatus] = FriendList_Approval;
    format(String,sizeof(String),"[FS] %s hat dir eine Freundschaftsanfrage gesendet! Mit /Acceptfs akzeptierst du die Anfrage.",GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    format(String,sizeof(String),"Du hast %s eine Freundschaftsanfrage gesendet!",GetName(giveid));
    SendClientMessage(playerid,COLOR_GREEN,String);
    return 1;
}

CMD:acceptfs(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new
        giveid;
    if( sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Acceptfs [Spieler]");
    }
    if(!IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    }
    if( IsPlayerOnFriendList(playerid,giveid) ) {
        return SendClientMessage(playerid,COLOR_RED, "Dieser Spieler ist bereits auf deiner Freundesliste!");
    }
    if( !IsPlayerOnFriendList(playerid,giveid,FriendList_Approval) ) {
        return SendClientMessage(playerid,COLOR_RED, "Von diesem Spieler liegt keine Freundschaftanfrage vor!");
    }
    new
        String[128],
        index;
    index = GetPlayerFriendSlot(playerid,giveid);
    g_FriendList[playerid][index][FL_iStatus] = FriendList_Active;
    index = GetPlayerFriendSlot(giveid,playerid);
    g_FriendList[giveid][index][FL_iStatus] = FriendList_Active;
    format(String,sizeof(String),"[FS] %s hat deine Freundschaftsanfrage akzeptiert!",GetName(playerid));
    SendClientMessage(giveid,COLOR_GREEN,String);
    format(String,sizeof(String),"Du hast die Freundschaftsanfrage von %s akzeptiert!",GetName(giveid));
    SendClientMessage(playerid,COLOR_GREEN,String);

    format(String,sizeof(String),"INSERT INTO `friendlist` VALUES (NULL, '%s', '%s');",GetName(giveid),GetName(playerid));
    mysql_pquery( String ,THREAD_ADDFRIENDLIST,playerid,gSQL,MySQLThreadOwner);

    format(String,sizeof(String),"INSERT INTO `friendlist` VALUES (NULL, '%s', '%s');",GetName(playerid),GetName(giveid));
    mysql_pquery( String ,THREAD_ADDFRIENDLIST,playerid,gSQL,MySQLThreadOwner);

    return 1;
}

CMD:delfs(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new
        idx,
        giveid,
        name[MAX_PLAYER_NAME];
    if( sscanf(params,"s[24]",name)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Delfs [Spieler]");
    }
    if( !IsNameOnFriendList(playerid,name,idx) ) {
        return SendClientMessage(playerid,COLOR_RED, "Der Name befindet sich nicht auf deiner Freundschaftsliste!");
    }
    new
        String[256];
    sscanf(name,"u",giveid);
    g_FriendList[playerid][idx][FL_iStatus] = 0;
    g_FriendList[playerid][idx][FL_sSpieler] = '\0';
    if( IsPlayerConnected(giveid) ) {
        if( IsNameOnFriendList(giveid,GetName(playerid),idx) ) {
            /*
            if( g_FriendList[giveid][idx][FL_iStatus] == FriendList_Approval) {
                format(String,sizeof(String),"%s hat deine Freundschaftsanfrage abgelehnt",name);
                SendClientMessage(giveid,COLOR_YELLOW,String);
            }
            else {
                format(String,sizeof(String),"%s hat dich aus seiner Freundschaftsliste entfernt!",name);
                SendClientMessage(giveid,COLOR_YELLOW,String);
            }
            */
            format(String,sizeof(String),"[FS] %s hat dich aus seiner Freundschaftsliste entfernt!", GetName(playerid) );
            SendClientMessage(giveid,COLOR_ORANGE,String);

            g_FriendList[giveid][idx][FL_iStatus] = 0;
            g_FriendList[giveid][idx][FL_sSpieler] = '\0';
        }
    }
    format(String,sizeof(String),"Du hast %s aus deiner Freundschaft entfernt!",name);
    SendClientMessage(playerid,COLOR_ORANGE,String);


    mysql_real_escape_string(name,name);
    format(String,sizeof(String),"DELETE FROM `friendlist` WHERE `Spieler` IN('%s','%s') AND `SpielerEx` IN('%s','%s')",GetName(playerid),name,GetName(playerid),name);
    mysql_pquery( String ,THREAD_DELFRIENDLIST,playerid,gSQL,MySQLThreadOwner);

    return 1;
}


CMD:fsliste(playerid)
{
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid, dialogText[600];
    for (new i; i < MAX_FRIEND_LIST; i++) {
        if (isnull(g_FriendList[playerid][i][FL_sSpieler])) continue;

        format(dialogText, sizeof(dialogText), "%s{FFFFFF}%s", dialogText, g_FriendList[playerid][i][FL_sSpieler]);
        if (g_FriendList[playerid][i][FL_iStatus] == FriendList_Approval) strcat(dialogText, " (wartet auf Bestätigung)", sizeof(dialogText));
        else if (g_FriendList[playerid][i][FL_iStatus] == FriendList_Wait) strcat(dialogText, " (muss bestätigen)", sizeof(dialogText));

        sscanf(g_FriendList[playerid][i][FL_sSpieler], "k<playername>", giveid);
        if (giveid == INVALID_PLAYER_ID) format(dialogText, sizeof(dialogText), "%s\t{FF0000}Offline\n", dialogText);
        else format(dialogText, sizeof(dialogText), "%s\t{00FF00}Online\n", dialogText);
    }

    if (isnull(dialogText)) format(dialogText, sizeof(dialogText), "{FFFFFF}Du hast noch keine Spieler auf deiner Freundesliste.");
    ShowPlayerDialog(playerid, DIALOG_FSLISTE, DIALOG_STYLE_TABLIST, "{FF0080}Freundesliste", dialogText, "Schließen", "");
    return 1;
}

CMD:fschat(playerid,params[]) {
    new giveid,text[128];
    if(sscanf(params,"us[128]",giveid,text)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Fschat [Spieler] [Nachricht]");
    if( !IsPlayerOnFriendList(playerid,giveid) ) return SendClientMessage(playerid,COLOR_RED, "Der Spieler ist noch nicht auf deiner Freundschaftsliste.");
    if(Spieler[playerid][pPrisonRun] > 0 ) return SendClientMessage(playerid, COLOR_RED, "Du kannst niemandem schreiben, wenn du im Straflauf bist!");
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    new
        String[256];
    format(String,sizeof(String),"[FS-CHAT] %s sagt: %s",GetName(playerid),text);
    SendClientMessage(giveid,COLOR_PINK,String);
    format(String,sizeof(String),"[FS-CHAT] >> %s: %s",GetName(giveid),text);
    SendClientMessage(playerid,COLOR_PINK,String);

    format(String,sizeof(String),"%s an %s: %s",GetName(playerid),GetName(giveid),text);
    FriendLog(String);
    return 1;
}


CMD:stelekom(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if( Spieler[playerid][pFraktion] != 9 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du bist nicht Mitglied der Regierungsmitglied");
    }
    if( Spieler[playerid][pRank] < 4 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst mindestens den Rang 4 haben in der Regierungsfraktion");
    }
    if( bBlockTelecom ) {
        SendClientMessageToAll(COLOR_ORANGE,"_________________________| SAN ANDREAS - STAAT |_________________________|");
        SendClientMessageToAll(COLOR_GREEN,"Die komplette Telekommunikation wurde vom Staat wieder freigegeben!");
        bBlockTelecom = false;
    }
    else {
        SendClientMessageToAll(COLOR_ORANGE,"_________________________| SAN ANDREAS - STAAT |_________________________|");
        SendClientMessageToAll(COLOR_RED,"Die komplette Telekommunikation wurde vom Staat aufgrund einer Notsituation vorübergehend abgeschaltet!");
        bBlockTelecom = true;
    }
    return 1;
}


CMD:staatssystem(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new giveid, job[50], frak[50], String[128];
    if( !(( Spieler[playerid][pFraktion] == 9) || ( Spieler[playerid][pFraktion] == 2)) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Regierungsbeamter!");
    if(sscanf(params, "u", giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Staatssystem [Spieler]");
    if( !IsPlayerConnected(giveid) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( playerid == giveid ) return SendClientMessage(playerid, COLOR_RED, "Du kannst deine eigene Staatsakte nicht einsehen.");
    SendClientMessage(playerid,COLOR_RED,"=========STAATSSYSTEM=========");
    format(String,sizeof(String),"Akte von Bürger: "#COLOR_HEX_ORANGE"%s",GetName(giveid));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Begangene Verbrechen: "#COLOR_HEX_ORANGE"%d",Spieler[giveid][pCrimes]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Begangene Morde: "#COLOR_HEX_ORANGE"%d",Spieler[giveid][pKills]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Wanted-Level: "#COLOR_HEX_ORANGE"%d",Spieler[giveid][pWanteds]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"KFZ-Steuern: "#COLOR_HEX_ORANGE"%d",Spieler[giveid][pKFZSteuer]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Bargeld: $%s", AddDelimiters(CheckMoney(giveid)));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Kontostand: $%s", AddDelimiters(Spieler[giveid][pBank]));
    SendClientMessage(playerid,COLOR_WHITE,String);
    ReturnPlayerJob(giveid,job);
    format(String,sizeof(String),"Beruf: %s",job);
    SendClientMessage(playerid,COLOR_WHITE,String);
    ReturnPlayerFraktion(giveid,frak);
    format(String,sizeof(String),"Fraktion: %s",frak);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Gehalt: $%s", AddDelimiters(Spieler[giveid][pFrakLohn]));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Staatsbürger: %s", Spieler[giveid][pStaat] );
    SendClientMessage(playerid,COLOR_WHITE,String);

    format(String,sizeof(String),"schaut die Staats-Akte von %s an",GetName(giveid));
    return cmd_me(playerid,String);
}


CMD:jobfeuern(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(Spieler[playerid][pFraktion] != 9 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Regierung");
    }
    new
        giveid;
    if(sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Jobfeuern [Spieler]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht Online.");
    }
    if(playerid == giveid) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst dich selber nicht feuern");
    }
    if( Spieler[giveid][pJob] == 0 ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keinen Job");
    }
    new
        job[50],
        String[128];

    ReturnPlayerJob(giveid,job);
    format(String,sizeof(String),"Staatsbeamter %s hat dich aus deinem Beruf '%s' fristlos gekündigt!",GetName(playerid),job);
    SendClientMessage(giveid,COLOR_RED,String);

    format(String,sizeof(String),"Du hast %s seinen %s Job gekündigt",GetName(giveid),job);
    SendClientMessage(playerid,COLOR_YELLOW,String);

    Spieler[giveid][pJob] = 0;
    return 1;
}


CMD:kfzsteuern(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(Spieler[playerid][pFraktion] != 9 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitarbeiter der Regierung");
    }
    new
        giveid,
        betrag;
    if(sscanf(params,"ud",giveid,betrag)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Kfzsteuern [Spieler] [Betrag]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht Online.");
    }
    if( betrag < 0 ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Betrag kann nicht negativ sein");
    }
    new
        String[128];
    format(String,sizeof(String),"[STEUERN] Staatsbeamter %s hat deine KFZ-Steuer auf folgenden Betrag geändert: $%s",GetName(playerid), AddDelimiters(betrag));
    SendClientMessage(giveid,COLOR_ORANGE,String);

    format(String,sizeof(String),"Die KFZ-Steuer von %s wurde auf folgenden Betrag geändert: $%s",GetName(giveid), AddDelimiters(betrag));
    SendClientMessage(playerid,COLOR_GREEN,String);

    Spieler[giveid][pKFZSteuer] = betrag;
    return 1;
}

CMD:amtssteuern(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(Spieler[playerid][pFraktion] != 9 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitarbeiter der Regierung");
    }
    new
        giveid,
        betrag;
    if(sscanf(params,"ud",giveid,betrag)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Amtssteuern [Spieler] [Betrag]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht Online.");
    }
    if( betrag < 0 ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Betrag kann nicht negativ sein");
    }
    new
        String[128];
    format(String,sizeof(String),"[STEUERN] Staatsbeamter %s hat deine Steuer auf folgenden Betrag geändert: $%s",GetName(playerid), AddDelimiters(betrag));
    SendClientMessage(giveid,COLOR_ORANGE,String);

    format(String,sizeof(String),"Die Steuer von %s wurde auf folgenden Betrag geändert: $%s",GetName(giveid), AddDelimiters(betrag));
    SendClientMessage(playerid,COLOR_GREEN,String);

    Spieler[giveid][pSSteuer] = betrag;
    return 1;
}


CMD:staatmelden(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new
        giveid,
        staat[30];
    if(Spieler[playerid][pFraktion] != 9 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Regierungsbeamter!");
    }
    if(sscanf(params,"us[30]",giveid,staat)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Staatmelden [ID/Name] [Staat]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid,COLOR_RED,"Der Spieler wurde nicht gefunden");
    }
    new
        String[128];
    Spieler[giveid][pStaat] = '\0';
    format(Spieler[giveid][pStaat],30,"%s",staat);
    format(String,sizeof(String),"Staatsbeamter %s hat dir folgende Staatsangehörigkeit zugeordnet: %s",GetName(playerid),staat);
    SendClientMessage(giveid,COLOR_YELLOW,String);
    return 1;
}



CMD:zollsperre(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new
        sModus[8];
    if ((!IsPlayerExecutive(playerid) || Spieler[playerid][pRank] < 2) && Spieler[playerid][pAdmin] < 3) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist oder bist nicht höher als Rang 2!");
    }
    if(sscanf(params,"s[8]",sModus)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Zollsperre [On/Off]");
    if(!strcmp(sModus,"On", true)) {
        if( g_Zoll[0][Z_bSperre] == true ) {
            return SendClientMessage(playerid,COLOR_RED,"Zollsperre bereits aktiv!");
        }
        for(new i ; i < sizeof(g_Zoll) ; i++) {
            g_Zoll[i][Z_bSperre] = true;
        }
        SendClientMessageToAll(COLOR_RED,"[STAAT] "#COL_ORANGE"Alle Zollstationen wurden vorübergehend aufgrund einer polizeilichen Maßnahme gesperrt!");
        if (tTollTimer != INVALID_TIMER_ID) KillTimer(tTollTimer);
        tTollTimer = SetTimer("OpenTollStations", 5 * 60 * 1000, false);
    }
    else if(!strcmp(sModus,"Off", true)) {
        if( g_Zoll[0][Z_bSperre] == false ) {
            return SendClientMessage(playerid,COLOR_RED,"Keine Zollsperre aktiv!");
        }
        for(new i ; i < sizeof(g_Zoll) ; i++) {
            g_Zoll[i][Z_bSperre] = false;
        }
        SendClientMessageToAll(COLOR_RED,"[STAAT] "#COL_GREEN"Alle Zollstationen wurden wieder geöffnet! Die polizeiliche Maßnahme wurde beendet.");
        if (tTollTimer != INVALID_TIMER_ID) KillTimer(tTollTimer);
    }
    else {
        return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Zollsperre [On/Off]");
    }
    return 1;
}

CMD:zollamt(playerid,params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    new
        zoll;
    zoll = GetPlayerZollArea(playerid);
    if( zoll == -1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du befindest dich an keiner Zoll-Station");
    }
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2  || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 4  || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 9 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18) ) {
        return SendClientMessage(playerid,COLOR_RED,"Dieser Befehl ist nur für Staatsbehörden");
    }
    if( !Zoll_Open(zoll,playerid) ) {
        return SendClientMessage(playerid,COLOR_RED,"Zollwächter: Die Bearbeitung eines anderen Fahrer findet noch statt");
    }
    SendClientMessage(playerid,COLOR_YELLOW,"Zollwächter: Vielen Dank! Sie dürfen den Zoll überqueren. Gute Weiterfahrt!");
    return 1;
}



CMD:pdgate(playerid, params[]) {
	if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Befehl ausführen wenn du tot bist.");
    if (PlayerIsPaintballing[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Befehl in Paintball nicht ausführen.");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 9 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22 || Spieler[playerid][pAdmin] >= 2))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist!");
    new Float:fX, Float:fY, Float:fZ;
    GetDynamicObjectPos(TOR_LSPD[0], fX, fY, fZ);
    if(IsPlayerInRangeOfPoint(playerid,20.0, 1544.45618, -1622.11987, 12.93280))
    {
        if(SERVER_GATE[0] == 0)
        {
            SERVER_GATE[0] = 1; MoveDynamicObject(TOR_LSPD[0],1544.45618, -1622.11987, LSPD_GATE_OPEN_Z,4.0);
        }
        else
        {
            SERVER_GATE[0] = 0; MoveDynamicObject(TOR_LSPD[0],1544.45618, -1622.11987, LSPD_GATE_CLOSED_Z,4.0);
        }
    }
    GetDynamicObjectPos(TOR_LSPD[1], fX, fY, fZ);
    if(IsPlayerInRangeOfPoint(playerid,20.0, 1596.02783, -1638.10132, 14.59349))
    {
        if(SERVER_GATE[1] == 0)
        {
            SERVER_GATE[1] = 1; MoveDynamicObject(TOR_LSPD[1],1596.02783, -1638.10132, LSPD_GATE2_OPEN_Z,4.0, 0.0000, 0.0000, 0.0000);
        }
        else
        {
            SERVER_GATE[1] = 0; MoveDynamicObject(TOR_LSPD[1],1596.02783, -1638.10132, LSPD_GATE2_CLOSED_Z,4.0, 0.0000, 0.0000, 0.0000);
        }
    }

    return 1;
}
