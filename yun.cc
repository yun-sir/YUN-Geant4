#include "QGSP_BERT_HP.hh"
#include "G4MTRunManager.hh"
#include "G4RunManager.hh"
#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

int main(int argc , char** argv)
{
    G4UIExecutive* ui = nullptr;
    if ( argc == 1 ) { ui = new G4UIExecutive(argc, argv); }   
    G4cout<<"OVER!!1"<<G4endl;

    G4RunManager* runManager = new G4RunManager();
    // G4MTRunManager* runManager = new G4MTRunManager();
    // runManager->SetNumberOfThreads(10);
    G4cout<<"OVER!!2"<<G4endl;
    runManager->SetUserInitialization(new DetectorConstruction);
    G4cout<<"OVER!!3"<<G4endl;
    runManager->SetUserInitialization(new QGSP_BERT_HP);
    G4cout<<"OVER!!4"<<G4endl;
    runManager->SetUserInitialization(new ActionInitialization);
    G4cout<<"OVER!!5"<<G4endl;

    runManager->Initialize();
    runManager->BeamOn(100);

    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    G4cout<<"OVER!!6"<<G4endl;

    G4UImanager* UImanager =  G4UImanager::GetUIpointer();
    if ( ! ui ) {
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
    }
    else {
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
    }

    delete visManager;
    delete runManager;
	G4cout<<"OVER!!"<<G4endl;

    return 0 ;
}
