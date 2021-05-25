	cpu	pmc884
	page	0

databit3	bit	[0xef].3
databit4	bit	[0xef],4
databit5	bit	databit4+1
portbit5	bit	io(0x34).5
portbit6	bit	io(0x34).6
portbit8	bit	portbit6+2

	nop			; 0x0000

	addc	a		; 0x0010
	subc	a		; 0x0011
	izsn	a		; 0x0012
	dzsn	a		; 0x0013
	pcadd	a		; 0x0017
	not	a		; 0x0018
	neg	a		; 0x0019
	sr	a		; 0x001a
	sl	a		; 0x001b
	src	a		; 0x001c
	slc	a		; 0x001d
	swap	a		; 0x001e
	delay	a		; 0x001f

	wdreset			; 0x0030
	pushaf			; 0x0032
	popaf			; 0x0033
	reset			; 0x0035
	stopsys			; 0x0036
	stopexe			; 0x0037
	engint			; 0x0038
	disgint			; 0x0039
	ret			; 0x003a
	reti			; 0x003b
	mul			; 0x003c

	pmode	0x1e		; 0x005e
	pmode	#0x1f		; 0x005f
	popwpc	0x0e		; 0x006e
	popwpc	#0x0f		; 0x006f
	pushwpc	0x0e		; 0x007e
	pushwpc	#0x0f		; 0x007f

	mov	io(0x34),a	; 0x00b4
	mov	a,io(0x34)	; 0x00f4

	stt16	[0xfe]		; 0x02fe
	ldt16	[0xfe]		; 0x02ff
	popw	[0xfe]		; 0x04fe
	pushw	[0xfe]		; 0x04ff
	igoto	[0xfe]		; 0x06fe
	icall	[0xfe]		; 0x06ff
	idxm	[0xfe],a	; 0x08fe
	idxm	a,[0xfe]	; 0x08ff
	ldtabl	[0xfe]		; 0x0afe
	ldtabh	[0xfe]		; 0x0aff

	delay	0xab		; 0x0eab
	delay	#0xab		; 0x0eab
	ret	0xab		; 0x0fab
	ret	#0xab		; 0x0fab

	xor	io(0x34),a	; 0x1034
	xor	a,io(0x34)	; 0x1074

	cneqsn	[0xef],a	; 0x14ef
	cneqsn	a,[0xef]	; 0x16ef

	add	a,0xab		; 0x18ab
	sub	a,0xab		; 0x19ab
	ceqsn	a,0xab		; 0x1aab
	cneqsn	a,0xab		; 0x1bab
	and	a,0xab		; 0x1cab
	or	a,0xab		; 0x1dab
	xor	a,0xab		; 0x1eab
	mov	a,0xab		; 0x1fab

	t0sn	io(0x34).5	; 0x2174
	t0sn	portbit5	; 0x2174
	t0sn	io(0x34),6	; 0x21b4
	t0sn	portbit6	; 0x21b4
	t0sn	io(0x35),0	; 0x2035
	t0sn	portbit8	; 0x2035
	t1sn	io(0x34).5	; 0x2374
	t1sn	portbit5	; 0x2374
	t1sn	io(0x34),6	; 0x23b4
	t1sn	portbit6	; 0x23b4
	t1sn	io(0x35),0	; 0x2235
	t1sn	portbit8	; 0x2235
	set0	io(0x34).5	; 0x2574
	set0	portbit5	; 0x2574
	set0	io(0x34),6	; 0x25b4
	set0	portbit6	; 0x25b4
	set0	io(0x35),0	; 0x2435
	set0	portbit8	; 0x2435
	set1	io(0x34).5	; 0x2774
	set1	portbit5	; 0x2774
	set1	io(0x34),6	; 0x27b4
	set1	portbit6	; 0x27b4
	set1	io(0x35),0	; 0x2635
	set1	portbit8	; 0x2635
	tog	io(0x34).5	; 0x2974
	tog	portbit5	; 0x2974
	tog	io(0x34),6	; 0x29b4
	tog	portbit6	; 0x29b4
	tog	io(0x35),0	; 0x2835
	tog	portbit8	; 0x2835
	wait0	io(0x34).5	; 0x2b74
	wait0	portbit5	; 0x2b74
	wait0	io(0x34),6	; 0x2bb4
	wait0	portbit6	; 0x2bb4
	wait0	io(0x35),0	; 0x2a35
	wait0	portbit8	; 0x2a35
	wait1	io(0x34).5	; 0x2d74
	wait1	portbit5	; 0x2d74
	wait1	io(0x34),6	; 0x2db4
	wait1	portbit6	; 0x2db4
	wait1	io(0x35),0	; 0x2c35
	wait1	portbit8	; 0x2c35
	swapc	io(0x34).5	; 0x2f74
	swapc	portbit5	; 0x2f74
	swapc	io(0x34).6	; 0x2fb4
	swapc	portbit6	; 0x2fb4
	swapc	io(0x35).0	; 0x2e35
	swapc	portbit8	; 0x2e35

	nmov	a,[0xef]	; 0x30ef
	nmov	[0xef],a	; 0x32ef
	nadd	a,[0xef]	; 0x34ef
	nadd	[0xef],a	; 0x36ef
	ceqsn	a,[0xef]	; 0x38ef
	ceqsn	[0xef],a	; 0x3aef
	comp	a,[0xef]	; 0x3cef
	comp	[0xef],a	; 0x3eef
	add	[0xef],a	; 0x40ef
	add	a,[0xef]	; 0x42ef
	sub	[0xef],a	; 0x44ef
	sub	a,[0xef]	; 0x46ef
	addc	[0xef],a	; 0x48ef
	addc	a,[0xef]	; 0x4aef
	subc	[0xef],a	; 0x4cef
	subc	a,[0xef]	; 0x4eef
	and	[0xef],a	; 0x50ef
	and	a,[0xef]	; 0x52ef
	or	[0xef],a	; 0x54ef
	or	a,[0xef]	; 0x56ef
	xor	[0xef],a	; 0x58ef
	xor	a,[0xef]	; 0x5aef
	mov	[0xef],a	; 0x5cef
	mov	a,[0xef]	; 0x5eef

	addc	[0xef]		; 0x60ef
	subc	[0xef]		; 0x62ef
	izsn	[0xef]		; 0x64ef
	dzsn	[0xef]		; 0x66ef
	inc	[0xef]		; 0x68ef
	dec	[0xef]		; 0x6aef
	clear	[0xef]		; 0x6cef
	xch	[0xef]		; 0x6eef
	not	[0xef]		; 0x70ef
	neg	[0xef]		; 0x72ef
	sr	[0xef]		; 0x74ef
	sl	[0xef]		; 0x76ef
	src	[0xef]		; 0x78ef
	slc	[0xef]		; 0x7aef
	swap	[0xef]		; 0x7cef
	delay	[0xef]		; 0x7eef

	t0sn	[0xef].3	; 0x86ef
	t0sn	databit3	; 0x86ef
	t0sn	[0xef],4	; 0x88ef
	t0sn	databit4	; 0x88ef
	t0sn	[0xef],5	; 0x8aef
	t0sn	databit5	; 0x8aef
	t1sn	[0xef].3	; 0x96ef
	t1sn	databit3	; 0x96ef
	t1sn	[0xef],4	; 0x98ef
	t1sn	databit4	; 0x98ef
	t1sn	[0xef],5	; 0x9aef
	t1sn	databit5	; 0x9aef
	set0	[0xef].3	; 0xa6ef
	set0	databit3	; 0xa6ef
	set0	[0xef],4	; 0xa8ef
	set0	databit4	; 0xa8ef
	set0	[0xef],5	; 0xaaef
	set0	databit5	; 0xaaef
	set1	[0xef].3	; 0xb6ef
	set1	databit3	; 0xb6ef
	set1	[0xef],4	; 0xb8ef
	set1	databit4	; 0xb8ef
	set1	[0xef],5	; 0xbaef
	set1	databit5	; 0xbaef

	goto	0xdef		; 0xcdef
	call	0xdef		; 0xedef

	data	1000,5000,9000,13000,17000,23000,27000,31000,35000,39000,43000,47000,51000,55000,59000,63000
	expect	1320
	data	67000
	endexpect
	data	"12345678"

uart	struct
data	res	1
ctrl	res	1
txen	bit	ctrl,0
rxen	bit	ctrl,1
stat	res	1
drdy	bit	stat,0
txempt	bit	stat,1
rxovr	bit	stat,2
txovr	bit	stat,3
	endstruct

	segment	data

	org	0x08
uart1	uart
