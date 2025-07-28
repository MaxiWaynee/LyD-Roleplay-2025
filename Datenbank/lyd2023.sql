-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Erstellungszeit: 23. Dez 2023 um 21:56
-- Server-Version: 10.3.39-MariaDB-0+deb10u1
-- PHP-Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `lyd2023`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `accounts`
--

CREATE TABLE `accounts` (
  `id` int(11) NOT NULL,
  `Name` varchar(24) NOT NULL,
  `Passwort` varchar(128) NOT NULL,
  `Level` int(11) NOT NULL,
  `Admin` int(11) NOT NULL,
  `DonateRank` int(11) NOT NULL,
  `Hours` int(11) NOT NULL,
  `Sex` int(11) NOT NULL,
  `Muted` int(11) NOT NULL,
  `Exp` int(11) NOT NULL,
  `MaxExp` int(11) NOT NULL,
  `Cash` int(11) NOT NULL,
  `Crimes` int(11) NOT NULL,
  `Kills` int(11) NOT NULL,
  `Deaths` int(11) NOT NULL,
  `Arrested` int(11) NOT NULL,
  `WantedDeaths` int(11) NOT NULL,
  `PhoneBook` int(11) NOT NULL,
  `LottoNr` int(11) NOT NULL,
  `Job` int(11) NOT NULL,
  `PayCheck` int(11) NOT NULL,
  `Jailed` int(11) NOT NULL,
  `JailTime` int(11) NOT NULL,
  `Mats` int(11) NOT NULL,
  `Drugs` int(11) NOT NULL,
  `Fraktion` int(11) NOT NULL,
  `Rank` int(11) NOT NULL,
  `Skin` int(11) NOT NULL,
  `BizKey` int(11) NOT NULL,
  `CarLic` int(11) NOT NULL,
  `FlyLic` int(11) NOT NULL,
  `BoatLic` int(11) NOT NULL,
  `GunLic` int(11) NOT NULL,
  `LKWLic` int(11) NOT NULL,
  `MotoLic` int(11) NOT NULL,
  `PayDay` int(11) NOT NULL,
  `Tut` int(11) NOT NULL,
  `Warns` int(11) NOT NULL,
  `Perso` int(11) NOT NULL,
  `HandyNr` int(11) NOT NULL,
  `HandyGeld` int(11) NOT NULL,
  `Tot` int(11) NOT NULL,
  `Banned` int(11) NOT NULL,
  `Wanteds` int(11) NOT NULL,
  `Bank` int(11) NOT NULL DEFAULT 0,
  `JailType` int(11) NOT NULL,
  `TotTime` int(11) NOT NULL,
  `TotX` float NOT NULL,
  `TotY` float NOT NULL,
  `TotZ` float NOT NULL,
  `TotWorld` int(11) NOT NULL,
  `Kanister` int(11) NOT NULL,
  `Waffenteile` int(11) NOT NULL,
  `Drogen` int(11) NOT NULL,
  `SafeTeile` int(11) NOT NULL,
  `SafeDrogen` int(11) NOT NULL,
  `SpawnChange` int(11) NOT NULL,
  `TankKey` int(11) NOT NULL,
  `Kekse` int(11) NOT NULL,
  `Zigaretten` int(11) NOT NULL,
  `FrakLohn` int(11) NOT NULL,
  `TimeBan` int(128) NOT NULL,
  `MuteTime` int(11) NOT NULL,
  `Angel` int(11) NOT NULL,
  `Fische` int(11) NOT NULL,
  `Koeder` int(11) NOT NULL,
  `MaxFishes` int(11) NOT NULL,
  `MaxVerloren` int(11) NOT NULL,
  `FishLic` int(11) NOT NULL,
  `FPunkte` int(10) NOT NULL DEFAULT 0,
  `FBPunkte` int(10) NOT NULL DEFAULT 0,
  `FlPunkte` int(10) NOT NULL DEFAULT 0,
  `GunPunkte` int(10) NOT NULL DEFAULT 0,
  `LKWPunkte` int(10) NOT NULL DEFAULT 0,
  `MotoPunkte` int(10) NOT NULL DEFAULT 0,
  `Marriage` int(11) DEFAULT 0,
  `FrakSperre` tinyint(1) NOT NULL,
  `Hartz4` int(11) NOT NULL,
  `KFZSteuer` int(11) NOT NULL,
  `GebanntVon` varchar(24) DEFAULT NULL,
  `BanGrund` varchar(128) DEFAULT NULL,
  `WantedCodes` int(11) NOT NULL,
  `SafeWantedCodes` int(11) NOT NULL,
  `Startbonus` int(11) NOT NULL,
  `HurePoints` int(11) NOT NULL,
  `DetectivPoints` int(11) NOT NULL,
  `LastSeen` timestamp NOT NULL DEFAULT current_timestamp(),
  `SecureCode` varchar(10) DEFAULT NULL,
  `Staat` varchar(30) NOT NULL DEFAULT 'Zigeuner',
  `BankKonto` int(11) NOT NULL DEFAULT 0,
  `BankPin` int(11) NOT NULL DEFAULT 0,
  `Boeller` int(11) NOT NULL,
  `Raketen` int(11) NOT NULL,
  `JobWechsel` int(11) NOT NULL,
  `Krankenversicherung` int(11) NOT NULL,
  `DrogenSamen` int(11) NOT NULL,
  `Geburtstag` varchar(20) DEFAULT NULL,
  `Spice` int(11) NOT NULL,
  `SafeSpice` int(11) NOT NULL,
  `Handy` int(11) NOT NULL,
  `Kampfstyle` int(11) NOT NULL,
  `Brecheisen` int(11) NOT NULL,
  `SperreFahr` int(11) NOT NULL,
  `SperreBoot` int(11) NOT NULL,
  `SperreFlug` int(11) NOT NULL,
  `SperreWaffe` int(11) NOT NULL,
  `SperreLKW` int(11) NOT NULL,
  `SperreMoto` int(11) NOT NULL,
  `HotelKey` int(11) NOT NULL,
  `SSteuer` int(11) NOT NULL,
  `Helm` int(11) NOT NULL,
  `Experte` int(11) NOT NULL,
  `Lobe` int(11) NOT NULL,
  `BMOD` int(11) NOT NULL,
  `Kreditwert` int(11) NOT NULL,
  `KreditGezahlt` int(11) NOT NULL,
  `MP3Player` int(11) NOT NULL,
  `PremiumCarSlot` int(11) NOT NULL,
  `SpawnX` float NOT NULL,
  `SpawnY` float NOT NULL,
  `SpawnZ` float NOT NULL,
  `SpawnFace` float NOT NULL,
  `SpawnInt` int(11) NOT NULL,
  `SpawnVirtual` int(11) NOT NULL,
  `Koffer` int(11) NOT NULL,
  `weapondata_slot00` int(11) NOT NULL,
  `weapondata_slot01` int(11) NOT NULL,
  `weapondata_slot02` int(11) NOT NULL,
  `weapondata_slot03` int(11) NOT NULL,
  `weapondata_slot04` int(11) NOT NULL,
  `weapondata_slot05` int(11) NOT NULL,
  `weapondata_slot06` int(11) NOT NULL,
  `weapondata_slot07` int(11) NOT NULL,
  `weapondata_slot08` int(11) NOT NULL,
  `weapondata_slot09` int(11) NOT NULL,
  `weapondata_slot10` int(11) NOT NULL,
  `weapondata_slot11` int(11) NOT NULL,
  `weapondata_slot12` int(11) NOT NULL,
  `UpgradeWaffenlager` int(11) NOT NULL,
  `UpgradeSafebox` int(11) NOT NULL,
  `HausWaffenlager` int(11) NOT NULL,
  `HausSafeboxSpice` int(11) NOT NULL,
  `HausSafeboxDrogen` int(11) NOT NULL,
  `Haustier` int(11) NOT NULL,
  `HaustierCooldown` int(11) NOT NULL,
  `HaustierFutter` int(11) NOT NULL,
  `ipadresse` varchar(16) NOT NULL,
  `GunLicB` int(11) NOT NULL,
  `RadarfallenWarnung` int(11) NOT NULL,
  `PremiumBizSlot` int(11) NOT NULL,
  `HouseMieteKey` int(11) NOT NULL,
  `PrisonRunCount` int(11) NOT NULL,
  `PrisonRun` int(11) NOT NULL,
  `ZollValid` int(11) NOT NULL,
  `SaltKey` varchar(32) NOT NULL,
  `LawyerPoints` int(11) NOT NULL,
  `WaffenSperre` int(11) NOT NULL,
  `KFZVersicherung` int(11) NOT NULL,
  `TrakLic` int(11) NOT NULL,
  `CarmALic` int(11) NOT NULL,
  `KillsGangFight` int(11) DEFAULT NULL,
  `email` varchar(64) NOT NULL,
  `vorname` varchar(32) NOT NULL,
  `PremiumNeon` int(11) NOT NULL,
  `Automatik` int(11) NOT NULL,
  `DrogenPoints` int(11) NOT NULL,
  `WaffenteilePoints` int(11) NOT NULL,
  `frakwarn` int(11) NOT NULL,
  `Deakacc` int(11) NOT NULL,
  `Schulden` int(11) NOT NULL,
  `Weihnachtsday` int(11) NOT NULL,
  `fahrlehrerboni` int(11) NOT NULL,
  `MarriageName` char(32) NOT NULL,
  `Deakaccadmin` varchar(32) NOT NULL,
  `userPremium` int(11) NOT NULL,
  `BWStrafe` int(11) NOT NULL DEFAULT 0,
  `BWStrafeGrund` varchar(128) NOT NULL,
  `Eventpoints` int(11) NOT NULL DEFAULT 0,
  `AdventDay` int(11) NOT NULL DEFAULT 0,
  `AdventMin` int(11) NOT NULL DEFAULT 0,
  `Nikolaus` int(11) NOT NULL DEFAULT 0,
  `MustUseAC` int(1) NOT NULL DEFAULT 0,
  `KillsStreetwar` int(11) NOT NULL DEFAULT 0,
  `ChatSettings` bit(7) NOT NULL DEFAULT b'1101111',
  `GangDrogenSamen` int(11) NOT NULL DEFAULT 0,
  `FV` int(11) NOT NULL DEFAULT 0,
  `SpiceSamenPoints` int(11) NOT NULL DEFAULT 0,
  `PilotPoints` int(11) NOT NULL DEFAULT 0,
  `C4` int(11) NOT NULL DEFAULT 0,
  `Pfand` int(11) NOT NULL DEFAULT 0,
  `KrauterMische` int(11) NOT NULL DEFAULT 0,
  `Oldname` varchar(255) NOT NULL,
  `swSpiceSp` int(11) NOT NULL DEFAULT 0,
  `DmgTogl` int(11) NOT NULL DEFAULT 0,
  `FradarStat` int(11) NOT NULL DEFAULT 0,
  `swDrogenSp` int(11) NOT NULL DEFAULT 0,
  `swWTSp` int(11) NOT NULL DEFAULT 0,
  `swCodesSp` int(11) NOT NULL DEFAULT 0,
  `PBPoints` int(11) NOT NULL,
  `OverWatch` int(11) NOT NULL,
  `SpielerOnline` int(11) NOT NULL,
  `HausWaffenlager2` int(11) DEFAULT NULL,
  `HausWaffenlager3` int(11) DEFAULT NULL,
  `hwid` varchar(255) DEFAULT NULL,
  `SpawnWeste` int(11) DEFAULT NULL,
  `Booster` int(11) DEFAULT NULL,
  `PowerRiegel` int(11) DEFAULT NULL,
  `TSFrei` int(1) NOT NULL DEFAULT 0,
  `SpawnWaffenUnix` int(11) DEFAULT NULL,
  `SpawnWaffen` int(11) DEFAULT NULL,
  `Schaufel` int(11) NOT NULL DEFAULT 0
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Daten für Tabelle `accounts`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `akte`
--

CREATE TABLE `akte` (
  `id` int(11) NOT NULL,
  `time` timestamp NOT NULL DEFAULT current_timestamp(),
  `spieler` text NOT NULL,
  `admin` text NOT NULL,
  `content` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `akte`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `angel`
--

CREATE TABLE `angel` (
  `ID` int(11) NOT NULL,
  `PosX` float NOT NULL,
  `PosY` float NOT NULL,
  `PosZ` float NOT NULL,
  `Fische` int(11) NOT NULL,
  `FacingAngle` float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `angel`
--

INSERT INTO `angel` (`ID`, `PosX`, `PosY`, `PosZ`, `Fische`, `FacingAngle`) VALUES
(58, 824.9, -2066.53, 12.85, 20, 179),
(57, 828.14, -2066.61, 12.85, 20, 184),
(56, 831.46, -2066.76, 12.85, 20, 181),
(55, 834.65, -2066.58, 12.85, 20, 182),
(54, 838.03, -2066.61, 12.85, 20, 178),
(53, 841.39, -2066.75, 12.85, 20, 181),
(52, 844.52, -2066.62, 12.85, 20, 172),
(51, 847.71, -2066.62, 12.85, 20, 179),
(59, 1967.76, -1220.18, 20.02, 20, 100),
(60, 694, -1919.06, 1.12, 20, 180),
(61, 696.66, -1918.21, 1.29, 20, 180.9),
(62, 697.55, -1918.51, 1.24, 2, 265.05),
(63, 685.53, -1919.93, 1.04, 2, 162.75),
(64, 685.2, -1920.08, 1.02, 1, 72.75),
(65, 693.05, -1918.53, 1.23, 2, 225.64),
(66, 692.86, -1919.05, 1.14, 99, 131.55),
(67, 692.1, -1920.19, 0.96, 150, 131.55),
(68, 1342.91, -1734.04, 12.95, 100, 149.42),
(69, 1322.83, -1735.04, 12.94, 100, 149.42),
(70, 1313.06, -1698.14, 12.94, 100, 149.42),
(71, 1313.38, -1661.27, 12.94, 1, 149.42),
(72, 1313.21, -1645.87, 12.94, 1, 149.42),
(73, 1313.59, -1597.55, 12.94, 1, 149.42),
(74, 391.24, -2088.79, 7.83, 1, 193.56),
(75, 390.57, -2088.57, 7.83, 100, 167.28),
(76, 390.57, -2088.57, 7.83, 150, 167.28);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `bank`
--

CREATE TABLE `bank` (
  `ID` int(11) NOT NULL,
  `An` text NOT NULL,
  `Von` text NOT NULL,
  `Datum` int(11) NOT NULL,
  `Betrag` int(11) NOT NULL,
  `Grund` text NOT NULL,
  `PushOnlineVon` int(11) NOT NULL,
  `PushOnlineAn` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `benachrichtigung`
--

CREATE TABLE `benachrichtigung` (
  `id` int(100) UNSIGNED NOT NULL,
  `userid` varchar(100) NOT NULL,
  `text` longtext NOT NULL,
  `time` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `beschwerde`
--

CREATE TABLE `beschwerde` (
  `id` int(11) NOT NULL,
  `player` varchar(255) DEFAULT NULL,
  `defendant` varchar(255) DEFAULT NULL,
  `summary` varchar(255) DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `status` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `beschwerde`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `beschwerdeantwort`
--

CREATE TABLE `beschwerdeantwort` (
  `id` int(11) NOT NULL,
  `beschwerdeid` int(11) DEFAULT NULL,
  `author` varchar(255) DEFAULT NULL,
  `content` longtext DEFAULT NULL,
  `time` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `beschwerdeantwort`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `bizes`
--

CREATE TABLE `bizes` (
  `ID` int(11) NOT NULL,
  `EnterX` float NOT NULL,
  `EnterY` float NOT NULL,
  `EnterZ` float NOT NULL,
  `ExitX` float NOT NULL,
  `ExitY` float NOT NULL,
  `ExitZ` float NOT NULL,
  `Besitzer` varchar(24) NOT NULL,
  `Name` varchar(64) NOT NULL,
  `Preis` int(11) NOT NULL,
  `Lock` int(11) NOT NULL,
  `Interior` int(11) NOT NULL,
  `Kasse` int(11) NOT NULL,
  `Eintritt` int(11) NOT NULL,
  `Waren` int(11) NOT NULL,
  `MaxWaren` int(11) NOT NULL,
  `WarenPreis` int(11) NOT NULL,
  `LadenAuf` int(11) NOT NULL,
  `LadenZu` int(11) NOT NULL,
  `erpresserfraktion` int(11) NOT NULL,
  `erpresserforderung` int(11) NOT NULL,
  `erpresserstate` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `bizes`
--

INSERT INTO `bizes` (`ID`, `EnterX`, `EnterY`, `EnterZ`, `ExitX`, `ExitY`, `ExitZ`, `Besitzer`, `Name`, `Preis`, `Lock`, `Interior`, `Kasse`, `Eintritt`, `Waren`, `MaxWaren`, `WarenPreis`, `LadenAuf`, `LadenZu`, `erpresserfraktion`, `erpresserforderung`, `erpresserstate`) VALUES
(1, 1368.06, -1279.67, 13.52, 285.79, -85.8, 1001.52, 'SERVER', 'Los Santos Ammunation', 125000000, 0, 4, 18060, 1000, 3921, 5000, 500, 0, 24, 6, 0, 0),
(20, 1196.31, -915.28, 43.31, 363.32, -74.62, 1001.51, 'SERVER', 'Subway', 30000000, 0, 10, 104300, 1000, 699, 1000, 50, 6, 24, 10, 0, 0),
(2, 2159.12, 943.19, 10.81, 286.14, -40.63, 1001.52, 'SERVER', 'Ammunation - Las Venturas', 150000000, 0, 1, 1250, 1000, 3773, 5000, 500, 0, 24, 7, 0, 0),
(18, 811, -1616.06, 13.52, 363.32, -74.62, 1001.51, 'SERVER', 'Burger Shot Verona Beach', 15000000, 0, 10, 0, 1000, 400, 500, 500, 6, 22, 0, 0, 0),
(5, 2105.37, -1806.53, 13.55, 372.26, -133.11, 1001.46, 'SERVER', 'Pizza Stack Idlewood', 15000000, 0, 5, 5200, 1000, 369, 500, 50, 11, 22, 12, 0, 0),
(6, 1102.52, -1457.93, 15.77, 372.26, -133.11, 1001.46, 'SERVER', 'Pizza Stack - Shopping Market', 2500000, 0, 5, 1000, 1000, 490, 500, 20, 8, 24, 13, 0, 0),
(19, -1912.18, 827.96, 35.2, 363.32, -74.62, 1001.51, 'SERVER', 'Burger Shot San Fierro Downtown', 1500000, 0, 10, 0, 1000, 490, 500, 20, 6, 24, 0, 0, 0),
(7, 2332.62, 75.01, 26.62, 372.26, -133.11, 1001.46, 'SERVER', 'Pizza Stack Palomino Creek', 2500000, 0, 5, 0, 1000, 484, 500, 20, 11, 22, 20, 0, 0),
(10, 2393.12, 2042, 10.81, 365.17, -11.01, 1001.84, 'SERVER', 'Cluckin Bell Old Venturas Strip', 1000000, 0, 9, 0, 1000, 500, 500, 10, 10, 20, 7, 0, 0),
(11, 1098.91, -1473.68, 15.77, 365.17, -11.01, 1001.84, 'SERVER', 'Cluckin Bell - Shopping Market', 2500000, 0, 9, 0, 1000, 479, 500, 20, 8, 24, 10, 0, 0),
(12, 2102.62, 2228.87, 11.02, 365.17, -11.01, 1001.84, 'SERVER', 'Cluckin Bell Emerald Isle', 15000000, 0, 9, 0, 850, 496, 500, 20, 8, 24, 11, 0, 0),
(8, 2083.12, 2224.33, 11.02, 372.26, -133.11, 1001.46, 'SERVER', 'Pizza Stack Emerald Isle', 15000000, 0, 5, 0, 500, 498, 500, 20, 8, 24, 21, 0, 0),
(15, 1873.06, 2071.62, 11.06, 363.32, -74.62, 1001.51, 'SERVER', 'Burger Shot Redsands East', 1000000, 0, 10, 0, 1000, 496, 500, 20, 8, 24, 20, 0, 0),
(16, 1158.56, 2072.12, 11.06, 363.32, -74.62, 1001.51, 'SERVER', 'Burger Shot Whitewood Estates', 1000000, 0, 10, 0, 500, 498, 500, 20, 7, 21, 21, 0, 0),
(13, 2398.12, -1898.42, 13.52, 365.17, -11.01, 1001.84, 'SERVER', 'Cluckin Bell Willowfield', 2500000, 0, 9, 0, 1000, 488, 500, 20, 10, 24, 12, 0, 0),
(49, 888.53, -924.53, 42.38, 0, 0, 0, 'SERVER', 'Autohaus - Oldtimer', 750000000, 0, 0, 38625000, 1000, 4830, 5000, 30, 10, 23, 0, 0, 0),
(54, -1491.29, 717.82, 7.17, 0, 0, 0, 'SERVER', 'Bootsverkauf in San Fierro', 100000000, 0, 0, 0, 1000, 390, 500, 20, 10, 20, 0, 0, 0),
(21, 1315.55, -897.9, 39.56, 6.09, -29.27, 1003.53, 'SERVER', '24/7 am BSN', 100000000, 0, 10, -20125, 1000, 5925, 5000, 60, 0, 24, 6, 0, 0),
(22, 1352.31, -1759.04, 13.5, 6.09, -29.27, 1003.53, 'SERVER', '24/7 Stadthalle', 120000000, 0, 10, 304300, 1000, 5160, 5000, 60, 0, 24, 7, 0, 0),
(23, 1833.66, -1842.52, 13.56, 6.09, -29.27, 1003.53, 'SERVER', '24/7 Alhambra', 20000000, 0, 10, 12500, 1000, 2898, 5000, 30, 0, 24, 0, 0, 0),
(14, 2420.12, -1509.06, 24, 365.17, -11.01, 1001.84, 'SERVER', 'Cluckin Bell East Los Santos', 15000000, 0, 9, 0, 1000, 0, 500, 10, 10, 24, 13, 0, 0),
(24, 2424.11, -1742.54, 13.52, 6.09, -29.27, 1003.53, 'SERVER', '24/7 Grove Street', 100000000, 0, 10, 47450, 1000, 1073, 5000, 20, 0, 24, 0, 0, 0),
(25, 1154.65, -1457.93, 15.77, 6.09, -29.27, 1003.53, 'SERVER', '24/7 - Shopping Market', 100000000, 0, 10, -118493, 1, 5000, 5000, 60, 0, 24, 0, 0, 0),
(52, 1293.81, 1335.93, 10.81, 0, 0, 0, 'SERVER', 'Flugzeugverkauf in Las Venturas', 500000000, 0, 0, 0, 999, 4683, 5000, 20, 0, 24, 0, 0, 0),
(46, 2133.62, -1122.78, 25.37, 0, 0, 0, 'SERVER', 'Autohaus günstig in Los Santos', 100000000, 0, 0, 757200, 1000, 4317, 5000, 20, 8, 23, 0, 0, 0),
(45, -73.05, -554.08, 3.7, 0, 0, 0, 'SERVER', 'Bootsverleih Los Santos', 50000000, 0, 0, 0, 1000, 500, 500, 20, 0, 24, 0, 0, 0),
(17, -2336.37, -166.83, 35.54, 363.32, -74.62, 1001.51, 'SERVER', 'Burger Shot Garcia', 1500000, 0, 10, 0, 1000, 494, 500, 20, 6, 24, 0, 0, 0),
(47, 1810.06, -1882.31, 13.56, 0, 0, 0, 'SERVER', 'Autohaus - Normal', 25000000, 0, 0, 0, 1000, 4990, 5000, 500, 0, 24, 0, 0, 0),
(48, 221.85, -1437.93, 13.31, 0, 0, 0, 'SERVER', 'Autohaus - Luxus', 500000000, 0, 0, 17828450, 1000, 900, 1000, 100000, 0, 24, 0, 0, 0),
(53, 2510.79, -1518.28, 23.92, 0, 0, 0, 'SERVER', 'Motorrad Los Santos', 200000000, 0, 0, 2670000, 1000, 4520, 5000, 500, 0, 24, 0, 0, 0),
(51, 1843.4, -2572.51, 13.52, 0, 0, 0, 'SERVER', 'Flugzeugverkauf Los Santos', 900000000, 0, 0, 15000000, 100, 2445, 3000, 500, 0, 24, 0, 0, 0),
(29, 1456.43, -1138.15, 23.95, 161.38, -93.15, 1001.78, 'SERVER', 'ZIP-Kleidergeschäft Zentralbank', 70000000, 0, 18, 42000, 1000, 456, 1000, 50, 0, 24, 0, 0, 0),
(36, 461.26, -1501, 30.62, 226.27, -7.42, 1002.21, 'SERVER', 'Victim Kleidungsgeschäft', 70000000, 0, 5, 3000, 1000, 946, 1000, 20, 9, 23, 0, 0, 0),
(63, 1739.31, -1583.15, 14.14, 2215.31, -1150.43, 1025.8, 'SERVER', 'Paintball-Arena Los Santos', 60000000, 0, 15, 139000, 1000, 500, 500, 500, 0, 24, 0, 0, 0),
(3, 2400.54, -1981.56, 13.52, 316.42, -169.41, 999.59, 'SERVER', 'Ammunation Willowfield', 150000000, 0, 6, 7520, 1000, 4964, 5000, 500, 0, 24, 6, 0, 0),
(50, 2094.06, 1387.31, 10.81, 0, 0, 0, 'SERVER', 'Autohaus günstig in Las Ventura', 100000000, 0, 0, 79200, 1000, 460, 500, 20, 6, 22, 0, 0, 0),
(61, 2421.6, -1220.43, 25.45, 1204.93, -13.47, 1000.9, 'SERVER', 'Laufhaus - Los Santos', 8000000, 0, 2, 4000, 1000, 1000, 1000, 500, 0, 24, 0, 0, 0),
(37, 2078.12, -1781.56, 13.52, 0, 0, 0, 'SERVER', 'Carsharing Idlewood', 50000000, 0, 0, 62400, 1, 500, 500, 100, 0, 24, 0, 0, 0),
(55, 987.15, -1982.39, 8.17, 0, 0, 0, 'SERVER', 'Bootshaus Verona Beach', 200000000, 0, 0, 1080000, 361, 940, 1000, 300, 0, 24, 0, 0, 0),
(57, 701.53, -1186.68, 15.89, 0, 0, 0, 'SERVER', 'Fahrradladen East Los Santos', 50000000, 0, 0, 54600, 500, 345, 500, 200, 0, 24, 0, 0, 0),
(43, 765.59, -1347.17, 13.51, 0, 0, 0, 'SERVER', 'Autoverleih am Neulingsspawn', 50000000, 0, 0, 16200, 1000, 1000, 1000, 500, 0, 24, 0, 0, 0),
(62, 1806.56, -1723.9, 13.52, 0, 0, 0, 'SERVER', 'Haustiershop', 60000000, 1, 0, 32000, 1000, 917, 1000, 500, 0, 24, -1, 0, 0),
(64, 1222.06, -1414.79, 13.31, 0, 0, 0, 'SERVER', 'Elektromarkt', 120000000, 0, 0, 2832300, 1000, 4649, 5000, 1000, 0, 24, 11, 0, 0),
(44, 1470.68, -2410.87, 13.55, 0, 0, 0, 'SERVER', 'Flugzeugverleih Los Santos', 50000000, 0, 0, 612800, 1000, 1000, 1000, 300, 0, 24, 0, 0, 0),
(38, 903.88, -1412.43, 13.34, 0, 0, 0, 'SERVER', 'CarSharing am Shopping Market', 50000000, 0, 0, 64680, 1000, 500, 500, 20, 0, 24, 0, 0, 0),
(42, 1336.06, -1259.56, 13.52, 0, 0, 0, 'SERVER', 'CarSharing-Station Ammunation', 50000000, 0, 0, 26040, 1, 500, 500, 20, 0, 24, 0, 0, 0),
(39, 939.26, -1769.68, 13.84, 0, 0, 0, 'SERVER', 'CarSharing-Station Verona Beach', 50000000, 0, 0, 31600, 1000, 500, 500, 20, 0, 24, 0, 0, 0),
(40, 1199.53, -1045.8, 31.92, 0, 0, 0, 'SERVER', 'CarSharing-Station am BSN', 50000000, 1, 0, 11040, 1000, 500, 500, 20, 0, 24, 0, 0, 0),
(41, 1580.63, 2622.02, 10.81, 0, 0, 0, 'SERVER', 'CarSharing-Station Prickle Pine', 50000000, 1, 0, 0, 31, 500, 500, 20, 6, 24, 0, 0, 0),
(9, 203.33, -202.52, 1.57, 372.26, -133.11, 1001.46, 'SERVER', 'Pizza Stack - Blue Berry', 2500000, 0, 5, 2050, 1000, 4999, 5000, 500, 0, 24, 6, 0, 0),
(27, 1656.89, 1733.31, 10.81, 207.72, -109.01, 1005.13, 'SERVER', 'Binco - Las Venturas The Visage', 2500000, 0, 15, 0, 1000, 4996, 5000, 500, 0, 24, 0, 0, 0),
(28, 2102.12, 2257.37, 11.02, 207.72, -109.01, 1005.13, 'SERVER', 'Binco - Las Venturas The Emeral', 1000000, 0, 15, 0, 1000, 4994, 5000, 500, 0, 24, 0, 0, 0),
(26, 2244.35, -1665.29, 15.47, 207.72, -109.01, 1005.13, 'SERVER', 'Binco - Los Santos Ganton', 70000000, 0, 15, 180000, 1000, 4824, 5000, 500, 0, 24, 0, 0, 0),
(34, -1694.81, 951.59, 24.87, 226.27, -7.42, 1002.21, 'SERVER', 'VicTim - San Fierro Financial', 1000000, 0, 5, 0, 1000, 4652, 5000, 500, 0, 24, 0, 0, 0),
(35, 2802.62, 2430.37, 11.06, 226.27, -7.42, 1002.21, 'SERVER', 'VicTim - Las Venturas Creek', 2500000, 0, 5, 0, 1000, 4997, 5000, 500, 0, 24, 0, 0, 0),
(30, 2572.04, 1904.78, 11.02, 161.38, -93.15, 1001.78, 'SERVER', 'ZIP - Las Venturas Starfish Cas', 1000000, 0, 18, 0, 1000, 4996, 5000, 500, 0, 24, 0, 0, 0),
(31, -1882.68, 866.09, 35.15, 161.38, -93.15, 1001.78, 'SERVER', 'ZIP - San Fierro Downtown', 2500000, 0, 18, 0, 1000, 4994, 5000, 500, 0, 24, 0, 0, 0),
(33, 2090.37, 2224.08, 11.02, 161.38, -93.15, 1001.78, 'SERVER', 'ZIP - Las Venturas The Emerald ', 2500000, 0, 18, 0, 1000, 4740, 5000, 500, 0, 24, 0, 0, 0),
(65, -2521.05, -624.84, 132.77, 0, 0, 0, 'SERVER', 'Strom GmbH San Andreas', 500000000, 0, 0, 6520000, 1000, 5000, 5000, 1, 0, 24, 0, 0, 0),
(56, 830.59, -2038.56, 12.85, 0, 0, 0, 'SERVER', 'Angelshop Los Santos', 40000000, 0, 0, 9600, 1000, 4440, 5000, 500, 0, 24, 0, 0, 0),
(60, 1836.06, -1682.43, 13.35, 493.32, -24, 1000.65, 'SERVER', 'Alhambra Disco', 5000000, 0, 17, 8000, 1000, 5000, 5000, 500, 0, 24, 0, 0, 0),
(59, 1328.18, -1558.31, 13.52, 1726.68, -1638.56, 20.2, 'SERVER', 'Los Santos Hotel', 80000000, 0, 18, 68000, 1000, 485, 500, 500, 0, 24, 0, 0, 0),
(58, 1498.4, -1582.42, 13.52, 1133.05, -15.39, 1000.65, 'SERVER', 'Los Santos - Großes Casino', 200000000, 0, 12, 69000, 1000, 5000, 5000, 500, 0, 24, 10, 0, 0),
(4, 1512.31, -1679.56, 13.51, 285.79, -85.8, 1001.52, 'SERVER', 'Stadthalle Ammunation', 11000000, 0, 4, 378820, 1000, 4020, 5000, 500, 0, 24, 7, 0, 0);

-- --------------------------------------------------------


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `blacklist`
--

CREATE TABLE `blacklist` (
  `ID` int(11) NOT NULL,
  `Name` varchar(24) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `blacklist`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `cp_buy`
--

CREATE TABLE `cp_buy` (
  `id` int(11) NOT NULL,
  `userID` int(11) NOT NULL DEFAULT 0,
  `status` int(11) NOT NULL,
  `time` int(11) NOT NULL,
  `paymentMethod` int(11) NOT NULL,
  `paymentAmount` int(11) NOT NULL,
  `paymentInfo` text DEFAULT NULL,
  `vorname` text NOT NULL,
  `nachname` text NOT NULL,
  `forenname` text NOT NULL,
  `email` text NOT NULL,
  `telefonnummer` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `cp_orders`
--

CREATE TABLE `cp_orders` (
  `id` int(11) NOT NULL,
  `time` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  `productID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `cp_sessions`
--

CREATE TABLE `cp_sessions` (
  `id` int(11) NOT NULL,
  `sID` varchar(64) NOT NULL,
  `userID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `cp_users`
--

CREATE TABLE `cp_users` (
  `userID` int(11) NOT NULL,
  `userName` varchar(32) NOT NULL,
  `userPassword` varchar(128) NOT NULL,
  `userAdmin` int(11) NOT NULL DEFAULT 0,
  `userPremium` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `firma`
--

CREATE TABLE `firma` (
  `id` int(11) NOT NULL,
  `jobid` int(11) NOT NULL,
  `bezeichnung` varchar(32) NOT NULL,
  `besitzer` varchar(24) NOT NULL,
  `kasse` int(11) NOT NULL,
  `gehalt` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `firma`
--

INSERT INTO `firma` (`id`, `jobid`, `bezeichnung`, `besitzer`, `kasse`, `gehalt`) VALUES
(1, 1, 'Bauerei GmbH', 'Niemand', 895000, 25000),
(2, 2, 'Bus Gesellschaft', 'Niemand', 1076040, 25000),
(3, 4, 'Flugbetrieb', 'Niemand', 88000, 25000),
(4, 3, 'Transport GmbH', 'Niemand', 56098, 25000),
(5, 7, 'Straßenreinigungsbetrieb', 'Niemand', 88000, 25000),
(6, 8, 'Abfallentsorgungsbetrieb', 'Niemand', 8000, 25000),
(7, 9, 'Gärtnerei GmbH', 'Niemand', 152000, 2500),
(8, 10, 'Bauarbeiter GmbH', 'Niemand', 8000, 25000),
(9, 11, 'Schiffstransport GmbH', 'Niemand', 864000, 25000),
(10, 12, 'Security Transport GmbH', 'Niemand', 0, 25000),
(11, 0, 'Los Santos Fahrschule', 'Niemand', 1230000, 25000),
(12, 5, 'San Andreas Mechaniker', 'Niemand', 240000, 30000);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `frakblacklist`
--

CREATE TABLE `frakblacklist` (
  `name` varchar(24) NOT NULL,
  `fraktion` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `frakblacklist`
--

INSERT INTO `frakblacklist` (`name`, `fraktion`) VALUES
('sanes322', 11);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `frakcars`
--

CREATE TABLE `frakcars` (
  `id` int(11) NOT NULL,
  `fraktion` int(11) NOT NULL DEFAULT 0,
  `modelid` int(11) NOT NULL DEFAULT 0,
  `X` decimal(10,5) NOT NULL,
  `Y` decimal(10,5) NOT NULL,
  `Z` decimal(10,5) NOT NULL,
  `R` decimal(10,5) NOT NULL,
  `world` int(11) NOT NULL DEFAULT 0,
  `c1` int(11) NOT NULL DEFAULT 0,
  `c2` int(11) NOT NULL DEFAULT 0,
  `tank` int(11) NOT NULL DEFAULT 999,
  `sirene` int(11) NOT NULL DEFAULT 0,
  `ersteller` varchar(30) DEFAULT NULL,
  `nitro` int(11) DEFAULT NULL,
  `hyd` int(11) DEFAULT NULL,
  `wheel` int(11) DEFAULT NULL,
  `ausp` int(11) DEFAULT NULL,
  `sideL` int(11) DEFAULT NULL,
  `sideR` int(11) DEFAULT NULL,
  `fb` int(11) DEFAULT NULL,
  `rb` int(11) DEFAULT NULL,
  `spoiler` int(11) DEFAULT NULL,
  `roof` int(11) DEFAULT NULL,
  `hood` int(11) DEFAULT NULL,
  `vents` int(11) DEFAULT NULL,
  `lamps` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `frakcars`
--

INSERT INTO `frakcars` (`id`, `fraktion`, `modelid`, `X`, `Y`, `Z`, `R`, `world`, `c1`, `c2`, `tank`, `sirene`, `ersteller`, `nitro`, `hyd`, `wheel`, `ausp`, `sideL`, `sideR`, `fb`, `rb`, `spoiler`, `roof`, `hood`, `vents`, `lamps`) VALUES
(607, 15, 560, 790.07700, 377.70700, 20.93700, 302.68100, 0, 245, 245, 60, 0, 'Ali', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(618, 15, 463, 741.73600, 375.89200, 22.71200, 12.08900, 0, 245, 245, 30, 0, 'Ali', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(619, 15, 463, 746.55100, 377.42700, 22.73800, 12.13100, 0, 245, 245, 30, 0, 'Ali', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(624, 15, 478, 778.45600, 352.09200, 19.63800, 8.98600, 0, 245, 245, 60, 0, 'Ali', 1010, 1086, 0, 1020, 0, 0, 0, 0, 0, 0, 0, 0, 1024),
(625, 6, 560, 2460.04500, -1654.03700, 13.07500, 89.16600, 0, 234, 234, 60, 0, 'Ali', 1010, 1087, 1077, 1029, 1027, 1026, 1170, 1140, 1138, 1032, 0, 0, 0),
(627, 6, 567, 2469.47400, -1670.79000, 13.26400, 12.62300, 0, 234, 234, 55, 0, 'Ali', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(629, 6, 560, 2499.13200, -1682.84600, 13.08200, 289.91200, 0, 234, 234, 60, 0, 'Ali', 1010, 1087, 1080, 1028, 1031, 1030, 1169, 1141, 1139, 1033, 0, 0, 0),
(630, 6, 522, 2490.46600, -1686.92900, 13.08300, 22.36400, 0, 234, 234, 20, 0, 'Ali', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(631, 6, 522, 2493.24600, -1686.52700, 13.08000, 20.35300, 0, 234, 234, 0, 0, 'Ali', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(638, 6, 451, 2472.53600, -1654.34300, 13.10900, 88.19700, 0, 234, 234, 60, 0, 'Ali', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(639, 6, 541, 2486.64700, -1654.06400, 13.02400, 89.82600, 0, 234, 234, 60, 0, 'Ali', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(708, 15, 482, 751.96100, 305.45500, 20.35200, 279.50200, 0, 187, 187, 50, 0, 'Nathan.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(709, 15, 482, 752.49500, 302.23500, 20.35200, 280.18200, 0, 187, 187, 50, 0, 'Nathan.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(765, 6, 411, 2506.83200, -1677.43200, 13.19200, 330.73100, 0, 234, 234, 60, 0, 'jordaN.Kennedy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(827, 6, 487, 2532.21100, -1677.81400, 20.09400, 89.81600, 0, 234, 234, 300, 0, 'Nathan.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(828, 6, 487, 2519.79300, -1697.24900, 18.89100, 31.88400, 0, 234, 234, 300, 0, 'Nathan.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(839, 15, 487, 761.08400, 372.60600, 26.93900, 190.85100, 0, 187, 187, 286, 0, 'Nathan.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(842, 15, 522, 739.91100, 379.78000, 22.74000, 282.60300, 0, 187, 187, 21, 0, 'Nathan.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(843, 15, 541, 774.86700, 361.20100, 19.57000, 97.17800, 0, 187, 187, 57, 0, 'Nathan.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(844, 15, 468, 751.61300, 377.52000, 22.87600, 195.57600, 0, 245, 245, 45, 0, 'BitteRein', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(846, 15, 522, 739.19500, 382.83000, 22.74000, 276.29700, 0, 245, 245, 30, 0, 'BitteRein', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(856, 6, 522, 2488.92500, -1686.74500, 13.08200, 24.91900, 0, 234, 234, 30, 0, 'Jason.Kennedy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(974, 4, 582, -16.10700, -2530.72200, 36.71000, 27.39100, 0, 219, 1, 70, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(978, 4, 586, -15.96200, -2508.82400, 36.24300, 267.93400, 0, 219, 1, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(981, 4, 488, -38.84900, -2495.33300, 40.38400, 214.46400, 0, 219, 1, 100, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(982, 6, 560, 2510.83400, -1688.17700, 13.25900, 47.60900, 0, 234, 234, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(984, 6, 411, 2501.19000, -1655.85400, 13.16700, 65.40700, 0, 234, 234, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(985, 6, 415, 2509.40800, -1666.37000, 13.25300, 16.21300, 0, 234, 234, 55, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(986, 6, 412, 2478.92900, -1682.84600, 13.22100, 61.29100, 0, 234, 234, 50, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(987, 6, 482, 2473.31000, -1696.70200, 13.63000, 359.71300, 0, 234, 234, 50, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1074, 15, 482, 752.91500, 298.56300, 20.36100, 278.04500, 0, 245, 245, 50, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1100, 15, 560, 782.12500, 380.69800, 20.89000, 306.68000, 0, 245, 245, 56, 0, 'jeremy', 1010, 1087, 0, 1029, 1031, 1030, 1170, 1140, 1138, 1032, 0, 0, 0),
(1101, 15, 482, 753.72900, 295.55600, 20.35700, 276.70400, 0, 245, 245, 50, 0, 'jeremy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1102, 15, 482, 751.52200, 309.08600, 20.31200, 276.58500, 0, 245, 245, 50, 0, 'jeremy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1103, 15, 463, 743.53200, 376.50100, 22.71100, 14.41700, 0, 245, 245, 30, 0, 'jeremy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1105, 15, 463, 745.04000, 377.02600, 22.71800, 13.21400, 0, 245, 245, 30, 0, 'jeremy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1106, 15, 522, 739.58300, 381.35300, 22.74100, 281.72300, 0, 245, 245, 26, 0, 'jeremy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1108, 15, 560, 786.15600, 379.09500, 20.93300, 304.32100, 0, 245, 245, 60, 0, 'jeremy', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1109, 15, 579, 796.49400, 352.41500, 19.45000, 13.35100, 0, 245, 245, 59, 0, 'jeremy', 1010, 1086, 1085, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1130, 10, 411, 2743.39600, -2457.47300, 13.37500, 272.20200, 0, 13, 13, 19, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1309, 15, 411, 757.05700, 352.79100, 20.15300, 125.42600, 0, 187, 187, 56, 0, 'Maka', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1310, 15, 411, 765.47600, 358.79800, 19.94400, 125.82800, 0, 187, 187, 58, 0, 'Maka', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1311, 15, 541, 782.69100, 362.30000, 19.36900, 97.37000, 0, 187, 187, 58, 0, 'Maka', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1313, 1, 596, 1602.39800, -1684.05200, 5.61200, 91.05300, 0, 201, 1, 60, 0, 'Kiramasu', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1314, 1, 596, 1602.11100, -1688.02100, 5.61200, 89.26200, 0, 201, 1, 60, 0, 'Kiramasu', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1315, 1, 596, 1602.30200, -1692.53300, 5.61200, 88.62300, 0, 201, 1, 60, 0, 'Kiramasu', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1316, 1, 596, 1602.15500, -1696.06700, 5.61200, 89.59200, 0, 201, 1, 60, 0, 'Kiramasu', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1322, 1, 596, 1602.08100, -1699.66600, 5.61100, 87.59300, 0, 201, 1, 60, 0, 'Kiramasu', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1410, 6, 560, 2465.39400, -1664.38000, 13.08800, 74.88200, 0, 234, 234, 60, 0, 'BitteRein', 1010, 1087, 1080, 1028, 1031, 1030, 1169, 1141, 1139, 1033, 0, 0, 0),
(1413, 21, 560, 2792.04100, -1623.40300, 10.62600, 353.36100, 0, 79, 79, 60, 0, 'PatrickJ.', 1010, 1086, 1080, 1029, 1031, 1030, 1170, 1140, 1139, 1032, 0, 0, 0),
(1414, 21, 560, 1368.15400, -1769.27800, 13.24600, 270.51200, 0, 79, 79, 60, 0, 'PatrickJ.', 1010, 1086, 1080, 1029, 1027, 1026, 1170, 1140, 1139, 1032, 0, 0, 0),
(1415, 21, 560, 2768.59500, -1606.24400, 10.58800, 272.08900, 0, 79, 79, 59, 0, 'PatrickJ.', 1010, 1087, 1080, 1029, 1031, 1030, 1170, 1140, 1139, 1032, 0, 0, 0),
(1416, 21, 411, 1666.63700, -1899.96300, 13.27300, 0.81800, 0, 79, 79, 56, 0, 'PatrickJ.', 1010, 0, 1098, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1417, 21, 411, 2770.34700, -1624.44900, 10.65400, 0.65700, 0, 79, 79, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1418, 21, 560, 2768.44400, -1615.07100, 10.62700, 269.45500, 0, 79, 79, 60, 0, 'PatrickJ.', 1010, 1086, 1080, 1029, 1031, 1030, 1170, 1140, 1139, 1032, 0, 0, 0),
(1419, 21, 541, 2774.42100, -1624.22100, 10.51000, 2.36000, 0, 79, 79, 60, 0, 'PatrickJ.', 1010, 1087, 1098, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1420, 21, 522, 2787.55900, -1627.71300, 10.49200, 359.02400, 0, 79, 79, 19, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1421, 21, 522, 2789.01900, -1627.86600, 10.49700, 0.37700, 0, 79, 79, 30, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1424, 21, 451, 1807.71100, -1085.22700, 23.65100, 3.10600, 0, 79, 79, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1426, 21, 487, -1862.65900, -1538.16800, 21.92600, 72.15100, 0, 79, 79, 300, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1427, 21, 487, 2777.43300, -1608.97700, 11.09800, 270.31300, 0, 79, 79, 297, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1428, 21, 409, 2796.29200, -1540.36200, 10.72100, 180.35500, 0, 79, 79, 59, 0, 'PatrickJ.', 1009, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1430, 21, 477, 2807.41900, -1538.66900, 10.63600, 179.95500, 0, 79, 79, 60, 0, 'PatrickJ.', 1010, 1087, 1082, 1018, 1017, 1007, 0, 0, 0, 0, 0, 0, 0),
(1432, 21, 480, 2810.97700, -1537.95200, 10.74100, 184.57100, 0, 79, 79, 55, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1437, 5, 525, 1759.23200, -1099.06900, 23.96600, 182.50900, 0, 1, 222, 75, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1441, 5, 525, 1755.21500, -1099.66300, 23.96500, 181.31300, 0, 1, 222, 39, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1442, 5, 525, 1768.53300, -1098.79300, 23.95400, 181.03100, 0, 1, 222, 75, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1443, 5, 525, 1763.49900, -1098.96200, 23.95300, 180.05900, 0, 1, 222, 75, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1444, 5, 525, 1772.44200, -1098.67500, 23.96200, 182.96000, 0, 1, 222, 75, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1445, 5, 525, 1776.25400, -1098.44800, 23.94900, 180.08200, 0, 1, 222, 74, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1446, 5, 599, 1785.66500, -1097.78400, 24.26900, 179.19800, 0, 1, 222, 69, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1448, 5, 599, 1799.72200, -1119.91000, 24.27900, 2.66500, 0, 1, 222, 75, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1450, 5, 426, 1813.31400, -1100.73700, 24.84500, 179.02500, 0, 158, 8, 45, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1451, 5, 426, 1785.92400, -1125.10100, 23.82900, 179.73700, 0, 158, 8, 29, 0, 'Maka', 1010, 1087, 1078, 1019, 0, 0, 0, 0, 1003, 0, 1004, 0, 0),
(1452, 5, 561, 1771.61400, -1131.74400, 23.89900, 157.83100, 0, 158, 8, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1454, 5, 561, 1775.12900, -1132.04600, 23.89900, 151.35000, 0, 158, 8, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1455, 5, 560, 1792.69300, -1143.95400, 23.70800, 2.42300, 0, 158, 8, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1456, 5, 560, 1785.85800, -1143.85800, 23.72600, 1.03300, 0, 158, 8, 53, 0, 'Maka', 1010, 1087, 0, 1029, 1031, 1030, 1170, 1140, 1139, 1032, 0, 0, 0),
(1457, 5, 560, 1789.31700, -1143.90200, 23.71400, 1.59000, 0, 158, 8, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1458, 5, 487, 1709.11500, -1128.62600, 41.24000, 273.27200, 0, 158, 8, 297, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1459, 15, 499, 2846.63300, 999.68900, 10.74000, 359.14600, 0, 245, 245, 48, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1461, 5, 569, 1786.61300, -1108.26100, 24.07800, 147.73400, 0, 1, 222, 100, 0, 'jeremy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1462, 5, 596, 1748.87400, -1122.08100, 23.80000, 179.04400, 0, 222, 222, 58, 0, 'jeremy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1483, 3, 416, 1182.07900, -1378.64000, 13.85400, 313.13800, 0, 3, 1, 70, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1484, 3, 416, 1153.55300, -1378.31100, 14.20000, 308.79500, 0, 3, 1, 70, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1485, 3, 416, 1166.96900, -1378.68900, 14.03800, 307.75300, 0, 3, 1, 70, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1486, 3, 416, 1078.18500, -1370.50300, 13.97900, 90.37700, 0, 3, 1, 70, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1487, 3, 416, 1078.37300, -1375.56700, 14.35000, 89.06500, 0, 3, 1, 64, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1488, 3, 416, 1078.02700, -1367.03400, 14.29100, 89.89400, 0, 3, 1, 70, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1489, 3, 407, 1079.60900, -1351.82900, 13.94200, 89.51500, 0, 3, 1, 80, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1491, 3, 407, 1079.97400, -1343.44500, 13.88600, 89.68000, 0, 3, 1, 80, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1494, 3, 497, 1124.40700, -1319.91100, 40.33300, 178.63700, 0, 3, 1, 70, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1495, 3, 497, 1109.95600, -1318.79700, 40.27500, 182.15300, 0, 3, 1, 71, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1497, 15, 473, 263.64000, 2930.23200, -0.31000, 334.35700, 0, 245, 245, 50, 0, 'jeremy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1517, 14, 411, -1061.99900, -1235.19100, 128.94500, 305.43900, 0, 50, 50, 60, 0, 'Maka', 1010, 1087, 1085, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1518, 14, 411, -1061.66700, -1243.64700, 128.94500, 306.93800, 0, 74, 74, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1519, 14, 411, -1061.65700, -1239.37300, 128.94500, 308.90900, 0, 18, 18, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1520, 14, 411, -1061.92800, -1248.07800, 128.94500, 306.59700, 0, 188, 188, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1521, 14, 522, -1062.98300, -1224.11300, 128.78700, 301.35000, 0, 49, 49, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1522, 14, 522, -1063.20400, -1220.65700, 128.78700, 301.41300, 0, 31, 31, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1523, 14, 522, -1063.09800, -1222.32600, 128.78900, 299.90700, 0, 43, 43, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1524, 14, 522, -1063.34500, -1218.93300, 128.78700, 299.11500, 0, 117, 117, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1525, 14, 560, -1071.57400, -1251.83300, 128.92300, 0.25400, 0, 47, 47, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1526, 14, 560, -1075.35800, -1251.82000, 128.92300, 0.76000, 0, 132, 132, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1527, 14, 560, -1067.95600, -1251.85300, 128.92400, 359.96500, 0, 20, 20, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1528, 14, 560, -1079.27400, -1251.92100, 128.92300, 0.85100, 0, 24, 24, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1529, 14, 541, -1072.24700, -1222.60600, 128.84300, 182.55200, 0, 59, 59, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1530, 14, 541, -1075.73500, -1222.87200, 128.84300, 181.92600, 0, 132, 132, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1531, 14, 487, -1074.24400, -1265.84200, 129.41100, 269.98900, 0, 83, 83, 300, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1532, 14, 487, -1074.08100, -1281.52300, 129.39500, 269.64500, 0, 140, 140, 300, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1533, 14, 487, -1088.35900, -1281.60200, 129.39800, 270.05400, 0, 168, 168, 300, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1534, 14, 487, -1088.50000, -1265.76500, 129.39500, 270.29300, 0, 86, 86, 300, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1535, 14, 451, -1082.89200, -1223.17000, 128.92500, 181.72600, 0, 133, 133, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1537, 14, 429, -1079.33900, -1223.10500, 128.89800, 183.05900, 0, 39, 39, 55, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1538, 14, 411, 1512.57200, -1470.26300, 9.22700, 273.11000, 0, 6, 6, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1539, 14, 411, 1512.48500, -1467.38500, 9.22700, 272.71500, 0, 56, 56, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1540, 14, 411, 1512.66100, -1464.05400, 9.22700, 274.82500, 0, 33, 33, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1541, 14, 560, 1520.71400, -1478.20200, 9.20500, 2.94000, 0, 147, 147, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1542, 14, 560, 1527.09200, -1478.23800, 9.20400, 358.87600, 0, 9, 9, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1543, 14, 560, 1523.99400, -1478.34800, 9.20500, 1.26400, 0, 33, 33, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1544, 14, 541, 1512.57200, -1460.79800, 9.12400, 272.46300, 0, 136, 136, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1545, 14, 541, 1513.35300, -1473.88600, 9.12500, 272.56800, 0, 10, 10, 60, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1546, 14, 522, 1538.45500, -1474.51500, 9.06700, 60.95600, 0, 117, 117, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1547, 14, 522, 1538.46000, -1472.63800, 9.07000, 64.15000, 0, 126, 126, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1548, 14, 521, 1538.20900, -1477.68000, 9.07000, 58.22000, 0, 44, 44, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1549, 14, 521, 1538.43300, -1475.95200, 9.07100, 59.51200, 0, 109, 109, 30, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1550, 14, 487, 1529.42000, -1456.12300, 64.03600, 88.08500, 0, 88, 88, 300, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1551, 14, 487, 1529.68800, -1465.83200, 64.03500, 87.74900, 0, 35, 35, 300, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1552, 14, 487, 1529.92200, -1472.68700, 64.03600, 85.75000, 0, 114, 114, 300, 0, 'Maka', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1582, 15, 468, 752.80800, 372.94900, 22.93900, 193.41600, 0, 245, 245, 41, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1583, 10, 560, 2744.04400, -2480.90800, 13.35900, 269.97900, 0, 13, 13, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1584, 10, 560, 2744.17900, -2485.51300, 13.35500, 270.77800, 0, 13, 13, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1585, 10, 560, 2743.98000, -2475.85300, 13.35300, 271.17600, 0, 13, 13, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1586, 10, 560, 2743.84000, -2471.26400, 13.35300, 270.02300, 0, 13, 13, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1587, 10, 411, 2743.55200, -2461.81800, 13.37500, 268.32300, 0, 13, 13, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1588, 10, 411, 2743.88100, -2467.01200, 13.37500, 270.16400, 0, 13, 13, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1589, 10, 541, 2743.23600, -2453.18700, 13.27300, 272.93800, 0, 13, 13, 58, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1591, 10, 451, 2743.99700, -2448.92000, 13.35400, 270.73200, 0, 13, 13, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1592, 10, 545, 2744.14300, -2425.23900, 13.43900, 272.14900, 0, 13, 13, 60, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1593, 10, 522, 2769.67600, -2434.82200, 13.21900, 82.45800, 0, 13, 13, 0, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1594, 10, 522, 2769.69700, -2433.17700, 13.21000, 85.34600, 0, 13, 13, 28, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1595, 10, 521, 2768.70100, -2477.77400, 13.21400, 94.86200, 0, 13, 13, 30, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1596, 10, 521, 2768.52700, -2479.21600, 13.21900, 95.43300, 0, 13, 13, 30, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1597, 10, 487, 2780.97400, -2513.19100, 13.84600, 88.14300, 0, 13, 13, 300, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1598, 10, 487, 2780.39500, -2530.30400, 13.79200, 93.34500, 0, 13, 13, 300, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1599, 10, 409, 2765.93600, -2485.54100, 13.35800, 357.14400, 0, 13, 13, 60, 0, 'PatrickJ.', 1009, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1600, 10, 579, 2743.60100, -2435.44900, 13.57900, 272.63800, 0, 13, 13, 65, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1601, 10, 579, 2744.50900, -2440.07000, 13.57500, 271.88400, 0, 13, 13, 65, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1602, 10, 415, 2743.88600, -2444.09300, 13.41500, 273.25100, 0, 13, 13, 55, 0, 'PatrickJ.', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1603, 10, 482, 2743.35300, -2430.57900, 13.76500, 272.91600, 0, 13, 13, 50, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1625, 14, 522, -1063.40800, -1217.17500, 128.78700, 296.97800, 0, 152, 152, 30, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1626, 14, 522, -1063.48300, -1215.39000, 128.78700, 295.36600, 0, 179, 179, 30, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1630, 3, 490, 1133.79100, -1379.27900, 14.19800, 302.93300, 0, 3, 1, 80, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1631, 3, 490, 1142.57600, -1378.73500, 14.22600, 309.74800, 0, 3, 1, 80, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1653, 5, 599, 1791.35000, -1098.04500, 24.26800, 178.95500, 0, 1, 222, 75, 0, 'Ceddo', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1654, 22, 522, 2236.17100, 1683.64700, 1008.35900, 5.68400, 2010, 0, 1, 30, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1657, 3, 407, 1079.58000, -1358.73700, 13.99200, 89.60600, 0, 3, 1, 80, 0, 'Tsubasa', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1658, 3, 407, 1079.90800, -1362.21200, 14.01000, 88.91100, 0, 3, 1, 80, 0, 'Tsubasa', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1659, 1, 430, 950.03000, -2061.26000, -0.32900, 91.34800, 0, 223, 90, 50, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1660, 1, 430, 951.79100, -2072.82600, -0.13800, 92.52900, 0, 223, 90, 50, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1661, 1, 473, 955.54300, -2077.06900, -0.08400, 85.53800, 0, 223, 90, 50, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1662, 1, 473, 954.54600, -2083.00200, -0.33200, 73.64600, 0, 223, 90, 50, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1663, 1, 595, 952.25000, -2090.85900, 0.33600, 83.50000, 0, 223, 90, 50, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1677, 11, 487, 2785.69000, -2011.30500, 13.74300, 178.36800, 0, 93, 93, 300, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1681, 21, 521, 2808.12900, -1560.97200, 10.66000, 289.52100, 0, 79, 79, 30, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1686, 21, 411, 2778.79400, -1624.10500, 10.61800, 359.02700, 0, 79, 79, 54, 0, 'Shirayama', 1010, 1087, 1098, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1687, 21, 579, 2803.30900, -1539.60900, 10.85100, 1.60200, 0, 79, 79, 65, 0, 'Shirayama', 1010, 1087, 1098, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1688, 21, 579, 2816.37900, -1539.94100, 10.85500, 181.57700, 0, 79, 79, 65, 0, 'Shirayama', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1690, 11, 487, 2772.24600, -2011.14600, 13.73100, 184.27800, 0, 93, 93, 292, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1691, 11, 560, 2773.25300, -1929.41100, 13.00900, 358.55700, 0, 93, 93, 34, 0, '[LyD]Shadow', 1010, 1087, 0, 0, 1027, 1026, 1169, 1141, 1139, 1032, 0, 0, 0),
(1692, 11, 560, 2773.13800, -1937.28300, 13.01100, 359.34500, 0, 93, 93, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1693, 11, 522, 2785.77100, -1921.88400, 13.11200, 75.36700, 0, 93, 93, 23, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1694, 11, 522, 2785.57500, -1923.57800, 13.12000, 79.05400, 0, 93, 93, 3, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1695, 11, 522, 2785.52600, -1929.53500, 13.12000, 67.99500, 0, 93, 93, 20, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1696, 11, 522, 2785.88200, -1928.30400, 13.11600, 71.54600, 0, 93, 93, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1697, 11, 409, 2741.60400, -1990.78600, 13.12200, 90.05200, 0, 93, 93, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1698, 11, 545, 2784.86100, -1913.59900, 13.35700, 129.07300, 0, 93, 93, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1699, 11, 579, 2765.67400, -1977.66700, 13.30300, 358.31800, 0, 93, 93, 58, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1700, 11, 579, 2773.30100, -1977.79600, 13.30300, 0.82700, 0, 93, 93, 65, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1701, 11, 541, 2765.77400, -1907.66600, 11.28500, 359.40300, 0, 93, 93, 60, 0, '[LyD]Shadow', 1010, 1087, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1703, 11, 415, 2765.65400, -1931.34000, 13.07200, 358.93400, 0, 93, 93, 55, 0, '[LyD]Shadow', 1010, 1087, 0, 1019, 0, 0, 0, 0, 1023, 0, 0, 0, 0),
(1704, 11, 411, 2790.78400, -1944.64400, 13.27200, 89.80000, 0, 93, 93, 60, 0, '[LyD]Shadow', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1705, 11, 411, 2773.52600, -1907.91300, 11.41100, 0.23900, 0, 93, 93, 59, 0, '[LyD]Shadow', 1010, 1087, 1078, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1708, 11, 487, 2779.90800, -2016.61700, 13.73100, 181.92900, 0, 93, 93, 300, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1710, 20, 487, 933.46800, 1726.20300, 15.95800, 269.63100, 0, 0, 0, 300, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1711, 20, 487, 933.05500, 1744.37600, 15.96900, 272.65000, 0, 0, 0, 300, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1712, 20, 411, 952.64500, 1709.23000, 8.37500, 269.40700, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1713, 20, 411, 952.27600, 1713.43100, 8.37500, 268.55300, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1714, 20, 411, 952.39000, 1717.02800, 8.37500, 269.18600, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1715, 20, 411, 952.20300, 1721.14800, 8.37500, 270.15400, 0, 0, 0, 60, 0, '[LyD]Shadow', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1716, 20, 480, 952.08900, 1725.26100, 8.42200, 269.64300, 0, 0, 0, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1717, 20, 415, 983.36600, 1746.23500, 8.33700, 88.24500, 0, 0, 0, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1718, 20, 560, 951.30600, 1743.37300, 8.35300, 271.21200, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1719, 20, 560, 951.46500, 1746.76200, 8.35300, 269.72200, 0, 0, 0, 58, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1720, 20, 560, 951.23900, 1750.66100, 8.35300, 269.62500, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1724, 20, 579, 951.97000, 1754.46800, 8.57100, 269.36500, 0, 0, 0, 65, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1725, 20, 579, 952.19600, 1758.16800, 8.57900, 270.78600, 0, 0, 0, 65, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1728, 20, 522, 942.52300, 1727.43800, 8.32300, 322.73900, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1729, 20, 522, 943.83900, 1726.77900, 8.42200, 323.86700, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1730, 20, 522, 945.42500, 1726.54400, 8.32300, 328.75500, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1731, 20, 522, 942.25800, 1739.49700, 8.43600, 220.99100, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1732, 20, 522, 944.02300, 1739.60600, 8.32500, 215.98000, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1733, 20, 522, 945.51000, 1739.60300, 8.32300, 218.17400, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1734, 20, 415, 983.36400, 1741.54000, 8.42000, 89.96400, 0, 0, 0, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1735, 20, 409, 983.35200, 1733.27000, 8.45100, 92.85700, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1736, 20, 415, 983.05700, 1737.23600, 8.42300, 91.70600, 0, 0, 0, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1737, 20, 541, 983.04300, 1720.67900, 8.27900, 91.58300, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1738, 20, 541, 982.96400, 1724.52900, 8.27900, 92.38500, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1739, 20, 541, 982.85400, 1728.96700, 8.27800, 91.92300, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1740, 3, 541, 1168.32300, -1349.84500, 13.66400, 176.95400, 0, 3, 3, 54, 0, '[LyD]Shadow', 1010, 0, 1074, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1741, 3, 560, 1115.41000, -1371.99500, 13.61300, 179.14400, 0, 3, 1, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1742, 3, 560, 1110.26400, -1372.06400, 13.66000, 180.55600, 0, 3, 1, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1743, 3, 560, 1105.10600, -1372.06100, 13.63500, 180.90300, 0, 3, 1, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1746, 3, 599, 1100.15600, -1372.56100, 14.14400, 179.27300, 0, 3, 1, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1747, 3, 599, 1095.03200, -1372.48700, 14.07100, 179.59200, 0, 3, 1, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1748, 3, 521, 1146.83200, -1354.79100, 13.58000, 228.30000, 0, 3, 1, 29, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1749, 3, 521, 1144.33100, -1354.87800, 13.57400, 225.96000, 0, 3, 1, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1750, 3, 521, 1141.95000, -1355.08600, 13.56700, 220.27500, 0, 3, 1, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1751, 3, 598, 1163.70300, -1356.87900, 13.58400, 179.04500, 0, 3, 1, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1752, 3, 598, 1159.30200, -1356.85100, 13.64900, 179.08800, 0, 3, 1, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1753, 20, 480, 951.55300, 1739.36500, 8.45600, 272.80500, 0, 0, 0, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1755, 12, 487, 2102.45100, 1665.47100, 11.07000, 268.26400, 0, 168, 168, 300, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1756, 12, 487, 2123.79800, 1665.38700, 11.07000, 269.54600, 0, 168, 168, 300, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1757, 12, 487, 2123.55200, 1701.14500, 11.07000, 269.15800, 0, 168, 168, 300, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1758, 12, 487, 2103.68700, 1701.50100, 11.07000, 269.78500, 0, 168, 168, 300, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1759, 12, 560, 2159.85600, 1711.03900, 10.75300, 152.13500, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1760, 12, 560, 2166.31900, 1707.60900, 10.75200, 151.44400, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1761, 12, 560, 2156.37400, 1712.88400, 10.75200, 152.37300, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1762, 12, 560, 2163.20500, 1709.25500, 10.75100, 151.80200, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1763, 12, 411, 2175.45400, 1666.32600, 10.54700, 90.99000, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1764, 12, 411, 2175.49400, 1663.02500, 10.54700, 91.56000, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1765, 12, 411, 2175.46600, 1669.99900, 10.54700, 89.76600, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1768, 12, 522, 2187.96700, 1666.57400, 10.68100, 86.95600, 0, 168, 168, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1769, 12, 522, 2188.09500, 1667.92200, 10.68200, 89.26400, 0, 168, 168, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1770, 12, 522, 2188.06900, 1669.17800, 10.68200, 88.65600, 0, 168, 168, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1771, 12, 522, 2187.98500, 1665.31600, 10.68100, 90.51800, 0, 168, 168, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1772, 12, 411, 2175.52500, 1673.70900, 10.54700, 89.18900, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1774, 12, 541, 2175.76300, 1687.35200, 10.44500, 90.57400, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1775, 12, 541, 2175.57800, 1677.49300, 10.44500, 88.35500, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1776, 12, 541, 2175.69600, 1683.99300, 10.44500, 89.25300, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1777, 12, 541, 2175.58900, 1680.92500, 10.44500, 88.34800, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1778, 12, 480, 2171.22000, 1654.23400, 10.83000, 69.99800, 0, 168, 168, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1779, 12, 480, 2172.95300, 1657.42000, 10.81900, 69.02700, 0, 168, 168, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1783, 12, 409, 2152.00500, 1677.37400, 10.55100, 353.07400, 0, 168, 168, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1784, 12, 579, 2171.16600, 1703.85300, 10.98000, 150.28300, 0, 168, 168, 65, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1785, 12, 579, 2174.95100, 1700.69100, 10.98300, 149.66900, 0, 168, 168, 65, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1786, 12, 415, 2175.49500, 1694.19400, 10.58700, 90.93200, 0, 168, 168, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1787, 12, 415, 2175.54400, 1690.59800, 10.59200, 90.75300, 0, 168, 168, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1791, 4, 582, -20.64100, -2533.09800, 36.70500, 28.23100, 0, 219, 1, 70, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1792, 4, 586, -17.19500, -2506.39300, 36.24200, 261.22500, 0, 219, 1, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1799, 4, 561, 6.77800, -2519.88200, 36.46200, 27.62700, 0, 219, 1, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1800, 4, 445, -2.49500, -2524.47300, 36.52300, 26.95100, 0, 219, 1, 40, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1801, 11, 541, 2765.84100, -1915.30900, 12.14600, 2.75100, 0, 93, 93, 60, 0, '[LyD]Shadow', 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1802, 11, 411, 2773.43600, -1916.02000, 12.32600, 359.49300, 0, 93, 93, 0, 0, '[LyD]Shadow', 1010, 1087, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1803, 11, 415, 2765.74000, -1924.97000, 13.07400, 1.41800, 0, 93, 93, 55, 0, '[LyD]Shadow', 1010, 1087, 1076, 1018, 1017, 1007, 0, 0, 1023, 0, 0, 0, 0),
(1804, 11, 480, 2773.27400, -1960.54000, 13.07900, 358.75400, 0, 93, 93, 52, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1805, 11, 560, 2773.17800, -1951.47400, 13.01000, 0.36100, 0, 93, 93, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1806, 7, 411, 1998.99200, -1120.94000, 26.43600, 185.52000, 0, 167, 167, 60, 0, 'HappyCookie', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1807, 7, 522, 2001.69700, -1118.86500, 26.35300, 181.19200, 0, 167, 167, 30, 0, 'HappyCookie', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1808, 7, 487, 2005.20800, -1109.34900, 34.33300, 110.90100, 0, 167, 167, 300, 0, 'HappyCookie', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1809, 7, 541, 2003.72000, -1120.92900, 26.38300, 181.52600, 0, 167, 167, 60, 0, 'HappyCookie', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1810, 2, 522, 1898.58800, 720.92400, 10.29500, 265.87000, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1811, 2, 522, 1898.45200, 723.05900, 10.29300, 267.68200, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1812, 2, 522, 1898.23700, 725.14900, 10.29200, 267.17400, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1813, 2, 522, 1898.62000, 727.44200, 10.29100, 266.15800, 0, 0, 0, 30, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1814, 2, 411, 1910.06700, 708.55800, 10.54700, 0.62600, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1815, 2, 411, 1913.21200, 708.54600, 10.54500, 1.98500, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1817, 2, 411, 1916.08700, 708.50500, 10.54400, 359.49400, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1818, 2, 598, 1919.52500, 708.53200, 10.56500, 359.88900, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1820, 2, 598, 1923.03700, 708.46300, 10.56600, 359.09800, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1821, 2, 598, 1926.04400, 708.64600, 10.56400, 358.31000, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1822, 2, 560, 1929.39600, 708.44100, 10.53600, 0.84700, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1823, 2, 560, 1932.51200, 708.06400, 10.43800, 358.84900, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1824, 2, 560, 1935.48500, 708.57800, 10.52400, 359.97200, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1825, 2, 415, 1909.93300, 698.41300, 10.60900, 180.03700, 0, 0, 0, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1826, 2, 415, 1913.09300, 698.45100, 10.62000, 180.62200, 0, 0, 0, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1827, 2, 415, 1916.38500, 697.91000, 10.50500, 180.40500, 0, 0, 0, 55, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1828, 2, 528, 1938.71900, 708.69800, 10.86700, 358.65200, 0, 0, 0, 65, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1830, 2, 601, 1942.14800, 708.51800, 10.65400, 0.27800, 0, 0, 0, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1832, 2, 541, 1919.61500, 698.30400, 10.48500, 179.69900, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1833, 2, 541, 1922.72800, 698.57800, 10.35900, 180.92000, 0, 0, 0, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1834, 2, 490, 1925.88300, 698.24500, 10.94900, 179.71200, 0, 0, 0, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1835, 2, 490, 1929.40600, 697.99000, 10.94900, 179.03300, 0, 0, 0, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1836, 2, 490, 1932.29600, 698.75000, 11.07000, 179.73500, 0, 0, 0, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1837, 2, 490, 1935.45400, 698.05200, 10.93400, 179.09400, 0, 0, 0, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1839, 2, 402, 1938.84000, 698.07200, 10.65100, 178.72100, 0, 0, 0, 50, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1840, 2, 402, 1941.88300, 697.62300, 10.65200, 180.23300, 0, 0, 0, 50, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1841, 2, 447, 1887.81900, 734.02600, 19.27900, 272.42000, 0, 0, 0, 150, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1849, 2, 497, 1887.03100, 753.80500, 19.52200, 270.96300, 0, 0, 0, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1850, 2, 497, 1886.42500, 671.06600, 19.59600, 270.63500, 0, 0, 0, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1851, 2, 497, 1887.30500, 653.49200, 19.59600, 269.43800, 0, 0, 0, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1852, 1, 497, 1567.02700, -1658.61100, 28.64500, 92.27200, 0, 223, 90, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1853, 1, 497, 1565.79500, -1644.56200, 28.65200, 85.17100, 0, 223, 90, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1854, 1, 497, 1565.96200, -1694.20000, 28.64500, 86.29300, 0, 223, 90, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1855, 1, 497, 1563.93700, -1705.89300, 28.64400, 87.03800, 0, 223, 90, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1856, 1, 596, 1529.23000, -1687.92500, 5.61000, 268.14800, 0, 1, 1, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1857, 1, 596, 1529.30900, -1683.75500, 5.61100, 271.27900, 0, 1, 1, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1858, 1, 601, 1526.19500, -1643.90500, 5.72800, 179.39900, 0, 223, 90, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1859, 1, 528, 1530.47300, -1643.97700, 5.87400, 178.19900, 0, 223, 90, 65, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1860, 1, 439, 1534.51600, -1643.67700, 5.82300, 179.50800, 0, 223, 90, 45, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1861, 1, 405, 1538.64100, -1643.89200, 5.76800, 179.10400, 0, 223, 90, 45, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1862, 1, 427, 1544.17800, -1651.06900, 6.02200, 92.34700, 0, 0, 1, 80, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1863, 1, 560, 1545.34900, -1654.77100, 5.60600, 91.73200, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1864, 1, 560, 1545.46800, -1659.05400, 5.59500, 91.34100, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1865, 1, 599, 1545.25200, -1662.98300, 5.89000, 86.65900, 0, 223, 90, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1866, 1, 599, 1546.05900, -1667.70500, 5.89000, 91.21400, 0, 223, 90, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1867, 1, 599, 1546.29100, -1671.75700, 5.89000, 91.90900, 0, 223, 90, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1868, 1, 599, 1545.81100, -1676.11800, 5.89000, 92.36700, 0, 223, 90, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1869, 1, 599, 1545.55500, -1680.24400, 5.89000, 89.57800, 0, 223, 90, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1870, 1, 599, 1545.89900, -1684.15400, 5.89000, 89.89700, 0, 223, 90, 75, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1871, 1, 596, 1558.82400, -1711.28100, 5.61000, 0.24900, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1872, 1, 596, 1564.52500, -1711.07100, 5.61000, 1.14000, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1873, 1, 596, 1570.55700, -1710.97100, 5.89000, 359.02000, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1874, 1, 596, 1574.64100, -1710.81100, 5.89000, 0.00000, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1875, 1, 596, 1578.63500, -1710.93800, 5.89000, 359.42500, 0, 223, 90, 52, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1876, 1, 596, 1583.52300, -1710.94100, 5.61200, 0.11500, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1877, 1, 596, 1587.60500, -1711.19000, 5.63500, 0.80600, 0, 223, 90, 53, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1878, 1, 596, 1591.91200, -1710.92500, 5.63800, 0.92300, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1879, 1, 596, 1595.59900, -1711.05800, 5.89000, 0.08600, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1880, 1, 596, 1601.86500, -1703.97300, 5.89000, 91.61100, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1882, 1, 541, 1585.50200, -1667.37100, 5.51600, 270.64700, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1883, 1, 415, 1585.90400, -1671.54800, 5.66500, 269.83800, 0, 223, 90, 51, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1884, 1, 523, 1557.59900, -1696.61100, 5.46800, 177.96100, 0, 223, 90, 36, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1885, 1, 523, 1559.52800, -1696.36700, 5.47900, 179.66700, 0, 223, 90, 45, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1886, 1, 523, 1561.39600, -1696.46600, 5.46800, 179.78000, 0, 223, 90, 28, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1887, 1, 523, 1563.48200, -1696.49200, 5.46200, 177.54300, 0, 223, 90, 0, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1888, 1, 5234, 1557.60200, -1693.47100, 5.89600, 182.87500, 0, 223, 90, 999, 0, '[LyD]Shadow', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1889, 1, 523, 1557.60200, -1693.47300, 5.37000, 182.87400, 0, 223, 90, 48, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1890, 1, 523, 1559.60900, -1693.43500, 5.46400, 181.92800, 0, 223, 90, 48, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1891, 1, 523, 1561.40200, -1693.30800, 5.46200, 183.88100, 0, 223, 90, 48, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1892, 1, 523, 1563.55400, -1693.22600, 5.46300, 177.01100, 0, 223, 90, 999, 0, '[LyD]Shadow', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1893, 1, 597, 1535.95600, -1667.95500, 13.38200, 359.32900, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1895, 1, 597, 1535.79000, -1677.98100, 13.15100, 0.31800, 0, 223, 90, 60, 0, '[LyD]Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1899, 9, 497, 1116.31600, -2052.93300, 74.67900, 277.64100, 0, 1, 1, 80, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1900, 9, 497, 1116.01200, -2019.75700, 74.67900, 259.96900, 0, 1, 1, 80, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1901, 9, 409, 1263.48200, -2011.50600, 59.12000, 180.39300, 0, 1, 1, 226, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1902, 9, 426, 1245.98600, -2043.71600, 59.57200, 270.49900, 0, 1, 1, 30, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1903, 9, 426, 1245.91700, -2039.97700, 59.57100, 270.76000, 0, 1, 1, 45, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1906, 9, 545, 1277.34800, -2044.81400, 58.84600, 88.18300, 0, 1, 1, 60, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1907, 9, 545, 1277.14300, -2041.68300, 58.83800, 89.79200, 0, 1, 1, 60, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1908, 9, 579, 1277.00000, -2038.46500, 58.94500, 90.33900, 0, 1, 1, 65, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1909, 9, 579, 1276.97500, -2035.33900, 58.93800, 87.90900, 0, 1, 1, 65, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1910, 9, 599, 1245.64900, -2032.68800, 60.02800, 270.33600, 0, 1, 1, 75, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1911, 9, 599, 1245.64200, -2029.57400, 60.02800, 270.43300, 0, 1, 1, 18, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1912, 9, 580, 1259.50100, -2010.47600, 59.23000, 179.18300, 0, 1, 1, 60, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1913, 9, 580, 1267.26900, -2010.18500, 59.00800, 181.42500, 0, 1, 1, 60, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1914, 9, 523, 1250.58600, -2009.01000, 59.26200, 179.71900, 0, 1, 1, 48, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1915, 9, 523, 1248.95500, -2008.84700, 59.30600, 178.61200, 0, 1, 1, 48, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1916, 9, 523, 1247.38300, -2008.88200, 59.33700, 180.35300, 0, 1, 1, 48, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1917, 9, 523, 1245.91600, -2008.93500, 59.38900, 182.15600, 0, 1, 1, 48, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1918, 9, 523, 1244.26000, -2008.44900, 59.39800, 181.60600, 0, 1, 1, 48, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1920, 9, 490, 1246.06700, -2025.11500, 59.95100, 269.81800, 0, 1, 1, 80, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1921, 9, 490, 1246.00100, -2021.11200, 59.95300, 270.39400, 0, 1, 1, 80, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1923, 9, 445, 1277.00500, -2031.53800, 58.86300, 90.44900, 0, 1, 1, 40, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1924, 9, 445, 1277.24800, -2027.93000, 58.82300, 89.28300, 0, 1, 1, 40, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1925, 9, 427, 1275.89600, -2023.71600, 59.11500, 91.22800, 0, 1, 1, 80, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1927, 9, 427, 1275.79900, -2019.75300, 59.20800, 89.79900, 0, 1, 1, 80, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1928, 9, 523, 1127.35500, -2045.37300, 69.00700, 269.84800, 0, 1, 1, 48, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1929, 9, 523, 1127.98400, -2028.79800, 68.48000, 270.83400, 0, 1, 1, 48, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1930, 3, 416, 1077.88500, -1379.48100, 14.14400, 89.55500, 0, 3, 1, 70, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1931, 6, 522, 2491.76400, -1686.83200, 13.08200, 17.46600, 0, 86, 86, 0, 0, 'dape.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1932, 6, 411, 2517.69500, -1672.64500, 13.88900, 62.77400, 0, 86, 86, 59, 0, 'dape.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1933, 6, 522, 2487.58500, -1686.70300, 13.08300, 24.70000, 0, 86, 86, 28, 0, 'dape.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1935, 6, 522, 2491.78500, -1686.69300, 13.08300, 26.06400, 0, 86, 86, 30, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1936, 6, 522, 2487.73600, -1686.98500, 13.08100, 23.29800, 0, 232, 233, 30, 0, 'Shadow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1939, 4, 521, -19.31000, -2503.75300, 36.29400, 254.57400, 0, 219, 1, 9, 0, 'dape.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1940, 4, 550, 2.14200, -2522.28300, 36.46500, 27.74200, 0, 219, 1, 60, 0, 'dape.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1941, 4, 560, -6.83700, -2526.71400, 36.46100, 25.49000, 0, 219, 1, 51, 0, 'dape.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1946, 3, 596, 1077.74700, -1377.37500, 13.59900, 86.96800, 0, 3, 1, 60, 0, 'Kirito.Kirigaya', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(1949, 11, 482, 2765.78100, -1952.79000, 13.41600, 359.50900, 0, 93, 93, 48, 0, 'PatrickJ.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `fraktionen`
--

CREATE TABLE `fraktionen` (
  `fraktionsid` int(11) NOT NULL,
  `EnterX` float NOT NULL DEFAULT 0 COMMENT 'Enter Coords',
  `EnterY` float NOT NULL DEFAULT 0,
  `EnterZ` float NOT NULL DEFAULT 0,
  `EnterInt` int(11) DEFAULT 0,
  `EnterWorld` int(11) DEFAULT NULL,
  `ExitX` float NOT NULL DEFAULT 0 COMMENT 'Exit Coords',
  `ExitY` float NOT NULL DEFAULT 0,
  `ExitZ` float NOT NULL DEFAULT 0,
  `partner` int(11) DEFAULT NULL COMMENT 'Bündnissystem',
  `status` int(11) DEFAULT NULL,
  `fsX` float DEFAULT 0 COMMENT 'fsafebox',
  `fsY` float DEFAULT 0,
  `fsZ` float DEFAULT 0,
  `hasfs` int(11) DEFAULT 0,
  `fsdrogen` int(11) NOT NULL,
  `fswaffenteile` int(11) NOT NULL,
  `fsspice` int(11) DEFAULT NULL,
  `fswantedcodes` int(11) NOT NULL,
  `fskrauter` int(11) NOT NULL,
  `fsgangsamen` int(11) NOT NULL,
  `fssprit` int(11) DEFAULT NULL,
  `waffenlagerX` float NOT NULL DEFAULT 0 COMMENT 'Waffenlager Coords',
  `waffenlagerY` float NOT NULL DEFAULT 0,
  `waffenlagerZ` float NOT NULL DEFAULT 0,
  `waffenlagerteile` int(11) NOT NULL,
  `hasWL` int(11) NOT NULL,
  `score` int(11) NOT NULL COMMENT 'Streetwar Punkte',
  `GIX` float DEFAULT 0 COMMENT 'Gangitem',
  `GIY` float DEFAULT 0,
  `GIZ` float DEFAULT 0,
  `hasGI` int(11) DEFAULT NULL,
  `skinX` float DEFAULT 0 COMMENT 'Skin',
  `skinY` float DEFAULT 0,
  `skinZ` float DEFAULT 0,
  `hasskin` int(11) DEFAULT NULL,
  `waffenX` float DEFAULT 0,
  `waffenY` float DEFAULT 0,
  `waffenZ` float DEFAULT 0,
  `aufzugoX` float DEFAULT 0,
  `aufzugoY` float DEFAULT 0,
  `aufzugoZ` float DEFAULT 0,
  `aufzuguX` float DEFAULT 0,
  `aufzuguY` float DEFAULT 0,
  `aufzuguZ` float DEFAULT 0,
  `hasaufzug` int(11) DEFAULT NULL,
  `fpoints` int(11) NOT NULL DEFAULT 0,
  `fradarUnix` int(11) DEFAULT NULL COMMENT 'Fraktionspunkteshop',
  `maxcars` int(11) DEFAULT NULL COMMENT 'Fraktionspunkteshop',
  `spawnwesteUnix` int(11) DEFAULT NULL COMMENT 'Fraktionspunkteshop'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `fraktionen`
--

INSERT INTO `fraktionen` (`fraktionsid`, `EnterX`, `EnterY`, `EnterZ`, `EnterInt`, `EnterWorld`, `ExitX`, `ExitY`, `ExitZ`, `partner`, `status`, `fsX`, `fsY`, `fsZ`, `hasfs`, `fsdrogen`, `fswaffenteile`, `fsspice`, `fswantedcodes`, `fskrauter`, `fsgangsamen`, `fssprit`, `waffenlagerX`, `waffenlagerY`, `waffenlagerZ`, `waffenlagerteile`, `hasWL`, `score`, `GIX`, `GIY`, `GIZ`, `hasGI`, `skinX`, `skinY`, `skinZ`, `hasskin`, `waffenX`, `waffenY`, `waffenZ`, `aufzugoX`, `aufzugoY`, `aufzugoZ`, `aufzuguX`, `aufzuguY`, `aufzuguZ`, `hasaufzug`, `fpoints`, `fradarUnix`, `maxcars`, `spawnwesteUnix`) VALUES
(1, 1554.61, -1675.51, 16.1951, 0, 2008, 1620, -1377.31, 1962.53, 0, 0, 1639.51, -1383.62, 1962.52, 0, 10, 20, 0, 0, 0, 0, 0, 1644.62, -1384.7, 1962.52, 0, 1, 0, 0, 0, 0, 0, 1641.61, -1381.65, 1962.52, 1, 1638.88, -1381.76, 1962.52, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(2, 1901.93, 742.875, 10.8198, 3, 2009, 264.373, 191.19, 1008.17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 246.281, 185.188, 1008.17, 0, 0, 0, 0, 0, 0, 0, 244.707, 188.143, 1008.17, 1, 244.186, 192.635, 1008.17, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(3, 1153.23, -1346.46, 15.4329, 0, 2004, 1458.02, -980.906, 675.603, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1466.36, -986.635, 675.613, 1, 1466.54, -983.297, 675.613, 1117.96, -1320.17, 40.1305, 1459.93, -1000.8, 675.603, 0, 0, NULL, NULL, NULL),
(4, -30.6529, -2502.19, 36.6483, 0, 0, -41.687, -2501.53, 36.7248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -43.2597, -2498.92, 36.7248, 1, -42.3162, -2500.06, 36.7248, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(5, 1706.74, -1136.59, 24.0858, 0, 2007, 1932.66, -2002.14, 823.413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1946.88, -2032.34, 823.413, 1, 1950.26, -2032.42, 823.413, 1709.77, -1116.75, 41.062, 1720, -1124.9, 24.0858, 0, 0, NULL, NULL, NULL),
(6, 2495.27, -1690.96, 14.7656, 3, 2012, 2495.91, -1692.79, 1014.74, 0, 0, 2498.5, -1710.86, 1014.74, 1, 0, 0, 0, 0, 0, 0, 0, 2491.1, -1699.94, 1014.74, 21700, 1, 0, 2491.65, -1701.32, 1018.34, 1, 0, 0, 0, 0, 2496.07, -1709.43, 1014.77, 0, 0, 0, 0, 0, 0, 0, 3, NULL, NULL, NULL),
(7, 1999.99, -1114.05, 27.125, 2, 0, 2468.71, -1698.37, 1013.51, 0, 0, 2455.21, -1703.73, 1013.51, 1, 800, 25000, 0, 0, 0, 0, 0, 2455.55, -1700.67, 1013.52, 25000, 1, 0, 2451.3, -1686.28, 1013.51, 1, 0, 0, 0, 0, 2449.25, -1701.96, 1013.51, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 864.19, -2687.9, -12.4919, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(9, 1123.29, -2036.99, 69.8871, 3, 2013, 367.618, 162.296, 1025.79, 0, 0, 353.691, 173.255, 1025.8, 0, 0, 0, 0, 0, 0, 0, 0, 355.819, 172.959, 1025.79, 0, 0, 0, 0, 0, 0, 0, 355.003, 172.811, 1025.79, 1, 354.879, 172.804, 1025.8, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(10, 2774.11, -2456.17, 13.637, 1, 2010, 2234, 1713.44, 1012.14, 0, 0, 2225.91, 1697.51, 1008.36, 1, 1700, 125000, 500, 0, 0, 0, 0, 2246.1, 1698.02, 1008.36, 116850, 1, 0, 2246.07, 1695.99, 1008.36, 1, 0, 0, 0, 0, 2235.79, 1676.21, 1008.36, 2727.85, -2366.11, 28.9279, 2755.54, -2382.32, 13.6328, 1, 0, NULL, NULL, NULL),
(11, 2786.8, -1925.88, 13.5466, 11, 0, 501.834, -68.1751, 998.758, 0, 0, 505.688, -79.8792, 998.961, 1, 2400, 100000, 400, 0, 0, 5, 0, 506.054, -81.1203, 998.961, 22556, 1, 0, 511.224, -78.4272, 998.961, 1, 0, 0, 0, 0, 508.337, -84.9195, 998.961, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(12, 2196.33, 1676.8, 12.3669, 1, 2011, -794.904, 490.195, 1376.2, 0, 0, -789.353, 497.109, 1371.74, 1, 500, 25000, 500, 0, 0, 0, 0, -779.525, 496.663, 1371.75, 25000, 1, 0, -784.746, 496.882, 1371.74, 1, 0, 0, 0, 0, -780.262, 506.055, 1371.74, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(13, 2526.82, -1033.97, 69.5792, 8, 0, 2807.61, -1174.76, 1025.57, -1, 0, 2811.67, -1165.94, 1025.57, 1, 500, 25000, 0, 0, 0, 0, 0, 2809.74, -1171.9, 1025.57, 25000, 1, 0, 2805.81, -1170.67, 1025.57, 1, 0, 0, 0, 0, 2807.21, -1165.5, 1025.57, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(14, -1067.14, -1201.63, 129.638, 4, 0, 302.141, 300.76, 999.148, 0, 0, 305.183, 304.517, 1003.81, 1, 200, 0, 200, 0, 0, 0, 0, 309.975, 309.38, 1003.3, 25000, 1, 0, 300.48, 310.699, 1003.3, 1, 0, 0, 0, 0, 300.668, 305.859, 1003.54, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(15, 758.318, 374.918, 23.1961, 0, 2021, 743.7, 383.832, 948.536, 0, 0, 769.262, 379.894, 945.084, 1, 1900, 89559, 6820, 0, 0, 0, 3200, 744.872, 377.591, 948.536, 14240, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 748.494, 379.341, 948.536, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(16, 2290.16, 2431.78, 10.8203, 0, 0, 2278.39, 2425.22, 3.4765, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2283.95, 2423.48, 3.4765, 1, 2279.95, 2423.48, 3.4765, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 938.915, 1729.03, 8.8514, 0, 0, 0, 0, 0, 0, 0, 0, 938.826, 1737.87, 8.8514, 25000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 938.724, 1733.36, 8.8514, 0, 0, 0, -1213.49, -1207.94, 1001.5, 0, 0, NULL, NULL, NULL),
(18, -1366.48, 500.71, 11.1953, 7, 0, 315.816, -143.509, 999.602, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 307.406, -131.539, 999.608, 1, 309.071, -136.388, 999.602, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2800, 976.088, 2058.29, 10.8203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL),
(20, 938.129, 1733.27, 8.8514, 2, 2022, 2548.8, -1294.72, 1060.98, -1, 0, 2552.07, -1295.38, 1060.98, 1, 500, 25000, 500, 0, 0, 0, 0, 2547.3, -1285.8, 1060.98, 25000, 1, 0, -2158.99, 640.358, 1052.38, 1, 0, 0, 0, 0, 2548.97, -1281.78, 1060.98, 0, 0, 0, 0, 0, 0, 0, 3, NULL, NULL, NULL),
(21, 2770.8, -1628.64, 12.1674, 3, 2018, 967.701, -53.2369, 1001.12, -1, 0, 962.009, -47.5984, 1001.12, 1, 1500, 115159, 0, 0, 0, 0, 0, 958.627, -47.541, 1001.12, 95237, 1, 0, 943.016, -51.0278, 1001.12, 1, 0, 0, 0, 0, 960.468, -47.5777, 1001.12, -2702.76, -300.575, 7.1708, -2906, -362.767, 3.2204, 0, 0, NULL, NULL, NULL),
(22, 627.595, -571.859, 17.6345, 5, 0, 322.222, 302.76, 999.15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 327.296, 303.564, 999.148, 1, 326.793, 307.737, 999.148, 616.918, -581.7, 26.1431, 610.456, -583.677, 18.134, 1, 0, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `friendlist`
--

CREATE TABLE `friendlist` (
  `id` int(11) NOT NULL,
  `Spieler` varchar(24) NOT NULL,
  `SpielerEx` varchar(24) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `friendlist`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `gangfight`
--

CREATE TABLE `gangfight` (
  `id` int(11) NOT NULL,
  `x_min` float NOT NULL,
  `x_max` float NOT NULL,
  `y_min` float NOT NULL,
  `y_max` float NOT NULL,
  `icon_x` float NOT NULL,
  `icon_y` float NOT NULL,
  `icon_z` float NOT NULL,
  `owner` int(11) NOT NULL,
  `timeout` int(11) NOT NULL,
  `gbestand` int(11) NOT NULL,
  `gupgrade` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `gangfight`
--

INSERT INTO `gangfight` (`id`, `x_min`, `x_max`, `y_min`, `y_max`, `icon_x`, `icon_y`, `icon_z`, `owner`, `timeout`, `gbestand`, `gupgrade`) VALUES
(1, 908.203, 1207.03, -398.438, -216.797, 1059.66, -345.595, 73.5604, 11, 1701458817, 0, 3),
(2, 1059.48, 1171.61, 2144.63, 2341.12, 1104.53, 2251.01, 16.7188, 10, 1596148933, 0, 3),
(3, -1282.56, -1344.96, 2564.59, 2486.56, -1304.4, 2526.19, 87.5393, 11, 0, 0, 3),
(4, -2199.47, -2099.08, -279.434, -195.512, -2182.86, -216.02, 36.5156, 10, 1699044292, 0, 3),
(5, 2355.47, 2537.11, -2718.75, -2501.95, 2468.91, -2626.26, 13.2115, 10, 1700084815, 0, 3),
(6, 2077.91, 2338.58, 980.683, 1184.11, 2183.85, 1114.92, 12.2193, 11, 1699570004, 0, 3),
(7, 2220.08, 2383.81, -109.951, 200.931, 2320.35, 27.9191, 26.4844, 11, 1701559558, 0, 3),
(8, 2453.65, 2505.71, -1438.65, -1261.32, 2493.13, -1405.63, 28.8389, 10, 1700319595, 0, 3),
(9, 1826.99, 1956.64, -1927.21, -1830.14, 1891.77, -1884.61, 13.4916, 11, 1701554912, 0, 3),
(10, -2802.52, -2713.61, -205.96, -76.6989, -2747.72, -196.731, 6.0189, 11, 1590100251, 0, 3),
(11, -913.673, -719.873, 1434.1, 1635.39, -816.255, 1515.27, 20.4507, 11, 1699734078, 0, 3),
(12, 1724.63, 1818.48, -1430.95, -1314.79, 1788.52, -1384.42, 15.7578, 10, 1700594296, 0, 3),
(13, 1565.94, 1808.68, -2373.36, -2199.94, 1664.18, -2286.45, -1.2338, 10, 1702157126, 0, 3),
(14, 2556.18, 2718.85, 782.266, 915.703, 2619.17, 833.396, 5.3158, 21, 1701032919, 0, 3),
(15, 1394.5, 1559.51, 1979.17, 2045.63, 1444.52, 2010.85, 10.8203, 11, 1700174019, 0, 3),
(16, -619.466, -365.79, -213.092, 28.0434, -526.95, -94.4384, 62.5453, 10, 1594940504, 0, 3),
(17, 1146.68, 1431.36, 119.132, 435.267, 1339.64, 329.107, 20.0262, 21, 1701119863, 0, 3),
(18, -2271.31, -2019.32, -2548.49, -2212.16, -2164, -2461.61, 30.625, 10, 1701124816, 0, 3),
(19, -1476.72, -1241.8, 477.719, 533.227, -1340.8, 509.575, 11.1953, 21, 1701126619, 0, 3),
(20, -1132.95, -950.14, -1707.07, -1579.51, -1100.54, -1620.7, 76.3672, 21, 1700753302, 0, 3),
(21, -2745.59, -2611.92, 713.84, 806.09, -2683.6, 776.648, 46.9598, 10, 1700580011, 0, 3),
(22, -322.533, -181.831, 2642.53, 2756.53, -273.315, 2674.9, 62.6324, 10, 1596314379, 0, 3),
(23, 1777.85, 1902.66, 2548.26, 2674.29, 1850.73, 2607.51, 10.8203, 10, 1596313259, 0, 3),
(24, 111.062, 287.856, 1335.23, 1485.47, 221.434, 1400.22, 10.5859, 11, 1700349790, 0, 3),
(25, 802.685, 957.652, -1134.91, -1070.33, 881.842, -1101.66, 24.2969, 10, 1700964912, 0, 3),
(26, -973.572, -899.796, -550.38, -482.91, -913.787, -523.038, 25.9536, 11, 1701274264, 0, 3),
(27, -126.443, -32.9237, -1604.16, -1521.5, -70.8169, -1574, 2.6172, 10, 1701288949, 0, 3),
(28, 1833.13, 1913.01, -2141.04, -2062.63, 1878.57, -2102.34, 13.5522, 10, 1702155313, 0, 3);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `gutschein`
--

CREATE TABLE `gutschein` (
  `id` int(11) NOT NULL,
  `code` varchar(32) NOT NULL DEFAULT '0',
  `gutschein` int(11) NOT NULL DEFAULT 0,
  `expired` tinyint(4) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `gutschein`
--

INSERT INTO `gutschein` (`id`, `code`, `gutschein`, `expired`) VALUES
(1, 'hollalala', 3, 1),
(2, 'YashikiHat26Zu16Kassiert', 1, 1),
(3, 'LyDFree', 2, 1);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `hausmoebel`
--

CREATE TABLE `hausmoebel` (
  `id` int(11) NOT NULL,
  `houseid` int(11) NOT NULL,
  `moebelid` int(11) NOT NULL,
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `rx` float NOT NULL,
  `ry` float NOT NULL,
  `rz` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `hausmoebel`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `hotel`
--

CREATE TABLE `hotel` (
  `ID` int(11) NOT NULL,
  `EnterX` float NOT NULL,
  `EnterY` float NOT NULL,
  `EnterZ` float NOT NULL,
  `ExitX` float NOT NULL,
  `ExitY` float NOT NULL,
  `ExitZ` float NOT NULL,
  `Besitzer` varchar(24) NOT NULL,
  `Name` varchar(32) NOT NULL,
  `Lock` int(11) NOT NULL,
  `MietPreis` int(11) NOT NULL,
  `EnterInterior` int(11) NOT NULL,
  `ExitInterior` int(11) NOT NULL,
  `EnterVirtualWorld` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `hotel`
--

INSERT INTO `hotel` (`ID`, `EnterX`, `EnterY`, `EnterZ`, `ExitX`, `ExitY`, `ExitZ`, `Besitzer`, `Name`, `Lock`, `MietPreis`, `EnterInterior`, `ExitInterior`, `EnterVirtualWorld`) VALUES
(57, 1734.93, -1642.18, 27.2, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 13', 1, 1000, 18, 2, 76),
(56, 1734.89, -1648.3, 27.2, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 12', 1, 1000, 18, 2, 76),
(55, 1734.81, -1654.05, 27.2, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 11', 1, 1000, 18, 2, 76),
(54, 1735.04, -1659.68, 27.2, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 10', 1, 1000, 18, 2, 76),
(53, 1708.76, -1670.18, 23.7, 225.75, 1240, 1082.14, 'die.nasE', 'Hotelzimmer 9', 1, 1000, 18, 2, 76),
(52, 1708.68, -1665.02, 23.7, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 8', 1, 1000, 18, 2, 76),
(51, 1708.68, -1660.14, 23.7, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 7', 1, 1000, 18, 2, 76),
(50, 1708.81, -1654.51, 23.7, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 6', 1, 1000, 18, 2, 76),
(49, 1708.8, -1649.52, 23.69, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 5', 1, 1000, 18, 2, 76),
(48, 1734.68, -1642.43, 23.75, 225.75, 1240, 1082.14, 'Slim_Shady', 'Hotelzimmer 4', 0, 1000, 18, 2, 76),
(47, 1734.68, -1648.31, 23.7, 225.75, 1240, 1082.14, 'SlashQ', 'Hotelzimmer 3', 0, 1000, 18, 2, 76),
(46, 1734.81, -1654.25, 23.7, 225.75, 1240, 1082.14, 'Niemand', 'Hotelzimmer 2', 1, 1000, 18, 2, 76),
(45, 1734.89, -1660.16, 23.7, 225.75, 1240, 1082.14, 'Madara.', 'Hotelzimmer 1', 1, 1000, 18, 2, 76),
(58, 1734.9, -1660.18, 23.7, 235.5, 1189.16, 1080.31, 'Niemand', 'Doppelzimmer', 1, 1000, 18, 3, 59),
(59, 1734.89, -1654.25, 23.7, 235.5, 1189.16, 1080.31, 'Niemand', 'Doppelzimmer', 1, 1000, 18, 3, 59),
(60, 1735.05, -1648.31, 23.7, 235.5, 1189.16, 1080.31, 'Niemand', 'Doppelzimmer', 1, 1000, 18, 3, 59),
(61, 1734.63, -1642.38, 23.75, 235.5, 1189.16, 1080.31, 'MRX', 'Doppelzimmer', 1, 1000, 18, 3, 59);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `houseinterior`
--

CREATE TABLE `houseinterior` (
  `ID` int(11) NOT NULL,
  `ExitX` float NOT NULL,
  `ExitY` float NOT NULL,
  `ExitZ` float NOT NULL,
  `Interior` int(11) NOT NULL,
  `PickupX` float NOT NULL,
  `PickupY` float NOT NULL,
  `PickupZ` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `houseinterior`
--

INSERT INTO `houseinterior` (`ID`, `ExitX`, `ExitY`, `ExitZ`, `Interior`, `PickupX`, `PickupY`, `PickupZ`) VALUES
(1, 235.509, 1189.17, 1080.34, 15, 221.92, 1189.77, 1080.25),
(2, 225.757, 1240, 1082.15, 2, 224.13, 1246.06, 1082.14),
(3, 223.044, 1289.26, 1082.2, 1, 224.8, 1292.86, 1082.14),
(4, 225.631, 1022.48, 1084.07, 7, 224.89, 1035.94, 1084.01),
(5, 295.139, 1474.47, 1080.52, 15, 294.56, 1488.85, 1080.25),
(6, 328.494, 1480.59, 1084.45, 15, 322.11, 1487.77, 1084.44),
(7, 385.804, 1471.77, 1080.21, 15, 379.64, 1463.26, 1080.18),
(8, 244.412, 305.033, 999.148, 1, 248.57, 302.18, 999.14),
(9, 266.832, 304.848, 999.148, 3, 272.01, 307.18, 999.14),
(10, 2468.03, -1698.25, 1013.51, 2, 2453.73, -1705.49, 1013.5),
(11, 2324.42, -1145.57, 1050.71, 12, 2319.11, -1140.3, 1050.49),
(12, 1261.29, -785.702, 1091.91, 5, 1264.48, -775.96, 1091.9),
(13, 421.785, 2536.4, 10, 10, 419.93, 2541.89, 10),
(14, 235.429, 1187.1, 1080.26, 3, 243.2, 1193.44, 1080.25),
(15, 226.732, 1114.29, 1081, 5, 247.03, 1116.03, 1080.99),
(16, 446.998, 1397.46, 1084.3, 3, 448.68, 1405.49, 1084.3),
(17, 23.8505, 1340.44, 1084.38, 10, 30.03, 1351.41, 1084.37),
(18, 140.3, 1366.27, 1083.86, 5, 150.19, 1369.74, 1083.85),
(19, 234.001, 1064.09, 1084.21, 6, 232.65, 1076.64, 1084.24),
(20, 2365.52, -1135.03, 1050.88, 8, 2375.23, -1127.37, 1050.87);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `houses`
--

CREATE TABLE `houses` (
  `ID` int(11) NOT NULL,
  `EnterX` float NOT NULL,
  `EnterY` float NOT NULL,
  `EnterZ` float NOT NULL,
  `Besitzer` varchar(256) DEFAULT NULL,
  `Name` varchar(32) NOT NULL,
  `Preis` int(11) NOT NULL,
  `Mieten` int(11) NOT NULL,
  `Lock` int(11) NOT NULL,
  `MietPreis` int(11) NOT NULL,
  `Kasse` int(11) NOT NULL,
  `SellX` float NOT NULL,
  `SellY` float NOT NULL,
  `SellZ` float NOT NULL,
  `SellRot` float NOT NULL,
  `HouseInteriorID` int(11) NOT NULL,
  `MieterMax` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `houses`
--

INSERT INTO `houses` (`ID`, `EnterX`, `EnterY`, `EnterZ`, `Besitzer`, `Name`, `Preis`, `Mieten`, `Lock`, `MietPreis`, `Kasse`, `SellX`, `SellY`, `SellZ`, `SellRot`, `HouseInteriorID`, `MieterMax`) VALUES
(1, 992.65, -1817.55, 13.89, 'Niemand', 'Strandhaus', 4000000, 0, 0, 250, 1250, 991.4, -1817.3, 13.8, 4.4, 20, 10),
(2, 980.9, -1814.56, 13.89, 'Niemand', 'Strandhaus', 4000000, 0, 0, 100, 0, 978.9, -1814, 13.8, 350.7, 20, 10),
(3, 969.78, -1812, 13.89, 'Niemand', 'Strandhaus', 4000000, 0, 0, 100, 0, 968, -1811, 13.8, 337.5, 15, 10),
(4, 958.26, -1809.06, 13.89, 'Niemand', 'Strandwohnung', 4000000, 0, 0, 50, 0, 956.5, -1808, 13.8, 336.2, 15, 10),
(5, 933.75, -1805.18, 13.84, 'Niemand', 'Strandwohnung', 4000000, 0, 0, 150, 0, 932.2, -1804.8, 13.8, 345.6, 15, 10),
(6, 922.01, -1803.88, 13.81, 'Niemand', 'Strandwohnung', 4000000, 0, 0, 50, 0, 920.2, -1803, 13.8, 343.5, 20, 10),
(7, 910.28, -1802.68, 13.8, 'Niemand', 'Strandwohnung', 4000000, 0, 0, 100, 0, 908.7, -1802.3, 13.6, 356, 20, 10),
(8, 914.53, -1817.06, 13.3, 'Niemand', 'Strandwohnung', 4800000, 0, 0, 100, 0, 915.9, -1817.5, 13.3, 172.6, 20, 10),
(9, 926.09, -1818.03, 13.31, 'Niemand', 'Strandwohnung', 4800000, 0, 0, 50, 0, 927.2, -1818.5, 13.3, 168.6, 20, 10),
(11, 972.45, -1826.93, 13.31, 'Niemand', 'Strandhaus', 4800000, 0, 0, 500, 0, 973.2, -1827.3, 13.3, 155.1, 15, 10),
(12, 983.65, -1829.93, 13.31, 'Niemand', 'Strandhaus', 4800000, 0, 0, 50, 0, 984.7, -1829.9, 13.3, 169, 19, 10),
(13, 315.85, -1769.9, 4.63, 'Niemand', 'Großes Strandhaus', 30000000, 0, 0, 420, 0, 314.7, -1769.5, 4.5, 194.1, 19, 10),
(15, 168.3, -1769, 4.46, 'Niemand', 'Strandhaus', 7500000, 0, 1, 50, 0, 167.1, -1769.5, 4.4, 181, 20, 10),
(16, 281.01, -1767.56, 4.53, 'Niemand', 'Strandhaus', 9000000, 0, 0, 50, 0, 280.1, -1767.4, 4.5, 206.3, 20, 10),
(17, 295.32, -1764.88, 4.53, 'Niemand', 'Strandhaus', 7500000, 0, 0, 50, 0, 294, -1765, 4.5, 199.8, 20, 10),
(18, 305.29, -1770.42, 4.53, 'Niemand', 'Strandwohnung', 7500000, 0, 0, 350, 0, 304.2, -1770.5, 4.5, 192.8, 20, 10),
(19, 653.59, -1714.06, 14.76, 'Niemand', 'Moderne Wohnung', 1800000, 0, 0, 100, 0, 0, 0, 0, 0, 15, 10),
(20, 657.21, -1652.68, 15.39, 'Niemand', 'Moderne Wohnung', 1800000, 0, 1, 50, 0, 0, 0, 0, 0, 15, 10),
(21, 655.9, -1636.18, 15.85, 'Niemand', 'Normale Wohnung', 1300000, 0, 1, 50, 0, 0, 0, 0, 0, 5, 10),
(23, 692.84, -1602.77, 15.02, 'Niemand', 'Normale Wohnung', 1900000, 0, 0, 50, 0, 0, 0, 0, 0, 7, 10),
(24, 697.28, -1626.93, 3.74, 'Niemand', 'Normale Wohnung', 3000000, 0, 0, 50, 0, 697.5, -1625.3, 3.7, 245.1, 7, 10),
(25, 693.75, -1646.01, 4.09, 'Niemand', 'Normale Wohnung', 2500000, 0, 0, 50, 0, 694, -1646.5, 4, 307.7, 7, 10),
(26, 694.84, -1690.68, 4.34, 'Niemand', 'Normale Wohnung', 2000000, 0, 0, 50, 0, 694.4, -1689.5, 4.3, 276.2, 17, 10),
(27, 693.53, -1705.78, 3.75, 'Niemand', 'Normale Wohnung', 2500000, 0, 0, 100, 0, 693.7, -1704.5, 3.7, 232, 7, 10),
(30, 766.9, -1605.78, 13.8, 'Niemand', 'Normale Wohnung', 2000000, 0, 0, 300, 0, 766.5, -1606.9, 13.6, 45, 7, 10),
(31, 761.7, -1564.06, 13.6, 'Niemand', '2 stöckiges Haus', 2000000, 1, 1, 50, 0, 762.2, -1562.5, 13.5, 273.6, 15, 10),
(32, 771.96, -1510.92, 13.52, 'Niemand', '2 stöckiges Haus', 2000000, 0, 0, 50, 0, 772.2, -1509.8, 13.5, 254.1, 17, 10),
(33, 822.46, -1504.81, 14.26, 'Niemand', '2 stöckiges Haus', 5000000, 0, 0, 50, 0, 821.5, -1504.8, 14.1, 2.5, 17, 10),
(36, 900.96, -1471.43, 14.13, 'Niemand', '2 stöckiges Haus', 8000000, 0, 1, 500, 0, 900.9, -1472.4, 14.1, 232.3, 17, 10),
(37, 904.28, -1513.18, 14.06, 'Niemand', '2 stöckiges Haus', 8000000, 0, 0, 250, 0, 904.2, -1514, 14.1, 248, 4, 10),
(38, 900.9, -1446.79, 14.18, 'Niemand', '2 stöckiges Haus', 8000000, 0, 1, 150, 0, 901, -1447.5, 14, 299.5, 19, 10),
(39, 880.26, -1423.56, 14.47, 'Niemand', '2 stöckiges Haus', 1500000, 0, 0, 100, 0, 0, 0, 0, 0, 19, 10),
(40, 852.34, -1422.43, 13.89, 'Niemand', 'Haus', 2000000, 0, 0, 500, 0, 851.2, -1422, 13.6, 348.6, 17, 10),
(41, 824.64, -1423.43, 14.47, 'Niemand', 'Haus', 1500000, 0, 0, 500, 0, 823.2, -1423.5, 14.3, 3.5, 17, 10),
(42, 785.03, -1435.78, 13.52, 'Niemand', 'Haus', 1900000, 0, 0, 150, 0, 785, -1434.3, 13.5, 282.1, 17, 10),
(44, 813.4, -1456.68, 14.1, 'Niemand', 'Haus', 6000000, 0, 0, 50, 0, 813.2, -1457.8, 14, 89, 4, 10),
(45, 739.15, -1418.01, 13.52, 'Niemand', 'Haus', 4000000, 0, 0, 500, 0, 738, -1417.8, 13.5, 341.6, 17, 10),
(46, 725.71, -1440.02, 13.52, 'Niemand', 'Luxushaus', 6000000, 0, 0, 500, 0, 726.7, -1440, 13.5, 346.2, 4, 10),
(47, 739.15, -1429.31, 13.52, 'Niemand', 'Familienhaus', 4000000, 0, 0, 50, 0, 740.2, -1429.5, 13.5, 176.5, 19, 10),
(48, 952.65, -910.07, 45.75, 'Niemand', 'Großes Haus', 25000000, 1, 0, 750, 0, 953.9, -909.5, 45.7, 169, 11, 10),
(49, 1246.68, -909.25, 46.59, 'Niemand', 'Kleine Wohnung', 1600000, 0, 1, 100, 0, 1246.5, -908.2, 46.5, 265.2, 3, 10),
(50, 1253.06, -908.13, 46.59, 'Niemand', 'Kleine Wohnung', 780000, 0, 0, 300, 0, 1252.8, -907.5, 46.5, 111.5, 15, 10),
(51, 1246.06, -902.9, 46.59, 'Niemand', 'Kleine Wohnung', 1600000, 0, 0, 100, 0, 0, 0, 0, 0, 3, 10),
(52, 1252.54, -901.89, 46.59, 'Niemand', 'Kleine Wohnung', 1600000, 0, 0, 100, 0, 0, 0, 0, 0, 3, 10),
(53, 1246.06, -902.71, 42.88, 'Niemand', 'Kleine Wohnung', 1600000, 1, 0, 480, 0, 1246.4, -903, 42.7, 295.2, 3, 10),
(54, 1252.43, -901.84, 42.88, 'Niemand', 'Kleine Wohnung', 1600000, 0, 0, 50, 0, 1252.3, -902.5, 42.7, 67, 3, 10),
(55, 1242.56, -878.34, 46.63, 'Niemand', 'Kleine Wohnung', 1600000, 1, 0, 50, 0, 1242.5, -877.5, 46.5, 265.2, 3, 10),
(56, 1249.18, -877.34, 46.63, 'Niemand', 'Moderne Wohnung', 1600000, 0, 0, 100, 0, 1248.8, -876.7, 46.5, 127, 3, 10),
(57, 1241.68, -871.83, 46.63, 'Niemand', 'Moderne Wohnung', 1600000, 0, 0, 50, 0, 1241.9, -872.5, 46.5, 303.5, 3, 10),
(58, 1290.68, -896.96, 42.88, 'Niemand', 'Moderne Wohnung', 1600000, 0, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(59, 1283.68, -897.83, 42.86, 'Niemand', 'Moderne Wohnung', 1600000, 0, 1, 250, 0, 0, 0, 0, 0, 3, 10),
(60, 1290.41, -896.82, 46.61, 'Niemand', 'Moderne Wohnung', 1600000, 0, 0, 500, 0, 1290.3, -897.5, 46.5, 31.2, 3, 10),
(61, 1284.18, -897.77, 46.61, 'Niemand', 'Moderne Wohnung', 1600000, 0, 0, 50, 0, 1284.4, -898.2, 46.5, 337.7, 3, 10),
(62, 1291.43, -903, 46.63, 'Niemand', 'Kleine Wohnung', 750000, 0, 0, 300, 0, 1290.8, -902.5, 46.5, 144.1, 3, 10),
(63, 1284.78, -903.96, 46.63, 'Niemand', 'Moderne Wohnung', 1600000, 0, 0, 50, 0, 1285, -903.2, 46.5, 244.5, 3, 10),
(64, 1281.18, -874.82, 46.84, 'Niemand', 'Kleine Wohnung', 740000, 0, 1, 50, 0, 1281.3, -874, 46.7, 273.1, 3, 10),
(65, 1287.88, -873.96, 46.84, 'Niemand', 'Kleine Wohnung', 740000, 0, 0, 600, 0, 0, 0, 0, 0, 3, 10),
(66, 1280.31, -868.71, 46.83, 'Niemand', 'Kleine Wohnung', 1600000, 1, 0, 50, 0, 1280.8, -869.2, 46.7, 290.6, 3, 10),
(67, 1287.81, -874.09, 43.06, 'Niemand', 'Kleine Wohnung', 1600000, 0, 0, 100, 0, 1287.5, -873.2, 43, 136.1, 3, 10),
(68, 1410.31, -920.75, 38.4, 'Niemand', 'Moderne Wohnung', 9000000, 0, 0, 500, 0, 1411.5, -920.9, 38.4, 164.6, 15, 10),
(69, 1439.31, -925.94, 39.63, 'Niemand', 'Moderne Wohnung', 9000000, 0, 0, 250, 0, 1440.9, -926, 39.5, 160.1, 15, 10),
(70, 1326.15, -1066.55, 31.54, 'Niemand', 'Stadt Wohnung', 9000000, 0, 0, 50, 0, 1325.9, -1067.5, 31.5, 267, 19, 10),
(71, 1326.26, -1091.89, 27.95, 'Niemand', 'Stadt Wohnung', 9000000, 1, 0, 50, 0, 1326, -1090.5, 27.7, 277.6, 19, 10),
(72, 1285.18, -1091.31, 28.25, 'Niemand', 'Stadt Wohnung', 8000000, 0, 1, 50, 0, 1285, -1089, 28.2, 104, 19, 10),
(73, 1242.26, -1100.66, 27.95, 'Niemand', 'Stadt Wohnung', 8000000, 0, 0, 50, 0, 1242, -1098.4, 27.7, 268.7, 19, 10),
(74, 1241.93, -1076.06, 31.54, 'Niemand', 'Stadt Wohnung', 8000000, 0, 0, 444, 0, 1241.9, -1074.4, 31.5, 271.7, 19, 10),
(75, 1285.25, -1065.93, 31.67, 'iBase', 'Stadt Wohnung', 1000000, 0, 0, 100, 0, 1285, -1068, 31.6, 98.8, 19, 2),
(76, 1183.18, -1075.65, 31.67, 'Niemand', 'Stadt Wohnung', 8000000, 0, 1, 500, 0, 1183.4, -1074, 31.6, 95, 19, 10),
(77, 1183.43, -1099.28, 28.25, 'Niemand', 'Stadt Wohnung', 8000000, 0, 0, 150, 0, 1183.4, -1100.8, 28.2, 91, 19, 10),
(78, 1142.06, -1093.31, 28.18, 'Niemand', 'Stadt Wohnung', 8000000, 0, 0, 100, 0, 1142, -1094.5, 28.1, 270.1, 19, 10),
(79, 1141.88, -1069.93, 31.76, 'Niemand', 'Stadt Wohnung', 8000000, 0, 0, 500, 0, 1141.8, -1068, 31.7, 266.1, 19, 10),
(81, 1127.81, -1022.14, 34.99, 'Niemand', 'Stadt Wohnung', 6000000, 0, 0, 50, 0, 1128.5, -1022.5, 34.9, 156.6, 15, 10),
(82, 1117.93, -1022.27, 34.99, 'Niemand', 'Stadt Wohnung', 6000000, 0, 0, 50, 0, 1118.8, -1023, 34.9, 143.6, 15, 10),
(83, 1103.13, -1068.53, 31.87, 'Niemand', 'Stadt Wohnung', 8000000, 0, 0, 100, 0, 1103, -1070, 31.7, 79, 19, 10),
(84, 1103.39, -1092.51, 28.45, 'Niemand', 'Stadt Wohnung', 8000000, 0, 0, 250, 0, 1103.3, -1093.5, 28.2, 90, 15, 10),
(85, 1059.38, -1105.43, 28.04, 'Niemand', 'Stadt Wohnung', 9800000, 0, 0, 1000, 0, 1058, -1105.5, 28, 246.6, 15, 10),
(86, 1068.56, -1081.18, 27.54, 'Niemand', 'Stadt Wohnung', 4000000, 0, 1, 50, 0, 1068.8, -1079.5, 27.7, 272.7, 15, 10),
(87, 1051.06, -1058.28, 34.79, 'Niemand', 'Stadt Wohnung', 6000000, 0, 0, 350, 0, 1050, -1057.4, 34.7, 329.2, 15, 10),
(88, 993.77, -1058.26, 33.7, 'Niemand', 'Stadt Wohnung', 6000000, 0, 0, 405, 0, 992.7, -1057.5, 33.7, 337.7, 15, 10),
(89, 1196, -1017.21, 32.54, 'Niemand', 'Kleine Wohnung', 1700000, 0, 0, 200, 0, 0, 0, 0, 0, 3, 10),
(90, 1189.43, -1017.96, 32.54, 'Niemand', 'Kleine Wohnung', 1700000, 0, 0, 250, 0, 0, 0, 0, 0, 3, 10),
(91, 1188.56, -1011.83, 32.54, 'Niemand', 'Kleine Wohnung', 1700000, 0, 1, 100, 0, 0, 0, 0, 0, 3, 10),
(92, 1195.06, -1011.02, 32.54, 'Niemand', 'Kleine Wohnung', 1700000, 1, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(93, 1195.31, -1010.96, 36.22, 'Niemand', 'Kleine Wohnung', 1700000, 0, 0, 100, 0, 1195, -1011.5, 36.2, 96.4, 3, 10),
(94, 1188.81, -1011.83, 36.22, 'Niemand', 'Kleine Wohnung', 1700000, 0, 0, 50, 0, 1189, -1012.2, 36.2, 295.7, 3, 10),
(95, 1195.93, -1017.07, 36.22, 'Niemand', 'Kleine Wohnung', 1700000, 0, 0, 50, 0, 1195.5, -1016.4, 36.2, 105.5, 3, 10),
(96, 1189.67, -1017.94, 36.22, 'Niemand', 'Kleine Wohnung', 1700000, 0, 0, 100, 0, 1189.4, -1017.2, 36.2, 298.7, 2, 10),
(97, 1234.43, -1016.15, 32.59, 'Niemand', 'Kleine Wohnung', 1700000, 0, 0, 500, 0, 0, 0, 0, 0, 3, 10),
(98, 1226.93, -1010.9, 32.59, 'Niemand', 'Kleine Wohnung', 1700000, 1, 0, 100, 0, 1226.4, -1009.5, 32.5, 273.6, 3, 10),
(99, 1233.41, -1010.02, 32.59, 'Niemand', 'Kleine Wohnung', 1700000, 1, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(100, 1233.56, -1010.03, 36.31, 'Niemand', 'Wohnung', 1680000, 0, 0, 50, 0, 1233.4, -1010.7, 36.2, 88, 3, 10),
(101, 1227.29, -1010.89, 36.31, 'Niemand', 'Wohnung', 1680000, 0, 0, 50, 0, 1227, -1010.2, 36.2, 266.1, 3, 10),
(102, 1234.5, -1016.26, 36.33, 'Niemand', 'Moderne Wohnung', 1680000, 0, 0, 10000, 0, 1234, -1015.7, 36.2, 176.5, 3, 10),
(103, 1227.68, -1017.08, 36.33, 'Niemand', 'Moderne Wohnung', 1680000, 0, 0, 299, 0, 0, 0, 0, 0, 3, 10),
(104, 1227.65, -1017.33, 32.59, 'Niemand', 'Kleine Wohung', 1680000, 0, 0, 5000, 0, 1228, -1016.2, 36.2, 189.6, 3, 10),
(105, 1676.56, -1462.16, 13.55, 'Niemand', 'Wohnung', 1680000, 0, 0, 50, 0, 0, 0, 0, 0, 2, 10),
(106, 1691.93, -1458.8, 13.52, 'Niemand', 'Wohnung', 1680000, 0, 0, 50, 0, 0, 0, 0, 0, 2, 10),
(107, 1685.4, -1463.93, 13.52, 'Niemand', 'Wohnung', 1680000, 0, 0, 50, 0, 0, 0, 0, 0, 2, 10),
(108, 1333.3, -1266.39, 13.52, 'Niemand', 'Stadt Wohnung', 2000000, 0, 0, 200, 0, 1333.4, -1267.3, 13.5, 276.2, 20, 10),
(109, 1327.92, -1271.65, 13.52, 'Niemand', 'Stadt Wohnung', 2000000, 0, 0, 250, 0, 1326.5, -1271.5, 13.5, 192, 20, 10),
(110, 1333.65, -1308.16, 13.52, 'Niemand', 'Stadt Wohnung', 2500000, 0, 0, 1000, 0, 1333.5, -1306.9, 13.5, 284.2, 20, 10),
(111, 1333.56, -1329.18, 13.52, 'Niemand', 'Stadt Wohnung', 2500000, 0, 0, 50, 0, 1333.5, -1327.8, 13.5, 288.2, 20, 10),
(112, 1333.63, -1349.68, 13.52, 'Niemand', 'Stadt Wohnung', 2500000, 0, 1, 1000, 0, 1333.3, -1348.5, 13.5, 290.7, 20, 10),
(113, 1370.52, -1316.14, 13.52, 'Niemand', 'Stadt Wohnung', 2500000, 0, 1, 200, 0, 1370, -1315, 13.5, 99, 20, 10),
(114, 1370.4, -1320.18, 13.52, 'Niemand', 'Stadt Wohnung', 2500000, 0, 0, 1500, 0, 1370, -1319, 13.5, 93.3, 5, 10),
(115, 1370.29, -1365.14, 13.52, 'Niemand', 'Stadt Wohnung', 2500000, 0, 0, 100, 0, 1370.5, -1366.5, 13.5, 88.5, 20, 10),
(116, 1370.5, -1361.43, 13.52, 'Niemand', 'Stadt Wohnung', 2500000, 0, 0, 250, 0, 1370.4, -1362.8, 13.5, 88.5, 20, 10),
(117, 1370.56, -1341.27, 13.52, 'Niemand', 'Stadt Wohnung', 2500000, 0, 0, 50, 0, 1370, -1339.9, 13.5, 97, 5, 10),
(118, 1161.39, -1656.18, 14.09, 'Niemand', 'Wohnung', 6000000, 0, 0, 100, 0, 1161.5, -1657, 14.1, 89.3, 2, 10),
(119, 1140.78, -1586.68, 13.55, 'Niemand', 'Haus', 6000000, 0, 0, 150, 0, 1140.5, -1585.3, 13.5, 271.7, 17, 10),
(120, 1135.29, -1581.31, 13.47, 'Niemand', 'Haus', 6000000, 0, 1, 50, 0, 1133.5, -1581.4, 13.3, 6.3, 17, 10),
(122, 1206.93, -1439.27, 13.38, 'Niemand', 'Stadt Wohnung', 5000000, 0, 0, 1500, 0, 1207.3, -1440, 13.3, 100.5, 7, 10),
(123, 1206.78, -1459.56, 13.38, 'Niemand', 'Stadt Wohnung', 5000000, 0, 0, 500, 0, 1207, -1460.5, 13.3, 81.8, 5, 10),
(124, 1187, -1261.17, 15.17, 'Niemand', 'Kleine Wohnung', 1720000, 0, 0, 250, 0, 0, 0, 0, 0, 3, 10),
(125, 1180.38, -1261.06, 15.17, 'Niemand', 'Kleine Wohnung', 540000, 0, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(126, 1180.18, -1260.9, 18.87, 'Niemand', 'Kleine Wohnung', 1750000, 0, 0, 200, 0, 1180, -1260.5, 18.7, 231.1, 3, 10),
(127, 1186.65, -1260.88, 18.87, 'Niemand', 'Kleine Wohnung', 1780000, 0, 1, 50, 0, 1187, -1261.4, 18.7, 56.5, 2, 10),
(128, 1180.18, -1254.78, 18.87, 'Niemand', 'Kleine Wohnung', 1720000, 0, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(129, 1187.04, -1254.68, 18.87, 'Niemand', 'Kleine Wohnung', 1750000, 0, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(130, 1180.5, -1254.81, 15.17, 'Niemand', 'Kleine Wohnung', 1760000, 0, 0, 100, 0, 1179.5, -1254, 18.7, 227.1, 3, 10),
(131, 1186.9, -1254.56, 15.17, 'Niemand', 'Kleine Wohnung', 1740000, 0, 0, 250, 0, 1187.3, -1255.3, 18.7, 54.2, 5, 10),
(132, 1186.93, -1233.43, 18.54, 'Niemand', 'Kleine Wohnung', 1600000, 0, 1, 50, 0, 0, 0, 0, 0, 3, 10),
(133, 1180.42, -1233.31, 18.54, 'Niemand', 'Kleine Wohnung', 1600000, 0, 0, 100, 0, 0, 0, 0, 0, 2, 10),
(134, 1186.79, -1227.16, 18.54, 'Niemand', 'Kleine Wohnung', 1600000, 0, 0, 100, 0, 0, 0, 0, 0, 2, 10),
(135, 1180.5, -1227.04, 18.54, 'Niemand', 'Kleine Wohnung', 1600000, 0, 0, 50, 0, 0, 0, 0, 0, 2, 10),
(136, 1186.89, -1227.02, 22.12, 'Niemand', 'Moderne Wohnung', 1750000, 0, 0, 200, 0, 1187.3, -1227.5, 22.1, 52.5, 20, 10),
(137, 1180.31, -1227.16, 22.12, 'Niemand', 'Kleine Wohnung', 1740000, 0, 0, 50, 0, 1179.9, -1227.5, 22.1, 324.2, 20, 10),
(138, 1187.03, -1233.3, 22.12, 'Niemand', 'Moderne Wohnung', 1730000, 0, 0, 50, 0, 1187.4, -1232.5, 22.1, 136, 3, 10),
(139, 1180.31, -1233.31, 22.12, 'Niemand', 'Kleine Wohnung', 1780000, 0, 0, 50, 0, 1180, -1232.5, 22.1, 214.6, 3, 10),
(140, 1288.81, -1272.02, 13.52, 'Niemand', 'Moderne Wohnung', 2000000, 0, 0, 50, 0, 1287.5, -1271.8, 13.5, 191.3, 20, 10),
(141, 1421.81, -885.84, 50.65, 'Niemand', 'Vinewood Haus', 20000000, 0, 0, 1000, 0, 1423, -886, 50.5, 2.2, 20, 10),
(142, 1468.56, -905.71, 54.83, 'Niemand', 'Vinewood Haus', 23000000, 1, 1, 1000, 0, 1467.4, -905.5, 54.7, 7.3, 15, 10),
(143, 1540.03, -851.38, 64.33, 'Niemand', 'Vinewood Haus', 22000000, 0, 0, 100, 0, 1539.9, -852.7, 64.3, 82, 4, 10),
(144, 1534.93, -800.15, 72.83, 'Niemand', 'Vinewood Haus', 26000000, 1, 0, 200, 0, 1534.5, -801.2, 72.8, 79.5, 15, 3),
(145, 1527.68, -772.65, 80.55, 'Niemand', 'Vinewood Haus', 27000000, 0, 0, 500, 2000, 1528, -773.5, 80.5, 127.9, 20, 10),
(147, 1441.68, -629.08, 95.69, 'Niemand', 'Vinewood Haus', 40000000, 1, 0, 50, 0, 1442.9, -629, 95.5, 179.6, 4, 5),
(148, 1332.15, -633.03, 109.12, 'Miraie.Kawasaki', 'OS VILLA', 1000000, 1, 0, 1000, 20050, 0, 0, 0, 0, 11, 1),
(149, 1258.56, -785.28, 92.01, 'Kirito.Kirigaya', 'MadDogg Villa', 5, 0, 0, 50, 0, 1258, -786.2, 92, 71.5, 12, 10),
(150, 1112.26, -741.78, 100.12, 'Niemand', 'Vinewood Haus', 22000000, 0, 0, 1000, 0, 1112.5, -740.4, 100, 103, 14, 10),
(151, 1034.68, -812.9, 101.83, 'Niemand', 'Vinewood Haus', 15000000, 0, 0, 2500, 0, 1033.5, -813.2, 101.8, 8.6, 20, 10),
(152, 990.21, -828.21, 95.44, 'Niemand', 'Vinewood Haus', 16000000, 0, 0, 200, 0, 0, 0, 0, 0, 15, 10),
(153, 937.65, -847.82, 93.69, 'Styler852', 'Vinewood Haus', 1000000, 0, 0, 1000, 0, 936.4, -848.4, 93.5, 26.7, 20, 10),
(154, 910.39, -817.34, 103.12, 'Niemand', 'Vinewood Haus', 8000000, 0, 0, 100, 0, 0, 0, 0, 0, 20, 10),
(155, 827.78, -858.33, 70.33, 'Niemand', 'Vinewood Haus', 15000000, 0, 0, 50, 0, 828.9, -857.9, 70.3, 202.8, 15, 10),
(157, 785.84, -828.15, 70.26, 'Niemand', 'Vinewood Haus', 8600000, 0, 0, 250, 0, 786.7, -828, 70, 20.1, 14, 10),
(158, 725.08, -998.84, 52.72, 'Niemand', 'Vinewood Haus', 12000000, 0, 0, 1000, 0, 726, -999.2, 52.7, 44, 11, 10),
(159, 672.59, -1020.09, 55.75, 'Niemand', 'Vinewood Haus', 10000000, 0, 0, 500, 0, 0, 0, 0, 0, 20, 10),
(160, 700.09, -1060.18, 49.4, 'Niemand', 'Vinewood Haus', 25000000, 0, 0, 450, 0, 699.2, -1061.3, 49.4, 49, 19, 10),
(161, 648.15, -1058.31, 52.56, 'Niemand', 'Vinewood Haus', 11100000, 0, 0, 1500, 0, 0, 0, 0, 0, 20, 10),
(162, 645.83, -1117.56, 44.2, 'Niemand', 'Vinewood Haus', 16000000, 0, 0, 5000, 0, 646.5, -1115.9, 44.2, 132, 15, 10),
(163, 612.38, -1085.68, 58.81, 'Niemand', 'Vinewood Haus', 11000000, 0, 0, 50, 0, 610.7, -1086, 58.7, 23.6, 20, 10),
(164, 558.28, -1161, 54.4, 'Niemand', 'Vinewood Haus', 7000000, 0, 0, 350, 0, 559.2, -1160.5, 54.4, 13.8, 20, 10),
(165, 553.21, -1200.17, 44.83, 'Niemand', 'Vinewood Haus', 10000000, 0, 0, 100, 0, 0, 0, 0, 0, 3, 10),
(166, 471.04, -1164.4, 67.19, 'Niemand', 'Vinewood Villa', 18000000, 0, 0, 1500, 0, 472.1, -1164.5, 67, 164.3, 19, 10),
(167, 431.89, -1253.43, 51.58, 'Niemand', 'Vinewood Haus', 8000000, 0, 0, 3750, 0, 0, 0, 0, 0, 15, 10),
(168, 398.67, -1271.15, 50, 'Niemand', 'Vinewood Haus', 11000000, 1, 0, 1000, 0, 0, 0, 0, 0, 20, 10),
(169, 355.1, -1281.06, 53.7, 'Niemand', 'Vinewood Haus', 8000000, 0, 0, 450, 0, 0, 0, 0, 0, 15, 10),
(172, 253.22, -1269.93, 74.41, 'Niemand', 'Vinewood Villa', 90000000, 0, 0, 1200, 0, 251.8, -1270.5, 74.4, 6, 19, 10),
(173, 251.88, -1220.78, 75.87, 'sQz.', 'Vinewood Villa', 1000000, 0, 0, 5000, 0, 253.3, -1220.3, 75.5, 225, 4, 10),
(174, 351.97, -1197.43, 76.51, 'Niemand', 'Vinewood Haus', 11000000, 1, 0, 2500, 0, 350.6, -1198.4, 76.5, 43.7, 15, 10),
(175, 300.01, -1154.56, 81.26, 'Kazuto.Kirigaya', 'Vinewoodvilla', 1000000, 1, 0, 50, 400, 300.7, -1155.4, 81, 144.1, 12, 2),
(176, 416.26, -1154.25, 76.68, 'Niemand', 'Vinewood Haus', 20000000, 0, 0, 100, 0, 0, 0, 0, 0, 15, 10),
(177, 219.25, -1249.93, 78.33, 'Niemand', 'Vinewood Villa', 60000000, 1, 0, 500, 0, 220.3, -1249.3, 78.3, 251.3, 4, 10),
(178, 189.63, -1308.18, 70.23, '$CRIM', 'Vinewood Villa', 1000000, 0, 0, 100, 0, 189.8, -1306.5, 70, 228.5, 18, 1),
(179, 228.38, -1405.18, 51.59, 'Niemand', 'Vinewood Haus', 16000000, 0, 0, 400, 0, 229.8, -1405, 51.5, 48.7, 15, 10),
(180, 143, -1469.92, 25.2, 'Niemand', 'Vinewood Haus', 17000000, 0, 0, 50, 0, 141.8, -1469.4, 25.2, 336.2, 20, 10),
(181, 1886.53, -1113.88, 26.27, 'Niemand', 'Wohnung', 2500000, 0, 0, 50, 0, 1888, -1115.4, 25.2, 184.3, 3, 10),
(182, 1905.81, -1112.93, 26.62, 'Niemand', 'Wohnung', 2500000, 0, 0, 50, 0, 1907.3, -1116, 25.6, 234.1, 3, 10),
(183, 1921.78, -1115.43, 27.04, 'Niemand', 'Wohnung', 2800000, 0, 0, 125, 0, 1923.9, -1117.3, 26, 176.8, 3, 10),
(184, 1938.93, -1114.43, 27.45, 'Niemand', 'Wohnung', 2500000, 0, 1, 500, 0, 1940.5, -1117.5, 26.2, 170, 3, 10),
(185, 1955.27, -1115.39, 27.79, 'Niemand', 'Wohnung', 2500000, 0, 0, 50, 0, 1957.5, -1117.5, 26.7, 171.8, 5, 10),
(186, 2022.81, -1120.26, 26.42, 'Niemand', 'Wohnung', 2000000, 0, 0, 100, 0, 2021.5, -1123.5, 26.1, 160.6, 5, 10),
(187, 2045.65, -1116.31, 26.36, 'Niemand', 'Wohnung', 2000000, 0, 0, 1000, 0, 2047.4, -1114, 25.6, 245.1, 5, 10),
(188, 2093.86, -1123.01, 27.68, 'Niemand', 'Wohnung', 2000000, 0, 0, 50, 0, 2092, -1122, 26.7, 91.3, 5, 10),
(189, 2095.35, -1145.06, 26.59, 'Niemand', 'Wohnung', 2000000, 0, 0, 50, 0, 2092.1, -1146.5, 25.5, 101.5, 5, 10),
(190, 2092.05, -1166.3, 26.54, 'Niemand', 'Wohnung', 1500000, 0, 0, 100, 0, 2088.8, -1167.4, 25.5, 100.5, 3, 10),
(191, 2091.57, -1184.66, 27.04, 'Niemand', 'Wohnung', 1500000, 0, 0, 100, 0, 2089.5, -1186.8, 26, 85.3, 3, 10),
(192, 2090.62, -1234.81, 25.68, 'Niemand', 'Wohnung', 3000000, 0, 0, 500, 0, 2091.3, -1234, 25.2, 18.2, 7, 10),
(193, 2110.87, -1243.93, 25.85, 'Niemand', 'Haus', 4000000, 1, 1, 650, 0, 2109.6, -1244, 25.7, 34, 2, 4),
(194, 2153.77, -1243.18, 25.36, 'Niemand', 'Haus', 4000000, 0, 0, 1000, 0, 2152.3, -1243.4, 25.2, 26.1, 3, 10),
(195, 2191.75, -1238.93, 24.12, 'Niemand', 'Wohnung', 2000000, 0, 0, 100, 0, 2193.1, -1238.9, 24.1, 11.6, 2, 10),
(196, 2209.76, -1239.68, 24.12, 'Niemand', 'Wohnung', 3000000, 0, 0, 500, 0, 2210.8, -1240, 24.1, 25.2, 3, 10),
(197, 2229.12, -1240.4, 25.61, 'Niemand', 'Wohnung', 4000000, 0, 0, 100, 0, 2227.5, -1240.3, 25.2, 24.7, 3, 10),
(198, 2249.86, -1238.81, 25.87, 'Niemand', 'Haus', 2000000, 0, 0, 50, 0, 2248.3, -1238.5, 25.7, 21.2, 3, 10),
(199, 2250.12, -1280.38, 25.45, 'Niemand', 'Haus', 4000000, 0, 0, 100, 0, 2251.8, -1280.5, 25.2, 206.6, 3, 10),
(200, 2230.12, -1280.81, 25.36, 'Niemand', 'Wohnung', 1000000, 0, 1, 500, 0, 2231.6, -1280, 25.2, 177.8, 3, 10),
(201, 2208.04, -1281.18, 24.79, 'Niemand', 'Wohnung', 1000000, 0, 0, 50, 0, 2209.1, -1280.9, 24.7, 198.8, 3, 10),
(202, 2191.62, -1276.5, 25.12, 'Niemand', 'Wohnung', 1000000, 0, 0, 100, 0, 2193.6, -1277, 25, 198.8, 20, 10),
(203, 2150.12, -1285.51, 24.19, 'Niemand', 'Wohnung', 1000000, 0, 0, 150, 0, 2148.8, -1285, 24.1, 193.8, 20, 10),
(204, 2148.37, -1319.56, 25.7, 'Niemand', 'Wohnung', 2400000, 0, 1, 50, 0, 2150.3, -1319, 25.7, 60.7, 7, 10),
(205, 2126.78, -1320.18, 26.62, 'Niemand', 'Großes Haus', 2000000, 0, 0, 50, 0, 2124.8, -1317.3, 25.5, 322, 5, 10),
(206, 2132.37, -1280.53, 25.87, 'Niemand', 'Wohnung', 1000000, 0, 0, 100, 0, 2133.8, -1280.5, 25.7, 208.3, 7, 10),
(207, 2111.37, -1279.65, 25.68, 'Niemand', 'Wohnung', 1200000, 0, 0, 200, 0, 2110.6, -1279.3, 25.6, 139.3, 5, 10),
(208, 2091.28, -1279.18, 26.1, 'Niemand', 'Wohnung', 1000000, 0, 1, 150, 0, 2092.3, -1278.9, 26.1, 218.1, 20, 10),
(209, 2100.87, -1321.56, 25.95, 'Niemand', 'Wohnung', 2400000, 0, 0, 100, 0, 2099.3, -1321.5, 25.7, 12.6, 3, 10),
(210, 2129.54, -1362.18, 25.79, 'Niemand', 'Wohnung', 2400000, 0, 0, 500, 0, 2130.8, -1361.5, 25.7, 214.6, 20, 10),
(211, 2147.55, -1366.43, 25.62, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 2146.6, -1366, 25.6, 184.3, 20, 10),
(212, 2185.28, -1364.31, 25.79, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 2183.6, -1363.5, 25.7, 213.5, 20, 10),
(213, 2202.62, -1364.25, 25.86, 'Niemand', 'Wohnung', 2000000, 0, 0, 50, 0, 2201.5, -1363.9, 25.7, 159.3, 20, 10),
(214, 2230.37, -1396.88, 24.2, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 2231.6, -1397, 24.2, 24.7, 7, 10),
(215, 2243.12, -1396.81, 24.2, 'Niemand', 'Wohnung', 1200000, 0, 0, 500, 0, 2244.5, -1397, 24.2, 22.2, 7, 10),
(216, 2256.59, -1396.81, 24.2, 'Niemand', 'Wohnung', 1000000, 0, 0, 50, 0, 2255, -1396.9, 24.2, 22.7, 7, 10),
(217, 2196.62, -1404.05, 25.61, 'Niemand', 'Wohnung', 1000000, 0, 0, 100, 0, 2196.3, -1405, 25.6, 273.7, 7, 10),
(218, 2189.79, -1419.16, 26.1, 'Niemand', 'Wohnung', 2400000, 0, 1, 500, 0, 2189.6, -1417.5, 26.1, 296.7, 7, 10),
(219, 2191.62, -1455.75, 25.7, 'Niemand', 'Wohnung', 1600000, 0, 0, 50, 0, 2191.1, -1456.8, 25.7, 279.7, 7, 10),
(220, 2232.62, -1469.93, 24.25, 'Niemand', 'Wohnung', 1000000, 1, 0, 50, 0, 2231.3, -1469.4, 24.2, 189, 3, 2),
(221, 2247.86, -1469.8, 24.12, 'Niemand', 'Wohnung', 1200000, 0, 1, 50, 0, 2246.5, -1469.4, 24.1, 187, 7, 10),
(222, 2263.87, -1469.68, 24.04, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 2262.6, -1469.4, 24, 179.3, 7, 10),
(223, 2190.62, -1470.43, 25.87, 'Niemand', 'Wohnung', 1700000, 0, 0, 100, 0, 2190.8, -1469, 25.7, 289, 7, 10),
(224, 2150.62, -1419.05, 25.92, 'Niemand', 'Wohnung', 1200000, 1, 0, 50, 0, 2150.3, -1420.5, 25.7, 98, 7, 10),
(225, 2149.37, -1433.81, 25.87, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 2149.6, -1432.9, 25.7, 100.5, 8, 10),
(226, 2151.62, -1446.18, 25.77, 'Niemand', 'Wohnung', 1500000, 0, 0, 50, 0, 2151.8, -1444.8, 25.7, 97.9, 7, 10),
(227, 2146.12, -1470.67, 25.7, 'Niemand', 'Wohnung', 1200000, 0, 0, 150, 0, 2146.6, -1471.9, 25.7, 126, 7, 10),
(228, 2148.35, -1484.81, 26.62, 'Niemand', 'Großes Haus', 2000000, 0, 0, 888, 0, 2146.3, -1482.9, 25.5, 66.9, 19, 10),
(229, 1863.53, -1597.81, 14.3, 'Niemand', 'Wohnung', 1500000, 0, 0, 100, 0, 1865, -1597.5, 14.3, 179.6, 7, 10),
(230, 1909.65, -1597.9, 14.3, 'Niemand', 'Wohnung', 1400000, 0, 0, 50, 0, 1911, -1597.8, 14.3, 188.5, 7, 10),
(231, 1853.93, -1914.52, 15.25, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 1854.9, -1914, 15.1, 184.6, 7, 10),
(232, 1872.18, -1912.06, 15.25, 'Niemand', 'Wohnung', 1200000, 0, 1, 50, 0, 1873.4, -1912, 15.1, 194.8, 20, 10),
(233, 1891.93, -1914.79, 15.25, 'Niemand', 'Wohnung', 1200000, 1, 0, 50, 0, 1892.9, -1914.4, 15.1, 183.3, 20, 10),
(234, 1913.31, -1912.18, 15.25, 'Niemand', 'Wohnung', 1200000, 0, 0, 500, 0, 1914.8, -1912, 15.1, 178, 20, 10),
(235, 1928.64, -1916.06, 15.25, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 1929.4, -1916, 15.1, 178.6, 20, 10),
(236, 1938.25, -1911.43, 15.25, 'Niemand', 'Wohnung', 1200000, 0, 0, 100, 0, 1938.4, -1912.5, 15.1, 94, 20, 10),
(237, 1967.5, -1634.18, 15.96, 'Niemand', 'Wohnung', 1200000, 0, 0, 250, 0, 0, 0, 0, 0, 20, 10),
(238, 1972.18, -1634.03, 15.96, 'Niemand', 'Wohnung', 1000000, 0, 0, 50, 0, 0, 0, 0, 0, 20, 10),
(239, 1967.43, -1634.06, 18.54, 'Niemand', 'Wohnung', 1200000, 0, 0, 100, 0, 1968, -1633.5, 15.8, 176.6, 20, 10),
(240, 1972.18, -1634.03, 18.54, 'Niemand', 'Wohnung', 1200000, 0, 0, 500, 0, 1968.5, -1633.8, 18.5, 182.6, 20, 10),
(241, 1973.3, -1655.01, 15.96, 'Niemand', 'Wohnung', 1000000, 0, 0, 100, 0, 1974.5, -1654.5, 15.8, 190.3, 7, 10),
(242, 1969.52, -1654.9, 15.96, 'Niemand', 'Wohnung', 1000000, 0, 0, 50, 0, 1970.5, -1655, 15.8, 181.6, 7, 10),
(243, 1969.93, -1671.52, 18.54, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 0, 0, 0, 0, 7, 10),
(244, 1974.79, -1671.56, 18.54, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 0, 0, 0, 0, 7, 10),
(245, 1970.06, -1671.31, 15.96, 'Niemand', 'Wohnung', 1200000, 0, 0, 200, 0, 1971, -1671.3, 18.5, 179.6, 20, 10),
(246, 1974.81, -1671.64, 15.96, 'Niemand', 'Wohnung', 1000000, 0, 1, 50, 0, 1976, -1671.4, 18.5, 178.6, 5, 10),
(247, 1981.31, -1682.81, 17.04, 'Niemand', 'Stadthaus', 4000000, 1, 0, 100, 0, 1982.9, -1680.8, 15.8, 268.2, 19, 10),
(248, 1973.18, -1705.43, 15.96, 'Niemand', 'Wohnung', 1000000, 0, 0, 200, 0, 0, 0, 0, 0, 5, 10),
(249, 1969.31, -1705.53, 15.96, 'Niemand', 'Wohnung', 1200000, 0, 1, 50, 0, 1968.5, -1705, 15.8, 188.1, 5, 10),
(250, 1980.63, -1718.93, 17.03, 'sano.manjiro', 'Stadthaus', 1000000, 1, 0, 5000, 0, 0, 0, 0, 0, 19, 10),
(251, 2014.29, -1732.43, 14.21, 'Diaz', 'Wohnung', 1000000, 1, 0, 500, 0, 2014, -1733.5, 14.1, 67, 7, 10),
(252, 2015.81, -1717.03, 13.97, 'Niemand', 'Kleines Haus', 1200000, 0, 0, 100, 0, 2015.3, -1717.9, 13.5, 85.8, 5, 10),
(253, 2017.27, -1703.42, 14.22, 'Niemand', 'Wohnung', 1200000, 0, 1, 50, 0, 2016.4, -1705, 14.1, 95, 17, 10),
(254, 2013.04, -1656.18, 13.8, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 2013, -1657.5, 13.8, 97, 5, 10),
(255, 2016.06, -1641.79, 13.77, 'Niemand', 'Wohnung', 1500000, 0, 0, 150, 0, 2016, -1642.5, 13.6, 95, 5, 10),
(256, 2017.31, -1629.93, 13.52, 'HappyCookie', 'Wohnung', 700000, 1, 0, 50, 0, 2017.4, -1630.8, 13.6, 88.5, 5, 10),
(257, 1987.03, -1605.17, 13.52, 'Niemand', 'Wohnung', 1200000, 0, 0, 100, 0, 1987.8, -1604, 13.5, 237.3, 7, 10),
(258, 2002.54, -1594.18, 13.56, 'Niemand', 'Wohnung', 900000, 0, 0, 50, 0, 2001.5, -1594.9, 13.5, 213.8, 7, 10),
(259, 2011.31, -1594.43, 13.56, 'Niemand', 'Wohnung', 1200000, 0, 1, 100, 0, 2010.5, -1595, 13.5, 227.6, 7, 10),
(260, 2068.29, -1628.81, 13.85, 'Niemand', 'Haus', 1200000, 0, 1, 150, 0, 2068.1, -1627.5, 13.8, 269.5, 14, 10),
(261, 2067.79, -1731.67, 13.85, 'Niemand', 'Haus', 1200000, 0, 0, 50, 0, 2067.3, -1730.3, 13.8, 269.5, 17, 10),
(262, 2066.51, -1717.06, 13.8, 'Niemand', 'Haus', 1200000, 0, 0, 50, 0, 2066.6, -1716, 13.8, 272.2, 17, 10),
(263, 2065.61, -1703.54, 14.14, 'Niemand', 'Wohnung', 5000000, 0, 1, 10000, 0, 2065.5, -1702.4, 14.1, 268.7, 20, 10),
(264, 2067.12, -1656.54, 13.89, 'Niemand', 'Wohnung', 1000000, 1, 0, 50, 0, 2067.3, -1655, 13.5, 264.2, 2, 10),
(265, 2068, -1643.68, 13.8, 'Niemand', 'Haus', 1200000, 0, 0, 150, 0, 2067.6, -1642.4, 13.8, 269.5, 19, 10),
(266, 2142.87, -1604.93, 14.35, 'Niemand', 'Kleine Wohnung', 720000, 0, 1, 50, 0, 2143.5, -1605.3, 14.3, 152.8, 3, 10),
(267, 2158.02, -1611.81, 14.34, 'Niemand', 'Kleine Wohnung', 1000000, 0, 0, 50, 0, 2156.6, -1611, 14.3, 169.1, 3, 10),
(268, 2178.37, -1660.25, 14.97, 'Niemand', 'Kleine Wohnung', 1000000, 0, 0, 150, 0, 2177.6, -1661.5, 14.8, 219, 3, 10),
(269, 2166.12, -1671.56, 15.06, 'Niemand', 'Kleine Wohnung', 1000000, 0, 0, 100, 0, 2166.8, -1670.5, 15, 230.3, 2, 10),
(270, 2155.37, -1699.18, 15.06, 'Niemand', 'Kleine Wohnung', 900000, 0, 0, 500, 0, 2156.5, -1698.8, 15, 185.1, 3, 10),
(271, 2156.87, -1708.91, 15.06, 'Niemand', 'Kleine Wohnung', 900000, 0, 0, 250, 0, 2157.8, -1709, 15, 358.1, 3, 10),
(272, 2139.12, -1697.88, 15.06, 'Niemand', 'Kleine Wohnung', 900000, 0, 0, 500, 0, 0, 0, 0, 0, 3, 10),
(273, 2156.29, -1652.52, 15.06, 'Niemand', 'Kleine Wohnung', 900000, 0, 0, 111, 0, 2157.1, -1651.5, 15, 230.3, 3, 10),
(274, 2163.36, -1660.81, 15.06, 'Niemand', 'Kleine Wohnung', 900000, 0, 0, 100, 0, 2164.3, -1660, 15, 54, 3, 10),
(275, 2144.12, -1663.29, 15.06, 'Niemand', 'Kleine Wohnung', 900000, 0, 0, 50, 0, 2144.8, -1662.4, 15, 223.6, 3, 10),
(276, 2141.58, -1802.13, 16.12, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 1, 8000, 0, 0, 0, 0, 0, 5, 10),
(277, 2144.62, -1801.93, 16.12, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 0, 10000, 0, 2143.6, -1801.8, 16.1, 189.6, 5, 10),
(278, 2146.87, -1808.77, 16.12, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 0, 100, 0, 2146.6, -1809.8, 16.1, 270.2, 5, 10),
(279, 2151.75, -1819.18, 16.12, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 0, 50, 0, 2152.3, -1819.4, 16.1, 355, 5, 10),
(280, 2158.3, -1819.43, 16.12, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 0, 100, 0, 2158.6, -1819.4, 16.1, 353.1, 5, 10),
(281, 2172.11, -1819.31, 16.12, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 0, 50, 0, 2172.6, -1819.5, 16.1, 5.3, 5, 10),
(282, 2164.87, -1819.43, 16.12, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 0, 100, 0, 2165.3, -1819.4, 16.1, 356.2, 5, 10),
(283, 2176.37, -1821.56, 16.12, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 0, 225, 0, 2176.3, -1820.8, 16.1, 88.4, 2, 10),
(284, 2169.07, -1814.65, 13.52, 'Niemand', 'Gemeinschaftswohnung', 450000, 0, 1, 200, 0, 2168, -1815, 13.5, 0.4, 2, 10),
(285, 2162.76, -1815.02, 13.52, 'Niemand', 'Gemeinschaftswohnung', 480000, 0, 1, 50, 0, 2161.6, -1815, 13.5, 0.4, 2, 10),
(286, 2151.12, -1807.93, 13.52, 'Niemand', 'Gemeinschaftswohnung', 470000, 0, 1, 50, 0, 2151.1, -1806.5, 13.5, 276.7, 2, 10),
(287, 2151.37, -1789.27, 13.5, 'JanReloaded', 'Gemeinschaftswohnung', 410000, 1, 0, 10000, 0, 2151.1, -1788, 13.5, 262.7, 3, 10),
(288, 2192.25, -1814.56, 13.52, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 0, 150, 0, 2190.8, -1814.9, 13.5, 359.7, 2, 10),
(289, 2186.03, -1814.81, 13.52, 'Niemand', 'Gemeinschaftswohnung', 900000, 0, 1, 150, 0, 2185, -1814.5, 13.5, 359.7, 2, 10),
(290, 2232.37, -1785.65, 13.56, 'Niemand', 'Wohnappartement', 1800000, 0, 1, 1000, 0, 2232.6, -1786.8, 13.5, 92.4, 15, 10),
(291, 2275.33, -1785.51, 13.52, 'Niemand', 'Wohnappartement', 1800000, 0, 0, 50, 0, 2275.6, -1786.4, 13.5, 89.5, 15, 10),
(292, 2247.37, -1796, 13.52, 'Niemand', 'Wohnappartement', 1800000, 0, 0, 100, 0, 2247.3, -1794.3, 13.5, 279.5, 15, 10),
(293, 2290.37, -1795.93, 13.52, 'Niemand', 'Wohnappartement', 1800000, 0, 0, 100, 0, 2290.1, -1794.5, 13.5, 263.5, 2, 10),
(294, 2307.62, -1785.75, 13.55, 'Niemand', 'Wohnappartement', 1800000, 0, 0, 100, 0, 2307.3, -1786.5, 13.5, 90.9, 14, 10),
(295, 2322.37, -1795.93, 13.52, 'Niemand', 'Wohnappartement', 1400000, 0, 0, 500, 0, 2322.1, -1794, 13.5, 263.2, 19, 10),
(296, 2345.28, -1785.81, 13.52, 'Niemand', 'Wohnappartement', 1800000, 0, 0, 100, 0, 2345.3, -1786.5, 13.5, 91.5, 17, 10),
(297, 2380.62, -1785.63, 13.52, 'Niemand', 'Wohnappartement', 1800000, 0, 0, 100, 0, 2380.3, -1784.5, 13.5, 82.5, 17, 10),
(298, 2308.84, -1714.81, 14.64, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 2310.1, -1714.5, 14.6, 181.3, 5, 10),
(299, 2326.62, -1717.06, 13.89, 'Niemand', 'Wohnung', 1200000, 0, 0, 50, 0, 2327.8, -1717, 13.8, 191.6, 5, 10),
(300, 2385.5, -1712, 14.22, 'Niemand', 'Wohnung', 1800000, 1, 0, 100, 0, 2386.5, -1712.9, 14.1, 173.6, 5, 1),
(301, 2327.37, -1682.06, 14.92, 'Niemand', 'Wohnung', 1350000, 0, 0, 100, 0, 2328.1, -1680.5, 14.8, 271.2, 5, 10),
(302, 1895.43, -2068.37, 15.64, 'Niemand', 'Wohnung ', 1850000, 0, 0, 250, 0, 1894, -2068.5, 15.6, 330.7, 5, 10),
(303, 1873.56, -2070.37, 15.47, 'Niemand', 'Wohnung ', 1850000, 0, 1, 50, 0, 1872.3, -2070.3, 15.3, 353, 5, 10),
(304, 1851.77, -2070.04, 15.47, 'Niemand', 'Wohnung ', 1850000, 0, 0, 50, 0, 1850.4, -2070.1, 15.3, 340.5, 5, 10),
(305, 1905.75, -2041.56, 13.52, 'Niemand', 'Wohnung', 1550000, 0, 0, 2500, 0, 1907, -2041, 13.5, 177.6, 3, 10),
(306, 1898.43, -2038.05, 13.52, 'Niemand', 'Wohnung', 1590000, 0, 0, 100, 0, 1898.5, -2039.4, 13.5, 86, 3, 10),
(307, 1894.93, -2021.43, 13.52, 'Niemand', 'Wohnung', 1610000, 0, 0, 250, 0, 1894.5, -2019.8, 13.5, 128.1, 17, 10),
(308, 1877.68, -2001.15, 13.52, 'Niemand', 'Wohnung', 1920400, 0, 0, 250, 0, 1877.5, -1999.9, 13.5, 267.7, 17, 10),
(309, 1871.06, -2019.43, 13.52, 'Niemand', 'Wohnung', 1790000, 0, 0, 50, 0, 1871, -2020.4, 13.5, 257.1, 7, 10),
(310, 1867.68, -2028.52, 13.52, 'Niemand', 'Wohnung', 1430000, 0, 1, 100, 0, 0, 0, 0, 0, 17, 10),
(311, 1859.02, -2041.42, 13.52, 'Niemand', 'Wohnung', 1510000, 0, 0, 50, 0, 1857, -2041, 13.5, 209.3, 19, 10),
(312, 1898.54, -2004.13, 13.52, 'Niemand', 'Wohnung', 1470000, 0, 0, 100, 0, 1899.8, -2004.5, 13.5, 126.8, 17, 10),
(313, 1851.56, -2135.12, 15.38, 'Niemand', 'Wohnung', 2010000, 0, 0, 450, 0, 0, 0, 0, 0, 16, 10),
(314, 1872.56, -2133.36, 15.47, 'Niemand', 'Wohnung', 2020000, 0, 1, 500, 0, 0, 0, 0, 0, 5, 10),
(315, 1894.16, -2133.87, 15.46, 'Niemand', 'Wohnung', 2025000, 0, 0, 500, 500, 0, 0, 0, 0, 5, 10),
(316, 1802.06, -2098.87, 14.02, 'Niemand', 'Wohnung', 1810000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 10),
(318, 1782.05, -2126.12, 14.06, 'Niemand', 'Wohnung', 1610000, 0, 0, 50, 0, 0, 0, 0, 0, 6, 10),
(319, 2140.59, -1707.68, 15.06, 'Niemand', 'Wohnung', 1820000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 10),
(320, 1781.38, -2101.79, 14.05, 'Niemand', 'Wohnung', 1520000, 0, 0, 50, 0, 0, 0, 0, 0, 5, 10),
(321, 2141.03, -1652.43, 15.06, 'Niemand', 'Wohnung', 1500000, 0, 0, 500, 0, 0, 0, 0, 0, 5, 10),
(322, 2437.87, -2020.43, 13.89, 'Niemand', 'Wohnung', 1700000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 10),
(323, 2465.12, -1996.18, 13.68, 'Niemand', 'Wohnung', 1600000, 0, 0, 400, 0, 0, 0, 0, 0, 5, 10),
(328, 2736.62, -1926.54, 13.52, 'Niemand', 'Wohnung', 1900000, 0, 0, 400, 0, 2736.6, -1927.4, 13.5, 105, 17, 10),
(329, 2851.01, -1532.68, 11.09, 'Niemand', 'Haus am Meer', 9000000, 0, 0, 2500, 0, 2851.1, -1534, 11, 280.7, 11, 10),
(330, 2853.12, -1365.9, 14.14, 'Niemand', 'Wohnung am Meer', 2300000, 0, 0, 50, 0, 2853.6, -1367, 14.1, 263.7, 15, 10),
(331, 2842.05, -1335.43, 14.72, 'Niemand', 'Wohnung', 1800000, 0, 0, 50, 0, 2842.8, -1334.5, 14.6, 273.5, 15, 10),
(332, 2808.12, -1175.93, 25.37, 'Niemand', 'Haus am Meer', 3200000, 0, 1, 1, 0, 2809, -1176, 25.2, 175.8, 14, 10),
(333, 2808.09, -1190.31, 25.34, 'Niemand', 'Haus am Meer', 3200000, 0, 0, 500, 0, 2808.6, -1190, 25.2, 359.1, 14, 10),
(334, 2801.12, -1105.43, 30.7, 'Niemand', 'Luxus-Wohnung', 8900000, 0, 0, 200, 0, 2800.6, -1103.8, 30.7, 282.2, 18, 10),
(335, 2800.62, -1070.41, 30.67, 'Niemand', 'Luxus-Wohnung', 8900000, 0, 1, 50, 0, 2800.6, -1071.5, 30.6, 267.2, 18, 10),
(336, 2626.12, -1112.56, 67.83, 'Niemand', 'Wohnung', 1500000, 0, 0, 100, 0, 2626.1, -1111.4, 67.9, 248.6, 5, 10),
(337, 2626.62, -1098.75, 69.33, 'Niemand', 'Wohnung', 1500000, 0, 0, 50, 0, 2626.1, -1097.8, 69.4, 258, 5, 10),
(338, 2628.01, -1085.06, 69.61, 'Niemand', 'Wohnung', 2400000, 0, 0, 50, 0, 2628, -1083.5, 69.5, 271.6, 2, 10),
(339, 2628.84, -1068.02, 69.61, 'Niemand', 'Wohnung', 3000000, 0, 0, 250, 0, 2628.3, -1066.5, 69.5, 250.3, 2, 10),
(342, 2576.5, -1070.55, 69.83, 'Niemand', 'Wohnhaus', 1200000, 0, 0, 150, 0, 2576.1, -1069.5, 69.8, 93.5, 2, 10),
(344, 2490.62, -1011.84, 65.37, 'Niemand', 'Wohnung', 1200000, 0, 0, 100, 0, 2489.3, -1013, 65.3, 133.1, 3, 10),
(345, 2462.33, -1011.28, 60.11, 'Niemand', 'Wohnung', 1150000, 0, 0, 340, 0, 2463.6, -1011.4, 60, 148.1, 3, 10),
(347, 2278.76, -1077.42, 48.22, 'Niemand', 'Wohnung', 1150000, 0, 0, 50, 0, 2279.8, -1078, 47.5, 326.2, 5, 10),
(348, 2287.37, -1081, 48.24, 'Niemand', 'Wohnung', 1050000, 0, 0, 50, 0, 2288.6, -1081.4, 47.5, 340.7, 3, 10),
(349, 2249.62, -1059.75, 55.95, 'Niemand', 'Wohnung', 1250000, 0, 0, 50, 0, 0, 0, 0, 0, 5, 10),
(350, 2186.37, -997.65, 66.44, 'Niemand', 'Wohnung', 1490000, 0, 0, 100, 0, 0, 0, 0, 0, 2, 10),
(351, 2139.87, -1008.33, 61.81, 'Niemand', 'Wohnung', 2500000, 0, 0, 187, 0, 2138.1, -1008, 61.4, 346.7, 5, 10),
(352, 2049.3, -987.09, 44.79, 'Niemand', 'Wohnung', 2500000, 0, 0, 100, 0, 2050.6, -987.5, 44.7, 10.8, 5, 10),
(353, 2015.78, -978.33, 36.56, 'Niemand', 'Wohnung', 2500000, 0, 1, 50, 0, 2015, -979.2, 36.2, 207.5, 2, 10),
(354, 2023.18, -1053.18, 25.59, 'Niemand', 'Wohnung', 2500000, 0, 0, 300, 0, 2024, -1055.5, 24.6, 156.6, 2, 10),
(355, 2050.78, -1065.91, 25.78, 'Niemand', 'Wohnung', 2500000, 0, 0, 50, 0, 2049.3, -1067.3, 24.7, 148.8, 3, 10),
(356, 2082.37, -1085.31, 25.45, 'Niemand', 'Wohnung', 2500000, 0, 1, 50, 0, 2084, -1086, 25, 152.1, 3, 10),
(357, 2140.56, -1082.43, 25.03, 'Niemand', 'Wohnung', 2500000, 0, 0, 500, 0, 2141.1, -1083, 24.7, 162.6, 3, 10),
(358, 2108.78, -1082.06, 25.29, 'Niemand', 'Wohnung', 2500000, 0, 0, 100, 0, 2108.1, -1081.5, 25.2, 331.2, 3, 10),
(359, 2077.37, -1057, 31.29, 'Niemand', 'Wohnung', 410000, 0, 0, 350, 0, 2076.5, -1056, 31.1, 343.2, 2, 10),
(362, 745.51, -591.02, 18.01, 'Niemand', 'Landhaus', 5000000, 0, 0, 50, 0, 0, 0, 0, 0, 19, 10),
(363, 745.15, -556.53, 18.01, 'Niemand', 'Landhaus', 10000000, 0, 0, 1000, 0, 743.7, -556.4, 18, 357.7, 19, 10),
(364, 766.59, -556.65, 18.01, 'Niemand', 'Landhaus', 10000000, 0, 1, 100, 0, 765.5, -556.5, 18, 2.4, 19, 10),
(365, 768.26, -503.82, 18.01, 'Niemand', 'Landhaus', 10000000, 0, 1, 50, 0, 769.9, -504.1, 18, 178.6, 15, 10),
(366, 795.08, -506.23, 18.01, 'Niemand', 'Landhaus', 15000000, 0, 0, 50, 0, 0, 0, 0, 0, 19, 10),
(367, 818.28, -509.32, 18.01, 'Niemand', 'Landhaus', 10000000, 1, 1, 50, 0, 819.2, -509.2, 18, 173.1, 19, 1),
(368, 743.34, -509.57, 18.01, 'Niemand', 'Landwohnung', 10000000, 0, 0, 50, 0, 744.7, -509.2, 18, 173.3, 15, 10),
(369, 252.38, -121.3, 3.5, 'Niemand', 'Landhaus', 5000000, 0, 0, 50, 0, 252.6, -119.9, 3.5, 82.8, 15, 10),
(370, 252.66, -92.44, 3.5, 'Niemand', 'Landhaus', 25000000, 0, 0, 500, 0, 252.6, -93.5, 3.5, 100, 17, 10),
(371, 312.98, -121.29, 3.5, 'Sanes322', 'Landhaus', 1000000, 0, 0, 100, 0, 312.7, -118.9, 3.5, 265.7, 19, 10),
(372, 313.22, -92.48, 3.5, 'Niemand', 'Landhaus', 2500000, 0, 0, 200, 0, 312.7, -94.3, 3.5, 273, 19, 10),
(373, 294.75, -54.7, 2.75, 'Niemand', 'Landwohnung', 2500000, 0, 1, 50, 0, 293.2, -53.7, 2, 157, 20, 10),
(375, 207.66, -62.31, 1.75, 'Niemand', 'Landwohnung', 5000000, 0, 0, 500, 0, 0, 0, 0, 0, 19, 10),
(466, 2513.6, -1650.4, 14.35, 'Niemand', 'Wohnung ', 5000000, 0, 0, 250, 0, 2514, -1651.3, 14.3, 133.5, 3, 10),
(470, 2452, -1641.78, 13.72, 'Niemand', 'Wohnung ', 5000000, 0, 0, 100, 0, 2453.1, -1642, 13.6, 158.6, 3, 10),
(476, 841.15, -1471.56, 14.18, 'bugga', '2 stöckiges Haus', 8000000, 0, 0, 50, 100, 842.2, -1471.8, 14.1, 161.5, 17, 10),
(477, 1094.39, -806.71, 107.41, 'Niemand', 'UFO361 - Villa', 80000000, 0, 0, 800, 0, 1093.3, -806.7, 107.4, 3.9, 11, 10),
(478, 867.84, -717.03, 105.68, 'Niemand', 'Vinewood Haus', 15000000, 0, 1, 5000, 0, 866.7, -716.2, 105.5, 311.7, 19, 10),
(479, 848.76, -745.4, 94.94, 'Niemand', 'Vinewood Haus', 15000000, 0, 0, 700, 0, 848, -744.2, 94.9, 305.7, 19, 10),
(480, 897.53, -677.65, 116.87, 'Niemand', 'Vinewood Haus', 25000000, 0, 0, 500, 0, 898.5, -676.7, 116.8, 194.3, 15, 10),
(481, 946.28, -710.45, 122.62, 'Niemand', 'Vinewoodhaus', 20000000, 0, 0, 550, 0, 945.2, -710.7, 122.5, 15.5, 20, 10),
(482, 980.45, -677.14, 121.97, 'GibMir500', 'Luxus Villa', 1000000, 0, 0, 50, 0, 978.9, -677.7, 121.9, 18.6, 4, 10),
(483, 1045.31, -642.65, 120.11, 'Niemand', 'Vinewood Villa', 50000000, 0, 0, 3600, 0, 1043.5, -642.2, 120, 343.7, 18, 10),
(484, 1095.04, -647.34, 113.62, 'Izaiah.Brantley', 'Villa de la Lux', 1000000, 1, 0, 5000, 1000, 1093.5, -646.9, 113.5, 338.7, 4, 1),
(521, 2363.77, 187.16, 28.44, 'Niemand', 'Landhaus', 1700000, 0, 0, 250, 0, 2361.3, 185.8, 27.7, 113.5, 15, 10),
(522, 2324.11, 191.02, 28.44, 'Niemand', 'Landhaus', 1700000, 0, 1, 160, 0, 2326.6, 189.3, 27.7, 304.2, 20, 10),
(523, 2364, 166.13, 28.44, 'Niemand', 'Landhaus', 1800000, 0, 0, 300, 0, 2360.5, 165.1, 27.6, 95.3, 15, 10),
(524, 2323.87, 162.3, 28.44, 'Niemand', 'Landhaus', 1500000, 0, 0, 50, 0, 2327.1, 163.3, 27.6, 268.7, 16, 10),
(525, 2363.87, 142.02, 28.44, 'Niemand', 'Landhaus', 1600000, 0, 1, 350, 0, 2360.6, 140.3, 27.6, 62.2, 20, 10),
(526, 2323.85, 136.24, 28.44, 'Niemand', 'Landhaus', 1600000, 0, 0, 50, 0, 2324, 137.6, 28.2, 254.5, 15, 10),
(527, 2364, 116.18, 28.44, 'Niemand', 'Landhaus', 1500000, 0, 0, 2500, 0, 2363.8, 114.5, 28.2, 70, 7, 10),
(528, 2323.85, 116.08, 28.44, 'Niemand', 'Landhaus', 1600000, 0, 0, 750, 0, 2324.1, 115, 28.2, 296, 20, 10),
(529, 2556.27, 26.35, 27.67, 'Niemand', 'Landhaus', 1300000, 0, 1, 50, 0, 2554.6, 27.2, 26.7, 0.6, 16, 10),
(530, 2511.62, 57.15, 27.68, 'Niemand', 'Landhaus', 1280000, 0, 0, 50, 0, 2512.8, 56.5, 26.7, 203.8, 16, 10),
(531, 2551.12, 57.25, 27.67, 'Niemand', 'Landhaus', 1280000, 0, 1, 50, 0, 2550.8, 58.5, 27.6, 113.3, 3, 10),
(532, 2556.86, 88, 27.67, 'Niemand', 'Landhaus', 1280000, 0, 0, 100, 0, 2555.5, 86.5, 26.7, 81.5, 15, 10),
(534, 2518.37, 128.97, 27.67, 'Niemand', 'Landhaus', 1700000, 0, 0, 150, 0, 2517, 128.6, 27.6, 223.6, 20, 10),
(535, 2480.57, 126.72, 27.67, 'Niemand', 'Landhaus', 1500000, 0, 0, 100, 0, 2481.6, 124.5, 26.7, 185.6, 20, 10),
(536, 2443.85, 92.23, 28.44, 'Niemand', 'Landhaus', 1400000, 0, 0, 500, 0, 2446.6, 93.5, 27.7, 256.7, 20, 10),
(537, 2446.62, 18.94, 27.68, 'Niemand', 'Landhaus', 1900000, 0, 1, 50, 0, 2448.1, 17.5, 27.2, 233.3, 20, 10),
(542, 2200.54, -37.52, 28.12, 'Niemand', 'Landhaus', 2000000, 0, 0, 500, 0, 1470.56, -1684.93, 14, 20.5, 15, 10),
(545, 2519.04, -1113.31, 56.59, 'Niemand', 'Wohnung', 900000, 0, 0, 50, 0, 0, 0, 0, 0, 2, 10),
(551, 2517.86, -965.4, 82.3, 'Niemand', 'Wohnung', 900000, 0, 1, 50, 0, 0, 0, 0, 0, 3, 10),
(552, 2492.1, -965.71, 82.54, 'Niemand', 'Wohnung', 800000, 0, 0, 50, 100, 0, 0, 0, 0, 3, 10),
(555, 2459.37, -947.7, 80.08, 'Niemand', 'Wohnung', 850000, 0, 0, 150, 0, 0, 0, 0, 0, 3, 10),
(558, 1378.93, -1753.06, 14.14, 'Niemand', 'Stadtwohnung', 40000000, 0, 0, 1300, 0, 0, 0, 0, 0, 19, 10),
(559, 1024.06, -982.4, 42.63, 'tazsuyo.nichio', 'Stadtwohnhaus', 1000000, 1, 0, 1000, 1000, 0, 0, 0, 0, 14, 10),
(579, -392.26, -1439.06, 26.29, 'Niemand', 'Landhaus', 1500000, 0, 1, 1500, 0, 0, 0, 0, 0, 15, 10),
(582, 924, -853.4, 93.44, 'Niemand', 'Vinewood Haus', 5500000, 0, 0, 501, 0, 0, 0, 0, 0, 20, 10),
(590, 794.94, -1692, 14.46, 'Niemand', 'Stadtwohnung', 480000, 0, 0, 50, 0, 0, 0, 0, 0, 19, 10),
(591, 2398.37, 111.29, 28.44, 'Niemand', 'Landhaus', 750000, 0, 0, 50, 0, 0, 0, 0, 0, 5, 10),
(592, -382.82, -1042.56, 58.9, 'Niemand', 'Landwohnung', 150000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 10),
(593, -347.94, -1046.29, 59.81, 'Niemand', 'Landwohnung', 200000, 1, 0, 500, 0, 0, 0, 0, 0, 5, 1),
(594, 683.53, -1435.43, 14.85, 'Niemand', 'Stadtwohnung', 3000000, 0, 0, 1500, 0, 0, 0, 0, 0, 20, 10),
(595, 662.4, -1440.41, 14.85, 'Niemand', 'Stadtwohnung', 3000000, 0, 0, 500, 0, 0, 0, 0, 0, 20, 10),
(597, 685.46, -1421.91, 14.77, 'Niemand', 'Stadtwohnung', 1000000, 0, 0, 50, 0, 0, 0, 0, 0, 20, 10),
(599, 662.4, -1466.68, 14.85, 'Niemand', 'Stadtwohnung', 3000000, 0, 1, 100, 0, 0, 0, 0, 0, 20, 10),
(601, 662.4, -1487.52, 14.85, 'Niemand', 'Stadtwohnung', 3000000, 1, 0, 200, 0, 0, 0, 0, 0, 20, 5),
(602, 662.4, -1513.89, 14.85, 'Niemand', 'Stadtwohnung', 3000000, 0, 0, 100, 0, 0, 0, 0, 0, 20, 10),
(603, 662.4, -1534.68, 14.85, 'Niemand', 'Stadtwohnung', 3000000, 0, 0, 100, 0, 0, 0, 0, 0, 20, 10),
(604, 558.21, -1076.02, 72.91, 'Niemand', 'Vinewood Haus', 30000000, 0, 0, 1500, 0, 0, 0, 0, 0, 4, 10),
(605, 497.45, -1095.05, 82.33, 'Niemand', 'Vinewood Haus', 20000000, 0, 0, 3500, 0, 0, 0, 0, 0, 15, 10),
(606, 2238.12, -1906.81, 14.93, 'Niemand', 'Haus', 1500000, 0, 1, 50, 0, 0, 0, 0, 0, 7, 10),
(615, 891.21, -783.13, 101.3, 'Niemand', 'Vinewood Haus', 15000000, 0, 0, 1000, 0, 0, 0, 0, 0, 18, 10),
(617, 977.53, -771.71, 112.19, 'Niemand', 'Vinewood Haus', 20000000, 0, 0, 50, 0, 0, 0, 0, 0, 19, 10),
(620, 808.9, -759.33, 76.51, 'Niemand', 'Vinewood Haus', 20000000, 0, 0, 950, 0, 0, 0, 0, 0, 19, 10),
(623, 858.69, -828.44, 89.5, 'Niemand', 'Vinewood Haus', 15000000, 0, 0, 50, 0, 0, 0, 0, 0, 4, 10),
(673, 2756.37, -1182.56, 69.4, 'Niemand', 'Stadthaus', 15000000, 0, 0, 100, 0, 2756.87, -1181.56, 69.37, 44.29, 20, 10),
(731, 1016.78, -762.71, 112.55, 'Niemand', 'Vinewood Haus', 12000000, 0, 0, 200, 0, 0, 0, 0, 0, 4, 10),
(732, 565.33, -1112.31, 62.79, 'Niemand', 'Vinnwood Haus', 15000000, 0, 0, 1500, 0, 0, 0, 0, 0, 13, 10),
(734, 161.6, -1456.02, 32.84, 'Niemand', 'Vinwood Haus', 15000000, 0, 1, 50, 0, 0, 0, 0, 0, 14, 10),
(737, 1654.05, -1656.26, 22.51, 'dape.', 'LS Luxusanwesen', 1000000, 1, 0, 100, 0, 0, 0, 0, 0, 12, 10),
(741, 725.28, -1450.31, 17.69, 'Niemand', 'Penthouse', 10000000, 0, 0, 100, 0, 0, 0, 0, 0, 11, 10),
(743, 1699.31, -1667.89, 20.19, 'Niemand', 'Haus', 50000000, 0, 0, 150, 0, 0, 0, 0, 0, 14, 10),
(745, 300.54, -1609.68, 33.09, 'Niemand', 'Villa am Stadtrand', 75000000, 1, 0, 100, 0, 0, 0, 0, 0, 12, 2),
(746, 1274.81, -1663.18, 19.7, 'Niemand', 'Apartment', 10000000, 0, 0, 50, 0, 0, 0, 0, 0, 17, 10),
(747, 1270.68, -1667.93, 19.7, 'Niemand', 'Apartment', 10000000, 0, 0, 50, 350, 0, 0, 0, 0, 17, 10),
(748, 1965.43, 1623.18, 12.85, 'Niemand', 'Piraten - Villa', 100000000, 0, 0, 50, 0, 0, 0, 0, 0, 4, 10),
(749, 1456.68, 2773.37, 10.81, 'Niemand', 'Golfvilla', 150000000, 1, 0, 7500, 0, 0, 0, 0, 0, 12, 3),
(750, 2238.12, 1285.68, 10.81, 'Niemand', 'Pyramiden - Villa', 125000000, 1, 0, 2500, 0, 0, 0, 0, 0, 12, 5),
(751, 2560.78, 1561.68, 10.81, 'Niemand', 'Luxus - Villa', 40000000, 0, 0, 700, 0, 0, 0, 0, 0, 11, 10),
(752, 2481.55, 1525.66, 11.71, 'Niemand', 'Luxus - Villa', 50000000, 0, 0, 100, 0, 0, 0, 0, 0, 20, 0),
(755, -2661.09, 876.9, 79.76, 'Niemand', 'Paradiso - Villa', 40000000, 0, 0, 100, 0, 0, 0, 0, 0, 4, 10),
(756, -2706.59, 864.84, 70.69, 'Niemand', 'Paradiso - Villa', 20000000, 0, 0, 100, 0, 0, 0, 0, 0, 18, 10),
(757, -2641.01, 935.28, 71.94, 'Niemand', 'Paradiso - Villa', 25000000, 0, 0, 100, 0, 0, 0, 0, 0, 11, 0),
(758, -2657.37, 849.21, 64, 'Niemand', 'Paradiso - Villa', 20000000, 0, 0, 100, 0, 0, 0, 0, 0, 11, 0),
(759, -2721.12, 923.9, 67.58, 'Niemand', 'Paradiso - Villa', 30000000, 0, 0, 100, 0, 0, 0, 0, 0, 11, 0),
(760, -2710.76, 968.07, 54.45, 'Niemand', 'Paradiso - Villa', 30000000, 0, 0, 100, 0, 0, 0, 0, 0, 19, 0),
(761, -2655.29, 986.03, 64.98, 'Niemand', 'Paradiso - Villa', 30000000, 0, 0, 100, 0, 0, 0, 0, 0, 11, 0),
(762, 2236.59, 167.61, 28.12, 'Niemand', 'Landhaus', 15000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 10),
(763, 2454.85, -964.83, 80.05, 'Niemand', 'Holz - Hütte', 1000000, 0, 0, 100, 0, 0, 0, 0, 0, 3, 10),
(765, 2522.86, -1679.43, 15.47, 'Niemand', 'Sweets - Haus', 30000000, 0, 0, 200, 0, 0, 0, 0, 0, 6, 10),
(766, 2486.59, -1645.06, 14.06, 'Niemand', 'Wohnung', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 2, 10),
(767, 2362.76, -1643.93, 13.52, 'Niemand', 'Wohnung', 2000000, 0, 1, 300, 0, 0, 0, 0, 0, 2, 10),
(768, 2384.62, -1674.93, 14.71, 'Niemand', 'Wohnung', 2000000, 0, 1, 100, 0, 0, 0, 0, 0, 2, 10),
(769, 2408.87, -1674.17, 13.6, 'Niemand', 'Wohnung', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 2, 0),
(770, 2413.77, -1647.04, 14.01, 'Niemand', 'Wohnung', 2000000, 0, 0, 1000, 0, 0, 0, 0, 0, 2, 10),
(771, 1111.43, -975.84, 42.75, 'Niemand', 'Antikes Blechhaus', 25000000, 0, 0, 300, 0, 0, 0, 0, 0, 18, 10),
(772, 857.25, -978.9, 37.18, 'Niemand', 'Blech Haus', 10000000, 0, 1, 500, 0, 0, 0, 0, 0, 3, 10),
(773, 705.59, 291.35, 20.42, 'Niemand', 'Heruntergekommenes Haus', 500000, 0, 0, 5000, 0, 0, 0, 0, 0, 10, 10),
(774, 718.46, 300.54, 20.2, 'Niemand', 'Heruntergekommenes Haus', 500000, 0, 0, 50, 0, 0, 0, 0, 0, 13, 10),
(775, 748.03, 257.35, 27.04, 'Niemand', 'Heruntergekommenes Haus', 500000, 0, 1, 100, 0, 0, 0, 0, 0, 13, 10),
(776, 747.75, 278.25, 27.2, 'Niemand', 'Heruntergekommenes Haus', 500000, 0, 0, 5000, 0, 0, 0, 0, 0, 13, 10),
(777, 746.71, 305.16, 20.2, 'Niemand', 'Heruntergekommenes Haus', 500000, 0, 0, 50, 0, 0, 0, 0, 0, 13, 10),
(778, -2477.12, 1244.38, 33.59, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 15, 0),
(779, -2477.87, 1264.16, 28.25, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(780, -2476.87, 1274.05, 25.29, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(781, -2477.12, 1281.43, 23.7, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 19, 0),
(782, -2477.87, 1301.05, 18.37, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(783, -2476.87, 1310.93, 15.39, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0),
(784, -2477.12, 1318.31, 13.85, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 19, 0),
(785, -2477.87, 1338.06, 8.5, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0),
(786, -2433.07, 1338.18, 8.5, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(787, -2433.75, 1318.43, 13.85, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(788, -2434.01, 1311.06, 15.39, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 2, 10),
(789, -2433.08, 1301.14, 18.37, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(790, -2433.62, 1281.31, 23.7, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 19, 0),
(791, -2433.87, 1274.27, 25.29, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(792, -2433.03, 1264.06, 28.25, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0);
INSERT INTO `houses` (`ID`, `EnterX`, `EnterY`, `EnterZ`, `Besitzer`, `Name`, `Preis`, `Mieten`, `Lock`, `MietPreis`, `Kasse`, `SellX`, `SellY`, `SellZ`, `SellRot`, `HouseInteriorID`, `MieterMax`) VALUES
(793, -2433.62, 1244.31, 33.61, 'Niemand', 'Stadthaus am Meer', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0),
(794, -2905.03, 1178.81, 13.64, 'Niemand', 'Stadthaus mit Meeresblick', 4000000, 0, 0, 100, 0, 0, 0, 0, 0, 15, 10),
(795, -2619.37, 67.87, 4.57, 'Niemand', 'Luxus Villa', 6000000, 0, 0, 100, 0, 0, 0, 0, 0, 4, 0),
(796, -1691.93, 1367.66, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(797, -1706.43, 1353, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 10),
(798, -1681.18, 1350.05, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(799, -1666.54, 1360.93, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(800, -1659.28, 1368.18, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(801, -1650.17, 1377.52, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(802, -1642.93, 1384.93, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(803, -1635.76, 1392.31, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 10),
(804, -1654.93, 1411.76, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 1, 0, 100, 0, 0, 0, 0, 0, 7, 10),
(805, -1663.93, 1406.03, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(806, -1667.75, 1398.68, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(807, -1669.68, 1393.06, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(808, -1675.38, 1376.81, 7.17, 'Niemand', 'Stadthaus am Pier', 5000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(809, 2249.12, 111.61, 28.44, 'Niemand', 'Mittel Haus', 2000000, 0, 1, 10000, 0, 0, 0, 0, 0, 5, 10),
(810, -2904.87, 1164.92, 13.64, 'Niemand', 'Stadthaus mit Meeresblick', 4000000, 0, 0, 50, 0, 0, 0, 0, 0, 5, 10),
(811, 2269.53, 111.37, 28.44, 'Niemand', 'Klein Haus', 2000000, 0, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(812, -314.48, 1774.81, 43.63, 'Niemand', 'Luxus Ferienhaus', 100000000, 0, 0, 100, 0, 0, 0, 0, 0, 4, 10),
(813, -2523.87, 2238.82, 5.38, 'Niemand', 'Haus am Meer', 20000000, 0, 0, 50, 0, 0, 0, 0, 0, 7, 10),
(814, -2552.1, 2266.37, 5.46, 'Niemand', 'Haus am Meer', 20000000, 1, 0, 500, 0, 0, 0, 0, 0, 14, 10),
(815, -369.82, 1169.43, 20.27, 'Niemand', 'Landhaus am Meer', 3500000, 0, 0, 500, 0, 0, 0, 0, 0, 19, 10),
(816, 2270.53, -7.48, 28.12, 'Niemand', 'Landhaus', 1800000, 0, 0, 750, 0, 0, 0, 0, 0, 5, 10),
(817, 2253.87, -1.62, 28.12, 'Niemand', 'Landhaus', 450000, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0),
(818, 2245.33, -1.62, 28.12, 'Niemand', 'Landhaus', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 2, 0),
(819, 2197.27, -60.61, 28.12, 'Niemand', 'Landhaus', 650000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 10),
(820, 2203.1, -89.48, 28.12, 'Niemand', 'Landhaus', 1700000, 0, 1, 100, 0, 0, 0, 0, 0, 5, 10),
(821, 2245.51, -122.26, 28.12, 'Niemand', 'Landhaus', 2000000, 0, 1, 100, 0, 0, 0, 0, 0, 7, 10),
(822, 2272.31, -119.12, 28.12, 'Niemand', 'Landhaus', 1900000, 0, 1, 100, 0, 0, 0, 0, 0, 5, 10),
(823, 2293.62, -124.94, 28.12, 'Niemand', 'Landhaus', 1700000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 10),
(824, 2313.87, -124.94, 28.12, 'Niemand', 'Landhaus', 1600000, 0, 0, 180, 0, 0, 0, 0, 0, 3, 10),
(825, 2322.28, -124.94, 28.12, 'Niemand', 'Landhaus', 1650000, 0, 1, 50, 0, 0, 0, 0, 0, 2, 10),
(826, 2367.3, -49.11, 28.12, 'Niemand', 'Landhaus', 2300000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(828, 2392.34, -54.93, 28.12, 'Niemand', 'Landhaus', 1600000, 0, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(829, 2415.37, -52.27, 28.12, 'Niemand', 'Landhaus', 2300000, 0, 0, 140, 0, 0, 0, 0, 0, 5, 10),
(830, 2438.62, -54.95, 28.12, 'Niemand', 'Landhaus', 1700000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 10),
(831, 2448.51, -11.02, 27.68, 'Niemand', 'Landhaus', 2700000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 10),
(832, 2484.5, -28.37, 28.44, 'Niemand', 'Landhaus', 1700000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(833, 2513.37, -28.37, 28.44, 'Niemand', 'Landhaus', 1650000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(834, 2488.12, 11.76, 28.44, 'Niemand', 'Landhaus', 1650000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 10),
(835, 2509.37, 11.75, 28.44, 'Niemand', 'Landhaus', 1650000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(836, 2551.12, -5.48, 27.67, 'Niemand', 'Landhaus', 2000000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0),
(838, 2443.27, 61.75, 28.44, 'Niemand', 'Landhaus', 1750000, 0, 0, 100, 0, 0, 0, 0, 0, 5, 10),
(839, 2413.61, 61.75, 28.44, 'Niemand', 'Landhaus', 1800000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(841, 327.92, -1512.16, 36.02, 'Niemand', 'Los Santos Stadtvilla', 150000000, 1, 0, 1000, 0, 0, 0, 0, 0, 4, 10),
(842, 797.46, -1729.42, 13.52, 'Niemand', 'Haus', 1200000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 0),
(843, 793.96, -1707.31, 14.02, 'Niemand', 'Haus', 1300000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 10),
(845, 950.52, -986.51, 38.79, 'Niemand', 'Stadtwohnung', 15000000, 0, 1, 50, 0, 0, 0, 0, 0, 2, 10),
(846, 769.21, -1745.81, 13.06, 'Niemand', 'Strandhaus', 1500000, 0, 0, 100, 0, 0, 0, 0, 0, 4, 10),
(847, 791.34, -1753.77, 13.43, 'Niemand', 'Mit Ausblick auf Straße', 2500000, 0, 1, 100, 0, 0, 0, 0, 0, 4, 10),
(849, 2060.87, -1075.56, 25.37, 'Niemand', 'Wohnung', 2300000, 0, 1, 100, 0, 0, 0, 0, 0, 5, 0),
(850, 1778.56, -1664.39, 14.43, 'Fleek', 'Großes Wohnkomplex', 1000000, 0, 0, 50, 0, 0, 0, 0, 0, 12, 5),
(852, 1317.28, -1184.06, 23.59, 'Niemand', 'Modernes Hochhaus', 30000000, 0, 0, 1000, 0, 0, 0, 0, 0, 11, 10),
(853, 2508.26, -1998.38, 13.89, 'Niemand', 'Wohnung', 1000000, 0, 0, 100, 0, 0, 0, 0, 0, 15, 10),
(854, 2486.26, -2021.55, 13.97, 'Niemand', 'Wohnung', 1000000, 0, 0, 350, 0, 0, 0, 0, 0, 15, 10),
(856, 2524.36, -1998.38, 14.1, 'Niemand', 'Wohnung', 1000000, 0, 0, 100, 0, 0, 0, 0, 0, 13, 0),
(860, 2522.37, -2018.68, 14.06, 'Niemand', 'Wohnung', 1000000, 1, 0, 100, 0, 0, 0, 0, 0, 13, 10),
(862, 1153.9, -1180.68, 32.81, 'Niemand', 'Hochhaus', 120000000, 0, 0, 1000, 0, 0, 0, 0, 0, 11, 10),
(864, 1308.54, -1468.18, 10.02, 'Niemand', 'Eventvilla', 10000000, 0, 0, 5000, 0, 0, 0, 0, 0, 18, 10),
(866, 985.69, -1094.38, 27.6, 'Niemand', 'Kleine Wohnung', 10000000, 0, 0, 100, 0, 0, 0, 0, 0, 7, 10),
(880, 2459.51, -1690.93, 13.52, 'Niemand', 'Ryders Haus', 10000000, 0, 0, 500, 0, 0, 0, 0, 0, 2, 10),
(884, 1497.06, -687.89, 95.55, 'steezo', 'Vinewood Villa', 1000000, 1, 0, 2500, 42550, 0, 0, 0, 0, 11, 1),
(889, 960.84, -1824.18, 13.31, 'Niemand', 'Luxus Strandhaus', 4800000, 0, 0, 50, 0, 0, 0, 0, 0, 4, 10),
(890, 1535.78, -885.28, 57.65, 'Niemand', 'Vinewood Villa', 15000000, 0, 1, 100, 0, 0, 0, 0, 0, 3, 0),
(892, 255.19, -1366.77, 53.09, 'Niemand', 'Vinewood-Villa', 50000000, 0, 1, 10000, 0, 0, 0, 0, 0, 18, 10),
(893, 2931.77, 2119.12, 18.37, 'Niemand', 'Bunker', 20000000, 0, 0, 100, 0, 0, 0, 0, 0, 2, 10),
(894, 2017.64, 1919.68, 12.34, 'Niemand', 'TheVisage', 150000000, 0, 0, 100, 0, 0, 0, 0, 0, 12, 0),
(895, 652.9, -1619.64, 15, 'Niemand', 'Bruchbude', 5000000, 0, 0, 50, 0, 0, 0, 0, 0, 7, 10),
(896, -2582.26, 2300.37, 7, 'Niemand', 'Bayside Haus', 25000000, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0),
(898, 870.09, -25.19, 63.97, 'Mirzet.Kirigaya ', 'Waldhütte', 1000000, 0, 0, 50, 0, 0, 0, 0, 0, 3, 10),
(907, -552.65, 2593.87, 53.93, 'Niemand', 'LV-Wüsten Villa', 100000000, 0, 0, 2500, 0, 0, 0, 0, 0, 12, 10),
(911, 1330.43, -985.78, 33.9, 'Niemand', 'LyD Tower', 150000000, 1, 0, 100, 0, 0, 0, 0, 0, 12, 3),
(915, 2225.87, 1837.79, 10.81, 'Niemand', 'Playboy Villa', 200000000, 1, 0, 100, 0, 0, 0, 0, 0, 11, 10),
(916, 1739.02, -1269.43, 13.52, 'Niemand', 'Thaddeus sein Apartment', 75000000, 1, 0, 5000, 0, 0, 0, 0, 0, 12, 10),
(917, 1734.43, -1265.31, 13.52, 'Niemand', 'Nachbar von Thaddeus', 75000000, 0, 0, 1000, 0, 0, 0, 0, 0, 17, 10),
(918, 836.28, -894.34, 68.76, 'Niemand', 'Vinewood Villa ', 50000000, 0, 1, 100, 0, 0, 0, 0, 0, 12, 10),
(920, 652.08, -1693.93, 14.56, 'Niemand', 'Moderne Wohnung', 1800000, 1, 0, 50, 0, 0, 0, 0, 0, 15, 0),
(922, 690.88, -1276, 13.56, 'Viper', 'Tennisvilla', 1000000, 0, 0, 100, -7500, 0, 0, 0, 0, 12, 0),
(926, -2719.85, -318.66, 7.84, 'akeno', 'Terravilla', 1000000, 0, 0, 100, 0, 0, 0, 0, 0, 19, 0);

-- --------------------------------------------------------


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `hwban`
--

CREATE TABLE `hwban` (
  `id` int(11) NOT NULL,
  `Name` varchar(128) NOT NULL,
  `Gebannt von` varchar(128) NOT NULL,
  `Grund` varchar(128) NOT NULL,
  `hwid` varchar(128) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `hwban`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `infotab`
--

CREATE TABLE `infotab` (
  `Info` varchar(64) NOT NULL,
  `Bestand` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `infotab`
--

INSERT INTO `infotab` (`Info`, `Bestand`) VALUES
('Lager', 1440),
('StaatsKasse', 6796617),
('SAMDKasse', 1847700),
('SANAKasse', 2081171),
('OAMTKasse', 2010000),
('GSKasse', 1990000),
('BALLASKasse', 1975000),
('SchulKasse', 500000),
('Yakuza', 47220000),
('Aztecas', 54395000),
('Cali Kartell', 2090000),
('Vagos', 2000000),
('Lotto', 95000),
('Hitman', 680000),
('BBikerZ', 3104000),
('Wheelmenk', 500000),
('TerrorK', 500000),
('OutlawzK', 2000000),
('ndgradethaK', 6766462),
('Samen1', 530),
('Samen2', 464),
('Samen3', 309),
('Samen4', 875),
('Samen5', 320),
('SW_WT', 82218),
('SW_WT_PREIS', 125),
('SW_SPC_PREIS', 1250),
('SW_DRG', 400),
('SW_DRG_PREIS', 1500),
('SW_SPC', 1500),
('SW_WCD', 0),
('SW_WCD_PREIS', 200);

-- --------------------------------------------------------


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `lob`
--

CREATE TABLE `lob` (
  `id` int(11) NOT NULL,
  `lobender` varchar(24) NOT NULL,
  `gelobter` varchar(24) NOT NULL,
  `datum` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `lob`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `news`
--

CREATE TABLE `news` (
  `id` int(11) NOT NULL,
  `time` timestamp NOT NULL DEFAULT current_timestamp(),
  `name` text NOT NULL,
  `content` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `news`
--

INSERT INTO `news` (`id`, `time`, `name`, `content`) VALUES
(22, '2013-03-20 10:43:02', 'Puma', '<font color=\"#0066CC\"><font color=\"#0066FF\"><b>Sehr geehrte Spieler und Spielerinnen,<br><br>von unserer User Control Panel aus können Sie ihre <font color=\"#FF0000\">persönlichen Statistiken</font> mitverfolgen.<br>Von der Funktion <font color=\"#FF0000\">\"Fraktion\"</font> die oben an der Button-Leiste zu sehen ist,<br>können Sie Mitglieder Ihrer <u>Fraktion</u> samt<u> Fraktionsrank</u> sehen.<br>Ihnen wurde in der Funktion <font color=\"#FF0000\">\"Signatur\"</font> die ebenfalls oben an der Button-Leiste zu sehen ist, eine <u>persönliche Signatur</u> eingerichtet, die Sie sehen und verwenden können.<br>Bei Fragen oder Problemen können Sie uns von&nbsp; unserer <font color=\"#FF0000\">\"Supportticket\"</font> Funktion kontaktieren, <br>wir werden dann schnellstmöglich mit Ihnen in Kontakt tretten.<br>Von der <font color=\"#FF0000\">\"Einstellungen\"</font>-Funktion können Sie auch Ihr<u> Passwort auf dem Server ändern</u>.<br>Bitte gleichen Sie bei der Funktion <font color=\"#FF0000\">\"Einstellungen\"</font> alle abgefragten Felder an!<br>Unter den <font color=\"#FF0000\">\"Server-Statistiken\"</font> die unten auf der Leiste abzurufen sind, werden Ihnen<u> alle Leader einer Fraktion</u> <br>so wie die <u>TOP-5</u> der <u>reichsten</u> und der <u>Level-höchsten</u> und <u>besondere Spieler</u> usw. aufgelistet!</b></font><br></font><font color=\"\\&quot;\\\\&quot;\\\\\\\\&quot;#00CCFF\\\\\\\\&quot;\\\\&quot;\\&quot;\"><br></font><b><font color=\"\\&quot;\\\\&quot;\\\\\\\\&quot;#0066FF\\\\\\\\&quot;\\\\&quot;\\&quot;\"><font color=\"\\&quot;\\\\&quot;\\\\\\\\&quot;#009900\\\\\\\\&quot;\\\\&quot;\\&quot;\"><i>Das Team wünscht Ihnen weiterhin viel Spaß!</i></font></font></b>');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `notizen`
--

CREATE TABLE `notizen` (
  `id` int(11) NOT NULL,
  `admin` text NOT NULL,
  `content` text NOT NULL,
  `status` int(1) NOT NULL DEFAULT 0
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `notizen`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `onlineplayers`
--

CREATE TABLE `onlineplayers` (
  `playername` varchar(24) NOT NULL,
  `id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `OnlineZeit`
--

CREATE TABLE `OnlineZeit` (
  `Name` varchar(20) NOT NULL,
  `MONTAG` int(11) DEFAULT NULL,
  `DIENSTAG` int(11) DEFAULT NULL,
  `MITTWOCH` int(11) DEFAULT NULL,
  `DONNERSTAG` int(11) DEFAULT NULL,
  `FREITAG` int(11) DEFAULT NULL,
  `SAMSTAG` int(11) DEFAULT NULL,
  `SONNTAG` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `OnlineZeit`
--


-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `playercar`
--

CREATE TABLE `playercar` (
  `id` int(11) NOT NULL,
  `owner` varchar(32) NOT NULL,
  `model` int(11) NOT NULL,
  `posX` float NOT NULL,
  `posY` float NOT NULL,
  `posZ` float NOT NULL,
  `rot` int(11) NOT NULL,
  `nitro` int(11) NOT NULL,
  `hyd` int(11) NOT NULL,
  `wheel` int(11) NOT NULL,
  `ausp` int(11) NOT NULL,
  `sideL` int(11) NOT NULL,
  `sideR` int(11) NOT NULL,
  `fb` int(11) NOT NULL,
  `rb` int(11) NOT NULL,
  `spoiler` int(11) NOT NULL,
  `roof` int(11) NOT NULL,
  `hood` int(11) NOT NULL,
  `vents` int(11) NOT NULL,
  `lamps` int(11) NOT NULL,
  `pj` int(11) NOT NULL,
  `c1` int(11) NOT NULL,
  `c2` int(11) NOT NULL,
  `preis` int(11) NOT NULL,
  `tank` int(11) NOT NULL,
  `state` int(11) NOT NULL,
  `neon1` int(11) NOT NULL,
  `neon2` int(11) NOT NULL,
  `specialtuned` int(11) NOT NULL,
  `numberplate` varchar(32) NOT NULL,
  `peilsender` int(11) NOT NULL,
  `distance` int(11) NOT NULL,
  `tuv` int(11) NOT NULL,
  `slot` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `playercar`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `rangeban`
--

CREATE TABLE `rangeban` (
  `ID` int(11) NOT NULL,
  `IPRange` varchar(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `reservierung`
--

CREATE TABLE `reservierung` (
  `reservierungid` int(11) NOT NULL,
  `timeslotid` int(11) NOT NULL,
  `spieler` varchar(30) NOT NULL,
  `erstellzeit` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `kurzbeschreibung` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `server_fvehicles`
--

CREATE TABLE `server_fvehicles` (
  `id` int(9) NOT NULL,
  `vehFraktion` int(2) NOT NULL,
  `modelid` int(3) NOT NULL,
  `vehPosX` float NOT NULL,
  `vehPosY` float NOT NULL,
  `vehPosZ` float NOT NULL,
  `vehPosA` float NOT NULL,
  `vehHealth` float NOT NULL,
  `vehColor1` float NOT NULL,
  `vehColor2` float NOT NULL,
  `vehPaintjob` int(5) NOT NULL,
  `vehSpoiler` int(5) NOT NULL,
  `vehHood` int(5) NOT NULL,
  `vehRoof` int(5) NOT NULL,
  `vehSideskirt` int(5) NOT NULL,
  `vehLamps` int(5) NOT NULL,
  `vehNitro` int(5) NOT NULL,
  `vehExhaust` int(5) NOT NULL,
  `vehWheels` int(5) NOT NULL,
  `vehStereo` int(5) NOT NULL,
  `vehHydraulics` int(5) NOT NULL,
  `vehFrontBumper` int(5) NOT NULL,
  `vehRearBumper` int(5) NOT NULL,
  `vehVentRight` int(5) NOT NULL,
  `vehVentLeft` int(5) NOT NULL,
  `vehPreis` int(9) NOT NULL,
  `vehNeonID` int(5) NOT NULL,
  `vehNumberPlate` varchar(32) NOT NULL,
  `vehFuel` float NOT NULL,
  `vehKMStand` float NOT NULL,
  `vehInterior` int(9) NOT NULL,
  `vehWorld` int(9) NOT NULL,
  `vehSiren` int(2) NOT NULL,
  `vehAbgeschleppt` int(11) NOT NULL,
  `vehAbgeschlepptVon` varchar(24) NOT NULL,
  `vehKaution` int(11) NOT NULL,
  `vehFahrgestell` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `server_rang`
--

CREATE TABLE `server_rang` (
  `fsID` int(11) NOT NULL,
  `RangName0` varchar(32) NOT NULL,
  `RangName1` varchar(32) NOT NULL,
  `RangName2` varchar(32) NOT NULL,
  `RangName3` varchar(32) NOT NULL,
  `RangName4` varchar(32) NOT NULL,
  `RangName5` varchar(32) NOT NULL,
  `RangName6` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `server_rang`
--

INSERT INTO `server_rang` (`fsID`, `RangName0`, `RangName1`, `RangName2`, `RangName3`, `RangName4`, `RangName5`, `RangName6`) VALUES
(1, 'Anwärter', 'Polizeikommissar', 'Polizeioberkommissar', 'Polizeihauptkommissar', 'Erster Polizeihauptkommissar', 'Stellv. Polizeidirektor', 'Leitender Polizeidirektor'),
(2, 'Trainee Unit', 'Agent', 'Special Agent', 'Elite Agent', 'Division Chief', 'Deputy Direktor', 'Direktor'),
(3, 'Praktikant', 'Arzthelfer', 'Arzt', 'Oberarzt', 'Hauptarzt', 'Stellv. Direktor', 'Direktor'),
(4, 'Praktikant', 'Zeitungsjunge', 'Reporter', 'Journalist', 'Manager', 'stellv. Chefredakteur', 'Chefredakteur'),
(5, 'Praktiant', 'Anwärter', 'Abschlepper', 'Kontrolleur', 'Ausbilder', 'Stellv Direktor', 'Direktor'),
(6, 'x Fool', 'x Runna', 'x Thug', 'x Executor', 'x Motherfucka', 'x Shot Calla', 'x Original Gangsta'),
(7, 'Wannabe', 'Knecht', 'Homie', 'Hustler', 'O.G', 'Underboss', 'Big Boss'),
(8, 'Praktikan', 'Azubi', 'Fahrlehrer', 'Dipl. Fahrlehrer', 'Ausbilder', 'Co-Leader', 'Leader'),
(9, 'Neuling', 'Secret Service', 'Secret Service Chief', 'Riechter', 'Minister', 'Vize-Präsident', 'Präsident'),
(10, 'Yurui', 'Arjukiou', 'Shatei', 'Kyodai', 'Shotoiumi', 'Saiko-Koman', 'Oyabun'),
(11, 'tankwart', 'tom', 'burkhard', 'gf leitung', 'tankwart', 'Kleiner Penis', 'Papaschlumpf'),
(12, 'Candidato', 'El Novato', 'Amigo', 'Compañero', 'Diputado', 'Mano derecha', 'Patrón'),
(13, 'Bot', 'Bot', 'Bot', 'Bot', 'Bot', 'Bot', 'Bot'),
(14, 'Bot', 'Bot', 'Bot', 'Bot', 'Bot', 'Bot', 'Direktor'),
(15, 'Terrorzwerk', 'Knecht', 'Farmer', 'Bot', 'Ausbilder', 'Vize-Präsident', 'Präsident'),
(16, '-', '0', '-', '-', '-', '-', '-'),
(17, '-', '0', '-', '-', '-', '-', '-'),
(18, 'Bot', 'Bot', 'Bot', 'Bot', 'Bot', 'Bot', 'Bot'),
(19, 'Neuling', 'Anwärter', 'Amokläufer', 'Taliban', 'Fanatiker', 'Staatsfeind', 'Staatsfeind Nr. 1'),
(20, 'Bambino', 'Picciotto', 'Soldado', 'Capo', 'Consigliere', 'Padrino', 'Don'),
(21, 'Noob', 'Cushouwa', 'Legende', 'Shibing', 'Guwen', 'Chongfén', 'Dragonhead'),
(22, 'Zollanwärter', 'Zollinspektor', 'Zolloberinspektor', 'Zollhauptwachtmeister', 'Zollamtsrat', 'Stellv. Zolldirektor', 'Zolldirektor'),
(23, '-', '0', '-', '-', '-', '-', '-');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `session`
--

CREATE TABLE `session` (
  `User` text NOT NULL,
  `SessionID` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `settings`
--

CREATE TABLE `settings` (
  `player` varchar(767) NOT NULL,
  `forum` text NOT NULL,
  `email` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `settings`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `staticbiz`
--

CREATE TABLE `staticbiz` (
  `sbizid` int(11) NOT NULL,
  `typ` int(11) NOT NULL,
  `waren` int(11) NOT NULL,
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `staticbiz`
--

INSERT INTO `staticbiz` (`sbizid`, `typ`, `waren`, `x`, `y`, `z`) VALUES
(1, 0, 539513, 2187.69, -2263.9, 13.4674),
(2, 0, 1006976, 2571.62, -2226.7, 13.355),
(3, 1, 50259190, -1034.62, -626.237, 32.0078),
(4, 1, 49472923, 2482.88, -2084.22, 13.5469);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `tanken`
--

CREATE TABLE `tanken` (
  `ID` int(11) NOT NULL,
  `EnterX` float NOT NULL,
  `EnterY` float NOT NULL,
  `EnterZ` float NOT NULL,
  `Besitzer` varchar(24) NOT NULL,
  `Name` varchar(32) NOT NULL,
  `FillCost` int(11) NOT NULL,
  `Kasse` int(11) NOT NULL,
  `Benzin` int(11) NOT NULL,
  `MaxBenzin` int(11) NOT NULL,
  `Preis` int(11) NOT NULL,
  `FillCostBenzin` int(11) NOT NULL,
  `FillCostSuper` int(11) NOT NULL,
  `FillCostDiesel` int(11) NOT NULL,
  `videoueberwachung` int(11) NOT NULL,
  `auto_notruf` int(11) NOT NULL,
  `erpresserfraktion` int(11) NOT NULL,
  `erpresserforderung` int(11) NOT NULL,
  `erpresserstate` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `tanken`
--

INSERT INTO `tanken` (`ID`, `EnterX`, `EnterY`, `EnterZ`, `Besitzer`, `Name`, `FillCost`, `Kasse`, `Benzin`, `MaxBenzin`, `Preis`, `FillCostBenzin`, `FillCostSuper`, `FillCostDiesel`, `videoueberwachung`, `auto_notruf`, `erpresserfraktion`, `erpresserforderung`, `erpresserstate`) VALUES
(60, 1797.18, -2434.87, 13.55, 'SERVER', 'Flughafen Tankstelle', 200, 30800, 3688, 5000, 11000000, 100, 100, 100, 0, 0, 0, 0, 0),
(58, 1596.28, 2198.62, 10.81, 'SERVER', 'Tankstelle Redsands West', 120, 0, 4582, 5000, 50000000, 100, 100, 250, 1, 1, 0, 0, 0),
(57, 611.9, 1695.06, 6.98, 'SERVER', 'Tankstelle Bone County', 120, 0, 3728, 5000, 50000000, 346, 400, 294, 1, 1, 0, 0, 0),
(56, -2023.81, 156.41, 28.79, 'SERVER', 'Tankstelle Doherty', 120, 2880, 3552, 5000, 50000000, 400, 400, 400, 0, 0, 0, 0, 0),
(55, -1670.28, 408.26, 7.17, 'SERVER', 'Tankstelle Easter Basin', 120, 0, 4167, 5000, 50000000, 400, 400, 400, 0, 0, 0, 0, 0),
(53, 1944.75, -1772.68, 13.39, 'SERVER', 'Alhambra Tankstelle', 200, 134160, 4871, 5000, 120000000, 400, 400, 400, 0, 0, 0, 0, 0),
(52, 653.28, -569.71, 16.29, 'SERVER', 'Tankstelle Dillimore', 200, 49500, 1974, 5000, 50000000, 1250, 1250, 750, 0, 0, 0, 0, 0),
(111, 1004.2, -939.4, 42.15, 'SERVER', 'Tankstelle am BSN', 200, 116000, 4665, 5000, 5000, 500, 500, 500, 0, 0, 0, 0, 0),
(68, -1605.76, -2714.31, 48.52, 'SERVER', 'Tankstelle Angel Pine Highway', 200, 0, 4546, 5000, 3500000, 100, 100, 100, 1, 1, 0, 0, 0),
(69, -2244.01, -2560.81, 31.92, 'SERVER', 'Tankstelle Angel Pine', 120, 0, 4653, 5000, 3000000, 400, 400, 400, 1, 1, 0, 0, 0),
(70, 2206.09, 2474.87, 10.81, 'SERVER', 'Tankstelle Emerald Isle', 120, 800, 4678, 5000, 50000000, 100, 100, 100, 0, 0, 0, 0, 0),
(106, 2145.1, 2748.57, 10.81, 'SERVER', 'LV Nord Tanke', 120, 0, 5000, 5000, 2000000, 100, 100, 100, 1, 1, 0, 0, 0),
(107, 1380.93, 457.38, 19.93, 'SERVER', 'LS - Tankstelle Montgomery', 187, 320, 4630, 5000, 50000000, 100, 100, 100, 0, 0, 0, 0, 0),
(108, 2114.87, 920.4, 10.81, 'SERVER', 'Tankstelle LV Süd', 120, 20000, 3624, 5000, 3500000, 500, 1000, 750, 1, 1, 0, 0, 0),
(110, 1471.02, -1611.14, 13.31, 'SERVER', 'Tankstelle an der Stadthalle', 120, 267740, 4259, 5000, 1000000, 250, 300, 200, 0, 0, 11, 30000, 0),
(112, -91.62, -1170.4, 2.4, 'SERVER', 'Route 89 Tankstelle', 50, 7000, 0, 1000, 120000000, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `teamspeak`
--

CREATE TABLE `teamspeak` (
  `Name` varchar(24) NOT NULL,
  `UID` varchar(28) NOT NULL,
  `lastSeen` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Daten für Tabelle `teamspeak`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `ticket`
--

CREATE TABLE `ticket` (
  `id` int(11) NOT NULL,
  `player` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `summary` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `status` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `ticket`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `ticketantwort`
--

CREATE TABLE `ticketantwort` (
  `id` int(11) NOT NULL,
  `ticketid` int(11) DEFAULT NULL,
  `author` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `content` longtext CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `time` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `ticketantwort`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `timeslot`
--

CREATE TABLE `timeslot` (
  `timeslotid` int(11) NOT NULL,
  `datum` date NOT NULL,
  `start` time NOT NULL,
  `ende` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `waffenlager`
--

CREATE TABLE `waffenlager` (
  `id` int(11) NOT NULL,
  `fraktion` int(11) NOT NULL,
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `waffenteile` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `waffenlager`
--

INSERT INTO `waffenlager` (`id`, `fraktion`, `x`, `y`, `z`, `waffenteile`) VALUES
(1, 7, 331.939, 1119.71, 1083.89, 24070),
(2, 6, 2491.1, -1699.94, 1014.74, 7905940),
(3, 10, 2246.1, 1698.02, 1008.36, 6308020),
(4, 11, 506.054, -81.1208, 998.961, 46370),
(5, 12, -779.525, 496.663, 1371.75, 0),
(6, 13, 2809.74, -1171.9, 1025.57, 0),
(7, 20, -2165.14, 644.117, 1052.38, 479440),
(8, 21, 771.309, -39.3888, 1000.69, 1584550),
(9, 14, 309.975, 309.38, 1003.3, 0),
(10, 15, 744.872, 377.591, 948.536, 3983065),
(11, 17, 938.826, 1737.87, 8.8516, 0),
(12, 19, 976.088, 2058.29, 10.8203, 0),
(13, 14, 310.113, 309.268, 1003.3, 0);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `werbetafel`
--

CREATE TABLE `werbetafel` (
  `ID` int(11) NOT NULL,
  `IconX` float NOT NULL,
  `IconY` float NOT NULL,
  `IconZ` float NOT NULL,
  `ModelID` int(11) NOT NULL,
  `ObjectX` float NOT NULL,
  `ObjectY` float NOT NULL,
  `ObjectZ` float NOT NULL,
  `RotX` float NOT NULL,
  `RotY` float NOT NULL,
  `RotZ` float NOT NULL,
  `Text` varchar(128) NOT NULL,
  `MaterialIndex` int(11) NOT NULL,
  `MaterialSize` int(11) NOT NULL,
  `FontFace` varchar(24) NOT NULL,
  `FontSize` int(11) NOT NULL,
  `Bold` int(11) NOT NULL,
  `FontColor` int(11) NOT NULL,
  `BackColor` int(11) NOT NULL,
  `TextAlignment` int(11) NOT NULL,
  `UnixTimestamp` int(11) NOT NULL,
  `Besitzer` varchar(24) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `werbetafel`
--

INSERT INTO `werbetafel` (`ID`, `IconX`, `IconY`, `IconZ`, `ModelID`, `ObjectX`, `ObjectY`, `ObjectZ`, `RotX`, `RotY`, `RotZ`, `Text`, `MaterialIndex`, `MaterialSize`, `FontFace`, `FontSize`, `Bold`, `FontColor`, `BackColor`, `TextAlignment`, `UnixTimestamp`, `Besitzer`) VALUES
(3, 1332.68, -1389.68, 13.6, 9314, 1333.68, -1387.18, 14.43, 0, 0, 302.42, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(4, 1852.18, -1046.67, 24.04, 4729, 1850.53, -1050.75, 34.88, 0, 0, 0, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(5, 1754.77, -1480.31, 13.52, 4729, 1751.4, -1483.8, 30.12, 0, 0, -30.25, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(6, 1028.51, -1713.06, 13.52, 4729, 1027.56, -1708.55, 31.62, 0, 0, 19.95, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(8, 1467.31, -1291.18, 13.6, 9314, 1465.56, -1287.53, 14.25, 0, 0, 220, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(10, 693.28, -1003.71, 52.13, 9314, 692.78, -1007.07, 52.97, 0, 0, 14.81, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(11, 78.44, -1512.5, 4.03, 9314, 75.19, -1515.51, 5.26, 0, 0, -33.18, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(12, 608.71, -1717.81, 13.93, 9314, 611.59, -1714.92, 14.81, 2.25, 0, -59.34, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(13, 1641.68, 242.11, 30.09, 9314, 1644.55, 243.02, 30.95, 0, 0, 74.93, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand'),
(14, 1821.28, 862.96, 10.68, 4729, 1819.31, 863.15, 23.12, 0, 0, 252.02, '{FF9900}Werbetafel zu vermieten\n\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}$40.000', 0, 130, 'Verdana', 38, 1, -1, -16777216, 1, 0, 'Niemand');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `whitelist`
--

CREATE TABLE `whitelist` (
  `ID` int(11) NOT NULL,
  `name` varchar(24) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `akte`
--
ALTER TABLE `akte`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `angel`
--
ALTER TABLE `angel`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `benachrichtigung`
--
ALTER TABLE `benachrichtigung`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `beschwerde`
--
ALTER TABLE `beschwerde`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `beschwerdeantwort`
--
ALTER TABLE `beschwerdeantwort`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `bizes`
--
ALTER TABLE `bizes`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `bizes_backup`
--
ALTER TABLE `bizes_backup`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `blacklist`
--
ALTER TABLE `blacklist`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `cp_buy`
--
ALTER TABLE `cp_buy`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `cp_orders`
--
ALTER TABLE `cp_orders`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `cp_sessions`
--
ALTER TABLE `cp_sessions`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `sID` (`sID`,`userID`);

--
-- Indizes für die Tabelle `cp_users`
--
ALTER TABLE `cp_users`
  ADD PRIMARY KEY (`userID`),
  ADD UNIQUE KEY `userName` (`userName`);

--
-- Indizes für die Tabelle `firma`
--
ALTER TABLE `firma`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`);

--
-- Indizes für die Tabelle `frakblacklist`
--
ALTER TABLE `frakblacklist`
  ADD PRIMARY KEY (`name`);

--
-- Indizes für die Tabelle `frakcars`
--
ALTER TABLE `frakcars`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `fraktionen`
--
ALTER TABLE `fraktionen`
  ADD PRIMARY KEY (`fraktionsid`);

--
-- Indizes für die Tabelle `friendlist`
--
ALTER TABLE `friendlist`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `gangfight`
--
ALTER TABLE `gangfight`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `gutschein`
--
ALTER TABLE `gutschein`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `code` (`code`);

--
-- Indizes für die Tabelle `hausmoebel`
--
ALTER TABLE `hausmoebel`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `hotel`
--
ALTER TABLE `hotel`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `houseinterior`
--
ALTER TABLE `houseinterior`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `houses`
--
ALTER TABLE `houses`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`);

--
-- Indizes für die Tabelle `houses_bakcup`
--
ALTER TABLE `houses_bakcup`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`);

--
-- Indizes für die Tabelle `hwban`
--
ALTER TABLE `hwban`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `infotab`
--
ALTER TABLE `infotab`
  ADD PRIMARY KEY (`Info`);

--
-- Indizes für die Tabelle `infotab_backup`
--
ALTER TABLE `infotab_backup`
  ADD PRIMARY KEY (`Info`);

--
-- Indizes für die Tabelle `lob`
--
ALTER TABLE `lob`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id` (`id`);

--
-- Indizes für die Tabelle `news`
--
ALTER TABLE `news`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `onlineplayers`
--
ALTER TABLE `onlineplayers`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `OnlineZeit`
--
ALTER TABLE `OnlineZeit`
  ADD PRIMARY KEY (`Name`);

--
-- Indizes für die Tabelle `playercar`
--
ALTER TABLE `playercar`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `playercar_backup`
--
ALTER TABLE `playercar_backup`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `playercar_backup2`
--
ALTER TABLE `playercar_backup2`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `rangeban`
--
ALTER TABLE `rangeban`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `reservierung`
--
ALTER TABLE `reservierung`
  ADD PRIMARY KEY (`reservierungid`),
  ADD UNIQUE KEY `timeslotreservierungid` (`reservierungid`);

--
-- Indizes für die Tabelle `server_fvehicles`
--
ALTER TABLE `server_fvehicles`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `server_rang`
--
ALTER TABLE `server_rang`
  ADD PRIMARY KEY (`fsID`);

--
-- Indizes für die Tabelle `settings`
--
ALTER TABLE `settings`
  ADD PRIMARY KEY (`player`);

--
-- Indizes für die Tabelle `staticbiz`
--
ALTER TABLE `staticbiz`
  ADD PRIMARY KEY (`sbizid`),
  ADD UNIQUE KEY `sbizid` (`sbizid`);

--
-- Indizes für die Tabelle `tanken`
--
ALTER TABLE `tanken`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `teamspeak`
--
ALTER TABLE `teamspeak`
  ADD UNIQUE KEY `UID` (`UID`),
  ADD KEY `UID_2` (`UID`);

--
-- Indizes für die Tabelle `ticket`
--
ALTER TABLE `ticket`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `ticketantwort`
--
ALTER TABLE `ticketantwort`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `timeslot`
--
ALTER TABLE `timeslot`
  ADD PRIMARY KEY (`timeslotid`),
  ADD UNIQUE KEY `timeslotid` (`timeslotid`);

--
-- Indizes für die Tabelle `waffenlager`
--
ALTER TABLE `waffenlager`
  ADD PRIMARY KEY (`id`);

--
-- Indizes für die Tabelle `werbetafel`
--
ALTER TABLE `werbetafel`
  ADD PRIMARY KEY (`ID`);

--
-- Indizes für die Tabelle `whitelist`
--
ALTER TABLE `whitelist`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT für exportierte Tabellen
--

--
-- AUTO_INCREMENT für Tabelle `accounts`
--
ALTER TABLE `accounts`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10817676;

--
-- AUTO_INCREMENT für Tabelle `akte`
--
ALTER TABLE `akte`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=259573;

--
-- AUTO_INCREMENT für Tabelle `angel`
--
ALTER TABLE `angel`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=77;

--
-- AUTO_INCREMENT für Tabelle `benachrichtigung`
--
ALTER TABLE `benachrichtigung`
  MODIFY `id` int(100) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `beschwerde`
--
ALTER TABLE `beschwerde`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11101;

--
-- AUTO_INCREMENT für Tabelle `beschwerdeantwort`
--
ALTER TABLE `beschwerdeantwort`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=48021;

--
-- AUTO_INCREMENT für Tabelle `bizes`
--
ALTER TABLE `bizes`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=67;

--
-- AUTO_INCREMENT für Tabelle `bizes_backup`
--
ALTER TABLE `bizes_backup`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=66;

--
-- AUTO_INCREMENT für Tabelle `blacklist`
--
ALTER TABLE `blacklist`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1171;

--
-- AUTO_INCREMENT für Tabelle `cp_buy`
--
ALTER TABLE `cp_buy`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `cp_orders`
--
ALTER TABLE `cp_orders`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `cp_sessions`
--
ALTER TABLE `cp_sessions`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT für Tabelle `cp_users`
--
ALTER TABLE `cp_users`
  MODIFY `userID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `firma`
--
ALTER TABLE `firma`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT für Tabelle `frakcars`
--
ALTER TABLE `frakcars`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1952;

--
-- AUTO_INCREMENT für Tabelle `fraktionen`
--
ALTER TABLE `fraktionen`
  MODIFY `fraktionsid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT für Tabelle `friendlist`
--
ALTER TABLE `friendlist`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6275;

--
-- AUTO_INCREMENT für Tabelle `gangfight`
--
ALTER TABLE `gangfight`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;

--
-- AUTO_INCREMENT für Tabelle `gutschein`
--
ALTER TABLE `gutschein`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT für Tabelle `hausmoebel`
--
ALTER TABLE `hausmoebel`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20050;

--
-- AUTO_INCREMENT für Tabelle `hotel`
--
ALTER TABLE `hotel`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=62;

--
-- AUTO_INCREMENT für Tabelle `houseinterior`
--
ALTER TABLE `houseinterior`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT für Tabelle `houses`
--
ALTER TABLE `houses`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=927;

--
-- AUTO_INCREMENT für Tabelle `houses_bakcup`
--
ALTER TABLE `houses_bakcup`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=927;

--
-- AUTO_INCREMENT für Tabelle `hwban`
--
ALTER TABLE `hwban`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT für Tabelle `lob`
--
ALTER TABLE `lob`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38052;

--
-- AUTO_INCREMENT für Tabelle `news`
--
ALTER TABLE `news`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT für Tabelle `playercar`
--
ALTER TABLE `playercar`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=223156;

--
-- AUTO_INCREMENT für Tabelle `playercar_backup`
--
ALTER TABLE `playercar_backup`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `playercar_backup2`
--
ALTER TABLE `playercar_backup2`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=223147;

--
-- AUTO_INCREMENT für Tabelle `rangeban`
--
ALTER TABLE `rangeban`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `reservierung`
--
ALTER TABLE `reservierung`
  MODIFY `reservierungid` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `server_fvehicles`
--
ALTER TABLE `server_fvehicles`
  MODIFY `id` int(9) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `server_rang`
--
ALTER TABLE `server_rang`
  MODIFY `fsID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT für Tabelle `staticbiz`
--
ALTER TABLE `staticbiz`
  MODIFY `sbizid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT für Tabelle `tanken`
--
ALTER TABLE `tanken`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=113;

--
-- AUTO_INCREMENT für Tabelle `ticket`
--
ALTER TABLE `ticket`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1799;

--
-- AUTO_INCREMENT für Tabelle `ticketantwort`
--
ALTER TABLE `ticketantwort`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4416;

--
-- AUTO_INCREMENT für Tabelle `timeslot`
--
ALTER TABLE `timeslot`
  MODIFY `timeslotid` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT für Tabelle `waffenlager`
--
ALTER TABLE `waffenlager`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT für Tabelle `werbetafel`
--
ALTER TABLE `werbetafel`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT für Tabelle `whitelist`
--
ALTER TABLE `whitelist`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
