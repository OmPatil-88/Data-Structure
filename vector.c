//Vector in c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct int_vec vector;
typedef int ret_t;

struct int_vec{
	int *vec;
	int length;
};

vector* create_vector();
ret_t push_back(vector *,int data);
ret_t pull_back(vector*);
ret_t destroy_vec(vector*);
void show_vec(vector*);

int main(){

	vector* pvec=NULL;
	pvec=create_vector();

	for(int i=1;i<11;i++)
	push_back(pvec,i*10);

	show_vec(pvec);

	for(int i=0;i<5;i++)
        pull_back(pvec);

	show_vec(pvec);

	destroy_vec(pvec);

	return 0;
}


vector* create_vector(){

	vector* p=NULL;

	p=(vector*)malloc(sizeof(vector));
	if(p==NULL){
	fprintf(stderr,"Out of Memeory\n");
	exit(EXIT_FAILURE);
	}

	p->vec=NULL;
	p->length=0;
}

ret_t push_back(vector *pvec,int data){


	pvec->vec=realloc(pvec->vec,sizeof(int)*pvec->length+1);
        
	if(pvec->vec==NULL){
	fprintf(stderr,"Out of memory\n");
	exit (EXIT_FAILURE);
	}

	pvec->vec[pvec->length]=data;
        pvec->length++;
        
        return EXIT_SUCCESS;
}

ret_t pull_back(vector *pvec){

	pvec->vec[pvec->length-1]=0;
	pvec->vec=realloc(pvec->vec,sizeof(int)*(pvec->length-1));
	pvec->length--;
	return EXIT_SUCCESS;
}

ret_t destroy_vec(vector *pvec){

	free(pvec->vec);
	pvec->vec=NULL;
	pvec->length=0;
	free(pvec);
	pvec=NULL;
}

void show_vec(vector* pvec){

	for(int i=0;i<pvec->length;i++){
	
		printf(" %d ",pvec->vec[i]);
	}
	puts(" ");
}
