/*
 ============================================================================
 Name        : ErathostenesDyna.c
 Author      : Diallo Aliou
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "inout.h"
/*librairie ajoutée*/
#include <inttypes.h>


/* typedef short int bool; */
typedef unsigned char bool;
#define false 0
#define true 1


#define MAX 2147483647       /* (2^31-1) */

/*variable que je defini*/

/*on met des 111111111 parceaque c'est le max */
#define MAX_UINT32 4294967295
struct TListPrimes {
    /*taille*/
	int  maximum; 
	/*pointeur <=> tableau des nombres premier*/
    int * pPrimes;
	/* */
    int cPrimes; 
};
typedef struct TListPrimes TListPrimes;
/*  TODO ... */

void InitializeTListPrimes(TListPrimes* listPrime);
void Erathostenes(TListPrimes* listPrime);
void ShowPrimes2(TListPrimes* listPrime);
void DestroyTListPrimes(TListPrimes* listPrime);

int main(int argc, char* argv[]) {
    clock_t ct1, ct2;
    /*..struct TListPrimes listPrimes;..*/
	TListPrimes listPrimes;
    do {
        InitializeTListPrimes(&listPrimes);
        listPrimes.maximum = ReadIntLimited("\nVotre naturel maximum ? ", 0, MAX);
		
		ct1 = clock();
        Erathostenes(&listPrimes);
        ct2 = clock();
		
        printf("Durée calculs : %.2f\n", (double)(ct2 - ct1) / CLOCKS_PER_SEC);
        ShowPrimes2(&listPrimes);
        /*ShowPrimes(&listPrimes);*/
        DestroyTListPrimes(&listPrimes);
    } while(!Stop());
    return EXIT_SUCCESS;
}


typedef unsigned int uint32;
#define setbitarray(pba, i) (pba[i >> 5] |= (0x00000001 << (i & 0x0000001F)))
#define unsetbitarray(pba, i) (pba[i >> 5] &= ~(0x00000001 << (i & 0x0000001F)))
#define issetbitarray(pba, i) (pba[i >> 5] & (0x00000001 << (i & 0x0000001F)))

/*  TODO ... */

void InitializeTListPrimes(TListPrimes* listPrime){
	
	listPrime->maximum = 0 ;
	/*cprimes est un entier, et correspond au nombre de nombre premier qu'on aura */
	listPrime->cPrimes=0;
	/* pPrimes est un tableau */
	listPrime->pPrimes=NULL;
	
	}
	
	
void Erathostenes(TListPrimes* listPrime){
	/*LOGIQUE INVERSE*/
		
	/*on enumere le nombre de case et on met chaque bit à 0*/
	uint32 *ui = calloc(((listPrime->maximum-1)/32)+1 , sizeof(uint32));
	
		/*variable qu'on va utiliser */
	int64_t  i;
	int64_t  j;
	int64_t  k;
	int64_t  m;
	int64_t n;
	int count;
	int racine;
	
	
	/*on met le bit 0 à 1 et le bit de 1 à 1*/
	setbitarray(ui,0);
	setbitarray(ui,1);
	
	/*on met tout les multiples de 2 à 1 */
		n=2;
		for(k = n*n; k<=listPrime->maximum; k+=n ){
				/*on met le bit k à 1*/
				setbitarray(ui, k);
				}
		/*2 est un nombre premier*/
		listPrime->cPrimes++;
	
	
	racine= sqrt(listPrime->maximum);
	
	for(j = 3; j<=listPrime->maximum; j+=2 ){
		
		if(!(issetbitarray(ui, j))){
			
			/*on incremente cprimes*/
			listPrime->cPrimes++;
			/*si on depasse la valeur de la racine , ça ne sert à rien de calculer ces multiples*/
			if(j<=racine){
			/*On met les bits  multiples de j  à 0*/
			
			for(i=j*j; i<=listPrime->maximum; i+=(2*j) ){
				
				
				/*on met le bit k à 1*/
				setbitarray(ui, i);
				
				}
		}
	  }
	}
	listPrime->pPrimes= malloc(listPrime->cPrimes*sizeof(int));
	 count= 0 ;
	 
	 /*On encode dans le tableau pPrimes, les bits qui sont à 1*/
	for(m = 0;m <= listPrime->maximum; m++ ){
		if(!(issetbitarray(ui, m))){
		/*si le bit ==0 on met m dans le tableau*/
			listPrime->pPrimes[count]=m;	
			count++;
			
		}
	}
	/*libere l'espace*/
	free(ui);
	
}
void ShowPrimes2(TListPrimes* listPrime){
	int i;
	
	printf("Il y a %d nombre premiers inferieurs à %d: \n", listPrime->cPrimes,listPrime->maximum);
	
		if(listPrime->cPrimes <= 20){
		for( i =0 ; i< listPrime->cPrimes ;i++){
		
			
		printf("	Nombre premier n     %d :         %d \n", (i+1),listPrime->pPrimes[i]);

			}
		
		
		}else if(listPrime->cPrimes > 20){
			
		for( i =0 ; i< 10 ;i++){
		
			
		printf("	Nombre premier n     %d :         %d \n", (i+1),listPrime->pPrimes[i]);

			}
			printf("...\n");
			for( i =listPrime->cPrimes-10 ; i< listPrime->cPrimes ;i++){
		
			
		printf("	Nombre premier n     %d :         %d \n", (i+1),listPrime->pPrimes[i]);

			}
			
			}
	
	
	
	
	
	}
void DestroyTListPrimes(TListPrimes* listPrime){
	
	free(listPrime->pPrimes);
	
	}