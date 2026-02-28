#include <YSI\y_hooks>

#define GB_GHETTOBLASTER_RANGE              20.0
#define GB_GHETTOBLASTER_RANGE_THRESHOLD    25.0
#define DIALOG_GHETTOSTREAM					6000

static enum GB_enum {
    GB_objID,
    Text3D:GB_t3DID,
    GB_areaID,
    GB_streamURL[256],
    Float:GB_posX,
    Float:GB_posY,
    Float:GB_posZ
}

static GB_ghettoBlasters[MAX_PLAYERS][GB_enum];

static GB_stations[] = "1-Live\nTechnoBase.FM\nHardBase.FM\nI Love Radio\nBreakz.us\nYouFM\nPlanet Radio\nThe Club\nNightWax\nI Love Mashup\nDas Hitradio\nI Love the Battle\nI Love 2Dance\nLogin-Musik\niTunes Hot 40\nEigener Audiostream"; // don't forget to adjust the listitem in the OnPlayerDialog

hook OnPlayerDisconnect(playerid) {
    if (IsValidDynamicObject(GB_ghettoBlasters[playerid][GB_objID]))
        removeGhettoBlaster(playerid);

    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid) {
    GC_StartStream(playerid, areaid);

    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid) {
    GC_StopStream(playerid, areaid);

    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    if (response) {
        switch (dialogid) {
            case DIALOG_GHETTOBLASTER: {
                if (!IsValidDynamicObject(GB_ghettoBlasters[playerid][GB_objID]))
                    return SendClientMessage(playerid, COLOR_DARKRED, "Dein Ghettoblaster ist nicht (mehr) aufgestellt.");

                switch (listitem) {
                    case 0: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://www.wdr.de/wdrlive/media/einslive.m3u"); }
                    case 1: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://listen.technobase.fm/tunein-dsl-pls"); }
                    case 2: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://listen.hardbase.fm/tunein-mp3-pls"); }
                    case 3: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://iloveradio.de/iloveradio.m3u"); }
                    case 4: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://breakz.us/radio/listen.m3u"); }
                    case 5: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://metafiles.gl-systemhaus.de/hr/youfm_2.m3u"); }
                    case 6: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://streams.planetradio.de/planetradio/mp3/hqlivestream.m3u"); }
                    case 7: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://streams.planetradio.de/plrchannels/mp3/hqtheclub.m3u"); }
                    case 8: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://streams.planetradio.de/plrchannels/mp3/hqnightwax.m3u"); }
                    case 9: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "https://streams.ilovemusic.de/iloveradio2.mp3"); }
                    case 10: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://skyserver5.skydisc.net:8000/listen.pls"); }
                    case 11: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "https://streams.ilovemusic.de/iloveradio5.mp3"); }
                    case 12: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "https://streams.ilovemusic.de/iloveradio3.mp3"); }
                    case 13: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, URL_LOGINMUSIC); }
                    case 14: { format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "http://mp3.planetradio.de/plrchannels/hqitunes.mp3"); }
					case 15: {
						return ShowPlayerDialog(playerid, DIALOG_GHETTOSTREAM, DIALOG_STYLE_INPUT, "Eigene Musik", "Füge einen Steaminglink ein. Diese Enden z.B. mit .mp3, .asx, .m3u", "Start", "Abbrechen");
					}
                }

                for (new i = 0; i <= GetPlayerPoolSize(); i++)
                    if (IsPlayerInDynamicArea(i, GB_ghettoBlasters[playerid][GB_areaID]))
                        GC_StartStream(i, GB_ghettoBlasters[playerid][GB_areaID]);

                return 1;
            }

            case DIALOG_ADMIN_GHETTOBLASTER: {
                new gbID = strval(inputtext); // TODO: validate input

                if (!IsValidDynamicObject(GB_ghettoBlasters[gbID][GB_objID]))
                    return SendClientMessage(playerid, COLOR_DARKRED, "Der Ghettoblaster ist nicht (mehr) aufgestellt.");

                SetPlayerPosEx(playerid, GB_ghettoBlasters[gbID][GB_posX], GB_ghettoBlasters[gbID][GB_posY], GB_ghettoBlasters[gbID][GB_posZ] + 2.0, 0, 0);
                return 1;
            }
			
			case DIALOG_GHETTOSTREAM: {
				if(response)
				{
					new String[128];
					format(String, sizeof(String), "%s", inputtext);
					format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "%s", String);
					for (new i = 0; i <= GetPlayerPoolSize(); i++)
						if (IsPlayerInDynamicArea(i, GB_ghettoBlasters[playerid][GB_areaID]))
							GC_StartStream(i, GB_ghettoBlasters[playerid][GB_areaID]);
					return 1;
           	}
        }
        }
    }

    return 1;
}

stock GC_StartStream(playerid, areaid) {
    // Wrapper cause samp is buggy
    for (new i = 0; i <= GetPlayerPoolSize(); i++) {
        if (IsValidDynamicArea(GB_ghettoBlasters[i][GB_areaID]) && areaid == GB_ghettoBlasters[i][GB_areaID] && strlen(GB_ghettoBlasters[i][GB_streamURL]) > 0) { // TODO: Check for other streams (MP3 & Radio)
            if (GetPVarInt(playerid, "GB.ON"))
                StopAudioStreamForPlayer(playerid);
            
            SetPVarInt(playerid, "GB.ON", 1);
            return PlayAudioStreamForPlayer(playerid, GB_ghettoBlasters[i][GB_streamURL], GB_ghettoBlasters[i][GB_posX], GB_ghettoBlasters[i][GB_posY], GB_ghettoBlasters[i][GB_posZ], GB_GHETTOBLASTER_RANGE, 1);
        }
    }

    return 1;
}

stock GC_StopStream(playerid, areaid) {
    // Wrapper cause samp is buggy
    for (new i = 0; i <= GetPlayerPoolSize(); i++) {
        if (IsValidDynamicArea(GB_ghettoBlasters[i][GB_areaID]) && areaid == GB_ghettoBlasters[i][GB_areaID]) { // TODO: Check for other streams (MP3 & Radio)
            DeletePVar(playerid, "GB.ON");
            return StopAudioStreamForPlayer(playerid);
        }
    }

    return 1;
}

stock removeGhettoBlaster(playerid) {
    for (new i = 0; i <= GetPlayerPoolSize(); i++)
        if (IsPlayerInDynamicArea(i, GB_ghettoBlasters[playerid][GB_areaID])) // TODO: Check for other streams (MP3 & Radio)
            GC_StopStream(i, GB_ghettoBlasters[playerid][GB_areaID]);

    DestroyDynamicObject(GB_ghettoBlasters[playerid][GB_objID]);
    DestroyDynamicObject(GB_ghettoBlasters[playerid][GB_objID]);
    DestroyDynamic3DTextLabel(GB_ghettoBlasters[playerid][GB_t3DID]);
    DestroyDynamicArea(GB_ghettoBlasters[playerid][GB_areaID]);

    GB_ghettoBlasters[playerid][GB_objID] = INVALID_STREAMER_ID;
    GB_ghettoBlasters[playerid][GB_t3DID] = Text3D:INVALID_STREAMER_ID;
    GB_ghettoBlasters[playerid][GB_areaID] = INVALID_STREAMER_ID;
    format(GB_ghettoBlasters[playerid][GB_streamURL], 256, "");
    GB_ghettoBlasters[playerid][GB_posX] = 0.0;
    GB_ghettoBlasters[playerid][GB_posY] = 0.0;
    GB_ghettoBlasters[playerid][GB_posZ] = 0.0;

    return 1;
}

stock IsPlayerNotIdle(playerid) { // Falling, Jumping, Swimming, Skydiving
    new index = GetPlayerAnimationIndex(playerid);
    if (index >= 958 && index <= 979 || 1196 <= index <= 1198 || 1538 <= index <= 1544 || index == 1134 || index == 1130 || index == 1195 || index == 1132) return 1;
    return 0;
}

CMD:ghettoblaster(playerid, params[]) {
    if (!Spieler[playerid][pMP3Player])
        return SendClientMessage(playerid, COLOR_DARKRED, "Du besitzt keinen Ghettoblaster.");

    if (Spieler[playerid][pTot] || IsPlayerInAnyVehicle(playerid) || IsPlayerNotIdle(playerid))
        return SendClientMessage(playerid, COLOR_DARKRED, "Du kannst gerade keinen Ghettoblaster aufstellen.");

    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
        return SendClientMessage(playerid, COLOR_DARKRED, "Du musst draussen sein, um ein Ghettoblaster aufstellen zu können.");

    if (IsValidDynamicObject(GB_ghettoBlasters[playerid][GB_objID])) {
        if (!IsPlayerInRangeOfPoint(playerid, 3.0, GB_ghettoBlasters[playerid][GB_posX], GB_ghettoBlasters[playerid][GB_posY], GB_ghettoBlasters[playerid][GB_posZ]))
            return SendClientMessage(playerid, COLOR_DARKRED, "Du bist nicht nahe genug an deinem Ghettoblaster, um den einzustellen.");

        return ShowPlayerDialog(playerid, DIALOG_GHETTOBLASTER, DIALOG_STYLE_LIST, "Verfügbare Radiostationen", GB_stations, "Auswählen", "Abbrechen");
    }

    for (new i = 0; i <= GetPlayerPoolSize(); i++) {
        if (!IsValidDynamicObject(GB_ghettoBlasters[i][GB_objID]))
            continue;

        if (IsPlayerInRangeOfPoint(playerid, GB_GHETTOBLASTER_RANGE + GB_GHETTOBLASTER_RANGE_THRESHOLD, GB_ghettoBlasters[i][GB_posX], GB_ghettoBlasters[i][GB_posY], GB_ghettoBlasters[i][GB_posZ]))
            return SendClientMessage(playerid, COLOR_DARKRED, "Hier in der Nähe hat bereits jemand ein Ghettoblaster aufgestellt.");
    }

    new Float:fX, Float:fY, Float:fZ, Float:fR;
    GetPlayerPos(playerid, fX, fY, fZ);
    GetPlayerFacingAngle(playerid, fR);

    fX += (0.8 * floatsin(-fR, degrees));
    fY += (0.8 * floatcos(-fR, degrees));
    fZ -= 1.0;

    new labelString[64];
    format(labelString, sizeof(labelString), "[ " COLOR_HEX_LIGHTBLUE "Ghettoblaster von %s (%i) " COLOR_HEX_BLUE """]", GetName(playerid), playerid);

    GB_ghettoBlasters[playerid][GB_objID] = CreateDynamicObject(2226, fX, fY, fZ, 0.0, 0.0, fR);
    GB_ghettoBlasters[playerid][GB_t3DID] = Text3D:CreateDynamic3DTextLabel(labelString, COLOR_BLUE, fX, fY, fZ + 0.6, 5.0);
    GB_ghettoBlasters[playerid][GB_areaID] = CreateDynamicSphere(fX, fY, fZ, GB_GHETTOBLASTER_RANGE);
    GB_ghettoBlasters[playerid][GB_posX] = fX;
    GB_ghettoBlasters[playerid][GB_posY] = fY;
    GB_ghettoBlasters[playerid][GB_posZ] = fZ;

    ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
    cmd_me(playerid, "platziert einen Ghettoblaster.");

    // Load fix
    for (new i = 0; i <= GetPlayerPoolSize(); i++)
        if (IsPlayerInRangeOfPoint(i, GB_GHETTOBLASTER_RANGE, fX, fY, fZ))
            Streamer_UpdateEx(i, fX, fY, fZ);

    return ShowPlayerDialog(playerid, DIALOG_GHETTOBLASTER, DIALOG_STYLE_LIST, "Verfügbare Radiostationen", GB_stations, "Auswählen", "Abbrechen");
}

CMD:rghettoblaster(playerid, params[]) return cmd_removeghettoblaster(playerid, params);

CMD:removeghettoblaster(playerid, params[]) {
    if (!IsValidDynamicObject(GB_ghettoBlasters[playerid][GB_objID]) && Spieler[playerid][pAdmin] < 1)
        return SendClientMessage(playerid, COLOR_DARKRED, "Du hast kein Ghettoblaster aufgestellt.");

    // loop cuz admin check don't flame plz
    for (new i = 0; i <= GetPlayerPoolSize(); i++) {
        if (!IsValidDynamicObject(GB_ghettoBlasters[i][GB_objID]))
            continue;

        if (!IsPlayerInRangeOfPoint(playerid, 3.0, GB_ghettoBlasters[i][GB_posX], GB_ghettoBlasters[i][GB_posY], GB_ghettoBlasters[i][GB_posZ]))
            continue;
        
        // Own ghettoblaster
        if (i == playerid) {
            removeGhettoBlaster(playerid);
            cmd_me(playerid, "packt seinen Ghettoblaster wieder ein.");
            return SendClientMessage(playerid, COLOR_LIGHTBLUE, "Du hast dein Ghettoblaster eingepackt.");
        }

        // Admin action
        if (Spieler[playerid][pAdmin]) {
            removeGhettoBlaster(i);
            SCMFormatted(i, COLOR_DARKRED, "%s %s hat deinen Ghettoblaster entfernt.", GetPlayerAdminRang(playerid), GetName(playerid));
            return SCMFormatted(playerid, COLOR_LIGHTBLUE, "Du hast den Ghettoblaster von %s entfernt.", GetName(i));
        }
    }

    return SendClientMessage(playerid, COLOR_DARKRED, "Du stehst nicht nahe genug an einem Ghettoblaster, um den wieder einzupacken.");
}

CMD:gotoghettoblaster(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 1)
        return SendClientMessage(playerid, COLOR_DARKRED, "Du besitzt nicht die benötigten Rechte.");

    new string[128];

    for (new i = 0; i <= GetPlayerPoolSize(); i++)
        if (IsValidDynamicObject(GB_ghettoBlasters[i][GB_objID]))
            format(string, sizeof(string), "%s%i\n", string, i);

    if (!strlen(string))
        return SendClientMessage(playerid, COLOR_DARKRED, "Momentan sind keine Ghettoblaster aufgestellt.");

    return ShowPlayerDialog(playerid, DIALOG_ADMIN_GHETTOBLASTER, DIALOG_STYLE_LIST, "Aufgestellte Ghettoblaster (IDs)", string, "Teleportieren", "Abbrechen");
}
