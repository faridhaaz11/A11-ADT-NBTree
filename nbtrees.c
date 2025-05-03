#include <stdio.h>
#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node){
	int i, idx;

	for (i = 0; i < jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
    }

    char nodes[] = {'A','B','C','D','E','F','G','H','I','J'};
    int first_sons[] = {2, 4, 7, 0, 8, 0, 0, 0, 0, 0};
    int next_brothers[] = {0, 3, 0, 5, 6, 0, 0, 9, 10, 0};
    int parents[] = {0, 1, 1, 2, 2, 2, 3, 5, 5, 5};

    for (i = 0; i < Jml_Node; i++) {
        int idx = i + 1;
        X[idx].info = nodes[i];
        X[idx].ps_fs = first_sons[i];
        X[idx].ps_nb = next_brothers[i];
        X[idx].ps_pr = parents[i];
    }
}
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input

boolean IsEmpty (Isi_Tree P){
	if (P[1].info == '\0'){
		return true;	
	}
	return false;
}

/***** Traversal *****/
void PreOrder (Isi_Tree P);

void InOrder (Isi_Tree P);

void PostOrder (Isi_Tree P);

void Level_order(Isi_Tree X, int Maks_node){
	int depth, level, i;
	
	if (IsEmpty(X)){
		return;
	}

    depth = Depth(X);
    
    for (level = 0; level <= depth; level++) {
        for (i = 1; i <= Maks_node; i++) {
            if (X[i].info != '\0' && Level(X, X[i].info) == level) {
                printf("%c ", X[i].info);
            }
        }
    }
}

void PrintTree (Isi_Tree P){
	int count, i;
	
	printf("\nSeluruh Node pada Non Binary Tree:\n");
    count = nbElmt(P);
    for (i = 1; i <= count; i++) {
        printf("--> Indeks ke-%d\n", i);
        printf("info array ke %d    : %c\n", i, P[i].info);
        printf("first son array ke %d   : %d\n", i, P[i].ps_fs);
        printf("next brother array ke %d : %d\n", i, P[i].ps_nb);
        printf("parent array ke %d    : %d\n", i, P[i].ps_pr);
    }
}

boolean Search (Isi_Tree P, infotype X);

int nbElmt (Isi_Tree P){
	int count, i;
	
	count = 0;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int nbDaun (Isi_Tree P);

int Level (Isi_Tree P, infotype X){
	int total, currentLevel, nodeIndex, i;
    
	total = nbElmt(P);
	currentLevel = 0;
    nodeIndex = 0;
    for (i = 1; i <= total; i++) {
        if (P[i].info == X) {
            nodeIndex = i;
            break;
        }
    }
    
    if (nodeIndex == 0) return -1;
    
    int p = nodeIndex;
    while (P[p].ps_pr != 0) {
        currentLevel++;
        p = P[p].ps_pr;
    }
    
    return currentLevel;
}

int Depth (Isi_Tree P){
	int maxDepth, total, i, currentDepth;
	
    
	maxDepth = 0;
	total = nbElmt(P);
    for (i = 1; i <= total; i++) {
        currentDepth = Level(P, P[i].info);
        if (currentDepth > maxDepth) {
            maxDepth = currentDepth;
        }
    }
    
    return maxDepth;
}

int Max (infotype Data1, infotype Data2);

