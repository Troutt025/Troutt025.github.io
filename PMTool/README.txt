PMTool README

9/26/2022

Version 1.0

------------------------------------------------
------------------------------------------------
The Puffer PM Tool consists of 2 .bat files.

PufferBackups.bat
CopyHotfixes.bat

PufferBackups.bat doesn't require any specific changes to work. It will work on any DeltaV system.

CopyHotfixes.bat requires adding hotfixes to the PMTool\Hotfix\Workstation and PMTool\Hotfix\Server folders.

If the script fails to find dt.src, manual input will be necessary.
Move the hotfixes you wish to install on the workstations into the Workstation folder and edit the Workstations.txt document to include all workstation names seperated by a line.
Example:
WS1
WS2
WS3

Do the same for the Server folder and Servers.txt.

It is recommended to use the unzipped OS hotfix for these since it doesn't take much more time to copy and saves having to unzip it individually.
The WS hotfix does not need to be unzipped.

Run the CopyHotfix.bat

WARNING:
The CopyHotfix.bat uses Mirror copy. Anything in the destination folders that are not in the source folder will be deleted.
