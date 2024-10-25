LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY portao IS PORT (
	------ Variáveis ------
	-- A: in / Vai abrir o portão
	-- F: in / Vai fechar o portão
		-- A xor F = Motor funcionando
	-- SA <= porta
	-- LEDG(1) <= not porta
	-- LEDG(1) = SA when porta = x
	-- B: in 
		-- if AF == 11
	-- S: in
	-- KEY(0): in
		KEY: in STD_LOGIC_VECTOR(3 downto 0);
			-- 3 = B
			--	2 = S
			-- 1 = Reset
			-- 0 = Clock

		LEDG: out STD_LOGIC_VECTOR(7 downto 0)
			-- LEDG(7) = F
			-- LEDG(6) = A
			
			-- LEDG(1) = SF
			-- LEDG(0) = SA
		
	);
END ENTITY portao;

ARCHITECTURE behave OF portao IS
	--TYPE Tipo_estado IS (A, B, C);
	--SIGNAL nome_estado: Tipo_estado;
	-- Fazer um process (reset, clock) e outro process da lógica da saída (pg 17, 18)
	-- Criar um signal para o F e A 
	signal SF;-- := LEDG(1);
	signal SA;--:= LEDG(0);
	signal F; -- := LEDG(7);
	signal A; -- := LEDG(6);
	TYPE tipo_estado IS (Ab,c1,c2,c3,Fc);
	signal estado := F1;
	
	BEGIN
		process(KEY(1), KEY(0)) -- Reset e Clock
			begin
				if(KEY(1) = '1' then
					estado <= F1;
				elsif(KEY(0)'EVENT AND KEY(0) = '0') then
					case estado is
						when F1 =>
							IF KEY(0)

		process(KEY(0))
			begin
			if (KEY(0)'EVENT AND KEY(0) = '0') then
				case estado is
					when F1 =>
						estado <= F2;
						SA <= '0'
					when F2 =>
						estado <= F3;
					when F3 =>
						if (LEDG(6) = '1') then
							LEDG(0) <= '1';
							LEDG(6) <= '0';
						elsif (LEDG(7) = '1') then 
							LEDG(1) <= '1';
							LEDG(7) <= '0';
						end if;
					proximo_estado := F1;
				end case;
			end if; 
		end process;
		
--		process(KEY(1))
--			begin
--			if(KEY(1) = '1')then
--				if (LEDG(6) = '1') then -- Abrindo
					--LEDG(6)<=0;
--					if (proximo_estado = '1')
--				if (LEDG(7) = '1') then -- Fechando
--				


END ARCHITECTURE;
