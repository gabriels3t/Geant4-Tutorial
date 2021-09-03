#include <iostream>
#include "G4RunManager.hh"// "inicializador"

// ------------------------------ incluindo o detector-------------------------------------------

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
G4VPhysicalVolume* MeuDetector::Construct(){
    // Criando uma material - um cubo com argonio liquido
    auto *lAr = G4NistManager::Instance()->FindOrBuildMaterial("G4_lAr"); // criando o argonio liquido
    auto *worldBox = new G4Box("mundo",10000,10000,10000);// criando a caixa, unidade padrao mm 
    auto *logicalWord = new G4LogicalVolume(worldBox,lAr,"Mundo Logico");// unindo no mundo logico
    auto *mundoFisico = new G4PVPlacement(0,{0,0,0},logicalWord,"Mundo fisico",0,false,0);// volume fisico

    return mundoFisico;
    
}


// ------------------------------ Fim do detector------------------------------------------------
// ------------------------------ incluindo lista de Fisica --------------------------------------

#include "G4VUserPhysicsList.hh"// incluindo a lista de fisica
#include "G4PhysListFactory.hh"// incluindo para poder usar lista de fisicas ja existentes no site do cern


// ------------------------------ Fim da lista de Fisica -----------------------------------------
// ------------------------------ incluindo a fonte de particulas --------------------------------

#include "G4VUserActionInitialization.hh" // inicializador das ações
#include "G4VUserPrimaryGeneratorAction.hh" // gerador primario (fonte)
#include "G4ParticleGun.hh" // produtor de particulas 
#include "G4Electron.hh" // produzindo eletrons

class FonteDeParticulas: public G4VUserActionInitialization
{
public:
    virtual void Build() const override;
};
/*
void FonteDeParticulas::Build() const{
    SetUserAction(new GeradorPrimario);
}
*/


// ------------------------------ Fim da fonte de particulas -------------------------------------

int main(){
    //G4RunManager *manager = new G4RunManager();
    auto *manager = new G4RunManager(); // auto faz com que o c++ entenda autimaticamente qual é o obj do ponteiro
    auto *factory = new G4PhysListFactory(); // a fabrica da lista
    auto *listadefisica = factory->GetReferencePhysList("Shielding"); // Usando a list ja existente 


    manager->SetUserInitialization(new MeuDetector()); // inicializador o detector 
    manager->SetUserInitialization(listadefisica);  // inicializador a lista de fisica
    
    manager->Initialize();// Inicializando a simulação
    
}