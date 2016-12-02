/*#pragma once
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

*/

#pragma once
#include "Frame.h"
#include <string>
#include "ExArray.h"

	template<typename T>
	void mySwap(T& num1, T& num2)
	{
		T temp= num1;
		num1=num2;
		num2=temp;
	}

void main()
{
	/*try
	{
		Frame* f1 = new Frame;
		Frame* f2 = new Frame[10];

		delete f1;
		delete[] f2;
	}catch(string msg)
	{
		cout<<"Error msg: "<<msg<<endl;
	}*/

	ExArray<int> arr1(3);
	ExArray<char> arr2(4);
	ExArray<double> arr3(5);

	arr1.addData(2);
	arr2.addData('A');
	arr3.addData(32.12);

	arr1.printData();
	arr2.printData();
	arr3.printData();

	int num1=10, num2=40;
	cout<<"before: "<<num1<<","<<num2<<endl;
	mySwap<int>(num1,num2);
	cout<<"after:"<<num1<<","<<num2<<endl;
	
	double num1d=121.11, num2d=10.5;
	cout<<"before: "<<num1d<<","<<num2d<<endl;
	mySwap<double>(num1d,num2d);
	cout<<"after:"<<num1d<<","<<num2d<<endl;
	
	ExArray<int> arr4(5);
	arr4.addData(10);

	mySwap<ExArray<int>>(arr1,arr4);
	arr1.printData();
	arr4.printData();
}