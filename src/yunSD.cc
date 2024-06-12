#include "yunSD.hh"
#include "G4THitsCollection.hh"

yunSD::yunSD(G4String name) : G4VSensitiveDetector(name)
{
    collectionName.insert("yunCollection");
}

yunSD::~yunSD(){}

void yunSD::Initialize(G4HCofThisEvent* HCE)
{
    static int HCID  = -1;
    //  Hits need
    yunCollection = new yunHitsCollection(SensitiveDetectorName, collectionName[0]);
    if(HCID < 0)
    {
        HCID = GetCollectionID(0);
    }
    HCE->AddHitsCollection(HCID, yunCollection);
}

G4bool yunSD::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
    G4double edep = aStep->GetTotalEnergyDeposit();
    if(edep==0.) return false;
    
    yunHits* hit_edep = new yunHits();
    hit_edep->SetDepositedEnergy(edep);
    yunCollection->insert(hit_edep);
    return true;
}