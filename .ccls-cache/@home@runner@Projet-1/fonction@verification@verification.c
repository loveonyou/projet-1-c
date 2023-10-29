#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static bool _bissextile(int *GlobalAnne) {
  if ((*GlobalAnne % 4 == 0 && *GlobalAnne % 100 != 0) ||
      (*GlobalAnne % 400 == 0)) {
    return true;
  } else {
    return false;
  }
}
static void _gestion_erreur(bool DateCorrect, bool InitialsCorrect) {

  if (DateCorrect == false) {
    printf("\x1b[31m");
    printf("\n[INFO][-] Date invalid.\n");
    printf("\x1b[0m");
  }
  if (InitialsCorrect == false) {
    printf("\x1b[31m");
    printf("\n[INFO][-] Initials invalid.\n");
    printf("\x1b[0m");
  }
}
static bool _check_date(int *GlobalJour, int *GlobalMois, int *GlobalAnne) {
  if (*GlobalMois <= 12 && *GlobalMois > 0) {
    if (_bissextile(GlobalAnne) == true) {
      if (*GlobalMois == 02 && *GlobalJour <= 29 && *GlobalJour > 0) {
        return true;
      }
    } else if (*GlobalMois == 02 && *GlobalJour <= 28 && *GlobalJour > 0) {
      return true;
    } else if (*GlobalMois == 01 || *GlobalMois == 03 || *GlobalMois == 05 ||
               *GlobalMois == 07 || *GlobalMois == 8 || *GlobalMois == 10) {
      if (*GlobalJour <= 31 && *GlobalJour > 0) {
        return true;
      } else
        return false;
    } else if (*GlobalMois == 04 || *GlobalMois == 06 || *GlobalMois == 9 ||
               *GlobalMois == 11 || *GlobalMois == 12) {
      if (*GlobalJour <= 30 && *GlobalJour > 0) {
        return true;
      } else
        return false;
    }
  }
  return false;
}

static bool _check_initials(int *GlobalInitial1, int *GlobalInitial2) {
  if (*GlobalInitial1 >= 65 && *GlobalInitial1 <= 90 && *GlobalInitial2 >= 65 &&
      *GlobalInitial2 <= 90) {
    return true;
  }
  return false;
}

static int _demande(int *GlobalJour, int *GlobalMois, int *GlobalAnne,
                    int *GlobalInitial1, int *GlobalInitial2,
                    int *GlobalNumeroOrdre, int *GlobalNumeroVerification) {
  int CodeJuste = 0;
  printf("Entre votre jour de naissance(JJ) : ");
  scanf("%i", GlobalJour);

  printf("Entre votre mois de naissance(MM) : ");
  scanf("%i", GlobalMois);

  printf("Entre votre anne de naissance(AA) : ");
  scanf("%i", GlobalAnne);

  printf("Entre t'es initials(N [espace] P) : ");
  scanf(" %i %i", GlobalInitial1, GlobalInitial2);

  printf("Entre ton numéro d'ordre : ");
  scanf("%i", GlobalNumeroOrdre);

  printf("Entre le code de verification(VV): ");
  scanf("%i", GlobalNumeroVerification);

  while (CodeJuste == 0) {
    bool DateCorrect = _check_date(GlobalJour, GlobalMois, GlobalAnne);
    bool InitialsCorrect = _check_initials(GlobalInitial1, GlobalInitial2);

    if (DateCorrect == true && InitialsCorrect == true) {
      CodeJuste = 1;
    } else {
      printf("\x1b[31m");
      printf("[ERROR][-] Essayer a nouveaux");
      printf("\x1b[0m");
      _gestion_erreur(DateCorrect, InitialsCorrect);
      printf("Entre votre jour de naissance(JJ) : ");
      scanf("%i", GlobalJour);

      printf("Entre votre mois de naissance(MM) : ");
      scanf("%i", GlobalMois);

      printf("Entre votre anne de naissance(AA) : ");
      scanf("%i", GlobalAnne);

      printf("Entre t'es initials(N [espace] P) : ");
      scanf(" %i %i", GlobalInitial1, GlobalInitial2);

      printf("Entre ton numéro d'ordre : ");
      scanf("%i", GlobalNumeroOrdre);

      printf("Entre le code de verification(CC): ");
      scanf("%i", GlobalNumeroVerification);
    }
  }
  long long controle_2 =
      (long long)*GlobalAnne * 10000000000 +
      (long long)*GlobalMois * 100000000 + (long long)*GlobalJour * 1000000 +
      (long long)*GlobalInitial1 * 10000 + (long long)*GlobalInitial2 * 100 +
      (long long)*GlobalNumeroOrdre;
  int verif = (controle_2 % 77);
  verif = 77 - verif;

  if (verif == *GlobalNumeroVerification) {
    return 1;
  } else
    return 0;
}

int MainVerification(int *GlobalJour, int *GlobalMois, int *GlobalAnne,
                     int *GlobalInitial1, int *GlobalInitial2,
                     int *GlobalNumeroOrdre, int *GlobalNumeroVerification) {
  int verif =
      _demande(GlobalJour, GlobalMois, GlobalAnne, GlobalInitial1,
               GlobalInitial2, GlobalNumeroOrdre, GlobalNumeroVerification);

  return verif;
}
