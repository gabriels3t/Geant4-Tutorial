#include <iostream>
#include "G4RunManager.hh"// "inicializador"
#include "MeuDetector.hpp" // Incluindo Detector
#include "GeradorPrimario.hpp"
#include "G4VUserPhysicsList.hh"// incluindo a lista de fisica
#include "G4PhysListFactory.hh"// incluindo para poder usar lista de fisicas ja existentes no site do cern

// ------------------------------ incluindo a fonte de particulas --------------------------------
// ------------------------------ Classe Gerador Primario ----------------------------------------

// ------------------------------ Fim Classe Gerador Primario ------------------------------------
// ------------------------------ Classe Fonte De Particulas -------------------------------------
// ------------------------------ Fim Classe Fonte De Particulas ---------------------------------
class FonteDeParticulas: public G4VUserActionInitialization
{
public:
    virtual void Build() const override;
};

void FonteDeParticulas::Build() const{
    SetUserAction(new GeradorPrimario());
}

// ------------------------------ Fim Classe Fonte De Particulas ---------------------------------

// ------------------------------ Fim da fonte de particulas -------------------------------------

int main(){
    //G4RunManager *manager = new G4RunManager();
    auto *manager = new G4RunManager(); // auto faz com que o c++ entenda autimaticamente qual é o obj do ponteiro
    auto *factory = new G4PhysListFactory(); // a fabrica da lista
    auto *listadefisica = factory->GetReferencePhysList("Shielding"); // Usando a list ja existente 


    manager->SetUserInitialization(new MeuDetector()); // inicializador o detector 
    manager->SetUserInitialization(listadefisica);  // inicializador a lista de fisica
    manager->SetUserInitialization(new FonteDeParticulas());// inicializador a fonte de particulas
    manager->Initialize();// Inicializando a simulação
    
    manager->BeamOn(2); // ligando o feixe de particulas (quantas particulas eu quero)
    delete manager;
    delete factory;


}