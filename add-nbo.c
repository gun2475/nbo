#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

FILE *fp, *fp1;
uint32_t num, num1;

int main(int argc, char *argv[]) {

    fp = fopen(argv[1], "rb");
    fp1 = fopen(argv[2], "rb");

    fread(&num, sizeof(num), 1, fp);
    fread(&num1, sizeof(num1), 1, fp1);

    num = ntohl(num); 
    num1 = ntohl(num1);  

    uint32_t sum = num + num1;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num, num, num1, num1, sum, sum);
    
    fclose(fp);
    fclose(fp1);
    return 0;
}
