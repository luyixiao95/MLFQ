//
// Created by Luyi Xiao on 9/28/22.
//

#include "Job.h"

Job::Job(int i, int t, int c) {
    id = i;
    time = t;
    countdownTime = c;
}
bool Job::reduceTime(int t) {
    time -= t;
    if (time == 0) {
        return false;
    }
    else {
        return true;
    }
}

bool Job::reduceCountdownTime(int t) {
    countdownTime -= t;
    if (countdownTime == 0) {
        return false;
    }
    else
    {
        return true;
    }
}

std::string Job::toString() {
    std::string str = "";
    str = str + "id: " + std::to_string(id) + " rest time:" + std::to_string(time) + " countdown time: " + std::to_string(countdownTime);
    str += "\n";
    return str;
}




