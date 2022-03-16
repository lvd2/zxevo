.NOLIST
.INCLUDE "m128def.inc"
.INCLUDE "_macros.asm"
.LIST
.LISTMAC

.DEF    MODE1   =R10    ;�������� ॣ����, (.0 - 0=VGAmode, 1=TVmode) �⠥��� �� EEPROM
.DEF    LANG    =R11    ;�������� ॣ����, �� ����䥩� (㬭��.�� 2) �⠥��� �� EEPROM
.DEF    INT6VECT=R12    ;�������� ॣ����, (��ࠡ��稪� INT6)
.DEF    FF      =R13    ;�������� ॣ����, �ᥣ�� = $FF
.DEF    ONE     =R14    ;�������� ॣ����, �ᥣ�� = $01
.DEF    NULL    =R15    ;�������� ॣ����, �ᥣ�� = $00
.DEF    DATA    =R16
.DEF    TEMP    =R17
.DEF    COUNT   =R18
.DEF    BITS    =R19
.DEF    FLAGS1  =R20    ;�������� ॣ����, 䫠��:
                        ;.0 - PUTCHAR ��뢠�� UARTDIRECT_PUTCHAR
                        ;.1 - PUTCHAR ��뢠�� UART_PUTCHAR
                        ;.2 - PUTCHAR ��뢠�� SCR_PUTCHAR
                        ;.3 - ��� ������ SD � RS232
.DEF    TMP2    =R22
.DEF    TMP3    =R23
.DEF    WL      =R24
.DEF    WH      =R25
; DATA,TEMP,COUNT,WL,WH,XL,XH,ZL,ZH - ����� ��।����� ��ࠬ���� � �㭪樨 � �������� १�����
; Y - 㪠��⥫� �� �⥪ ������ (����� ����)
; R0,R1 � ��⠫�� - �ᯮ������� �����쭮
;
;--------------------------------------
;
.EQU    DBSIZE_HI       =HIGH(2048)
.EQU    DBMASK_HI       =HIGH(2047)
.EQU    nCONFIG         =PORTF0
.EQU    nSTATUS         =PORTF1
.EQU    CONF_DONE       =PORTF2
;
;--------------------------------------
;ॣ����� fpga
.EQU    TEMP_REG        =$A0
.EQU    SD_CS0          =$A1
.EQU    SD_CS1          =$A2
.EQU    FLASH_LOADDR    =$A3
.EQU    FLASH_MIDADDR   =$A4
.EQU    FLASH_HIADDR    =$A5
.EQU    FLASH_DATA      =$A6
.EQU    FLASH_CTRL      =$A7
.EQU    SCR_LOADDR      =$A8    ; ⥪��� ������ ����
.EQU    SCR_HIADDR      =$A9    ;
.EQU    SCR_ATTR        =$AA    ; ������ ��ਡ�� � ATTR
.EQU    SCR_FILL        =$AB    ; �।���६��� ���� � ������ ��ਡ�� � ATTR � � ������
                                ; (�᫨ ⮫쪮 ��࣠�� spics_n, �㤥� ������� �।��騩 ATTR)
.EQU    SCR_CHAR        =$AC    ; �।���६��� ���� � ������ ᨬ���� � ������ � ATTR � ������
                                ; (�᫨ ⮫쪮 ��࣠�� spics_n, �㤥� ������� �।��騩 ᨬ���)
.EQU    SCR_MOUSE_TEMP  =TEMP_REG
.EQU    SCR_MOUSE_X     =$AD
.EQU    SCR_MOUSE_Y     =$AE
.EQU    SCR_MODE        =$AF    ; .0 - 0=VGAmode, 1=TVmode; .1 - 0=�⪠ 720x576;

.EQU    MTST_CONTROL    =$50
.EQU    MTST_PASS_CNT0  =$51
.EQU    MTST_PASS_CNT1  =TEMP_REG
.EQU    MTST_FAIL_CNT0  =$52
.EQU    MTST_FAIL_CNT1  =TEMP_REG

.EQU    COVOX           =$53

.EQU    INT_CONTROL     =$54
;
;--------------------------------------
;
.MACRO  SPICS_SET
        SBI     PORTB,0
.ENDMACRO

.MACRO  SPICS_CLR
        CBI     PORTB,0
.ENDMACRO
;
;--------------------------------------
;
.DSEG
                .ORG    $0300
DSTACK:
.EQU    UART_TXBSIZE    =128            ;ࠧ��� ���� �.�. ࠢ�� �������_������ ���� (...32,64,128,256)
UART_TX_BUFF:   .BYTE   UART_TXBSIZE    ;���� �.�. ��⥭ UART_TXBSIZE
.EQU    UART_RXBSIZE    =128            ;ࠧ��� ���� �.�. ࠢ�� �������_������ ����
UART_RX_BUFF:   .BYTE   UART_RXBSIZE    ;���� �.�. ��⥭ UART_RXBSIZE

                .ORG    $0400
BUFSECT:        ;���� ᥪ��
                .ORG    $0600
BUF4FAT:        ;�६���� ���� (FAT � �.�.)
                .ORG    $0800
MEGABUFFER:
                .ORG    RAMEND
HSTACK:
                .ORG    $0100
RND:            .BYTE   3
NEWFRAME:       .BYTE   1
GLB_STACK:      .BYTE   2
GLB_Y:          .BYTE   2
;
;--------------------------------------
;
.ESEG
                .ORG    $0000
EE_DUMMY:       .DB     $FF
EE_MODE1:       .DB     $FF
EE_LANG:        .DB     $00
;
;--------------------------------------
;
.CSEG
        .ORG    0
        JMP     START
        JMP     START   ;EXT_INT0 ; IRQ0 Handler
        JMP     START   ;EXT_INT1 ; IRQ1 Handler
        JMP     START   ;EXT_INT2 ; IRQ2 Handler
        JMP     START   ;EXT_INT3 ; IRQ3 Handler
        JMP     EXT_INT4 ; IRQ4 Handler
        JMP     EXT_INT5 ; IRQ5 Handler
        JMP     EXT_INT6 ; IRQ6 Handler
        JMP     START   ;EXT_INT7 ; IRQ7 Handler
        JMP     START   ;TIM2_COMP ; Timer2 Compare Handler
        JMP     START   ;TIM2_OVF ; Timer2 Overflow Handler
        JMP     START   ;TIM1_CAPT ; Timer1 Capture Handler
        JMP     START   ;TIM1_COMPA ; Timer1 CompareA Handler
        JMP     START   ;TIM1_COMPB ; Timer1 CompareB Handler
        JMP     START   ;TIM1_OVF ; Timer1 Overflow Handler
        JMP     START   ;TIM0_COMP ; Timer0 Compare Handler
        JMP     TIM0_OVF ; Timer0 Overflow Handler
        JMP     START   ;SPI_STC ; SPI Transfer Complete Handler
        JMP     START   ;USART0_RXC ; USART0 RX Complete Handler
        JMP     START   ;USART0_DRE ; USART0,UDR Empty Handler
        JMP     START   ;USART0_TXC ; USART0 TX Complete Handler
        JMP     START   ;ADC ; ADC Conversion Complete Handler
        JMP     START   ;EE_RDY ; EEPROM Ready Handler
        JMP     START   ;ANA_COMP ; Analog Comparator Handler
        JMP     START   ;TIM1_COMPC ; Timer1 CompareC Handler
        JMP     START   ;TIM3_CAPT ; Timer3 Capture Handler
        JMP     TIM3_COMPA ; Timer3 CompareA Handler
        JMP     START   ;TIM3_COMPB ; Timer3 CompareB Handler
        JMP     START   ;TIM3_COMPC ; Timer3 CompareC Handler
        JMP     START   ;TIM3_OVF ; Timer3 Overflow Handler
        JMP     USART1_RXC ; USART1 RX Complete Handler
        JMP     USART1_DRE ; USART1,UDR Empty Handler
        JMP     START   ;USART1_TXC ; USART1 TX Complete Handler
        JMP     START   ;TWI_INT ; Two-wire Serial Interface Interrupt Handler
        JMP     START   ;SPM_RDY ; SPM Ready Handler

        .DW     0,0
        .DB     "================"
        .DB     " ZX Evo Service "
        .DB     "================"
;
;--------------------------------------
;
.INCLUDE "_message.inc"
.INCLUDE "_t_sd.asm"
.INCLUDE "_uart.asm"
.INCLUDE "_timers.asm"
.INCLUDE "_pintest.asm"
.INCLUDE "_ps2k.asm"
.INCLUDE "_t_ps2k.asm"
.INCLUDE "_t_ps2m.asm"
.INCLUDE "_output.asm"
.INCLUDE "_screen.asm"
;
;--------------------------------------
;����� � ॣ���ࠬ� � FPGA
;in:    TEMP == ����� ॣ����
;       DATA == �����
;out:   DATA == �����
FPGA_REG:
        PUSH    DATA
        SPICS_SET
        OUT     SPDR,TEMP
        RCALL   FPGA_RDY_RD
        POP     DATA
;����� ��� ��⠭���� ॣ����
;in:    DATA == �����
;out:   DATA == �����
FPGA_SAME_REG:
        SPICS_CLR
        OUT     SPDR,DATA
;�������� ����砭�� ������ � FPGA �� SPI
;� �⥭�� ��襤�� ������
;out:   DATA == �����
FPGA_RDY_RD:
;        SBIC    SPSR,WCOL
;        JMP     CHAOS00
        SBIS    SPSR,SPIF
        RJMP    FPGA_RDY_RD
        IN      DATA,SPDR
        SPICS_SET
        RET
;
;--------------------------------------
;
EXT_INT6:
        PUSH    BITS
        IN      BITS,SREG
        SBRC    INT6VECT,0
        CALL    T_BEEP_INT
        SBRC    INT6VECT,1
        STS     NEWFRAME,ONE
        OUT     SREG,BITS
        POP     BITS
        RETI
;
;--------------------------------------
;
.INCLUDE "_sd_lowl.asm"
.INCLUDE "_t_zxkbd.asm"
.INCLUDE "_t_beep.asm"
.INCLUDE "_sd_fat.asm"
.INCLUDE "_depack.asm"
.INCLUDE "_flasher.asm"
.INCLUDE "_t_video.asm"
.INCLUDE "_t_dram.asm"
.INCLUDE "_misc.asm"
;
;--------------------------------------
;
START:  CLI
        CLR     R0
        LDIZ    $0001
CLRALL1:ST      Z+,R0
        CPI     ZL,$1E
        BRNE    CLRALL1
        LDI     ZL,$20
CLRALL2:ST      Z+,NULL
        CPI     ZH,$11
        BRNE    CLRALL2
        INC     ONE
        DEC     FF
;
        LDI     TEMP,LOW(HSTACK)
        OUT     SPL,TEMP
        LDI     TEMP,HIGH(HSTACK)
        OUT     SPH,TEMP
        LDIX    RND
        ST      X+,TEMP
        ST      X+,FF
        ST      X+,ONE
;
        LDIW    EE_MODE1
        CALL    EEPROM_READ
        MOV     MODE1,DATA
        LDI     WL,LOW(EE_LANG)
        CALL    EEPROM_READ
        CPI     DATA,MAX_LANG
        BRCS    RDE1
        CLR     DATA
RDE1:   LSL     DATA
        MOV     LANG,DATA
;
        CALL    PINTEST
; - - - - - - - - - - - - - - -
        LDI     TEMP,      0B11111111
        OUTPORT PORTG,TEMP
        LDI     TEMP,      0B00000000
        OUTPORT DDRG,TEMP

        LDI     TEMP,      0B00001000
        OUTPORT PORTF,TEMP
        OUTPORT DDRF,TEMP

        LDI     TEMP,      0B11111111
        OUT     PORTE,TEMP
        LDI     TEMP,      0B00000000
        OUT     DDRE,TEMP

        LDI     TEMP,      0B11111111
        OUT     PORTD,TEMP
        LDI     TEMP,      0B00000000
        OUT     DDRD,TEMP

        LDI     TEMP,      0B11011111
        OUT     PORTC,TEMP
        LDI     TEMP,      0B00000000
        OUT     DDRC,TEMP

        LDI     TEMP,      0B11111001
        OUT     PORTB,TEMP
        LDI     TEMP,      0B10000111
        OUT     DDRB,TEMP

        LDI     TEMP,      0B11111111
        OUT     PORTA,TEMP
        LDI     TEMP,      0B00000000
        OUT     DDRA,TEMP
; - - - - - - - - - - - - - - -
        LDIZ    MLMSG_STATUSOF_CRLF*2
        CALL    POWER_STATUS
        SBIS    PINF,0 ;VCC5
        RJMP    UP10
        SBIS    PINC,5 ;POWERGOOD
        RJMP    UP11
        RJMP    UP19
UP10:   LDIZ    MLMSG_POWER_ON*2
        CALL    PRINTMLSTR
;��� ����祭�� ATX, � ��⮬ ��� ����-����.
UP12:   SBIC    PINF,0 ;VCC5
        RJMP    UP11
        LDIZ    MLMSG_STATUSOF_CR*2
        CALL    POWER_STATUS
        RJMP    UP12
UP11:   LDI     COUNT,170 ;170 ࠧ �� 31 ᨬ���� �� ᪮��� 115200 = ~500ms
UP13:   PUSH    COUNT
        LDIZ    MLMSG_STATUSOF_CR*2
        CALL    POWER_STATUS
        POP     COUNT
        DEC     COUNT
        BRNE    UP13
UP19:
; - - - - - - - - - - - - - - -
        LDIZ    MLMSG_CFGFPGA*2
        CALL    PRINTMLSTR
;SPI init
        LDI     TEMP,(1<<SPI2X)
        OUT     SPSR,TEMP
        LDI     TEMP,(1<<SPE)|(1<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)
        OUT     SPCR,TEMP
;����㧪� FPGA
        INPORT  TEMP,DDRF
        SBR     TEMP,(1<<nCONFIG)
        OUTPORT DDRF,TEMP

        DELAY_US 40

        INPORT  TEMP,DDRF
        CBR     TEMP,(1<<nCONFIG)
        OUTPORT DDRF,TEMP

LDFPGA1:SBIS    PINF,nSTATUS
        RJMP    LDFPGA1

        LDIZ    PACKED_FPGA*2
        OUT     RAMPZ,ONE
        CALL    DMLZ_INIT
LDFPGA3:CALL    DMLZ_GETBYTE
        BREQ    LDFPGA_DONE
        OUT     SPDR,DATA
LDFPGA2:SBIS    SPSR,SPIF
        RJMP    LDFPGA2
        RJMP    LDFPGA3
LDFPGA_DONE:
        SBIS    PINF,CONF_DONE
        RJMP    LDFPGA_DONE

        LDIZ    $0100
CLRRAM: ST      Z+,NULL
        CPI     ZH,$11
        BRNE    CLRRAM

;SPI reinit
        LDI     TEMP,(1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)
        OUT     SPCR,TEMP
; - - - - - - - - - - - - - - -
        LDIZ    MLMSG_DONE*2
        CALL    PRINTMLSTR
        DELAY_US 200
        LDIY    DSTACK
;
        CALL    UART_INIT
        CALL    PS2K_INIT
        CALL    TIMERS_INIT
        IN      TEMP,EICRB
        ORI     TEMP,(1<<ISC61)|(0<<ISC60)
        OUT     EICRB,TEMP
        IN      TEMP,EIMSK
        ORI     TEMP,(1<<INT6)
        OUT     EIMSK,TEMP
        SEI

        MOV     DATA,MODE1
        ORI     DATA,0B11111110
        LDI     TEMP,SCR_MODE
        CALL    FPGA_REG
        LDI     DATA,0B00000000
        LDI     TEMP,INT_CONTROL
        CALL    FPGA_REG

        CALL    PS2K_DETECT_KBD

        LDI     DATA,$01
        LDI     TEMP,MTST_CONTROL
        CALL    FPGA_REG

        LDIZ    MSG_READY*2
        CALL    PRINTSTRZ
        CALL    SCR_KBDSETLED
;
NOEXIT:
        LDIZ    MENU_MAIN*2
        CALL    MENU
        RJMP    NOEXIT
;
MSG_READY:
        .DB     "---",$0D,$0A,0
;
;--------------------------------------
;
POWER_STATUS:
        CALL    PRINTMLSTR
        LDIZ    MSG_POWER_PG*2
        CALL    PRINTSTRZ
        LDI     DATA,$30 ;"0"
        SBIC    PINC,5 ;POWERGOOD
        LDI     DATA,$31 ;"1"
        CALL    HEXHALF
        LDIZ    MSG_POWER_VCC5*2
        CALL    PRINTSTRZ
        LDI     DATA,$30 ;"0"
        SBIC    PINF,0 ;VCC5
        LDI     DATA,$31 ;"1"
        JMP     HEXHALF
;
;--------------------------------------
;
;NOTHING:RET
;
;--------------------------------------
;
.NOLIST
        .ORG    $7F80
TABL_SINUS:
.INCLUDE "sin256.inc"
        .ORG    $8000
PACKED_FPGA:
.INCLUDE "fpga.inc"
;
;--------------------------------------
;
