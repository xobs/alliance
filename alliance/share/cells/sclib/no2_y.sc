#cell2 * no2_y sc * 2 CMOS 11264 v8r4.4
# "21-Nov-94 GMT" "16:56:29 GMT" "21-Nov-94 GMT" "16:56:29 GMT" scr * .icn pChannelTransistor .sc pChannelTransistor .icn nChannelTransistor .sc nChannelTransistor .
V 4
 $H 2 10000 "Asheet" 1 "no2_y"; $B "Asheet" 1100 800; $D 2; D
"nChannelTransistor" "nChannelTransistor" 3 "gate" 0 0 1 "source" 30
-20 2 "drain" 30 20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
D "pChannelTransistor" "pChannelTransistor" 3 "gate" 0 0 1 "source" 30
20 2 "drain" 30 -20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
$N 7 "VDD" "F" "VSS" "I0" "I1" "BULK" ""; $C 5; C 4 1 1; C 3 1 2;
C 5 1 3; C 1 1 4; C 2 1 5; $J 4; J 1 "u2" 3 1 1 5 2 1 3 3 1 2 2 1
0 "6" 2 0 "1"; J 1 "u3" 3 1 1 4 2 1 3 3 1 2 2 1 0 "6" 2 0 "1"; J 2
"u4" 3 1 1 5 2 1 7 3 1 2 2 1 0 "23" 2 0 "1"; J 2 "u5" 3 1 1 4 2 1 1 3
1 7 2 1 0 "23" 2 0 "1"; $I 4; I 1 "u2" "@" 330 420 0 22 2 1 0 "6" 2
0 "1"; I 1 "u3" "@" 430 420 0 22 2 1 0 "6" 2 0 "1"; I 2 "u4" "@" 380
510 0 22 2 1 0 "23" 2 0 "1"; I 2 "u5" "@" 380 580 0 22 2 1 0 "23" 2 0
"1"; $E 25; E 20400002 330 420 1 1 1; E 20400002 360 400 1 1 2; E
20400002 360 440 1 1 3; E 20400002 430 420 1 2 1; E 20400002 460 400
1 2 2; E 20400002 460 440 1 2 3; E 20400002 380 510 1 3 1; E
20400002 410 530 1 3 2; E 20400002 410 490 1 3 3; E 20400002 380 580
1 4 1; E 20400002 410 600 1 4 2; E 20400002 410 560 1 4 3; E
20200002 410 640 + 410 645 "vdd" 1 LB H 0 + 410 625 "" 1 LB H 0 4 0;
E 20200002 510 440 + 510 445 "f" 1 LB H 0 + 510 425 "" 1 LB H 0 3 0;
E 20000002 410 440 0; E 20000002 360 370 0; E 20000002 460 370 0; E
20000002 410 370 0; E 20200002 410 340 + 410 345 "vss" 1 LB H 0 + 410
325 "" 1 LB H 0 5 0; E 20200002 230 580 + 230 585 "i0" 1 LB H 0 + 230
565 "" 1 LB H 0 1 0; E 20000002 280 580 0; E 20000002 280 380 0; E
20000002 430 380 0; E 20200002 230 510 + 230 515 "i1" 1 LB H 0 + 230
495 "" 1 LB H 0 2 0; E 20000002 330 510 0; $S 19; S 11 13 2; S 8
12 2; S 6 14 2; S 3 15 2; S 15 6 2; S 15 9 2; S 16 2 2; S 17 5 2
; S 16 18 2; S 18 17 2; S 19 18 2; S 20 21 2; S 21 10 2; S 22 21
2; S 22 23 2; S 23 4 2; S 24 25 2; S 25 7 2; S 1 25 2; $T 1; T
+ 400 270 "no2_y" 1 LB H 0; $Z;
