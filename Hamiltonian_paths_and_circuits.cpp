#include <iostream>
#include <vector>
using namespace std;

vector<string> H_cycle;    // Hamiltonian Circuits storage
vector<string> H_path;     // Hamiltonian Path storgae
ll ans = INT_MAX;          // Minimum Hamiltonian Path
string q;                  // Which Hamiltonian Path (As string format)

void Hamiltonian_Paths_and_Cycles(vector<vector<ll>> g, int v, vector<bool> visited, vector<int> &path, int N){
	if (path.size() == N){
		string k="";
		ll sum=0;
		for (int i=0;i<N-1;i++){
			sum += graph[path[i]][path[i+1]];                /*This If statement is completelty for stroring the cycle/path as string and checking minimum*/
			k += to_string(path[i]);
	    }
	    k += to_string(path[N-1]);
		if(graph[path[0]][path[N-1]]!=0){
			k += to_string(path[0]);
			sum += graph[path[i]][path[i+1]];
			H_cycle.push_back(k);
		}
		else{
			H_path.push_back(k);
		}
		if(sum<ans){
			ans = sum;
			q = k;
		}
		return;
	}
	for (int w=0;w<N;w++){
		if (!visited[w] and g[v][w]==1){
			visited[w] = true;
			path.push_back(w);                                 // Recursive Steps for Hamiltonian generation
			Hamiltonian_Paths_and_Cycles(g, w, visited, path, N);
			visited[w] = false;
			path.pop_back();
		}
	}
}

int main(){
	ll N,e,a,b;
	cin >> N >> e;
	vector<vector<ll>> graph(N,vector<ll>(N,0));
	for(int i=0;i<e;i++){
		cin >> a >> b;
		graph[a][b]=1;
		graph[b][a]=1;
	}
	vector<int> path;
	for(int i=0;i<N;i++){
		path.push_back(i);
		visited[i]=true;
		Hamiltonian_Paths_and_Cycles(g, start, visited, path, N);
		visited[i]=false;
		path.pop_back();
	}
	if(H_cycle.size()==0){
		cout << "No Hamiltonian Circuit Exists"<< endl;
		cout << "Following are the Hamiltonian Paths" << endl;
		for(auto x: H_path){
			cout << x << endl;
		}
	}
	else{
		cout << "Hamiltonian Circuit Exists"<< endl;
		cout << "Following are the Hamiltonian Circuits" << endl;
		for(auto x: H_cycle){
			cout << x << endl;
		}
		unordered_map<char,unordered_map<char,int>> mp;
		vector<pair<string,string>> ans;
		for(int i=0;i<H_cycle.size();i++){
			string p = H_cycle[i];
			for(int j=0;j<p.length()-1;j++){                         // CHeckig the existance of edge disjoint Hamiltonian Cycles
				mp[p[j]][p[j+1]]=1;                                  // Uses Map of Map for edge mapping
			}
			for(int j=i+1;j<H_cycle.size();j++){
				string x = H_cycle[i];
				ll flag=0;
				for(int k=0;k<x.length()-1;k++){
					if(mp[p[k]][p[k+1]]=1){
						flag=1;
						break;
					}
				}
				if(flag==0){
					ans.push_back({p,x});
				}
			}
		}
		if(ans.size()==0){
			cout << "No Edge Disjoint Hamiltonian Circuit exists" << end;
		}
		else{
			cout << "Following are the edge Disjoint Hamiltonian Circuits" << endl;
			for(int i=0;i<ans.size());i++){
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}
	}
	if(ans!=INT_MAX){
		cout << "Following is shortest Hamiltonian" << endl;
		cout << q << endl;
	}
	return 0;
}
