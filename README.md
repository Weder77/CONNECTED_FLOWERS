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
&nbsp; &nbsp; - Proceeding from 1st to 25th of January: Algo, initial analysis <br />
&nbsp; &nbsp; - Rendering 2 - February 28: graphical interface, circulation in pages <br />
&nbsp; &nbsp; - Rendering 3 - 2 April: Modeling <br />
&nbsp; &nbsp; - Rendering 4 - 3 May: database + query <br />


## Technologies
Project is created with:
* C
* Sublim Text 3

	
## Setup
To run this project, you need to install mysql with brew.

```
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" // Ignore if you have already brew
$ brew install mysql
$ mysql.server start
$mysql -uroot
```

Next, launch algo_plante.c 

```
$ cd algorithmique
$ export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/opt/openssl/lib/
$ gcc -o ter `mysql_config --cflags` algo_plante.c `mysql_config --libs` 
$ ./ter
```
