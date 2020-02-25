#!/bin/bash -ev

mkdir -p ~/.meconcash
echo "rpcuser=username" >>~/.meconcash/meconcash.conf
echo "rpcpassword=`head -c 32 /dev/urandom | base64`" >>~/.meconcash/meconcash.conf
echo "addnode=51.231.158.66" >>~/.meconcash/meconcash.conf
echo "addnode=52.231.158.58" >>~/.meconcash/meconcash.conf
echo "addnode=51.231.155.139" >>~/.meconcash/meconcash.conf
echo "addnode=51.231.158.111" >>~/.meconcash/meconcash.conf
echo "addnode=52.231.154.91" >>~/.meconcash/meconcash.conf
echo "banscore=3" >>~/.meconcash/meconcash.conf
echo "maxconnections=4" >>~/.meconcash/meconcash.conf
