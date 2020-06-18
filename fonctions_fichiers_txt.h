//
//  fonctions_fichiers_txt.h
//  SDD projet 1 : Editeur de texte. Hugo et Loïc.
//
//  Created by Hugo GUILLAUME on 15/10/2019.
//  Copyright © 2019 Hugo GUILLAUME. All rights reserved.
//

#ifndef fonctions_fichiers_txt_h
#define fonctions_fichiers_txt_h

Texte* recuperer_fichiertxt(Texte* controle){
    int itineraire = 0;
    if(controle == NULL){
        controle = malloc(sizeof(Texte));
        itineraire = 1;
    }
    Texte* nouveau = controle;
    Texte* temp = malloc(sizeof(Texte));
    printf("Quel fichier voulez vous ouvrir ?\n");
    temp->titre = entrer_titre();
    FILE* fichier;
    char nom[11];
    int compteur = 0;
    while (temp->titre != NULL){
        nom[compteur] = temp->titre->info;
        compteur++;
        temp->titre = temp->titre->next;
    }
    fichier = fopen(nom, "r");
    
    if(fichier == NULL){
        printf("Il n'existe aucun fichier .txt de ce nom.");
    }else{
        if (itineraire == 1){
            controle = temp;
            controle->next = NULL;
            printf("Quel titre voulez vous donner au texte ?\n");
            temp->titre = entrer_titre();
            char entre = '0';
            Maillon* liste = malloc(sizeof(Maillon));
            temp->lecture = liste;
            temp->next = NULL;
            while(entre != '\n' && entre != EOF){
                entre = fgetc(fichier);
                liste = ajouterelement(liste, entre);
            }
        }else{
            while (nouveau->next != NULL) {
                nouveau = nouveau->next;
            }
            nouveau->next = temp;
            printf("Quel titre voulez vous donner au texte ?\n");
            temp->titre = entrer_titre();
            char entre = '0';
            Maillon* liste = malloc(sizeof(Maillon));
            temp->lecture = liste;
            temp->next = NULL;
            liste->next = NULL;
            while(entre != '\n' && entre != EOF){
                entre = fgetc(fichier);
                liste = ajouterelement(liste, entre);
            }
        }
    }
    
    return controle;
}

void creer_txt(Texte* controle){
    char nom[11];
    Texte* texte_actuel = controle;
    if (controle != NULL){
        printf("Quel texte voulez vous enregistrer ?\n");
        texte_actuel = choix_texte(controle);
        if(texte_actuel != NULL){
            printf("Quel nom voulez vous donner au fichier cree ?\n");
            fgets(nom, 11, stdin);
            FILE*fichier = fopen(nom, "w+");
            if(fichier == NULL){
                printf("Erreur dans la creation du fichier. Faites attention a ne pas utiliser de caracteres speciaux.\n");
            }else{
                printf("Fichier - %s - cree avec succes\n", nom);
                vider_buffer();
                Maillon* ma_liste = texte_actuel->lecture;
                while (ma_liste != NULL){
                    fputc(ma_liste->info, fichier);
                    ma_liste = ma_liste->next;
                }
            fclose(fichier);
            }
            }else{
                printf("Vous allez etre redirige vers le menu.\n");
            }
    }else{
        printf("Vous allez etre redirige vers le menu.\n");
    }
}
   

#endif /* fonctions_fichiers_txt_h */
