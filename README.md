# DEV Project - GROUPE N°07

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
it is a school project designed over a year. The subject being imposed on us, here is what we did. The members of the group are : <br>
&nbsp;&nbsp; - GRELET Théo <br />
&nbsp;&nbsp; - JEAN-CHARLES Dany<br />
&nbsp;&nbsp; - LECLERC Loris (Leave on April 2nd)<br />
&nbsp;&nbsp; - RAMOS LAGE Clément (Arrived on June 4th) <br />

Returns made: <br />
&nbsp; &nbsp; - Rendering 1 - January 25 : Algo, initial analysis <br />
&nbsp; &nbsp; - Rendering 2 - February 28 : graphical interface, circulation in pages <br />
&nbsp; &nbsp; - Rendering 3 - April 2 : Modeling <br />
&nbsp; &nbsp; - Rendering 4 - May 3 : database + query <br />


## Technologies
Project is created with:
* C
* Mysql Api
* Library in C : 
	* <stdio.h>
	* <stdlib.h>
	* <string.h>
	* <unistd.h>
	* <mysql.h>

	
## Setup
To run this project, you need to install mysql with brew.

Brew installation :

```
$ // Ignore this step if you have already brew
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" 
```

Mysql installation :

```
$ brew install mysql
$ mysql.server start
$ cd merise
$ mysql -uroot
$ CREATE DATABASE ConnectF;
$ use ConnectF;
$ exit
$ mysql source ConnectF < uf_dev.SQL
```

Next, launch algo_plante.c 

```
$git clone https://github.com/Weder77/UF_DEV.git
$ cd algorithmique
$ export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/opt/openssl/lib/
$ gcc -o ter `mysql_config --cflags` algo_plante.c `mysql_config --libs` 
$ ./ter
```
