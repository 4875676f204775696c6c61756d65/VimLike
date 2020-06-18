//
//  fonctions_texte.h
//  SDD projet 1 : Editeur de texte. Hugo et Loïc.
//
//  Created by Hugo GUILLAUME on 15/10/2019.
//  Copyright © 2019 Hugo GUILLAUME. All rights reserved.
//

#ifndef fonctions_texte_h
#define fonctions_texte_h

// cette fonction permet à l'utilisateur d'entrer le texte
Maillon * entrer_texte(){
    printf("Vous pouvez entrer votre texte.\n");
    char entre = '0';
    Maillon* liste = NULL;
    while(entre != '\n'){
        entre = getchar();
        liste = ajouterelement(liste, entre);
    }
    return liste;
}


Maillon *entrer_titre(){
    int nbr_lettre = 0;
    char entre = '0';
    Maillon* liste = NULL;
    while((entre != '\n') && (nbr_lettre < 10)){
        entre = getchar();
        liste = ajouterelement(liste, entre);
        nbr_lettre++;
    }
    if(entre != '\n'){
        vider_buffer();
        liste = ajouterelement(liste, '\n');
    }
    return liste;
}


//creer plusieurs textes
Texte* creer_texte(Texte* prec){
    Texte* new_text = malloc(sizeof(Texte));
    printf("Entrez votre titre \n");
    new_text->titre = entrer_titre();
    new_text->lecture = entrer_texte();
    new_text->next = NULL;
    new_text->prec = prec;
    return new_text;
}


//creer un nouveau maillon pour y mettre le texte
Texte* ajouter_texte(Texte* init_texte){
    Texte* temp = NULL;
    Texte* precedent = NULL;
    if(init_texte == NULL){
        init_texte = creer_texte(precedent);
    }
    else{
        temp = init_texte;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = creer_texte(temp);
    }
    return init_texte;
}

// En cours de fabrication
Texte* choix_texte(Texte* controle){

    int end = 0;
    Maillon* titre = entrer_titre();
    Texte* controle_temp = controle;
    if(controle == NULL){
        printf("Il n'y a aucun texte en memoire...\nCreez un texte pour utiliser cette fonction.\n\n");
        return NULL;
    }else{
        while(comparer_texte(titre, controle_temp->titre) != 0 && end == 0){
            if(controle_temp->next != NULL){
                controle_temp = controle_temp->next;
            }else{
                end = 1;
            }
        }
        if(end == 0){
            return controle_temp;
        }else{
            printf("Il n'existe pas de texte portant ce titre\n");
            return NULL;
        }
    }
}

int comparer_texte(Maillon* liste_1, Maillon* liste_2){
    if((liste_1 == NULL) && (liste_2 == NULL)){
       return 0;
    }
    else if(liste_1 == NULL){
        return 1 + comparer_texte(liste_1, liste_2->next);
    }
    else if(liste_2 == NULL){
        return 1 + comparer_texte(liste_1->next, liste_2);
    }
    else if(liste_1->info == liste_2->info){
        return 0 + comparer_texte(liste_1->next, liste_2->next);
    }
    else{
        return 1 + comparer_texte(liste_1->next, liste_2->next);
    }
}

void aff_texte(Texte* controle){
    liste_titre(controle);
    printf("Saisissez le titre du texte que vous voulez afficher : \n");
    Texte* choix_txt = choix_texte(controle);
    if(choix_txt != NULL){
        Maillon* choix = choix_txt->lecture;
        aff_liste(choix);
    }else{
        printf("Vous allez etre redirige vers le menu.\n");
    }
}

void copier_texte(Texte* controle){
    liste_titre(controle);
    printf("Saisissez le titre du texte que vous voulez copier : \n");
    Texte* choix_txt = choix_texte(controle);
    if(choix_txt != NULL){
        Maillon* liste = choix_txt->lecture;
        Texte* controle_temp = controle;
        while(controle_temp->next != NULL){
            controle_temp = controle_temp->next;
        }
        controle_temp->next = malloc(sizeof(Texte));
        controle_temp = controle_temp->next;
        controle_temp->next = NULL;
        printf("Quel titre voulez vous donner a la copie ?\n");
        controle_temp->titre = entrer_titre();
        controle_temp->lecture = creer_maillon(liste->info);
        Maillon* nouv = controle_temp->lecture;
        while (liste->next != NULL){
            nouv->next = creer_maillon(liste->next->info);
            nouv = nouv->next;
            liste = liste->next;
        }
    }else{
        printf("Vous allez etre redirige vers le menu.\n");
    }
}


void concatener_texte(Texte* controle){
    liste_titre(controle);
    printf("Choisissez d'abord le premier texte a concatener : \n");
    Texte* texte1 = choix_texte(controle);
    if(texte1 != NULL){
        printf("Choisissez le second texte a concatener : \n");
        Texte* texte2 = choix_texte(controle);
        if(texte2 != NULL){
            Texte* new_text = malloc(sizeof(Texte));
            printf("Entrez votre titre \n");
            new_text->titre = entrer_titre();
            new_text->next = NULL;
            Maillon* lecture_1 = texte1->lecture;
            Maillon* lecture_2 = texte2->lecture;
            new_text->lecture = creer_maillon(lecture_1->info);
            Maillon* new_lecture = new_text->lecture;
            lecture_1 = lecture_1->next;
            while(lecture_1 != NULL){
                new_lecture->next = creer_maillon(lecture_1->info);
                lecture_1 = lecture_1->next;
                new_lecture = new_lecture->next;
            }
            new_lecture->info = ' ';
            while (lecture_2->next != NULL) {
                new_lecture->next = creer_maillon(lecture_2->info);
                lecture_2 = lecture_2->next;
                new_lecture = new_lecture->next;
            }
            while(controle->next != NULL){
                controle = controle->next;
            }
            controle->next = new_text;
            new_text->prec = controle;
        }else{
            printf("Vous allez etre redirige vers le menu.\n");
        }
    }else{
            printf("Vous allez etre redirige vers le menu.\n");
    }
}

void insertion_texte(Texte** controle){
    liste_titre(*controle);
    int position;
    int lengh;
    printf("Choisissez d'abord le texte de depart : \n");
    Texte* texte1 = choix_texte(*(controle));
    if(texte1 != NULL){
        printf("Choisissez le texte a ajouter : \n");
        Texte* texte2 = choix_texte(*(controle));
        if(texte2 != NULL && comparer_texte(texte1->lecture, texte2->lecture) != 0){
            lengh = longueur_liste(texte1->lecture);
            do{
                printf("En quelle position voulez vous inserer le deuxieme texte? (entre 0 c'est a dire avant et %d c'est a dire apres).\n", lengh);
                scanf("%d", &position);
            }while(position < 0 || position > lengh);
            vider_buffer();
            int longueur = longueur_liste(texte1->lecture);
            if(position <= 1){
                Maillon* temp = texte2->lecture;
                while(temp->next->next != NULL){
                    temp = temp->next;
                }
                free(temp->next);
                temp->next = texte1->lecture;
                texte1->lecture = texte2->lecture;
                if(texte2->prec == NULL){
                    *(controle) = texte2->next;
                    texte2->lecture = NULL;
                    texte2->next = NULL;
                    free_texte(texte2);
                }else{
                    texte2->prec->next = texte2->next;
                    texte2->next = NULL;
                    texte2->lecture = NULL;
                    free_texte(texte2);
                }
            }else if(position >= longueur){
                Maillon* lecture = texte1->lecture;
                while(lecture->next->info != '\n'){
                    lecture = lecture->next;
                }
                free(lecture->next);
                lecture->next = texte2->lecture;
                if(texte2->prec == NULL){
                    *(controle) = texte2->next;
                    texte2->lecture = NULL;
                    texte2->next = NULL;
                    free_texte(texte2);
                }
                else{
                    texte2->prec->next = texte2->next;
                    texte2->next = NULL;
                    texte2->lecture = NULL;
                    free_texte(texte2);
                }
            }else{
                int pos_temp = 2;
                Maillon* lecture = texte1->lecture;
                Maillon* lecture2 = texte2->lecture;
                while(pos_temp != position){
                    pos_temp++;
                    lecture = lecture->next;
                }
                Maillon* temp = lecture->next;
                lecture->next = lecture2;
                while(lecture2->next->info != '\n'){
                    lecture2 = lecture2->next;
                }
                free(lecture2->next);
                lecture2->next = temp;
                if(texte2->prec == NULL){
                    *(controle) = texte2->next;
                    texte2->next = NULL;
                    texte2->lecture = NULL;
                    free_texte(texte2);
                }else{
                    texte2->prec->next = texte2->next;
                    texte2->next = NULL;
                    texte2->lecture = NULL;
                    free_texte(texte2);
                }
            }
        }else{
                printf("Vous allez etre redirige vers le menu.\n");
        }
    }else{
            printf("Vous allez etre redirige vers le menu.\n");
    }
}

void rechercher_ocurence(Texte* controle){
    liste_titre(controle);
    printf("Saisissez le titre du texte que vous scanner : \n");
    Texte* texte1 = choix_texte(controle);
    if(texte1 != NULL){
        Maillon* liste = texte1->lecture;
        int occurence = 0;
        char ele_recherche;
        Position* position = NULL;
        int place = 1;
        printf("Quelle chaine de caracteres voulez vous chercher dans le texte ?\n");
        ele_recherche = getchar();
        vider_buffer();
        while (liste != NULL) {
            if (liste->info == ele_recherche){
                occurence++;
                position = ajouterelement_int(position, place);
            }
            place += 1;
            liste = liste->next;
        }
    
        if(occurence == 0){
            printf("Il n'y a aucune occurence de cette chaine dans le texte.\n");
        }else{
            printf("Il y a %d occurence de la chaine de caracteres %c\n", occurence, ele_recherche);
            printf("Elle(s) se trouve(nt) au(x) emplacement(s) ");
            while(position != NULL){
                printf("%d ", position->position);
                position = position->suivant;
            }
        }
    }else{
        printf("Vous allez etre redirige vers le menu.\n");
    }
}


void remplacer_element(Texte* controle){
    liste_titre(controle);
    printf("Donnez le titre du texte que vous voulez modifier ?\n");
    Texte* texte1 = choix_texte(controle);
    if(texte1 != NULL){
        Texte* temp = texte1;
        printf("Quel caractere voulez vous remplacer ?\n");
        char occurence = getchar();
        vider_buffer();
        printf("Par quel caractere voulez vous le remplacer ?\n");
        char remplacement = getchar();
        vider_buffer();
        Maillon* templ = temp->lecture;
        while (templ->next != NULL){
            if(templ->info == occurence){
                templ->info = remplacement;
                templ = templ->next;
            }else{
                templ = templ->next;
            }
        }
        if (templ->info == occurence){
            templ->info = remplacement;
        }
    }else{
        printf("Vous allez etre redirige vers le menu.\n");
    }
}



void liste_titre(Texte* arbre){
    char choix;
    printf("voulez vous afficher la liste des titres deja existant ? (si oui tapez y)\n");
    choix = getchar();
    vider_buffer();
    printf("\n");
    if(choix == 'y'){
        int compteur = 1;
        if(arbre == NULL){
            printf("Il n'y aucun texte enregistre\n");
        }
        else{
            while(arbre != NULL){
                printf("[%d] ", compteur);
                aff_liste(arbre->titre);
                compteur++;
                arbre = arbre->next;
            }
        }
    }
}


void suppression_texte(Texte* controle){
    int position = 0;
    int i;
    int quantite = 0;
    int position_temp = 1;
    liste_titre(controle);
    printf("Quel texte voulez vous modififer ?\n");
    Texte* texte1 = choix_texte(controle);
    if(texte1 != NULL){
        Maillon* lecture1 = texte1->lecture;
        Maillon* prec = lecture1;
        int longueur = longueur_liste(lecture1);
        printf("En quelle position voulez vous supprimer des caracteres?(entre 1 et %d)\n", longueur-1);
        while((position >= longueur) || (position <= 0)){
            scanf("%d", &position);
            if((position >= longueur) || (position <= 0)){
                printf("En quelle position voulez vous supprimer des caracteres?(entre 1 et %d)\n", longueur-1);
            }
        }
        printf("Combien de caracteres voulez vous supprimer?\n");
        scanf("%d", &quantite);
        vider_buffer();
        if(position != 1){
            while(position_temp != position){
                prec = lecture1;
                lecture1 = lecture1->next;
                position_temp++;
            }
            for(i = 0; i < quantite; i++){
                prec->next = lecture1->next;
                free(lecture1);
                lecture1 = prec->next;
                if(lecture1->next == NULL){
                    return;
                }
            }
        }else{
            for(i = 0; i < quantite; i++){
                Maillon* suppr = texte1->lecture;
                texte1->lecture = texte1->lecture->next;
                free(suppr);
                if(texte1->lecture->next == NULL){
                    printf("Cette liste a ete integralement videe de son texte. Elle est cependant toujours utilisable en tant que liste.");
                    return;
                }
            }
        }
    }else{
            printf("Vous allez etre redirige vers le menu.\n");
    }
}
#endif /* fonctions_texte_h */
