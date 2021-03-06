#   BSD LICENSE
#
#   Copyright(c) 2015 Intel Corporation. All rights reserved.
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in
#       the documentation and/or other materials provided with the
#       distribution.
#     * Neither the name of Intel Corporation nor the names of its
#       contributors may be used to endorse or promote products derived
#       from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

ifeq ($(RTE_SDK),)
$(error "Please define RTE_SDK environment variable")
endif

# Default target, can be overwritten by command line or environment
RTE_TARGET ?= x86_64-native-linuxapp-gcc

include $(RTE_SDK)/mk/rte.vars.mk

ifneq ($(CONFIG_RTE_EXEC_ENV),"linuxapp")
$(error This application can only operate in a linuxapp environment, \
please change the definition of the RTE_TARGET environment variable)
endif

# library name
LIB = liboryx.a

LIBABIVER := 1

# all source are stored in SRC-Y
SRCS-y :=\
   counter.c debug.c format.c fio.c  utils.c rbtree.c ipc.c lq.c \
   memcache.c oryx.c error.c atomic.c ring.c shm_ring.c mpool.c parser.c task.c htable.c memory.c \
   mdx.c list.c tmr.c vec.c


#CFLAGS += $(WERROR_FLAGS)
CFLAGS := -W -Wall -Wstrict-prototypes -Wmissing-prototypes
CFLAGS += -Wmissing-declarations -Wpointer-arith
CFLAGS += -Wcast-align -Wnested-externs
CFLAGS += -Wformat-nonliteral -Wformat-security
CFLAGS += -Wundef -Wwrite-strings
#CFLAGS += -Wold-style-definition -Wcast-qual

CFLAGS += -g -O3 --std=gnu99 
CFLAGS += -D_GNU_SOURCE -D__USE_GNU -D__STDC_FORMAT_MACROS\
		  -DHAVE_PCAP -DHAVE_ADVANCED_TMR


include $(RTE_SDK)/mk/rte.extlib.mk
