import sympy

def somaRiemann(funcao, a, b, n):
  x = sympy.Symbol('x')
  f = sympy.sympify(funcao)

  delta_x = (b - a) / n #Largura dos retângulos

  area = 0
  for i in range(n):
    x_i = a + i * delta_x + delta_x / 2 #Ponto médio dos retângulos
    altura = f.subs(x, x_i)
    area += altura * delta_x

  return area

###Inputs
funcao = str(input("escreva a função f(x): "))
a = int(input("Insira o valor de a: "))
b = int(input("Insira o valor de b: "))
n = int(input("insira o valor de n: "))  # Número de retângulos

resultado = somaRiemann(funcao, a, b, n)
print("A área aproximada usando a Soma de Riemann é: {:.3f} unidades de área".format(resultado))