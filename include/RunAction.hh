#ifndef RunAction_h
#define RunAction_h

#include "G4UserRunAction.hh"
#include "TFile.h"
#include "TTree.h"

class RunAction : public G4UserRunAction
{
    public:
        RunAction();
        ~RunAction() ;

    public:
        void BeginOfRunAction(const G4Run*);
        void EndOfRunAction(const G4Run*);
        void BeginOfEvent();
        void EndOfEvent();
        void Get_Gd_Edep(G4double a){ edep = a; }
    private:
        TFile* root_file_name;
        TTree* eventTree;
        G4double edep;
};

#endif