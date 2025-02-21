#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();          // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n')
        ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

int rechercheLettre(char lettre, char motSecret[], int *lettreTrouvee)
{
    int bonneLettre = 0;

    for (int i = 0; motSecret[i] != '\n'; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }

    return bonneLettre;
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
        printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        for (int i = 0; i < nombreLettres; i++)
        {
            if (lettreTrouvee[i])
                printf("%c", motSecret[i]);
            else
                printf("*");
        }

        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
            coupsRestants--;
    }

    return 0;
}