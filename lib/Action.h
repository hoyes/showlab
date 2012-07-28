#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <memory>
#include <thread>

class Action;
typedef std::shared_ptr<Action> ActionRef;
typedef float duration_t;

class Action
{
public:
    enum LengthType {
        LENGTH_TYPE_FIRE,
        LENGTH_TYPE_VARIABLE,
    };

private:
    std::string mName;
    LengthType mLengthType;
    duration_t mPreWait;
    duration_t mPostWait;
    ActionRef mRelAction;
    
    std::thread th;
    bool mRunning;

public:
    Action(std::string name = "");
    
    std::string Name() { return mName; }
    void Name(std::string v) { mName = v; }
    
    duration_t PreWait() { return mPreWait; }
    void PreWait(duration_t v) { mPreWait = v; }
    
    duration_t PostWait() { return mPostWait; }
    void PostWait(duration_t v) { mPostWait = v; }
    
    ActionRef RelAction() { return mRelAction; }
    void RelAction(ActionRef v) { mRelAction = v; }
    
    void fire();
    static void fireThread(void* ptr);
    virtual void doFire() = 0;
};

#endif
