hand = soma das cartas
carta
hit: in (pedir carta)
stay: in (manter hand)
    O jogador não pode pedir hit após dar um stay.

# Regras
Há apenas o player e o dealer
O baralho possui 52 cartas
Start funciona como reset
Os estados mudam com a borda de descida do clock
hit e stay não são pressionados simultaneamente
estado inicial = eStart
O dealer vai pedir hit enquanto a dHand for menor que 17
# Botões
hit: in std_logic;
stay: in std_logic;
start: in std_logic;
cards: in std_logic_vector(9 downto 0);
Random_Cards: in std_logic;
clock: in std_logic;
# Saídas
win: out std_logic;
lose: out std_logic;
tie: out std_logic;
card: out std_logic_vector(7 downto 0);
hand1: out std_logic_vector(7 downto 0);
hand0: out std_logic_vector(7 downto 0);

# Estados
.Entregando+Hit
.Entregando+Stay
.Comparando
.Vez do Dealer
