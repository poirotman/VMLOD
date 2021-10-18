#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Matrix{
    int nblignecolonne[2];
    int **Matrice;
};
typedef struct Matrix Matrix;
Matrix *MatrixArray;

Matrix readMatrix(){
    int lignes;
    int colonnes;
    scanf("%i %i", &lignes, &colonnes);
    Matrix matrice;
    matrice.nblignecolonne[0] = lignes;
    matrice.nblignecolonne[1] = colonnes;
    matrice.Matrice=calloc(lignes, sizeof(int*) );
    for(int i=0; i<lignes; i++){
        matrice.Matrice[i]=(int*)calloc(colonnes, sizeof(int));
        for(int y=0; y<colonnes; y++){
            scanf("%i", &(matrice.Matrice[i][y]));
        }
        scanf("\n");
    }
    return matrice;
}

int main(void) {
    int nbMatrice;
    scanf("%i", &nbMatrice);
    Matrix mat;
    mat = readMatrix();
    printf("%i", mat.Matrice[0][1]);
    return 0;
}