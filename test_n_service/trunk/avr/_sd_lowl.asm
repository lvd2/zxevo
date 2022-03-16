;
;--------------------------------------
;in;    TEMP - n
SD_RD_DUMMY:
        SER     DATA
        RCALL   SD_EXCHANGE
        DEC     TEMP
        BRNE    SD_RD_DUMMY
        RET
;
;--------------------------------------
;in:    DATA
SD_WR_CMD:
        PUSH    DATA
        LDI     TEMP,2
        RCALL   SD_RD_DUMMY
        POP     DATA
        RCALL   SD_EXCHANGE
        CLR     DATA
        RCALL   SD_EXCHANGE
SD_WR_CMX4:
        CLR     DATA
        RCALL   SD_EXCHANGE
        CLR     DATA
        RCALL   SD_EXCHANGE
        CLR     DATA
        RCALL   SD_EXCHANGE
        SER     DATA
        RCALL   SD_EXCHANGE
        RJMP    SD_WAIT_NOTFF
;
;--------------------------------------
;in:    Z
SD_WR_PGM_6:
        LDI     TEMP,2
        RCALL   SD_RD_DUMMY
        LDI     TEMP,6
SD_WR_PGX:
SDWRP61:LPM     DATA,Z+
        RCALL   SD_EXCHANGE
        DEC     TEMP
        BRNE    SDWRP61
; - - - - - - - - - - - - - - - - - - -
;out:   DATA
SD_WAIT_NOTFF:
        LDI     TEMP,32
SDWNFF2:SER     DATA
        RCALL   SD_EXCHANGE
        CPI     DATA,$FF
        BRNE    SDWNFF1
        DEC     TEMP
        BRNE    SDWNFF2
SDWNFF1:RET
;
;--------------------------------------
;in:    Z - �㤠
;       X,W - �ᥪ��
;out:   sreg.Z - SET==error
SD_READ_SECTOR:
        LDS     DATA,SD_CARDTYPE
        SBRC    DATA,2
        RJMP    SDRDSE1
        LSL     WL
        ROL     WH
        ROL     XL
        MOV     XH,XL
        MOV     XL,WH
        MOV     WH,WL
        CLR     WL
SDRDSE1:
        SER     DATA
        RCALL   SD_EXCHANGE
        LDI     DATA,$40|17 ;CMD17 (read_single_block)
        RCALL   SD_EXCHANGE
        MOV     DATA,XH
        RCALL   SD_EXCHANGE
        MOV     DATA,XL
        RCALL   SD_EXCHANGE
        MOV     DATA,WH
        RCALL   SD_EXCHANGE
        MOV     DATA,WL
        RCALL   SD_EXCHANGE
        SER     DATA
        RCALL   SD_EXCHANGE

        SER     WL
SDRDSE2:RCALL   SD_WAIT_NOTFF
        DEC     WL
        BREQ    SDRDSE8
        CPI     DATA,$FE
        BRNE    SDRDSE2

        PUSH    FLAGS1
        SBRS    FLAGS1,3
        RJMP    SDRDSE5
        CBR     FLAGS1,0B00001101
        SBR     FLAGS1,0B00000010
        PUSHZ
        LDIZ    MSG_TSD_SKIP*2
        CALL    PRINTSTRZ
        POPZ
SDRDSE5:LDIW    512
SDRDSE3:RCALL   SD_RECEIVE
        ST      Z+,DATA
        SBIW    WL,1
        BRNE    SDRDSE3
        POP     FLAGS1

        LDI     TEMP,2+1
        RCALL   SD_RD_DUMMY
        CLZ
        RET
;�訡�� �� �⥭�� ᥪ��
SDRDSE8:RET
;
;--------------------------------------
;out:   DATA
SD_RECEIVE:
        SER     DATA
; - - - - - - - - - - - - - - - - - - -
;in:    DATA
;out:   DATA
SD_EXCHANGE:
        SBRS    FLAGS1,3
        RJMP    FPGA_SAME_REG
;�� ��, �� � FPGA_SAME_REG, �� � ����� � RS-232
;in:    DATA == �����
;out:   DATA == �����
        PUSH    FLAGS1
        CBR     FLAGS1,0B00000101
        SBR     FLAGS1,0B00000010
        PUSHZ
        PUSH    DATA
        LDIZ    MSG_TSD_OUT*2
        RCALL   PRINTSTRZ
        POP     DATA
        PUSH    DATA
        RCALL   HEXBYTE
        POP     DATA
        SPICS_CLR
        OUT     SPDR,DATA
;�������� ����砭�� ������ � FPGA �� SPI
;� �⥭�� ��襤�� ������
;out:   DATA == �����
SD_RDY_RD:
;        SBIC    SPSR,WCOL
;        JMP     CHAOS00
        SBIS    SPSR,SPIF
        RJMP    SD_RDY_RD
        IN      DATA,SPDR
        SPICS_SET
        PUSH    DATA
        LDIZ    MSG_TSD_IN*2
        RCALL   PRINTSTRZ
        POP     DATA
        PUSH    DATA
        RCALL   HEXBYTE
        POP     DATA
        POPZ
        POP     FLAGS1
        RET
;
;--------------------------------------
;
