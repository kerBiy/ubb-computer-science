#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* myFile = fopen("input.txt", "r");

    int row, col;
    fscanf(myFile, "%d %d", &row, &col);
    
    int** mat = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; ++i) {
        mat[i]  = (int*)malloc(col * sizeof(int));
        for (int j = 0; j < col; ++j) {
            fscanf(myFile, "%d", &mat[i][j]);
        }
    }
   
    fclose(myFile);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; ++i) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
