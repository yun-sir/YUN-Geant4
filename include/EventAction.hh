#ifndef EventAction_h
#define EventAction_h 

#include "G4UserEventAction.hh"

class RunAction;

class EventAction : public G4UserEventAction
{
    private:
        /* data */
        RunAction* bRun = nullptr;
    public:
        EventAction(RunAction* aRun);
        ~EventAction();

    public:
        void BeginOfEventAction(const G4Event* aEvent);
        void EndOfEventAction(const G4Event* bEvent);
};

#endif