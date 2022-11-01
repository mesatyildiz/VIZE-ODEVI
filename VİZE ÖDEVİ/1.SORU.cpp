#include <iostream>
int kattop(){


 int s, a;

        a = 0;

        for (s = 1; s < 1000; s++) {


            if (s % 3 == 0 || s % 5 == 0) {


                a = a + s;

                printf(" = %d\n", a );
            }
    }
}

    int main() {

        kattop();
       
        return 0;
    }

