// Observer.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<vector>
#include<iostream>
#include<string>


using namespace std;

class Subject;
class Observer{                    //�۲��߳�����
public:
	virtual void registerSubject(Subject *base) = 0;
	virtual void update(Subject *base) = 0;
protected:
	Subject * _subject;
};

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



class FSubject :public Subject{
public:
	void set(string s){
		s1 = s;
	
		notify();                                    //֪ͨ�۲��ߡ���������ִ��˳���Ѿ���֤�����еĹ۲��߶��Ѿ�����������
	}
};

class FObserver :public Observer{    //��һ���۲���������
public:


	void registerSubject(Subject *base){

		_subject = base;
		_subject->regiObserver(this);
	}

	void update(Subject *base){
		s1 = base->s1;
	
		display();
	}
	void display(){
		cout << "��һ��observer\n" <<"�õ�������ϢΪ"<<s1 << endl;
		
	}
private:
	string s1;
	
};

class SObserver :public Observer{    //�ڶ����۲���������
public:
	void registerSubject(Subject *base){
		_subject = base;
		_subject->regiObserver(this);
	}
	void update(Subject *base){
		s1 = base->s1;

		display();
	}
	void display(){
		cout << "�ڶ���observer\n" << "�õ�������ϢΪ"<< s1 << endl;
	
	}
private:
	string s1;
	
};

int main()
{
	FSubject * sub = new FSubject;

	FObserver * one = new FObserver();	
	one->registerSubject(sub);

	SObserver * two = new SObserver();
	two->registerSubject(sub);

	sub->set("1");

	sub->set("2");

	sub->set("3");
	return 0;
}
