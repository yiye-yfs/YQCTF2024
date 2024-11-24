#!/bin/sh

# Get the user
user=$(ls /home)

# Check the environment variables for the flag and assign to INSERT_FLAG

INSERT_FLAG="YQCTF{Kn0w1ng_th3_TYPE_LeNGth_is_n3cessary!}"


# 将FLAG写入文件 请根据需要修改
echo $INSERT_FLAG | tee /home/$user/flag

# 赋予程序运行权限
chmod 711 /home/ctf/attachment

/etc/init.d/xinetd start;
sleep infinity;
