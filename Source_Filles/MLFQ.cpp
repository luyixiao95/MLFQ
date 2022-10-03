//
// Created by Luyi Xiao on 9/28/22.
//

#include "MLFQ.h"
#include <iostream>

MLFQ::MLFQ() {
    Queue q0 = Queue(0);
    Queue q1 = Queue(1);
    Queue q2 = Queue(2);
    mlfq.push_back(q0);
    mlfq.push_back(q1);
    mlfq.push_back(q2);
}

int MLFQ::getActiveQueueIdx() {
    int idx = 0;
    for(Queue q : mlfq) {
        if (q.isEmpty()) {
            idx += 1;
            continue;
        }
        else {
            return idx;
        }
    }
    return -1;
}

int MLFQ::execute(int time) {
    int activeQueueIdx = getActiveQueueIdx();
    if(activeQueueIdx == -1) {
        return -1;
    }
    Queue activeQueue = mlfq[activeQueueIdx];
    activeQueue.executeQueue(time);
    mlfq[activeQueueIdx] = activeQueue;
    reduceCountdownTimeForAll(time);
    rearrangeMLFQ();

    return 1;
}

int MLFQ::addJob(Job job) {

    mlfq[0].addJob(job);
    return 1;
}


int MLFQ::reduceCountdownTimeForAll(int time) {
    for(Queue& q : mlfq) {
        q.groupReduceCountdownTime(time);
    }
    return 1;
}

int MLFQ::rearrangeMLFQ() {
    for(int idx =0 ; idx < 3 ; ++idx) {
        Queue &currQ = mlfq[idx];
        Queue &nextQ = mlfq[(idx + 1) % 3];

        for (int jdx = 0; jdx < currQ.getLength(); ++jdx ) {

            Job currJob = currQ.getJobFromIdx(jdx);
            if (currJob.getCountDowntime() <= 0) {
                currQ.removeJobWithIdx(jdx);
                nextQ.addJob(Job(currJob.getId(), currJob.getTime(), timestamp));
            }

        }

    }
    return 1;
}

std::string MLFQ::toString() {
    std::string  str = "";
    str += "The MLFQ contains: \n";

    for(Queue q : mlfq) {
        str += q.toString();
    }
    str += "\n";
    return str;
}

