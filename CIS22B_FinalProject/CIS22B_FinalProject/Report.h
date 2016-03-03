#ifndef _REPORT_H
#define _REPORT_H

#include <string>
using namespace std;

class Report
{
private:
	BookDatabase* database;
public:
	Report(BookDatabase* dtbs);
};


#endif
