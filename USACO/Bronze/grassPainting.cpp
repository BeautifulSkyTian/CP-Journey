#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); 
    cin.tie(0); 

	freopen("gymnastics.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("gymnastics.out", "w", stdout);
    
    int N;
	cin >> N;
	vector<int> degree(N);
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		degree[a - 1]++, degree[b - 1]++; //This keeps track of the number of neighbours of a node. 
	}
	int result = 0;
    /* The reason for only tracking the number of neighbours of a node is that the types of grass can be reused. Imagine that you have a tree with a depth of 3. 
    Say that the first stage has five neighbours and each of these neighbours has an individual neighbour that is not connected to anything. The nodes in stage 2 can be reused in a different order in stage 3. 
    This means that there is no need to worry about neighbours of neighbours. You only need to keep track ok the number of neighbours of a node. If a node has n neighbours, then you need n+1 types. 
    A separate tree can just reuse the types of a different tree since the two trees are not connected. 
    */
	for (int i = 0; i < N; i++) result = max(result, degree[i]); 
	cout << result + 1 << '\n';
}