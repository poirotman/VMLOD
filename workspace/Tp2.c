#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


//Exo 1
void echangeContenue(int *a, int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
}
//Exo 2
bool estConvexe(bool tab[], int length){
short nb_chaine=0;
    for(int64_t i=0;i<length-1;i++){
        if(tab[i]!=tab[i+1]){
            nb_chaine+=1;
        }
        if(nb_chaine>2){
            return false;
        }
        if((nb_chaine==2)&&(tab[0]!=tab[length-1])){
            return false;
        }
    }
    return true;
}

//Exo 3.1
void mult_matrice(int64_t resultat[5][5], int64_t matriceA[5][5], int64_t matriceB[5][5]){
    int resultatCase;
    for(int ligne=0; ligne<5; ligne++){
        for(int colonne=0; colonne<5; colonne++){
            resultatCase=0;
            for(int i=0; i<5; i++){
                resultatCase+= matriceA[ligne][i]*matriceB[i][colonne];
            };
        resultat[ligne][colonne]=resultatCase;    
        };
    };
}
void affiche_matrice(int64_t matrice[5][5]){
    for(int lig=0; lig<5; lig++){
        for(int col=0; col<5; col++){
            printf("%li ", matrice[lig][col]);
        }
        printf("\n");
    }
}

//3.2
//On ne peut utiliser cette fonction qu'avec des matrice 5x5. Elle n'est absolument
//pas générale

//3.3
void mult_matrice_gen(int64_t **resultat, int64_t **matriceA, int64_t **matriceB){
    int resultatCase;
    printf("test1");
    int Colonne1 = sizeof(matriceA[0])/8;
    int Ligne2 = sizeof(matriceB)/8;
    int Colonne2 = sizeof(matriceB[0])/8;
    int Ligne1 = sizeof(matriceA)/8;
    if(Ligne2!=Colonne1){
        printf("Mauvais Calcul");
    }
    else{
        for(int ligne=0; ligne<Ligne1; ligne++){
            for(int colonne=0; colonne<Colonne2; colonne++){
                resultatCase=0;
                for(int i=0; i<Ligne2; i++){
                    printf("test2");
                    resultatCase+= matriceA[ligne][i]*matriceB[i][colonne];
                };
            resultat[ligne][colonne]=resultatCase;    
            };
        };
    }
}

//Exo 4
enum Mois {jan = 1, fev, mars, avr, mai, juin, juil, aout, sept, oct, nov, dec};

struct Date {
int jour;
enum Mois mois;
int annee;
};
typedef enum Mois Mois;
typedef struct Date Date;

void initialiseDate(Date *d){
    printf("Jour :");
    scanf("%i", &d->jour);
    printf("Mois :");
    scanf("%i", (int *)&d->mois);
    printf("Annee :");
    scanf("%i",&d->annee);
}
Date creerDateParCopie(){
    Date d;
    printf("Jour :");
    scanf("%i", &d.jour);
    printf("Mois :");
    scanf("%i", (int*)&d.mois);
    printf("Annee :");
    scanf("%i",&d.annee);
    return d;
}

void afficheDate(Date *d){
    char *Mois;
    switch (d->mois){
    case 1:
        Mois = "janvier";
        break;
    case 2:
        Mois = "frévrier";
        break;
    case 3:
        Mois = "mars";
        break;
    case 4:
        Mois = "avril";
        break;
    case 5:
        Mois = "mai";
        break;
    case 6:
        Mois = "juin";
        break;
    case 7:
        Mois = "juillet";
        break;
    case 8:
        Mois = "août";
        break;
    case 9:
        Mois = "septembre";
        break;
    case 10:
        Mois = "octobre";
        break;
    case 11:
        Mois = "novembre";
        break;
    case 12:
        Mois = "décembre";
        break;
    default:
        break;
    }
    printf("%i %s %i \n", d->jour, Mois, d->annee);
}


int main(void) {
    //Exo1
    int a=10;
    int b=20;
    echangeContenue(&a,&b);
    printf("a= %i et b= %i\n", a, b);

    //Exo 2
    bool test1[5] ={true,false,false,true,false};
    bool test2[7] ={true,true,false,false,false,true,true};
    bool test3[7] ={false,false,false,true,true,true,false};
    bool test4[9] ={true,true,false,false,true,false,false,true,true};
    printf("Le tableau de bool test1 est convexe %s \n",estConvexe(test1,sizeof(test1))? "true":"false");
    printf("Le tableau de bool test2 est convexe %s \n",estConvexe(test2,sizeof(test2))? "true":"false");
    printf("Le tableau de bool test3 est convexe %s \n",estConvexe(test3,sizeof(test3))? "true":"false");
    printf("Le tableau de bool test4 est convexe %s \n",estConvexe(test4,sizeof(test4))? "true":"false");

    //Exo 3.1
    //matrices en ligne * colonne
    int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[5][5];
    mult_matrice(matriceResultat,matrice1,matrice2);
    affiche_matrice(matriceResultat);

    //Exo 4
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &? C'est pour modifier la date directement. Sinon elle ne se modifie pas.
    afficheDate(&d);
    d = creerDateParCopie();
    afficheDate(&d);

    return EXIT_SUCCESS;
}