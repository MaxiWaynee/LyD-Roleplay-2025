#include <YSI\y_hooks>

#define MAX_CRYPTOS                 3
#define MAX_STOCKS                  2
#define COINBASE_FEE_PERCENTAGE     0.01 // 1%
#define COINBASE_BIZ_INDEX          62

static cryptos[MAX_CRYPTOS][4] = {
    { "BTC" },
    { "ETH" },
    { "LTC" }
};

static stocks[MAX_STOCKS][7] = {
    { "AAPL" },
    { "SSUN.F" }
};

static prices[MAX_CRYPTOS + MAX_STOCKS];

hook OnGameModeInit() {
    updateCoinbasePrices();
    SetTimer("updateCoinbasePrices", 35000, true);

    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    new bIndex = GetBizIndexByID(COINBASE_BIZ_INDEX);
    switch (dialogid) {
        case DIALOG_COINBASE_CHOOSE: {
            if (response && -1 < listitem < (MAX_CRYPTOS + MAX_STOCKS)) {
                SetPVarInt(playerid, "COINBASE.ASSET", listitem);
                new dialogString[64];
                format(dialogString, sizeof(dialogString), "{FFFFFF}Möchtest du %s kaufen oder verkaufen?", getAssetNameByIndex(listitem));
                return ShowPlayerDialog(playerid, DIALOG_COINBASE_BUYORSELL, DIALOG_STYLE_MSGBOX, "Kaufen oder Verkaufen", dialogString, "Kaufen", "Verkaufen");
            } else
                return 1;
        }

        case DIALOG_COINBASE_BUYORSELL: {
            if (response)
                SetPVarInt(playerid, "COINBASE.BUYORSELL", 0); // 0 = Buy
            else
                SetPVarInt(playerid, "COINBASE.BUYORSELL", 1); // 1 = Sell
                
            return ShowPlayerDialog(playerid, DIALOG_COINBASE_AMOUNT, DIALOG_STYLE_INPUT, "Betrag", "{FFFFFF}Gebe den Betrag an, wie viel du kaufen / verkaufen möchtest:", "Fertig", "Abbrechen");
        }

        case DIALOG_COINBASE_AMOUNT: {
            if (response) {
                if (!floatstr(inputtext))
                    return ShowPlayerDialog(playerid, DIALOG_COINBASE_AMOUNT, DIALOG_STYLE_INPUT, "Betrag", "{FF0000}Du musst einen gültigen Betrag angeben. (Ganz- / Fliesskommazahlen)\n\n{FFFFFF}Gebe den Betrag an, wie viel du kaufen / verkaufen möchtest:", "Fertig", "Abbrechen");

                new dialogString[256];
                SetPVarFloat(playerid, "COINBASE.AMOUNT", floatstr(inputtext));

                new assetIndex = GetPVarInt(playerid, "COINBASE.ASSET");
                new sum = floatround(floatstr(inputtext) * prices[assetIndex]);
                new fee = floatround(sum * COINBASE_FEE_PERCENTAGE);

                if (!GetPVarInt(playerid, "COINBASE.BUYORSELL")) {
                    // Buy
                    SetPVarInt(playerid, "COINBASE.TOTAL", sum + fee);

                    if ((sum + fee) < 1)
                        return SendClientMessage(playerid, COLOR_DARKRED, "Zur Zeit können wir dir diese Anlage nicht verkaufen.");

                    if (GetPlayerMoney(playerid) < (sum + fee))
                        return ShowPlayerDialog(playerid, DIALOG_COINBASE_AMOUNT, DIALOG_STYLE_INPUT, "Betrag", "{FF0000}Du hast nicht genügend Geld dabei, um Anlagen in dieser Höhe zu kaufen.\n\n{FFFFFF}Gebe den Betrag an, wie viel du kaufen / verkaufen möchtest:", "Fertig", "Abbrechen");

                    format(dialogString, sizeof(dialogString), "Folgende Offerte können wir dir anbieten.\n\n{FF0000}Betrag\t\t\t\t-$%s\n{FF0000}Münzkassette Gebühr\t\t-$%s\n\nTOTAL\t\t\t\t-$%s\n\n{00FF00}Du erhälst\t\t\t+%.5f %s", AddDelimiters(sum), AddDelimiters(fee), AddDelimiters(sum + fee), GetPVarFloat(playerid, "COINBASE.AMOUNT"), getAssetNameByIndex(GetPVarInt(playerid, "COINBASE.ASSET")));
                } else {
                    // Sell
                    SetPVarInt(playerid, "COINBASE.TOTAL", sum - fee);

                    if ((sum - fee) < 1)
                        return SendClientMessage(playerid, COLOR_DARKRED, "Zur Zeit können wir dir diese Anlage nicht abkaufen.");

                    if (GetPVarFloat(playerid, "COINBASE.AMOUNT") > Float:Spieler[playerid][pBTC + SpielerDaten:assetIndex])
                        return ShowPlayerDialog(playerid, DIALOG_COINBASE_AMOUNT, DIALOG_STYLE_INPUT, "Betrag", "{FF0000}Du kannst nicht mehr an Anlagen verkaufen, als du besitzt.\n\n{FFFFFF}Gebe den Betrag an, wie viel du kaufen / verkaufen möchtest:", "Fertig", "Abbrechen");

                    if (Biz[bIndex][bKasse] < (sum - fee))
                        return ShowPlayerDialog(playerid, DIALOG_COINBASE_AMOUNT, DIALOG_STYLE_INPUT, "Betrag", "{FF0000}Das Geschäft hat nicht genügend Geld, um dir deine Anlage in dieser Höhe abzukaufen.\n\n{FFFFFF}Gebe den Betrag an, wie viel du kaufen / verkaufen möchtest:", "Fertig", "Abbrechen");

                    format(dialogString, sizeof(dialogString), "Folgende Offerte können wir dir anbieten.\n\n{FF0000}Betrag\t\t\t\t-%.5f %s\n{FF0000}Münzkassette Gebühr\t\t-$%s\n\nTOTAL\t\t\t\t-%.5f %s + -$%s\n\n{00FF00}Du erhälst\t\t\t+$%s", GetPVarFloat(playerid, "COINBASE.AMOUNT"), getAssetNameByIndex(GetPVarInt(playerid, "COINBASE.ASSET")), AddDelimiters(fee), GetPVarFloat(playerid, "COINBASE.AMOUNT"), getAssetNameByIndex(GetPVarInt(playerid, "COINBASE.ASSET")), AddDelimiters(fee), AddDelimiters(sum - fee));
                }

                return ShowPlayerDialog(playerid, DIALOG_COINBASE_CONFIRM, DIALOG_STYLE_MSGBOX, "Offerte bestätigen", dialogString, "Akzeptieren", "Ablehnen");
            } else
                return 1;
        }

        case DIALOG_COINBASE_CONFIRM: {
            if (response) {
                new Float:amount = GetPVarFloat(playerid, "COINBASE.AMOUNT");
                new assetIndex = GetPVarInt(playerid, "COINBASE.ASSET");
                new sum = floatround(amount * prices[assetIndex]);
                new fee = floatround(sum * COINBASE_FEE_PERCENTAGE);
                new total = GetPVarInt(playerid, "COINBASE.TOTAL");

                if (!GetPVarInt(playerid, "COINBASE.BUYORSELL")) {
                    // Buy
                    if (GetPlayerMoney(playerid) < GetPVarInt(playerid, "COINBASE.TOTAL"))
                        return SendClientMessage(playerid, COLOR_DARKRED, "Du hast nicht genügend Geld dabei, um Anlagen in dieser Höhe zu kaufen.");

                    if (total != (sum + fee))
                        return SendClientMessage(playerid, COLOR_DARKRED, "Der Preis der Anlage hat sich seit der Offerte zu stark geändert, beantrage eine neue Offerte an.");
                    
                    GivePlayerCash(playerid, -total);
                    Biz[bIndex][bKasse] += total;
                    Spieler[playerid][pBTC + SpielerDaten:assetIndex] = _:floatadd(Float:Spieler[playerid][pBTC + SpielerDaten:assetIndex], amount);

                    LogCoinbase(GetName(playerid), GetPVarInt(playerid, "COINBASE.BUYORSELL"), amount, getAssetNameByIndex(assetIndex), total);

                    return SCMFormatted(playerid, COLOR_DARKGREEN, "Du hast dir für $%s, %.5f %s gekauft.", AddDelimiters(total), amount, getAssetNameByIndex(assetIndex));
                } else {
                    // Sell
                    if (Biz[bIndex][bKasse] < GetPVarInt(playerid, "COINBASE.TOTAL"))
                        return SendClientMessage(playerid, COLOR_DARKRED, "Das Geschäft hat nicht genügend Geld, um dir deine Anlage in dieser Höhe abzukaufen.");

                    if (amount > Float:Spieler[playerid][pBTC + SpielerDaten:assetIndex])
                        return SendClientMessage(playerid, COLOR_DARKRED, "Du kannst nicht mehr an Anlagen verkaufen, als du besitzt.");

                    if (total != (sum - fee))
                        return SendClientMessage(playerid, COLOR_DARKRED, "Der Preis der Anlage hat sich seit der Offerte zu stark geändert, beantrage eine neue Offerte an.");
                    
                    GivePlayerCash(playerid, total);
                    Biz[bIndex][bKasse] -= total;
                    Spieler[playerid][pBTC + SpielerDaten:assetIndex] = _:floatsub(Float:Spieler[playerid][pBTC + SpielerDaten:assetIndex], amount);

                    LogCoinbase(GetName(playerid), GetPVarInt(playerid, "COINBASE.BUYORSELL"), amount, getAssetNameByIndex(assetIndex), total);

                    return SCMFormatted(playerid, COLOR_DARKGREEN, "Du hast deine %.5f %s für $%s verkauft.", amount, getAssetNameByIndex(assetIndex), AddDelimiters(total));
                }
            } else
                return 1;
        }
    }

    return 1;
}

forward OnAssetPriceResponse(index, response_code, data[]);
public OnAssetPriceResponse(index, response_code, data[]) {
    if (response_code != 200)
        return 1;

    prices[index] = strval(data);
    return updateCoinbaseMonitors();
}

forward updateCoinbasePrices();
public updateCoinbasePrices() {
    for (new i = 0; i < MAX_CRYPTOS + MAX_STOCKS; i++) {
        new url[32];
        format(url, sizeof(url), "lydassets.pkfln.io/%i", i);
        HTTP(i, HTTP_GET, url, "", "OnAssetPriceResponse");
    }

    return 1;
}

stock getAssetNameByIndex(index) {
    new string[10] = "Unbekannt";

    if (index > (MAX_CRYPTOS - 1))
        format(string, sizeof(string), "%s", stocks[index - MAX_CRYPTOS]);
    else
        format(string, sizeof(string), "%s", cryptos[index]);
    
    return string;
}

stock updateCoinbaseMonitors() {
    new cryptoMonitor[256];
    new stockMonitor[256];

    for (new i = 0; i < sizeof(cryptos); i++)
        format(cryptoMonitor, sizeof(cryptoMonitor), "%s{FF9900}%s {006400}$%s\n", cryptoMonitor, cryptos[i], AddDelimiters(prices[i]));

    for (new i = 0; i < sizeof(stocks); i++)
        format(stockMonitor, sizeof(stockMonitor), "%s{00ACFC}%s {006400}$%s\n", stockMonitor, stocks[i], AddDelimiters(prices[MAX_CRYPTOS + i]));

    SetDynamicObjectMaterialText(object_coinbase[27], 1, cryptoMonitor, OBJECT_MATERIAL_SIZE_256x128, "Courier", 24, 1, 0xFFFFFFFF, 0xFFA52A2A, 1);
    SetDynamicObjectMaterialText(object_coinbase[42], 1, stockMonitor, OBJECT_MATERIAL_SIZE_256x128, "Courier", 24, 1, 0xFFFFFFFF, 0xFFA52A2A, 1);

    return 1;
}

CMD:coinbase(playerid, params[]) {
    if (Spieler[playerid][pLevel] < 3)
        return SendClientMessage(playerid, COLOR_DARKRED, "Du musst mindestens Level 3 sein, um in Kryptowährungen und Aktien investieren zu können.");
    
    if (!IsPlayerInRangeOfPoint(playerid, 2.5, COINBASE_COORDS))
        return SendClientMessage(playerid, COLOR_DARKRED, "Hier kannst du diesen Befehl nicht benutzen.");

    new dialogString[512] = "Anlage\tWert\tBesitz\n";

    for (new i = 0; i < sizeof(cryptos); i++)
        format(dialogString, sizeof(dialogString), "%s{FF9900}%s\t{006400}$%s\t%.5f\n", dialogString, cryptos[i], AddDelimiters(prices[i]), Spieler[playerid][pBTC + SpielerDaten:i]);

    for (new i = 0; i < sizeof(stocks); i++)
        format(dialogString, sizeof(dialogString), "%s{00ACFC}%s\t{006400}$%s\t%.5f\n", dialogString, stocks[i], AddDelimiters(prices[MAX_CRYPTOS + i]), Spieler[playerid][pBTC + SpielerDaten:MAX_CRYPTOS + SpielerDaten:i]);

    return ShowPlayerDialog(playerid, DIALOG_COINBASE_CHOOSE, DIALOG_STYLE_TABLIST_HEADERS, "Wähle eine Kryptowährung oder Aktie aus", dialogString, "Auswählen", "Abbrechen");
}
