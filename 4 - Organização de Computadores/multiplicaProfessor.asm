.data	0x1001000 #Podemos especificar a memória, esse valor é o default

MSG_VALOR1:	.string	"Insira o valor A: "
MSG_VALOR2:	.asciz	"Insira o valor B: "
MSG_FINAL:	.string	"Resultado da Multiplicação: "
VALOR_A: 	.word	0
VALOR_B:	.space	4

.text	0x400000
main:
	#ESCREVER MENSAGEM
	la a0, MSG_VALOR1
	li a7, 4
	ecall

	#LER INPUT
	li a7, 5
	ecall
	mv s0, a0

	#ESCREVER MENSAGEM
	la a0, MSG_VALOR2
	li a7, 4
	ecall

	#LER INPUT
	li a7, 5
	ecall
	mv s1, a0

	#PASSAR ARGUMENTOS USANDO A PILHA (Reg. sp)
	addi sp, sp, -8 # A pilha cresce de forma decrescente
	sw s0, 0(sp)
	sw s1, 4(sp)	
	call multiplica_1
	mv t0, a0,

	la a0, MSG_FINAL
	li a7, 4
	ecall
	
	mv a0, t0
	li a7, 1
	ecall

	li a7, 10 #Informa que o programa acabou
	ecall

multiplica_1:
	lw a0, 0(sp)
	lw a1, 4(sp)
	addi sp, sp, 8 #Limpa a pilha
	
	li t3, 0
	li t2, 0
loop:
	beq t2, a1, end_loop
	add t3, t3, a0
	addi t2, t2, 1
	j loop
end_loop:
	mv a0, t3
	ret
