#include <iostream>
#include <sstream>
#include <math.h>

int fonks(){

    int a, s, tk, sonuc, e, t;

    a = 0;


    for (s = 0; s <= 100; s++) {

        a = a + s;

        tk = a * a;
    }

    t = 0;


    for (e = 0; e <= 100; e++) {

        t = (t + (e * e));
    }

    sonuc = tk - t;


    printf("sonuc=%d", sonuc);
}

int main() {
    
  fonks();

    return 0;
}

