//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_PRIMARYPAT_HH
#define FINAL_PRIMARYPAT_HH

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include "Mes.hh"
class Mes1;
class PrimaryPat: public G4VUserPrimaryGeneratorAction{
private:
    G4ParticleGun* gun2;
    G4ParticleGun* gun1;
    G4ParticleGun* gun;
    Mes1* detMes1;

public:
    PrimaryPat();
    ~PrimaryPat();
    virtual void GeneratePrimaries(G4Event* anEvent);
    G4double vis_det1;
    void ChangeAll228 (G4double newAll);
};
#endif //FINAL_PRIMARYPAT_HH
