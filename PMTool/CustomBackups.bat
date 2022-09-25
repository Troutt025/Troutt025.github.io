@ECHO off
REM 
REM Title: Custom Backups
REM Author: Jesse Troutt
REM Date: 10-29-2020
REM
REM README: This file was created to gather backups of a typical DeltaV system installed on the D drive. You still need to copy the backups to another computer.

REM This is solely for the "set stamp" below
for /f "delims=" %%a in ('wmic OS Get localdatetime ^| find "."') do set dt=%%a
set datestamp=%dt:~0,8%
set timestamp=%dt:~8,6%
set YYYY=%dt:~0,4%
set MM=%dt:~4,2%
set DD=%dt:~6,2%
set HH=%dt:~8,2%
set Min=%dt:~10,2%
set Sec=%dt:~12,2%

REM sets the "stamp" variable to the date
set stamp=%MM%-%DD%-%YYYY%

REM creates the dated PM folder, and "Backups" folder
mkdir D:\%stamp%PM\Backups

REM Gathers all backups, graphics-iFix, POWERUP, Charts, sound, and .fhx backup
ROBOCOPY D:\DeltaV\DVData\Graphics-iFix D:\%stamp%PM\Backups\Graphics-iFix\ /E /COPYALL
ROBOCOPY D:\DeltaV\DVData\POWERUP D:\%stamp%PM\Backups\POWERUP\ /E /COPYALL
ROBOCOPY D:\DeltaV\DVData\Charts D:\%stamp%PM\Backups\Charts\ /E /COPYALL
ROBOCOPY D:\DeltaV\DVData\sound D:\%stamp%PM\Backups\sound\ /E /COPYALL
Start C:\DeltaV\bin\dbImpExpClient.exe -de D:\%stamp%PM\Backups