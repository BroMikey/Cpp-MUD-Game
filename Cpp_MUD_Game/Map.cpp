#include "Map.h"
#include<iostream>
#include<Windows.h>

Map::Map() {

}

/// <summary>
/// 读取存档时构造的地图
/// </summary>
/// <param name="p">
/// 读取存档角色的位置信息
/// </param>
Map::Map(int p){
	vector<string> map = {
		"______________________________________________________________________________  "
		"|                                ______________                               | "
		"|                               |              |                              | "
		"|                               |   北俱芦洲   |                              | "
		"|                               |______2_______|                              | "
		"|                                                                             | "
		"|         ______                 ______________                  ______       | "
		"|        |      |               |              |      ________  |      |      | "
		"|        |  西  |               |              |     |东海龙宫| |  东  |      | "
		"|        |  牛  |               |   南赡部洲   |     |____7___| |  胜  |      | "
		"|        |  贺  |               |      1       |      ____      |  神  |      | "
		"|        |  洲  |               |              |     |花果|     |  洲  |      | "
		"|        |__3___|               |______________|     |山  |     |___4__|      | "
		"|                                                    |_6__|                   | "
		"|                                ______________                               | "
		"|                               |              |                              | "
		"|                               |   南海龙宫   |                              | "
		"|                               |_______5______|                              | "
		"|_____________________________________________________________________________| "
	};
}

Map::~Map() {

}

void Map::ShowWorldMap() {
	system("cls");
	cout << "世界地图:" << endl;											     
	cout << "                                                                                " << endl;
	cout << "______________________________________________________________________________  " << endl;
	cout << "|                                ______________                               | " << endl;
	cout << "|                               |              |                              | " << endl;
	cout << "|                               |   北俱芦洲   |                              | " << endl;
	cout << "|                               |______2_______|                              | " << endl;
	cout << "|                                                                             | " << endl;
	cout << "|         ______                 ______________                  ______       | " << endl;
	cout << "|        |      |               |              |      ________  |      |      | " << endl;
	cout << "|        |  西  |               |              |     |东海龙宫| |  东  |      | " << endl;
	cout << "|        |  牛  |               |   南赡部洲   |     |____7___| |  胜  |      | " << endl;
	cout << "|        |  贺  |               |      1       |      ____      |  神  |      | " << endl;
	cout << "|        |  洲  |               |              |     |花果|     |  洲  |      | " << endl;
	cout << "|        |__3___|               |______________|     |山  |     |___4__|      | " << endl;
	cout << "|                                                    |_6__|                   | " << endl;
	cout << "|                                ______________                               | " << endl;
	cout << "|                               |              |                              | " << endl;
	cout << "|                               |   南海龙宫   |                              | " << endl;
	cout << "|                               |_______5______|                              | " << endl;
	cout << "|_____________________________________________________________________________| " << endl;
	int choiceWorld = 0;		           
	cout << "选择你要去的位置" << endl; cin >> choiceWorld;
	switch (choiceWorld)
	{
	case 1:

	case 2:

	case 3:

	case 4:

	case 5:

	case 6:
		system("cls");
		//GenerateCell("东海龙王");
		break;
	case 7:

	default:
		break;
	}
}

void Map::GenerateCell(Cell cell) {
	cout << "  ___________" << endl;
	for (int i = 0; i < cell.NPCs.size(); i++) {
		cout << " |"<<i<<"." << cell.NPCs[i].name << "\t " << endl;
	}
	//cout << " |1." << cell.NPCs << "\t " << endl;
	//cout << " |NPC:test\t " << endl;
	//cout << " |2." << monsterName << "\t " << endl;
	cout << " |\t\t" << endl;
	cout << " |\t\t" << endl;
	cout << "  \t\t\t|" << endl;
	cout << "  \t\t________| " << endl;
}