//
//  main.c
//  SDD projet 1 : Editeur de texte. Hugo et Loïc.
//
//  Created by Hugo GUILLAUME.
//

#include <stdio.h>
#include <stdlib.h>

#include "prototypes.h"
#include "fonctions_texte.h"
#include "fonctions_annexes.h"
#include "fonctions_avancés.h"
#include "structures & fonctions_listes.h"
#include "fonctions_fichiers_txt.h"


//affiche le menu et retourne le choix de l'utilisateur
char menu(){
    char choix = 'X';
    while(choix != '0' && choix != '1' && choix != '2' && choix != '3' && choix != '4' && choix != '5' && choix != '6' && choix != '7' && choix != '8' && choix != '9' && choix != 'E' && choix != 'L' && choix != 'P' && choix != 'T'){
        printf("\nBienvenue dans le menu principal de cet editeur.\n");
        printf(" |0| Saisir un texte.\n");
        printf(" |1| Affichage d'un texte.\n");
        printf(" |2| Copier un texte.\n");
        printf(" |3| Concatenation de deux textes.\n");
        printf(" |4| Insertion d'un texte dans un autre.\n");
        printf(" |5| Suppression d'une partie d'un texte.\n");
        printf(" |6| Rechercher dans un texte.\n");
        printf(" |7| Remplacer un element dans tout un texte.\n");
        printf(" |8| Afficher a partir d'un fichier existant.\n");
        printf(" |9| Sauvegarder un texte dans un fichier.\n");
        printf(" |L| Calculer la distance de levensthein entre deux textes.\n");
        printf(" |P| Recherche de la sous chaine la plus longue.\n");
        printf(" |T| Liste des titres des textes en memoire.\n");
        printf(" |E| Quitter.\n");
        printf(" Quelle action voulez vous realiser ?\n");
        choix = getchar();
        vider_buffer();
        printf("Vous avez choisi %c \n", choix);
    }
    return choix;
}

//fonction pour tout le programme et les choix
void fonction_controle(){
    Texte* Mon_controle = NULL;
    int end = 1;
    while(end != 0 ){
    char choix = menu();
        switch(choix){
            case '0':
                Mon_controle = ajouter_texte(Mon_controle);
                break;
            case '1':
                aff_texte(Mon_controle);
                break;
            case '2':
                copier_texte(Mon_controle);
                break;
            case '3':
                concatener_texte(Mon_controle);
                break;
            case'4':
                insertion_texte(&Mon_controle);
                break;
            case '5':
                suppression_texte(Mon_controle);
                break;
            case '6':
                rechercher_ocurence(Mon_controle);
                break;
            case '7':
                remplacer_element(Mon_controle);
                break;
            case '8':
                Mon_controle = recuperer_fichiertxt(Mon_controle);
                break;
            case '9':
                creer_txt(Mon_controle);
                break;
            case 'L':
                appel_levenstein(Mon_controle);
                break;
            case 'P':
                plus_longue_sous_chaine(Mon_controle);
                break;
            case 'T':
                liste_titre(Mon_controle);
                break;
            case 'E':
                end = 0;
                printf("\n || A bientot ||\n");
                break;
            default:
                printf("En cours de fabrication...");
                break;
        
        }
    }
    free_texte(Mon_controle);
}

int main(int argc, const char * argv[]) {
    
    fonction_controle();
    
    printf("\n\n Projet de liste L2-BN. Hugo et Loic.\n");
    return 0;
}
