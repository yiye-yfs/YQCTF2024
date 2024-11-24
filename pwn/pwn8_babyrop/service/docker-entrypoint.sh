#!/bin/sh

# Get the user
user=$(ls /home)

INSERT_FLAG="YQCTF{WOW_Ret6rn_2_l1bc_ff555fc}"

# 将FLAG写入文件 请根据需要修改
echo $INSERT_FLAG | tee /home/$user/flag

# 赋予程序运行权限
chmod 711 /home/ctf/attachment

/etc/init.d/xinetd start;
sleep infinity;
