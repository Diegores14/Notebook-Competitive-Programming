struct kosaraju {
    int N, cont;
    vector< vector< int > > G, GT;
    vector< int > order, comp;
    vector< bool > used;
    kosaraju( int n ): N(n), G(N), GT(N), comp(N) { cont = 0; }
    void add_edge( int a, int b ) {
        G[a].push_back(b);
        GT[b].push_back(a);
    }

    void DFS1( int v ) {
        used[v] = true;
        for( int u: G[v] ) {
            if( !used[u] ) {
                DFS1(u);
            }
        }
        order.push_back(v);
    }

    void DFS2( int v ) {
        used[v] = true;
        comp[v] = cont;
        for( int u: GT[v] ) {
            if( !used[u] ) {
                DFS2(u);
            }
        }
    }

    void start() {
        used.assign(N, false);
        for( int i = 0; i < N; i++ ) {
            if(!used[i]) {
                DFS1(i);
            }
        }
        used.assign(N, false);
        reverse( order.begin(), order.end() );
        for( int u: order ) {
            if( !used[u] ) {
                DFS2(u);
                cont++;
            }
        }
    }
};