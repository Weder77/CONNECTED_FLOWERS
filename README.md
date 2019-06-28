# DEV Project - GROUPE N°07

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info

![](photos/home.jpg)

It is a school project designed over a year. The subject being imposed on us, here is what we did. The members of the group are : <br>
&nbsp;&nbsp; - GRELET Théo alias @Sheraw91 (https://github.com/Sheraw91) <br />
&nbsp;&nbsp; - JEAN-CHARLES Dany<br />
&nbsp;&nbsp; - LECLERC Loris (Leave on April 2nd)<br />
&nbsp;&nbsp; - RAMOS LAGE Clément (Arrived on June 4th) alias @MENT3 (https://github.com/MENT3)<br />
&nbsp;&nbsp; - DE WEERD Damien (Arrived on June 14th) <br />


Returns made: <br />
&nbsp; &nbsp; - Rendering 1 - January 25 : Algo, initial analysis <br />
&nbsp; &nbsp; - Rendering 2 - February 28 : graphical interface, circulation in pages <br />
&nbsp; &nbsp; - Rendering 3 - April 2 : Modeling <br />
&nbsp; &nbsp; - Rendering 4 - May 3 : database + query <br />
&nbsp; &nbsp; - Rendering 5 - June 4 : Finalizing applications <br />
&nbsp; &nbsp; - FINAL - June 24 : IoT



## Technologies
Project is created with:
* C
* Mysql Api
* Arduino
* Raspberry 3 B+

	
## Setup
To run this project, you need to install mysql with brew.

Brew installation ( ignore this step if you have already brew ) :

```
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" 
```

Mysql installation :

```
$ brew install mysql
$ mysql.server start
$ cd merise
$ mysql -uroot
$ CREATE DATABASE ConnectF;
$ exit
$ mysql -uroot ConnectF < uf_dev.SQL
$ mysql -uroot
$ use ConnectF;
$ exit
```

Next, launch algo_plante.c 

```
$ git clone https://github.com/Weder77/UF_DEV.git
$ cd UF_DEV
$ cd algorithmique
$ export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/opt/openssl/lib/
$ gcc -o ter `mysql_config --cflags` algo_plante.c `mysql_config --libs` 
$ ./ter
```

