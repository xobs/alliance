#cell1 mx2sc_fp CMOS schematic 19456 v7r5.6
# 8-Feb-94 14:12 8-Feb-94 14:12 fitpath * .icn pChannelTransistor .sc
# pChannelTransistor .icn nChannelTransistor .sc nChannelTransistor .
V 4
 $H 2 10000 "Asheet" 1 ""; $B "Asheet" 1100 800; $D 2; D
"nChannelTransistor" "nChannelTransistor" 3 "gate" 0 0 1 "source" 30
-20 2 "drain" 30 20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
D "pChannelTransistor" "pChannelTransistor" 3 "gate" 0 0 1 "source" 30
20 2 "drain" 30 -20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
$N 13 "S0I0" "S1I0" "I0" "I1" "O" "VDD" "VSS" "BULK" "" "" "" "" ""; $C 7
; C 1 1 1; C 2 1 2; C 3 1 3; C 4 1 4; C 5 1 5; C 6 1 6; C 7 1 7
; $J 10; J 1 "u2" 3 1 1 1 2 1 9 3 1 10 2 1 0 "9" 2 0 "1"; J 1 "u3" 3
1 1 3 2 1 7 3 1 9 2 1 0 "9" 2 0 "1"; J 2 "u7" 3 3 1 10 2 1 11 1 1 1 2
1 0 "18" 2 0 "1"; J 1 "u5" 3 3 1 12 2 1 7 1 1 4 2 1 0 "9" 2 0 "1"; J
2 "u6" 3 1 1 2 2 1 13 3 1 10 2 1 0 "18" 2 0 "1"; J 1 "u4" 3 1 1 2 2 1
12 3 1 10 2 1 0 "9" 2 0 "1"; J 2 "u8" 3 1 1 3 2 1 6 3 1 13 2 1 0 "18"
2 0 "1"; J 2 "u9" 3 1 1 4 2 1 6 3 1 11 2 1 0 "18" 2 0 "1"; J 2 "u10"
3 1 1 10 2 1 6 3 1 5 2 1 0 "12" 2 0 "1"; J 1 "u11" 3 1 1 10 2 1 7 3 1
5 2 1 0 "6" 2 0 "1"; $I 10; I 1 "u2" "@" 330 410 0 22 2 1 0 "9" 2 0
"1"; I 1 "u3" "@" 330 340 0 22 2 1 0 "9" 2 0 "1"; I 2 "u7" "@" 460
540 4 22 2 1 0 "18" 2 0 "1"; I 1 "u5" "@" 460 340 4 22 2 1 0 "9" 2 0
"1"; I 2 "u6" "@" 330 540 0 22 2 1 0 "18" 2 0 "1"; I 1 "u4" "@" 460
410 4 22 2 1 0 "9" 2 0 "1"; I 2 "u8" "@" 330 620 0 22 2 1 0 "18" 2 0
"1"; I 2 "u9" "@" 460 620 4 22 2 1 0 "18" 2 0 "1"; I 2 "u10" "@" 520
540 0 22 2 1 0 "12" 2 0 "1"; I 1 "u11" "@" 520 410 0 22 2 1 0 "6" 2 0
"1"; $E 66; E 20400002 330 410 1 1 1; E 20400002 360 390 1 1 2; E
20400002 360 430 1 1 3; E 20400002 330 340 1 2 1; E 20400002 360 320
1 2 2; E 20400002 360 360 1 2 3; E 20400002 430 520 1 3 3; E
20400002 430 560 1 3 2; E 20400002 460 540 1 3 1; E 20400002 430 360
1 4 3; E 20400002 430 320 1 4 2; E 20400002 460 340 1 4 1; E
20400002 330 540 1 5 1; E 20400002 360 560 1 5 2; E 20400002 360 520
1 5 3; E 20400002 460 410 1 6 1; E 20400002 430 390 1 6 2; E
20400002 430 430 1 6 3; E 20400002 330 620 1 7 1; E 20400002 360 640
1 7 2; E 20400002 360 600 1 7 3; E 20400002 460 620 1 8 1; E
20400002 430 640 1 8 2; E 20400002 430 600 1 8 3; E 20000002 360 480
0; E 20000002 430 480 0; E 20000002 430 300 0; E 20000002 360 300 0
; E 20000002 360 660 0; E 20000002 430 660 0; E 20000002 390 660 0;
E 20200002 390 690 + 390 695 "vdd" 1 LB H 0 + 390 675 "" 1 LB H 0 6 0
; E 20000002 400 300 0; E 20200002 400 270 + 400 275 "vss" 1 LB H 0 +
400 255 "" 1 LB H 0 7 0; E 20000002 490 480 0; E 20400002 520 540 1
9 1; E 20400002 550 560 1 9 2; E 20400002 550 520 1 9 3; E 20400002
520 410 1 10 1; E 20400002 550 390 1 10 2; E 20400002 550 430 1 10 3
; E 20000002 490 540 0; E 20000002 490 410 0; E 20000002 550 660 0;
E 20000002 550 300 0; E 20200002 240 620 + 240 625 "i0" 1 LB H 0 +
240 605 "" 1 LB H 0 3 0; E 20200002 240 540 + 240 545 "s0i0" 1 LB H 0 +
240 525 "" 1 LB H 0 1 0; E 20000002 280 410 0; E 20000002 260 340 0
; E 20000002 580 340 0; E 20000002 470 410 0; E 20000002 470 370 0;
E 20000002 560 370 0; E 20000002 550 480 0; E 20200002 600 480 + 600
485 "o" 1 LB H 0 + 600 465 "" 1 LB H 0 5 0; E 20000002 560 590 0; E
20200002 600 620 + 600 625 "i1" 1 LB H 0 + 600 605 "" 1 LB H 0 4 0; E
20000002 480 540 0; E 20200002 600 590 + 600 595 "s1i0" 1 LB H 0 + 600
575 "" 1 LB H 0 2 0; E 20000002 260 620 0; E 20000002 280 540 0; E
20000002 580 620 0; E 20000002 280 570 0; E 20000002 480 570 0; E
20000002 310 590 0; E 20000002 310 540 0; $S 54; S 8 24 2; S 14 21
2; S 3 25 2; S 25 15 2; S 25 26 2; S 26 7 2; S 18 26 2; S 6 2 2
; S 10 17 2; S 27 11 2; S 31 32 2; S 28 5 2; S 20 29 2; S 23 30 2
; S 29 31 2; S 31 30 2; S 28 33 2; S 33 27 2; S 34 33 2; S 26 35
2; S 42 36 2; S 35 42 2; S 43 35 2; S 43 39 2; S 12 50 2; S 37
44 2; S 30 44 2; S 45 40 2; S 27 45 2; S 50 62 2; S 49 4 2; S 49
60 2; S 62 57 2; S 48 61 2; S 16 51 2; S 52 51 2; S 41 54 2; S
54 38 2; S 54 55 2; S 48 1 2; S 52 53 2; S 46 60 2; S 60 19 2; S
47 61 2; S 56 59 2; S 22 62 2; S 53 56 2; S 9 58 2; S 61 63 2; S
63 64 2; S 58 64 2; S 65 56 2; S 66 65 2; S 66 13 2; $Z;
