#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char menu[] = "[1] : Afficher les informations \n[2]: Changer mot de passe "
              "\n[3]: quittez\nchoix : ";
static void _AfficherInfo(int *GlobalJour, int *GlobalMois, int *GlobalAnne,
                          int *GlobalInitial1, int *GlobalInitial2,
                          int *GlobalNumeroOrdre) {
  char initial1 = (char)*GlobalInitial1;
  char initial2 = (char)*GlobalInitial2;
  char sexe[10];
  if (*GlobalNumeroOrdre % 2 == 0) {
    strcpy(sexe, "femme");
  } else {
    strcpy(sexe, "homme");
  }
  printf("Information\nDate de naissance : %i/%i/%i\nInitiales : %c%c\nsexe : "
         "%s\n",
         *GlobalJour, *GlobalMois, *GlobalAnne, initial1, initial2, sexe);
}
static void _motdepasse() {
  char MotDePasse[] = "198296";
  char NewPass[100], MotDePasseTempo[100];
  printf("veillez entrer votre ancien mot de passe :");
  scanf("%s", MotDePasseTempo);

  if (strcmp(MotDePasse, MotDePasseTempo) == 0) {
    printf("veillez entrer votre nouveau mot de passe :");
    scanf("%s", NewPass);
    printf("veillez confirmer votre nouveau mot de passe :");
    scanf("%s", MotDePasseTempo);
    if (strcmp(NewPass, MotDePasseTempo) == 0) {
      if (strlen(NewPass) <= 6) {
        printf("Mot de passe correct\n");
        strcpy(MotDePasse, NewPass);
      } else {
        printf("Mot de passe est superieur a 6 carractéres\n");
      }
    }
  } else {
    printf("votre mot de passe est faux .\n");
  }
}
void Menu(int *GlobalJour, int *GlobalMois, int *GlobalAnne,
          int *GlobalInitial1, int *GlobalInitial2, int *GlobalNumeroOrdre) {
  int choix, choix_quitte, boucle = 0;

  while (boucle == 0) {
    printf("%s", menu);
    scanf("%d", &choix);

    if (choix == 1) {
      _AfficherInfo(GlobalJour, GlobalMois, GlobalAnne, GlobalInitial1,
                    GlobalInitial2, GlobalNumeroOrdre);
    } else if (choix == 2) {
      _motdepasse();
    } else if (choix == 3) {
      printf("Vous voulez vous quitter se programme\n[1] : quitter\n[0] : "
             "rester\nchoix : ");
      scanf("%d", &choix_quitte);
      if (choix_quitte == 1) {
        boucle = 1;
      }
    }
  }
}
