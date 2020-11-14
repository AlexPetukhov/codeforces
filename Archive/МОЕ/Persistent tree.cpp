vi A;
struct node{
    ll val;
    node* l;
    node* r;
    node(ll val, node* l, node* r): val(val), l(l), r(r){};
};
vector<node*> roots;
typedef node* tree;
ll getval(tree t){
    return (t ? t->val : 0);
}
tree make(int x){
    return new node(x, NULL, NULL);
}
tree combine(tree l, tree r){
    return new node(getval(l) + getval(r), l, r);
}
tree build(int l, int r){
    if(l == r)
        return make(A[l]);
    int m = (l + r) >> 1;
    return combine(build(l, m), build(m + 1, r));
}

tree upd(tree t, int l, int r, int pos, int val){
    if(l == r){
        return make(getval(t) + val);
    }
    tree lf = (t ? t->l : NULL);
    tree rg = (t ? t->r : NULL);
    int m = (l + r) >> 1;
    if(pos <= m){
        lf = upd(lf, l, m, pos, val);
    }else{
        rg = upd(rg, m + 1, r, pos, val);
    }
    return combine(lf, rg);
}
ll get(tree t, int l, int r, int i, int j){
    if(i > j) return 0;
    if(!t || (i == l && j == r)) return getval(t);
    int m = (l + r) / 2;
    ll q1 = get(t->l, l, m, i, min(m, j));
    ll q2 = get(t->r, m + 1, r, max(i, m + 1), j);
    return q1 + q2;
}
vector<vector<pair<int,int > > > start, en;
signed main(){
    // freopen("lewa.in","r",stdin);
    // freopen("stupid_rmq.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    tree t = make(0);
    roots.pb(t);
    
    
    
}
