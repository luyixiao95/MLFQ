//
// Created by Luyi Xiao on 9/28/22.
//

#ifndef CS5600_MLFQ_H
#define CS5600_MLFQ_H


#include "Queue.h"

class MLFQ {
private:
    vector<Queue> mlfq;
    int timestamp = 5;
    int boostTime = 5;
public:
    MLFQ();
    int addJob(Job job) ;
    Queue getQueueWithIndex(int idx) {return mlfq[idx];}
    int getActiveQueueIdx();
    int execute(int time);
    int reduceCountdownTimeForAll(int time);
    int rearrangeMLFQ();
    std::string toString();

};


#endif //CS5600_MLFQ_H
