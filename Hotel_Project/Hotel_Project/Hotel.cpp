#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>

//釭醞縑 �飛� 堅薑衛酈晦
//蘋む縑憮 й橾. 啪蝶お賅萄 棻 虜菟晦.
using namespace std;

#define X 50
#define Y 18

struct Member {
	string m_id;		//�蛾� 嬴檜蛤
	string m_name;	//�蛾� 檜葷
	int age;		//�蛾� 釭檜
	string m_phone;	//�蛾� 瞪�食醽�
	string m_gender;	//�蛾� 撩滌
	int point;		//�蛾衋� ん檣お
	int cnt;		//檜辨�蝦�
};

struct Room {
	int room_num; //�ˊ�
	int room_use; //蕨擒醞檣雖 嬴棋雖
	char* user; //餌辨濠 檜葷
	char* date_in; //羹觼檣 陳瞼
	char* date_out; //羹觼嬴醒 陳瞼
	Member** base; //�蛾灠� 翱唸? 謁...?
};

struct base {
	int max_member; //

};

class Hotel_Menu {
	int x, y, m_key;
	Member m;
public:
	void gotoxy(int m_x, int m_y) {
		COORD Pos = { m_x - 1, m_y - 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	int KeyPress() {
		int key;
		cin >> key;
		return key;
	}

	int Start() {
		system("cls");
		x = X - 10; y = 5;
		Hotel_draw(x, y);
		x = X; y = Y;
		menu_draw(x, y);
		x = X; y = 5;
		return KeyPress();
	}

	void ownerShow() {
		while ((m_key = Owner_Menu()) != 4) {
			switch (m_key) {
			case 1: 
				while((m_key = Room_Set())!=3){
					switch (m_key) {
					case 1:Room_add(); break;
					case 2:Room_delete(); break;
					case 3:break;
					}
				}
					break;
			case 2: Room_Status(); break;
			case 3: Member_Set(); break;
			case 4: break;
			}
		}
	}

	void guestShow() {
		while ((m_key = Guest_Menu()) != 7) {
			switch (m_key) {
			case 1:joinMember(); break;
			case 2:
				while (modifyMember()!=1); break;
			case 3:deleteMember(); break;
			case 4:ReserveRoom(); break;
			case 5: CheckIn(); break;
			case 6: CheckOut(); break;
			case 7: break;
			}
		}
	}

	void Hotel_draw(int m_x, int m_y) {
		gotoxy(m_x, m_y);
		printf("*     *   *******  *******  ********  *");
		m_y++; gotoxy(m_x, m_y);
		printf("*     *  *       *    *     *         *");
		m_y++; gotoxy(m_x, m_y);
		printf("*******  *       *    *     ********  *");
		m_y++; gotoxy(m_x, m_y);
		printf("*     *  *       *    *     *         *");
		m_y++; gotoxy(m_x, m_y);
		printf("*     *   *******     *     ********  ******");
		m_y++; gotoxy(m_x, m_y);
	}

	void menu_draw(int m_x, int m_y) {
		gotoxy(m_x, m_y - 1);//x=50, y=17
		cout << "收收收收收收收收收收收收收收收收收收";
		gotoxy(m_x, m_y); //x=50,y=18
		cout << "| <1> Owner mode |";
		m_y++; gotoxy(m_x, m_y); //y=19
		cout << "| <2> Guest mode |";
		m_y++; gotoxy(m_x, m_y);
		cout << "| <3> Exit       |";
		m_y++; gotoxy(m_x, m_y);
		cout << "收收收收收收收收收收收收收收收收收收" << endl;
		m_y++; gotoxy(m_x + 7, m_y);
		cout << ">> ";
	}

	int Owner_Menu() {
		system("cls");
		gotoxy(x, y);
		cout << "### Owner Mode ###";
		y++; gotoxy(x-20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; gotoxy(x+2, y);
		cout << "<1> 偌褒 婦葬";
		y+=2; gotoxy(x+2, y);
		cout << "<2> 偌褒 ⑷��";
		y+=2; gotoxy(x+2, y);
		cout << "<3> �蛾� 婦葬";
		y += 2; gotoxy(x + 2, y);
		cout << "<4> 詭檣戲煎";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		cout << ">> ";
		x = X; y = 5;
		return KeyPress();
	}

	int Guest_Menu() {
		system("cls");
		gotoxy(x, y);
		cout << "### Guest Mode ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; gotoxy(x + 2, y);
		cout << "<1> �蛾� 陛殮";
		y += 2; gotoxy(x + 2, y);
		cout << "<2> �蛾� 薑爾 熱薑";
		y += 2; gotoxy(x + 2, y);
		cout << "<3> �蛾� 驍黴";
		y += 2; gotoxy(x + 2, y);
		cout << "<4> 蕨擒";
		y += 2; gotoxy(x + 2, y);
		cout << "<5> 羹觼檣";
		y += 2; gotoxy(x + 2, y);
		cout << "<6> 羹觼嬴醒";
		y += 2; gotoxy(x + 2, y);
		cout << "<7> 詭檣戲煎";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		cout << ">> ";
		x = X; y = 5;
		return KeyPress();
	}

	int Room_Set() {
		system("cls");
		gotoxy(x, y);
		cout << "### 偌褒 婦葬 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; gotoxy(x + 2, y);
		cout << "<1> 偌褒 蹺陛";
		y += 2; gotoxy(x + 2, y);
		cout << "<2> 偌褒 餉薯";
		y += 2; gotoxy(x + 2, y);
		cout << "<3> 檜瞪戲煎";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		cout << ">> ";
		x = X; y = 5;
		return KeyPress();
	}
	void Room_Status() {
		system("cls");
		gotoxy(x, y);
		cout << "### 偌褒 ⑷�� ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; 
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");

	}
	void Member_Set() {
		system("cls");
		gotoxy(x, y);
		cout << "### �蛾� 婦葬 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void joinMember() {
		system("cls");
		gotoxy(x, y);
		cout << "### �蛾� 陛殮 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; gotoxy(x - 20, y);
		cout << "檜葷擊 殮溘п輿撮蹂: "; cin >> m.m_name;
		y++; gotoxy(x - 20, y);
		cout << "釭檜蒂 殮溘п輿撮蹂: "; cin >> m.age;
		y++; gotoxy(x - 20, y);
		cout << "撩滌擊 殮溘п輿撮蹂: "; cin >> m.m_gender;
		y++; gotoxy(x - 20, y);
		cout << "瞪�食醽ㄧ� 殮溘п輿撮蹂: "; cin >> m.m_phone;
		y++; gotoxy(x - 20, y);
		cout << "�蛾灠㊣� 諫猿 腎樟蝗棲棻";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5; 
		system("PAUSE");
	}

	void Insert(string name, int age, string gender, string phone) {

	}

	int modifyMember() {
		int choice;
		system("cls");
		gotoxy(x, y);
		cout << "### �蛾� 薑爾 熱薑 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; gotoxy(x - 20, y);
		cout << "<1> 檜葷: " << m.m_name;
		y++; gotoxy(x - 20, y);
		cout << "<2> 釭檜: " << m.age;
		y++; gotoxy(x - 20, y);
		cout << "<3> 撩滌: " << m.m_gender;
		y++; gotoxy(x - 20, y);
		cout << "<4> 瞪�食醽�: " << m.m_phone;
		y++; gotoxy(x - 20, y);
		cout << "<5> 菴煎陛晦 ";
		y++; y++; gotoxy(x - 20, y);
		cout << "熱薑й о跡擊 埤塭輿撮蹂: ";
		cin >> choice;
		y++; y++; gotoxy(x - 20, y);
		switch (choice)	{
			case 1: 
				cout << "滲唳й 檜葷擊 殮溘ж撮蹂: ";
				cin >> m.m_name; break;
			case 2:
				cout << "滲唳й 釭檜蒂 殮溘ж撮蹂: ";
				cin >> m.age; break;
			case 3:
				cout << "滲唳й 撩滌擊 殮溘ж撮蹂: ";
				cin >> m.m_gender; break;
			case 4:
				cout << "滲唳й 瞪�食醽ㄧ� 殮溘ж撮蹂: ";
				cin >> m.m_phone; break;
			case 5:
				cout << "菴煎陛晦";
				x = X; y = 5;
				return 1;
		}
		y++; y++; gotoxy(x - 20, y);
		cout << "滲唳 諫猿^^";
		y++; y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
		return 0;
	}

	void deleteMember() {
		string name, tel;
		system("cls");
		gotoxy(x, y);
		cout << "### �蛾� 驍黴 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; gotoxy(x - 20, y);
		cout << "驍黴蒂 錳ж衛賊 檜葷婁 瞪�食醽ㄧ� 殮溘п輿撮蹂";
		y++; gotoxy(x - 20, y);
		cout << "檜葷: ";
		cin >> name;
		y++; gotoxy(x - 20, y);
		cout << "瞪�食醽�: ";
		cin >> tel;

		if (m.m_name == name && m.m_phone == tel){
			y++; gotoxy(x - 20, y);
			cout << "驍黴籀葬腎歷蝗棲棻~~^^";
		}
		else {
			y++; gotoxy(x - 20, y);
			cout << "翕橾и 薑爾曖 �蛾衋� 襄營ж雖 彊蝗棲棻~~^^";
		}

		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void ReserveRoom() {
		system("cls");
		gotoxy(x, y);
		cout << "### 蕨擒ж晦 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; gotoxy(x + 2, y);
		y += 2; gotoxy(x + 2, y);
		y += 2; gotoxy(x + 2, y);
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void Room_add() {
		system("cls");
		gotoxy(x, y);
		cout << "### 偌褒 蹺陛 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void Room_delete() {
		system("cls");
		gotoxy(x, y);
		cout << "### 偌褒 餉薯 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void CheckIn() {
		system("cls");
		gotoxy(x, y);
		cout << "### 羹觼 檣 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void CheckOut() {
		system("cls");
		gotoxy(x, y);
		cout << "### 羹觼嬴醒 ###";
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}
};
