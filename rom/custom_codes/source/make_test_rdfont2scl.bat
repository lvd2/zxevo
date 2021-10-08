
@echo off

..\..\..\tools\asl\bin\asl -U -L test_rdfont.a80
..\..\..\tools\asl\bin\p2bin test_rdfont.p test_rdfont.rom -r $-$ -k
..\..\..\tools\mhmt\mhmt -mlz test_rdfont.rom test_rdfont_pack.rom

..\..\..\tools\asl\bin\asl -U -L make_test_rdfont2scl.a80
..\..\..\tools\asl\bin\p2bin make_test_rdfont2scl.p make_test_rdfont2scl.rom -r $-$ -k

..\..\..\tools\csum32\csum32 test_rdfont_pack.rom
copy /B /Y make_test_rdfont2scl.rom+csum32.bin ..\test_rdfont.scl

del csum32.bin
del *.lst

pause