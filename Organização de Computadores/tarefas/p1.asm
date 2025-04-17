;usar s0, s1, s2
;esses 3 registradores tem 3 numeros inteiros
;fazer um programa que carrega em t0 o maior número entre os três registradores

.data
.text

	li s0, 4
	li s1, 3
	li s2, 4
retorna: 
	nop
zeromaior:
	mv t0, s0
	bge s1, t0, ummaior
	j retorna
ummaior:
	mv t0, s1
	bge s2 t0, doismaior
	j retorna
doismaior:
	mv t0, s2
	j retorna
;Tem uma resposta nos slides
