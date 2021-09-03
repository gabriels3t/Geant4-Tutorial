#include "G4VUserActionInitialization.hh" // inicializador das ações
#include "G4VUserPrimaryGeneratorAction.hh" // gerador primario (fonte)
#include "G4ParticleGun.hh" // produtor de particulas 
#include "G4Electron.hh" // produzindo eletrons

class GeradorPrimario:public G4VUserPrimaryGeneratorAction
{
public:
  virtual void GeneratePrimaries(G4Event* anEvent) override;
};