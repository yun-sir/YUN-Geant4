#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4LogicalVolume.hh"
#include "DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4EventManager.hh"

SteppingAction::SteppingAction()
{

}

SteppingAction::~SteppingAction()
{

}

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
    if(!fScoringVolume)
    {
        const DetectorConstruction* det = static_cast<const DetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
        fScoringVolume = det->GetScoringVolume();
    }

    G4LogicalVolume* volume = aStep->GetPreStepPoint()->GetTouchableHandle()
                                                                            ->GetVolume()->GetLogicalVolume();
    if (volume == fScoringVolume)
    {
        G4int event_id = (G4EventManager::GetEventManager())->GetConstCurrentEvent()->GetEventID();
        G4int track_id = aStep->GetTrack()->GetTrackID();
        G4int pdeg = aStep->GetTrack()->GetDefinition()->GetPDGEncoding();
        G4String preName = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();
        G4double preE = aStep->GetPreStepPoint()->GetKineticEnergy();
        G4double postE = aStep->GetPostStepPoint()->GetKineticEnergy();
        G4String processN = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
        G4double edepStep = aStep->GetTotalEnergyDeposit();
        G4String particleName = aStep->GetTrack()->GetDefinition()->GetParticleName();
        G4double X = aStep->GetTrack()->GetPosition().x();
        G4double Y = aStep->GetTrack()->GetPosition().y();
        G4double Z = aStep->GetTrack()->GetPosition().z();

        G4cout<<std::setw(8)<<std::setfill(' ') <<std::left <<event_id
          <<std::setw(8)<<std::setfill(' ') <<std::left <<track_id
        //   <<std::setw(8)<<std::setfill(' ') <<std::left <<pdeg
          <<std::setw(15)<<std::setfill(' ') <<std::left <<particleName
          <<std::setw(10)<<std::setfill(' ') <<std::left <<X
          <<std::setw(10)<<std::setfill(' ') <<std::left <<Y
          <<std::setw(10)<<std::setfill(' ') <<std::left <<Z
        //   <<std::setw(10)<<std::setfill(' ') <<std::left <<preName
          <<std::setw(15)<<std::setfill(' ') <<std::left <<preE
          <<std::setw(15)<<std::setfill(' ') <<std::left <<postE
          <<std::setw(15)<<std::setfill(' ') <<std::left <<edepStep
          <<G4endl;
    }
    
}

void SteppingAction::BeginOfSteppingAction(const G4Step* bStep)
{
    G4cout << "TrackID --> " << bStep->GetTrack()->GetTrackID() << G4endl;
}

void SteppingAction::EndOfSteppingAction(const G4Step* cStep)
{
    G4cout<<"End of Step!!!!!"<<G4endl;
}