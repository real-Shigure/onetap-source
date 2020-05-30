rem I'm don't want add comments, so, idk, read script. :d 
@echo off
mode con: cols=80 lines=30 
chcp 1250
:starter
cls
call :random_color
title OneTap Offset Updater. Build: 03.04.2020 / 1.6
set language=unknown
echo.
echo.
echo		        @-------------------------------------------@
echo 	        	#					    #
echo		        # ONETAP OFFSET UPDATER (working april 2020) #  
echo		        #            SIGNATURES: 0x000cb             #
echo		        #              SOFT: HoShiMin                #
echo 	        	# Fixed by UnsereKleineHacker (HamburgerJoe) #
echo  	        	#   					     #
echo	 		#					    #
echo		        @-------------------------------------------@
echo.
echo.
cd Insignia
offset_updater.exe
ping 0.0.0.0 -n 5 > nul 
echo #Good luck with it!
echo.
echo #To start write in start:
echo.
set /p language="console: "
if "%language%"=="hu" goto :insignia
if "%language%"=="start" goto :insignia
goto language_not_selected
:insignia
cls
echo.
echo.
call :language_interpreter %language%, "Search new offsets. This can take 1-2 min, please wait...." 
call :insignia_search_module, :patcher
:patcher
echo.
call :language_interpreter %language%, "Offsets found. Writing to file..."
call :patcher_module, :end
:end
echo.
call :language_interpreter %language%, "Writing offsets done. Good luck!"
echo.
echo.
echo.
ping 0.0.0.0 -n 10 > nul
exit
:insignia_search_module
cd Insignia
Insignia.exe sigs.txt offsets.txt ../client_panorama.dll
cd ..
goto %~1
:patcher_module
cd Patcher
patcher.exe ../Insignia/offsets.txt
cd..
goto %~1
:language_not_selected
color 4
cls
echo.
echo.
echo		        @-------------------------------------------@
echo 	        #					    #
echo		        #             Select language               #  
echo		        #	         		    	    #
echo	 		#					    #
echo		        @-------------------------------------------@
ping 0.0.0.0 -n 5 > nul
goto :starter
:random_color
set /a random=%random% %% 16
set HEX=0123456789ABCDEF
call set random_color=%%HEX:~%random%,1%%%%,1%%
color %random_color%
:language_interpreter
 if "%~1"=="start" (
	echo %~2
 )
 if "%~1"=="hu" ( 
     echo %~3
 )
