
struct node{
    ll val;
    node* l;
    node* r;
    node(ll val, node* l, node* r): val(val), l(l), r(r){};
};
typedef node* tree;
map<int, int> ma;
ll getVal(tree t){
    return (t ? t->val : 0);
}
void upd(tree t, int l, int r, int pos, ll val){
    if(!t || (l > r)) return;
    assert(t != NULL);
    if(l == r) {
        t->val = val;
        return;
    }
    int m = (l + r) >> 1;
    if(pos <= m){
        if(!(t->l)) t->l = new node(0, NULL, NULL);
        upd(t->l, l, m, pos, val);
    }else{
        if(!(t->r)) t->r = new node(0, NULL, NULL);
        upd(t->r, m + 1, r, pos, val);
    }
    t->val = gcd(getVal(t->l), getVal(t->r));
}
ll get(tree t, int l, int r, int i, int j){
    if(i > j) return 0;
    assert(t != NULL);
    if(i == l && j == r) return t-> val;
    int m = (l + r) >> 1;
    ll q1 = 0, q2 = 0;
    if(t->l) q1 = get(t->l, l, m, i, min(m, j));
    if(t->r) q2 = get(t->r, m + 1, r, max(m + 1, i), j);
    return gcd(q1, q2);
}
signed main(){
    // freopen("lewa.in","r",stdin);
    // freopen("stupid_rmq.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    tree t = new node(0, NULL, NULL);
    
}

