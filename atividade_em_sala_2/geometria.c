#include "geometria.h"

float area_circulo(float raio){
    float pi = 3.14159;
    return pi * raio * raio;
}

float area_triangulo(float base, float altura){
    return (base * altura) / 2.0;
}

float area_retangulo(float base, float altura){
    return base * altura;
}
