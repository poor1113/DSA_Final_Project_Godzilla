#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
	//ostringstream c_buf;
	ostringstream ns;
	ns << "add" << argv[1] << "mails";
	//string n = "add"+argv[1]+"mails";
	FILE* f = fopen(ns.str().c_str(),"w");
	for(int i=1;i<=atoi(argv[1]);i++){
		fprintf(f,"add test_data/mail%d\n",i);
	}
	fclose(f);
	return 0;
}