#pragma once

#include "Setting.h"
#define DATANUM 1000

struct Result {
	char name[CHARBUFF];
	double time;

};

void dataInput(char filename[CHARBUFF],int data[DATANUM]);

void bubbleSort(int data[DATANUM]);
void selectionSort(int data[DATANUM]);
void insertionSort(int data[DATANUM]);
void shellSort(int data[DATANUM]);
void mergeSort(int data[DATANUM], int l, int r);
void sortedDATACSVOut(int data[DATANUM]);