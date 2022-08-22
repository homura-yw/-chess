#include <iostream>
#include <cstdlib>
#include "井.h"

using namespace std;

int main()
{
	void display(char qipan[][3]);

	char qipan[3][3] = { {'O','_','_'} ,{'_','_','_'} ,{'_','_','_'} };
	start:
	cout << "输入1进入游戏" << endl;
	cout << "输入2查看使用说明" << endl;
	int x = 0;
	cin >> x;
	system("cls");
	if (x == 1) {
		int step = 1;
		display(qipan);
		while (true) {
			int x = 0, y = 0;
			cout << "\n轮到你的回合了：" << endl;
			cin >> x >> y;
			if (qipan[x - 1][y - 1] == '_') {
				step += 2;

				qipan[x - 1][y - 1] = 'X';
				int w = whowin(qipan);
				if (w == 1) {
					system("cls");
					display(qipan);
					goto jite; 
				}
				putPiece(qipan);
			}
			else {
				cout << "你输入的坐标已有棋子，输入回车键继续" << endl;
				getchar();
				getchar();
			}
			system("cls");
			display(qipan);
			if (whowin(qipan) == 1) {
				jite:
				cout << "你赢麻了" << endl;
				getchar();
				getchar();
				return 0;
			}
			else if (whowin(qipan) == 2) {
				cout << "你输麻了" << endl;
				getchar();
				getchar();
				return 0;
			}
			else {
				if (step != 9) continue;
				else {
					cout << "你俩不相上下" << endl;
					getchar();
					getchar();
					return 0;
				}
			}
		}

	}
	else if (x == 2) {
		cout << "游玩说明:" << endl;
		cout << "由于本人尚且不太熟练c++的前端开发，故此程序采用小黑框通过键盘进行程序互动" << endl;
		cout << "本程序基于校acm网络赛中一道算法题的所激发的灵感，而实现的一个小游戏功能\n" << endl;
		cout << "操作指南" << endl;
		cout << "通过输入坐标来来确定自己的棋子的位置，纵坐标在前，横坐标在后，其中原点为棋盘最左上角的格子" << endl;
		cout << "本游戏为带ai的单机游戏，无联机功能" << endl;
		cout << "输入回车退回标题" << endl;
		getchar();
		getchar();
		system("cls");
		goto start;
	}
	else {
		cout << "输的啥啊我看不懂捏" << endl;
		cout << "输入回车退回标题" << endl;
		getchar();
		getchar();
		system("cls");
		goto start;
	}
}

void display(char qipan[][3]) {
	for (int I = 0; I < 3; I++) {
		for (int i = 0; i < 3; i++) {
			cout << qipan[I][i] << ' ';
		}
		cout << endl;
	}
}
