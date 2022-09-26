@ECHO off
REM 
REM Title: Puffer Backups
REM Author: Jesse Troutt
REM Date: 10-29-2020
REM
REM README: This file was created to gather backups of a typical DeltaV system. You still need to copy the backups to another computer. This batch file only works on systems that have DeltaV installed on their D:\ drive.

REM Gathers date information for "stamp" below
for /f "delims=" %%a in ('wmic OS Get localdatetime ^| find "."') do set dt=%%a
set datestamp=%dt:~0,8%
set YYYY=%dt:~0,4%
set MM=%dt:~4,2%
set DD=%dt:~6,2%

REM sets the "stamp" variable to the date
set stamp=%MM%-%DD%-%YYYY%

REM creates the "Puffer" folder, dated PM folder, and "Backups" folder
mkdir D:\Puffer\%stamp%PM\Backups

REM Gathers all backups, graphics-iFix, POWERUP, Charts, sound, and .fhx backup
ROBOCOPY D:\DeltaV\DVData\Graphics-iFix D:\Puffer\%stamp%PM\Backups\Graphics-iFix\ /E /COPYALL
ROBOCOPY D:\DeltaV\DVData\POWERUP D:\Puffer\%stamp%PM\Backups\POWERUP\ /E /COPYALL
ROBOCOPY D:\DeltaV\DVData\Charts D:\Puffer\%stamp%PM\Backups\Charts\ /E /COPYALL
ROBOCOPY D:\DeltaV\DVData\sound D:\Puffer\%stamp%PM\Backups\sound\ /E /COPYALL
Start C:\DeltaV\bin\dbImpExpClient.exe -de D:\Puffer\%stamp%PM\Backups
