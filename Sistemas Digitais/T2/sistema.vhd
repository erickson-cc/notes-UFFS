Trabalho Sistemas
Thais Zanella<thaistzanella@gmail.com>
​
Você​
library ieee;
use ieee.std_logic_1164.all;

entity portao is
port( 
SA: out std_logic;
SF: out std_logic;
S_out: out std_logic;
S_in: in std_logic;
B: in std_logic;
Clock: in std_logic;
A: in std_logic;
F: in std_logic
);
end entity portao;

architecture behavior of portao is
type tipo_estado IS (F1, F2, F3);
signal proximo_estado: tipo_estado;
begin
process(B)
begin
if (B = '1') then
if (SF = '1') then
A <= '1';
F <= '0';
SF <= '0';
elsif (SA = '1') then
A <= '0';
F <= '1';
SA <= '0';
end if;
end if;
end process;

process (Clock)
begin
if (Clock'EVENT AND Clock = '1') then
case proximo_estado is
when F1 =>
proximo_estado <= F2;
when F2 =>
proximo_estado <= F3;
when F3 =>
if (A = '1') then
SA <= '1';
A <= '0';
elsif (F = '1') then 
SF <= '1';
F <= '0';
end if;
proximo_estado <= F1;
end case;
end if; 
end process;

end architecture behavior;
