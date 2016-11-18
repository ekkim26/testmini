//#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class keyEvent
{
private:
	HANDLE hin;
	COORD keyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downkey;
public:
	keyEvent()
	{
		hin=GetStdHandle(STD_INPUT_HANDLE);
		EventCount=1;
	}
	int getkey()
	{
		ReadConsoleInput(hin,&InRec,1,&NumRead);
		if(InRec.EventType==KEY_EVENT)
		{
			if(InRec.Event.KeyEvent.bKeyDown)
			{
			downkey=InRec.Event.KeyEvent.wVirtualKeyCode;
			return downkey;
			}
			else
			{
				return -1;
			}
		}
		return -1;
	}
};
class Game   // 화살표누르는대로 움직이게 하는 거 !!
{
private:
 int x,y,direction;
 void gotoXY(int x,int y)
 {
	 COORD pos={x,y};
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
 }
public:
	Game()
	{
		x=5;
		y=5;
		direction=0;
	}
	void setDirection(int i)
	{
		direction=i;
	}
	void move()
	{
		if(direction==37)
		{
			x--;
		}
		else if(direction==38)
		{
			y--;
		}
		else if(direction==39)
		{
			x++;
		}
		else if(direction==40)
		{
			y++;
		}
			system("cls");
		this->gotoXY(x,y);
		cout<<x<<" "<<y;
		cout<<"■";
	}

	
};

Game* game = new Game();
unsigned int __stdcall mythread(void*)
{
	int i=0;
	while(1)
	{
		game->move();
		Sleep(500);
	}
	return 0;
}

unsigned int __stdcall keyEvent1(void*)
{
	keyEvent k;
	int i;
	while(1)
	{
		i=k.getkey();
		if(i!=-1) game->setDirection(i);
	}
	return 0;
}

int main()
{
	cout<<"game project 입니다";
}