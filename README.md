parse_conf
==========

###使用：
直接引入conf.h文件即可，方法见测试程序test.cpp

###配置文件的格式：
```
#注释符，凡是出现在#之后的都不会被解析
# = 之后的空格或者tab也会自动去掉
[xx]  #comment 
x = xxxx 
y = yy 
[yy] 
    y = yy
```
