#pragma once
#include "G4VSensitiveDetector.hh"

class MeuSensor:public G4VSensitiveDetector
{
public:
    MeuSensor(const G4String &name);
    ~MeuSensor();
    virtual G4bool ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist) override;
};

