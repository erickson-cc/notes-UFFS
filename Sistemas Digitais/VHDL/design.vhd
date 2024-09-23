library ieee;
use ieee.std_logic_1164.all;

entity state is port (
	a: in std_logic;
    b: in std_logic;
    c: out std_logic
   );
end entity state;

architecture behav of state is
	begin
    	c <= a AND b;
end architecture;