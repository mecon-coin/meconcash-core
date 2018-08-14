#!/bin/bash -ev

mkdir -p ~/.meconcash
echo "rpcuser=username" >>~/.meconcash/meconcash.conf
echo "rpcpassword=`head -c 32 /dev/urandom | base64`" >>~/.meconcash/meconcash.conf

