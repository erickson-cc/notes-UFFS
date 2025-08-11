LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY blackjack IS PORT (


   ------ Variáveis ------

	HIT: in STD_LOGIC;-- SW(1) = Reset, SW(2) = S, SW(3) = B
    STAY: in STD_LOGIC;
    START: in STD_LOGIC;
    CLK: in STD_LOGIC;
    CARDS: in STD_LOGIC_VECTOR(3 downto 0);
    RANDOM_CARDS: in STD_LOGIC;-- Key(0) = Clock

    WIN : out  STD_LOGIC;
    LOSE : out  STD_LOGIC;
    TIE : out  STD_LOGIC;
    CARDDISPLAY : out  STD_LOGIC_VECTOR(6 downto 0);
    SUMDISPLAY1 : out  STD_LOGIC_VECTOR(6 downto 0);-- Mostra a casa decimal de maior valor
    SUMDISPLAY2 : out  STD_LOGIC_VECTOR(6 downto 0) -- Mostra a casa decimal das unidades

   );

END ENTITY blackjack;

ARCHITECTURE behave OF blackjack IS
    TYPE tipo_estado IS (reset,recebePlayer1,recebeDealer1,recebePlayer2,recebeDealer2,esperaPlayer,hitPlayer,esperaDealer,hitDealer,compara,ganhouP, perdeuP, empate);
    signal estado : tipo_estado;
   -- signal estadoAnterior : tipo_estado;
    signal playerCards :  integer range 1 to 13; 
    signal playerSoma : integer range 0 to 30 := 0;
    signal dealerCards :  integer range 1 to 13; 
    signal dealerSoma : integer range 0 to 10 := 0 ;   
    signal cardArray :  integer range 1 to 52; 

     BEGIN

        process(CLK)--Process referente à troca de estados

            begin

                if(START = '1') then -- Reset

                    estado <= reset;

							
                elsif(CLK'EVENT AND CLK = '0') then -- Clock

                    case estado is

                        when reset =>
                            --estadoAnterior <= estado;
                            estado <=recebePlayer1;
                            --if(RANDOM_CARDS = '1') then

                            --else

                    
                            --end if;
                        when recebePlayer1 =>
                            estado <= recebeDealer1;

                        when recebeDealer1 =>
                            estado <= recebePlayer2;

                        when recebePlayer2 =>
                            estado <= recebeDealer2;

                        when recebeDealer2 =>
                            estado <= esperaPlayer;

                        when esperaPlayer =>

                            if(HIT = '1') then 
                                estado <= hitPlayer;
                                --recebe carta
                                

                            end if;
                            if(STAY = '1') then 
                                estado <= esperaDealer;
                            
                            end if;

                        when hitPlayer =>
                            if(RANDOM_CARDS = '1') then -- 

                                end if;
                            if(playerSoma>21) then -- se eu e o dealer tiver mais de 21 eu perco ou da empate
                                estado <= perdeuP;

            				elsif(playerSoma=21) then
			            		estado <=esperaDealer;

                            elsif(playerSoma<=21) then 
                                estado <= esperaPlayer;
                            
                            end if;   

                        when esperaDealer =>

                            if(dealerSoma<17) then 
                                estado <= hitdealer;--por que precisa desse processo? vai ter que ficar dando clock, da pra fazer de uma vez
                                --recebe carta
                                

                            end if;
                            if(dealerSoma>=17) then 
                                estado <= compara;
                            
                            end if;

                        when hitDealer =>
                            if(RANDOM_CARDS = '1') then
    
    
    
                        
                            end if;
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

        process(ESTADO,playerCards)--Process de saída(conferir o que vai aqui)
            begin
                if (CLK'EVENT AND CLK = '0') then
                    case playerCards is --And estado != compara & perdeu & ganhou & empate
                    -- when 01 => CARDDISPLAY <= "1110000";  --AS
                        when 02 => CARDDISPLAY <= "1011011";  -- 2  --a,b,c,d,e,f,g
                        when 03=> CARDDISPLAY <= "1001111";  -- 3
                        when 04 => CARDDISPLAY <= "1100110";  -- 4
                        when 05 => CARDDISPLAY <= "1101101";  -- 5
                        when 06 => CARDDISPLAY <= "1111101";  -- 6
                        when 07 => CARDDISPLAY <= "0000111";  -- 7
                        when 08 => CARDDISPLAY <= "1111111";  -- 8
                        when 09 => CARDDISPLAY <= "1101111";  -- 9
                        when 10 => CARDDISPLAY <= "1110111";  --A
                        when 11 => CARDDISPLAY <= "1111100";  --B
                        when 12 => CARDDISPLAY <= "0111001";  --C
                        when 13 => CARDDISPLAY <= "1011110";  --D

                        when others => CARDDISPLAY <= "0000000";
                    end case; --encerra caso

                    --Criar um case SumDisplay
                        --Irá mostrar a soma das cartas do player em 2 displays de 7 segmentos
                    --Talvez criar um case sumDisplay para o dealer
                        --Será demonstrado no estado de comparação.

                    --case estado is (USAR AQUI PARA ADICIONAR CARTAS)
                    case estado is
                        when reset =>  --Zerar variáveis, desligar LED
                        when recebePlayer1 => --Adicionar playerCards ao playerSoma, verificar randomCards
                        when recebeDealer1 => --Adicionar dealerCards ao dealerSoma, verificar randomCards
                        when recebePlayer2 => --Adicionar playerCards ao playerSoma, verificar randomCards
                        when recebeDealer2 => --Adicionar dealerCards ao dealerSoma, verificar randomCards
                        when esperaPlayer => --x
                        when hitPlayer => -- Adicionar playerCards ao playerSoma, verificar randomCards
                        when esperaDealer => --x
                        when hitDealer => -- Adicionar dealerCards ao dealerSoma, verificar randomCards
                        when compara => --x
                        when empate => -- Ligar LED empate
                        when ganhouP => -- Ligar LED Vitória
                        when perdeuP => -- Ligar LED DERROTA
                    end case;

            end if;

        end process;
	
        process (estado)
            BEGIN
                case estado is
                    when perdeuP =>
                        LOSE <= '1';
                        WIN <= '0';
                        TIE <= '0';
                    when ganhouP =>
                        LOSE <= '0';
                        WIN <= '1';
                        TIE <= '0';
                    when empate =>
                        LOSE <= '0';
                        WIN <= '0';
                        TIE <= '1';
		when others =>
		       LOSE <= '0';
                        WIN <= '0';
                        TIE <= '0';
                end case;
        end process;
end behave;
-- Fazer números aleatórios
-- Criar a lógica do sumDisplay1 e sumDisplay2
-- Fazer while do hitDealer
-- Criar a lógica de cartas restantes do baralho.