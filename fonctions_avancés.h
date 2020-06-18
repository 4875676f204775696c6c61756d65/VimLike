//
//  fonctions_avancés.h
//  SDD projet 1 : Editeur de texte. Hugo et Loïc.
//
//  Created by Hugo GUILLAUME on 15/10/2019.
//  Copyright © 2019 Hugo GUILLAUME. All rights reserved.
//

#ifndef fonctions_avance_s_h
#define fonctions_avance_s_h


//cette fonction retourne la distance de levenstein entre 2 chaines de caractères
int levenstein(Maillon* liste1, Maillon* liste2){
    int compteur = 0;
    if((liste1->info == '\n') && (liste2->info == '\n')){
        return 0;
    }
    else if(liste1->info == '\n'){
        return longueur_liste(liste2) + 1;
    }
    else if(liste2->info == '\n'){
        return longueur_liste(liste1) + 1;
    }
    else if(liste1->info == liste2->info){
        int compteur1 = levenstein(liste1->next, liste2);
        int compteur2 = levenstein(liste1, liste2->next);
        int compteur3 = levenstein(liste1->next, liste2->next);
        compteur = min_3nombres(compteur1, compteur2, compteur3);
        return 0 + compteur;
    }
    else{
        int compteur1 = levenstein(liste1->next, liste2);
        int compteur2 = levenstein(liste1, liste2->next);
        int compteur3 = levenstein(liste1->next, liste2->next);
        compteur = min_3nombres(compteur1, compteur2, compteur3);
        return 1 + compteur;
    }
}

// cette fontion gere l'appel de la fonction levenstein
void appel_levenstein(Texte* controle){
    liste_titre(controle);
    printf("Donnez le titre de votre premier texte?\n");
    Texte* texte1 = choix_texte(controle);
    if(texte1 != NULL){
        Maillon* lecture1 = texte1->lecture;
        printf("Donnez le titre de votre deuxième texte?\n");
        Texte* texte2 = choix_texte(controle);
        if (texte2 != NULL){
            Maillon* lecture2 = texte2->lecture;
            printf("La distance de levensthein entre ces deux chaines de caracteres est %d.\n", levenstein(lecture1, lecture2));
        }else{
        printf("Ce texte n'existe pas. Verifier l'orthographe.");
        }
    }else{
    printf("Ce texte n'existe pas. Verifier l'orthographe.");
    }
}

void plus_longue_sous_chaine(Texte* controle){
    liste_titre(controle);
    printf("Ecrivez le titre de votre premier texte ?\n");
    Texte* texte1 = choix_texte(controle);
    if(texte1 != NULL){
        printf("Ecrivez le titre de votre deuxieme texte ?\n");
        Texte* texte2 = choix_texte(controle);
        if(texte2 != NULL){
            Maillon* lecture1 = texte1->lecture;
            Maillon* lecture2 = texte2->lecture;
            Maillon* lecture1_temp;
            Maillon* lecture2_temp;
            Maillon* chaine_def = NULL;
            Maillon* chaine_temp = NULL;
            while(lecture1->info != '\n'){
                lecture2 = texte2->lecture;
                while(lecture2->info != '\n'){
                    if(lecture1->info == lecture2->info){
                        lecture1_temp = lecture1;
                        lecture2_temp = lecture2;
                        do{
                            chaine_temp = ajouterelement(chaine_temp, lecture1_temp->info);
                            lecture1_temp = lecture1_temp->next;
                            lecture2_temp = lecture2_temp->next;
                        }while((lecture1_temp->info == lecture2_temp->info) && (lecture1_temp->info != '\n') && (lecture2_temp->info != '\n'));
                        if(chaine_def == NULL){
                            chaine_def = chaine_temp;
                            chaine_temp = NULL;
                        }
                        else{
                            int longueur_temp = longueur_liste(chaine_temp);
                            int longueur_def = longueur_liste(chaine_def);
                                if(longueur_def < longueur_temp){
                                    free_liste(chaine_def);
                                    chaine_def = chaine_temp;
                                    chaine_temp = NULL;
                                }
                                else{
                                    free_liste(chaine_temp);
                                    chaine_temp = NULL;
                                }
                        }
                    }
                    lecture2 = lecture2->next;
                }
                lecture1 = lecture1->next;
            }
            printf("La chaine la plus longue est -> ");
            aff_liste(chaine_def);

        }else{
        printf("Ce texte n'existe pas. Verifier l'orthographe.");
        }
    }else{
        printf("Ce texte n'existe pas. Verifier l'orthographe.");
    }
}


#endif /* fonctions_avance_s_h */
