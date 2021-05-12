**Image 命令**

```
docker images

docker search

docker pull

docker rmi

docker rmi -f 容器id #删除指定容器

docker rmi -f 容器id 容器id 容器id #删除多个容器

docker rmi -f $(docker images -aq) #删除多个容器
```

**容器命令**

```
docker run

docker run [options] image

\#options

—-name=“name” 

-d   后台方式运行

-it  指定交互式运行，进去容器查看内容

docker ps

\# docker ps 

-a # 列出所有运行容器 + history

-n=? # 显示最近创建的容器

-q # 只显示容器的编号

退出容器

exit #直接中止

Ctrl + P + Q #退出但不中止

删除容器

docker rm 容器id

docker rm -f $(docker ps -aq)

docker ps -a -q|xargs docker rm #这两个命令都可以删除所有的容器

启动和停止容器的操作

docker start container-id

docker restart container-id

docker stop container-id

docker kill container-id 
```



**常用其他命令**

**后台启动容器**

docker run -d centos

常见的坑: docker 容器使用后台运行的时候，就必须有要有一个前台进程， docker发现没有应用。就会自动停止

查看日志

docker logs

查看容器中的进程信息

top命令

查看镜像元数据

docker inspect containId

进入当前正在运行的容器

docker exec -it 容器id