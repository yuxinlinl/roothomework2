#include "Particle.h"
ClassImp(Particle)

//default constructor -ROOT needs the default one where everything is set to 0
Particle::Particle():fPx(0.0),fPy(0.0),fPz(0.0),fMomentumMagnitude(0.0){

}

//another constructor
Particle::Particle(Double_t px,Double_t py,Double_t pz):fPx(px),fPy(py),fPz(pz){
    fMomentumMagnitude =TMath::Sqrt(fPx * fPx + fPy * fPy + fPz *fPz);
}

//Destructor
Particle::~Particle(){

}

Double_t Particle::GetPx() const{
    return fPx;
}

Double_t Particle::GetPy() const{
    return fPz;
}

Double_t Particle::GetPz() const{
    return fPz;
}

Double_t Particle::GetMagnitudeP() const{
    return fMomentumMagnitude;
}

void Particle::SetPx(Double_t px){
    fPx = px;
}
void Particle::SetPy(Double_t py){
    fPy = py;
}
void Particle::SetPz(Double_t pz){
    fPz = pz;
}