clear
cd /
docker images
docker ps -a
docker rm -f $(docker ps -aq)
docker images | awk '!/php|ubuntu/ && !/REPOSITORY/ {print $3}' | xargs -r docker rmi

cd /YQCTF/pwn/
docker build ./pwn1_justnc -t pwn1_justnc
docker run -d -p 20001:9999 pwn1_justnc 

docker build ./pwn2_reallymathcalc -t pwn2_reallymathcalc
docker run -d -p 20002:9999 pwn2_reallymathcalc

docker build ./pwn3_houses -t pwn3_houses
docker run -d -p 20003:9999 pwn3_houses

docker build ./pwn4_execit -t pwn4_execit
docker run -d -p 20004:9999 pwn4_execit

docker build ./pwn5_isbn -t pwn5_isbn
docker run -d -p 20005:9999 pwn5_isbn

docker build ./pwn6_loader -t pwn6_loader
docker run -d -p 20006:9999 pwn6_loader

docker build ./pwn7_ezstack -t pwn7_ezstack
docker run -d -p 20007:9999 pwn7_ezstack

docker build ./pwn8_babyrop -t pwn8_babyrop
docker run -d -p 20008:9999 pwn8_babyrop


cd /YQCTF/web/
docker build ./web1_shell -t web1_shell
docker run -d -p 10001:80 web1_shell 

docker build ./web2_filemini -t web2_filemini
docker run -d -p 10002:80 web2_filemini 

docker build ./web3_filepro -t web3_filepro
docker run -d -p 10003:80 web3_filepro 

docker build ./web4_sequence -t web4_sequence
docker run -d -p 10004:80 web4_sequence 

docker build ./web5_leak -t web5_leak
docker run -d -p 10005:80 web5_leak 

docker build ./web6_fileplus -t web6_fileplus
docker run -d -p 10006:80 web6_fileplus

docker build ./web7_injection -t web7_injection
cd ./web7_injection/docker/
docker-compose up -d

cd /YQCTF/web/
docker build ./web8_ezflask -t web8_ezflask
cd ./web8_ezflask/docker/
docker-compose up -d


cd /
clear
docker images
docker ps -a

#docker exec -it xxxx /bin/bash
#cd /YQCTF && chmod 777 ./* && ./run.sh
