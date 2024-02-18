#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define N 4
#define M 5

class node {
public:
   int x, y;
   int dir; /*If dir=0 Up direction.
If dir=1 left direction.
If dir=2 down direction.
If dir=3 right direction.*/

   node(int i, int j)
   {
       x = i;
       y = j;
       dir = 0; //set to 0 initially --> up direction
   }
};


int n = N, m = M;

int fx, fy;
bool visited[N][M];

bool isReachable(int maze[N][M])
{

    int j = 0, k = 0;
  
   stack<node> s;
  
   node temp(k, j);
  
   s.push(temp);

   while (!s.empty()) {

         
       temp = s.top();
       int q = temp.dir;
       k = temp.x, j = temp.y;

       temp.dir++;
       s.pop();
       s.push(temp);

      
       if (k == fx and j == fy) {
           return true;
       }

       //up direction
       if (q == 0) {
           if (k - 1 >= 0 and maze[k - 1][j] and
                                   visited[k - 1][j]) {
               node temp1(k - 1, j);
               visited[k - 1][j] = false;
               s.push(temp1);
           }
       }

       // left direction
       else if (q == 1) {
           if (j - 1 >= 0 and maze[k][j - 1] and
                                   visited[k][j - 1]) {
               node temp1(k, j - 1);
               visited[k][j - 1] = false;
               s.push(temp1);
           }
       }

       // down direction
       else if (q == 2) {
           if (k + 1 < n and maze[k + 1][j] and
                                   visited[k + 1][j]) {
               node temp1(k + 1, j);
               visited[k + 1][j] = false;
               s.push(temp1);
           }
       }
       // right direction
       else if (q == 3) {
           if (j + 1 < m and maze[k][j + 1] and
                                   visited[k][j + 1]) {
               node temp1(k, j + 1);
               visited[k][j + 1] = false;
               s.push(temp1);
           }
       }

  
       else {
           visited[temp.x][temp.y] = true;
           s.pop();
       }
   }


   return false;
}


int main()
{
     
   memset(visited, true, sizeof(visited));
  

   int maze[N][M] = {
       { 1, 0, 1, 1, 1 },
       { 1, 1, 1, 0, 1 },
       { 0, 0, 0, 0, 1 },
       { 1, 1, 1, 0, 1 }
   };

   cout<<"Input\n"<<N<<" "<<M<<"\n"<<endl;
int i,j;
for(i=0;i<N;i++){
for(j=0;j<M;j++){
if(j!=M-1){
cout<<maze[i][j]<<", ";
}

else{
cout<<maze[i][j];
}
}
cout<<endl;
}

   fx = 3;
   fy = 2;

cout<<endl<<fx<<" "<<fy<<"\n";

   if (isReachable(maze)) {
       cout << "\nPath Found!" << '\n';
   }
   else
       cout << "\nNo Path Found!" << '\n';
      
   return 0;
}