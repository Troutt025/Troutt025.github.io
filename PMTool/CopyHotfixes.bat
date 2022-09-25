@ECHO off
REM
REM Title:  Copy Hotfixes
REM Author: Jesse Troutt
REM Date:   4-28-2022
REM
REM README: This file is not to be changed. To add or remove machines, please edit the Servers.txt and Workstations.txt files.
REM         
REM         

ECHO Server Hotfixes
ECHO:
for /f %%i in (D:\PMTool\Machines\Servers.txt) do robocopy D:\PMTool\Hotfixes\Server\ \\%%i\D$\Hotfixes\ /MIR /S /E /COPYALL /R:1 /W:5 /NFL /NS /NJS

ECHO:
ECHO Workstation Hotfixes
ECHO:
for /f %%i in (D:\PMTool\Machines\Workstations.txt) do robocopy D:\PMTool\Hotfixes\Workstation\ \\%%i\D$\Hotfixes\ /MIR /S /E /COPYALL /R:1 /W:5 /NFL /NS /NJS

ECHO:
pause