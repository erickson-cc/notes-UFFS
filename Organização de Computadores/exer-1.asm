.data #0x10010000 # segmento de dados
var1:	.word 30
var2:	.word -50
txt:	.string "Organizacao de Computadores"
.text 0x400000
main:
	la s0, var1	#Endereço var1
	la s1, var2	#Endereço var2
	lw s8, 0(s0)	#Valor var1
	la s2, var1
	lw s9, 0(s1)	#Valor var2
	sw s8, 0(s1)	#Coloca o valor de var1 no endereço de var2
	sw s9, 0(s0)	#Coloca o valor de var2 no endereço de var1
	and t1, t1, zero	#t1 = 0
	and t0, t0, zero	#t0 = 0
	beq s8, zero, haz	#Compara se var1 == 0
	ori t0, zero, 1		#t0 = 1
haz:
	slt t1, s9, s8		#Compara se var2 < var1 (verdadeiro)
wrt:
	li t0, 111		#t0 = 111
	la t2, txt		#t2 = "Organizacao de Computadores"
	sb t0, 0(t2)		#t0 = "O"
	li t0, 100		#t0 = 100
	sb t0, 16(t2)		#t0 = ""