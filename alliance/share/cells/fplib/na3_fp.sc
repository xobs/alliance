#cell1 na3_fp cmos schematic 14336 v7r5.6
# 24-Oct-91 11:43 24-Oct-91 11:43 dea9247 * .icn pChannelTransistor .sc
# pChannelTransistor .icn nChannelTransistor .sc nChannelTransistor .
V 4
 $H 2 10000 "Asheet" 1 "na3_dp"; $B "Asheet" 1100 850; $D 2; D
"nChannelTransistor" "nChannelTransistor" 3 "gate" 0 0 1 "source" 30
-20 2 "drain" 30 20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
D "pChannelTransistor" "pChannelTransistor" 3 "gate" 0 0 1 "source" 30
20 2 "drain" 30 -20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
$P 4; P 1 "nchwidth" "STRING" "4"; P 2 "nchlength" "STRING" "2"; P
3 "pchwidth" "STRING" "4"; P 4 "pchlength" "STRING" "2"; $N 9 "I0"
"I1" "I2" "VDD" "VSS" "O" "BULK" "" ""; $C 6; C 1 1 1; C 2 1 2; C
3 1 3; C 5 1 4; C 6 1 5; C 4 1 6; $J 6; J 1 "u2" 3 1 1 2 2 1 8 3
1 9 2 1 0 "12" 2 0 "1"; J 1 "u1" 3 1 1 1 2 1 9 3 1 6 2 1 0 "12" 2 0
"1"; J 2 "u3" 3 1 1 1 2 1 4 3 1 6 2 1 0 "12" 2 0 "1"; J 1 "u7" 3 1 1
3 2 1 5 3 1 8 2 1 0 "12" 2 0 "1"; J 2 "u4" 3 1 1 2 2 1 4 3 1 6 2 1 0
"12" 2 0 "1"; J 2 "u5" 3 3 1 6 2 1 4 1 1 3 2 1 0 "12" 2 0 "1"; $I 6
; I 1 "u2" "@" 720 350 0 22 2 1 0 "12" 2 0 "1"; I 1 "u1" "@" 720 440
0 22 2 1 0 "12" 2 0 "1"; I 2 "u3" "@" 720 580 0 22 2 1 0 "12" 2 0 "1"
; I 1 "u7" "@" 720 260 0 22 2 1 0 "12" 2 0 "1"; I 2 "u4" "@" 580 580
0 22 2 1 0 "12" 2 0 "1"; I 2 "u5" "@" 440 580 0 22 2 1 0 "12" 2 0 "1"
; $E 33; E 400003 720 350 1 1 1; E 400003 750 330 1 1 2; E 400003
750 370 1 1 3; E 400003 720 440 1 2 1; E 400003 750 420 1 2 2; E
400003 750 460 1 2 3; E 400003 720 580 1 3 1; E 400003 750 600 1 3 2
; E 400003 750 560 1 3 3; E 200003 330 440 + 330 445 "i0" 1 CB H 0 +
330 425 "" 1 LB H 0 1 0; E 400003 470 560 1 6 3; E 3 680 580 0; E
400003 580 580 1 5 1; E 400003 610 600 1 5 2; E 3 540 580 0; E
400003 720 260 1 4 1; E 400003 750 240 1 4 2; E 400003 750 280 1 4 3
; E 3 750 510 0; E 3 680 440 0; E 3 400 260 0; E 200003 330 350 +
330 355 "i1" 1 CB H 0 + 330 335 "" 1 LB H 0 2 0; E 3 470 510 0; E 3
610 510 0; E 400003 610 560 1 5 3; E 3 540 350 0; E 400003 470 600
1 6 2; E 400003 440 580 1 6 1; E 3 400 580 0; E 200003 330 260 +
330 265 "i2" 1 CB H 0 + 330 245 "" 1 LB H 0 3 0; E 20200002 750 640 +
750 645 "VDD" 1 LB H 0 + 750 625 "" 1 LB H 0 5 0; E 20200002 750 200
+ 750 205 "VSS" 1 LB H 0 + 750 185 "" 1 LB H 0 6 0; E 20200002 810
510 + 810 515 "o" 1 LB H 0 + 810 495 "" 1 LB H 0 4 0; $S 25; S 18 2
2; S 26 1 2; S 19 9 2; S 23 11 2; S 23 24 400002; S 6 19 2; S 24
25 2; S 27 14 2; S 15 13 2; S 20 4 2; S 3 5 2; S 21 29 200002; S
12 7 2; S 24 19 400002; S 26 15 200002; S 20 12 200002; S 14 8 2;
S 10 20 2; S 21 16 2; S 22 26 2; S 29 28 2; S 30 21 2; S 8 31 2;
S 32 17 2; S 19 33 2; $T 1; T + 550 150 "na3_dp  23/10/91" 1 LB H 0
; $Z;
