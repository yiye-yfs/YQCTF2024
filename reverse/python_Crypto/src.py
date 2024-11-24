def KSA(key):
	#初始化S盒
    S=[0]*256
    K=[0]*256
    j = 0
    for i in range(256):
    	S[i]=i
    	K[i]=key[i%len(key)]
    for i in range(256):
    	j=(j+S[i]+K[i])%256
    	S[i],S[j]=S[j],S[i]
    return S
 
def PRGA(S,size):
	#生成密钥流
    i, j = 0, 0
    l=[]
    for i in range(size):
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        K = S[(S[i] + S[j]) % 256]
        l.append(0xff&(K-3))
    return l
 
def RC4(key, text):
    S = KSA(key)
    res=[]
    size=len(text)
    keystream = PRGA(S,size)
    #按位异或
    for i in range(size):
    	res.append(text[i]^keystream[i])
    return bytes(res)
key=b'YQCTF^^^2024'

c = RC4(key,bytes(input("Input your flag:").encode()))
cip=b'\x17x\xdf9\x95g,\xb0\xa5-\xfc\x8di\xdc\r\x8c\x94\xcft3x\xe2`*\x12W|\xfc\xde\\\xb28\xcb~\x97\x07\xf9t\x1b\xd2'
if c==cip:
	print('Right!')
else:
	print('Wrong')