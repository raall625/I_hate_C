#include <stdio.h>

int print_title_screen()
{
	printf("#####################################\n");
	printf("##                                 ##\n");
	printf("##                                 ##\n");
	printf("##            run                  ##\n");
	printf("##         -vol 01-                ##\n");
	printf("##       1. Game start             ##\n");
	printf("##       2. How to play            ##\n");
	printf("##       3. Exit                   ##\n");
	printf("##                                 ##\n");
	printf("##                                 ##\n");
	printf("##                                 ##\n");
	printf("#####################################\n");
	return 0;
}
int print_howtoplay_screen()
{
	printf("#####################################\n");
	printf("##                                 ##\n");
	printf("##                                 ##\n");
	printf("##   이 게임은 여러분이 끝없이     ##\n");
	printf("##   달리기만 하는 게임입니다,     ##\n");
	printf("##   여러분이 달리지 못하도록      ##\n");
	printf("##   방해하는 것들을 피하면서      ##\n");
	printf("##   계속 달리세요                 ##\n");
	printf("##                                 ##\n");
	printf("##                                 ##\n");
	printf("##                                 ##\n");
	printf("##                                 ##\n");
	printf("#####################################\n");
	return 0;
}
int main()
{      
	print_title_screen();
	int game_state = 1;
        int input = 0;
	int how = 0;
	int user = 0;
	while(game_state)
	{
		printf("input(1~3)>");
                scanf("%d",&input);
	}
		if(input==2)
	{       
		while(how)
		{
		        print_howtoplay_screen();
			printf("Return to menu? (1.yes 2.no");
			scanf("%d",&user);
			if(user==1)
			{
				how = 1;
				input = 0;
			}
		}	
        }
		if(input==3)
		{
		          game_state=0; 
	        }

		
	return 0; 
}
