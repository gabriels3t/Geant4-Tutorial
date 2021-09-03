#include <iostream>
#include "Teste.hpp"
int main() {
    auto *tes = new Teste();
    tes->setNumero(10);
    std::cout << tes->getInt() << std::endl;
}
