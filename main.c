#include <stdio.h>
#include <stdlib.h>

int tailleMot(char motSecret[])
{
    int nombreLettres = 0;
    for (int i = 0; motSecret[i] != '\0'; i++)
        nombreLettres++;

    return nombreLettres;
}

void initTableau(int *lettreTrouvee, int taille)
{
    for (int i = 0; i < taille; i++)
        lettreTrouvee[i] = 0;
}

int gagne(int *lettreTrouvee, int nombreLettres)
{
    int i = 0;
    int joueurGagne = 1;

    for (i = 0; i < nombreLettres; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}

int main(int argc, char *argv[])
{
    char lettre = 0;            // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[] = "ROUGE"; // C'est le mot à trouver
    int coupsRestants = 10;     // Compteur de coups restants (0 = mort)
    int nombreLettres = tailleMot(motSecret);
    int *lettreTrouvee = NULL; // Tableau de booleens
    lettreTrouvee = malloc(nombreLettres * sizeof(int));
    initTableau(lettreTrouvee, nombreLettres);

    while (coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres))
    {
    }

    return 0;
}