#ifndef Genaratoraction_h
#define Genaratoraction_h

#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

class G4Event;

class Genaratoraction : public G4VUserPrimaryGeneratorAction{
public:
    Genaratoraction();
    ~Genaratoraction();
    virtual void GeneratePrimaries(G4Event*);
private:
    G4ParticleGun* particleGun;
};

#endif