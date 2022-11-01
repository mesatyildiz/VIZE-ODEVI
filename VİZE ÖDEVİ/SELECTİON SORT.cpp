#include <iostream>
#include <stdlib.h>
#include<time.h>
void selectionSort(int dizi[],int boyut){


	int ekindex;

	for (int i = 0; i < boyut; i++) {

		ekindex = i;

		for (int j = i; j < boyut; j++) {

			if (dizi[j] < dizi[ekindex]) {

				ekindex = j;
			}

		}
		int temp = dizi[i];

		dizi[i] = dizi[ekindex];

		dizi[ekindex] = temp;



	}


	 


	
}
	


int main(){



	int numbers[100000];
	
	srand(time(0));

	for (int i = 0; i < 100000; i++) {

		numbers[i] = (rand()% 10000 + 1);


	}


	selectionSort(numbers, 100000);



	for (int i = 0; i < 100000; i++) {

		printf("%d.sayi = %d\n", i+1, numbers[i]);
	}
  
  
    
    
    
	return 0;


}

