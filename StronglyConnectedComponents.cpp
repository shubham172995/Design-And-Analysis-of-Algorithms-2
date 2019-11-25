#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int f=0;
vector<int> fin(875715), fin1(875715), leader(875715);
int lead=875714;
vector<bool> visited(875715);
int siz;

void dfs(vector<vector<int> > G, int v){
	visited[v]=true;
	loop(i, 0, G[v].size()){
		if(!visited[G[v][i]])
			dfs(G, G[v][i]);
	}
	++f;
	fin[v]=f;
	fin1[f]=v;
}

void workhorse(vector<vector<int> > G){
	for(int i=875714;i>0;i--){
		if(!visited[i]){
			lead=i;
			dfs(G, i);
		}
	}
}


void DFSloop(vector<vector<int> > G, int v){
	/*leader[fin1[v]]=lead;
	if(fin1[v]!=lead)
		++leader[lead];*/
	if(!visited[v]){
		//cout<<v<<" ";
		visited[v]=true;
		leader[v]=lead;
		loop(i, 0, G[v].size()){
			DFSloop(G, G[v][i]);
		}
	}
}

int main(){	
	vector<vector<int> > G(875715), G1(875715);
	fstream myfile;
	myfile.open(("StronglyConnectedComponents.txt"));
	if(myfile.is_open()){
		int a, b;
		while(myfile>>a>>b){
			/*int a, b;
			cin>>a>>b;*/
			if(a==0)
				break;
			G[a].push_back(b);
			G1[b].push_back(a);
			//cout<<a<<" "<<b<<endl;
		}
		myfile.close();
	}
	workhorse(G);
	loop(i, 1, visited.size()){
		visited[i]=false;
	}
	/*loop(i, 1, 875715){
		cout<<fin[i]<<" "<<fin1[i]<<" "<<leader[i]<<endl;
	}*/
	map<int, int> sizes;
	for(int i=875714;i>0;i--){
		//DFSloop(G1, i);
		//siz=0;
		if(!visited[fin1[i]]){
			lead=fin1[i];
			//cout<<"Hey "<<lead<<endl;
			leader[lead]=lead;
			DFSloop(G1, fin1[i]);
			//cout<<endl;
		}
		//sizes.push_back(siz);
	}
	loop(i, 0, leader.size()){
		if(sizes[leader[i]])
			++sizes[leader[i]];
		else
			sizes[leader[i]]=1;
	}
	vector<int> s;
	for(map<int, int>::iterator it=sizes.begin(); it!=sizes.end(); it++){
		//cout<<it->first<<" hey "<<it->second<<endl;
		s.push_back(it->second);
	}
	sort(s.begin(), s.end());
	int c=0;
	for(int i=s.size()-1;i>=0;i--){
		if(c==5)
			break;
		++c;
		cout<<s[i]<<endl;
	}
	return 0;
}
