#pragma once

#include "G4VUserPrimaryGeneratorAction.hh" // gerador primario (fonte)
#include "G4ParticleGun.hh" // produtor de particulas 
#include "G4Geantino.hh" // produzindo uma particula ficticia nula do geant

class GeradorPrimario:public G4VUserPrimaryGeneratorAction
{
private:
  G4ParticleGun *m_particleGun;
public:
  GeradorPrimario();
  ~GeradorPrimario();
  virtual void GeneratePrimaries(G4Event* anEvent) override;
};