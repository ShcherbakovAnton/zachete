//
// Created by student on 14.05.17.
//

#include <Mes.hh>
#include <Logger.hh>


Mes::Mes(Geometry* geom):detGeom(geom) {
    //Logger::Info("\"Mes.cc\" works, command created");
    //fDirectory = new G4UIdirectory (" !!!new_commands");

    change_H = new G4UIcmdWithADouble (" !!!new_commands/ch_H_detector", this);
    change_H->SetGuidance("change H of detector (tubs) ");
    change_D = new G4UIcmdWithADouble (" !!!new_commands/ch_D_source", this);
    change_D->SetGuidance("changing D of source (cube)");


    setMat = new G4UIcommand (" !!!new_commands/setMat", this);
    setMat->SetGuidance("setting new material for detector (choise of 3)");

    G4UIparameter* matIst = new G4UIparameter("material", 's', true);
    matIst->SetGuidance("setting new material for detector (choise of 3)");
    matIst->SetDefaultValue("G4_Cf");
    matIst->SetParameterCandidates("G4_U G4_Xe G4_Cs");

    setMat->SetParameter(matIst);

    ch_all = new G4UIcmdWithADouble (" !!!new_commands/change_all!!!", this);
    ch_all->SetGuidance("setting new detector geometry");

    setCol = new G4UIcommand (" !!!new_commands/setColourGreen",this);

    change_Mat = new G4UIcommand (" !!!new_commands/change_Mat", this);

   // change_Col = new G4UIcommand (" !!!new_commands/change_color", this);
    /*change_Mat->SetCandidates("G4_Fe");
    change_Mat->SetCandidates("G4_AIR");*/
}

void Mes::SetNewValue(G4UIcommand* cmd, G4String newvalue){
    Logger::Info("\"Mes.cc\"->cmd SetNewValue works");
    if (cmd == change_H)
        detGeom->SetH(change_H->GetNewDoubleValue(newvalue));
       // detGeom->
    if (cmd == change_D)
        detGeom->SetD(change_D->GetNewDoubleValue(newvalue));

    if (cmd == setMat)
        detGeom->SetMat(newvalue);
    if (cmd == setCol)
        detGeom->SetCol();

    if (cmd == ch_all)
        detGeom->ChangeAll(ch_all->GetNewDoubleValue(newvalue));



    //if (cmd == change_Mat)
    //    detGeom->SetMat("G4_Fe");
       // detGeom->SetMat(change_Mat->GetCurrentValue());
        Logger::Info(" Material changed to-> smth");
    /*if (cmd == change_Col)
        detGeom->SetMat("G4_Fe");*/
}
