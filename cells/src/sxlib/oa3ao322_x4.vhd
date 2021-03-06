
--
-- Generated by VASY
--
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY oa3ao322_x4 IS
PORT(
  i0	: IN STD_LOGIC;
  i1	: IN STD_LOGIC;
  i2	: IN STD_LOGIC;
  i3	: IN STD_LOGIC;
  i4	: IN STD_LOGIC;
  i5	: IN STD_LOGIC;
  i6	: IN STD_LOGIC;
  q	: OUT STD_LOGIC
);
END oa3ao322_x4;

ARCHITECTURE RTL OF oa3ao322_x4 IS
BEGIN
  q <= (((i0 AND i1) AND i2) OR (i6 AND ((i3 OR i4) OR i5)));
END RTL;
