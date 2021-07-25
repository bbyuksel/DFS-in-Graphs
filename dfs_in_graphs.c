#include <stdio.h>
#define N 7  //matrix dimension

//function prototypes
void displayMatris(int ,int ,int[N+1][N+1]);
void drawPath(char [][2*(N-1)+1],int[][N+1],int[][N+1]);
int checkWay(int ,int ,int [][N+1],int [][N+1]);
int findPath(int [][N+1], int [][N+1], int ,int );
  
void displayMatris(int row,int col,int labirent[row][col])
{
	int i,j;
	for (i=0;i<row;i++)
	{
		printf("%d\t",i);
		for (j=0;j<col;j++)
		{
			printf("%d",labirent[i][j]);
		}
		printf("\n");
	}
}


int checkWay(int x,int y,int labirent[][N+1],int solution[][N+1])         
{
    if( labirent[x][y]==1 && !solution[x][y])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void drawPath(char frame[][2*(N-1)+1], int labirent[][N+1], int solution[][N+1])
{
    int i,k,i1,k1;
    for(i=1;i<N;i++)
    {
        for(k=1;k<N;k++)
        {
        	if(solution[i][k] == 0) continue;
        	
			//look North
			if (solution[i-1][k] == 1)
			{
				i1 = (i-1)*2;
				k1 = k*2-1;
				frame[i1][k1] = ' ';
			}
			
			//look West 
			if (solution[i][k-1] == 1)
			{
				i1 = 2*i-1;
				k1 = 2*k-2;
				if(2*i-1 == 0)
				{
					
				}
				else
				{
					frame[i1][k1] = ' ';
				}
			}
			     	
			//look South	
			if (solution[i+1][k] == 1)
			{
				i1 = (i+1)*2;
				k1 = k*2-1;
				if(i1 == 2*N-2)
				{
					
				}
				else
				{
					frame[i1][k1] = ' ';
				}
			}
			
        	//look East  
			if (solution[i][k+1] == 1)
			{
				i1 = 2*i-1;
				k1 = 2*k+2;
				if(k1 == 2*N-2)
				{
					
				}
				else
				{
					frame[i1][k1] = ' ';
				}
			}	
			
			if (solution[i][k] == 1)
			{
				
				i1 = 2*i-1;
				k1 = 2*k-1;
				if ((i1==1 && k1 ==1) || (i1==2*N-3 && k1 == 2*N-3))
				{
					
				}
				else
				{
					frame[i1][k1] = 'I';	
				}
			}
			
        }
    }   
    
    
    for(i=0;i<2*(N-1)+1;i++)
    {
			printf("\n");
        for(k=0;k<2*(N-1)+1;k++)
        {
			printf("%c",frame[i][k]);
        }
    }
			printf("\n\n\n\n\n..................\n");
}

int findPath(int labirent[][N+1], int solution[][N+1], int x,int y)   
{
    if(x==N-1 && y==N-1)
   	{
    solution[x][y]=1;
    return 1;
   	}
    if(checkWay(x,y,labirent,solution)==1)
    { 
        solution[x][y]=1;
        if(findPath(labirent,solution,x,y+1)==1)       
        {
            return 1;
        }  
        else if(findPath(labirent,solution,x+1,y)==1)  
        {
            return 1;
        }                                   
        else if(findPath(labirent,solution,x,y-1)==1) 
        {
            return 1;
        }  
        else if(findPath(labirent,solution,x-1,y)==1) 
        {
            return 1;
        }  
        solution[x][y]=0;                
    }
    return 0;
}

int main(void)
{	
	
	int labirent[N+1][N+1] ={	
		  					{ 0, 0, 0, 0, 0, 0 ,0, 0}, 
							{ 0, 1, 0, 1, 1, 1 ,1 ,0},
							{ 0, 1, 1, 1, 0, 1 ,0 ,0}, 							
							{ 0, 0, 0, 1, 0, 1 ,0 ,0}, 
							{ 0, 0, 0, 1, 0, 1 ,0 ,0}, 
							{ 0, 0, 0, 1, 0, 1 ,0 ,0},
							{ 0, 0, 1, 1, 0, 1 ,1 ,0},					
							{ 0, 0, 0, 0, 0, 0 ,0 ,0}
						};
	char frame[2*(N-1)+1][2*(N-1)+1] ={	
		  					{ '+','-','+','-','+','-','+','-','+','-','+','-','+' },
		  					{ '|','*','|',' ','|',' ','|',' ','|',' ','|',' ','|' },
		  					{ '+','-','+','-','+','-','+','-','+','-','+','-','+' },
		  					{ '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|' },
		  					{ '+','-','+','-','+','-','+','-','+','-','+','-','+' },
		  					{ '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|' },
		  					{ '+','-','+','-','+','-','+','-','+','-','+','-','+' },
		  					{ '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|' },
		  					{ '+','-','+','-','+','-','+','-','+','-','+','-','+' },
		  					{ '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|' },
		  					{ '+','-','+','-','+','-','+','-','+','-','+','-','+' },
		  					{ '|',' ','|',' ','|',' ','|',' ','|',' ','|','X','|' },
		  					{ '+','-','+','-','+','-','+','-','+','-','+','-','+' }
						};
	
	printf("INPUT MATRIX\n\n");
    displayMatris(N+1,N+1,labirent);
    
	int solution[N+1][N+1] = {0};
	
	
    if(findPath(labirent,solution,1,1)==1)
    {
          printf("\n\nPATH FIND\n");
          drawPath(frame,labirent,solution);
    }
    
    else
    {
         printf("\n\nNO PATH!\n");    
    }
    
    
    int i,k;
    displayMatris(N+1,N+1,solution);    
    return 0;
}
