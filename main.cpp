#include <iostream>
#include "startInfo.h"
#include "firstFit.h"
#include "nextFit.h"
#include "worstFit.h"
#include "bestFit.h"

int main() {
    SuperStruct sp;
    //inputValues(sp);
    inputValuesFixed(sp);
    executeFirstFit(sp);
    inputValuesFixed(sp);
    executeNextFit(sp);

    return 0;
}
