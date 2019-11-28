#ifndef ROOM_H
#define ROOM_H

#include "Member.h"
#include <string>
#include <vector>

struct room {
	int room_num; //호실
	int room_use; //예약중인지 아닌지 1이면 예약중
	string user; //사용자 이름
	string date_inL; //체크인 날짜
	string date_out; //체크아웃 날짜
	Member** base; //회원과 연결

	friend ostream& operator <<(ostream& os, const room& score);
};

class Room {
	room r;
	vector<room> Vip;
	vector<room> Com;
public:

	Room();
	void Reservation(); //방 예약하기
	void CheckIn(); //입실
	void CheckOut(); //퇴실
	void ShowRoom(); //객실 보기
	void addroom(); //객실 추가
	void deleteroom(); //객실 삭제
	void roomservice(); //룸서비스
	room InsertRoom();
};
#endif // Member_H
