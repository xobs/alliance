#cell1 amoutptop_c idps_symb compose *
# 21-Feb-95 12:26 21-Feb-95 12:26 mbkvti400 * .cp
# .
V 4 VTIcompose 1.1
A 2 5 35 65
B 2 5 35 65
F F
C vss 2 5 metal2 2 1 * * W vss
C vdd 2 65 metal2 2 2 * * W vdd
C mi 14 5 metal 1 3 * * S mi
C mi 14 65 metal 1 4 * * N mi
C mnext 2 38 metal2 2 5 * * W mnext
C mnext 23 5 metal 1 6 * * S mnext
C vss 35 5 metal2 8 7 * * E vss
C vdd 35 65 metal2 6 8 * * E vdd
I via1 20 38 0 "cvia" ly * *
I via2 19 5 0 "cvia" ly * *
I via3 19 65 0 "cvia" ly * *
I cbn1 19 60 0 "cbn" ly * *
I cbn2 19 56 0 "cbn" ly * *
I cbn3 19 52 0 "cbn" ly * *
I cbn4 19 48 0 "cbn" ly * *
I cbn5 19 44 0 "cbn" ly * *
I cbn6 23 60 0 "cbn" ly * *
I cbn7 27 60 0 "cbn" ly * *
I cbn8 31 60 0 "cbn" ly * *
I cbn9 23 52 0 "cbn" ly * *
I cbn10 27 52 0 "cbn" ly * *
I cbn11 31 52 0 "cbn" ly * *
I cbn12 23 44 0 "cbn" ly * *
I cbn13 27 44 0 "cbn" ly * *
I cbn14 31 44 0 "cbn" ly * *
I cbp1 19 11 0 "cbp" ly * *
I cbp2 19 15 0 "cbp" ly * *
I cbp3 19 19 0 "cbp" ly * *
I cbp4 19 23 0 "cbp" ly * *
I mnext_in 20 38 0 "ref_con" ly * *
P 2 5 * metal2
P 35 5 * metal2
W -6 -3 43 13
S 8 H metal2 P 1 P 2
P 2 65 * metal2
P 35 65 * metal2
W -4 59 41 71
S 6 H metal2 P 3 P 4
P 14 5 * metal
P 14 65 * metal
W 13 4 15 66
S 1 V metal P 5 P 6
P 23 5 * metal
P 23 28 * metal
W 22 4 24 29
S 1 V metal P 7 P 8
P 2 52 * nwell
P 35 52 * nwell
W -24 26 61 78
S 26 H nwell P 9 P 10
P 2 38 * metal2
P 20 38 * metal2
W 0 36 22 40
S 2 H metal2 P 11 P 12
P 20 28 * metal
P 23 28 * metal
W 19 27 24 29
S 1 H metal P 13 P 14
P 20 28 * metal
P 20 38 * metal
W 19 27 21 39
S 1 V metal P 15 P 16
P 19 44 * metal
P 19 65 * metal
W 17 42 21 67
S 2 V metal P 17 P 18
P 19 5 * metal
P 19 23 * metal
W 17 3 21 25
S 2 V metal P 19 P 20
P 19 60 * metal
P 31 60 * metal
W 17 58 33 62
S 2 H metal P 21 P 22
P 19 52 * metal
P 31 52 * metal
W 17 50 33 54
S 2 H metal P 23 P 24
P 19 44 * metal
P 31 44 * metal
W 17 42 33 46
S 2 H metal P 25 P 26
P 19 60 * ntie
P 31 60 * ntie
W 16 57 34 63
S 3 H ntie P 27 P 28
P 19 44 * ntie
P 19 60 * ntie
W 16 41 22 63
S 3 V ntie P 29 P 30
P 19 44 * ntie
P 31 44 * ntie
W 16 41 34 47
S 3 H ntie P 31 P 32
P 19 52 * ntie
P 31 52 * ntie
W 16 49 34 55
S 3 H ntie P 33 P 34
P 19 11 * ptie
P 19 23 * ptie
W 16 8 22 26
S 3 V ptie P 35 P 36
E
