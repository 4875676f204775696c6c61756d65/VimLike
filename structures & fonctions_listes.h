//
//  structures & fonctions_listes.h
//  SDD projet 1 : Editeur de texte. Hugo et Loïc.
//
//  Created by Hugo GUILLAUME on 15/10/2019.
//  Copyright © 2019 Hugo GUILLAUME. All rights reserved.
//

#ifndef structures___fonctions_listes_h
#define structures___fonctions_listes_h

typedef struct S_Maillon{
    char info;
    struct S_Maillon* next;
}Maillon;

//(‡ changer en doublement chainÈ)
typedef struct S_texte{
    Maillon* titre;
    Maillon* lecture;
    struct S_texte* next;
    struct S_texte* prec;
}Texte;

typedef struct S_position{
    int position;
    struct S_position* suivant;
}Position;

//Cette fonction retourne un pointeur vers un maillon nouvellement créé
Maillon* creer_maillon(char ajout){
    Maillon* temp = malloc(sizeof(Maillon));
    temp->info = ajout;
    temp->next = NULL;
    return temp;
}

//Cette fonction retourne un pointeur vers une structure position nouvellement créé
Position* creer_maillon_int(int ajout){
    Position* temp = malloc(sizeof(Position));
    temp->position = ajout;
    temp->suivant = NULL;
    return temp;
}


// cette fonction affiche une liste chaine
void aff_liste(Maillon * liste){
    if(liste == NULL){
        printf("La liste est vide.");
    }
    else if(liste->next == NULL){
        printf("%c \n", liste->info);
    }
    else{
        printf("%c", liste->info);
        aff_liste(liste->next);
    }
}


// cette fonction ajoute des element a la liste chaine de maillon
Maillon *ajouterelement(Maillon* liste, char ajout){
   
    if(liste == NULL){
        liste = creer_maillon(ajout);
    }
    else{
        Maillon * temp = liste;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = creer_maillon(ajout);
    }
    return liste;
}

// ajoute des element a la liste chaine de position
Position *ajouterelement_int(Position* liste, int ajout){
   
    if(liste == NULL){
        liste = creer_maillon_int(ajout);
    }
    else{
        Position * temp = liste;
        while(temp->suivant != NULL){
            temp = temp->suivant;
        }
        temp->suivant = creer_maillon_int(ajout);
    }
    return liste;
}


#endif /* structures___fonctions_listes_h */
