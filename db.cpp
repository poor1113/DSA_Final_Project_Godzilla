#ifndef HEADERS_H
#define HEADERS_H
#include "headers.h"
#endif

#include "db.h"


Database::Database(){}

void Database::add(Mail* m){
	mail_list.push_back(m);
	m->show_mail();
}
void Database::remove(int rm_id){
		for (vector<Mail*>::iterator it = mail_list.begin() ; it != mail_list.end(); ++it){
			if((*it)->id==rm_id) {mail_list.erase(it);break;}
		}	
}

void Database::show_mails(){
	cout<<"From\t\tid\t\tSubject\t\t\n";
		for (vector<Mail*>::iterator it = mail_list.begin() ; it != mail_list.end(); ++it){
			cout<<(*it)->from<<"\t\t"<<(*it)->id<<"\t\t"<<(*it)->subject<<"\t\t\n";
		}	
}
