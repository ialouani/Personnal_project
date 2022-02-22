LDFLAGS=
VAR=$(echo $(pwd))
CC= cc
CPPFLAGS= -std=c99 -g3
cp_v2_plus: cp_perso.c
	$(CC) $< -o $@ #\FF a la fin qui cree un bug d'encodage de characteres
#dont la modification risque de deteriorer completement le fichier.
lancement_MORPION0: ./jeu_morpion.c
	gcc -std=c99 jeu_morpion.c -o $@ ${LDFLAGS}
lancement__DAME_DE_PIQUE0: ./bataille__dame_de_pique.c
	gcc -std=c99 $^ -o $@ ${LDGAFS}
%.o: %.c
	$(CC) -c -std=c99 $< -o $@
lancement_MORPION0_v2: jeu_morpion.o 
	gcc ${CPPFLAGS} jeu_morpion.o -o lancement_MORPION0_v2
lancement_jeu_morpion=lancement_MORPION0_v2
lancement0: ${lancement_jeu_morpion}
Morpion: lancement0
	@for e in ${lancement_jeu_morpion}; do \
	echo $${e}; ./$${e}; \
	done
lancement__DAME_DE_PIQUE0___v2: bataille__dame_de_pique.c
	$(CC) $(CPPFLAGS) $^ -o $@
Bataille_52=lancement__DAME_DE_PIQUE0___v2
lancement__52: ${Bataille_52}
jeu_52CARTES: lancement__52
	@for e in ${Bataille_52};do \
	echo $${e}; ./$${e}; \
	done 
clean:
	rm -f lancement_MORPION0 lancement__DAME_DE_PIQUE0 *.o *.c~ lancement_MORPION0_v2 lancement__DAME_DE_PIQUE0___v2 cp_v2_plus
