#include <stdio.h>
float prix_plein_tarif = 10;
typedef long TypeEntier;
float prix_billet(float billet, int age){
        if(age<=2){
            return billet*0.1;
        }
        else if(age<12){
            return billet*0.5;
        }
        else{
            return billet;
        }
    };
int Exo2(int N){
    if(N<3 || N>18){
        return 0;
    }
    for(int a=1; a<=6; a++){
        for(int b=1; b<=6; b++){
            for(int c=1; c<=6; c++){
                if(a+b+c==N){
                    printf("%i%i%i \n",a,b,c);
                }
            }
        }
    }
    return 0;
} 
int Exo2Ameliore(int N){
    if(N<3 || N>18){
        return 0;
    }
    for(int a=1; a<=6; a++){
        for(int b=1; b<=6; b++){
            if( N-a-b<=6 && N-a-b>=1 ){
                printf("%i%i%i\n", a, b, N-a-b);
            }
        }
    }
    return 0;
}

void Exo3(int N){
    for(int a=1; a<=N; a++){
        int somme =0;
        if(a==1){
            printf("1\n");
        }
        for(int t=1; t<a; t++){
            if(a%t==0){
                somme+=t;
            }
        }
        if(somme==a){
            printf("%i\n", a );
        }
    }

}
TypeEntier factorielle(int a){
    TypeEntier resultat =1;
    for( int b=2; b<=a; b++){
        resultat=b*resultat;
    }
    return resultat;
}

int main(void) {
    printf("%f\n", prix_billet(prix_plein_tarif,2));
    Exo2Ameliore(4);
    Exo3(9);
    for(int i=1; i<=15; i++){
        printf("%li\n", factorielle(i));
        };
    return 0;
}