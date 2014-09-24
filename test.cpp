#include <iostream>
#include "conf.h"
using namespace std;

int main ()
{

	Conf cf;
	cf.LoadConf ("server.conf");
	cout<<cf.getString ("CfgPath", "MysqlCfg")<<endl;
	cout<<cf.getInt ("server", "port")<<endl;
	return 0;
}
