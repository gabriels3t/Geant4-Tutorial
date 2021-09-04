#include <iostream>
#include "G4RunManager.hh"// "inicializador"
#include "MeuDetector.hpp" // Incluindo Detector
#include "GeradorPrimario.hpp"// Incluindo Gerador Primario
#include "FonteDeParticulas.hpp" // Incluindo Fonte de particulas
#include "G4VUserPhysicsList.hh"// incluindo a lista de fisica
#include "G4PhysListFactory.hh"// incluindo para poder usar lista de fisicas ja existentes no site do cern
#include "G4UIExecutive.hh" // incluindo a interface de usuario
#include"G4UImanager.hh" //incluindo para poder usar comandos pre selecionados no programa

int main(int argc,char** argv){
    //G4RunManager *manager = new G4RunManager();
    auto *runManager = new G4RunManager(); // auto faz com que o c++ entenda autimaticamente qual é o obj do ponteiro
    auto *factory = new G4PhysListFactory(); // a fabrica da lista
    auto *listadefisica = factory->GetReferencePhysList("Shielding"); // Usando a list ja existente 


    runManager->SetUserInitialization(new MeuDetector()); // inicializador o detector 
    runManager->SetUserInitialization(listadefisica);  // inicializador a lista de fisica
    runManager->SetUserInitialization(new FonteDeParticulas());// inicializador a fonte de particulas
    runManager->Initialize();// Inicializando a simulação
    
    //auto *executarUI= new G4UIExecutive(argc,argv);
    //executarUI->SessionStart();
   
    auto *uiManager = G4UImanager::GetUIpointer();
    //uiManager->ApplyCommand("/run/beamOn 10"); // Passando o comando 
    uiManager->ApplyCommand("/control/execute "+ G4String(argv[1])); // passando para ler um arquivo macro
    delete runManager;
    delete factory;
    //delete executarUI;


}