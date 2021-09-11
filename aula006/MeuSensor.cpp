#include "MeuSensor.hpp"
#include <iostream>
#include <iomanip>
#include "G4UnitsTable.hh"

MeuSensor::MeuSensor(const G4String &name):G4VSensitiveDetector(name){

}


G4bool  MeuSensor::ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist){
    std::cout
    << "TrackID: " <<   aStep->GetTrack()->GetTrackID() 
    << " PID: "    <<   aStep->GetTrack()->GetParticleDefinition()->GetParticleName() 
    << " EnDep: "  <<   std::setw(7) << G4BestUnit( aStep->GetTotalEnergyDeposit(), "Energy" )
    << " Position: " << std::setw(7) << G4BestUnit( aStep->GetPreStepPoint()->GetPosition(), "Length" ) <<
    std::endl;

}

MeuSensor::~MeuSensor(){
    
}