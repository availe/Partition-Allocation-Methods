#include "nextFit.h"
#include "firstFit.h"

void executeNextFit(SuperStruct &sp) {
    autoLoop(sp);
    std::cout << "---\nResults for next fit:";
    sp.results();
}

void static autoLoop(SuperStruct &sp) {
    int currPartition = -1;
    auto it = sp.partitionList.find(currPartition);
    auto startIt = it;
    for (auto &[jobId, job]: sp.jobList) {
        if (job.status) continue;
        startIt = it;
        do {
            currPartition = (currPartition + 1) % int(sp.partitionList.size());
            it = sp.partitionList.find(currPartition);
            auto &[partId, part] = *it;
            if (part.status || job.size > part.size) continue;
            part.assignedJob = jobId;
            part.status = true;
            job.assignedPart = partId;
            job.status = true;
            part.updateMemoryWaste(job.size);
            break;
        } while (it != startIt);
    }
}