#include<iostream>
#include<time.h>
#include<stdlib.h>

void insertionSort(int dizi[],int boyut){
	int once;
	int eleman;

	for (int i = 1; i < boyut; i++) {

		eleman = dizi[i];

		once = i - 1;

		while (once >= 0 && dizi[once] > eleman) {

			dizi[once + 1] = dizi[once];

			once--;
		}
		dizi[once + 1] = eleman;
	}

	 


	
}
	


int main(){



	int numbers[100000];

     srand(time(0));
    
	for (int i = 0; i < 100000; i++) {

		numbers[i] = (rand()% 10000 + 1);


	}


	insertionSort(numbers, 100000);



	for (int i = 0; i < 100000; i++) {

		printf("%d.sayi = %d\n", i+1, numbers[i]);
	}
  
  
    
    
    
	return 0;


}

