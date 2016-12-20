#pragma once
#include<vector>
#include<iostream>
#include<string>
#include "Observer.h"

using namespace std;

class Subject{                    //目标抽象类
public:
	string s1;                        //数据值，可以作为私有数据，然后定义一个借口去返回值，这里为了省事                           //数据值
	void regiObserver(Observer *obs){
		_observer.push_back(obs);
		cout << "已订阅" << endl;
	}
	void deleObserver(Observer *obs){
		_observer.pop_back();
	}
	void notify(){                //更新所有的观察者
		vector<Observer *>::iterator it;
		for (it = _observer.begin(); it != _observer.end(); it++)
			(*it)->update(this);
	}
private:
	vector<Observer *> _observer;        //观察者容器
};
