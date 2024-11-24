#include<stdio.h>
#include<stdint.h>
#include<string.h>

uint32_t s2n(const char *s) {
    // 将字符串转为32位整数
    uint32_t result = 0;
    for (int i = 0; i < 4; i++) {
        result |= (unsigned char)s[i] << (8 * (3 - i));
    }
    return result;
}

void encipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4],uint32_t result[2]){
	unsigned int i;
	uint32_t v0=v[0],v1=v[1],sum=0,delta=0x12345678;
	for(i=0;i<num_rounds;i++){
		v0+=(((v1<<4)^(v1>>5))+v1)^(sum+key[sum&3]);
		sum+=delta;
		v1+=(((v0<<4)^(v0>>5))+v0)^(sum+key[(sum>>11)&3]);
	}
	result[0]=v0;result[1]=v1;
}

int main(){
	//const char *flag = "YQCTF{Nuts_And_TEA_@re_@_w0nd3rful_Comb1nat10n!}";
	uint32_t const k[4]={5,6,7,8};
	unsigned int r=48;
	int32_t res[6][2]={0};
	int32_t cip[6][2] = {
	{-2122337917,1858501092},
	{-1861537113,-2026907601},
	{-1280949182,-1666022502},
	{-686858183,323529055},
	{-1059489236,-2085865544},
	{-1547718812,-2144744674}
    };
	char flag[100]={0};
	puts("Input your flag:");
	scanf("%s",&flag);
	if(strlen(flag)!=r){
		puts("Wrong Length!");
		return 0;
	}
	for(int i=0;i<6;++i){
		uint32_t a[2];
		a[0] = s2n(&flag[i * 8]);
        a[1] = s2n(&flag[i * 8 + 4]);
		encipher(r,a,k,res[i]);
		//printf("{%d,%d},\n",res[i][0],res[i][1]);
	}
    for (int i = 0; i < 6; i++) 
        if(res[i][0] != cip[i][0] || res[i][1]!=cip[i][1]) {
        	puts("Wrong!");
        	return 0;
        }
    puts("Right.Flag is your input!");
	return 0;
}