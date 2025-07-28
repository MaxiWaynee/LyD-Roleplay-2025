#include <YSI\y_hooks>

enum e_Fraktion
{
    Fr_FrakID,
    Float:Fr_EnterX,
    Float:Fr_EnterY,
    Float:Fr_EnterZ,
    Fr_Interior,
    Fr_VW,
    Float:Fr_ExitX,
    Float:Fr_ExitY,
    Float:Fr_ExitZ,
    Fr_Partner,
    Fr_PartnerRequest,
    Fr_Status,
    Float:Fr_FSafeboxX,
    Float:Fr_FSafeboxY,
    Float:Fr_FSafeboxZ,
    Fr_HasFS,
    Fr_FSDrogen,
    Fr_FSWaffenteile,
    Fr_FSSpice,
    Fr_FSWantedcodes,
    Fr_FSKrauter,
    Fr_FSGangsamen,
    Fr_FSSprit,
    Float:Fr_WaffenlagerX,
    Float:Fr_WaffenlagerY,
    Float:Fr_WaffenlagerZ,
    Fr_WaffenlagerTeile,
    Fr_HasWL,
    Fr_SWScore,
    Float:Fr_GangitemX,
    Float:Fr_GangitemY,
    Float:Fr_GangitemZ,
    Fr_HasGI,
    Float:Fr_FSkinX,
    Float:Fr_FSkinY,
    Float:Fr_FSkinZ,
    Fr_HasSkin,
    Float:Fr_WaffenX,
    Float:Fr_WaffenY,
    Float:Fr_WaffenZ,
    Float:Fr_AufzugUX,
    Float:Fr_AufzugUY,
    Float:Fr_AufzugUZ,
    Float:Fr_AufzugOX,
    Float:Fr_AufzugOY,
    Float:Fr_AufzugOZ,
    Fr_HasAufzug,
    Fr_EnterPickup,
    Text3D:Fr_EnterText,
    Fr_ExitPickup,
    Text3D:Fr_ExitText,
    Fr_FSPickup,
    Text3D:Fr_FSText,
    Fr_WaffenlagerPickup,
    Text3D:Fr_WaffenlagerText,
    Fr_GIPickup,
    Text3D:Fr_GIText,
    Fr_SkinPickup,
    Text3D:Fr_SkinText,
    Fr_WaffenPickup,
    Text3D:Fr_WaffenText,
    Fr_AufzugOPickup,
    Text3D:Fr_AufzugOText,
    Fr_AufzugUPickup,
    Text3D:Fr_AufzugUText,
    Fr_Object,
    Fr_Fraktionspunkte,
    FR_FRadarUnix,
    FR_MaxCars,
    FR_SpawnwesteUnix,
    bool:Fr_WaffenlagerStatus
}

new g_fraktion[MAX_FACTIONS][e_Fraktion];


CMD:fsettings(playerid)
{
    if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
    new string[512],i=1;
    for(;i<sizeof(factionNames);i++) {
    	if(strlen(string) == 0) { format(string,sizeof(string),"%s\n%s",factionNames[i]); }
 	        else{ format(string,sizeof(string),"%s\n%s",string,factionNames[i]); }
    }
    ShowPlayerDialog(playerid,DIALOG_FSETTINGS,DIALOG_STYLE_LIST,"Fraktionsauswahl",string,"Auswählen","Abbrechen");
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    switch(dialogid) {
        case DIALOG_FSETTINGS: {
            if(!response) return 1;
            if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
            SelectedPlayer[playerid] = listitem +1;
            ShowPlayerDialog(playerid,DIALOG_FSETTINGS_SELECT,DIALOG_STYLE_LIST,"Auswahl","Icon's zu dir porten\nIcon's verschieben\nWaffenlager\nInterior\nVirtuelle Welt\nKassenstand\nSafebox\nDe/Aktivieren\nMaximale Fahrzeuge\nFraktions-Punkte","Bestätigen","Abbrechen");
        }
        case DIALOG_FSETTINGS_SELECT: {
            if(!response)return 1;
            if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV] || Spieler[playerid][pAdmin] == 0) return ERROR_RANG_MSG(playerid);
            SelectedItem[playerid] = listitem;
            switch(listitem) {
                case 0: ShowPlayerDialog(playerid,DIALOG_FSETTINGS_AUSWAHL,DIALOG_STYLE_LIST,"FE Auswahl","Spawn Punkt\nFSafebox\nWaffenlager\nGangitem\nFSkin\nEnter Point\nExit Point\nAufzug Unten\nAufzug Oben","Bestätigen","Abbrechen");
                case 1: ShowPlayerDialog(playerid,DIALOG_FSETTINGS_AUSWAHL,DIALOG_STYLE_LIST,"FE Auswahl","Spawn Punkt\nFSafebox\nWaffenlager\nGangitem\nFSkin\nEnter Point\nExit Point\nAufzug Unten\nAufzug Oben","Bestätigen","Abbrechen");
                case 2: { //Waffenlager
                    new dialogCaption[64], dialogText[256];
                    format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Waffenlager - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
                    format(dialogText, sizeof(dialogText), "{FF0099}Im Lager: {FFFFFF}%s Waffenteile\nGebe an, wieviele Waffenteile das Lager haben soll:", AddDelimiters(g_fraktion[SelectedPlayer[playerid]][Fr_WaffenlagerTeile]));
                    return ShowPlayerDialog(playerid, DIALOG_AWAFFENLAGER_CHANGE, DIALOG_STYLE_INPUT, dialogCaption, dialogText, "Ändern", "Zurück");
                }
                case 3: { //INterior
                    new dialogCaption[64], dialogText[256];
                    format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Interior - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
                    format(dialogText, sizeof(dialogText), "{FF0099}Aktuell: {FFFFFF}%d\nGebe an, welches Interior die Fraktion haben soll:", g_fraktion[SelectedPlayer[playerid]][Fr_Interior]);
                    return ShowPlayerDialog(playerid, DIALOG_FSETTINGS_INTERIOR, DIALOG_STYLE_INPUT, dialogCaption, dialogText, "Ändern", "Zurück");
                }
                case 4: { //VW
                    new dialogCaption[64], dialogText[256];
                    format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Virtuelle Welt - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
                    format(dialogText, sizeof(dialogText), "{FF0099}Aktuell: {FFFFFF}%d\nGebe an, welche Virtuelle Welt die Fraktion haben soll:", g_fraktion[SelectedPlayer[playerid]][Fr_VW]);
                    return ShowPlayerDialog(playerid, DIALOG_FSETTINGS_VW, DIALOG_STYLE_INPUT, dialogCaption, dialogText, "Ändern", "Zurück");
                }
                case 5: { //Kassenstand
                    new dialogCaption[64], dialogText[256],Kassenstand;
                    switch(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]) {
                        case 1: Kassenstand = Kasse[Staat];
                        case 2: Kassenstand = Kasse[Staat];
                        case 3: Kassenstand = Kasse[Samd];
                        case 4: Kassenstand = Kasse[Sana];
                        case 5: Kassenstand = Kasse[Oamt];
                        case 6: Kassenstand = Kasse[Grove];
                        case 7: Kassenstand = Kasse[Ballas];
                        case 8: Kassenstand = Kasse[Fahrschule];
                        case 9: Kassenstand = Kasse[Staat];
                        case 10: Kassenstand = Kasse[Yakuza];
                        case 11: Kassenstand = Kasse[Aztecas];
                        case 12: Kassenstand = Kasse[LCN];
                        case 13: Kassenstand = Kasse[Vagos];
                        case 14: Kassenstand = Kasse[Hitman];
                        case 15: Kassenstand = Kasse[BBikerZ];
                        case 16: Kassenstand = Kasse[Staat];
                        case 17: Kassenstand = Kasse[Wheelmenk];
                        case 18: Kassenstand = Kasse[Staat];
                        case 19: Kassenstand = Kasse[TerrorK];
                        case 20: Kassenstand = Kasse[OutlawzK];
                        case 21: Kassenstand = Kasse[ndgradethaK];
                        case 22: Kassenstand = Kasse[Staat];
                    }
                    format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Kassenstand - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
                    format(dialogText, sizeof(dialogText), "{FF0099}Aktuell: {FFFFFF}%s\nGebe an, wie viel Geld die Fraktion haben soll:", AddDelimiters(Kassenstand));
                    return ShowPlayerDialog(playerid, DIALOG_FSETTINGS_KASSENSTAND, DIALOG_STYLE_INPUT, dialogCaption, dialogText, "Ändern", "Zurück");
                }
                case 6: { //Safebox
                    new dialogCaption[64], dialogText[256];
                    format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Safebox - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
                    format(dialogText, sizeof(dialogText), "{FF0099}Drogen {FFFFFF}%d\n{FF0099}Waffenteile {FFFFFF}%d\n{FF0099}Spice {FFFFFF}%d\n{FF0099}Wantedcodes {FFFFFF}%d\n\
                    {FF0099}Kräuter {FFFFFF}%d\n{FF0099}Gangsamen {FFFFFF}%d\n{FF0099}Sprit {FFFFFF}%d",g_fraktion[SelectedPlayer[playerid]][Fr_FSDrogen],g_fraktion[SelectedPlayer[playerid]][Fr_FSWaffenteile] \
                    ,g_fraktion[SelectedPlayer[playerid]][Fr_FSSpice],g_fraktion[SelectedPlayer[playerid]][Fr_FSWantedcodes],g_fraktion[SelectedPlayer[playerid]][Fr_FSKrauter]\
                    ,g_fraktion[SelectedPlayer[playerid]][Fr_FSGangsamen],g_fraktion[SelectedPlayer[playerid]][Fr_FSSprit]);
                    return ShowPlayerDialog(playerid, DIALOG_FSETTINGS_SAFEBOX, DIALOG_STYLE_LIST, dialogCaption, dialogText, "Ändern", "Zurück");
                }
                case 7: { //De/Aktivieren
                    new dialogCaption[64], dialogText[256];
                    format(dialogCaption, sizeof(dialogCaption), "{FFFF00}De/Aktivieren - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
                    format(dialogText, sizeof(dialogText), "{FF0099}Safebox {FFFFFF}%s\n{FF0099}Waffenlager {FFFFFF}%s\n{FF0099}Gangitem {FFFFFF}%s\n{FF0099}Fraktions-Skin {FFFFFF}%s\n{FF0099}Aufzug {FFFFFF}%s",\
                    g_fraktion[SelectedPlayer[playerid]][Fr_HasFS] ? "Aktiviert" : "Deaktiviert",g_fraktion[SelectedPlayer[playerid]][Fr_HasWL] ? "Aktiviert" : "Deaktiviert",g_fraktion[SelectedPlayer[playerid]][Fr_HasGI] ? "Aktiviert" : "Deaktiviert"\
                    ,g_fraktion[SelectedPlayer[playerid]][Fr_HasSkin] ? "Aktiviert" : "Deaktiviert",g_fraktion[SelectedPlayer[playerid]][Fr_HasAufzug] ? "Aktiviert" : "Deaktiviert");
                    return ShowPlayerDialog(playerid, DIALOG_FSETTINGS_DEAKTIVIEREN, DIALOG_STYLE_LIST, dialogCaption, dialogText, "Ändern", "Zurück");
                }
                case 8: { //Maximale Fahrzeuge
                    new dialogCaption[64], dialogText[256];
                    format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Maximale Fahrzeuge - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
                    format(dialogText, sizeof(dialogText), "{FF0099}Aktuell: {FFFFFF}%d\nGebe an, wie viele Fahrzeuge die Fraktion haben darf:", g_fraktion[SelectedPlayer[playerid]][FR_MaxCars]);
                    return ShowPlayerDialog(playerid, DIALOG_FSETTINGS_MAXCARS, DIALOG_STYLE_INPUT, dialogCaption, dialogText, "Ändern", "Zurück");
                }
                case 9: { //Fpunkte
                    new dialogCaption[64], dialogText[256];
                    format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Fraktions Punkte - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
                    format(dialogText, sizeof(dialogText), "{FF0099}Aktuell: {FFFFFF}%d\nGebe an, wie viele Fraktions-Punkte die Fraktion haben soll:", g_fraktion[SelectedPlayer[playerid]][Fr_Fraktionspunkte]);
                    return ShowPlayerDialog(playerid, DIALOG_FSETTINGS_FRAKPUNKTE, DIALOG_STYLE_INPUT, dialogCaption, dialogText, "Ändern", "Zurück");
                }
            }
        }
        case DIALOG_FSETTINGS_INTERIOR: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 1) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Interior - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Interior: {FFFFFF}%d\nGebe an, welches Interior die Fraktion haben soll:", g_fraktion[index][Fr_Interior]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_Interior] = amount;
            format(message, sizeof(message), "%s %s hat das Interior der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_VW: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 0) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Virtuelle Welt - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Virtuelle Welt: {FFFFFF}%d\nGebe an, welche Virtuelle Welt die Fraktion haben soll:", g_fraktion[index][Fr_VW]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_VW] = amount;
            format(message, sizeof(message), "%s %s hat die Virtuelle Welt der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_KASSENSTAND: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 1) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Kassenstand - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Gebe an, wie viel Geld die Fraktion haben soll:");
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            switch(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]) {
                case 1: Kasse[Staat] = amount;
                case 2: Kasse[Staat] = amount;
                case 3: Kasse[Samd] = amount;
                case 4: Kasse[Sana] = amount;
                case 5: Kasse[Oamt] = amount;
                case 6: Kasse[Grove] = amount;
                case 7: Kasse[Ballas] = amount;
                case 8: Kasse[Fahrschule] = amount;
                case 9: Kasse[Staat] = amount;
                case 10: Kasse[Yakuza] = amount;
                case 11: Kasse[Aztecas] = amount;
                case 12: Kasse[LCN] = amount;
                case 13: Kasse[Vagos] = amount;
                case 14: Kasse[Hitman] = amount;
                case 15: Kasse[BBikerZ] = amount;
                case 16: Kasse[Staat] = amount;
                case 17: Kasse[Wheelmenk] = amount;
                case 18: Kasse[Staat] = amount;
                case 19: Kasse[TerrorK] = amount;
                case 20: Kasse[OutlawzK] = amount;
                case 21: Kasse[ndgradethaK] = amount;
                case 22: Kasse[Staat] = amount;
            }
            format(message, sizeof(message), "%s %s hat die Kasse der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_SAFEBOX: {
            if(!response) return 1;
            switch(listitem) {
                case 0: { //Drogen
                    ShowPlayerDialog(playerid, DIALOG_FSETTINGS_DROGEN, DIALOG_STYLE_INPUT, "Safebox Drogen", "Gib an wie viele Drogen du der Fraktion geben willst.", "Okay", "Abbrechen");
                }
                case 1: { //Waffenteile
                    ShowPlayerDialog(playerid, DIALOG_FSETTINGS_WAFFENTEILE, DIALOG_STYLE_INPUT, "Safebox Waffenteile", "Gib an wie viele Waffenteile du der Fraktion geben willst.", "Okay", "Abbrechen");
                }
                case 2: { //Spice
                    ShowPlayerDialog(playerid, DIALOG_FSETTINGS_SPICE, DIALOG_STYLE_INPUT, "Safebox Spice", "Gib an wie viele Spice du der Fraktion geben willst.", "Okay", "Abbrechen");
                }
                case 3: { //Wantedcodes
                    ShowPlayerDialog(playerid, DIALOG_FSETTINGS_WANTEDCODES, DIALOG_STYLE_INPUT, "Safebox Wantedcodes", "Gib an wie viele Wantedcodes du der Fraktion geben willst.", "Okay", "Abbrechen");
                }
                case 4: { //Kräuter
                    ShowPlayerDialog(playerid, DIALOG_FSETTINGS_KRAUTER, DIALOG_STYLE_INPUT, "Safebox Kräuter", "Gib an wie viele Kräuter du der Fraktion geben willst.", "Okay", "Abbrechen");
                }
                case 5: { //Gangsamen
                    ShowPlayerDialog(playerid, DIALOG_FSETTINGS_GANGSAMEN, DIALOG_STYLE_INPUT, "Safebox Gangsamen", "Gib an wie viele Gangsamen du der Fraktion geben willst.", "Okay", "Abbrechen");
                }
                case 6: { //Sprit
                    ShowPlayerDialog(playerid, DIALOG_FSETTINGS_SPRIT, DIALOG_STYLE_INPUT, "Safebox Sprit", "Gib an wie viele Sprit du der Fraktion geben willst.", "Okay", "Abbrechen");
                }
            }
        }
        case DIALOG_FSETTINGS_DEAKTIVIEREN: {
            if(!response) return 1;
            switch(listitem) {
                case 0: {
                    g_fraktion[SelectedPlayer[playerid]][Fr_HasFS] = g_fraktion[SelectedPlayer[playerid]][Fr_HasFS] ? 0 : 1;
                } case 1: {
                    g_fraktion[SelectedPlayer[playerid]][Fr_HasWL] = g_fraktion[SelectedPlayer[playerid]][Fr_HasWL] ? 0 : 1;
                } case 2: {
                    g_fraktion[SelectedPlayer[playerid]][Fr_HasGI] = g_fraktion[SelectedPlayer[playerid]][Fr_HasGI] ? 0 : 1;
                } case 3: {
                    g_fraktion[SelectedPlayer[playerid]][Fr_HasSkin] = g_fraktion[SelectedPlayer[playerid]][Fr_HasSkin] ? 0 : 1;
                } case 4: {
                    g_fraktion[SelectedPlayer[playerid]][Fr_HasAufzug] = g_fraktion[SelectedPlayer[playerid]][Fr_HasAufzug] ? 0 : 1;
                }
            }
            new dialogCaption[64], dialogText[256];
            format(dialogCaption, sizeof(dialogCaption), "{FFFF00}De/Aktivieren - %s", GetFactionName(g_fraktion[SelectedPlayer[playerid]][Fr_FrakID]));
            format(dialogText, sizeof(dialogText), "{FF0099}Safebox {FFFFFF}%s\n{FF0099}Waffenlager {FFFFFF}%s\n{FF0099}Gangitem {FFFFFF}%s\n{FF0099}Fraktions-Skin {FFFFFF}%s\n{FF0099}Aufzug {FFFFFF}%s",\
            g_fraktion[SelectedPlayer[playerid]][Fr_HasFS] ? "Aktiviert" : "Deaktiviert",g_fraktion[SelectedPlayer[playerid]][Fr_HasWL] ? "Aktiviert" : "Deaktiviert",g_fraktion[SelectedPlayer[playerid]][Fr_HasGI] ? "Aktiviert" : "Deaktiviert"\
            ,g_fraktion[SelectedPlayer[playerid]][Fr_HasSkin] ? "Aktiviert" : "Deaktiviert",g_fraktion[SelectedPlayer[playerid]][Fr_HasAufzug] ? "Aktiviert" : "Deaktiviert");
            ReloadFrak();
            return ShowPlayerDialog(playerid, DIALOG_FSETTINGS_DEAKTIVIEREN, DIALOG_STYLE_LIST, dialogCaption, dialogText, "Ändern", "Zurück");
        }
        case DIALOG_FSETTINGS_MAXCARS: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 1) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Maximale Fahrzeuge - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Maximale Fahrzeuge: {FFFFFF}%d\nGebe an, wie viel Fahrzeuge die Fraktion haben darf:", g_fraktion[index][FR_MaxCars]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][FR_MaxCars] = amount;
            format(message, sizeof(message), "%s %s hat die Maximale Fahrzeuge der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_FRAKPUNKTE: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 1) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Fraktions-Punkte - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Fraktions-Punkte: {FFFFFF}%d\nGebe an, wie viel Fraktions-Punkte die Fraktion haben darf:", g_fraktion[index][Fr_Fraktionspunkte]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_Fraktionspunkte] = amount;
            format(message, sizeof(message), "%s %s hat die Fraktions-Punkte der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_DROGEN: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 0) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Drogen - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Drogen: {FFFFFF}%d\nGebe an, welche Drogen die Fraktion haben soll:", g_fraktion[index][Fr_FSDrogen]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_FSDrogen] = amount;
            format(message, sizeof(message), "%s %s hat die Drogen der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_WAFFENTEILE: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 0) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Waffenteile - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Waffenteile: {FFFFFF}%d\nGebe an, welche Waffenteile die Fraktion haben soll:", g_fraktion[index][Fr_FSWaffenteile]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_FSWaffenteile] = amount;
            format(message, sizeof(message), "%s %s hat die Waffenteile der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_SPICE: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 0) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Spice - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Spice: {FFFFFF}%d\nGebe an, welche Spice die Fraktion haben soll:", g_fraktion[index][Fr_FSSpice]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_FSSpice] = amount;
            format(message, sizeof(message), "%s %s hat die Spice der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_WANTEDCODES: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 0) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Wantedcodes - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Wantedcodes: {FFFFFF}%d\nGebe an, welche Wantedcodes die Fraktion haben soll:", g_fraktion[index][Fr_FSWantedcodes]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_FSWantedcodes] = amount;
            format(message, sizeof(message), "%s %s hat die Wantedcodes der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_KRAUTER: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 0) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Kräuter - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Kräuter: {FFFFFF}%d\nGebe an, welche Kräuter die Fraktion haben soll:", g_fraktion[index][Fr_FSKrauter]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_FSKrauter] = amount;
            format(message, sizeof(message), "%s %s hat die Kräuter der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_GANGSAMEN: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 0) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Gangsamen - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Gangsamen: {FFFFFF}%d\nGebe an, welche Gangsamen die Fraktion haben soll:", g_fraktion[index][Fr_FSGangsamen]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_FSGangsamen] = amount;
            format(message, sizeof(message), "%s %s hat die Gangsamen der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_SPRIT: {
            if(!response) return 1;
            new amount, index = SelectedPlayer[playerid];
            if (sscanf(inputtext, "d", amount) || amount < 0) {
                new dialogCaption[64], dialogText[256];
                format(dialogCaption, sizeof(dialogCaption), "{FFFF00}Sprit - %s", GetFactionName(g_fraktion[index][Fr_FrakID]));
                format(dialogText, sizeof(dialogText), "{FF0099}Sprit: {FFFFFF}%d\nGebe an, welche Sprit die Fraktion haben soll:", g_fraktion[index][Fr_FSSprit]);
                return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst einen gültigen Wert angeben.");
            }
            new message[145];
            g_fraktion[index][Fr_FSSprit] = amount;
            format(message, sizeof(message), "%s %s hat die Sprit der Fraktion %s auf %s gesetzt.", GetPlayerAdminRang(playerid), 
            GetName(playerid), GetFactionName(g_fraktion[index][Fr_FrakID]), AddDelimiters(amount));
            SendAdminMessage(COLOR_YELLOW, message);
        }
        case DIALOG_FSETTINGS_AUSWAHL: {
            if(!response) return 1;
            if(Spieler[playerid][pAdmin] < 4 && !Spieler[playerid][pFV]) return ERROR_RANG_MSG(playerid);
            new Float:X,Float:Y,Float:Z;
            GetPlayerPos(playerid,X,Y,Z);
            switch(listitem) {
                case 0: { //Spawn Punkt
                    if(SelectedItem[playerid] == 0){
                        g_fraktion[SelectedPlayer[playerid]][Fr_WaffenX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_WaffenY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_WaffenZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1;
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(1240, g_fraktion[SelectedPlayer[playerid]][Fr_WaffenX], g_fraktion[SelectedPlayer[playerid]][Fr_WaffenY]	, g_fraktion[SelectedPlayer[playerid]][Fr_WaffenZ]	, 0.00000, 0.00000, 0.00000);
                        SelectedPickup=1;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                }
                case 1: { //Fsafebox
                    if(SelectedItem[playerid] == 0) {
                        g_fraktion[SelectedPlayer[playerid]][Fr_FSafeboxX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_FSafeboxY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_FSafeboxZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1;
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(1279, g_fraktion[SelectedPlayer[playerid]][Fr_FSafeboxX], g_fraktion[SelectedPlayer[playerid]][Fr_FSafeboxY]	, g_fraktion[SelectedPlayer[playerid]][Fr_FSafeboxZ]	, 0.00000, 0.00000, 0.00000);
                        SelectedPickup=2;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                }
                case 2: {  //Waffenlager
                    if(SelectedItem[playerid] == 0){
                        g_fraktion[SelectedPlayer[playerid]][Fr_WaffenlagerX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_WaffenlagerY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_WaffenlagerZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1;
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(1254, g_fraktion[SelectedPlayer[playerid]][Fr_WaffenlagerX], g_fraktion[SelectedPlayer[playerid]][Fr_WaffenlagerY]	, g_fraktion[SelectedPlayer[playerid]][Fr_WaffenlagerZ]	, 0.00000, 0.00000, 0.00000);
                        SelectedPickup=3;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                }
                case 3: { //Gangitem
                    if(SelectedItem[playerid] == 0) {
                        g_fraktion[SelectedPlayer[playerid]][Fr_GangitemX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_GangitemY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_GangitemZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1;
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(1275, g_fraktion[SelectedPlayer[playerid]][Fr_GangitemX], g_fraktion[SelectedPlayer[playerid]][Fr_GangitemY]	, g_fraktion[SelectedPlayer[playerid]][Fr_GangitemZ]	, 0.00000, 0.00000, 0.00000);
                        SelectedPickup=4;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                } 
                case 4: { //Skin
                    if(SelectedItem[playerid] == 0) {
                        g_fraktion[SelectedPlayer[playerid]][Fr_FSkinX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_FSkinY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_FSkinZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1; 
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(1275, g_fraktion[SelectedPlayer[playerid]][Fr_FSkinX], g_fraktion[SelectedPlayer[playerid]][Fr_FSkinY]	, g_fraktion[SelectedPlayer[playerid]][Fr_FSkinZ]	, 0.00000, 0.00000, 0.00000);
                        SelectedPickup=5;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                }
                case 5: { //Enter
                    if(SelectedItem[playerid] == 0) {
                        g_fraktion[SelectedPlayer[playerid]][Fr_EnterX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_EnterY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_EnterZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1;
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(19197, g_fraktion[SelectedPlayer[playerid]][Fr_EnterX], g_fraktion[SelectedPlayer[playerid]][Fr_EnterY], g_fraktion[SelectedPlayer[playerid]][Fr_EnterZ], 0.00000, 0.00000, 0.00000);
                        SelectedPickup=6;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                }
                case 6: { //Exit
                    if(SelectedItem[playerid] == 0) {
                        g_fraktion[SelectedPlayer[playerid]][Fr_ExitX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_ExitY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_ExitZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1;
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(19197, g_fraktion[SelectedPlayer[playerid]][Fr_ExitX], g_fraktion[SelectedPlayer[playerid]][Fr_ExitY], g_fraktion[SelectedPlayer[playerid]][Fr_ExitZ], 0.00000, 0.00000, 0.00000);
                        SelectedPickup=7;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                }
                case 7: { //Aufzug Unten
                    if(SelectedItem[playerid] == 0) {
                        g_fraktion[SelectedPlayer[playerid]][Fr_AufzugUX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_AufzugUY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_AufzugUZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1;
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(19197, g_fraktion[SelectedPlayer[playerid]][Fr_AufzugUX], g_fraktion[SelectedPlayer[playerid]][Fr_AufzugUY], g_fraktion[SelectedPlayer[playerid]][Fr_AufzugUZ]	, 0.00000, 0.00000, 0.00000);
                        SelectedPickup=8;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                }
                case 8: { //Aufzug Oben
                    if(SelectedItem[playerid] == 0) {
                        g_fraktion[SelectedPlayer[playerid]][Fr_AufzugOX] = X;
                        g_fraktion[SelectedPlayer[playerid]][Fr_AufzugOY] = Y;
                        g_fraktion[SelectedPlayer[playerid]][Fr_AufzugOZ] = Z;
                        ReloadFrak();
                    } else if(SelectedItem[playerid] == 1) {
                        Spieler[playerid][pEditObjectModeFS] = 1;
                        g_fraktion[SelectedPlayer[playerid]][Fr_Object] = CreateDynamicObject(19197, g_fraktion[SelectedPlayer[playerid]][Fr_AufzugOX], g_fraktion[SelectedPlayer[playerid]][Fr_AufzugOY], g_fraktion[SelectedPlayer[playerid]][Fr_AufzugOZ]	, 0.00000, 0.00000, 0.00000);
                        SelectedPickup=9;
                        EditDynamicObject(playerid,g_fraktion[SelectedPlayer[playerid]][Fr_Object]);
                    }
                }
            }
        }
    }
    return 1;
}


LoadFraktion()
{
    return mysql_oquery("SELECT * FROM `fraktionen`",THREAD_LOADFRAKTION,INVALID_PLAYER_ID,gSQL);
}

forward SaveFraktion();
public SaveFraktion()
{
    new query[2048];
    for(new i=1; i<MAX_FACTIONS;i++)
    {
        format(query,sizeof(query),"UPDATE `fraktionen` SET \
            `EnterX` = %.4f, \
            `EnterY` = %.4f, \
            `EnterZ` = %.4f, \
            `EnterInt` = %d, \
            `EnterWorld` = %d, \
            `ExitX` = %.4f, \
            `ExitY` = %.4f, \
            `ExitZ` = %.4f, \
            `partner` = %d, \
            `status` = %d, \
            `fsX` = %.4f, \
            `fsY` = %.4f, \
            `fsZ` = %.4f, \
            `hasfs` = %d, \
            `fsdrogen` = %d, \
            `fswaffenteile` = %d, \
            `fsspice` = %d, \
            `fswantedcodes` = %d, \
            `fskrauter` = %d, \
            `fsgangsamen` = %d, \
            `fssprit` = %d, \
            `waffenlagerX` = %.4f, \
            `waffenlagerY` = %.4f, \
            `waffenlagerZ` = %.4f, \
            `waffenlagerteile` = %d, \
            `hasWL` = %d, \
            `GIX` = %.4f, \
            `GIY` = %.4f, \
            `GIZ` = %.4f, \
            `hasGI` = %d, \
            `skinX` = %.4f, \
            `skinY` = %.4f, \
            `skinZ` = %.4f, \
            `hasskin` = %d, \
            `waffenX` = %.4f, \
            `waffenY` = %.4f, \
            `waffenZ` = %.4f, \
            `aufzugoX` = %.4f, \
            `aufzugoY` = %.4f, \
            `aufzugoZ` = %.4f, \
            `aufzuguX` = %.4f, \
            `aufzuguY` = %.4f, \
            `aufzuguZ` = %.4f, \
            `hasaufzug` = %d, \
            `fpoints` = %d, \
            `fradarUnix` = %d, \
            `maxcars` = %d, \
            `spawnwesteUnix` = %d \
            WHERE `fraktionsid` = %d",
            g_fraktion[i][Fr_EnterX],
            g_fraktion[i][Fr_EnterY],
            g_fraktion[i][Fr_EnterZ],
            g_fraktion[i][Fr_Interior],
            g_fraktion[i][Fr_VW],
            g_fraktion[i][Fr_ExitX],
            g_fraktion[i][Fr_ExitY],
            g_fraktion[i][Fr_ExitZ],
            g_fraktion[i][Fr_Partner],
            g_fraktion[i][Fr_Status],
            g_fraktion[i][Fr_FSafeboxX],
            g_fraktion[i][Fr_FSafeboxY],
            g_fraktion[i][Fr_FSafeboxZ],
            g_fraktion[i][Fr_HasFS],
            g_fraktion[i][Fr_FSDrogen],
            g_fraktion[i][Fr_FSWaffenteile],
            g_fraktion[i][Fr_FSSpice],
            g_fraktion[i][Fr_FSWantedcodes],
            g_fraktion[i][Fr_FSKrauter],
            g_fraktion[i][Fr_FSGangsamen],
            g_fraktion[i][Fr_FSSprit],
            g_fraktion[i][Fr_WaffenlagerX],
            g_fraktion[i][Fr_WaffenlagerY],
            g_fraktion[i][Fr_WaffenlagerZ],
            g_fraktion[i][Fr_WaffenlagerTeile],
            g_fraktion[i][Fr_HasWL],    
            g_fraktion[i][Fr_GangitemX],    
            g_fraktion[i][Fr_GangitemY],    
            g_fraktion[i][Fr_GangitemZ],    
            g_fraktion[i][Fr_HasGI],    
            g_fraktion[i][Fr_FSkinX],    
            g_fraktion[i][Fr_FSkinY],
            g_fraktion[i][Fr_FSkinZ],    
            g_fraktion[i][Fr_HasSkin],    
            g_fraktion[i][Fr_WaffenX],    
            g_fraktion[i][Fr_WaffenY],    
            g_fraktion[i][Fr_WaffenZ],    
            g_fraktion[i][Fr_AufzugOX],    
            g_fraktion[i][Fr_AufzugOY],    
            g_fraktion[i][Fr_AufzugOZ],    
            g_fraktion[i][Fr_AufzugUX],    
            g_fraktion[i][Fr_AufzugUY],    
            g_fraktion[i][Fr_AufzugUZ],    
            g_fraktion[i][Fr_HasAufzug],
            g_fraktion[i][Fr_Fraktionspunkte],
            g_fraktion[i][FR_FRadarUnix],
            g_fraktion[i][FR_MaxCars],
            g_fraktion[i][FR_SpawnwesteUnix],
            g_fraktion[i][Fr_FrakID]);
        mysql_oquery(query,THREAD_SAVEFRAKTION,i,gSQL);
    }
    return 1;
}


stock ReloadFrak() {
    for (new i; i < MAX_FACTIONS; i++) {
        new string[256];
        if(g_fraktion[i][Fr_HasWL] && IsAFightFaction(g_fraktion[i][Fr_FrakID]) || g_fraktion[i][Fr_FrakID] == 14 || g_fraktion[i][Fr_FrakID] == 15) {
            format(string,sizeof(string),COLOR_HEX_YELLOW"%s - Waffenlager\n"COLOR_HEX_WHITE"Tippe /Waffenlager",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_WaffenlagerPickup]);
            g_fraktion[i][Fr_WaffenlagerPickup] = CreateDynamicPickup(1254, 1, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_WaffenlagerText]);
            g_fraktion[i][Fr_WaffenlagerText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
        }
        if(IsAFightFaction(g_fraktion[i][Fr_FrakID])) {
            format(string,sizeof(string),COLOR_HEX_BLUE"%s Spawn\n"COLOR_HEX_WHITE"Tippe /Gangwaffen zum Ausrüsten\nTippe /Gheilen zum heilen",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_WaffenPickup]);
            g_fraktion[i][Fr_WaffenPickup] = CreateDynamicPickup(1240, 1, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_WaffenText]);
            g_fraktion[i][Fr_WaffenText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
	        format(string,sizeof(string),COLOR_HEX_YELLOW"Territorium der\n{%s}%s",GetFactionColor(g_fraktion[i][Fr_FrakID]),GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_EnterPickup]);
            g_fraktion[i][Fr_EnterPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], .worldid = 0, .interiorid = 0);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_EnterText]);
            g_fraktion[i][Fr_EnterText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], 10.0, .testlos = 1, .worldid = 0, .interiorid = 0);
	        DestroyDynamicPickup(g_fraktion[i][Fr_ExitPickup]);
            g_fraktion[i][Fr_ExitPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_ExitX], g_fraktion[i][Fr_ExitY], g_fraktion[i][Fr_ExitZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
        }
        if(IsADutyFaction(g_fraktion[i][Fr_FrakID])) {
            format(string,sizeof(string),COLOR_HEX_BLUE"%s Dienst\n"COLOR_HEX_WHITE"Tippe /Dienst um in den Dienst zu gehen",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_WaffenPickup]);
            g_fraktion[i][Fr_WaffenPickup] = CreateDynamicPickup(1240, 1, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_WaffenText]);
            g_fraktion[i][Fr_WaffenText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], 10.0 , .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            format(string,sizeof(string),COLOR_HEX_YELLOW"Eingang\n"COLOR_HEX_WHITE"%s",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_EnterPickup]);
            g_fraktion[i][Fr_EnterPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], .worldid = 0, .interiorid = 0);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_EnterText]);
            g_fraktion[i][Fr_EnterText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], 10.0, .testlos = 1, .worldid = 0, .interiorid = 0);
	        DestroyDynamicPickup(g_fraktion[i][Fr_ExitPickup]);
            g_fraktion[i][Fr_ExitPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_ExitX], g_fraktion[i][Fr_ExitY], g_fraktion[i][Fr_ExitZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            if(g_fraktion[i][Fr_HasWL]) {
                format(string,sizeof(string),COLOR_HEX_YELLOW"%s - Waffenspind\n"COLOR_HEX_WHITE"Tippe /waffenspind",GetFactionName(g_fraktion[i][Fr_FrakID]));
                DestroyDynamicPickup(g_fraktion[i][Fr_WaffenlagerPickup]);
                g_fraktion[i][Fr_WaffenlagerPickup] = CreateDynamicPickup(2061, 1, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                DestroyDynamic3DTextLabel(g_fraktion[i][Fr_WaffenlagerText]);
                g_fraktion[i][Fr_WaffenlagerText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            }
        }
        if(g_fraktion[i][Fr_FrakID] == 14) {   
            format(string,sizeof(string),COLOR_HEX_BLUE"%s Spawn\n"COLOR_HEX_WHITE"Tippe /hitmanwaffen zum Ausrüsten\nTippe /Gheilen zum heilen",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_WaffenPickup]);
            g_fraktion[i][Fr_WaffenPickup] = CreateDynamicPickup(1240, 1, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_WaffenText]);
            g_fraktion[i][Fr_WaffenText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
	        format(string,sizeof(string),COLOR_HEX_YELLOW"Territorium der\n"COLOR_HEX_WHITE"%s",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_EnterPickup]);
            g_fraktion[i][Fr_EnterPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], .worldid = 0, .interiorid = 0);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_EnterText]);
            g_fraktion[i][Fr_EnterText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], 10.0, .testlos = 1, .worldid = 0, .interiorid = 0);
	        DestroyDynamicPickup(g_fraktion[i][Fr_ExitPickup]);
            g_fraktion[i][Fr_ExitPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_ExitX], g_fraktion[i][Fr_ExitY], g_fraktion[i][Fr_ExitZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);    
        }
        if(g_fraktion[i][Fr_FrakID] == 15) {   
            format(string,sizeof(string),COLOR_HEX_BLUE"%s Spawn\n"COLOR_HEX_WHITE"Tippe /Ninowaffen zum Ausrüsten\nTippe /Gheilen zum heilen",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_WaffenPickup]);
            g_fraktion[i][Fr_WaffenPickup] = CreateDynamicPickup(1240, 1, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_WaffenText]);
            g_fraktion[i][Fr_WaffenText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
	        format(string,sizeof(string),COLOR_HEX_YELLOW"Territorium der\n"COLOR_HEX_WHITE"%s",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_EnterPickup]);
            g_fraktion[i][Fr_EnterPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], .worldid = 0, .interiorid = 0);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_EnterText]);
            g_fraktion[i][Fr_EnterText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], 10.0, .testlos = 1, .worldid = 0, .interiorid = 0);
	        DestroyDynamicPickup(g_fraktion[i][Fr_ExitPickup]);
            g_fraktion[i][Fr_ExitPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_ExitX], g_fraktion[i][Fr_ExitY], g_fraktion[i][Fr_ExitZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
        }
        if(g_fraktion[i][Fr_HasSkin]) {
            format(string,sizeof(string),COLOR_HEX_BLUE"%s Fraktionsskin\n"COLOR_HEX_WHITE"Tippe /FSkin um in die Skinauswahl zu gehen",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_SkinPickup]);
            g_fraktion[i][Fr_SkinPickup] = CreateDynamicPickup(1275, 1, g_fraktion[i][Fr_FSkinX], g_fraktion[i][Fr_FSkinY], g_fraktion[i][Fr_FSkinZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_SkinText]);
            g_fraktion[i][Fr_SkinText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_FSkinX], g_fraktion[i][Fr_FSkinY], g_fraktion[i][Fr_FSkinZ], 10.0 , .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
        }
        if(g_fraktion[i][Fr_HasFS]) {
            format(string,sizeof(string),COLOR_HEX_YELLOW"Safebox der %s\n"COLOR_HEX_WHITE"Tippe /FSafebox",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_FSPickup]);
            g_fraktion[i][Fr_FSPickup] = CreateDynamicPickup(1279, 1, g_fraktion[i][Fr_FSafeboxX], g_fraktion[i][Fr_FSafeboxY], g_fraktion[i][Fr_FSafeboxZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_FSText]);
            g_fraktion[i][Fr_FSText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_FSafeboxX], g_fraktion[i][Fr_FSafeboxY], g_fraktion[i][Fr_FSafeboxZ], 10.0 , .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
        }
        if(g_fraktion[i][Fr_HasGI]) {
            format(string,sizeof(string),COLOR_HEX_YELLOW"%s - Gangshop\n"COLOR_HEX_WHITE"Tippe /Gangitem",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_GIPickup]);
            g_fraktion[i][Fr_GIPickup] = CreateDynamicPickup(1275, 1, g_fraktion[i][Fr_GangitemX], g_fraktion[i][Fr_GangitemY], g_fraktion[i][Fr_GangitemZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_GIText]);
            g_fraktion[i][Fr_GIText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_GangitemX], g_fraktion[i][Fr_GangitemY], g_fraktion[i][Fr_GangitemZ], 10.0 , .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
        }
        if(g_fraktion[i][Fr_HasAufzug]) {
            format(string,sizeof(string),COLOR_HEX_YELLOW"Aufzug - %s\n"COLOR_HEX_WHITE"Drücke 'Enter'",GetFactionName(g_fraktion[i][Fr_FrakID]));
            DestroyDynamicPickup(g_fraktion[i][Fr_AufzugOPickup]);
            g_fraktion[i][Fr_AufzugOPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_AufzugOX], g_fraktion[i][Fr_AufzugOY], g_fraktion[i][Fr_AufzugOZ], .worldid = VW_MAIN, .interiorid = 0);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_AufzugOText]);
            g_fraktion[i][Fr_AufzugOText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_AufzugOX], g_fraktion[i][Fr_AufzugOY], g_fraktion[i][Fr_AufzugOZ], 10.0 , .testlos = 1, .worldid = VW_MAIN, .interiorid = 0);
            DestroyDynamicPickup(g_fraktion[i][Fr_AufzugUPickup]);
            g_fraktion[i][Fr_AufzugUPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_AufzugUX], g_fraktion[i][Fr_AufzugUY], g_fraktion[i][Fr_AufzugUZ], .worldid = VW_MAIN, .interiorid = 0);
            DestroyDynamic3DTextLabel(g_fraktion[i][Fr_AufzugUText]);
            g_fraktion[i][Fr_AufzugUText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_AufzugUX], g_fraktion[i][Fr_AufzugUY], g_fraktion[i][Fr_AufzugUZ], 10.0 , .testlos = 1, .worldid = VW_MAIN, .interiorid = 0);
        }
    }
    return 1;
}


hook OnQueryFinish(query[], resultid, extraid, connectionHandle , threadowner ) {
    switch(resultid) {
        case THREAD_LOADFRAKTION: {
            new rows,row,FrakID;
            rows = cache_get_row_count(connectionHandle);
            while ( row < rows) {
                FrakID = cache_get_field_content_int(row,"fraktionsid",connectionHandle);
                g_fraktion[FrakID][Fr_EnterX] = cache_get_field_content_float(row,"EnterX",connectionHandle);
                g_fraktion[FrakID][Fr_EnterY] = cache_get_field_content_float(row,"EnterY",connectionHandle);
                g_fraktion[FrakID][Fr_EnterZ] = cache_get_field_content_float(row,"EnterZ",connectionHandle);
                g_fraktion[FrakID][Fr_Interior] = cache_get_field_content_int(row,"EnterInt",connectionHandle);
                g_fraktion[FrakID][Fr_VW] = cache_get_field_content_int(row,"EnterWorld",connectionHandle);
                g_fraktion[FrakID][Fr_ExitX] = cache_get_field_content_float(row,"ExitX",connectionHandle);
                g_fraktion[FrakID][Fr_ExitY] = cache_get_field_content_float(row,"ExitY",connectionHandle);
                g_fraktion[FrakID][Fr_ExitZ] = cache_get_field_content_float(row,"ExitZ",connectionHandle);
                g_fraktion[FrakID][Fr_Partner] = cache_get_field_content_int(row,"partner",connectionHandle);
                g_fraktion[FrakID][Fr_Status] = cache_get_field_content_int(row,"status",connectionHandle);
                g_fraktion[FrakID][Fr_FSafeboxX] = cache_get_field_content_float(row,"fsX",connectionHandle);
                g_fraktion[FrakID][Fr_FSafeboxY] = cache_get_field_content_float(row,"fsY",connectionHandle);
                g_fraktion[FrakID][Fr_FSafeboxZ] = cache_get_field_content_float(row,"fsZ",connectionHandle);
                g_fraktion[FrakID][Fr_HasFS] = cache_get_field_content_int(row,"hasfs",connectionHandle);
                g_fraktion[FrakID][Fr_FSDrogen] = cache_get_field_content_int(row,"fsdrogen",connectionHandle);
                g_fraktion[FrakID][Fr_FSWaffenteile] = cache_get_field_content_int(row,"fswaffenteile",connectionHandle);
                g_fraktion[FrakID][Fr_FSSpice] = cache_get_field_content_int(row,"fsspice",connectionHandle);
                g_fraktion[FrakID][Fr_FSWantedcodes] = cache_get_field_content_int(row,"fswantedcodes",connectionHandle);
                g_fraktion[FrakID][Fr_FSKrauter] = cache_get_field_content_int(row,"fskrauter",connectionHandle);
                g_fraktion[FrakID][Fr_FSGangsamen] = cache_get_field_content_int(row,"fsgangsamen",connectionHandle);
                g_fraktion[FrakID][Fr_FSSprit] = cache_get_field_content_int(row,"fssprit",connectionHandle);
                g_fraktion[FrakID][Fr_WaffenlagerX] = cache_get_field_content_float(row,"waffenlagerX",connectionHandle);
                g_fraktion[FrakID][Fr_WaffenlagerY] = cache_get_field_content_float(row,"waffenlagerY",connectionHandle);
                g_fraktion[FrakID][Fr_WaffenlagerZ] = cache_get_field_content_float(row,"waffenlagerZ",connectionHandle);
                g_fraktion[FrakID][Fr_WaffenlagerTeile] = cache_get_field_content_int(row,"waffenlagerteile",connectionHandle);
                g_fraktion[FrakID][Fr_HasWL] = cache_get_field_content_int(row,"hasWL",connectionHandle);
                g_fraktion[FrakID][Fr_SWScore] = cache_get_field_content_int(row,"score",connectionHandle);
                g_fraktion[FrakID][Fr_GangitemX] = cache_get_field_content_float(row,"GIX",connectionHandle);
                g_fraktion[FrakID][Fr_GangitemY] = cache_get_field_content_float(row,"GIY",connectionHandle);
                g_fraktion[FrakID][Fr_GangitemZ] = cache_get_field_content_float(row,"GIZ",connectionHandle);
                g_fraktion[FrakID][Fr_HasGI] = cache_get_field_content_int(row,"hasGI",connectionHandle);
                g_fraktion[FrakID][Fr_FSkinX] = cache_get_field_content_float(row,"skinX",connectionHandle);
                g_fraktion[FrakID][Fr_FSkinY] = cache_get_field_content_float(row,"skinY",connectionHandle);
                g_fraktion[FrakID][Fr_FSkinZ] = cache_get_field_content_float(row,"skinZ",connectionHandle);
                g_fraktion[FrakID][Fr_HasSkin] = cache_get_field_content_int(row,"hasskin",connectionHandle);
                g_fraktion[FrakID][Fr_WaffenX] = cache_get_field_content_float(row,"waffenX",connectionHandle);
                g_fraktion[FrakID][Fr_WaffenY] = cache_get_field_content_float(row,"waffenY",connectionHandle);
                g_fraktion[FrakID][Fr_WaffenZ] = cache_get_field_content_float(row,"waffenZ",connectionHandle);
                g_fraktion[FrakID][Fr_AufzugUX] = cache_get_field_content_float(row,"aufzuguX",connectionHandle);
                g_fraktion[FrakID][Fr_AufzugUY] = cache_get_field_content_float(row,"aufzuguY",connectionHandle);
                g_fraktion[FrakID][Fr_AufzugUZ] = cache_get_field_content_float(row,"aufzuguZ",connectionHandle);
                g_fraktion[FrakID][Fr_AufzugOX] = cache_get_field_content_float(row,"aufzugoX",connectionHandle);
                g_fraktion[FrakID][Fr_AufzugOY] = cache_get_field_content_float(row,"aufzugoY",connectionHandle);
                g_fraktion[FrakID][Fr_AufzugOZ] = cache_get_field_content_float(row,"aufzugoZ",connectionHandle);
                g_fraktion[FrakID][Fr_HasAufzug] = cache_get_field_content_int(row,"hasaufzug",connectionHandle);
                g_fraktion[FrakID][Fr_Fraktionspunkte] = cache_get_field_content_int(row,"fpoints",connectionHandle);
                g_fraktion[FrakID][FR_FRadarUnix] = cache_get_field_content_int(row,"fradarUnix",connectionHandle);
                g_fraktion[FrakID][FR_MaxCars] = cache_get_field_content_int(row,"maxcars",connectionHandle);
                g_fraktion[FrakID][FR_SpawnwesteUnix] = cache_get_field_content_int(row,"spawnwesteUnix",connectionHandle);
                g_fraktion[FrakID][Fr_FrakID] = FrakID;
                if( ( FrakID >= MAX_FACTIONS ) || ( FrakID < 0 ) ) continue;

                row ++;
            }
            //Dynamisches Fraksystem
            for (new i; i < MAX_FACTIONS; i++) {
                new string[256];
                if(g_fraktion[i][Fr_HasWL] && IsAFightFaction(g_fraktion[i][Fr_FrakID]) || g_fraktion[i][Fr_FrakID] == 14 || g_fraktion[i][Fr_FrakID] == 15) {
                    format(string,sizeof(string),COLOR_HEX_YELLOW"%s - Waffenlager\n"COLOR_HEX_WHITE"Tippe /Waffenlager",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_WaffenlagerPickup] = CreateDynamicPickup(1254, 1, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    g_fraktion[i][Fr_WaffenlagerText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                } if(IsAFightFaction(g_fraktion[i][Fr_FrakID])) {
                    format(string,sizeof(string),COLOR_HEX_BLUE"%s Spawn\n"COLOR_HEX_WHITE"Tippe /Gangwaffen zum Ausrüsten\nTippe /Gheilen zum heilen",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_WaffenPickup] = CreateDynamicPickup(1240, 1, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    g_fraktion[i][Fr_WaffenText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    format(string,sizeof(string),COLOR_HEX_YELLOW"Territorium der\n{%s}%s",GetFactionColor(g_fraktion[i][Fr_FrakID]),GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_EnterPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], .worldid = 0, .interiorid = 0);
                    g_fraktion[i][Fr_EnterText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], 10.0, .testlos = 1, .worldid = 0, .interiorid = 0);
                    g_fraktion[i][Fr_ExitPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_ExitX], g_fraktion[i][Fr_ExitY], g_fraktion[i][Fr_ExitZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                } if(IsADutyFaction(g_fraktion[i][Fr_FrakID])) {
                    format(string,sizeof(string),COLOR_HEX_BLUE"%s Dienst\n"COLOR_HEX_WHITE"Tippe /Dienst um in den Dienst zu gehen",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_WaffenPickup] = CreateDynamicPickup(1240, 1, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    g_fraktion[i][Fr_WaffenText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], 10.0 , .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    format(string,sizeof(string),COLOR_HEX_YELLOW"Eingang\n"COLOR_HEX_WHITE"%s",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_EnterPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], .worldid = 0, .interiorid = 0);
                    g_fraktion[i][Fr_EnterText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], 10.0, .testlos = 1, .worldid = 0, .interiorid = 0);
                    g_fraktion[i][Fr_ExitPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_ExitX], g_fraktion[i][Fr_ExitY], g_fraktion[i][Fr_ExitZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    if(g_fraktion[i][Fr_HasWL]) {
                        format(string,sizeof(string),COLOR_HEX_YELLOW"%s - Waffenspind\n"COLOR_HEX_WHITE"Tippe /waffenspind",GetFactionName(g_fraktion[i][Fr_FrakID]));
                        g_fraktion[i][Fr_WaffenlagerPickup] = CreateDynamicPickup(2061, 1, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                        g_fraktion[i][Fr_WaffenlagerText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenlagerX], g_fraktion[i][Fr_WaffenlagerY], g_fraktion[i][Fr_WaffenlagerZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    }
                } if(g_fraktion[i][Fr_FrakID] == 14) {   
                    format(string,sizeof(string),COLOR_HEX_BLUE"%s Spawn\n"COLOR_HEX_WHITE"Tippe /hitmanwaffen zum Ausrüsten\nTippe /Gheilen zum heilen",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_WaffenPickup] = CreateDynamicPickup(1240, 1, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    g_fraktion[i][Fr_WaffenText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    format(string,sizeof(string),COLOR_HEX_YELLOW"Territorium der\n"COLOR_HEX_WHITE"%s",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_EnterPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], .worldid = 0, .interiorid = 0);
                    g_fraktion[i][Fr_EnterText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], 10.0, .testlos = 1, .worldid = 0, .interiorid = 0);
                    g_fraktion[i][Fr_ExitPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_ExitX], g_fraktion[i][Fr_ExitY], g_fraktion[i][Fr_ExitZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                
                } if(g_fraktion[i][Fr_FrakID] == 15) {   
                    format(string,sizeof(string),COLOR_HEX_BLUE"%s Spawn\n"COLOR_HEX_WHITE"Tippe /Ninowaffen zum Ausrüsten\nTippe /Gheilen zum heilen",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_WaffenPickup] = CreateDynamicPickup(1240, 1, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    g_fraktion[i][Fr_WaffenText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_WaffenX], g_fraktion[i][Fr_WaffenY], g_fraktion[i][Fr_WaffenZ], 10.0, .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    format(string,sizeof(string),COLOR_HEX_YELLOW"Territorium der\n"COLOR_HEX_WHITE"%s",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_EnterPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], .worldid = 0, .interiorid = 0);
                    g_fraktion[i][Fr_EnterText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_EnterX], g_fraktion[i][Fr_EnterY], g_fraktion[i][Fr_EnterZ], 10.0, .testlos = 1, .worldid = 0, .interiorid = 0);
                    g_fraktion[i][Fr_ExitPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_ExitX], g_fraktion[i][Fr_ExitY], g_fraktion[i][Fr_ExitZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                } if(g_fraktion[i][Fr_HasSkin]) {
                    format(string,sizeof(string),COLOR_HEX_BLUE"%s Fraktionsskin\n"COLOR_HEX_WHITE"Tippe /FSkin um in die Skinauswahl zu gehen",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_SkinPickup] = CreateDynamicPickup(1275, 1, g_fraktion[i][Fr_FSkinX], g_fraktion[i][Fr_FSkinY], g_fraktion[i][Fr_FSkinZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    g_fraktion[i][Fr_SkinText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_FSkinX], g_fraktion[i][Fr_FSkinY], g_fraktion[i][Fr_FSkinZ], 10.0 , .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                } if(g_fraktion[i][Fr_HasFS]) {
                    format(string,sizeof(string),COLOR_HEX_YELLOW"Safebox der %s\n"COLOR_HEX_WHITE"Tippe /FSafebox",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_FSPickup] = CreateDynamicPickup(1279, 1, g_fraktion[i][Fr_FSafeboxX], g_fraktion[i][Fr_FSafeboxY], g_fraktion[i][Fr_FSafeboxZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    g_fraktion[i][Fr_FSText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_FSafeboxX], g_fraktion[i][Fr_FSafeboxY], g_fraktion[i][Fr_FSafeboxZ], 10.0 , .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                } if(g_fraktion[i][Fr_HasGI]) {
                    format(string,sizeof(string),COLOR_HEX_YELLOW"%s - Gangshop\n"COLOR_HEX_WHITE"Tippe /Gangitem",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    g_fraktion[i][Fr_GIPickup] = CreateDynamicPickup(1275, 1, g_fraktion[i][Fr_GangitemX], g_fraktion[i][Fr_GangitemY], g_fraktion[i][Fr_GangitemZ], .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                    g_fraktion[i][Fr_GIText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_GangitemX], g_fraktion[i][Fr_GangitemY], g_fraktion[i][Fr_GangitemZ], 10.0 , .testlos = 1, .worldid = g_fraktion[i][Fr_VW], .interiorid = g_fraktion[i][Fr_Interior]);
                } if(g_fraktion[i][Fr_HasAufzug]) {
                    format(string,sizeof(string),COLOR_HEX_YELLOW"Aufzug - %s\n"COLOR_HEX_WHITE"Drücke 'Enter'",GetFactionName(g_fraktion[i][Fr_FrakID]));
                    DestroyDynamicPickup(g_fraktion[i][Fr_AufzugOPickup]);
                    g_fraktion[i][Fr_AufzugOPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_AufzugOX], g_fraktion[i][Fr_AufzugOY], g_fraktion[i][Fr_AufzugOZ], .worldid = VW_MAIN, .interiorid = 0);
                    DestroyDynamic3DTextLabel(g_fraktion[i][Fr_AufzugOText]);
                    g_fraktion[i][Fr_AufzugOText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_AufzugOX], g_fraktion[i][Fr_AufzugOY], g_fraktion[i][Fr_AufzugOZ], 10.0 , .testlos = 1, .worldid = VW_MAIN, .interiorid = 0);
                    DestroyDynamicPickup(g_fraktion[i][Fr_AufzugUPickup]);
                    g_fraktion[i][Fr_AufzugUPickup] = CreateDynamicPickup(19197, 1, g_fraktion[i][Fr_AufzugUX], g_fraktion[i][Fr_AufzugUY], g_fraktion[i][Fr_AufzugUZ], .worldid = VW_MAIN, .interiorid = 0);
                    DestroyDynamic3DTextLabel(g_fraktion[i][Fr_AufzugUText]);
                    g_fraktion[i][Fr_AufzugUText] = CreateDynamic3DTextLabel(string, COLOR_WHITE, g_fraktion[i][Fr_AufzugUX], g_fraktion[i][Fr_AufzugUY], g_fraktion[i][Fr_AufzugUZ], 10.0 , .testlos = 1, .worldid = VW_MAIN, .interiorid = 0);
                }
            }
            ReloadFrak();
        }
        case THREAD_SAVEFRAKTION:
        {
        }
    }
    return 1;
}