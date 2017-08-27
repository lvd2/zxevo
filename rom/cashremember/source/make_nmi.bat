
@ECHO OFF

asw -U -L nmi_code.a80
p2bin nmi_code.p nmi_code.rom -r $-$ -k

pause
