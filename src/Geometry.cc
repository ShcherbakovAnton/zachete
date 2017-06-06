//
// Created by idalov on 10.05.17.
//

#include <Geometry.hh>
#include <G4PVPlacement.hh>
#include <Logger.hh>
#include <G4Tubs.hh>
#include <G4GeometryManager.hh>
#include <G4SolidStore.hh>
#include <G4RunManager.hh>
#include <G4UImanager.hh>
#include <G4Color.hh>
#include <G4VisCommandsGeometrySet.hh>
#include <G4Orb.hh>

Geometry::Geometry(){

    nist = G4NistManager::Instance();
    world_mat = nist->FindOrBuildMaterial("G4_AIR");

    ist_Col = new G4VisAttributes (G4Colour::Red());
    det_Col = new G4VisAttributes (G4Colour::Red());;

    det_H=40;
    ist_D=40;

    vis_det = 1;

    Logger::Info("\"Geometry\" have been built");
    detMes =new Mes(this);

}

Geometry::~Geometry(){
    delete detMes;
    delete world;
    delete world_log;
    delete world_VP;
    Logger::Info("\"Geometry\" have been destroyed");
}
G4VPhysicalVolume* Geometry::Construct() {
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();


    G4double size = 50*m;
    world = new G4Box("world", 2*size/2., 2*size/2.,2*size/2.);
    world_log = new G4LogicalVolume(world, world_mat, "world_log");
    world_log->SetVisAttributes(G4VisAttributes::Invisible);
    world_VP = new G4PVPlacement(0,G4ThreeVector(),world_log,"world_PV",0,false,0);

    det_Mat = nist->FindOrBuildMaterial("G4_WATER");
    ist_Mat = nist->FindOrBuildMaterial("G4_Cf");
    G4Tubs* det=new G4Tubs("det", 0, 70, det_H, 0, 360*deg);
    G4Box* ist=new G4Box("ist", ist_D, ist_D, ist_D);
    G4Orb* det2 = new G4Orb("det2", 70);

    //G4LogicalVolume* det_log= new G4LogicalVolume(det, det_Mat, "det_log");
    if (vis_det == 0)
        {
          //  G4LogicalVolume *det_log = new G4LogicalVolume(det, det_Mat, "det_log");
          //  new G4PVPlacement (0, G4ThreeVector (0,0,-50), det_log, "ded_PVP", world_log, false,0);
            G4LogicalVolume* det_log= new G4LogicalVolume(det2, det_Mat, "det_log");
            new G4PVPlacement (0, G4ThreeVector (0,0,0), det_log, "ded_PVP", world_log, false,0);

            G4LogicalVolume* det_log1= new G4LogicalVolume(det2, det_Mat, "det_log");
            new G4PVPlacement (0, G4ThreeVector (0,0,-150), det_log1, "ded_PVP", world_log, false,0);

            G4LogicalVolume* det_log2= new G4LogicalVolume(det2, det_Mat, "det_log");
            new G4PVPlacement (0, G4ThreeVector (0,0,150), det_log2, "ded_PVP", world_log, false,0);
        }

    else {
       // G4Box* ist=new G4Box("ist", ist_D, ist_D, ist_D)


        G4LogicalVolume* ist_log= new G4LogicalVolume(ist, ist_Mat, "ist_log");
        new G4PVPlacement (0, G4ThreeVector (0,0,0), ist_log, "ist_PVP", world_log, false,0);

        }

    //G4LogicalVolume* ist_log= new G4LogicalVolume(ist, ist_Mat, "ist_log");

   // G4VisAttributes* Clr = det_Col;
    //det_log->SetVisAttributes(Clr);

    //G4VisAttributes* Clr2 = ist_Col;
   // ist_log->SetVisAttributes(Clr2);


    //new G4PVPlacement (0, G4ThreeVector (0,0,-50), det_log, "ded_PVP", world_log, false,0);
    // !! new G4PVPlacement (0, G4ThreeVector (0,0,50), ist_log, "ist_PVP", world_log, false,0);

    return world_VP;
}

void Geometry::SetH (G4double newH){
    det_H = newH;
    Logger::Info("\"Messenger: New_H_detector = ", det_H);
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");
}

void Geometry::SetD (G4double newD){
    ist_D = newD;
    Logger::Info("\"Messenger: New_D_source = ", ist_D);
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");
}

void Geometry::SetMat (G4String newMat){
    ist_Mat = nist->FindOrBuildMaterial(newMat);
    Logger::Info("\"Messenger: New_Mat = " + ist_Mat->GetName());
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");
}

void Geometry::SetCol (){
    ist_Col = new G4VisAttributes (G4Colour::Green());
    det_Col = new G4VisAttributes (G4Colour::Green());

    //Logger::Info("\"Messenger: New_Mat = " + ist_Mat->GetName());
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");
}

//void G4VisAttributes::SetVisAttributes (const G4VisAttributes* Clr);

void Geometry::ChangeAll (G4double newAll){
    vis_det = newAll;

    //ist_Mat = nist->FindOrBuildMaterial(newMat);
    //Logger::Info("\"Messenger: New_Mat = " + ist_Mat->GetName());
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");
}