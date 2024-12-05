LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
ENTITY blackjack IS PORT (

   ------ Variáveis ------

     KEY: in STD_LOGIC_VECTOR(3 downto 0);

        -- KEY(1) START
        -- KEY(0) = CLOCK        

    SW: in STD_LOGIC_VECTOR(9 downto 0);

        -- SW(9) = HIT
        -- SW(8) = STAY
        -- SW CARDS

    LEDR : out STD_LOGIC_VECTOR(9 downto 0); -- perdeu
    LEDG : out STD_LOGIC_VECTOR(7 downto 0); -- ganhou

    HEX0 : out STD_LOGIC_VECTOR(6 downto 0); -- CARDDISPLAY2 UNIDADE
    HEX1 : out STD_LOGIC_VECTOR(6 downto 0); -- CARDDISPLAY1 DEZENA -- Usar na compara dealer x player
    HEX2 : out STD_LOGIC_VECTOR(6 downto 0); -- SUMDISPLAY2 Mostra a casa decimal das unidades
    HEX3 : out STD_LOGIC_VECTOR(6 downto 0) -- SUMDISPLAY1 Mostra a casa decimal de maior valor
   );
END ENTITY blackjack;

ARCHITECTURE behave OF blackjack IS
    TYPE tipo_estado IS (reset,digita1,digita2,digita3,digita4,recebePlayer1,recebeDealer1,recebePlayer2,recebeDealer2,esperaPlayer,hitPlayer,esperaDealer,hitDealer,compara,ganhouP, perdeuP, empate);
    signal estado : tipo_estado := reset;
    --signal playerCards :  integer range 0 to 13:= 0; 
    signal playerSoma : integer range 0 to 50 := 0;
   -- signal dealerCards :  integer range 0 to 13:=0; 
    signal dealerSoma : integer range 0 to 50:= 0 ;   
    signal cardArray :  integer range 0 to 52:= 0; 

    function int2display (
        card_hand: in integer range 0 to 13)
        return std_logic_vector is 
        variable display : std_logic_vector (6 downto 0);   

        begin 
            case card_hand is 
                when 0 => display := "0111111";
                when 1 => display := "0000110";  --AS
                when 2 => display := "1011011";  -- 2  --a,b,c,d,e,f,g
                when 3 => display := "1001111";  -- 3
                when 4 => display := "1100110";  -- 4
                when 5 => display := "1101101";  -- 5
                when 6 => display := "1111101";  -- 6
                when 7 => display := "0000111";  -- 7
                when 8 => display := "1111111";  -- 8
                when 9 => display := "1101111";  -- 9
                when 10 => display := "1110111";  --A
                when 11 => display := "1111100";  --B
                when 12 => display := "0111001";  --C
                when 13 => display := "1011110";  --D 0100001
            when others => display:="0000000";
            end case;   
        return std_logic_vector(display);
    end;

    function displayHand_dezena(
        card_hand: in integer range 0 to 30)
        return std_logic_vector is
        variable display_dezena : std_logic_vector (6 downto 0);

        begin
            if(card_hand<10) then
                display_dezena := "0111111";
            elsif(card_hand <20) then
                display_dezena := "0000110";
            elsif(card_hand < 30) then
                display_dezena := "1011011";
            elsif (card_hand = 30)then -- quando 30
                display_dezena := "1001111";
            else
                display_dezena := "0000000";
            end if;
        return std_logic_vector(display_dezena);
    end;

     BEGIN
        process(KEY(0))--Process referente à troca de estados
            begin

                If(KEY(1) = '1') then -- Reset
                    estado <= reset;           

                elsif(KEY(0)'EVENT AND KEY(0) = '1') then -- Clock

                    case estado is
                        when reset =>
				estado <= digita1;
			when digita1 =>
                            estado <=recebePlayer1;

                        when recebePlayer1 =>
				estado <= digita2;
			when digita2 =>
                            estado <= recebeDealer1;

                        when recebeDealer1 =>
				estado <= digita3;
			when digita3 =>
                            estado <= recebePlayer2;

                        when recebePlayer2 =>
				estado => digita 4;
			when digita4 =>
                            estado <= recebeDealer2;

                        when recebeDealer2 =>
                            estado <= esperaPlayer;

                        when esperaPlayer =>
                            if(SW(9) = '1') then 
                                estado <= hitPlayer;                                

                            end if;
                            if(SW(8) = '1') then 
                                estado <= esperaDealer;

                            end if;

                        when hitPlayer =>
                            if(playerSoma>21) then
                                estado <= perdeuP;

                            elsif(playerSoma=21) then
                                estado <= ganhouP;

                            elsif(playerSoma<=21) then 
                                estado <= esperaPlayer;
                            
                            end if;   

                        when esperaDealer =>
                            if(dealerSoma<17) then 
                                estado <= hitdealer;

                            end if;
                            if(dealerSoma>=17) then 
                                estado <= compara;

                            end if;

                        when hitDealer =>
                            if(dealerSoma>21) then 
                                estado <= ganhouP;

                            end if;
                            if(dealerSoma<=21) then 
                                estado <= esperaDealer;

                            end if;

                        when compara =>
                            if((dealerSoma = 21 and dealerSoma /= playerSoma) or (dealerSoma < 21 and dealerSoma > playerSoma)) then
                                estado <= perdeuP;

                            elsif((playerSoma = 21 and dealerSoma /= playerSoma) or (playerSoma < 21 and playerSoma > dealerSoma) ) then --or (playerSoma < 21 and dealerSoma > 21)???????
                                estado <= ganhouP;

                            else 
                                estado <= empate;

                            end if;

                        when empate =>
                            estado <= reset;

                        when ganhouP =>
                            estado <= reset;

                        when perdeuP =>
                            estado <= reset;

                        end case;
                end if;
        end process;

        process(ESTADO)--Process de saída(conferir o que vai aqui)
            variable playerCards :  integer range 0 to 13:= 0; 
            variable dealerCards :  integer range 0 to 13:= 0; 

            begin
                case estado is
                    when reset =>  --Zerar variáveis, desligar LED
                        playerCards := 0;
                        dealerCards := 0; 
                        playerSoma <= 0;
                        dealerSoma <= 0 ;   
                        LEDR <= "0000000000";
                        LEDG <= "00000000";
                        HEX0 <= int2display(0);
                        HEX1 <= int2display(0);
		when digita1 =>
			LEDR<= "1111100000";
			playerCards:=to_integer(unsigned(SW(3 downto 0)));
			HEX0 <= int2display(playerCards);
		when digita2 =>
			LEDG<= "11110000";
			dealerCards:=to_integer(unsigned(SW(3 downto 0)));
			HEX0 <= int2display(dealerCards);
		when digita3 =>
			LEDR<= "1111100000";
			playerCards:=to_integer(unsigned(SW(3 downto 0)));
			HEX0 <= int2display(playerCards);
		when digita4 =>
			LEDG<= "11110000";
			dealerCards:=to_integer(unsigned(SW(3 downto 0)));
			HEX0 <= int2display(dealerCards);
                    when recebePlayer1 =>
			LEDR <= "0000011111";
			HEX0 <= int2display(playerCards);
                        HEX1 <= int2display(0);
			playerSoma := playerSoma+playerCards;
			HEX2 <= int2display(playerSoma mod 10);
			HEX3 <= displayHand_dezena(playerSoma);

                    when recebeDealer1 => --Adicionar dealerCards ao dealerSoma, verificar randomCards
			HEX0 <= int2display(dealerCards);
			LEDG <= "00001111";
                        HEX1 <= int2display(0);
			dealerSoma := dealerSoma+dealerCards;
			HEX2 <= int2display(dealerSoma mod 10);
			HEX3 <= displayHand_dezena(dealerSoma);

                    when recebePlayer2 => --Adicionar playeCARDDISPLAY1 <= int2display(playerCards);
			HEX0 <= int2display(playerCards);
			LEDR <= "0000011111";
                        HEX1 <= int2display(0);
			playerSoma := playerSoma+playerCards;
			HEX2 <= int2display(playerSoma mod 10);
			HEX3 <= displayHand_dezena(playerSoma);

                    when recebeDealer2 => --Adicionar dealerCards ao dealerSoma, verificar randomCards
			HEX0 <= int2display(dealerCards);
			LEDG <= "00001111";
                        HEX1 <= int2display(0);
			dealerSoma := dealerSoma+dealerCards;
			HEX2 <= int2display(dealerSoma mod 10);
			HEX3 <= displayHand_dezena(dealerSoma);

                    when esperaPlayer => --x
			LEDR <= "1111100000";
			HEX0 <= int2display(playerCards);
			HEX2 <= int2display(playerSoma mod 10);
			HEX3 <= displayHand_dezena(playerSoma);

                    when hitPlayer => -- Adicionar ao playerSoma, verificar randomCards
			LEDR <= "0000011111";
			playerSoma := playerSoma+playerCards;
                        HEX1 <= int2display(0);

                    when esperaDealer => --x
			LEDG <= "11110000";
			HEX0 <= int2display(dealerCards);
			HEX2 <= int2display(dealerSoma mod 10);
			HEX3 <= displayHand_dezena(dealerSoma);
			
                    when hitDealer => -- Adicionar dealerCards ao dealerSoma, verificar randomCar
			LEDG <= "00001111";
			dealerSoma := dealerSoma+dealerCards;
                        HEX0 <= int2display(dealerCards);

                    when compara => --x
                        LEDR <= "0101010101";--tirar
                        LEDG <= "10101010";--tirar

                    when perdeuP => -- Ligar LED derrota
                        LEDR <= "1111111111";
                        LEDG <= "00000000";
                        HEX0 <= int2display(dealerSoma mod 10);
                        HEX1 <=  displayHand_dezena(dealerSoma);

                    when ganhouP => -- Ligar LED Vitória
                        LEDR <= "0000000000";
                        LEDG <= "11111111";
                        HEX0 <= int2display(dealerSoma mod 10);
                        HEX1 <=  displayHand_dezena(dealerSoma);

                    when empate => -- Ligar LED empate
                        LEDR <= "1111111111";
                        LEDG <= "11111111";
                        HEX0 <= int2display(dealerSoma mod 10);
                        HEX1 <=  displayHand_dezena(dealerSoma);

                end case; 

    end process;
    --HEX2 <= int2display(playerSoma mod 10);
    --HEX3 <=  displayHand_dezena(playerSoma);--  
end behave;

-- NÃO SERÁ TESTADO

--      CARTAS MAIORES QUE 13

--      CARTAS REPETIDAS

-- Binário para decimal
