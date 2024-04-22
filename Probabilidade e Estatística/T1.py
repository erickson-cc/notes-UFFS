#P(x) = Cn,x . (p)^[x] . (q)^[n-x]
import math

#Probabilidade Favorável
while True:
    probFav = float(input("Informe a Chance em porcentagem de o evento acontecer: "))/100
    if probFav>=0 and probFav<=1:
        break
    else:
        print("A chance deve ser entre 0% e 100%")
#Probabilidade Contrária
probCon = 1 - probFav
cFavs = int(input("Casos Favoráveis: "))
cPoss = int(input("Casos Possíveis: "))


def ProbBinInd(probFav,probCon,cFavs,cPoss):
    return 100*math.factorial(cPoss)/(math.factorial(cPoss-cFavs)*math.factorial(cFavs)) * (probFav**cFavs) * (probCon**(cPoss-cFavs))
def ProbBinAcu_menor(probFav,probCon,cFavs,cPoss):
    prob = 0
    while cFavs >= 0:
        prob += ProbBinInd(probFav,probCon,cFavs,cPoss)
        cFavs -= 1
    return prob
def ProbBinAcu_maior(probFav,probCon,cFavs,cPoss):
    prob = 0
    while cFavs <= cPoss:
        prob += ProbBinInd(probFav,probCon,cFavs,cPoss)
        cFavs += 1
    return prob

if cFavs == 1:
    x = "vez"
else:
    x = "vezes"
print(f"\nProbabilidade de o evento acontecer exatamente {cFavs} {x}: {ProbBinInd(probFav,probCon,cFavs,cPoss):.2f}%")
print(f"Probabilidade de o evento acontecer no máximo {cFavs} {x}: {ProbBinAcu_menor(probFav,probCon,cFavs,cPoss):.2f}%")
print(f"Probabilidade de o evento acontecer no mínimo {cFavs} {x}: {ProbBinAcu_maior(probFav,probCon,cFavs,cPoss):.2f}%")
    

