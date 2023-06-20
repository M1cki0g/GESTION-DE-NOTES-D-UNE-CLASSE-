#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define MAX1 100
#define MAX2 100
#define MAX_ETUDIANTS 100
int c, h, N, i = 0, k, g, j, n = 0, choix_P, matrcl, choix_G, choix_C, tab[MAX1], nbEtudiants;
char nom[MAX1][MAX2], prenom[MAX1][MAX2], r;
float notesetudiants[MAX_ETUDIANTS][6],noteF[MAX_ETUDIANTS],noteA[MAX_ETUDIANTS],noteI[MAX_ETUDIANTS],noteE[MAX_ETUDIANTS],noteC[MAX_ETUDIANTS],noteD[MAX_ETUDIANTS],bulletin[MAX_ETUDIANTS];


/*afficher menu principal*/
void Menu_Principal()
{

printf("\nMenu Principal:");
    printf("\n\n\n1 - Gestion\n\n2 - Consultation\n\n3 - Quitter\n\n");
    printf("\nsasir un choix: ");
    do{
    scanf("%d",&choix_P);
    system("cls");
    switch (choix_P) {
            case 1:
                Menu_Gestion();
                break;
            case 2:
                menu_consultation();
                break;
            case 3:
                printf("Au revoir.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix_P >= 3);


}

void Menu_Gestion()
{int retourmenu;
 do{
        printf("Menu Gestion:");
        printf("\n\n\n1-Ajouter un etudiant\n\n2-Modifier un etudiant\n\n3-Ajouter notes par etudiant\n\n4-Quitter\n\n5-Retour");
        printf("\n\nchoisir un choix: ");
        scanf("%d",&choix_G);
        system("cls");

        switch(choix_G)
        {
        case 1:
            system("cls");
            ajouter_etd();
            break;
        case 2:

            modifier_etd();
            break;
        case 3:
            Ajouter_note();
            break;
        case 4:
            printf("Au revoir.");
            break;
        case 5:
            Menu_Principal();
            break;

        default:
            printf("choix invalide !!");
        }
 }while(choix_G>5);
}

void menu_consultation()
{
    int choix_C;

    printf("Menu Consultation");
    printf("\n\n\n1-Liste de notes par matiere\n\n2-Bulletin par etudiant\n\n3-Quitter\n\n4-Retour");

    do {
        printf("\n\nSaisir un choix: ");
        scanf("%d", &choix_C);

        switch (choix_C) {
            case 1:
                system("cls");
                Moyenne();
                break;
            case 2:
                system("cls");
                bulletins();
                break;
            case 3:
                system("cls");
                printf("Au revoir.");
                break;
            case 4:
                system("cls");
                Menu_Principal();
                break;

        default:
            printf("choix invalide !!");
        }
    } while (choix_C > 4);
}


void ajouter_etd()
{int retourmenu;
do
{
for (k = 0; k <= i; k++) {
        printf("\nvoulez vous ajouter un autre etudiant(repond par O/N):\n ");
        scanf(" %c", &r);

        if (r == 'O' || r == 'o') {
            printf("saisir le nom d'etudiant: %d\n ",k+1);
            scanf("%s",&nom[k]);
            printf("saisir le prenom d'etudiant: %d\n ",k+1);
            scanf("%s",&prenom[k]);
            printf("Entrez le matricule: %d\n ",k+1);
            scanf("%d", &matrcl);
            nbEtudiants++;

            c = 0;
            for (j = 0; j <= i; j++) {
                if (matrcl == tab[j]) {
                    c = 1;
                    break;
                }
            }

            if (c == 1 || matrcl == tab[j-1]) {
                printf("Le matricule existe deja dans le tableau,le matricule doit etre unique: \n");

            } else {
                if(i!=MAX1){
                tab[i] = matrcl;
                i++;
                }
                else
                 printf("le tableau est plein");
       }

        }
         if(r == 'N' || r == 'n')
        break;
}

}while((r == 'o' || r== 'O')&&(i!=MAX1));

system("cls");
    // Afficher les éléments du tableau
    printf("\nVoici les informations: \n");
    for(g=0; g<=i-1 ; g++)
    {printf("\netudiant: %d\n",g+1);
        printf("Nom: %s\n",nom[g]);
        printf("Prenom: %s\n",prenom[g]);
        printf("Matricule: %d\n",tab[g]);
        printf("\n");

    }
printf("Le nombre etudiants: %d",nbEtudiants);
    printf("\nVoulez-vous retourner au menu Gestion et choisir à nouveau (répondez par O/N) : ");
        scanf(" %c", &r);
        system("cls");

        if (r == 'O' || r == 'o')
            retourmenu = 1;
         else
            retourmenu = 0;

        if (retourmenu == 1)
        Menu_Gestion();


}

void modifier_etd()
{int retourmenu,nv_matrcl,existe=0;
    printf("\nSaisir le matricule de l'etudiant a modifier : ");
    scanf("%d", &matrcl);
    int c = 0;
    for (k = 0; k < i; k++)
    {
        if (tab[k] == matrcl)
        {
            existe = 1;
            printf("Les informations a modifier : \n");
            printf("Nom : %s\n", nom[k]);
            printf("Prenom : %s\n", prenom[k]);
            printf("Matricule : %d\n", tab[k]);
            printf("\n");

            printf("Saisir les nouvelles informations : \n");
            printf("Nouveau nom : ");
            scanf("%s", nom[k]);
            printf("Nouveau prenom : ");
            scanf("%s", prenom[k]);
            do {
                printf("Nouveau matricule : ");
                scanf("%d", &nv_matrcl);

                existe = 0; // Reset existe flag

                for (int j = 0; j < i; j++)
                {
                    if (j != k && tab[j] == nv_matrcl)
                    {
                        existe = 1;
                        printf("Le matricule existe deja.\n");
                        break;
                    }
                }

                if (existe==0)
                {
                    tab[k] = nv_matrcl;
                }
            } while (existe==1);

            c = 1;
            break;
        }
    }

    if (c == 0)
    {
        printf("\nLe matricule n'existe pas.\n");
    }


      system("cls");
    // Afficher les éléments du tableau
    printf("\nVoici les informations: \n");
    for(k=0; k<i ; k++)
    {printf("\netudiant: %d\n",k+1);
        printf("Nom: %s\n",nom[k]);
        printf("Prenom: %s\n",prenom[k]);
        printf("Matricule: %d\n",tab[k]);
        printf("\n");
    }

    printf("\nVoulez-vous retourner au menu Gestion et choisir à nouveau (répondez par O/N) : ");
        scanf(" %c", &r);
        system("cls");


        if (r == 'O' || r == 'o')
            retourmenu = 1;
         else
            retourmenu = 0;

        if (retourmenu == 1)
        Menu_Gestion();
}





void Ajouter_note()
{
 int retourmenu;
 c=0;
 printf("saisir le matricule: ");
 scanf("%d",&matrcl);
 for(k = 0; k <= i-1; k++)
 {
     if(tab[k] == matrcl){
        c=1;
     do{
         printf("saisir la note du francais: ");
         scanf("%f",&noteF[k]);
     }while(noteF[k]<0||noteF[k]>20);
     do{
         printf("saisir la note du Anglais: ");
         scanf("%f",&noteA[k]);
     }while(noteA[k]<0||noteA[k]>20);
     do{
         printf("saisir la note du informatique: ");
         scanf("%f",&noteI[k]);
     }while(noteI[k]<0||noteI[k]>20);
     do{
         printf("saisir la note du electrecite: ");
         scanf("%f",&noteE[k]);
     }while(noteE[k]<0||noteE[k]>20);
     do{
         printf("saisir la note du circuit numerique: ");
         scanf("%f",&noteC[k]);
     }while(noteC[k]<0||noteC[k]>20);
     do{
         printf("saisir la note du droit: ");
         scanf("%f",&noteD[k]);
     }while(noteD[k]<0||noteD[k]>20);
     printf("\nVoici les informations: \n");

    printf("\netudiant: %d\n",k+1);
        printf("Nom: %s\n",nom[k]);
        printf("Prenom: %s\n",prenom[k]);
        printf("Matricule: %d\n",tab[k]);
        printf("note francais: %.2f\n",noteF[k]);
        printf("note anglais: %.2f\n",noteA[k]);
        printf("note informatique: %.2f\n",noteI[k]);
        printf("note electrecite: %.2f\n",noteE[k]);
        printf("note circuit numerique: %.2f\n",noteC[k]);
        printf("note droit: %.2f\n",noteD[k]);
        printf("\n");
        break;

   }
 }

     if(c==0)
        printf("n'existe pas");


    printf("\nVoulez-vous retourner au menu Gestion et choisir à nouveau (répondez par O/N) : ");
        scanf(" %c", &r);
        system("cls");


        if (r == 'O' || r == 'o')
            retourmenu = 1;
         else
            retourmenu = 0;

        if (retourmenu == 1)
        Menu_Gestion();
}


void bulletins() {
    char r;
    int matricule;
    int existe = -1;
    int i;

    if (nbEtudiants == 0) {
        printf("La liste d'Etudiants est vide.\n");
        return;
    }

    printf("\n-----BULLETIN -----\n\n\n");
    printf("Matricule de l'etudiant : ");
    scanf("%d", &matricule);

    for (i = 0; i < nbEtudiants; i++) {
        if (matricule == tab[i]) {
            existe = i;
            break;
        }
    }

    if (existe == -1) {
        printf("Aucun etudiant trouve avec ce matricule.\n");
        return;
    }

    printf("bulletin de l'etudiant : %s %s \n", nom[existe], prenom[existe]);
    float moyenne = (noteF[existe] + noteA[existe] + noteI[existe] + noteE[existe] + noteC[existe] + noteD[existe]) / 6.0;

    printf("\n FRANCAIS           :  ");
    if (noteF[existe] < 10) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    printf("%.2f\n", noteF[existe]);

    printf(" ANGLAIS            :  ");
    if (noteA[existe] < 10) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    printf("%.2f\n", noteA[existe]);

    // Réinitialiser la couleur de la console
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf(" INFORMATIQUE            :  ");
    if (noteI[existe] < 10) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    printf("%.2f\n", noteI[existe]);

    // Réinitialiser la couleur de la console
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf(" ELECTRECITE            :  ");
    if (noteE[existe] < 10) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    printf("%.2f\n", noteE[existe]);

    // Réinitialiser la couleur de la console
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf(" CIRCUIT NUMERIQUE            :  ");
    if (noteC[existe] < 10) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    printf("%.2f\n", noteC[existe]);

    // Réinitialiser la couleur de la console
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf(" DROIT           :  ");
    if (noteD[existe] < 10) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    printf("%.2f\n", noteD[existe]);

    // Réinitialiser la couleur de la console
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Bulletin : %.2f  \t", moyenne);

    if (moyenne < 10) {
        clignoterRedoublant();
    } else if (moyenne < 12) {
        printf(" PASSABLE");
    } else if (moyenne < 15) {
        printf(" ASSER BIEN");
    } else if (moyenne < 16) {
        printf(" BIEN");
    } else {
        printf(" TRES BIEN");
    }
    printf("\n\nvoulez vous afficher un bulletin repondez(O/N): ");
    scanf(" %c",&r);
    if(r=='o'||r=='O')
        bulletins();
    else
        menu_consultation();

}

void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void clignoterRedoublant() {
    int i;
    int x = 50; // Horizontal position
    int y = 23; // Vertical position

    for (i = 0; i < 9999999999; i++) {
        gotoxy(x, y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        printf("REDOUBLANT");
        Sleep(700);
        gotoxy(x, y);
        printf("           ");
        Sleep(120);
    }
}


void Moyenne()
{
    float moyenne = 0;
    int total_etudiants = 0;
    int matiere;
    for(k=0 ; k<nbEtudiants ; k++)
        {
    printf("\netudiant: %d\n",k+1);
        printf("Nom: %s\n",nom[k]);
        printf("Prenom: %s\n",prenom[k]);
        printf("Matricule: %d\n",tab[k]);
        printf("note francais: %.2f\n",noteF[k]);
        printf("note anglais: %.2f\n",noteA[k]);
        printf("note informatique: %.2f\n",noteI[k]);
        printf("note electrecite: %.2f\n",noteE[k]);
        printf("note circuit numerique: %.2f\n",noteC[k]);
        printf("note droit: %.2f\n",noteD[k]);
        printf("\n");
        }

    printf("Numero de la matiere : ");
    scanf("%d", &matiere);

    switch (matiere) {
        case 1:
            for (k = 0; k < nbEtudiants; k++) {
                moyenne += noteF[k];
                total_etudiants++;
            }
            break;
        case 2:
            for (k = 0; k < nbEtudiants; k++) {
                moyenne += noteA[k];
                total_etudiants++;
            }
            break;
        case 3:
            for (k = 0; k < nbEtudiants; k++) {
                moyenne += noteI[k];
                total_etudiants++;
            }
            break;
        case 4:
            for (k = 0; k < nbEtudiants; k++) {
                moyenne += noteE[k];
                total_etudiants++;
            }
            break;
        case 5:
            for (k = 0; k < nbEtudiants; k++) {
                moyenne += noteC[k];
                total_etudiants++;
            }
            break;
        case 6:
            for (k = 0; k < nbEtudiants; k++) {
                moyenne += noteD[k];
                total_etudiants++;
            }
            break;
        default:
            printf("Numero de matiere invalide.\n");
            return;
    }

    if (total_etudiants > 0) {
        moyenne /= total_etudiants;
        printf("Moyenne de la matiere %d: %.2f\n", matiere, moyenne);
    } else {
        printf("Aucun etudiant avec des notes dans cette matiere.\n");
    }

    printf("\nVoulez-vous retourner au menu Consultation et choisir à nouveau (répondez par O/N) : ");
    scanf(" %c", &r);
    system("cls");

    if (r == 'O' || r == 'o') {
        Moyenne();
    }
    else
        menu_consultation();

}









int main()
{


        Menu_Principal();

    return 0;
}


















