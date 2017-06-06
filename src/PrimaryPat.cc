//
// Created by idalov on 10.05.17.
//

#include <PrimaryPat.hh>
#include <G4Gamma.hh>
#include <G4SystemOfUnits.hh>
#include <Logger.hh>
#include <G4RunManager.hh>
#include <G4UImanager.hh>


PrimaryPat::PrimaryPat() {
    vis_det1 = 1;
    gun = new G4ParticleGun(1);
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());

    gun1 = new G4ParticleGun(1);
    gun1->SetParticleDefinition(G4Gamma::GammaDefinition());


    gun2 = new G4ParticleGun(1);
    gun2->SetParticleDefinition(G4Gamma::GammaDefinition());
   // Logger::Info("\"Primary particles generation actions\" have been built");
    detMes1 =new Mes1(this);
}

PrimaryPat::~PrimaryPat() {
   // Logger::Info("\"Primary particles generation actions\" have been destroyed");
    delete gun;
    delete gun1;
    delete gun2;
}



void PrimaryPat::GeneratePrimaries(G4Event* anEvent){
    if (vis_det1 == 0)
    {
    gun->SetParticleEnergy(0.661*MeV);
    gun->SetParticlePosition(G4ThreeVector(100,0,0));
    gun->SetParticleMomentumDirection(G4ThreeVector(-1,0,0));

    gun->GeneratePrimaryVertex(anEvent);


    gun1->SetParticleEnergy(0.661*MeV);
    gun1->SetParticlePosition(G4ThreeVector(100,0,0));
    gun1->SetParticleMomentumDirection(G4ThreeVector(-1,0,-2));

    gun1->GeneratePrimaryVertex(anEvent);

    gun2->SetParticleEnergy(0.661*MeV);
    gun2->SetParticlePosition(G4ThreeVector(100,0,0));
    gun2->SetParticleMomentumDirection(G4ThreeVector(-1,0,2));

    gun2->GeneratePrimaryVertex(anEvent);
}
    else {
        gun->SetParticleEnergy(0.661*MeV);
        gun->SetParticlePosition(G4ThreeVector(100,0,0));
        gun->SetParticleMomentumDirection(G4ThreeVector(-1,0,0));

        gun->GeneratePrimaryVertex(anEvent);

    }

    }
void PrimaryPat::ChangeAll228 (G4double newAll){
    vis_det1 = newAll;





    //ist_Mat = nist->FindOrBuildMaterial(newMat);
    //Logger::Info("\"Messenger: New_Mat = " + ist_Mat->GetName());
   // G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
   // G4RunManager::GetRunManager()->ReinitializeGeometry();
  //  G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");
}