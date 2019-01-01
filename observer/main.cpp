#include "concreteSubject.h"
#include "concreteObserver.h"
#include <iostream>

using namespace std;
/*observer designPattern*/

//观察者模式定义了对象间一对多依赖，包含subject和observer，类似于C/S关系。
//观察者模式的目的是让subject和observer之间松耦合。
//此处举例：subject 为 team leader ，observer 为 team member
#define freeObject(p) { if(p){delete(p); (p)=NULL;}}

int main()
{
	//creat subject 
	ConcreteSubject *pSubject = new ConcreteSubject();
	
	//create observer
	ObserverIf *pMember1 = new ConcreteObserver("member1");
	ObserverIf *pMember2 = new ConcreteObserver("member2");
	
	//register observer
	pSubject->registerObserver(pMember1);
	pSubject->registerObserver(pMember2);

	//change the temperature,and notify the observers
	pSubject->setAttr(30);
	cout<<"Notify all member"<<endl;
	pSubject->notifyObserver();

	//remove observser
	cout<<"Member2 is removed"<<endl;
	pSubject->removeObserver(pMember2);

	//modify the temperature again,and notify observers
	pSubject->setAttr(25);
	pSubject->notifyObserver();
	
	//free all objects
	freeObject(pMember1);
	freeObject(pMember2);
	freeObject(pSubject);
	
	return 0;
}

