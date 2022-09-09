#include <assert.h>

// напишите функцию swap, которая меняет значение двух чисел

void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 42;
    int b = 13;
    // напишите вызов swap здесь для a и b
    swap(&a, &b);
    assert(a == 13);
    assert(b == 42); 
}


