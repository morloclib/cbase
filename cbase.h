#include <stdlib.h>
#include <stdio.h>

char* packDouble(double x);
double unpackDouble(char* json);

char* packDouble(double x){
  char* x_str = (char*)malloc(50 * sizeof(char));
  sprintf(x_str, "%g", x);
  return x_str;
}

double unpackDouble(char* json){
  double x;
  sscanf(json, "%lf", &x);
  return x;
}
