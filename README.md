# SF1500-NAP
A DPDK-based([dpdk-17.0.52](http://fast.dpdk.org/rel/dpdk-17.05.2.tar.xz)) IO interface, which named NAP,  for SF1500 platform
![](https://github.com/asterfusion/SF1500-OSAutoInstaller/blob/master/Docs/SF1500_front.jpg) 

This IO interface provides a function that forwarding packets from 8 GE ports to 2 XE ports or from 2 XE ports to 8 GE ports.The basis of port deciding is based on the L3 source IP address, the L3 destinition IP address, the source L4 port, the destinition L4 port and the protocol carried in each packets.The section which not privided by packet will treated as 0.

# What's the purpose of this interface ?
Help you to increase your development acceleration, reduce unnecessary barriers of your productions.

# How to run this example on SF1500 ?

1. Prepare runtime enviroment

  - Login to SF1500 download dpdk-17.05.2 from dpdk.org and abstract the archive to anywhere you want on SF1500.

  - Run following commands to support NAP compiling.

        root@OCTEONTX: export RTE_SDK=/home/dpdk-stable-17.05.2
        root@OCTEONTX: export RTE_TARGET=arm64-thunderx-linuxapp-gcc

  **Note** You can append this export things to /etc/bash.bashrc, and then source /etc/bash.bashrc.

  - Clone project from github

        root@OCTEONTX: git clone https://github.com/asterfusion/SF1500-NAP.git
  
2. Switch to top of this project and compiling

        root@OCTEONTX: cd SF1500-NAP
        root@OCTEONTX: source Compile.sh
        root@OCTEONTX: <wait for compile finished>
        root@OCTEONTX: make install
        root@OCTEONTX: tar -xvf napd-v2.5.0.$gitSHA.tar.gz
        root@OCTEONTX: cd napd
        root@OCTEONTX: ./install_nap.sh

3. Run nap

  Switch to /usr/local/etc/nap, and run StartNAPD.sh to lauch nap.
  
  
# Q&A
