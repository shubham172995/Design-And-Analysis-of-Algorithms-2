#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
vector<int> dis(201);
vector<bool> mark(201);

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.first>n2.first;
    }
};

/*void relax(int u, int v, int w){
	if(dis[v]>=(dis[u]+w))
		dis[v]=dis[u]+w;
	//cout<<dis[u]<<" "<<dis[v]<<endl;
}*/

void dijkstra(vector<vector<pair<int, int> > > G, int s){
	dis[s]=0;
	loop(i, 1, 201){
		if(i!=s)
			dis[i]=INT_MAX;
	}
	//cout<<dis[20]<<endl;
	priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDist > q;
	/*loop(i, 1, 201)
		q.push(make_pair(dis[i], i));*/
	q.push(make_pair(dis[s], s));
	//cout<<q.top().first<<" "<<q.top().second<<endl;
	while(!q.empty()){
		//cout<<q.top().first<<endl;
		//cout<<q.top().first<<" "<<q.top().second<<endl;
		int u=q.top().second;
		if(mark[u]){
			q.pop();
			continue;
		}
		mark[u]=true;
		q.pop();
		//cout<<q.size()<<endl;
		loop(j, 0, G[u].size()){
			//relax(u, G[u][j].first, G[u][j].second);
			if(dis[G[u][j].first]>=(dis[u]+G[u][j].second))
				dis[G[u][j].first]=dis[u]+G[u][j].second;
			q.push(make_pair(dis[G[u][j].first], G[u][j].first));
			//cout<<q.top().first<<" "<<q.top().second<<endl;
		}
	}
}

int main(){
	fstream myfile;
	myfile.open("dijkstraData.txt");
	vector<vector<pair<int, int> > > G(201);
	if(myfile.is_open()){
		loop(i, 0, 201){
			int a;
			myfile>>a;
			string s;
			getline(myfile, s);
			//cout<<a<<"  "<<s<<endl;
			/*int k=0, temp=0;
			loop(j, 0, s.length()){
				if(s[j]!=','&&!(s[j]>='0'&&s[j]<='9'))
					continue;
			}*/
			stringstream ss;
			ss<<s;
			string temp;
			while(ss>>temp){
				int j, k;
				j=k=0;
				string node, weight;
				for(j=0; j<temp.length();j++){
					if(temp[j]==',')
						break;
				}
				node=temp.substr(0, j);
				weight=temp.substr(j+1, temp.length()-(j+1));
				j=k=0;
				int l=0;
				//cout<<node<<" Node Weight "<<weight<<endl;
				while(l!=node.length()){
					j=(node[l]-'0')+(j*10);
					//node=node.substr(0, node.length()-1);
					++l;
				}
				l=0;
				while(l!=weight.length()){
					k=(weight[l]-'0')+(k*10);
					//weight=weight.substr(0, weight.length()-1);
					++l;
				}
				//cout<<j<<" Node Weight "<<k<<endl;
				G[a].push_back(make_pair(j, k));
			}
		}
	}
	myfile.close();
	/*cout<<"200 ";
	loop(i, 0, G[200].size())
		cout<<G[200][i].first<<" Node Weight "<<G[200][i].second<<endl;*/
	cout<<"Enter source vertex\n";
	int source;
	cin>>source;
	dijkstra(G, source);
	cout<<dis[7]<<" "<<dis[37]<<" "<<dis[59]<<" "<<dis[82]<<" "<<dis[99]<<" "<<dis[115]<<" "<<dis[133]<<" "<<dis[165]<<" "<<dis[188]<<" "<<dis[197]<<endl;
	return 0;
}
