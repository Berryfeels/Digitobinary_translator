#include <unistd.h>
#include <stdio.h>

void print_bits(unsigned char octet)
{
    char byte[9] = "00000000";
    int n = octet;
    int i = 0;
    int relate = 128;
    int rest = 0;

    printf("n is: %i\n", n);
    while(relate > n){
        relate /= 2;
        i ++;
    }
    byte[i++]= '1';
    printf("relate is: %i\n", relate);
    rest = relate / 2;
    while(rest >= 2 && relate != n){
        while((relate + rest) > n){
            rest /=2;
            printf("Rest is: %i\n", rest);
            i++;
        }
        byte[i] = '1';
        relate = relate + rest;
        rest /= 2;
        printf("relate is: %i\n", relate);
        i++;
    }
    if (relate + rest == n) 
        byte[7] = '1';
        i = 0;
        while(byte[i])
            write(1, &byte[i++], 1);

}

int main()
{
    unsigned char octet = 222;
    print_bits(octet);
    return 0;
}