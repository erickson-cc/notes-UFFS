.data
vetor:	.word	0,1,0,1,-1,-1

.text
main:
	la a0, vetor
	li a1, 6
	call funcao
	
	li a7, 1
	ecall
	
	mv a0, a1
	ecall
	
	mv a0, a2
	ecall
	
	li a7, 10
	ecall
	
funcao:
	mv t0, a0
	mv t1, a1
	li t2, 0
	li t3, 0
	li t3, 0
loop:
	beq t2,t1, fim
	slli t5, t2, 2
	add t5, t5, t0
	lw t5, 0(t5)
	blt t5, zero, incrementa_negativo
	bgt t5, zero, incrementa_positivo
	j proximo
incrementa_positivo:
	addi t4, t4, 1
	j proximo
incrementa_negativo:
	addi t3, t3,1
proximo:
	addi t2, t2, 1
	j loop
fim:
	mv a0, t3
	add t2, t3, t4
	sub t1, t1, t2
	mv a1, t1
	mv a2, t4
	ret