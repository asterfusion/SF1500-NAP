# SF1500-NAP
A DPDK-based([dpdk-17.0.52](http://fast.dpdk.org/rel/dpdk-17.05.2.tar.xz)) IO interface, which named NAP,  for SF1500 platform
![](https://github.com/asterfusion/SF1500-OSAutoInstaller/blob/master/Docs/SF1500_front.jpg) 

This IO interface provides a function that forwarding packets from 8 GE ports to 2 XE ports or from 2 XE ports to 8 GE ports.The basis of port deciding is based on the L3 source IP address, the L3 destinition IP address, the source L4 port, the destinition L4 port and the protocol carried in each packets.The section which not privided by packet will treated as 0.

The forwarding model diagram is showed below:
![](https://github.com/asterfusion/SF1500-NAP/blob/master/docs/SF1500-nap-forwarding-topology.jpg)

On NAP side, it will abstract the metadata (SIP,DIP,SP,DP,PROTO) from comeing pacekts and caculate a 32-bit RSS value with them. The 32-bit RSS value will decide a port for packet output.

Let's see a simple example here.

A packet which carrying metadata with (SP=192.168.0.1,DP=192.168.0.2,SP=1234,DP=4321,PROTO=6) comes from one of XE port. The NAP gets a 32-bit RSS value 231405843 throu a hash function. Then, the NAP trys to decide one of 8 GE ports as output (note that) with this RSS value. At last, the packet will be deliveried to that port only when it's up, otherwise, it will be dropped.
   
  - packet arrived
  - abstract metadata
  - caculate 32-bit RSS value by metadata
  - decide output port by RSS value
  - delivery out


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

3. Run NAP

  Switch to /usr/local/etc/nap, and run StartNAPD.sh to lauch nap.

4. About the design principle of the NAP

  There are 4 lcores in SOC of SF1500 and the NAP uses 3 of them as full-time packets IO. Each lcore connected to each port (CPU) through queues and this feature can be showed from the startup NAP application.

	root@OCTEONTX: ps -ef | grep nap

  You can see output like this "napd -c 0xf -n 2 -- -p 0x7 --config=(0,0,1),(0,1,2),(0,2,3),(1,0,1),(1,1,2),(1,2,3),(2,0,1),(2,1,2),(2,2,3)". The --config shows us a set of three-axis matrixs (lcoreid,portid,rxqueueid).

  
# Q&A


