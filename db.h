#ifndef HEADERS_H
#define HEADERS_H
#include "headers.h"
#endif

#ifndef MAIL_H
#define MAIL_H
#include "Mail.h"
#endif

class Database{
	//this is the generalized mail data base, supports add, remove, query.

	//first edition : use simple vector.  add in O(1), remove in O(n), query in O(n)

public:
	Database();

	void add(Mail* m);
	void remove(int rm_id);

	void show_mails();

private:
	vector<Mail*> mail_list;
};