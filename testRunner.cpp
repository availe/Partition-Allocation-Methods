#include "testRunner.h"
#include "firstFit.h"
#include "nextFit.h"
#include "worstFit.h"
#include "bestFit.h"

void executeStaticTest(SuperStruct& sp) {
    inputValuesFixed(sp);
    executeFirstFit(sp);
    inputValuesFixed(sp);
    executeNextFit(sp);
    inputValuesFixed(sp);
    executeWorstFit(sp);
    inputValuesFixed(sp);
    executeBestFit(sp);
}

void executeDynamicTest(SuperStruct& sp) {
    inputValues(sp);
    SuperStruct storeSp = sp;

    executeFirstFit(sp);
    sp = storeSp;
    executeNextFit(sp);
    sp = storeSp;
    executeWorstFit(sp);
    sp = storeSp;
    executeBestFit(sp);
}