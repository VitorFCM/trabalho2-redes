cc := g++

aplicacao_transmissora.o: src/aplicacao_transmissora.cpp
	$(cc) -g -I include -c src/aplicacao_transmissora.cpp -o build/aplicacao_transmissora.o

main.o: src/main.cpp
	$(cc) -g -I include -c src/main.cpp -o build/main.o

main: main.o aplicacao_transmissora.o
	$(cc) build/main.o build/aplicacao_transmissora.o -o main

clean:
	rm -f build/*.o all
	rm main
