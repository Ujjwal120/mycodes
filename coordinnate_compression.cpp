
// coordinate compression understand it

const int maxn = 1e5, logn = 30, inf = 1e9;

int add[2 * maxn * logn], sum[2 * maxn * logn];
int L[2 * maxn * logn], R[2 * maxn * logn];
int sz = 2;

int create(int &v)
{
    if(!v)
        v = sz++;
    return v;
}

void upd(int a, int b, int c, int v = 1, int l = 0, int r = inf)
{ // arr[a..b) += c
    if(a <= l && r <= b)
    {
        add[v] += c;
        sum[v] += (r - l) * c;
        return;
    }
    if(r <= a || b <= l)
        return;
    int m = (l + r) / 2;
    upd(a, b, c, create(L[v]), l, m);
    upd(a, b, c, create(R[v]), m, r);
    sum[v] = (r - l) * add[v] + sum[L[v]] + sum[R[v]];
}

int get(int a, int b, int v = 1, int l = 0, int r = inf)
{ // sum[a..b)
    if(a <= l && r <= b)
        return sum[v];
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) / 2;
    return get(a, b, L[v], l, m) + get(a, b, R[v], m, r) +
           max(0, min(r, b) - max(l, a)) * add[v];
}