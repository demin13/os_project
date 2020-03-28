#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//searching algorithm Big-O(n)
int search(int array[],int keys,int leng){
	int r,t;
	for(r=0;r<leng;r++)
	{
		if(keys==array[r])
		{
			t=r;
			break;
		}
	}
	return t;
}
//deletion of any index from an integer array O(n^2)
void delete_i(int arr[],int ind,int len)
{
	int p,o;
	for(p=0;p<len;p++)
	{
	  if(p==ind)
	  {
	  	for(o=p;o<len;o++)
	  	{
	  		arr[o]=arr[o+1];
		  }
	  	len=len-1;
	  	break;
	    }		
	}
}
//deletion of any index from an character array O(n^2)
void delete_c(char arr[],int ind,int len)
{
	int p,o;
	for(p=0;p<len;p++)
	{
	  if(p==ind)
	  {
	  	for(o=p;o<len;o++)
	  	{
	  		arr[o]=arr[o+1];
		  }
	  	len=len-1;
	  	break;
	    }		
	}
}

int main(){
	int i,j;
	time_t t;
	srand(time(&t));     //uses of srand because every time random number will differ
	char n_student[]={'a','b','c','d','e','f','g','h','i','j'};
	int n_shops[20];
	int n_gifts[10];
	for(i=0;i<10;i++)    //O(n)
	{
		n_shops[i]=rand()%50;
		n_gifts[i]=rand()%30;
	}
	printf("No. of gifts picked by which student and from which shop no :-\n\n");
	for(j=0;j<10;j++)
	{
		printf("No of gifts picked by %c from shop no %d =  %d\n",n_student[j],n_shops[j],n_gifts[j]);
	}
	//At billing counter
	int k,l,index=0;
	int n_bill[10];
	int order_billed[10];
	for(k=0;k<10;k++)
	{
		int key=0;
		for(l=0;l<10-k;l++)
		{
			if(n_gifts[l]>=key)
			{
				key=n_gifts[l];
		    }	
		}
		n_bill[k]=key;
		index=search(n_gifts,key,(sizeof(n_gifts)/4));
		order_billed[k]=n_student[index];
		delete_i(n_gifts,index,(sizeof(n_gifts)/4));
		delete_c(n_student,index,(strlen(n_student)));
		
	}
	printf("\nAt billing counter first preference will be given to those student those are\n");
	printf("having maximum number of gifts and if equal then on FCFS basis:-\n\n");
	for(i=0;i<10;i++)
	{
		printf("billing of student %c as he picked %d gifts.\n",order_billed[i],n_bill[i]);
	}
} 
