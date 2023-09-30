# Отчёт по лабораторной работе №1
---

## по курсу "Фундаментальная информатика"
---

Студент группы М8О-108Б-23 Нургалиев Даниэль Ильдарович

Работа выполнена

Преподаватель: каф. 806 Севастьянов  Виктор Сергеевич

1. **Тема**: Bash, linux terminal
2. **Цель работы**: Опробовать команды
3. **Задание**: 
- Опробовать следующие команды:
    - who
    - pwd
    - ls
    - cd
    - cp
    - mv
    - rm
    - cat
    - ps
    - tail
    - head
    - grep
    - history
    - mkdir
    - rmdir
    - sudo
    - echo
    - ssh
    - scp
    - ssh-keygen
    - ssh-copy-id
- Использовать основные команды
- Сохранить листинг в файл
- Заархивировать
- Отправить на удаленную машину, там разархивировать
- Скачать разархивированный файл к себе на машину
- Составить отчет с листингом в формате markdown
- Выложить на github через merge веток
4. **Идея, метод, алгоритм решения задачи**:
- Запустить GIT
- Изучить новые команды в интернете
- Опробовать новые команды и вспомнить старые
- Идти по заданию
- Составить отчет и отправить на GitHub
5. **Сценарий выполнения работы**: Изучить новые команды и применить их в терминале. Выполнить архивирование и разаархивирование.
6. **Протокол**:
```
rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ pwd
/c/Users/rombica/GIT-projekt/LW2

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ls

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ cd ..

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ ls
LW1/  LW10/  LW11/  LW12/  LW13/  LW14/  LW15/  LW2/  LW3/  LW4/  LW5/  LW6/  LW7/  LW8/  LW9/

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ touch test.txt

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ cp test.txt LW2

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ cd LW2

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ls
test.txt

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ rm test.txt

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ls

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ cd ..

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ mv test.txt LW2

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ ls
LW1/  LW10/  LW11/  LW12/  LW13/  LW14/  LW15/  LW2/  LW3/  LW4/  LW5/  LW6/  LW7/  LW8/  LW9/

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt (master)
$ cd LW2

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ls
test.txt

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ cat test.txt
Файл зачисленных в МАИ с предоставлением места в общежитии (постарался)
№ рег. номер      снилс    г.рожд гражданство м  и\ф р И.д СумБал
1 БД-00-26542 145-293-402 58 2003 гражданин РФ 92 100 92 5 289
2 БД-00-32441 158-509-935 07 2005 гражданин РФ 100 88 93 5 286
3 БД-00-13311 177-338-731 05 2005 гражданин РФ 90 95 93 5 283
4 БД-00-32660 192-352-684 83 2005 гражданин РФ 90 93 97 2 282
5 БД-00-30634 193-216-110 47 2005 гражданка РФ 92 95 87 5 279
6 БД-00-17899 174-152-085 52 2005 гражданка РФ 92 88 93 5 278
7 БД-00-33190 150-820-493 39 2005 гражданин РФ 84 98 91 5 278
8 БД-00-33417 205-118-075 14 2006 гражданка РФ 82 97 89 8 276
9 БД-00-33385 182-092-904 70 2003 гражданин РФ 100 80 95 0 275
10 БД-00-33225 157-506-851 86 2005 гражданин РФ 92 90 93 0 275
11 БД-00-33052 165-518-278 86 2004 гражданин РФ 86 93 96 0 275
12 БД-00-33185 173-742-178 80 2005 гражданин РФ 74 99 97 5 275
13 БД-00-30544 159-869-654 56 2005 гражданин РФ 96 95 83 0 274
14 БД-00-32916 156-977-246 26 2003 гражданин РФ 96 78 90 10 274
15 БД-00-26735 185-910-749 03 2005 гражданка РФ 78 95 93 7 273
16 БД-00-28184 174-201-562 37 2005 гражданин РФ 88 93 91 0 272
17 БД-00-34094 168-324-823 87 2005 гражданин РФ 90 91 89 2 272
18 БД-00-30749 170-910-115 33 2005 гражданин РФ 86 90 95 0 271
19 БД-00-24729 159-360-914 92 2005 гражданин РФ 82 98 91 0 271
20 БД-14-27090 201-548-474 36 2005 УКРАИНА
(соотечественник) 86 83 100 2 271
21 БД-00-33349 154-015-678 41 2005 гражданин РФ 82 95 89 5 271
22 БД-00-34263 206-704-142 30 2005 гражданин РФ 88 93 89 0 270
23 БД-00-32335 207-724-951 72 2005 гражданин РФ 88 89 93 0 270
24 БД-00-28306 136-086-010 40 2005 гражданин РФ 82 93 93 2 270
25 БД-00-29933 195-153-845 95 2005 гражданка РФ 78 90 97 5 270
26 БД-00-22497 206-730-823 47 2005 гражданин РФ 82 88 93 7 270
27 БД-00-18839 190-955-664 12 2005 гражданка РФ 82 85 95 7 269
28 БД-00-6083 158-925-066 05 2005 гражданин РФ 78 90 93 8 269
Системный номер: 913130 4 из 69
29 БД-00-19939 158-516-614 87 2005 гражданин РФ 88 85 95 0 268
30 БД-00-22079 198-237-920 21 2005 гражданин РФ 82 90 91 5 268
31 БД-00-26472 169-025-712 74 2005 гражданка РФ 78 88 95 7 268
32 БД-00-26463 164-760-162 73 2004 гражданин РФ 88 93 85 0 266
33 БД-00-29970 156-793-447 15 2005 гражданин РФ 78 93 93 2 266
34 БД-00-32996 143-438-829 69 2003 гражданин РФ 84 90 87 5 266
35 БД-00-32521 153-237-459 55 2005 гражданин РФ 82 85 93 6 266
36 БД-00-28337 159-457-240 01 2005 гражданин РФ 80 100 85 0 265
37 БД-00-32475 165-525-296 81 2005 гражданин РФ 84 87 89 5 265
38 БД-00-33901 202-763-232 29 2005 гражданин РФ 82 87 91 5 265
39 БД-00-32881 158-699-060 32 2003 гражданин РФ 88 88 88 0 264
40 БД-00-12661 163-121-138 14 2005 гражданка РФ 82 85 95 2 264
41 БД-14-32079 207-714-982 74 2006 КИРГИЗИЯ
(соотечественник) 74 90 95 5 264
42 БД-00-26678 206-851-830 66 2005 гражданка РФ 86 78 93 7 264
43 БД-00-31842 151-680-456 59 2005 гражданин РФ 82 90 85 7 264
44 БД-00-33437 194-144-667 87 2005 гражданка РФ 80 88 89 7 264
45 БД-00-31860 191-450-842 70 2004 гражданин РФ 88 90 85 0 263
46 БД-00-30490 152-434-319 37 2005 гражданин РФ 88 88 87 0 263
47 БД-14-33401 000824248 2003 КАЗАХСТАН 82 92 89 0 263
48 БД-00-34056 162-204-287 27 2005 гражданин РФ 80 90 93 0 263
49 БД-00-15189 165-954-082 03 2004 гражданка РФ 80 85 98 0 263
50 БД-00-33062 146-385-611 81 2005 гражданин РФ 80 98 83 2 263
51 БД-00-33215 180-364-698 80 2005 гражданин РФ 84 85 89 5 263
52 БД-00-30722 165-649-649 17 2005 гражданин РФ 84 93 85 0 262
53 БД-00-30087 204-684-942 74 2006 гражданин РФ 84 91 87 0 262
54 БД-00-21457 172-421-508 39 2002 гражданин РФ 76 95 91 0 262
55 БД-00-30448 170-723-231 41 2006 гражданин РФ 78 90 93 0 261
56 БД-00-29299 191-047-606 59 2005 гражданин РФ 78 90 91 2 261
57 БД-00-22777 170-787-559 07 2005 гражданка РФ 78 85 91 7 261
58 БД-00-33347 166-760-442 92 2004 гражданка РФ 86 80 94 0 260
59 БД-00-33793 162-257-733 65 2005 гражданин РФ 88 80 87 5 260
60 БД-00-33892 175-842-528 01 2005 гражданин РФ 82 80 91 7 260
61 БД-00-33827 174-862-857 18 2004 гражданка РФ 84 88 87 0 259
62 БД-00-30699 157-121-680 51 2005 гражданин РФ 76 90 93 0 259
63 БД-00-2881 165-002-280 21 2005 гражданин РФ 78 95 81 5 259
64 БД-00-31049 152-781-823 79 2005 гражданин РФ 74 85 95 5 259 - эт я
65 БД-00-32487 171-136-085 37 2005 гражданка РФ 74 83 95 7 259
66 БД-00-27564 168-151-213 58 2005 гражданин РФ 86 87 85 0 258
67 БД-00-33150 143-323-913 33 2006 гражданин РФ 86 85 85 2 258
68 БД-00-23240 166-831-601 84 2005 гражданин РФ 84 85 87 2 258
69 БД-00-31847 193-038-201 55 2005 гражданин РФ 76 85 95 2 258

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ps
      PID    PPID    PGID     WINPID   TTY         UID    STIME COMMAND
      115       1     115       7484  ?         197609 00:02:25 /usr/bin/mintty
      117     115     117      10112  pty0      197609 00:02:26 /usr/bin/bash
      352     117     352       4756  pty0      197609 01:19:56 /usr/bin/ps

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ps -A | grep
ps: unknown option -- A
Try `ps --help' for more information.
Usage: grep [OPTION]... PATTERN [FILE]...
Try 'grep --help' for more information.

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ps -A | tail
ps: unknown option -- A
Try `ps --help' for more information.

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ps -A | head
ps: unknown option -- A
Try `ps --help' for more information.

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ cd ../..

rombica@DESKTOP-C383C55 MINGW64 ~
$ tail GIT-projekt/LW2/test.txt
60 БД-00-33892 175-842-528 01 2005 гражданин РФ 82 80 91 7 260
61 БД-00-33827 174-862-857 18 2004 гражданка РФ 84 88 87 0 259
62 БД-00-30699 157-121-680 51 2005 гражданин РФ 76 90 93 0 259
63 БД-00-2881 165-002-280 21 2005 гражданин РФ 78 95 81 5 259
64 БД-00-31049 152-781-823 79 2005 гражданин РФ 74 85 95 5 259 - эт я
65 БД-00-32487 171-136-085 37 2005 гражданка РФ 74 83 95 7 259
66 БД-00-27564 168-151-213 58 2005 гражданин РФ 86 87 85 0 258
67 БД-00-33150 143-323-913 33 2006 гражданин РФ 86 85 85 2 258
68 БД-00-23240 166-831-601 84 2005 гражданин РФ 84 85 87 2 258
69 БД-00-31847 193-038-201 55 2005 гражданин РФ 76 85 95 2 258

rombica@DESKTOP-C383C55 MINGW64 ~
$ tail -n 20 GIT-projekt/LW2/test.txt
50 БД-00-33062 146-385-611 81 2005 гражданин РФ 80 98 83 2 263
51 БД-00-33215 180-364-698 80 2005 гражданин РФ 84 85 89 5 263
52 БД-00-30722 165-649-649 17 2005 гражданин РФ 84 93 85 0 262
53 БД-00-30087 204-684-942 74 2006 гражданин РФ 84 91 87 0 262
54 БД-00-21457 172-421-508 39 2002 гражданин РФ 76 95 91 0 262
55 БД-00-30448 170-723-231 41 2006 гражданин РФ 78 90 93 0 261
56 БД-00-29299 191-047-606 59 2005 гражданин РФ 78 90 91 2 261
57 БД-00-22777 170-787-559 07 2005 гражданка РФ 78 85 91 7 261
58 БД-00-33347 166-760-442 92 2004 гражданка РФ 86 80 94 0 260
59 БД-00-33793 162-257-733 65 2005 гражданин РФ 88 80 87 5 260
60 БД-00-33892 175-842-528 01 2005 гражданин РФ 82 80 91 7 260
61 БД-00-33827 174-862-857 18 2004 гражданка РФ 84 88 87 0 259
62 БД-00-30699 157-121-680 51 2005 гражданин РФ 76 90 93 0 259
63 БД-00-2881 165-002-280 21 2005 гражданин РФ 78 95 81 5 259
64 БД-00-31049 152-781-823 79 2005 гражданин РФ 74 85 95 5 259 - эт я
65 БД-00-32487 171-136-085 37 2005 гражданка РФ 74 83 95 7 259
66 БД-00-27564 168-151-213 58 2005 гражданин РФ 86 87 85 0 258
67 БД-00-33150 143-323-913 33 2006 гражданин РФ 86 85 85 2 258
68 БД-00-23240 166-831-601 84 2005 гражданин РФ 84 85 87 2 258
69 БД-00-31847 193-038-201 55 2005 гражданин РФ 76 85 95 2 258

rombica@DESKTOP-C383C55 MINGW64 ~
$ head GIT-projekt/LW2/test.txt
Файл зачисленных в МАИ с предоставлением места в общежитии (постарался)
№ рег. номер      снилс    г.рожд гражданство м  и\ф р И.д СумБал
1 БД-00-26542 145-293-402 58 2003 гражданин РФ 92 100 92 5 289
2 БД-00-32441 158-509-935 07 2005 гражданин РФ 100 88 93 5 286
3 БД-00-13311 177-338-731 05 2005 гражданин РФ 90 95 93 5 283
4 БД-00-32660 192-352-684 83 2005 гражданин РФ 90 93 97 2 282
5 БД-00-30634 193-216-110 47 2005 гражданка РФ 92 95 87 5 279
6 БД-00-17899 174-152-085 52 2005 гражданка РФ 92 88 93 5 278
7 БД-00-33190 150-820-493 39 2005 гражданин РФ 84 98 91 5 278
8 БД-00-33417 205-118-075 14 2006 гражданка РФ 82 97 89 8 276

rombica@DESKTOP-C383C55 MINGW64 ~
$ head -n 3 GIT-projekt/LW2/test.txt
Файл зачисленных в МАИ с предоставлением места в общежитии (постарался)
№ рег. номер      снилс    г.рожд гражданство м  и\ф р И.д СумБал
1 БД-00-26542 145-293-402 58 2003 гражданин РФ 92 100 92 5 289

rombica@DESKTOP-C383C55 MINGW64 ~
$ cd GIT-projekt/LW2

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ grep -i "Файл зачисленных в МАИ с предоставлением места в общежитии (постарался)" test.txt
Файл зачисленных в МАИ с предоставлением места в общежитии (постарался)

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ grep -i "Файл" test.txt
Файл зачисленных в МАИ с предоставлением места в общежитии (постарался)

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ grep -i "152" test.txt
6 БД-00-17899 174-152-085 52 2005 гражданка РФ 92 88 93 5 278
46 БД-00-30490 152-434-319 37 2005 гражданин РФ 88 88 87 0 263
64 БД-00-31049 152-781-823 79 2005 гражданин РФ 74 85 95 5 259 - эт я

history
    1  mkdir papka
    2  help str
    3  help (str)
    4  help
    5  cd
    6  mkdir tmp
    7  cd tmp
    8  mkdir tmp2
    ...
    rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ history 10
  379  cd ~
  380  grep rombika
  381  cd GIT-projekt/LW2
  382  grep -i "красный" errror.txt
  383  grep -n "красный" test.txt
  384  grep -i "Файл зачисленных в МАИ с предоставлением места в общежитии (постарался)" test.txt
  385  grep -i "Файл" test.txt
  386  grep -i "152" test.txt
  387  history
  388  history 10

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ history -10
bash: history: -1: invalid option
history: usage: history [-c] [-d offset] [n] or history -anrw [filename] or history -ps arg [arg...]

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ history 5
  386  grep -i "152" test.txt
  387  history
  388  history 10
  389  history -10
  390  history 5

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ history -d 390

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ history 5
  387  history
  388  history 10
  389  history -10
  390  history -d 390
  391  history 5

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ history | grep touch
   12  touch tmp.txt
   19  touch my_scr.sh
   98  touch REPORT.md
  189  touch Test.txt
  192  touch Test.txt
  312  touch test.txt
  314  touch test.txt
  341  touch test.txt
  392  history | grep touch

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ history -c

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ history
    1  history

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ mkdir PEP8

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ls
PEP8/  test.txt

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ rmdir PEP8

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ls
test.txt

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ ssh d_nurgaliev@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct  1 01:02:27 2023 from 85.143.224.39
d_nurgaliev@vds2476450:~$ mkdir papka
d_nurgaliev@vds2476450:~$ rmdir papka
d_nurgaliev@vds2476450:~$ exit
logout
Connection to 185.5.249.140 closed.

rombica@DESKTOP-C383C55 MINGW64 ~
$ scp "C:\dir\file.zip" d_nurgaliev@185.5.249.140:~/archives
d_nurgaliev@185.5.249.140's password:
C:\dir\file.zip                                                                                                                                                                 100%   22     1.7KB/s   00:00

rombica@DESKTOP-C383C55 MINGW64 ~
$ ^C

rombica@DESKTOP-C383C55 MINGW64 ~
$ ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/c/Users/rombica/.ssh/id_rsa):
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /c/Users/rombica/.ssh/id_rsa
Your public key has been saved in /c/Users/rombica/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:wZmrEWyepiBvnWVueNdklUo0S/47e6nGh0n3zyAO9TM rombica@DESKTOP-C383C55
The key's randomart image is:
+---[RSA 3072]----+
|          +      |
|     . . * o .   |
|      + = + o    |
|     o o + +     |
|. .   B S + o    |
| o o O o + ..o.  |
|  o = = . oo++Eo |
| .   o .   o=++=.|
|           .++  +|
+----[SHA256]-----+

rombica@DESKTOP-C383C55 MINGW64 ~/.ssh
$ cat ~/.ssh/id_rsa.pub
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQCgYWb1g2WxjbaO7ro5mV5rZAZFEIZ3Re4WQkCMIS2Thc1lfxL1Odj4P1MqA8BAUpIp2UMPPaJeliwWs2P7u31jnkxqf0i8+oyVi9ckJA+8Zf6DBlMjqLpDQzMTv2yUTO5TIZzPZmUH6vZ+h6Ae51XNwuIXJ477+1xDxeBoUb3p37Pu2VTGdmfUJhz7hCWuUxCoOiSUqGIwk1P2Xmp55UBCOWIyqEzLIhYpg264b62Sy4THfKZtf/xwcAwryopeE3PFOxh2ZdLNY2WtP3UDCCxl81Y1Qfd4tjD0UjlBN7sFk+NIfQD569cDU3DCoQ9EAbIduEe0E0YTHdNku9JfAujtSMDFJLeRd8J+2S9pxo9jaI5frkpQrTV725HQF1RQj9GtUjG0QIBBvxgCv+H7+bxBEjk3eMtrNsVYpVpZoLZO3rzSX7W5dCOODRZb/rEzAEjOXU/d2pg+UFjiBBZM9QjhAAHijLraM6Ncij9jEKYn1cVCpDsRMQD1VdNSRYZiSUM= rombica@DESKTOP-C383C55

rombica@DESKTOP-C383C55 MINGW64 ~/.ssh
$ ssh-copy-id d_nurgaliev@185.5.249.140
/usr/bin/ssh-copy-id: INFO: Source of key(s) to be installed: "/c/Users/rombica/.ssh/id_rsa.pub"
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
d_nurgaliev@185.5.249.140's password:

Number of key(s) added: 1

Now try logging into the machine, with:   "ssh 'd_nurgaliev@185.5.249.140'"
and check to make sure that only the key(s) you wanted were added.

rombika@DESKTOP-098GB89:/mnt/c/Users/admin$ who
user     pts/1        2023-10-01 02:07

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ sudo whoami
rombica

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ export VAR=GIT

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW2 (master)
$ echo Я СДЕЛАЛ ВТОРУЮ ЛАБУ ПО $VAR
Я СДЕЛАЛ ВТОРУЮ ЛАБУ ПО GIT

```