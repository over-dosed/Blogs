# 搭建内网穿透

## 背景

在家用ssh连内网的实验室电脑 (fprc)
有云端公网服务器 （frps）

## 解决方案

<https://blog.csdn.net/weixin_43922901/article/details/109261700>
基本是按照这个来，记得[这里](https://github.com/fatedier/frp/releases)下载两个分别适合操作系统的安装包，一个修改frps,放在公网服务器上；一个修改frpc，放在内网电脑上

## 后台运行&开机自启动

<https://blog.csdn.net/weixin_41534481/article/details/116243139>

<https://blog.csdn.net/x7418520/article/details/81077652>

主要采用这两个的systemctl方法。

## vscode ssh 免密码

<https://www.cnblogs.com/dev-sy/p/12893012.html>
这个教程还可以

这几个记得改，在/etc/ssh/sshd_config里面
keysfile路径记得改
有#记得不要去掉！
![20220107213725](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220107213725.png)

重启ssh：
![20220107211528](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220107211528.png)

## linux sudo 免密

1. 使用 sudo visudo 打开 /etc/sudoers 文件
2. **增加一行**
    your_user_name     ALL=(ALL:ALL) NOPASSWD:ALL
3. 修改 %sudo   ALL=(ALL:ALL) ALL
    为 %sudo   ALL=(ALL:ALL) NOPASSWD:ALL
4. ctrl + x 保存退出

![20220107231430](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220107231430.png)

## tips

记得打开内网的ssh服务

记得内网和服务器的防火墙

记得连接时会用到内网的用户，密码，权限
