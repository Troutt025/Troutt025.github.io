PMTool README

4/28/2022

Version 1.0

------------------------------------------------
------------------------------------------------
The PM Tool consists of 2 .bat files.

CustomBackups.bat
CopyHotfixes.bat

CustomBackups.bat doesn't require any specific changes to work. It will work on any system that has DeltaV installed on the D: drive.

CopyHotfixes.bat requires adding hotfixes to the PMTool\Hotfix\Workstation and PMTool\Hotfix\Server folders. Then editing the Workstations.txt and Servers.txt to include the names
of the workstations and servers.

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