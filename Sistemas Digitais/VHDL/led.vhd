library ieee;
use ieee.std_logic_1164.ALL;

entity led is port (
	a: in std_logic;
	b: out std_logic
);
end entity led;

architecture behav_led of led is
	begin
		b <= a;
end behav_led;
