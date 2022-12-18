cc := g++

transmissao := src/transmissao

camada_enlace_transmissora.o: src/transmissao/camada_enlace_transmissora.cpp
	$(cc) -g -I include -c src/transmissao/camada_enlace_transmissora.cpp -o build/camada_enlace_transmissora.o

camada_aplicacao_transmissora.o: src/transmissao/camada_aplicacao_transmissora.cpp
	$(cc) -g -I include -c src/transmissao/camada_aplicacao_transmissora.cpp -o build/camada_aplicacao_transmissora.o

aplicacao_transmissora.o: src/transmissao/aplicacao_transmissora.cpp
	$(cc) -g -I include -c src/transmissao/aplicacao_transmissora.cpp -o build/aplicacao_transmissora.o

main.o: src/main.cpp
	$(cc) -g -I include -c src/main.cpp -o build/main.o

main: main.o aplicacao_transmissora.o camada_aplicacao_transmissora.o camada_enlace_transmissora.o
	$(cc) build/main.o build/aplicacao_transmissora.o build/camada_aplicacao_transmissora.o build/camada_enlace_transmissora.o -o main

clean:
	rm -f build/*.o all
	rm main
