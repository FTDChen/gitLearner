#ifndef SUBJECTIF_H
#define SUBJECTIF_H

class ObserverIf;

//abstract subject
class SubjectIf
{
public:
	virtual void registerObserver(ObserverIf *) = 0;//register observer
	virtual void removeObserver(ObserverIf *) = 0;//remove observer
	virtual void notifyObserver() = 0;//notify observer

};
#endif //SUBJECTIF_H
