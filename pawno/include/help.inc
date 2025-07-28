#include <YSI\y_hooks>

// - - - - - - -  - - - - - - -  <-- HELP SYSTEM

new const StandartHelp[37][] = {
	{"sup"},
    {"admin"},
    {"anrufen"},
    {"navi"},
    {"suche"},
    {"spielerinfo"},
    {"rauchzig"},
    {"zigweg"},
    {"geben"},
    {"liste"},
    {"inventar"},
    {"koffer"},
    {"kofferauf"},
    {"firmen"},
    {"mutetime"},
    {"animlist"},
    {"staatskasse"},
    {"leader"},
    {"gutscheincode"},
    {"musik"},
    {"mp3player"},
    {"ghettoblaster"},
    {"removeghettoblaster"},
    {"jailtime"},
    {"einstellungen"},
    {"clubhelp"},
    {"werbetafelkaufen"},
    {"werbetafelfinden"},
    {"werbetafel"},
    {"eventpreise"},
    {"mineninfo"},
    {"showjob"},
    {"jobkleidung"},
    {"skill"},
    {"upgradeinfo"},
    {"oldname"},
	{"freischalten"}
};

new const MoneyHelp[7][]= {
    {"findatm"},
    {"automat"},
    {"ueberweisen"},
    {"gebecheck"},
    {"guthaben"},
    {"zahlen"},
    {"finanzen"}
};

new DeathmatchHelp[19][]= {
    {"Nimmdrogen"},
    {"Nimmspice"},
    {"Isskeks"},
    {"Booster"},
    {"Riegel"},
    {"kampfstyle"},
    {"pickwaffe"},
    {"jailtime"},
    {"tottime"},
    {"killauftrag"},
    {"driveby"},
    {"gangfightwette"},
    {"gangfightinfo"},
    {"gfinfo"},
    {"swinfo"},
    {"tankstelleausrauben"},
    {"bankhacken"},
    {"transporterausrauben"},
    {"ndaufbrechen"}
};

new SellHelp[4][]= {
    {"sellkekse"},
    {"sellwantedcodes"},
    {"selldrogen"},
    {"sellwaffenteile"}
};

new CasinoHelp[3][]= {
    {"spielautomat"},
    {"kartenspiel"},
    {"gluecksrad"}
};

new VehicleHelp[26][]= {
    {"radio"},
    {"carlock"},
    {"carkey"},
    {"movecarkey"},
    {"findcar"},
    {"flock"},
    {"tanken"},
    {"carsell"},
    {"parken"},
    {"licht"},
    {"motor"},
    {"fenster"},
    {"rauswerfen"},
    {"kanister"},
    {"kofferraum"},
    {"kofferraumansehen"},
    {"fahrzeugschein"},
    {"scheine"},
    {"scheinsperre"},
    {"fahrzeuginfo"},
    {"lock"},
    {"mieten"},
    {"entmieten"},
    {"mietlock"},
    {"findmietcar"},
    {"fahrpruefung"}
};

new HouseHelp[16][]= {
    {"hauskaufen"},
    {"zuhause"},
    {"hausupgrade"},
    {"hausmieten"},
    {"hausentmieten"},
    {"haustuer"},
    {"hausmenu"},
    {"hausverkaufen"},
    {"hausverstaatlichen"},
    {"hausmietung"},
    {"hausraus"},
    {"hausrausalle"},
    {"hausabgeben"},
    {"hoteltuer"},
    {"miethotelraum"},
    {"entmietenhotelraum"}
};

new BizHelp[9][]= {
    {"bizkaufen"},
    {"bizverkaufen"},
    {"bizverstaatlichen"},
    {"bizkassestand"},
    {"bizkasse"},
    {"biztuer"},
    {"eintritt"},
    {"warenverkaufsstelle1"},
    {"warenverkaufsstelle2"}
};

new TankstelleHelp[8][]= {
    {"tankekaufen"},
    {"tankstelleverkaufen"},
    {"tankeverstaatlichen"},
    {"maxbenzin"},
    {"tankkassestand"},
    {"tankkasse"},
    {"spritverkaufsstelle1"},
    {"spritverkaufsstelle2"}
};

new FirmenHelp[4][]= {
    {"firmenkasse"},
    {"firmengehalt"},
    {"firmennachricht"},
    {"entlassen"}
};

new ChatHelp[18][]= {
    {"f"},
    {"s"},
    {"nc"},
    {"ic"},
    {"jc"},
    {"chatanim"},
    {"gc"},
    {"chatoff"},
    {"anrufen"},
    {"sms"},
    {"auflegen"},
    {"abnehmen"},
    {"guthaben"},
    {"handystatus"},
    {"sendfs"},
    {"delfs"},
    {"fsliste"},
    {"fschat"}
};

new HaustierHelp[4][]= {
    {"haustier"},
    {"sellhaustier"},
    {"fuettern"},
    {"haustiershop"}
};

new LeaderHelp[1][]= {
    {"leaderhelp"}
};

new Job1Help[2][]= {
    {"startbauer"},
    {"stopbauer"}
};

new Job2Help[2][]= {
    {"startlinie"},
    {"stoplinie"}
};

new Job3Help[6][]= {
    {"loadbenzin"},
    {"startbenzin"},
    {"loadwaren"},
    {"startwaren"},
    {"ladung"},
    {"entladen"}
};

new Job4Help[2][]= {
    {"startflug"},
    {"stopflug"}
};

new Job5Help[2][]= {
    {"nachtanken"},
    {"reparieren"}
};

new Job6Help[2][]= {
    {"befreien"},
    {"sliste"}
};

new Job7Help[2][]= {
    {"startreinigung"},
    {"stopreinigung"}
};

new Job8Help[3][]= {
    {"startmuell"},
    {"stopmuell"},
    {"entleeren"}
};

new Job9Help[2][]= {
    {"startgarten"},
    {"stopgarten"}
};

new Job10Help[2][]= {
    {"startbauerbeiter"},
    {"stopbauerbeiter"}
};

new Job11Help[2][]= {
    {"startschiff"},
    {"stopschiff"}
};

new Job12Help[2][]= {
    {"starttransport"},
    {"stoptransport"}
};

new Job13Help[1][]= {
    {"eisverkaufen"}
};

new Job14Help[2][]= {
    {"dfinden"},
    {"dzeigen"}
};

new Job15Help[2][]= {
    {"pizzaverkaufen"},
    {"sliste"}
};

new Job16Help[1][]= {
    {"starttaxi"}
};

new Job17Help[2][]= {
    {"paketeinladen"},
    {"paketentladen"}
};

new Job18Help[2][]= {
    {"paketeinladen"},
    {"paketentladen"}
};

new Job19Help[1][]= {
    {"tascheklauen"}
};

new Job20Help[1][]= {
    {"sex"}
};

new Job21Help[3][]= {
    {"wantedhacken"},
    {"wcodes"},
    {"sellwantedcodes"}
};

new Job22Help[1][]= {
    {"autoknacken"}
};

/*new Job23Help[2][]= {
    {"startzug"},
    {"stopzug"}
};*/

new Job23Help[1][]= {
    {"hotdogverkaufen"}
};

new Frak9Help[9][] = {
    {"dienst"},
    {"setsteuern"},
    {"smsg"},
    {"staatssystem"},
    {"zollamt"},
    {"fc"},
    {"bc"},
    {"kasse"},
    {"kassenstand"}
};

new Frak1Help[65][]= {
    {"clear"},
    {"pdclear"},
    {"dienst"},
    {"sliste"},
    {"acceptcop"},
    {"mitglieder"},
    {"dienstmarke"},
    {"sp"},
    {"staatskasse"},
    {"haussuchen"},
    {"beamteon"},
    {"reinziehen"},
    {"freilassen"},
    {"verhaften"},
    {"koffereinziehen"},
    {"offlinearrest"},
    {"rufdetektiv"},
    {"scheinentziehen"},
    {"arrest"},
    {"w"},
    {"caufbrechen"},
    {"zollamt"},
    {"ticket"},
    {"aufbrechen"},
    {"knastzeit"},
    {"finden"},
    {"pflanzeverbrennen"},
    {"gangpflanzeverbrennen"},
    {"zollsperre"},
    {"parkstrafe"},
    {"strafzettel"},
    {"entschaerfen"},
    {"fc"},
    {"bc"},
    {"vk"},
    {"pvk"},
    {"cpartner"},
    {"acceptpartner"},
    {"ve"},
    {"kofferdurchsuchen"},
    {"durchsuchen"},
    {"promille"},
    {"pakte"},
    {"gefangene"},
    {"meldestelle"},
    {"parkscheinkontrolle"},
    {"vamt"},
    {"kfzsuchen"},
    {"kzsuchen"},
    {"uclight"},
    {"copman"},
    {"copfrau"},
    {"rank"},
    {"rankfrau"},
    {"copcap"},
    {"copcapf"},
    {"copmuetze"},
    {"tcop"},
    {"pschild"},
    {"copbrille"},
    //{"waffenspind"},
    {"vrk"},
    {"hsirene"},
    {"pein"},
    {"ermitteln"},
    {"findfcars"}
};

new Frak3Help[21][]= {
    {"dienst"},
    {"aufnehmen"},
    {"wiederbeleben"},
    {"deskwb"},
    {"sheilen"},
    {"samdgate"},
    {"samdgarage"},
    {"mv"},
    {"m"},
    {"kasse"},
    {"kassenstand"},
    {"mitglieder"},
    {"sfinden"},
    {"bc"},
    {"sliste"},
    {"acceptsani"},
    {"rtwsirene"},
    {"meinsatz"},
    {"bk"},
    {"dtasche"},
    {"findfcars"}
};

new Frak4Help[11][]= {
    {"dienst"},
    {"news"},
    {"starteventpoint"},
    {"stopeventpoint"},
    {"interview"},
    {"Kasse"},
    {"Kassenstand"},
    {"mitglieder"},
    {"sanagarage"},
    {"fskin"},
    {"findfcars"}
};

new Frak5Help[40][]= {
    {"dienst"},
    {"ov"},
    {"ogate"},
    {"beamteon"},
    {"mitglieder"},
    {"zollamt"},
    {"dienstmarke"},
    {"kasse"},
    {"kassenstand"},
    {"okamera"},
    {"sp"},
    {"fpunkte"},
    {"ticket"},
    {"strafzettel"},
    {"parkstrafe"},
    {"koffereinziehen"},
    {"scheinentziehen"},
    {"blitzerabbauen"},
    {"blitzeraufstellen"},
    {"tierverbot"},
    {"deltierverbot"},
    {"oparken"},
    {"ofreistellen"},
    {"fmparkkralle"},
    {"mparkkralle"},
    {"festnehmen"},
    {"fparken"},
    {"durchsuchen"},
    {"kofferdurchsuchen"},
    {"vamt"},
    {"pakte"},
    {"kfzsuchen"},
    {"kzsuchen"},
    {"promille"},
    {"bc"},
    {"fc"},
    {"m"},
    {"ovk"},
    {"bk"},
    {"findfcars"}
};

new FrakGangHelp[34][]= {
    {"gangwaffen"},
    {"gheilen"},
    {"mitglieder"},
    {"buendnis"},
    {"kasse"},
    {"kassenstand"},
    {"fc"},
    {"bg"},
    {"flock"},
    {"ggd (/givegangdrugs))"},
    {"frespawn"},
    {"kidnap"},
    {"mundbinde"},
    {"augenbinde"},
    {"fesseln"},
    {"entfesseln"},
    {"gangjail"},
    {"aufbrechen"},
    {"frakblacklist"},
    {"addfrakblacklist"},
    {"delfrakblacklist"},
    {"gangfight"},
    {"gangfightstop"},
    {"fge"},
    {"gangfightinfo"},
    {"swinfo"},
    {"schutzgeld"},
    {"schutzgeldabbrechen"},
    {"gangpflanzen"},
    {"findfcars"},
    {"samenpaketeinladen"},
    {"samenpaketentladen"},
    {"samenlagerpunkt"},
    {"selldrogen"}
};

new Frak14Help[19][]= {
    {"accept hitman"},
    {"hitmanwaffen"},
    {"gheilen"},
    {"hwerbung"},
    {"fc"},
    {"flock"},
    {"hmaske"},
    {"hitmanmaske"},
    {"kasse"},
    {"kassenstand"},
    {"mitglieder"},
    {"hrelease"},
    {"arz"},
    {"agbefreien"},
    {"knastbefreien"},
    {"agtor"},
    {"atorhacken"},
    {"acceptag"},
    {"findfcars"}
};

new Frak15Help[28][]= {
    {"ninowaffen"},
    {"gheilen"},
    {"fsafebox"},
    {"fc"},
    {"flock"},
    {"pflanzen"},
    {"kidnap"},
    {"augenbinde"},
    {"samen"},
    {"samenpunkte"},
    {"kasse"},
    {"kassenstand"},
    {"mitglieder"},
    {"samenlager"},
    {"paketeinladen"},
    {"storepakete"},
    {"storesamen"},
    {"samenlagerstatus"},
    {"findfcars"},
    {"bombelegen"},
    {"entfesseln"},
    {"kidnap"},
    {"startwt"},
    {"stopwt"},
    {"startsprit"},
    {"spritklauen"},
    {"stopsprit"},
    {"selbstmord"}
};

new Frak19Help[15][]= {
    {"fc"},
    {"kasse"},
    {"kassenstand"},
    {"kassenstand"},
    {"mitglieder"},
    {"flock"},
    {"bombelegen"},
    {"terrorwaffen"},
    {"entfesseln"},
    {"kidnap"},
    {"terrorgate"},
    {"findfcars"},
    {"makespice"},
    {"startwt"},
    {"stopwt"}
};

new const StandartHelpText[37][] = {
	{"Supportticket erstellen"},
    {"Nachricht an Admins versenden"},
    {"Spieler anrufen"},
    {"Navigtionspunkte anzeigen"},
    {"Spieler suchen"},
    {"Spielerinformationen anzeigen"},
    {"Zigarette Rauchen"},
    {"Zigarette Wegwerfen"},
    {"Inventare geben"},
    {"Online Liste"},
    {"Inventar anzeigen"},
    {"Koffer holen/weglegen"},
    {"Koffer öffnen"},
    {"Firmen anzeigen"},
    {"Mutezeit anzeigen"},
    {"Animationsliste"},
    {"Staatskasse"},
    {"Leaderliste"},
    {"Gutscheincode einlösen"},
    {"Musik abspielen"},
    {"Mp3Player starten"},
    {"Ghettoblaster aufstellen"},
    {"Ghettoblaster entfernen"},
    {"Jailtime anzeigen"},
    {"Einstellungen anpassen"},
    {"Clubbefehle anzeigen"},
    {"Werbetafel kaufen"},
    {"Werbetafel finden"},
    {"Werbetafel bearbeiten"},
    {"Eventpreise anzeigen"},
    {"Minen Informationen"},
    {"Jobpunkt anzeigen"},
    {"Jobkleidung anziehen"},
    {"Skillliste öffnen"},
    {"Skillupgrade bzw. Skillup einsehen"},
    {"Alten Namen eines Spieler einsehen"},
	{"Teamspeak Freischalten"}
};

new const MoneyHelpText[7][]= {
    {"Nächsten Geldautomaten anzeigen"},
    {"Interaktiv mit Geldautomaten"},
    {"Überweisung tätigen"},
    {"Geldcheck vergeben"},
    {"Handyguthaben einsehen"},
    {"Zahlungen tätigen"},
    {"Finanzen einsehen"}
};

new DeathmatchHelpText[19][]= {
    {"Drogen einnehmen"},
    {"Spice einnehmen"},
    {"Kekse essen"},
    {"Booster einnehmen"},
    {"Riegel essen"},
    {"Kampfstyle ändern"},
    {"Waffen aufheben"},
    {"Knastzeit"},
    {"Totzeit"},
    {"Kopfgeld stellen"},
    {"Drive-By tätigen"},
    {"Gangfightwette"},
    {"Gangfight Informationen"},
    {"Gangfight Informationen"},
    {"Streetwar Informationen"},
    {"Tankstelle ausrauben"},
    {"Bank ausrauben"},
    {"Geldtransporter ausrauben"},
    {"NineDemons Safebox ausrauben"}
};

new SellHelpText[4][]= {
    {"Kekse verkaufen"},
    {"Wantedhackercodes verkaufen"},
    {"Drogen verkaufen"},
    {"Waffenteile verkaufen"}
};

new CasinoHelpText[3][]= {
    {"Spielautomat im Casino"},
    {"kartenspiel im Casino"},
    {"gluecksrad im Casino"}
};

new VehicleHelpText[26][]= {
    {"Radio abspielen"},
    {"Fahrzeug aufschließen und abschließen"},
    {"Fahrzeugschlüssel wechseln"},
    {"Fahrzeugschlüssel Slot ändern"},
    {"Fahrzeug orten"},
    {"Fraktionsfahrzeug abschließen"},
    {"Fahrzeug Tanken"},
    {"Fahrzeug verkaufen"},
    {"Parken"},
    {"Licht"},
    {"Motor"},
    {"Fenster öffnen"},
    {"Spieler aus Fahrzeug rauswerfen"},
    {"Kanister benutzen"},
    {"Kofferraum öffnen"},
    {"Kofferraum ansehen"},
    {"Fahrzeugschein ansehen"},
    {"Führerscheine ansehen"},
    {"Scheinsperre Informationen"},
    {"Fahrzeug Informationen"},
    {"Mietfahrzeug abschließen"},
    {"Fahrzeug mieten"},
    {"Mietfahrzeug abgeben"},
    {"Mietfahrzeug abschließen"},
    {"Mietfahrzeug orten"},
    {"Führerscheinprüfung starten"}
};

new HouseHelpText[15][]= {
    {"Haus kaufen"},
    {"Wohnort anzeigen"},
    {"Haussafebox und Waffenlager"},
    {"Wohnung mieten"},
    {"Haustür abschließen und aufschließen"},
    {"Hausmenü"},
    {"Haus an einen Spieler verkaufen"},
    {"Haus an den Staat verkaufen"},
    {"Mieterliste"},
    {"Mieter kündigen"},
    {"Allen Mietern kündigen"},
    {"Haus an den Staat verkaufen"},
    {"Hoteltür abschließen und aufschließen"},
    {"Hotelraum mieten"},
    {"Hotelraum kündigen"}
};

new BizHelpText[9][]= {
    {"Business kaufen"},
    {"Business verkaufen"},
    {"Business an den Staat verkaufen"},
    {"Business Kasse"},
    {"Business Kasse"},
    {"Business aufschließen und abschließen"},
    {"Business Eintritt festlegen"},
    {"Business Waren kaufen"},
    {"Business Waren kaufen"}
};

new TankstelleHelpText[8][]= {
    {"Tankstelle kaufen"},
    {"Tankstelle verkaufen"},
    {"Tankstelle an den Staat verkaufen"},
    {"Tankstelle Benzinlager"},
    {"Tankstelle Kasse"},
    {"Tankstelle Kasse"},
    {"Tankstelle Sprit kaufen"},
    {"Tankstelle Sprit kaufen"}
};

new FirmenHelpText[4][]= {
    {"Firmen Kasse"},
    {"Firmen Gehalt anpassen"},
    {"Firmennachricht"},
    {"Spieler entlassen"}
};

new ChatHelpText[18][]= {
    {"flüstern"},
    {"schreien"},
    {"Neulingschat"},
    {"Roleplay Chat"},
    {"Job Chat"},
    {"Reden Animation"},
    {"Gobaler Serverchat"},
    {"Chats ausschalten"},
    {"Spieler anrufen"},
    {"SMS schreiben"},
    {"Anruf auflegen"},
    {"Anruf abnehmen"},
    {"Guthaben einsehen"},
    {"Handy anschalten und ausschalten"},
    {"Freundschaftsanfrage senden"},
    {"Freund löschen"},
    {"Freundschaftsliste"},
    {"Freundschaftschat"}
};

new HaustierHelpText[4][]= {
    {"Haustier"},
    {"Haustier verkaufen"},
    {"Haustier füttern"},
    {"Haustiershop"}
};

new LeaderHelpText[1][]= {
    {"leaderhelp"}
};

new SupporterHelp[47][]= {
    {"Goto"},
    {"Gethere"},
    {"Gotobiz"},
    {"Gotopos"},
    {"Gotoliste"},
    {"Gotocar"},
    {"Getcar"},
    {"Spawncar"},
    {"Respawncar"},
    {"Respawnallcars"},
    {"RJobcars"},
    {"RFrakcars"},
    {"Aschlagen"},
    {"Fraktionen"},
    {"Jobs"},
    {"Kick"},
    {"Ban"},
    {"Spawn"},
    {"Supauto"},
    {"Check"},
    {"Tickets"},
    {"Openticket"},
    {"Closeticket"},
    {"Delticket"},
    {"Dticket"},
    {"Aticket"},
    {"Gebannt"},
    {"Gotohaus"},
    {"Delveh"},
    {"Entwicklung"},
    {"Checkscheine"},
    {"Sichercode"},
    {"Freeze"},
    {"Unfreeze"},
    {"Setafk"},
    {"Setback"},
    {"Guncheck"},
    {"Regelwarnung"},
    {"Asettings"},
    {"Admn"},
    {"Adienst"},
    {"Mute"},
    {"Adminhelp"},
    {"ASpec"},
    {"Spec"},
    {"Specoff"},
    {"Sc"}
};

new EventSupporterHelp[32][]= {
    {"Addlabel"},
    {"Removelabel"},
    {"Removealllabels"},
    {"Objectlist"},
    {"Addobject"},
    {"Removeallobjects"},
    {"Removeobject"},
    {"Editobject"},
    {"Gotoobject"},
    {"Delallvehs"},
    {"Clearweapons"},
    {"Eventuhr"},
    {"Eventmarker"},
    {"Aeventitem"},
    {"Eventpunkte"},
    {"Startevent"},
    {"Stopevent"},
    {"Awiederbeleben"},
    {"SetHP"},
    {"SetArmor"},
    {"Setmark"},
    {"Gotomark"},
    {"Delmark"},
    {"Waffeumgebung"},
    {"Healumgebung"},
    {"Armorumgebung"},
    {"Freezeumgebung"},
    {"Unfreezeumgebung"},
    {"Veh"},
    {"Spawnall"},
    {"Gotocp"},
    {"Givegun"}
};

new ModeratorHelp[57][]= {
    {"Setkasse"},
    {"VW"},
    {"SetVW"},
    {"Adminwarnung"},
    {"LoadFrak"},
    {"Tban"},
    {"Changeweather"},
    {"Setinterior"},
    {"BWStrafen"},
    {"BWStrafe"},
    {"Lastdamage"},
    {"Configplayer"},
    {"Fallover"},
    {"Givecar"},
    {"Prison"},
    {"AFKick"},
    {"IPBan"},
    {"Giveac"},
    {"GCOff"},
    {"Regsperre"},
    {"Giveallscheine"},
    {"Giveschein"},
    {"Verwarnen"},
    {"Entbannen"},
    {"DelFraksperre"},
    {"Fraksperre"},
    {"Settime"},
    {"OffAgeld"},
    {"Offbannen"},
    {"OAFKick"},
    {"Rangeban"},
    {"AddWhitelist"},
    {"Checkskill"},
    {"Nameblacklist"},
    {"Akteneintrag"},
    {"Offprison"},
    {"HWBan"},
    {"HWUnban"},
    {"Stopkredit"},
    {"Spielerip"},
    {"Multiacc"},
    {"Inballon"},
    {"Savehausupgrade"},
    {"Clearchat"},
    {"Gotozone"},
    {"Ageld"},
    {"ALevel"},
    {"ARP"},
    {"CPrison"},
    {"Gebeclub"},
    {"Waffensperre"},
    {"CarOwner"},
    {"OffTban"},
    {"OffCPrison"},
    {"Zollsperre"},
    {"Offverwarnen"},
    {"atafelentmieten"}
};

new FraktionsverwalterHelp[12][]= {
    {"Makeleader"},
    {"Setzoneowner"},
    {"Setbizowner"},
    {"Gebietupgrade"},
    {"Fsbreset"},
    {"Createfcar"},
    {"FCarcolor"},
    {"Delfcar"},
    {"DelAllFCars"},
    {"Delzeitsperre"},
    {"Kampfzone"},
    {"fsettings"}
};

new AdministratorHelp[51][]= {
    {"Namechange"},
    {"PWChange"},
    {"Configtanke"},
    {"Confighouse"},
    {"Configbiz"},
    {"Tankstand"},
    {"Auftanken"},
    {"SetBWStrafe"},
    {"Createhouse"},
    {"Makeadmin"},
    {"OffMakeadmin"},
    {"MakeBMod"},
    {"OffMakeBMod"},
    {"MakeFV"},
    {"OffMakeFV"},
    {"SACBan"},
    {"Amotor"},
    {"Givecoins"},
    {"Purge"},
    {"PGiveGun"},
    {"PGiveHealth"},
    {"PGiveArmor"},
    {"Allesspeichern"},
    {"SFreischalten"},
    {"Rauswerfenhoten"},
    {"Fixveh"},
    {"DelZeitsperre"},
    {"BFreischalten"},
    {"DelClub"},
    {"GebeFirma"},
    {"DelFirma"},
    {"DelHaus"},
    {"AUnlock"},
    {"DelAllGVehs"},
    {"FSettings"},
    {"CreateGutschein"},
    {"Deakaccount"},
    {"Aktaccount"},
    {"Gebeskill"},
    {"Gmsg"},
    {"Nachricht"},
    {"Makeleader"},
    {"Setzoneowner"},
    {"Setbizowner"},
    {"Gebietupgrade"},
    {"Fsbreset"},
    {"Createfcar"},
    {"FCarcolor"},
    {"Delfcar"},
    {"DelAllFCars"},
    {"Kampfzone"}
};

new VertretungBennyHelp[11][]= {
    {"Creategutschein"},
    {"Amotor"},
    {"Pwchange"},
    {"Aunlock"},
    {"Givecoins"},
    {"Configbiz"},
    {"Makeadmin (0-3)"},
    {"Makebmod"},
    {"Offmakebmod"},
    {"Makefv"},
    {"Offmakefv"}
};

new ManagerHelp[11][]= {
    {"VehColor"},
    {"Tazer"},
    {"Animationdebug"},
    {"GivePayDay"},
    {"Startlotto"},
    {"GMX"},
    {"Createtanke"},
    {"CreateAPlatz"},
    {"Event"},
    {"Adminmaske"},
    {"CreateHotelroom"}
};

new ProjektleiterHelp[11][]= {
    {"Makeadmin"},
    {"Offmakeadmin"},
    {"Gmx"},
    {"Event"},
    {"Pwchange"},
    {"Givecoins"},
    {"Vehcolor"},
    {"Jailtimeout"},
    {"Debugpos"},
    {"Tankstand"},
    {"Auftanken"}
};

/*new RconHelp[11][]= {
    {"Makeadmin"},
    {"Gmx"}
};*/


// - - - - - - - - - - - - - - -
