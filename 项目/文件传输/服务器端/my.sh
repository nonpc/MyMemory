#########################################################################
# File Name: my.sh
# Author: DW*Joker
# mail: daemon.love@foxmail.com
# Created Time: Sat 18 May 2019 08:44:56 PM CST
#########################################################################
#!/bin/bash


#awk -F'[" "]' '{print $1}'

#echo "$1"
#a=`md5sum shizhong.mp4`
a=`md5sum $1`
echo "$a" >>md5.c




#$a | awk '{print $1}'
#b=$1
#echo "$b"
