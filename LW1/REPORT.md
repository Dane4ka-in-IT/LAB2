# Отчет по лабораторной работе № 1
## по курсу "Прикладная математика и информатика"

Студент группы М8О-108Б-23 Нургалиев Даниэль Ильдарович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Git, Github, Gitlab
2. **Цель работы**: Изучить основы Git
3. **Задание**: 
- завести репозиторий (**общий под все лабораторные работы с отдельной папкой под каждую лр!**)
- отчет с листингом в Markdown (листинг - ctrl+c -> ctrl+v из терминала с форматированием в markdown)
- создать отдельную ветку в репозитории под задание
- создать коммит с листингом и отчетом
- смержить ветку в мейн
4. **Идея, метод, алгоритм решения задачи**: 
- скачать git
- завести репозиторий
- свзяать его с удалённым
- создать ветку
- смержить её  с веткой master
5. **Сценарий выполнения работы**: выполнить команды, проверить результат
6. **Протокол**: 
```
rombica@DESKTOP-C383C55 MINGW64 ~
$ pwd
/c/Users/rombica

rombica@DESKTOP-C383C55 MINGW64 ~
$ mkdir GIT-projekt

rombica@DESKTOP-C383C55 MINGW64 ~
$ cd GIT-projekt && git init
Initialized empty Git repository in C:/Users/rombica/GIT-projekt/.git/

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ mkdir LW1 LW2 LW3 LW4 LW5 LW6 LW7 LW8 LW9 LW10 LW11 LW12 LW13 LW14 LW15

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ ls
LW1/  LW10/  LW11/  LW12/  LW13/  LW14/  LW15/  LW2/  LW3/  LW4/  LW5/  LW6/  LW7/  LW8/  LW9/

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ cd LW1

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW1 (master)
$ ls
REPORT.md

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW1 (master)
$ cd ..

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git add --all

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git commit -m 'Первая лаба изменена'
[master (root-commit) 737ef0f] Первая лаба изменена
 1 file changed, 144 insertions(+)
 create mode 100644 LW1/REPORT.md

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ cd ~

rombica@DESKTOP-C383C55 MINGW64 ~
$ ls -la .ssh/
total 23
drwxr-xr-x 1 rombica 197121    0 Sep 30 20:58 ./
drwxr-xr-x 1 rombica 197121    0 Sep 30 22:04 ../
-rw-r--r-- 1 rombica 197121  432 Sep 25 09:58 id_ed25519
-rw-r--r-- 1 rombica 197121  112 Sep 25 09:58 id_ed25519.pub
-rw-r--r-- 1 rombica 197121 1098 Sep 25 10:02 known_hosts
-rw-r--r-- 1 rombica 197121  362 Sep 25 10:02 known_hosts.old

rombica@DESKTOP-C383C55 MINGW64 ~
$ rm -rf ~/.ssh

rombica@DESKTOP-C383C55 MINGW64 ~
$ ls -la .ssh/
ls: cannot access '.ssh/': No such file or directory

rombica@DESKTOP-C383C55 MINGW64 ~
$ ssh-keygen -t ed25519 -C "daniel.nurgaliev2005@gmail.com"
Generating public/private ed25519 key pair.
Enter file in which to save the key (/c/Users/rombica/.ssh/id_ed25519):
Created directory '/c/Users/rombica/.ssh'.
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /c/Users/rombica/.ssh/id_ed25519
Your public key has been saved in /c/Users/rombica/.ssh/id_ed25519.pub
The key fingerprint is:
SHA256:XUyt3zRJUzouNZVe9/Ddcm+912WLOkFMHngRJ9xkM+k daniel.nurgaliev2005@gmail.com
The key's randomart image is:
+--[ED25519 256]--+
|          o+*B. =|
|         . B+o=*o|
|          = =.BoO|
|         . =.E.*B|
|        S o ...=+|
|           . .. B|
|            . .o=|
|           . . oo|
|           .o   .|
+----[SHA256]-----+

rombica@DESKTOP-C383C55 MINGW64 ~
$ ls -a ~/.ssh
./  ../  id_ed25519  id_ed25519.pub

rombica@DESKTOP-C383C55 MINGW64 ~
$ clip < ~/.ssh/id_ed25519.pub

rombica@DESKTOP-C383C55 MINGW64 ~
$ ssh -T git@github.com
The authenticity of host 'github.com (140.82.121.3)' can't be established.
ED25519 key fingerprint is SHA256:+DiY3wvvV6TuJJhbpZisF/zLDA0zPMSvHdkr4UvCOqU.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'github.com' (ED25519) to the list of known hosts.
Hi Dane4ka-in-IT! You've successfully authenticated, but GitHub does not provide shell access.

rombica@DESKTOP-C383C55 MINGW64 ~
$ cd GIT-projekt

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git remote add origin git@github.com:Dane4ka-in-IT/LAB2.git

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git remote -v
origin  git@github.com:Dane4ka-in-IT/LAB2.git (fetch)
origin  git@github.com:Dane4ka-in-IT/LAB2.git (push)

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git push -u origin master

Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 2.74 KiB | 2.74 MiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0
remote:
remote: Create a pull request for 'master' on GitHub by visiting:
remote:      https://github.com/Dane4ka-in-IT/LAB2/pull/new/master
remote:
To github.com:Dane4ka-in-IT/LAB2.git
 * [new branch]      master -> master
branch 'master' set up to track 'origin/master'.

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git add --all

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git commit -m 'загрузка'
[master 4c2ca0a] загрузка
 1 file changed, 1 insertion(+), 1 deletion(-)

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git status
On branch master
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git push
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 330 bytes | 330.00 KiB/s, done.
Total 4 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To github.com:Dane4ka-in-IT/LAB2.git
   737ef0f..4c2ca0a  master -> master

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git branch new-task

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git checkout new-task
Switched to branch 'new-task'

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (new-task)
$ cd LW1

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW1 (new-task)
$ touch report.md

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW (new-task)
$ touch report.md

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW (new-task)
$ git checkout master

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git add --all

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git commit -m 'Оформление в стиле markdown'
[master 8aa2151] Оформление в стиле markdown
 1 file changed, 171 insertions(+), 106 deletions(-)

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ git push
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 2.88 KiB | 2.88 MiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0
To github.com:Dane4ka-in-IT/LAB2.git
   4c2ca0a..8aa2151  master -> master

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)

```
7. **Выводы**: Я научился создавать репозитории, связывать локальные и удалённые репозитории, создавать ветки и мержить их. Также я оформил отчёт в стиле markdown