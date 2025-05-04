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
void PreOrder (Isi_Tree P){
	if (IsEmpty(P)) return;

    int stack[jml_maks];
    int top = -1;
    stack[++top] = 1; 

    while (top >= 0) {
        int idx = stack[top--];
        if (idx == 0) continue;

        printf("%c ", P[idx].info); 

        int child = P[idx].ps_fs;
        int children[jml_maks];
        int childCount = 0;

        while (child != 0) {
            children[childCount++] = child;
            child = P[child].ps_nb;
        }

        for (int i = childCount - 1; i >= 0; i--) {
            stack[++top] = children[i];
        }
    }
}

void InOrder(Isi_Tree P) {
    if (IsEmpty(P)) return;

    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].ps_pr == nil && P[i].info != '\0') { 
            break;
        }
    }

    int stack[jml_maks];
    int top = -1;
    int current = i;
    int visited[jml_maks + 1] = {0};

    while (current != nil || top != -1) {
        while (current != nil && !visited[current]) {
            stack[++top] = current;
            current = P[current].ps_fs; 
        }

        if (top != -1) {
            current = stack[top--];

            if (!visited[current]) {
                printf("%c ", P[current].info);
                visited[current] = 1;
            }

            int first_child = P[current].ps_fs;
            if (first_child != nil) {
                current = P[first_child].ps_nb; 
            } else {
                current = nil;
            }
        }
    }
}


void PostOrder (Isi_Tree P){
	if (IsEmpty(P)) return;

    int stack1[jml_maks], stack2[jml_maks];
    int top1 = -1, top2 = -1;
    stack1[++top1] = 1;

    while (top1 != -1) {
        int idx = stack1[top1--];
        stack2[++top2] = idx;

        int child = P[idx].ps_fs;
        while (child != 0) {
            stack1[++top1] = child;
            child = P[child].ps_nb;
        }
    }

    while (top2 != -1) {
        printf("%c ", P[stack2[top2--]].info);
    }
}

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
        printf("\n--> Indeks ke-%d\n", i);
        printf("info array ke %d    : %c\n", i, P[i].info);
        printf("first son array ke %d   : %d\n", i, P[i].ps_fs);
        printf("next brother array ke %d : %d\n", i, P[i].ps_nb);
        printf("parent array ke %d    : %d\n", i, P[i].ps_pr);
    }
}

boolean Search (Isi_Tree P, infotype X){
	int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

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

int nbDaun (Isi_Tree P){
	int i, count = 0;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == 0) {
            count++; // Tidak punya anak, berarti daun
        }
    }
    return count;
}
	
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

int Max (infotype Data1, infotype Data2){
	return (Data1 > Data2) ? Data1 : Data2;
}

