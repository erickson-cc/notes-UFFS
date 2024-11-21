LIBRARY ieee;
USE iee.numeric_std.all;
USE ieee.std_logic_1164.ALL;


ENTITY blackjack IS PORT (



   ------ Variáveis ------
	
	HIT: in STD_LOGIC;
	STAY: in STD_LOGIC;
	START: in STD_LOGIC;--Reset
	CLOCK: in STD_LOGIC;
	RANDOM_CARDS: in STD_LOGIC;
	CARDS: in STD_LOGIC_VECTOR (3 downto 0);

	VEZ_DO_PLAYER: out STD_LOGIC;
	VEZ_DO_DEALER: out STD_LOGIC;
	LED_EMPATE: out STD_LOGIC;
	LED_PERDEU: out STD_LOGIC;
	LED_GANHOU: out STD_LOGIC;


   );

END ENTITY blackjack;


ARCHITECTURE behave OF blackjack IS

   TYPE tipo_estado IS (
	inicio,--
	player_recebe_1,--
	player_recebe_2,--
	player_choice,--
	player_hit,--
	dealer_recebe_1,--
	dealer_recebe_2,--
	dealer_choice,--
	dealer_hit,--
	compara,--
	empate,--
	perdeu,--
	ganhou--
	);
--	function puxar_carta(carta: STD_LOGIC_VECTOR(4 downto 0); nova: STD_LOGIC_VECTOR(3 downto 0); As: STD_LOGIC)
--		return STD_LOGIC_VECTOR is
--			variable result: STD_LOGIC_VECTOR(4 downto 0);

	signal estado : tipo_estado;
--	signal carta: STD_LOGIC_VECTOR(4 downto 0) := "00000";

   BEGIN

       process(CLOCK, START)
	variable carta_manual : STD_LOGIC_VECTOR(3 downto 0) := "0000";--if not random_cards
	variable carta_int : integer range 0 to 20 := 0;
           BEGIN

               if(START = '1') then

                   estado <= inicio;
							--downrising_edge(KEY(0))
               elsif(CLOCK'EVENT AND CLOCK = '0') then

                   case estado is
			when Start =>
				estado <= player_recebe_1;

			when player_recebe_1 =>
				estado <= dealer_recebe_1;

			when dealer_recebe_1 =>
				estado <= player_recebe_2;

			when player_recebe_2 =>
				estado <= dealer_recebe_2;

			when dealer_recebe_2 =>
				estado <= player_choice;

			when player_choice =>
				if(HIT = '1' and STAY = '0') then
					estado <= player_hit;
				elsif(STAY = '1' and HIT = '0') then
					estado <= dealer_choice;
				end if;

			when player_hit =>
				if(player_hand > 21) then
					estado <= perdeu;
				else
					estado <= player_choice;
				end if;
			when dealer_choice => --Espera dealer
				if(dealer_hand < 17) then
					estado <= dealer_hit;
				else
					estado <= compara;
				end if;

			when dealer_hit =>
				if(dealer_hand > 21) then
					estado <= compara;
				else
					estado <= dealer_choice;
				end if;
				
			when compara => -- Talvez tirar esse estado e comparar no player-stay
				if(dealer_hand > 21) then
					estado <= ganhou;
				elsif(dealer_hand = player_hand) then
					estado <= empate;
				elsif(dealer_hand > player_hand) then
					estado <= perdeu;
				end if;

			when empate => estado <= estado;
			when ganhou => estado <= estado;
			when perdeu => estado <= estado;
                    end case;
	    end if;-- if do clock

       end process;

       process(estado)

           BEGIN
                   case estado is
			when Start =>

			when player_recebe_1 =>
				VEZ_DO_PLAYER <= '1';
				VEZ_DO_DEALER <= '0';
			when dealer_recebe_1 =>
				VEZ_DO_DEALER <= '1';

			when player_recebe_2 =>
				VEZ_DO_PLAYER <= '1';
				VEZ_DO_DEALER <= '0';

			when dealer_recebe_2 =>

			when player_choice =>
				VEZ_DO_PLAYER <= '1';
				VEZ_DO_DEALER <= '0';

			when player_hit =>
				VEZ_DO_PLAYER <= '0';
				VEZ_DO_DEALER <= '0';

			when dealer_choice => --Espera dealer
				VEZ_DO_PLAYER <= '0';
				VEZ_DO_DEALER <= '1';

			when dealer_hit =>
				VEZ_DO_PLAYER <= '0';
				VEZ_DO_DEALER <= '0';
				
			when compara => 
				VEZ_DO_PLAYER <= '0';
				VEZ_DO_DEALER <= '0';

			when empate => 
				VEZ_DO_PLAYER <= '0';
				VEZ_DO_DEALER <= '0';
				LED_EMPATE <= '1';
			when ganhou =>
				VEZ_DO_PLAYER <= '0';
				VEZ_DO_DEALER <= '0';
				LED_GANHOU <= '1';
			when perdeu =>
				VEZ_DO_PLAYER <= '0';
				VEZ_DO_DEALER <= '0';
				LED_PERDEU <= '1';
                    end case;

       end process;
end architecture;
