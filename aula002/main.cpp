#include <iostream>
#include "G4RunManager.hh"// "inicializador"
#include "MeuDetector.hpp" // Incluindo Detector
#include "GeradorPrimario.hpp"// Incluindo Gerador Primario
#include "FonteDeParticulas.hpp" // Incluindo Fonte de particulas
#include "G4VUserPhysicsList.hh"// incluindo a lista de fisica
#include "G4PhysListFactory.hh"// incluindo para poder usar lista de fisicas ja existentes no site do cern
#include "G4UIExecutive.hh" // incluindo a interface de usuario



int main(int argc,char** argv){
    //G4RunManager *manager = new G4RunManager();
    auto *manager = new G4RunManager(); // auto faz com que o c++ entenda autimaticamente qual é o obj do ponteiro
    auto *factory = new G4PhysListFactory(); // a fabrica da lista
    auto *listadefisica = factory->GetReferencePhysList("Shielding"); // Usando a list ja existente 


    manager->SetUserInitialization(new MeuDetector()); // inicializador o detector 
    manager->SetUserInitialization(listadefisica);  // inicializador a lista de fisica
    manager->SetUserInitialization(new FonteDeParticulas());// inicializador a fonte de particulas
    manager->Initialize();// Inicializando a simulação
    
    auto *executarUI= new G4UIExecutive(argc,argv);
    executarUI->SessionStart();
   // manager->BeamOn(2); // ligando o feixe de particulas (quantas particulas eu quero)
    delete manager;
    delete factory;
    delete executarUI;


}