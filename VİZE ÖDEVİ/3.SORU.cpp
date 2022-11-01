#include <iostream>
#include <stdlib.h>
#include<time.h>

int main() {


    srand(time(0));

	int numbers[100000];

	for (int i = 0; i < 100000; i++) {

		numbers[i] = (rand() % 10000 + 1);


	}





	for (int i = 0; i < 100000; i++) {

		printf("%d.sayi = %d\n", i + 1, numbers[i]);
	}





	return 0;


}

