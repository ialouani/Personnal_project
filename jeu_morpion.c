#include<stdio.h>
#include<stdlib.h>
void afficher (char str[12][12]);
void afficher2 (char str[10][10]);
int on_peut_ecrire(char grille [9][9], int i, int j);
int existe_alignement(char grille [10][10]);
void afficher3(char grille[10][10]);//implementer une autre ca sera mieux ouf...
int nn_rempli(char grille[10][10]);
void jeu(char grille[10][10]);
int main(int argc, char *argv[])
{
  /* char str[12][12]={
{"grgz"},
{"fbvfs"},
{"bsb"}};
  printf("%c\n",str[2][1]);
  printf("%s\n",str[1]);
afficher (str); //on sinteresse a str seulement
  //afficher par exemple cette <<matrice>> : voir plus bas..(pour le moment).
  */
//On sinteresse a lapplication du commentaire plus haut a la construction
//de la grille..
/*char grille[10][10]={
  {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
  {"........."}};
  afficher2(grille);*/
//passage au commentaire ca a reussit.
//laffectation ?:voir ci-dessous.
/* char grille[10][10]={
  {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
  {"........."}};
grille[1][1]='x';
grille[4][4]='o';
afficher2(grille);*/
/*char grille[9][9]={
  {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
 {"........."},
  {"........."}};
grille[1][1]='x';
grille[4][4]='o';
printf("%d\n",on_peut_ecrire(grille,4,5));
printf("%d\n",on_peut_ecrire(grille,4,4));
printf("%d\n",on_peut_ecrire(grille,9,9));
printf("%d\n",on_peut_ecrire(grille,10,10));
printf("%d\n",on_peut_ecrire(grille,0,0));
printf("%d\n",on_peut_ecrire(grille,15,15));
printf("%d\n",on_peut_ecrire(grille,8,8));*/
//ca marche!
//printf("%d",1==1==3);
//attention (interpretation du commentaire ci-dessus)
char grille[10][10]={
  {"rrrrrrrrr"},
 {"rrrrrrrrr"},
 {"rrrrrrrrr"},
 {"rrrrrrrrr"},
 {"rrrrrrrrr"},
 {"rrrrrrrrr"},
 {"rrrrrrrrr"},
 {"rrrrrrrrr"},
  {"rrrrrrrrr"}};
//printf("%d\n",existe_alignement(grille));
//printf("%d\n",'.'!='.');bizarre /à linterpretation de existe_alignement
//attention= et ==;;
//IMPORTANT IMPORTANT IMPORTANT IMPORTANT :
/*char s='a';
grille[1][1]=s;
printf("%c",grille[1][1]);
*/
//changement juste existe alignement
//.
//.
//printf("%d","joueur1"=="joueur1/(|)2");
//;
//.
//printf("%d",nn_rempli(grille));
//.#quit;;
jeu(grille);
return 0;
}

//pointeur mais le POINTEUR en tant que telle-> nbr delements a indiquer.
//Remarque ci-dessus..

void afficher(char str[12][12])
{
  int i=0;
  while (i<=2)
    {
      printf("%s\n",str[i]);
      i++;
    }

}//pour str
//void afficher mais pour la grille du morpion


void afficher2 (char str[10][10])
{
  int i=0;
  while (i<=8)
    {
      printf("%s\n",str[i]);
      i++;
    }

}
//fonctions annexes.(mais a ne pas passer aux commentaires..)..
//laffectation(reponse):  oui!!!
//On a des elements fondamentales pour la construction de notre
//programme ensembliste.
 
//fonction preliminaire..
int on_peut_ecrire(char grille [9][9], int i, int j)
{
  if (grille[i][j]) return 1;
  return 0;
}

int existe_alignement(char grille [10][10])//Ce programme offre tt enfin presque.
{
  int i,j;
  for (i=0;i<=8;i++)
    {
      for (j=0;j<=8;j++)
	{
	  if (grille[i][j]==grille[i+1][j+1] && grille[i][j]==grille[i+2][j+2] && grille[i][j]!='r') return 1;
 if (grille[i][j]==grille[i+1][j] && grille[i][j]==grille[i+2][j] && grille[i][j]!='r') return 1;
 if (grille[i][j]==grille[i][j+1] && grille[i][j]==grille[i][j+2] && grille[i][j]!='r') return 1;
	}}
  return 0;
}//ouf..on laisse r.



void afficher3(char grille[10][10])
{
  int i=0;
  while(i<=8)
    {printf("%s\n",grille[i]);i++;}
}

int nn_rempli(char grille[10][10])
{
  int i,j;
  for (i=0;i<=8;i++)
    {
      for (j=0;j<=8;j++)
	{
	  if (grille[i][j]=='r') return 1;
	}
    }
  return 0;

}

void jeu(char grille[10][10])
{
  int i,j;
  char* j1="joueur1";
  char* j2="joueur2";
  char* jjj="joueur1";//choix arbitraire.
  afficher3(grille);
  while (nn_rempli(grille) && !existe_alignement(grille))
    {	
      if (jjj==j1)
	{
      printf("Joueur 1 Tapez le numero de la ligne:\t");
      scanf("%d",&i);
      printf("Joueur 1 Tapez le numero de la colonne:\t");
      scanf("%d",&j);
      if (grille[i][j]=='r') grille[i][j]='x';
        }
      else 
	{
printf("Joueur 2 Tapez le numero de la ligne:\t");
      scanf("%d",&i);
      printf("Joueur 2 Tapez le numero de la colonne:\t");
      scanf("%d",&j);
      if (grille[i][j]=='r') grille[i][j]='o';
	}
      afficher3(grille);
      if (jjj==j1) jjj=j2;
      else {jjj=j1;}
    }
  if (existe_alignement(grille))
    { 
  if (jjj==j1) {printf("Joueur 2 gagne. Fin de la partie\n");}
  else{printf("Joueur 1 gagne. Fin de la partie\n");}}
  else {printf("Match nul!\n");}
  
}

