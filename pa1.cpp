// Daniel Tymecki
// UFID: 9689-1628
// Programming Assignment 1 - Magic Square Generator
// 2/2/2017 
// Finished 2/4/2017


#include<iostream>

using namespace std;

//Defines a magic square object.
class Magic_Square
{
	//Declares the public data fields.
	public:
		int N;
		int square[15][15];
		int sum;
	
	//Constructor taking in the size of the square.
	Magic_Square(int N)
	{
		this->N = N;
		sum = N*(((N^2)+1)/2);
	}
	
	//Prints the magic square.
	void printSquare()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << "|" << square[i][j] << "\t";
			}
			cout << "|\n";
		}
	}
	
	//Initializes the magic square with all 0s.
	void initialize()
	{	
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				square[i][j] = 0;
			}
		}
	}
	
	//Checks to see if the desired move is within the defined bounds of the matrix.
	//If move is not valid, returns true. Else, returns false.
	bool boundsFlag(int i, int j, int lim)
	{
		if (i < 0 || i >= lim || j < 0 || j >= lim)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	//Checks whether or not the move is valid based off if the space is already filled.
	//Magic sqaure must be initialized to work. Empty = 0 in this context.
	//If move is not valid, returns true. Else, returns false.
	bool fillFlag(int i, int j)
	{
		if (square[i][j] != 0)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	//Returns the sum of a single row.
	int sumRows(int i)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			sum += square[i][j];
		}
		return sum;
	}
	
	//Returns the sum of a single column.
	int sumCols(int j)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += square[i][j];
		}
		return sum;
	}
	
	//Returns the sum of the right diagnal.
	int sumRD()
	{
		int sum = 0;
		int j = 0;
		for (int i = 0; i < N; i++)
		{
			sum += square[i][j];
			j++;
		}
		return sum;
	}
	
	//Returns the sum of the left diagnal.
	int sumLD()
	{
		int sum = 0;
		int j = N-1;
		for (int i = 0; i < N; i++)
		{
			sum += square[i][j];
			j--;
		}
		return sum;
	}
	
	//Prints the results of checking to see if the square is magic based off the four methods defined above.
	void result()
	{
		cout << "Checking the sums of every row: \t";
		for (int i = 0; i < N; i++)
		{
			cout << sumRows(i) << " ";
		}
		cout << endl;
		
		cout << "Checking the sums of every col: \t";
		for (int j = 0; j < N; j++)
		{
			cout << sumCols(j) << " ";
		}
		cout << endl;
		
		cout << "Checking the sums of the diags: \t";
		cout << sumRD() << " " << sumLD() << " \n";
	}
	
	//Rotates the magic square clockwise 90 degrees to generate a new magic square.
	void rotate()
	{
		int turn[N][N];
		int d = 0;
		int t = 0;
		for (int j = 0; j < N; j++)
		{
			for (int i = N-1; i >= 0; i--)
			{
				turn[d][t] = square[i][j];
				t++;
			}
			d++;
			t = 0;
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				square[i][j] = turn[i][j];
			}
		}
	}
	
	//Generates a magic square based off the desired n defined in the constructor (only valid if odd n from 3-15).
	void generate()
	{
		int fill = 1;
		int i = 0;
		if (N == 3)
		{
			int j = 1;
			int lim = 3;
			do 
			{
				square[i][j] = fill;
				int d = i;
				int t = j;
				fill++;
				i--;
				j++;
				if (boundsFlag(i,j,lim))
				{
					if (i < 0 && j > 0 && j < lim)
					{
						i = lim - 1;
					}
					else if (i < 0 && j >= lim)
					{
						i = d+1;
						j = t;
					}
					else if (i >= 0 && j >= lim)
					{
						j = 0;
						while (fillFlag(i, j))
						{
							j++;
						}
					}
				}
				else if (fillFlag(i, j))
				{
					i = d+1;
					j = t; 
				}
			} while (fill < 10);	
		}
		if (N == 5)
		{
			int j = 2;
			int lim = 5;
			do 
			{
				square[i][j] = fill;
				int d = i;
				int t = j;
				fill++;
				i--;
				j++;
				if (boundsFlag(i,j,lim))
				{
					if (i < 0 && j > 0 && j < lim)
					{
						i = lim - 1;
					}
					else if (i < 0 && j >= lim)
					{
						i = d+1;
						j = t;
					}
					else if (i >= 0 && j >= lim)
					{
						j = 0;
						while (fillFlag(i, j))
						{
							j++;
						}
					}
				}
				else if (fillFlag(i, j))
				{
					i = d+1;
					j = t; 
				}
			} while (fill < 26);	
		}
		if (N == 7)
		{
			int j = 3;
			int lim = 7;
			do 
			{
				square[i][j] = fill;
				int d = i;
				int t = j;
				fill++;
				i--;
				j++;
				if (boundsFlag(i,j,lim))
				{
					if (i < 0 && j > 0 && j < lim)
					{
						i = lim - 1;
					}
					else if (i < 0 && j >= lim)
					{
						i = d+1;
						j = t;
					}
					else if (i >= 0 && j >= lim)
					{
						j = 0;
						while (fillFlag(i, j))
						{
							j++;
						}
					}
				}
				else if (fillFlag(i, j))
				{
					i = d+1;
					j = t; 
				}
			} while (fill < 50);	
		}
		if (N == 9)
		{
			int j = 4;
			int lim = 9;
			do 
			{
				square[i][j] = fill;
				int d = i;
				int t = j;
				fill++;
				i--;
				j++;
				if (boundsFlag(i,j,lim))
				{
					if (i < 0 && j > 0 && j < lim)
					{
						i = lim - 1;
					}
					else if (i < 0 && j >= lim)
					{
						i = d+1;
						j = t;
					}
					else if (i >= 0 && j >= lim)
					{
						j = 0;
						while (fillFlag(i, j))
						{
							j++;
						}
					}
				}
				else if (fillFlag(i, j))
				{
					i = d+1;
					j = t; 
				}
			} while (fill < 82);	
		}
		if (N == 11)
		{
			int j = 5;
			int lim = 11;
			do 
			{
				square[i][j] = fill;
				int d = i;
				int t = j;
				fill++;
				i--;
				j++;
				if (boundsFlag(i,j,lim))
				{
					if (i < 0 && j > 0 && j < lim)
					{
						i = lim - 1;
					}
					else if (i < 0 && j >= lim)
					{
						i = d+1;
						j = t;
					}
					else if (i >= 0 && j >= lim)
					{
						j = 0;
						while (fillFlag(i, j))
						{
							j++;
						}
					}
				}
				else if (fillFlag(i, j))
				{
					i = d+1;
					j = t; 
				}
			} while (fill < 122);	
		}
		if (N == 13)
		{
			int j = 6;
			int lim = 13;
			do 
			{
				square[i][j] = fill;
				int d = i;
				int t = j;
				fill++;
				i--;
				j++;
				if (boundsFlag(i,j,lim))
				{
					if (i < 0 && j > 0 && j < lim)
					{
						i = lim - 1;
					}
					else if (i < 0 && j >= lim)
					{
						i = d+1;
						j = t;
					}
					else if (i >= 0 && j >= lim)
					{
						j = 0;
						while (fillFlag(i, j))
						{
							j++;
						}
					}
				}
				else if (fillFlag(i, j))
				{
					i = d+1;
					j = t; 
				}
			} while (fill < 170);	
		}
		if (N == 15)
		{
			int j = 7;
			int lim = 15;
			do 
			{
				square[i][j] = fill;
				int d = i;
				int t = j;
				fill++;
				i--;
				j++;
				if (boundsFlag(i,j,lim))
				{
					if (i < 0 && j > 0 && j < lim)
					{
						i = lim - 1;
					}
					else if (i < 0 && j >= lim)
					{
						i = d+1;
						j = t;
					}
					else if (i >= 0 && j >= lim)
					{
						j = 0;
						while (fillFlag(i, j))
						{
							j++;
						}
					}
				}
				else if (fillFlag(i, j))
				{
					i = d+1;
					j = t; 
				}
			} while (fill < 226);	
		}
	}
};

int main(void)
{
	//Initialize the only needed variable.
	int n = 0;
	//Prompts the user for the size of the magic square and stores their response in n.
	cout << "Enter the size of a magic square:  ";
	cin >> n;
	
	//Checks whether or not the input is good. 
	//If input is not good, it notifys the user and ends the program.
	if (!cin.good() || n < 3 || n > 15 || n % 2 == 0)
	{
		cerr << "Invalid input" << endl;
		return 1;
	}
	
	//Constructs a magic square object named magic using the valid n.
	Magic_Square magic(n);
	//Initializes the magic square.
	magic.initialize();
	//Generates the first magic square.
	magic.generate();
	cout << "\nMagic Square #1\n";
	//Prints out the magic square.
	magic.printSquare();
	//Prints out the results of the magic square.
	magic.result();
	cout << endl;
	//Rotates the previously constructed magic square to generate a second magic square.
	magic.rotate();
	cout << "Magic Square #2\n";
	//Prints out the magic square.
	magic.printSquare();
	//Prints out the results of the magic square.
	magic.result();
	cout << endl;
	//Rotates the previously constructed magic square to generate a thrid magic square.
	magic.rotate();
	cout << "Magic Square #3\n";
	//Prints out the magic square.
	magic.printSquare();
	//Prints out the results of the magic square.
	magic.result();
	cout << endl;
	//Rotates the previously constructed magic square to generate a forth magic square.
	magic.rotate();
	cout << "Magic Square #4\n";
	//Prints out the magic square.
	magic.printSquare();
	//Prints out the results of the magic square.
	magic.result();
	cout << endl;
	return 0;
}

