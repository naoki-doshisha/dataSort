// dataSort.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "Setting.h"
#include "sortUtils.h"
#include <time.h>

#define MAXSIZE 100

int main()
{
	char directory[CHARBUFF];//ディレクトリ
	char returnValue[CHARBUFF];//ファイル名を格納する配列

	int data[DATANUM] = {};//データを格納する配列
	Result result[MAXSIZE];//結果を格納する構造体

	//iniファイルからファイル名を取得
	getCurrentDirectory(directory);//ディレクトリを取得
	if (readChar("data", "data2", "none", returnValue, directory)) {
		printf("%s\n", returnValue);
	}

	dataInput(returnValue, data);//データを配列に格納

	/*シミュレーション*/

	int index = 0;//実験回数
	int flag = 0;//0-5のキーが押された：１、押されてない：０
	int rdata[DATANUM];//整列結果を格納する配列
	char type[6][CHARBUFF] = { "バブルソート","選択ソート","挿入ソート","シェルソート","クイックソート","マージソート" };//整列アルゴリズム名

	printf("アルゴリズムを選択してください（ｑでシミュレーション終了。）\n");
	for (int i = 0;i < 6;i++) {//整列アルゴリズムと番号を出力
		printf("%s->%d\n", type[i], i);
	}
	while (1) {
		int cdata[DATANUM];//シミュレーション用のデータ
		memcpy(cdata, data, sizeof(data));//配列をコピー(引数の最後はsizeofでないとうまくコピーできない）

		/*入力キーと、それに対する処理*/
		int key = getchar();//入力文字を取得
		if (key == 'q') break;//qが押されたらシミュレーション終了
		else {
			clock_t startTime = clock();//計測開始
			switch (key)
			{
			case '0':
				bubbleSort(cdata);
				flag = 1;
				break;
			case '1':
				selectionSort(cdata);
				flag = 1;
				break;
			case '2':
				insertionSort(cdata);
				flag = 1;
				break;
			case '3':
				shellSort(cdata);
				flag = 1;
				break;
			case '4':
				quickSort(cdata, 0, DATANUM - 1);
				flag = 1;
				break;
			case '5':
				mergeSort(cdata, 0, DATANUM - 1);
				flag = 1;
				break;
			default:
				break;
			}
			clock_t endTime = clock();//計測終了
			if (flag == 1) {
				double time = endTime - startTime;//経過時間
				int key2 = (unsigned char)key-48;//keyを数値に変換
				strcpy_s(result[index].name, type[key2]);//整列アルゴリズムを構造体に格納
				result[index].time = time;//経過時間を構造体に格納
				index++;
				printf("%lf\n", time);//処理時間を表示
				memcpy(rdata, cdata, sizeof(cdata));//整列後のデータを配列に格納
				flag = 0;
			}
		}
	}
	resultCSVOut(result, index);//結果を出力
	sortedDATACSVOut(rdata);//ソートされたデータを出力
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
