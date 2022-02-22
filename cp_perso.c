#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[]){ //pour simuler une copie avec un cp different
  //ici un executable avec des parametres au lieu d'une commande bash CLASSIQUE.
  //!!! aux erreurs de segmentation de la memoire par acces sans effets de bord.
  FILE* fl=fopen(argv[1],"r");
  FILE* fl2=fopen(argv[2],"w+");
  while(!feof(fl)){
    fputc(fgetc(fl),fl2);
  }
  fclose(fl);
  fclose(fl2);
  return 0;
}
//MAIS pas general quand meme..///.//
