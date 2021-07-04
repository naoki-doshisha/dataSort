#include <iostream>
#include "Setting.h"
#include "sortUtils.h"

void dataInput(char fileName[CHARBUFF], int data[DATANUM]) {
    FILE* fp;
    char s[BUFFSIZE];
    errno_t error;
    error = fopen_s(&fp, fileName, "r");//fp<-file
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {
        int i = -1;
        char* p1; // char型ポインタワーク
        char delim[] = ", ";//デリミタ(複数渡せる)ここではカンマと空白
        char* ctx;
        double count = 0;//日数
        while (fgets(s, BUFFSIZE, fp) != NULL) {
            if (i >= 0) {
                //== 変換処理(スペース区切りで分割した文字列の数値変換)==
                p1 = strtok_s(s, delim, &ctx); // 1個目の部分文字列取得

                        int tmp = atof(p1);
                        data[i] = tmp;
            }
            i++;
        }
        fclose(fp);
    }
}
/*バブルソート*/
void bubbleSort(int data[DATANUM]) {
    int i, j;
    for (i = 0; i < (DATANUM - 1); i++) {
        for (j = (DATANUM - 1); j > i; j--) {
            if (data[j] < data[j - 1]) {
                int temp= data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
        }
    }
}
/*選択ソート*/
void selectionSort(int data[DATANUM]) {
    int i, j, m, min;

    for (i = 0; i < DATANUM - 1; i++) {
        m = i;
        for (j = i + 1; j <DATANUM; j++) {
            if (data[j] < data[m]) {
                m = j;
            }
        }
        min = data[m];
        data[m] = data[i];
        data[i] = min;
    }
}
/*挿入ソート*/
void insertionSort(int data[DATANUM]) {
    int i, j, temp;

    for (i = 1; i < DATANUM; i++) {
        temp = data[i];
        j = i - 1;

        while ((j >= 0) && (data[j] > temp)) {
            data[j + 1] =data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}
/*シェルソート*/
void shellSort(int data[DATANUM]) {
    int i, j, h, temp;
    for ( h = DATANUM / 2; h > 0; h /= 2) {
        for (i = h; i < DATANUM; i += 1) {
            int temp= data[i];

            int j;
            for (j = i; j >= h && data[j - h] > temp; j -= h) {
                data[j] = data[j - h];
            }

            data[j] = temp;
        }
    }
}
/*クイックソート*/
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int  data[DATANUM], int l, int r) {
    int pivot = data[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (data[j] <= pivot) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[r]);
    return (i + 1);
}

void quickSort(int data[DATANUM], int l, int r) {
    if (l < r) {
        int pivot = partition(data, l, r);
        quickSort(data, l, pivot - 1);
        quickSort(data, pivot + 1, r);
    }
}
/*マージソート*/
void merge(int data[DATANUM], int l, int m, int r) {
    int i, j, k;

    int n1 = m - l + 1;  // number of elements in first subarray
    int n2 = r - m;      // number of elements in second subarray

    // create temporary subarrays
    int L[DATANUM];  // array[l..m]
    int R[DATANUM];  // array[m+1..r]

    // copy data to subarrays L and R 
    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] =data[m + 1 + j];

    // merge the two arrays
    i = 0;    // index of L
    j = 0;    // index of R
    k = l;    // index of merged array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
           data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int data[DATANUM], int l, int r) {

    if (l < r) {
        // avoids overflow for large l and h
        int m = l + (r - l) / 2;

        mergeSort(data, l, m);
        mergeSort(data, m + 1, r);
        merge(data, l, m, r);
    }

}
void sortedDATACSVOut(int data[DATANUM]) {
    FILE* fp;
    errno_t error;
    char filename[BUFFSIZE];
    sprintf_s(filename, "sortedData.csv");
    error = fopen_s(&fp, filename, "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {
        fprintf(fp, "ソート済みのデータ\n");
        for (int i = 0; i < DATANUM; i++) {
            fprintf(fp, "%d\n", data[i]);
        }
        fclose(fp);
    }
}
void resultCSVOut(Result result[],int num) {
    FILE* fp;
    errno_t error;
    char filename[BUFFSIZE];
    sprintf_s(filename, "resultData.csv");
    error = fopen_s(&fp, filename, "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {
        fprintf(fp, "アルゴリズム,時間\n");
        for (int i = 0; i < num; i++) {
            fprintf(fp, "%s,%lf\n",result[i].name, result[i].time);
        }
        fclose(fp);
    }
}