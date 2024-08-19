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
		"|                               |______________|                              | "
		"|                                                                             | "
		"|         ______                 ______________                  ______       | "
		"|        |      |               |              |      ________  |      |      | "
		"|        |  西  |               |              |     |东海龙宫| |  东  |      | "
		"|        |  牛  |               |   南赡部洲   |     |________| |  胜  |      | "
		"|        |  贺  |               |              |      ____      |  神  |      | "
		"|        |  洲  |               |              |     |花果|     |  洲  |      | "
		"|        |______|               |______________|     |山  |     |______|      | "
		"|                                                    |____|                   | "
		"|                                ______________                               | "
		"|                               |              |                              | "
		"|                               |   南海龙宫   |                              | "
		"|                               |______________|                              | "
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
	cout << "|                               |______________|                              | " << endl;
	cout << "|                                                                             | " << endl;
	cout << "|         ______                 ______________                  ______       | " << endl;
	cout << "|        |      |               |              |      ________  |      |      | " << endl;
	cout << "|        |  西  |               |              |     |东海龙宫| |  东  |      | " << endl;
	cout << "|        |  牛  |               |   南赡部洲   |     |________| |  胜  |      | " << endl;
	cout << "|        |  贺  |               |              |      ____      |  神  |      | " << endl;
	cout << "|        |  洲  |               |              |     |花果|     |  洲  |      | " << endl;
	cout << "|        |______|               |______________|     |山  |     |______|      | " << endl;
	cout << "|                                                    |____|                   | " << endl;
	cout << "|                                ______________                               | " << endl;
	cout << "|                               |              |                              | " << endl;
	cout << "|                               |   南海龙宫   |                              | " << endl;
	cout << "|                               |______________|                              | " << endl;
	cout << "|_____________________________________________________________________________| " << endl;
	char choiceDir;		           
	cout << "选择你要去的位置" << endl; cin >> choiceDir;

	//switch (this->pos)
	//{
	//case 1:

	//	break;
	//case 2:

	//	break;
	//case 3:

	//	break;
	//case 4:

	//	break;
	//case 5:

	//	break;
	//case 6:
	//	system("cls");
	//	//GenerateCell("东海龙王");
	//	break;
	//case 7:

	//	break;
	//default:

	//	break;
	//}
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