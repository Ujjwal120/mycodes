// a and b are the start and end of an interval
// ternary search is for real numbers and the function should be Unimodal MUST


double l = a, r = b;
 
for(int i = 0; i < 200; i++) {
  double l1 = (l*2+r)/3;
  double l2 = (l+2*r)/3;
  if(f(l1) > f(l2)) r = l2; 
  else l = l1;
}
 
double ans = l;