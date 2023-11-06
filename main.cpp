#include <iostream>
#include "startInfo.h"
#include "testRunner.h"

int main() {
    SuperStruct sp;
    int input;
    std::cout << "Press 1 to run static test or 2 to run dynamic test: ";
    std::cin >> input;
    switch (input) {
        case 1:
            executeStaticTest(sp);
            break;
        case 2:
            executeDynamicTest(sp);
            break;
        default:
            std::cout << "Invalid selection";
            break;
    }

    return 0;
}
