#include <stdio.h>

int main(){
	int n,m,r;
	scanf("%d%d%d",&n,&m,&r);
	int adj[n+1][n+1];
	int indegree[n+1],outdegree[n+1];
      for(int i = 0; i <= n; i++) {
            indegree[i] = 0;
            outdegree[i] = 0;
            for(int j = 0; j <= n; j++) {
                  adj[i][j] = 0;
            }
      }
	for(int i=0 ;i < m ;i ++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a][b]=1;
		indegree[b] ++;
		outdegree[a]++;
	}

	int size =0 ;
	int ans[n+1];
	int k=0;

	for(int i=1 ;i <= n ;i ++)  {
		if(outdegree[i] == 0 && indegree[i] > 0 ) {
			size ++;
			ans[k++] = i;
		} 
	}

      int maxi = 0;
      for(int i=1 ;i <= n ;i ++) {
              if(indegree[i] >= maxi) {
                    maxi = indegree[i];
              }
        }
      for(int i=1;i <=  n ;i ++) {
            if(indegree[i] == maxi) {
                printf("%d ",i);
            }
      }


}
