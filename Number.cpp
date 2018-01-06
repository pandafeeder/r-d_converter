//
//  Number.cpp
//  Roman2Decimal
//
//  Created by qusr on 01/01/2018.
//  Copyright © 2018 qusr. All rights reserved.
//

#include "Number.hpp"


std::smatch get_patterns(const std::string &str) {
    std::smatch sm;
    try {
        if (std::regex_match(str, sm, re) && sm.size() > 1)
            return sm;
        else
            throw "Bad roman number";
    } catch(std::regex_error &e) {
        throw e;
    }
}

unsigned r2d(const std::smatch& sm)
{
    unsigned decimal = 0;
    for (unsigned i = 0; i < sm.size(); ++i) {
        if (i == 0)
            // ignore whole matched string
            continue;
        std::string str = sm.str(i);
        if (roman2NumMap[str]) {
            decimal += roman2NumMap[str];
        }
        else {
            for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
                decimal += roman2NumMap[std::string(1, *it)];
            }
        }
    }
    return decimal;
}
std::string d2r(const unsigned &dec)
{
    std::string roman = "";
    int temp(dec);
    while ( temp != 0) {
    L1: for (const auto &d : nums) {
            if (temp - d >= 0) {
                temp -= d;
                roman += num2RomanMap[d];
                goto L1;
            }
        }
    }
    return roman;
}
