#pragma once

#pragma once

#include <string>
#include <vector>
using namespace std;

class NPC {
public:
    string name;
};

class Cell {
public:
    vector<NPC> NPCs;
    string eventMessage;  // 新增：事件触发时的消息

    void AddNPC(NPC npc){}
    void RemoveNPC(NPC npc){}
    void SetEventMessage(string message) {}  // 新增：设置事件消息
};

class Map {
public:
    vector<string> map = {
        "____________________________________________________________________  ",
        "|                      ______________                               | ",
        "|                     |   北俱芦洲   |                              | ",
        "|                     |              |                              | ",
        "|                     |______  ______|                              | ",
        "|                                                                   | ",
        "|         ______       ______  ______       ________   ______       | ",
        "|        |      |     |              |     |东海龙宫| |      |      | ",
        "|        |  西  |     |              |     |        | |  东  |      | ",
        "|        |  贺                                  ____| |  神  |      | ",
        "|        |  牛            南赡部洲             _____  |  胜  |      | ",
        "|        |  洲  |     |              |         |花果|    洲  |      | ",
        "|        |______|     |______   _____|         |山     ______|      | ",
        "|                                                                   | ",
        "|                                              |____|               | ",
        "|                      ______  ______                               | ",
        "|                     |              |                              | ",
        "|                         南海龙宫                                  | ",
        "|                     |______________|                              | ",
        "|___________________________________________________________________| "
    };

    Cell Place1;
    Cell Place2;
    Cell Place3;
    Cell Place4;
    Cell Place5;
    Cell Place6;
    Cell Place7;

    int playerX = 51, playerY = 12;

    Map();
    Map(int pX, int pY);  // 带有位置信息的，用于读取存档
    ~Map();

    void InMap();
    void GotoXY(int x, int y);
    void DrawMap();
    void UpdataPos(char move);
    void CheckPos();
    void ShowMessage(string message);  // 修改：显示特定消息
    void GenerateCell(Cell cell);
};
