# How to Run an Installation on Your Computer



#### **For All Computers**

1. Remove or hide all icons from your screen

   - For Macs, you can hide icons from the terminal, type defaults write 

     ```
     com.apple.finder CreateDesktop -bool false
     ```

     To bring them back, type defaults write 

     ```
     com.apple.finder CreateDesktop -bool true
     ```

     

   - For Windows, right-click on the Desktop, go to View and uncheck Show Desktop icons

2. Set the desktop background to something neutral or a screenshot from what you will be showcasing (makes it slightly less obvious if it stops running and returns to the main screen)

3. Make sure the computer, the display, and the hard disks never sleep. The computer should also start automatically when the computer freezes.

   - For Windows, go to Control Panel -> Hardware and Sound -> Power Options
   - For Macs, go to Energy Saver

4. Make sure the screensaver never starts.

   - For Windows, go to Control Panel, Appearance and Personalization, Personalization, Screen Saver and set Screen Saver to None

5. If your installation does not require audio, mute the output volume.

6. Disable Bluetooth

7. Disable any alerts/pop ups

8. Download TeamViewer, setup the computer for unattended remote access

9. If internet access is necessary, always try to use an ethernet cable rather than Wifi. And when possible, bring your own router (unless you absolutely trust the internet being provided by the venue)

10. If you or an assistant will be onsite, set up TouchOSC to change parameters on the fly. This can also be an easy way to adjust to a screen size during a speedy installation!

11. All numerical inputs for variables should be stored in a json file and then read by the program. (This way if a non-technical person needs to change something, they are only updating a json file). An example of this can be found above. 

12. Always bring extra long HDMI, VGA, Ethernet, and all of the dongles (check the cables BEFORE going on site - HDMI cables stop working OFTEN)

    

#### **Mac Specific**

1. Add a schedule to Energy Save so that the computer starts up and shuts down at a fixed time everyday.

2. Hide the dock by pressing Option + Command + D while in Finder.

3. Select Automatic Login when your computer starts.

   - Go to System Preferences, Users and Groups, and select Login options

4. Add your application to the Login Items of the user you log in with, to ensure your installation will start up automatically.

   - This is the ProjectName.app file, you can find it in your Finder under ProjectName/xcode/build/Release

5. Disable Accessibility Shortcuts

   - Go to Control Panel, Accessibility

6. Disable dashboard, as this takes up resources (CPU). Type this into the terminal 

   ```
   defaults write com.apple.dashboard mcx-disabled -boolean YES
   ```

   To enable it again, type 

   ```
   defaults write com.apple.dashboard mcx-disabled -boolean NO
   ```

7. Disable Spotlight. Type this into your terminal 

   ```
   sudo mdutil -a -i off
   ```

   To enable it again, type this

   ```
   sudo mdutil -a -i on
   ```

8. Disable the Require Password After Sleep in the General tab under Security & Privacy to prevent the system from asking password after a scheduled system start up.

9. Prevent OS X from reopening apps after a restart. You want to do this because it increases the time it takes to start up the machine into a steady state, and it reopens apps you may not be using anymore. To prevent apps from re-opening, do the following:

   1. Quit all apps

   2. Navigate to ~/Library/Preferences/ByHost/com.apple.loginwindow.*.plist.

   3. Click Command + I on the file, and lock it using the Locked checkbox.

      

#### **Windows Specific**

1. Auto shutdown, go to Control Panel -> System and Security -> Administrative Tools -> Task Scheduler. Go to Create a New Task :
   1. Add a Title and description
   2. Follow the directions
   3. In the Action tab, select start a program, select C:\Windows\System32\shutdown.exe, add argument /s
2. Disable Taskbar, right-click an empty spot on the TaskBar, click Taskbar Settings and hide toolbar
3. Avoid windows login screen, go to System Configuration, select the Boot tab and select No GUI boot, click Apply, then OK, and restart the machine
4. Make sure it stays awake when you close the lid, go to Control Panel -> Hardware and Sound -> Power Options and select Do Nothing for “When I close the lid”Disable System Updates, go to Control Panel -> System and Security -> Windows Update -> Change Settings, and set to Never Check for Updates
5. Remove password from login process, click Window + R, and type netplwiz, select the user account you are using and unclick User must enter a username and password to use this computer and hit Apply, enter your password and hit OK
6. To disable default startup programs, go to System Configuration, and click the Startup tab, disable all programs you don’t need
7. Add programs to the start menu, in Windows search bar type shell:startup, this will open a directory and place your files there.
   - For processing sketches, open your processing code, go to File -> Export Application, in the application.windows64 folder, make a shortcut for the executable and place the shortcut in the startup folder


**MOST IMPORTANT -** Let the application run overnight to see if it crashes!