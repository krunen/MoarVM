# This file is generated from src/core/oplist by tools/update_ops.p6.


class MAST::Ops {}
BEGIN {
    MAST::Ops.WHO<@offsets> := nqp::list_i(0,
    0,
    1,
    3,
    5,
    7,
    9,
    11,
    13,
    15,
    17,
    19,
    21,
    23,
    25,
    27,
    29,
    31,
    33,
    35,
    37,
    39,
    41,
    43,
    45,
    47,
    49,
    51,
    53,
    55,
    57,
    59,
    61,
    63,
    65,
    67,
    69,
    71,
    73,
    75,
    76,
    77,
    78,
    79,
    79,
    81,
    83,
    85,
    87,
    89,
    91,
    93,
    96,
    99,
    102,
    105,
    108,
    111,
    114,
    116,
    118,
    119,
    120,
    121,
    122,
    124,
    125,
    127,
    129,
    131,
    133,
    134,
    136,
    138,
    140,
    142,
    145,
    148,
    151,
    154,
    156,
    158,
    161,
    164,
    167,
    170,
    173,
    176,
    179,
    182,
    185,
    188,
    191,
    194,
    196,
    198,
    200,
    202,
    204,
    206,
    208,
    210,
    213,
    216,
    219,
    222,
    224,
    226,
    228,
    230,
    233,
    236,
    239,
    242,
    244,
    246,
    249,
    252,
    255,
    257,
    260,
    263,
    266,
    269,
    271,
    273,
    275,
    277,
    279,
    281,
    283,
    285,
    287,
    289,
    291,
    293,
    294,
    296,
    299,
    302,
    304,
    308,
    309,
    311,
    313,
    315,
    317,
    319,
    321,
    323,
    325,
    327,
    329,
    331,
    333,
    335,
    337,
    339,
    342,
    343,
    344,
    346,
    349,
    352,
    355,
    358,
    361,
    364,
    368,
    371,
    374,
    376,
    378,
    380,
    382,
    384,
    386,
    389,
    392,
    394,
    396,
    398,
    399,
    402,
    405,
    409,
    413,
    415,
    417,
    420,
    423,
    427,
    433,
    436,
    439,
    441,
    443,
    445,
    448,
    451,
    453,
    457,
    459,
    462,
    467,
    472,
    474,
    476,
    478,
    481,
    485,
    487,
    489,
    493,
    498,
    503,
    506,
    510,
    516,
    517,
    520,
    523,
    526,
    529,
    532,
    537,
    541,
    543,
    545,
    547,
    549,
    551,
    553,
    556,
    558,
    560,
    562,
    564,
    566,
    568,
    570,
    573,
    576,
    580,
    584,
    588,
    592,
    596,
    599,
    602,
    605,
    608,
    611,
    614,
    617,
    620,
    623,
    627,
    631,
    635,
    638,
    642,
    646,
    651,
    655,
    659,
    664,
    667,
    670,
    672,
    674,
    677,
    680,
    682,
    685,
    691,
    694,
    696,
    698,
    699,
    702,
    705,
    708,
    711,
    713,
    715,
    717,
    720,
    723,
    726,
    729,
    732,
    735,
    738,
    741,
    744,
    746,
    748,
    751,
    753,
    755,
    758,
    761,
    764,
    767,
    770,
    773,
    776,
    779,
    781,
    783,
    785,
    787,
    789,
    791,
    793,
    795,
    797,
    799,
    801,
    803,
    805,
    807,
    809,
    811,
    815,
    817,
    820,
    823,
    826,
    828,
    830,
    832,
    837,
    842,
    847,
    852,
    856,
    860,
    864,
    868,
    873,
    878,
    883,
    888,
    892,
    896,
    900,
    904,
    906,
    907,
    909,
    910,
    912,
    914,
    915,
    916,
    917,
    918,
    919,
    921,
    922,
    923,
    924,
    926,
    927,
    930,
    932,
    934,
    936,
    938,
    940,
    942,
    945,
    947,
    949,
    951,
    955,
    957,
    959,
    961,
    964,
    966,
    968,
    970,
    972,
    974,
    976,
    978,
    980,
    982,
    985,
    987,
    990,
    992,
    995,
    998,
    1001,
    1002,
    1004,
    1006,
    1008,
    1009,
    1010,
    1011,
    1012,
    1013,
    1014,
    1015,
    1019,
    1022,
    1025,
    1028,
    1030,
    1031,
    1032,
    1034,
    1036,
    1038,
    1040,
    1042,
    1043,
    1045,
    1047,
    1049,
    1050,
    1052,
    1054,
    1055,
    1058,
    1059,
    1062,
    1065,
    1068,
    1071,
    1074,
    1077,
    1078,
    1079,
    1081,
    1083,
    1084,
    1085,
    1086,
    1091,
    1092,
    1097,
    1099,
    1101,
    1106,
    1109,
    1111,
    1112,
    1113,
    1115,
    1117,
    1120,
    1122,
    1125,
    1126,
    1127,
    1128,
    1129,
    1130,
    1133,
    1134,
    1135,
    1136,
    1138,
    1139,
    1141,
    1143,
    1146,
    1149,
    1152,
    1154,
    1157,
    1159,
    1161,
    1163,
    1165,
    1168,
    1174,
    1177,
    1180,
    1181,
    1182,
    1183,
    1184,
    1188,
    1189,
    1190,
    1191,
    1193,
    1196,
    1200,
    1201,
    1203);
    MAST::Ops.WHO<@counts> := nqp::list_i(0,
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    1,
    1,
    1,
    1,
    0,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    2,
    2,
    1,
    1,
    1,
    1,
    2,
    1,
    2,
    2,
    2,
    2,
    1,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    2,
    2,
    3,
    3,
    3,
    2,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    1,
    2,
    3,
    3,
    2,
    4,
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    1,
    1,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    4,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    2,
    2,
    2,
    1,
    3,
    3,
    4,
    4,
    2,
    2,
    3,
    3,
    4,
    6,
    3,
    3,
    2,
    2,
    2,
    3,
    3,
    2,
    4,
    2,
    3,
    5,
    5,
    2,
    2,
    2,
    3,
    4,
    2,
    2,
    4,
    5,
    5,
    3,
    4,
    6,
    1,
    3,
    3,
    3,
    3,
    3,
    5,
    4,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    3,
    4,
    4,
    5,
    4,
    4,
    5,
    3,
    3,
    2,
    2,
    3,
    3,
    2,
    3,
    6,
    3,
    2,
    2,
    1,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    2,
    2,
    3,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    4,
    2,
    3,
    3,
    3,
    2,
    2,
    2,
    5,
    5,
    5,
    5,
    4,
    4,
    4,
    4,
    5,
    5,
    5,
    5,
    4,
    4,
    4,
    4,
    2,
    1,
    2,
    1,
    2,
    2,
    1,
    1,
    1,
    1,
    1,
    2,
    1,
    1,
    1,
    2,
    1,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    2,
    2,
    2,
    4,
    2,
    2,
    2,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    2,
    3,
    2,
    3,
    3,
    3,
    1,
    2,
    2,
    2,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    4,
    3,
    3,
    3,
    2,
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    1,
    2,
    2,
    2,
    1,
    2,
    2,
    1,
    3,
    1,
    3,
    3,
    3,
    3,
    3,
    3,
    1,
    1,
    2,
    2,
    1,
    1,
    1,
    5,
    1,
    5,
    2,
    2,
    5,
    3,
    2,
    1,
    1,
    2,
    2,
    3,
    2,
    3,
    1,
    1,
    1,
    1,
    1,
    3,
    1,
    1,
    1,
    2,
    1,
    2,
    2,
    3,
    3,
    3,
    2,
    3,
    2,
    2,
    2,
    2,
    3,
    6,
    3,
    3,
    1,
    1,
    1,
    1,
    4,
    1,
    1,
    1,
    2,
    3,
    4,
    1,
    2,
    2);
    MAST::Ops.WHO<@values> := nqp::list_i(72,
    33,
    72,
    33,
    72,
    49,
    72,
    49,
    72,
    57,
    72,
    57,
    72,
    57,
    72,
    57,
    72,
    65,
    72,
    65,
    72,
    82,
    81,
    34,
    9,
    34,
    17,
    34,
    25,
    34,
    9,
    34,
    17,
    34,
    25,
    10,
    33,
    18,
    33,
    26,
    33,
    10,
    33,
    18,
    33,
    26,
    33,
    50,
    41,
    42,
    49,
    82,
    83,
    84,
    81,
    34,
    56,
    50,
    56,
    58,
    56,
    66,
    56,
    56,
    33,
    56,
    49,
    56,
    57,
    56,
    65,
    66,
    57,
    57,
    65,
    33,
    49,
    57,
    65,
    10,
    8,
    18,
    16,
    26,
    24,
    34,
    32,
    42,
    40,
    50,
    48,
    58,
    56,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    34,
    33,
    34,
    34,
    34,
    34,
    66,
    96,
    104,
    16,
    33,
    16,
    49,
    16,
    57,
    16,
    65,
    65,
    34,
    65,
    50,
    65,
    58,
    65,
    66,
    65,
    50,
    49,
    49,
    50,
    49,
    49,
    50,
    49,
    49,
    50,
    49,
    49,
    50,
    49,
    50,
    49,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    49,
    49,
    34,
    49,
    49,
    34,
    49,
    49,
    34,
    49,
    49,
    34,
    49,
    49,
    34,
    49,
    49,
    16,
    32,
    16,
    48,
    16,
    56,
    16,
    16,
    34,
    16,
    50,
    16,
    58,
    16,
    66,
    16,
    34,
    16,
    72,
    50,
    16,
    72,
    58,
    16,
    72,
    66,
    16,
    72,
    34,
    56,
    50,
    56,
    58,
    56,
    66,
    56,
    34,
    56,
    72,
    50,
    56,
    72,
    58,
    56,
    72,
    66,
    56,
    72,
    50,
    33,
    34,
    49,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    34,
    33,
    33,
    50,
    49,
    49,
    66,
    65,
    32,
    33,
    66,
    33,
    66,
    57,
    57,
    65,
    58,
    33,
    58,
    49,
    34,
    57,
    50,
    57,
    50,
    65,
    58,
    65,
    66,
    16,
    66,
    65,
    72,
    34,
    33,
    33,
    34,
    49,
    49,
    34,
    33,
    65,
    56,
    65,
    16,
    66,
    65,
    57,
    65,
    65,
    65,
    33,
    58,
    65,
    66,
    65,
    34,
    65,
    66,
    65,
    66,
    65,
    66,
    65,
    66,
    32,
    66,
    32,
    66,
    32,
    66,
    57,
    66,
    72,
    66,
    65,
    50,
    49,
    49,
    66,
    66,
    34,
    65,
    66,
    65,
    33,
    34,
    65,
    33,
    50,
    65,
    33,
    58,
    65,
    33,
    34,
    65,
    33,
    66,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    34,
    65,
    57,
    34,
    49,
    34,
    49,
    65,
    65,
    65,
    65,
    34,
    65,
    66,
    65,
    65,
    65,
    57,
    66,
    65,
    65,
    34,
    65,
    66,
    65,
    66,
    65,
    49,
    58,
    57,
    57,
    58,
    57,
    33,
    58,
    57,
    33,
    33,
    34,
    57,
    57,
    33,
    34,
    57,
    34,
    57,
    34,
    57,
    57,
    34,
    57,
    57,
    34,
    57,
    57,
    33,
    34,
    57,
    33,
    33,
    57,
    33,
    34,
    57,
    33,
    34,
    57,
    33,
    58,
    57,
    58,
    57,
    58,
    57,
    66,
    57,
    57,
    58,
    57,
    65,
    34,
    57,
    57,
    33,
    56,
    72,
    34,
    57,
    34,
    33,
    57,
    34,
    57,
    33,
    33,
    33,
    34,
    57,
    33,
    16,
    16,
    34,
    57,
    58,
    33,
    34,
    57,
    34,
    57,
    33,
    34,
    57,
    57,
    33,
    58,
    57,
    58,
    57,
    34,
    33,
    57,
    33,
    34,
    33,
    57,
    33,
    33,
    34,
    33,
    57,
    33,
    33,
    66,
    65,
    65,
    66,
    65,
    57,
    33,
    65,
    57,
    33,
    65,
    65,
    65,
    57,
    34,
    57,
    57,
    34,
    57,
    57,
    34,
    57,
    57,
    34,
    57,
    57,
    34,
    57,
    57,
    66,
    33,
    57,
    33,
    33,
    34,
    57,
    57,
    33,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    49,
    50,
    49,
    34,
    33,
    33,
    34,
    33,
    33,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    66,
    65,
    65,
    34,
    65,
    65,
    34,
    65,
    65,
    34,
    65,
    65,
    34,
    65,
    65,
    34,
    65,
    65,
    34,
    65,
    65,
    34,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    66,
    65,
    33,
    65,
    66,
    65,
    33,
    65,
    66,
    65,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    66,
    65,
    65,
    65,
    65,
    34,
    65,
    33,
    66,
    65,
    65,
    50,
    65,
    58,
    65,
    66,
    49,
    65,
    66,
    57,
    65,
    34,
    65,
    58,
    65,
    33,
    66,
    33,
    57,
    33,
    33,
    65,
    50,
    65,
    65,
    50,
    49,
    50,
    49,
    66,
    66,
    65,
    56,
    66,
    65,
    57,
    34,
    65,
    56,
    34,
    65,
    57,
    66,
    65,
    66,
    65,
    66,
    65,
    34,
    65,
    57,
    50,
    65,
    57,
    58,
    65,
    57,
    66,
    65,
    57,
    65,
    57,
    33,
    65,
    57,
    49,
    65,
    57,
    57,
    65,
    57,
    65,
    34,
    65,
    57,
    65,
    57,
    34,
    65,
    34,
    65,
    65,
    58,
    65,
    34,
    65,
    34,
    65,
    33,
    50,
    65,
    33,
    58,
    65,
    33,
    66,
    65,
    33,
    65,
    33,
    33,
    65,
    33,
    49,
    65,
    33,
    57,
    65,
    33,
    65,
    65,
    33,
    65,
    49,
    65,
    57,
    65,
    65,
    34,
    65,
    50,
    65,
    58,
    65,
    66,
    65,
    34,
    65,
    50,
    65,
    58,
    65,
    66,
    65,
    65,
    33,
    65,
    49,
    65,
    57,
    65,
    65,
    65,
    65,
    33,
    33,
    65,
    33,
    66,
    33,
    65,
    66,
    49,
    65,
    66,
    57,
    65,
    34,
    65,
    50,
    65,
    58,
    65,
    65,
    65,
    56,
    33,
    16,
    65,
    65,
    56,
    49,
    16,
    65,
    65,
    56,
    57,
    16,
    65,
    65,
    56,
    65,
    16,
    65,
    65,
    57,
    33,
    65,
    65,
    57,
    49,
    65,
    65,
    57,
    57,
    65,
    65,
    57,
    65,
    34,
    65,
    65,
    56,
    16,
    50,
    65,
    65,
    56,
    16,
    58,
    65,
    65,
    56,
    16,
    66,
    65,
    65,
    56,
    16,
    34,
    65,
    65,
    57,
    50,
    65,
    65,
    57,
    58,
    65,
    65,
    57,
    66,
    65,
    65,
    57,
    34,
    65,
    66,
    34,
    65,
    66,
    66,
    65,
    34,
    57,
    66,
    66,
    66,
    66,
    66,
    57,
    65,
    66,
    66,
    66,
    34,
    65,
    58,
    66,
    65,
    57,
    34,
    65,
    34,
    65,
    66,
    65,
    58,
    65,
    66,
    65,
    58,
    65,
    66,
    65,
    65,
    65,
    65,
    65,
    33,
    65,
    65,
    65,
    65,
    57,
    65,
    34,
    65,
    34,
    65,
    66,
    65,
    65,
    33,
    65,
    34,
    65,
    34,
    65,
    34,
    57,
    34,
    57,
    66,
    65,
    65,
    65,
    65,
    57,
    65,
    65,
    66,
    57,
    66,
    57,
    65,
    66,
    57,
    66,
    57,
    65,
    66,
    65,
    66,
    65,
    65,
    66,
    65,
    65,
    34,
    65,
    65,
    66,
    66,
    65,
    66,
    65,
    66,
    65,
    66,
    66,
    66,
    66,
    66,
    66,
    66,
    34,
    65,
    65,
    57,
    65,
    57,
    65,
    34,
    65,
    33,
    66,
    57,
    57,
    66,
    65,
    65,
    65,
    66,
    65,
    58,
    65,
    57,
    57,
    57,
    57,
    57,
    57,
    57,
    57,
    33,
    34,
    57,
    57,
    33,
    57,
    66,
    57,
    58,
    65,
    65,
    66,
    57,
    57,
    65,
    58,
    65,
    33,
    58,
    57,
    57,
    57,
    57,
    57,
    34,
    65,
    57,
    65,
    33,
    33,
    34,
    65,
    33,
    65,
    65,
    65,
    33,
    34,
    65,
    66,
    66,
    66,
    66,
    57,
    33,
    33,
    33,
    65,
    66,
    57,
    33,
    33,
    33,
    65,
    33,
    66,
    65,
    34,
    65,
    57,
    33,
    33,
    58,
    65,
    33,
    65,
    57,
    57,
    57,
    58,
    65,
    34,
    65,
    34,
    57,
    33,
    58,
    65,
    58,
    65,
    57,
    57,
    34,
    50,
    34,
    66,
    66,
    65,
    65,
    65,
    50,
    33,
    58,
    57,
    66,
    58,
    57,
    66,
    57,
    65,
    33,
    65,
    65,
    33,
    65,
    66,
    65,
    33,
    58,
    65,
    34,
    65,
    65,
    65,
    57,
    34,
    65,
    65,
    65,
    66,
    65,
    58,
    65,
    65,
    58,
    57,
    65,
    65,
    65,
    65,
    66,
    16,
    16,
    66,
    16,
    32,
    66,
    66,
    65,
    66,
    34,
    57,
    57,
    65,
    58,
    33,
    65,
    66,
    33,
    66,
    65,
    65,
    66,
    65,
    65,
    33,
    66,
    66,
    16,
    34,
    65);
    MAST::Ops.WHO<%codes> := nqp::hash('no_op', 0,
    'goto', 1,
    'if_i', 2,
    'unless_i', 3,
    'if_n', 4,
    'unless_n', 5,
    'if_s', 6,
    'unless_s', 7,
    'if_s0', 8,
    'unless_s0', 9,
    'if_o', 10,
    'unless_o', 11,
    'set', 12,
    'extend_u8', 13,
    'extend_u16', 14,
    'extend_u32', 15,
    'extend_i8', 16,
    'extend_i16', 17,
    'extend_i32', 18,
    'trunc_u8', 19,
    'trunc_u16', 20,
    'trunc_u32', 21,
    'trunc_i8', 22,
    'trunc_i16', 23,
    'trunc_i32', 24,
    'extend_n32', 25,
    'trunc_n32', 26,
    'getlex', 27,
    'bindlex', 28,
    'getlex_ni', 29,
    'getlex_nn', 30,
    'getlex_ns', 31,
    'getlex_no', 32,
    'bindlex_ni', 33,
    'bindlex_nn', 34,
    'bindlex_ns', 35,
    'bindlex_no', 36,
    'getlex_ng', 37,
    'bindlex_ng', 38,
    'return_i', 39,
    'return_n', 40,
    'return_s', 41,
    'return_o', 42,
    'return', 43,
    'const_i8', 44,
    'const_i16', 45,
    'const_i32', 46,
    'const_i64', 47,
    'const_n32', 48,
    'const_n64', 49,
    'const_s', 50,
    'add_i', 51,
    'sub_i', 52,
    'mul_i', 53,
    'div_i', 54,
    'div_u', 55,
    'mod_i', 56,
    'mod_u', 57,
    'neg_i', 58,
    'abs_i', 59,
    'inc_i', 60,
    'inc_u', 61,
    'dec_i', 62,
    'dec_u', 63,
    'getcode', 64,
    'prepargs', 65,
    'arg_i', 66,
    'arg_n', 67,
    'arg_s', 68,
    'arg_o', 69,
    'invoke_v', 70,
    'invoke_i', 71,
    'invoke_n', 72,
    'invoke_s', 73,
    'invoke_o', 74,
    'add_n', 75,
    'sub_n', 76,
    'mul_n', 77,
    'div_n', 78,
    'neg_n', 79,
    'abs_n', 80,
    'eq_i', 81,
    'ne_i', 82,
    'lt_i', 83,
    'le_i', 84,
    'gt_i', 85,
    'ge_i', 86,
    'eq_n', 87,
    'ne_n', 88,
    'lt_n', 89,
    'le_n', 90,
    'gt_n', 91,
    'ge_n', 92,
    'argconst_i', 93,
    'argconst_n', 94,
    'argconst_s', 95,
    'checkarity', 96,
    'param_rp_i', 97,
    'param_rp_n', 98,
    'param_rp_s', 99,
    'param_rp_o', 100,
    'param_op_i', 101,
    'param_op_n', 102,
    'param_op_s', 103,
    'param_op_o', 104,
    'param_rn_i', 105,
    'param_rn_n', 106,
    'param_rn_s', 107,
    'param_rn_o', 108,
    'param_on_i', 109,
    'param_on_n', 110,
    'param_on_s', 111,
    'param_on_o', 112,
    'coerce_in', 113,
    'coerce_ni', 114,
    'band_i', 115,
    'bor_i', 116,
    'bxor_i', 117,
    'bnot_i', 118,
    'blshift_i', 119,
    'brshift_i', 120,
    'pow_i', 121,
    'pow_n', 122,
    'takeclosure', 123,
    'jumplist', 124,
    'caller', 125,
    'getdynlex', 126,
    'binddynlex', 127,
    'coerce_is', 128,
    'coerce_ns', 129,
    'coerce_si', 130,
    'coerce_sn', 131,
    'smrt_numify', 132,
    'smrt_strify', 133,
    'param_sp', 134,
    'param_sn', 135,
    'ifnonnull', 136,
    'cmp_i', 137,
    'cmp_n', 138,
    'not_i', 139,
    'setlexvalue', 140,
    'exception', 141,
    'bindexmessage', 142,
    'bindexpayload', 143,
    'bindexcategory', 144,
    'getexmessage', 145,
    'getexpayload', 146,
    'getexcategory', 147,
    'throwdyn', 148,
    'throwlex', 149,
    'throwlexotic', 150,
    'throwcatdyn', 151,
    'throwcatlex', 152,
    'throwcatlexotic', 153,
    'die', 154,
    'newlexotic', 155,
    'lexoticresult', 156,
    'mod_n', 157,
    'usecapture', 158,
    'savecapture', 159,
    'captureposelems', 160,
    'captureposarg', 161,
    'captureposarg_i', 162,
    'captureposarg_n', 163,
    'captureposarg_s', 164,
    'captureposprimspec', 165,
    'invokewithcapture', 166,
    'multicacheadd', 167,
    'multicachefind', 168,
    'lexprimspec', 169,
    'ceil_n', 170,
    'floor_n', 171,
    'assign', 172,
    'assignunchecked', 173,
    'objprimspec', 174,
    'backtracestrings', 175,
    'masttofile', 176,
    'masttocu', 177,
    'iscompunit', 178,
    'compunitmainline', 179,
    'compunitcodes', 180,
    'sleep', 181,
    'concat_s', 182,
    'repeat_s', 183,
    'substr_s', 184,
    'index_s', 185,
    'graphs_s', 186,
    'codes_s', 187,
    'eq_s', 188,
    'ne_s', 189,
    'eqat_s', 190,
    'haveat_s', 191,
    'getcp_s', 192,
    'indexcp_s', 193,
    'uc', 194,
    'lc', 195,
    'tc', 196,
    'split', 197,
    'join', 198,
    'getcpbyname', 199,
    'indexat_scb', 200,
    'unipropcode', 201,
    'unipvalcode', 202,
    'hasuniprop', 203,
    'hasunipropc', 204,
    'chars', 205,
    'chr', 206,
    'ordfirst', 207,
    'ordat', 208,
    'rindexfrom', 209,
    'escape', 210,
    'flip', 211,
    'iscclass', 212,
    'findcclass', 213,
    'findnotcclass', 214,
    'nfafromstatelist', 215,
    'nfarunproto', 216,
    'nfarunalt', 217,
    'flattenropes', 218,
    'gt_s', 219,
    'ge_s', 220,
    'lt_s', 221,
    'le_s', 222,
    'cmp_s', 223,
    'radix', 224,
    'eqatic_s', 225,
    'sin_n', 226,
    'asin_n', 227,
    'cos_n', 228,
    'acos_n', 229,
    'tan_n', 230,
    'atan_n', 231,
    'atan2_n', 232,
    'sec_n', 233,
    'asec_n', 234,
    'sinh_n', 235,
    'cosh_n', 236,
    'tanh_n', 237,
    'sech_n', 238,
    'sqrt_n', 239,
    'gcd_i', 240,
    'lcm_i', 241,
    'add_I', 242,
    'sub_I', 243,
    'mul_I', 244,
    'div_I', 245,
    'mod_I', 246,
    'neg_I', 247,
    'abs_I', 248,
    'cmp_I', 249,
    'eq_I', 250,
    'ne_I', 251,
    'lt_I', 252,
    'le_I', 253,
    'gt_I', 254,
    'ge_I', 255,
    'bor_I', 256,
    'bxor_I', 257,
    'band_I', 258,
    'bnot_I', 259,
    'blshift_I', 260,
    'brshift_I', 261,
    'pow_I', 262,
    'gcd_I', 263,
    'lcm_I', 264,
    'expmod_I', 265,
    'isprime_I', 266,
    'rand_I', 267,
    'coerce_In', 268,
    'coerce_Is', 269,
    'coerce_nI', 270,
    'coerce_sI', 271,
    'isbig_I', 272,
    'base_I', 273,
    'radix_I', 274,
    'div_In', 275,
    'log_n', 276,
    'exp_n', 277,
    'knowhow', 278,
    'findmeth', 279,
    'findmeth_s', 280,
    'can', 281,
    'can_s', 282,
    'create', 283,
    'gethow', 284,
    'getwhat', 285,
    'atkey_i', 286,
    'atkey_n', 287,
    'atkey_s', 288,
    'atkey_o', 289,
    'bindkey_i', 290,
    'bindkey_n', 291,
    'bindkey_s', 292,
    'bindkey_o', 293,
    'existskey', 294,
    'deletekey', 295,
    'getwhere', 296,
    'eqaddr', 297,
    'reprname', 298,
    'isconcrete', 299,
    'atpos_i', 300,
    'atpos_n', 301,
    'atpos_s', 302,
    'atpos_o', 303,
    'bindpos_i', 304,
    'bindpos_n', 305,
    'bindpos_s', 306,
    'bindpos_o', 307,
    'push_i', 308,
    'push_n', 309,
    'push_s', 310,
    'push_o', 311,
    'pop_i', 312,
    'pop_n', 313,
    'pop_s', 314,
    'pop_o', 315,
    'shift_i', 316,
    'shift_n', 317,
    'shift_s', 318,
    'shift_o', 319,
    'unshift_i', 320,
    'unshift_n', 321,
    'unshift_s', 322,
    'unshift_o', 323,
    'splice', 324,
    'setelemspos', 325,
    'box_i', 326,
    'box_n', 327,
    'box_s', 328,
    'unbox_i', 329,
    'unbox_n', 330,
    'unbox_s', 331,
    'bindattr_i', 332,
    'bindattr_n', 333,
    'bindattr_s', 334,
    'bindattr_o', 335,
    'bindattrs_i', 336,
    'bindattrs_n', 337,
    'bindattrs_s', 338,
    'bindattrs_o', 339,
    'getattr_i', 340,
    'getattr_n', 341,
    'getattr_s', 342,
    'getattr_o', 343,
    'getattrs_i', 344,
    'getattrs_n', 345,
    'getattrs_s', 346,
    'getattrs_o', 347,
    'isnull', 348,
    'knowhowattr', 349,
    'iscoderef', 350,
    'null', 351,
    'clone', 352,
    'isnull_s', 353,
    'bootint', 354,
    'bootnum', 355,
    'bootstr', 356,
    'bootarray', 357,
    'boothash', 358,
    'sethllconfig', 359,
    'hllboxtype_i', 360,
    'hllboxtype_n', 361,
    'hllboxtype_s', 362,
    'elems', 363,
    'null_s', 364,
    'newtype', 365,
    'islist', 366,
    'ishash', 367,
    'iter', 368,
    'iterkey_s', 369,
    'iterval', 370,
    'getcodename', 371,
    'composetype', 372,
    'setmethcache', 373,
    'setmethcacheauth', 374,
    'settypecache', 375,
    'setinvokespec', 376,
    'isinvokable', 377,
    'iscont', 378,
    'decont', 379,
    'setboolspec', 380,
    'istrue', 381,
    'isfalse', 382,
    'istrue_s', 383,
    'isfalse_s', 384,
    'getcodeobj', 385,
    'setcodeobj', 386,
    'setcodename', 387,
    'forceouterctx', 388,
    'getcomp', 389,
    'bindcomp', 390,
    'getcurhllsym', 391,
    'bindcurhllsym', 392,
    'getwho', 393,
    'setwho', 394,
    'rebless', 395,
    'istype', 396,
    'ctx', 397,
    'ctxouter', 398,
    'ctxcaller', 399,
    'ctxlexpad', 400,
    'curcode', 401,
    'callercode', 402,
    'bootintarray', 403,
    'bootnumarray', 404,
    'bootstrarray', 405,
    'hlllist', 406,
    'hllhash', 407,
    'attrinited', 408,
    'setcontspec', 409,
    'existspos', 410,
    'gethllsym', 411,
    'freshcoderef', 412,
    'markcodestatic', 413,
    'markcodestub', 414,
    'getstaticcode', 415,
    'getcodecuid', 416,
    'copy_f', 417,
    'append_f', 418,
    'rename_f', 419,
    'delete_f', 420,
    'chmod_f', 421,
    'exists_f', 422,
    'mkdir', 423,
    'rmdir', 424,
    'open_dir', 425,
    'read_dir', 426,
    'close_dir', 427,
    'open_fh', 428,
    'close_fh', 429,
    'read_fhs', 430,
    'slurp', 431,
    'spew', 432,
    'write_fhs', 433,
    'seek_fh', 434,
    'lock_fh', 435,
    'unlock_fh', 436,
    'sync_fh', 437,
    'trunc_fh', 438,
    'eof_fh', 439,
    'getstdin', 440,
    'getstdout', 441,
    'getstderr', 442,
    'connect_sk', 443,
    'close_sk', 444,
    'bind_sk', 445,
    'listen_sk', 446,
    'accept_sk', 447,
    'send_sks', 448,
    'recv_sks', 449,
    'setencoding', 450,
    'print', 451,
    'say', 452,
    'readall_fh', 453,
    'tell_fh', 454,
    'stat', 455,
    'readline_fh', 456,
    'readlineint_fh', 457,
    'chdir', 458,
    'rand_i', 459,
    'rand_n', 460,
    'time_i', 461,
    'clargs', 462,
    'newthread', 463,
    'jointhread', 464,
    'time_n', 465,
    'exit', 466,
    'loadbytecode', 467,
    'getenvhash', 468,
    'sha1', 469,
    'createsc', 470,
    'scsetobj', 471,
    'scsetcode', 472,
    'scgetobj', 473,
    'scgethandle', 474,
    'scgetobjidx', 475,
    'scsetdesc', 476,
    'scobjcount', 477,
    'setobjsc', 478,
    'getobjsc', 479,
    'serialize', 480,
    'deserialize', 481,
    'wval', 482,
    'wval_wide', 483,
    'scwbdisable', 484,
    'scwbenable', 485,
    'pushcompsc', 486,
    'popcompsc', 487,
    'shell', 488,
    'cwd', 489,
    'seed', 490,
    'rethrow', 491,
    'bloballoc', 492,
    'blobptr', 493,
    'ptrcast', 494,
    'cpointer', 495,
    'cscalar', 496,
    'cscalar_decont_i', 497);
    MAST::Ops.WHO<@names> := nqp::list('no_op',
    'goto',
    'if_i',
    'unless_i',
    'if_n',
    'unless_n',
    'if_s',
    'unless_s',
    'if_s0',
    'unless_s0',
    'if_o',
    'unless_o',
    'set',
    'extend_u8',
    'extend_u16',
    'extend_u32',
    'extend_i8',
    'extend_i16',
    'extend_i32',
    'trunc_u8',
    'trunc_u16',
    'trunc_u32',
    'trunc_i8',
    'trunc_i16',
    'trunc_i32',
    'extend_n32',
    'trunc_n32',
    'getlex',
    'bindlex',
    'getlex_ni',
    'getlex_nn',
    'getlex_ns',
    'getlex_no',
    'bindlex_ni',
    'bindlex_nn',
    'bindlex_ns',
    'bindlex_no',
    'getlex_ng',
    'bindlex_ng',
    'return_i',
    'return_n',
    'return_s',
    'return_o',
    'return',
    'const_i8',
    'const_i16',
    'const_i32',
    'const_i64',
    'const_n32',
    'const_n64',
    'const_s',
    'add_i',
    'sub_i',
    'mul_i',
    'div_i',
    'div_u',
    'mod_i',
    'mod_u',
    'neg_i',
    'abs_i',
    'inc_i',
    'inc_u',
    'dec_i',
    'dec_u',
    'getcode',
    'prepargs',
    'arg_i',
    'arg_n',
    'arg_s',
    'arg_o',
    'invoke_v',
    'invoke_i',
    'invoke_n',
    'invoke_s',
    'invoke_o',
    'add_n',
    'sub_n',
    'mul_n',
    'div_n',
    'neg_n',
    'abs_n',
    'eq_i',
    'ne_i',
    'lt_i',
    'le_i',
    'gt_i',
    'ge_i',
    'eq_n',
    'ne_n',
    'lt_n',
    'le_n',
    'gt_n',
    'ge_n',
    'argconst_i',
    'argconst_n',
    'argconst_s',
    'checkarity',
    'param_rp_i',
    'param_rp_n',
    'param_rp_s',
    'param_rp_o',
    'param_op_i',
    'param_op_n',
    'param_op_s',
    'param_op_o',
    'param_rn_i',
    'param_rn_n',
    'param_rn_s',
    'param_rn_o',
    'param_on_i',
    'param_on_n',
    'param_on_s',
    'param_on_o',
    'coerce_in',
    'coerce_ni',
    'band_i',
    'bor_i',
    'bxor_i',
    'bnot_i',
    'blshift_i',
    'brshift_i',
    'pow_i',
    'pow_n',
    'takeclosure',
    'jumplist',
    'caller',
    'getdynlex',
    'binddynlex',
    'coerce_is',
    'coerce_ns',
    'coerce_si',
    'coerce_sn',
    'smrt_numify',
    'smrt_strify',
    'param_sp',
    'param_sn',
    'ifnonnull',
    'cmp_i',
    'cmp_n',
    'not_i',
    'setlexvalue',
    'exception',
    'bindexmessage',
    'bindexpayload',
    'bindexcategory',
    'getexmessage',
    'getexpayload',
    'getexcategory',
    'throwdyn',
    'throwlex',
    'throwlexotic',
    'throwcatdyn',
    'throwcatlex',
    'throwcatlexotic',
    'die',
    'newlexotic',
    'lexoticresult',
    'mod_n',
    'usecapture',
    'savecapture',
    'captureposelems',
    'captureposarg',
    'captureposarg_i',
    'captureposarg_n',
    'captureposarg_s',
    'captureposprimspec',
    'invokewithcapture',
    'multicacheadd',
    'multicachefind',
    'lexprimspec',
    'ceil_n',
    'floor_n',
    'assign',
    'assignunchecked',
    'objprimspec',
    'backtracestrings',
    'masttofile',
    'masttocu',
    'iscompunit',
    'compunitmainline',
    'compunitcodes',
    'sleep',
    'concat_s',
    'repeat_s',
    'substr_s',
    'index_s',
    'graphs_s',
    'codes_s',
    'eq_s',
    'ne_s',
    'eqat_s',
    'haveat_s',
    'getcp_s',
    'indexcp_s',
    'uc',
    'lc',
    'tc',
    'split',
    'join',
    'getcpbyname',
    'indexat_scb',
    'unipropcode',
    'unipvalcode',
    'hasuniprop',
    'hasunipropc',
    'chars',
    'chr',
    'ordfirst',
    'ordat',
    'rindexfrom',
    'escape',
    'flip',
    'iscclass',
    'findcclass',
    'findnotcclass',
    'nfafromstatelist',
    'nfarunproto',
    'nfarunalt',
    'flattenropes',
    'gt_s',
    'ge_s',
    'lt_s',
    'le_s',
    'cmp_s',
    'radix',
    'eqatic_s',
    'sin_n',
    'asin_n',
    'cos_n',
    'acos_n',
    'tan_n',
    'atan_n',
    'atan2_n',
    'sec_n',
    'asec_n',
    'sinh_n',
    'cosh_n',
    'tanh_n',
    'sech_n',
    'sqrt_n',
    'gcd_i',
    'lcm_i',
    'add_I',
    'sub_I',
    'mul_I',
    'div_I',
    'mod_I',
    'neg_I',
    'abs_I',
    'cmp_I',
    'eq_I',
    'ne_I',
    'lt_I',
    'le_I',
    'gt_I',
    'ge_I',
    'bor_I',
    'bxor_I',
    'band_I',
    'bnot_I',
    'blshift_I',
    'brshift_I',
    'pow_I',
    'gcd_I',
    'lcm_I',
    'expmod_I',
    'isprime_I',
    'rand_I',
    'coerce_In',
    'coerce_Is',
    'coerce_nI',
    'coerce_sI',
    'isbig_I',
    'base_I',
    'radix_I',
    'div_In',
    'log_n',
    'exp_n',
    'knowhow',
    'findmeth',
    'findmeth_s',
    'can',
    'can_s',
    'create',
    'gethow',
    'getwhat',
    'atkey_i',
    'atkey_n',
    'atkey_s',
    'atkey_o',
    'bindkey_i',
    'bindkey_n',
    'bindkey_s',
    'bindkey_o',
    'existskey',
    'deletekey',
    'getwhere',
    'eqaddr',
    'reprname',
    'isconcrete',
    'atpos_i',
    'atpos_n',
    'atpos_s',
    'atpos_o',
    'bindpos_i',
    'bindpos_n',
    'bindpos_s',
    'bindpos_o',
    'push_i',
    'push_n',
    'push_s',
    'push_o',
    'pop_i',
    'pop_n',
    'pop_s',
    'pop_o',
    'shift_i',
    'shift_n',
    'shift_s',
    'shift_o',
    'unshift_i',
    'unshift_n',
    'unshift_s',
    'unshift_o',
    'splice',
    'setelemspos',
    'box_i',
    'box_n',
    'box_s',
    'unbox_i',
    'unbox_n',
    'unbox_s',
    'bindattr_i',
    'bindattr_n',
    'bindattr_s',
    'bindattr_o',
    'bindattrs_i',
    'bindattrs_n',
    'bindattrs_s',
    'bindattrs_o',
    'getattr_i',
    'getattr_n',
    'getattr_s',
    'getattr_o',
    'getattrs_i',
    'getattrs_n',
    'getattrs_s',
    'getattrs_o',
    'isnull',
    'knowhowattr',
    'iscoderef',
    'null',
    'clone',
    'isnull_s',
    'bootint',
    'bootnum',
    'bootstr',
    'bootarray',
    'boothash',
    'sethllconfig',
    'hllboxtype_i',
    'hllboxtype_n',
    'hllboxtype_s',
    'elems',
    'null_s',
    'newtype',
    'islist',
    'ishash',
    'iter',
    'iterkey_s',
    'iterval',
    'getcodename',
    'composetype',
    'setmethcache',
    'setmethcacheauth',
    'settypecache',
    'setinvokespec',
    'isinvokable',
    'iscont',
    'decont',
    'setboolspec',
    'istrue',
    'isfalse',
    'istrue_s',
    'isfalse_s',
    'getcodeobj',
    'setcodeobj',
    'setcodename',
    'forceouterctx',
    'getcomp',
    'bindcomp',
    'getcurhllsym',
    'bindcurhllsym',
    'getwho',
    'setwho',
    'rebless',
    'istype',
    'ctx',
    'ctxouter',
    'ctxcaller',
    'ctxlexpad',
    'curcode',
    'callercode',
    'bootintarray',
    'bootnumarray',
    'bootstrarray',
    'hlllist',
    'hllhash',
    'attrinited',
    'setcontspec',
    'existspos',
    'gethllsym',
    'freshcoderef',
    'markcodestatic',
    'markcodestub',
    'getstaticcode',
    'getcodecuid',
    'copy_f',
    'append_f',
    'rename_f',
    'delete_f',
    'chmod_f',
    'exists_f',
    'mkdir',
    'rmdir',
    'open_dir',
    'read_dir',
    'close_dir',
    'open_fh',
    'close_fh',
    'read_fhs',
    'slurp',
    'spew',
    'write_fhs',
    'seek_fh',
    'lock_fh',
    'unlock_fh',
    'sync_fh',
    'trunc_fh',
    'eof_fh',
    'getstdin',
    'getstdout',
    'getstderr',
    'connect_sk',
    'close_sk',
    'bind_sk',
    'listen_sk',
    'accept_sk',
    'send_sks',
    'recv_sks',
    'setencoding',
    'print',
    'say',
    'readall_fh',
    'tell_fh',
    'stat',
    'readline_fh',
    'readlineint_fh',
    'chdir',
    'rand_i',
    'rand_n',
    'time_i',
    'clargs',
    'newthread',
    'jointhread',
    'time_n',
    'exit',
    'loadbytecode',
    'getenvhash',
    'sha1',
    'createsc',
    'scsetobj',
    'scsetcode',
    'scgetobj',
    'scgethandle',
    'scgetobjidx',
    'scsetdesc',
    'scobjcount',
    'setobjsc',
    'getobjsc',
    'serialize',
    'deserialize',
    'wval',
    'wval_wide',
    'scwbdisable',
    'scwbenable',
    'pushcompsc',
    'popcompsc',
    'shell',
    'cwd',
    'seed',
    'rethrow',
    'bloballoc',
    'blobptr',
    'ptrcast',
    'cpointer',
    'cscalar',
    'cscalar_decont_i');
}
