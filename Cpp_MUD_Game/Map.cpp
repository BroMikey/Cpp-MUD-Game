#include "Map.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

void Cell::SetEventMessage(string message) {
    this->eventMessage = message;
}

Cell::Cell() {

}

/// <summary>
/// 用于根据NPC初始化cell
/// </summary>
Cell::Cell(vector<NPC>npcs) {
    for (auto oneNPC:npcs) {
        this->AddNPC(oneNPC);
    }
}

Cell::~Cell() {

}

void Cell::AddNPC(NPC n) {
    this->NPCs.push_back(n);
}

Map::Map() {
    // 初始化特定位置的事件消息
    cellXi.SetEventMessage("你到了西牛贺州！");
    cellNanS.SetEventMessage("你到了南赡部州！");
    cellNanH.SetEventMessage("你到了南海龙宫！");
    cellBei.SetEventMessage("你到了北俱芦州！");
    cellDongH.SetEventMessage("你到了东海龙宫！");
    cellDongS.SetEventMessage("你到了东胜神州！");
    cellHua.SetEventMessage("你到了花果山！");
    cellHua.AddNPC(NPC("土地"));
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
    system("cls");
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
    case 'w': if (playerY > 0 &&
        map[playerY - 1][playerX] != '_' &&
        map[playerY - 1][playerX] != '|' && 
        map[playerY - 1][playerX] == ' ' ||
        map[playerY - 1][playerX] == '*')
            playerY--; break; // 向上移动
    case 's': if (playerY < map.size() - 1 && 
        map[playerY + 1][playerX] != '_' && 
        map[playerY + 1][playerX] != '|' && 
        map[playerY + 1][playerX] == ' ' || 
        map[playerY + 1][playerX] == '*')
            playerY++; break; // 向下移动
    case 'a': if (playerX > 0 && 
        map[playerY][playerX - 1] != '|' && 
        map[playerY][playerX - 1] != '_' && 
        map[playerY][playerX - 1] == ' ' || 
        map[playerY][playerX - 1] == '*')
            playerX--; break; // 向左移动
    case 'd': if (playerX < map[0].size() - 1 && 
        map[playerY][playerX + 1] != '|' &&
        map[playerY][playerX + 1] != '_' && 
        map[playerY][playerX + 1] == ' ' || 
        map[playerY][playerX + 1] == '*')
            playerX++; break; // 向右移动
    }

    // 显示新位置
    GotoXY(playerX, playerY);
    cout << "#";
}

void Map::CheckPos() {
    // 根据当前位置触发不同的事件
    if (playerX == 14 && playerY == 10) {
        system("cls");
        ShowMessage(cellXi.eventMessage);
        GenerateCell(cellXi);
    }
    else if (playerX == 51 && playerY == 12) {
        system("cls");
        ShowMessage(cellHua.eventMessage);
        GenerateCell(cellHua);
    }
    else if (playerX == 30 && playerY == 9) {
        system("cls");
        ShowMessage(cellNanS.eventMessage);
        GenerateCell(cellNanS);
    }
    else if (playerX == 30 && playerY == 16) {
        system("cls");
        ShowMessage(cellNanH.eventMessage);
        GenerateCell(cellNanH);
    }
    else if (playerX == 30 && playerY == 3) {
        system("cls");
        ShowMessage(cellBei.eventMessage);
        GenerateCell(cellBei);
    }
    else if (playerX == 48 && playerY == 8) {
        system("cls");
        ShowMessage(cellDongH.eventMessage);
        GenerateCell(cellDongH);
    }
    
    else if (playerX == 56 && playerY == 10) {
        system("cls");
        ShowMessage(cellDongS.eventMessage);
        GenerateCell(cellDongS);
    }
}

void Map::ShowMessage(string message) {

    cout << message << endl;

    Sleep(1000);
    //此处为退出地图程序进入cell

}

