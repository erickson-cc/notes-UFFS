# qtd_comparação:
#	a0: endereço do vetor
#	a1: comprimento vetor
#	a2: número para comparação

# retorna:
#	a0: quantidade de elementos menores que a2
#	a1: número no vetor cuja diferença com a2 seja a maior

qtd_comparação:
	addi	sp, sp, -16	# Alocar espaço na pilha
	sw	ra, 12(sp)	# Salvar o endereço de retorno
	sw	s0, 8(sp)	# Salvar s0
	sw	s1, 4(sp)	# Salvar s1

	li	a0, 0		# Inicializar contador de elementos menores
	li	a1, 0		# Inicializar índice de maior diferença
	mv	s0, a2		# Copiar a2 para s0
	mv	t0, a1		# Copiar tamanho do vetor para t0
	
loop:
	beq 	t0, zero, fim	# if(t0==0) break;
	lw	t1, 0(a0)	# Carregar elemento atual
	blt	t1, s0, menor	# if(elemento<a2), ir para menor
	# Calcular a diferença absoluta e comparar
	sub	t2, t1, s0
	bltz	t2, neg
	mv	t2, t2

neg:
	bge	t2, a1, continua# if(diferença<=a1) ir para continua
	mv	a1, t2	
	addi	s1, t0, -1	# Calcular índice
	mv	a1, s1

continua:
	addi	a0, a0, 1	# Incrementar contador
	addi	a0, a0, 3	# Avançar para o próximo elemento
	addi	t0, t0, -1	# Decrementar contador do loop
	j	loop

menor:
	addi	a0, a0, 1	# Incrementar contador
	addi	a0, a0, 4	# Avançar para o próximo elemento
	addi	t0, t0, -1	# Decrementar contador do loop
	j 	loop

fim:
	lw	ra, 12(sp)	# Restaurar o endereço de retorno
	lw	s0, 8(sp)	# Restaurar s0
	lw	s1, 4(sp)	# Restaurar s1
	addi	sp, sp, 16	# LIberar espaço na pilha
	ret			# Retornar
	
