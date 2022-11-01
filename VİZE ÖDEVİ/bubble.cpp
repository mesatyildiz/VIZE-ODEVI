#include <iostream>
#include <stdlib.h>
#include<time.h>

void bubbleSort(int dizi[], int boyut) {

	for (int i = 0; i < boyut; i++) {

		for (int j = 1; j < boyut - i; j++) {

			if (dizi[j - 1] > dizi[j]) {

				int temp = dizi[j];

				dizi[j] = dizi[j - 1];

				dizi[j - 1] = temp;
			}
		}
	}

}



int main() {



	int numbers[100000];

    srand(time(0));
    
	for (int i = 0; i < 100000; i++) {

		numbers[i] = (rand() % 10000 + 1);


	}


	bubbleSort(numbers, 100000);



	for (int i = 0; i < 100000; i++) {

		printf("%d.sayi = %d\n", i + 1, numbers[i]);
	}





	return 0;


}

