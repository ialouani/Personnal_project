#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum type{valet=1,dame,roi};//le dernier est le plus fort.
enum valeur{trefle=1,coeur,pique,carreau};//le premier est le plus fort.

char* lbt[25]={};
char* lbt2[25]={};

typedef struct trefle{
  enum valeur trefle;
  union{
  char AS;
  int a2;int a3;int a4;int a5;int a6;int a7;int a8;int a9;int a10;}cartesT;
  enum type valet_trefle;
  enum type dame_trefle;
  enum type roi_trefle;
}trefle1;

typedef struct coeur{
  enum valeur coeur;
  union{
  char AS;
  int a2;int a3;int a4;int a5;int a6;int a7;int a8;int a9;int a10;}cartesCO;
  enum type valet_coeur;
  enum type dame_coeur;
  enum type roi_coeur;
}coeur2;

typedef struct pique{
  enum valeur pique;
  union{
  char AS;
  int a2;int a3;int a4;int a5;int a6;int a7;int a8;int a9;int a10;}cartesP;
  enum type valet_pique;
  enum type dame_pique;
  enum type roi_pique;
}pique3;

typedef struct carreau{
  enum valeur carreau;
  union{
  char AS;
  int a2;int a3;int a4;int a5;int a6;int a7;int a8;int a9;int a10;}cartesCC;
  enum type valet_carreau;
  enum type dame_carreau;
  enum type roi_carreau;
}carreau4;

typedef struct lejeu52{
  trefle1 trefle;
  coeur2 coeur;
  pique3 pique;
  carreau4 carreau;
}jeu_1;

typedef struct partie1{
  char* tableau1[13];
}PART1;
typedef struct partie2{
  char* tableau2[13];
}PART2;
typedef struct partie3{
  char* tableau3[13];
}PART3;
typedef struct partie4{
  char* tableau4[13];
}PART4;

int tab[53];
int tableau[5][14];

enum cc{Rtrefle=1,Dtrefle,Vtrefle,TREFLE10,TREFLE9,TREFLE8,TREFLE7,TREFLE6,TREFLE5,TREFLE4,TREFLE3,TREFLE2,AS_TREFLE,Rcoeur,Dcoeur,Vcoeur,COEUR10,COEUR9,COEUR8,COEUR7,COEUR6,COEUR5,COEUR4,COEUR3,COEUR2,AS_COEUR,Rpique,Dpique,Vpique,PIQUE10,PIQUE9,PIQUE8,PIQUE7,PIQUE6,PIQUE5,PIQUE4,PIQUE3,PIQUE2,AS_PIQUE,Rcarreau,Dcarreau,Vcarreau,CARREAU10,CARREAU9,CARREAU8,CARREAU7,CARREAU6,CARREAU5,CARREAU4,CARREAU3,CARREAU2,AS_CARREAU};
//par ordre decroissant.


void melanger_cartes_52();
int occurence(int elmt, int tab[53]);
int trouvable(int tab[53],int elmt);
void adaptation();//affichage avec piquedame..
void affiche();
int conversion(char* a);
int compare_2_cartes(enum cc carte1, enum cc carte2);
enum cc conversion_2(char *a);
void affiche2();
void affiche3();
void afficher_tab(int t[27]);
void jeu_final();


int main(int argc, char *argv[])
{
  //melanger_cartes_52() //en enlevant les autres commentaires..
  //test:autre..
  //adaptation();//matrice delements.
  //test:::affiche aleatoire vraies cartes
  // affiche();ca a marche mais cest long..!
  //affiche();
  //affiche();(autres verifications).
  //affiche(); ..
  jeu_final();
 return 0;
}

void melanger_cartes_52()
{
  //printf("INITIALISATION (attendez svp)\n");
  trefle1 trefle_13;
  coeur2 coeur_13;
  pique3 pique_13;
  carreau4 carreau_13;
  int j=0;
  while (j<52){
    tab[j]=j+1;
    j++;
  }
  //melange suivant random:
   for (int l=0;l<=51;l++){
    int aleo=rand()%(52)+1;
    tab[l]=aleo;}
   /*for (int b=0;b<=51;b++){
     printf("%d\n",tab[b]);}
     printf("------------------\n");*/
   //deuxieme partie:stockage dans un tableau les numeros index qui se repetent:
  int i;
  int x=0;
  int m;
  int tab2[53]={};
  int tab3[53]={};
  int tab4[53]={};
  for (i=0;i<=51;i++)
    {if (occurence(tab[i],tab)>1) {tab2[x]=tab[i];tab3[x]=i;x++;}}
  /*for (int c=0;c<x;c++){
    printf("%d\n",tab2[c]);}
  printf("------------------\n");
for (int d=0;d<x;d++){
    printf("%d\n",tab3[d]);}
    printf("------------------\n");*/
  //le tab2 contient les numeros qui se repetent et pour index tab3.

  //construction d'un tableau des elements qui se trouvent pas dans tab
  //vous allez le devinez cest le tab4!
  int f=0;
  for (int n=1;n<=52;n++){
    if (!trouvable(tab,n)) {tab4[f]=n;f++;}}
  /*for (int e=0;e<f;e++){
    printf("%d\n",tab4[e]);}
    printf("------------------\n");*/
  //tab4 contient desormais les elements entre 1 et 52 introuvables dans tab

  //formalisation:
  int u=0;
  for (int g=0;g<x;g++){
    int a=tab3[g];
    if (occurence(tab[a],tab)>1){
    tab[a]=tab4[u];
    u++;}
  }
  //Attention: verification:
  /*int s;
  for (s=0;s<=51;s++){
    printf("%d\n",tab[s]);}
  printf("%d\n",s);
  //verification plus forte:
  printf("--------------\n");
  for (m=0;m<=51;m++){
    printf("%d\n",occurence(tab[m],tab));}
  printf("-------------------\n");
  printf("Suite\n");*/
}
 
int occurence(int elmt, int tab[53])
{
  int c=0;
  for (int i=0;i<=51;i++)
    {if (tab[i]==elmt) c+=1;}
  return c;
}

 int trouvable(int tab[53],int elmt)
 {
   for (int k=0;k<=51;k++)
     {if (tab[k]==elmt) return 1;}
   return 0;
 }

void adaptation()
{
  melanger_cartes_52();
  int tableau1[53]={1,2,3,4,5,6,7,8,9,10,11,12,13};
  int tableau2[53]={14,15,16,17,18,19,20,21,22,23,24,25,26};
  int tableau3[53]={27,28,29,30,31,32,33,34,35,36,37,38,39};
  int tableau4[53]={40,41,42,43,44,45,46,47,48,49,50,51,52};
  for (int z=0;z<=51;z++){
    int a=tab[z];
    if (trouvable(tableau1,a)){
      tableau[0][z]=a; 
      printf("%d\n",tableau[0][z]);}
    else if (trouvable(tableau2,a)) {
      tableau[1][z-14]=a; 
      printf("%d\n",tableau[1][z-14]);}
    else if (trouvable(tableau3,a)) {
      tableau[2][z-27]=a; 
      printf("%d\n",tableau[2][z-27]);}
    else if (trouvable(tableau4,a)){
      tableau[3][z-40]=a; 
      printf("%d\n",tableau[3][z-40]);}
  }
  printf("--------------------------\n");
}


struct TREFLE{
  char* AS;
  char* a2;char* a3;char* a4;char* a5;char* a6;char* a7;char* a8;char* a9;char* a10;
  char* Valet;char* Dame;char* Roi;
};

enum cara{AS,a2,a3,a4,a5,a6,a7,a8,a9,a10,Valet,Dame,ROI};

struct TREFLE trefle_r={"AS_TREFLE","TREFLE2","TREFLE3","TREFLE4","TREFLE5","TREFLE6","TREFLE7","TREFLE8","TREFLE9","TREFLE10","Vtrefle","Dtrefle","Rtrefle"};

struct COEUR{
  char* AS;
  char* a2;char* a3;char* a4;char* a5;char* a6;char* a7;char* a8;char* a9;char* a10;
  char* Valet;char* Dame;char* Roi;
};

struct COEUR coeur_r={"AS_COEUR","COEUR2","COEUR3","4COEUR","COEUR5","COEUR6","COEUR7","COEUR8","COEUR9","COEUR10","Vcoeur","Dcoeur","Rcoeur"};

struct PIQUE{
  char* AS;
  char* a2;char* a3;char* a4;char* a5;char* a6;char* a7;char* a8;char* a9;char* a10;
  char* Valet;char* Dame;char* Roi;
};

struct PIQUE pique_r={"AS_PIQUE","PIQUE2","PIQUE3","PIQUE4","PIQUE5","PIQUE6","PIQUE7","PIQUE8","PIQUE9","PIQUE10","Vpique","Dpique","Rpique"};

struct CARREAU{
  char* AS;
  char* a2;char* a3;char* a4;char* a5;char* a6;char* a7;char* a8;char* a9;char* a10;
  char* Valet;char* Dame;char* Roi;
};

struct CARREAU carreau_r={"AS_CARREAU","CARREAU2","CARREAU3","CARREAU4","CARREAU5","CARREAU6","CARREAU7","CARREAU8","CARREAU9","CARREAU10","Vcarreau","Dcarreau","Rcarreau"};


void affiche()
{
  adaptation();
  int ct=0;
  for (int r=0;r<=51;r++){
       int a =tab[r];
       if (a==1) printf("%s\n",trefle_r.AS);
      if (a==2) printf("%s\n",trefle_r.a2);
      if (a==3) printf("%s\n",trefle_r.a3);
      if (a==4) printf("%s\n",trefle_r.a4);
      if (a==5) printf("%s\n",trefle_r.a5);
      if (a==6) printf("%s\n",trefle_r.a6);
      if (a==7) printf("%s\n",trefle_r.a7);
      if (a==8) printf("%s\n",trefle_r.a8);
      if (a==9) printf("%s\n",trefle_r.a9);
      if (a==10) printf("%s\n",trefle_r.a10);
      if (a==11) printf("%s\n",trefle_r.Valet);
      if (a==12) printf("%s\n",trefle_r.Dame);
      if (a==13) printf("%s\n",trefle_r.Roi);  
      if (a==14) printf("%s\n",coeur_r.AS);
      if (a==15) printf("%s\n",coeur_r.a2);
      if (a==16) printf("%s\n",coeur_r.a3);
      if (a==17) printf("%s\n",coeur_r.a4);
      if (a==18) printf("%s\n",coeur_r.a5);
      if (a==19) printf("%s\n",coeur_r.a6);
      if (a==20) printf("%s\n",coeur_r.a7);
      if (a==21) printf("%s\n",coeur_r.a8);
      if (a==22) printf("%s\n",coeur_r.a9);
      if (a==23) printf("%s\n",coeur_r.a10);
      if (a==24) printf("%s\n",coeur_r.Valet);
      if (a==25) printf("%s\n",coeur_r.Dame);
      if (a==26) printf("%s\n",coeur_r.Roi);
      if (a==27) printf("%s\n",pique_r.AS);
      if (a==28) printf("%s\n",pique_r.a2);
      if (a==29) printf("%s\n",pique_r.a3);
      if (a==30) printf("%s\n",pique_r.a4);
      if (a==31) printf("%s\n",pique_r.a5);
      if (a==32) printf("%s\n",pique_r.a6);
      if (a==33) printf("%s\n",pique_r.a7);
      if (a==34) printf("%s\n",pique_r.a8);
      if (a==35) printf("%s\n",pique_r.a9);
      if (a==36) printf("%s\n",pique_r.a10);
      if (a==37) printf("%s\n",pique_r.Valet);
      if (a==38) printf("%s\n",pique_r.Dame);
      if (a==39) printf("%s\n",pique_r.Roi);
      if (a==40) printf("%s\n",carreau_r.AS);
      if (a==41) printf("%s\n",carreau_r.a2);
      if (a==42) printf("%s\n",carreau_r.a3);
      if (a==43) printf("%s\n",carreau_r.a4);
      if (a==44) printf("%s\n",carreau_r.a5);
      if (a==45) printf("%s\n",carreau_r.a6);
      if (a==46) printf("%s\n",carreau_r.a7);
      if (a==47) printf("%s\n",carreau_r.a8);
      if (a==48) printf("%s\n",carreau_r.a9);
      if (a==49) printf("%s\n",carreau_r.a10);
      if (a==50) printf("%s\n",carreau_r.Valet);
      if (a==51) printf("%s\n",carreau_r.Dame);
      if (a==52) printf("%s\n",carreau_r.Roi);
      ct+=1;
    }
  printf("_________%d\n---------------\n\n",ct);
}

struct cartee{
  int a;
}CARTE={43};//for example...

/*struct TREFLE{
  char* AS;
  char* a2;char* a3;char* a4;char* a5;char* a6;char* a7;char* a8;char* a9;char* a10;
  char* Valet;char* Dame;char* Roi;
  };*/ // on a copié pour laide seulement; je le précise.
/*struct TREFLE trefle_r={"AS_TREFLE","2_TREFLE","3_TREFLE","4_TREFLE","5_TREFLE","6_TREFLE","7_TREFLE","8_TREFLE","9_TREFLE","10_TREFLE","Vtrefle","Dtrefle","Rtrefle"};*/ //et de même.

int conversion(char* a)
{
if (a=="AS_TREFLE") return 1;
if (a=="TREFLE2") return 2;
if (a=="TREFLE3") return 3;
if (a=="TREFLE4") return 4;
if (a=="TREFLE5") return 5;
if (a=="TREFLE6") return 6;
if (a=="TREFLE7") return 7;
if (a=="TREFLE8") return 8;
if (a=="TREFLE9") return 9;
if (a=="TREFLE10") return 10;
if (a=="Vtrefle") return 11;
if (a=="Dtrefle") return 12;
if (a=="Rtrefle") return 13;
if (a=="AS_COEUR") return 14;
if (a=="COEUR2") return 15;
if (a=="COEUR3") return 16;
if (a=="COEUR4") return 17;
if (a=="COEUR5") return 18;
if (a=="COEUR6") return 19;
if (a=="COEUR7") return 20;
if (a=="COEUR8") return 21;
if (a=="COEUR9") return 22;
if (a=="COEUR10") return 23;
if (a=="Vcoeur") return 24;
if (a=="Dcoeur") return 25;
if (a=="Rcoeur") return 26;
if (a=="AS_PIQUE") return 27;
if (a=="PIQUE2") return 28;
if (a=="PIQUE3") return 29;
if (a=="PIQUE4") return 30;
if (a=="PIQUE5") return 31;
if (a=="PIQUE6") return 32;
if (a=="PIQUE7") return 33;
if (a=="PIQUE8") return 34;
if (a=="PIQUE9") return 35;
if (a=="PIQUE10") return 36;
if (a=="Vpique") return 37;
if (a=="Dpique") return 38;
if (a=="Rpique") return 39;
if (a=="AS_CARREAU") return 40;
if (a=="CARREAU2") return 41;
if (a=="CARREAU3") return 42;
if (a=="CARREAU4") return 43;
if (a=="CARREAU5") return 44;
if (a=="CARREAU6") return 45;
if (a=="CARREAU7") return 46;
if (a=="CARREAU8") return 47;
if (a=="CARREAU9") return 48;
if (a=="CARREAU10") return 49;
if (a=="Vcarreau") return 50;
if (a=="Dcarreau") return 51;
if (a=="Rcarreau") return 52;
}

/*enum cc{Rtrefle=1,Dtrefle,Vtrefle,TREFLE10,TREFLE9,TREFLE8,TREFLE7,TREFLE6,TREFLE5,TREFLE4,TREFLE3,TREFLE2,AS_TREFLE,Rcoeur,Dcoeur,Vcoeur,COEUR10,COEUR9,COEUR8,COEUR7,COEUR6,COEUR5,COEUR4,COEUR3,COEUR2,AS_COEUR,Rpique,Dpique,Vpique,PIQUE10,PIQUE9,PIQUE8,PIQUE7,PIQUE6,PIQUE5,PIQUE4,PIQUE3,PIQUE2,AS_PIQUE,Rcarreau,Dcarreau,Vcarreau,CARREAU10,CARREAU9,CARREAU8,CARREAU7,CARREAU6,CARREAU5,CARREAU4,CARREAU3,CARREAU2,AS_CARREAU};
//10_TREFLE par exemple ne saccepte pas et meme les strings!
*///pour éviter les éventuelles intéractions.


int compare_2_cartes(enum cc carte1, enum cc carte2)//1 si carte 1 puissante
{
  if (carte1<carte2) return 1;
  return 0;
}

enum cc conversion_2(char *a)
{
if (a=="AS_TREFLE") return 13;
if (a=="TREFLE2") return 12;
if (a=="TREFLE3") return 11;
if (a=="TREFLE4") return 10;
if (a=="TREFLE5") return 9;
if (a=="TREFLE6") return 8;
if (a=="TREFLE7") return 7;
if (a=="TREFLE8") return 6;
if (a=="TREFLE9") return 5;
if (a=="TREFLE10") return 4;
if (a=="Vtrefle") return 3;
if (a=="Dtrefle") return 2;
if (a=="Rtrefle") return 1;
if (a=="AS_COEUR") return 26;
if (a=="COEUR2") return 25;
if (a=="COEUR3") return 24;
if (a=="COEUR4") return 23;
if (a=="COEUR5") return 22;
if (a=="COEUR6") return 21;
if (a=="COEUR7") return 20;
if (a=="COEUR8") return 19;
if (a=="COEUR9") return 18;
if (a=="COEUR10") return 17;
if (a=="Vcoeur") return 16;
if (a=="Dcoeur") return 15;
if (a=="Rcoeur") return 14;
if (a=="AS_PIQUE") return 39;
if (a=="PIQUE2") return 38;
if (a=="PIQUE3") return 37;
if (a=="PIQUE4") return 36;
if (a=="PIQUE5") return 35;
if (a=="PIQUE6") return 34;
if (a=="PIQUE7") return 33;
if (a=="PIQUE8") return 32;
if (a=="PIQUE9") return 31;
if (a=="PIQUE10") return 30;
if (a=="Vpique") return 29;
if (a=="Dpique") return 28;
if (a=="Rpique") return 27;
if (a=="AS_CARREAU") return 52;
if (a=="CARREAU2") return 51;
if (a=="CARREAU3") return 50;
if (a=="CARREAU4") return 49;
if (a=="CARREAU5") return 48;
if (a=="CARREAU6") return 47;
if (a=="CARREAU7") return 46;
if (a=="CARREAU8") return 45;
if (a=="CARREAU9") return 44;
if (a=="CARREAU10") return 43;
if (a=="Vcarreau") return 42;
if (a=="Dcarreau") return 41;
if (a=="Rcarreau") return 40;
}


void affiche2(){
  int i=0;
  for (int r=0;r<=25;r++){
      int a =tab[r];
      if (a==1) {printf("%s\n",trefle_r.AS);lbt[i]=trefle_r.AS;}
      if (a==2) {printf("%s\n",trefle_r.a2);lbt[i]=trefle_r.a2;}
      if (a==3) {printf("%s\n",trefle_r.a3);lbt[i]=trefle_r.a3;}
      if (a==4) {printf("%s\n",trefle_r.a4);lbt[i]=trefle_r.a4;}
      if (a==5) {printf("%s\n",trefle_r.a5);lbt[i]=trefle_r.a5;}
      if (a==6) {printf("%s\n",trefle_r.a6);lbt[i]=trefle_r.a6;}
      if (a==7) {printf("%s\n",trefle_r.a7);lbt[i]=trefle_r.a7;}
      if (a==8) {printf("%s\n",trefle_r.a8);lbt[i]=trefle_r.a8;}
      if (a==9) {printf("%s\n",trefle_r.a9);lbt[i]=trefle_r.a9;}
      if (a==10) {printf("%s\n",trefle_r.a10);lbt[i]=trefle_r.a10;}
      if (a==11) {printf("%s\n",trefle_r.Valet);lbt[i]=trefle_r.Valet;}
      if (a==12) {printf("%s\n",trefle_r.Dame);lbt[i]=trefle_r.Dame;}
      if (a==13) {printf("%s\n",trefle_r.Roi);lbt[i]=trefle_r.Roi;} 
      if (a==14) {printf("%s\n",coeur_r.AS);lbt[i]=coeur_r.AS;}
      if (a==15) {printf("%s\n",coeur_r.a2);lbt[i]=coeur_r.a2;}
      if (a==16) {printf("%s\n",coeur_r.a3);lbt[i]=coeur_r.a3;}
      if (a==17) {printf("%s\n",coeur_r.a4);lbt[i]=coeur_r.a4;}
      if (a==18) {printf("%s\n",coeur_r.a5);lbt[i]=coeur_r.a5;}
      if (a==19) {printf("%s\n",coeur_r.a6);lbt[i]=coeur_r.a6;}
      if (a==20) {printf("%s\n",coeur_r.a7);lbt[i]=coeur_r.a7;}
      if (a==21) {printf("%s\n",coeur_r.a8);lbt[i]=coeur_r.a8;}
      if (a==22) {printf("%s\n",coeur_r.a9);lbt[i]=coeur_r.a9;}
      if (a==23) {printf("%s\n",coeur_r.a10);lbt[i]=coeur_r.a10;}
      if (a==24) {printf("%s\n",coeur_r.Valet);lbt[i]=coeur_r.Valet;}
      if (a==25) {printf("%s\n",coeur_r.Dame);lbt[i]=coeur_r.Dame;}
      if (a==26) {printf("%s\n",coeur_r.Roi);lbt[i]=coeur_r.Roi;}
      if (a==27) {printf("%s\n",pique_r.AS);lbt[i]=pique_r.AS;}
      if (a==28) {printf("%s\n",pique_r.a2);lbt[i]=pique_r.a2;}
      if (a==29) {printf("%s\n",pique_r.a3);lbt[i]=pique_r.a3;}
      if (a==30) {printf("%s\n",pique_r.a4);lbt[i]=pique_r.a4;}
      if (a==31) {printf("%s\n",pique_r.a5);lbt[i]=pique_r.a5;}
      if (a==32) {printf("%s\n",pique_r.a6);lbt[i]=pique_r.a6;}
      if (a==33) {printf("%s\n",pique_r.a7);lbt[i]=trefle_r.a7;}
      if (a==34) {printf("%s\n",pique_r.a8);lbt[i]=trefle_r.a8;}
      if (a==35) {printf("%s\n",pique_r.a9);lbt[i]=pique_r.a9;}
      if (a==36) {printf("%s\n",pique_r.a10);lbt[i]=pique_r.a10;}
      if (a==37) {printf("%s\n",pique_r.Valet);lbt[i]=pique_r.Valet;}
      if (a==38) {printf("%s\n",pique_r.Dame);lbt[i]=pique_r.Dame;}
      if (a==39) {printf("%s\n",pique_r.Roi);lbt[i]=pique_r.Roi;}
      if (a==40) {printf("%s\n",carreau_r.AS);lbt[i]=carreau_r.AS;}
      if (a==41) {printf("%s\n",carreau_r.a2);lbt[i]=carreau_r.a2;}
      if (a==42) {printf("%s\n",carreau_r.a3);lbt[i]=carreau_r.a3;}
      if (a==43) {printf("%s\n",carreau_r.a4);lbt[i]=carreau_r.a4;}
      if (a==44) {printf("%s\n",carreau_r.a5);lbt[i]=carreau_r.a5;}
      if (a==45) {printf("%s\n",carreau_r.a6);lbt[i]=carreau_r.a6;}
      if (a==46) {printf("%s\n",carreau_r.a7);lbt[i]=carreau_r.a7;}
      if (a==47) {printf("%s\n",carreau_r.a8);lbt[i]=carreau_r.a8;}
      if (a==48) {printf("%s\n",carreau_r.a9);lbt[i]=carreau_r.a9;}
      if (a==49) {printf("%s\n",carreau_r.a10);lbt[i]=carreau_r.a10;}
if (a==50) {printf("%s\n",carreau_r.Valet);lbt[i]=carreau_r.Valet;}
if (a==51) {printf("%s\n",carreau_r.Dame);lbt[i]=carreau_r.Dame;}
if (a==52) {printf("%s\n",carreau_r.Roi);lbt[i]=carreau_r.Roi;}
 i++;
}
}

void affiche3(){
  int i=0;
  for (int r=26;r<=51;r++){
      int a =tab[r];
      if (a==1) {printf("%s\n",trefle_r.AS);lbt2[i]=trefle_r.AS;}
      if (a==2) {printf("%s\n",trefle_r.a2);lbt2[i]=trefle_r.a2;}
      if (a==3) {printf("%s\n",trefle_r.a3);lbt2[i]=trefle_r.a3;}
      if (a==4) {printf("%s\n",trefle_r.a4);lbt2[i]=trefle_r.a4;}
      if (a==5) {printf("%s\n",trefle_r.a5);lbt2[i]=trefle_r.a5;}
      if (a==6) {printf("%s\n",trefle_r.a6);lbt2[i]=trefle_r.a6;}
      if (a==7) {printf("%s\n",trefle_r.a7);lbt2[i]=trefle_r.a7;}
      if (a==8) {printf("%s\n",trefle_r.a8);lbt2[i]=trefle_r.a8;}
      if (a==9) {printf("%s\n",trefle_r.a9);lbt2[i]=trefle_r.a9;}
      if (a==10) {printf("%s\n",trefle_r.a10);lbt2[i]=trefle_r.a10;}
      if (a==11) {printf("%s\n",trefle_r.Valet);lbt2[i]=trefle_r.Valet;}
      if (a==12) {printf("%s\n",trefle_r.Dame);lbt2[i]=trefle_r.Dame;}
      if (a==13) {printf("%s\n",trefle_r.Roi);lbt2[i]=trefle_r.Roi;} 
      if (a==14) {printf("%s\n",coeur_r.AS);lbt2[i]=coeur_r.AS;}
      if (a==15) {printf("%s\n",coeur_r.a2);lbt2[i]=coeur_r.a2;}
      if (a==16) {printf("%s\n",coeur_r.a3);lbt2[i]=coeur_r.a3;}
      if (a==17) {printf("%s\n",coeur_r.a4);lbt2[i]=coeur_r.a4;}
      if (a==18) {printf("%s\n",coeur_r.a5);lbt2[i]=coeur_r.a5;}
      if (a==19) {printf("%s\n",coeur_r.a6);lbt2[i]=coeur_r.a6;}
      if (a==20) {printf("%s\n",coeur_r.a7);lbt2[i]=coeur_r.a7;}
      if (a==21) {printf("%s\n",coeur_r.a8);lbt2[i]=coeur_r.a8;}
      if (a==22) {printf("%s\n",coeur_r.a9);lbt2[i]=coeur_r.a9;}
      if (a==23) {printf("%s\n",coeur_r.a10);lbt2[i]=coeur_r.a10;}
      if (a==24) {printf("%s\n",coeur_r.Valet);lbt2[i]=coeur_r.Valet;}
      if (a==25) {printf("%s\n",coeur_r.Dame);lbt2[i]=coeur_r.Dame;}
      if (a==26) {printf("%s\n",coeur_r.Roi);lbt2[i]=coeur_r.Roi;}
      if (a==27) {printf("%s\n",pique_r.AS);lbt2[i]=pique_r.AS;}
      if (a==28) {printf("%s\n",pique_r.a2);lbt2[i]=pique_r.a2;}
      if (a==29) {printf("%s\n",pique_r.a3);lbt2[i]=pique_r.a3;}
      if (a==30) {printf("%s\n",pique_r.a4);lbt2[i]=pique_r.a4;}
      if (a==31) {printf("%s\n",pique_r.a5);lbt2[i]=pique_r.a5;}
      if (a==32) {printf("%s\n",pique_r.a6);lbt2[i]=pique_r.a6;}
      if (a==33) {printf("%s\n",pique_r.a7);lbt2[i]=trefle_r.a7;}
      if (a==34) {printf("%s\n",pique_r.a8);lbt2[i]=trefle_r.a8;}
      if (a==35) {printf("%s\n",pique_r.a9);lbt2[i]=pique_r.a9;}
      if (a==36) {printf("%s\n",pique_r.a10);lbt2[i]=pique_r.a10;}
      if (a==37) {printf("%s\n",pique_r.Valet);lbt2[i]=pique_r.Valet;}
      if (a==38) {printf("%s\n",pique_r.Dame);lbt2[i]=pique_r.Dame;}
      if (a==39) {printf("%s\n",pique_r.Roi);lbt2[i]=pique_r.Roi;}
      if (a==40) {printf("%s\n",carreau_r.AS);lbt2[i]=carreau_r.AS;}
      if (a==41) {printf("%s\n",carreau_r.a2);lbt2[i]=carreau_r.a2;}
      if (a==42) {printf("%s\n",carreau_r.a3);lbt2[i]=carreau_r.a3;}
      if (a==43) {printf("%s\n",carreau_r.a4);lbt2[i]=carreau_r.a4;}
      if (a==44) {printf("%s\n",carreau_r.a5);lbt2[i]=carreau_r.a5;}
      if (a==45) {printf("%s\n",carreau_r.a6);lbt2[i]=carreau_r.a6;}
      if (a==46) {printf("%s\n",carreau_r.a7);lbt2[i]=carreau_r.a7;}
      if (a==47) {printf("%s\n",carreau_r.a8);lbt2[i]=carreau_r.a8;}
      if (a==48) {printf("%s\n",carreau_r.a9);lbt2[i]=carreau_r.a9;}
      if (a==49) {printf("%s\n",carreau_r.a10);lbt2[i]=carreau_r.a10;}
if (a==50) {printf("%s\n",carreau_r.Valet);lbt2[i]=carreau_r.Valet;}
if (a==51) {printf("%s\n",carreau_r.Dame);lbt2[i]=carreau_r.Dame;}
if (a==52) {printf("%s\n",carreau_r.Roi);lbt2[i]=carreau_r.Roi;}
 i++;
}
}

/*void melanger_cartes_52();
int occurence(int elmt, int tab[53]);
int trouvable(int tab[53],int elmt);
void adaptation();//affichage avec piquedame..
void affiche();
int conversion(char* a);
int compare_2_cartes(enum cc carte1, enum cc carte2);
enum cc conversion_2(char *a);
void affiche2();
void affiche3();*/

void jeu_final()
{
  affiche();
  printf("debut de la partie:\n");
  printf("\t\tCartes du joueur1 :\n");
  affiche2();
  printf("\t\tCartes du joueur2 :\n");
  affiche3();
  printf("------------------------\n\n");
  printf("------------------------\n\n\n");
  char* j1="joueur1";
  char* j2="joueur2";
  int a1=26;
  int a2=26;
  int k=0;
  int h=0;
  int t1[27]={};
  int t2[27]={};
  int i=0;
  while (a1 && a2){
    int d;
    printf("Tirez une carte de votre paquet %s : \t",j1);
    scanf("%d",&d);//d doit etre entre 0 et 25.
    if (!trouvable(t1,d)){
    printf("\nLa carte en terme d'indice dans lbt est:%d",d);
    printf("\ndonc elle correspond à : %s\n\n",lbt[d]);
    t1[k]=d;
    k++;}
    else {
    printf("Recommencez svp: SAUF:(vu les 0 nn inquietude)\t");
    afficher_tab(t1);
    scanf("%d",&d);
    printf("\nLa carte en terme d'indice dans lbt est:%d",d);
    printf("\ndonc elle correspond à : %s\n\n",lbt[d]);
    t1[k]=d;
    k++;}
    int p;
    printf("Tirez une carte de votre paquet %s : \t",j2);
    scanf("%d",&p);//d doit etre entre 0 et 25.
    if (!trouvable(t2,p)){
    printf("\nLa carte en terme d'indice dans lbt2 est:%d",p);
    printf("\ndonc elle correspond à : %s\n\n",lbt2[p]);
    t2[h]=p;
    h++;}
    else {
    printf("Recommencez svp: SAUF:(ca peut etre une erreur)\t");
    afficher_tab(t2);
    scanf("%d",&p);
    printf("\nLa carte en terme d'indice dans lbt2 est:%d",p);
    printf("\ndonc elle correspond à : %s\n\n",lbt2[p]);
    t2[h]=p;
    h++;}
    int b1=conversion_2(lbt[d]);
    int b2=conversion_2(lbt2[p]);
    int s=compare_2_cartes(b1,b2);
    if (s==1) {printf("%s est la plus forte\n %s la recupere\n",lbt[d],"joueur1");a2--;}
	if (s==0){
	  printf("%s est le plus forte\n %s la recupere\n",lbt2[p],"joueur2");a1--;}
  }
  if (a1==0) printf("VAINQUEUR: joueur2\n-fin de la partie.\n");
  if (a2==0) printf("VAINQUEUR: joueur1\n-fin de la partie.\n");
}
  
//Fin du jeu et fin du TP.

void afficher_tab(int t[27])
{
  printf("{\n");
  for (int i=0;i<=26;i++)
    {if (0<=t[i]<=25) printf("%d",t[i]);}
  printf("}");
}


