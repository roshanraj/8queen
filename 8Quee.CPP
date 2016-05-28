#include <iostream.h>
#include <conio.h>


	 int board[8][8];

	int neb(int x,int y)
	{
		for (int i=0;i<8;i++)
			if( (board[x][i]==1) || (board[i][y]==1) )
			{
				return 0;
			}
		return 1;

	}

	int maj(int x,int y)
	{
		if (x>y)
		{
			x=x-y;
			y=0;
			   //cout<<x<<"    "<<y<<endl;

			while (x!=8)
			{
				if(board[x][y]==1)
				return 0;
				x++;
				y++;
			}

		}///// if statement  ends
		else
		{
			y=y-x;
			x=0;
			   //cout<<x<<"    "<<y<<endl;

			while (y!=8)
			{
				if(board[x][y]==1)
					return 0;
				x++;
				y++;

			}
		}

		return 1;


	}






	int min(int x,int y)
	{
		if ((x+y)<8)
		{
			y = x+y;
			x = 0;
         //cout<<x<<"    "<<y<<endl;
			while (y!=0)
			{
				if(board[x][y]==1)
					return 0;
				x++;
				y--;
			}
		}
		else
		{

			x = (x+y)-7;
			y = 7;
        //	cout<<x<<"  "<<y<<endl;
			while (x!=8)
			{
				if(board[x][y]==1)
					return 0;
				x++;
				y--;
			}
		}
		return 1;

	}


	void display()
	{
		for (int i=0;i<8;i++)
		{
			for (int j=0;j<8;j++)
				cout<<board[i][j]<<" ";
         cout<<endl;
		}
	}


	int test()
	{
		for (int i=0;i<8;i++)
		{
			for(int j=0; j<8;j++)
			{
				if( (min(i,j)+maj(i,j)+neb(i,j)) == 3 )
					return 1;
			}
		}
		return 0;
	}/////// function closed






	void main()
	{
		int q = 8;

		while(q>0)
		{
       cout<<"Enter the row of the queen's movement"<<endl;


			int x=0;
         cin>>x;

			cout<<"Possible moves ";
			for (int i=0; i<8;i++)
			{
				if( (min(x,i)+maj(x,i)+neb(x,i)) == 3 )
					cout<<i<<", ";
			}

			cout<<endl;

			cout<<"Enter the colunm of the queen's movement"<<endl;
			int y = 0;
         cin>>y;
			int po=1;
			if( (min(x,y)+maj(x,y)+neb(x,y)) == 3)
			{
				board[x][y]=1;
				display();
			}else
			{
				cout<<"Possible moves ";
				for (int i=0; i<8;i++)
				{
					if( (min(x,i)+maj(x,i)+neb(x,i)) == 3 )
						cout<<i+", ";
				}
				cout<<endl;
			}

			if(test()==0)
			{
         	cout<<"lost the game"<<endl;
				break;
			}

		}


             getch();

	}






