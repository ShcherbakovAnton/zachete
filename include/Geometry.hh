//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_GEOMETRY_HH
#define FINAL_GEOMETRY_HH

#include <G4VUserDetectorConstruction.hh>
#include <G4Box.hh>
#include <G4NistManager.hh>
#include <G4SystemOfUnits.hh>
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "Mes.hh"
#include "G4VisAttributes.hh"

class Mes;
class Geometry: public G4VUserDetectorConstruction {
private:
    G4Box               *world;
    G4LogicalVolume     *world_log;
    G4VPhysicalVolume   *world_VP;

    G4NistManager*      nist;
    G4Material*         world_mat;
    virtual G4VPhysicalVolume *Construct();

    G4double det_H;
    G4double ist_D;
    G4double vis_det;
    //G4bool vis_det2;
    Mes* detMes;
    //Mes* istMes;
    G4Material* det_Mat;
    G4Material* ist_Mat;
    G4VisAttributes* ist_Col;
    G4VisAttributes* det_Col;

public:
    Geometry();
    ~Geometry();

    void SetH (G4double newH);
    void SetD (G4double newD);
    void SetMat (G4String newMat);
    void SetCol ();
    void ChangeAll (G4double newAll);

};

#endif //FINAL_GEOMETRY_HH
