#include "GeneratorAction.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

Genaratoraction::Genaratoraction(){

    particleGun = new G4ParticleGun(1);
    auto table = G4ParticleTable::GetParticleTable();
    particleGun->SetParticleDefinition(table->FindParticle("neutron"));
    particleGun->SetParticleEnergy(0.025*eV);
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
    particleGun->SetParticlePosition(G4ThreeVector(0,0,-100));
    particleGun->SetNumberOfParticles(1);
}

Genaratoraction::~Genaratoraction(){

    delete particleGun;
}

void Genaratoraction::GeneratePrimaries(G4Event* e){

    particleGun->GeneratePrimaryVertex(e);
    
}