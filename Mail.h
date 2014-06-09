#ifndef HEADERS_H
#define HEADERS_H
#include "headers.h"
#endif

using namespace std;

class Mail{

public:
	string from;
	string date; //need comparism mechanism
	int id;
	string subject;
	string to;
	string content;
	Mail(fstream &f);
	void show_mail();
};