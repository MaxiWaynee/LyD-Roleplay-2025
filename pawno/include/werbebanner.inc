#define MAX_WERBEBANNER 50

enum e_Werbebanner {
	W_iID,
	Float:W_fX,
	Float:W_fY,
	Float:W_fZ,
	Text3D:W_t3dLabel,
	W_iPickup,

	W_iObjectID,
	W_iModelID,
	Float:W_fObjX,
	Float:W_fObjY,
	Float:W_fObjZ,
	Float:W_fObjRotX,
	Float:W_fObjRotY,
	Float:W_fObjRotZ,

	W_sText[256],
	W_iMaterialIndex,
	W_iMaterialSize,
	W_iFontFace[32],
	W_iFontSize,
	W_iBold,
	W_iFontColor,
	W_iBackColor,
	W_iTextAlignment,

	W_unixBought,
	W_sOwner[MAX_PLAYER_NAME]
};

new g_iWerbebanner, g_Werbebanner[MAX_WERBEBANNER][e_Werbebanner];

enum E_MAT_SIZE {
    MAT_SIZE_NAME[8],
    MAT_SIZE_VALUE,
}

new const g_MatSizes[][E_MAT_SIZE] = {
    {"32x32",   10},
    {"64x32",   20},
    {"64x64",   30},
    {"128x32",  40},
    {"128x64",  50},
    {"128x128", 60},
    {"256x32",  70},
    {"256x64",  80},
    {"256x128", 90},
    {"256x256", 100},
    {"512x64",  110},
    {"512x128", 120},
    {"512x256", 130},
    {"512x512", 140}
};

enum E_TEXT_COLOR {
	TEXT_COLOR_NAME[12],
	TEXT_COLOR_EMBEDDED[9],
	TEXT_COLOR_VALUE
}

new const g_textColors[][E_TEXT_COLOR] = {
	{"Rot", "{FF0000}", 0xFFFF0000},
	{"Grün", "{04B404}", 0xFF04B404},
	{"Blau", "{0000FF}", 0xFF0000FF},
	{"Gelb", "{FFFF00}", 0xFFFFFF00},
	{"Pink", "{FF00FF}", 0xFFFF00FF},
	{"Grau", "{848484}", 0xFF848484},
	{"Weiß", "{FFFFFF}", 0xFFFFFFFF},
	{"Grün-Blau", "{00B5CD}", 0xFF00B5CD}
};

stock InitWerbebanner() {
	mysql_oquery("SELECT * FROM `werbetafel`", THREAD_WERBEBANNER, INVALID_OBJECT_ID, gSQL);
	SetTimer("SaveWerbebanner", 99989 * 5, true);
	SetTimer("CheckWerbebanner", 30103, true);
	return 1;
}

forward CheckWerbebanner();
public CheckWerbebanner() {
	new playerid, now = gettime();
	for (new i; i < g_iWerbebanner; i++) {
	    if (g_Werbebanner[i][W_unixBought] <= 0 || now < g_Werbebanner[i][W_unixBought]) continue;
        if (!strcmp("Niemand", g_Werbebanner[i][W_sOwner], true)) continue;
		sscanf(g_Werbebanner[i][W_sOwner], "u", playerid);
		if (playerid != INVALID_PLAYER_ID) SendClientMessage(playerid, COLOR_YELLOW, "Deine Werbetafelmiete ist abgelaufen!");
		WerbetafelZuVermieten(i);
		UpdateObject(i);
	}
	return 1;
}

forward SaveWerbebannerEx(index);
public SaveWerbebannerEx(index) {
	new query[800], text[256], font[32];
    mysql_real_escape_string(g_Werbebanner[index][W_sText], text, gSQL, sizeof(text));
    mysql_real_escape_string(g_Werbebanner[index][W_iFontFace], font, gSQL, sizeof(font));
    format(query, sizeof(query), "UPDATE `werbetafel` SET \
        `IconX` = '%.2f',\
        `IconY` = '%.2f',\
        `IconZ` = '%.2f',\
        `ModelID` = '%d',\
        `ObjectX` = '%.2f',\
        `ObjectY` = '%.2f',\
        `ObjectZ` = '%.2f',\
        `RotX` = '%.2f',\
        `RotY` = '%.2f',\
        `RotZ` = '%.2f',\
        `Text` = '%s',\
        `MaterialIndex` = '%d',\
        `MaterialSize` = '%d',\
        `FontFace` = '%s',\
        `FontSize` = '%d',\
        `Bold` = '%d',\
        `FontColor` = '%d',\
        `BackColor` = '%d',\
        `TextAlignment` = '%d',\
        `UnixTimestamp` = '%d',\
        `Besitzer` = '%s' \
        WHERE `ID` = '%d'",
			g_Werbebanner[index][W_fX],
			g_Werbebanner[index][W_fY],
			g_Werbebanner[index][W_fZ],
			g_Werbebanner[index][W_iModelID],
			g_Werbebanner[index][W_fObjX],
			g_Werbebanner[index][W_fObjY],
			g_Werbebanner[index][W_fObjZ],
			g_Werbebanner[index][W_fObjRotX],
			g_Werbebanner[index][W_fObjRotY],
			g_Werbebanner[index][W_fObjRotZ],
			text,
			g_Werbebanner[index][W_iMaterialIndex],
			g_Werbebanner[index][W_iMaterialSize],
			font,
			g_Werbebanner[index][W_iFontSize],
			g_Werbebanner[index][W_iBold],
			g_Werbebanner[index][W_iFontColor],
			g_Werbebanner[index][W_iBackColor],
			g_Werbebanner[index][W_iTextAlignment],
			g_Werbebanner[index][W_unixBought],
			g_Werbebanner[index][W_sOwner],
			g_Werbebanner[index][W_iID]
	);
	mysql_oquery(query, THREAD_SAVEWERBEBANNER, INVALID_PLAYER_ID, gSQL);
	return 1;
}

forward SaveWerbebanner();
public SaveWerbebanner() {
	new query[800], text[256], font[32];
	for (new i; i < g_iWerbebanner; i++) {
        mysql_real_escape_string(g_Werbebanner[i][W_sText], text, gSQL, sizeof(text));
        mysql_real_escape_string(g_Werbebanner[i][W_iFontFace], font, gSQL, sizeof(font));
	    format(query, sizeof(query), "UPDATE `werbetafel` SET \
	        `IconX` = '%.2f',\
	        `IconY` = '%.2f',\
	        `IconZ` = '%.2f',\
	        `ModelID` = '%d',\
	        `ObjectX` = '%.2f',\
	        `ObjectY` = '%.2f',\
	        `ObjectZ` = '%.2f',\
	        `RotX` = '%.2f',\
	        `RotY` = '%.2f',\
	        `RotZ` = '%.2f',\
	        `Text` = '%s',\
	        `MaterialIndex` = '%d',\
	        `MaterialSize` = '%d',\
	        `FontFace` = '%s',\
	        `FontSize` = '%d',\
	        `Bold` = '%d',\
	        `FontColor` = '%d',\
	        `BackColor` = '%d',\
	        `TextAlignment` = '%d',\
	        `UnixTimestamp` = '%d',\
	        `Besitzer` = '%s' \
	        WHERE `ID` = '%d'",
				g_Werbebanner[i][W_fX],
				g_Werbebanner[i][W_fY],
				g_Werbebanner[i][W_fZ],
				g_Werbebanner[i][W_iModelID],
				g_Werbebanner[i][W_fObjX],
				g_Werbebanner[i][W_fObjY],
				g_Werbebanner[i][W_fObjZ],
				g_Werbebanner[i][W_fObjRotX],
				g_Werbebanner[i][W_fObjRotY],
				g_Werbebanner[i][W_fObjRotZ],
				text,
				g_Werbebanner[i][W_iMaterialIndex],
				g_Werbebanner[i][W_iMaterialSize],
                font,
				g_Werbebanner[i][W_iFontSize],
				g_Werbebanner[i][W_iBold],
				g_Werbebanner[i][W_iFontColor],
				g_Werbebanner[i][W_iBackColor],
				g_Werbebanner[i][W_iTextAlignment],
				g_Werbebanner[i][W_unixBought],
				g_Werbebanner[i][W_sOwner],
				g_Werbebanner[i][W_iID]
		);

		mysql_oquery(query, THREAD_SAVEWERBEBANNER, INVALID_PLAYER_ID, gSQL);
	}

	return 1;
}

stock AddWerbebanner(index) {
	new String[128];
	g_Werbebanner[index][W_iPickup] = CreateDynamicPickup(1239, 1, g_Werbebanner[index][W_fX], g_Werbebanner[index][W_fY], g_Werbebanner[index][W_fZ]);
	if (!strcmp(g_Werbebanner[index][W_sOwner], "Niemand", true)) format(String, sizeof(String), "Diese Werbetafel steht zum Verkauf!\n{FFFFFF}Benutze /Werbetafelkaufen");
	else format(String, sizeof(String), "Besitzer der Werbetafel:\n{FFFFFF}%s", g_Werbebanner[index][W_sOwner]);
	g_Werbebanner[index][W_t3dLabel] = CreateDynamic3DTextLabel(String, 0x28C0D6FF, g_Werbebanner[index][W_fX], g_Werbebanner[index][W_fY] ,g_Werbebanner[index][W_fZ], 30.0, .testlos = 1);
	g_Werbebanner[index][W_iObjectID] = CreateDynamicObject(g_Werbebanner[index][W_iModelID], g_Werbebanner[index][W_fObjX], g_Werbebanner[index][W_fObjY],
		g_Werbebanner[index][W_fObjZ], g_Werbebanner[index][W_fObjRotX], g_Werbebanner[index][W_fObjRotY], g_Werbebanner[index][W_fObjRotZ]);

	UpdateObject(index);
	Streamer_SetFloatData(STREAMER_TYPE_OBJECT, g_Werbebanner[index][W_iObjectID], E_STREAMER_DRAW_DISTANCE, 300.0);
	return 1;
}

stock IsPlayerAtWerbetafel(playerid, Float:distance = 3.0) {
	for (new x = 0; x < g_iWerbebanner; x++)
		if (IsPlayerInRangeOfPoint(playerid, distance, g_Werbebanner[x][W_fX], g_Werbebanner[x][W_fY], g_Werbebanner[x][W_fZ])) return x;

	return 999;
}

COMMAND:atafelentmieten(playerid, params[]) {
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
	if (Spieler[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du besitzt nicht die benötigten Rechte.");
	new werbetafel = IsPlayerAtWerbetafel(playerid);
	if (werbetafel == 999) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht in der Nähe einer Werbetafel.");

	new String[128];
	format(String, sizeof(String), "Admin %s hat Werbetafel Nr. %d freigestellt.", GetName(playerid), werbetafel);
	SendAdminMessage(COLOR_YELLOW, String);

	WerbetafelZuVermieten(werbetafel);
	UpdateObject(werbetafel);
	SaveWerbebannerEx(werbetafel);
	return 1;
}

COMMAND:werbetafelfinden(playerid, params[]) {
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
	new werbetafel = GetPlayerWerbetafel(playerid);
	if (werbetafel == 999) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du besitzt keine Werbetafel.");
	SetPlayerCheckpointEx(playerid, g_Werbebanner[werbetafel][W_fX], g_Werbebanner[werbetafel][W_fY], g_Werbebanner[werbetafel][W_fZ], 2.0, CP_NAVI1);
	return SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Deine Werbetafel wurde auf der Map rot markiert.");
}

COMMAND:werbetafel(playerid, params[]) {
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
	new werbetafel = IsPlayerAtWerbetafel(playerid);
	if (werbetafel == 999) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht in der Nähe einer Werbetafel.");
	if (!strcmp(g_Werbebanner[werbetafel][W_sOwner], GetName(playerid), true)) return ShowWerbetafelMenu(playerid);

	return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Diese Werbetafel gehört nicht dir.");
}

COMMAND:werbetafelkaufen(playerid, params[]) {
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
	new werbetafel = IsPlayerAtWerbetafel(playerid);
	if (werbetafel == 999) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht in der Nähe einer Werbetafel.");
	if (!strcmp(g_Werbebanner[werbetafel][W_sOwner], GetName(playerid), true)) return ShowWerbetafelMenu(playerid);
	if (GetPlayerWerbetafel(playerid) != 999) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du besitzt bereits eine Werbetafel.");
	if (strcmp(g_Werbebanner[werbetafel][W_sOwner], "Niemand", true) != 0) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Diese Werbetafel steht nicht zum Verkauf.");
	return ShowPlayerDialog(playerid, DIALOG_ADBOARD_BUY, DIALOG_STYLE_MSGBOX, "Werbetafel Kaufen",\
		"{FFFFFF}Möchtest du diese Werbetafel kaufen?\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000", "Kaufen", "Abbrechen");
}

stock GetPlayerWerbetafel(playerid) {
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	for (new x = 0; x < g_iWerbebanner; x++) if (!strcmp(g_Werbebanner[x][W_sOwner], name, true)) return x;
	return 999;
}

stock ShowWerbetafelMenu(playerid) {
	return ShowPlayerDialog(playerid, DIALOG_ADBOARD_MAIN, DIALOG_STYLE_LIST, "Werbetafel - Einstellungen",
		COLOR_B "Hilfe\n" COLOR_B "Text ändern\n" COLOR_B "Textgröße ändern\n" COLOR_B "Textfarbe ändern\n" COLOR_B "Schriftart ändern\n" COLOR_B\
		"Textausrichtung ändern\n" COLOR_B "Fettschrift einstellen\n" COLOR_B "Hintergrundfarbe ändern\n" COLOR_B "Materialgröße ändern\n" COLOR_B\
		"Standard wiederherstellen\n" COLOR_B "Werbetafel verkaufen", "Weiter", "Abbrechen");
}

stock Werbebanner_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	new werbetafel = IsPlayerAtWerbetafel(playerid);
	if (werbetafel == 999) return 0;
	if (dialogid == DIALOG_ADBOARD_HELP) return ShowWerbetafelMenu(playerid);
	if (dialogid == DIALOG_ADBOARD_BUY) {
        if (!response) return 1;
        if (Spieler[playerid][pLevel] < 3) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Um eine Werbetafel zu kaufen, musst du mindestens Level 3 sein.");
        if (Spieler[playerid][pCash] < 40000) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du besitzt keine $40.000 um die Werbetafel zu kaufen.");
        new String[128];
        if (werbetafel == 999) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht in der Nähe einer Werbetafel.");
        if (strcmp(g_Werbebanner[werbetafel][W_sOwner], "Niemand", true) != 0) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Diese Werbetafel steht nicht zum Verkauf.");
        format(g_Werbebanner[werbetafel][W_sOwner], MAX_PLAYER_NAME, GetName(playerid));
        SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Diese Werbetafel gehört nun 96 Stunden lang dir.");
        SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Benutze /Werbetafel um sie einzustellen.");
        GivePlayerCash(playerid, -40000);
        format(String, sizeof(String), "Besitzer der Werbetafel:\n{FFFFFF}%s", g_Werbebanner[werbetafel][W_sOwner]);
        UpdateDynamic3DTextLabelText(g_Werbebanner[werbetafel][W_t3dLabel], 0x28C0D6FF, String);
        g_Werbebanner[werbetafel][W_unixBought] = gettime() + 4*24*60*60;
    }
	if (dialogid == DIALOG_ADBOARD_MAIN) {
	    if (!response) return 1;
        switch (listitem) {
            case 0: return ShowPlayerDialog(playerid, DIALOG_ADBOARD_HELP, DIALOG_STYLE_MSGBOX, "Werbetafel - Hilfe", COLOR_B\
            	"Der Text ist auf 127 Zeichen beschränkt.\nIm Text können eingebettete Farben wie z.B.\n{ FF9900 } - ohne die Leerzeichen benutzt werden.\n\
            	Ein Zeilenumbruch kann mit \\n eingefügt werden.\nDie Materialgröße bestimmt, wie lesbar die Schrift\nauf der Werbetafel sein wird.", "Zurück", "");
        	case 1: {
        	    new string[400];
        	    format(string, sizeof(string), COLOR_B "Derzeitiger Text:\n{FFFFFF}%s\n\n" COLOR_G "Gebe hier den neuen Text ein:", g_Werbebanner[werbetafel][W_sText]);
        	    return ShowPlayerDialog(playerid, DIALOG_ADBOARD_TEXT, DIALOG_STYLE_INPUT, "Werbetafel - Text", string, "Bestätigen", "Zurück");
        	}
        	case 2: {
			    new string[128];
			    format(string, sizeof(string), COLOR_B "Derzeitige Textgröße: {FFFFFF}%d\n\n" COLOR_G "Gebe hier die neue Textgröße ein:", g_Werbebanner[werbetafel][W_iFontSize]);
                return ShowPlayerDialog(playerid, DIALOG_ADBOARD_TEXTSIZE, DIALOG_STYLE_INPUT, "Werbetafel - Textgröße", string, "Bestätigen", "Zurück");
			}
			case 3: {
				return ShowPlayerDialog(playerid, DIALOG_ADBOARD_TEXTCOLOR, DIALOG_STYLE_LIST, "Werbetafel - Textfarbe",
					COLOR_B "Wähle eine vorgegebene Farbe\n" COLOR_B "Gebe einen ARGB Farbcode ein", "Weiter", "Zurück");
			}
			case 4: {
				new dialogText[128];
				format(dialogText, sizeof(dialogText), COLOR_B "Derzeitige Schriftart: {FFFFFF}%s\n\n" COLOR_G "Gebe hier die neue Schriftart ein:",
					g_Werbebanner[werbetafel][W_iFontFace]);
				return ShowPlayerDialog(playerid, DIALOG_ADBOARD_FONT, DIALOG_STYLE_INPUT, "Werbetafel - Schriftart", dialogText, "Bestätigen", "Zurück");
			}
			case 5: {
				new dialogCaption[64];
				format(dialogCaption, sizeof(dialogCaption), "Werbetafel - Textausrichtung | {FFFFFF}%s",
					g_Werbebanner[werbetafel][W_iTextAlignment] == 1 ? "Zentriert" : (g_Werbebanner[werbetafel][W_iTextAlignment] == 2 ? "Rechtsbündig" : "Linksbündig"));

			    return ShowPlayerDialog(playerid, DIALOG_ADBOARD_ALIGN, DIALOG_STYLE_LIST, dialogCaption, COLOR_B "Linksbündig\n" COLOR_B "Zentriert\n" COLOR_B\
			     "Rechtsbündig", "Bestätigen", "Zurück");
			}
			case 6: {
				new dialogCaption[64];
				format(dialogCaption, sizeof(dialogCaption), "Werbetafel - Fettschrift einstellen | {FFFFFF}%s",
					g_Werbebanner[werbetafel][W_iBold] ? "Fettschrift" : "Keine Fettschrift");
				return ShowPlayerDialog(playerid, DIALOG_ADBOARD_BOLD, DIALOG_STYLE_LIST, dialogCaption, COLOR_B "Keine Fettschrift\n" COLOR_B\
				 "Fettschrift", "Bestütigen", "Zurück");
			}
			case 7: {
				return ShowPlayerDialog(playerid, DIALOG_ADBOARD_BACKCOLOR, DIALOG_STYLE_LIST, "Werbetafel - Hintergrundfarbe",
					COLOR_B "Wähle eine vorgegebene Farbe\n" COLOR_B "Gebe einen ARGB Farbcode ein", "Weiter", "Zurück");
			}
			case 8: {
				new dialogCaption[64], dialogText[512], mSize = g_Werbebanner[werbetafel][W_iMaterialSize];
				format(dialogCaption, sizeof(dialogCaption), "Werbetafel - Materialgröße | {FFFFFF}%s (%i)", g_MatSizes[mSize / 10 - 1][MAT_SIZE_NAME], mSize);
				for (new i; i < sizeof(g_MatSizes); i++) format(dialogText, sizeof(dialogText), "%s" COLOR_B "%s" COLOR_G " (%i)\n", dialogText, g_MatSizes[i][MAT_SIZE_NAME], g_MatSizes[i][MAT_SIZE_VALUE]);
				return ShowPlayerDialog(playerid, DIALOG_ADBOARD_MATSIZE, DIALOG_STYLE_TABLIST, dialogCaption, dialogText, "Bestätigen", "Zurück");
			}
			case 9: {
				return ShowPlayerDialog(playerid, DIALOG_ADBOARD_RESET, DIALOG_STYLE_MSGBOX, "Werbetafel - Standard wiederherstellen", COLOR_B "Bist du sicher, \
					dass du die Werbetafel auf die\nStandardeinstellungen zurücksetzen möchtest?", "Bestätigen", "Zurück");
			}
			case 10: {
				return ShowPlayerDialog(playerid, DIALOG_ADBOARD_SELL, DIALOG_STYLE_MSGBOX, "Werbetafel - Verkaufen", COLOR_B "Bist du sicher, \
					dass du die Werbetafel verkaufen möchtest?\nDu bekommst kein Geld dafür zurück.", "Bestätigen", "Zurück");
			}
        }

	    return 1;
	}
	if (dialogid == DIALOG_ADBOARD_TEXT) {
		if (!response || isnull(inputtext)) return ShowWerbetafelMenu(playerid);
		for (new i, j = strlen(inputtext) - 1; i < j; i++) {
			if (inputtext[i] == '\\' && inputtext[i + 1] == 'n') {
				inputtext[i] = ' ';
				inputtext[i + 1] = '\n';
			}
		}

		format(g_Werbebanner[werbetafel][W_sText], 256, inputtext);
		UpdateObject(werbetafel);
		SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast den Text deiner Werbetafel auf folgendes geändert:");
		SendClientMessage(playerid, COLOR_WHITE, inputtext);
		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_MATSIZE) {
		if (!response) return ShowWerbetafelMenu(playerid);
		if (listitem < 0 || listitem >= sizeof(g_MatSizes)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast keine gültige Auswahl getroffen.");
		g_Werbebanner[werbetafel][W_iMaterialSize] = g_MatSizes[listitem][MAT_SIZE_VALUE];
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Materialgröße deiner Werbetafel auf %s (%i) geändert.",\
			g_MatSizes[listitem][MAT_SIZE_NAME], g_MatSizes[listitem][MAT_SIZE_VALUE]);

		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_FONT) {
		if (!response) return ShowWerbetafelMenu(playerid);
		format(g_Werbebanner[werbetafel][W_iFontFace], 32, inputtext);
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Schriftart deiner Werbetafel auf %s geändert.", g_Werbebanner[werbetafel][W_iFontFace]);
		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_TEXTSIZE) {
		if (!response) return ShowWerbetafelMenu(playerid);
		new textSize;
		if (sscanf(inputtext, "i", textSize) || textSize < 1) {
			SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Gebe eine positive Ganzzahl als Textgröße an.");
			return ShowWerbetafelMenu(playerid);
		}

		g_Werbebanner[werbetafel][W_iFontSize] = textSize;
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Textgröße deiner Werbetafel auf %i geändert.", textSize);
		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_BOLD) {
		if (!response) return ShowWerbetafelMenu(playerid);
		g_Werbebanner[werbetafel][W_iBold] = listitem ? 1 : 0;
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Einstellung deiner Werbetafel auf %s geändert.", listitem ? "Fettschrift" : "Keine Fettschrift");
		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_TEXTCOLOR) {
		if (!response) return ShowWerbetafelMenu(playerid);
		if (!listitem) {
			new dialogText[256];
			for (new i; i < sizeof(g_textColors); i++)
				format(dialogText, sizeof(dialogText), "%s%s%s\n", dialogText, g_textColors[i][TEXT_COLOR_EMBEDDED], g_textColors[i][TEXT_COLOR_NAME]);
			return ShowPlayerDialog(playerid, DIALOG_ADBOARD_TEXTCOLOR_LIST, DIALOG_STYLE_LIST, "Werbetafel - Textfarbe auswählen",
				dialogText, "Weiter", "Zurück");
		}

		return ShowPlayerDialog(playerid, DIALOG_ADBOARD_TEXTCOLOR_INPUT, DIALOG_STYLE_INPUT, "Werbetafel - Textfarbe eingeben", COLOR_B "Gebe einen ARGB Farbcode \
			für die Textfarbe ein (z.B. 0xFFBB4400):", "Bestätigen", "Zurück");
	}
	if (dialogid == DIALOG_ADBOARD_BACKCOLOR) {
		if (!response) return ShowWerbetafelMenu(playerid);
		if (!listitem) {
			new dialogText[256];
			for (new i; i < sizeof(g_textColors); i++)
				format(dialogText, sizeof(dialogText), "%s%s%s\n", dialogText, g_textColors[i][TEXT_COLOR_EMBEDDED], g_textColors[i][TEXT_COLOR_NAME]);
			return ShowPlayerDialog(playerid, DIALOG_ADBOARD_BACKCOLOR_LIST, DIALOG_STYLE_LIST, "Werbetafel - Hintergrundfarbe auswählen",
				dialogText, "Weiter", "Zurück");
		}

		return ShowPlayerDialog(playerid, DIALOG_ADBOARD_BACKCOLOR_INPUT, DIALOG_STYLE_INPUT, "Werbetafel - Hintergrundfarbe eingeben", COLOR_B "Gebe einen ARGB Farbcode \
			für die Textfarbe ein (z.B. 0xFFBB4400):", "Bestätigen", "Zurück");
	}
	if (dialogid == DIALOG_ADBOARD_RESET) {
		if (!response) return ShowWerbetafelMenu(playerid);
	    format(g_Werbebanner[werbetafel][W_sText], 256, "{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000");
		g_Werbebanner[werbetafel][W_iMaterialIndex] = 0;
		g_Werbebanner[werbetafel][W_iMaterialSize] = 130;
		format(g_Werbebanner[werbetafel][W_iFontFace], 32, "Verdana");
		g_Werbebanner[werbetafel][W_iFontSize] = 38;
		g_Werbebanner[werbetafel][W_iBold] = 1;
		g_Werbebanner[werbetafel][W_iFontColor] = 0xFFFFFFFF;
		g_Werbebanner[werbetafel][W_iBackColor] = -16777216;
		g_Werbebanner[werbetafel][W_iTextAlignment] = 1;
		UpdateObject(werbetafel);
		SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast deine Werbetafel auf die Standardeinstellungen zurückgesetzt.");
		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_SELL) {
		if (!response) return ShowWerbetafelMenu(playerid);
		WerbetafelZuVermieten(werbetafel);
		UpdateObject(werbetafel);
		SaveWerbebannerEx(werbetafel);
		return SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast deine Werbetafel verkauft.");
	}
	if (dialogid == DIALOG_ADBOARD_ALIGN) {
		if (!response) return ShowWerbetafelMenu(playerid);
		if (listitem < 0 || listitem > 2) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast keine gültige Auswahl getroffen.");
		g_Werbebanner[werbetafel][W_iTextAlignment] = listitem;
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Textausrichtung deiner Werbetafel auf %s geändert.", !listitem ? \
			"Linksbündig" : (listitem == 1 ? "Zentriert" : "Rechtsbündig"));

		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_TEXTCOLOR_INPUT) {
		if (!response) return ShowWerbetafelMenu(playerid);
		g_Werbebanner[werbetafel][W_iFontColor] = HexToInt(inputtext);
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Textfarbe deiner Werbetafel auf %s geändert.", inputtext);
		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_BACKCOLOR_INPUT) {
		if (!response) return ShowWerbetafelMenu(playerid);
		g_Werbebanner[werbetafel][W_iBackColor] = HexToInt(inputtext);
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Hintergrundfarbe deiner Werbetafel auf %s geändert.", inputtext);
		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_TEXTCOLOR_LIST) {
		if (!response) return ShowWerbetafelMenu(playerid);
		if (listitem < 0 || listitem >= sizeof(g_textColors)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast keine gültige Auswahl getroffen.");
		g_Werbebanner[werbetafel][W_iFontColor] = g_textColors[listitem][TEXT_COLOR_VALUE];
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Textfarbe deiner Werbetafel auf %s geändert.", g_textColors[listitem][TEXT_COLOR_NAME]);
		return ShowWerbetafelMenu(playerid);
	}
	if (dialogid == DIALOG_ADBOARD_BACKCOLOR_LIST) {
		if (!response) return ShowWerbetafelMenu(playerid);
		if (listitem < 0 || listitem >= sizeof(g_textColors)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast keine gültige Auswahl getroffen.");
		g_Werbebanner[werbetafel][W_iBackColor] = g_textColors[listitem][TEXT_COLOR_VALUE];
		UpdateObject(werbetafel);
		SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Hintergrundfarbe deiner Werbetafel auf %s geändert.", g_textColors[listitem][TEXT_COLOR_NAME]);
		return ShowWerbetafelMenu(playerid);
	}
    return 0;
}

stock HexToInt(string[]) { //By Zamaroht, I think... =/
	if (string[0] == 0) return 0;
	new cur = 1, res = 0;
	for (new i = strlen(string); i > 0; i--) {
	if (string[i - 1] < 58) res = res + cur * (string[i - 1] - 48);
	else res = res + cur * (string[i - 1] - 65 + 10);
	cur = cur * 16;
	}

	return res;
}

stock UpdateObject(werbetafel) {
	SetDynamicObjectMaterialText(
		g_Werbebanner[werbetafel][W_iObjectID],
		g_Werbebanner[werbetafel][W_iMaterialIndex],
	 	g_Werbebanner[werbetafel][W_sText],
		g_Werbebanner[werbetafel][W_iMaterialSize],
		g_Werbebanner[werbetafel][W_iFontFace],
		g_Werbebanner[werbetafel][W_iFontSize],
		g_Werbebanner[werbetafel][W_iBold],
		g_Werbebanner[werbetafel][W_iFontColor],
		g_Werbebanner[werbetafel][W_iBackColor],
		g_Werbebanner[werbetafel][W_iTextAlignment]
	);

	return 1;
}

stock WerbetafelZuVermieten(werbetafel) {
    format(g_Werbebanner[werbetafel][W_sText], 256, "{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000");
	format(g_Werbebanner[werbetafel][W_sOwner], MAX_PLAYER_NAME, "Niemand");
	g_Werbebanner[werbetafel][W_unixBought] = 0;
	g_Werbebanner[werbetafel][W_iMaterialIndex] = 0;
	g_Werbebanner[werbetafel][W_iMaterialSize] = 130;
	format(g_Werbebanner[werbetafel][W_iFontFace], 32, "Verdana");
	g_Werbebanner[werbetafel][W_iFontSize] = 38;
	g_Werbebanner[werbetafel][W_iBold] = 1;
	g_Werbebanner[werbetafel][W_iFontColor] = 0xFFFFFFFF;
	g_Werbebanner[werbetafel][W_iBackColor] = -16777216;
	g_Werbebanner[werbetafel][W_iTextAlignment] = 1;
	UpdateDynamic3DTextLabelText(g_Werbebanner[werbetafel][W_t3dLabel], 0x28C0D6FF, "Diese Werbetafel steht zum Verkauf!\n{FFFFFF}Benutze /Werbetafelkaufen");
	return 1;
}
