#include <YSI\y_hooks>

#define MAX_TASKS 30
#define DAILY_TASK_COUNT 10
#define REWARD 15000
#define BONUS_REWARD 20000
#define BONUS_COINS 10

new playerRewards[MAX_PLAYERS];
new RandomTasks[MAX_TASKS];

new LSPDtasks[MAX_TASKS][128] = {
    "Lobe 3 Personen",
    "Mache 5 Drogenschnelltest bei Mitgliedern einer Gang/Mafia",
    "Mache einen Alkoholtest bei Mitglieder einer Gang/Mafia",
    "Überprüfe 5 Personalausweise",
    "Durchsuche 5 Personen",
    "Zerre 5 Personen in dein Fahrzeug,",
    "Nimm 5 Verbrecher fest",
    "Tötet 5 Verbrecher mit einer MP5 / M4.",
    "Tazer 5 Verbrecher",
    "Entschärfe eine Bombe",
    "Orte einen Gesuchten & töte Ihn",
    "Orte einen Gesuchten & verhafte Ihn",
    "Iss 5 Power Riegel",
    "Iss 5 Kekse",
    "Wechsel 3x deinen Skin",
    "Kaufe ein Lottoticket",
    "Rauche 5 Zigaretten",
    "Trinke außerhalb vom Dienst 2 Bier",
    "Absolviere 2 Fraktions-Aufgaben",
    "Fahr mit einem Beifahrer 20 Kilometer",
    "Fahre mit einem Dienstwagen 10 Kilometer",
    "Mach 10 Werbungen",
    "Angel 20 mal",
    "Telefoniere 3 Minuten an einer Telefonzelle",
    "Equipe dich 7x an der Base",
    "Iss in 2 verschiedenen Restaurants in LV",
    "Iss an 2 verschiedenen Restaurants in SF",
    "Esse an 3 verschiedenen Restaurants in LS",
    "Spiele eine Runde Paintball",
    "Benutze einen Ghettoblaster"
};

new SAMDtasks[MAX_TASKS][128] = {
    "Heile drei Mitglieder einer Gang/Mafia",
    "Heile drei Staats-Mitglieder",
    "Trinke außerhalb vom Dienst 2 Bier",
    "Belebe 5 Mitglieder einer Gang/Mafia",
    "Iss 10 Kekse",
    "Iss 5 Power-Riegel",
    "Fahr mit einem Beifahrer 20 Kilometer",
    "Fahre mit einem Dienstwagen 10 Kilometer",
    "Fahre mit einem Mitglied der Executive 15 Kilometer",
    "Rüste dich drei mal in der Base aus.",
    "Schalte 5 mal Werbung",
    "Fahr 15 Kilometer mit einem Rettungswagen.",
    "Iss in 2 verschiedenen Restaurants in LV",
    "Iss an 2 verschiedenen Restaurants in SF",
    "Esse an 3 verschiedenen Restaurants in LS",
    "Nimm 3 Notrufe an",
    "Wechsel 3x deinen Skin",
    "Lobe 3 Spieler",
    "Fahr mit einem Feuerwehrauto über 5 km/h ",
    "Kaufe dir im Ammunation eine Schutzweste",
    "Spiele eine Runde Paintball.",
    "Wiederbelebe 3 Spieler",
    "Kaufe einen Ghettoblaster",
    "Benutze einen Ghettoblaster",
    "Benutze einen Booster",
    "Kaufe dir Kekse im 24/7",
    "Lösch einen Hausbrand",
    "Absolviere 2 Fraktions-Aufgaben",
    "Fahr mit einem Beifahrer 20 Kilometer",
    "Spiele eine Runde im Casino"
};

new OAMTtasks[MAX_TASKS][128] = {
"Lobe 3 Spieler",
"Kaufe ein Lotto-Ticket",
"Rauche 5 Zigaretten",
"Iss 10 Kekse",
"Trinke außerhalb vom Dienst ein Bier",
"Absolviere 2 Aufgaben",
"Fahr mit einem Beifahrer 20 Kilometer",
"Lege mit einem TowTruck über 10 km zurück.",
"Schalte 4 Werbungen.",
"Schlepp ein Fahrzeug ab",
"Schreibe 3 Strafzettel",
"Telefoniere 3 Minuten an einer Telefonzelle",
"Konsumiert 5 Power-Riegel",
"Equipe dich 7x an der Base",
"Iss in 2 verschiedenen Restaurants in LV",
"Iss an 2 verschiedenen Restaurants in SF",
"Esse an 3 verschiedenen Restaurants in LS",
"Kaufe dir eine Schutzweste im Ammunation",
"Spiele eine Runde Paintball.",
"Benutze einen Ghettoblaster",
"Gib jemanden Punkte auf den Führerschein",
"Gib jemanden eine Haustier-Sperre",
"Durchsuche 3 Spieler",
"Stelle eine Straßensperre auf",
"Schleppe ein Motorrad ab",
"Kauf einen Booster",
"Stelle einen Mobilen Blitzer auf",
"Mach einen Alkoholtest bei einem Spieler",
"Durchsuche einen Koffer eines Spielers",
"Kauf dir 3 Booster"
};

new ZIVItasks[MAX_TASKS][128] = {
"Miete dir 5 Roller",
"Benutze einen Ghettoblaster",
"Brich in 3 Häuser ein",
"Überfalle eine Tankstelle",
"Repariere als Mechaniker 5 Fahrzeuge",
"Tanke 10 Fahrzeuge als Mechaniker",
"Trinke in einer Bar 3x Soda",
"Erreiche insgesamt 5 Paydays",
"Spiel eine Runde im Paintball",
"Lass dich von Medic 3x healen",
"Nutzte 5 Mal /Service",
"Mache einen Schein bei der Fahrschule",
"Fahr mit einem Beifahrer über 75 km/h",
"Fahr mit einem Flugzeug über 100 km/h",
"Tanke an 3 Tankstellen",
"Kaufe 3 mal in einem 24/7 ein",
"Kaufe dir ein Koffer",
"Überfall die Asservatenkammer",
"Lande als Schwervebrecher im Alkatraz",
"Setze einen Killauftrag auf einen Spieler",
"Benutze einen Getränkeautomaten",
"Iss 3 in einem Restaurant in Los Santos",
"Telefoniere 3 Minuten an einer Telefonzelle",
"Brich aus dem Gefängnis aus",
"Schalte 3 mal eine Werbung",
"Kauf dir etwas im Schwarzmarkt",
"Überfall die Zentralbank",
"Iss 5 Kekse",
"Kauf dir einen Booster",
"Kauf dir ein Lotto-Ticket"
};

new G_Mtasks[MAX_TASKS][128] = {
"Mache 10 Kills in Gangfights",
"Verkaufe Drogen",
"Lobe 3 Spieler",
"Equipt euch 50x an der Base",
"Baue 50 Gangpflanzen an",
"Raub die Asservatenkammer aus",
"Kaufe etwas im Schwarzmarkt",
"Raub die Nine Demons aus",
"Starte einen Casino Raub",
"Sammel Pfandflaschen",
"Gewinnt einen Gangfight",
"Starte einen Bizfight",
"Mache 5 Streetwar Kills",
"Nimm 10 mal Spice",
"Kaufe 3 Booster",
"Brich aus dem Gefängnis aus",
"Iss 5 Power-Riegel",
"Raub die Zentralbank aus",
"Spiel ein Spiel im Casino",
"Kauf dir ein Lotto-Ticket",
"Schließe 2 Fraktions-Aufgaben ab",
"Geh mit deinem Haustier spazieren",
"Tanke 4 Autos auf",
"Farme 50 Gangpflanzen Samen",
"Mache einen Killauftrag auf einen Spieler",
"Lege Waffenteile ins Waffenlager",
"Lege Spice in die Fraktionssafebox",
"Schalte 3 mal eine Werbung",
"Entführe einen Spieler",
"Nimm einen Booster ein"
};

new completedTasks[MAX_FACTIONS][MAX_TASKS];
new activeFactionTasks[MAX_FACTIONS][DAILY_TASK_COUNT];
new completedFactionTasks[MAX_FACTIONS];
new taskRewards[MAX_FACTIONS][MAX_TASKS];

hook OnGameModeInit()
{
    StartNewDay();
}

CMD:frakaufgaben(playerid,params[]) {
    return ShowTaskDialog(playerid);
}
forward ShowTaskDialog(playerid);
public ShowTaskDialog(playerid)
{
    // Überprüfen, ob der Spieler alle Aufgaben erledigt hat
    if (AlleAufgabenErledigt(playerid))
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Alle Aufgaben für heute sind erledigt");
        return 1;
    }

    // Dialog mit verfügbaren Aufgaben anzeigen
    new dialogText[1024], string[512];
    for (new i = 0; i < DAILY_TASK_COUNT; i++)
    {
        new taskIndex = activeFactionTasks[GetPlayerFaction(playerid)][i];
        format(string,sizeof(string),"{FF0000}Diese Aufgabe wird bereits von {00FF00}%s {FF0000}erledigt", GetTaskCompleter(playerid, taskIndex));
        if(completedTasks[GetPlayerFaction(playerid)][taskIndex]) {
            format(dialogText, sizeof(dialogText), "%s%s\t$%s\n", dialogText, string, AddDelimiters(REWARD));
        } else {
            if(IsPlayerExecutive(playerid)) {
                format(dialogText, sizeof(dialogText), "%s%s\t$%s\n", dialogText, LSPDtasks[taskIndex], AddDelimiters(REWARD));
            } else if(Spieler[playerid][pFraktion] == 3) {
                format(dialogText, sizeof(dialogText), "%s%s\t$%s\n", dialogText, SAMDtasks[taskIndex], AddDelimiters(REWARD));
            } else if(Spieler[playerid][pFraktion] == 5) {
                format(dialogText, sizeof(dialogText), "%s%s\t$%s\n", dialogText, OAMTtasks[taskIndex], AddDelimiters(REWARD));
            } else if(Spieler[playerid][pFraktion] == 0) {
                format(dialogText, sizeof(dialogText), "%s%s\t$%s\n", dialogText, ZIVItasks[taskIndex], AddDelimiters(REWARD));
            } else if(IsAFightFaction(Spieler[playerid][pFraktion])) {
                format(dialogText, sizeof(dialogText), "%s%s\t$%s\n", dialogText, G_Mtasks[taskIndex], AddDelimiters(REWARD));
            }
        }
        
    }
    format(dialogText,sizeof(dialogText),"Aufgabe\tBelohnung\n%s",dialogText);
    ShowPlayerDialog(playerid, DIALOG_FRAGEN, DIALOG_STYLE_TABLIST_HEADERS, "Wähle eine Aufgabe",dialogText, "Akzeptieren", "Abbrechen");
    
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if (dialogid == DIALOG_FRAGEN && response)
    {
        // Spieler hat eine Aufgabe ausgewählt
        new taskIndex = activeFactionTasks[GetPlayerFaction(playerid)][listitem];

        if (!completedTasks[GetPlayerFaction(playerid)][taskIndex])
        {
            if(IsPlayerExecutive(playerid)) {
                SCMFormatted(playerid, COLOR_GREEN, "Aufgabe akzeptiert: %s",LSPDtasks[taskIndex]);
            } else if(Spieler[playerid][pFraktion] == 3) {
                SCMFormatted(playerid, COLOR_GREEN, "Aufgabe akzeptiert: %s",SAMDtasks[taskIndex]);
            } else if(Spieler[playerid][pFraktion] == 5) {
                SCMFormatted(playerid, COLOR_GREEN, "Aufgabe akzeptiert: %s",OAMTtasks[taskIndex]);
            } else if(Spieler[playerid][pFraktion] == 0) {
                SCMFormatted(playerid, COLOR_GREEN, "Aufgabe akzeptiert: %s",ZIVItasks[taskIndex]);
            } else if(IsAFightFaction(Spieler[playerid][pFraktion])) {
                SCMFormatted(playerid, COLOR_GREEN, "Aufgabe akzeptiert: %s",G_Mtasks[taskIndex]);
            }
            completedTasks[GetPlayerFaction(playerid)][taskIndex] = true;
            GiveTaskReward(playerid, taskIndex);

            // Überprüfen, ob die Fraktion alle Aufgaben erledigt hat
            if (AlleFactionAufgabenErledigt(GetPlayerFaction(playerid)))
            {
                new string[128];
                format(string,sizeof(string),"Die Fraktion %s hat alle Aufgaben für heute erledigt!",GetFactionNameOfFaction(GetPlayerFaction(playerid)));
                SendClientMessageToAll(COLOR_YELLOW, string);
                completedFactionTasks[GetPlayerFaction(playerid)] = true;
            }
        }
        else
        {
            SCMFormatted(playerid, COLOR_RED, "Diese Aufgabe wurde bereits erledigt von %s", GetTaskCompleter(playerid, taskIndex));
        }
    }
    return 1;
}

forward StartNewDay(); 
public StartNewDay()
{
    // Hier können Sie neue tägliche Aufgaben generieren und andere Aktionen für einen neuen Tag durchführen.
    for (new i = 0; i < MAX_FACTIONS; i++)
    {
        GenerateDailyTasks(i);
        completedFactionTasks[i] = false;
    }
}

forward GenerateDailyTasks(faction);
public GenerateDailyTasks(faction)
{
    // Zufällige Auswahl von DAILY_TASK_COUNT Aufgaben für die Fraktion
    for (new i = 0; i < DAILY_TASK_COUNT; i++)
    {
        if(RandomTasks[i] == 1) continue;
        RandomTasks[i] = 1;
        activeFactionTasks[faction][i] = Random(MAX_TASKS - 1);
    }
}

forward AlleAufgabenErledigt(playerid); 
public AlleAufgabenErledigt(playerid)
{
    for (new i = 0; i < DAILY_TASK_COUNT; i++)
    {
        if (!completedTasks[GetPlayerFaction(playerid)][activeFactionTasks[GetPlayerFaction(playerid)][i]])
            return 0;
    }
    return 1;
}

forward AlleFactionAufgabenErledigt(faction);
public AlleFactionAufgabenErledigt(faction)
{
    for (new i = 0; i < DAILY_TASK_COUNT; i++)
    {
        if (!completedTasks[faction][activeFactionTasks[faction][i]])
            return 0;
    }
    return 1;
}

forward GiveTaskReward(playerid, taskIndex);
public GiveTaskReward(playerid, taskIndex)
{
    playerRewards[playerid] += REWARD;
    taskRewards[GetPlayerFaction(playerid)][taskIndex] = REWARD;
}

forward GiveBonusReward(playerid);
public GiveBonusReward(playerid)
{
    playerRewards[playerid] += BONUS_REWARD;
}
 
stock GetTaskReward(playerid, taskIndex)
{
    new string[128];
    if (completedTasks[GetPlayerFaction(playerid)][taskIndex])
    {
        format(string,sizeof(string),"Erledigt von %s", GetTaskCompleter(playerid, taskIndex));
    }
    else
    {
        format(string,sizeof(string),"%d - %d$", taskRewards[GetPlayerFaction(playerid)][taskIndex], taskRewards[GetPlayerFaction(playerid)][taskIndex]);
    }
    return string;
}

stock GetTaskCompleter(playerid, taskIndex)
{
    new string[128];
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        if (completedTasks[GetPlayerFaction(playerid)][taskIndex] && taskRewards[GetPlayerFaction(playerid)][taskIndex] > 0)
        {
            format(string,sizeof(string),"%s",GetName(i));
            return string;
        } else {
            format(string,sizeof(string),"");
        }
    }
    return string;
}
