/*fastest way algorithm by Aman Irshad Bajwa*/

#include<iostream> // including libraries

using namespace std;

// method to print answers
void Print_way(int *L1, int *L2, int L, int length, int *f1)
{
	int i = L; // checking which line is our exit line
	cout << "the fastest time is : " << f1[length] << endl;

	// For last station the exit line is stored in L
	cout << "On line " << i << " the station  : " << length << endl;

	// back-tracking and checking which node was seleted by that line
	for (int j = length - 1; j > 0; j--){
		if (i == 1){
			i = L1[j];
		}
		else
		{
			i = L2[j];
		}
		cout << "On line " << i << " the station  : " << j << endl;
	}

}

// implementing fastest way algoritm
void Fastest_Way(int e1, int e2, int *a1, int *a2, int x1, int x2, int *f1, int *f2, int *L1, int *L2, int &L, int *t1, int *t2, int length)
{
	f1[0] = e1 + a1[0]; // storing entry + first station value for line 1
	f2[0] = e2 + a2[0]; // storing entry + first station value for line 2
	int i;

	// checking for the rest of the station which node should we select
	for (i = 1; i<length; i++) // starting from node 2 till the total number of nodes
	{
		// checking for line 1 which node should we select, whether the next node on line 1 or do the transactiona and select the next node from line 2
		
		if (f1[i - 1] + a1[i]<f2[i - 1] + a1[i] + t2[i - 1])  
		{
			f1[i] = f1[i - 1] + a1[i];
			L1[i] = 1;
		}
		else
		{
			f1[i] = f2[i - 1] + a1[i] + t2[i - 1];
			L1[i] = 2;
		}

		// checking for line 1 which node should we select, whether the next node on line 1 or do the transactiona and select the next node from line 2
		if (f2[i - 1] + a2[i]<f1[i - 1] + a2[i] + t1[i - 1])
		{
			f2[i] = f2[i - 1] + a2[i];
			L2[i] = 2;
		}
		else
		{
			f2[i] = f1[i - 1] + a2[i] + t1[i - 1];
			L2[i] = 1;
		}
	}
	// checking the exit values and determining what should be the exit path line 1 or line 2 and storing that value in variable L and storing cost in f1
	//because we are concerned with optimal cost only
	if (f1[length - 1] + x1<f2[length - 1] + x2)
	{
		f1[length] = f1[length - 1] + x1;
		L = 1;
	}
	else
	{
		f1[length] = f2[length - 1] + x2;
		L = 2;
	}

}

// main method
int main(){

	// local declarations
	int e1;
	int e2;
	int x1;
	int x2;
	int len;
	int a1[1000];
	int a2[1000];
	int t1[1000];
	int t2[1000];
	int f1[1000], f2[1000], L1[1000], L2[1000], L;

	// prompting the user to add values
	cout << "Enter the number of nodes\n";
	cin >> len;
	cout << "Enter the entry value for line 1\n";
	cin >> e1;
	
	cout << "Enter the entry value for line 2\n";
	cin >> e2;

	cout << "Enter the exit for line 1\n";
	cin >> x1;

	cout << "Enter the exit value for line 2\n";
	cin >> x2;
	cout << "Enter the station time for line 1\n";
	for (int i = 0; i < len; i++){

		cin >> a1[i];
	}

	cout << "Enter the station time for line 2\n";
	for (int i = 0; i < len; i++){

		cin >> a2[i];
	}

	cout << "Enter the transaction time for line 1\n";
	for (int i = 0; i < len-1; i++){

		cin >> t1[i];
	}

	cout << "Enter the transaction time for line 2\n";
	for (int i = 0; i < len-1; i++){

		cin >> t2[i];
	}

	Fastest_Way(e1, e2, a1, a2, x1, x2, f1, f2, L1, L2, L, t1, t2, len);
	Print_way(L1, L2, L, len, f1);
	getchar();
	getchar();
	return 0;

}