#cell1 a2p_y idps_symb compose *
# 07-Oct-98 12:02 07-Oct-98 12:02 mbkvti400 * .cp
# .
V 4 VTIcompose 1.1
A 5 3 29 45
B 5 3 29 45
F F
C vdd 29 43 metal 8 1 * * E vdd
C vss 5 5 metal 8 2 * * W vss
C vss 29 5 metal 8 3 * * E vss
C vdd 5 43 metal 8 4 * * W vdd
C i1 14 3 metal2 2 5 * * S i1
C t 8 3 metal2 2 6 * * S t
C t 8 45 metal2 2 7 * * N t
C i1 14 45 metal2 2 8 * * N i1
C i0 26 3 metal2 2 9 * * S i0
C i0 26 45 metal2 2 10 * * N i0
I cdp1 14 45 0 "cdp" ly * *
I cdp2 20 34 0 "cdp" ly * *
I cpf1 13 21 0 "cpf" ly * *
I via12x1 14 28 0 "via12" ly * *
I via12x2 8 21 0 "via12" ly * *
I cdp3 14 39 0 "cdp" ly * *
I cdp4 8 34 0 "cdp" ly * *
I cdp5 8 28 0 "cdp" ly * *
I cdn1 8 13 0 "cdn" ly * *
I cdn2 14 13 0 "cdn" ly * *
I cbn1 26 45 0 "cbn" ly * *
I cbp1 26 3 0 "cbp" ly * *
I cdn3 14 8 0 "cdn" ly * *
I via12x3 26 28 0 "via12" ly * *
I cpf2 26 22 0 "cpf" ly * *
I cpf3 18 22 0 "cpf" ly * *
I cdp6 26 34 0 "cdp" ly * *
I cdp7 14 34 0 "cdp" ly * *
I cdn4 26 13 0 "cdn" ly * *
I cbp2 20 3 0 "cbp" ly * *
I cbn2 20 45 0 "cbn" ly * *
P 17 28 * ptrans
P 17 40 * ptrans
W 16 27 18 41
S 1 V ptrans P 1 P 2
P 23 28 * ptrans
P 23 40 * ptrans
W 22 27 24 41
S 1 V ptrans P 3 P 4
P 17 7 * ntrans
P 17 19 * ntrans
W 16 6 18 20
S 1 V ntrans P 5 P 6
P 23 7 * ntrans
P 23 19 * ntrans
W 22 6 24 20
S 1 V ntrans P 7 P 8
P 20 9 * ndif
P 20 17 * ndif
W 17 6 23 20
S 3 V ndif P 9 P 10
P 20 30 * pdif
P 20 38 * pdif
W 17 27 23 41
S 3 V pdif P 11 P 12
P 11 25 * ptrans
P 11 51 * ptrans
W 10 24 12 52
S 1 V ptrans P 13 P 14
P 11 4 * ntrans
P 11 19 * ntrans
W 10 3 12 20
S 1 V ntrans P 15 P 16
P 5 39 * nwell
P 29 39 * nwell
W -21 13 55 65
S 26 H nwell P 17 P 18
P 8 6 * ndif
P 8 17 * ndif
W 5 3 11 20
S 3 V ndif P 19 P 20
P 8 27 * pdif
P 8 49 * pdif
W 5 24 11 52
S 3 V pdif P 21 P 22
P 26 3 * metal2
P 26 45 * metal2
W 24 1 28 47 i0
S 2 V metal2 P 23 P 24
P 20 3 * ptie
P 26 3 * ptie
W 18 1 28 5
S 2 H ptie P 25 P 26
P 20 45 * ntie
P 26 45 * ntie
W 18 43 28 47
S 2 H ntie P 27 P 28
P 8 3 * metal2
P 8 45 * metal2
W 6 1 10 47
S 2 V metal2 P 29 P 30
P 8 13 * metal
P 8 34 * metal
W 6 11 10 36
S 2 V metal P 31 P 32
P 26 30 * pdif
P 26 38 * pdif
W 23 27 29 41
S 3 V pdif P 33 P 34
P 14 3 * metal2
P 14 45 * metal2
W 12 1 16 47
S 2 V metal2 P 35 P 36
P 20 3 * allowM2
P 20 45 * allowM2
W 18 1 22 47
S 2 V allowM2 P 37 P 38
P 15 26 * metal
P 18 26 * metal
W 14 25 19 27
S 1 H metal P 39 P 40
P 18 22 * metal
P 18 26 * metal
W 17 21 19 27
S 1 V metal P 41 P 42
P 15 26 * metal
P 15 28 * metal
W 14 25 16 29
S 1 V metal P 43 P 44
P 14 28 * metal
P 15 28 * metal
W 13 27 16 29
S 1 H metal P 45 P 46
P 22 13 * metal
P 26 13 * metal
W 20 11 28 15
S 2 H metal P 47 P 48
P 22 13 * metal
P 22 30 * metal
W 21 12 23 31
S 1 V metal P 49 P 50
P 20 30 * metal
P 22 30 * metal
W 19 29 23 31
S 1 H metal P 51 P 52
P 20 30 * metal
P 20 34 * metal
W 18 28 22 36
S 2 V metal P 53 P 54
P 13 18 * metal
P 22 18 * metal
W 12 17 23 19
S 1 H metal P 55 P 56
P 13 18 * metal
P 13 21 * metal
W 11 16 15 23
S 2 V metal P 57 P 58
P 11 19 * poly
P 11 25 * poly
W 10 18 12 26
S 1 V poly P 59 P 60
P 11 21 * poly
P 13 21 * poly
W 9 19 15 23
S 2 H poly P 61 P 62
P 14 5 * metal
P 14 13 * metal
W 12 3 16 15 vss
S 2 V metal P 63 P 64
P 26 22 * metal
P 26 28 * metal
W 25 21 27 29
S 1 V metal P 65 P 66
P 23 19 * poly
P 23 28 * poly
W 22 18 24 29
S 1 V poly P 67 P 68
P 23 22 * poly
P 26 22 * poly
W 20 19 29 25
S 3 H poly P 69 P 70
P 14 6 * ndif
P 14 17 * ndif
W 11 3 17 20
S 3 V ndif P 71 P 72
P 26 9 * ndif
P 26 17 * ndif
W 23 6 29 20
S 3 V ndif P 73 P 74
P 17 19 * poly
P 17 28 * poly
W 16 18 18 29
S 1 V poly P 75 P 76
P 17 22 * poly
P 18 22 * poly
W 16 21 19 23
S 1 H poly P 77 P 78
P 14 27 * pdif
P 14 49 * pdif
W 11 24 17 52
S 3 V pdif P 79 P 80
P 20 3 * metal
P 26 3 * metal
W 19 2 27 4 vss
S 1 H metal P 81 P 82
P 26 3 * metal
P 26 5 * metal
W 25 2 27 6 vss
S 1 V metal P 83 P 84
P 5 5 * metal
P 29 5 * metal
W -3 -3 37 13 vss
S 8 H metal P 85 P 86
P 5 43 * metal
P 29 43 * metal
W -3 35 37 51 vdd
S 8 H metal P 87 P 88
P 14 43 * metal
P 14 45 * metal
W 13 42 15 46 vdd
S 1 V metal P 89 P 90
P 14 34 * metal
P 14 43 * metal
W 12 32 16 45 vdd
S 2 V metal P 91 P 92
P 20 45 * metal
P 26 45 * metal
W 19 44 27 46 vdd
S 1 H metal P 93 P 94
P 26 43 * metal
P 26 45 * metal
W 25 42 27 46 vdd
S 1 V metal P 95 P 96
P 26 34 * metal
P 26 43 * metal
W 24 32 28 45 vdd
S 2 V metal P 97 P 98
E
