/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : 13224087
 *   Nama File           : soal1.c
 *   Deskripsi           : Kode ini merupakan solusi dari Praktikum EL2008, Modul 3, Soal 1, yaitu Sensor Badai Dinamis. Masalah ini akan menerima input nilai suatu input elemen integer yang jumlahnya tak diketahui, serta input akan berakhir ketika user memasukkan nilai -1. Dari nilai yang diinput (selin -1), perlu distore di sebuah dynamic array. Setelah itu, dynamic array perlu disort dan ditentukan mediannya. Objektif keluaran dari program adalah COUNT, SORTED ARRAY, dan MEDIAN. 
 */

#include <stdio.h>
#include <stdlib.h>

// https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
void bubbleSort(int* arr, int n){
    int i, j;
    int isSwap;
    for (i = 0; i < n - 1; i++) {
        isSwap = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                isSwap = 1;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (isSwap == 0)
            break;
    }
}

// https://www.geeksforgeeks.org/c/find-median-of-numbers-in-an-array-in-c/
float findMedian(int *sortedArr, int n) {
  	// If even, median is the average of the two
  	// middle elements
    if (n % 2 == 0) {
        return (sortedArr[n / 2 - 1] + sortedArr[n / 2]) / 2.0;
    }
  
  	// If odd, median is the middle element
  	else {
        return sortedArr[n / 2];
    }
}

int main (void){

    int *arr = NULL; // deklarasi buat ukuran untuk 0 elemen terlebih dahulu
    int count = 0;

    int inp;

    // menerima input pertama
    scanf("%d", &inp);
    
    while(inp != -1){
        arr = (int*)realloc(arr, (count+1) * sizeof(int)); // realloc untuk menambah ukuran array sebesar +1 elemen

        arr[count] = inp; // mengubah nilai elemen pada array menjadi nilai input

        count++; // menambah nilai count dengan +1

        scanf("%d", &inp); // menerima input kembali
    }

    bubbleSort(arr, count); // sorting dynamic array


    if(count % 2 == 0){
        // even number of element, then the MEDIAN value is a decimal

        float MEDIAN = findMedian(arr, count); // memperoleh nilai median

        // format output
        printf("COUNT %d ", count);
        printf("SORTED");
        for(int i = 0; i < count; i++){
            printf(" %d", arr[i]);
        }
        printf(" ");
        printf("MEDIAN %.2f\n", MEDIAN);
    }
    else {
        // odd number of element, then the MEDIAN value is an integer
        int MEDIAN = (int)findMedian(arr, count);

        printf("COUNT %d ", count);
        printf("SORTED");
        for(int i = 0; i < count; i++){
            printf(" %d", arr[i]);
        }
        printf(" ");
        printf("MEDIAN %d\n", MEDIAN);
    }

    return 0;
}

// source used: 
// https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
// https://www.geeksforgeeks.org/c/find-median-of-numbers-in-an-array-in-c/