#include <stdio.h>
#include "nbtrees.h"

int main() {
	Isi_Tree tree;
    
    Create_tree(tree, jml_maks+1);
    
    int choice;
    do {
        printf("\nMenu Program Non Binary Tree:\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &choice);
        getchar();
        
        infotype searchVal, val1, val2;
        int level;
        switch (choice) {
            case 1:
            	printf("Traversal PreOrder: ");
                PreOrder(tree);
                printf("\n");
                break;
            case 2:
            	printf("Traversal InOrder: ");
                InOrder(tree);
                printf("\n");
                break;
            case 3:
            	printf("Traversal PostOrder: ");
                PostOrder(tree);
                printf("\n");
                break;
            case 4:
                printf("Traversal Level Order: ");
                Level_order(tree, nbElmt(tree));
                printf("\n");
                break;
            case 5:
                PrintTree(tree);
                break;
            case 6:
            	printf("Masukkan nilai node yang ingin dicari: ");
                scanf(" %c", &searchVal);
                if (Search(tree, searchVal)) {
                    printf("Node %c ditemukan dalam tree.\n", searchVal);
                } else {
                    printf("Node %c tidak ditemukan dalam tree.\n", searchVal);
                }
                break;
            case 7:
            	printf("Jumlah daun (leaf): %d\n", nbDaun(tree));
                break;
            case 8:
            	printf("Masukkan nilai node: ");
                scanf(" %c", &searchVal);
                level = Level(tree, searchVal);
                if (level != -1) {
                    printf("Level node %c: %d\n", searchVal, level);
                } else {
                    printf("Node dengan nilai %c tidak ditemukan.\n", searchVal);
                }
                break;
            case 9:
                printf("Kedalaman tree: %d\n", Depth(tree));
                break;
            case 10:
            	printf("Masukkan dua node yang ingin dibandingkan:\n");
                printf("Node 1: ");
                scanf(" %c", &val1);
                printf("Node 2: ");
                scanf(" %c", &val2);
                if (Max(val1, val2) == val1) {
                    printf("Node dengan nilai lebih besar: %c\n", val1);
                } else {
                    printf("Node dengan nilai lebih besar: %c\n", val2);
                }
                break;
            case 11:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 11);
    
    return 0;
}
