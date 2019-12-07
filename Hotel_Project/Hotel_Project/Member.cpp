#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
Menu* menu;

Member::Member(char* id, char* password, char* name, int age, char* phone, char* gender,
	int point, int check, int cnt, int total_amount) {
	this->age = age;
	this->point = point;
	this->check = check;
	this->cnt = cnt;
	this->total_amount = total_amount;

	mid = new char[20];
	mpw = new char[20];
	mname = new char[20];
	mphone = new char[20];
	mgender = new char[10];

	strcpy_s(this->mid, 20, id);
	strcpy_s(this->mpw, 20, password);
	strcpy_s(this->mname, 20, name);
	strcpy_s(this->mphone, 20, phone);
	strcpy_s(this->mgender, 10, gender);
}

Member::Member(){}
Member::~Member() {
	delete mid, mpw, mname, mphone, mgender;
}

int Member::DeleteMember() {
	//int choice, i, num;
	char uid[20]; //componet[20];// , find[20];
	char* finder;
	system("cls");
	
	x = X; y = 5;
	menu->gotoxy(x, y);
	cout << "### �蛾� 驍黴 ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
	y++; menu->gotoxy(x - 20, y);
	cout << "驍黴й �蛾衋� 嬴檜蛤蒂 殮溘п輿撮蹂: "; cin >> uid;
	finder = uid;
	y++; menu->gotoxy(x - 20, y);

	Member::DBconnecter();

	sprintf_s(Query, 256, "delete from room where id = '%s'", finder);
	stat = mysql_query(connection, Query);

	sprintf_s(Query, 256, "delete from member where id = '%s'", finder);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "п渡ж朝 嬴檜蛤曖 �蛾衋� 橈蝗棲棻";
		system("PAUSE");
		return 1;
	}
	else {
		cout << "撩奢瞳戲煎 驍黴陛 腎歷蝗棲棻";
		system("PAUSE");
		return 0; 
	}
}//Guest

int Member::JoinMember() {
	//Member* m = new Member();
	Member::DBconnecter();
	char id[20], pass[20], name[20], gender[20], phone[20];
	char* i=NULL, *pw=NULL , *n = NULL, *g = NULL, *p = NULL;
	int age,point,cnt;
	bool check;
	x = X; y = 5;
	system("cls");
	menu->gotoxy(x, y);
	cout << "### �蛾� 陛殮 ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
	y++; menu->gotoxy(x - 10, y);
	cout << "�蛾� 嬴檜蛤蒂 殮溘п輿撮蹂: "; cin >> id; i = id;//getchar();
	y++; menu->gotoxy(x - 10, y);


	cout << "綠塵廓�ㄧ� 殮溘п輿撮蹂: "; cin >> pass;  pw = pass;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "檜葷擊 殮溘п輿撮蹂: "; cin >>  name; n = name;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "釭檜蒂 殮溘п輿撮蹂: "; cin >> age; //getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "撩滌擊 殮溘п輿撮蹂: "; cin >> gender;  g = gender;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "瞪�食醽ㄧ� 殮溘п輿撮蹂: "; cin >> phone; p = phone; //getchar();
	y += 2; menu->gotoxy(x + 2, y);

	//x = X; y = 5;
	point = 10; // 陛殮爾傘蝶 10薄
	check = 0; //⑷營 檜辨醞檣雖 嬴棋雖~
	cnt = 0; //餌辨�蝦�
	total_amount = 0;
	m = new Member(i, pw, n, age, p, g, point, check, cnt, total_amount);

	Member::SetMember(m);

	y+=2; menu->gotoxy(x - 10, y);
	cout << "�蛾灠㊣� 諫猿 腎樟蝗棲棻";
	y++; menu->gotoxy(x - 20, y);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
	system("PAUSE");

	return 0;
}//�蛾灠㊣�
//Guest

int Member::ModifyMember() {
	Member::DBconnecter();
	int choice,chk;
	char user[20], componet[20];// , find[20];
	char* finder=NULL, *find=NULL;
	system("cls");
	x = X; y = 5;
	menu->gotoxy(x, y); 
	cout << "### �蛾� 薑爾 熱薑 ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
	y++; menu->gotoxy(x - 20, y);
	cout << "薑爾蒂 熱薑й �蛾� 嬴檜蛤 殮溘: "; cin >> user;
		finder = user;
	y++; menu->gotoxy(x - 20, y);

	
	sprintf_s(Query, 256, "select id from member;");
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);

	while ((Row = mysql_fetch_row(Result)) != NULL) {
		chk = strcmp(Row[0], finder); //蜃戲賊 0
		if (chk == 0) 
			break;
	}
	if (chk == 1) {
		cout << "п渡ж朝 嬴檜蛤陛 橈蝗棲棻";
		system("PAUSE");
		return 1;
	}
	cout << "綠塵廓�ㄧ� 殮溘п輿撮蹂: ";
	cin >> user; 
	find = user; //綠塵廓��

	y++; menu->gotoxy(x - 20, y);
	sprintf_s(Query, 256, "select * from member where id = '%s'", finder);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);

	while((Row = mysql_fetch_row(Result)) != NULL) {
		chk = strcmp(Row[1], find); //蜃戲賊 0
		if (chk == 0)
			break;
	}
	if (chk == 1) {
		cout << "綠塵廓�ㄟ� 蜃雖 彊蝗棲渡";
		system("PAUSE");
		return 1;
	}
	//Result = mysql_store_result(connection);
	//Row = mysql_fetch_row(Result);
	//cout << Row[0];
		

	system("cls");
	x = X; y = 5;
	menu->gotoxy(x-1, y);
	y++; cout << "### �蛾� 薑爾 熱薑 ###";
	menu->gotoxy(x - 32, y);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
	y++; 	menu->gotoxy(x - 32, y);
	cout << "    ID        NAME     AGE        TEL       GENDER    POINT   CNT   Total_Amount   ";
	y++; 	menu->gotoxy(x - 32, y);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
	y++; 	menu->gotoxy(x - 32, y);

	sprintf_s(Query, 256, "select * from member where id = '%s' and password='%s'", finder, find);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	///Row = mysql_fetch_row(Result);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	Row = mysql_fetch_row(Result);
	//while ((Row = mysql_fetch_row(Result)) != NULL) {
	printf("%9s %9s    %3d  %13s    %5s   %4d     %3d   %7d", Row[0], Row[2], atoi(Row[3]), Row[4], Row[5], atoi(Row[6]), atoi(Row[8]), atoi(Row[9]));
		y++; 	menu->gotoxy(x - 33, y);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; 	menu->gotoxy(x - 32, y);
	//}


	y++; 	menu->gotoxy(x - 30, y);
	cout << "滲唳й 薑爾";
	y++;	menu->gotoxy(x - 30, y);
	cout << "<1> Name, <2> Age, <3> Tel, <4> Gender, <5> exit";
	y++;	menu->gotoxy(x - 30, y);
	cout << ">> "; cin >> choice;
	y++;	menu->gotoxy(x - 30, y);

	switch (choice) {
	case 1:
		cout << "滲唳й 檜葷擊 殮溘ж撮蹂: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set name = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 2:
		cout << "滲唳й 釭檜蒂 殮溘ж撮蹂: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set age = %d where id = '%s'", atoi(componet), finder);
		mysql_query(connection, Query);
		break;
	case 3:
		cout << "滲唳й 瞪�食醽ㄧ� 殮溘ж撮蹂: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set tel = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 4:
		cout << "滲唳й 撩滌擊 殮溘ж撮蹂: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set gender = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 5:
		cout << "菴煎陛晦";
		x = X; y = 5;
		return 1;
	}
	y++; y++; menu->gotoxy(x - 30, y);
	cout << "滲唳 諫猿^^";
	y++; y++; menu->gotoxy(x - 30, y);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
	y += 2; menu->gotoxy(x - 30, y);
	x = X, y = 12;
	system("PAUSE");
	return 1;
}//�蛾讔內蜈鶬�
//Guest*/

void Member::ShowMember() {
	system("cls");
	Member::DBconnecter();
	x = X, y = 12;
	sprintf_s(Query, 256, "select * from member order by cnt desc"); //餌辨и �蝦鰤� 號擎 牖憮渠煎 轎溘
	mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	fields = mysql_num_fields(Result);

	menu->gotoxy(x +3, y-6);
	y++; cout << "### �蛾� 薑爾 ###";
	
	menu->gotoxy(x - 33, y-6);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
	y++; 	menu->gotoxy(x - 32, y - 6);
	cout << "    ID        NAME     AGE        TEL       GENDER    POINT   CNT   Total_Amount   ";
	y++; 	menu->gotoxy(x - 33, y - 6);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
	y++; 	menu->gotoxy(x-32, y - 6);
	
	while ((Row = mysql_fetch_row(Result)) != NULL) {
		printf("%9s %9s    %3d  %13s    %5s   %4d     %3d   %7d", Row[0], Row[2], atoi(Row[3]), Row[4], Row[5], atoi(Row[6]), atoi(Row[8]), atoi(Row[9]));
		y++; 	menu->gotoxy(x - 33, y -6);
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
		y++; 	menu->gotoxy(x - 32, y -6);
	}
	mysql_free_result(Result);
	mysql_close(connection);
	x = X, y = 12;
	system("PAUSE");
}//�蛾羉蛾忿眻�
//Owner



int Member::checkMember(char* i) {
	Member::DBconnecter();
	//cout << "$$$";
	sprintf_s(Query, 256, "select * from member where id = '%s'", i);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	cout << Row[6] << "," << Row[8];
	sprintf_s(Query, 256, "update member set point = %d, chk = 1, cnt = %d", atoi(Row[6]) + 50, atoi(Row[8])+1);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);

	mysql_free_result(Result);
	mysql_close(connection);
	
	return 0;
}
int Member::SetMember(Member* m) {
	//Member::DBconnecter();
	sprintf_s(Query, 256,"INSERT INTO MEMBER VALUES('%s','%s', '%s' ,%d,'%s','%s',%d,%d,%d,%d);",
				m->mid, m->mpw, m->mname, m->age, m->mphone, m->mgender,m->point, m->check,m->cnt, m->total_amount);

	stat = mysql_query(connection, Query);

	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	else cout << "success!!" << endl;

	return 0;
}//漱攪縑 詹幗厥晦

void Member::deleteAllM() {
	sprintf_s(Query, 256, "delete from member;");
	stat = mysql_query(connection, Query);
	if (stat != 0) cout << "error: " << mysql_error(&mysql);
	else cout << "member success!!" << endl;
}

int Member::DBconnecter() {
	mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, "localhost", "root", "mirim2", "chotel", 3306, NULL, 0);
	if (connection == NULL) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	mysql_query(connection, "set session character_set_connection=euckr");
	mysql_query(connection, "set session character_set_results=euckr");
	mysql_query(connection, "set session character_set_client=euckr");
	return 0;
}


/*ostream& operator <<(ostream& os, const member& member){
	os << "嬴檜蛤: " << member.id << "檜葷: " << member.name << endl << "釭檜: " << member.age << endl <<
		"瞪�食醽�: " << member.phone << endl << "撩滌: " << member.gender << endl << "ん檣お: " << member.point << endl
		<< "檜辨�蝦�: " << member.cnt;
	return os;
}*/
