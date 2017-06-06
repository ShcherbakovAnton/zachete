//
// Created by student on 14.05.17.
//

#ifndef FINAL_MESSENGER_HH
#define FINAL_MESSENGER_HH


#include <G4UIcommand.hh>
#include <G4UIdirectory.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UImessenger.hh>
#include <Geometry.hh>
#include <G4UIcmdWithAString.hh>
#include "PrimaryPat.hh"




class EventAct;
class Mes2 : public G4UImessenger{
public:

    Mes2(EventAct* even21);
    ~Mes2(){}
    void SetNewValue(G4UIcommand* cmd, G4String newvalue2);
    EventAct* even1;
private:
    G4UIcmdWithADouble* ch_all2;



};


class PrimaryPat;
class Mes1 : public G4UImessenger{
public:

    Mes1(PrimaryPat* Part);
    ~Mes1(){}
    void SetNewValue(G4UIcommand* cmd, G4String newvalue1);
    PrimaryPat* party;
private:
    G4UIcmdWithADouble* ch_all1;



};

class Geometry;
class Mes : public G4UImessenger{
public:

    Mes(Geometry* geom);
    ~Mes(){}
    void SetNewValue(G4UIcommand* cmd, G4String newvalue);
    Geometry* detGeom;
    //PrimaryPat* party;

private:
    //Geometry* detGeom;
    G4UIdirectory* fDirectory;
    G4UIcmdWithADouble* change_H;
    G4UIcmdWithADouble* change_D;
    G4UIcommand* setMat;
    G4UIcmdWithADouble* ch_all;
    G4UIcommand* setCol;

    G4UIcommand* change_Mat;
    G4UIcommand* change_Col;

};

#endif //FINAL_MESSENGER_HH
