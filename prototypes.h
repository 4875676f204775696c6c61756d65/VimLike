//
//  prototypes.h
//  SDD projet 1 : Editeur de texte. Hugo et Loïc.
//
//  Created by Hugo GUILLAUME on 15/10/2019.
//  Copyright © 2019 Hugo GUILLAUME. All rights reserved.
//

#ifndef prototypes_h
#define prototypes_h
#include "structures & fonctions_listes.h"

char menu(void);
void fonction_controle(void);



void vider_buffer(void);
void free_liste(Maillon* liste);
void free_texte(Texte* texte);
int min_3nombres(int compteur1, int compteur2, int compteur3);
int longueur_liste(Maillon* liste);
int comparer_texte(Maillon* liste_1, Maillon* liste_2);



Maillon* creer_maillon(char ajout);
void aff_liste(Maillon * liste);
Maillon *ajouterelement(Maillon* liste, char ajout);
Position *ajouterelement_int(Position* liste, int ajout);
Position *ajouterelement_int(Position* liste, int ajout);



Maillon * entrer_texte(void);
Maillon* entrer_titre(void);

Texte* creer_texte(Texte* precedent);
Texte* ajouter_texte(Texte* init_texte);
Texte* choix_texte(Texte* controle);

void aff_texte(Texte* controle);
void copier_texte(Texte* controle);
void concatener_texte(Texte* controle);
void remplacer_element(Texte* controle);
void insertion_texte(Texte** controle);
void appel_levenstein(Texte* controle);
void suppression_texte(Texte* controle);
void liste_titre(Texte* arbre);
void rechercher_ocurence(Texte* controle);



void creer_txt(Texte* texte);
Texte* recuperer_fichiertxt(Texte* texte);


void appel_levenstein(Texte* controle);
void plus_longue_sous_chaine(Texte* controle);
int levenstein(Maillon* liste1, Maillon* liste2);


#endif /* prototypes_h */
