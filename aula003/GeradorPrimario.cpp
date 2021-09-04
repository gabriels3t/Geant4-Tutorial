#include <iostream>
#include "GeradorPrimario.hpp"

GeradorPrimario::GeradorPrimario():
G4VUserPrimaryGeneratorAction(),
m_particleGun(new G4ParticleGun(G4Geantino::Definition())){

}


void GeradorPrimario::GeneratePrimaries(G4Event* anEvent) {
    m_particleGun->GeneratePrimaryVertex(anEvent);
    /*std::cout << "Run Id             : " << anEvent->GetEventID()<< std::endl;*/
    std::cout << "Particula primaria : " << m_particleGun->GetParticleDefinition()->GetParticleName()<< std::endl;
    std::cout << "Energia (Mev)      : " << m_particleGun->GetParticleEnergy()<< std::endl;

}

GeradorPrimario::~GeradorPrimario(){
    delete m_particleGun;
}