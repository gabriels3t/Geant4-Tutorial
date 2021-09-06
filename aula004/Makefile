all:
	g++ -I compilado/ ./compilado/*.o `geant4-config --libs` -I${G4INCLUDES} -o main

compilar-todos:
	g++ -c *.cpp `geant4-config --libs` -I${G4INCLUDES} 
	mv *.o compilado/
compilar-FonteDeParticulas:
	g++ -c FonteDeParticulas.cpp `geant4-config --libs` -I${G4INCLUDES}
	mv *.o compilado/
compilar-GeradorPrimario:
	g++ -c GeradorPrimario.cpp `geant4-config --libs` -I${G4INCLUDES}
	mv *.o compilado/
compilar-MeuDetector:
	g++ -c MeuDetector.cpp `geant4-config --libs` -I${G4INCLUDES}
	mv *.o compilado/
compilar-main:
	g++ -c main.cpp `geant4-config --libs` -I${G4INCLUDES}
	mv *.o compilado/
