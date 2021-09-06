#pragma once
#include"G4VUserDetectorConstruction.hh"

class MeuDetector:public G4VUserDetectorConstruction
{
public:
    virtual G4VPhysicalVolume* Construct() override;
 
  
};