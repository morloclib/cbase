# cbase

The base C functions. Only `double` is supported in this stub.

We can test the current code with the following main function:

``` C
#include "cbase.h"

int main(int argc, char * argv[]){
    double x = unpackDouble("123.4") + 100.0;
    char* json = packDouble(x);
    printf("%s\n", json);
    return 0;
}
```
