#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TH2D.h>
#include "Particle.h"

void read(){
    
    //Open your file 
    TFile *file = TFile::Open("tree_file.root");
    //Check if the file was successfully opened
    if(!file){
        cerr << "Error:Could not open the file." << endl;
        return;
    }

    //Get your tree
    TTree *tree = (TTree*)file->Get("tree");

    Particle *particle{nullptr};
    //Remember to set the branch address
    tree->SetBranchAddress("particle",&particle);

    //Create a TH2D for px and py
    TH2D *h2 = new TH2D("h2","SCatter Plot of px vs py",100,-1,1,100,-1,1);

    //Loop over the whole tree
    Long64_t N = tree->GetEntries();
    for (Long64_t i{0}; i < N;i++){
        tree->GetEntry(i);

        //Fill the TH2 with px and py
        h2->Fill(particle->GetPx(),particle->GetPy());
    }
    //Draw the TH2
    h2->Draw("colz");

    //Draw a scatter plot of px*py vs pz with some criterion on the magnitude of momentum 
    tree->Draw("fPx*fPy:fPz","particle->GetMagnitudeP() < 0.5");

    //Close the root file
    file->Close();

}