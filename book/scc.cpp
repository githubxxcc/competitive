/*
 * =====================================================================================
 *
 *       Filename:  scc.cpp
 *
 *    Description:  SCC 4.2.9
 *
 *        Version:  1.0
 *        Created:  11/26/18 09:05:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ricky (), 
 *   Organization:  
 *
 * =====================================================================================
 */


int main() {
    /*  Build Graph */
    auto G = build_adjG();
    int N = num_nodes;

    /*  Prep data */
    vector<int> dfs_num(N, -1);
    vector<int> dfs_low(N, 0);
    vector<int> on_path(N, 0);
    stack<int> S;
    int counter = 0;

    for(int i = 0; i<N ; i++) {
        if(dis_num[i] == -1) {
            tarjanSCC(G, dfs_num, dfs_low, on_path, S, counter, i);
        }
    }
}

void tarjanSCC(vvi &G, vi&dfs_num, vi &dfs_low, vi &on_path, si &S, int count, int u) 
{
    dfs_num[u] = dfs_low[u] = count++;
    on_path[u] = 1;
    S.push(u);

    for(auto v : G[u]) {
        if(dfs_num[v] == -1) {
            tarjanSCC(G, dfs_num, dfs_low, on_path, S, count, v);
        }

        if(on_path[v] == 1) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    /*  Back to the node, all children visited */
    if(dfs_num[u] == dfs_low[v]) {
        vi comp;
        /*  Keep popping children nodes of a component */
        while(1) {
            auto x = S.top(); S.pop();
            comp.push_back(x);
            on_path[x] = 0;
            if(u == v) break; 
        }
    }
}


