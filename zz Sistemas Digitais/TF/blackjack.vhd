LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
ENTITY blackjack IS PORT (

   ------ Variáveis ------

     KEY: in STD_LOGIC_VECTOR(3 downto 0);

        -- KEY(1) = START
        -- KEY(0) = CLOCK        

    SW: in STD_LOGIC_VECTOR(9 downto 0);

        -- SW(9) = HIT
        -- SW(8) = STAY
        -- SW CARDS (BINÁRIO)

    LEDR : out STD_LOGIC_VECTOR(9 downto 0); -- derrota
    LEDG : out STD_LOGIC_VECTOR(7 downto 0); -- vitória

    HEX0 : out STD_LOGIC_VECTOR(6 downto 0); -- CARDDISPLAY2 UNIDADE
    HEX1 : out STD_LOGIC_VECTOR(6 downto 0); -- CARDDISPLAY1 DEZENA
    HEX2 : out STD_LOGIC_VECTOR(6 downto 0); -- SUMDISPLAY2 Mostra a casa da unidade
    HEX3 : out STD_LOGIC_VECTOR(6 downto 0) -- SUMDISPLAY1 Mostra a casa da dezena
   );
END ENTITY blackjack;

ARCHITECTURE behave OF blackjack IS
    TYPE tipo_estado IS (reset,recebePlayer1,recebeDealer1,recebePlayer2,recebeDealer2,esperaPlayer,hitPlayer,esperaDealer,hitDealer,compara,ganhouP, perdeuP, empate);
    signal estado : tipo_estado := reset;
    signal playerSoma : integer range 0 to 50 := 0;
    signal dealerSoma : integer range 0 to 50:= 0 ;   
    signal cardArray :  integer range 0 to 52:= 0;
    signal pCard : integer range 0 to 13:= 0;
    signal dCard : integer range 0 to 13:= 0;

    function int2display (
        card_hand: in integer range 0 to 13)
        return std_logic_vector is 
        variable display : std_logic_vector (6 downto 0);   

        begin 
            case card_hand is 
                when 0 => display := "1000000";
                when 1 => display := "1111001";  --AS
                when 2 => display := "0100100";  -- 2 
                when 3 => display := "0110000";  -- 3
                when 4 => display := "0011001";  -- 4
                when 5 => display := "0010010";  -- 5
                when 6 => display := "0000010";  -- 6
                when 7 => display := "1111000";  -- 7
                when 8 => display := "0000000";  -- 8
                when 9 => display := "0010000";  -- 9
                when 10 => display := "0001000";  --A
                when 11 => display := "0000011";  --B
                when 12 => display := "1000110";  --C
                when 13 => display := "0100001";  --D
            when others => display := "1111111";
            end case;   
        return std_logic_vector(display);
    end;

    function displayHand_dezena(
        card_hand: in integer range 0 to 30)
        return std_logic_vector is
        variable display_dezena : std_logic_vector (6 downto 0);

        begin
            if(card_hand < 10) then
                display_dezena := "1000000";
            elsif(card_hand < 20) then
                display_dezena := "1111001";
            elsif(card_hand < 30) then
                display_dezena := "0100100";
            elsif (card_hand = 30) then
                display_dezena := "0110000";
            else
                display_dezena := not"0000000";
            end if;
        return std_logic_vector(display_dezena);
    end;

     BEGIN
        process(KEY(0))--Process referente à troca de estados
            variable preSomaPlayer : integer range 0 to 50 := 0;
            variable preSomaDealer : integer range 0 to 50 := 0;
            variable playerCards :  integer range 0 to 13:= 0; 
            variable dealerCards :  integer range 0 to 13:= 0; 
            
            begin
                        
                If(KEY(1) = '0') then -- Reset
                    estado <= reset;           

                elsif(KEY(0)'EVENT AND KEY(0) = '0') then -- Clock

                    case estado is
                        when reset =>
                            preSomaPlayer := 0;
                            preSomaDealer := 0;
                            playerCards := 0;
                            dealerCards := 0; 
                            playerSoma <= 0;
                            dealerSoma <= 0 ;
                            estado <=recebePlayer1;

                        when recebePlayer1 =>
                                                
                            if((SW(3 downto 0) = "1011") or (SW(3 downto 0) = "1100") or (SW(3 downto 0) = "1101")) then
                                playerCards := 10;
                            elsif(SW(3 downto 0) = "0001") then
                                if((preSomaPlayer + 11) <=21) then
                                    playerCards := 11;
                                else 
                                    playerCards := 1;
                                end if;
                            else
                                playerCards := to_integer(unsigned(SW(3 downto 0)));
                           end if;
                                                      
                           preSomaPlayer:= preSomaPlayer+playerCards;
                           estado <= recebeDealer1;

                        when recebeDealer1 =>
                                                
                            if((SW(3 downto 0) = "1011") or (SW(3 downto 0) = "1100") or (SW(3 downto 0) = "1101")) then
                                dealerCards := 10;
                            elsif(SW(3 downto 0) = "0001") then
                                if((preSomaDealer + 11) <=21) then
                                    dealerCards := 11;
                                else 
                                    dealerCards := 1;
                                end if;
                            else
                                dealerCards := to_integer(unsigned(SW(3 downto 0)));
                            end if;
                                                      
                            preSomaDealer := preSomaDealer+dealerCards;
                            estado <= recebePlayer2;

                        when recebePlayer2 =>
                                                
                            if((SW(3 downto 0) = "1011") or (SW(3 downto 0) = "1100") or (SW(3 downto 0) = "1101")) then
                                playerCards := 10;
                            elsif(SW(3 downto 0) = "0001") then
                                if((preSomaPlayer + 11) <=21) then
                                    playerCards := 11;
                                else 
                                    playerCards := 1;
                                end if;
                            else
                                playerCards := to_integer(unsigned(SW(3 downto 0)));
                            end if;
                                                      
                            preSomaPlayer:= preSomaPlayer+playerCards;
                            estado <= recebeDealer2;

                        when recebeDealer2 =>
                                                                                       
                            if((SW(3 downto 0) = "1011") or (SW(3 downto 0) = "1100") or (SW(3 downto 0) = "1101")) then
                                dealerCards := 10;
                            elsif(SW(3 downto 0) = "0001") then
                                if((preSomaDealer + 11) <=21) then
                                    dealerCards := 11;
                                else 
                                    dealerCards := 1;
                                end if;
                            else
                                dealerCards := to_integer(unsigned(SW(3 downto 0)));
                            end if;
                                                
                            preSomaDealer := preSomaDealer+dealerCards;
                            estado <= esperaPlayer;

                        when esperaPlayer =>
                            if(SW(9) = '1') then 
                                estado <= hitPlayer;                                

                            end if;
                            if(SW(8) = '1') then 
                                estado <= esperaDealer;

                            end if;

                        when hitPlayer =>
                                                
                            if((SW(3 downto 0) = "1011") or (SW(3 downto 0) = "1100") or (SW(3 downto 0) = "1101")) then
                                playerCards := 10;
                            elsif(SW(3 downto 0) = "0001") then
                                if((preSomaPlayer + 11) <=21) then
                                    playerCards := 11;
                                else 
                                    playerCards := 1;
                                end if;
                            else
                                playerCards := to_integer(unsigned(SW(3 downto 0)));
                           end if;
                                                      
                            preSomaPlayer := preSomaPlayer+playerCards;

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
                                                
                            if((SW(3 downto 0) = "1011") or (SW(3 downto 0) = "1100") or (SW(3 downto 0) = "1101")) then
                                dealerCards := 10;
                            elsif(SW(3 downto 0) = "0001") then
                                if((preSomaDealer + 11) <=21) then
                                    dealerCards := 11;
                                else 
                                    dealerCards := 1;
                                end if;
                            else
                                dealerCards := to_integer(unsigned(SW(3 downto 0)));
                            end if;
                                                
                            preSomaDealer := preSomaDealer + dealerCards;

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
                playerSoma<= preSomaPlayer;
                dealerSoma<= preSomaDealer;
                pCard <= playerCards;
                dCard <= dealerCards;
        end process;

        process(ESTADO) --Process de saída

            begin
                case estado is
                    when reset =>
   
                        LEDR <= "0000001111";
                        LEDG <= "10000000";
                        HEX0 <= int2display(0);
                        HEX1 <= int2display(0);
                        HEX2 <= int2display(0);
                        HEX3 <= int2display(0);

                    when recebePlayer1 =>
                    
                        LEDR <= "1000001111";
                        LEDG <= "00000000";
                        HEX1 <= "1111111";
                        HEX0 <= int2display(to_integer(unsigned(SW(3 downto 0))));
                        HEX2 <= int2display(playerSoma mod 10);
                        HEX3 <= displayHand_dezena(playerSoma);

                    when recebeDealer1 =>
                           
                        LEDG <= "00000000";
                        LEDR <= "0100001111";
                        HEX0 <= int2display(to_integer(unsigned(SW(3 downto 0))));
                        HEX1 <= "1111111";
                        HEX2 <= int2display(playerSoma mod 10);
                        HEX3 <= displayHand_dezena(playerSoma);

                    when recebePlayer2 =>

                        LEDG <= "00100000";
                        LEDR <= "0000001111";
                        HEX0 <= int2display(to_integer(unsigned(SW(3 downto 0))));
                        HEX1 <= "1111111";
                        HEX2 <= int2display(playerSoma mod 10);
                        HEX3 <= displayHand_dezena(playerSoma);

                    when recebeDealer2 =>

                        LEDR <= "0000001000";
                        HEX1 <= "1111111";
                        HEX2 <= int2display(playerSoma mod 10);
                        HEX3 <= displayHand_dezena(playerSoma);
                        HEX0 <= int2display(to_integer(unsigned(SW(3 downto 0))));

                    when esperaPlayer =>

                        LEDR <= "0000010000";
                        HEX0 <= int2display(to_integer(unsigned(SW(3 downto 0))));
                        HEX1 <= "1111111";
                        HEX2 <= int2display(playerSoma mod 10);
                        HEX3 <= displayHand_dezena(playerSoma);

                    when hitPlayer =>

                        HEX0 <= int2display(pCard);
                        LEDR <= "0001000000";
                        HEX1 <= "1111111";

                    when esperaDealer =>

                        LEDR <= "0010000000";

                    when hitDealer =>

                        HEX1 <= "1111111";
                        LEDR <= "0100000000";
                        HEX0 <= int2display(dCard);

                    when compara =>

                        LEDR <= "1000000000";

                    when perdeuP =>

                        LEDR <= "1111111111";
                        LEDG <= "00000000";
                        HEX0 <= int2display(dealerSoma mod 10);
                        HEX1 <=  displayHand_dezena(dealerSoma);

                    when ganhouP =>

                        LEDR <= "0000000000";
                        LEDG <= "11111111";
                        HEX0 <= int2display(dealerSoma mod 10);
                        HEX1 <=  displayHand_dezena(dealerSoma);

                    when empate =>

                        LEDR <= "1111111111";
                        LEDG <= "11111111";
                        HEX0 <= int2display(dealerSoma mod 10);
                        HEX1 <=  displayHand_dezena(dealerSoma);

                end case; 

                               
    end process;
end behave;