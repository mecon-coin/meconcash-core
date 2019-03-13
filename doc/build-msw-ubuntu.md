# Windows Build from Linux ubuntu

## Install the dependencies

```bash
sudo apt install p7zip-full autoconf automake autopoint bash bison bzip2 cmake flex gettext git g++ gperf intltool libffi-dev libtool libltdl-dev libssl-dev libxml-parser-perl make openssl patch perl pkg-config python ruby scons sed unzip wget xz-utils g++-multilib libc6-dev-i386
```

## Install MXE

```bash
sudo su -
cd /opt
git clone https://github.com/mxe/mxe.git
```

## Compile meconcash dependencies

### Compile boost

```bash
cd /opt/mxe
make MXE_TARGETS="i686-w64-mingw32.static" boost
```

### Compile QT5

```bash
make MXE_TARGETS="i686-w64-mingw32.static" qttools
```

### Compile miniupnpc

```bash
wget -O miniupnpc-1.9.tar.gz http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.9.tar.gz
tar -xf db-4.8.30.tar.gz -C /opt/mxe
pushd /opt/mxe/db-4.8.30
compile-miniupnpc.sh # execute from meconcash-core/scripts/compile-miniupnpc.sh
```

### Compile libdb

```bash
cd /opt/mxe
wget http://download.oracle.com/berkeley-db/db-4.8.30.tar.gz
tar -xf db-4.8.30.tar.gz -C /opt/mxe
pushd /opt/mxe/db-4.8.30
compile-libdb.sh # execute from meconcash-core/scripts/compile-libdb.sh
```

## Compile Meconcash

```bash
export PATH=/opt/mxe/usr/bin:$PATH
compile-meconcash.sh # execute from meconcash-core/scripts/compile-meconcash.sh
```
