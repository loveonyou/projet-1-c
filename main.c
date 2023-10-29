#include "fonction/menu/menu.h"
#include "fonction/verification/verification.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  bool quit = false;
  int choix, verif;
  int GlobalJour = 0, GlobalMois = 0, GlobalAnne = 0, GlobalNumeroOrdre = 0,
      GlobalNumeroVerification = 0;
  int GlobalInitial1, GlobalInitial2;
  verif = MainVerification(&GlobalJour, &GlobalMois, &GlobalAnne,
                           &GlobalInitial1, &GlobalInitial2, &GlobalNumeroOrdre,
                           &GlobalNumeroVerification);
  verif = 1;
  if (verif == 1) {
    Menu(&GlobalJour, &GlobalMois, &GlobalAnne, &GlobalInitial1,
         &GlobalInitial2, &GlobalNumeroOrdre);
  } else {
    printf("code invalide");
  }

  return 0;
}