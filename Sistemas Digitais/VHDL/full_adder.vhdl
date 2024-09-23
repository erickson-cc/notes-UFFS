LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY adder3bits IS
	PORT (
		a_f, b_f: in STD_LOGIC_VECTOR(2 downto 0);
		overflow: out STD_LOGIC;
		sum: out STD_LOGIC_VECTOR(2 downto 0)
	);

End ENTITY adder3bits;

ARCHITECTURE behav_estrutural OF adder3bits IS
	COMPONENT full_adder IS
		PORT (
			a_f,b_f: in STD_LOGIC;
			carry_in: in STD_LOGIC;
			carry_out, sum: out STD_LOGIC
		);
	END COMPONENT;
	SIGNAL c0,c1,c2: STD_LOGIC;
BEGIN
	fa0 : full_adder
	port map(
		a_f=>A(0),-- af é um vetor
		b_f=>B(0),
		carry_in=>'0',
		carry_out=>c0,-- signal,o carry vai sair do FA0 e ir para o FA1
		sum=>sum(0)
	);
	fa1 : full_adder
	port map(
		a_f=>A(1),-- af é um vetor
		b_f=>B(2),
		carry_in=>c0,
		carry_out=>c1,-- signal,o carry vai sair do FA0 e ir para o FA1
		sum=>sum(1)
	);
	fa2 : full_adder
	port map(
		a_f=>A(2),-- af é um vetor
		b_f=>B(2),
		carry_in=>c1,
		carry_out=>c2,-- signal,o carry vai sair do FA0 e ir para o FA1
		sum=>sum(2)
	);
-- agora a única coisa que falta é mapear o c2 pro overflow
	overflow<=c2;
END ARCHITECTURE;
