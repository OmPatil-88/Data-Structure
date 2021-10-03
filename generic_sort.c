#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include<limits.h>
#include<time.h>

#define TRUE 1
#define swap(a,b){a=b+a; b=a-b; a=a-b;}

void input(int* pa,int size);
void output(int* pa,int size,char * msg);

void selection_sort(int *pa,int size);
void bubble_sort(int* pa,int size);

void insertion_sort(int *pa,int size);
void insert_at_pos(int *pa,int n);

void merge_sort(int *pa,int start,int end);
void merge(int *pa,int p,int q,int r);

int partition(int* pa,int p,int r);
void quick_sort(int* pa,int p,int r);

void sort(int* pa,int n,int choice);


int main(int argc,char** argv){

	 
	  if(argc!=3){
	  fprintf(stderr,"Invalid Arguments\n");
	  return (EXIT_FAILURE);
	  }
        
	  int n=10,choice=0;
      int *pa=NULL;
	  
	  n=atoi(argv[1]);
	  if(n==0){
	  fprintf(stderr,"Bad number of element\n");
	  return (EXIT_FAILURE);
	  }
	  
	  choice=atoi(argv[2]);
          if(choice>=5 || choice <=0){
	  fprintf(stderr,"Invalid choice\n");
	  return (EXIT_FAILURE);
	  }

	  pa=(int *)malloc(sizeof(int)*n);
	  
	  if(pa==NULL){
	  fprintf(stderr,"Out of memory \n");
	  return (EXIT_FAILURE);
	  }

      input(pa,n);
	  output(pa,n,"After sort \n");
	  sort(pa,n,choice);
	  output(pa,n,"After sort \n");

	  return (EXIT_SUCCESS);

}

void input(int *pa,int n){
       

	srand(time(0));
	for(int i=0;i<n;i++){
	
		pa[i]=rand()%10000;
	}

}

void output(int *pa,int n,char *msg){

	puts(msg);
	for(int i=0;i<n;i++){
	printf("%d\n",pa[i]);
	}
}

void sort(int *pa,int n,int choice){


	switch(choice){
	
		case 1:
			selection_sort(pa,n);
			break;
		case 2:
			bubble_sort(pa,n);
			break;
		case 3:
			insertion_sort(pa,n);
			break;
		case 4:
			merge_sort(pa,0,n-1);
			break;
		case 5:
		        quick_sort(pa,0,n-1);	
	
	}
}

/*************************************************************/
void selection_sort(int *pa,int n){

	for(int i=0;i<n;i++){
	int min=i;
          for(int j=i+1;j<n;j++){
	     if(pa[min]>=pa[j]){
		 min=j;
	     } 
	   }

	  int temp=pa[i];
	  pa[i]=pa[min];
	  pa[min]=temp;
	}
}
/**************************************************************/
void bubble_sort(int *pa,int n){

	int swapped=1;

	for(int i=n-1;i>=0 && swapped;i--){
	swapped=0;
	    for(int j=0;j<=i-1;j++){
	    
		    if(pa[j]>pa[j+1]){
		    swap(pa[j],pa[j+1]);
		    swapped=1;
		    }
	    }

	}
}

/**************************************************************/

void insert_at_pos(int *pa,int n){

	int key=pa[n-1];
	int i=n-2;
	while(i>-1 && pa[i]>key){
	pa[i+1]=pa[i];
	i--;
	}
	pa[i+1]=key;

}

void insertion_sort(int *pa,int n){

	if(n==2){
	 if(pa[0]>pa[1]){
	   swap(pa[0],pa[1]);
	 }
	 return;
	}

	for(int i=2;i<=n;i++){
	insert_at_pos(pa,i);
	}

}

/**************************************************************/

void merge(int *pa,int p,int q,int r){


	int *pa1 =NULL;
	int *pa2 =NULL;
	int n1;
	int n2;
	int i;
	int j;
	int k;
	int cnt;

	n1=q-p+1;
	n2=r-q;

	pa1=(int*) malloc(n1* sizeof(int));
	if(pa1==NULL){
	fprintf(stderr,"Out of memory\n");
	exit (EXIT_SUCCESS);
	}
        memset(pa1,0,n1*sizeof(int));

	pa2=(int*)malloc(n2*sizeof(int));
	if(pa2==NULL){
	fprintf(stderr,"Out of memory\n");
	exit(EXIT_SUCCESS);
	}
	memset(pa2,0,n2*sizeof(int));

	for(cnt=0;cnt<n1;++cnt)
	pa1[cnt]=pa[p+cnt];
	
	for(cnt=0;cnt<n2;++cnt)
	pa2[cnt]=pa[q+1+cnt];

	i=0;
	j=0;
	k=0;
	
	while(TRUE){
	
		if(pa1[i]<=pa2[j]){

		  pa[p+k]=pa1[i];
                  ++i;
		  ++k;
		   if(i==n1){
		     
			   while(j<n2){
			   pa[p+k]=pa2[j];
			   j++;
			   ++k;
			   }
                    break;
		   }
		}
		else{

		pa[p+k]=pa2[j];
		++j;
		++k;
		if(j==n2){
	           
		while(i<n1){
		
			pa[p+k]=pa1[i];
			++i;
			++k;
		}	
                   break;
		}
	   }
	
	}

	free(pa1);
	pa1=NULL;

	free(pa2);
	pa2=NULL;

}


void merge_sort(int* pa,int p,int r){


	int q;
	if(p<r){
	
		q=(p+r)/2;
		merge_sort(pa,p,q);
		merge_sort(pa,q+1,r);
		merge(pa,p,q,r);
	
	}
}

int partition(int* pa,int p,int r){

	int i,j,tmp,pivot;

	pivot=pa[r];
	i=p-1;

	for(j=p;j<r;++j){
	
		if(pa[j]<=pivot){
		     i=i+1;
		     swap(pa[i],pa[j]);
		}
	}
	swap(pa[i+1],pa[r]);
	return i+1;

}
void quick_sort(int* pa,int p,int r){

	int q;
	if(p<r){
	
		q=partition(pa,p,r);
		quick_sort(pa,p,q-1);
		quick_sort(pa,q+1,r);
	}
}
