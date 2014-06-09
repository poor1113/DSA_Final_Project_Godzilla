#ifndef HEADERS_H
#define HEADERS_H
#include "headers.h"
#endif

#include "mail.h"

Mail::Mail(fstream &f){
	//char buf[1000]={'\0'};
	string buf;

	//parse From
	getline(f,buf);
	this->from = buf.substr(6);

	//parse date
	getline(f,buf);
	this->date = buf.substr(6);

	//parse id
	getline(f,buf);
	this->id = atoi(buf.substr(12).c_str());

	//parse subject
	getline(f,buf);
	this->subject = buf.substr(9);

	//parse to
	getline(f,buf);
	this->to = buf.substr(4);

	//parse content
	getline(f,buf); //should be "Content:"		
	//ostringstream c_buf;
	string c_buf;
	while(getline(f,buf)){
	//	c_buf << buf << endl;
		c_buf += buf+'\n';
	}
	//buf = c_buf.str();
	int i=0;
	for(i=0;i<c_buf.size();i++){
		if(!isalnum(c_buf[i])&&c_buf[i]!='\n'){
			c_buf[i] = ' ';
		}
	}
	c_buf = reduce(c_buf);
	this->content = c_buf;
}

/* [mail format]
From: Dora
Date: 13 November 2011 at 13:35
Message-ID: 3
Subject: Bakurans
To: Austin
Content:
In Star Wars, the Bakurans were humans inhabiting the planet [Bakura]. Bakurans developed a distinct culture due to their isolated location and their lack of contact with any nonhuman beings besides the Kurtzen natives. The Bakurans descended from the Bakuran Mining Cor- poration colonists who arrived at the planet around 150 BBY. They soon broke away from the corporate control and created their own senate and elected a Prime Minister. The leader of the 150 BBY Bakuran Mining Corporation expedition, Deredith Arden’s descendants were the leaders of the Bakurian government. In 4 ABY the Bakurans joined force with the Alliance to Restore the Republic to ward off the attacking Ssi-Ruuk, a saurian species from the Unknown Regions of the galaxy, who planned to conquer the planet.

*/

void Mail::show_mail(){
	cout<<"-----<Mail Start>-----"<<endl;
	cout<<"From: "<<this->from<<endl;
	cout<<"Date: "<<this->date<<endl;
	cout<<"Message-ID: "<<this->id<<endl;
	cout<<"Subject: "<<this->subject<<endl;
	cout<<"To: "<<this->to<<endl;
	cout<<"Content: "<<endl;
	cout<<this->content<<endl;
	cout<<"-----<Mail End>-----"<<endl;
}
