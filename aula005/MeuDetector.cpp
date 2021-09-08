#include "MeuDetector.hpp"

#include "G4Box.hh"// incluindo uma caixa
#include "G4Material.hh" // Incluindo material
#include "G4NistManager.hh" // Incluindo lista de material
#include "G4LogicalVolume.hh"// Incluindo a união entre a geomatria com o material
#include "G4VPhysicalVolume.hh" // Incluindo para um volume fisico
#include "G4PVPlacement.hh"// Incluindo para um volume fisico
#include "SystemOfUnits.h" // Incluindo sistema de unidade 

G4VPhysicalVolume* MeuDetector::Construct(){
    //CLHEP:: Namcespace para poder usar o SystemOfUnits

    auto lAr = G4NistManager::Instance()->FindOrBuildMaterial("G4_lAr"); // criando o argonio liquido
    auto ar = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"): // criando ar
    auto achoInox = G4NistManager::Instance()->FindOrBuildMaterial("G4_STAINLESS-STEEL"): // criando aço inox
    auto *worldBox = new G4Box("mundo",1*CLHEP::m,1*CLHEP::m,1*CLHEP::m);
    auto *logicalWord = new G4LogicalVolume(worldBox,lAr,"Mundo Logico");// unindo no mundo logico
    auto *mundoFisico = new G4PVPlacement(0,{0,0,0},logicalWord,"Mundo fisico",0,false,0);// volume fisico

    return mundoFisico;
    
}