LIBRARY ieee;

USE ieee.std_logic_1164.ALL;


ENTITY blackjack IS PORT (



   ------ Variáveis ------
	
	HIT: in STD_LOGIC;
	STAY: in STD_LOGIC;
	START: in STD_LOGIC;--Reset
	CLOCK: in STD_LOGIC;
	RANDOM_CARDS: in STD_LOGIC;
	CARDS: in STD_LOGIC_VECTOR (3 downto 0);

	SW: in STD_LOGIC_VECTOR(9 downto 0);
	KEY: in STD_LOGIC_VECTOR(3 downto 0);

   LEDG: out STD_LOGIC_VECTOR(7 downto 0)


   );

END ENTITY blackjack;


ARCHITECTURE behave OF blackjack IS

   TYPE tipo_estado IS (
	inicio,
	player_recebe_1,
	player_recebe_2,
	player_choice,
	player_hit,
	player_stay,
	dealer_recebe_1,
	dealer_recebe_2,
	dealer_choice,
	dealer_hit,
	compara,
	empate,
	perdeu,
	ganhou
	);

   signal estado : tipo_estado;
   --signal estadoAnterior : tipo_estado;

   BEGIN

       process(CLOCK, START)

           begin

               if(START = '1') then

                   estado <= inicio;
							--downrising_edge(KEY(0))
               elsif(KEY(0)'EVENT AND KEY(0) = '0') then

                   case estado is


                       when Ab =>
                                estadoAnterior <= estado;

                           if(SW(3)  = '1') then
                             
                               estado <= c1;
                               
                           end if;

                       when c1 =>

                        estadoAnterior <= estado;


                        if estadoAnterior = Ab then
                            if(SW(2)  = '1') then
   estado <= Ab;
   
                            else

                                estado <= c2;
                            end if;

                        else
                            if(SW(2)  = '1') then
   estado <= c2;
   
                            else

                                estado <= ab;
end if;
                        end if;

                       when c2 =>
                        estadoAnterior <= estado;


                       if estadoAnterior = c1 then
                           if(SW(2)  = '1') then
                               estado <= c1;
                       
                           else

                               estado <= c3;
                           end if;
                   
                       else
                           if(SW(2)  = '1') then
                               estado <= c3;
                       
                           else

                               estado <= c1;
                           end if;
                       end if;
                       when c3 =>estadoAnterior <= estado;


                       if estadoAnterior = c2 then
                           if(SW(2)  = '1') then
                               estado <= c2;
                       
                           else

                               estado <= FC;
                           end if;
                   
                       else
                           if(SW(2)  = '1') then
                               estado <= Fc;
                       
                           else

                               estado <= c2;
                           end if;

                        end if;

                       when Fc =>
                        estadoAnterior <= estado;

                           if(SW(3) = '1') then

                               estado <= c3;

                           end if;

                    end case;
 
                end if;

       end process;


  process (estado)
  BEGIN
  case estado is
  when Ab =>
  LEDG(6) <= '0'; -- MotorA desligado
  LEDG(7) <= '0'; -- MotorF desligado
  LEDG(0) <= '1'; -- Sa ligado
  LEDG(1) <= '0'; -- Sf desligado
   
  when c1 =>
  if (estadoAnterior = Ab) then
  LEDG(7) <= '1'; -- MotorF ligado
  LEDG(6) <= '0'; -- MotorA desligado
  elsif (estadoAnterior = c2) then
  LEDG(6) <= '1'; -- MotorA ligado
  LEDG(7) <= '0'; -- MotorF desligado
  end if;
   
  LEDG(0) <= '0'; -- Sa desligado
  LEDG(1) <= '0'; -- Sf desligado
   
  when c2 =>

                if (estadoAnterior = c1) then
                    LEDG(7) <= '1'; -- MotorF ligado
                    LEDG(6) <= '0'; -- MotorA desligado
                elsif (estadoAnterior = c3) then
                    LEDG(6) <= '1'; -- MotorA ligado
                    LEDG(7) <= '0'; -- MotorF desligado
                end if;

                LEDG(0) <= '0'; -- Sa desligado
                LEDG(1) <= '0'; -- Sf desligado

   
  when c3 =>
if (estadoAnterior = FC) then
LEDG(7) <= '0'; -- MotorF desligado
LEDG(6) <= '1'; -- MotorA ligado
elsif (estadoAnterior = c2) then
LEDG(6) <= '0'; -- MotorA desligado
LEDG(7) <= '1'; -- MotorF ligado
end if;
 
  LEDG(0) <= '0'; -- Sa desligado
  LEDG(1) <= '0'; -- Sf desligado
   
  when Fc =>

  LEDG(6) <= '0'; -- MotorA desligado
  LEDG(7) <= '0'; -- MotorF desligado
  LEDG(0) <= '0'; -- Sa desligado
  LEDG(1) <= '1'; -- Sf desligado
  end case;
  end process;
end architecture;
