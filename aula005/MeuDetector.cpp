#include "MeuDetector.hpp"

#include "G4Box.hh"// incluindo uma caixa
#include "G4Material.hh" // Incluindo material
#include "G4NistManager.hh" // Incluindo lista de material
#include "G4LogicalVolume.hh"// Incluindo a união entre a geomatria com o material
#include "G4VPhysicalVolume.hh" // Incluindo para um volume fisico
#include "G4PVPlacement.hh"// Incluindo para um volume fisico
G4VPhysicalVolume* MeuDetector::Construct(){
    // Criando uma material - um cubo com argonio liquido
    auto *lAr = G4NistManager::Instance()->FindOrBuildMaterial("G4_lAr"); // criando o argonio liquido G4_lAr
    auto *worldBox = new G4Box("mundo",10000,10000,10000);// criando a caixa, unidade padrao mm 
    auto *logicalWord = new G4LogicalVolume(worldBox,lAr,"Mundo Logico");// unindo no mundo logico
    auto *mundoFisico = new G4PVPlacement(0,{0,0,0},logicalWord,"Mundo fisico",0,false,0);// volume fisico

    return mundoFisico;
    
}