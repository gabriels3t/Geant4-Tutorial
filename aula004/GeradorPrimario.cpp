#include <iostream>
#include "GeradorPrimario.hpp"
#include "G4Geantino.hh" // produzindo uma particula ficticia nula do geant

GeradorPrimario::GeradorPrimario():
G4VUserPrimaryGeneratorAction(),
m_particleGun(new G4ParticleGun(G4Geantino::Definition())){

}


void GeradorPrimario::GeneratePrimaries(G4Event* anEvent) {
    m_particleGun->GeneratePrimaryVertex(anEvent);

}

GeradorPrimario::~GeradorPrimario(){
    delete m_particleGun;
}