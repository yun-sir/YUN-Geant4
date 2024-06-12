#ifndef yunSD_h
#define yunSD_h

#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "yunHits.hh"

class yunSD : public G4VSensitiveDetector
{
    public:
        yunSD(G4String name);
        ~yunSD();
        virtual void Initialize(G4HCofThisEvent* HCE);
        virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist) ;

    private:
        static const G4String theYUNCollectionName;
        yunHitsCollection* yunCollection;
};

#endif