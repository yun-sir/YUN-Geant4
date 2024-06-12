#include "ActionInitialization.hh"
#include "GeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization(){}

ActionInitialization::~ActionInitialization(){}

 void ActionInitialization::Build() const
 {
    SetUserAction(new Genaratoraction());
    RunAction* runAction = new RunAction();
    SetUserAction(runAction);
    EventAction* event = new EventAction(runAction);
    SetUserAction(event);
    // SetUserAction(new SteppingAction());

}

void ActionInitialization::BuildForMaster() const {
}