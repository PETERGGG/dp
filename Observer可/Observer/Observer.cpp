// Observer.cpp : 定义控制台应用程序的入口点。
//
#include<vector>
#include<iostream>
#include<string>


using namespace std;

class Subject;
class Observer{                    //观察者抽象类
public:
	virtual void registerSubject(Subject *base) = 0;
	virtual void update(Subject *base) = 0;
protected:
	Subject * _subject;
};

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



class FSubject :public Subject{
public:
	void set(string s){
		s1 = s;
	
		notify();                                    //通知观察者。主函数的执行顺序已经保证了所有的观察者都已经进入容器内
	}
};

class FObserver :public Observer{    //第一个观察者派生类
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
		cout << "第一个observer\n" <<"得到订阅信息为"<<s1 << endl;
		
	}
private:
	string s1;
	
};

class SObserver :public Observer{    //第二个观察者派生类
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
		cout << "第二个observer\n" << "得到订阅信息为"<< s1 << endl;
	
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
