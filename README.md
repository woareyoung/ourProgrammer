# 注意

 - 请确认代码没有错误的时候再发代码上来。
 - 当github上代码版本较高的时候，需要来下来更新本地代码，并添加自己的代码进去。

# git简易教程

一般的流程就是先把2、3之后4提交到服务器。但是要是遇到了冲突的时候，就可能是因为本地和远程仓库的版本不一致导致的，这个时候就需要我们执行7，拉取远程仓库的内容到本地，经过合并后再次提交。

## 1.查看git仓库的提交记录
git log

## 2.添加修改的部分到本地仓库
git add *（*表示全部添加）

## 3.提交修改的部分到本地仓库
git commmit -m "文字信息"

## 4.提交到远程git仓库
git push origin master

## 5.强制提交到远程git仓库
（备注：只有在回滾的时候用到，注意没事不要乱用，会强制覆盖掉远程仓库的东西的）
git push -f

## 6.回滾一个版本
（注意：回滾了之后找不回来原来的版本，除非必要，否则不要随便使用）
git reset --hard HEAD^

## 7.拉取更新
git fetch origin master

git pull origin master
