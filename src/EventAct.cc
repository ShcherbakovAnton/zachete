//
// Created by idalov on 10.05.17.
//

#include <EventAct.hh>
#include <Logger.hh>
#include <G4EventManager.hh>
#include "G4Event.hh"

EventAct::EventAct(){
    //Logger::Info("\"EventAct.cc\" works");
    detMes2 =new Mes2(this);    vis_det1 = 1;
}
void EventAct::BeginOfEventAction(const G4Event *anEvent) {


    if (vis_det1 == 0){
        anEvent->GetEventID();

        if (anEvent->GetEventID()%1000==0) {
            G4cout << anEvent->GetEventID() << G4endl;
        }
    }
    else {

    }

}
void EventAct::ChangeAll22 (G4double newAll) {
    vis_det1 = newAll;
}