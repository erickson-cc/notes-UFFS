-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.0.0 Build 156 04/24/2013 SJ Web Edition"

-- DATE "10/31/2024 23:12:16"

-- 
-- Device: Altera EP2C20F484C7 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEII;
LIBRARY IEEE;
USE CYCLONEII.CYCLONEII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	portao IS
    PORT (
	SW : IN std_logic_vector(9 DOWNTO 0);
	KEY : IN std_logic_vector(3 DOWNTO 0);
	LEDG : OUT std_logic_vector(7 DOWNTO 0)
	);
END portao;

-- Design Ports Information
-- SW[0]	=>  Location: PIN_L22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- SW[4]	=>  Location: PIN_W12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- SW[5]	=>  Location: PIN_U12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- SW[6]	=>  Location: PIN_U11,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- SW[7]	=>  Location: PIN_M2,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- SW[8]	=>  Location: PIN_M1,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- SW[9]	=>  Location: PIN_L2,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- KEY[1]	=>  Location: PIN_R21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- KEY[2]	=>  Location: PIN_T22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- KEY[3]	=>  Location: PIN_T21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- LEDG[0]	=>  Location: PIN_U22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- LEDG[1]	=>  Location: PIN_U21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- LEDG[2]	=>  Location: PIN_V22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- LEDG[3]	=>  Location: PIN_V21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- LEDG[4]	=>  Location: PIN_W22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- LEDG[5]	=>  Location: PIN_W21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- LEDG[6]	=>  Location: PIN_Y22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- LEDG[7]	=>  Location: PIN_Y21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- SW[2]	=>  Location: PIN_M22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- SW[3]	=>  Location: PIN_V12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- KEY[0]	=>  Location: PIN_R22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- SW[1]	=>  Location: PIN_L21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default


ARCHITECTURE structure OF portao IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_SW : std_logic_vector(9 DOWNTO 0);
SIGNAL ww_KEY : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_LEDG : std_logic_vector(7 DOWNTO 0);
SIGNAL \Selector0~2clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \SW[1]~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \Selector0~1_combout\ : std_logic;
SIGNAL \estadoAnterior.c1~regout\ : std_logic;
SIGNAL \Selector2~0_combout\ : std_logic;
SIGNAL \estadoAnterior.Ab~regout\ : std_logic;
SIGNAL \Selector4~4_combout\ : std_logic;
SIGNAL \SW[1]~clkctrl_outclk\ : std_logic;
SIGNAL \estado.c3~regout\ : std_logic;
SIGNAL \Selector3~0_combout\ : std_logic;
SIGNAL \Selector3~1_combout\ : std_logic;
SIGNAL \estado.c2~regout\ : std_logic;
SIGNAL \estadoAnterior.c2~regout\ : std_logic;
SIGNAL \Selector5~0_combout\ : std_logic;
SIGNAL \Selector5~1_combout\ : std_logic;
SIGNAL \estado.Fc~regout\ : std_logic;
SIGNAL \Selector2~1_combout\ : std_logic;
SIGNAL \Selector2~2_combout\ : std_logic;
SIGNAL \estado.c1~regout\ : std_logic;
SIGNAL \Selector1~0_combout\ : std_logic;
SIGNAL \Selector1~1_combout\ : std_logic;
SIGNAL \estado.Ab~regout\ : std_logic;
SIGNAL \estadoAnterior.c3~regout\ : std_logic;
SIGNAL \estadoAnterior.Fc~regout\ : std_logic;
SIGNAL \Selector0~0_combout\ : std_logic;
SIGNAL \Selector0~2_combout\ : std_logic;
SIGNAL \Selector0~2clkctrl_outclk\ : std_logic;
SIGNAL \Selector6~0_combout\ : std_logic;
SIGNAL \Selector6~1_combout\ : std_logic;
SIGNAL \LEDG[6]$latch~combout\ : std_logic;
SIGNAL \Selector7~0_combout\ : std_logic;
SIGNAL \Selector7~1_combout\ : std_logic;
SIGNAL \LEDG[7]$latch~combout\ : std_logic;
SIGNAL \SW~combout\ : std_logic_vector(9 DOWNTO 0);
SIGNAL \KEY~combout\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \ALT_INV_SW~combout\ : std_logic_vector(1 DOWNTO 1);
SIGNAL \ALT_INV_KEY~combout\ : std_logic_vector(0 DOWNTO 0);
SIGNAL \ALT_INV_estado.Ab~regout\ : std_logic;

BEGIN

ww_SW <= SW;
ww_KEY <= KEY;
LEDG <= ww_LEDG;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\Selector0~2clkctrl_INCLK_bus\ <= (gnd & gnd & gnd & \Selector0~2_combout\);

\SW[1]~clkctrl_INCLK_bus\ <= (gnd & gnd & gnd & \SW~combout\(1));
\ALT_INV_SW~combout\(1) <= NOT \SW~combout\(1);
\ALT_INV_KEY~combout\(0) <= NOT \KEY~combout\(0);
\ALT_INV_estado.Ab~regout\ <= NOT \estado.Ab~regout\;

-- Location: LCCOMB_X49_Y11_N30
\Selector0~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector0~1_combout\ = (\estadoAnterior.c2~regout\ & (((\estado.c3~regout\)))) # (!\estadoAnterior.c2~regout\ & (\estadoAnterior.Ab~regout\ & (\estado.c1~regout\ & !\estado.c3~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estadoAnterior.Ab~regout\,
	datab => \estadoAnterior.c2~regout\,
	datac => \estado.c1~regout\,
	datad => \estado.c3~regout\,
	combout => \Selector0~1_combout\);

-- Location: PIN_R22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\KEY[0]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_KEY(0),
	combout => \KEY~combout\(0));

-- Location: PIN_V12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[3]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(3),
	combout => \SW~combout\(3));

-- Location: PIN_M22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[2]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(2),
	combout => \SW~combout\(2));

-- Location: PIN_L21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[1]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(1),
	combout => \SW~combout\(1));

-- Location: LCFF_X49_Y11_N31
\estadoAnterior.c1\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	sdata => \estado.c1~regout\,
	sload => VCC,
	ena => \ALT_INV_SW~combout\(1),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estadoAnterior.c1~regout\);

-- Location: LCCOMB_X49_Y11_N0
\Selector2~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector2~0_combout\ = \SW~combout\(2) $ (\estadoAnterior.c1~regout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \SW~combout\(2),
	datad => \estadoAnterior.c1~regout\,
	combout => \Selector2~0_combout\);

-- Location: LCFF_X49_Y11_N17
\estadoAnterior.Ab\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	sdata => \estado.Ab~regout\,
	sload => VCC,
	ena => \ALT_INV_SW~combout\(1),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estadoAnterior.Ab~regout\);

-- Location: LCCOMB_X49_Y11_N28
\Selector4~4\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector4~4_combout\ = (\estado.c2~regout\ & (\Selector2~0_combout\ $ (((\SW~combout\(3) & \estado.Fc~regout\))))) # (!\estado.c2~regout\ & (\SW~combout\(3) & (\estado.Fc~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110101011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estado.c2~regout\,
	datab => \SW~combout\(3),
	datac => \estado.Fc~regout\,
	datad => \Selector2~0_combout\,
	combout => \Selector4~4_combout\);

-- Location: CLKCTRL_G6
\SW[1]~clkctrl\ : cycloneii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \SW[1]~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \SW[1]~clkctrl_outclk\);

-- Location: LCFF_X49_Y11_N29
\estado.c3\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	datain => \Selector4~4_combout\,
	aclr => \SW[1]~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estado.c3~regout\);

-- Location: LCCOMB_X48_Y11_N24
\Selector3~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector3~0_combout\ = (\estado.c3~regout\ & (\SW~combout\(2) $ (!\estadoAnterior.c2~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW~combout\(2),
	datac => \estadoAnterior.c2~regout\,
	datad => \estado.c3~regout\,
	combout => \Selector3~0_combout\);

-- Location: LCCOMB_X49_Y11_N20
\Selector3~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector3~1_combout\ = (\Selector3~0_combout\) # ((\estado.c1~regout\ & (\SW~combout\(2) $ (!\estadoAnterior.Ab~regout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estado.c1~regout\,
	datab => \SW~combout\(2),
	datac => \estadoAnterior.Ab~regout\,
	datad => \Selector3~0_combout\,
	combout => \Selector3~1_combout\);

-- Location: LCFF_X49_Y11_N21
\estado.c2\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	datain => \Selector3~1_combout\,
	aclr => \SW[1]~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estado.c2~regout\);

-- Location: LCFF_X49_Y11_N27
\estadoAnterior.c2\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	sdata => \estado.c2~regout\,
	sload => VCC,
	ena => \ALT_INV_SW~combout\(1),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estadoAnterior.c2~regout\);

-- Location: LCCOMB_X48_Y11_N14
\Selector5~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector5~0_combout\ = (!\SW~combout\(3) & \estado.Fc~regout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \SW~combout\(3),
	datad => \estado.Fc~regout\,
	combout => \Selector5~0_combout\);

-- Location: LCCOMB_X49_Y11_N24
\Selector5~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector5~1_combout\ = (\Selector5~0_combout\) # ((\estado.c3~regout\ & (\SW~combout\(2) $ (\estadoAnterior.c2~regout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW~combout\(2),
	datab => \estadoAnterior.c2~regout\,
	datac => \estado.c3~regout\,
	datad => \Selector5~0_combout\,
	combout => \Selector5~1_combout\);

-- Location: LCFF_X49_Y11_N25
\estado.Fc\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	datain => \Selector5~1_combout\,
	aclr => \SW[1]~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estado.Fc~regout\);

-- Location: LCCOMB_X49_Y11_N10
\Selector2~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector2~1_combout\ = (\SW~combout\(3) & (!\estado.Ab~regout\ & (!\estado.Fc~regout\))) # (!\SW~combout\(3) & (((\estado.Fc~regout\ & !\Selector2~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010000110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estado.Ab~regout\,
	datab => \SW~combout\(3),
	datac => \estado.Fc~regout\,
	datad => \Selector2~0_combout\,
	combout => \Selector2~1_combout\);

-- Location: LCCOMB_X49_Y11_N8
\Selector2~2\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector2~2_combout\ = (\estado.c2~regout\ & (!\Selector2~0_combout\ & ((\Selector2~1_combout\) # (!\estado.Fc~regout\)))) # (!\estado.c2~regout\ & (((!\estado.Fc~regout\ & \Selector2~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010011100000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estado.c2~regout\,
	datab => \Selector2~0_combout\,
	datac => \estado.Fc~regout\,
	datad => \Selector2~1_combout\,
	combout => \Selector2~2_combout\);

-- Location: LCFF_X49_Y11_N9
\estado.c1\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	datain => \Selector2~2_combout\,
	aclr => \SW[1]~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estado.c1~regout\);

-- Location: LCCOMB_X48_Y11_N8
\Selector1~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector1~0_combout\ = (\estado.c1~regout\ & (\SW~combout\(2) $ (\estadoAnterior.Ab~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100100001001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW~combout\(2),
	datab => \estado.c1~regout\,
	datac => \estadoAnterior.Ab~regout\,
	combout => \Selector1~0_combout\);

-- Location: LCCOMB_X49_Y11_N14
\Selector1~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector1~1_combout\ = (!\Selector1~0_combout\ & ((\SW~combout\(3)) # (\estado.Ab~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \SW~combout\(3),
	datac => \estado.Ab~regout\,
	datad => \Selector1~0_combout\,
	combout => \Selector1~1_combout\);

-- Location: LCFF_X49_Y11_N15
\estado.Ab\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	datain => \Selector1~1_combout\,
	aclr => \SW[1]~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estado.Ab~regout\);

-- Location: LCFF_X49_Y11_N5
\estadoAnterior.c3\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	sdata => \estado.c3~regout\,
	sload => VCC,
	ena => \ALT_INV_SW~combout\(1),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estadoAnterior.c3~regout\);

-- Location: LCFF_X49_Y11_N23
\estadoAnterior.Fc\ : cycloneii_lcell_ff
PORT MAP (
	clk => \ALT_INV_KEY~combout\(0),
	sdata => \estado.Fc~regout\,
	sload => VCC,
	ena => \ALT_INV_SW~combout\(1),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \estadoAnterior.Fc~regout\);

-- Location: LCCOMB_X49_Y11_N4
\Selector0~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector0~0_combout\ = (\estado.c3~regout\ & (((\estadoAnterior.Fc~regout\)))) # (!\estado.c3~regout\ & ((\estadoAnterior.c1~regout\) # ((\estadoAnterior.c3~regout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111001010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estado.c3~regout\,
	datab => \estadoAnterior.c1~regout\,
	datac => \estadoAnterior.c3~regout\,
	datad => \estadoAnterior.Fc~regout\,
	combout => \Selector0~0_combout\);

-- Location: LCCOMB_X49_Y11_N12
\Selector0~2\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector0~2_combout\ = (\estado.c3~regout\ & ((\Selector0~1_combout\) # ((\Selector0~0_combout\)))) # (!\estado.c3~regout\ & ((\estado.c2~regout\ & ((\Selector0~0_combout\))) # (!\estado.c2~regout\ & (!\Selector0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111100011011001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Selector0~1_combout\,
	datab => \estado.c3~regout\,
	datac => \Selector0~0_combout\,
	datad => \estado.c2~regout\,
	combout => \Selector0~2_combout\);

-- Location: CLKCTRL_G4
\Selector0~2clkctrl\ : cycloneii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \Selector0~2clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \Selector0~2clkctrl_outclk\);

-- Location: LCCOMB_X49_Y11_N26
\Selector6~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector6~0_combout\ = (\estado.c2~regout\ & (((!\estadoAnterior.c1~regout\)))) # (!\estado.c2~regout\ & (\estadoAnterior.Ab~regout\ & (\estado.c1~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000100011111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estadoAnterior.Ab~regout\,
	datab => \estado.c1~regout\,
	datac => \estado.c2~regout\,
	datad => \estadoAnterior.c1~regout\,
	combout => \Selector6~0_combout\);

-- Location: LCCOMB_X49_Y11_N22
\Selector6~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector6~1_combout\ = (\estado.c3~regout\ & (\estadoAnterior.Fc~regout\)) # (!\estado.c3~regout\ & ((\Selector6~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001111000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \estado.c3~regout\,
	datac => \estadoAnterior.Fc~regout\,
	datad => \Selector6~0_combout\,
	combout => \Selector6~1_combout\);

-- Location: LCCOMB_X49_Y11_N16
\LEDG[6]$latch\ : cycloneii_lcell_comb
-- Equation(s):
-- \LEDG[6]$latch~combout\ = (GLOBAL(\Selector0~2clkctrl_outclk\) & ((\Selector6~1_combout\))) # (!GLOBAL(\Selector0~2clkctrl_outclk\) & (\LEDG[6]$latch~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111000100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LEDG[6]$latch~combout\,
	datab => \Selector0~2clkctrl_outclk\,
	datad => \Selector6~1_combout\,
	combout => \LEDG[6]$latch~combout\);

-- Location: LCCOMB_X49_Y11_N6
\Selector7~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector7~0_combout\ = (\estado.c2~regout\ & (((\estadoAnterior.c1~regout\)))) # (!\estado.c2~regout\ & (\estado.c1~regout\ & (!\estadoAnterior.Ab~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estado.c2~regout\,
	datab => \estado.c1~regout\,
	datac => \estadoAnterior.Ab~regout\,
	datad => \estadoAnterior.c1~regout\,
	combout => \Selector7~0_combout\);

-- Location: LCCOMB_X49_Y11_N2
\Selector7~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \Selector7~1_combout\ = (\estado.c3~regout\ & (!\estadoAnterior.Fc~regout\)) # (!\estado.c3~regout\ & ((\Selector7~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101111101010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \estadoAnterior.Fc~regout\,
	datac => \estado.c3~regout\,
	datad => \Selector7~0_combout\,
	combout => \Selector7~1_combout\);

-- Location: LCCOMB_X49_Y11_N18
\LEDG[7]$latch\ : cycloneii_lcell_comb
-- Equation(s):
-- \LEDG[7]$latch~combout\ = (GLOBAL(\Selector0~2clkctrl_outclk\) & ((\Selector7~1_combout\))) # (!GLOBAL(\Selector0~2clkctrl_outclk\) & (\LEDG[7]$latch~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \LEDG[7]$latch~combout\,
	datac => \Selector0~2clkctrl_outclk\,
	datad => \Selector7~1_combout\,
	combout => \LEDG[7]$latch~combout\);

-- Location: PIN_L22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[0]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(0));

-- Location: PIN_W12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[4]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(4));

-- Location: PIN_U12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[5]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(5));

-- Location: PIN_U11,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[6]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(6));

-- Location: PIN_M2,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[7]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(7));

-- Location: PIN_M1,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[8]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(8));

-- Location: PIN_L2,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\SW[9]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_SW(9));

-- Location: PIN_R21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\KEY[1]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_KEY(1));

-- Location: PIN_T22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\KEY[2]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_KEY(2));

-- Location: PIN_T21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\KEY[3]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_KEY(3));

-- Location: PIN_U22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\LEDG[0]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \ALT_INV_estado.Ab~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_LEDG(0));

-- Location: PIN_U21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\LEDG[1]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \estado.Fc~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_LEDG(1));

-- Location: PIN_V22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\LEDG[2]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_LEDG(2));

-- Location: PIN_V21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\LEDG[3]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_LEDG(3));

-- Location: PIN_W22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\LEDG[4]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_LEDG(4));

-- Location: PIN_W21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\LEDG[5]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_LEDG(5));

-- Location: PIN_Y22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\LEDG[6]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \LEDG[6]$latch~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_LEDG(6));

-- Location: PIN_Y21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\LEDG[7]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \LEDG[7]$latch~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_LEDG(7));
END structure;


