#include "firstFit.h"

void executeFirstFit(SuperStruct &sp) {
    autoLoop(sp);
    sp.results();
}

void autoLoop(SuperStruct &sp) {
    for (auto &[jobId, job]: sp.jobList) {
        if (job.status) continue;
        for (auto &[partId, part]: sp.partitionList) {
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