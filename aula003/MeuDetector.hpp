#pragma once

#include"G4VUserDetectorConstruction.hh"
#include "G4Box.hh"// incluindo uma caixa
#include "G4Material.hh" // Incluindo material
#include "G4NistManager.hh" // Incluindo lista de material
#include "G4LogicalVolume.hh"// Incluindo a união entre a geomatria com o material
#include "G4VPhysicalVolume.hh" // Incluindo para um volume fisico
#include "G4PVPlacement.hh"// Incluindo para um volume fisico

class MeuDetector:public G4VUserDetectorConstruction
{
public:
    virtual G4VPhysicalVolume* Construct() override;
 
  
};