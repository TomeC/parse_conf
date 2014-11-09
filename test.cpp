#include <iostream>
#include "conf.h"
using namespace std;

int main ()
{

	Conf cf;
	cf.LoadConf ("server.conf");
	cout<<cf.getString ("serverNet", "ip")<<endl;
	cout<<cf.getInt ("serverNet", "port")<<endl;
	return 0;
}
