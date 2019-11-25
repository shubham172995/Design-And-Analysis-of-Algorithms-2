#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int f=0;
vector<int> fin(13), fin1(13), leader(13);
int lead=13;
vector<bool> visited(13);
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
	for(int i=12;i>0;i--){
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
	vector<vector<int> > G(13), G1(13);
	fstream myfile;
	myfile.open(("test5.txt"));
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
	loop(i, 1, 13){
		cout<<fin[i]<<" "<<fin1[i]<<" "<<leader[i]<<endl;
	}
	map<int, int> sizes;
	for(int i=12;i>0;i--){
		//DFSloop(G1, i);
		//siz=0;
		if(!visited[fin1[i]]){
			lead=fin1[i];
			//cout<<"Hey "<<lead<<endl;
			leader[lead]=lead;
			DFSloop(G1, fin1[i]);
			cout<<endl;
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
	loop(i, 0, s.size()){
		cout<<s[i]<<endl;
	}
	return 0;
}
