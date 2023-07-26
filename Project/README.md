
```shell
|-- test
|   |-- ...  #	生成的各种.data和.xml文件
|-- thirdpart
|   |-- tinyxml2.cpp
|   |-- tinyxml2.h
|-- src
|   |-- binary.h		   #	二进制序列化和反序列化
|   |-- xml.h			   #	xml序列化和反序列化
|   |-- util.h			   #	测试工具
|   |-- UserDefinedType.h  #	定义的结构类型
|-- main.cpp		   #	测试程序
|-- Makefile
```

在该文件夹下打开命令行窗口，输入`mingw32-make`完成编译

此时再双击运行`main.exe`，即可看到测试样例的运行结果，并且生成的序列文件也会被存储再`test`文件夹下（我已经清空`test`文件夹，运行后才会生成序列化文件）

按下空格即可执行下一个测试

:round_pushpin:  **注意：**我采取的编译方式为`mingw32-make` ，适用于`windows平台`
