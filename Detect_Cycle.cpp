//Sunny Singh Yadav IIIT-Allahabad 
//isc2013008@iiita.ac.in
#include <bits/stdc++.h>
#include <vector>

#define ll long long

using namespace std;

long long cost[100000];

vector <vector<long long> > arr(100000);
	
void solve(ll n)
{
	bool *Visited = new bool[n];
	
	for(int i = 0; i < n ; i++) {
		Visited[i] = false;
	}
	
	list<ll> queue;
	
	queue.push_back(1);
	Visited[1] = true;
	vector<ll>::iterator itr;
	
	while(!queue.empty()){
		ll s = queue.front();
		cout<<s;
		queue.pop_front();
		for(itr = arr[s].begin() ; itr != arr[s].end() ; itr++){
			if(!Visited[*itr]) {
				Visited[*itr] = true;
				queue.push_back(*itr);
			}
		}
	}
}
bool iscycle(bool Visited[] , int itr , int n , bool backt) 
{
	
	if(!Visited[itr]) {
		Visited[itr] = true;
		bacjt[itr] = true;
			list<long long>::itertor tt;
	
		for(tt = arr[itr].begin(); tt != arr[itr].end() ; tt++) {
			if(!Visited[*tt] && iscycle(Visited , *tt ,n , backt))
				return true;
			else if(backt[*tt]){
				return true;
			}
		}
	}
	
		backt[itr] = false;
		return false;

}
bool DetectCycle(long long n)
{
	bool *Visited = new bool[n];
	bool *backt = new bool[n];
	for(int i = 0 ; i < n ; i++) {
		Visited[i] = false;
		backt[i] = false;
	}
	return iscycle(Visited , backt);
}
int main()
{
	long long j , k , l , m , i , n ,t , a, b;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;

		for(i = 0; i < n ; i++)
		{
			cin>>a;
			cin>>b;
			arr[a].push_back(b);
//			arr[b].push_back(a);
		}
		if(DetectCycle(n) == true ) printf("Yes");
		else printf("No");
	//	solve(n);	
	}	
}
