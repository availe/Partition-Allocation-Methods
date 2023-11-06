#include "firstFit.h"

void executeFirstFit(SuperStruct &sp) {
    autoLoop(sp);
    std::cout << "---\nResults for first fit:";
    sp.results();
}

void static autoLoop(SuperStruct &sp) {
    for (auto &[jobId, job]: sp.jobMap) {
        if (job.status) continue;
        for (auto &[partId, part]: sp.partitionMap) {
            if (part.status || job.size > part.size) continue;
             part.assignedJob = jobId;
             part.status = true;
             job.assignedPart = partId;
             job.status = true;
             part.updateMemoryWaste(job.size);
             break;
        }
    }
}