#include "Action.h"
#include <chrono>

Action::Action(std::string name) : mName(name), mPreWait(0), mPostWait(0) {}

void Action::fire()
{
    if (!mRunning) {
        if (th.joinable()) th.join();
        th = std::thread(&Action::fireThread, (void*) this);
    }
}

void Action::fireThread(void* ptr)
{
    Action* a = (Action*) ptr;
    a->mRunning = true;
    if (a->PreWait() > 0.0) {
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(a->PreWait() * 1000)));
    }
    a->doFire();
    if (a->PostWait() > 0.0) {
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(a->PostWait() * 1000)));
    }
    a->mRunning = false;
}
