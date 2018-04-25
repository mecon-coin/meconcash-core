#!/bin/bash -ev

sudo apt-get install -y -qq htop
sudo timedatectl set-ntp no
sudo apt-get -y -qq install ntp
sudo ntpq -p

#dependencies
sudo apt-get update -qq
sudo apt-get upgrade -y -qq
sudo apt-get install -y -qq autoconf build-essential pkg-config libssl-dev libboost-all-dev
sudo apt-get install -y -qq miniupnpc libminiupnpc-dev gettext

#for gui
sudo apt-get install -y -qq qtbase5-dev qttools5-dev-tools
sudo apt-get install -y -qq libdb++-dev

#install
gcc --version
g++ --version

./contrib/install_db4.sh `pwd`
#flags arent being picked up, so need to link
sudo ln -sf `pwd`/db4/include /usr/local/include/bdb4.8
sudo ln -sf `pwd`/db4/lib/*.a /usr/local/lib
./autogen.sh
./configure
make -j$(nproc)
make check
