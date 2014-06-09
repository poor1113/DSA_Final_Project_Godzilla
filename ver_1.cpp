/* DSA Final Proj Main Prog : main_ver_1.cpp */
#include "headers.h"

#ifndef MAIL_H
#define MAIL_H
#include "Mail.h"
#endif

#ifndef DB_H
#define DB_H
#include "db.h"
#endif 

#ifndef PARSER_H
#define PARSER_H
#include "parser.h"
#endif 

using namespace std;

/* [mail format]

From: Dora
Date: 13 November 2011 at 13:35
Message-ID: 3
Subject: Bakurans
To: Austin
Content:
In Star Wars, the Bakurans were humans inhabiting the planet [Bakura]. Bakurans developed a distinct culture due to their isolated location and their lack of contact with any nonhuman beings besides the Kurtzen natives. The Bakurans descended from the Bakuran Mining Cor- poration colonists who arrived at the planet around 150 BBY. They soon broke away from the corporate control and created their own senate and elected a Prime Minister. The leader of the 150 BBY Bakuran Mining Corporation expedition, Deredith Arden’s descendants were the leaders of the Bakurian government. In 4 ABY the Bakurans joined force with the Alliance to Restore the Republic to ward off the attacking Ssi-Ruuk, a saurian species from the Unknown Regions of the galaxy, who planned to conquer the planet.

*/

int main(int argc, char const *argv[])
{
	string cmd;
	Parser p;

	Database db;

	while(getline(cin,cmd)){
		p.input_cmd(cmd,db);
	}
	return 0;
}