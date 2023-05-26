在当前窗口下打开命令行

**输入**

```
mingw32-make
```

编译连接我所有的程序

然后**双击**运行

```
test.bat
```

即可看到我的测试样例

运行测试样例后会生成`Diary.txt`, 所有对日记的操作都会被保存到该文件中



Add的对象为`diary1.txt`,`diary2.txt`,`diary3.txt`, 以`diary1.txt`为例，它的内容为

```
2023-05-01
Today was a 5.1 day. I went for a walk in the park and enjoyed the sunshine.The weather was perfect, and the birds were singing.I also had a great conversation with an old friend.
```

其中`2023-05-01`表示这篇日记的时间，你可以任意修改这个时间以及下方的内容（但是，为了方便起见，我的读取文件是以`.\n`作为结束符，这意味着日记的内容不能换行）
