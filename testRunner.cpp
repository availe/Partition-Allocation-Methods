#include "testRunner.h"
#include "firstFit.h"
#include "nextFit.h"
#include "worstFit.h"
#include "bestFit.h"

void executeTests(SuperStruct& sp) {
    inputValuesFixed(sp);
    executeFirstFit(sp);
    inputValuesFixed(sp);
    executeNextFit(sp);
    inputValuesFixed(sp);
    executeWorstFit(sp);
}