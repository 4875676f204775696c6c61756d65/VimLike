//
//  fonctions_annexes.h
//  SDD projet 1 : Editeur de texte. Hugo et Loïc.
//
//  Created by Hugo GUILLAUME on 15/10/2019.
//  Copyright © 2019 Hugo GUILLAUME. All rights reserved.
//

#ifndef fonctions_annexes_h
#define fonctions_annexes_h

//cette fonction nettoie la memoire d'une structure maillon, necessaire car on a mallloc.
void free_liste(Maillon* liste){
    if(liste == NULL){
        return;
    }
    if(liste->next == NULL){
        free(liste);
    }
    else{
        free_liste(liste->next);
        free(liste);
    }
}


//cette fonction nettoie la memoire d'une structure texte, necessaire car on a mallloc.
void free_texte(Texte* texte){
    if(texte == NULL){
        return;
    }
    if(texte->next == NULL){
        free_liste(texte->lecture);
        free_liste(texte->titre);
        free(texte);
    }
    else{
        free_liste(texte->lecture);
        free_liste(texte->titre);
        free_texte(texte->next);
        free(texte);
    }
}

//vide le  buffer on s'en sert apres un scanf ou un getchar
void vider_buffer(){
    char vide;
    do{
        vide = getchar();
    }while(vide != '\n' && vide != EOF);
}

//cette fonction retourne le minimum entre 3 nombres
int min_3nombres(int compteur1, int compteur2, int compteur3){
    if((compteur1 <= compteur2) && (compteur1 <= compteur3))
       return compteur1;
    else if ((compteur2 <= compteur1) && (compteur2 <= compteur3))
        return compteur2;
    else
        return compteur3;
}

//retourne la longeur d'une liste chaine de type maillon
int longueur_liste(Maillon* liste){
    if(liste == NULL){
        return 0;
    }
    else{
        return 1 + longueur_liste(liste->next);
    }
}

#endif /* fonctions_annexes_h */
