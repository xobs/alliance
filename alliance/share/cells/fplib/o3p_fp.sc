#cell1 o3p_fp CMOS schematic 17408 v7r5.6
# 8-Feb-94 11:13 8-Feb-94 11:13 fitpath * .icn nChannelTransistor .sc
# nChannelTransistor .icn pChannelTransistor .sc pChannelTransistor .
V 4
 $H 2 10000 "Asheet" 1 "o3p_dp"; $B "Asheet" 1100 800; $D 2; D
"pChannelTransistor" "pChannelTransistor" 3 "gate" 0 0 1 "source" 30
20 2 "drain" 30 -20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
D "nChannelTransistor" "nChannelTransistor" 3 "gate" 0 0 1 "source" 30
-20 2 "drain" 30 20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
$N 10 "I0" "I1" "I2" "NO" "O" "VDD" "VSS" "BULK" "" ""; $C 7; C 1 1
1; C 2 1 2; C 3 1 3; C 4 1 4; C 5 1 5; C 6 1 6; C 7 1 7; $J 8;
J 1 "u2" 3 1 1 1 2 1 6 3 1 9 2 1 0 "21" 2 0 "1"; J 1 "u4" 3 3 1 4 2 1
10 1 1 3 2 1 0 "21" 2 0 "1"; J 2 "u9" 3 2 1 7 1 1 3 3 1 4 2 1 0 "6" 2
0 "1"; J 2 "u7" 3 3 1 4 2 1 7 1 1 1 2 1 0 "6" 2 0 "1"; J 2 "u12" 3 1
1 4 2 1 7 3 1 5 2 1 0 "11" 2 0 "1"; J 2 "u8" 3 1 1 2 2 1 7 3 1 4 2 1
0 "6" 2 0 "1"; J 1 "u10" 3 1 1 4 3 1 5 2 1 6 2 1 0 "21" 2 0 "1"; J 1
"u5" 3 3 1 10 2 1 9 1 1 2 2 1 0 "21" 2 0 "1"; $I 8; I 1 "u2" "@" 340
570 0 22 2 1 0 "21" 2 0 "1"; I 1 "u4" "@" 340 380 0 22 2 1 0 "21" 2 0
"1"; I 2 "u9" "@" 550 190 0 22 2 1 0 "6" 2 0 "1"; I 2 "u7" "@" 340
280 0 22 2 1 0 "6" 2 0 "1"; I 2 "u12" "@" 790 310 0 22 2 1 0 "11" 2 0
"1"; I 2 "u8" "@" 430 230 0 22 2 1 0 "6" 2 0 "1"; I 1 "u10" "@" 790
430 0 22 2 1 0 "21" 2 0 "1"; I 1 "u5" "@" 340 470 0 22 2 1 0 "21" 2 0
"1"; $E 50; E 20400002 340 570 1 1 1; E 20400002 370 590 1 1 2; E
20400002 370 550 1 1 3; E 20400002 370 360 1 2 3; E 20400002 370 400
1 2 2; E 20400002 340 380 1 2 1; E 20400002 580 170 1 3 2; E
20400002 550 190 1 3 1; E 20000002 310 190 0; E 20400002 790 430 1 7
1; E 20400002 790 310 1 5 1; E 20400002 820 290 1 5 2; E 20200002
370 660 + 370 665 "VDD" 1 LB H 0 + 370 645 "" 1 LB H 0 6 0; E
20000002 740 310 0; E 20000002 740 430 0; E 20400002 430 230 1 6 1;
E 20400002 460 210 1 6 2; E 20400002 460 250 1 6 3; E 20200002 220
470 + 220 475 "i1" 1 LB H 0 + 220 455 "" 1 LB H 0 2 0; E 20000002 290
470 0; E 20200002 220 380 + 220 385 "i2" 1 LB H 0 + 220 365 "" 1 LB H
0 3 0; E 20400002 820 330 1 5 3; E 20400002 370 300 1 4 3; E
20400002 370 260 1 4 2; E 20400002 340 280 1 4 1; E 20000002 370 150
0; E 20000002 460 150 0; E 20000002 580 150 0; E 20200002 460 90 +
460 95 "VSS" 1 LB H 0 + 460 75 "" 1 LB H 0 7 0; E 20400002 820 410 1
7 3; E 20400002 820 450 1 7 2; E 20000002 370 350 0; E 20000002 740
350 0; E 20000002 820 150 0; E 20000002 460 350 0; E 20000002 580
350 0; E 20000002 820 610 0; E 20000002 370 610 0; E 20200002 220
570 + 220 575 "i0" 1 LB H 0 + 220 555 "" 1 LB H 0 1 0; E 20000002 270
570 0; E 20000002 270 280 0; E 20400002 580 210 1 3 3; E 20000002
310 380 0; E 20000002 290 230 0; E 20400002 370 450 1 8 3; E
20400002 370 490 1 8 2; E 20400002 340 470 1 8 1; E 20200002 890 400
+ 890 405 "o" 1 LB H 0 + 890 385 "" 1 LB H 0 5 0; E 20000002 820 400
0; E 20200002 890 350 + 890 355 "no" 1 LB H 0 + 890 335 "" 1 LB H 0 4
0; $S 41; S 31 37 2; S 9 43 2; S 42 36 2; S 15 10 2; S 26 24 2;
S 27 17 2; S 27 28 2; S 19 20 2; S 26 27 2; S 29 27 2; S 20 47 2
; S 14 11 2; S 23 32 2; S 32 4 2; S 14 33 2; S 33 15 2; S 28 34 2
; S 34 12 2; S 32 35 2; S 18 35 2; S 35 36 2; S 36 33 2; S 46 3 2
; S 2 38 2; S 38 13 2; S 38 37 2; S 39 40 2; S 40 1 2; S 41 40 2
; S 41 25 2; S 43 6 2; S 21 43 2; S 28 7 2; S 44 16 2; S 9 8 2;
S 44 20 2; S 5 45 2; S 22 49 2; S 49 48 2; S 49 30 2; S 33 50 2;
$T 1; T + 350 40 "o3p_dp 13/05/92" 1 LB H 0; $Z;
