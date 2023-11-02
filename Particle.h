#ifndef __Particle_H__
#define __Particle_H__

#include <TObject.h>
#include <TString.h>
#include <TMath.h>

class Particle: public TObject{
    public:
      Particle();//default constructor
      Particle(Double_t px,Double_t py,Double_t pz);//some other constructors
      virtual ~Particle();//destructor

      Double_t GetPx() const;
      Double_t GetPy() const;
      Double_t GetPz() const;
      Double_t GetMagnitudeP()const;

      //Setter methods
      void SetPx(Double_t px);
      void SetPy(Double_t py);
      void SetPz(Double_t pz);

    private:
      Double_t fPx;
      Double_t fPy;
      Double_t fPz;
      Double_t fMomentumMagnitude;

      ClassDef(Particle,1);

};
#endif//__Particle_H__