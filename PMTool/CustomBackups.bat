@ECHO off
SETLOCAL enabledelayedexpansion

REM 
REM Title: Custom Backups
REM Author: Jesse Troutt
REM Date: 09-26-2022
REM
REM README: This file was created to gather backups of a typical DeltaV system, as well as search through the dt.scr file for machine names and OS types to sort into a database of machines.
REM         You still need to copy the backups to another computer or flash drive for proper backup management.

REM Variables for DeltaV drive letters and Machine information
set DVdrvltr=DOESNOTEXIST
set DVData=:\deltav\dvdata\download
set strNodeName=DEFAULT
set strNodeType=DEFAULT
set strWinEdition=DEFAULT
set backupsLocation=d

REM Delete old Machine documentation
IF EXIST Machines\Servers.txt (del "Machines\Servers.txt")
IF EXIST Machines\Workstations.txt (del "Machines\Workstations.txt")

REM This is solely for the "set stamp" below
for /f "delims=" %%a in ('wmic OS Get localdatetime ^| find "."') do set dt=%%a
set datestamp=%dt:~0,8%
set YYYY=%dt:~0,4%
set MM=%dt:~4,2%
set DD=%dt:~6,2%

REM sets the "stamp" variable to the date
set stamp=%MM%-%DD%-%YYYY%

REM Check for dt.scr and run, if not revert to manual input
IF EXIST c:\deltav\dvdata\download\dt.scr (
	set DVdrvltr=c
) ELSE (
	IF EXIST d:\deltav\dvdata\download\dt.scr (
		set DVdrvltr=d
	) ELSE (
		ECHO.&ECHO. Unable to locate DeltaV host file, manual input required
		set DVData=DOESNOTEXIST
		set DVdrvltr=DOESNOTEXIST
		set strNodeType=WS
	)
)

REM creates the dated PM folder, and "Backups" folder
IF EXIST d:\ (
	mkdir D:\%stamp%PM\Backups
	set backupsLocation=d
) ELSE (
	mkdir C:\%stamp%PM\Backups
	set backupsLocation=c
)

REM Gathers all backups, graphics-iFix, POWERUP, Charts, sound, and .fhx backup
ROBOCOPY !DVdrvltr!:\DeltaV\DVData\Graphics-iFix !backupsLocation!:\%stamp%PM\Backups\Graphics-iFix\ /E /COPYALL
ROBOCOPY !DVdrvltr!:\DeltaV\DVData\POWERUP !backupsLocation!:\%stamp%PM\Backups\POWERUP\ /E /COPYALL
ROBOCOPY !DVdrvltr!:\DeltaV\DVData\Charts !backupsLocation!:\%stamp%PM\Backups\Charts\ /E /COPYALL
ROBOCOPY !DVdrvltr!:\DeltaV\DVData\sound !backupsLocation!:\%stamp%PM\Backups\sound\ /E /COPYALL
Start C:\DeltaV\bin\dbImpExpClient.exe -de !backupsLocation!:\%stamp%PM\Backups

REM Gather info from DV nodes from dt.scr for "Copy Hotfixes"
IF NOT !DVData! == DOESNOTEXIST (
	for /f "tokens=3,4 skip=3" %%g in (!DVdrvltr!!DVData!\dt.scr) do (
		set strNodeName=%%g
		set strNodeType=%%h

		for /f "delims=' tokens=2" %%g in ("!strNodeName!") do (set strNodeName=%%g)
		for /f "delims== tokens=2" %%g in ("!strNodeType!") do (set strNodeType=%%g)

		REM Check if machine is alive to gather info and add to machine list
		IF "!strNodeType!" EQU "WS" (
			echo !strNodeName!

			ping -n 1 !strNodeName!>NUL

			IF !ERRORLEVEL! GEQ 1 (ECHO.&ECHO. Host !strNodeName! not found, skipping&ECHO.
			) ELSE (
				for /f "tokens=3-5 delims== " %%g in ('wmic /NODE:"!strNodeName!" os get Caption /value ^| find "Windows" ') do (set "strWinEdition=%%g %%h %%i")

				echo !strWinEdition!

				IF NOT "x!strWinEdition:Server=!"=="x!strWinEdition!" (
					echo !strNodeName!>>Machines\Servers.txt
				) ELSE (
					echo !strNodeName!>>Machines\Workstations.txt
				)
			)
		)
	)
)

ECHO:
pause
