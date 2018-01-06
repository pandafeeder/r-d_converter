//
//  main.cpp
//  Roman2Decimal
//
//  Created by qusr on 01/01/2018.
//  Copyright © 2018 qusr. All rights reserved.
//

#include <iostream>
#include <string>
#include "Number.hpp"


int main(int argc, const char * argv[]) {
    Roman r("MMCMLIII");
    Decimal d(2953);
    std::cout << r.get_decimal() << '\n';
    std::cout << r.get_roman() << '\n';
    std::cout << d.get_roman() << std::endl;
    return 0;
}
