#include "FonteDeParticulas.hpp"
#include "GeradorPrimario.hpp"
void FonteDeParticulas::Build() const{
    SetUserAction(new GeradorPrimario());
}
