#include "RunAction.hh"
#include "G4Run.hh"
#include "TFile.h"
#include "TTree.h"

RunAction::RunAction()
{

}

RunAction::~RunAction()
{

}

void RunAction::BeginOfRunAction(const G4Run* aRun)
{
    G4int RunN = aRun->GetRunID();
    G4cout<<  "Run ID : "<< RunN <<G4endl;
    root_file_name = new TFile("Gd_edep_test.root", "RECREATE");
    G4cout<<  "ROOT!!! "<<G4endl;
    eventTree = new TTree("Tree", "YUN tree");
    eventTree->Branch("edep", &edep, "edep/D") ;
    G4cout<<  "BRANCH"<<G4endl;
}

void RunAction::BeginOfEvent()
{
    G4cout<<  "RunAction--- BeginOfEvent !!! "<<G4endl;
    edep = 0.0;
}

void RunAction::EndOfEvent()
{
    eventTree->Fill();
    G4cout<<  "RunAction--- EndofEvent !!! "<<G4endl;
}

void RunAction::EndOfRunAction(const G4Run* bRun)
{
    G4int NumOfEvents = bRun->GetNumberOfEvent();
    G4cout<<  "This Run consists of  Events :  "<<  NumOfEvents <<G4endl;
    eventTree->Write();
    root_file_name->Write();
    root_file_name->Close();
}

