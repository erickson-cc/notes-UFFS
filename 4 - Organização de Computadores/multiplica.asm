# 5 - Ler Inteiro
# 4 - Imprimir String
# 1 - Imprimir Inteiro
.data
MSG_VALOR1:	.string "Entre com o Valor A: "
MSG_VALOR2:	.asciz "Entre com o Valor B: "
MSG_FINAL:	.string "Resultado da Multiplicação: "
#	str: .asciz "Ola mundo"
.text
ler_inteiros:
	li a7, 5
	ecall
	mv t0, a0 #mover o int para t0
	
	li a7, 5
	ecall
	mv t1, a0 #mover o int para t1
	
	li t2, 0 #usado para fazer o loop do multiplica_1
	li t3, 0
	#jal multiplica_1
	li t3, 0
	li s9, 1 #usado para comparar o último bit
	j multiplica_2
multiplica_1:

	beq t2, t1, imprimir_1
	addi t2, t2, 1
	add t3, t3, t0
	j multiplica_1
	ret
multiplica_2:
	
	beq t1, zero, fim_multiplica
	
	li s10, 2 # Usado para calcular o resto
	li s11, 0 # Usado para verificar se (t1&1), Linha pode ser descartada.
	rem s11, t1, s10
	bne s11, s9, not_equal
	add t3, t3, s11
not_equal:
	slli t0, t0, 1
	srli t1, t1, 9	
	j multiplica_2

fim_multiplica:
	j imprimir_1
	ret
imprimir_1:
	mv a0, t3
	li a7, 1
	ecall
	#ret
		
#multiplica_2:

	

