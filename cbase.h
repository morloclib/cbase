#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

char* foreign_call(char* cmd);

char* packDouble(double x);
double unpackDouble(char* json);

char* packInt(int x);
int unpackInt(char* json);

char* packString(char* x);
char* unpackString(char* x);

char* foreign_call(char* cmd)
{
    FILE *fh = popen(cmd, "r");
    size_t nbytes = sizeof(char) * BUFFER_SIZE;
    size_t i = 1;
    size_t offset = 0;
    char* json;
    char* old_json;
    char* buffer = calloc(BUFFER_SIZE, sizeof(char));
    while (fgets(buffer, BUFFER_SIZE, fh) !=NULL){
        if(i == 1){
            json = malloc(nbytes);
            memcpy(json, buffer, nbytes);
        } else {
            // TODO: make this more memory efficient
            old_json = json;
            offset = (i-1) * nbytes;
            json = malloc(i * nbytes);
            memcpy(json, old_json, offset);
            memcpy(json + offset + 1, buffer, nbytes);
            free(old_json);
        }
        i++;
    }
    pclose(fh);
    free(buffer);
    return json;
}

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
char* packString(char* x){
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
char* unpackString(char* json){
  return json;
}
