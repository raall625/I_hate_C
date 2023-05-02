 #include <stdio.h>

 int main(){
 int num,hp;
 hp = 30;
 printf("주인공의 공격력을 입력하세요\n ");
 scanf("%d", &num);
 printf("주인공은 공격력이 %d입니다\n", num);
 printf("주인공이 적을 공격하여 %d의 데미지를 입혔습니다\n", num);
 hp = hp - num;
 printf("적의 잔여 HP : %d\n", hp);

 if(hp>0)
 {
	 printf("적이 주인공을 공격하여 주인공이 뒤졌습니다.\n");
 }
 else
 {
	 printf("적을 물리쳤습니다!\n");
 }
 return 0;
}

