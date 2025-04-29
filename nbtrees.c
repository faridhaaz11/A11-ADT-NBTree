#include <stdio.h>
#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola
Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter
input

boolean IsEmpty (Isi_Tree P);

/***** Traversal *****/
void PreOrder (Isi_Tree P);

void InOrder (Isi_Tree P);

void PostOrder (Isi_Tree P);

void Level_order(Isi_Tree X, int Maks_node);

void PrintTree (Isi_Tree P);

boolean Search (Isi_Tree P, infotype X);

int nbElmt (Isi_Tree P);

int nbDaun (Isi_Tree P);

int Level (Isi_Tree P, infotype X);

int Depth (Isi_Tree P);

int Max (infotype Data1, infotype Data2);
