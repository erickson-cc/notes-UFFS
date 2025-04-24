# 5 - Ler Inteiro
# 4 - Imprimir String
# 1 - Imprimir Inteiro
.data
#	str: .asciz "Ola mundo"
.text
ler_inteiros:
	li a7, 5
	ecall
	mv t0, a0 #mover o int para t0
	
	li a7, 5
	ecall
	mv t1, a0 #mover o int para t0
	
	li t2, 0 #usado para fazer o loop do multiplica_1
	li t3, 0
	#j multiplica_1
multiplica_1:

	beq t2, t1, imprimir_1
	addi t2, t2, 1
	add t3, t3, t0
	j multiplica_1
imprimir_1:
	mv a0, t3
	li a7, 1
	ecall
	#ret
		
#multiplica_2:

	

