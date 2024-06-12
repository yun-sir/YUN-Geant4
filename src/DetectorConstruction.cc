#include "DetectorConstruction.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SubtractionSolid.hh"
#include  "G4VisAttributes.hh"

DetectorConstruction::DetectorConstruction()
{
    yun_SD_Ma = G4SDManager::GetSDMpointer();
}

DetectorConstruction::~DetectorConstruction()
{

}

void DetectorConstruction::defineMaterial()
{
    // element
    G4Isotope* const B10 = new G4Isotope("B10", 5, 10, 10.811*(g/mole));
    G4Element* ele_B = new G4Element("Boron", "B", 1);
    ele_B->AddIsotope(B10, 100.*perCent);
    G4Element* ele_N = new G4Element("Nitrogen",  "N", 7., 14.01*g/mole);
    G4Element* ele_C = new G4Element("Carbon",  "C", 6., 12.01*g/mole);
    G4Element* ele_O = new G4Element("Oxygen",  "O", 8., 15.999*g/mole);

    G4Isotope* Gd155 = new G4Isotope("Gd155", 64, 155, 154.92*(g/mole));
    G4Isotope* Gd157 = new G4Isotope("Gd157", 64, 157, 157.92*(g/mole));
    G4Element* ele_Gd = new G4Element("Gadolinium",  "Gd", 2);
    ele_Gd->AddIsotope(Gd155, 14.8*perCent);
    ele_Gd->AddIsotope(Gd157, 15.65*perCent);

    B4C = new G4Material("B4C", 2.52*g/cm3 , 2, kStateSolid, 293.15*kelvin, 1.*atmosphere);
    B4C->AddElement(ele_B, 4);
    B4C->AddElement(ele_C, 1);

    BN = new G4Material("BN", 2.29*g/cm3 , 2, kStateSolid, 293.15*kelvin, 1.*atmosphere);
    BN->AddElement(ele_B, 1);
    BN->AddElement(ele_N, 1);

    density = 7.07 *g/cm3;
    Gd2O3 = new G4Material("Gd2O3", density, 2, kStateSolid, 293.15*kelvin, 1.*atmosphere);
    Gd2O3->AddElement(ele_Gd, 2);
    Gd2O3->AddElement(ele_O, 3);

    density = 7.9*g/cm3;
    Gd_nat = new G4Material("Gd_nat", density, 1, kStateSolid, 293.15, 1.0);
    Gd_nat->AddElement(ele_Gd, 1);

}

G4VPhysicalVolume* DetectorConstruction::Construct(){
    defineMaterial();
    G4NistManager* nist = G4NistManager::Instance();
    G4Box* solid_world = new G4Box("world", 1*m, 1*m,1*m);
    G4LogicalVolume* logic_world = new G4LogicalVolume(solid_world, nist->FindOrBuildMaterial("G4_Galactic"), "world");
    logic_world->SetVisAttributes(G4VisAttributes(false));
    auto physics_world = new G4PVPlacement(0, G4ThreeVector(0,0,0), logic_world,"world", 0, 0, 0);

    G4Box* big_box = new G4Box("Gd", 40*mm,40*mm,20*mm);
    G4LogicalVolume* logic_ke = new G4LogicalVolume(big_box,Gd_nat,big_box->GetName());
    logic_ke->SetVisAttributes(G4VisAttributes(true));
    new G4PVPlacement(
        0,
        G4ThreeVector(0,0,0),
        logic_ke,
        logic_ke->GetName(),
        logic_world,
        false,
        0  );

    yun_SD_Gd = new yunSD("Gd_SD");
    yun_SD_Ma->AddNewDetector(yun_SD_Gd);
    fScoringVolume = logic_ke;
    logic_ke->SetSensitiveDetector(yun_SD_Gd);
    return physics_world;

}