/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty()) return -1;
   return s.top();
}
/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty()) return -1;
   s.pop();
   int o = s.top();
   s.pop();
   if(!s.empty())minEle = s.top();
   return o;
}
/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty()) minEle=INT_MAX;
   if(x < minEle) minEle = x;
   s.push(x);
   s.push(minEle);
}
