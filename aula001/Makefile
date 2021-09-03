all:
	g++ main.cpp MeuDetector.cpp MeuDetector.hpp GeradorPrimario.hpp GeradorPrimario.cpp FonteDeParticulas.hpp FonteDeParticulas.cpp  `geant4-config --libs` -I${G4INCLUDES} -o main
	./main > resultado.txt