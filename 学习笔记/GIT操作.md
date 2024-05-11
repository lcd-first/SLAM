# 下载和安装 省略 
使用【重点】

向仓库推送代码步骤：

```http
https://blog.csdn.net/weixin_43233914/article/details/103502718?ops_request_misc=&request_id=&biz_id=102&utm_term=git%20%E5%90%91github%20%E4%BB%93%E5%BA%93&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-103502718.142^v100^pc_search_result_base4&spm=1018.2226.3001.4187
```

初始化

```shell
# 初始化
git init 
# 设置用户名
git config --global user.name "lcd-first"
# 设置邮箱
git config --global user.email "1810750396@qq.com"
# 查看邮箱和用户名
git config user.name
git config user.email
# 生成ssh 密钥
ssh-keygen -t rsa -C "1810750396@qq.com"
# 获取密钥
cat  ~/.ssh/id_rsa.pub
# 在github上添加ssh密钥
# 省略
git remote add 仓库别名 仓库地址
git remote add origin git@github.com:lcd-first/SLAM.git
# 查看仓库别名
git remote
#测试是否连通
ssh -T git@github.com

git add .

git commit -m '本次提交的备注'
# origin 别名   master 是分支
git push -u origin master

```



git


git add . : 添加当前路径下的全部文件到暂存区

git commit -m 'xxx项目no.x' : 将暂存区中的文件提交到 本地仓库中

git remote add origin xxxx.git  ：添加新仓库 重命名为 origin 

git push -u origin  master -f  :  推送文件从本地仓库到远程仓库 origin 中 
