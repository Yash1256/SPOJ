#if 1
/*AC in first attempt . form nbr list we can easily calculate ex from 4 we can go 1 5 7  2 length paths from 1 will be 1 + 1 + 1
=3    when we have to count 3 len path from a no see all neighbours and accummulate their 2 len path count
BASIC conting with Memoization*/
#include <iostream>
#include <cstdio>
using namespace std;
#define MOD 1000000007
int nbr[10][4] = { 
	{7,-1,-1,-1 },  // 0s nbr
	{ 2,4,-1,-1 },  // 1s nbr
	{ 1,3,5,-1 },  // 2s nbr	
	{ 2,6,-1,-1 },  // 3s nbr
	{ 1,5,7,-1 },  // 4s nbr
	{ 2,4,6,8 },  // 5s nbr
	{ 3,5,9,-1 },  // 6s nbr
	{ 4,8,0,-1 },  // 7s nbr
	{ 5,7,9,-1 },  // 8s nbr
	{ 6,8,-1,-1 },  // 9s nbr
};
/// row starting no   col = pass code length
int pass[11][100000] = {0}; // keep passcode count in this array . once computed will be reused
int N;
int main()
{
	std::ios_base::sync_with_stdio(false); //  makes I/O faster
#ifdef _WIN32
	freopen("SPOJ_SAFECRAC_Crack_the_Safe.txt", "r", stdin);
#endif
	int T;
	cin >> T;
	int done_count = 0;
	for (int i = 0; i<= 9; i++)
	{
		pass[i][1] = 1;   /// 1 lenght password are 1 in total Initialize that first
	}
	pass[10][1] = 10; //  Initial total sum for all 1 length password
	done_count = 1;
	while (T--)
	{
		cin >> N;
		for (int pLen = done_count + 1; pLen <= N; pLen++)
		{
			int count = 0;
			 for (int no = 0; no <= 9; no++)
				{
					int sum = 0;
					////nbr loop
					for (int k = 0; k < 4;k++) 
					{
						if (nbr[no][k] == -1)
							break;
						else
						{
							sum = ( sum%MOD + pass[nbr[no][k]][pLen - 1]% MOD) % MOD; /// need to add neighbours count of password of lenght lesser by ONE
						}
					}//for k
					pass[no][pLen] = sum;
					count = (count%MOD + pass[no][pLen]% MOD)% MOD; //accumulte sum 
				}//for i
				pass[10][pLen] = count;
				done_count++;
			
		}
		
		cout << pass[10][N] << endl;
	}
	return 0;
}
#endif
