#include <YSI\y_hooks>

const Float:AUTOBOMB_EXPLOSION_RADIUS = 20.0;
const AUTOBOMB_DETONATION_TIME = 10; // in Sekunden
const Float:AUTOBOMB_DAMAGE = 200.0; // Maximale Schadensgrenze

new Float:autobombPosition[3];
new bool:isAutobombActive = false;
new autobombArea;
new AutobombDraht;


CMD:autobombe(playerid,params[]) {
    if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER) 
    ShowPlayerDialog(playerid,DIALOG_WIRE_SELECTION,DIALOG_STYLE_LIST,"Autobombe-Drahtauswahl","Rot\nBlau\nGelb\nGrün","Okay","Abbrechen");
    else SendClientMessage(playerid, -1, "Du musst im Fahrzeug sein, um eine Autobombe zu legen oder zu entschärfen!");
    return 1;
}

hook OnPlayerDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    if (response){
            switch(dialogid) {
                case DIALOG_WIRE_SELECTION: {
                    switch(listitem) {
                        case 0: {
                            AutobombDraht = 0;
                        } case 1: {
                            AutobombDraht = 1;
                        } case 2: {
                            AutobombDraht = 2;
                        } case 3: {
                            AutobombDraht = 3;
                        }
                    }
                    if(!isAutobombActive) {
                        GetPlayerPos(playerid, autobombPosition[0], autobombPosition[1], autobombPosition[2]);
                        isAutobombActive = true;
                        SetTimerEx("OnAutobombExplodeTimer", AUTOBOMB_DETONATION_TIME * 1000, false,"d",playerid);
                        ShowAutobombArea();
                        SendClientMessageToAll(COLOR_RED,"Die Nine-Demons haben eine Autobombe platziert die in 5 Minuten explodieren wird.");
                    } else {
                        if(listitem == AutobombDraht) {
                            SendClientMessageToAll(COLOR_GREEN,"Das Los Santos Police Department hat erfolgreich eine Autobombe entschärft.");
                            isAutobombActive = false;
                        } else {
                            SendClientMessageToAll(COLOR_RED,"Das Los Santos Police Department hat es nicht geschafft die Autobombe zu entschärfen.");
                            ExplodeAutobomb();
                        }
                    }
                }
            }
        }
    return 1;
}

stock OnAutobombExplodeTimer()
{
    if (isAutobombActive)
    {
        ExplodeAutobomb();
    }
    return 1;
}

stock ExplodeAutobomb()
{
    new Float:pos[3];
    pos[0] = autobombPosition[0];
    pos[1] = autobombPosition[1];
    pos[2] = autobombPosition[2];

    // Implementiere die Explosion
    CreateExplosion(pos[0], pos[1], pos[2], 2, 500.0);

    // Zerstöre Fahrzeuge in der Nähe
    for (new i = 0; i < MAX_VEHICLES; i++)
    {
        new Float:pos2[3];
        GetVehiclePos(i, pos2[0], pos2[1], pos2[2]);
        if (IsValidVehicle(i) && GetDistanceBetweenPoints(pos[0], pos[1], pos[2], pos2[0], pos2[1], pos2[2]) <= AUTOBOMB_EXPLOSION_RADIUS)
        {
            DestroyVehicle(i);
        }
    }

    // Überprüfe, ob Spieler in der Nähe sind
    new Float:distance;
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        if (IsPlayerConnected(i))
        {
            new Float:pos2[3];
            GetPlayerPos(i, pos2[0], pos2[1], pos2[2]);
            distance = GetDistanceBetweenPoints(pos[0], pos[1], pos[2], pos2[0], pos2[1], pos2[2]);

            if (distance <= AUTOBOMB_EXPLOSION_RADIUS)
            {
                ApplyAutobombDamage(i, distance);
            }
        }
    }

    // Deaktiviere die Autobombe
    isAutobombActive = false;

    // Entferne die GangZone
    RemoveAutobombArea();
}

stock ApplyAutobombDamage(playerid, Float:distance)
{
    new Float:damage = AUTOBOMB_DAMAGE * (1.0 - (distance / AUTOBOMB_EXPLOSION_RADIUS));
    new Float:armor = GetPlayerArmour(playerid);
    new Float:health = GetPlayerHealth(playerid);

    // Kombinierte Gesundheit und Rüstung
    new Float:combinedHealthArmor = health + armor;

    if (damage > 0.0)
    {
        // Reduziere Schaden basierend auf der Rüstung des Spielers
        if (armor > 0.0)
        {
            if (damage >= armor)
            {
                damage -= armor;
                SetPlayerArmour(playerid, 0.0);
            }
            else
            {
                SetPlayerArmour(playerid, armor - damage);
                damage = 0.0;
            }
        }

        // Setze die neue Gesundheit des Spielers
        combinedHealthArmor -= damage;

        // Überprüfe, ob der kombinierte Wert von Leben und Rüstung den maximalen Schaden erreicht
        if (combinedHealthArmor <= 0.0)
        {
            SetPlayerHealth(playerid, 0.0);
            SetPlayerArmour(playerid, 0.0);
        }
        else
        {
            // Verteile den verbleibenden Schaden auf Leben und Rüstung
            if (combinedHealthArmor <= health)
            {
                SetPlayerHealth(playerid, health - damage);
            }
            else
            {
                SetPlayerHealth(playerid, 0.0);
                SetPlayerArmour(playerid, combinedHealthArmor - health);
            }
        }
    }
}

stock ShowAutobombArea()
{
    new Float:pos[3];
    pos[0] = autobombPosition[0];
    pos[1] = autobombPosition[1];
    pos[2] = autobombPosition[2];
    autobombArea = GangZoneCreate(pos[0] - AUTOBOMB_EXPLOSION_RADIUS, pos[1] - AUTOBOMB_EXPLOSION_RADIUS, pos[0] + AUTOBOMB_EXPLOSION_RADIUS, pos[1] + AUTOBOMB_EXPLOSION_RADIUS);
    foreach(new i : Player) {
		if (IsPlayerConnected(i) && gPlayerLogged[i]) {
			if (IsPlayerNPC(i)) continue;  
            if(IsPlayerExecutive(i)) {
                GangZoneShowForPlayer(i, autobombArea, COLOR_RED);
            }       
        }
    }
}

stock RemoveAutobombArea()
{
    GangZoneDestroy(autobombArea);
}
