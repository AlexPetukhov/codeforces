class node{
    public:
        ll sum;
        node* le;
        node* ri;
        int l;
        int r;
        node(int a,int b){
            sum = 0;
            le = ri = 0;
            l = a;
            r = b;
        }
        
};
typedef node* tree;
ll get(tree t, int l, int r){
    ll ans = 0;
    if(t == 0)ret 0;
    if(t -> l > r || t -> r < l)ret 0;
    if(t -> l >= l && t -> r <= r)ret t -> sum;
    
    ans = get(t -> le, l,r) + get(t -> ri, l ,r);
    ret ans;
}
void add(tree t, int p, int x){
    t -> sum += x;
    if( t -> l == t -> r)ret ;
    int m = (t -> l + t -> r)/2;  
    // cout << t -> l << " " << t -> r << " " << m << endl;
    if( p <= m){
        if(!(t -> le))t -> le = new node(t -> l, m);
        add(t -> le, p ,x);
    }
    else {
        if(! t -> ri)t -> ri = new node(m + 1, t -> r);
        add(t -> ri, p, x);
    }
    
}