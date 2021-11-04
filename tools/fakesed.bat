@ECHO OFF
echo %1
for /F "tokens=1-2 delims=:" %%A in ('%1') do (
	IF NOT "%%B"=="" (
		ECHO %%A %2 : %%B>%2
	) ELSE (
		ECHO  %%A>>%2
	)
)