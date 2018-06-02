#include "Includes/dynaArray.h"

#define INC 	2


DynaArray *createDynaArray(int size){
	if(size <= 0) return NULL;

	DynaArray *a;

	a = malloc(sizeof(DynaArray));
	a->array = malloc(size * sizeof(char *));
	a->length = 0;
	a->size = size;

	return a;
}


static void increaseSize(DynaArray *a){
	if (a->length == a->size){
		a->size *= INC;
    	char **tmp = realloc(a->array, a->size * sizeof(char*));
		if(!tmp){
  			fprintf(stderr, "Erro ao aumentar tamanho do array");
		} else {
  			a->array = tmp;
		}
	}
}


void insertDynaArrayNoCpy(DynaArray *a, char *str){
	increaseSize(a);
	a->array[a->length++] = str;
}


void freeDynaArray(DynaArray *a){
  	free(a->array);
  	free(a);
}


void printDynaArray(DynaArray *a){
	for(int i=0; i < a->length; i++){
		printf("%s\n", a->array[i]);
	}
}
