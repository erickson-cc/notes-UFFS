LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY sistema IS PORT (
	LEDR: out STD_LOGIC_VECTOR (9 downto 0);
	SW: in STD_LOGIC_VECTOR (9 downto 0)
	-- SW(9): Botão de modo seguro{0:inativo}{1:ativo}
	-- SW(8): Janela{0:fechada}{1:aberta}
	-- SW(7): Porta {0:fechada}{1:aberta}
	
	-- SW(3): sensor CAIXA A bit 1
	-- SW(2): sensor CAIXA A bit 0
	
	-- SW(1): sensor CAIXA B bit 1
	-- SW(0): sensor CAIXA B bit 0
	
	
	-- LEDR(9): Sinal de Alerta {SW(9)andSW(8)}
	-- LEDR(8): Sinal Janela ABERTA {SW(8)}
	-- LEDR(7): Sinal Porta ABERTA {SW(7)}
	-- LEDR(3): Eletroválvula {SW(3)}
	-- LEDR(1): Bomba {SW(3)orSW(2)}nand{SW(1)andSW(0)}
	);
END ENTITY sistema;

ARCHITECTURE behave OF sistema IS
	BEGIN
		LEDR(9) <= SW(9) and (SW(8) or SW(7));
		LEDR(8) <= SW(8);
		LEDR(7) <=2 SW(7);
		
		LEDR(3) <= not SW(3);
		LEDR(1) <= (SW(3) or SW(2)) and (SW(1)nand SW(0));
		
END ARCHITECTURE;
