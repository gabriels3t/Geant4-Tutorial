#pragma once

#include "G4VUserActionInitialization.hh" // inicializador das ações

class FonteDeParticulas: public G4VUserActionInitialization
{
public:
    virtual void Build() const override;
};