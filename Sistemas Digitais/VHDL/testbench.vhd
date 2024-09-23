library ieee;
use ieee.std_logic_1164.all;

entity teste is
end entity teste;

architecture behav of teste is component state is port (
	a: in std_logic;
    b: in std_logic;
    c: out std_logic
    );
    end component;
	
    signal a,b,c: std_logic;
    
    begin
    
    	a1:state
    	port map (a=>a,b=>b,c=>c);
        
        a<= '0','1' after 10 ns, '0' after 20 ns;
        b<= '0','1' after 5 ns, '0' after 10 ns,'1' after 15 ns,'0' after 20 ns;
        
   	end behav;