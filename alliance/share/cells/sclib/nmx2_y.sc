#cell2 * nmx2_y sc * 2 CMOS 16384 v8r4.4
# "21-Nov-94 GMT" "16:56:16 GMT" "21-Nov-94 GMT" "16:56:16 GMT" scr * .icn nChannelTransistor .sc nChannelTransistor .icn pChannelTransistor .sc pChannelTransistor .
V 4
 $H 2 10000 "Asheet" 1 "nmx2_y"; $B "Asheet" 1100 800; $D 2; D
"pChannelTransistor" "pChannelTransistor" 3 "gate" 0 0 1 "source" 30
20 2 "drain" 30 -20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
D "nChannelTransistor" "nChannelTransistor" 3 "gate" 0 0 1 "source" 30
-20 2 "drain" 30 20 3 3 "chwidth" 1 "chlength" 2 "gateCapacitance" 3;
$N 11 "I1" "J0" "J1" "I0" "F" "VDD" "VSS" "BULK" "" "" ""; $C 7; C 4
1 1; C 1 1 2; C 2 1 3; C 3 1 4; C 5 1 5; C 6 1 6; C 7 1 7; $J 8
; J 1 "u2" 3 1 1 2 2 1 6 3 1 9 2 1 0 "23" 2 0 "1"; J 1 "u3" 3 1 1 1 2
1 9 3 1 5 2 1 0 "23" 2 0 "1"; J 2 "u9" 3 1 1 3 2 1 7 3 1 11 2 1 0
"12" 2 0 "1"; J 1 "u5" 3 1 1 4 2 1 9 3 1 5 2 1 0 "23" 2 0 "1"; J 2
"u6" 3 1 1 4 2 1 10 3 1 5 2 1 0 "12" 2 0 "1"; J 2 "u7" 3 1 1 1 2 1 7
3 1 10 2 1 0 "12" 2 0 "1"; J 2 "u8" 3 1 1 2 2 1 11 3 1 5 2 1 0 "12" 2
0 "1"; J 1 "u4" 3 3 1 9 2 1 6 1 1 3 2 1 0 "23" 2 0 "1"; $I 8; I 1
"u2" "@" 420 500 0 22 2 1 0 "23" 2 0 "1"; I 1 "u3" "@" 420 420 0 22 2
1 0 "23" 2 0 "1"; I 2 "u9" "@" 540 240 0 22 2 1 0 "12" 2 0 "1"; I 1
"u5" "@" 540 420 0 22 2 1 0 "23" 2 0 "1"; I 2 "u6" "@" 420 320 0 22 2
1 0 "12" 2 0 "1"; I 2 "u7" "@" 420 240 0 22 2 1 0 "12" 2 0 "1"; I 2
"u8" "@" 540 320 0 22 2 1 0 "12" 2 0 "1"; I 1 "u4" "@" 540 500 0 22 2
1 0 "23" 2 0 "1"; $E 51; E 20400002 420 500 1 1 1; E 20400002 450
520 1 1 2; E 20400002 450 480 1 1 3; E 20400002 420 420 1 2 1; E
20400002 450 440 1 2 2; E 20400002 450 400 1 2 3; E 20400002 570 480
1 8 3; E 20000002 570 200 0; E 20000002 450 200 0; E 20400002 540
420 1 4 1; E 20400002 570 440 1 4 2; E 20400002 570 400 1 4 3; E
20400002 420 320 1 5 1; E 20400002 450 300 1 5 2; E 20400002 450 340
1 5 3; E 20400002 420 240 1 6 1; E 20400002 450 220 1 6 2; E
20400002 450 260 1 6 3; E 20400002 540 320 1 7 1; E 20400002 570 300
1 7 2; E 20400002 570 340 1 7 3; E 20400002 540 240 1 3 1; E
20400002 570 220 1 3 2; E 20400002 570 260 1 3 3; E 20000002 450 550
0; E 20000002 570 550 0; E 20400002 570 520 1 8 2; E 20400002 540
500 1 8 1; E 20200002 280 240 + 280 245 "i1" 1 LB H 0 + 280 225 "" 1
LB H 0 4 0; E 20000002 570 370 0; E 20000002 390 420 0; E 20000002
570 460 0; E 20000002 450 460 0; E 20000002 390 240 0; E 20200002
280 500 + 280 505 "j0" 1 LB H 0 + 280 485 "" 1 LB H 0 1 0; E 20000002
450 370 0; E 20000002 360 500 0; E 20000002 360 350 0; E 20000002
540 350 0; E 20000002 510 500 0; E 20000002 510 240 0; E 20000002
510 450 0; E 20200002 280 450 + 280 455 "j1" 1 LB H 0 + 280 435 "" 1
LB H 0 2 0; E 20200002 280 320 + 280 325 "i0" 1 LB H 0 + 280 305 "" 1
LB H 0 3 0; E 20000002 480 420 0; E 20000002 480 320 0; E 20200002
680 370 + 680 375 "f" 1 LB H 0 + 680 355 "" 1 LB H 0 5 0; E 20000002
510 550 0; E 20200002 510 600 + 510 605 "vdd" 1 LB H 0 + 510 585 "" 1
LB H 0 6 0; E 20000002 510 200 0; E 20200002 510 160 + 510 165 "vss"
1 LB H 0 + 510 145 "" 1 LB H 0 7 0; $S 41; S 2 25 2; S 34 16 2; S
30 47 2; S 29 34 2; S 27 26 2; S 18 14 2; S 9 17 2; S 33 32 2; S
8 23 2; S 24 20 2; S 36 30 2; S 5 33 2; S 21 30 2; S 30 12 2; S
48 49 2; S 32 7 2; S 11 32 2; S 33 3 2; S 15 36 2; S 36 6 2; S
35 37 2; S 37 1 2; S 38 37 2; S 38 39 2; S 19 39 2; S 40 28 2; S
41 22 2; S 41 42 2; S 42 40 2; S 43 42 2; S 44 13 2; S 45 10 2;
S 46 45 2; S 13 46 2; S 31 4 2; S 34 31 2; S 25 48 2; S 48 26 2;
S 9 50 2; S 50 8 2; S 51 50 2; $T 1; T + 480 70 "nmx2_y" 1 LB H 0
; $Z;
