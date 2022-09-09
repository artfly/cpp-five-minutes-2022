#include <assert.h>
#include <stddef.h>

// напишите функцию bsearch, которая находит 
// в отсортированном по возрастанию массиве 'arr' заданное число 'n'
// и возвращает указатель на элемент в массиве
// если такого числа нет в массиве, то возвращает NULL
// можно написать функцию "примерно", главное сама идея решения
int * bsearch(int * arr, int size, int n) {
    int cur = size / 2;
    // for (int i = 0; i < log2(size); i++) {
    //     if (arr[cur] == n) return arr + cur;
    //     else if (arr[cur] < n) { 
    //         cur += cur / 2;
    //         continue;
    //     }
    //     else {
    //         cur -= cur / 2;
    //     }
    // }

    int l = 0;
    int r = size;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (arr[mid] == n) return arr + mid;
        if (arr[mid] > n) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    // if (arr[r] == )
    // if (arr[l] == )

    return NULL;
}


int main() {
    int arr[] = {1, 3, 4, 5};
    assert(*bsearch(arr, 4, 4) == 4);
}


