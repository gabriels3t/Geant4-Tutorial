#include "MeuDetector.hpp"

#include "G4Box.hh"// incluindo uma caixa
#include "G4Material.hh" // Incluindo material
#include "G4NistManager.hh" // Incluindo lista de material
#include "G4LogicalVolume.hh"// Incluindo a união entre a geomatria com o material
#include "G4VPhysicalVolume.hh" // Incluindo para um volume fisico
#include "G4PVPlacement.hh"// Incluindo para um volume fisico
#include "CLHEP/Units/SystemOfUnits.h" // Incluindo sistema de unidade 
#include "G4SubtractionSolid.hh" // Incluindo para poder subtrair solidos 

G4VPhysicalVolume* MeuDetector::Construct(){
    //CLHEP:: Namcespace para poder usar o SystemOfUnits

    // Materiais
    auto lAr = G4NistManager::Instance()->FindOrBuildMaterial("G4_lAr"); // criando o argonio liquido
    auto ar = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"); // criando ar
    auto achoInox = G4NistManager::Instance()->FindOrBuildMaterial("G4_STAINLESS-STEEL"); // criando aço inox
    // Mundo do detector
    auto worldBox = new G4Box("mundo",0.5*CLHEP::m,0.5*CLHEP::m,0.5*CLHEP::m); // O Geant duplica o espaço entao no final sera 1 metro
    auto logicalWord = new G4LogicalVolume(worldBox,ar,"Mundo-Logico");// unindo no mundo logico
    auto mundoFisico = new G4PVPlacement(0,{0,0,0},logicalWord,"Mundo",0,false,0);// volume fisico

    // Detector 
    
        //Dimensões do detector
    double comprimento = 50.0 *CLHEP::cm;
    double largura = 10.0*CLHEP::cm;
    double espessura = 3.0*CLHEP::mm;
    
        // Construindo a caixa do detector
    auto detectorExterno = new G4Box("Detector-Externo",comprimento/2,largura/2,largura/2);
    auto detectorInterior = new G4Box("Detector-Interior",comprimento/2-espessura,largura/2-espessura,largura/2-espessura); // precisa do -espessura, pois assim ficara com o tamanho correto
    auto detectorParede = new G4SubtractionSolid("DetectorParede",detectorExterno,detectorInterior); // assim subtraindo o detectorExterno do detectorInterior
        
        //Construindo o volume logico (a parte de aço do detector)
    auto detectorLogicoDaParede = new G4LogicalVolume(detectorParede,achoInox,"detector-Da-Parede");

    auto detectorFisico = new G4PVPlacement(0,{0,0,0},detectorLogicoDaParede,"detector-Fisico",logicalWord,false,0); // logicalWord pq esta o detector esta dentro dele 
    
    // Criando um volume interno para colocar o argonio 
    auto detectorVolumeLogico = new G4LogicalVolume(detectorInterior,lAr,"Volume-Logico-Detector");
    auto detectorFisicoDoVoulme = new G4PVPlacement(0,{0,0,0},detectorVolumeLogico,"detector-Fisico-do-volume",logicalWord,false,0); 

    return mundoFisico;
    
}