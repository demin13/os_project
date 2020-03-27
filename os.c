#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int search(int ar[],int ki,int leng){
	int ri,ro;
	for(ri=0;ri<leng;ri++)
	{
		if(ki==ar[ri])
		{
			ro=ri;
			break;
		}
	}
	return ro;
}


void del(int arr[],int ind,int len)
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
	int i,j,n=20;
	time_t t;
	srand(time(&t));     //uses of srand because every time random number will differ
	char n_student[]={'a','b','c','d','e','f','g','h','i','j'};
	int n_shops[n];
	int n_gifts[10];
	for(i=0;i<10;i++)
	{
		n_shops[i]=rand()%50;
		n_gifts[i]=rand()%20;
	}
	for(j=0;j<10;j++)
	{
		printf("No of gifts picked by %c from shop no %d =  %d\n",n_student[j],n_shops[j],n_gifts[j]);
	}
	//billing counter
	int k,l,index=0;
	int n_bill[10];
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
		del(n_gifts,index,(sizeof(n_gifts)/4));
		printf("%d : %c\n",index,n_student[index]);
	}
	for(i=0;i<10;i++)
	{
		printf("%d\n",n_bill[i]);
	}
} 
