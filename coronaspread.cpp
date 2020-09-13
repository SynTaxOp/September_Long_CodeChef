#include <bits/stdc++.h>
#include <chrono>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vp;
typedef pair<long long, long long> pl;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int, int> mi;
#define fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define fa(i, N) for (auto i : N)
#define gi map<int, si>
#define gc map<char, set<char>>
#define all(X) X.begin(), X.end()
#define all(X) X.begin(), X.end()
#define T5 100001
#define mod 1000000007
void make_graph_dir(vp V,gi &G)
{
    fa(i,V)
    {
        G[i.first].insert(i.second);
    }
}
void make_graph_un(vp V,gi &G)
{
    fa(i,V)
    {
        G[i.first].insert(i.second);
        G[i.second].insert(i.first);
    }
}
bool isprime(int N)
{
  if(N%2==0){return false;}
  for(int i=3;i*i<=N;i=i+2)
  {
    if(N%i==0){return false;}
  }
  return true;
}
ll factorial(ll a)
{
  ll p=1;
  fo(i,1,a+1)
  {
    p*=i;  
  }
  return p;
}
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  int tc = 0;
  while ((tc++) < t)
  {
     int N;
     cin>>N; 
     vi V(N);
     int a;
     fo(i,0,N)
     {
      cin>>V[i]; //Taking input of speeds
     }
     int maxinf=INT_MIN;
     int mininf=INT_MAX;
     fo(i,0,N)   //loop for selecting ith player
     {
       int minspeed=INT_MAX;
       int maxspeed=INT_MIN;
       fo(j,0,i+1){maxspeed=max(maxspeed,V[j]);} //finding maxspeed in left subarray
       fo(j,i,N){minspeed=min(minspeed,V[j]);}  //finding minspeed in right subarray
       int s=1; //Counter=1
       fo(j,0,i) //Left Subarray
       {
         if(V[j]>minspeed) //if speed is greater than minspeed ,increment counter
         {
             s++;
         }
       }
       fo(j,i+1,N) //Right Subarray
       {
         if(V[j]<maxspeed) //If speed is lesser than maxspeed,increment counter
         {s++;}
       }
       //Total No of Infected calculated,Update maxinf and mininf
       maxinf=max(maxinf,s);
       mininf=min(mininf,s); 
     }
    cout<<mininf<<" "<<maxinf<<endl; 
  }
}
