#!/bin/bash

# Get the user
user=$(ls /home)
INSERT_FLAG="YQCTF{E@sy_S3rver-S1de_T3mplat3_Inject10n}"
# 将FLAG写入文件 请根据需要修改
echo $INSERT_FLAG | tee /flag

# 控制flag和项目源码的权限
chmod 744 /flag
chmod 740 /app/*
cd /app && python app.py