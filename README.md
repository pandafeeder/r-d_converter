# converter for Roman Number and Decimal Number in C++

```
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
```
