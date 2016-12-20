#pragma once
#include<vector>
#include<iostream>
#include<string>
#include "Observer.h"

using namespace std;

class Subject{                    //Ŀ�������
public:
	string s1;                        //����ֵ��������Ϊ˽�����ݣ�Ȼ����һ�����ȥ����ֵ������Ϊ��ʡ��                           //����ֵ
	void regiObserver(Observer *obs){
		_observer.push_back(obs);
		cout << "�Ѷ���" << endl;
	}
	void deleObserver(Observer *obs){
		_observer.pop_back();
	}
	void notify(){                //�������еĹ۲���
		vector<Observer *>::iterator it;
		for (it = _observer.begin(); it != _observer.end(); it++)
			(*it)->update(this);
	}
private:
	vector<Observer *> _observer;        //�۲�������
};
