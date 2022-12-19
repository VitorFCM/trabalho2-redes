cc := g++

aplicacao_receptora.o: src/receptor/aplicacao_receptora.cpp
	$(cc) -g -I include -c src/receptor/aplicacao_receptora.cpp -o build/aplicacao_receptora.o

camada_aplicacao_receptora.o: src/receptor/camada_aplicacao_receptora.cpp
	$(cc) -g -I include -c src/receptor/camada_aplicacao_receptora.cpp -o build/camada_aplicacao_receptora.o

camada_enlace_receptora.o: src/receptor/camada_enlace_receptora.cpp
	$(cc) -g -I include -c src/receptor/camada_enlace_receptora.cpp -o build/camada_enlace_receptora.o

meio_comunicacao.o: src/meio_comunicacao.cpp
	$(cc) -g -I include -c src/meio_comunicacao.cpp -o build/meio_comunicacao.o

camada_enlace_transmissora.o: src/transmissao/camada_enlace_transmissora.cpp
	$(cc) -g -I include -c src/transmissao/camada_enlace_transmissora.cpp -o build/camada_enlace_transmissora.o

camada_aplicacao_transmissora.o: src/transmissao/camada_aplicacao_transmissora.cpp
	$(cc) -g -I include -c src/transmissao/camada_aplicacao_transmissora.cpp -o build/camada_aplicacao_transmissora.o

aplicacao_transmissora.o: src/transmissao/aplicacao_transmissora.cpp
	$(cc) -g -I include -c src/transmissao/aplicacao_transmissora.cpp -o build/aplicacao_transmissora.o

main.o: src/main.cpp
	$(cc) -g -I include -c src/main.cpp -o build/main.o

main: main.o aplicacao_transmissora.o camada_aplicacao_transmissora.o camada_enlace_transmissora.o meio_comunicacao.o camada_enlace_receptora.o camada_aplicacao_receptora.o aplicacao_receptora.o
	$(cc) build/main.o build/aplicacao_transmissora.o build/camada_aplicacao_transmissora.o build/camada_enlace_transmissora.o build/meio_comunicacao.o build/camada_enlace_receptora.o build/camada_aplicacao_receptora.o build/aplicacao_receptora.o -o main

clean:
	rm -f build/*.o all
	rm main
