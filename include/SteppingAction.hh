
#ifndef SteppingAction_h
#define SteppingAction_h

#include "G4UserSteppingAction.hh"

class EventAction;
class G4LogicalVolume;

class SteppingAction : public G4UserSteppingAction
{
    public:
        SteppingAction();
        ~SteppingAction();

        void UserSteppingAction(const G4Step* ) override;

        void BeginOfSteppingAction(const G4Step* );
        void EndOfSteppingAction(const G4Step* );

    private:
        EventAction* fEventAction = nullptr;
        G4LogicalVolume* fScoringVolume = nullptr;
};

#endif