
// int t[4*MAXN];
// struct node{
//   int val = 0;
//   node* le;
//   node* ri;
// };
// void add(node* t, int l, int r,int p,int x){
//   if(r - l == 1){
//     t -> val += x;
//     ret;
//   }
//   int m = (l + r) >> 1;
//   if(p < m){
//     if(t -> le == nullptr) t -> le = new node();
//     add(t -> le, l, m, p, x);
//   }else{
//     if(t -> ri == nullptr) t -> ri = new node();
//     add(t->ri, m, r, p, x);
//   }
//   if(t -> le == nullptr) t -> le = new node();
//   if(t -> ri == nullptr) t->ri = new node();
//   t->val = t->ri->val + t->le->val;
// }
// int get(node* t, int l, int r, int L, int R){
//   if(L >= R) ret 0;
//   if(l >= L && r <= R) ret t -> val;
//   int m = (l + r) / 2;
//   if(t -> le == nullptr) t -> le = new node();
//   if(t -> ri == nullptr) t->ri = new node();
//   ret get(t->le,l,m,L,min(R,m)) + get(t->ri,m,l,max(L,m),R);
// }

// int Sum (int v, int tl, int tr, int l, int r) {
// 	if (l > r)
// 		return 0;
// 	if (l == tl && r == tr)
// 		return t[v];
// 	int tm = (tl + tr) / 2;
// 	return Sum (v*2, tl, tm, l, min(r,tm))
// 		+ Sum (v*2+1, tm+1, tr, max(l,tm+1), r);
// }
// void update (int v, int tl, int tr, int pos, int new_val) {
// 	if (tl == tr)
// 		t[v] = new_val;
// 	else {
// 		int tm = (tl + tr) / 2;
// 		if (pos <= tm)
// 			update (v*2, tl, tm, pos, new_val);
// 		else
// 			update (v*2+1, tm+1, tr, pos, new_val);
// 		t[v] = t[v*2] + t[v*2+1];
// 	}
// }