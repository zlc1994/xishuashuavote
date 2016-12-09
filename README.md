千里码-喜刷刷自动投票
======

> **只支持Python3**，**Python2不适用**。

纯Python来计算验证码值的话太慢，所以将计算验证码的模块用C改写（计算MD5的代码来源：https://gist.github.com/creationix/4710780），然后利用Python去填写验证码投票，大概20秒投一次。

![日志](!%5Balt%20tag%5D%28https://raw.githubusercontent.com/zlc1994/xishuashuavote/master/doc/screeshot.png)

### 使用

```
$ sudo python3 setup.py install
```

`cp vote.py.example vote.py && vim vote.py`，将`user`，`token`和`vote_num`（即当前票数）改为你自己的，然后运行：

```
$ python3 vote.py
```

### 运行时间比较


![时间比较](!%5Balt%20tag%5D%28https://raw.githubusercontent.com/zlc1994/xishuashuavote/master/doc/screeshot2.png)
