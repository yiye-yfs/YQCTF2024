FROM python:3.8-slim-bullseye

# 制作者信息
LABEL auther_template="CTF-Archives"

RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.ustc.edu.cn/g' /etc/apt/sources.list &&\
    apt-get install tar bash 

# 安装必要的python依赖库，如flask
RUN python3 -m pip install -i https://pypi.mirrors.ustc.edu.cn/simple \
    flask

# 拷贝源码和启动脚本至根目录
COPY ./src/ /app
COPY ./service/docker-entrypoint.sh /

EXPOSE 80

# 指定容器入口点
ENTRYPOINT ["/bin/bash","/docker-entrypoint.sh"]