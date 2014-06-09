#ifndef HEADERS_H
#define HEADERS_H
#include "headers.h"
#endif

#include "parser.h"

Parser::Parser(){}

void Parser::input_cmd(string cmd,Database &db){
	if(cmd.substr(0,3)=="add")this->add_mail(cmd.substr(4),db);
	else if(cmd.substr(0,6)=="remove")this->remove_mail(cmd.substr(7),db);
	else if(cmd.substr(0,5)=="query")this->query_mail(cmd.substr(6),db);
	else if(cmd.substr(0,4)=="show")this->show(db);
}
void Parser::show(Database &db){
	db.show_mails();
}

void Parser::add_mail(string cmd,Database &db){
	
	fstream f;
	f.open(cmd.c_str(),ios::in);
	//FILE* f = fopen(cmd.c_str(),"r");
	Mail* m = new Mail(f);
	db.add(m);
	//add a mail to the database
}

void Parser::remove_mail(string cmd,Database &db){
	int rm_id = atoi(cmd.c_str());
	db.remove(rm_id);
} 

void Parser::query_mail(string cmd,Database &db){
	//this is super hard to parse QQ

	/*
	query [-f"<from>"] [-t"<to>"] [-d<date1>~<date2>] <keyword-expression>:
	<from>       := <string>
    <to>         := <string>
    <date>       := {YYYYMMDDhhmm} or {blank}
    <expression> := <keyword> or (<expression>) or !<expression>
                     or <expression>|<expression> or <expression>&<expression>
    <keyword>    := <string>
    <string>     := {any alpha-numeric string without whitespace or punctuation}
	*/
	query q;

    if(cmd.substr(0,2)=="-f"){
    	q.from = cmd.substr(2);
    	q._from = true;
    	//eat -f 
    }

    else if(cmd.substr(0,2)=="-t"){
    	q.to = cmd.substr(2);
    	q._from = true;
    }

    else if(cmd.substr(0,2)=="-d"){
 		//其實也就只有date1~   date1~date2  ~date2這幾種
    	if(cmd[2]=='~'){
    		//~date2 
    		//-dYYYYMMDDhhmm
    		//012345678901234
    		q.date2.y 	= atoi(cmd.substr(2,4).c_str());
    		q.date2.m 	= atoi(cmd.substr(6,2).c_str());
    		q.date2.d 	= atoi(cmd.substr(8,2).c_str());
    		q.date2.h 	= atoi(cmd.substr(10,2).c_str());
    		q.date2.mi 	= atoi(cmd.substr(12,2).c_str());
    		q._date2 = true;
    		//q.date1.y = atoi(cmd.substr(2,4).c_str());
    	}
    	else{
    		q.date1.y 	= atoi(cmd.substr(2,4).c_str());
    		q.date1.m 	= atoi(cmd.substr(6,2).c_str());
    		q.date1.d 	= atoi(cmd.substr(8,2).c_str());
    		q.date1.h 	= atoi(cmd.substr(10,2).c_str());
    		q.date1.mi 	= atoi(cmd.substr(12,2).c_str());
    		q._date1 = true;
    		if(cmd[14]=='~'){
        		q.date2.y 	= atoi(cmd.substr(15,4).c_str());
        		q.date2.m 	= atoi(cmd.substr(19,2).c_str());
        		q.date2.d 	= atoi(cmd.substr(21,2).c_str());
        		q.date2.h 	= atoi(cmd.substr(23,2).c_str());
        		q.date2.mi 	= atoi(cmd.substr(25,2).c_str());
        		q._date2 = true;
    		}
    	}
    }

    else{
    	//parse expr
    }

}
