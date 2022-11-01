#include<iostream>
#include<time.h>
#include<stdlib.h>

void quickSort(int dizi[], int bas, int bts){
	
	int i,j,pivot,temp;
	i= bas;
	j= bts;
	pivot = dizi[(i+j)/2];
	
	do {
		
		while(dizi[i]<pivot)
		i++;
		while(dizi[j]> pivot)
		j--;
		if( i<=j){
			
			temp= dizi[i];
			dizi[i]=dizi[j];
			dizi[j] = temp;
			i++;
			j--;
		}
	}while(i<j);
	if(i<bts)
	quickSort(dizi,i,bts);
	if(bas<j)
	quickSort(dizi,bas,j);
	
	
	
	
}





int main() {



	int numbers[100000];

    srand(time(0));
    
	for (int i = 0; i < 100000; i++) {

		numbers[i] = (rand() % 10000 + 1);


	}


	quickSort(numbers,0,99999);



	for (int i = 0; i < 100000; i++) {

		printf("%d.sayi = %d\n", i + 1, numbers[i]);
	}





	return 0;


}

