### Git学习笔记2020.9.11

#### 一

```

```

####  安装配置

下载安装git后，配置本机环境，由于Git是分布式版本控制系统，每台机器需要配置仓库对应的用户名和Email地址；命令如下：

```c
git config --global user.name "IsanaYashiro"
git config --global user.email "2037078081@qq.com"
```

#### 二 创建版本库

软件开发通过版本进行阶段管理，版本库又名仓库，英文名**repository**，也就是用来存放代码的地方，以目录形式存在，这个目录里面的所有文件都可以被Git管理起来，每个文件的修改、删除，Git都能跟踪，以便任何时刻都可以追踪历史，或者在将来某个时刻可以“还原”。

首先创建一个空目录作为版本库

```c
mkdir gitspace
cd gitspace
```

进入创建好的目录后，对该目录初始化，就可以使用git对这个目录中的内容进行管理了

```c
git init
```

初始化完成后，在目录中出现.git的文件夹，这个文件夹就是git用来管理这个版本库的工作区了

以建立一个新的readme.txt文件为例，尝试使用git管理文件

首先编写readme.txt文件内容

```c
git is a version control system
git is a free softward
```

对于一个新文件，使用git管理有以下几步

1. 将文件添加到仓库

   ```c
   git add readme.txt
   ```

   此时文件从工作区被加入到版本库的暂存区，关于暂存区后续会有详细的讲解。

2. 把文件提交到版本库





![git-repo](https://www.liaoxuefeng.com/files/attachments/919020037470528/0)