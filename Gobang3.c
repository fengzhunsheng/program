#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define temp0 if (tempp == 0){p[i][j] = 0;continue;}

void gameStart(void);
void player(void);
void AI(void);
int AI2(void);
int AI3(void);
void DrawBoard(void);
void pos(int x,int y);
int ok(int row,int col); 
void go(int row,int col,int num);
int point(int row,int col,int num);

int p[16][16]={0};
int is_end=0;
int s,s0,ais=2;
int x[4]={1,0,1,1};
int y[4]={0,1,1,-1};

int main(){
	gameStart();
	while(!is_end)
	{
		if(s==ais) player();
		else AI();
		s=3-s;
	}
	return 0;
}
void gameStart(void){
	printf("please input 1 or 2 to choose who first play!!!\n 1. AI paly firstly with black chess\n 2. Player play firstiy with black chess\n");
	scanf("%d",&s);
	s0=s;
	if(s!=1 && s!=2)
	{
		return gameStart();
	}
	DrawBoard();
}
void pos(int x,int y){
	COORD position;
	HANDLE hOutput;
	position.X=2*y; //double col 
	position.Y=x;
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,position);
}
void DrawBoard(void){
	system("cls");
	system("mode con cols=60 lines=30") ;
	int i,j,k;
	j=1;
	for(i=5;i<20;i++)
	{
		pos(2,i);
		printf("%d",j);
		j++;
	}
	k=1;
	for(i=3;i<18;i++)
	{
		pos(i,4);
		printf("%d",k);
		k++;
	}
	
	pos(3,5);
	printf("┏ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┓");
	for(i=4;i<17;i++)
	{
		pos(i,5);
        printf("┠ ┼ ┼ ┼ ┼ ┼ ┼ ┼ ┼ ┼ ┼ ┼ ┼ ┼ ┨");
	}
    pos(17,5);
    printf("┗ ┷ ┷ ┷ ┷ ┷ ┷ ┷ ┷ ┷ ┷ ┷ ┷ ┷ ┛");
    
    system("color 09");
}
void player(void){
	pos(18,5);
	printf("                                ");
	pos(18,5);
	printf("轮到玩家下，请输入坐标:  ");
	int col,row;
	scanf("%d %d",&row,&col);
	pos(19,5);
	printf("                                ");
	if (!ok(row, col))
	{
		pos(19,5);
		printf("此处不能下");
		return player();
	}
    go(row,col,2);
}
void AI(void){	
	pos(19,5);
    printf("轮到AI下: ");
	if(p[8][8]==0) return go(8,8,1);
	int i,j;
	int keyp = -100000, keyi, keyj, tempp;
	for(i=1;i<=15;i++)
	{
		for(j=1;j<=15;j++)
		{
			if(!ok(i,j)) continue; 
			p[i][j]=1;
			tempp=point(i,j,1); 
			temp0
			if(tempp==10000) 
			{
				p[i][j]=0;
				return go(i,j,1);
			}
			tempp=AI2();
			p[i][j]=0;
			if (tempp > keyp)
			{
			    keyp = tempp;
				keyi = i;
				keyj = j;
			}                 //第一层取极大
		}
	}
	pos(20,5);
	printf("最终AI评分为：%d",keyp);
	return go(keyi, keyj,1);	
}
int AI2(void){
	int i,j;
	int keyp = 100000, tempp;
	for(i=1;i<=15;i++)
	{
		for(j=1;j<=15;j++)
		{
			if(!ok(i,j)) continue; 
			p[i][j]=2;
			tempp=point(i,j,2); 
			temp0
			if(tempp==10000)
			{
				p[i][j]=0;
				return -10000;
			} 
			tempp=AI3();
			p[i][j]=0;
			if (tempp < keyp)
			{
			    keyp = tempp;
			}                 //第二层取极小 
		}
	} 
	return keyp;
}
int AI3(void){
	int i, j;
	int keyp = -100000, tempp;
	for (i = 1; i <= 15; i++)
	{
		for (j = 1; j <= 15; j++)
	    {
		    if (!ok(i,j))continue;
		    tempp = point(i,j,1);
		    temp0
	    	if (tempp == 10000)
		    {
			    return 10000;
		    }
		   	if (tempp == -10000)
		    {
			    return -10000;
		    }
		    if (tempp> keyp)
		    {
		        keyp = tempp;//第三层取极大
	        }
	    }
	}
	return keyp;
}
int ok(int row,int col){//能否落子 
	if(row>=1 && row<=15 && col>=1 && col<=15 && p[row][col]==0) return 1;
	else return 0;
}
void go(int row,int col,int num){//落下一子 
	pos(row+2,col+4);
	if(num==1)
	{
		p[row][col]=1;
	    if(s0==1) printf("●");
	    else printf("○");
	    pos(19,5);
        printf("轮到AI下: %d %d ",row,col);
	}
	else
	{
		p[row][col]=2;
	    if(s0==2) printf("●");
	    else printf("○");	
	}
	if(end(row,col,num))
    {
    	is_end=1; 
    	pos(20,5);
    	if(num==2) printf("玩家胜！");
		else printf("AI胜！"); 
	}
}
int point(int row,int col,int num){//评分 
	if(end(row,col,num))
	{
		return 10000;
	}
	int i,ret=0,score[4]={0};
	for(i=0;i<4;i++)
	{
		if(p[row+x[i]][col+y[i]]==num)//level=1
		{
			if(p[row+2*x[i]][col+2*y[i]]==num)//level=2
			{
				if(p[row+3*x[i]][col+3*y[i]]==num)//level=3
				{
					if(p[row+4*x[i]][col+4*y[i]]==0)
					{
						if(p[row-1*x[i]][col-1*y[i]]==0)
						{
							score[i]=1000;
						}
						else if(p[row-1*x[i]][col-1*y[i]]==3-num)
						{
							score[i]=100;
						}
					}
					else if(p[row+4*x[i]][col+4*y[i]]==3-num)
					{
						score[i]=100;
					}
				}
				else if(p[row+3*x[i]][col+3*y[i]]==0)//level=3
				{
					if(p[row-1*x[i]][col-1*y[i]]==0)
					{
						score[i]=100;
					}
					else if(p[row-1*x[i]][col-1*y[i]]==num)
					{
						score[i]=1000;
					}
					else
					{
						score[i]=10;
					}
				}
				else//level=3
				{
					if(p[row-1*x[i]][col-1*y[i]]==0)
					{
						score[i]=10;
					}
					else if(p[row-1*x[i]][col-1*y[i]]==num)
					{
						if(p[row-2*x[i]][col-2*y[i]]==0)
						{
							score[i]=100;
						}
					}
				}
			}
			else if(p[row+2*x[i]][col+2*y[i]]==0)//level=2
			{
				if(p[row-1*x[i]][col-1*y[i]]==num)
				{
					if(p[row-2*x[i]][col-2*y[i]]==num)
					{
						score[i]=1000;
					}
					else if(p[row-2*x[i]][col-2*y[i]]==0)
					{
						score[i]=100;
					}
					else
					{
						score[i]=10;
					}
				}
				else if(p[row-1*x[i]][col-1*y[i]]==0)
				{
					score[i]=10;
				}
			}
			else//level=2
			{
				if(p[row-1*x[i]][col-1*y[i]]==num)
				{
					if(p[row-2*x[i]][col-2*y[i]]==num)
					{
						score[i]=100;
					}
					else if(p[row-2*x[i]][col-2*y[i]]==0)
					{
						score[i]=10;
					}
				}
			}
		}
		else if(p[row+x[i]][col+y[i]]==3-num)//level=1
		{
			if(p[row+2*x[i]][col+2*y[i]]==3-num)//level=2
			{
				if(p[row+3*x[i]][col+3*y[i]]==3-num)
				{
					if(p[row+4*x[i]][col+4*y[i]]==3-num)
					{
						if(p[row+5*x[i]][col+5*y[i]]==0)
						{
							return -10000;
						}						
						if(p[row+5*x[i]][col+5*y[i]]==num)
						{
							score[i]=1000;
						}
					}
					if(p[row+4*x[i]][col+4*y[i]]==num)
					{
						score[i]=100;
					}
					else if(p[row+4*x[i]][col+4*y[i]]==0)
					{
						score[i]=1000;
					}
			    }
			    else if(p[row+3*x[i]][col+3*y[i]]==0)
			    {
			    	score[i]=10;
				}
			}
			if(p[row-1*x[i]][col-1*y[i]]==num)//反相level=1
			{
				if(p[row-2*x[i]][col-2*y[i]]==num)
				{
					if(p[row-3*x[i]][col-3*y[i]]==num)
					{
						score[i]=score[i]+100;
					}
					else if(p[row-3*x[i]][col-3*y[i]]==0)
					{
						score[i]=score[i]+10;
					}
				}
			}
			else if(p[row-1*x[i]][col-1*y[i]]==3-num)
			{
				if(p[row-2*x[i]][col-2*y[i]]==3-num)
				{
					if(p[row-3*x[i]][col-3*y[i]]==3-num)
					{
						score[i]=score[i]+1000;
					}
					else if(p[row-3*x[i]][col-3*y[i]]==0)
					{
						score[i]=score[i]+100;
					}
					else
					{
						score[i]=score[i]+10;
					}
				}
			}
		}
		else //level=1
		{
			if(p[row-1*x[i]][col-1*y[i]]==num)
			{
				if(p[row-2*x[i]][col-2*y[i]]==num)
				{
					if(p[row-3*x[i]][col-3*y[i]]==num)
					{
						if(p[row-4*x[i]][col-4*y[i]]==3-num)
						{
							score[i]=100;
						}
						if(p[row-4*x[i]][col-4*y[i]]==0)
						{
							score[i]=1000;
						}						
					}
					else if(p[row-3*x[i]][col-3*y[i]]==0)
					{
						score[i]=100;
					}
					else
					{
						score[i]=10;
					}
				}
				else if(p[row-2*x[i]][col-2*y[i]]==0)
				{
					score[i]=10;
				}
			}
		}
	}
	for(i=0;i<4;i++)
	{
		ret=ret+score[i];
	}
	return ret;
}
int end(int row,int col,int num){//(row,col)处落子之后是否游戏结束	
	int out=0;
	int i,j;
	for(i=0;i<4;i++)
	{
		int sum=1;
		for(j=1;j<5;j++)
		{
			if(p[row+j*x[i]][col+j*y[i]]==num)	sum++;			
			else break;
		}
		for(j=-1;j>-5;j--)
		{
			if(p[row+j*x[i]][col+j*y[i]]==num)  sum++;
			else break;
		}
		if(sum>=5)
		{
			out=1;
			break;
		}
	}
	return out;
}
