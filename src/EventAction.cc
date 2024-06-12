#include "G4Event.hh"
#include "EventAction.hh"
#include "G4SDManager.hh"
#include "yunHits.hh"
#include "G4HCofThisEvent.hh"
#include "RunAction.hh"

EventAction::EventAction(RunAction* aRun)
: bRun(aRun)
{

}

EventAction::~EventAction()
{

}

void EventAction::BeginOfEventAction(const G4Event* aEvent)
{
    G4cout<<  "Begin of Event ---> "<<  aEvent->GetEventID() <<G4endl;
    bRun->BeginOfEvent();

}

void EventAction::EndOfEventAction(const G4Event* bEvent)
{
    G4cout<<  " EventAction----  End of Event !!! " <<G4endl;
    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    G4int CollID_pmt = SDman->GetCollectionID("yunCollection");
    G4HCofThisEvent* HCE = bEvent->GetHCofThisEvent();
    yunHitsCollection* col_Gd = (yunHitsCollection*)(HCE->GetHC(CollID_pmt));

    double  totPE = 0.0;
    if(col_Gd)
    {
        G4int n_hit = col_Gd->entries();
        for(int i=0; i<n_hit; i++)
        {
            totPE += (*col_Gd)[i]->GetDepositedEnergy();
        }
        bRun->Get_Gd_Edep(totPE);
        bRun->EndOfEvent();
    }
    else {
        G4cout<<"EventAction have some Error in yunHitsCollection!!!"
                            "yunHistCollection isn't include!! "<<G4endl;
    }
}