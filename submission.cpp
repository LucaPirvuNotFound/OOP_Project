#include <cstdio>

int is_prime(int p) {
    if((p % 2 == 0 || p % 3 == 0) && p > 3)
        return 0;
    for(int i = 6; (i + 1) * (i + 1) < p * p; i += 6) {
        if( p % (i - 1) == 0 || p % (i + 1) == 0)
            return 0;
    }
    return p > 1;
}

int main() {
    int p;
    printf("Introduceti un numar: ");
    scanf("%i", &p);

    if(is_prime(p))
        printf("Numarul %i este prim\n", p);
    else
        printf("Numarul %i nu este prim\n", p);
    return 0;
}
