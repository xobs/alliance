#cell1 amoutibot_c idps_symb compose *
# 21-Feb-95 12:26 21-Feb-95 12:26 mbkvti400 * .cp
# .
V 4 VTIcompose 1.1
A 2 5 35 65
B 2 5 35 65
F F
C vss 2 5 metal2 2 1 * * W vss
C vdd 2 65 metal2 2 2 * * W vdd
C m0 5 5 metal 1 3 * * S m0
C m0 5 65 metal 1 4 * * N m0
C mi 23 65 metal 1 5 * * N mi
C mi 23 5 metal 1 6 * * S mi
C msb 14 5 metal 1 7 * * S msb
C mnext 2 38 metal2 2 8 * * W mnext
C mnext 9 5 metal 1 9 * * S mnext
C vss 35 5 metal2 8 10 * * E vss
C vdd 35 65 metal2 6 11 * * E vdd
I via1 19 38 0 "cvia" ly * *
I via2 27 38 0 "cvia" ly * *
I via3 9 38 0 "cvia" ly * *
I via4 19 65 0 "cvia" ly * *
I cbn1 19 60 0 "cbn" ly * *
I cbn2 19 56 0 "cbn" ly * *
I cbn3 19 52 0 "cbn" ly * *
I cbn4 19 48 0 "cbn" ly * *
I cbn5 15 60 0 "cbn" ly * *
I cbn6 10 60 0 "cbn" ly * *
I cbn7 10 48 0 "cbn" ly * *
I cbn8 15 48 0 "cbn" ly * *
I via5 19 5 0 "cvia" ly * *
I cbp1 19 11 0 "cbp" ly * *
I cbp2 19 15 0 "cbp" ly * *
I cbp3 19 19 0 "cbp" ly * *
I cbp4 19 23 0 "cbp" ly * *
I mnext_in 9 38 0 "ref_con" ly * *
I msb_1 27 53 0 "ref_con" ly * *
I msb_2 27 48 0 "ref_con" ly * *
I msb_3 27 43 0 "ref_con" ly * *
I msb_5 27 33 0 "ref_con" ly * *
I msb_6 27 28 0 "ref_con" ly * *
I msb_7 27 23 0 "ref_con" ly * *
I msb_8 27 18 0 "ref_con" ly * *
I msb_9 27 13 0 "ref_con" ly * *
I lsb_9 32 13 0 "ref_con" ly * *
I lsb_8 32 18 0 "ref_con" ly * *
I lsb_7 32 23 0 "ref_con" ly * *
I lsb_6 32 28 0 "ref_con" ly * *
I lsb_5 32 33 0 "ref_con" ly * *
I lsb_3 32 43 0 "ref_con" ly * *
I lsb_2 32 48 0 "ref_con" ly * *
I lsb_1 32 53 0 "ref_con" ly * *
I lsb_4 32 38 0 "ref_con" ly * *
I msb_4 27 38 0 "ref_con" ly * *
I lsb_0 32 58 0 "ref_con" ly * *
I msb 35 38 0 "ref_ref" ly * *
I lsb 35 58 0 "ref_ref" ly * *
P 32 58 * allowM2
P 35 58 * allowM2
W 30 56 37 60 p9
S 2 H allowM2 P 1 P 2
P 27 53 * allowM2
P 35 53 * allowM2
W 25 51 37 55 p8
S 2 H allowM2 P 3 P 4
P 27 48 * allowM2
P 35 48 * allowM2
W 25 46 37 50 p7
S 2 H allowM2 P 5 P 6
P 27 43 * allowM2
P 35 43 * allowM2
W 25 41 37 45 p6
S 2 H allowM2 P 7 P 8
P 27 38 * allowM2
P 35 38 * allowM2
W 25 36 37 40 p5
S 2 H allowM2 P 9 P 10
P 27 33 * allowM2
P 35 33 * allowM2
W 25 31 37 35 p4
S 2 H allowM2 P 11 P 12
P 27 28 * allowM2
P 35 28 * allowM2
W 25 26 37 30 p3
S 2 H allowM2 P 13 P 14
P 27 23 * allowM2
P 35 23 * allowM2
W 25 21 37 25 p2
S 2 H allowM2 P 15 P 16
P 27 18 * allowM2
P 35 18 * allowM2
W 25 16 37 20 p1
S 2 H allowM2 P 17 P 18
P 2 5 * metal2
P 35 5 * metal2
W -6 -3 43 13
S 8 H metal2 P 19 P 20
P 5 5 * metal
P 5 65 * metal
W 4 4 6 66
S 1 V metal P 21 P 22
P 2 52 * nwell
P 35 52 * nwell
W -24 26 61 78
S 26 H nwell P 23 P 24
P 2 38 * metal2
P 9 38 * metal2
W 0 36 11 40
S 2 H metal2 P 25 P 26
P 23 5 * metal
P 23 65 * metal
W 22 4 24 66
S 1 V metal P 27 P 28
P 14 5 * metal
P 14 31 * metal
W 13 4 15 32
S 1 V metal P 29 P 30
P 14 31 * metal
P 19 31 * metal
W 13 30 20 32
S 1 H metal P 31 P 32
P 19 31 * metal
P 19 38 * metal
W 18 30 20 39
S 1 V metal P 33 P 34
P 19 38 * metal2
P 27 38 * metal2
W 17 36 29 40
S 2 H metal2 P 35 P 36
P 27 13 * metal
P 27 53 * metal
W 26 12 28 54
S 1 V metal P 37 P 38
P 32 13 * metal
P 32 58 * metal
W 31 12 33 59
S 1 V metal P 39 P 40
P 2 65 * metal2
P 35 65 * metal2
W -4 59 41 71
S 6 H metal2 P 41 P 42
P 9 5 * metal
P 9 38 * metal
W 8 4 10 39
S 1 V metal P 43 P 44
P 19 48 * metal
P 19 65 * metal
W 17 46 21 67
S 2 V metal P 45 P 46
P 10 60 * metal
P 19 60 * metal
W 8 58 21 62
S 2 H metal P 47 P 48
P 10 48 * metal
P 19 48 * metal
W 8 46 21 50
S 2 H metal P 49 P 50
P 10 60 * ntie
P 19 60 * ntie
W 7 57 22 63
S 3 H ntie P 51 P 52
P 19 48 * ntie
P 19 60 * ntie
W 16 45 22 63
S 3 V ntie P 53 P 54
P 10 48 * ntie
P 19 48 * ntie
W 7 45 22 51
S 3 H ntie P 55 P 56
P 19 5 * metal
P 19 23 * metal
W 17 3 21 25
S 2 V metal P 57 P 58
P 19 11 * ptie
P 19 23 * ptie
W 16 8 22 26
S 3 V ptie P 59 P 60
P 27 13 * allowM2
P 35 13 * allowM2
W 25 11 37 15 p0
S 2 H allowM2 P 61 P 62
E
