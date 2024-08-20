


#include "Map.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

Map::Map() {
    // 初始化特定位置的事件消息
    Place1.SetEventMessage("你到了北俱芦州！");
    Place2.SetEventMessage("你到了南赡部州！");
    Place3.SetEventMessage("你到了花果山！");
    Place4.SetEventMessage("你到了东海龙宫！");
    Place5.SetEventMessage("你到了南海龙宫！");
    Place5.SetEventMessage("你到了东胜神州！");
    Place5.SetEventMessage("你到了西牛贺州！");
}

Map::Map(int pX, int pY) {
    playerX = pX;
    playerY = pY;
}

Map::~Map() {}

void Map::GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Map::GenerateCell(Cell cell) {
	cout << "  ___________" << endl;
	for (int i = 0; i < cell.NPCs.size(); i++) {
		cout << " |" << i << "." << cell.NPCs[i].name << "\t " << endl;
	}
	//cout << " |1." << cell.NPCs << "\t " << endl;
	//cout << " |NPC:test\t " << endl;
	//cout << " |2." << monsterName << "\t " << endl;
	cout << " |\t\t" << endl;
	cout << " |\t\t" << endl;
	cout << "  \t\t\t|" << endl;
	cout << "  \t\t________| " << endl;
}

void Map::DrawMap() {
    system("cls");
    for (int y = 0; y < map.size(); y++) {
        cout << map[y] << endl;
    }
    GotoXY(playerX, playerY);
    cout << "#";
}

void Map::InMap() {
    DrawMap();

    bool isRunning = true;
    while (isRunning) {
        if (_kbhit()) {
            char input = _getch();
            if (input == 'q') {
                isRunning = false;  // 退出
                system("cls");
            }
            else if (input == 'e') {
                CheckPos();  // 检查事件
            }
            else {
                UpdataPos(input);  // 移动人物
            }
        }

        Sleep(100);  // 稍微暂停一下，避免 CPU 过度占用
    }
}

void Map::UpdataPos(char move) {
    // 清除旧位置
    GotoXY(playerX, playerY);
    cout << map[playerY][playerX];

    switch (move) {
    case 'w': if (playerY > 0 && map[playerY - 1][playerX] != '_' && map[playerY - 1][playerX] != '|' && map[playerY - 1][playerX] == ' ') playerY--; break; // 向上移动
    case 's': if (playerY < map.size() - 1 && map[playerY + 1][playerX] != '_' && map[playerY + 1][playerX] != '|' && map[playerY + 1][playerX] == ' ') playerY++; break; // 向下移动
    case 'a': if (playerX > 0 && map[playerY][playerX - 1] != '|' && map[playerY][playerX - 1] != '_' && map[playerY][playerX - 1] == ' ') playerX--; break; // 向左移动
    case 'd': if (playerX < map[0].size() - 1 && map[playerY][playerX + 1] != '|' && map[playerY][playerX + 1] != '_' && map[playerY][playerX + 1] == ' ') playerX++; break; // 向右移动
    }

    // 显示新位置
    GotoXY(playerX, playerY);
    cout << "#";
}

void Map::CheckPos() {
    // 根据当前位置触发不同的事件
    if (playerX >= 8 && playerY <= 12 && playerY <= 7 && playerX >= 12) {
        ShowMessage(Place1.eventMessage);
    }
    else if (playerX == 25 && playerY == 8) {
        ShowMessage(Place2.eventMessage);
    }
    else if (playerX == 38 && playerY == 10) {
        ShowMessage(Place3.eventMessage);
    }
    else if (playerX == 32 && playerY == 7) {
        ShowMessage(Place4.eventMessage);
    }
    else if (playerX == 29 && playerY == 16) {
        ShowMessage(Place5.eventMessage);
    }
}

void Map::ShowMessage(string message) {
    GotoXY(0, map.size() + 1);  // 将光标移动到地图下方，显示消息
    cout << message << endl;
    system("pause");  // 暂停，等待用户按键
}

