#pragma once

#include <vector>
#include "celestial_mechanics/Interpolation.hpp"

class GOST4401_81 {

    public:

        std::vector<double> heights_ = {
            80000,   80500,   81000,   81500,   82000,   82500,   83000,   83500,   84000,   84500,   85000,   85500,
            86000,   86500,   87000,   87500,   88000,   88500,   89000,   89500,   90000,   90500,   91000,   91500,
            92000,   92500,   93000,   93500,   94000,   94500,   95000,   96000,   97000,   98000,   99000,   100000,
            101000,  102000,  103000,  104000,  105000,  106000,  107000,  108000,  109000,  110000,  111000,  112000,
            113000,  114000,  115000,  116000,  117000,  118000,  119000,  120000,  120000,  121000,  122000,  123000,
            124000,  125000,  126000,  127000,  128000,  129000,  130000,  131000,  132000,  133000,  134000,  135000,
            136000,  137000,  138000,  139000,  140000,  141000,  142000,  143000,  144000,  145000,  146000,  147000,
            148000,  149000,  150000,  151000,  152000,  153000,  154000,  155000,  156000,  157000,  158000,  159000,
            160000,  161000,  162000,  163000,  164000,  165000,  166000,  167000,  168000,  169000,  170000,  171000,
            172000,  173000,  174000,  175000,  176000,  177000,  178000,  179000,  180000,  181000,  182000,  183000,
            184000,  185000,  186000,  187000,  188000,  189000,  190000,  191000,  192000,  193000,  194000,  195000,
            196000,  197000,  198000,  199000,  200000,  201000,  202000,  203000,  204000,  205000,  206000,  207000,
            208000,  209000,  210000,  211000,  212000,  213000,  214000,  215000,  216000,  217000,  218000,  219000,
            220000,  221000,  222000,  223000,  224000,  225000,  226000,  227000,  228000,  229000,  230000,  231000,
            232000,  233000,  234000,  235000,  236000,  237000,  238000,  239000,  240000,  241000,  242000,  243000,
            244000,  245000,  246000,  247000,  248000,  249000,  250000,  251000,  252000,  253000,  254000,  255000,
            256000,  257000,  258000,  259000,  260000,  261000,  262000,  263000,  264000,  266000,  266000,  267000,
            268000,  269000,  270000,  271000,  272000,  273000,  274000,  275000,  276000,  277000,  278000,  279000,
            280000,  281000,  282000,  283000,  284000,  285000,  286000,  287000,  288000,  289000,  290000,  291000,
            292000,  293000,  294000,  295000,  296000,  297000,  298000,  299000,  300000,  302000,  304000,  306000,
            308000,  310000,  312000,  314000,  316000,  318000,  320000,  322000,  324000,  326000,  328000,  330000,
            332000,  334000,  336000,  338000,  340000,  342000,  344000,  346000,  348000,  350000,  352000,  354000,
            356000,  358000,  360000,  362000,  364000,  366000,  368000,  370000,  372000,  374000,  376000,  378000,
            380000,  382000,  384000,  386000,  388000,  390000,  392000,  394000,  396000,  398000,  400000,  402000,
            404000,  406000,  408000,  410000,  412000,  414000,  416000,  418000,  420000,  422000,  424000,  426000,
            428000,  430000,  432000,  434000,  436000,  438000,  440000,  442000,  444000,  446000,  448000,  450000,
            452000,  454000,  456000,  458000,  460000,  462000,  464000,  466000,  468000,  470000,  472000,  474000,
            476000,  478000,  480000,  482000,  484000,  486000,  488000,  490000,  492000,  494000,  496000,  498000,
            500000,  505000,  510000,  515000,  520000,  525000,  530000,  535000,  540000,  545000,  550000,  555000,
            560000,  565000,  570000,  575000,  580000,  585000,  590000,  595000,  600000,  605000,  610000,  615000,
            620000,  625000,  630000,  635000,  640000,  645000,  650000,  655000,  660000,  665000,  670000,  675000,
            680000,  685000,  690000,  695000,  700000,  705000,  710000,  715000,  720000,  725000,  730000,  735000,
            740000,  745000,  750000,  755000,  760000,  765000,  770000,  775000,  780000,  785000,  790000,  795000,
            800000,  805000,  810000,  815000,  820000,  825000,  830000,  835000,  840000,  845000,  850000,  855000,
            860000,  865000,  870000,  875000,  880000,  885000,  890000,  895000,  900000,  905000,  910000,  915000,
            920000,  925000,  930000,  935000,  940000,  945000,  950000,  955000,  960000,  965000,  970000,  975000,
            980000,  985000,  990000,  995000,  1000000, 1005000, 1010000, 1015000, 1020000, 1025000, 1030000, 1035000,
            1040000, 1045000, 1050000, 1055000, 1060000, 1065000, 1070000, 1075000, 1080000, 1085000, 1090000, 1095000,
            1100000, 1105000, 1110000, 1115000, 1120000, 1125000, 1130000, 1135000, 1140000, 1145000, 1150000, 1155000,
            1160000, 1165000, 1170000, 1175000, 1180000, 1185000, 1190000, 1195000, 1200000};

        std::vector<double> densities_ = {
            1.8458e-05,  1.70542e-05, 1.57493e-05, 1.45408e-05, 1.34175e-05, 1.23781e-05, 1.14145e-05, 1.05216e-05,
            9.69458e-06, 8.92878e-06, 8.22001e-06, 7.56427e-06, 6.95782e-06, 6.37469e-06, 5.83212e-06, 5.33476e-06,
            4.88072e-06, 4.4645e-06,  4.0845e-06,  3.73686e-06, 3.41817e-06, 3.12745e-06, 2.86108e-06, 2.61757e-06,
            2.39477e-06, 2.19135e-06, 2.00484e-06, 1.8342e-06,  1.6784e-06,  1.53554e-06, 1.4051e-06,  1.16617e-06,
            9.6445e-07,  7.99924e-07, 6.65312e-07, 5.54951e-07, 4.64111e-07, 3.89128e-07, 3.27067e-07, 2.75614e-07,
            2.26166e-07, 1.86514e-07, 1.55121e-07, 1.3006e-07,  1.0986e-07,  9.34035e-08, 7.99116e-08, 6.87683e-08,
            5.94575e-08, 5.17245e-08, 4.51814e-08, 3.96418e-08, 3.49222e-08, 3.08814e-08, 2.74061e-08, 2.44041e-08,
            2.44041e-08, 2.20814e-08, 2.01267e-08, 1.83438e-08, 1.67199e-08, 1.5243e-08,  1.39015e-08, 1.26846e-08,
            1.15819e-08, 1.05836e-08, 9.68064e-09, 8.86428e-09, 8.12642e-09, 7.45948e-09, 6.85639e-09, 6.3106e-09,
            5.81605e-09, 5.36717e-09, 4.95889e-09, 4.58659e-09, 4.24614e-09, 3.93386e-09, 3.64654e-09, 3.38138e-09,
            3.13605e-09, 2.90864e-09, 2.69768e-09, 2.5021e-09,  2.32127e-09, 2.15494e-09, 2.00329e-09, 1.89681e-09,
            1.79797e-09, 1.70494e-09, 1.61741e-09, 1.5351e-09,  1.4577e-09,  1.38496e-09, 1.3166e-09,  1.25237e-09,
            1.19204e-09, 1.13535e-09, 1.0821e-09,  1.03206e-09, 9.85037e-10, 9.40825e-10, 8.9924e-10,  8.60103e-10,
            8.23245e-10, 7.88506e-10, 7.55732e-10, 7.24781e-10, 6.95515e-10, 6.67809e-10, 6.41542e-10, 6.16603e-10,
            5.92889e-10, 5.70303e-10, 5.48759e-10, 5.28175e-10, 5.08478e-10, 4.89604e-10, 4.71493e-10, 4.54096e-10,
            4.37368e-10, 4.21273e-10, 4.05781e-10, 3.9087e-10,  3.76524e-10, 3.62734e-10, 3.49499e-10, 3.36823e-10,
            3.24717e-10, 3.13199e-10, 3.02294e-10, 2.92032e-10, 2.82451e-10, 2.73595e-10, 2.65513e-10, 2.58262e-10,
            2.51904e-10, 2.42171e-10, 2.34594e-10, 2.27283e-10, 2.20229e-10, 2.13424e-10, 2.06859e-10, 2.00526e-10,
            1.94416e-10, 1.88523e-10, 1.82838e-10, 1.77353e-10, 1.72062e-10, 1.66958e-10, 1.62033e-10, 1.5728e-10,
            1.52694e-10, 1.48268e-10, 1.43996e-10, 1.39871e-10, 1.35889e-10, 1.32043e-10, 1.28328e-10, 1.24738e-10,
            1.21269e-10, 1.17916e-10, 1.14674e-10, 1.11538e-10, 1.08504e-10, 1.05567e-10, 1.02724e-10, 9.99709e-11,
            9.73033e-11, 9.47179e-11, 9.22112e-11, 8.97799e-11, 8.74209e-11, 8.5131e-11,  8.29076e-11, 8.07479e-11,
            7.86493e-11, 7.66094e-11, 7.4626e-11,  7.2697e-11,  7.08203e-11, 6.89942e-11, 6.7217e-11,  6.54871e-11,
            6.38031e-11, 6.21637e-11, 6.05679e-11, 5.91295e-11, 5.7671e-11,  5.62529e-11, 5.4874e-11,  5.35333e-11,
            5.22299e-11, 5.09625e-11, 4.97302e-11, 4.85321e-11, 4.73671e-11, 4.62343e-11, 4.51328e-11, 4.40617e-11,
            4.30201e-11, 4.20071e-11, 4.10218e-11, 4.00635e-11, 3.91313e-11, 3.82245e-11, 3.73422e-11, 3.64837e-11,
            3.56482e-11, 3.48351e-11, 3.40437e-11, 3.32732e-11, 3.2523e-11,  3.17925e-11, 3.1081e-11,  3.03879e-11,
            2.97125e-11, 2.90544e-11, 2.8413e-11,  2.77876e-11, 2.71778e-11, 2.65831e-11, 2.60029e-11, 2.54368e-11,
            2.48843e-11, 2.43449e-11, 2.38182e-11, 2.33038e-11, 2.28013e-11, 2.23102e-11, 2.18302e-11, 2.1361e-11,
            2.09021e-11, 2.04532e-11, 2.00141e-11, 1.95843e-11, 1.91637e-11, 1.83486e-11, 1.75668e-11, 1.68164e-11,
            1.60957e-11, 1.54032e-11, 1.47378e-11, 1.40984e-11, 1.34842e-11, 1.28945e-11, 1.23289e-11, 1.17871e-11,
            1.12692e-11, 1.07752e-11, 1.03055e-11, 9.86051e-12, 9.44101e-12, 9.04785e-12, 8.68207e-12, 8.3449e-12,
            8.03773e-12, 7.76214e-12, 7.51986e-12, 7.31282e-12, 7.14309e-12, 7.01292e-12, 6.75194e-12, 6.50003e-12,
            6.25809e-12, 6.02573e-12, 5.80258e-12, 5.58829e-12, 5.38249e-12, 5.18486e-12, 4.99506e-12, 4.81277e-12,
            4.63769e-12, 4.46952e-12, 4.30797e-12, 4.15277e-12, 4.00363e-12, 3.86031e-12, 3.72256e-12, 3.59013e-12,
            3.4628e-12,  3.34034e-12, 3.22253e-12, 3.10918e-12, 3.0001e-12,  2.89508e-12, 2.79396e-12, 2.69942e-12,
            2.60748e-12, 2.51874e-12, 2.43308e-12, 2.35038e-12, 2.27052e-12, 2.1934e-12,  2.11891e-12, 2.04695e-12,
            1.97745e-12, 1.91031e-12, 1.84547e-12, 1.78285e-12, 1.72241e-12, 1.66408e-12, 1.60781e-12, 1.55357e-12,
            1.50131e-12, 1.45103e-12, 1.40268e-12, 1.35626e-12, 1.31176e-12, 1.26918e-12, 1.22852e-12, 1.1898e-12,
            1.14872e-12, 1.11124e-12, 1.07496e-12, 1.03985e-12, 1.00587e-12, 9.73002e-13, 9.41207e-13, 9.10457e-13,
            8.80722e-13, 8.51973e-13, 8.24181e-13, 7.97319e-13, 7.71357e-13, 7.4627e-13,  7.2203e-13,  6.98612e-13,
            6.75989e-13, 6.54137e-13, 6.33031e-13, 6.12647e-13, 5.9296e-13,  5.73949e-13, 5.5559e-13,  5.37862e-13,
            5.20743e-13, 4.80474e-13, 4.43567e-13, 4.09731e-13, 3.78691e-13, 3.50196e-13, 3.24011e-13, 2.99926e-13,
            2.77744e-13, 2.57292e-13, 2.38414e-13, 2.20971e-13, 2.04842e-13, 1.89925e-13, 1.76131e-13, 1.63389e-13,
            1.51643e-13, 1.4085e-13,  1.30981e-13, 1.2202e-13,  1.1396e-13,  1.06205e-13, 9.90517e-14, 9.23975e-14,
            8.62103e-14, 8.04593e-14, 7.51152e-14, 7.01498e-14, 6.55367e-14, 6.12504e-14, 5.7267e-14,  5.3549e-14,
            5.01275e-14, 4.69735e-14, 4.40643e-14, 4.13788e-14, 3.88976e-14, 3.66028e-14, 3.44783e-14, 3.25089e-14,
            3.06811e-14, 2.89823e-14, 2.74014e-14, 2.59281e-14, 2.45532e-14, 2.32685e-14, 2.20664e-14, 2.09405e-14,
            1.98849e-14, 1.88944e-14, 1.79647e-14, 1.70917e-14, 1.62723e-14, 1.55035e-14, 1.47832e-14, 1.41093e-14,
            1.34806e-14, 1.28959e-14, 1.23545e-14, 1.18561e-14, 1.14006e-14, 1.09248e-14, 1.04935e-14, 1.00859e-14,
            9.70075e-15, 9.33686e-15, 8.99305e-15, 8.66819e-15, 8.36124e-15, 8.07122e-15, 7.7972e-15,  7.53828e-15,
            7.29363e-15, 7.06247e-15, 6.84404e-15, 6.63764e-15, 6.44261e-15, 6.25832e-15, 6.08416e-15, 5.91959e-15,
            5.76406e-15, 5.60198e-15, 5.44733e-15, 5.29993e-15, 5.15935e-15, 5.02514e-15, 4.89694e-15, 4.77435e-15,
            4.65704e-15, 4.54468e-15, 4.43696e-15, 4.33361e-15, 4.23434e-15, 4.13892e-15, 4.04712e-15, 3.95872e-15,
            3.87353e-15, 3.79136e-15, 3.71205e-15, 3.63544e-15, 3.5614e-15,  3.50435e-15, 3.44759e-15, 3.39217e-15,
            3.33801e-15, 3.28502e-15, 3.23313e-15, 3.18226e-15, 3.13235e-15, 3.08332e-15, 3.03513e-15, 2.98845e-15,
            2.9423e-15,  2.89697e-15, 2.85243e-15, 2.8087e-15,  2.76575e-15, 2.72358e-15, 2.68219e-15, 2.64156e-15,
            2.6017e-15,  2.56259e-15, 2.52423e-15, 4.48661e-15, 2.44972e-15, 2.41357e-15, 2.37814e-15, 2.34342e-15,
            2.30942e-15, 2.27613e-15, 2.24353e-15, 3.21163e-15, 2.18042e-15, 2.1499e-15,  2.12006e-15, 2.09089e-15,
            2.0624e-15,  2.03457e-15, 2.0074e-15,  1.98089e-15, 1.95503e-15};

        Interpolant<double, double> interpolant_{heights_, densities_};

        double density(double height) const;
};