#cell1 mx2_y idps_symb compose *
# 07-Oct-98 12:09 07-Oct-98 12:09 mbkvti400 * .cp
# .
V 4 VTIcompose 1.1
A 5 3 47 45
B 5 3 47 45
F F
C t 44 45 metal2 2 1 * * N t
C i1 32 45 metal2 2 2 * * N i1
C l1 26 45 metal2 2 3 * * N l1
C l0 14 45 metal2 2 4 * * N l0
C i0 8 45 metal2 2 5 * * N i0
C t 44 3 metal2 2 6 * * S t
C i1 32 3 metal2 2 7 * * S i1
C l1 26 3 metal2 2 8 * * S l1
C l0 14 3 metal2 2 9 * * S l0
C i0 8 3 metal2 2 10 * * S i0
C vdd 47 43 metal 8 11 * * E vdd
C vdd 5 43 metal 8 12 * * W vdd
C vss 5 5 metal 8 13 * * W vss
C vss 47 5 metal 8 14 * * E vss
I cbp1 32 3 0 "cbp" ly * *
I cbp2 8 3 0 "cbp" ly * *
I cbn1 32 45 0 "cbn" ly * *
I cbn2 26 45 0 "cbn" ly * *
I cdn1 8 12 0 "cdn" ly * *
I cdn2 20 17 0 "cdn" ly * *
I cdn3 32 12 0 "cdn" ly * *
I cdn4 38 14 0 "cdn" ly * *
I cdn5 44 14 0 "cdn" ly * *
I cdp1 8 28 0 "cdp" ly * *
I cdp2 8 34 0 "cdp" ly * *
I cdp3 14 36 0 "cdp" ly * *
I cdp4 14 42 0 "cdp" ly * *
I cdp5 20 32 0 "cdp" ly * *
I cdp6 26 28 0 "cdp" ly * *
I cdp7 32 35 0 "cdp" ly * *
I cdp8 38 33 0 "cdp" ly * *
I cdp9 38 39 0 "cdp" ly * *
I cdp10 44 34 0 "cdp" ly * *
I cdp11 44 28 0 "cdp" ly * *
I cpf1 9 22 0 "cpf" ly * *
I cpf2 15 22 0 "cpf" ly * *
I cpf3 25 22 0 "cpf" ly * *
I cpf4 31 22 0 "cpf" ly * *
I cpf5 38 22 0 "cpf" ly * *
I via12x1 44 20 0 "via12" ly * *
I via12x2 32 17 0 "via12" ly * *
I via12x3 26 17 0 "via12" ly * *
I via12x4 14 17 0 "via12" ly * *
I via12x5 8 17 0 "via12" ly * *
I cbp3 38 3 0 "cbp" ly * *
I cbn3 38 45 0 "cbn" ly * *
I cbn4 44 45 0 "cbn" ly * *
I cbp4 44 3 0 "cbp" ly * *
I cbp5 26 3 0 "cbp" ly * *
I cbp6 20 3 0 "cbp" ly * *
I cbp7 14 3 0 "cbp" ly * *
I cbn5 8 45 0 "cbn" ly * *
I cbn6 20 45 0 "cbn" ly * *
P 20 27 * pdif
P 20 38 * pdif
W 17 24 23 41
S 3 V pdif P 1 P 2
P 38 22 * metal
P 38 27 * metal
W 36 20 40 29
S 2 V metal P 3 P 4
P 20 27 * metal
P 38 27 * metal
W 19 26 39 28
S 1 H metal P 5 P 6
P 26 27 * metal
P 26 28 * metal
W 24 25 28 30
S 2 V metal P 7 P 8
P 38 5 * metal
P 38 14 * metal
W 36 3 40 16 vss
S 2 V metal P 9 P 10
P 38 33 * metal
P 38 43 * metal
W 36 31 40 45 vdd
S 2 V metal P 11 P 12
P 5 43 * metal
P 47 43 * metal
W -3 35 55 51 vdd
S 8 H metal P 13 P 14
P 14 17 * metal
P 14 22 * metal
W 12 15 16 24
S 2 V metal P 15 P 16
P 14 22 * metal
P 15 22 * metal
W 12 20 17 24
S 2 H metal P 17 P 18
P 26 17 * metal
P 26 22 * metal
W 24 15 28 24
S 2 V metal P 19 P 20
P 25 22 * metal
P 26 22 * metal
W 23 20 28 24
S 2 H metal P 21 P 22
P 32 17 * metal
P 32 22 * metal
W 30 15 34 24
S 2 V metal P 23 P 24
P 31 22 * metal
P 32 22 * metal
W 29 20 34 24
S 2 H metal P 25 P 26
P 44 14 * metal
P 44 34 * metal
W 42 12 46 36
S 2 V metal P 27 P 28
P 8 28 * metal
P 8 34 * metal
W 6 26 10 36
S 2 V metal P 29 P 30
P 8 31 * metal
P 20 31 * metal
W 7 30 21 32
S 1 H metal P 31 P 32
P 20 31 * metal
P 20 35 * metal
W 18 29 22 37
S 2 V metal P 33 P 34
P 20 35 * metal
P 32 35 * metal
W 19 34 33 36
S 1 H metal P 35 P 36
P 32 12 * ndif
P 32 18 * ndif
W 29 9 35 21
S 3 V ndif P 37 P 38
P 38 3 * allowM2
P 38 45 * allowM2
W 36 1 40 47
S 2 V allowM2 P 39 P 40
P 20 3 * allowM2
P 20 45 * allowM2
W 18 1 22 47
S 2 V allowM2 P 41 P 42
P 38 22 * poly
P 41 22 * poly
W 35 19 44 25
S 3 H poly P 43 P 44
P 41 20 * poly
P 41 25 * poly
W 40 19 42 26
S 1 V poly P 45 P 46
P 29 22 * poly
P 31 22 * poly
W 27 20 33 24
S 2 H poly P 47 P 48
P 29 20 * poly
P 29 25 * poly
W 28 19 30 26
S 1 V poly P 49 P 50
P 23 22 * poly
P 25 22 * poly
W 21 20 27 24
S 2 H poly P 51 P 52
P 23 20 * poly
P 23 25 * poly
W 22 19 24 26
S 1 V poly P 53 P 54
P 15 22 * poly
P 17 22 * poly
W 13 20 19 24
S 2 H poly P 55 P 56
P 17 20 * poly
P 17 25 * poly
W 16 19 18 26
S 1 V poly P 57 P 58
P 9 22 * poly
P 11 22 * poly
W 7 20 13 24
S 2 H poly P 59 P 60
P 11 20 * poly
P 11 25 * poly
W 10 19 12 26
S 1 V poly P 61 P 62
P 8 3 * metal2
P 8 45 * metal2
W 6 1 10 47 i0
S 2 V metal2 P 63 P 64
P 32 3 * metal2
P 32 45 * metal2
W 30 1 34 47 i1
S 2 V metal2 P 65 P 66
P 26 3 * metal2
P 26 45 * metal2
W 24 1 28 47 l1
S 2 V metal2 P 67 P 68
P 14 3 * metal2
P 14 45 * metal2
W 12 1 16 47 l0
S 2 V metal2 P 69 P 70
P 8 22 * metal
P 9 22 * metal
W 6 20 11 24
S 2 H metal P 71 P 72
P 8 17 * metal
P 8 22 * metal
W 6 15 10 24
S 2 V metal P 73 P 74
P 44 3 * metal2
P 44 45 * metal2
W 42 1 46 47 t
S 2 V metal2 P 75 P 76
P 44 13 * ndif
P 44 18 * ndif
W 41 10 47 21
S 3 V ndif P 77 P 78
P 8 3 * ptie
P 44 3 * ptie
W 6 1 46 5
S 2 H ptie P 79 P 80
P 20 45 * ntie
P 44 45 * ntie
W 18 43 46 47
S 2 H ntie P 81 P 82
P 8 12 * ndif
P 8 18 * ndif
W 5 9 11 21
S 3 V ndif P 83 P 84
P 26 13 * ndif
P 26 18 * ndif
W 23 10 29 21
S 3 V ndif P 85 P 86
P 20 13 * ndif
P 20 18 * ndif
W 17 10 23 21
S 3 V ndif P 87 P 88
P 14 13 * ndif
P 14 18 * ndif
W 11 10 17 21
S 3 V ndif P 89 P 90
P 14 27 * pdif
P 14 42 * pdif
W 11 24 17 45
S 3 V pdif P 91 P 92
P 32 27 * pdif
P 32 38 * pdif
W 29 24 35 41
S 3 V pdif P 93 P 94
P 26 27 * pdif
P 26 38 * pdif
W 23 24 29 41
S 3 V pdif P 95 P 96
P 8 27 * pdif
P 8 38 * pdif
W 5 24 11 41
S 3 V pdif P 97 P 98
P 38 13 * ndif
P 38 18 * ndif
W 35 10 41 21
S 3 V ndif P 99 P 100
P 38 27 * pdif
P 38 39 * pdif
W 35 24 41 42
S 3 V pdif P 101 P 102
P 44 27 * pdif
P 44 38 * pdif
W 41 24 47 41
S 3 V pdif P 103 P 104
P 5 39 * nwell
P 47 39 * nwell
W -21 13 73 65
S 26 H nwell P 105 P 106
P 41 11 * ntrans
P 41 20 * ntrans
W 40 10 42 21
S 1 V ntrans P 107 P 108
P 29 11 * ntrans
P 29 20 * ntrans
W 28 10 30 21
S 1 V ntrans P 109 P 110
P 23 11 * ntrans
P 23 20 * ntrans
W 22 10 24 21
S 1 V ntrans P 111 P 112
P 17 11 * ntrans
P 17 20 * ntrans
W 16 10 18 21
S 1 V ntrans P 113 P 114
P 11 11 * ntrans
P 11 20 * ntrans
W 10 10 12 21
S 1 V ntrans P 115 P 116
P 41 25 * ptrans
P 41 40 * ptrans
W 40 24 42 41
S 1 V ptrans P 117 P 118
P 29 25 * ptrans
P 29 40 * ptrans
W 28 24 30 41
S 1 V ptrans P 119 P 120
P 23 25 * ptrans
P 23 40 * ptrans
W 22 24 24 41
S 1 V ptrans P 121 P 122
P 17 25 * ptrans
P 17 40 * ptrans
W 16 24 18 41
S 1 V ptrans P 123 P 124
P 11 25 * ptrans
P 11 40 * ptrans
W 10 24 12 41
S 1 V ptrans P 125 P 126
P 5 5 * metal
P 47 5 * metal
W -3 -3 55 13 vss
S 8 H metal P 127 P 128
P 32 5 * metal
P 32 12 * metal
W 30 3 34 14 vss
S 2 V metal P 129 P 130
P 8 45 * metal
P 44 45 * metal
W 6 43 46 47 vdd
S 2 H metal P 131 P 132
P 14 36 * metal
P 14 45 * metal
W 12 34 16 47 vdd
S 2 V metal P 133 P 134
P 8 3 * metal
P 8 12 * metal
W 6 1 10 14 vss
S 2 V metal P 135 P 136
P 8 3 * metal
P 44 3 * metal
W 6 1 46 5 vss
S 2 H metal P 137 P 138
P 20 17 * metal
P 20 27 * metal
W 19 16 21 28
S 1 V metal P 139 P 140
E
