#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TRandom3.h>
#include "Particle.h"

void write(){
    
    Particle *particle{nullptr};
    
    //Create my root file
    TFile *file = new TFile("tree_file.root","RECREATE");

    //Create my TTree
    TTree *tree = new TTree("tree","Particle Tree");
    
    
    //Create a branch for the particle object
    tree->Branch("particle",&particle);
    

    //For loop to fill the tree with random data
    for (Int_t i{0}; i < 10000; i++){

        particle = new Particle();
        //Genterate random values for momentum
        Double_t px = gRandom->Gaus(0,0.02);
        Double_t py = gRandom->Gaus(0,0.02);
        Double_t pz = gRandom->Gaus(0,0.02);

        //Set the values in your class
        particle->SetPx(px);
        particle->SetPy(py);
        particle->SetPz(pz);

        //Fill the TTree with the particle data
        tree->Fill();
        delete particle;
    }
    //Write the tree to the file 
    tree->Write();

    //Close the file and clean up
    
    file->Close();
    
}