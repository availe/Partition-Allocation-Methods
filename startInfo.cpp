#include "startInfo.h"

/*void inputValues(superStruct sp) {
    int numOfPartitions, sizeOfPartitions, numofProcesses;
    std::cout << "Insert numOfMemoryPartitions: ";
    std::cin >> numOfPartitions;

    for (int i = 0; i < numOfPartitions; i++) {

    }


    std::cout << "\nInsert sizeOfMemoryPartitions: ";
    std::cin >> sizeOfPartitions;
    std::cout << "\nInsert numofProcesses";
    std::cin >> numofProcesses;

    int processId;
    for (int i = 0; i < numofProcesses; i++) {
        processId = i;
        std::cout << "Which partition does job belong to?";
    }
}*/

void inputValuesFixed(SuperStruct &sp) {
    Partition p0, p1, p2, p3;
    sp.partitionList[0] = p0;
    sp.partitionList[1] = p1;
    sp.partitionList[2] = p2;
    sp.partitionList[3] = p3;

    Job j0, j1, j2, j3;
    sp.jobList[0] = j0;
    sp.jobList[1] = j1;
    sp.jobList[2] = j2;
    sp.jobList[3] = j3;
}
