// dataSort.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "Setting.h"
#include "sortUtils.h"
#include <time.h>

#define MAXSIZE 100

int main()
{
	char directory[CHARBUFF];
	char returnValue[CHARBUFF];

	int data[DATANUM] = {};
	Result result[MAXSIZE];

	getCurrentDirectory(directory);
	if (readChar("data", "data2", "none", returnValue, directory)) {
		printf("%s\n", returnValue);
	}
	dataInput(returnValue, data);


	int algo = 0;
	int index = 0;
	char type[6][CHARBUFF] = { "バブルソート","選択ソート","挿入ソート","シェルソート","クイックソート","マージソート" };
	printf("アルゴリズムを選択してください（aとｄでアルゴリズム変更。ｓで決定。ｑでシミュレーション終了。）\n");
	while (1) {
		int cdata[DATANUM];
		memcpy(cdata, data, sizeof(data));//配列をコピー(引数の最後はsizeofでないとうまくコピーできない）
		printf("\r%s", type[algo]);
		int key = getchar();
		if (key == 'q') break;
		switch (key) {
		case 'a':
			if (algo > 0) {
				algo--;
			}
			else {
				algo = 5;
			}
			break;
		case 'd':
			if (algo < 5) {
				algo++;
			}
			else {
				algo = 0;
			}
			break;

		}
		if (key == 's') {
			clock_t startTime = clock();
			switch (algo)
			{
			case 0:
				bubbleSort(cdata);
				break;
			case 1:
				selectionSort(cdata);
				break;
			case 2:
				insertionSort(cdata);
				break;
			case 3:
				shellSort(cdata);
				break;
			case 4:
				quickSort(cdata, 0, DATANUM - 1);
				break;
			case 5:
				mergeSort(cdata, 0, DATANUM - 1);
				break;
			default:
				break;
			}
			clock_t endTime = clock();
			double time = endTime - startTime;
			strcpy_s(result[index].name, type[algo]);//文字列をコピー
			result[index].time = time;
			index++;
			printf("%lf\n", time);
		}
	}
	resultCSVOut(result, index);

}



// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
