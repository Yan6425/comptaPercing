exe: fonctions.o fonctionsDb.o main.o
	@echo "Compilation de l'exécutable."
	gcc fonctions.o fonctionsDb.o main.o -o comptaPercing.exe

sansDb: fonctions.o main.o
	@echo "Compilation sans db."
	gcc fonctions.o main.o -o sansDb.exe

test.o: main.c fonctions.h
	gcc -c -Wall test.c -o test.o

fonctions.o: fonctions.c fonctions.h
	@echo "Compilation de fonctions."
	gcc -c -Wall fonctions.c -o fonctions.o

fonctionsDb.o: fonctionsDb.c fonctions.h
	@echo "Compilation de fonctionsDb."
	gcc -c -Wall fonctionsDb.c -o fonctionsDb.o

main.o: main.c fonctions.h
	@echo "Compilation du main."
	gcc -c -Wall main.c -o main.o

clean:
	@echo "J'ai tout effacé."
	rm -f *.o
