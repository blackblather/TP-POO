for /F "tokens=1,2,3 delims= " %%A in ('reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\RecoveryEnvironment" /v TargetOS') DO SET TARGETOS=%%C

for /F "tokens=1 delims=\" %%A in ('Echo %TARGETOS%') DO SET TARGETOSDRIVE=%%A

if EXIST %TARGETOSDRIVE%\recovery\OEM\Unattend.xml xcopy %TARGETOSDRIVE%\recovery\OEM\Unattend.xml %TARGETOSDRIVE%\Windows\Panther\ /y
