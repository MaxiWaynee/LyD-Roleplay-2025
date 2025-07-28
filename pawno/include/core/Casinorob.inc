#include <YSI\y_hooks>

#define CASINOROB_COORDS_TRESOR             1494.2532,-1521.8376,1001.0000
#define CASINOROB_COORDS_EINGANG            1515.4930,-1518.5248,1001.0000
#define CASINOROB_COORDS_EINGANG_FACE       90.0
#define CASINOROB_COORDS_DOOR               1512.7344,-1513.0126,1001.0000
#define CASINOROB_COORDS_DOOR2              1501.8773,-1521.8826,1001.0000
#define CASINOROB_COORDS_HINTERAUSGANG      1486.6844,-1523.8231,1001.0000
#define CASINOROB_COORDS_HINTERTÜR          1488.7295,-1521.8787,1001.0000
#define CASINOROB_COORDS_HINTEREINGANG      1516.9272,-1505.5941,13.5547
#define CASINOROB_COORDS_ENTER              1143.3438,6.2615,1000.6797
#define CASINOROB_COORDS_TISCH1             1492.6506,-1516.2598,1001.0000
#define CASINOROB_COORDS_TISCH2             1493.5178,-1512.7888,1001.0000
#define CASINOROB_COORDS_TISCH3             1496.7543,-1512.2200,1001.0000

new AlarmanlageTimer;
new CasinoRobStatus = Bankraub_Bereit;
new CasinoRob[MAX_PLAYERS];
new CasinoRob_Beute;
new CheckRaubTimer;
new CasinoRaubTimer;
new CasinoBereitTimer;
new CTAufbrechenTimer;
new CasinoMarkTimer;
new CTAufbrechenCheckTimer;
new CasinoRaubStopTimer;
new CasinoRobAusraubTimer;
new CasinoRobAusraubCheckTimer;
new CasinoTresorLeben = 20000;
new bool:CasinoAusrauben[3] = false;
new bool:CasinoRobBild = false;
new bool:CasinoRob_Tresor_Status = false;
new bool:CasinoHinten = false;
new Mark = 0;
new CasinoRob_Alarm = 0;
new Text3D:Label_Casino[7];



CMD:alarmanlage(playerid,params[]) {
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_DOOR) && !IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_DOOR2)) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Hier kannst du keine Alarmanlage deaktivieren.");
    if(GetOnlineExekutive(playerid) < 2) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Es sind nicht genügend Polizisten online.");
    if(GetRobPlayers() > 0) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Das Casino wird bereits ausgeraubt.");
	if(IsPlayerExecutive(playerid)) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Polizisten können das Casino nicht ausrauben");
    if(CasinoRobStatus  == Bankraub_Wartezeit ) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Das Casino kann zur Zeit nicht ausgeraubt werden.");
	if(g_aSettings[ASETTING_ROBBLOCK][ASETTING_TOGGLE]) return SendClientMessage(playerid, COLOR_YELLOW, "[Casino-Raub]{8E2E1B} Zurzeit ist die Überfallsperre aktiviert.");
    if(CasinoRob_Alarm == 1) return SendClientMessage(playerid,COLOR_YELLOW,"[CASINO-RAUB]{8E2E1B} Jemand anderes sabotiert bereits die Alarmanlage.");
    CasinoRob_Beute = 0;
    ShowPlayerDialog(playerid, DIALOG_CASINOROB_PANEL, DIALOG_STYLE_LIST, "Wähle einen Draht", "{FF0000}Rot\n{006F00}Grün\n{F8C500}Gelb\n{004A98}Blau\n", "Zwicken", "Abbrechen");
    CasinoRob_Alarm = 1;
    return 1;
}



CMD:bildabnehmen(playerid,params[]) {
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_TRESOR)) return SendClientMessage(playerid, COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Hier kannst du kein Bild abnehmen.");
    new string[128];
    if(GetRobPlayers() > 0 && CasinoRob[playerid]) {
        MoveDynamicObject(CASINOROB_BILD[0], 1496.415039, -1521.703369, 1001.329528, 1.5, -3.899998, -89.300010, -133.999984);
        CasinoRob_Beute += RandomEx(25000,100000);
        CasinoRobBild = true;
        format(string, sizeof(string), "{FFFFFF}- Casino Tresor -\n\n{CB2720}Verschlossen\nHP: %i", CasinoTresorLeben);
        UpdateDynamic3DTextLabelText(Label_Casino[0], COLOR_WHITE, string);
    }
    return 1;
}



CMD:ausrauben(playerid,params[]) {
    if(GetRobPlayers() > 0 && CasinoRob[playerid]) {
        if(!(IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_TISCH1) || IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_TISCH2) || IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_TISCH3)))
        return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Hier kannst du nichts ausrauben.");
        if(IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_TISCH1)) {
            if(CasinoAusrauben[0] == true) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Der Tisch wird bereits ausgeraubt.");
            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{2D7D00} Du raubst den Tisch aus, bleib in der Nähe.");
            CasinoAusrauben[0] = true;
            CasinoRobAusraubCheckTimer = SetTimerEx("Check_CasinoRaub_Ausrauben", 1000, false, "dd",playerid,1);
            CasinoRobAusraubTimer = SetTimerEx("CasinoRaub_Ausrauben", 60000, false, "dd",playerid,1);
        } else if(IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_TISCH2)) {
            if(CasinoAusrauben[1] == true) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Der Tisch wird bereits ausgeraubt.");
            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{2D7D00} Du raubst den Tisch aus, bleib in der Nähe.");
            CasinoAusrauben[1] = true;
            CasinoRobAusraubCheckTimer = SetTimerEx("Check_CasinoRaub_Ausrauben", 1000, false, "dd",playerid,2);
            CasinoRobAusraubTimer = SetTimerEx("CasinoRaub_Ausrauben", 60000, false, "dd",playerid,2);
        } else if(IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_TISCH3)) {
            if(CasinoAusrauben[2] == true) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Der Tisch wird bereits ausgeraubt.");
            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{2D7D00} Du raubst den Tisch aus, bleib in der Nähe.");
            CasinoAusrauben[2] = true;
            CasinoRobAusraubCheckTimer = SetTimerEx("Check_CasinoRaub_Ausrauben", 1000, false, "dd",playerid,3);
            CasinoRobAusraubTimer = SetTimerEx("CasinoRaub_Ausrauben", 60000, false, "dd",playerid,3);
        }
    }
    return 1;
}



CMD:ctaufbrechen(playerid,params[]){
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_HINTERTÜR)) return SendClientMessage(playerid, COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Hier kannst du keine Tür aufbrechen.");
    if(CasinoRob_Tresor_Status == false) return SendClientMessage(playerid, COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du musst zu erst den Tresor zerstören.");
    if(GetRobPlayers() > 0 && CasinoRob[playerid]) {
        if(Spieler[playerid][pBrecheisen] < 1) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du benötigst ein Brecheisen");
        Spieler[playerid][pBrecheisen] -= 1;
        SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{FFFFFF} Du versuchst eine Sicherheitstür auf zu brechen, das kann 3 Minuten dauern.");
        CTAufbrechenTimer = SetTimerEx("CTAufbrechen", 180000, false, "d",playerid);
        CTAufbrechenCheckTimer = SetTimerEx("Check_CTAufbrechen", 2000, true, "d",playerid);
    }
    return 1;
}



hook OnGameModeInit() {
    Label_Casino[0] = CreateDynamic3DTextLabel("", COLOR_WHITE, 1494.256835, -1522.309814, 1001.687805 , 10.0, .testlos = 1, .worldid = VW_CASINOROB, .interiorid = CASINOROB_INTERIOR);
    Label_Casino[1] = CreateDynamic3DTextLabel("{F0CC1F}[Casino-Raub]\n{FFFFFF}Tippe /Alarmanlage", COLOR_WHITE, CASINOROB_COORDS_DOOR , 10.0, .testlos = 1, .worldid = VW_CASINOROB, .interiorid = CASINOROB_INTERIOR);
    Label_Casino[1] = CreateDynamic3DTextLabel("{F0CC1F}[Casino-Raub]\n{FFFFFF}Tippe /Alarmanlage", COLOR_WHITE, CASINOROB_COORDS_DOOR2 , 10.0, .testlos = 1, .worldid = VW_CASINOROB, .interiorid = CASINOROB_INTERIOR);
    Label_Casino[2] = CreateDynamic3DTextLabel("{F0CC1F}[Casino-Raub]\n{FFFFFF}Tippe /Bildabnehmen", COLOR_WHITE, CASINOROB_COORDS_TRESOR , 10.0, .testlos = 1, .worldid = VW_CASINOROB, .interiorid = CASINOROB_INTERIOR);
    Label_Casino[3] = CreateDynamic3DTextLabel("{F0CC1F}[Casino-Raub]\n{FFFFFF}Tippe /ctaufbrechen", COLOR_WHITE, CASINOROB_COORDS_HINTERTÜR , 10.0, .testlos = 1, .worldid = VW_CASINOROB, .interiorid = CASINOROB_INTERIOR);
    Label_Casino[4] = CreateDynamic3DTextLabel("{F0CC1F}[Casino-Raub]\n{FFFFFF}Tippe /ausrauben", COLOR_WHITE, CASINOROB_COORDS_TISCH1 , 10.0, .testlos = 1, .worldid = VW_CASINOROB, .interiorid = CASINOROB_INTERIOR);
    Label_Casino[5] = CreateDynamic3DTextLabel("{F0CC1F}[Casino-Raub]\n{FFFFFF}Tippe /ausrauben", COLOR_WHITE, CASINOROB_COORDS_TISCH2 , 10.0, .testlos = 1, .worldid = VW_CASINOROB, .interiorid = CASINOROB_INTERIOR);
    Label_Casino[6] = CreateDynamic3DTextLabel("{F0CC1F}[Casino-Raub]\n{FFFFFF}Tippe /ausrauben", COLOR_WHITE, CASINOROB_COORDS_TISCH3 , 10.0, .testlos = 1, .worldid = VW_CASINOROB, .interiorid = CASINOROB_INTERIOR);
    CreateDynamicPickup(19197, 1, CASINOROB_COORDS_ENTER, VW_CASINOINTERIOR, 12);
    return 1;
}



hook OnGameModeExit() {
    DestroyDynamic3DTextLabel(Label_Casino[0]);
    DestroyDynamic3DTextLabel(Label_Casino[1]);
    DestroyDynamic3DTextLabel(Label_Casino[2]);
    DestroyDynamic3DTextLabel(Label_Casino[3]);
    DestroyDynamic3DTextLabel(Label_Casino[4]);
    DestroyDynamic3DTextLabel(Label_Casino[5]);
    DestroyDynamic3DTextLabel(Label_Casino[6]);
    return 1;
}



hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(newkeys == KEY_SECONDARY_ATTACK) {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_ENTER)) {
            if(GetRobPlayers() && !IsPlayerExecutive(playerid)) return SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Das Casino wird gerade ausgeraubt.");
            SetPlayerPosEx(playerid,CASINOROB_COORDS_EINGANG,CASINOROB_INTERIOR,VW_CASINOROB);
            SetPlayerFacingAngle(playerid, CASINOROB_COORDS_EINGANG_FACE);
        } else if(IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_EINGANG)) {
            SetPlayerPosEx(playerid,CASINOROB_COORDS_ENTER,Biz[CasinoBiz_Index][bInterior],VW_CASINOINTERIOR);
            CasinoRob[playerid] = 0;
        } else if(IsPlayerInRangeOfPoint(playerid, 2.0, CASINOROB_COORDS_HINTERAUSGANG)) {
            SetPlayerPosEx(playerid,CASINOROB_COORDS_HINTEREINGANG,CASINOROB_INTERIOR,VW_MAIN);
            if(CasinoRob[playerid] && GetRobPlayers() && !IsPlayerExecutive(playerid) && CasinoHinten == false) {
                SendExecutiveMessage(COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Die Räuber haben das Casino über den Hintereingang verlassen, Ihr seht Sie 2 Minuten lang auf der Karte.");
                SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Ihr werdet der Polizei 2 Minuten lang auf der Karte angezeigt.");
                CasinoHinten = true;
                CasinoMarkTimer = SetTimerEx("Pulse_CasinoMark", 1000, false, "d",playerid);
                KillTimer(CasinoRaubTimer);
            }
        }
    }
    return 1;
}



hook OnPlayerSpawn(playerid) {
    CasinoRob[playerid] = 0;
    return 1;
}



hook OnPlayerTot(playerid) {
    CasinoRob[playerid] = 0;
    return 1;
}



hook OnPlayerDeath(playerid) {
    CasinoRob[playerid] = 0;
    return 1;
}



hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    switch(dialogid) {
        case DIALOG_CASINOROB_PANEL: {
            if(response) {
                new RandomDraht = RandomEx(0,4);
                switch(listitem) {
                    case 0: {
                        if(RandomDraht == 0) {
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{007433} Du hast den richtiges Draht durch getrennt und 2 Minuten Zeit gewonnen.");
                            MoveDynamicObject(CASINOROB_DOOR[0], 1512.1502, -1513.8281, 1000.0145, 3.0, 0.0, 0.0, -18.3000);
                            MoveDynamicObject(CASINOROB_DOOR[3], 1502.5474, -1521.4482, 999.9843, 3.0 ,0.0, 0.0, -9.0);
                            AlarmanlageTimer = SetTimerEx("Alarmanlage", 120000, false, "d",playerid);
                        } else {
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du hast den falschen Draht durch getrennt, die Polizei wurde informiert.");
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Zerstöre die Zugangskontrolle!");
                            AlarmanlageTimer = SetTimerEx("Alarmanlage", 500, false, "d",playerid);
                        }
                        CasinoRobStart(playerid);
                    }
                    case 1: {
                        if(RandomDraht == 1) {
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{007433} Du hast den richtiges Draht durch getrennt und 2 Minuten Zeit gewonnen.");
                            MoveDynamicObject(CASINOROB_DOOR[0], 1512.1502, -1513.8281, 1000.0145, 3.0, 0.0, 0.0, -18.3000);
                            MoveDynamicObject(CASINOROB_DOOR[3], 1502.5474, -1521.4482, 999.9843, 3.0 ,0.0, 0.0, -9.0);
                            AlarmanlageTimer = SetTimerEx("Alarmanlage", 120000, false, "d",playerid);
                        } else {
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du hast den falschen Draht durch getrennt, die Polizei wurde informiert.");
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Zerstöre die Zugangskontrolle!");
                            AlarmanlageTimer = SetTimerEx("Alarmanlage", 500, false, "d",playerid);
                        }
                        CasinoRobStart(playerid);
                    }
                    case 2: {
                        if(RandomDraht == 2) {
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{007433} Du hast den richtiges Draht durch getrennt und 2 Minuten Zeit gewonnen.");
                            MoveDynamicObject(CASINOROB_DOOR[0], 1512.1502, -1513.8281, 1000.0145, 3.0, 0.0, 0.0, -18.3000);
                            MoveDynamicObject(CASINOROB_DOOR[3], 1502.5474, -1521.4482, 999.9843, 3.0 ,0.0, 0.0, -9.0);
                            AlarmanlageTimer = SetTimerEx("Alarmanlage", 120000, false, "d",playerid);
                        } else {
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du hast den falschen Draht durch getrennt, die Polizei wurde informiert.");
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Zerstöre die Zugangskontrolle!");
                            AlarmanlageTimer = SetTimerEx("Alarmanlage", 500, false, "d",playerid);
                        }
                        CasinoRobStart(playerid);
                    }
                    case 3: {
                        if(RandomDraht == 3) {
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{007433} Du hast den richtiges Draht durch getrennt und 2 Minuten Zeit gewonnen.");
                            MoveDynamicObject(CASINOROB_DOOR[0], 1512.1502, -1513.8281, 1000.0145, 3.0, 0.0, 0.0, -18.3000);
                            MoveDynamicObject(CASINOROB_DOOR[3], 1502.5474, -1521.4482, 999.9843, 3.0 ,0.0, 0.0, -9.0);
                            AlarmanlageTimer = SetTimerEx("Alarmanlage", 120000, false, "d",playerid);
                        } else {
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du hast den falschen Draht durch getrennt, die Polizei wurde informiert.");
                            SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Zerstöre die Zugangskontrolle!");
                            AlarmanlageTimer = SetTimerEx("Alarmanlage", 500, false, "d",playerid);
                        }
                        CasinoRobStart(playerid);
                    }
                }
                CasinoRob_Alarm = 0;
            } else if(!response) {
                CasinoRob_Alarm = 0;
            }
        }
    }
    return 1;
}



forward CasinoRaub_Ausrauben(playerid,tisch);
public CasinoRaub_Ausrauben(playerid,tisch) {
    switch(tisch) {
        case 1: {
            new AusraubBeute = RandomEx(50000,120000);
            CasinoRob_Beute += AusraubBeute;
            SCMFormatted(playerid,COLOR_YELLOW,"[Casino-Raub]{2C8500} Du hast diesen Tisch erfolgreich ausgeraubt und %s$ gestohlen.",AddDelimiters(AusraubBeute));
            CasinoAusrauben[0] = true;
        }
        case 2: {
            new AusraubBeute = RandomEx(50000,120000);
            CasinoRob_Beute += AusraubBeute;
            SCMFormatted(playerid,COLOR_YELLOW,"[Casino-Raub]{2C8500} Du hast diesen Tisch erfolgreich ausgeraubt und %s$ gestohlen.",AddDelimiters(AusraubBeute));
            CasinoAusrauben[1] = true;
        }
        case 3: {
            new AusraubBeute = RandomEx(50000,120000);
            CasinoRob_Beute += AusraubBeute;
            SCMFormatted(playerid,COLOR_YELLOW,"[Casino-Raub]{2C8500} Du hast diesen Tisch erfolgreich ausgeraubt und %s$ gestohlen.",AddDelimiters(AusraubBeute));
            CasinoAusrauben[2] = true;
        }
    }
    return 1;
}



forward Check_CasinoRaub_Ausrauben(playerid,tisch);
public Check_CasinoRaub_Ausrauben(playerid,tisch) {
    switch(tisch) {
        case 1: { 
            if(!IsPlayerInRangeOfPoint(playerid, 1.5, CASINOROB_COORDS_TISCH1)) {
                SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du hast dich zu weit vom Tisch entfernt.");
                CasinoAusrauben[0] = false;
                KillTimer(CasinoRobAusraubCheckTimer);
                KillTimer(CasinoRobAusraubTimer);
            }
        }
        case 2: { 
            if(!IsPlayerInRangeOfPoint(playerid, 1.5, CASINOROB_COORDS_TISCH2)) {
                SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du hast dich zu weit vom Tisch entfernt.");
                CasinoAusrauben[1] = false;
                KillTimer(CasinoRobAusraubCheckTimer);
                KillTimer(CasinoRobAusraubTimer);
            }
        }
        case 3: {
            if(!IsPlayerInRangeOfPoint(playerid, 1.5, CASINOROB_COORDS_TISCH3)) {
                SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du hast dich zu weit vom Tisch entfernt.");
                CasinoAusrauben[2] = false;
                KillTimer(CasinoRobAusraubCheckTimer);
                KillTimer(CasinoRobAusraubTimer);
            }
        }
    }
    return 1;
}



forward Check_CTAufbrechen(playerid);
public Check_CTAufbrechen(playerid) {
    if(!IsPlayerInRangeOfPoint(playerid, 7.5, CASINOROB_COORDS_HINTERTÜR)) { 
        KillTimer(CTAufbrechenCheckTimer);
        KillTimer(CTAufbrechenTimer);
        SendClientMessage(playerid, COLOR_YELLOW,"[Casino-Raub]{8E2E1B} Du hast dich zu weit von der Tür entfernt.");
    }
    return 1;
}



forward CTAufbrechen(playerid);
public CTAufbrechen(playerid) {
    if(GetRobPlayers() > 0 && CasinoRob[playerid]) {
        MoveDynamicObject(CASINOROB_DOOR[1], 1488.6455, -1523.0,1000.0145, 2.0, -8.1, 1.3, -136.0);
        CasinoRob_Beute += RandomEx(25000,75000);
        SendClientMessage(playerid,COLOR_YELLOW,"[Casino-Raub]{FFFFFF} Du hast die Sichertür aufgebrochen und kannst jetzt flüchten.");
    }
    return 1;
}



forward Pulse_CasinoMark(playerid);
public Pulse_CasinoMark(playerid){
    if(Mark <= 120) {
        foreach(new i : Player) {
            foreach(new x : Player) {
                if(IsPlayerExecutive(x) && CasinoRob[i])
                SetPlayerMarkerForPlayer(x,i,COLOR_YELLOW);
            }
        }
        CasinoMarkTimer = SetTimerEx("Pulse_CasinoMark", 1000, false, "d",playerid);
    } else {
        CasinoRaubTimer = SetTimerEx("Pulse_Casinoraub", 1000, false, "d",playerid);
        KillTimer(CasinoMarkTimer);
        Mark = 0;
    }
    Mark ++;
    return 1;
}



forward Alarmanlage(playerid);
public Alarmanlage(playerid) {
    foreach(new i : Player) {
        if(CasinoRob[i]) {
            SendClientMessage(i, COLOR_DARKRED, "Du hast ein Verbrechen begangen. (Überfall/Raub) Reporter: Casino-Sicherheitssystem");
            SendClientMessage(i, COLOR_YELLOW, "Du hast 6 Wanteds erhalten!");
            Spieler[i][pWanteds] += 6;
        }
    }
    new string[128];
    format(string,sizeof(string),"[Casino-Raub]{FF8200} Das Los Santos Casino wird von %d Personen ausgeraubt.",GetRobPlayers());
    SendClientMessageToAll(COLOR_YELLOW, string);
    KillTimer(AlarmanlageTimer);
    return 1;
}



forward Pulse_Casinoraub(playerid);
public Pulse_Casinoraub(playerid) {
    if(GetRobPlayers() > 0) {
        CasinoRob_Beute += RandomEx(50000,150000);
        CasinoRaubStopTimer = SetTimerEx("CasinoRobStop", 180000, false, "d",playerid);
        new string[128];
        format(string,sizeof(string),"[Casino-Raub]{FFFFFF} %d Räuber haben das Casino um %s$ erleichtert.",GetRobPlayers(),AddDelimiters(CasinoRob_Beute));
        SendClientMessageToAll(COLOR_YELLOW, string);
        KillTimer(CheckRaubTimer);
        new EinzelBeute = CasinoRob_Beute/GetRobPlayers();
        foreach(new i : Player) {
            if(CasinoRob[i]) {
                GivePlayerCash(i, EinzelBeute);
                SCMFormatted(i,COLOR_YELLOW,"[Casino-Raub]{FFFFFF} Du hast deinen Anteil von %s$ bekommen.",AddDelimiters(EinzelBeute));
                CasinoRob[i] = 0;
            }
        }
        CasinoRob_Beute = 0;
    }
    return 1;
}



forward Pulse_Checkraub(playerid);
public Pulse_Checkraub(playerid) {
    if(GetRobPlayers() == 0 && CasinoRobStatus == Bankraub_Aktiv) {
        KillTimer(CheckRaubTimer);
        CasinoRobStatus = Bankraub_Wartezeit;
        SendClientMessageToAll(COLOR_YELLOW, "[Casino-Raub]{FFFFFF} Alle Räuber wurden verhaftet oder haben das Casino verlassen.");
        CasinoRaubStopTimer = SetTimerEx("CasinoRobStop", 180000, false, "d",playerid);
    } 
    CheckRaubTimer = SetTimerEx("Pulse_Checkraub", 1000, false, "d",playerid);
    return 1;
}



forward Pulse_CasinoReady(playerid);
public Pulse_CasinoReady(playerid) {
    if(CasinoRobStatus == Bankraub_Wartezeit) {
        SendClientMessageToAll(COLOR_YELLOW, "[Casino-Raub]{FFFFFF} Das Los Santos Casino kann wieder ausgeraubt werden.");
        CasinoRobStatus = Bankraub_Bereit;
        KillTimer(CasinoBereitTimer);
    }
    return 1;
}



stock GetRobPlayers() {
    new x;
    foreach(new i : Player) {
        if(CasinoRob[i]) x ++;
    }
    if(x > 0) return x;
    else return 0;
}



stock SetRobPlayers() {
    foreach(new i : Player) {
        if(GetPlayerVirtualWorld(i) == VW_CASINOROB && !IsPlayerExecutive(i)) {
            CasinoRob[i] = 1;
        }
    }
    return 1;
}



stock CasinoRobStart(playerid) {
    CasinoRobStatus = Bankraub_Aktiv;
    CasinoRob_Beute += RandomEx(50000,100000);
    CasinoRaubTimer = SetTimerEx("Pulse_Casinoraub", 720000, false, "d",playerid);
    CheckRaubTimer = SetTimerEx("Pulse_Checkraub", 1000, false, "d",playerid);
    for(new i; i < 11; i++) {
        ApplyDynamicActorAnimation(CASINOROB_ACTOR[i], "PED", "COWER", 3.0, 1, 0, 0, 0, 0);
    }
    SetRobPlayers();
    return 1;
}


forward CasinoRobStop(playerid);
public CasinoRobStop(playerid) {
    MoveDynamicObject(CASINOROB_BILD[0], 1494.265869, -1522.436157, 1001.862304, 3.0, 0.0, 0.0, -180.0);
    MoveDynamicObject(CASINOROB_DOOR[0], 1512.1501, -1513.8481, 1000.0145, 3.0, 0.0000, 0.0000, 90.0000);
    MoveDynamicObject(CASINOROB_DOOR[1], 1488.6455, -1523.0000, 1000.0145, 3.0, 0.0000, 0.0000, 135.0000);
    MoveDynamicObject(CASINOROB_DOOR[3], 1502.5598, -1521.3691, 999.9843,  3.0, 0.0000, 0.0000, -180.0000);
    MoveDynamicObject(CASINOROB_KEYPAD[0], 1512.1551, -1512.1512, 1001.4597, 3.0, 0.0000, 0.0000, 90.0000);
    DestroyDynamicObject(CASINOROB_TRESOR[0]);
    CasinoRob_Tresor_Status = false;
    CasinoRobBild = false;
    CasinoAusrauben[0] = false;
    CasinoAusrauben[1] = false;
    CasinoAusrauben[2] = false;
    CasinoHinten = false;
    CasinoTresorLeben = 20000;
    CasinoRob_Alarm = 0;
    ClearDynamicActorAnimations(CASINOROB_ACTOR[0]);
    ApplyDynamicActorAnimation(CASINOROB_ACTOR[1], "CASINO", "CARDS_WIN", 4.0998, 1, 0, 0, 0, 0);
    ClearDynamicActorAnimations(CASINOROB_ACTOR[2]);
    ClearDynamicActorAnimations(CASINOROB_ACTOR[3]);
    ApplyDynamicActorAnimation(CASINOROB_ACTOR[4], "BEACH", "LAY_BAC_LOOP", 4.0998, 1, 0, 0, 0, 0);
    ApplyDynamicActorAnimation(CASINOROB_ACTOR[5], "BD_FIRE", "BD_PANIC_LOOP", 4.0998, 1, 0, 0, 0, 0);
    ApplyDynamicActorAnimation(CASINOROB_ACTOR[6], "CASINO", "SLOT_WAIT", 4.0998, 1, 0, 0, 0, 0);
    ApplyDynamicActorAnimation(CASINOROB_ACTOR[7], "CASINO", "ROULETTE_LOSE", 4.0998, 1, 0, 0, 0, 0);
    ApplyDynamicActorAnimation(CASINOROB_ACTOR[8], "CASINO", "ROULETTE_WIN", 4.0998, 1, 0, 0, 0, 0);
    ApplyDynamicActorAnimation(CASINOROB_ACTOR[9], "CASINO", "SLOT_BET_01", 4.0998, 1, 0, 0, 0, 0);
    ApplyDynamicActorAnimation(CASINOROB_ACTOR[10], "BAR", "BARSERVE_LOOP", 4.0998, 1, 0, 0, 0, 0);
    CASINOROB_TRESOR[0] = CreateDynamicObject(2332, 1494.2635, -1522.9162, 1001.6337, 0.0000, 0.0000, 180.0000, VW_CASINOROB);
    UpdateDynamic3DTextLabelText(Label_Casino[0], COLOR_WHITE, "");
    KillTimer(CasinoRaubTimer);
    KillTimer(CTAufbrechenTimer);
    KillTimer(CheckRaubTimer);
    KillTimer(CasinoRaubStopTimer);
    CasinoRobStatus = Bankraub_Wartezeit;
    CasinoBereitTimer = SetTimerEx("Pulse_CasinoReady", 20*60*1000, false, "d",playerid);
    return 1;
}