#pragma once

#include "Setting.h"
#define DATANUM 10000

struct Result {//処理結果を格納する構造体
	char name[CHARBUFF];//アルゴリズム名
	double time;//処理時間

};

void dataInput(char filename[CHARBUFF],int data[DATANUM]);

void bubbleSort(int data[DATANUM]);
void selectionSort(int data[DATANUM]);
void insertionSort(int data[DATANUM]);
void shellSort(int data[DATANUM]);
void quickSort(int data[DATANUM], int l, int r);
void mergeSort(int data[DATANUM], int l, int r);

void sortedDATACSVOut(int data[DATANUM]);
void resultCSVOut(Result result[], int num);