.data 0x10010000
byte1:	.byte 30	# 10000
var1:	.space 2	# 10001
value1:	.word 10	# 10003
byte2:	.byte 12	# 10007
value2:	.word 10	# 10008

.text
	la t1, value1
	li t2, 111
	sw t2, 0(t1)