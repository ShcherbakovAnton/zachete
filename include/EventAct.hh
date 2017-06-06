//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_EVENTACT_HH
#define FINAL_EVENTACT_HH

#include <G4UserEventAction.hh>
#include <pwdefs.hh>
#include "Mes.hh"
class Mes2;
class EventAct: public G4UserEventAction{
public:

    Mes2* detMes2;
    G4double vis_det1;
    EventAct();
    //~EventAct();
   void BeginOfEventAction(const G4Event *anEvent);
    void ChangeAll22 (G4double newAll);
};
#endif //FINAL_EVENTACT_HH
