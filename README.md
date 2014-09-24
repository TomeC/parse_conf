parse_conf
==========

###编译：
>g++ test.cpp

###配置文件的格式：
\#注释符，凡是出现在#之后的都不会被解析 <br />
\# = 之后的空格或者tab也会自动去掉  <br />
[xx]  #comment  <br />
x = xxxx  <br />
y = yy  <br />
[yy]  <br />
  y = yy  <br />

LoadConf(path)  //path是需要解析的文件的路径，比如 "./conf/netsver.conf"; <br />
getString (const string &sec, const string &name)   //返回sec下name的值，string类型 <br />
getInt (const string &sec, const string &name)      //返回sec下name的值，int类型  <br />
  
