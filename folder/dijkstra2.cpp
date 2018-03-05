bool f(int a, int b){
    return { d[b],a} < { d[a] ,b };
}

void dij(int x){  //O(nlog(n) + m*log(n))
    for() d[i]] = infinity;
    d[x] = 0;
    set<int , bool(*)(int,int) > s(f);
    s.insert(x);
    while(!s.empty()){
        int id = *s.begin();
        s.erase(id);
        for( y : id -> y) {
            int dist = d[id] + l;
            if(d[y] > dist ){
                s.erase(y);
                d[y] = dist;
                s.insert(y);
            }
        }
    }
}

