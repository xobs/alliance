#cell1 ammuxiinbot_c idps_symb compose *
# 21-Feb-95 12:25 21-Feb-95 12:25 mbkvti400 * .cp
# .
V 4 VTIcompose 1.1
A 2 5 79 65
B 2 5 79 65
F F
C n2j 63 65 metal 1 1 * * N n2j
C c2j 33 65 metal 1 2 * * N c2j
C d2j 11 65 metal 1 3 * * N d2j
C vdd 79 65 metal2 2 4 * * E vdd
C vss 2 5 metal2 2 5 * * W vss
C vss 79 5 metal2 2 6 * * E vss
C ai 7 5 poly 1 7 * * S ai
C ai 2 38 metal2 2 8 * * W ai
C ai 79 38 metal2 2 9 * * E ai
C pi2j 79 23 metal2 2 10 * * E pi2j
C d2j 11 5 metal 1 11 * * S d2j
C c2j 33 5 metal 1 12 * * S c2j
C n2j 63 5 metal 1 13 * * S n2j
C vdd 2 65 metal2 2 14 * * W vdd
C d2jbar 22 65 metal 1 15 * * N d2jbar
C d2jbar 22 5 metal 1 16 * * S d2jbar
C pi2jnext 53 5 metal 1 17 * * S pi2jnext
C pi2jnext 53 65 metal 1 18 * * N pi2jnext
I cpf1 33 65 0 "cpf" ly * *
I cdp1 47 50 0 "cdp" ly * *
I via1 57 65 0 "cvia" ly * *
I cdp2 76 47 0 "cdp" ly * *
I via2 76 65 0 "cvia" ly * *
I cdn1 5 17 0 "cdn" ly * *
I via3 4 5 0 "cvia" ly * *
I cpf2 22 5 0 "cpf" ly * *
I cdn2 27 17 0 "cdn" ly * *
I cdn3 37 17 0 "cdn" ly * *
I cdn4 43 17 0 "cdn" ly * *
I cdp3 38 44 0 "cdp" ly * *
I cpf3 46 9 0 "cpf" ly * *
I cdn5 49 17 0 "cdn" ly * *
I cpf4 63 59 0 "cpf" ly * *
I cdn6 73 17 0 "cdn" ly * *
I cdn7 57 22 0 "cdn" ly * *
I cdn8 57 13 0 "cdn" ly * *
I cdn9 73 12 0 "cdn" ly * *
I cpf5 63 5 0 "cpf" ly * *
I cdn10 67 22 0 "cdn" ly * *
I cdn11 67 17 0 "cdn" ly * *
I cdp4 58 50 0 "cdp" ly * *
I cdp5 67 47 0 "cdp" ly * *
I via4 73 5 0 "cvia" ly * *
I via5 28 65 0 "cvia" ly * *
I via6 57 5 0 "cvia" ly * *
I via7 27 5 0 "cvia" ly * *
I cdp6 29 44 0 "cdp" ly * *
I via8 4 38 0 "cvia" ly * *
I cpf6 4 29 0 "cpf" ly * *
I via9 48 38 0 "cvia" ly * *
I cpf7 33 5 0 "cpf" ly * *
I cpf8 49 25 0 "cpf" ly * *
I cpf9 44 61 0 "cpf" ly * *
I cpf10 48 31 0 "cpf" ly * *
I cpf11 43 42 0 "cpf" ly * *
I via10 77 23 0 "cvia" ly * *
I cbp1 27 24 0 "cbp" ly * *
I cbn1 28 58 0 "cbn" ly * *
I cbn2 76 61 0 "cbn" ly * *
I cbn3 76 57 0 "cbn" ly * *
I cpf12 57 30 0 "cpf" ly * *
I cpf13 57 42 0 "cpf" ly * *
I cdn12 19 16 0 "cdn" ly * *
I cdp7 23 44 0 "cdp" ly * *
I cpf14 23 31 0 "cpf" ly * *
I cdp8 17 44 0 "cdp" ly * *
I cbn4 20 54 0 "cbn" ly * *
I cbn5 24 54 0 "cbn" ly * *
I cbn6 28 54 0 "cbn" ly * *
I c2j_in 33 58 0 "ref_con" ly * *
I n2j_in 63 53 0 "ref_con" ly * *
P 2 65 * metal2
P 79 65 * metal2
W -4 59 85 71
S 6 H metal2 P 1 P 2
P 14 12 * ntrans
P 14 21 * ntrans
W 13 11 15 22
S 1 V ntrans P 3 P 4
P 30 12 * ntrans
P 30 21 * ntrans
W 29 11 31 22
S 1 V ntrans P 5 P 6
P 27 14 * ndif
P 27 19 * ndif
W 24 11 30 22
S 3 V ndif P 7 P 8
P 5 14 * ndif
P 5 19 * ndif
W 2 11 8 22
S 3 V ndif P 9 P 10
P 4 5 * metal
P 4 17 * metal
W 3 4 5 18
S 1 V metal P 11 P 12
P 27 5 * metal
P 27 24 * metal
W 26 4 28 25
S 1 V metal P 13 P 14
P 40 12 * ntrans
P 40 21 * ntrans
W 39 11 41 22
S 1 V ntrans P 15 P 16
P 46 12 * ntrans
P 46 21 * ntrans
W 45 11 47 22
S 1 V ntrans P 17 P 18
P 35 14 * ndif
P 35 19 * ndif
W 29 8 41 25
S 6 V ndif P 19 P 20
P 43 14 * ndif
P 43 19 * ndif
W 40 11 46 22
S 3 V ndif P 21 P 22
P 37 9 * metal
P 46 9 * metal
W 36 8 47 10
S 1 H metal P 23 P 24
P 46 9 * poly
P 46 12 * poly
W 45 8 47 13
S 1 V poly P 25 P 26
P 50 14 * ndif
P 50 19 * ndif
W 47 11 53 22
S 3 V ndif P 27 P 28
P 57 50 * metal
P 57 65 * metal
W 56 49 58 66
S 1 V metal P 29 P 30
P 73 11 * ndif
P 73 24 * ndif
W 70 8 76 27
S 3 V ndif P 31 P 32
P 57 11 * ndif
P 57 24 * ndif
W 54 8 60 27
S 3 V ndif P 33 P 34
P 57 5 * metal
P 57 22 * metal
W 56 4 58 23
S 1 V metal P 35 P 36
P 76 47 * metal
P 76 65 * metal
W 75 46 77 66
S 1 V metal P 37 P 38
P 77 23 * metal
P 77 30 * metal
W 76 22 78 31
S 1 V metal P 39 P 40
P 35 39 * ptrans
P 35 48 * ptrans
W 34 38 36 49
S 1 V ptrans P 41 P 42
P 50 45 * ptrans
P 50 54 * ptrans
W 49 44 51 55
S 1 V ptrans P 43 P 44
P 55 45 * ptrans
P 55 54 * ptrans
W 54 44 56 55
S 1 V ptrans P 45 P 46
P 70 42 * ptrans
P 70 51 * ptrans
W 69 41 71 52
S 1 V ptrans P 47 P 48
P 73 42 * ptrans
P 73 51 * ptrans
W 72 41 74 52
S 1 V ptrans P 49 P 50
P 26 39 * ptrans
P 26 48 * ptrans
W 25 38 27 49
S 1 V ptrans P 51 P 52
P 60 9 * ntrans
P 60 26 * ntrans
W 59 8 61 27
S 1 V ntrans P 53 P 54
P 70 9 * ntrans
P 70 26 * ntrans
W 69 8 71 27
S 1 V ntrans P 55 P 56
P 70 51 * poly
P 70 53 * poly
W 69 50 71 54
S 1 V poly P 57 P 58
P 67 30 * metal
P 77 30 * metal
W 66 29 78 31
S 1 H metal P 59 P 60
P 73 5 * metal
P 73 17 * metal
W 72 4 74 18
S 1 V metal P 61 P 62
P 29 44 * metal
P 29 54 * metal
W 28 43 30 55
S 1 V metal P 63 P 64
P 65 11 * ndif
P 65 24 * ndif
W 60 6 70 29
S 5 V ndif P 65 P 66
P 60 9 * poly
P 63 9 * poly
W 59 8 64 10
S 1 H poly P 67 P 68
P 63 5 * poly
P 63 9 * poly
W 62 4 64 10
S 1 V poly P 69 P 70
P 33 5 * metal
P 33 65 * metal
W 32 4 34 66
S 1 V metal P 71 P 72
P 22 60 * metal
P 22 65 * metal
W 21 59 23 66
S 1 V metal P 73 P 74
P 70 26 * poly
P 73 26 * poly
W 69 25 74 27
S 1 H poly P 75 P 76
P 20 39 * ptrans
P 20 48 * ptrans
W 19 38 21 49
S 1 V ptrans P 77 P 78
P 66 44 * pdif
P 66 49 * pdif
W 63 41 69 52
S 3 V pdif P 79 P 80
P 58 47 * pdif
P 58 52 * pdif
W 55 44 61 55
S 3 V pdif P 81 P 82
P 23 41 * pdif
P 23 46 * pdif
W 21 39 25 48
S 2 V pdif P 83 P 84
P 30 41 * pdif
P 30 46 * pdif
W 25 36 35 51
S 5 V pdif P 85 P 86
P 47 47 * pdif
P 47 52 * pdif
W 44 44 50 55
S 3 V pdif P 87 P 88
P 39 41 * pdif
P 39 46 * pdif
W 36 38 42 49
S 3 V pdif P 89 P 90
P 53 5 * metal
P 53 65 * metal
W 52 4 54 66
S 1 V metal P 91 P 92
P 11 14 * ndif
P 11 19 * ndif
W 9 12 13 21
S 2 V ndif P 93 P 94
P 7 5 * poly
P 7 9 * poly
W 6 4 8 10
S 1 V poly P 95 P 96
P 7 9 * poly
P 8 9 * poly
W 6 8 9 10
S 1 H poly P 97 P 98
P 2 52 * nwell
P 79 52 * nwell
W -24 26 105 78
S 26 H nwell P 99 P 100
P 67 17 * metal
P 67 47 * metal
W 66 16 68 48
S 1 V metal P 101 P 102
P 63 5 * metal
P 63 65 * metal
W 62 4 64 66
S 1 V metal P 103 P 104
P 62 5 * metal
P 63 5 * metal
W 61 4 64 6
S 1 H metal P 105 P 106
P 76 44 * pdif
P 76 49 * pdif
W 73 41 79 52
S 3 V pdif P 107 P 108
P 73 26 * poly
P 73 42 * poly
W 72 25 74 43
S 1 V poly P 109 P 110
P 8 9 * poly
P 8 12 * poly
W 7 8 9 13
S 1 V poly P 111 P 112
P 37 48 * poly
P 37 60 * poly
W 36 47 38 61
S 1 V poly P 113 P 114
P 35 48 * poly
P 37 48 * poly
W 34 47 38 49
S 1 H poly P 115 P 116
P 4 21 * poly
P 4 29 * poly
W 3 20 5 30
S 1 V poly P 117 P 118
P 4 21 * poly
P 8 21 * poly
W 3 20 9 22
S 1 H poly P 119 P 120
P 4 29 * metal
P 4 38 * metal
W 3 28 5 39
S 1 V metal P 121 P 122
P 26 35 * poly
P 26 39 * poly
W 25 34 27 40
S 1 V poly P 123 P 124
P 2 38 * metal2
P 79 38 * metal2
W 0 36 81 40
S 2 H metal2 P 125 P 126
P 33 5 * poly
P 33 12 * poly
W 32 4 34 13
S 1 V poly P 127 P 128
P 37 9 * metal
P 37 28 * metal
W 36 8 38 29
S 1 V metal P 129 P 130
P 40 21 * poly
P 40 25 * poly
W 39 20 41 26
S 1 V poly P 131 P 132
P 49 17 * metal
P 49 25 * metal
W 48 16 50 26
S 1 V metal P 133 P 134
P 38 61 * metal
P 44 61 * metal
W 37 60 45 62
S 1 H metal P 135 P 136
P 44 61 * poly
P 50 61 * poly
W 43 60 51 62
S 1 H poly P 137 P 138
P 50 54 * poly
P 50 61 * poly
W 49 53 51 62
S 1 V poly P 139 P 140
P 30 25 * poly
P 49 25 * poly
W 29 24 50 26
S 1 H poly P 141 P 142
P 30 25 * poly
P 30 31 * poly
W 29 24 31 32
S 1 V poly P 143 P 144
P 43 17 * metal
P 43 50 * metal
W 42 16 44 51 t_s
S 1 V metal P 145 P 146
P 48 31 * metal
P 48 38 * metal
W 47 30 49 39
S 1 V metal P 147 P 148
P 39 31 * poly
P 48 31 * poly
W 38 30 49 32
S 1 H poly P 149 P 150
P 39 31 * poly
P 39 35 * poly
W 38 30 40 36
S 1 V poly P 151 P 152
P 26 35 * poly
P 39 35 * poly
W 25 34 40 36
S 1 H poly P 153 P 154
P 43 50 * metal
P 47 50 * metal
W 42 49 48 51
S 1 H metal P 155 P 156
P 38 28 * metal
P 38 61 * metal
W 37 27 39 62
S 1 V metal P 157 P 158
P 37 28 * metal
P 38 28 * metal
W 36 27 39 29
S 1 H metal P 159 P 160
P 30 12 * poly
P 33 12 * poly
W 29 11 34 13
S 1 H poly P 161 P 162
P 4 17 * metal
P 5 17 * metal
W 3 16 6 18
S 1 H metal P 163 P 164
P 77 23 * metal2
P 79 23 * metal2
W 75 21 81 25
S 2 H metal2 P 165 P 166
P 2 5 * metal2
P 79 5 * metal2
W -6 -3 87 13
S 8 H metal2 P 167 P 168
P 8 12 * ntrans
P 8 21 * ntrans
W 7 11 9 22
S 1 V ntrans P 169 P 170
P 28 54 * metal
P 28 65 * metal
W 26 52 30 67
S 2 V metal P 171 P 172
P 28 54 * metal
P 29 54 * metal
W 27 53 30 55
S 1 H metal P 173 P 174
P 57 50 * metal
P 58 50 * metal
W 56 49 59 51
S 1 H metal P 175 P 176
P 33 64 * poly
P 33 65 * poly
W 32 63 34 66
S 1 V poly P 177 P 178
P 33 61 * poly
P 37 61 * poly
W 32 60 38 62
S 1 H poly P 179 P 180
P 37 60 * poly
P 37 61 * poly
W 36 59 38 62
S 1 V poly P 181 P 182
P 63 59 * poly
P 70 59 * poly
W 62 58 71 60
S 1 H poly P 183 P 184
P 70 52 * poly
P 70 59 * poly
W 69 51 71 60
S 1 V poly P 185 P 186
P 33 61 * poly
P 33 65 * poly
W 32 60 34 66
S 1 V poly P 187 P 188
P 76 57 * metal
P 76 65 * metal
W 74 55 78 67
S 2 V metal P 189 P 190
P 76 57 * ntie
P 76 61 * ntie
W 73 54 79 64
S 3 V ntie P 191 P 192
P 51 35 * poly
P 51 42 * poly
W 50 34 52 43
S 1 V poly P 193 P 194
P 51 35 * poly
P 73 35 * poly
W 50 34 74 36
S 1 H poly P 195 P 196
P 43 42 * poly
P 51 42 * poly
W 42 41 52 43
S 1 H poly P 197 P 198
P 49 25 * poly
P 53 25 * poly
W 48 24 54 26
S 1 H poly P 199 P 200
P 53 25 * poly
P 53 30 * poly
W 52 24 54 31
S 1 V poly P 201 P 202
P 53 30 * poly
P 57 30 * poly
W 52 29 58 31
S 1 H poly P 203 P 204
P 57 30 * metal
P 57 42 * metal
W 56 29 58 43
S 1 V metal P 205 P 206
P 55 42 * poly
P 57 42 * poly
W 54 41 58 43
S 1 H poly P 207 P 208
P 55 42 * poly
P 55 45 * poly
W 54 41 56 46
S 1 V poly P 209 P 210
P 15 60 * metal
P 22 60 * metal
W 14 59 23 61
S 1 H metal P 211 P 212
P 15 10 * metal
P 22 10 * metal
W 14 9 23 11
S 1 H metal P 213 P 214
P 22 5 * metal
P 22 10 * metal
W 21 4 23 11
S 1 V metal P 215 P 216
P 19 14 * ndif
P 19 19 * ndif
W 14 9 24 24
S 5 V ndif P 217 P 218
P 23 31 * metal
P 23 44 * metal
W 22 30 24 45
S 1 V metal P 219 P 220
P 19 31 * metal
P 23 31 * metal
W 18 30 24 32
S 1 H metal P 221 P 222
P 19 16 * metal
P 19 31 * metal
W 18 15 20 32
S 1 V metal P 223 P 224
P 11 5 * metal
P 11 11 * metal
W 10 4 12 12
S 1 V metal P 225 P 226
P 9 11 * metal
P 11 11 * metal
W 8 10 12 12
S 1 H metal P 227 P 228
P 9 11 * metal
P 9 60 * metal
W 8 10 10 61
S 1 V metal P 229 P 230
P 9 60 * metal
P 11 60 * metal
W 8 59 12 61
S 1 H metal P 231 P 232
P 11 60 * metal
P 11 65 * metal
W 10 59 12 66
S 1 V metal P 233 P 234
P 15 55 * metal
P 15 60 * metal
W 14 54 16 61
S 1 V metal P 235 P 236
P 13 55 * metal
P 15 55 * metal
W 12 54 16 56
S 1 H metal P 237 P 238
P 13 16 * metal
P 13 55 * metal
W 12 15 14 56
S 1 V metal P 239 P 240
P 13 16 * metal
P 15 16 * metal
W 12 15 16 17
S 1 H metal P 241 P 242
P 15 10 * metal
P 15 16 * metal
W 14 9 16 17
S 1 V metal P 243 P 244
P 17 41 * pdif
P 17 46 * pdif
W 14 38 20 49
S 3 V pdif P 245 P 246
P 17 44 * metal
P 17 49 * metal
W 16 43 18 50
S 1 V metal P 247 P 248
P 17 49 * metal
P 29 49 * metal
W 16 48 30 50
S 1 H metal P 249 P 250
P 22 5 * poly
P 22 12 * poly
W 21 4 23 13
S 1 V poly P 251 P 252
P 14 12 * poly
P 22 12 * poly
W 13 11 23 13
S 1 H poly P 253 P 254
P 14 21 * poly
P 14 35 * poly
W 13 20 15 36
S 1 V poly P 255 P 256
P 14 35 * poly
P 20 35 * poly
W 13 34 21 36
S 1 H poly P 257 P 258
P 20 35 * poly
P 20 39 * poly
W 19 34 21 40
S 1 V poly P 259 P 260
P 23 31 * poly
P 30 31 * poly
W 22 30 31 32
S 1 H poly P 261 P 262
P 20 54 * metal
P 28 54 * metal
W 18 52 30 56
S 2 H metal P 263 P 264
P 20 54 * ntie
P 28 54 * ntie
W 17 51 31 57
S 3 H ntie P 265 P 266
P 28 54 * ntie
P 28 58 * ntie
W 25 51 31 61
S 3 V ntie P 267 P 268
P 73 24 * ndif
P 73 11 * ndif
W 71 9 75 26
S 2 V ndif P 269 P 270
P 67 24 * ndif
P 67 11 * ndif
W 65 9 69 26
S 2 V ndif P 271 P 272
P 57 24 * ndif
P 57 11 * ndif
W 55 9 59 26
S 2 V ndif P 273 P 274
P 63 24 * ndif
P 63 11 * ndif
W 61 9 65 26
S 2 V ndif P 275 P 276
P 49 19 * ndif
P 49 14 * ndif
W 47 12 51 21
S 2 V ndif P 277 P 278
P 33 19 * ndif
P 33 14 * ndif
W 31 12 35 21
S 2 V ndif P 279 P 280
P 19 19 * ndif
P 19 14 * ndif
W 17 12 21 21
S 2 V ndif P 281 P 282
P 17 19 * ndif
P 17 14 * ndif
W 15 12 19 21
S 2 V ndif P 283 P 284
P 32 46 * pdif
P 32 41 * pdif
W 30 39 34 48
S 2 V pdif P 285 P 286
P 38 46 * pdif
P 38 41 * pdif
W 36 39 40 48
S 2 V pdif P 287 P 288
P 67 49 * pdif
P 67 44 * pdif
W 65 42 69 51
S 2 V pdif P 289 P 290
E
