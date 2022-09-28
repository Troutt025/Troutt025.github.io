@ECHO off
REM
REM Title:  Copy Hotfixes
REM Date:   9/28/2022
REM
REM README: This file is not to be changed. To add or remove machines, please edit the Servers.txt and Workstations.txt files.
REM         
REM 

REM Variable for Hotfix location
set hotfixLocation=d
 
ECHO Server Hotfixes
ECHO:
for /f %%i in (Machines\Servers.txt) do (
	IF EXIST \\%%i\D$\ (
		mkdir D:\Hotfixes
		set hotfixLocation=d
	) ELSE (
		mkdir C:\Hotfixes
		set hotfixLocation=c
	)
	robocopy Hotfixes\Server\ \\%%i\%hotfixLocation%\Hotfixes\ /MIR /S /E /COPYALL /R:1 /W:5 /NFL /NS /NJS
)

ECHO:
ECHO Workstation Hotfixes
ECHO:
for /f %%i in (Machines\Workstations.txt) do (
	IF EXIST \\%%i\D$\ (
		mkdir D:\Hotfixes
		set hotfixLocation=d
	) ELSE (
		mkdir C:\Hotfixes
		set hotfixLocation=c
	)
	robocopy Hotfixes\Workstation\ \\%%i\%hotfixLocation%\Hotfixes\ /MIR /S /E /COPYALL /R:1 /W:5 /NFL /NS /NJS
)

ECHO:
pause
