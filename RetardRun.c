/* ************************************************************************
* Retard RUN
*************************************************************************
* Fonction : Jeux basé sur le spamm de touche
*************************************************************************
* Entrée : 2 touches récupéré avec getche()
* précision sur getche() : http://geeksquiz.com/difference-getchar-getch-getc-getche/
* Sortie : Barre de progresion en console
*
* ***********************************************************************
* Librairie : conio.h
*************************************************************************
* Auteur   : Philippe Skopal                    * Date  : 07/01/2016
* Version  : v1.0                   			* Executable Windows
*************************************************************************/

//On commence par inclure les bibliothèque nécéssaire
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // celle-ci est nécéssaire pour la fonction getche ==> récup de caractère
#include <unistd.h> // pour la fonction sleep

// On ouvre la fonction principale
int main(int argc, char *argv[])
{


    //--------------------- Bloc du premier screen --------------------
    // Dans ce screen on va simplement afficher la fenètre d'accueil

    system("cls"); // Pour commencer on nettoie l'écran en cas d'un deuxième lancement du programme

    printf("############################################################# \n");
    printf("######## Bienvenue BANDE de retards sur RETARD RUN  ######### \n");
    printf("############################################################# \n");
    printf("##                                                         ## \n");
    printf("## Le joueur 1 est : vert : sa touche  est le q (lol)      ## \n");
    printf("## Le joueur 2 est : rouge : sa touche  est le m           ## \n");
    printf("##                                                         ## \n");
    printf("##### Quand chaque tardos est prêt il apui sur sa touch ##### \n");
    printf("##                                                         ## \n");
    printf("############################################################# \n");

    //--------------------- Bloc d'attente des deux joueurs  --------------------
        // ici on va leur demander de chacun apuuyer sur sa touche pour lancer le jeux
        // et donc confirmer que ils sont prêt

        //rappel
        //joueur 1 : q = 113
        //joueur 2 : m = 109

    // on commence par déclarer les variables
    int varJ1 = 0; // en 1 confirme que joueur 1 a appuyer sur sa touche q
    int varJ2 = 0; // en 1 confirme que joueur 2 a appuyer sur sa touche m
    int varJ12 = 0; // en 1 confirme que les deux joueur ont appuyer sur leurs touches
    int charTardos = NULL; // récupère la touche pressé par les joueurs

    // on va commencer la boucle a passer pour démarer le jeux
    while(varJ12 == 0)
    {
        // on va commencer comme toujours par effacer l'écran


        // on va faire une demande de appuyer sur la touche en fonction de qui doit appuyer
        // 1er cas : Si la variable du joueur 1 = 0 et celle du 2 aussi, on affiche que j1 et 2 doivent appuyer sur leurs touches
        // 2nd cas : Si la variable du joueur 1 = 0 et celle du 2 = 1, on dit a j1 d'appuyer sur q
        // 3rd cas : Si la variable du joueur 1 = 1 et celle du 2 = 0, on dit a j2 d'appuyer sur m
        // Si varJ1 et varJ1 = 1 on passe au décompte

        if(varJ1 ==0 && varJ2 ==0) // 1er cas
        {
            printf(" ");
            printf("Joueur 1 appuis sur q, et Joueur 2 appuis sur m.\n");
        }
        else if (varJ1 ==0 && varJ2 ==1) // 2nd cas
        {
            printf(" ");
            printf("Joueur 1 appuis sur q pour lancer la partie.\n");
        }
        else if (varJ1 ==1 && varJ2 ==0)
        {
            printf(" ");
            printf("Joueur 2 appuis sur m pour lancer la partie.\n");
        }
        else
        {
            // normalement ne devrais jamais être exécuter
        }

        // on récupère ce qui va être entré.
        charTardos = getche();
        // on vide la console car sinon le char sera afficher
        system("cls");

        // en fonction de ce qui va être entrer on  va réagir
        // 1) un q on met en 1 varJ1
        // 2) un m on met en 1 varJ2
        // 3) on ignore le reste

        if(charTardos == 113) // 1) Joueur 1 ==> q
        {
            varJ1 = 1;
        }
        else if(charTardos == 109) // 2) Joueur 2 ==> m
        {
            varJ2 = 1;
        }
        else  // 3) mauvaise touche
        {
            printf("Mauvaise touche bande de retard.\n");
        }
        if(varJ1 ==1 && varJ2 ==1) // on rompt la boucle
        {
            varJ12 = 1;
        }
    }
    //--------------------- Bloc du décompte  --------------------
    // on nettoie le screen
    system("cls");
    printf("##### Debut de la guerre dans : 5 #####\n");
    sleep(1);

    system("cls");
    printf("#### Debut de la guerre dans : 4 ####\n");
    sleep(1);

    system("cls");
    printf("### Debut de la guerre dans : 3 ###\n");
    sleep(1);

    system("cls");
    printf("## Debut de la guerre dans : 2 ##\n");
    sleep(1);

    system("cls");
    printf("# Debut de la guerre dans : 1 #\n");
    sleep(1);
    system("cls");
    //--------------------- Bloc du jeu  --------------------

    // on déclare les variable du jeux
    int varRecupBourinage = 0;
    int compteur = 25;

    int varBreak = 0;

    while(varBreak ==0)
    {

        //on nettoie l'ecran
        system("cls");
        //on affiche le screen du jeux par rapport au compteur
        printf("#############################################################\n");
        printf("######## RETARD RUN the game by Philippe Skopal     #########\n");
        printf("#############################################################\n");
        printf("##                                                         ##\n");
        printf("##      Allez les tards on bourinnent sa touche            ##\n");
        printf("##                                                         ##\n");
        if(compteur ==25) // egalite
        {
            printf("##      Egalite tardosienne                                ##\n");
        }
        else if(compteur > 25) // joueur 2 en tête
        {
            printf("##      Joueur 2/rouge en tete                             ##\n");
        }
        else if(compteur < 25) // Joueur 1 en tete
        {
            printf("##      Joueur 1/vert en tete                              ##\n");
        }
        printf("##                                                         ##\n");
        // la progressbar
        int j = compteur + 1; // ==> +1 par rapport au compteur pour remplir de 1 a la bonne valeur de =

        int i = 0; // compteur interne qui va de 1 à compteur
        int l = 0;

        char progressBar[51]; // ==> on céer la chaine de caractère vide

        progressBar[0] = '['; // ==> case 0 on y met un début de crochet
        for (i=1; i < j; i++) // ==> on remplit de la case 1 a la valeur du compteur de =
        {
            progressBar[i] = '=';
        }
        for(l=compteur+1; l < 51;l++) //==> on remplit le reste d'espace
        {
            progressBar[l] = ' ';
        }
        progressBar[51] = ']'; // ==> on finis par refermer le crochet
        printf("##  ");
        printf(" %s", progressBar);
        printf("##\n");
        printf("##                                                         ##\n");
        printf("#############################################################\n");

        // gestion de la pression des touches
        varRecupBourinage = 0; // on la vide pour eviter les problèmes
        varRecupBourinage = getche();

        if(varRecupBourinage == 113)
        {
            compteur--;
        }
        else if(varRecupBourinage == 109)
        {
            compteur++;
        }
        else
        {
            //on ne fais rien
        }

        if(compteur == 0)
        {
            varBreak = 1;
        }
        else if(compteur == 50)
        {
            varBreak = 1;
        }
        else
        {
            //nothing
        }
        varRecupBourinage = 0; // on la vide pour eviter les problèmes
    }

    //--------------------- Bloc screen final --------------------
    int break2 = 0;
    int input2 = 0;
    int compteur2 = compteur;
    if(compteur2 == 0)
    {
        while(break2 == 0)
        {
            system("cls");
            system("COLOR 20");
            printf("Joueur 1 Gagne ! \n");
            printf("Appuyer sur g pour terminer le jeux \n");
            input2 = getche();
            if(input2 == 103)
            {
                break2 = 1;
            }
        }

    }
    else if(compteur == 50)
    {
        while(break2 == 0)
        {
            system("cls");
            system("COLOR 40");
            printf("Joueur 2 Gagne ! \n");
            printf("Appuyer sur g pour terminer le jeux \n");
            input2 = getche();
            if(input2 == 103)
            {
                break2 = 1;
            }
        }

    }
return 0;
}
