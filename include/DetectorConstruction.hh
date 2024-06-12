#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4Isotope.hh"
#include "yunSD.hh"
#include "G4SDManager.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        DetectorConstruction();
        ~DetectorConstruction();
        virtual G4VPhysicalVolume *Construct();
        void defineMaterial();
        G4LogicalVolume* GetScoringVolume() const {return fScoringVolume;}
        G4SDManager* yun_SD_Ma;
        yunSD* yun_SD_Gd ;
    private:
        G4double density;
        G4LogicalVolume* Box_test ;
        G4Material* B4C;
        G4Material* BN;
        G4Material* Gd2O3;
        G4Material* Gd_nat;
        G4LogicalVolume* fScoringVolume = nullptr;
    
};

#endif 