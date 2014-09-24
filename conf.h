#ifndef __CONF_H__
#define __CONF_H__

#include <fstream>
#include <map>
#include <string>
using namespace std;

class Conf
{
public:
	typedef map<string, string>         MapSection;
    typedef map<string, MapSection>     MapFile;
    //typedef map<string, MapFile>        MapFiles;
public:
	Conf ()	{ ; }
	int LoadConf (const string &path)
	{
		if (path.length () == 0)
		{
			cout<<"需要的解析的路径长度为0"<<endl;
			return 1;
		}

		if (fs.open (path))
		{
			cout<<"打开文件"<<path<<"错误"<<endl;
			return 2;	
		}

		size_t first = 0, last = 0;
		string inbuf, section;
		while (!fs.eof ())
		{
			getline (fs, inbuf);

			// 分析是否为注释行, 以#为注释
            first = inbuf.find_first_of("#"); 
            if (first != (string::npos))
            {
                inbuf = inbuf.substr(0, first);
            }
			//空行或注释行
			if (inbuf.size () == 0)
				continue;	
			
			if (inbuf[0] == '[')
			{
				last = inbuf.rfind (']');
				if(last != string::npos)
				{
					section = inbuf.substr (1, last - 1);
					MapSection empty;
					mconf.insert (MapFile::value_type (section, empty));
				}else
				{
					cout<<"格式错误"<<endl;
					return 3;
				}
			}else
			{
				first = inbuf.find('=');
				if (first == string::npos)
				{
					cout<<"格式错误"<<endl;
					return 4;
				}
				string name = inbuf.substr(0, first);
				string value = inbuf.substr(first+1, string::npos);
				Trim(name, " \t\r\n");	
				Trim(value, " \t\r\n");
				MapSection& mapSection = mconf[section];
				mapSection.insert(MapSection::value_type(name, value));
			}

		}
	}
	string getString (const string &sec, const string &name) const
	{
		if (mconf.size () < 1)
			return NULL;
		MapFile::const_iterator mfi = mconf.find (sec);
		if (mfi != mconf.end ())
		{
			MapSection tmp = mfi->second;
			MapSection::const_iterator msi = tmp.find (name);
			if (msi != tmp.end ())
				return msi->second;
		}
		return NULL;
	}
	int getInt (const string &sec, const string &name) const
	{
		string tmp = getString (sec, name);
		string::iterator si = tmp.begin ();
		int result = 0;
		while (si != tmp.end ())
		{
			result = result*10 + (*si - '0');
			si++;
		}
		return result;
	}
	string& Trim(string& line, const char* trim)
	{
		size_t first = line.find_first_not_of(trim);
		size_t last  = line.find_last_not_of(trim);
		if (first == string::npos || last == string::npos)
		{
			line = "";
		}
		else
		{
			line = line.substr(first, last-first+1);
		}

		return line;
	}
private:
	MapFile mconf;
	ifstream fs;
};

#endif
