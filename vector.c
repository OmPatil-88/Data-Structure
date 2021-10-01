#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct int_vec vector;

typedef int ret_t;

struct int_vec{

	int *vec;
	int length;
};

vector* create_vector();
ret_t push_back(vector* ,int);
ret_t pull_back(vector*);
ret_t destroy_vec(vector*);
void show_vec(vector*);

int main(){

	vector* pvec=NULL;

	pvec=create_vector();
	for(int i=1;i<11;i++){
	push_back(pvec,i*10);
	}
	show_vec(pvec);

	for(int i=0;i<5;i++){
	pull_back(pvec);
	}
	
	show_vec(pvec);

	destroy_vec(pvec);

	return 0;
}


vector* create_vector(){

	vector* p=NULL;
        p=(vector*)malloc(sizeof(vector));
        if(p==NULL){
	fprintf(stderr,"Failed to malloc\n");
	exit(EXIT_FAILURE);
	}
	p->vec=NULL;
	p->length=0;
}

ret_t push_back(vector* p_vec,int data){

	p_vec->vec=realloc(p_vec->vec,sizeof(int)*(p_vec->length+1));
	if(p_vec->vec==NULL){
	fprintf(stderr,"Failed to realloc\n");
	exit(EXIT_FAILURE);
	}
        
	p_vec->vec[p_vec->length]=data;
	p_vec->length++;
	return EXIT_SUCCESS;
}

ret_t pull_back(vector* p_vec){

	p_vec->vec=realloc(p_vec->vec,sizeof(int)*(p_vec->length-1));
	if(p_vec->vec==NULL){
	fprintf(stderr,"Failed to realloc\n");
	exit(EXIT_SUCCESS);
	}
	p_vec->length--;
}


ret_t destroy_vec(vector* p_vec){

	free(p_vec->vec);
	p_vec->vec=NULL;
	p_vec->length=0;
	free(p_vec);
	p_vec=NULL;
}

void show_vec(vector * p_vec){

	for(int i=0;i<p_vec->length;i++){
	
	  printf(" %d ",p_vec->vec[i]);
	}
	puts(" ");
}
