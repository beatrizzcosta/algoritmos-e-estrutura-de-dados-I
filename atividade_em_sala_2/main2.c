#include <stdio.h>
#include "conversor.h"

int main(void) {
    float metros;
    printf("digite o valor em metros: ");
    scanf("%f", &metros);
    
    float cm = metros_para_centimetros(metros);
    float km = metros_para_quilometros(metros);
    float mm = metros_para_milimetros(metros);
    
    printf("centimetros: %.2f\n", cm);
    printf("quilometros: %.4f\n", km);
    printf("milimetros: %.2f\n", mm);
    
    return 0;
}
