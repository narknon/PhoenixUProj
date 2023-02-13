# Prebuilt uProject and Engine Installation Instructions


### See [option 1](\#1-standard-install---no-easy-updating) for standard install, or [option 2](\#2-github-clone-install---update-with-the-click-of-a-button) for install along with Github desktop to allow for easy updates.  Be sure to install any missing [prerequisites](\#prerequisites) first.  See [section 3](\#3-troubleshooting) for troubleshooting.

I highly recommend following option 2, as you can update with the click of a button and updates will only download changed files.

### For Audio Modding switch the the "AudioBranch" branch of this repo and follow the readme from there.

### [Packaging assets as IO Store (utoc/ucas)](https://github.com/narknon/PhoenixUProj/wiki/Packaging-assets-as-IO-Store-(utoc-ucas)#to-pak-files-as-ucasutoc)


## Prerequisites

### Link Epic and Github Accounts

If you have not done so already, follow the instructions here to create and link a Github account to an Epic Games account: https://www.unrealengine.com/en-US/ue-on-github


They will send you two confirmation emails, one of which may require that you follow a link to verify the connection.


### Install Visual Studio

Download and install Visual Studio.  It can be 2017, 2019, or 2022.  It can be found here (https://visualstudio.microsoft.com/downloads/), and you should download the "Community" version.  You may need to log in to a Microsoft account to access this link.

If you are installing for the first time, be sure to include the below options.

### VS - C++ Tools

![image](https://user-images.githubusercontent.com/73571427/218323712-1347266b-c58d-43b0-a992-d758fe10ae67.png)


To add C++ tools to your VS installation, make sure you select Game development with C++ under Workloads, as well as the Unreal Engine Installer option.  You must have at least one Windows 10 SDK, Windows 11 SDK will not be sufficient.




# 1. Standard Install - No easy updating

Make sure you followed the Prerequisites or the 2nd link will not work.

Proceed to the links https://github.com/narknon/PhoenixUProj and https://github.com/narknon/UnrealEngine-CEEnd/tree/4.27-chaos.


Click on the green arrow to the right, and select download zip.

![image](https://user-images.githubusercontent.com/73571427/218326661-f8e2b9f3-d69a-44bf-a94c-854140cc12b3.png)


Once the downloads are complete, extract each to separate folders (I personally prefer not to use Desktop or Documents for Unreal installs, and instead install on root of my drive, or close to root).  Be sure not to use a very long path or UE will give errors.

### Engine

Once extracted, rename the engine folder (UnrealEngine-CEEnd) to whatever you would like just to ensure that the path to the files is not gigantic.


Inside the engine root folder (not the /Engine/ folder within the downloaded folders), double click the file named Setup.bat.  Wait for this to complete.  At the very end of its process, it will pop-up a Windows Elevated rights request in the background, so be sure to check your taskbar and select and allow the elevation.

![image](https://user-images.githubusercontent.com/73571427/176477471-ef0b54df-e784-4c1c-9565-d4a1ffcf881f.png)

![image](https://user-images.githubusercontent.com/73571427/176477497-4d25c243-ff9b-4bfb-97bb-b3871875a0f9.png)

Then navigate to find the UnrealVersionSelector-Win64-Shipping.exe at the following path: \Engine\Binaries\Win64\UnrealVersionSelector-Win64-Shipping.exe.  Double click this file. It will then ask if you wish to register the directory as an Unreal installation.  Select yes.  It should then say registration succesful.

![image](https://user-images.githubusercontent.com/73571427/176457712-115965b1-d260-4845-83c9-d77dcf127e10.png)


### uProject

Inside the folder to which you extracted the project, find the Phoenix.uproject file.  Right click on this file, and select "Switch Unreal Engine Version".  If you correctly registered the engine directory as an Unreal directory, it should simply appear in the dropdown.  If it does not appear automatically, click the three dots to the right of the path. Navigate to the folder to which you extracted the engine, and select the root folder (i.e., the folder that contains the setup.bat file).

![image](https://user-images.githubusercontent.com/73571427/176458008-307cc67f-0122-4a1b-9025-964c3592c8c1.png)


![image](https://user-images.githubusercontent.com/73571427/176459346-7e40b7bd-ab8d-4e81-8866-e6acc9394b79.png)



Following this, the uproject should generate a .sln file.  If this file does not generate, something went wrong.  Try right clicking on the TresGame.uproject again, and this time select "Generate Project Files."  If the .sln still does not generate, something else is happening.  Navigate to your Saved/Logs folder to find a file titled unrealversionselector-2022.06.29-09.16.08.log (the date will be the current date/time), and check to see what the error was, or post the file in the #kh3-modding channel on the discord for help. 


If the .sln did generate, you're done!  Double click on the Phoenix.uproject to launch the project!

### Done!




# 2. Github Clone Install - Update with the click of a button


### Additional Prerequisites

Github Desktop: https://desktop.github.com/ (install with defaults, being sure to include any options relating to adding GIT as an environmental variable/path.)

Git CLI: https://git-scm.com/downloads (install with defaults, being sure to include any options relating to adding GIT as an environmental variable/path.)


### Engine

Create a folder in which you would like to install the engine (I personally prefer not to use Desktop or Documents for Unreal installs, and instead install on root of my drive, or close to root).

Open the folder, hold Shift, and Right Click.  The Right Click context menu should include the option "Open Powershell Window Here".  Select this option.

![image](https://user-images.githubusercontent.com/73571427/176466757-96a88aaa-bd02-4248-b0be-9a1072472ee2.png)


A new console window should then open. 

Copy/paste the below command into the console window. Make sure you followed the Prerequisites or the clone will not work.

    git clone --branch 4.27-chaos --single-branch https://github.com/narknon/UnrealEngine-CEEnd.git
    
    
Wait for the download to complete based on the output in the console window.

![image](https://user-images.githubusercontent.com/73571427/218326628-c391390f-6407-472a-bb7b-e7e59851d71c.png)


Once completed, rename the engine folder (UnrealEngine-CEEnd) to whatever you would like just to ensure that the path to the files is not gigantic.


Inside the engine root folder (not the /Engine/ folder within the downloaded folders), double click the file named Setup.bat.  Wait for this to complete.  At the very end of its process, it will pop-up a Windows Elevated rights request in the background, so be sure to check your taskbar and select and allow the elevation.

![image](https://user-images.githubusercontent.com/73571427/176477471-ef0b54df-e784-4c1c-9565-d4a1ffcf881f.png)

![image](https://user-images.githubusercontent.com/73571427/176477497-4d25c243-ff9b-4bfb-97bb-b3871875a0f9.png)


Then navigate to find the UnrealVersionSelector-Win64-Shipping.exe at the following path: \Engine\Binaries\Win64\UnrealVersionSelector-Win64-Shipping.exe.  Double click this file. It will then ask if you wish to register the directory as an Unreal installation.  Select yes.  It should then say registration succesful.

![image](https://user-images.githubusercontent.com/73571427/176457712-115965b1-d260-4845-83c9-d77dcf127e10.png)


### uProject

Create a new folder that is not within the engine folder to which you would like to install the uProject.

Open a new powershell window from within this new folder.  Paste the below command into the powershell window

    git clone https://github.com/narknon/PhoenixUProj.git
    
    
Wait for the download to complete based on the output in the console window.  This should be much quicker than the engine download.

Once complete, find the Phoenix.uproject file in this folder.  Right click on this file, and select "Switch Unreal Engine Version".  If you correctly registered the engine directory as an Unreal directory, it should simply appear in the dropdown.  If it does not appear automatically, click the three dots to the right of the path. Navigate to the folder to which you extracted the engine, and select the root folder (i.e., the folder that contains the setup.bat file).


![image](https://user-images.githubusercontent.com/73571427/176458008-307cc67f-0122-4a1b-9025-964c3592c8c1.png)


![image](https://user-images.githubusercontent.com/73571427/176459346-7e40b7bd-ab8d-4e81-8866-e6acc9394b79.png)


Following this, the uproject should generate a .sln file.  If this file does not generate, something went wrong.  Try right clicking on the TresGame.uproject again, and this time select "Generate Project Files."  If the .sln still does not generate, something else is happening.  Navigate to your Saved/Logs folder to find a file titled unrealversionselector-2022.06.29-09.16.08.log (the date will be the current date/time, not the one listed here), and check to see what the error was, or post the file in the #kh3-modding channel on the discord for help. 


If the .sln did generate, you should now be able to launch the project by double clicking on the Phoenix.uproject.  Proceed to the Github Desktop steps below to allow one-button updates.

### Github Desktop

Open Github Desktop and navigate to File->Add Local Repository; or press CTRL+O.  

![image](https://user-images.githubusercontent.com/73571427/176687516-0dfd3263-16f4-4b3d-aa0c-113b6dfb798d.png)


In the new dialog, press "Choose" and navigate to the folder to which you cloned the uproject (this will be the folder that contains the hidden .git folder, not the folder that is a directory up from that).

![image](https://user-images.githubusercontent.com/73571427/176687457-13a4c1b3-aaeb-48b9-97a4-b9485ed0d3bd.png)

Once inside this folder, press select folder.

![image](https://user-images.githubusercontent.com/73571427/218326741-1467f772-2756-41aa-a213-4621623d5311.png)

![image](https://user-images.githubusercontent.com/73571427/218326789-0748eb61-8a31-4a11-bc53-1fdfe27fe990.png)



The repository should now be added as the current repository.

![image](https://user-images.githubusercontent.com/73571427/176688075-eef2ed9d-3151-4320-b000-f75a67eea494.png)


Do the same for the engine.  Now you should be able to swap between both by clicking the "Current Repository" button.  You can also switch between branches easily if you'd like to try out one of the experimental branches.


### Done!


# 3. Troubleshooting

If your problem is not solved by the below, then navigate to Saved/Logs for both your uProject folder, your engine folder, and the automation tool (see below paths), and request help in the server by sending the relevant logs from each.

{EngineFolderRoot}\Engine\Saved\Logs

{EngineFolderRoot}\Engine\Programs\AutomationTool\Saved\Logs

{EngineFolderRoot}\Engine\Programs\UnrealHeaderTool\Saved\Logs

{ProjectFolderRoot}\Saved\Logs
