#include <iostream>
#include "GeradorPrimario.hpp"
void GeradorPrimario::GeneratePrimaries(G4Event* anEvent) {
    auto *particleGun = new G4ParticleGun(G4Electron::Definition()); // Criando o produtor de particulas para jogar eletrons
    particleGun->GeneratePrimaryVertex(anEvent);
    /*std::cout << "Run Id             : " << anEvent->GetEventID()<< std::endl;*/

    std::cout << "Particula primaria : " << particleGun->GetParticleDefinition()->GetParticleName()<< std::endl;
    std::cout << "Energia (Mev)      : " << particleGun->GetParticleEnergy()<< std::endl;

}