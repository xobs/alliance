
--
-- Generated by VASY
--
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY mx3_x2 IS
PORT(
  cmd0	: IN STD_LOGIC;
  cmd1	: IN STD_LOGIC;
  i0	: IN STD_LOGIC;
  i1	: IN STD_LOGIC;
  i2	: IN STD_LOGIC;
  q	: OUT STD_LOGIC
);
END mx3_x2;

ARCHITECTURE RTL OF mx3_x2 IS
BEGIN
  q <= ((NOT(cmd0) AND i0) OR (cmd0 AND ((cmd1 AND i1) OR (NOT(cmd1) AND i2))));
END RTL;
