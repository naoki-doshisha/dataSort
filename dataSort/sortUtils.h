#pragma once

#include "Setting.h"
#define DATANUM 10000

struct Result {//ˆ—Œ‹‰Ê‚ğŠi”[‚·‚é\‘¢‘Ì
	char name[CHARBUFF];//ƒAƒ‹ƒSƒŠƒYƒ€–¼
	double time;//ˆ—ŠÔ

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