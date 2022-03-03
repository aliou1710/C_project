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
	/*tableau */
    int cPrimes; 
};
typedef struct TListPrimes TListPrimes;
/*  TODO ... */

void InitializeTListPrimes(TListPrimes *listPrime);
void Erathostenes(TListPrimes * listPrime);
void ShowPrimes2(TListPrimes * listPrime);
void DestroyTListPrimes(TListPrimes * listPrime);

int main(int argc, char* argv[]) {
    clock_t ct1, ct2;
    /*..struct TListPrimes listPrimes;..*/
	TListPrimes listPrimes;
    do {
        InitializeTListPrimes(&listPrimes);
        listPrimes.maximum = ReadIntLimited("\nVotre naturel maximum ? ", 0, MAX);
		
		
        /*InitializeTListPrimes(&listPrimes);*/
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

void InitializeTListPrimes(TListPrimes *listPrime){
	
	listPrime->maximum = 0 ;
	/*cprimes est un entier, et correspond au nombre de nombre premier qu'on aura */
	listPrime->cPrimes=0;
	/* pPrimes est un tableau */
	listPrime->pPrimes=NULL;
	
	}
	
	
void Erathostenes(TListPrimes *listPrime){
	/*creer un tableau  provisoire qui permet d'allouer de memoire	*/
	uint32 *tab= calloc((((listPrime->maximum-1)/32)+1),sizeof(uint32));
	
	/*variable qu'on va utiliser */
	int  j ;
	int i;
	int k;
	int m;
	int count;

	/*(((listPrime->maximum-1)/32)+1) correspond au nombre de case entier de 32 bits*/
	for(i = 0 ; i< (((listPrime->maximum-1)/32)+1);i++){
		tab[i] = MAX_UINT32; 
		/*la valeur MAX_UINT32 est une valeur qui correspond  au 1111 1111 1111 1111 1111 1111 1111 1111 */
		}
		
	/* je mets le bit 0 -> 0 et aussi 1 ->0*/
	unsetbitarray(tab,0);
	unsetbitarray(tab,1);
	
	
	for( j = 2 ; j< (listPrime->maximum);j++){
		
		/**** si issetbitarray ==1 cvd vrai sinon ==0 cvd faux ****/
		if(issetbitarray(tab,j)){
			/*par pas de i: on enleve touts les multiples d'une valeur*/
			listPrime->cPrimes +=1;
			for(k = j*j ; k<(listPrime->maximum);k+=j){
				/*unset met à faux => met à 0*/
				/*je mets tous les multiples à 0*/
						
				unsetbitarray(tab,k);
			}
		}
}
	 count =0;
	listPrime->pPrimes =malloc(listPrime->cPrimes*sizeof(int)) ;
	
	/*** je mets tous les nombres premiers dans le tableaux pPrimes ***/
	for(i = 0 ; i< (listPrime->maximum);i++){
		  
		if(issetbitarray(tab,i)){
			
			listPrime->pPrimes[count]= i;
			count ++;
			
			}
		}
	free(tab);
}
void ShowPrimes2(TListPrimes * listPrime){
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
void DestroyTListPrimes(TListPrimes * listPrime){
	
	free(listPrime->pPrimes);
	
	}