vl ft;
ll get(int x){
    ll ans = 0;
    for(; x; x -= (x &(-x))) ans += ft[x];
    return ans;
}
ll get(int x, int y){
    return get(y) - (x == 1 ? 0 : get(x - 1));
}
void upd(int pos, int val){
    for(; pos < sz(ft); pos += (pos & (-pos))) ft[pos] += val;
}
signed main(){
    ft.assign(n + 1, 0);
    
}
