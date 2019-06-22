#include <stdlib.h>
#include <stdio.h>

char* packDouble(double x);
double unpackDouble(char* json);

char* packInt(int x);
int unpackInt(char* json);

char* packString(char* x);
char* unpackString(char* x);

char* packDouble(double x){
  char* x_str = (char*)malloc(50 * sizeof(char));
  sprintf(x_str, "%lf", x);
  return x_str;
}
char* packInt(int x){
  char* x_str = (char*)malloc(50 * sizeof(char));
  sprintf(x_str, "%ld", x);
  return x_str;
}
char* packString(int x){
  return x;
}

double unpackDouble(char* json){
  double x;
  sscanf(json, "%lf", &x);
  return x;
}
int unpackInt(char* json){
  int x;
  sscanf(json, "%ld", &x);
  return x;
}
int unpackString(char* json){
  return json;
}
