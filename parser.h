#ifndef HEADERS_H
#define HEADERS_H
#include "headers.h"
#endif

#ifndef MAIL_H
#define MAIL_H
#include "Mail.h"
#endif

#ifndef DB_H
#define DB_H
#include "db.h"
#endif 

struct date{
    int y;
    int m;
    int d;
    int h;
    int mi; //minutes;
};

struct expr{};

class query{
public:
    string from;
    string to;
    date date1;
    date date2;
    expr e;
    bool _from;
    bool _to;
    bool _date1;
    bool _date2;
    bool _e;
public:
    query(){
        _from = false;
        _to = false;
        _date1 = false;
        _date2 = false;
        _e = false;
    }
};


class Parser{
public:

	Parser();

	void input_cmd(string cmd,Database &db);

	void show(Database &db);

	void add_mail(string cmd,Database &db);

	void remove_mail(string cmd,Database &db);

	void query_mail(string cmd,Database &db);

};

