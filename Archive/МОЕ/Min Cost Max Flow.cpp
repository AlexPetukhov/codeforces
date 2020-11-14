struct Edge{
    int y;
    int f;
    int c;
    int cost;
    Edge();
    Edge(int y, int c, int cost): y(y), c(c), cost(cost), f(0){};
};
vector<Edge> e;
vvi g;
void add_e(int x, int y, int c, int cost){
    g[x].pb(sz(e));
    e.pb(Edge(y,c,cost));
    g[y].pb(sz(e));
    e.pb(Edge(x,0,-cost));
}
int rem(int x){
    return e[x].c - e[x].f;
}

int s,t;

const int MAXN = 306;
int d[MAXN], p[MAXN], pe[MAXN], inq[MAXN];
pii push(){
    re(MAXN) d[i] = M9, p[i] = -1, pe[i] = -1, inq[i] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = 1;
    d[s] = 0;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        inq[v] = 0;
        
        for(auto o : g[v]){
            int r = rem(o);
            if(!r) continue;
            int to = e[o].y;
            int cost = e[o].cost;
            
            if(d[to] > d[v] + cost){
                d[to] = d[v] + cost;
                p[to] = v;
                pe[to] = o;
                if(!inq[to]){
                    inq[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    
    if(p[t] == -1) return {0, -1};
    int cur = t;
    int mx = M9;
    while(cur != s){
        mx = min(mx, rem(pe[cur]));
        cur = p[cur];
    }
    cur = t;
    while(cur != s){
        e[pe[cur]].f += mx;
        e[pe[cur] ^ 1].f -= mx;
        cur = p[cur];
    }
    return {d[t], mx * 1ll * d[t]};
}
pii flow(){
    pii ans;
    
    while(1){
        auto cur = push();
        if(cur.se == -1) break;
        ans+= cur;
    }
    
    return ans;
}
signed main() {
    
    cin >> n;
    s = MAXN - 2;
    t = s + 1;
    g.resize(MAXN);
    
    // ... add edges!!!! ...
    
    auto cur = flow();  // {flow, cost}
    
    
    
    
    
}
