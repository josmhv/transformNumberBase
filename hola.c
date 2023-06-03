#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

// void base10sum(char* tn, int base) {
//     printf("\n");
//     for (int i = 0; i < strlen(tn); i++) {
//         int expo = strlen(tn) - i - 1;
//         printf("%c", tn[i]);
//         if (!(i == strlen(tn) - 1)) {
//             printf("*%i^%d + ", base, expo);
//         }
//     }
//     printf("\n");
// }

void transformNumberBase(int num, int base) {
    int size = 5;
    char final_num[size]; // 5 = tamaño del numero final ( y de mi co.cc )
    bool keep_dividing = true;
    while(keep_dividing) {
        int cocient = num / base;
        int remainder = num % base;

        char remainder_str[size];
        sprintf(remainder_str, "%d", remainder);
        printf("%s\n", remainder_str);
        strcat(final_num, remainder_str);

        if (cocient < base) {
            printf("%d\n", cocient);
            char cocient_str[size]; // también aumentalo para el cociente
            sprintf(cocient_str, "%d", cocient);
            strcat(final_num, cocient_str);
            printf("DONE\n");
            keep_dividing = false;
        }

        num = cocient;
    }

    char* transformedNumber = strrev(final_num);
    printf("\n%s\n", transformedNumber);
    // base10sum(transformedNumber, base);
    // printf("\n%s\n", transformedNumber);
}


int main(int argc, char* argv[])
{
    char* arg1 = argv[1];
    char *out1;
    long n = strtol(arg1, &out1 , 10);
    char* arg2 = argv[2];
    char *out2;
    long b = strtol(arg2, &out2 , 10);

    int num = (int) n;
    int base = (int) b;

    transformNumberBase(num, base);

    return 0;
}

