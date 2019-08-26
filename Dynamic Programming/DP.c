Exceptional Lego Block
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX 1001

 int N, M,i,j,nPieces = 4;
int pieces[] = {1, 2, 3, 4};
long long RowComb[MAX],ColumnComb[MAX],ColumnCombWithNoHoles[MAX];

void logic()
{
    scanf("%d %d",&N,&M);
    
    memset(RowComb, 0, sizeof(RowComb));
    RowComb[0] = 1;
    for (i = 1; i <= M; i++) {
        for (j = 0; j < nPieces; j++) {
            if (i - pieces[j] >= 0)
                RowComb[i] = (RowComb[i]+RowComb[i - pieces[j]]) % MOD;
        }
    }

    for (i = 1; i <= M; i++) {
        long long res = 1;
        for (j = 1; j <= N; j++) {
            res = (res *RowComb[i]) % MOD;
        }
        ColumnComb[i] = res;
    }
    ColumnCombWithNoHoles[1] = ColumnComb[1];
    for (i = 2; i <= M; i++) {
        ColumnCombWithNoHoles[i] = ColumnComb[i];
        for (j = 1; j < i; j++) {
            ColumnCombWithNoHoles[i] = (MOD + ColumnCombWithNoHoles[i]-(ColumnCombWithNoHoles[j] * ColumnComb[i - j]) % MOD) % MOD;
        }
    }

    printf("%lld\n",ColumnCombWithNoHoles[M]);
    	
}

int main() {
    int T;
	scanf("%d",&T);	
	while(T--) logic();   
    return 0;
}
1. Fibonacci Modified
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXL    26624

unsigned int MADD(unsigned int* pC, unsigned int* pB, unsigned int* pA, unsigned int n)
{
    unsigned int i,j,x;
    
    for (i=0; i<n; i++) pC[i] = pA[i];
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if ((x = (pC[i+j] += pB[i]*pB[j])) < 10000) continue;
            x /= 10000; pC[i+j+1] += x; pC[i+j] -= x*10000;            
        }
        if ((x = pC[i+j]) < 10000) continue;
        x /= 10000; pC[i+j+1] += x; pC[i+j] -= x*10000;            
    }
    n <<= 1; while (pC[n-1] == 0) n--;
    return n;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int N,m,n=1;
    unsigned int* p;
    unsigned int* pA;
    unsigned int* pB;
    unsigned int* pC;
    unsigned int A[MAXL];
    unsigned int B[MAXL];
    unsigned int C[MAXL];

    memset(pA=A, 0, sizeof(A));
    memset(pB=B, 0, sizeof(B));
    memset(pC=C, 0, sizeof(C));

    scanf("%d %d %d\n", pA, pB, &N);

    while (N-- > 2)
    {
        n = MADD(pC, pB, pA, n);
        p = pC; pC=pA; pA = pB; pB=p;
    }
    printf("%d", p[--n]);
    while (n > 0) printf("%04u", p[--n]);
    printf("\n");
    return 0;
}
2. Maximum Subarray
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m;
    scanf("%d",&m);
    while(m--)
      {
    int n;
    scanf("%d",&n);
    long *arr=(long*)calloc(n,sizeof(long));
    int i,j;
    for(i=0;i<n;i++)
        {
        scanf("%li",&arr[i]);
    }
    
    long max_so_far = 0;
    long max_ending_here = 0;
    long count=0;
    for( i = 0; i < n; i++)
    {
        if(arr[i]>0)
            count+=arr[i];
        max_ending_here = max_ending_here + arr[i];
 
        if(max_ending_here < 0)
            max_ending_here = 0;
 
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
        if(max_so_far==0)
        {
            max_so_far=arr[0];
            for( i = 1; i < n; i++)
            {
                if(arr[i]>max_so_far)
                    {
                     max_so_far=arr[i];
                }
            }
            count=max_so_far;
        }
    printf("%li %li\n",max_so_far,count);
    count=0;
   
    }
    
        
    return 0;
}
3. Coin Change Problem
#include <stdio.h>
#include <stdlib.h>
long long C[100000];

int main(){
  long long N,c_size=0,**dp,i,j;
  char c;
  for(i=0;1;i++){
    scanf("%lld%c",&C[i],&c);
    if(c!=','){
      scanf("%lld",&N);
      break;
    }
    scanf("%c",&c);
  }
  c_size=i+1;
  dp=(long long**)malloc(c_size*sizeof(long long*));
  for(i=0;i<c_size;i++)
    dp[i]=(long long*)malloc((N+1)*sizeof(long long));
  for(i=0;i<N+1;i++)
    for(j=0;j<c_size;j++)
      if(!j)
        if(i%C[j]==0)
          dp[j][i]=1;
        else
          dp[j][i]=0;
      else{
        dp[j][i]=dp[j-1][i];
        if(i-C[j]>=0)
          dp[j][i]+=dp[j][i-C[j]];
      }
  printf("%lld",dp[c_size-1][N]);
  return 0;
}
4. Candies
#include<stdio.h>
int main()
{
    int n;
    //int n;
    int child[1000000];
    int candies[1000000];
    int j,i;
    unsigned long long int sum=0;
    
    int c=1;
        int d=1;
    scanf("%d",&n);
        scanf("%d",&child[0]);
    candies[0]=1;
    for(i=1;i<n;i++)
    {
        scanf("%d",&child[i]);
        if(child[i]==child[i-1])
        {
            c=1;
            candies[i]=1;
        }
        else if(child[i]>child[i-1])
        {
            c=c+1;
            candies[i]=c;
        }
        else if(child[i]<child[i-1])
        {
            if(c==1)
            {
                
               j=i-1;
                candies[i]=1;
                candies[i-1]++;
                while(j>=1 && child[j]<child[j-1] && candies[j]>=candies[j-1])
                {
                    
                    candies[j-1]++;
                    j--;
                }
            }
            else
            {
                c=1;
                candies[i]=1;
            }
        }
    }
    for(i=0;i<n;i++)
        sum+=candies[i];
    printf("%lld\n",sum);
}
5. stock Maximize
#include<stdio.h>
int maxarray(int *a,int start,int end)
{
    int i,pos,big;
    big=a[start];
    pos=start;
    for(i=start;i<=end;i++)
    {
        if(a[i]>big)
        {
        pos=i;
        big=a[i];
        }
    }
    return pos;
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        long long pro=0;
        int pos=0,start=0;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        while(pos!=(n-1))
        {
        pos=maxarray(a,start,n-1);
        for(i=start;i<pos;i++)
        {
            pro=pro+(a[pos]-a[i]);
        }
        start=pos+1;
        }
        printf("%lld\n",pro);
    }
    return 0;
}
6.Grid Walking
#include <stdio.h>
#include <stdlib.h>

typedef long long int64;

#define MAXD 10
#define MAXDIM 128 /* 100 + elbow room */
#define MAXLEN 300

/* All math done modulo MOD. */
#define MOD 1000000007LL

/* n choose k  */
int64 choose[MAXLEN+1][MAXLEN+1];

void initbinomial(int maxn) {
  int n, k;

  choose[0][0] = 1;
  for (n = 1; n <= maxn; n++) {
    choose[n][0] = choose[n][n] = 1;
    for (k = 1; k <= n-1; k++)
      choose[n][k] = (choose[n-1][k] + choose[n-1][k-1]) % MOD;
  }
}

int ndim;         /* N = number of dimensions */
int walklen;      /* M = total length of walk */
int initx[MAXD];  /* initial position */
int dim[MAXD];    /* dimension size */

/* walks[i][n] = # of one-dimensional random walks of length n */
int64 walks[MAXD][MAXLEN+1];

/* Compute all one-dimensional walks. */
void computewalks() {
  int i, d, len;
  int64 prev[MAXDIM], cur[MAXDIM];

  for (d = 0; d < ndim; d++) {
    /* Initially, only one zero-length walk. */
    for (i = 1; i <= dim[d]; i++)
      cur[i] = 1;
    walks[d][0] = 1;

    for (len = 1; len <= walklen; len++) {
      /* Only need state from n-1 walks to compute n walks. */
      for (i = 1; i <= dim[d]; i++)
	prev[i] = cur[i];
      prev[0] = prev[dim[d]+1] = 0;
      
      /* 
       * Two possibilities, left or right.
       * Sentinels handle edge cases.
       */
      for (i = 1; i <= dim[d]; i++)
	cur[i] = (prev[i-1] + prev[i+1]) % MOD;

      /* We only care about walks leaving from the initial point */
      walks[d][len] = cur[initx[d]];
    }
  }
}

/* Compute # of n-dimensional walks of length walklen. */
int64 ndwalks() {
  int d, m, k;
  int64 prev[MAXLEN+1], cur[MAXLEN+1];
  int64 paths;

  /* Initial value. */
  cur[0] = 1;
  for (m = 1; m <= walklen; m++)
    cur[m] = 0;

  for (d = ndim-1; d >= 0; d--) {
    for (m = 0; m <= walklen; m++)
      prev[m] = cur[m];

    /* Subproblem: K out of M legs of the random walk occur in this
     * dimension.  We know how many one-dimensional walks of length K
     * there are in this dimension.  What do the with the remaining
     * M-K legs is the other subproblem.
     */
    for (m = 0; m <= walklen; m++) {
      cur[m] = 0;
      for (k = 0; k <= m; k++) {
	paths = (choose[m][k] * walks[d][k]) % MOD;
	cur[m] += (paths * prev[m-k]) % MOD;
	cur[m] %= MOD;
      }
    }
  }

  /* We care about full-length walks using all dimensions. */
  return cur[walklen];
}

void getinput() {
  int i;

  if (scanf(" %d %d", &ndim, &walklen) != 2)
    exit(1);
  
  for (i = 0; i < ndim; i++)
    if (scanf(" %d", &initx[i]) != 1)
      exit(1);
  
  for (i = 0; i < ndim; i++)
    if (scanf(" %d", &dim[i]) != 1)
      exit(1);
}

int main() {
  int ncases;

  initbinomial(MAXLEN);

  if (scanf(" %d", &ncases) != 1)
    return 1;

  while (ncases-- > 0) {
    getinput();
    computewalks();
    printf("%lld\n", ndwalks());
  }

  return 0;
}
7.Red John is Back
#include<stdio.h>
#include<stdlib.h>
  int sieve[300000][2];
int main()
{
    int t,i,j,k,n;
    int a[41],x;
    a[1]=1;
    a[0]=0;
    a[2]=1;
    a[3]=1;
    a[4]=2;
    for(i=5;i<=40;i++)
    {
        a[i]=a[i-1]+a[i-4];
    }
   // printf("%d\n",a[40]);
    for(i=0;i<300000;i++)
    {
        for(j=0;j<2;j++)
        sieve[i][j]=0;
    }
    for(i=2;i<300000;i++)
    {
        if(sieve[i][0]==0)
         {
             sieve[i][1]=sieve[i-1][1]+1;
         }
         else
         {
             sieve[i][1]=sieve[i-1][1];
             continue;
         }
        for(j=2*i;j<300000;j=j+i)
        {
            sieve[j][0]=1;
        }
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%d\n",sieve[a[n]][1]);
    }

    return(0);
}
8. mr k Marsh
#include <stdio.h>


long long M,a[1000][1000],b[1000],i,j,k,l,m,n,v=0;
char c[1000];


void test(long long aa, long long bb)
{
long long vv;

vv = 2*(aa+bb);

if(vv > v) v = vv;

//printf("test %lld %lld\n", aa,bb);

return ;
}

int main()
{

scanf("%lld %lld",&M, &n);


for(i=0;i<M;i++)
    {
     scanf("%s",c);
     for(j=0;j<n;j++) 
     {
//       printf("-%c\n",c[j]);
       if(c[j]=='.') a[i][j] = 0; else a[i][j] = 1;
     }   
     
    }
/*
for(i=0;i<M;i++)
{

 for(j=0;j<n;j++) 
    {
 printf("%lld ",a[i][j]);
    }

printf("\n");
}
*/

for(i=1;i<M;i++)
{
for(j=0;j<=i;j++) b[j] = -1;
 
 for(j=0;j<n;j++)
  {

//printf("%lld =i %lld =j\n",i,j);
//for(m=i-1;m>=0;m--) printf("m=%lld -> %lld\n",m,b[m]);
   k = a[i][j];
   for(m=i-1;m>=0;m--)
     {
       if(a[i][j]) b[m] = -1;
       if(a[m][j] == 1) 
         {
           k = 1;
           b[m] = -1;
           continue;
         }
       if(k==0 && b[m]!=-1) test(i-m,j-b[m]);
       if(k==0 && b[m] == -1) b[m] = j;        
     } 
  }
}
if(v) printf("%lld\n",v);
 else printf("impossible\n");
return 0;
}
9. Equal
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#define lld long long int
#define llu long long unsigned int
int compare(const void * a, const void * b){return *(lld *)a-*(lld *)b;}
long long int readint() {long long int n=0,count=0,counti=0; char c;while(1){c=getchar_unlocked();if(c=='-')count=1;else if((c==' '||c=='\n'||c==EOF) && counti==1)break;else if(c>='0' && c<='9'){counti=1;n=(n<<3)+(n<<1)+c-'0';}}if(count==0)return n;else return -n;}
#define min(a,b)(a>b?b:a)
#define max(a,b)(a<b?b:a)
#define sort(arr,n) qsort(arr,n,sizeof(arr[0]),compare)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define su(n) scanf("%llu",&n)
#define rep(i,start,end) for(i=start; i<end; i++)
#define pdn(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pun(n) printf("%llu\n",n)
#define pd(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define pu(n) printf("%llu",n)
#define pn printf("\n")
#define ps printf(" ")
int main()
{
    int t;
    sd(t);
    while(t--)
    {
        lld n,arr[100009],i,min=10000000000,ansi=1000000000,j;
        sl(n);
        for(i=0;i<n; i++)
        {
            sl(arr[i]);
            if(arr[i]<min)
                min=arr[i];
        }
        for(j=0; j<5; j++)
        {
            lld ans=0;
            for(i=0; i<n; i++)
            {
                lld p=arr[i]-min;
                ans+=(p/5) + (p%5)/2 + (p%5)%2;
            }
            if(ans<ansi)
                ansi=ans;
            min--;
        }
        pln(ansi);
    }
    return 0;
}
10. Knapsack
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int cache[1005];
int main() {
    int i;
    for (i = 1; i < 1005; i++) {
        cache[i] = i / 5 + (i % 5 + 1) / 2;
    }
    int t;
    scanf("%d", &t);
    int nums[10000];
    for (i = 0; i < t; i++) {
        int j, num;
        scanf("%d", &num);
        int min = 1000;
        for (j = 0; j < num; j++) {
            scanf("%d", nums + j);
            min = nums[j] < min ? nums[j]:min;
        }
        int sum[5];
        for (j = 0; j <= 4; j++) {
            sum[j] = 0;
            int k;
            for (k = 0; k < num; k++) {
                sum[j] += cache[nums[k]+j-min];
            }
        }
        int best = sum[0];
        for (j = 1; j <= 4; j++) {
            best = best < sum[j] ? best : sum[j];
        }
        printf("%d\n",best);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
11.Bricks Game
#include <stdio.h>
#include <stdlib.h>
void process(int N,int *b,int *firststep,long long *firstsum,int idx);

int main(){
  int T,N,i,*b,*firststep;
  long long *firstsum;
  b=(int*)malloc(100000*sizeof(int));
  firststep=(int*)malloc(100001*sizeof(int));
  firstsum=(long long*)malloc(100001*sizeof(long long));
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d",b+i);
      firststep[i]=-1;
      firstsum[i]=-1;
    }
    firststep[N]=-1;
    firstsum[N]=-1;
    for(i=N-1;i>=0;i--)
      process(N,b,firststep,firstsum,i);
    printf("%lld\n",firstsum[0]);
  }
  return 0;
}
void process(int N,int *b,int *firststep,long long *firstsum,int idx){
  int step,i,j;
  long long max=-1,sum;
  if(firststep[idx]==-1){
    if(idx>=N){
      firststep[idx]=0;
      firstsum[idx]=0;
    }
    else if(N-idx<4){
      firststep[idx]=N-idx;
      firstsum[idx]=0;
      for(i=idx;i<N;i++)
        firstsum[idx]+=b[i];
    }
    else{
      for(i=1;i<4;i++){
        for(j=0,sum=0;j<i;j++)
          sum+=b[idx+j];
        process(N,b,firststep,firstsum,idx+i);
        process(N,b,firststep,firstsum,idx+i+firststep[idx+i]);
        if(sum+firstsum[idx+i+firststep[idx+i]]>max){
          max=sum+firstsum[idx+i+firststep[idx+i]];
          step=i;
        }
      }
      firststep[idx]=step;
      firstsum[idx]=max;
    }
  }
  return;
}
12.Cut Tree
#include <stdio.h>
#include <stdlib.h>
void dfs(int x,int parent);
int table[50][50]={0},c[50]={0},p[50],q[51]={0},N;
long long dp1[50][51]={0},dp2[50][51]={0},temp[51],ans; // 1 without 2 with [node][K]

int main(){
  int K,x,y,i,j,k;
  scanf("%d%d",&N,&K);
  for(i=0;i<N-1;i++){
    scanf("%d%d",&x,&y);
    table[x-1][y-1]=-1;
    table[y-1][x-1]=-1;
  }
  dfs(0,0);
  for(i=0;i<N;i++)
    if(!c[i])
      q[++q[0]]=i;
  while(q[0]){
    x=q[q[0]--];
    dp1[x][0]=dp2[x][0]=1;
    for(i=0;i<N;i++)
      if(table[x][i]==1){
        for(j=1;j<=K;j++)
          temp[j]=0;
        for(j=1;j<=K;j++){
          dp1[x][j]+=dp1[i][j]+dp2[i][j-1];
          for(k=0;k<=j;k++)
            if(k==1)
              temp[j]+=(dp2[i][k]+1)*dp2[x][j-k];
            else
              temp[j]+=dp2[i][k]*dp2[x][j-k];
        }
        for(j=1;j<=K;j++)
          dp2[x][j]=temp[j];
      }
    if(x){
      c[p[x]]--;
      if(!c[p[x]])
        q[++q[0]]=p[x];
    }
  }
  for(i=0,ans=0;i<=K;i++)
    ans+=dp1[0][i]+dp2[0][i];
  printf("%lld",ans);
  return 0;
}
void dfs(int x,int parent){
  int i;
  p[x]=parent;
  for(i=0;i<N;i++)
    if(table[x][i] && i!=parent){
      table[x][i]+=2;
      c[x]++;
      dfs(i,x);
    }
  return;
}
13.Sam and sub-strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 200001
#define MODULUS 1000000007LL

int main() {
	long long total, multiplier, partialsum;
	char c;
	
	total = partialsum = 0;
	multiplier = 1;
	while (1) {
		c=getchar();
		if (c<'0' || c>'9') break;
		c -= '0';
		partialsum += multiplier * c;
		total = (total * 10 + partialsum) % MODULUS;
		multiplier++;
	}
	
	printf("%lld\n",total);
	return 0;
}
14.The Longest Increasing Subsequence
#include <stdio.h>

int n,a[1000000],b[1000000]; 

int getRight(int *Arr,int left,int right,int value)
{
    int mid;
    while(right>left+1)
    {
        mid=left+(right-left)/2;
        if(Arr[mid]>=value)right=mid;
        else left=mid;
    }
    return right;
}
 
int CalcLIS()
{
    int i,res=1;
    b[0]=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<b[0])
            b[0]=a[i];
        else if(a[i]>b[res-1])
            b[res++]=a[i];
        else
            b[getRight(b,-1,res-1,a[i])]=a[i];
    }
    return res;
}
 
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    printf("%d",CalcLIS());
    return 0;
}
15.Coin on the Table
#include <stdio.h>

#define abs(x) ((x)<0?(-(x)):(x))

#define NMAX 50
#define KMAX 1000
#define BADVAL 1000000

char board[NMAX][NMAX];

int cache[KMAX+1][NMAX][NMAX];
#define CACHEMISS (-3)

// Problem parameters
int N, M, K;

// The end point
int endx, endy;

void flushcache(void)
{
    int i, j, k;

    for (k=0; k<=K; k++)
        for (j=0; j<N; j++)
            for (i=0; i<M; i++)
                cache[k][j][i] = CACHEMISS;
}

// Returns (nchanges + minimum changes to be made in getting from [x,y] to the end
//   in k steps or fewer)
int solve(int x, int y, int k, int nchanges)
{
    char c;
    int km1;
    int iret, imin;

    if (cache[k][y][x]!=CACHEMISS)
        return nchanges + cache[k][y][x];

    // Have we reached the star?
    if (x==endx && y==endy)
        return nchanges;

    imin = BADVAL;
    if (k >= abs(x-endx)+abs(y-endy)) {
        km1 = k-1;
        c = board[y][x];
        if (x < M-1) {
            iret = solve(x+1, y,   km1, nchanges+(c != 'R'));
            if (iret < imin) imin=iret;
        }
        if (y < N-1) {
            iret = solve(x,   y+1, km1, nchanges+(c != 'D'));
            if (iret < imin) imin=iret;
        }
        if (x > 0) {
            iret = solve(x-1, y,   km1, nchanges+(c != 'L'));
            if (iret < imin) imin=iret;
        }
        if (y > 0) {
            iret = solve(x,   y-1, km1, nchanges+(c != 'U'));
            if (iret < imin) imin=iret;
        }
    }

    if (imin<BADVAL)
        cache[k][y][x] = imin - nchanges;

    return imin;
}

int main(void)
{
    int i, j;
    char linein[NMAX+1];
    int ires;

    // Read input
    scanf("%d %d %d", &N, &M, &K);

    for (j=0; j<N; j++) {
        scanf("%s", linein);
        for (i=0; i<M; i++) {
            board[j][i] = linein[i];
            if (linein[i]=='*') {
                endy = j;
                endx = i;
            }
        }
    }

    // Catch trivial solutions
    if ((endx+endy)==0) {
        //  - We are starting on the star
        ires = 0;
    } else if ((endx+endy) > K) {
        //  - We do not have enough moves to reach the star
        ires = -1;
    } else {
        // - Call the solver
        flushcache();
        ires = solve(0, 0, K, 0);
        if (ires == BADVAL) ires = -1;
    }

    printf("%d\n", ires);

    return 0;
}
16.Substring Diff
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1500

int main(void){
  int num_cases;
  int k;
  char string1[MAX_SIZE+1],string2[MAX_SIZE+1];
  char diff_array[MAX_SIZE][MAX_SIZE];
  int length;
  int i;
  //  for(k=0;k<MAX_SIZE;k++)
  //    diff_array[k]=malloc(sizeof(char)*MAX_SIZE);
  
  scanf("%d",&num_cases);
  while(num_cases--){
    scanf("%d %s %s",&k,string1,string2);
    length=strlen(string1);
    
    /* Filling it up */
    int j;
    for(i=0;i<length;i++){
      for(j=0;j<length;j++)
	diff_array[i][j]=(string1[i]!=string2[j]);
    }
    
    int front_pointer,back_ptr1,back_ptr2,front_sum1,front_sum2,curr_max=-1;
    int back_sum1,back_sum2;
    int res_length;
    for(i=0;i<length;i++){
      front_sum1=front_sum2=back_sum1=back_sum2=0;
      back_ptr1=back_ptr2=-1;
      for(front_pointer=0;front_pointer+i<length;front_pointer++){
	front_sum1+=diff_array[front_pointer][i+front_pointer];
	front_sum2+=diff_array[i+front_pointer][front_pointer];
	while(front_sum1-back_sum1>k){
	  back_ptr1++;
	  back_sum1+=diff_array[back_ptr1][i+back_ptr1];
	}
	while(front_sum2-back_sum2>k){
	  back_ptr2++;
	  back_sum2+=diff_array[i+back_ptr2][back_ptr2];
	}
	
	if(front_pointer-back_ptr1>curr_max)
	  curr_max=front_pointer-back_ptr1;
	if(front_pointer-back_ptr2>curr_max)
	  curr_max=front_pointer-back_ptr2;
      }
    }
    
    printf("%d\n",curr_max);
  }
  return 0;
}
17.Xor and Sum
#include <stdio.h>
#include <stdlib.h> 
#define MOD 1000000007
#define s(k) scanf("%d",&k);
#define sll(k) scanf("%lld",&k);
#define p(k) printf("%d\n",k);
#define pll(k) printf("%lld\n",k);
#define f(i,N) for(i=0;i<N;i++)
#define f1(i,N) for(i=0;i<=N;i++)
#define f2(i,N) for(i=1;i<=N;i++)
#define lim 314160
typedef long long ll;
void rev(char* in){
    int start=0,end=strlen(in)-1,i,l=strlen(in);
    char t;
    while(start<end){
        t=in[start];
        in[start]=in[end];
        in[end]=t;
        start++;
        end--;
    }
    for(i=strlen(in);i<lim+l;i++)
        in[i]='0';
}
int main(){
    char A[414160],B[414160];
    int i,num,len;
    ll X,sum,pos;
    scanf("%s",A);
    scanf("%s",B);
    len=strlen(B);
    rev(A);
    rev(B);
    num=0;
    pos=1;
    sum=0;
    for(i=0;i<lim-1;i++){
        if(B[i]=='1')
            num++;
        X=num;
        if(A[i]=='1')
            X=lim-X;
        sum=(sum+X*pos)%MOD;
        pos=(pos<<1)%MOD;
    }
    for(i=0;i<len;i++){
        X=num;
        sum=(sum+X*pos)%MOD;
        pos=(pos<<1)%MOD;
        if(B[i]=='1')
            num--;
    }
    
    pll(sum);
/*    printf("%s\n",A);
    printf("%s\n",B);*/
    return 0;
    
}
18.The Longest Common Subsequence
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int a,int b)
    {
    if(a>b)
        return a;
    else
        return b;
    
}
void longest(int b[],int c[],int m,int n)
    {
    int lcs[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
        {
        for(j=0;j<=n;j++)
            {
            if(i==0||j==0)
                lcs[i][j]=0;
            else if(b[i-1]==c[j-1])
                {
                lcs[i][j]=lcs[i-1][j-1]+1;
                }
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
        
    }
    int index=lcs[m][n];
    int k=index;
    int output[index];
    //printf("index;%d",index);
    i=m;
    j=n;
    while(i>0&&j>0)
        {
        if(b[i-1]==c[j-1])
            {
            output[index-1]=b[i-1];
            j--;
            i--;
            index--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1])
            {
            i--;
        }
        else
            j--;
    }
    
    for(i=0;i<k;i++)
        {
        printf("%d ",output[i]);
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int i;
    int a[2];
    for(i=0;i<2;i++)
        {
        scanf("%d",&a[i]);
    }
    int m=a[0];
    int n=a[1];
    int b[m];
    int c[n];
    
    for(i=0;i<m;i++)
        {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
        {
        scanf("%d",&c[i]);
    }
    longest(b,c,m,n);
    return 0;
}
19.Hexagonal Grid
#include <stdio.h>
#include <stdlib.h>
int dp1[4][2]={{0,3},{2,0},{1,2},{0,0}};
int count[4]={2,1,2,1};
int dp2[4][10],table[10];
void solve(int mask,int row);

int main(){
  int T,N,i,j;
  char str1[11],str2[11];
  scanf("%d",&T);
  while(T--){
    scanf("%d%s%s",&N,str1,str2);
    for(i=0;i<N;i++){
      table[i]=0;
      if(str1[i]-'0')
        table[i]+=1;
      if(str2[i]-'0')
        table[i]+=2;
    }
    for(i=0;i<4;i++)
      for(j=0;j<N;j++)
        dp2[i][j]=-1;
    solve(table[N-1],N-1);
    if(dp2[table[N-1]][N-1])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
void solve(int mask,int row){
  int i;
  if(row==0){
    if(mask==0 || mask==3)
      dp2[mask][row]=1;
    else
      dp2[mask][row]=0;
    return;
  }
  if(row==1){
    for(i=0;i<count[mask];i++){
      if(dp1[mask][i]&table[row-1])
        continue;
      if((dp1[mask][i]|table[row-1])==3 || (dp1[mask][i]|table[row-1])==0){
        dp2[mask][row]=1;
        return;
      }
    }
    dp2[mask][row]=0;
    return;
  }
  for(i=0;i<count[mask];i++){
    if(dp1[mask][i]&table[row-1])
      continue;
    if(dp2[dp1[mask][i]|table[row-1]][row-1]==-1)
      solve(dp1[mask][i]|table[row-1],row-1);
    if(dp2[dp1[mask][i]|table[row-1]][row-1]){
      dp2[mask][row]=1;
      return;
    }
  }
  dp2[mask][row]=0;
  return;
}
20.Square Subsequences
#include<stdio.h>
#include<string.h>
main()
{
    int t,total[30]={0};
    int prevcount[201][201]={0};
    scanf("%d",&t);
    int i,j;
    for(i=0;i<t;++i)
    {
        int count[201][201]={0};
        char string[200];
        scanf("%s",string);
        //total=0;
        int k,l;
        for(j=1;j<strlen(string);++j)
        {
            for(k=0;k<j;++k)
            {
            prevcount[k][j]=0;
                if(string[k]==string[j])
                {
                    count[k][j]=1;
                    //printf("%d %d   %d\n",k+1,j+1,count[k][j]);
                    for(l=k+1;l<j;++l)
                    {
                        int q;
                        for(q=0;q<k;++q)
                        {
                            count[k][l]=(count[k][l]+prevcount[q][l])%1000000007;
                            //if(count[q][l]!=0)
                            //printf("%d %d   %d\n",k+1,l+1,count[k][l]);
                        }
                        
                    }
                }    
            } 
            for(k=0;k<=j;++k)
            {
                for(l=0;l<k;++l)
                {
                    prevcount[l][k]=count[l][k];
                }
            } 
        }
        for(k=0;k<strlen(string);++k)
        {
            for(j=0;j<k;++j)
            {
            total[i]=(total[i]+count[j][k])%1000000007;
            }//printf("%d  %d   %d     %d\n",left[k],link[k],right[k],linkvar);
        }
        
    }
    for(i=0;i<t;++i)
        printf("%d\n",total[i]);
}
21.Sherlock and  cost
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int T,N,B,L,R,ML,MR,X,Y,P,Q;
    scanf("%d",&T);
    for(int i = 0; i < T; i++) {
        scanf("%d",&N);
        for(int j = 0; j < N; j++) {
            scanf("%d",&B);
            if(j) {
                X = L - 1 + ML;
                Y = R - 1 + MR;
                P = abs(L - B) + ML;
                Q = abs(R - B) + MR;
                ML = (X > Y ? X : Y);
                MR = (P > Q ? P : Q);
            } else {
                ML = MR = 0;
            }
            L = 1;
            R = B;
        }
        printf("%d\n", (ML > MR ? ML : MR));
    }
    return 0;
}
22. vertical sticks
#include<stdio.h>
void bubbleSort(int A[], int array_size)
{
  int i, temp;
	int k ;
	for (i = array_size  - 1; i > 0; i--)
	{
		for (k = 0; k < i; k++)
		{
			if (A[k] > A[k+1])
			{
				temp = A[k+1];
				A[k+1] = A[k];
				A[k] = temp;
			}
		}
	}
}


void expVal(int *A, int N)
{
	int i, k, x, rank = 1, same = 0;
	int R[100];
	long double avg = 0;
	bubbleSort (A, N);
	R[0] = rank;
  for (i = 1; i < N; i++) 
	{
		if 	(A[i-1] < A[i]) {
			rank++;
			rank += same;
			same = 0;
		} else {
			same++;
		}
		R[i] = rank;
	}
	for (i = 0; i < N; i++){
			
		for (k = 1; k <= R[i]; k++) 
		{
			long double partAvg ;
			if ((i == (N - 1)) && (R[i] > R[i-1])) 
			{
				partAvg =  (long double)k/N;
			} else {
				partAvg = (long double)k/N * ((long double) (N - R[i] + 1));
			}

			for (x = 1; x <= k - 1; x++)
			{
				partAvg *=  (long double)(R[i] - x)/(N  - x);
			}
			avg += partAvg;
		}
	}
	printf("%.2Lf\n", avg);
}

main()
{
	int Y[100];
	int T, N;
	unsigned int i, p;
	scanf("%d", &T);
	for (i = 0; i < T ; i++)
	{
		scanf("%d", &N);
		for (p = 0; p < N; p++)
		{
			scanf("%d", &Y[p]);
		}
		expVal(Y, N);
	}
}
24.candles counting
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
void get_num(int j,int shift,int *zero,int *one);
void init( int n );
void range_increment( int i, int j, int val, int *tree );
int query( int i, int *tree );
int dp[128][150000];
int H[50000],C[50000],N;
int mask[8]={0,0b1,0b11,0b111,0b1111,0b11111,0b111111,0b1111111};

int main(){
  int N,K,i,j,x,y,max=-1;
  for(i=0;i<128;i++)
    for(j=0;j<150000;j++)
      dp[i][j]=0;
  scanf("%d%d",&N,&K);
  for(i=0;i<N;i++){
    scanf("%d%d",H+i,C+i);
    if(max==-1 || H[i]>max)
      max=H[i];
  }
  init(max);
  for(i=0;i<N;i++){
    if(H[i]!=1)
      for(j=0;j<(1<<(K-1));j++){
        get_num(j,C[i]-1,&x,&y);
        range_increment(H[i],max,query(H[i]-1,&dp[y][0]),&dp[y][0]);
        if(!j)
          range_increment(H[i],max,1,&dp[y][0]);
        else
          range_increment(H[i],max,query(H[i]-1,&dp[x][0]),&dp[y][0]);
      }
    else
      range_increment(H[i],max,1,&dp[1<<(C[i]-1)][0]);
  }
  printf("%d",query(max,&dp[(1<<K)-1][0]));
  return 0;
}
void get_num(int j,int shift,int *zero,int *one){
  int x,y;
  x=((j<<1)&(~mask[shift+1]));
  y=(j&mask[shift]);
  *zero=(x|y);
  *one=((*zero)|(1<<shift));
  return;
}
void init( int n ){
  N = 1;
  while( N < n ) N *= 2;
}
void range_increment( int i, int j, int val, int *tree ){
  for( i += N, j += N; i <= j; i = ( i + 1 ) / 2, j = ( j - 1 ) / 2 )
  {
    if( i % 2 == 1 ) tree[i] = (tree[i] +val)%MOD;
    if( j % 2 == 0 ) tree[j] = (tree[j] +val)%MOD;
  }
}
int query( int i, int *tree ){
  int ans = 0,j;
  for( j = i + N; j; j /= 2 ) ans = (ans+tree[j])%MOD;
  return ans;
}
25. queens on board
/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <stdio.h>

#define P 1000000007

long long J1,j2,j3,b[10],a[60][40][40][40],i,j,k,l,m,n,zzas[40000][3],kkon,zas[40000][3],t,kon,H;
char s[100][100];

void makaj(long long ind, long long level)
{
long long ii,I1,I2,I3;

//printf("%lld=ind %lld=lev\n",ind, level);

if(ind == m)
  {
   I1 = I2 = I3 = 0;
   
//   for(ii=0;ii<m;ii++) printf("%lld ",b[ii]);
//   printf(".. %lld=lev %lld %lld %lld\n",level,b[0],b[1],b[2]);
   
   for(ii=0;ii<m;ii++) 
    {
    if(b[ii]==2)
      {
       if(ii>0 && (J1&(1<<ii)))     I1 += (1<<(ii-1));
       if(j2 & (1<<ii))             I2 += (1<<ii);
       if(ii<m-1 && (j3 & (1<<ii))) I3 += (1<<(ii+1));
      }
    if(b[ii]==3)
      {
       if(ii>0)     I1 += (1<<(ii-1));
                    I2 += (1<<ii);
       if(ii<m-1)   I3 += (1<<(ii+1));
      }  
    }
   
  a[level+1][I1][I2][I3] = (a[level+1][I1][I2][I3] + a[level][J1][j2][j3])%P;
  
  return;
  }

ii = ind;
ii++;
while(ii<m && b[ii]) ii++;
makaj(ii,level);

b[ind]=3;
ii = ind+1;
while(ii<m && b[ii]!=1) ii++;
while(ii<m && b[ii]) ii++;
makaj(ii,level);
b[ind]=0;

return;
}

int main()
{
//L=1;

scanf("%lld",&t);
while(t--)
{
scanf("%lld %lld\n",&n,&m);
for(i=1;i<=n;i++) scanf("%s\n",s[i]);

H = (1<<m);

kon=1;
//c[0][0][0]=L;
a[1][0][0][0]=1;

for(i=1;i<=n;i++)
//i=1;
 {
 for(J1=0;J1<H;J1++)
  for(j2=0;j2<H;j2++)
   for(j3=0;j3<H;j3++) a[i+1][J1][j2][j3]=0;


 for(J1=0;J1<H;J1++)
  for(j2=0;j2<H;j2++)
   for(j3=0;j3<H;j3++)
    if(a[i][J1][j2][j3]!=0)
  {
    for(l=0;l<m;l++) b[l] = 0;
    for(l=0;l<m;l++) 
      {  
      if(s[i][l]=='#') b[l] = 1;
      if(b[l]==0 && ((J1&(1<<l)) ||(j2&(1<<l)) ||(j3&(1<<l))))  b[l]=2;
      }
   k=0;
   while(k<m && b[k]) k++;
    makaj(k,i);
 
  }
 }

m=0;
 for(J1=0;J1<H;J1++)
  for(j2=0;j2<H;j2++)
   for(j3=0;j3<H;j3++)
     m = (m+a[n+1][J1][j2][j3])%P;

printf("%lld\n",(m+P-1)%P);

//t=0;
//L++;
}


return 0;
}
26. hyper strings
/* Enter your code here. Read input from STDIN. Print output to STDOUT */#define __int64 long long
#include <string.h>
typedef unsigned char byte;

byte len[200]={0};
char strings[200][100]={0};
__int64 count[200]={0};
int n,m;

int reduce(char* src,int ind)
{
	int i;
	for (i=0;i<n;i++)
	{
		if(len[i]!=0&&i!=ind&&strlen(src)>=len[i]&&strncmp(src,strings[i],len[i])==0)
		{
			
			if (*(src+len[i])!='\0')
			{
				if (reduce(src+len[i],ind)==0)
				{
					return 0;
				}		
			}
			else
			{
				len[ind]=0;
				return 0;
			}
			
		}
	}
	return 1;

}


int main()
{
	int i,j,k;
	scanf("%d %d",&n,&m);
for (i=0;i<n;i++)
{
	scanf("%s",strings[i]);
	len[i]=strlen(strings[i]);
}

for (i=0;i<n;i++)
{
	reduce(strings[i],i);
	//printf("%d",len[i]);
}

count[0]=1;

for(i=1;i<=m;i++)
{
	for (j=0;j<i;j++)
	{
		int tmp=0;
		if (count[j]!=0)
		{
			for (k=0;k<n;k++)
			{
				if (len[k]!=0&&j+len[k]==i)
				{
					tmp++;
				}
			}
			count[i]+=((count[j]*tmp)%1000000007);
			count[i]%=1000000007;
		}

	}

}

for (i=1;i<=m;i++)
{
	count[0]+=count[i];
//	printf("%d",count[i]);
	count[0]%=1000000007;
}
printf("%lld",count[0]);
	return 0;

}
27. points in a plane
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

// Test whether a/b==c/d using only integers
#define eqratio(a, b, c, d) ((a)*(d)==(b)*(c))

#define MOD 1000000007
#define MAXPOINTS 16
#define MAXCOMBS (1<<MAXPOINTS)

typedef unsigned int Reg;
typedef unsigned long long Big;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int remove;
    int nways;
} Result;

int T, N;

// For storing the points
Point p[MAXPOINTS];

// For storing points/lines that can be removed at any turn
Reg lines[MAXCOMBS];
int lineidx;
int longlinecount;

int factorial[(MAXPOINTS+3)/2];
int oddfac[(MAXPOINTS+3)/2];

// Min number of lines removed
int globalmin;

int cmp(const void *ip, const void *jp)
{
    return __builtin_popcount(*(unsigned int *)jp) - __builtin_popcount(*(unsigned int *)ip);
}

#if DEBUG
void printbin(Reg i, int n)
{
    int j;
    for (j=0; j<n; j++) {
        printf("%s", (i%2)?"1":"0");
        i >>= 1;
    }
}
#endif

Result rempoints(Reg reg, int n, int idx)
{
    int i;
    int minremove, nways;
    Result res, ret;
    int tmp;

    // We've removed all the points
    if (reg==0) {
        // Keep track of the minimum number of lines removed
        if (n < globalmin)
            globalmin = n;
        res.remove = n;
        res.nways  = 1;
        return res;
    }

    // Bail out early if we have already removed too many lines
    if (n>=globalmin) {
        res.remove = N; // dummy large value
        res.nways  = 0;
        return res;
    }

    // Baseline: truncate here and just remove all remaining points in pairs
    tmp = (1 + __builtin_popcount(reg))/2;
    minremove = n + tmp;
    nways  = oddfac[tmp];

    // Now try removing more lines and see if we can do better
    for (i=idx; i<longlinecount; i++) {
        if ((reg|lines[i]) == reg) {
            ret = rempoints(reg^lines[i], n+1, i+1);

            if (ret.remove<minremove) {
                minremove = ret.remove;
                nways = 0;
            }
            if (ret.remove == minremove)
                nways = (nways + ret.nways)%MOD;
        }
    }

    res.remove = minremove;
    res.nways  = nways;
    return res;
}

void addpoints(Reg reg, int thispoint, int npoints)
{
    int p0, p1;
    int dx0, dy0, dx1, dy1;

    if (thispoint==N)
        return;

    // A zero in this place
    addpoints(reg, thispoint+1, npoints);

    // Maybe a one in this place
    if (npoints < 2) {

        reg |= 1<<thispoint;
        lines[lineidx++] = reg;
        addpoints(reg, thispoint+1, npoints+1);

    } else {

        // Find two points already on the line we are considering
        p0 = __builtin_ctz(reg);
        p1 = __builtin_ctz((1<<p0)^reg);

        dx0 = p[p0].x        - p[p1].x;
        dy0 = p[p0].y        - p[p1].y;
        dx1 = p[thispoint].x - p[p0].x;
        dy1 = p[thispoint].y - p[p0].y;

        // If the point is co-linear with the ones we have, then add it
        if (eqratio(dx1, dy1, dx0, dy0)) {
            reg |= 1<<thispoint;
            lines[lineidx++] = reg;
            ++longlinecount;
            addpoints(reg, thispoint+1, npoints+1);
        }
    }
}

int main()
{
    int i;
    int x, y;
    Result ret;

    factorial[0] = 1;
    oddfac[0]    = 1;
    for (i=1; i<=(MAXPOINTS+1)/2; i++) {
        factorial[i] = ((Big)i*(Big)factorial[i-1])%MOD;
        oddfac[i] = ((Big)(2*i-1)*(Big)oddfac[i-1])%MOD;
    }

    scanf("%d\n", &T);

    while (T--) {

        scanf("%d\n", &N);
        for (i=0; i<N; i++) {
            scanf("%d %d\n", &x, &y);
            p[i].x = x;
            p[i].y = y;
        }

        // Find the lines
        lineidx       = 0;
        longlinecount = 0;
        addpoints(0, 0, 0);

        // Lazy but effective...
        qsort((void *)lines, (size_t)lineidx, sizeof(lines[0]), &cmp);

        // Remove lines and find the minimum and number of ways
        globalmin = N;
        ret = rempoints((1<<N)-1, 0, 0);

        printf("%d %d\n", ret.remove, (int)(((Big)ret.nways*(Big)factorial[ret.remove])%MOD));

#if DEBUG
        //for (i=0; i<lineidx; i++) {
        for (i=0; i<longlinecount; i++) {
            printf("%d :\t", i);
            printbin(lines[i], N);
            printf("\n");
        }
#endif

    }

    return 0;
}
28. angry children 2
#include<stdio.h>
#define Mx 100000
long long tree[Mx<<1][3];
int N,K,i,j;
long long arr[Mx+9];
long long L[2],R[2],T[2],lsum,rsum,a,res=9223372036854775807LL;
long long Min(long long g,long long gg){return g<gg?g:gg;}

void update(int idx ,long long t,long long l,long long r){while (idx <= N)tree[idx][0] += t,tree[idx][1] += l,tree[idx][2] += r,idx += (idx & -idx);}
void query(int idx,int f){while (idx > 0)T[f]+=tree[idx][0],L[f]+=tree[idx][1],R[f]+=tree[idx][2],idx -= (idx & -idx);}
long long comp (const void * a, const void * b){return ( *(long long *)a - *(long long *)b );}
int main()
{
    scanf("%d %d",&N,&K);
    for(i=1; i<=N; i++)scanf("%lld",&arr[i]);
    qsort(arr+1,N,sizeof(long long int),comp);
    for(i=1; i<=N; i++)update(i,arr[i],i*arr[i],(N-i)*arr[i]);
    for(i=K; i<=N; i++)
    {
        for(j=0; j<2; j++)L[j]=R[j]=T[j]=0;
        query(i,0),query(i-K,1);
        lsum=(L[0]-L[1])-((i-K+1)*(T[0]-T[1])),rsum=(R[0]-R[1])-((N-i)*(T[0]-T[1]));
        res=Min(res,lsum-rsum);
    }
    printf("%lld\n",res);
}
29. play with words
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int L[3100][3100],cntt[30][3100];

int max(int a,int b)
    {
    if(a<b)
        {
        return b;
    }
    return a;
}

int main() {
    char str[4000],c;
    int i,j,t,l,cl;
    scanf("%s",str);
    l=strlen(str);
    for(i=0;i<l;i++)
        {
        L[i][i]=1;
    }
    for (cl=2; cl<=l; cl++)
    {
        for (i=0; i<l-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    int mx=0;
    for(i=0;i<l;i++)
        {
        if((L[0][i]*L[i+1][l-1])>mx)
            {
            mx=(L[0][i]*L[i+1][l-1]);
        }
    }
    printf("%d\n",mx);
    return 0;
}
30. alien languages
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

int main() {

    int tpm, nbtest,nb,profondeur,i,j,tot,deb,*facteur,*list,*previous,*next,*tmp,mod=100000007,flnb_2,flnb_2p1,out;
    scanf("%d", &nbtest);
    
    while(nbtest>0){
        nbtest--;
        scanf("%d %d", &nb,&profondeur);
        
        facteur=(int*) calloc(profondeur,sizeof(int));
        list=(int*) calloc(profondeur,sizeof(int));
        previous=(int*) calloc(nb+1,sizeof(int));
        next=(int*) calloc(nb+1,sizeof(int));

        flnb_2=floor(nb/2);
        flnb_2p1=flnb_2+1;
        out=0;
        for(i=1;i<=nb;i++){
            previous[i]=1;  
        }
        tot=nb-flnb_2;
        
        for(j=1;j<profondeur;j++){
            
            list[j]=tot;
            next[1]=tot;

            //printf("\n");
            //printf("\n");
            
            for(i=1;i<=j-1;i++){
                //printf("tot => %d - %d x %d ",tot ,facteur[i],list[j-i]);
            tot-=((long long)facteur[i]*(long long)list[j-i])%mod;
                if(tot<0){
                tot+=mod;
                }
                //printf(" => %d",tot);
            }
            
            //printf("\n");
            //printf("\n");
            if(tot>0){
            facteur[j]=tot;
            } else {
                out=1;
               /* 
                printf("\n"); printf("\n");
                for(i=1;i<j;i++){
                    printf("%d ",facteur[i]);
                }
                printf("\n");
                for(i=1;i<j;i++){
                   printf("%d ",list[i]);
                }
                printf("out");*/
                break;
            }
            tot=0;
            
            
            
            for(i=2;i<flnb_2p1;i=i+2){
                next[i]=(next[i-1]+previous[i>>1])%mod;
                next[i+1]=next[i];
            }
            
            if(flnb_2p1&1){
                deb=1;
                tot=(tot+next[flnb_2p1])%mod;
            } else {
                deb=0;
            }
            
            for(i=flnb_2p1+deb;i<=nb;i=i+2){
                next[i]=(next[i-1]+previous[i>>1])%mod;
   
                if(i+1<=nb){
                    next[i+1]=next[i]%mod;
                    tot=(tot+2*next[i])%mod;
                } else {
                    tot=(tot+next[i])%mod;
                }
            }
            //for(i=1;i<=nb;i=i+1){printf("%d\t",next[i]);}
            //printf("\n\n");
            tmp=previous;
            previous=next;
            next=tmp;
        }
        if(out&1){
            for(i=j+1;i<=profondeur;i++){
                list[i]=0;
                for(int k=1;k<=j;k++){
                    
                    tot=((long long)facteur[k]*(long long)list[i-k])%mod;
                    //printf("Tot: %d %d => %d + %d\n",facteur[k],list[i-k],tot,list[i]);
                list[i]=(list[i]+tot)%mod;
                
                }
            }
            tot=list[i-1];
        
        }
       
        printf("%d\n", tot);
    }   
    return 0;
}
31. unfair Game

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXN (15)
#define MAXS (1<<MAXN)
#define MAXBIT (32)

#define bool char
#define true (1)
#define false (0)

#define TAKE(v,i) (((v)>>(i))&1)
#define REPLACE(a,i,b) (((a)&~(1<<(i)))|((b)<<(i)))

//#define DEBUG

#define value unsigned int
//#define INFI 0x7f7f7f7f7f7f7f7f
//#define NONE 0
#define NONE 0x7f7f7f7f

inline void update( value* pa, value b ){
    if ( (*pa > b) )
        *pa = b;
}

int n;
int v[MAXN];

value f[2][MAXS][2];

value dp(){
    int max_bit;

    for( max_bit = 0; max_bit < 31 ; max_bit++ ){
        bool has = 0;
        int j;
        for( j = 0; j < n; j++ )
            if ( (v[j] >> max_bit) )
                has = true;
        if ( ! has ) 
            break;
    }

//    assert(max_bit < MAXBIT );
    
    int maxs = 1 << n;
    

    int curr = 0, next = 1;
    memset(f,0x7f,sizeof(f));
    f[0][0][0] = 0;

    max_bit += 1; // XXX enough?
    
    int i;
    for( i = 0; i < max_bit; i++ ){
        // more bit for overflow
        int j,s,xor_sum;
        for( j = 0; j < n; j++ ){
            int part2 = TAKE(v[j],i);
            for( s = 0; s < maxs; s++ ){
                int part1 = TAKE(s,j);
                int s_ = s&~(1<<j);
                for( xor_sum = 0; xor_sum < 2; xor_sum++ ) 
                    if( f[curr][s][xor_sum] != NONE ){
//                        printf("f(%d,%d,%d,%d) = %u\n", i,j,s,xor_sum,f[curr][s][xor_sum]);
//                        int c;
//                        for( c = 0; c < 2; c++ ){

                            int next_bit = part1 + part2;
                            int next_bit_low = next_bit & 1;
                            int next_bit_high = next_bit >> 1;
                            int next_xor_sum = xor_sum ^ next_bit_low;
                            int next_s = s_|(next_bit_high<<j);
                            value* pnf = &f[next][next_s][next_xor_sum];
                            value vnf = f[curr][s][xor_sum];
                            *pnf = *pnf>vnf?vnf:*pnf;

                            int next2_bit = next_bit + 1;
                            int next2_bit_low = next2_bit & 1;
                            int next2_bit_high = next2_bit >> 1;
                            int next2_xor_sum = xor_sum ^ next2_bit_low;
                            int next2_s = s_|(next2_bit_high<<j);
                            value* pn2f = &f[next][next2_s][next2_xor_sum];
                            value vn2f = vnf + (((value)1)<<i);
                            *pn2f = *pn2f>vn2f?vn2f:*pn2f;

//                        }
                        f[curr][s][xor_sum] = NONE;
                        }       
            }
            curr ^= 1;
            next ^= 1;
//            memset(f[next],0x7f,sizeof(f[next]));
        }

        /*
        memset(f[next],0x7f,sizeof(f[next]));
        for( s = 0; s < maxs; s++ )
            f[next][s][0] = f[curr][s][0];
        curr ^= 1;
        next ^= 1;
        */
        for( s = 0; s < maxs; s++ )
            f[curr][s][1] = NONE;
 
        //memset(f[next],0x7f,sizeof(f[next]));

    }

 
    value ans = f[curr][0][0];
//    assert(ans != NONE );
    return ans;
}

int main(){
    int t, test;
    scanf("%d",&test);
    for( t = 0; t < test; t++ ){
        int i;
        
        scanf("%d",&n);
        for( i = 0; i < n; i++ )
            scanf("%d", v+i);

        value result = dp();

//        printf("%d\n",result);
        //printf("%lld\n",result);
        printf("%u\n",result);
    }
    return 0;
}
32. brick tiling
/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <stdio.h>

#define P 1000000007LL

char ss[30][30];
long long a[22][70000],t,tt,i,j,k,l,m,n,b[3][20],M,ii,jj;
long long s[30][30];

void makaj(long long ind, long long xx, long long x1, long long y1,
 long long x2, long long y2, long long x3, long long y3)
{
long long iii,jjj;

if(xx+x1>=m || xx+x1<0 || b[y1][xx+x1]) return;
if(xx+x2>=m || xx+x2<0 || b[y2][xx+x2]) return;
if(xx+x3>=m || xx+x3<0 || b[y3][xx+x3]) return;

b[0][xx]=1;
b[y1][xx+x1] = 1;
b[y2][xx+x2] = 1;
b[y3][xx+x3] = 1;

//printf("%lld=ind %lld=xx\n",ind,xx);

/*
for(iii=0;iii<m;iii++) printf("%lld",b[2][iii]);
printf("\n");
for(iii=0;iii<m;iii++) printf("%lld",b[1][iii]);
printf("\n");
for(iii=0;iii<m;iii++) printf("%lld",b[0][iii]);
printf("\n");
*/

iii=xx+1;

while(iii<m && b[0][iii]) iii++;

if(iii==m)
{

jjj=0;

for(iii=m-1;iii>=0;iii--) jjj= 2*jjj+b[2][iii];
for(iii=m-1;iii>=0;iii--) jjj= 2*jjj+b[1][iii];

//printf("ukladam1 %lld\n",jjj);

a[ind][jjj]= (a[ind][jjj]+a[ind-1][j])%P;

//printf("ukladam1 %lld=jj %lld=ind %lld=hodn\n",jjj,ind,a[ind][jjj]);


}
else
{
//printf("!!!%lld=ind\n",ind);

makaj(ind,iii,1,0,1,1,1,2);
makaj(ind,iii,1,0,0,1,0,2);
makaj(ind,iii,0,1,0,2,-1,2);
makaj(ind,iii,0,1,0,2,1,2);
makaj(ind,iii,0,1,-1,1,-2,1);
makaj(ind,iii,0,1,1,1,2,1);
makaj(ind,iii,1,0,2,0,2,1);
makaj(ind,iii,1,0,2,0,0,1);
}

b[0][xx]=0;
b[y1][xx+x1] = 0;
b[y2][xx+x2] = 0;
b[y3][xx+x3] = 0;


return;
}


int main()
{

scanf("%lld", &t);
for(tt=0;tt<t;tt++)
{

scanf("%lld %lld\n",&n,&m);
for(i=0;i<n;i++) scanf("%s\n",ss[i]);

//printf("%s\n",ss[1]);

k=0;

if(n==1)
 {
 for(j=0;j<m;j++) if(ss[0][j]=='.') k=1;

 if(k) printf("0\n"); else printf("1\n");

 continue;
 }

for(i=0;i<n;i++)
 for(j=0;j<m;j++)
   if(ss[i][j]=='.') s[i][j]=0; else s[i][j]=1;

for(j=0;j<m;j++) s[n][j]=0;

M = (1<<(2*m));

for(i=0;i<n;i++)
 for(j=0;j<M;j++) a[i][j]=0;

j=0;
for(i=m-1;i>=0;i--) j= 2*j+s[1][i];
for(i=m-1;i>=0;i--) j= 2*j+s[0][i];

a[0][j]=1;

//printf("%lld==zaciaa\n",j);

for(i=1;i<n;i++)
 for(j=0;j<M;j++)
  if(a[i-1][j])
    {
//printf("j=%lld i=%lldna zac..\n",j,i);



    jj=j;
    for(ii=0;ii<m;ii++)
     {
     b[0][ii] = (jj&1);
     jj/=2;
     }

//printf("i=%lld na zac..\n",i);


    for(ii=0;ii<m;ii++)
     {
     b[1][ii] = (jj&1);
     jj/=2;
     }

//printf("i=%lld na zac..\n",i);


    for(ii=0;ii<m;ii++)
      b[2][ii] = (long long)(s[i+1][ii]);

//printf("i=%lld na zac..\n",i);

//for(l=0;l<m;l++) printf("bb %lld %lld\n",b[2][l],(long long)s[2][l]);


ii=0;
while(ii<m && b[0][ii]) ii++;

//printf("i=%lld na zac\n",i);

if(ii<m)
{
//printf("%lld=i!!\n",i);

makaj(i,ii,1,0,1,1,1,2);
makaj(i,ii,1,0,0,1,0,2);
makaj(i,ii,0,1,0,2,-1,2);
makaj(i,ii,0,1,0,2,1,2);
makaj(i,ii,0,1,-1,1,-2,1);
makaj(i,ii,0,1,1,1,2,1);
makaj(i,ii,1,0,2,0,2,1);
makaj(i,ii,1,0,2,0,0,1);
}
else
 {
 jj=0;

for(ii=m-1;ii>=0;ii--) jj= 2*jj+b[2][ii];
for(ii=m-1;ii>=0;ii--) jj= 2*jj+b[1][ii];

//printf("ukladam2 %lld=jj %lld=i\n",jj,i);

//printf("%lld = nove\n",a[i][jj]);

   a[i][jj]= (a[i][jj]+a[i-1][j])%P;

//printf("%lld = nove\n",a[i][jj]);
 }

//for(l=0;l<M;l++)
// if(a[2][l]) printf("%lld-> %lld\n",l,a[2][l]);
}

printf("%lld\n",a[n-1][(1<<m)-1]);

//return 0;
}


return 0;
}
33. the indian job
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int **bin, *arr, flag=0, sum=0, i=0, j, n, n1, ans1=0, ans2=0, b=0, t;
    scanf("%d", &t);
    while (t--)
    {
        //printf("Enter the length of the string of numbers\n");
        scanf("%d", &n);
        scanf("%d", &b);
        n1=n;
        arr=(int *)malloc(n*sizeof(int));
        while (i<n1)
        {
            scanf("%d", &arr[i]);
            i++;
        }
        bin=(int **)malloc((n+1)*sizeof(int *));
        sum=b;
        for (i=0; i<=n; i++)
        {
            bin[i]=(int *)malloc((sum+1)*sizeof(int));
        }
        bin[0][0]=1;
        for (i=1; i<=sum; i++)
        {
            bin[0][i]=0;
        }
        for (i=0; i<=n; i++)
        {
            bin[i][0]=1;
        }
        for (i=1; i<=n; i++)
        {
            for (j=1; j<=sum; j++)
            {
                if (j<arr[i-1])
                {
                    bin[i][j]=bin[i-1][j];
                }
                else if(j==arr[i-1])
                {
                    bin[i][j]=1;
                }
                else
                {
                    if (bin[i-1][j]==1 || bin[i-1][j-arr[i-1]]==1)
                    {
                        bin[i][j]=1;
                    }
                    else
                        bin[i][j]=0;
                }
            }
        }
        /*printf("The array is:\n");
        for (i=0; i<=n; i++)
        {
            for (j=0; j<=sum; j++)
            {
                printf("%d ", bin[i][j]);
            }
            printf("\n");
        }*/
        //printf("1st array is:\n");
        for (i=sum; i>=1; )
        {
            for (j=1; j<=n; j++)
            {
                if (bin[j][i]==1)
                {
                    ans1+=arr[j-1];
                    //printf("%d ", arr[j-1]);
                    i-=arr[j-1];
                    arr[j-1]=-1;
                    flag=1;
                    break;
                }
            }
            if (flag!=1)
            {
                i--;
            }
            else
            {
                flag=0;
            }
        }
        //printf("\n2nd array is:\n");
        for (i=0; i<n; i++)
        {
            if (arr[i]!=-1)
            {
                ans2+=arr[i];
                //printf("%d ", arr[i]);
            }
        }
        if (ans1<=b && ans2<=b)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        free(arr);
        free(bin);
        flag=sum=i=j=n=n1=ans1=ans2=b=0;
    }
    return 0;
}
34. oil well
#include <stdio.h>

int a[55][55][55][55],b[55][55],t,i,j,k,l,m,n,r,c,dy,dx;
int z[55][55][55],v[55][55][55],u;

int main()
{

scanf("%d %d", &r, &c);

for(i=0;i<r;i++)
 for(j=0;j<c;j++)
  scanf("%d",&b[i][j]);

for(i=0;i<c;i++)
 for(j=0;j<r;j++)
 {
   z[j][j][i] = b[j][i];
   for(k=j+1;k<r;k++) z[j][k][i] = z[j][k-1][i] + b[k][i]; 
 }

for(i=0;i<r;i++)
 for(j=0;j<c;j++)
 {
   v[i][j][j] = b[i][j];
   for(k=j+1;k<c;k++) v[i][j][k] = v[i][j][k-1] + b[i][k]; 
 }


u = -1;

for(dy=0;dy<r;dy++) 
 for(dx=0;dx<c;dx++)
  for(i=0;i+dy<r;i++)
   for(j=0;j+dx<c;j++)

    {
      k = i+dy;
      l = j+dx;
    
       m = 2000000000; 
    
      if(k==i && l==j) m = 0;
    
      if(k-i >= l-j && k-i > 0)
       {
         t = a[i+1][j][k][l];  
         if(v[k][j][l]) 
           {
            t +=  v[i][j][l]*(k-i);
            if(t<m) m = t;
           }

         t = a[i][j][k-1][l];  
         if(v[i][j][l]) 
           {
            t +=  v[k][j][l]*(k-i);
            if(t<m) m = t;       
           }
       }    
    
//    printf("prve m %d\n",m);
    
      if(k-i <= l-j && l-j > 0)
       {
         t = a[i][j+1][k][l];  
         if(z[i][k][l]) 
          {
           t +=  z[i][k][j]*(l-j);
           if(t<m) m = t;
          }

         t = a[i][j][k][l-1];  
         if(z[i][k][j]) 
          {
           t +=  z[i][k][l]*(l-j);
           if(t<m) m = t;       
          }
       }    
    
      a[i][j][k][l] = m;    
   
   if(m!=2000000000 && m > u) u = m;
       }  

if(u<0) u = 0;

printf("%d\n",u);

return 0;
}
35. interval selection
/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <stdio.h>
#include <stdlib.h>

long long v,zas[1100],d[3000][3],ii,jj,kk,s[10000][2],aa[1100],a[1100][1100],i,j,k,l,m,n,t,tt;


int com(const void*x, const void *y)
{
long long *xx,*yy;

xx = (long long *)x;
yy = (long long *)y; 

if(xx[0]>yy[0]) return 1;
if(xx[0]==yy[0] && xx[2]==1) return 1; 
  
return -1;
}

int main()
{

scanf("%lld",&t);
for(tt=0;tt<t;tt++)
 {
 scanf("%lld",&n);
 for(i=0;i<n;i++) scanf("%lld %lld", &s[i][0], &s[i][1]);


// s[0][0] = -5; 
// s[0][1] = -1;
  
 
// for(i=0;i<n;i++)
//  for(j=0;j<n;j++) a[i][j] =0;

  
 for(i=0;i<n;i++) 
    {
     d[2*i][0]=s[i][0];
     d[2*i][1]=i;
     d[2*i][2]=0;
     
     d[2*i+1][0]=s[i][1];
     d[2*i+1][1]=i;
     d[2*i+1][2]=1; 
    }
 
 qsort(d,n*2,sizeof(d[0]),com);

l=0;
m=0;
v=0;

for(i=0;i<2*n;i++)
  {
   ii = d[i][1];
  
   if(d[i][2]==0)
     {
    for(j=0;j<l;j++) 
       {
       a[ii][zas[j]] = a[zas[j]][ii] = aa[zas[j]]+1;
       if(a[ii][zas[j]]>v) v = a[ii][zas[j]];
       }
    
     zas[l] = ii;
     l++;
     aa[ii] = m+1;   
     if(aa[ii]>v) v = aa[ii];
     }
   else
     {
     if(aa[ii]>m) m=aa[ii];	
     
     j=0;
     while(zas[j]!=ii) j++;
     l--;
     zas[j] = zas[l];
     
     for(j=0;j<l;j++) 
        if(a[ii][zas[j]] > aa[zas[j]]) 
                 aa[zas[j]] = a[ii][zas[j]];
     }  
  }

//for(i=0;i<n;i++)for(j=0;j<n;j++) printf("%lld %lld -> %lld\n",i,j,a[i][j]);

//for(i=0;i<n;i++) printf("%lld -> %lld\n",i,aa[i]);

printf("%lld\n",v);

//for(i=0;i<2*n;i++) printf("%lld %lld %lld\n",d[i][0],d[i][1],d[i][2]);

}


return 0;
}
36. string reduction
#include <stdio.h>
#include <string.h>

int min( int a, int b ) { return a < b ? a : b; }

int T, n;
char s[ 105 ];

int a[ 105 ][ 105 ];
int b[ 105 ][ 105 ];
int c[ 105 ][ 105 ];
int f[ 105 ][ 105 ];

int len, i, l, r, m;

int main()
{
  scanf( "%d", &T );
  
  while( T-- ) {
    scanf( "%s", s );
    n = strlen( s );

    for( i = 0; i < n; ++i ) {
      if( s[i] == 'a' ) a[i][i] = 1; else a[i][i] = 0;
      if( s[i] == 'b' ) b[i][i] = 1; else b[i][i] = 0;
      if( s[i] == 'c' ) c[i][i] = 1; else c[i][i] = 0;
      f[i][i] = 1;
    }
    
    for( len = 2; len <= n; ++len ) {
      for( l = 0; l+len <= n; ++l ) {
        r = l + len - 1;
        
        f[l][r] = f[l][r-1]+1;
        a[l][r] = b[l][r] = c[l][r] = 0;
        
        for( m = l; m < r; ++m ) {
          c[l][r] |= ( a[l][m] && b[m+1][r] || b[l][m] && a[m+1][r] );
          b[l][r] |= ( a[l][m] && c[m+1][r] || c[l][m] && a[m+1][r] );
          a[l][r] |= ( c[l][m] && b[m+1][r] || b[l][m] && c[m+1][r] );
          f[l][r] |= min( f[l][r], f[l][m] + f[m+1][r] );
        }

        
        if( a[l][r] || b[l][r] || c[l][r] ) f[l][r] = 1;
      }
    }
    
    printf( "%d\n", f[0][n-1] );
  }  

  return 0;
}
37. far vertices
/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <stdio.h>

long long b[1000],a[1000][1000],i,j,k,l,m,n,t,K;


long long makaj(long long ii, long long jj, long long hh)
{
long long vv=0,tt;

for(tt=0;tt<n;tt++)
 {
  if(a[tt][jj]<a[tt][ii] && a[tt][ii]<=hh) vv++; 
  if(a[tt][jj]>a[tt][ii] && a[tt][ii]<=K-hh) vv++;
 }

return vv;
} 


int main()
{

scanf("%lld %lld\n",&n,&K);

for(i=0;i<n;i++)
 for(j=0;j<n;j++) a[i][j] = 100000000;

for(i=0;i<n;i++) a[i][i]=0;

for(i=0;i<n-1;i++)
{
 scanf("%lld %lld",&j,&l);
 a[j-1][l-1]=1;
 a[l-1][j-1]=1;
}

  for(k=0;k<n;k++)
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
   if(a[i][j]> a[i][k] + a[k][j]) 
     {
     a[i][j] = a[j][i] = a[i][k]+a[k][j];
     }

m = 100000;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(a[i][j]==1)
       {
       for(l=K;l>=(K+1)/2;l--)
       k = makaj(i,j,l);
       if(n-k<m) m = n-k;       
       }



printf("%lld\n",m);

return 0;
}
38. find the seed
#include <math.h>
#include <stdio.h>
#include <string.h>


#define maxn (110)
//const long long mod = 5;
long long mod = 1000000007;

long long n, k, result;
long long ca, cb;
long long tmp;
long long v[maxn], c[maxn], v2[maxn];
long long m[maxn][maxn];
long long res[2][maxn][maxn];

void solve(long long x, long long y) {
    if (y == 0) {//x==1
		//if (x != 1) printf("NO"); 
        ca = 1;
        cb = 0;
        return;   
    }
    solve(y, x % y);
    tmp = x / y;
    tmp = ca - tmp * cb;
    tmp = ((tmp % mod) + mod) % mod;
    ca = cb;
    cb = tmp;
}

inline long long getI(long long now) {
    solve(now, mod);
    return ca;
}

inline void getM() {
    memset(m, 0, sizeof(m));
    for (int i = 1; i < n; ++i) m[i - 1][i] = 1;
    long long cn = getI(c[n - 1]);
    m[n - 1][0] = cn;
    for (int i = 1; i < n; ++i) {
        tmp = -cn * c[i - 1];
        tmp = ((tmp % mod) + mod) % mod;
        m[n - 1][i] = tmp;
    }
}

void multiM(long long C[maxn][maxn], long long A[maxn][maxn], long long B[maxn][maxn]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            tmp = 0;
            for (int k = 0; k < n; ++k) tmp = (tmp + A[i][k] * B[k][j]) % mod;
            C[i][j] = tmp;
        }
}

void printM(long long m[maxn][maxn]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf(" %lld", m[i][j]);
        printf("\n");
    }
}

void calcM(long long po) {
    if (po == 0) return;
    calcM(po >> 1);
    multiM(res[result ^ 1], res[result], res[result]);
    result ^= 1;
    if (po & 1) {
        multiM(res[result ^ 1], res[result], m);
        result ^= 1;
    }
    //printf("%d", po);
    //printM(res[result]);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    

    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%lld", v + i);
    for (int i = 0; i < n; ++i) scanf("%lld", c + i);
    
    getM();
    //printM(m);
    memset(res, 0, sizeof(res));
    result = 0;
    for (int i = 0; i < n; ++i) res[0][i][i] = 1;
    calcM(k - n + 1);
    //printM(res[result]);
    
    for (int i = 0; i < n; ++i) {
        tmp = 0;
        for (int j = 0; j < n; ++j) tmp = (tmp + res[result][i][j] * v[j]) % mod;
        v2[i] = tmp;
    }
    printf("%lld", v2[0]);
    for (int i = 1; i < n; ++i) printf(" %lld", v2[i]);
    
    return 0;
}
39. the blacklist
#include<stdio.h>
#include<limits.h>
#define MIN(x,y) x<y?x:y
int res,n,k,a[15][25]={0};
void find(int curr,int d[],int i,int sumsofar)
{

        //printf("here %d %d %d %d\n",curr,i,sumsofar,res);
    if(sumsofar>=res)
    return;
    if(curr>n)
    {
        res=sumsofar;
        return;
    }
    int p[25],x=0;

    //find(curr+1,d,i,sumsofar+a[i][curr]);
    int j,l;
    for(j=1;j<=k;j++)
    if(d[j]==0)
    p[x++]=j;
    for(l=curr;l<=n;l++)
    {
        for(j=0;j<x;j++)
        if(sumsofar+a[p[j]][l]<sumsofar+a[i][l] && sumsofar+a[p[j]][l]<res)
        {
           // printf("here also %d %d\n",p[j],i);
            d[p[j]]=1;
            find(l+1,d,p[j],sumsofar+a[p[j]][l]);
            d[p[j]]=0;
        }
        sumsofar+=a[i][l];
        if(sumsofar>=res)
        return;
    }
    res=sumsofar;
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    /*for(i=1;i<=k;i++)
    {for(j=1;j<=n;j++)
    {
        b[i][j]=b[i][j-1]+a[i][j];
        //if(i!=1)
        for(j1=1;j1<=i;j1++)
        b[i][j]=MIN(b[i][j],(b[j1][j-1]+a[i][j]));
      //  printf("%d ",b[i][j]);
    }
   // printf("\n");
   }*/
    //int min=INT_MAX;
    /*for(i=1;i<=k;i++)
    if(b[i][n]<min)
    min=b[i][n];*/
    res=INT_MAX;
    int d[25]={0};
    for(i=1;i<=k;i++)
    {
        d[i]=1;
        find(1,d,i,0);
        d[i]=0;
    }
    printf("%d\n",res);
    return 0;
}
40. covering the stains
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
long long modPow(long long a,int x);
long long modInverse(long long a);
long long C(int n,int k);
long long fac[1001];
long long ifac[1001];

int main(){
  int N,K,maxx=-1,maxy=-1,minx=-1,miny=-1,u=0,d=0,l=0,r=0,ul=0,ur=0,dl=0,dr=0,i,t;
  int *x,*y;
  long long ans=0;
  fac[0]=fac[1]=ifac[0]=ifac[1]=1;
  for(i=2;i<1001;i++){
    fac[i]=i*fac[i-1]%MOD;
    ifac[i]=modInverse(fac[i]);
  }
  scanf("%d%d",&N,&K);
  x=(int*)malloc(N*sizeof(int));
  y=(int*)malloc(N*sizeof(int));
  for(i=0;i<N;i++){
    scanf("%d%d",x+i,y+i);
    if(minx==-1 || x[i]<minx)
      minx=x[i];
    if(miny==-1 || y[i]<miny)
      miny=y[i];
    if(maxx==-1 || x[i]>maxx)
      maxx=x[i];
    if(maxy==-1 || y[i]>maxy)
      maxy=y[i];
  }
  for(i=0;i<N;i++){
    if(x[i]==minx)
      l++;
    if(x[i]==maxx)
      r++;
    if(y[i]==miny)
      d++;
    if(y[i]==maxy)
      u++;
    if(x[i]==minx && y[i]==miny)
      dl++;
    if(x[i]==minx && y[i]==maxy)
      ul++;
    if(x[i]==maxx && y[i]==miny)
      dr++;
    if(x[i]==maxx && y[i]==maxy)
      ur++;
  }
  if(N==1){
    if(K==0)
      printf("0");
    else
      printf("1");
  }
  else if(minx==maxx || miny==maxy){
    if(K>=1)
      ans=(ans+C(N-1,K-1)*2%MOD)%MOD;
    if(K>=2)
      ans=(ans-C(N-2,K-2)+MOD)%MOD;
    printf("%lld",ans);
  }
  else{
    if(K>=u)
      ans=(ans+C(N-u,K-u))%MOD;
    if(K>=d)
      ans=(ans+C(N-d,K-d))%MOD;
    if(K>=l)
      ans=(ans+C(N-l,K-l))%MOD;
    if(K>=r)
      ans=(ans+C(N-r,K-r))%MOD;
    t=u+d;
    if(K>=t)
      ans=(ans-C(N-t,K-t)+MOD)%MOD;
    t=u+l-ul;
    if(K>=t)
      ans=(ans-C(N-t,K-t)+MOD)%MOD;
    t=u+r-ur;
    if(K>=t)
      ans=(ans-C(N-t,K-t)+MOD)%MOD;
    t=d+l-dl;
    if(K>=t)
      ans=(ans-C(N-t,K-t)+MOD)%MOD;
    t=d+r-dr;
    if(K>=t)
      ans=(ans-C(N-t,K-t)+MOD)%MOD;
    t=l+r;
    if(K>=t)
      ans=(ans-C(N-t,K-t)+MOD)%MOD;
    t=u+d+l-ul-dl;
    if(K>=t)
      ans=(ans+C(N-t,K-t))%MOD;
    t=u+d+r-ur-dr;
    if(K>=t)
      ans=(ans+C(N-t,K-t))%MOD;
    t=u+r+l-ul-ur;
    if(K>=t)
      ans=(ans+C(N-t,K-t))%MOD;
    t=r+d+l-dl-dr;
    if(K>=t)
      ans=(ans+C(N-t,K-t))%MOD;
    t=u+d+l+r-ul-ur-dl-dr;
    if(K>=t)
      ans=(ans-C(N-t,K-t)+MOD)%MOD;
    printf("%lld",ans);
  }
  return 0;
}
long long modPow(long long a,int x){
  long long res = 1;
  while(x>0){
    if(x%2)
      res=res*a%MOD;
    a=a*a%MOD;
    x>>=1;
  }
  return res;
}
long long modInverse(long long a){
  return modPow(a,MOD-2);
}
long long C(int n,int k){
  return fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}
41.wet shark and two Subsequences
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
int a[100];
long long dp1[101][100][2001];

int main(){
  int m,r,s,A,B,i,j,k;
  long long ans=0;
  scanf("%d%d%d",&m,&r,&s);
  for(i=0;i<m;i++)
    scanf("%d",a+i);
  if((r+s)%2 || r<s){
    printf("0");
    return 0;
  }
  A=(r+s)/2;
  B=(r-s)/2;
  for(i=0;i<=m;i++)
    for(j=0;j<m;j++)
      for(k=0;k<=A;k++)
        if(!i)
          if(!k)
            dp1[i][j][k]=1;
          else
            dp1[i][j][k]=0;
        else if(!j){
          if(i>1)
            dp1[i][j][k]=0;
          else if(k==a[j])
            dp1[i][j][k]=1;
          else
            dp1[i][j][k]=0;
        }
        else if(i>j+1)
          dp1[i][j][k]=0;
        else{
          dp1[i][j][k]=dp1[i][j-1][k];
          if(k-a[j]>=0)
            dp1[i][j][k]=(dp1[i][j][k]+dp1[i-1][j-1][k-a[j]])%MOD;
        }
  for(i=1;i<=m;i++)
    ans=(ans+dp1[i][m-1][A]*dp1[i][m-1][B]%MOD)%MOD;
  printf("%lld",ans);
  return 0;
}
42. fairy chess
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#define MAX_WIDTH  200
#define MAX_MOVE 201
#define MODULAR 1000000007

#define FORMAT_RESULT(x) if (x >= MODULAR) {\
    x -= MODULAR;\
} else if (x < 0) {\
    x += MODULAR;\
}

char board[MAX_WIDTH][MAX_WIDTH];
int width; // board width
int max_step;  // step can move once
int max_moves;
int result[MAX_MOVE][MAX_WIDTH][MAX_WIDTH] = {0};
int cache_asc[2][MAX_WIDTH][MAX_WIDTH];
int cache_desc[2][MAX_WIDTH][MAX_WIDTH];
int read_index;
int write_index;

void
compute(int moves)
{
    int y, x, x1, y1, y2, x2, dx, dy;
    
    // (0, 0)
    for (y = 0; y < max_step; y++) {
        result[moves][0][0] += cache_desc[read_index][y][0];
        FORMAT_RESULT(result[moves][0][0]);
    }
    if (max_step < width) {
        result[moves][0][0] += cache_desc[read_index][max_step][0];
        FORMAT_RESULT(result[moves][0][0]);
    } else {
        if (1 < width) {
            result[moves][0][0] += cache_desc[read_index][max_step - 1][1];
            FORMAT_RESULT(result[moves][0][0]);
        }
    }
    cache_desc[write_index][0][0] = cache_asc[write_index][0][0] = board[0][0] == 'P' ? 0 : result[moves][0][0];

    // [(1, 0), (width - 1, 0)]
    for (x = 1; x < width; x++) {
        result[moves][0][x] = result[moves][0][x - 1];

        x1 = x;
        y1 = max_step;
        if (y1 >= width) {
            dy = y1 - width + 1;
            y1 -= dy;
            x1 += dy;
        }
        if (x1 < width) {
            result[moves][0][x] += cache_desc[read_index][y1][x1];
            FORMAT_RESULT(result[moves][0][x]);
        }

        x1 = x - 1;
        y1 = max_step;
        if (y1 >= width) {
            dy = y1 - width + 1;
            y1 -= dy;
            x1 -= dy;
        }
        if (x1 >= 0) {
            result[moves][0][x] -= cache_asc[read_index][y1][x1];
            FORMAT_RESULT(result[moves][0][x]);
        }

        cache_desc[write_index][0][x] = cache_asc[write_index][0][x] = board[0][x] == 'P' ? 0 : result[moves][0][x];
    }

    // [(0, 1), (width - 1, width - 1)]
    for (y = 1; y < width; y++) {
        for (x = 0; x < width; x++) {
            result[moves][y][x] = result[moves][y - 1][x];

            x1 = x;
            y1 = y + max_step;
            x2 = x + max_step;
            y2 = y;
            if (y1 >= width) {
                dy = y1 - width + 1;
                y1 -= dy;
                x1 += dy;
            }
            if (x1 < width) {
                if (x2 >= width - 1) {
                    result[moves][y][x] += cache_desc[read_index][y1][x1];
                    FORMAT_RESULT(result[moves][y][x]);
                } else {
                    result[moves][y][x] += cache_desc[read_index][y1][x1] - cache_desc[read_index][y2 - 1][x2 + 1];
                    FORMAT_RESULT(result[moves][y][x]);
                }
            }
            x1 = x;
            y1 = y + max_step;
            x2 = x - max_step;
            y2 = y;
            if (y1 >= width) {
                dy = y1 - width + 1;
                y1 -= dy;
                x1 -= dy;
            }
            if (x1 >= 0) {
                if (x2 <= 0) {
                    result[moves][y][x] += cache_asc[read_index][y1][x1];
                    FORMAT_RESULT(result[moves][y][x]);
                } else {
                    result[moves][y][x] += cache_asc[read_index][y1][x1] - cache_asc[read_index][y2 - 1][x2 - 1];
                    FORMAT_RESULT(result[moves][y][x]);
                }
            }
            if (y + max_step < width) {
                result[moves][y][x] -= result[moves - 1][y + max_step][x];
                FORMAT_RESULT(result[moves][y][x]);
            }

            x1 = x + max_step;
            y1 = y - 1;
            x2 = x;
            y2 = y - 1 - max_step;
            if (x1 >= width) {
                dx = x1 - width + 1;
                y1 -= dx;
                x1 -= dx;
            }
            if (y1 >= 0) {
                if (y2 <= 0 || x2 == 0) {
                    result[moves][y][x] -= cache_asc[read_index][y1][x1];
                    FORMAT_RESULT(result[moves][y][x]);
                } else {
                    result[moves][y][x] -= cache_asc[read_index][y1][x1] - cache_asc[read_index][y2 - 1][x2 - 1];
                    FORMAT_RESULT(result[moves][y][x]);
                }
            }

            x1 = x - max_step;
            y1 = y - 1;
            x2 = x;
            y2 = y - 1 - max_step;
            if (x1 < 0) {
                dx = -x1;
                x1 += dx;
                y1 -= dx;
            }
            if (y1 >= 0) {
                if (y2 <= 0 || x2 == width - 1) {
                    result[moves][y][x] -= cache_desc[read_index][y1][x1];
                    FORMAT_RESULT(result[moves][y][x]);
                } else {
                    result[moves][y][x] -= cache_desc[read_index][y1][x1] - cache_desc[read_index][y2 - 1][x2 + 1];
                    FORMAT_RESULT(result[moves][y][x]);
                }
            }
            if (y - 1 - max_step >= 0) {
                result[moves][y][x] += result[moves - 1][y - 1 - max_step][x];
                FORMAT_RESULT(result[moves][y][x]);
            }


            cache_asc[write_index][y][x] = x > 0 ? cache_asc[write_index][y - 1][x - 1] : 0;
            cache_desc[write_index][y][x] = (x < width - 1) ? cache_desc[write_index][y - 1][x + 1] : 0;
            if (board[y][x] != 'P') {
                cache_desc[write_index][y][x] += result[moves][y][x];
                FORMAT_RESULT(cache_desc[write_index][y][x]);
                cache_asc[write_index][y][x] += result[moves][y][x];
                FORMAT_RESULT(cache_asc[write_index][y][x]);
            }
        }
    }

    for (y = 0; y < width; y++) {
        for (x = 0; x < width; x++) {
            if (board[y][x] == 'P') {
                result[moves][y][x] = 0;
            }
        }
    }
}

int
main (int argc, char *argv[])
{
    int num_case;
    int x, y, moves, sum, i, j;

    scanf("%d", &num_case);
    while (num_case--) {
        bzero(result, sizeof(int) * MAX_MOVE * MAX_WIDTH * MAX_WIDTH);
        bzero(cache_asc, sizeof(int) * 2 * MAX_WIDTH * MAX_WIDTH);
        bzero(cache_desc, sizeof(int) * 2 * MAX_WIDTH * MAX_WIDTH);

        scanf("%d %d %d", &width, &max_moves, &max_step);
        for (y = width - 1; y >= 0; y--) {
            scanf("%s", board[y]);
        }

        read_index = 0;
        write_index = 1;
        for (y = 0; y < width; y++) {
            for (x = 0; x < width; x++) {
                if (board[y][x] == 'L') {
                    result[0][y][x] = 1;
                }
                if (x > 0 && y > 0) {
                    cache_asc[read_index][y][x] = result[0][y][x] + cache_asc[read_index][y - 1][x - 1];
                } else {
                    cache_asc[read_index][y][x] = result[0][y][x];
                }
                if (x < width && y > 0) {
                    cache_desc[read_index][y][x] = result[0][y][x] + cache_desc[read_index][y - 1][x + 1];
                } else {
                    cache_desc[read_index][y][x] = result[0][y][x];
                }
            }
        }

        for (moves = 1; moves <= max_moves; moves++) {
            compute(moves);
            if (read_index == 1) {
                write_index = 1;
                read_index = 0;
            } else {
                write_index = 0;
                read_index = 1;
            }
        }

        sum = 0;
        for (y = 0; y < width; y++) {
            for (x = 0; x < width; x++) {
                sum += result[max_moves][y][x];
                FORMAT_RESULT(sum);
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
43.modify the Subsequence
#include <stdio.h>
#include <stdlib.h>
int get_i(int*a,int num,int size);
int med(int*a,int size);
void sort_a2(int*a,int*b,int size);
void merge2(int*a,int*left_a,int*right_a,int*b,int*left_b,int*right_b,int left_size, int right_size);
int u[1000000],v[1000000],a[1000000];

int main(){
  int n,x,i,ans=1,size=0,*aa;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x);
    if(x>i){
      u[size]=i-x;
      v[size]=i;
      size++;
    }
  }
  sort_a2(u,v,size);
  aa=a+999999;
  aa[0]=v[0];
  for(i=1;i<size;i++){
    x=get_i(aa,v[i],ans);
    if(aa[x]==v[i])
      continue;
    if(!x){
      aa--;
      aa[0]=v[i];
      ans++;
    }
    else
      aa[x-1]=v[i];
  }
  printf("%d",n-ans);
  return 0;
}
int get_i(int*a,int num,int size){
  if(size==0)
    return 0;
  if(num>med(a,size))
    return get_i(&a[(size+1)>>1],num,size>>1)+((size+1)>>1);
  else
    return get_i(a,num,(size-1)>>1);
}
int med(int*a,int size){
  return a[(size-1)>>1];
}
void sort_a2(int*a,int*b,int size){
  if (size < 2)
    return;
  int m = (size+1)/2,i;
  int*left_a,*left_b,*right_a,*right_b;
  left_a=(int*)malloc(m*sizeof(int));
  right_a=(int*)malloc((size-m)*sizeof(int));
  left_b=(int*)malloc(m*sizeof(int));
  right_b=(int*)malloc((size-m)*sizeof(int));
  for(i=0;i<m;i++){
    left_a[i]=a[i];
    left_b[i]=b[i];
  }
  for(i=0;i<size-m;i++){
    right_a[i]=a[i+m];
    right_b[i]=b[i+m];
  }
  sort_a2(left_a,left_b,m);
  sort_a2(right_a,right_b,size-m);
  merge2(a,left_a,right_a,b,left_b,right_b,m,size-m);
  free(left_a);
  free(right_a);
  free(left_b);
  free(right_b);
  return;
}
void merge2(int*a,int*left_a,int*right_a,int*b,int*left_b,int*right_b,int left_size, int right_size){
  int i = 0, j = 0;
  while (i < left_size|| j < right_size) {
    if (i == left_size) {
      a[i+j] = right_a[j];
      b[i+j] = right_b[j];
      j++;
    } else if (j == right_size) {
      a[i+j] = left_a[i];
      b[i+j] = left_b[i];
      i++;
    } 
    else if (left_a[i] == right_a[j]) {
      if(left_b[i] >= right_b[j]){
        a[i+j] = left_a[i];
        b[i+j] = left_b[i];
        i++;
      }
      else{
        a[i+j] = right_a[j];
        b[i+j] = right_b[j];
        j++;
      }
    }
    else if (left_a[i] < right_a[j]) {
      a[i+j] = left_a[i];
      b[i+j] = left_b[i];
      i++;
    } else {
      a[i+j] = right_a[j];
      b[i+j] = right_b[j];
      j++;
    }
  }
  return;
}

44. superman celebrates diwali
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int np[1901][1901];
int res[1901][1901];
int ma[1901];

int max(int a,int b)
{
  if(a>b)
   return a;
  return b;
}

int main() {
    int n,h,l,u,val,i,j;
    scanf("%d %d %d",&n,&h,&l);
    for(i=1;i<=n;i++)
     {
        scanf("%d",&u);
        for(j=0;j<u;j++)
         {
          scanf("%d",&val);
          np[i][val]++;
         }
     }

     for(j=1;j<=l;j++)
        {
     
        for(i=1;i<=n;i++)
          {    
          res[i][j] =res[i][j-1]+np[i][j];
          ma[j] =max(ma[j],res[i][j]);
          }
      }
      
        for(j=l+1;j<=h;j++)
        {
           
          for(i=1;i<=n;i++)
           {
             if(res[i][j-l]==ma[j-l])
             {
               res[i][j] =  np[i][j]+res[i][j-1];
             }
             else
             {
               res[i][j] = np[i][j]+max(res[i][j-1],ma[j-l]);
             }
              if(res[i][j]>ma[j])
                ma[j]=res[i][j];
           }
           
        }

       printf("%d\n",ma[h]);
    
               
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

45. dorsey theif
#include <stdio.h>
#include <stdlib.h>
void sort_a2(int*a,long long*b,int size);
void merge2(int*a,int*left_a,int*right_a,long long*b,long long*left_b,long long*right_b,int left_size, int right_size);

int main(){
  int N,X,i,j,k,*a,len,*index;
  long long *dp,temp,*v;
  scanf("%d%d",&N,&X);
  a=(int*)malloc(N*sizeof(int));
  v=(long long*)malloc(N*sizeof(long long));
  dp=(long long*)malloc((X+1)*sizeof(long long));
  index=(int*)malloc((X+1)*sizeof(int));
  for(i=1;i<=X;i++){
    dp[i]=-1;
    index[i]=-1;
  }
  dp[0]=0;
  for(i=0;i<N;i++)
    scanf("%lld%d",v+i,a+i);
  sort_a2(a,v,N);
  for(i=0;i<N && a[i]<=X;i++)
    if(i==0 || a[i]!=a[i-1])
      index[a[i]]=i;
  for(i=1;i<=X;i++){
    if(index[i]==-1)
      continue;
    len=X/a[index[i]]+index[i];
    for(k=index[i];k<len && k<N;k++){
      if(k!=index[i] && a[k]!=a[k-1])
        break;
      for(j=X;j>=a[k];j--){
        temp=(dp[j-a[k]]==-1)?-1:dp[j-a[k]]+v[k];
        if(temp>dp[j])
          dp[j]=temp;
      }
    }
  }
  if(dp[X]!=-1)
    printf("%lld",dp[X]);
  else
    printf("Got caught!");
  return 0;
}
void sort_a2(int*a,long long*b,int size){
  if (size < 2)
    return;
  int m = (size+1)/2,i;
  int *left_a,*right_a;
  long long *left_b,*right_b;
  left_a=(int*)malloc(m*sizeof(int));
  right_a=(int*)malloc((size-m)*sizeof(int));
  left_b=(long long*)malloc(m*sizeof(long long));
  right_b=(long long*)malloc((size-m)*sizeof(long long));
  for(i=0;i<m;i++){
    left_a[i]=a[i];
    left_b[i]=b[i];
  }
  for(i=0;i<size-m;i++){
    right_a[i]=a[i+m];
    right_b[i]=b[i+m];
  }
  sort_a2(left_a,left_b,m);
  sort_a2(right_a,right_b,size-m);
  merge2(a,left_a,right_a,b,left_b,right_b,m,size-m);
  free(left_a);
  free(right_a);
  free(left_b);
  free(right_b);
  return;
}
void merge2(int*a,int*left_a,int*right_a,long long*b,long long*left_b,long long*right_b,int left_size, int right_size){
  int i = 0, j = 0;
  while (i < left_size|| j < right_size) {
    if (i == left_size) {
      a[i+j] = right_a[j];
      b[i+j] = right_b[j];
      j++;
    } else if (j == right_size) {
      a[i+j] = left_a[i];
      b[i+j] = left_b[i];
      i++;
    } else if (left_a[i] < right_a[j]) {
      a[i+j] = left_a[i];
      b[i+j] = left_b[i];
      i++;
    }  else if (left_a[i] == right_a[j]) {
      if (left_b[i] <= right_b[j]) {
        a[i+j] = right_a[j];
        b[i+j] = right_b[j];
        j++;
      }
      else{
        a[i+j] = left_a[i];
        b[i+j] = left_b[i];
        i++;
      }
    }else {
      a[i+j] = right_a[j];
      b[i+j] = right_b[j];
      j++;
    }
  }
  return;
}
46. requirement
/* Enter your code here. Read input from STDIN. Print output to STDOUT */#include <malloc.h>
#include <math.h>
typedef unsigned char byte;
int n,m;


int imore[16]={0};
int imorex[16]={0};
int ilessx[16]={0};
int iless[16]={0};
byte reorder[16]={0};
byte order[16]={0};
int limit[16]={0};
byte limitn[16]={0};
byte dim=5;
byte indpre=100;
byte*** more;
byte*** less;
byte* morecount;
byte* lesscount;
byte* current;
long long count=0;
int* predata;
byte orderpre[16]={0};
int reorderpre[16]={-1};
byte inprecmpute;


void find(byte ind)
{
	byte minval=0;
	byte maxval=9;
	int i=0;
	byte tmp;
	int index=0;


	if (inprecmpute==0&&ind==indpre)
	{

		for (i=dim-1;i>=0;i--)
		{
			index*=10;
			index+=current[orderpre[i]];
		}
		count+=predata[index];
	}
	else
	{

		for(i=0;i<morecount[ind];i++)
		{
			tmp=*(more[ind][i]);
			maxval=maxval<tmp?maxval:tmp;	
		}
		for(i=0;i<lesscount[ind];i++)
		{
			tmp=*(less[ind][i]);
			minval=minval>tmp?minval:tmp;	
		}
		if (ind<n-1)
		{
			for (i=minval;i<=maxval;i++)
			{
				current[ind]=i;
				find(ind+1);
			}

		}
		else if (maxval>=minval)
		{
			count+=maxval-minval+1;
		}
	
	}


}

void extent()
{
	int oldsum1=1;
	int sum2=0;
	int tmp;
	int i,j;
	memcpy(ilessx,iless,sizeof(iless));
	memcpy(imorex,imore,sizeof(imore));
	//for (i=0;i<n;i++)
	//{
	//	printf("%d:less:%s more:%s\n",i,tostring(iless[i]),tostring(imore[i]));
	//}
	while(oldsum1!=sum2)
	{
		for (i=0;i<n;i++)
		{
			int tmpless=iless[i];
			int tmpmore=imore[i];
			for (j=0;j<n;j++)
			{
				if ((tmpless&1)!=0)
				{
					ilessx[i]|=iless[j];
				}
				if ((tmpmore&1)!=0)
				{
					imorex[i]|=imore[j];
				}
				tmpless>>=1;
				tmpmore>>=1;
			}
		}
		oldsum1=sum2;
		sum2=0;
		for (i=0;i<n;i++)
		{
			sum2+=ilessx[i]+imorex[i];
		}
////		printf("%d,%d\n",oldsum1,sum1);
//		for (i=0;i<n;i++)
//		{
//			printf("%d:less:%s more:%s\n",i,tostring(ilessx[i]),tostring(imorex[i]));
//		}
	}
	tmp=1;
	for (i=0;i<n;i++)
	{
		ilessx[i]&=(~tmp);
		imorex[i]&=(~tmp);
		tmp<<=1;		
	}

	//for (i=0;i<n;i++)
	//{
	//	printf("%d:less:%s more:%s\n",i,tostring(ilessx[i]),tostring(imorex[i]));
	//}
}


byte sum1(int num)
{
	int i;
	byte count=0;
	for (i=0;i<n;i++)
	{
		if (num&(1<<i))
		{
			count++;
		}
		
	}
	return count;

}

void sort()
{
	int i,j,k,tmp;
	byte flag[16]={0};
	//printf("sort\n");
	for(i=n-1;i>=0;i--)
	{
		int nlimit=n;
		int ind=0;
		int indmore=0xFFFFFFFF;
		int indless=0xFFFFFFFF;
		for (j=0;j<n;j++)
		{
			if (flag[j]==0)
			{
				int tmpmore=imore[j];
				int tmpless=iless[j];
				for (k=0;k<n;k++)
				{
					if (flag[k]==0&&j!=k)
					{
						if (((imore[j]>>k)&1)!=0)
						{
							tmpmore&=~(imorex[k]);
						}
						if (((iless[j]>>k)&1)!=0)
						{
							tmpless&=~(ilessx[k]);
						}
					}
					
				}
				tmp=sum1((tmpmore|tmpless|limit[i+1])&(~(1<<j)));
				if(tmp<=nlimit)
				{
					ind=j;
					nlimit=tmp;
					indmore=tmpmore;
					indless=tmpless;
				}
			}
		}
		tmp=~(1<<ind);
		for (j=0;j<n;j++)
		{
			if(flag[j]==0)
			{
				imore[j]&=tmp;
				iless[j]&=tmp;
			
			}
		}
		order[i]=ind;
		flag[ind]=1;
		imore[ind]=indmore;
		iless[ind]=indless;
		limit[i]=(limit[i+1]|indmore|indless)&(~(1<<ind));
		limitn[i]=sum1(limit[i]);
		if (limitn[i]<=dim)
		{
		//	indpre=i;

		}
		/*printf("%d\n",ind);
		for (j=0;j<n;j++)
		{
			for (j=0;j<n;j++)
			{
				printf("%d:less:%s more:%s\n",j,tostring(iless[j]),tostring(imore[j]));
			}
		}*/
	}
	
	//for (i=0;i<n;i++)
	//{
	//	for (i=0;i<n;i++)
	//	{
	//		printf("%d:less:%s more:%s\n",i,tostring(iless[i]),tostring(imore[i]));
	//	}
	//}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (order[j]==i)
			{
				break;
			}
		}
		reorder[i]=j;
	}

}

void precomp()
{
	int nd,i,j;
	int tmp;
	int scal=1;
	if (indpre>=n)
	{
		return;
	}

	inprecmpute=1;
	nd=limitn[indpre];
	for (i=0;i<nd;i++)
	{
		scal*=10;
	}
	predata=(int*)malloc(scal*sizeof(int));
	tmp=limit[indpre];
	j=0;
	for (i=0;i<n;i++)
	{	
		if (tmp&1!=0)
		{
			orderpre[j]=reorder[i];
			j++;
		}
		tmp>>=1;
	}
	dim=j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<dim;j++)
		{
			if (orderpre[j]==i)
			{
				break;
			}
		}
		reorderpre[i]=j;
	}
	for (i=0;i<scal;i++)
	{
		byte coordinate[16];
		tmp=i;
		for (j=0;j<dim;j++)
		{
			current[orderpre[j]]=tmp%10;
			tmp/=10;
		}
		count=0;
		find(indpre);
		predata[i]=count;
		count=0;

	}
	inprecmpute=0;
}


void main()
{
	int i,j;

	scanf("%d %d",&n,&m);
	current=(byte*)malloc(n*sizeof(byte));
	more=(byte***)malloc(n*sizeof(byte**));
	less=(byte***)malloc(n*sizeof(byte**));
	morecount=(byte*)malloc(n*sizeof(byte));
	lesscount=(byte*)malloc(n*sizeof(byte));
	memset(morecount,0,n);
	memset(lesscount,0,n);
	for (i=0;i<n;i++)
	{
		//printf(" %d ",lesscount[i]);
		more[i]=(byte**)malloc(n*sizeof(byte*));
		memset(more[i],0,n);
		less[i]=(byte**)malloc(n*sizeof(byte*));
		memset(less[i],0,n);
	}
	memset(imore,0,16*4);
	memset(iless,0,16*4);
	for(i=0;i<m;i++ )
	{
		int s,b;
		scanf("%d %d",&s,&b);
		/*if(s>b)
		{
			more[s][morecount[s]]=current+b;
			morecount[s]++;
		}
		else
		{
			less[b][lesscount[b]]=current+s;
			lesscount[b]++;
		}*/
		//more[s][morecount[s]]=current+b;
		//morecount[s]++;
		//less[b][lesscount[b]]=current+s;
		//lesscount[b]++;
		imore[s]|=(1<<b);
		iless[b]|=(1<<s);
	}
	extent();
    sort();
indpre=n/2;
	for(i=0;i<n;i++ )
	{
		byte orderi=order[i];
		int tmpless=iless[orderi];
		int tmpmore=imore[orderi];
		for (j=0;j<n;j++)
		{
			if ((tmpless&1)!=0)
			{
				less[i][lesscount[i]]=current+reorder[j];
				lesscount[i]++;

			}
			if ((tmpmore&1)!=0)
			{
				more[i][morecount[i]]=current+reorder[j];
				morecount[i]++;
			}
			tmpless>>=1;
			tmpmore>>=1;
		}
	}
	precomp();


	//sort();
	find(0);
	printf("%lld",count%1007);
}
47. a super hero
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int **createCache(int n,int m){
    
    int **A = (int**)malloc(sizeof(int*)*n);
    
    int i,j;
    
    for(i=0;i<n;i++){
        A[i] = (int*)malloc(sizeof(int)*m);
        for(j=0;j<m;j++)
            A[i][j] = -1;
    }
    
    return A;
    
}

int **createPowerMatrix(int n,int m){
    
    int **A = (int**)malloc(sizeof(int*)*n);
    
    int i,j;
    
    for(i=0;i<n;i++){
        A[i] = (int*)malloc(sizeof(int)*m);
        for(j=0;j<m;j++)
            scanf("%d",&A[i][j]);
    }
    
    return A;
}

int **createBulletMatrix(int n,int m){
    
    int **A = (int**)malloc(sizeof(int*)*n);
    
    int i,j;
    
    for(i=0;i<n;i++){
        A[i] = (int*)malloc(sizeof(int)*m);
        for(j=0;j<m;j++)
            scanf("%d",&A[i][j]);
    }
    
    return A;
}

int nextLevel(int BulletsAtThisLevel,int index,int n,int m,int **P,int **B,int **cache){	

	if(index == n)
		return 0;

	
    if(cache[index][BulletsAtThisLevel] != -1)
        return cache[index][BulletsAtThisLevel];
	int min = INT_MAX;
	int s;
	int j;
    

	for(j=0;j<m;j++){

		if(BulletsAtThisLevel < P[index][j])
			s = P[index][j] - BulletsAtThisLevel + nextLevel(B[index][j],index+1,n,m,P,B,cache);
		else
			s = nextLevel(B[index][j],index+1,n,m,P,B,cache);

		if(s<min)
			min = s;
	}

	return cache[index][BulletsAtThisLevel] = min;

}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int t;
    scanf("%d",&t);
    
    while(t--){
        
        int n,m;
        scanf("%d%d",&n,&m);
        
        int **P = createPowerMatrix(n,m);
        int **B = createBulletMatrix(n,m);
        int **cache = createCache(100,10001);
        printf("%d\n",nextLevel(0,0,n,m,P,B,cache));
    }
    return 0;
}

48. billboards
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

struct moving_min {
  int64_t value;
  int index;
};

struct queue {
  int max_size;
  int first;
  int last;
  int size;
  struct moving_min* values;
};

// Queue functions
struct moving_min* front(const struct queue* q) {
  return q->values + q->first;
}

struct moving_min* back(const struct queue* q) {
  return q->values + q->last;
}

void push_back(struct queue* q, int64_t value, int index) {
  q->last = (q->last + 1) % q->max_size;
  q->values[q->last].value = value;
  q->values[q->last].index = index;
  q->size++;
  assert(q->size <= q->max_size);
}

void pop_front(struct queue* q) {
  q->first = (q->first + 1) % q->max_size;
  q->size--;
  assert(q->size >= 0);
}

void pop_back(struct queue* q) {
  q->last = (q->last - 1);
  if (q->last < 0) {
    q->last = q->max_size - 1;
  }
  q->size--;
  assert(q->size >= 0);
}

void init_queue(struct queue* q, int k) {
  q->max_size = k;
  q->size = 0;
  q->first = 0;
  q->last = k - 1;
  q->values = malloc(sizeof(struct moving_min) * k);
}

void free_queue(struct queue* q) {
  free(q->values);
}

void print_queue(const struct queue* q) {
  int i;
  for (i = 0; i < q->size; ++i) {
    struct moving_min* val = q->values + ((q->first + i) % q->max_size);
    printf("[%d]=%d,%lld ", i, val->index, val->value);
  }
  printf("\n");
}

// Maintain a queue with the min value of the last k in front

void maintain_moving(int latest_index, int64_t latest_value,
                     struct queue* q) {
  // Remove the first element if its index is out of date
  if ((int64_t)front(q)->index <= latest_index - (int64_t)q->max_size) {
    pop_front(q);
  }
  // Remove elements with a greater value
  while (q->size > 0) {
    if (latest_value <= back(q)->value) {
      pop_back(q);
    } else {
      break;
    }
  }
  // Add the new element
  push_back(q, latest_value, latest_index);
}

int64_t shortest_path(int n, int k, int64_t* values) {
  struct queue q;
  int64_t shortest_path_value;
  int64_t value_sum = 0;
  int i;
  int64_t ret;
  init_queue(&q, k + 1);
  maintain_moving(0, 0, &q);
  for (i = 0; i < n; ++i) {
    value_sum += values[i];
    shortest_path_value = front(&q)->value + values[i];
    maintain_moving(i + 1, shortest_path_value, &q);
  }
  ret = value_sum - front(&q)->value;
  free_queue(&q);
  return ret;
}

int main() {
  int n, k, i;
  scanf("%d %d\n", &n, &k);
  int64_t* values = malloc(n * sizeof(int64_t));
  for (i = 0; i < n; ++i) {
    scanf("%lld\n", values + i);
  }
  printf("%lld", shortest_path(n, k, values));
  return 0;
}

49. tree pruning
#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
  int x;
  struct _node *next;
} node;
void insert_edge(int x,int y);
void dfs(int x);
long long max(long long x,long long y);
int a[100000],b[100000],size[100000],trace[100000]={0},NN=0;
long long dp[100001][201];
node *table[100000]={0};

int main(){
  int N,K,x,y,i,j;
  long long sum;
  scanf("%d%d",&N,&K);
  for(i=0;i<N;i++)
    scanf("%d",a+i);
  for(i=0;i<N-1;i++){
    scanf("%d%d",&x,&y);
    insert_edge(x-1,y-1);
  }
  dfs(0);
  for(i=0;i<=K;i++)
    dp[0][i]=0;
  for(i=1,sum=0;i<=N;i++){
    sum+=b[i-1];
    for(j=0;j<=K;j++)
      dp[i][j]=sum;
  }
  for(i=1,sum=0;i<=N;i++)
    for(j=0;j<=K;j++){
      if(j!=K)
        dp[i+size[i-1]-1][j+1]=max(dp[i+size[i-1]-1][j+1],dp[i-1][j]);
      dp[i][j]=max(dp[i][j],dp[i-1][j]+b[i-1]);
    }
  printf("%lld",dp[N][K]);
  return 0;
}
void insert_edge(int x,int y){
  node *t;
  t=(node*)malloc(sizeof(node));
  t->x=y;
  t->next=table[x];
  table[x]=t;
  t=(node*)malloc(sizeof(node));
  t->x=x;
  t->next=table[y];
  table[y]=t;
  return;
}
void dfs(int x){
  node *t;
  int i=NN;
  trace[x]=1;
  b[NN++]=a[x];
  for(t=table[x];t;t=t->next)
    if(!trace[t->x])
      dfs(t->x);
  size[i]=NN-i;
  return;
}
long long max(long long x,long long y){
  return (x>y)?x:y;
}

50. extremum permutations
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
int o[5000]={0};
long long dp[5000][5000]={0};

int main(){
  int N,K,L,x,i,j;
  long long sum;
  scanf("%d%d%d",&N,&K,&L);
  for(i=0;i<K;i++){
    scanf("%d",&x);
    if(o[x-1]==1){
      printf("0");
      exit(0);
    }
    o[x-1]=-1;
    if(o[x]==-1){
      printf("0");
      exit(0);
    }
    o[x]=1;
  }
  for(i=0;i<L;i++){
    scanf("%d",&x);
    if(o[x-1]==-1){
      printf("0");
      exit(0);
    }
    o[x-1]=1;
    if(o[x]==1){
      printf("0");
      exit(0);
    }
    o[x]=-1;
  }
  dp[0][0]=1;
  for(i=1;i<N;i++){
    sum=0;
    switch(o[i]){
      case 0:
        for(j=0,sum=0;j<i;j++)
          sum=(sum+dp[i-1][j])%MOD;
        for(j=0;j<=i;j++)
          dp[i][j]=sum;
        break;
      case -1:
        for(j=i-1,sum=0;j>=0;j--){
          sum=(sum+dp[i-1][j])%MOD;
          dp[i][j]=sum;
        }
        break;
      default:
        for(j=0,sum=0;j<i;j++){
          sum=(sum+dp[i-1][j])%MOD;
          dp[i][j+1]=sum;
        }
    }
  }
  for(i=0,sum=0;i<N;i++)
    sum=(sum+dp[N-1][i])%MOD;
  printf("%lld",sum);
  return 0;
}
51. ones and twos
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int MOD = 1e9 + 7;
int dp_sum[1001][1001],dp_bit[1001][1001];
void add(int &x,long long v){
    v%=MOD;
    x+=v;
    if(x>=MOD)x-=MOD;
}
int f_bit(int lv,int B);
int f_sum(int lv,int B){
    if(lv>B)return 1;
    if(dp_sum[lv][B]!=-1)return dp_sum[lv][B];
    int tmp=f_sum(lv+1,B);
    add(tmp,f_bit(lv,B));
    return dp_sum[lv][B]=tmp;

}
int f_bit(int lv,int B){
    if(lv>B)return 0;
    if(dp_bit[lv][B]!=-1)return dp_bit[lv][B];
    return dp_bit[lv][B]=f_sum(lv+1,B-lv);
}
int main(){
    int T,A,B;
    scanf("%d",&T);
    memset(dp_sum,-1,sizeof(dp_sum));
    memset(dp_bit,-1,sizeof(dp_bit));
    while(T--){
        scanf("%d%d",&A,&B);
        int an=0;
        if(A==0)an=f_sum(1,B);
        else{
            int k=1;
            while((1LL<<k)<=A)k++;
            k++;
            add(an,(long long)(A+1)*f_sum(k,B));
            long long ha=(1LL<<k)-A-1;
            int now=0,i=1;
            long long last=0;
            while(ha>0){
                now++;
                if(B<now)break;
                add(an,min((1LL<<i)-last,ha)*f_sum(k,B-now));
                ha-=(1LL<<i)-last;
                last=1LL<<i;
                i++;
                if(i==k){
                    last=0;
                    i=1;
                }
            }
            /*
            long long last=A;
            for(int i=1;i<=B;i++){
                if(last+1>=(1LL<<k))break;
                add(an,(min(((long long)A+(1LL<<i)),(1LL<<k)-1)-last)*f_sum(k,B-i));
                last=min((long long)A+(1LL<<i),(1LL<<k)-1);
            }*/
        }
        printf("%d\n",(an+MOD-1)%MOD);
    }
    return 0;
}

52. p-sequences
#include <stdio.h>

#define P 1000000007LL

long long b[100000][3],i,j,k,l,m,n,t;
long long a[1010][65000];

int main()
{

scanf("%lld %lld",&n,&t);

k = 1;
l = 0;

while(k<=t)
 {
   b[l][0] = k;
   b[l][1] = t/(t/k);
   b[l][2] = b[l][1] - b[l][0] + 1;
   k = b[l][1] + 1;
   l++;
 }

for(i=0;i<l;i++) a[0][i] = 0;
a[0][0] = 1;

for(i=1;i<=n;i++)
{
 k = 0;
 for(j=0;j<l;j++)
   {
    k = (k+a[i-1][j]*b[j][2])%P;
    a[i][l-1-j] = k;   
   }
}

k = 0;

for(i=0;i<l;i++) k = (k+a[n][i]*b[i][2])%P;

printf("%lld\n",k);

//for(i=0;i<l;i++) printf("%lld: %lld-%lld -> %lld\n",i,b[i][0],b[i][1],t/b[i][0]);

return 0;
}
53. divisible numbers
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define M 30300
#define N 300
#define INF 100000000

int d[M][N], p[M][N], n, len = 1, bon = 10;

void pre(void){
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < N; ++j)
		p[i][j] = d[i][j] = INF;

	for (int i = 1; i <= 9; ++i)
		p[i][i] = i;
}

bool din(void){
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < N && j <= len * 9; ++j)
	for (int k = 1, to = i + bon; k <= 9 && j + k<N; ++k, to += bon){
		if (to >= n)
			to -= n;
		d[to][j + k] = min(d[to][j + k], p[i][j] * k);
	}

	for (int j = 0; j < N; ++j)
	if (p[0][j] <= j)
		return 1;

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < N; ++j){
		p[i][j] = d[i][j];
		d[i][j] = INF;
	}

	return 0;
}

int ans[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 3, 5, 3, 2, 3, 3, 0, 2, 4, 3, 4, 6, 4, 3, 3, 3, 0, 2, 5, 4, 3, 5, 5, 3, 4, 4, 0, 2, 3, 3, 5, 18, 3, 3, 3, 3, 0, 2, 4, 4, 4, 5, 3, 4, 5, 4, 0, 2, 5, 3, 6, 7, 6, 3, 3, 3, 0, 2, 4, 4, 5, 6, 4, 4, 4, 5, 0, 2, 5, 4, 7, 5, 4, 4, 5, 12, 0, 4, 4, 5, 3, 7, 3, 3, 5, 5, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 4, 5, 5, 5, 6, 4, 0, 3, 3, 5, 5, 12, 5, 3, 5, 4, 0, 3, 5, 6, 5, 6, 6, 4, 6, 5, 0, 3, 6, 5, 6, 7, 3, 6, 7, 4, 0, 3, 6, 4, 4, 21, 5, 5, 5, 4, 0, 3, 5, 4, 6, 6, 4, 5, 5, 4, 0, 3, 5, 4, 7, 30, 4, 4, 7, 5, 0, 3, 4, 7, 6, 5, 5, 5, 12, 6, 0, 4, 4, 4, 8, 5, 5, 5, 6, 5, 0, 3, 3, 3, 8, 9, 6, 6, 5, 5, 0, 3, 6, 4, 5, 13, 8, 5, 8, 5, 0, 3, 5, 6, 6, 11, 6, 3, 7, 5, 0, 5, 5, 5, 8, 11, 6, 4, 6, 6, 0, 6, 5, 5, 9, 8, 6, 4, 8, 6, 0, 5, 6, 6, 4, 9, 7, 5, 6, 4, 0, 5, 5, 4, 6, 32, 7, 5, 4, 4, 0, 4, 9, 4, 5, 5, 6, 5, 5, 8, 0, 4, 6, 6, 5, 6, 6, 13, 5, 9, 0, 8, 4, 4, 8, 7, 5, 7, 6, 5, 0, 3, 3, 6, 7, 12, 7, 4, 6, 5, 0, 3, 6, 6, 6, 14, 7, 5, 4, 6, 0, 6, 6, 6, 6, 9, 5, 5, 8, 8, 0, 6, 11, 6, 6, 9, 6, 7, 6, 6, 0, 5, 4, 4, 6, 6, 7, 7, 5, 6, 0, 5, 5, 7, 5, 12, 8, 5, 9, 9, 0, 4, 4, 4, 4, 7, 7, 4, 6, 6, 0, 5, 6, 6, 6, 18, 8, 4, 7, 4, 0, 5, 5, 6, 7, 14, 12, 4, 7, 6, 0, 7, 9, 8, 4, 12, 5, 4, 8, 6, 0, 3, 5, 5, 5, 10, 10, 7, 5, 5, 0, 7, 6, 5, 6, 13, 6, 6, 8, 6, 0, 6, 6, 7, 7, 10, 7, 4, 6, 5, 0, 5, 8, 6, 6, 5, 9, 6, 10, 7, 0, 7, 8, 6, 8, 18, 8, 8, 10, 5, 0, 7, 8, 5, 9, 7, 8, 8, 6, 5, 0, 8, 6, 8, 7, 15, 9, 6, 10, 7, 0, 6, 6, 7, 5, 14, 7, 8, 8, 7, 0, 5, 6, 5, 9, 27, 8, 5, 6, 8, 0, 6, 8, 7, 5, 20, 5, 8, 9, 5, 0, 3, 7, 5, 4, 5, 8, 7, 6, 7, 0, 6, 6, 5, 6, 15, 6, 5, 4, 5, 0, 5, 10, 7, 5, 12, 6, 4, 7, 6, 0, 7, 23, 7, 7, 12, 6, 4, 6, 5, 0, 5, 7, 9, 8, 61, 4, 4, 4, 4, 0, 4, 4, 8, 9, 14, 4, 6, 7, 6, 0, 4, 6, 6, 6, 12, 6, 7, 8, 7, 0, 8, 6, 7, 8, 5, 9, 5, 5, 5, 0, 5, 8, 8, 13, 10, 5, 7, 9, 6, 0, 7, 8, 9, 8, 18, 4, 4, 11, 7, 0, 3, 9, 8, 10, 9, 6, 5, 5, 5, 0, 5, 7, 5, 8, 23, 9, 8, 7, 9, 0, 5, 7, 6, 5, 6, 6, 4, 5, 5, 0, 7, 8, 10, 6, 13, 6, 7, 7, 7, 0, 6, 8, 6, 5, 10, 4, 5, 9, 5, 0, 7, 6, 7, 6, 7, 6, 6, 8, 7, 0, 7, 5, 5, 9, 13, 8, 7, 8, 4, 0, 5, 9, 5, 12, 16, 6, 6, 9, 7, 0, 5, 6, 12, 9, 9, 6, 5, 7, 6, 0, 7, 13, 7, 4, 15, 4, 4, 6, 6, 0, 3, 7, 5, 8, 18, 9, 6, 9, 6, 0, 8, 9, 5, 8, 12, 8, 6, 5, 5, 0, 6, 8, 9, 8, 15, 9, 4, 13, 7, 0, 5, 7, 8, 8, 9, 9, 6, 8, 8, 0, 8, 10, 6, 5, 7, 6, 5, 10, 7, 0, 7, 10, 5, 12, 12, 9, 6, 6, 8, 0, 8, 8, 6, 9, 14, 7, 6, 4, 8, 0, 7, 5, 5, 5, 16, 6, 8, 7, 7, 0, 6, 12, 5, 5, 13, 7, 7, 7, 5, 0, 5, 11, 8, 9, 11, 12, 7, 5, 6, 0, 3, 5, 8, 8, 14, 10, 6, 8, 6, 0, 9, 6, 6, 8, 34, 11, 8, 7, 8, 0, 8, 11, 6, 10, 16, 8, 6, 9, 5, 0, 8, 9, 7, 8, 16, 11, 6, 6, 5, 0, 6, 6, 9, 8, 5, 8, 5, 8, 8, 0, 6, 7, 8, 11, 14, 9, 8, 9, 10, 0, 6, 7, 4, 8, 6, 6, 6, 8, 6, 0, 8, 5, 6, 8, 14, 8, 6, 6, 6, 0, 13, 9, 5, 6, 15, 11, 9, 7, 9, 0, 8, 9, 8, 8, 15, 9, 8, 8, 12, 0, 3, 11, 7, 10, 15, 11, 6, 5, 8, 0, 7, 9, 9, 8, 53, 5, 5, 10, 9, 0, 8, 8, 6, 8, 20, 9, 8, 9, 6, 0, 7, 11, 8, 6, 12, 11, 5, 7, 8, 0, 5, 12, 7, 6, 13, 11, 8, 7, 6, 0, 9, 6, 10, 6, 15, 13, 6, 8, 6, 0, 6, 7, 6, 8, 18, 8, 7, 8, 8, 0, 7, 6, 8, 6, 14, 7, 9, 9, 11, 0, 8, 8, 6, 7, 8, 6, 11, 9, 21, 0, 6, 6, 8, 8, 15, 9, 7, 5, 8, 0, 5, 5, 7, 8, 11, 9, 9, 10, 8, 0, 5, 11, 8, 7, 17, 11, 7, 4, 6, 0, 8, 9, 7, 7, 13, 6, 4, 7, 6, 0, 8, 9, 8, 6, 18, 9, 8, 8, 9, 0, 7, 6, 9, 9, 15, 4, 4, 8, 9, 0, 7, 10, 8, 10, 15, 8, 7, 7, 8, 0, 11, 10, 6, 12, 14, 7, 9, 6, 10, 0, 8, 7, 10, 23, 15, 11, 8, 7, 12, 0, 6, 6, 7, 8, 12, 6, 7, 10, 13, 0, 5, 5, 6, 9, 9, 9, 9, 8, 9, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 13, 10, 7, 9, 8, 0, 4, 4, 8, 6, 14, 7, 6, 6, 7, 0, 4, 4, 7, 6, 9, 6, 8, 7, 8, 0, 4, 6, 5, 8, 21, 8, 11, 12, 8, 0, 4, 10, 9, 7, 14, 8, 7, 10, 5, 0, 4, 9, 5, 13, 15, 5, 8, 7, 8, 0, 4, 12, 8, 8, 15, 8, 7, 13, 10, 0, 4, 5, 6, 8, 13, 9, 6, 12, 8, 0, 5, 9, 8, 10, 15, 9, 9, 8, 8, 0, 4, 4, 4, 4, 21, 11, 7, 11, 10, 0, 4, 14, 7, 9, 18, 9, 6, 10, 8, 0, 4, 6, 11, 9, 5, 5, 5, 5, 5, 0, 4, 5, 5, 7, 13, 5, 7, 10, 5, 0, 12, 9, 7, 8, 10, 7, 5, 9, 5, 0, 8, 8, 9, 7, 21, 13, 8, 5, 5, 0, 5, 6, 8, 6, 13, 10, 9, 9, 5, 0, 7, 11, 6, 8, 14, 12, 12, 10, 7, 0, 6, 6, 8, 10, 38, 13, 6, 12, 8, 0, 11, 7, 9, 8, 20, 11, 7, 7, 7, 0, 4, 4, 7, 13, 7, 9, 7, 11, 6, 0, 4, 10, 6, 6, 15, 13, 8, 9, 6, 0, 6, 6, 8, 7, 15, 8, 8, 9, 9, 0, 6, 8, 7, 11, 14, 5, 9, 9, 5, 0, 9, 9, 8, 7, 52, 10, 5, 12, 6, 0, 9, 12, 9, 10, 50, 10, 7, 12, 7, 0, 8, 6, 6, 13, 32, 11, 10, 12, 5, 0, 9, 5, 9, 7, 14, 12, 6, 9, 5, 0, 8, 9, 8, 5, 13, 7, 10, 8, 9, 0, 8, 9, 8, 13, 16, 8, 10, 11, 6, 0, 4, 4, 11, 5, 12, 6, 8, 7, 9, 0, 4, 9, 5, 7, 18, 8, 9, 9, 10, 0, 11, 9, 8, 13, 15, 12, 7, 12, 5, 0, 6, 11, 6, 9, 12, 6, 7, 10, 11, 0, 8, 8, 6, 12, 15, 6, 5, 10, 5, 0, 8, 6, 7, 8, 14, 11, 9, 8, 6, 0, 7, 10, 6, 11, 15, 13, 6, 13, 5, 0, 7, 9, 7, 7, 27, 9, 11, 8, 8, 0, 5, 12, 9, 6, 14, 8, 8, 8, 11, 0, 9, 8, 6, 10, 14, 9, 8, 5, 11, 0, 4, 7, 5, 5, 21, 11, 9, 9, 6, 0, 11, 8, 5, 10, 12, 9, 8, 12, 7, 0, 8, 9, 8, 6, 7, 13, 7, 9, 9, 0, 8, 8, 8, 8, 18, 6, 7, 9, 8, 0, 9, 7, 8, 6, 16, 4, 9, 12, 8, 0, 8, 7, 10, 9, 6, 11, 10, 5, 5, 0, 6, 6, 6, 12, 21, 7, 6, 8, 5, 0, 9, 11, 10, 13, 14, 12, 9, 5, 5, 0, 10, 7, 5, 7, 18, 12, 7, 9, 9, 0, 10, 5, 5, 11, 14, 11, 10, 9, 8, 0, 4, 12, 8, 7, 15, 5, 7, 8, 6, 0, 8, 10, 11, 5, 14, 32, 5, 8, 10, 0, 6, 13, 7, 6, 17, 8, 10, 6, 5, 0, 8, 11, 7, 6, 11, 9, 5, 8, 8, 0, 7, 11, 8, 11, 14, 7, 9, 10, 10, 0, 7, 8, 6, 13, 61, 7, 8, 10, 8, 0, 7, 8, 5, 10, 9, 9, 8, 10, 5, 0, 5, 14, 12, 9, 19, 8, 8, 8, 8, 0, 9, 11, 7, 10, 15, 6, 7, 8, 6, 0, 7, 12, 6, 8, 18, 9, 9, 8, 11, 0, 4, 14, 5, 12, 14, 8, 8, 10, 12, 0, 8, 14, 8, 11, 15, 11, 7, 13, 7, 0, 8, 9, 5, 8, 9, 10, 7, 12, 7, 0, 9, 6, 8, 12, 15, 13, 10, 9, 7, 0, 13, 9, 10, 11, 21, 8, 6, 13, 8, 0, 7, 8, 9, 5, 12, 7, 6, 8, 10, 0, 9, 8, 5, 12, 16, 8, 8, 9, 8, 0, 8, 13, 6, 9, 12, 9, 9, 6, 9, 0, 7, 14, 8, 9, 17, 7, 6, 9, 8, 0, 7, 8, 9, 9, 16, 11, 7, 12, 10, 0, 4, 9, 6, 9, 21, 8, 10, 12, 9, 0, 6, 6, 9, 11, 29, 10, 9, 10, 8, 0, 8, 11, 9, 8, 17, 11, 8, 10, 8, 0, 8, 14, 10, 11, 21, 11, 7, 8, 10, 0, 10, 5, 5, 5, 16, 12, 5, 9, 9, 0, 7, 9, 6, 8, 14, 13, 10, 8, 5, 0, 9, 10, 5, 12, 23, 9, 8, 11, 9, 0, 12, 10, 10, 11, 6, 8, 9, 11, 5, 0, 10, 11, 5, 10, 12, 7, 8, 12, 9, 0, 8, 5, 7, 13, 15, 11, 11, 6, 8, 0, 4, 11, 9, 14, 13, 7, 9, 6, 10, 0, 5, 13, 10, 6, 34, 10, 10, 10, 10, 0, 11, 13, 6, 10, 13, 11, 8, 15, 10, 0, 9, 13, 7, 7, 13, 7, 8, 8, 12, 0, 9, 12, 6, 11, 17, 8, 9, 12, 8, 0, 9, 7, 7, 6, 10, 13, 8, 6, 9, 0, 11, 12, 6, 9, 14, 9, 11, 11, 10, 0, 7, 10, 10, 12, 14, 6, 11, 7, 11, 0, 8, 6, 8, 12, 7, 9, 13, 22, 10, 0, 6, 6, 11, 14, 12, 13, 10, 8, 7, 0, 5, 9, 7, 7, 14, 5, 10, 13, 5, 0, 11, 12, 8, 9, 13, 11, 10, 8, 10, 0, 7, 9, 9, 11, 30, 10, 4, 8, 8, 0, 8, 12, 11, 11, 15, 9, 7, 7, 8, 0, 6, 13, 10, 7, 23, 4, 8, 6, 7, 0, 6, 8, 9, 9, 14, 11, 7, 7, 11, 0, 7, 12, 11, 14, 17, 7, 9, 6, 13, 0, 7, 9, 8, 9, 21, 8, 8, 6, 8, 0, 9, 9, 11, 14, 11, 8, 6, 13, 8, 0, 5, 8, 7, 6, 13, 13, 9, 9, 7, 0, 4, 4, 4, 4, 20, 8, 8, 9, 9, 0, 4, 12, 8, 10, 13, 13, 7, 10, 8, 0, 4, 9, 9, 7, 11, 7, 6, 13, 11, 0, 4, 13, 10, 13, 22, 12, 10, 13, 9, 0, 6, 7, 9, 13, 14, 6, 8, 10, 7, 0, 8, 9, 8, 8, 15, 13, 8, 23, 5, 0, 8, 11, 5, 8, 15, 7, 6, 12, 9, 0, 6, 8, 11, 8, 13, 8, 8, 8, 7, 0, 8, 13, 11, 12, 18, 12, 9, 14, 11, 0, 8, 10, 9, 10, 21, 10, 6, 13, 7, 0, 4, 9, 8, 13, 15, 9, 11, 12, 9, 0, 8, 12, 5, 12, 5, 7, 9, 12, 9, 0, 8, 9, 9, 11, 9, 9, 8, 13, 8, 0, 10, 12, 5, 8, 10, 9, 8, 8, 7, 0, 9, 10, 11, 7, 23, 11, 8, 12, 9, 0, 10, 14, 7, 8, 7, 12, 7, 6, 6, 0, 11, 11, 9, 13, 90, 6, 12, 14, 7, 0, 7, 8, 9, 5, 8, 13, 6, 6, 6, 0, 9, 13, 10, 8, 12, 7, 10, 13, 8, 0, 11, 10, 12, 6, 11, 8, 8, 8, 11, 0, 4, 8, 8, 13, 14, 12, 6, 8, 6, 0, 6, 9, 8, 10, 21, 11, 9, 7, 6, 0, 6, 8, 8, 14, 19, 11, 8, 9, 9, 0, 10, 14, 13, 9, 16, 5, 12, 13, 5, 0, 9, 5, 8, 11, 16, 10, 8, 13, 8, 0, 8, 13, 11, 12, 21, 11, 10, 19, 9, 0, 9, 10, 11, 9, 15, 13, 11, 13, 5, 0, 11, 9, 9, 11, 13, 10, 8, 11, 10, 0, 7, 9, 7, 12, 14, 13, 9, 12, 6, 0, 8, 13, 7, 9, 56, 11, 10, 10, 9, 0, 4, 9, 7, 11, 15, 10, 11, 13, 6, 0, 7, 6, 5, 8, 26, 15, 6, 6, 8, 0, 7, 14, 8, 11, 16, 11, 11, 11, 17, 0, 10, 8, 10, 14, 15, 11, 12, 13, 8, 0, 9, 9, 8, 8, 7, 10, 9, 11, 8, 0, 10, 7, 9, 10, 14, 13, 8, 9, 9, 0, 9, 8, 10, 13, 45, 13, 7, 11, 11, 0, 11, 10, 10, 11, 21, 8, 10, 7, 10, 0, 9, 7, 11, 9, 15, 11, 7, 10, 11, 0, 9, 14, 10, 9, 18, 15, 11, 8, 11, 0, 10, 8, 6, 13, 17, 9, 8, 13, 13, 0, 11, 13, 8, 8, 92, 9, 9, 12, 11, 0, 8, 13, 9, 10, 16, 7, 7, 11, 10, 0, 8, 9, 11, 6, 19, 8, 5, 6, 9, 0, 7, 10, 6, 9, 12, 9, 9, 11, 9, 0, 7, 8, 10, 11, 21, 11, 7, 8, 8, 0, 6, 12, 8, 12, 8, 10, 8, 7, 10, 0, 7, 11, 9, 6, 22, 13, 6, 10, 9, 0, 9, 13, 10, 12, 16, 12, 7, 9, 8, 0, 9, 13, 8, 10, 22, 9, 10, 9, 10, 0, 9, 11, 11, 7, 18, 7, 10, 11, 11, 0, 7, 9, 10, 14, 15, 8, 7, 13, 10, 0, 6, 12, 7, 8, 18, 11, 11, 9, 5, 0, 12, 12, 8, 10, 10, 6, 10, 6, 10, 0, 7, 13, 11, 8, 21, 11, 5, 8, 7, 0, 9, 10, 11, 6, 10, 13, 11, 10, 9, 0, 7, 9, 13, 17, 14, 9, 6, 12, 5, 0, 9, 6, 9, 8, 15, 11, 6, 11, 10, 0, 11, 9, 11, 9, 20, 9, 10, 12, 8, 0, 9, 10, 9, 15, 14, 9, 8, 7, 12, 0, 6, 10, 9, 8, 15, 12, 7, 10, 11, 0, 8, 13, 12, 14, 16, 10, 13, 10, 8, 0, 6, 10, 8, 10, 15, 13, 7, 12, 8, 0, 10, 11, 6, 7, 20, 12, 9, 13, 7, 0, 8, 11, 7, 11, 14, 13, 10, 13, 11, 0, 12, 9, 11, 5, 16, 13, 7, 12, 13, 0, 7, 13, 8, 10, 189, 9, 10, 5, 5, 0, 5, 12, 5, 17, 7, 10, 9, 5, 8, 0, 9, 7, 8, 12, 14, 8, 9, 13, 6, 0, 7, 9, 5, 11, 22, 10, 12, 13, 8, 0, 8, 8, 10, 13, 15, 18, 6, 9, 12, 0, 8, 13, 7, 9, 15, 13, 9, 5, 8, 0, 8, 6, 12, 8, 12, 7, 9, 12, 8, 0, 8, 7, 10, 9, 22, 11, 8, 7, 6, 0, 13, 8, 5, 10, 11, 13, 13, 13, 7, 0, 13, 11, 10, 10, 23, 13, 11, 13, 12, 0, 12, 12, 8, 7, 12, 14, 6, 5, 9, 0, 11, 10, 9, 12, 16, 6, 13, 9, 10, 0, 7, 6, 13, 14, 15, 10, 8, 13, 8, 0, 6, 13, 12, 13, 10, 6, 6, 12, 11, 0, 7, 12, 9, 10, 23, 12, 7, 10, 10, 0, 7, 8, 10, 6, 30, 12, 11, 8, 9, 0, 8, 11, 10, 11, 19, 11, 8, 11, 8, 0, 11, 12, 11, 11, 11, 6, 7, 11, 8, 0, 8, 13, 12, 6, 21, 13, 11, 14, 10, 0, 10, 13, 7, 9, 12, 11, 13, 7, 10, 0, 10, 9, 9, 11, 20, 8, 8, 11, 7, 0, 8, 14, 10, 13, 18, 13, 10, 6, 10, 0, 11, 10, 9, 9, 17, 8, 21, 15, 12, 0, 11, 10, 6, 8, 17, 6, 7, 10, 11, 0, 9, 9, 11, 10, 21, 5, 8, 14, 8, 0, 7, 13, 11, 13, 32, 12, 8, 5, 8, 0, 9, 11, 6, 9, 10, 9, 4, 9, 10, 0, 8, 13, 7, 10, 21, 9, 10, 10, 11, 0, 11, 9, 5, 12, 20, 13, 8, 7, 11, 0, 7, 11, 10, 9, 17, 11, 9, 6, 12, 0, 6, 13, 5, 7, 27, 9, 13, 13, 8, 0, 8, 13, 8, 8, 21, 10, 6, 13, 8, 0, 9, 6, 9, 12, 18, 9, 7, 8, 8, 0, 8, 13, 11, 11, 21, 10, 10, 6, 8, 0, 4, 4, 7, 11, 16, 12, 6, 9, 9, 0, 4, 9, 11, 7, 139, 11, 11, 9, 11, 0, 8, 11, 9, 14, 21, 13, 10, 16, 10, 0, 10, 6, 10, 8, 33, 12, 9, 12, 8, 0, 8, 7, 8, 11, 18, 8, 8, 9, 9, 0, 6, 11, 11, 14, 15, 11, 8, 13, 9, 0, 8, 13, 5, 11, 6, 11, 12, 10, 10, 0, 8, 12, 11, 7, 24, 10, 10, 7, 11, 0, 9, 12, 10, 7, 21, 9, 6, 9, 10, 0, 9, 10, 9, 7, 12, 11, 12, 11, 12, 0, 4, 11, 11, 12, 12, 11, 9, 13, 6, 0, 8, 12, 11, 13, 23, 12, 10, 7, 11, 0, 10, 8, 8, 12, 23, 13, 10, 9, 11, 0, 8, 8, 9, 12, 23, 12, 7, 10, 13, 0, 13, 32, 12, 14, 15, 8, 8, 13, 12, 0, 11, 12, 7, 13, 9, 15, 13, 6, 8, 0, 6, 8, 8, 10, 23, 6, 9, 5, 7, 0, 10, 8, 9, 11, 12, 7, 12, 6, 11, 0, 11, 9, 13, 13, 17, 8, 13, 9, 11, 0, 13, 9, 6, 11, 17, 13, 7, 11, 8, 0, 9, 13, 8, 9, 9, 10, 12, 14, 11, 0, 11, 12, 8, 8, 20, 11, 11, 17, 8, 0, 9, 15, 9, 11, 11, 10, 7, 11, 11, 0, 9, 14, 8, 8, 18, 16, 9, 10, 9, 0, 6, 9, 10, 9, 27, 10, 11, 13, 8, 0, 9, 12, 8, 14, 14, 13, 6, 9, 14, 0, 9, 8, 10, 8, 13, 12, 10, 12, 8, 0, 7, 16, 7, 11, 16, 12, 8, 10, 10, 0, 12, 6, 9, 10, 18, 8, 9, 15, 8, 0, 9, 7, 9, 12, 18, 10, 8, 15, 10, 0, 11, 9, 9, 13, 18, 8, 11, 12, 11, 0, 6, 15, 8, 15, 23, 5, 10, 12, 12, 0, 10, 8, 11, 11, 9, 10, 8, 13, 7, 0, 8, 12, 10, 14, 22, 9, 13, 11, 10, 0, 7, 11, 8, 13, 10, 13, 5, 11, 5, 0, 6, 8, 7, 9, 27, 14, 12, 8, 12, 0, 11, 14, 10, 13, 19, 12, 8, 9, 5, 0, 11, 16, 10, 6, 15, 13, 7, 20, 9, 0, 11, 13, 12, 12, 15, 9, 11, 8, 11, 0, 12, 16, 10, 17, 19, 13, 12, 12, 10, 0, 11, 11, 13, 8, 33, 13, 10, 13, 5, 0, 10, 14, 8, 8, 15, 9, 8, 5, 9, 0, 8, 7, 10, 7, 32, 11, 9, 10, 14, 0, 13, 10, 13, 8, 18, 13, 10, 12, 9, 0, 10, 8, 9, 12, 21, 9, 11, 13, 11, 0, 11, 12, 9, 13, 19, 6, 10, 11, 8, 0, 12, 9, 12, 9, 36, 6, 11, 9, 6, 0, 7, 14, 10, 15, 23, 12, 11, 9, 8, 0, 6, 7, 8, 14, 15, 9, 8, 8, 10, 0, 10, 13, 11, 8, 19, 9, 12, 9, 8, 0, 9, 11, 12, 7, 15, 12, 8, 13, 10, 0, 9, 14, 8, 9, 12, 17, 11, 9, 6, 0, 9, 14, 10, 12, 14, 13, 7, 12, 10, 0, 10, 6, 7, 8, 21, 13, 6, 11, 10, 0, 9, 10, 12, 11, 23, 10, 10, 12, 9, 0, 9, 11, 13, 14, 18, 14, 7, 8, 12, 0, 8, 11, 12, 13, 21, 10, 7, 9, 5, 0, 6, 12, 8, 14, 20, 12, 8, 11, 10, 0, 11, 11, 7, 13, 15, 13, 10, 12, 12, 0, 7, 13, 9, 5, 5, 5, 5, 5, 9, 0, 5, 12, 12, 5, 14, 9, 5, 12, 7, 0, 11, 8, 6, 13, 14, 14, 5, 11, 11, 0, 8, 13, 8, 11, 13, 8, 5, 5, 9, 0, 9, 11, 7, 10, 14, 11, 5, 12, 6, 0, 9, 9, 13, 14, 24, 11, 11, 12, 9, 0, 9, 12, 7, 10, 16, 14, 9, 11, 12, 0, 5, 8, 11, 9, 16, 11, 5, 5, 8, 0, 10, 10, 10, 11, 24, 10, 12, 10, 11, 0, 8, 13, 9, 23, 21, 12, 9, 13, 8, 0, 9, 12, 12, 5, 15, 8, 5, 20, 10, 0, 8, 13, 9, 12, 12, 6, 9, 11, 11, 0, 7, 11, 12, 19, 13, 13, 7, 14, 8, 0, 13, 7, 9, 13, 6, 6, 5, 10, 6, 0, 6, 13, 10, 13, 16, 16, 9, 12, 6, 0, 8, 11, 9, 14, 20, 10, 9, 16, 6, 0, 13, 15, 8, 13, 15, 6, 9, 10, 7, 0, 10, 14, 11, 12, 14, 15, 12, 12, 13, 0, 10, 13, 10, 13, 109, 12, 11, 13, 5, 0, 8, 7, 8, 12, 17, 12, 13, 13, 7, 0, 13, 15, 13, 14, 23, 13, 13, 11, 11, 0, 8, 8, 9, 17, 21, 13, 11, 13, 11, 0, 8, 14, 9, 7, 19, 10, 7, 6, 8, 0, 8, 13, 12, 9, 13, 21, 5, 14, 8, 0, 11, 13, 9, 12, 7, 15, 14, 9, 8, 0, 13, 11, 6, 11, 14, 11, 9, 11, 9, 0, 9, 15, 11, 14, 15, 10, 7, 12, 6, 0, 11, 6, 8, 13, 15, 7, 11, 13, 6, 0, 11, 12, 10, 13, 14, 12, 6, 12, 12, 0, 9, 9, 9, 13, 14, 22, 7, 11, 8, 0, 10, 14, 9, 6, 20, 14, 8, 14, 11, 0, 12, 13, 9, 10, 18, 8, 9, 7, 9, 0, 13, 11, 11, 9, 12, 8, 11, 14, 11, 0, 11, 13, 11, 10, 14, 13, 5, 5, 11, 0, 12, 11, 6, 12, 21, 13, 5, 9, 9, 0, 15, 11, 12, 10, 14, 9, 8, 10, 13, 0, 12, 7, 10, 17, 52, 12, 8, 11, 10, 0, 9, 10, 13, 14, 18, 8, 10, 15, 11, 0, 7, 16, 9, 12, 16, 12, 11, 11, 12, 0, 9, 13, 12, 8, 61, 7, 10, 14, 7, 0, 10, 16, 9, 13, 18, 12, 7, 11, 11, 0, 4, 4, 12, 11, 21, 6, 9, 7, 6, 0, 4, 13, 6, 10, 34, 11, 9, 12, 8, 0, 12, 12, 12, 15, 22, 7, 5, 11, 12, 0, 7, 17, 9, 13, 17, 16, 11, 14, 12, 0, 11, 7, 6, 9, 18, 6, 10, 13, 13, 0, 6, 13, 7, 9, 17, 14, 9, 9, 12, 0, 10, 13, 8, 11, 23, 13, 9, 13, 10, 0, 11, 14, 5, 9, 19, 13, 9, 15, 9, 0, 10, 15, 6, 12, 21, 13, 9, 11, 11, 0, 10, 12, 11, 8, 13, 14, 9, 15, 12, 0, 4, 13, 9, 13, 21, 9, 9, 8, 10, 0, 10, 12, 5, 13, 23, 9, 11, 8, 8, 0, 9, 11, 14, 15, 25, 9, 11, 11, 13, 0, 7, 13, 10, 13, 12, 8, 9, 10, 8, 0, 8, 13, 12, 13, 30, 15, 12, 11, 12, 0, 7, 12, 13, 9, 16, 13, 10, 7, 5, 0, 9, 18, 9, 6, 21, 13, 10, 12, 8, 0, 9, 14, 10, 13, 18, 10, 11, 17, 12, 0, 9, 12, 11, 12, 18, 13, 8, 15, 13, 0, 10, 13, 11, 11, 21, 12, 8, 14, 6, 0, 10, 6, 12, 16, 8, 10, 11, 14, 11, 0, 6, 12, 9, 13, 19, 12, 7, 8, 6, 0, 13, 13, 9, 13, 12, 26, 7, 13, 9, 0, 11, 14, 9, 13, 25, 11, 12, 13, 13, 0, 7, 7, 11, 13, 17, 13, 9, 10, 11, 0, 8, 15, 10, 8, 21, 13, 10, 13, 9, 0, 5, 8, 9, 12, 23, 8, 5, 10, 11, 0, 8, 9, 10, 13, 13, 14, 10, 12, 12, 0, 10, 12, 11, 10, 15, 14, 9, 13, 7, 0, 9, 9, 12, 15, 20, 13, 11, 10, 10, 0, 12, 10, 11, 14, 14, 13, 12, 13, 6, 0, 12, 13, 11, 9, 30, 8, 13, 13, 12, 0, 9, 13, 8, 16, 15, 12, 5, 15, 9, 0, 11, 15, 11, 12, 6, 13, 8, 19, 11, 0, 8, 9, 8, 12, 27, 12, 12, 9, 10, 0, 13, 11, 9, 12, 17, 14, 10, 11, 14, 0, 9, 9, 5, 8, 17, 14, 9, 15, 9, 0, 12, 13, 7, 12, 21, 6, 11, 8, 12, 0, 9, 9, 6, 8, 22, 8, 11, 10, 14, 0, 11, 13, 9, 12, 18, 12, 10, 13, 6, 0, 7, 14, 6, 8, 15, 12, 11, 13, 8, 0, 9, 12, 6, 14, 19, 16, 13, 8, 13, 0, 11, 12, 11, 10, 15, 7, 8, 14, 11, 0, 10, 14, 7, 11, 28, 12, 11, 13, 10, 0, 9, 6, 9, 12, 15, 14, 10, 11, 13, 0, 13, 9, 13, 8, 21, 13, 8, 5, 5, 0, 11, 14, 9, 8, 23, 12, 7, 13, 5, 0, 12, 13, 7, 13, 15, 10, 10, 8, 10, 0, 10, 13, 8, 14, 23, 13, 10, 8, 11, 0, 10, 13, 11, 10, 7, 16, 13, 13, 10, 0, 7, 8, 10, 10, 15, 8, 9, 11, 12, 0, 10, 10, 13, 12, 53, 13, 8, 13, 11, 0, 10, 12, 9, 6, 19, 8, 13, 6, 10, 0, 7, 12, 7, 9, 16, 12, 8, 10, 7, 0, 8, 11, 13, 14, 17, 15, 12, 10, 8, 0, 12, 6, 10, 11, 18, 11, 12, 14, 7, 0, 9, 11, 9, 16, 34, 9, 12, 9, 5, 0, 7, 13, 9, 14, 14, 14, 13, 11, 11, 0, 10, 9, 11, 12, 15, 13, 7, 11, 12, 0, 14, 12, 10, 5, 18, 8, 5, 12, 11, 0, 8, 10, 6, 17, 21, 13, 13, 14, 8, 0, 15, 15, 8, 13, 29, 16, 8, 12, 10, 0, 11, 12, 13, 13, 12, 40, 5, 12, 13, 0, 9, 13, 9, 10, 17, 11, 12, 9, 10, 0, 8, 13, 12, 14, 18, 13, 10, 12, 13, 0, 9, 14, 8, 9, 18, 15, 8, 15, 9, 0, 8, 10, 10, 12, 20, 11, 14, 17, 12, 0, 11, 7, 13, 13, 21, 13, 7, 12, 11, 0, 7, 14, 10, 9, 16, 12, 9, 6, 12, 0, 12, 13, 10, 13, 15, 7, 11, 9, 7, 0, 7, 11, 11, 14, 19, 11, 16, 13, 9, 0, 12, 12, 7, 9, 33, 14, 8, 11, 8, 0, 6, 14, 13, 16, 17, 13, 6, 6, 9, 0, 7, 7, 9, 6, 15, 13, 8, 8, 9, 0, 12, 15, 12, 14, 16, 6, 6, 9, 7, 0, 10, 12, 9, 14, 23, 12, 11, 11, 12, 0, 9, 11, 9, 15, 18, 11, 7, 36, 12, 0, 11, 12, 14, 8, 21, 14, 11, 14, 9, 0, 10, 11, 6, 15, 28, 13, 11, 12, 9, 0, 11, 13, 8, 9, 21, 12, 10, 8, 10, 0, 10, 14, 8, 22, 8, 13, 13, 12, 8, 0, 12, 12, 8, 7, 33, 13, 12, 10, 7, 0, 12, 13, 14, 8, 15, 9, 9, 9, 12, 0, 13, 12, 10, 8, 14, 13, 9, 13, 10, 0, 12, 13, 11, 7, 15, 11, 9, 11, 9, 0, 12, 13, 7, 10, 15, 11, 7, 11, 10, 0, 9, 8, 9, 10, 20, 11, 10, 15, 9, 0, 8, 12, 7, 7, 16, 13, 10, 9, 10, 0, 10, 13, 12, 12, 78, 10, 13, 17, 11, 0, 8, 12, 10, 14, 18, 14, 11, 12, 12, 0, 14, 15, 11, 13, 17, 8, 13, 12, 11, 0, 10, 14, 14, 8, 23, 12, 12, 13, 13, 0, 12, 9, 8, 17, 21, 13, 5, 14, 9, 0, 11, 11, 14, 13, 17, 14, 10, 8, 13, 0, 6, 12, 11, 15, 21, 12, 13, 11, 10, 0, 8, 12, 8, 13, 16, 18, 11, 12, 9, 0, 7, 11, 10, 11, 12, 11, 10, 13, 14, 0, 11, 12, 10, 9, 21, 14, 11, 6, 9, 0, 7, 8, 8, 14, 21, 6, 6, 12, 12, 0, 13, 15, 8, 13, 15, 12, 10, 9, 10, 0, 4, 9, 10, 12, 22, 12, 12, 15, 12, 0, 10, 13, 13, 8, 17, 12, 11, 11, 14, 0, 9, 11, 8, 9, 17, 14, 8, 8, 5, 0, 8, 12, 12, 12, 17, 13, 11, 13, 12, 0, 8, 10, 10, 13, 19, 9, 12, 12, 10, 0, 10, 14, 12, 11, 15, 14, 9, 12, 8, 0, 11, 14, 9, 11, 21, 10, 9, 17, 9, 0, 8, 14, 9, 13, 20, 11, 9, 12, 9, 0, 9, 12, 10, 10, 21, 9, 8, 12, 12, 0, 10, 11, 12, 13, 9, 10, 11, 10, 9, 0, 13, 9, 8, 18, 10, 9, 7, 13, 8, 0, 11, 9, 13, 11, 32, 14, 14, 7, 10, 0, 11, 14, 11, 14, 15, 12, 11, 13, 12, 0, 13, 17, 13, 9, 17, 12, 14, 14, 14, 0, 8, 8, 13, 12, 22, 13, 8, 13, 10, 0, 8, 12, 14, 15, 21, 7, 6, 8, 8, 0, 6, 11, 10, 13, 23, 9, 12, 5, 12, 0, 11, 13, 12, 12, 10, 8, 11, 10, 9, 0, 6, 6, 8, 10, 12, 6, 11, 10, 7, 0, 6, 13, 5, 13, 17, 13, 13, 8, 10, 0, 9, 11, 9, 18, 15, 8, 13, 15, 8, 0, 9, 15, 12, 10, 24, 12, 8, 13, 11, 0, 12, 13, 9, 14, 31, 10, 11, 18, 12, 0, 6, 12, 8, 14, 14, 13, 12, 17, 12, 0, 12, 9, 9, 11, 12, 12, 8, 13, 13, 0, 9, 13, 11, 6, 36, 13, 12, 8, 7, 0, 11, 14, 7, 10, 14, 17, 13, 14, 14, 0, 13, 13, 9, 9, 21, 13, 8, 9, 8, 0, 6, 12, 11, 13, 12, 14, 8, 8, 8, 0, 12, 16, 12, 10, 26, 14, 12, 19, 13, 0, 7, 9, 8, 8, 18, 7, 11, 12, 11, 0, 11, 14, 10, 16, 23, 13, 10, 8, 12, 0, 7, 12, 11, 12, 13, 13, 9, 11, 6, 0, 11, 16, 13, 13, 27, 13, 13, 14, 10, 0, 12, 10, 8, 13, 12, 11, 11, 8, 11, 0, 13, 14, 6, 10, 21, 14, 11, 10, 13, 0, 12, 14, 10, 7, 29, 12, 9, 13, 8, 0, 9, 11, 12, 11, 20, 20, 12, 13, 13, 0, 13, 12, 8, 14, 19, 13, 11, 15, 9, 0, 10, 8, 11, 11, 17, 7, 10, 11, 11, 0, 13, 13, 8, 10, 20, 15, 13, 15, 11, 0, 11, 12, 11, 9, 17, 14, 8, 5, 13, 0, 9, 13, 10, 14, 21, 16, 11, 16, 9, 0, 7, 10, 11, 13, 27, 14, 13, 10, 10, 0, 7, 9, 11, 12, 129, 5, 5, 5, 5, 0, 5, 5, 13, 12, 16, 5, 9, 18, 10, 0, 5, 10, 12, 9, 25, 5, 9, 17, 12, 0, 14, 9, 7, 7, 15, 9, 9, 12, 7, 0, 11, 8, 9, 14, 22, 13, 11, 13, 11, 0, 13, 11, 10, 9, 14, 5, 5, 11, 10, 0, 5, 10, 11, 15, 23, 14, 9, 12, 13, 0, 10, 15, 10, 8, 29, 14, 13, 13, 9, 0, 8, 18, 11, 13, 11, 9, 9, 13, 12, 0, 10, 12, 13, 14, 18, 14, 14, 11, 11, 0, 9, 13, 11, 11, 18, 5, 12, 8, 14, 0, 13, 13, 13, 11, 30, 12, 8, 13, 7, 0, 9, 7, 11, 13, 16, 13, 13, 16, 5, 0, 9, 14, 10, 13, 18, 14, 11, 9, 7, 0, 12, 11, 10, 14, 24, 7, 9, 60, 13, 0, 10, 13, 8, 12, 17, 5, 11, 10, 8, 0, 15, 14, 7, 15, 20, 13, 11, 14, 13, 0, 12, 13, 10, 13, 20, 10, 9, 10, 8, 0, 11, 13, 6, 16, 41, 13, 11, 13, 13, 0, 9, 14, 13, 15, 18, 12, 9, 7, 11, 0, 11, 14, 8, 6, 23, 5, 13, 9, 10, 0, 13, 15, 11, 10, 25, 16, 12, 12, 11, 0, 13, 6, 11, 16, 34, 12, 12, 10, 10, 0, 10, 13, 11, 11, 14, 14, 12, 14, 8, 0, 6, 10, 13, 13, 18, 13, 12, 11, 8, 0, 13, 12, 13, 15, 21, 14, 11, 14, 12, 0, 9, 6, 10, 21, 19, 12, 10, 17, 12, 0, 7, 7, 9, 12, 28, 13, 8, 13, 10, 0, 11, 13, 11, 18, 15, 13, 7, 10, 9, 0, 12, 12, 12, 8, 24, 12, 13, 6, 6, 0, 7, 12, 11, 11, 18, 14, 13, 12, 6, 0, 9, 11, 8, 11, 23, 17, 6, 11, 6, 0, 15, 17, 5, 13, 15, 12, 10, 14, 7, 0, 14, 16, 9, 12, 21, 13, 13, 20, 9, 0, 10, 6, 12, 14, 29, 11, 13, 14, 10, 0, 11, 12, 10, 14, 15, 15, 9, 18, 14, 0, 13, 13, 13, 14, 30, 14, 12, 13, 15, 0, 7, 14, 13, 13, 21, 11, 10, 9, 9, 0, 12, 16, 9, 13, 16, 16, 11, 11, 12, 0, 10, 13, 7, 9, 10, 10, 9, 11, 13, 0, 9, 14, 7, 12, 21, 11, 11, 14, 10, 0, 11, 27, 9, 15, 17, 15, 13, 13, 12, 0, 9, 13, 8, 14, 20, 6, 14, 17, 11, 0, 10, 14, 13, 19, 26, 9, 12, 9, 11, 0, 13, 8, 13, 22, 29, 15, 18, 19, 8, 0, 10, 11, 6, 14, 16, 8, 8, 8, 12, 0, 9, 14, 12, 19, 12, 14, 9, 16, 8, 0, 13, 14, 13, 9, 17, 11, 11, 13, 10, 0, 16, 14, 14, 13, 16, 14, 5, 13, 12, 0, 9, 7, 10, 13, 22, 12, 11, 29, 8, 0, 12, 12, 12, 13, 16, 5, 5, 12, 6, 0, 5, 10, 12, 14, 14, 12, 13, 9, 12, 0, 14, 9, 14, 15, 21, 9, 10, 13, 13, 0, 11, 17, 11, 13, 19, 7, 11, 10, 7, 0, 11, 9, 7, 12, 23, 14, 11, 13, 13, 0, 9, 11, 8, 9, 61, 5, 11, 12, 13, 0, 4, 13, 7, 8, 17, 7, 15, 15, 10, 0, 8, 13, 8, 11, 18, 13, 8, 12, 11, 0, 9, 11, 10, 9, 15, 6, 9, 13, 16, 0, 7, 6, 11, 27, 20, 15, 12, 7, 12, 0, 13, 13, 12, 13, 29, 13, 8, 14, 10, 0, 9, 16, 7, 13, 29, 8, 13, 8, 13, 0, 8, 13, 6, 6, 23, 16, 10, 12, 6, 0, 10, 12, 11, 6, 22, 13, 10, 12, 9, 0, 7, 13, 12, 7, 24, 9, 8, 11, 10, 0, 13, 8, 10, 13, 23, 16, 11, 11, 7, 0, 13, 14, 10, 16, 31, 12, 9, 14, 12, 0, 8, 15, 9, 16, 19, 16, 11, 11, 6, 0, 9, 12, 8, 6, 21, 9, 13, 13, 8, 0, 10, 10, 15, 9, 18, 13, 9, 7, 10, 0, 13, 11, 9, 13, 21, 13, 8, 14, 14, 0, 8, 8, 11, 11, 18, 13, 8, 14, 6, 0, 8, 13, 9, 16, 11, 17, 10, 10, 11, 0, 14, 14, 12, 6, 17, 10, 12, 8, 9, 0, 6, 13, 13, 13, 15, 12, 10, 16, 12, 0, 8, 13, 13, 7, 26, 8, 10, 11, 12, 0, 12, 13, 9, 14, 13, 9, 14, 14, 8, 0, 12, 14, 10, 11, 32, 17, 7, 14, 10, 0, 15, 11, 10, 12, 17, 13, 11, 10, 11, 0, 7, 15, 10, 16, 21, 9, 12, 11, 13, 0, 8, 14, 11, 12, 17, 10, 11, 13, 11, 0, 11, 11, 13, 14, 22, 13, 12, 10, 13, 0, 13, 10, 13, 16, 13, 7, 8, 13, 9, 0, 7, 12, 12, 14, 10, 15, 13, 7, 5, 0, 10, 11, 11, 17, 26, 9, 10, 10, 9, 0, 12, 9, 11, 10, 18, 12, 10, 7, 11, 0, 12, 11, 11, 16, 23, 14, 11, 13, 12, 0, 11, 12, 8, 11, 25, 13, 9, 16, 10, 0, 9, 16, 13, 10, 28, 13, 11, 12, 9, 0, 11, 10, 10, 13, 25, 11, 10, 18, 11, 0, 14, 12, 11, 13, 13, 7, 10, 16, 9, 0, 11, 13, 10, 19, 14, 9, 12, 13, 12, 0, 13, 14, 12, 13, 53, 9, 13, 13, 12, 0, 14, 8, 8, 8, 32, 14, 8, 12, 13, 0, 10, 12, 10, 13, 15, 10, 11, 13, 11, 0, 8, 15, 11, 32, 16, 16, 12, 14, 11, 0, 9, 19, 13, 14, 20, 14, 11, 14, 11, 0, 13, 11, 8, 15, 21, 11, 10, 13, 11, 0, 11, 15, 13, 13, 19, 6, 10, 17, 10, 0, 12, 6, 6, 8, 20, 14, 12, 10, 11, 0, 9, 13, 9, 18, 15, 5, 15, 11, 13, 0, 10, 12, 13, 8, 21, 9, 8, 13, 12, 0, 12, 11, 11, 15, 15, 13, 10, 13, 13, 0, 10, 17, 6, 9, 18, 14, 12, 13, 7, 0, 11, 8, 10, 17, 6, 9, 13, 15, 12, 0, 12, 16, 9, 9, 25, 14, 10, 11, 13, 0, 11, 17, 10, 7, 29, 11, 12, 11, 14, 0, 13, 12, 11, 13, 15, 19, 10, 9, 10, 0, 16, 10, 13, 18, 15, 16, 11, 16, 10, 0, 14, 13, 10, 12, 15, 8, 11, 12, 9, 0, 12, 11, 8, 14, 25, 18, 12, 14, 10, 0, 9, 18, 15, 15, 20, 19, 12, 11, 9, 0, 11, 19, 9, 17, 26, 15, 9, 13, 11, 0, 9, 13, 14, 14, 21, 8, 9, 20, 7, 0, 9, 18, 13, 9, 17, 10, 14, 9, 9, 0, 12, 11, 10, 18, 21, 13, 14, 9, 10, 0, 14, 10, 6, 13, 17, 15, 14, 17, 9, 0, 13, 9, 12, 14, 16, 15, 9, 14, 6, 0, 14, 13, 9, 6, 23, 12, 11, 14, 8, 0, 10, 13, 13, 8, 15, 15, 12, 11, 13, 0, 11, 12, 11, 12, 25, 12, 9, 13, 11, 0, 11, 13, 10, 16, 33, 7, 11, 13, 11, 0, 8, 12, 7, 12, 52, 10, 9, 14, 11, 0, 13, 13, 11, 6, 20, 14, 12, 14, 9, 0, 12, 8, 12, 10, 21, 16, 12, 14, 13, 0, 7, 9, 13, 7, 21, 12, 13, 12, 8, 0, 6, 10, 11, 16, 18, 15, 7, 15, 9, 0, 11, 13, 14, 14, 109, 13, 9, 13, 13, 0, 13, 8, 7, 18, 14, 12, 9, 13, 11, 0, 14, 17, 7, 15, 38, 8, 12, 15, 12, 0, 14, 5, 8, 11, 21, 12, 9, 14, 12, 0, 8, 16, 15, 13, 18, 13, 12, 11, 8, 0, 9, 10, 9, 11, 52, 13, 9, 7, 10, 0, 11, 8, 12, 13, 12, 12, 7, 14, 10, 0, 13, 9, 9, 13, 17, 14, 8, 12, 11, 0, 10, 7, 11, 11, 17, 11, 12, 13, 13, 0, 8, 13, 12, 14, 15, 11, 10, 15, 9, 0, 10, 15, 15, 8, 20, 14, 11, 16, 7, 0, 11, 14, 10, 15, 21, 8, 9, 15, 13, 0, 12, 13, 11, 14, 23, 14, 6, 13, 12, 0, 6, 12, 12, 8, 17, 11, 6, 7, 9, 0, 10, 17, 13, 16, 18, 14, 14, 6, 8, 0, 11, 13, 13, 7, 21, 20, 10, 16, 14, 0, 13, 11, 12, 13, 32, 19, 8, 12, 7, 0, 14, 16, 21, 11, 21, 8, 12, 11, 8, 0, 12, 14, 9, 16, 21, 12, 6, 18, 10, 0, 13, 13, 10, 14, 11, 12, 9, 15, 9, 0, 11, 18, 13, 19, 32, 15, 14, 8, 13, 0, 11, 13, 7, 14, 16, 13, 5, 5, 8, 0, 12, 11, 8, 14, 16, 23, 5, 10, 7, 0, 11, 9, 12, 8, 10, 5, 11, 16, 8, 0, 12, 14, 9, 7, 26, 10, 12, 10, 12, 0, 9, 16, 11, 14, 24, 10, 8, 17, 7, 0, 13, 13, 11, 10, 17, 16, 10, 12, 11, 0, 11, 13, 10, 12, 21, 14, 10, 11, 12, 0, 13, 10, 7, 19, 11, 11, 13, 12, 14, 0, 4, 9, 13, 11, 14, 13, 13, 16, 11, 0, 9, 11, 9, 12, 21, 12, 9, 13, 8, 0, 12, 6, 10, 14, 21, 15, 5, 11, 13, 0, 7, 19, 14, 9, 14, 13, 10, 9, 11, 0, 10, 11, 12, 13, 21, 9, 13, 15, 9, 0, 8, 13, 7, 14, 20, 11, 10, 15, 13, 0, 10, 12, 11, 15, 22, 9, 10, 9, 11, 0, 14, 13, 6, 9, 26, 8, 12, 14, 10, 0, 13, 9, 11, 13, 14, 8, 9, 11, 12, 0, 8, 15, 10, 13, 18, 17, 11, 14, 7, 0, 8, 9, 11, 18, 64, 14, 12, 12, 12, 0, 15, 17, 14, 11, 13, 12, 13, 7, 13, 0, 11, 12, 7, 13, 27, 13, 11, 10, 8, 0, 13, 13, 12, 14, 20, 14, 9, 10, 12, 0, 13, 17, 13, 14, 18, 9, 6, 18, 7, 0, 8, 10, 11, 18, 20, 14, 11, 12, 11, 0, 8, 13, 9, 15, 26, 12, 9, 16, 11, 0, 13, 10, 8, 6, 24, 18, 10, 8, 8, 0, 9, 13, 7, 11, 22, 14, 13, 12, 12, 0, 8, 11, 5, 10, 16, 12, 11, 11, 15, 0, 12, 19, 13, 11, 18, 13, 17, 10, 13, 0, 11, 19, 13, 13, 26, 14, 12, 21, 10, 0, 13, 14, 9, 16, 21, 8, 10, 18, 13, 0, 14, 13, 13, 13, 23, 13, 13, 14, 12, 0, 14, 10, 9, 14, 25, 9, 8, 15, 8, 0, 7, 10, 13, 12, 7, 14, 13, 14, 10, 0, 9, 12, 8, 13, 15, 14, 13, 13, 12, 0, 13, 15, 13, 11, 15, 7, 11, 13, 9, 0, 13, 13, 13, 12, 15, 12, 10, 13, 13, 0, 8, 12, 12, 13, 17, 15, 13, 12, 11, 0, 11, 12, 12, 11, 16, 13, 11, 12, 11, 0, 14, 13, 8, 21, 45, 13, 11, 13, 8, 0, 10, 11, 12, 13, 18, 12, 11, 12, 9, 0, 13, 11, 11, 8, 14, 17, 10, 14, 10, 0, 8, 14, 9, 11, 21, 20, 10, 19, 10, 0, 13, 15, 8, 13, 15, 13, 11, 11, 12, 0, 13, 8, 14, 8, 33, 7, 14, 10, 11, 0, 10, 9, 13, 11, 15, 10, 10, 13, 8, 0, 7, 11, 13, 14, 20, 12, 11, 10, 15, 0, 13, 9, 9, 13, 25, 15, 14, 14, 11, 0, 12, 11, 11, 13, 20, 12, 13, 17, 13, 0, 13, 15, 7, 13, 14, 7, 13, 10, 11, 0, 11, 14, 10, 18, 32, 14, 11, 15, 11, 0, 13, 13, 10, 8, 21, 14, 11, 9, 10, 0, 9, 11, 10, 13, 27, 5, 13, 11, 8, 0, 12, 16, 12, 10, 24, 13, 10, 11, 13, 0, 13, 10, 13, 15, 92, 10, 11, 13, 7, 0, 13, 11, 12, 14, 53, 17, 11, 23, 15, 0, 9, 14, 8, 10, 18, 13, 14, 8, 9, 0, 10, 18, 10, 12, 21, 15, 10, 11, 10, 0, 13, 8, 7, 11, 21, 20, 12, 17, 8, 0, 11, 8, 12, 13, 12, 11, 11, 12, 11, 0, 14, 6, 10, 9, 23, 11, 8, 11, 13, 0, 12, 15, 7, 13, 30, 13, 11, 19, 12, 0, 10, 13, 7, 13, 15, 14, 11, 8, 6, 0, 8, 13, 12, 15, 12, 13, 12, 14, 9, 0, 9, 6, 9, 14, 24, 10, 14, 16, 11, 0, 10, 14, 13, 13, 20, 10, 12, 16, 12, 0, 14, 17, 16, 14, 21, 13, 11, 17, 11, 0, 9, 13, 13, 11, 14, 16, 8, 14, 11, 0, 7, 10, 6, 13, 19, 17, 16, 17, 8, 0, 9, 29, 7, 15, 23, 12, 9, 13, 10, 0, 9, 10, 8, 9, 25, 12, 10, 10, 14, 0, 8, 10, 9, 16, 14, 11, 12, 13, 9, 0, 9, 15, 8, 19, 22, 12, 6, 14, 15, 0, 10, 14, 11, 13, 17, 12, 10, 14, 13, 0, 10, 12, 9, 15, 23, 13, 7, 5, 11, 0, 13, 13, 10, 7, 19, 17, 9, 13, 9, 0, 7, 14, 9, 14, 25, 13, 13, 16, 9, 0, 15, 17, 11, 15, 13, 13, 13, 18, 8, 0, 10, 14, 7, 14, 22, 11, 14, 14, 6, 0, 13, 11, 6, 11, 29, 12, 11, 17, 11, 0, 12, 13, 11, 17, 19, 13, 11, 15, 11, 0, 13, 8, 14, 14, 18, 14, 7, 7, 13, 0, 10, 13, 11, 13, 21, 6, 12, 8, 16, 0, 9, 8, 12, 13, 22, 12, 14, 9, 12, 0, 13, 21, 12, 16, 21, 14, 13, 9, 10, 0, 7, 18, 11, 13, 11, 12, 12, 19, 12, 0, 7, 15, 6, 15, 24, 15, 9, 15, 13, 0, 12, 13, 8, 11, 18, 6, 7, 11, 12, 0, 13, 11, 11, 13, 22, 19, 9, 9, 12, 0, 11, 11, 12, 17, 28, 19, 11, 14, 12, 0, 8, 10, 9, 18, 10, 14, 6, 6, 13, 0, 13, 11, 10, 6, 16, 16, 10, 13, 8, 0, 11, 13, 8, 14, 33, 13, 13, 6, 11, 0, 13, 12, 13, 12, 21, 19, 12, 13, 12, 0, 8, 12, 11, 14, 32, 14, 10, 12, 9, 0, 11, 14, 14, 9, 15, 14, 9, 13, 13, 0, 12, 22, 9, 13, 10, 14, 10, 16, 7, 0, 12, 16, 10, 14, 19, 14, 12, 6, 13, 0, 13, 14, 10, 13, 22, 14, 11, 12, 13, 0, 7, 17, 12, 13, 26, 10, 13, 13, 13, 0, 8, 19, 10, 12, 23, 7, 5, 13, 13, 0, 11, 15, 13, 11, 23, 13, 13, 18, 10, 0, 11, 8, 7, 11, 21, 14, 13, 14, 9, 0, 6, 14, 12, 13, 16, 15, 13, 10, 10, 0, 9, 13, 11, 12, 28, 14, 11, 17, 11, 0, 14, 16, 8, 11, 34, 12, 11, 12, 10, 0, 10, 13, 7, 14, 18, 10, 8, 16, 12, 0, 14, 18, 9, 11, 23, 18, 13, 10, 10, 0, 4, 19, 10, 13, 21, 10, 11, 14, 9, 0, 13, 12, 12, 7, 25, 10, 13, 17, 7, 0, 12, 12, 11, 13, 24, 13, 8, 10, 9, 0, 13, 14, 11, 10, 28, 15, 8, 15, 13, 0, 12, 8, 13, 10, 14, 15, 11, 15, 13, 0, 13, 14, 13, 16, 22, 14, 9, 12, 14, 0, 7, 14, 10, 13, 23, 14, 12, 14, 13, 0, 13, 13, 14, 14, 20, 16, 12, 8, 9, 0, 14, 7, 6, 17, 32, 17, 13, 13, 13, 0, 13, 10, 12, 16, 15, 14, 10, 13, 7, 0, 13, 12, 9, 12, 13, 13, 13, 15, 13, 0, 13, 11, 12, 11, 19, 13, 8, 11, 13, 0, 13, 13, 10, 18, 28, 7, 10, 16, 12, 0, 10, 13, 12, 13, 15, 7, 12, 10, 15, 0, 8, 11, 13, 15, 24, 12, 9, 16, 17, 0, 13, 14, 8, 12, 14, 12, 13, 15, 11, 0, 14, 11, 10, 13, 29, 11, 13, 15, 13, 0, 9, 9, 13, 17, 30, 11, 8, 19, 11, 0, 9, 16, 11, 17, 23, 14, 13, 13, 9, 0, 11, 12, 11, 12, 26, 14, 13, 9, 12, 0, 12, 15, 11, 14, 20, 13, 7, 14, 11, 0, 16, 17, 13, 13, 195, 14, 10, 9, 9, 0, 10, 14, 12, 13, 17, 10, 8, 15, 13, 0, 8, 11, 13, 13, 16, 19, 12, 11, 13, 0, 13, 22, 11, 14, 7, 13, 8, 19, 12, 0, 13, 11, 13, 14, 20, 15, 8, 15, 10, 0, 12, 13, 14, 9, 9, 15, 13, 12, 13, 0, 15, 14, 13, 15, 21, 14, 11, 13, 11, 0, 15, 14, 11, 13, 22, 11, 11, 12, 13, 0, 15, 16, 7, 12, 22, 13, 14, 11, 11, 0, 7, 14, 12, 9, 27, 18, 12, 14, 14, 0, 13, 12, 10, 14, 21, 12, 9, 13, 11, 0, 15, 11, 10, 17, 21, 8, 7, 17, 11, 0, 11, 13, 12, 12, 15, 11, 9, 18, 13, 0, 10, 14, 14, 17, 16, 8, 13, 12, 14, 0, 11, 9, 8, 15, 23, 15, 7, 15, 10, 0, 9, 9, 11, 13, 23, 11, 7, 13, 9, 0, 9, 7, 8, 13, 14, 15, 14, 13, 12, 0, 12, 8, 8, 16, 19, 13, 12, 14, 13, 0, 14, 8, 9, 13, 29, 15, 10, 13, 10, 0, 9, 15, 13, 12, 14, 11, 13, 12, 14, 0, 13, 12, 13, 13, 32, 18, 15, 9, 13, 0, 11, 13, 13, 12, 23, 7, 12, 11, 10, 0, 11, 15, 7, 22, 25, 13, 6, 6, 12, 0, 11, 16, 13, 16, 6, 12, 6, 14, 13, 0, 13, 15, 7, 14, 20, 14, 10, 13, 8, 0, 18, 10, 12, 13, 26, 20, 12, 12, 10, 0, 7, 14, 13, 12, 29, 13, 10, 13, 11, 0, 12, 19, 13, 17, 29, 15, 12, 15, 16, 0, 12, 12, 11, 13, 16, 14, 12, 11, 10, 0, 11, 12, 13, 12, 23, 14, 14, 12, 11, 0, 8, 14, 12, 6, 15, 12, 6, 16, 7, 0, 11, 12, 16, 13, 28, 14, 14, 13, 7, 0, 11, 6, 11, 13, 18, 10, 6, 16, 11, 0, 6, 12, 9, 12, 18, 12, 12, 6, 6, 0, 13, 15, 9, 15, 18, 13, 10, 13, 12, 0, 11, 26, 11, 15, 26, 13, 8, 9, 13, 0, 9, 14, 10, 14, 21, 9, 16, 14, 13, 0, 12, 11, 12, 13, 30, 13, 17, 15, 13, 0, 6, 12, 11, 7, 16, 18, 11, 13, 13, 0, 12, 13, 11, 14, 18, 12, 10, 13, 12, 0, 13, 9, 7, 15, 19, 12, 14, 13, 11, 0, 11, 13, 11, 16, 17, 13, 9, 12, 13, 0, 12, 13, 10, 8, 28, 14, 9, 12, 7, 0, 14, 8, 12, 14, 21, 10, 13, 17, 10, 0, 11, 14, 9, 9, 18, 13, 11, 13, 10, 0, 12, 15, 11, 19, 54, 12, 12, 13, 14, 0, 13, 17, 11, 13, 10, 17, 9, 10, 11, 0, 10, 16, 13, 15, 23, 18, 14, 19, 14, 0, 14, 11, 10, 9, 19, 17, 8, 15, 12, 0, 13, 13, 10, 11, 24, 20, 8, 13, 13, 0, 12, 15, 14, 11, 20, 12, 12, 14, 13, 0, 9, 13, 13, 12, 22, 16, 10, 6, 8, 0, 11, 18, 13, 13, 11, 17, 11, 16, 12, 0, 8, 8, 8, 13, 21, 13, 13, 15, 14, 0, 13, 15, 12, 13, 21, 12, 14, 16, 10, 0, 14, 12, 13, 14, 16, 16, 13, 13, 10, 0, 10, 12, 13, 15, 21, 15, 14, 12, 7, 0, 9, 13, 13, 8, 12, 19, 9, 13, 13, 0, 13, 21, 9, 9, 27, 16, 10, 12, 14, 0, 13, 17, 13, 16, 24, 9, 11, 17, 10, 0, 13, 14, 11, 11, 23, 18, 11, 14, 10, 0, 9, 14, 13, 15, 22, 11, 12, 15, 12, 0, 13, 12, 17, 9, 22, 14, 8, 13, 11, 0, 10, 14, 14, 14, 21, 15, 11, 13, 11, 0, 12, 12, 7, 13, 18, 11, 14, 13, 11, 0, 8, 8, 13, 17, 33, 10, 10, 13, 13, 0, 15, 20, 10, 9, 26, 11, 11, 8, 10, 0, 21, 8, 7, 15, 14, 11, 13, 14, 16, 0, 13, 12, 13, 13, 23, 16, 10, 16, 12, 0, 15, 12, 9, 13, 23, 13, 10, 14, 13, 0, 11, 14, 9, 14, 19, 13, 11, 8, 12, 0, 11, 12, 9, 11, 25, 13, 13, 13, 13, 0, 10, 13, 9, 12, 21, 10, 11, 14, 8, 0, 13, 16, 12, 14, 17, 8, 8, 15, 14, 0, 15, 13, 11, 12, 38, 13, 13, 10, 11, 0, 12, 14, 9, 10, 34, 17, 15, 13, 13, 0, 11, 17, 12, 14, 24, 12, 8, 11, 10, 0, 10, 12, 10, 19, 18, 13, 10, 12, 14, 0, 8, 9, 9, 14, 23, 9, 15, 13, 12, 0, 4, 14, 16, 18, 17, 12, 13, 13, 11, 0, 11, 16, 16, 9, 29, 20, 6, 8, 13, 0, 11, 13, 9, 17, 21, 18, 14, 12, 12, 0, 13, 17, 12, 14, 23, 14, 12, 8, 13, 0, 13, 12, 12, 11, 22, 17, 11, 16, 11, 0, 11, 14, 10, 15, 30, 9, 14, 13, 9, 0, 11, 10, 9, 14, 31, 8, 12, 12, 13, 0, 15, 16, 7, 14, 25, 11, 8, 15, 10, 0, 7, 14, 11, 15, 17, 8, 13, 15, 13, 0, 13, 13, 11, 13, 16, 17, 13, 10, 14, 0, 13, 16, 6, 23, 19, 13, 9, 13, 7, 0, 10, 10, 11, 8, 53, 11, 9, 13, 10, 0, 13, 15, 11, 13, 11, 11, 8, 17, 8, 0, 12, 10, 13, 10, 21, 13, 15, 16, 11, 0, 8, 13, 9, 21, 21, 13, 13, 13, 12, 0, 6, 14, 10, 17, 17, 17, 8, 6, 11, 0, 13, 8, 9, 19, 25, 6, 10, 15, 13, 0, 9, 13, 15, 12, 21, 15, 9, 9, 8, 0, 11, 12, 12, 11, 27, 13, 13, 81, 16, 0, 6, 15, 8, 11, 14, 13, 12, 14, 15, 0, 11, 19, 11, 22, 21, 10, 6, 14, 10, 0, 13, 12, 12, 6, 23, 12, 8, 11, 13, 0, 8, 11, 11, 14, 15, 14, 10, 7, 7, 0, 9, 11, 6, 11, 17, 18, 6, 16, 12, 0, 6, 9, 14, 16, 23, 9, 13, 11, 11, 0, 13, 15, 12, 13, 26, 9, 12, 14, 13, 0, 10, 14, 12, 15, 139, 11, 8, 11, 9, 0, 14, 14, 10, 9, 13, 15, 11, 12, 12, 0, 11, 17, 8, 12, 17, 11, 7, 18, 13, 0, 11, 14, 13, 15, 28, 14, 12, 13, 10, 0, 13, 8, 13, 20, 22, 14, 13, 14, 9, 0, 11, 16, 13, 10, 24, 6, 10, 17, 11, 0, 11, 13, 10, 16, 61, 14, 11, 12, 12, 0, 9, 18, 13, 17, 15, 13, 11, 13, 12, 0, 9, 16, 8, 11, 23, 14, 15, 20, 13, 0, 11, 19, 13, 12, 18, 14, 7, 13, 14, 0, 14, 42, 11, 15, 22, 12, 10, 18, 10, 0, 8, 14, 6, 13, 52, 13, 9, 10, 12, 0, 11, 17, 14, 12, 21, 9, 12, 11, 13, 0, 14, 11, 12, 13, 14, 14, 9, 14, 8, 0, 12, 13, 10, 10, 30, 17, 12, 20, 13, 0, 11, 14, 11, 14, 35, 14, 12, 13, 13, 0, 12, 15, 10, 14, 21, 15, 13, 13, 12, 0, 10, 16, 8, 10, 21, 12, 6, 12, 11, 0, 12, 14, 14, 18, 50, 18, 11, 13, 13, 0, 11, 14, 12, 7, 16, 18, 12, 13, 10, 0, 12, 13, 12, 13, 29, 12, 11, 11, 14, 0, 12, 7, 7, 19, 21, 19, 12, 9, 15, 0, 11, 12, 10, 14, 20, 6, 14, 15, 13, 0, 15, 14, 14, 13, 15, 16, 11, 13, 12, 0, 11, 7, 7, 12, 12, 9, 15, 14, 12, 0, 12, 19, 14, 11, 34, 11, 12, 14, 14, 0, 14, 19, 10, 16, 16, 13, 13, 20, 12, 0, 14, 17, 15, 12, 12, 18, 11, 13, 13, 0, 11, 14, 8, 13, 16, 11, 6, 8, 12, 0, 9, 16, 8, 14, 21, 14, 11, 16, 14, 0, 12, 13, 9, 16, 29, 6, 9, 12, 8, 0, 11, 18, 9, 7, 9, 15, 12, 11, 11, 0, 10, 16, 13, 15, 17, 8, 10, 16, 8, 0, 14, 12, 10, 15, 23, 18, 14, 14, 12, 0, 10, 9, 8, 13, 23, 9, 11, 15, 13, 0, 11, 17, 8, 12, 22, 14, 9, 15, 9, 0, 14, 12, 10, 16, 34, 11, 9, 13, 15, 0, 13, 19, 12, 16, 20, 18, 13, 15, 13, 0, 14, 11, 13, 14, 22, 36, 9, 18, 12, 0, 12, 14, 12, 16, 21, 16, 13, 8, 12, 0, 13, 14, 12, 13, 25, 14, 12, 16, 14, 0, 8, 10, 13, 11, 24, 12, 9, 15, 14, 0, 14, 13, 9, 11, 23, 12, 12, 19, 12, 0, 13, 12, 10, 13, 38, 16, 8, 19, 12, 0, 14, 12, 9, 16, 24, 8, 14, 15, 12, 0, 10, 10, 10, 19, 35, 15, 12, 22, 13, 0, 12, 17, 8, 14, 20, 12, 13, 11, 14, 0, 12, 12, 14, 12, 27, 20, 7, 7, 10, 0, 13, 13, 16, 13, 12, 13, 13, 7, 11, 0, 12, 12, 13, 13, 16, 19, 13, 8, 12, 0, 9, 15, 13, 9, 14, 9, 10, 12, 13, 0, 10, 14, 14, 14, 18, 19, 9, 8, 15, 0, 13, 17, 12, 9, 12, 13, 16, 12, 17, 0, 11, 14, 13, 13, 18, 14, 14, 7, 13, 0, 9, 11, 13, 9, 19, 11, 10, 13, 11, 0, 7, 13, 14, 13, 26, 7, 9, 10, 14, 0, 11, 13, 9, 14, 24, 14, 13, 14, 8, 0, 10, 9, 13, 8, 28, 9, 11, 10, 11, 0, 13, 21, 14, 14, 23, 15, 15, 9, 13, 0, 13, 16, 13, 12, 19, 19, 9, 11, 15, 0, 12, 13, 9, 15, 27, 9, 13, 19, 12, 0, 11, 18, 14, 17, 23, 14, 13, 14, 12, 0, 12, 10, 9, 17, 25, 19, 17, 12, 30, 0, 8, 20, 17, 12, 23, 19, 14, 14, 16, 0, 7, 14, 12, 17, 14, 22, 11, 14, 11, 0, 12, 14, 13, 15, 33, 14, 12, 14, 8, 0, 12, 13, 9, 15, 19, 12, 11, 16, 12, 0, 11, 19, 10, 14, 16, 20, 12, 16, 13, 0, 13, 12, 6, 12, 22, 15, 8, 13, 10, 0, 14, 12, 11, 17, 27, 16, 12, 18, 12, 0, 13, 16, 11, 13, 20, 14, 9, 18, 11, 0, 14, 11, 11, 15, 14, 14, 6, 13, 13, 0, 8, 14, 6, 11, 18, 13, 8, 13, 17, 0, 6, 6, 6, 12, 19, 11, 14, 15, 14, 0, 6, 14, 9, 13, 12, 11, 13, 18, 13, 0, 6, 11, 12, 12, 13, 14, 13, 14, 14, 0, 13, 18, 13, 14, 25, 12, 8, 19, 11, 0, 15, 14, 13, 20, 18, 19, 8, 13, 11, 0, 12, 11, 10, 11, 24, 13, 13, 19, 12, 0, 13, 11, 10, 18, 20, 15, 12, 9, 10, 0, 14, 14, 13, 13, 56, 6, 11, 12, 9, 0, 13, 10, 15, 8, 18, 8, 14, 14, 11, 0, 9, 6, 10, 17, 17, 15, 12, 15, 15, 0, 6, 19, 13, 18, 25, 13, 14, 18, 9, 0, 13, 12, 10, 14, 21, 9, 9, 15, 9, 0, 8, 8, 12, 15, 18, 15, 15, 13, 11, 0, 13, 12, 12, 16, 30, 15, 13, 12, 12, 0, 11, 13, 9, 13, 18, 17, 13, 8, 14, 0, 11, 13, 14, 15, 17, 11, 11, 18, 13, 0, 11, 15, 8, 11, 19, 15, 12, 9, 11, 0, 6, 21, 13, 14, 23, 8, 11, 5, 13, 0, 11, 15, 6, 12, 25, 12, 12, 12, 7, 0, 6, 17, 14, 15, 14, 13, 10, 23, 14, 0, 6, 15, 13, 10, 29, 17, 13, 13, 10, 0, 12, 9, 13, 13, 29, 12, 10, 13, 11, 0, 11, 17, 13, 14, 33, 13, 10, 11, 13, 0, 15, 14, 11, 12, 22, 12, 11, 19, 12, 0, 14, 18, 16, 14, 23, 14, 13, 11, 14, 0, 12, 10, 15, 9, 14, 17, 12, 10, 10, 0, 13, 13, 12, 14, 23, 16, 12, 13, 11, 0, 5, 14, 11, 12, 17, 12, 5, 17, 7, 0, 13, 19, 12, 12, 17, 13, 15, 13, 11, 0, 12, 9, 10, 17, 53, 16, 9, 17, 11, 0, 13, 12, 7, 11, 17, 12, 13, 13, 11, 0, 13, 10, 13, 11, 23, 14, 12, 15, 13, 0, 11, 14, 11, 9, 32, 14, 13, 19, 11, 0, 11, 9, 9, 9, 17, 15, 5, 14, 10, 0, 9, 12, 11, 15, 20, 16, 12, 11, 10, 0, 13, 14, 9, 17, 21, 7, 10, 13, 13, 0, 13, 11, 12, 20, 35, 17, 11, 15, 7, 0, 11, 12, 11, 16, 23, 13, 10, 15, 13, 0, 13, 17, 10, 17, 21, 20, 10, 9, 13, 0, 14, 14, 11, 14, 23, 14, 11, 15, 14, 0, 10, 8, 13, 8, 32, 16, 10, 12, 10, 0, 15, 20, 11, 8, 23, 13, 8, 13, 13, 0, 13, 8, 9, 12, 33, 19, 14, 16, 12, 0, 9, 15, 11, 14, 17, 11, 11, 14, 13, 0, 9, 14, 10, 16, 61, 16, 8, 13, 10, 0, 12, 9, 14, 17, 14, 5, 5, 13, 9, 0, 5, 18, 16, 13, 20, 14, 13, 12, 8, 0, 13, 8, 7, 13, 29, 13, 13, 9, 8, 0, 8, 41, 7, 13, 14, 15, 12, 10, 12, 0, 8, 12, 13, 18, 29, 10, 14, 16, 11, 0, 10, 20, 12, 14, 40, 5, 9, 14, 12, 0, 12, 13, 8, 17, 24, 8, 15, 17, 13, 0, 11, 17, 13, 11, 35, 13, 12, 19, 13, 0, 11, 8, 10, 15, 23, 15, 10, 13, 12, 0, 11, 9, 11, 15, 21, 14, 12, 10, 12, 0, 9, 12, 13, 8, 17, 14, 15, 11, 14, 0, 9, 12, 9, 13, 29, 15, 11, 14, 8, 0, 13, 10, 14, 13, 12, 18, 11, 12, 11, 0, 6, 18, 13, 12, 22, 13, 9, 14, 12, 0, 13, 13, 13, 15, 27, 17, 13, 14, 9, 0, 13, 15, 7, 14, 10, 12, 13, 11, 10, 0, 11, 12, 12, 8, 23, 13, 14, 14, 12, 0, 11, 9, 6, 13, 52, 16, 14, 6, 11, 0, 11, 13, 8, 17, 14, 14, 13, 12, 13, 0, 11, 14, 11, 14, 21, 21, 14, 19, 10, 0, 12, 18, 13, 13, 47, 14, 13, 18, 7, 0, 13, 16, 13, 13, 25, 13, 8, 17, 10, 0, 7, 13, 12, 12, 33, 9, 12, 8, 14, 0, 8, 14, 12, 18, 15, 11, 14, 13, 12, 0, 12, 14, 11, 8, 16, 8, 11, 8, 8, 0, 16, 12, 11, 16, 10, 18, 7, 10, 14, 0, 10, 14, 8, 12, 23, 21, 9, 13, 8, 0, 13, 7, 16, 9, 15, 8, 12, 9, 10, 0, 11, 19, 13, 18, 24, 13, 7, 14, 12, 0, 13, 12, 8, 14, 21, 18, 13, 17, 8, 0, 10, 13, 14, 14, 19, 13, 13, 15, 12, 0, 14, 11, 12, 15, 24, 14, 14, 12, 11, 0, 16, 13, 12, 17, 21, 11, 9, 17, 11, 0, 13, 17, 11, 16, 23, 16, 12, 13, 15, 0, 12, 14, 13, 14, 17, 18, 11, 14, 13, 0, 9, 12, 13, 12, 21, 13, 8, 13, 13, 0, 7, 14, 13, 18, 38, 8, 13, 11, 12, 0, 11, 14, 13, 14, 33, 6, 8, 18, 14, 0, 12, 17, 14, 12, 21, 10, 11, 17, 7, 0, 11, 17, 14, 14, 18, 10, 10, 13, 14, 0, 9, 13, 13, 17, 16, 13, 10, 8, 15, 0, 13, 11, 14, 13, 23, 14, 11, 11, 12, 0, 10, 20, 9, 13, 21, 19, 9, 19, 13, 0, 14, 14, 11, 12, 19, 13, 9, 14, 26, 0, 15, 14, 11, 13, 18, 15, 13, 14, 14, 0, 7, 16, 10, 8, 22, 13, 13, 21, 10, 0, 6, 7, 8, 15, 21, 11, 11, 13, 13, 0, 7, 14, 12, 15, 21, 19, 13, 10, 12, 0, 7, 17, 11, 14, 30, 15, 5, 17, 13, 0, 13, 17, 13, 12, 30, 16, 13, 9, 13, 0, 13, 14, 13, 14, 34, 5, 8, 16, 13, 0, 11, 14, 11, 13, 19, 15, 11, 14, 9, 0, 12, 16, 13, 11, 34, 17, 14, 11, 9, 0, 10, 13, 12, 11, 15, 17, 12, 13, 14, 0, 12, 15, 12, 14, 17, 10, 12, 18, 13, 0, 6, 12, 7, 24, 23, 13, 13, 17, 15, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 17, 9, 12, 10, 0, 5, 5, 5, 14, 16, 18, 12, 16, 13, 0, 5, 5, 11, 10, 21, 15, 12, 9, 12, 0, 5, 5, 8, 17, 21, 17, 15, 13, 15, 0, 5, 19, 15, 9, 26, 15, 14, 13, 6, 0, 5, 14, 12, 9, 22, 12, 8, 14, 10, 0, 5, 16, 12, 18, 25, 9, 13, 15, 12, 0, 5, 13, 9, 12, 24, 13, 12, 11, 11, 0, 14, 14, 14, 11, 21, 16, 12, 9, 11, 0, 5, 5, 5, 5, 5, 11, 10, 22, 10, 0, 5, 5, 11, 10, 33, 11, 16, 17, 9, 0, 5, 20, 16, 17, 26, 12, 13, 18, 13, 0, 5, 12, 15, 15, 29, 12, 15, 11, 11, 0, 5, 14, 9, 13, 18, 13, 13, 15, 14, 0, 11, 17, 11, 39, 24, 11, 11, 13, 6, 0, 11, 9, 10, 15, 49, 17, 13, 14, 14, 0, 12, 12, 13, 12, 30, 13, 12, 14, 10, 0, 14, 14, 8, 16, 21, 13, 11, 15, 15, 0, 9, 10, 8, 13, 17, 19, 12, 17, 11, 0, 5, 5, 5, 12, 23, 8, 14, 18, 12, 0, 5, 14, 12, 14, 26, 14, 12, 11, 15, 0, 5, 12, 13, 12, 22, 14, 8, 7, 7, 0, 16, 16, 16, 7, 20, 17, 9, 13, 11, 0, 12, 13, 9, 17, 26, 16, 10, 14, 12, 0, 12, 9, 10, 14, 24, 12, 13, 16, 11, 0, 11, 14, 8, 11, 90, 13, 8, 12, 13, 0, 10, 32, 11, 15, 28, 13, 10, 14, 13, 0, 13, 14, 10, 19, 26, 60, 13, 13, 11, 0, 13, 17, 12, 13, 8, 14, 7, 15, 13, 0, 5, 5, 12, 11, 26, 10, 12, 8, 12, 0, 5, 19, 9, 21, 26, 17, 13, 15, 14, 0, 13, 13, 8, 19, 16, 14, 11, 17, 9, 0, 13, 12, 9, 13, 21, 17, 12, 13, 11, 0, 9, 16, 13, 13, 18, 16, 12, 13, 13, 0, 13, 16, 7, 13, 29, 12, 14, 16, 16, 0, 8, 19, 10, 18, 13, 13, 8, 15, 14, 0, 13, 9, 13, 14, 24, 17, 8, 19, 12, 0, 11, 12, 13, 11, 27, 7, 8, 11, 13, 0, 7, 14, 13, 14, 30, 13, 15, 6, 13, 0, 5, 5, 15, 14, 22, 9, 8, 14, 8, 0, 5, 15, 6, 15, 30, 17, 10, 10, 13, 0, 14, 16, 12, 15, 18, 14, 12, 20, 15, 0, 14, 19, 11, 12, 15, 11, 13, 17, 14, 0, 16, 15, 8, 15, 23, 11, 9, 10, 9, 0, 10, 14, 7, 13, 21, 15, 11, 13, 9, 0, 9, 14, 12, 20, 14, 14, 17, 14, 14, 0, 12, 14, 13, 10, 15, 17, 10, 14, 12, 0, 12, 13, 14, 13, 21, 11, 14, 17, 9, 0, 14, 17, 14, 12, 28, 18, 8, 15, 15, 0, 5, 14, 16, 12, 32, 14, 10, 14, 13, 0, 15, 13, 8, 6, 21, 15, 15, 21, 9, 0, 17, 12, 13, 14, 23, 17, 13, 14, 14, 0, 10, 13, 14, 7, 16, 13, 13, 13, 12, 0, 13, 13, 13, 16, 114, 13, 14, 17, 12, 0, 11, 18, 7, 13, 15, 17, 15, 18, 11, 0, 11, 13, 13, 12, 21, 10, 16, 11, 8, 0, 8, 12, 8, 12, 24, 16, 11, 13, 11, 0, 13, 12, 11, 14, 16, 21, 7, 10, 7, 0, 12, 15, 14, 12, 16, 15, 14, 11, 13, 0, 5, 14, 9, 17, 34, 12, 9, 13, 13, 0, 13, 9, 14, 11, 31, 15, 13, 12, 6, 0, 11, 17, 8, 6, 19, 11, 16, 16, 12, 0, 17, 18, 10, 22, 29, 13, 12, 13, 13, 0, 12, 12, 11, 13, 21, 14, 11, 17, 13, 0, 12, 14, 13, 16, 26, 14, 14, 12, 9, 0, 12, 13, 12, 18, 26, 22, 12, 19, 13, 0, 12, 10, 12, 6, 19, 15, 13, 14, 10, 0, 13, 14, 8, 13, 21, 14, 14, 16, 12, 0, 9, 13, 9, 12, 17, 18, 13, 21, 15, 0, 5, 15, 12, 14, 19, 18, 13, 16, 9, 0, 11, 13, 11, 14, 32, 13, 11, 14, 12, 0, 7, 14, 10, 18, 21, 13, 11, 19, 11, 0, 15, 12, 15, 15, 20, 17, 13, 14, 8, 0, 10, 11, 13, 14, 19, 11, 9, 12, 13, 0, 13, 20, 15, 17, 18, 18, 12, 13, 13, 0, 9, 16, 11, 11, 36, 11, 9, 12, 10, 0, 9, 19, 10, 13, 27, 19, 8, 12, 11, 0, 13, 17, 6, 15, 15, 11, 13, 14, 11, 0, 7, 10, 13, 16, 25, 13, 8, 12, 13, 0, 5, 11, 14, 18, 24, 14, 14, 12, 8, 0, 6, 15, 15, 27, 38, 9, 9, 15, 14, 0, 11, 15, 14, 14, 20, 15, 13, 12, 13, 0, 16, 19, 13, 13, 15, 14, 14, 18, 10, 0, 14, 13, 11, 14, 15, 17, 13, 12, 12, 0, 12, 15, 12, 14, 28, 17, 13, 19, 14, 0, 9, 9, 11, 15, 32, 9, 15, 15, 13, 0, 13, 13, 12, 15, 18, 17, 15, 22, 15, 0, 11, 15, 12, 23, 24, 19, 12, 13, 15, 0, 11, 17, 12, 17, 24, 22, 14, 14, 12, 0, 7, 8, 14, 14, 21, 8, 12, 18, 10, 0, 11, 19, 14, 14, 56, 19, 14, 19, 13, 0, 11, 14, 12, 18, 15, 17, 11, 8, 14, 0, 14, 14, 16, 15, 34, 14, 10, 18, 9, 0, 13, 11, 12, 14, 7, 13, 12, 19, 10, 0, 15, 18, 13, 23, 21, 18, 12, 13, 14, 0, 11, 15, 8, 18, 15, 13, 13, 12, 11, 0, 13, 15, 13, 14, 16, 18, 13, 13, 16, 0, 14, 12, 13, 15, 19, 29, 12, 16, 11, 0, 6, 14, 11, 12, 29, 14, 9, 14, 11, 0, 5, 5, 5, 5, 5, 13, 13, 12, 9, 0, 5, 5, 14, 10, 26, 15, 9, 14, 14, 0, 5, 12, 13, 17, 21, 11, 14, 13, 8, 0, 5, 20, 11, 9, 23, 17, 9, 15, 16, 0, 5, 14, 16, 14, 25, 19, 15, 18, 13, 0, 12, 13, 11, 17, 23, 18, 9, 13, 14, 0, 8, 11, 12, 15, 25, 19, 13, 16, 11, 0, 10, 20, 15, 9, 24, 7, 12, 13, 13, 0, 10, 21, 10, 17, 71, 15, 13, 14, 13, 0, 8, 9, 10, 11, 22, 9, 12, 17, 10, 0, 5, 5, 13, 13, 24, 12, 14, 18, 13, 0, 5, 14, 15, 13, 35, 15, 11, 8, 14, 0, 11, 7, 10, 15, 21, 17, 15, 17, 12, 0, 13, 17, 7, 13, 26, 18, 14, 11, 14, 0, 12, 13, 10, 12, 23, 21, 13, 14, 18, 0, 11, 14, 9, 11, 25, 17, 13, 15, 14, 0, 10, 13, 10, 15, 29, 13, 14, 16, 13, 0, 10, 13, 15, 6, 72, 15, 9, 28, 12, 0, 11, 18, 10, 14, 20, 7, 7, 12, 9, 0, 11, 14, 10, 19, 16, 17, 8, 15, 10, 0, 5, 13, 10, 8, 18, 14, 12, 17, 11, 0, 7, 12, 11, 16, 15, 22, 11, 14, 12, 0, 7, 8, 15, 13, 18, 8, 11, 14, 13, 0, 14, 14, 14, 13, 21, 6, 6, 6, 6, 0, 14, 16, 15, 10, 24, 13, 6, 6, 6, 0, 17, 14, 13, 12, 15, 13, 9, 6, 6, 0, 9, 13, 14, 18, 45, 12, 13, 14, 6, 0, 12, 10, 10, 27, 15, 14, 13, 13, 13, 0, 8, 9, 12, 11, 38, 15, 9, 19, 15, 0, 13, 15, 16, 8, 24, 15, 13, 13, 9, 0, 5, 16, 12, 11, 19, 11, 16, 19, 8, 0, 13, 13, 8, 14, 31, 17, 11, 19, 12, 0, 12, 13, 12, 9, 17, 14, 13, 21, 11, 0, 13, 13, 8, 15, 23, 14, 13, 16, 16, 0, 11, 16, 13, 11, 25, 11, 6, 6, 6, 0, 15, 9, 14, 13, 21, 30, 10, 6, 6, 0, 13, 9, 11, 13, 27, 15, 13, 15, 6, 0, 13, 15, 6, 10, 32, 15, 12, 9, 7, 0, 10, 13, 11, 9, 26, 7, 13, 14, 7, 0, 11, 16, 15, 11, 15, 17, 14, 13, 11, 0, 5, 20, 11, 8, 16, 15, 11, 14, 10, 0, 13, 11, 12, 8, 23, 13, 12, 14, 12, 0, 13, 13, 10, 13, 23, 14, 10, 13, 13, 0, 14, 8, 11, 15, 19, 14, 10, 16, 10, 0, 14, 17, 11, 12, 21, 10, 18, 13, 10, 0, 16, 14, 15, 21, 17, 14, 9, 6, 6, 0, 11, 12, 13, 13, 33, 25, 9, 9, 6, 0, 17, 14, 8, 13, 21, 14, 11, 13, 10, 0, 9, 19, 11, 17, 32, 16, 11, 16, 7, 0, 13, 12, 11, 13, 26, 14, 11, 7, 11, 0, 14, 8, 12, 17, 21, 11, 10, 14, 8, 0, 9, 12, 8, 17, 92, 20, 12, 14, 8, 0, 14, 9, 13, 14, 17, 14, 8, 11, 14, 0, 8, 15, 13, 14, 21, 15, 13, 11, 7, 0, 14, 17, 17, 14, 24, 14, 14, 17, 13, 0, 11, 17, 10, 16, 9, 17, 13, 14, 11, 0, 14, 13, 9, 11, 30, 14, 10, 14, 6, 0, 12, 16, 12, 15, 20, 13, 8, 19, 13, 0, 17, 10, 9, 19, 18, 11, 8, 13, 14, 0, 13, 17, 9, 23, 28, 11, 12, 13, 8, 0, 13, 10, 8, 13, 18, 13, 13, 19, 10, 0, 13, 14, 11, 16, 19, 13, 12, 16, 15, 0, 12, 13, 14, 19, 12, 10, 12, 14, 11, 0, 9, 18, 17, 10, 21, 16, 12, 16, 8, 0, 12, 15, 11, 8, 24, 13, 12, 9, 13, 0, 19, 13, 16, 17, 61, 12, 11, 15, 14, 0, 13, 15, 7, 17, 29, 7, 16, 5, 10, 0, 14, 10, 7, 11, 19, 13, 9, 17, 14, 0, 14, 9, 13, 17, 31, 10, 14, 14, 11, 0, 13, 17, 12, 9, 20, 14, 12, 17, 11, 0, 11, 16, 16, 13, 30, 21, 11, 19, 9, 0, 15, 15, 13, 11, 37, 13, 10, 16, 13, 0, 12, 20, 12, 20, 10, 14, 14, 17, 14, 0, 11, 13, 13, 12, 18, 16, 14, 11, 10, 0, 14, 13, 13, 17, 18, 16, 11, 10, 13, 0, 13, 16, 10, 19, 13, 16, 14, 10, 9, 0, 8, 13, 14, 16, 8, 12, 14, 16, 11, 0, 14, 17, 16, 10, 18, 10, 9, 13, 10, 0, 14, 11, 11, 17, 25, 22, 15, 20, 12, 0, 14, 18, 15, 12, 19, 13, 14, 16, 14, 0, 15, 11, 14, 16, 21, 16, 13, 15, 13, 0, 11, 12, 12, 14, 34, 11, 16, 26, 13, 0, 17, 9, 10, 18, 22, 13, 17, 12, 12, 0, 13, 20, 13, 17, 23, 13, 13, 13, 12, 0, 13, 9, 14, 14, 23, 13, 11, 16, 12, 0, 17, 15, 6, 8, 25, 13, 9, 8, 13, 0, 11, 16, 12, 20, 35, 18, 10, 14, 10, 0, 13, 13, 10, 12, 21, 10, 22, 13, 12, 0, 12, 21, 13, 16, 16, 13, 14, 17, 15, 0, 13, 13, 12, 15, 12, 11, 15, 36, 15, 0, 7, 16, 9, 13, 23, 15, 9, 18, 13, 0, 10, 18, 13, 19, 24, 18, 7, 14, 9, 0, 9, 14, 15, 14, 34, 14, 10, 11, 11, 0, 12, 16, 13, 13, 23, 12, 15, 15, 11, 0, 11, 12, 14, 15, 16, 13, 13, 11, 13, 0, 14, 19, 12, 15, 26, 18, 15, 13, 10, 0, 14, 13, 14, 19, 27, 19, 13, 11, 13, 0, 10, 15, 8, 17, 23, 19, 12, 8, 10, 0, 13, 14, 15, 12, 21, 10, 13, 13, 8, 0, 14, 20, 13, 13, 27, 16, 12, 18, 9, 0, 5, 5, 5, 17, 27, 11, 14, 14, 9, 0, 5, 20, 13, 12, 23, 20, 16, 8, 14, 0, 5, 9, 12, 14, 38, 15, 13, 14, 12, 0, 12, 19, 8, 11, 38, 13, 12, 15, 13, 0, 9, 13, 11, 15, 19, 13, 11, 14, 11, 0, 10, 13, 9, 17, 28, 18, 12, 15, 12, 0, 15, 19, 16, 12, 23, 13, 15, 20, 13, 0, 11, 17, 13, 8, 21, 16, 11, 17, 13, 0, 13, 9, 13, 13, 30, 16, 7, 12, 13, 0, 10, 13, 9, 16, 24, 9, 12, 9, 12, 0, 5, 21, 12, 15, 23, 11, 12, 13, 8, 0, 13, 13, 11, 17, 30, 14, 13, 7, 13, 0, 9, 11, 13, 19, 14, 11, 13, 18, 11, 0, 11, 14, 11, 14, 23, 16, 13, 13, 11, 0, 12, 19, 12, 13, 30, 9, 6, 10, 14, 0, 14, 16, 13, 13, 14, 13, 7, 18, 11, 0, 13, 18, 14, 16, 30, 16, 14, 16, 16, 0, 13, 18, 13, 13, 32, 12, 14, 12, 13, 0, 13, 8, 14, 18, 17, 13, 13, 15, 8, 0, 11, 21, 14, 11, 15, 9, 14, 14, 9, 0, 5, 28, 14, 17, 15, 15, 13, 11, 14, 0, 7, 16, 11, 18, 32, 15, 13, 21, 11, 0, 14, 19, 13, 13, 23, 11, 11, 13, 11, 0, 8, 19, 11, 19, 25, 14, 14, 17, 16, 0, 13, 15, 8, 9, 26, 13, 14, 11, 8, 0, 10, 13, 13, 13, 28, 17, 9, 14, 10, 0, 12, 8, 12, 9, 14, 20, 11, 18, 11, 0, 11, 19, 14, 18, 25, 19, 7, 9, 9, 0, 14, 14, 14, 19, 21, 13, 11, 14, 7, 0, 10, 12, 14, 11, 17, 16, 16, 22, 15, 0, 7, 13, 13, 14, 19, 9, 11, 11, 13, 0, 11, 14, 13, 13, 35, 6, 13, 14, 18, 0, 9, 15, 10, 18, 23, 17, 9, 14, 15, 0, 13, 15, 17, 9, 28, 20, 15, 15, 12, 0, 14, 15, 7, 13, 21, 18, 6, 6, 6, 0, 11, 18, 10, 13, 19, 16, 16, 6, 6, 0, 15, 22, 9, 20, 40, 14, 14, 19, 6, 0, 7, 21, 13, 13, 23, 14, 13, 8, 12, 0, 13, 15, 14, 14, 26, 11, 14, 17, 12, 0, 13, 18, 14, 19, 38, 14, 11, 12, 9, 0, 12, 12, 13, 20, 18, 13, 11, 14, 8, 0, 12, 16, 10, 13, 29, 13, 6, 16, 7, 0, 12, 11, 15, 14, 16, 14, 13, 19, 13, 0, 12, 8, 14, 12, 19, 19, 14, 12, 16, 0, 18, 17, 12, 14, 27, 14, 13, 16, 11, 0, 17, 15, 13, 13, 29, 17, 17, 6, 6, 0, 11, 14, 14, 18, 34, 14, 13, 19, 6, 0, 13, 12, 15, 8, 18, 14, 14, 18, 13, 0, 13, 16, 11, 13, 15, 14, 13, 14, 13, 0, 15, 14, 9, 9, 15, 13, 13, 7, 11, 0, 13, 12, 14, 18, 24, 14, 12, 14, 7, 0, 15, 16, 12, 14, 16, 14, 9, 16, 8, 0, 11, 15, 14, 13, 28, 15, 16, 12, 15, 0, 11, 19, 15, 13, 28, 18, 11, 14, 13, 0, 12, 13, 13, 20, 16, 13, 11, 17, 11, 0, 14, 13, 10, 23, 15, 16, 8, 18, 11, 0, 10, 12, 8, 14, 21, 13, 14, 11, 6, 0, 9, 18, 13, 17, 22, 17, 12, 16, 13, 0, 15, 8, 14, 19, 21, 18, 14, 13, 9, 0, 8, 17, 13, 5, 27, 13, 5, 11, 14, 0, 11, 18, 11, 20, 30, 14, 8, 15, 10, 0, 13, 8, 9, 17, 37, 19, 17, 13, 15, 0, 7, 13, 12, 13, 22, 12, 5, 13, 14, 0, 11, 13, 13, 20, 13, 16, 12, 12, 7, 0, 17, 13, 14, 9, 15, 12, 12, 10, 11, 0, 12, 21, 13, 8, 24, 12, 12, 13, 11, 0, 8, 12, 10, 7, 19, 14, 11, 14, 13, 0, 13, 14, 9, 9, 23, 12, 14, 13, 14, 0, 15, 14, 12, 8, 14, 15, 11, 16, 15, 0, 11, 13, 13, 15, 32, 13, 12, 14, 15, 0, 13, 11, 12, 18, 21, 14, 11, 16, 12, 0, 18, 14, 15, 13, 27, 21, 13, 16, 10, 0, 11, 11, 12, 17, 26, 17, 8, 15, 11, 0, 7, 10, 15, 15, 15, 16, 11, 8, 13, 0, 11, 17, 11, 11, 16, 22, 15, 8, 14, 0, 10, 20, 11, 14, 24, 17, 14, 15, 13, 0, 12, 16, 15, 17, 189, 18, 13, 20, 12, 0, 18, 19, 11, 13, 23, 13, 11, 14, 6, 0, 15, 17, 10, 6, 22, 13, 15, 16, 9, 0, 11, 6, 9, 12, 29, 15, 11, 8, 13, 0, 13, 11, 13, 6, 22, 7, 18, 9, 15, 0, 17, 16, 12, 18, 33, 13, 9, 16, 15, 0, 13, 14, 12, 14, 27, 14, 14, 14, 6, 0, 13, 15, 14, 13, 20, 13, 17, 7, 12, 0, 9, 24, 14, 12, 15, 17, 12, 17, 14, 0, 14, 14, 12, 11, 24, 13, 11, 20, 8, 0, 13, 19, 18, 13, 35, 12, 14, 9, 13, 0, 7, 18, 12, 20, 28, 22, 11, 13, 10, 0, 12, 14, 11, 14, 21, 17, 15, 14, 12, 0, 13, 12, 15, 14, 23, 14, 14, 18, 12, 0, 13, 12, 14, 6, 24, 18, 14, 13, 9, 0, 14, 20, 12, 13, 34, 17, 17, 14, 15, 0, 12, 16, 14, 9, 23, 15, 5, 14, 12, 0, 17, 20, 12, 19, 19, 19, 15, 22, 19, 0, 8, 15, 17, 14, 21, 8, 13, 14, 13, 0, 13, 17, 11, 15, 29, 7, 11, 14, 15, 0, 15, 13, 13, 19, 34, 9, 14, 16, 15, 0, 15, 16, 12, 11, 21, 12, 13, 14, 12, 0, 7, 23, 12, 18, 21, 14, 12, 7, 8, 0, 11, 18, 14, 9, 36, 12, 11, 8, 14, 0, 5, 5, 13, 17, 18, 17, 8, 11, 16, 0, 5, 16, 13, 14, 15, 17, 14, 7, 11, 0, 11, 10, 9, 17, 24, 10, 14, 13, 6, 0, 13, 21, 14, 16, 21, 12, 18, 14, 8, 0, 13, 10, 13, 14, 18, 17, 12, 17, 15, 0, 14, 16, 15, 13, 24, 15, 15, 10, 15, 0, 12, 16, 14, 13, 29, 18, 9, 16, 9, 0, 8, 18, 6, 13, 30, 15, 12, 12, 10, 0, 16, 19, 11, 13, 22, 16, 13, 23, 13, 0, 11, 14, 13, 10, 23, 7, 14, 42, 11, 0, 5, 11, 11, 13, 11, 14, 13, 16, 13, 0, 12, 12, 9, 9, 25, 13, 16, 11, 9, 0, 13, 13, 11, 14, 21, 17, 12, 21, 11, 0, 13, 11, 13, 11, 131, 18, 12, 13, 9, 0, 17, 12, 8, 10, 25, 13, 11, 19, 15, 0, 11, 14, 11, 6, 22, 10, 8, 14, 17, 0, 16, 15, 12, 12, 25, 11, 13, 18, 12, 0, 15, 12, 14, 19, 29, 17, 13, 14, 8, 0, 13, 13, 13, 19, 18, 9, 14, 15, 10, 0, 13, 15, 10, 26, 16, 15, 12, 14, 16, 0, 15, 13, 8, 17, 15, 15, 14, 13, 13, 0, 12, 18, 15, 14, 23, 13, 13, 14, 11, 0, 15, 11, 14, 17, 23, 29, 13, 16, 8, 0, 14, 13, 13, 16, 24, 20, 12, 15, 13, 0, 14, 13, 11, 15, 34, 9, 15, 13, 13, 0, 9, 20, 17, 13, 20, 11, 12, 9, 13, 0, 13, 14, 13, 14, 33, 14, 9, 18, 14, 0, 13, 15, 7, 17, 23, 18, 8, 14, 6, 0, 9, 8, 17, 9, 25, 11, 13, 12, 12, 0, 10, 14, 12, 15, 14, 16, 9, 14, 12, 0, 13, 17, 7, 15, 21, 14, 13, 7, 8, 0, 12, 14, 14, 13, 25, 13, 14, 18, 12, 0, 13, 20, 7, 17, 29, 12, 9, 15, 15, 0, 10, 15, 7, 17, 21, 17, 10, 11, 8, 0, 16, 13, 10, 13, 24, 7, 13, 18, 7, 0, 12, 11, 12, 18, 22, 18, 14, 13, 7, 0, 8, 13, 13, 15, 35, 10, 14, 14, 13, 0, 13, 14, 11, 13, 17, 12, 8, 14, 16, 0, 16, 14, 12, 13, 23, 14, 11, 16, 14, 0, 12, 19, 16, 17, 17, 17, 9, 14, 14, 0, 11, 21, 13, 6, 21, 18, 13, 16, 13, 0, 10, 16, 10, 16, 31, 11, 10, 18, 10, 0, 13, 14, 15, 17, 26, 12, 11, 13, 10, 0, 8, 16, 12, 14, 20, 17, 9, 15, 16, 0, 14, 12, 13, 14, 22, 16, 15, 17, 12, 0, 16, 14, 10, 10, 23, 14, 14, 6, 6, 0, 13, 18, 7, 15, 38, 18, 11, 14, 6, 0, 14, 20, 13, 17, 21, 13, 11, 11, 13, 0, 8, 14, 12, 14, 23, 12, 12, 12, 13, 0, 14, 8, 14, 11, 24, 19, 13, 11, 14, 0, 13, 15, 11, 11, 30, 11, 14, 15, 9, 0, 14, 16, 18, 19, 30, 17, 7, 11, 13, 0, 7, 14, 16, 36, 22, 10, 14, 13, 11, 0, 9, 14, 13, 19, 28, 16, 9, 13, 14, 0, 11, 14, 17, 12, 23, 21, 15, 17, 10, 0, 13, 19, 10, 14, 25, 18, 14, 16, 14, 0, 11, 8, 13, 10, 25, 18, 15, 13, 6, 0, 10, 17, 11, 13, 28, 17, 12, 13, 12, 0, 11, 13, 8, 19, 18, 14, 9, 19, 15, 0, 11, 17, 11, 16, 23, 13, 11, 14, 8, 0, 14, 9, 14, 11, 21, 15, 10, 14, 11, 0, 13, 18, 11, 10, 33, 14, 15, 12, 12, 0, 11, 19, 10, 16, 28, 17, 13, 13, 12, 0, 10, 22, 11, 12, 21, 16, 7, 13, 11, 0, 13, 25, 12, 13, 18, 14, 11, 18, 17, 0, 16, 16, 12, 19, 21, 19, 8, 11, 13, 0, 13, 7, 12, 13, 35, 13, 7, 13, 15, 0, 12, 13, 11, 13, 24, 22, 13, 12, 12, 0, 16, 12, 15, 19, 30, 13, 10, 16, 16, 0, 13, 8, 16, 12, 21, 16, 15, 17, 13, 0, 9, 15, 14, 19, 7, 12, 13, 13, 15, 0, 14, 17, 14, 12, 23, 12, 15, 11, 10, 0, 13, 14, 9, 17, 15, 12, 14, 13, 14, 0, 11, 15, 12, 14, 28, 18, 13, 21, 13, 0, 12, 13, 14, 19, 16, 13, 9, 16, 13, 0, 11, 17, 15, 20, 15, 15, 7, 13, 11, 0, 9, 12, 10, 11, 20, 12, 9, 12, 10, 0, 11, 17, 14, 18, 9, 13, 16, 8, 9, 0, 16, 17, 12, 13, 29, 15, 11, 17, 7, 0, 13, 19, 15, 14, 52, 12, 13, 11, 12, 0, 13, 20, 13, 17, 26, 19, 9, 16, 18, 0, 14, 22, 10, 15, 29, 13, 11, 19, 8, 0, 18, 21, 14, 18, 21, 11, 14, 17, 9, 0, 11, 15, 11, 16, 11, 14, 12, 8, 13, 0, 12, 7, 10, 16, 23, 10, 11, 13, 12, 0, 10, 19, 13, 9, 21, 17, 10, 14, 14, 0, 11, 10, 14, 16, 26, 13, 15, 13, 12, 0, 11, 12, 13, 12, 78, 14, 10, 14, 8, 0, 14, 12, 12, 21, 27, 18, 21, 16, 16, 0, 18, 14, 20, 12, 24, 17, 13, 13, 13, 0, 14, 21, 9, 18, 50, 14, 14, 17, 17, 0, 14, 17, 12, 13, 29, 18, 12, 13, 14, 0, 13, 12, 14, 13, 15, 17, 13, 17, 11, 0, 11, 13, 19, 15, 17, 17, 14, 13, 8, 0, 13, 7, 11, 17, 26, 10, 11, 12, 9, 0, 13, 18, 11, 14, 18, 21, 8, 18, 16, 0, 15, 14, 11, 11, 30, 15, 12, 16, 14, 0, 13, 16, 14, 13, 28, 14, 13, 18, 11, 0, 14, 14, 13, 16, 23, 9, 10, 13, 8, 0, 11, 22, 12, 24, 26, 13, 12, 13, 11, 0, 5, 5, 13, 14, 15, 11, 12, 17, 13, 0, 5, 15, 13, 16, 32, 15, 15, 10, 14, 0, 9, 14, 13, 13, 21, 11, 11, 14, 6, 0, 14, 15, 12, 10, 20, 14, 13, 15, 9, 0, 11, 10, 11, 17, 15, 14, 16, 17, 11, 0, 9, 15, 15, 11, 21, 12, 15, 14, 13, 0, 13, 19, 13, 11, 32, 23, 13, 17, 14, 0, 13, 12, 12, 19, 25, 17, 13, 10, 9, 0, 13, 13, 14, 14, 16, 8, 13, 19, 8, 0, 13, 13, 15, 18, 31, 14, 9, 12, 16, 0, 5, 15, 13, 15, 15, 11, 15, 13, 10, 0, 7, 14, 14, 10, 35, 20, 8, 11, 11, 0, 11, 20, 10, 17, 23, 17, 14, 14, 11, 0, 9, 17, 11, 8, 24, 12, 9, 14, 13, 0, 8, 11, 12, 19, 29, 17, 12, 14, 11, 0, 14, 16, 14, 6, 19, 17, 9, 9, 14, 0, 11, 11, 14, 8, 32, 11, 12, 17, 8, 0, 12, 22, 18, 15, 23, 21, 8, 13, 14, 0, 6, 13, 14, 21, 15, 19, 15, 17, 14, 0, 12, 12, 13, 13, 26, 19, 12, 13, 8, 0, 10, 14, 9, 18, 15, 8, 10, 14, 11, 0, 10, 13, 10, 17, 30, 20, 13, 18, 14, 0, 12, 13, 10, 14, 18, 14, 12, 18, 10, 0, 14, 14, 14, 13, 28, 13, 13, 14, 9, 0, 12, 10, 14, 21, 30, 17, 12, 18, 12, 0, 15, 15, 10, 14, 21, 13, 13, 13, 16, 0, 13, 13, 14, 14, 27, 17, 12, 12, 11, 0, 11, 18, 14, 17, 24, 16, 15, 14, 14, 0, 16, 19, 17, 15, 23, 17, 12, 11, 12, 0, 15, 9, 13, 13, 24, 16, 11, 14, 14, 0, 8, 16, 15, 14, 23, 14, 13, 12, 11, 0, 13, 11, 15, 10, 24, 15, 11, 13, 12, 0, 9, 17, 11, 16, 29, 19, 16, 13, 13, 0, 16, 13, 13, 29, 26, 7, 12, 15, 10, 0, 10, 12, 12, 11, 32, 13, 15, 16, 13, 0, 8, 14, 9, 10, 21, 8, 13, 9, 8, 0, 13, 18, 12, 16, 23, 10, 13, 21, 13, 0, 11, 15, 14, 18, 28, 19, 13, 17, 13, 0, 16, 11, 9, 14, 15, 13, 9, 14, 13, 0, 12, 12, 12, 19, 25, 8, 14, 19, 13, 0, 14, 14, 14, 19, 25, 14, 14, 16, 13, 0, 13, 16, 15, 16, 30, 13, 9, 15, 9, 0, 14, 16, 13, 20, 17, 14, 9, 15, 14, 0, 12, 10, 13, 12, 13, 14, 8, 15, 9, 0, 13, 13, 9, 12, 20, 5, 14, 11, 11, 0, 9, 13, 12, 13, 32, 18, 9, 13, 15, 0, 7, 19, 9, 13, 26, 13, 12, 15, 12, 0, 9, 13, 10, 26, 21, 16, 11, 14, 13, 0, 8, 13, 9, 16, 27, 16, 13, 12, 13, 0, 13, 19, 12, 17, 11, 11, 12, 15, 13, 0, 13, 16, 15, 17, 29, 19, 12, 13, 10, 0, 13, 18, 14, 14, 465, 9, 9, 14, 11, 0, 13, 14, 19, 19, 27, 14, 9, 12, 8, 0, 14, 29, 14, 11, 21, 16, 12, 18, 11, 0, 7, 14, 13, 13, 32, 17, 14, 13, 14, 0, 9, 12, 11, 16, 24, 13, 13, 17, 13, 0, 9, 13, 12, 11, 34, 19, 10, 14, 6, 0, 14, 13, 13, 19, 27, 19, 10, 14, 16, 0, 11, 14, 11, 20, 29, 14, 13, 19, 11, 0, 14, 15, 9, 19, 21, 11, 13, 13, 11, 0, 13, 22, 12, 13, 23, 8, 14, 23, 13, 0, 13, 14, 13, 8, 53, 17, 13, 18, 13, 0, 15, 15, 14, 19, 21, 14, 13, 12, 12, 0, 14, 18, 7, 21, 22, 15, 14, 16, 16, 0, 15, 14, 13, 16, 16, 9, 13, 14, 13, 0, 15, 12, 12, 18, 22, 11, 14, 13, 12, 0, 11, 12, 10, 13, 29, 20, 13, 20, 12, 0, 14, 17, 8, 15, 23, 14, 11, 15, 17, 0, 7, 16, 13, 17, 27, 15, 11, 22, 16, 0, 14, 14, 13, 13, 23, 15, 8, 11, 8, 0, 14, 6, 13, 17, 23, 11, 10, 19, 16, 0, 15, 14, 12, 11, 23, 15, 11, 16, 11, 0, 13, 19, 11, 17, 24, 9, 14, 12, 12, 0, 12, 15, 18, 11, 20, 15, 13, 17, 12, 0, 11, 19, 14, 20, 23, 14, 13, 14, 12, 0, 13, 18, 12, 10, 32, 18, 14, 18, 10, 0, 15, 26, 6, 6, 6, 6, 14, 13, 11, 0, 16, 14, 6, 16, 12, 18, 13, 6, 19, 0, 11, 16, 6, 10, 34, 13, 15, 9, 9, 0, 14, 17, 6, 27, 28, 14, 7, 14, 13, 0, 15, 13, 18, 13, 32, 6, 7, 15, 14, 0, 14, 14, 13, 12, 90, 14, 18, 12, 10, 0, 15, 19, 17, 12, 27, 13, 7, 18, 13, 0, 11, 18, 14, 12, 23, 14, 15, 14, 10, 0, 13, 16, 9, 15, 23, 14, 8, 16, 12, 0, 10, 17, 14, 14, 21, 22, 12, 9, 14, 0, 17, 14, 6, 16, 29, 13, 13, 14, 8, 0, 12, 17, 15, 22, 28, 9, 13, 13, 16, 0, 13, 14, 12, 16, 20, 16, 14, 12, 12, 0, 12, 14, 15, 16, 34, 21, 16, 16, 8, 0, 14, 14, 18, 18, 14, 6, 12, 18, 16, 0, 17, 18, 6, 14, 20, 21, 13, 13, 11, 0, 12, 14, 10, 14, 15, 12, 12, 13, 11, 0, 13, 10, 11, 17, 18, 12, 13, 20, 15, 0, 11, 15, 14, 14, 23, 13, 10, 17, 9, 0, 12, 18, 11, 19, 12, 13, 13, 12, 12, 0, 8, 7, 6, 13, 32, 18, 14, 19, 12, 0, 14, 11, 12, 16, 21, 13, 11, 11, 16, 0, 12, 13, 12, 13, 61, 19, 8, 19, 14, 0, 19, 11, 15, 8, 27, 7, 12, 11, 7, 0, 5, 18, 14, 17, 30, 14, 13, 15, 7, 0, 13, 10, 12, 14, 23, 16, 13, 23, 20, 0, 17, 15, 11, 20, 15, 10, 14, 12, 11, 0, 17, 15, 16, 22, 33, 13, 13, 12, 13, 0, 14, 16, 12, 17, 21, 17, 14, 14, 6, 0, 14, 14, 12, 16, 20, 16, 14, 11, 9, 0, 11, 12, 6, 13, 33, 12, 12, 10, 14, 0, 12, 13, 15, 13, 26, 9, 15, 14, 16, 0, 13, 10, 15, 8, 16, 16, 8, 13, 8, 0, 14, 19, 13, 18, 23, 16, 13, 13, 13, 0, 11, 18, 8, 13, 29, 13, 7, 14, 7, 0, 12, 19, 9, 22, 34, 18, 14, 20, 14, 0, 11, 12, 16, 16, 24, 14, 11, 15, 8, 0, 11, 17, 11, 19, 29, 15, 6, 7, 15, 0, 13, 18, 15, 13, 17, 17, 15, 15, 14, 0, 9, 18, 14, 12, 26, 14, 15, 13, 12, 0, 12, 20, 15, 19, 35, 10, 11, 13, 13, 0, 10, 17, 12, 14, 17, 15, 16, 21, 12, 0, 15, 15, 13, 15, 18, 15, 12, 14, 13, 0, 13, 13, 6, 18, 15, 18, 9, 13, 14, 0, 14, 15, 13, 11, 20, 15, 6, 15, 13, 0, 12, 19, 16, 14, 32, 20, 15, 16, 13, 0, 8, 14, 9, 18, 27, 15, 12, 14, 13, 0, 15, 18, 8, 14, 21, 12, 14, 13, 13, 0, 10, 19, 12, 17, 24, 14, 11, 18, 12, 0, 13, 13, 13, 19, 26, 18, 13, 14, 10, 0, 13, 16, 13, 14, 23, 12, 13, 18, 12, 0, 16, 14, 14, 7, 17, 17, 10, 17, 6, 0, 13, 17, 14, 16, 21, 13, 15, 14, 14, 0, 13, 14, 17, 10, 24, 17, 13, 17, 14, 0, 9, 14, 15, 19, 22, 22, 12, 16, 11, 0, 8, 13, 10, 12, 29, 12, 16, 12, 13, 0, 15, 19, 8, 13, 20, 16, 8, 20, 16, 0, 14, 13, 11, 11, 22, 17, 12, 12, 13, 0, 13, 13, 7, 21, 26, 11, 10, 20, 16, 0, 13, 14, 10, 16, 38, 19, 13, 18, 9, 0, 14, 7, 18, 15, 18, 19, 13, 17, 10, 0, 15, 14, 13, 13, 26, 16, 7, 13, 13, 0, 12, 12, 13, 15, 16, 13, 14, 20, 9, 0, 12, 14, 17, 11, 21, 13, 12, 15, 13, 0, 12, 24, 12, 13, 29, 16, 8, 17, 14, 0, 10, 14, 18, 14, 25, 16, 11, 14, 13, 0, 16, 15, 13, 19, 23, 15, 13, 15, 8, 0, 13, 21, 9, 16, 27, 14, 6, 17, 13, 0, 13, 11, 14, 16, 21, 15, 11, 21, 14, 0, 14, 11, 11, 9, 16, 14, 11, 17, 11, 0, 9, 11, 15, 14, 24, 45, 13, 14, 14, 0, 12, 18, 12, 16, 14, 18, 13, 17, 9, 0, 10, 16, 9, 15, 22, 13, 15, 16, 14, 0, 16, 14, 12, 12, 29, 12, 13, 22, 7, 0, 11, 14, 12, 21, 26, 9, 9, 19, 8, 0, 9, 13, 7, 15, 20, 11, 14, 14, 11, 0, 9, 13, 15, 7, 27, 14, 15, 14, 16, 0, 13, 19, 9, 17, 24, 19, 13, 13, 14, 0, 9, 14, 7, 15, 29, 9, 15, 13, 11, 0, 15, 17, 15, 14, 129, 24, 13, 13, 14, 0, 15, 10, 12, 17, 12, 15, 13, 14, 11, 0, 9, 8, 12, 11, 25, 20, 14, 15, 13, 0, 13, 19, 11, 12, 20, 11, 12, 14, 16, 0, 14, 13, 10, 22, 31, 20, 12, 16, 11, 0, 15, 13, 9, 14, 24, 19, 10, 12, 15, 0, 11, 13, 13, 11, 29, 15, 13, 16, 9, 0, 12, 15, 7, 17, 14, 19, 12, 15, 13, 0, 14, 16, 18, 13, 25, 18, 13, 9, 10, 0, 12, 18, 12, 14, 15, 17, 14, 14, 8, 0, 9, 20, 14, 14, 22, 16, 13, 17, 13, 0, 18, 18, 12, 13, 40, 13, 13, 11, 9, 0, 9, 19, 11, 14, 29, 16, 15, 13, 8, 0, 17, 11, 9, 13, 27, 12, 14, 14, 13, 0, 12, 26, 13, 16, 14, 15, 8, 16, 13, 0, 15, 13, 16, 14, 29, 20, 10, 21, 13, 0, 7, 17, 12, 14, 19, 17, 12, 9, 14, 0, 17, 18, 10, 13, 109, 14, 13, 21, 11, 0, 15, 19, 12, 12, 23, 23, 13, 14, 15, 0, 13, 12, 12, 17, 16, 13, 13, 11, 11, 0, 9, 19, 10, 27, 18, 20, 12, 17, 13, 0, 13, 8, 6, 12, 29, 17, 13, 14, 10, 0, 16, 11, 11, 13, 30, 15, 13, 14, 15, 0, 7, 11, 13, 16, 26, 18, 9, 16, 14, 0, 16, 15, 13, 14, 26, 19, 10, 17, 8, 0, 9, 18, 13, 13, 25, 12, 12, 19, 14, 0, 14, 13, 10, 9, 24, 17, 17, 27, 13, 0, 12, 15, 13, 21, 18, 15, 20, 14, 11, 0, 14, 19, 10, 11, 16, 14, 12, 13, 18, 0, 14, 13, 10, 12, 25, 14, 10, 13, 11, 0, 8, 19, 15, 16, 21, 20, 11, 13, 10, 0, 12, 15, 14, 14, 26, 17, 14, 12, 14, 0, 8, 20, 21, 8, 26, 13, 15, 16, 14, 0, 8, 22, 12, 14, 34, 17, 15, 13, 8, 0, 13, 14, 9, 16, 18, 12, 13, 18, 11, 0, 14, 15, 13, 20, 23, 13, 7, 10, 13, 0, 9, 16, 15, 15, 18, 18, 16, 13, 8, 0, 16, 13, 7, 16, 17, 12, 5, 15, 8, 0, 13, 15, 9, 12, 25, 14, 13, 13, 18, 0, 18, 18, 10, 15, 28, 27, 11, 14, 13, 0, 14, 16, 11, 13, 9, 18, 12, 12, 12, 0, 8, 7, 17, 12, 25, 11, 14, 18, 10, 0, 14, 14, 14, 18, 25, 18, 15, 22, 17, 0, 11, 15, 15, 60, 22, 18, 13, 14, 13, 0, 16, 15, 10, 20, 25, 13, 13, 16, 14, 0, 5, 12, 15, 14, 27, 14, 12, 14, 11, 0, 11, 19, 12, 15, 23, 20, 13, 14, 14, 0, 13, 14, 15, 11, 25, 14, 16, 19, 8, 0, 17, 21, 13, 15, 21, 14, 13, 13, 11, 0, 11, 24, 13, 14, 20, 14, 15, 15, 10, 0, 14, 9, 13, 14, 26, 16, 15, 19, 17, 0, 17, 13, 17, 12, 35, 13, 11, 17, 13, 0, 13, 16, 15, 22, 24, 14, 8, 17, 10, 0, 10, 15, 15, 16, 29, 15, 14, 16, 14, 0, 10, 17, 10, 19, 61, 11, 13, 13, 11, 0, 15, 14, 15, 13, 18, 15, 13, 13, 16, 0, 11, 19, 16, 12, 24, 14, 11, 12, 15, 0, 15, 19, 11, 21, 27, 12, 10, 18, 14, 0, 9, 8, 12, 14, 20, 12, 13, 13, 14, 0, 14, 18, 11, 17, 14, 19, 16, 19, 8, 0, 16, 13, 10, 13, 23, 16, 15, 13, 9, 0, 13, 14, 12, 18, 38, 13, 13, 15, 13, 0, 9, 17, 15, 6, 12, 19, 10, 13, 13, 0, 8, 10, 9, 19, 32, 20, 9, 20, 14, 0, 16, 6, 6, 12, 26, 14, 12, 12, 13, 0, 14, 20, 16, 15, 15, 6, 12, 13, 13, 0, 17, 17, 13, 15, 46, 13, 12, 15, 10, 0, 16, 13, 13, 10, 22, 13, 12, 19, 10, 0, 16, 14, 14, 30, 15, 13, 16, 15, 11, 0, 16, 13, 11, 15, 32, 9, 12, 14, 9, 0, 12, 19, 13, 14, 25, 10, 11, 17, 12, 0, 11, 9, 6, 17, 22, 14, 13, 13, 18, 0, 11, 14, 13, 11, 18, 14, 12, 21, 11, 0, 12, 13, 10, 17, 24, 15, 15, 18, 16, 0, 11, 19, 14, 12, 29, 14, 12, 7, 13, 0, 14, 18, 17, 14, 29, 15, 13, 21, 16, 0, 11, 18, 13, 14, 27, 11, 12, 18, 10, 0, 14, 12, 11, 10, 32, 13, 9, 19, 10, 0, 12, 21, 8, 9, 26, 12, 11, 15, 12, 0, 13, 23, 14, 17, 16, 16, 14, 16, 15, 0, 8, 16, 13, 13, 16, 19, 14, 16, 9, 0, 10, 13, 13, 17, 29, 12, 12, 13, 8, 0, 13, 13, 10, 13, 17, 10, 13, 13, 9, 0, 16, 14, 11, 13, 25, 13, 15, 16, 11, 0, 14, 19, 16, 21, 29, 13, 17, 14, 9, 0, 13, 10, 12, 21, 23, 17, 13, 18, 15, 0, 12, 19, 13, 14, 34, 17, 8, 9, 14, 0, 13, 14, 7, 18, 24, 13, 13, 12, 7, 0, 13, 15, 11, 15, 18, 19, 10, 19, 12, 0, 14, 14, 16, 19, 23, 13, 12, 14, 11, 0, 15, 15, 11, 17, 18, 18, 12, 14, 14, 0, 17, 17, 13, 19, 53, 10, 10, 11, 12, 0, 16, 12, 11, 22, 15, 14, 10, 15, 18, 0, 13, 18, 6, 16, 26, 19, 11, 17, 15, 0, 6, 19, 8, 11, 24, 18, 12, 15, 16, 0, 10, 17, 16, 19, 52, 17, 8, 16, 18, 0, 14, 13, 11, 13, 15, 18, 14, 17, 8, 0, 10, 20, 14, 18, 15, 14, 7, 17, 6, 0, 9, 19, 14, 15, 29, 17, 18, 11, 13, 0, 13, 12, 13, 15, 21, 16, 14, 14, 6, 0, 16, 10, 8, 20, 17, 13, 13, 12, 13, 0, 14, 16, 12, 18, 92, 6, 10, 15, 14, 0, 8, 14, 12, 18, 29, 19, 16, 13, 10, 0, 17, 17, 16, 14, 27, 22, 13, 13, 13, 0, 11, 17, 13, 8, 20, 17, 12, 16, 12, 0, 13, 14, 15, 16, 15, 15, 10, 15, 14, 0, 14, 16, 8, 18, 28, 12, 14, 15, 13, 0, 10, 12, 13, 14, 20, 16, 15, 10, 13, 0, 12, 14, 17, 12, 50, 15, 16, 14, 11, 0, 14, 16, 8, 13, 14, 13, 17, 10, 13, 0, 14, 20, 12, 14, 32, 14, 15, 15, 15, 0, 10, 15, 15, 15, 21, 12, 15, 11, 13, 0, 14, 9, 14, 13, 17, 15, 9, 8, 12, 0, 10, 20, 19, 14, 17, 16, 7, 14, 14, 0, 11, 13, 10, 21, 32, 14, 14, 16, 14, 0, 12, 16, 13, 11, 24, 12, 13, 19, 13, 0, 9, 19, 14, 19, 22, 13, 10, 16, 13, 0, 10, 9, 14, 13, 10, 17, 13, 10, 12, 0, 9, 14, 12, 19, 25, 12, 13, 11, 11, 0, 10, 18, 13, 12, 25, 14, 9, 18, 13, 0, 15, 13, 8, 14, 21, 13, 8, 15, 12, 0, 11, 15, 6, 21, 36, 18, 13, 17, 14, 0, 14, 20, 13, 12, 22, 47, 11, 19, 17, 0, 12, 15, 15, 19, 21, 13, 10, 19, 12, 0, 13, 19, 14, 14, 25, 14, 15, 14, 10, 0, 8, 15, 9, 18, 21, 13, 15, 13, 13, 0, 14, 14, 17, 12, 27, 7, 11, 14, 11, 0, 18, 11, 15, 19, 28, 22, 11, 11, 15, 0, 12, 8, 11, 14, 38, 14, 11, 19, 14, 0, 14, 19, 9, 18, 30, 14, 13, 19, 15, 0, 16, 19, 14, 20, 27, 14, 11, 9, 10, 0, 10, 11, 13, 11, 15, 8, 10, 10, 13, 0, 14, 22, 15, 8, 29, 10, 14, 15, 11, 0, 19, 11, 12, 19, 25, 14, 8, 17, 11, 0, 14, 16, 16, 12, 20, 13, 12, 13, 14, 0, 14, 16, 14, 14, 25, 16, 12, 12, 15, 0, 13, 19, 16, 14, 29, 15, 14, 13, 13, 0, 12, 13, 9, 10, 21, 14, 12, 20, 12, 0, 12, 19, 10, 14, 12, 19, 12, 14, 11, 0, 9, 13, 17, 22, 30, 8, 8, 21, 12, 0, 12, 11, 19, 17, 23, 14, 13, 11, 13, 0, 12, 13, 11, 13, 35, 13, 12, 13, 9, 0, 14, 18, 19, 13, 14, 20, 15, 12, 11, 0, 15, 16, 16, 20, 36, 14, 13, 19, 14, 0, 17, 14, 13, 16, 24, 19, 13, 14, 10, 0, 5, 14, 15, 18, 24, 15, 13, 14, 8, 0, 12, 16, 9, 19, 52, 11, 11, 14, 11, 0, 13, 13, 14, 19, 22, 10, 14, 18, 14, 0, 13, 12, 13, 30, 25, 15, 8, 13, 17, 0, 17, 17, 12, 15, 19, 13, 12, 19, 13, 0, 14, 13, 10, 19, 16, 21, 14, 14, 14, 0, 9, 13, 12, 12, 24, 16, 12, 18, 15, 0, 15, 10, 8, 12, 24, 10, 11, 19, 12, 0, 16, 14, 14, 14, 14, 14, 13, 14, 16, 0, 13, 21, 9, 9, 32, 9, 12, 17, 13, 0, 16, 9, 14, 16, 7, 13, 16, 20, 17, 0, 13, 15, 14, 21, 29, 18, 12, 19, 12, 0, 15, 12, 13, 13, 24, 15, 17, 18, 11, 0, 13, 16, 13, 16, 21, 17, 13, 9, 13, 0, 7, 20, 10, 6, 21, 18, 14, 18, 14, 0, 13, 16, 15, 13, 25, 20, 14, 17, 11, 0, 14, 20, 17, 17, 25, 12, 9, 12, 13, 0, 12, 13, 15, 17, 23, 16, 9, 14, 14, 0, 11, 14, 12, 13, 20, 8, 13, 21, 13, 0, 13, 14, 11, 13, 25, 20, 14, 11, 13, 0, 11, 17, 14, 11, 61, 20, 11, 14, 14, 0, 15, 21, 11, 20, 33, 17, 16, 15, 11, 0, 12, 9, 12, 15, 25, 13, 11, 14, 15, 0, 10, 13, 13, 10, 27, 14, 11, 14, 14, 0, 15, 8, 15, 18, 29, 13, 14, 20, 11, 0, 12, 15, 13, 16, 27, 14, 11, 14, 13, 0, 15, 11, 14, 15, 21, 17, 12, 13, 10, 0, 14, 12, 13, 19, 30, 12, 11, 15, 13, 0, 8, 16, 9, 13, 24, 15, 11, 18, 16, 0, 14, 17, 12, 13, 21, 14, 17, 13, 7, 0, 14, 17, 12, 14, 17, 12, 17, 15, 13, 0, 10, 20, 13, 16, 34, 6, 15, 23, 16, 0, 13, 30, 12, 12, 20, 13, 13, 18, 12, 0, 12, 10, 15, 15, 29, 11, 12, 12, 12, 0, 10, 11, 17, 20, 24, 13, 8, 11, 12, 0, 12, 14, 9, 25, 29, 18, 15, 13, 13, 0, 13, 11, 8, 14, 33, 17, 13, 14, 13, 0, 13, 13, 9, 10, 20, 20, 13, 10, 11, 0, 14, 13, 16, 22, 29, 16, 15, 14, 13, 0, 17, 18, 15, 13, 28, 13, 13, 21, 19, 0, 8, 14, 13, 16, 24, 13, 14, 20, 6, 0, 6, 6, 11, 14, 35, 20, 6, 18, 13, 0, 13, 17, 8, 15, 25, 6, 6, 16, 11, 0, 12, 16, 16, 10, 25, 18, 6, 19, 14, 0, 18, 6, 13, 12, 33, 15, 18, 13, 17, 0, 16, 9, 10, 13, 26, 17, 10, 13, 13, 0, 12, 15, 8, 9, 25, 13, 14, 8, 13, 0, 13, 19, 12, 12, 29, 12, 12, 11, 17, 0, 11, 13, 16, 15, 24, 81, 13, 20, 13, 0, 9, 6, 13, 15, 29, 8, 15, 19, 14, 0, 14, 13, 13, 16, 23, 17, 18, 17, 11, 0, 14, 20, 16, 19, 14, 11, 15, 22, 12, 0, 17, 10, 14, 10, 28, 14, 17, 11, 11, 0, 12, 16, 14, 12, 34, 12, 11, 13, 13, 0, 9, 12, 11, 19, 41, 18, 12, 14, 14, 0, 11, 15, 8, 14, 30, 15, 15, 14, 12, 0, 9, 18, 17, 14, 38, 10, 15, 19, 11, 0, 11, 15, 16, 11, 44, 6, 6, 28, 14, 0, 15, 18, 9, 15, 23, 16, 15, 21, 8, 0, 13, 6, 9, 13, 21, 14, 11, 16, 17, 0, 13, 19, 15, 15, 26, 11, 15, 22, 10, 0, 9, 14, 10, 15, 14, 19, 16, 13, 17, 0, 11, 9, 6, 15, 18, 14, 17, 13, 14, 0, 14, 15, 13, 14, 14, 12, 14, 15, 12, 0, 11, 11, 13, 8, 32, 11, 12, 18, 9, 0, 14, 16, 14, 14, 21, 21, 14, 22, 10, 0, 11, 15, 13, 14, 28, 12, 14, 13, 16, 0, 13, 20, 13, 17, 27, 8, 9, 13, 13, 0, 16, 11, 14, 14, 18, 18, 12, 13, 16, 0, 11, 11, 14, 14, 24, 19, 11, 15, 9, 0, 11, 16, 13, 12, 22, 13, 15, 17, 9, 0, 8, 16, 10, 15, 35, 20, 13, 22, 14, 0, 14, 16, 13, 14, 15, 14, 13, 14, 14, 0, 13, 19, 14, 16, 29, 14, 15, 22, 14, 0, 16, 6, 14, 17, 29, 17, 11, 20, 12, 0, 12, 14, 13, 21, 30, 10, 15, 16, 13, 0, 10, 14, 6, 14, 16, 19, 9, 17, 13, 0, 13, 13, 12, 18, 15, 17, 9, 17, 6, 0, 20, 13, 15, 16, 14, 13, 13, 12, 13, 0, 11, 15, 11, 16, 18, 13, 10, 11, 13, 0, 16, 14, 16, 20, 26, 20, 16, 20, 16, 0, 15, 13, 13, 19, 37, 19, 18, 15, 9, 0, 15, 14, 12, 14, 22, 13, 14, 15, 9, 0, 15, 14, 14, 42, 13, 21, 10, 15, 15, 0, 14, 12, 13, 14, 19, 18, 14, 10, 11, 0, 15, 20, 13, 14, 13, 14, 16, 13, 15, 0, 11, 13, 14, 18, 46, 21, 14, 17, 13, 0, 21, 17, 15, 17, 25, 20, 14, 12, 11, 0, 13, 9, 15, 12, 27, 11, 16, 17, 13, 0, 18, 14, 14, 11, 26, 17, 16, 13, 16, 0, 12, 14, 11, 10, 18, 14, 14, 11, 7, 0, 17, 16, 16, 13, 34, 15, 13, 10, 13, 0, 15, 17, 15, 16, 29, 20, 12, 21, 15, 0, 13, 19, 8, 14, 31, 18, 14, 14, 11, 0, 7, 14, 13, 13, 38, 19, 14, 13, 11, 0, 14, 14, 13, 15, 24, 10, 13, 17, 17, 0, 11, 15, 17, 13, 34, 22, 11, 15, 15, 0, 8, 20, 17, 17, 32, 15, 10, 19, 13, 0, 12, 14, 14, 16, 23, 18, 11, 13, 8, 0, 14, 12, 17, 22, 24, 16, 13, 18, 13, 0, 5, 18, 17, 11, 27, 13, 16, 18, 13, 0, 9, 18, 12, 15, 13, 19, 15, 7, 9, 0, 8, 19, 14, 13, 22, 13, 15, 18, 13, 0, 15, 14, 13, 13, 27, 12, 13, 13, 13, 0, 12, 14, 12, 17, 15, 11, 17, 16, 7, 0, 13, 16, 17, 7, 20, 13, 16, 26, 16, 0, 14, 19, 13, 20, 29, 12, 13, 20, 11, 0, 11, 17, 11, 12, 26, 10, 14, 14, 16, 0, 12, 6, 11, 22, 29, 20, 14, 17, 17, 0, 6, 17, 12, 14, 22, 14, 12, 13, 11, 0, 14, 19, 11, 13, 20, 19, 12, 17, 10, 0, 13, 19, 13, 7, 34, 13, 11, 15, 14, 0, 16, 19, 12, 17, 31, 14, 13, 12, 18, 0, 16, 21, 15, 19, 27, 17, 12, 14, 13, 0, 13, 16, 10, 13, 23, 14, 15, 17, 14, 0, 13, 17, 11, 19, 24, 17, 9, 16, 13, 0, 18, 13, 11, 20, 30, 20, 11, 13, 16, 0, 10, 16, 11, 17, 24, 17, 14, 13, 13, 0, 14, 18, 16, 16, 21, 22, 11, 15, 14, 0, 7, 11, 14, 14, 28, 18, 13, 13, 18, 0, 11, 11, 13, 14, 15, 8, 13, 12, 15, 0, 14, 15, 13, 16, 24, 17, 12, 14, 11, 0, 11, 14, 13, 11, 29, 16, 14, 14, 15, 0, 14, 14, 11, 22, 25, 19, 11, 16, 13, 0, 17, 6, 18, 9, 16, 12, 10, 12, 12, 0, 13, 13, 11, 18, 18, 18, 14, 7, 7, 0, 14, 15, 18, 17, 31, 21, 13, 15, 12, 0, 10, 10, 13, 16, 27, 20, 12, 15, 11, 0, 16, 19, 13, 21, 14, 18, 13, 9, 17, 0, 12, 19, 14, 13, 33, 18, 13, 16, 16, 0, 14, 18, 14, 16, 24, 14, 15, 19, 14, 0, 15, 13, 16, 21, 189, 16, 13, 13, 14, 0, 13, 9, 13, 21, 23, 15, 12, 22, 10, 0, 14, 17, 15, 17, 14, 8, 13, 12, 13, 0, 16, 14, 12, 16, 33, 15, 12, 14, 13, 0, 8, 21, 14, 12, 9, 13, 14, 16, 13, 0, 14, 11, 10, 15, 27, 20, 14, 19, 10, 0, 12, 13, 16, 19, 21, 14, 14, 22, 13, 0, 11, 18, 10, 13, 7, 16, 11, 13, 14, 0, 16, 14, 13, 18, 17, 16, 10, 14, 11, 0, 13, 36, 12, 18, 18, 18, 9, 17, 11, 0, 14, 14, 8, 14, 32, 21, 11, 16, 13, 0, 10, 18, 11, 16, 23, 19, 10, 12, 13, 0, 14, 14, 11, 16, 24, 16, 18, 14, 15, 0, 11, 16, 13, 14, 14, 20, 11, 14, 15, 0, 13, 8, 13, 10, 41, 22, 16, 23, 8, 0, 11, 17, 12, 20, 30, 15, 10, 14, 11, 0, 10, 19, 16, 13, 24, 20, 11, 11, 14, 0, 10, 12, 11, 16, 22, 19, 13, 20, 13, 0, 16, 13, 13, 12, 27, 10, 14, 13, 17, 0, 14, 16, 14, 22, 23, 20, 15, 20, 12, 0, 11, 17, 16, 12, 19, 17, 18, 16, 11, 0, 8, 8, 15, 18, 28, 15, 10, 14, 13, 0, 15, 10, 13, 10, 23, 18, 13, 19, 12, 0, 12, 15, 15, 14, 24, 22, 13, 14, 14, 0, 14, 19, 18, 19, 21, 19, 12, 16, 11, 0, 17, 12, 11, 13, 33, 11, 15, 14, 12, 0, 15, 18, 14, 12, 26, 14, 16, 12, 16, 0, 13, 21, 15, 23, 21, 20, 14, 18, 13, 0, 13, 19, 13, 13, 29, 17, 12, 13, 17, 0, 15, 18, 15, 13, 24, 16, 15, 18, 13, 0, 13, 15, 16, 17, 15, 21, 13, 13, 16, 0, 14, 19, 13, 13, 30, 8, 13, 16, 13, 0, 10, 9, 16, 22, 32, 21, 15, 12, 14, 0, 13, 9, 12, 15, 21, 12, 14, 14, 16, 0, 14, 19, 13, 20, 24, 14, 14, 14, 12, 0, 12, 19, 14, 14, 33, 8, 10, 15, 16, 0, 13, 22, 9, 17, 32, 18, 13, 9, 11, 0, 13, 13, 13, 19, 33, 12, 13, 22, 15, 0, 17, 12, 17, 14, 27, 19, 14, 16, 11, 0, 15, 14, 14, 19, 33, 7, 12, 14, 15, 0, 16, 14, 12, 11, 28, 22, 13, 9, 11, 0, 12, 11, 13, 18, 21, 22, 15, 15, 10, 0, 13, 7, 12, 16, 29, 20, 17, 13, 12, 0, 14, 7, 14, 14, 32, 18, 15, 17, 17, 0, 11, 18, 13, 16, 25, 12, 13, 14, 11, 0, 16, 14, 14, 17, 15, 14, 7, 19, 15, 0, 11, 14, 15, 9, 17, 15, 13, 12, 14, 0, 9, 9, 16, 23, 30, 10, 13, 12, 13, 0, 13, 18, 9, 21, 15, 19, 13, 19, 13, 0, 11, 15, 14, 17, 24, 9, 13, 17, 15, 0, 12, 16, 14, 16, 28, 13, 11, 12, 10, 0, 16, 19, 13, 9, 29, 14, 14, 17, 12, 0, 13, 15, 9, 13, 19, 9, 11, 15, 14, 0, 15, 9, 13, 13, 24, 19, 13, 18, 9, 0, 13, 14, 12, 18, 27, 19, 13, 18, 12, 0, 13, 15, 13, 14, 37, 14, 15, 15, 16, 0, 15, 21, 16, 20, 27, 18, 11, 17, 15, 0, 16, 19, 16, 22, 27, 12, 19, 30, 13, 0, 18, 8, 10, 20, 20, 18, 13, 12, 14, 0, 15, 19, 12, 14, 18, 22, 14, 16, 11, 0, 15, 19, 7, 14, 37, 16, 13, 17, 11, 0, 9, 22, 14, 13, 15, 17, 11, 11, 16, 0, 10, 21, 13, 14, 26, 13, 12, 22, 14, 0, 18, 14, 12, 28, 26, 14, 13, 8, 15, 0, 15, 19, 12, 20, 20, 16, 9, 15, 13, 0, 17, 12, 16, 18, 36, 18, 10, 18, 13, 0, 14, 15, 13, 19, 24, 10, 15, 14, 15, 0, 14, 20, 10, 18, 20, 16, 13, 17, 14, 0, 6, 17, 16, 12, 26, 13, 14, 12, 10, 0, 12, 18, 12, 19, 21, 17, 14, 14, 16, 0, 16, 21, 12, 13, 12, 18, 11, 19, 13, 0, 8, 16, 14, 17, 25, 19, 8, 18, 6, 0, 11, 13, 13, 18, 27, 11, 16, 18, 10, 0, 14, 14, 14, 18, 24, 18, 9, 19, 13, 0, 17, 20, 13, 11, 38, 11, 15, 15, 12, 0, 15, 14, 6, 19, 35, 15, 17, 22, 12, 0, 9, 20, 16, 14, 38, 6, 6, 14, 8, 0, 10, 18, 14, 11, 27, 13, 13, 17, 9, 0, 18, 6, 13, 16, 29, 16, 15, 22, 14, 0, 17, 11, 12, 14, 24, 15, 15, 18, 8, 0, 13, 18, 10, 25, 35, 14, 15, 13, 14, 0, 15, 11, 9, 18, 15, 18, 11, 15, 8, 0, 13, 15, 11, 11, 25, 15, 14, 12, 14, 0, 13, 14, 11, 21, 27, 19, 14, 19, 13, 0, 17, 19, 13, 18, 25, 19, 15, 14, 15, 0, 16, 16, 12, 18, 14, 19, 14, 11, 11, 0, 17, 15, 18, 16, 25, 13, 12, 20, 10, 0, 12, 19, 8, 8, 53, 13, 12, 11, 13, 0, 11, 17, 13, 13, 14, 12, 13, 11, 14, 0, 18, 13, 8, 18, 17, 19, 14, 17, 13, 0, 16, 20, 11, 11, 52, 19, 12, 18, 19, 0, 13, 15, 15, 14, 26, 14, 11, 15, 12, 0, 15, 17, 13, 14, 15, 13, 12, 13, 14, 0, 18, 6, 14, 17, 29, 12, 13, 14, 14, 0, 13, 13, 13, 17, 20, 19, 19, 11, 14, 0, 16, 8, 17, 14, 18, 15, 7, 14, 12, 0, 14, 17, 11, 13, 21, 21, 14, 17, 9, 0, 12, 15, 12, 14, 25, 15, 13, 19, 10, 0, 14, 16, 12, 19, 38, 16, 14, 18, 19, 0, 9, 13, 13, 15, 21, 18, 12, 18, 15, 0, 14, 19, 16, 12, 32, 10, 8, 14, 16, 0, 14, 17, 14, 13, 17, 15, 13, 18, 13, 0, 15, 17, 14, 15, 18, 21, 15, 15, 9, 0, 14, 15, 13, 15, 31, 13, 9, 12, 9, 0, 18, 20, 17, 19, 17, 13, 16, 17, 15, 0, 14, 15, 15, 19, 115, 12, 13, 19, 16, 0, 12, 18, 12, 13, 25, 18, 14, 13, 13, 0, 10, 19, 13, 14, 24, 8, 12, 18, 13, 0, 16, 18, 9, 13, 15, 17, 15, 15, 18, 0, 14, 11, 10, 21, 30, 18, 11, 17, 13, 0, 13, 17, 16, 15, 33, 19, 11, 21, 7, 0, 15, 15, 12, 19, 61, 9, 10, 11, 13, 0, 17, 18, 12, 21, 21, 13, 14, 14, 13, 0, 10, 13, 14, 13, 20, 5, 13, 16, 8, 0, 11, 11, 11, 15, 21, 11, 15, 12, 14, 0, 11, 12, 13, 14, 33, 19, 17, 7, 15, 0, 9, 21, 11, 17, 25, 18, 12, 15, 16, 0, 8, 13, 13, 12, 18, 23, 14, 16, 17, 0, 13, 17, 10, 15, 32, 18, 8, 13, 13, 0, 15, 17, 11, 19, 28, 13, 7, 21, 12, 0, 10, 14, 17, 9, 52, 13, 19, 13, 7, 0, 13, 12, 15, 18, 26, 13, 13, 18, 14, 0, 18, 13, 11, 17, 14, 14, 8, 16, 16, 0, 17, 17, 8, 19, 21, 20, 8, 19, 10, 0, 16, 19, 16, 14, 18, 19, 10, 12, 16, 0, 16, 20, 13, 12, 33, 19, 14, 14, 9, 0, 13, 14, 12, 19, 32, 20, 17, 14, 14, 0, 13, 18, 8, 15, 30, 11, 14, 16, 12, 0, 11, 12, 13, 19, 32, 15, 12, 9, 13, 0, 14, 17, 14, 18, 26, 10, 11, 20, 17, 0, 14, 17, 17, 13, 22, 15, 13, 17, 11, 0, 11, 16, 13, 14, 30, 20, 14, 15, 17, 0, 10, 14, 11, 14, 29, 14, 13, 12, 14, 0, 14, 18, 17, 21, 22, 17, 9, 21, 14, 0, 11, 13, 10, 19, 28, 16, 8, 15, 15, 0, 11, 21, 10, 15, 32, 13, 9, 14, 11, 0, 12, 17, 14, 21, 29, 10, 11, 17, 15, 0, 17, 16, 11, 19, 34, 17, 14, 23, 13, 0, 12, 19, 8, 12, 21, 18, 17, 11, 11, 0, 19, 12, 13, 18, 23, 18, 13, 16, 11, 0, 11, 13, 13, 10, 28, 13, 13, 11, 13, 0, 8, 16, 14, 12, 27, 15, 15, 17, 14, 0, 17, 21, 14, 21, 28, 18, 13, 19, 17, 0, 17, 15, 13, 14, 25, 19, 13, 18, 12, 0, 17, 22, 12, 18, 22, 16, 8, 11, 14, 0, 12, 15, 12, 14, 23, 14, 16, 12, 13, 0, 16, 9, 14, 18, 18, 18, 11, 15, 13, 0, 11, 16, 11, 12, 29, 23, 13, 14, 14, 0, 15, 19, 12, 14, 38, 14, 13, 17, 16, 0, 12, 7, 16, 19, 24, 13, 14, 13, 14, 0, 9, 19, 12, 11, 38, 17, 17, 20, 15, 0, 13, 17, 12, 20, 31, 15, 16, 17, 15, 0, 14, 14, 13, 18, 17, 11, 13, 19, 13, 0, 16, 13, 17, 19, 34, 15, 13, 19, 9, 0, 13, 13, 14, 17, 17, 14, 7, 17, 15, 0, 17, 20, 14, 14, 24, 22, 14, 13, 21, 0, 15, 19, 12, 14, 21, 15, 7, 14, 13, 0, 12, 33, 18, 17, 16, 15, 14, 18, 11, 0, 13, 23, 12, 8, 24, 14, 13, 9, 11, 0, 7, 16, 8, 10, 21, 12, 15, 17, 19, 0, 7, 19, 11, 30, 33, 13, 10, 8, 13, 0, 16, 13, 20, 8, 23, 13, 10, 18, 13, 0, 18, 14, 13, 8, 35, 13, 8, 12, 11, 0, 13, 19, 13, 19, 23, 25, 11, 21, 9, 0, 14, 9, 13, 15, 34, 19, 14, 14, 15, 0, 13, 19, 10, 17, 35, 14, 17, 22, 17, 0, 14, 17, 17, 14, 17, 10, 13, 24, 17, 0, 13, 16, 11, 16, 25, 13, 18, 13, 13, 0, 12, 21, 15, 16, 26, 18, 14, 17, 12, 0, 5, 5, 5, 5, 5, 13, 8, 20, 12, 0, 5, 5, 12, 18, 23, 17, 9, 13, 8, 0, 5, 14, 13, 13, 27, 12, 14, 32, 13, 0, 5, 19, 14, 14, 18, 21, 7, 13, 14, 0, 5, 13, 14, 13, 25, 9, 13, 18, 12, 0, 17, 8, 14, 41, 30, 17, 11, 21, 11, 0, 13, 15, 11, 17, 40, 10, 13, 18, 16, 0, 14, 13, 17, 12, 19, 14, 12, 18, 13, 0, 11, 10, 15, 17, 29, 16, 14, 16, 12, 0, 12, 19, 11, 20, 24, 20, 12, 14, 17, 0, 5, 5, 9, 16, 30, 16, 9, 21, 17, 0, 5, 14, 14, 13, 35, 17, 15, 18, 11, 0, 13, 12, 11, 19, 23, 17, 7, 17, 13, 0, 15, 17, 13, 17, 25, 13, 8, 21, 13, 0, 17, 13, 14, 15, 26, 19, 10, 16, 17, 0, 10, 11, 12, 22, 30, 14, 13, 15, 10, 0, 10, 15, 14, 10, 53, 14, 14, 14, 10, 0, 12, 12, 18, 11, 35, 12, 14, 15, 9, 0, 13, 19, 13, 21, 24, 11, 14, 20, 14, 0, 14, 9, 13, 12, 24, 13, 12, 18, 7, 0, 5, 22, 17, 20, 26, 11, 18, 19, 14, 0, 13, 9, 13, 12, 29, 9, 15, 15, 16, 0, 11, 18, 18, 11, 27, 14, 14, 8, 13, 0, 13, 16, 13, 19, 21, 14, 9, 13, 18, 0, 14, 18, 9, 16, 25, 12, 11, 19, 13, 0, 12, 14, 9, 18, 25, 15, 14, 12, 9, 0, 14, 13, 12, 19, 21, 26, 16, 12, 10, 0, 19, 21, 13, 13, 36, 17, 18, 15, 11, 0, 11, 18, 12, 14, 24, 14, 17, 9, 16, 0, 19, 20, 13, 17, 21, 7, 13, 18, 8, 0, 5, 12, 11, 17, 26, 14, 13, 19, 14, 0, 16, 18, 7, 20, 34, 19, 13, 8, 14, 0, 15, 13, 11, 14, 22, 14, 15, 20, 17, 0, 14, 11, 14, 9, 24, 18, 11, 15, 13, 0, 13, 16, 15, 14, 17, 16, 15, 11, 15, 0, 12, 13, 15, 15, 28, 15, 12, 19, 9, 0, 13, 14, 16, 21, 33, 13, 11, 22, 16, 0, 9, 20, 13, 16, 24, 13, 16, 16, 9, 0, 12, 21, 10, 14, 26, 20, 17, 11, 14, 0, 19, 21, 14, 30, 34, 14, 16, 13, 13, 0, 5, 14, 13, 13, 14, 18, 11, 7, 11, 0, 14, 18, 17, 16, 27, 18, 12, 13, 10, 0, 13, 13, 10, 9, 27, 21, 11, 16, 13, 0, 17, 7, 14, 13, 26, 13, 10, 12, 13, 0, 10, 9, 11, 18, 30, 18, 17, 17, 10, 0, 14, 19, 10, 14, 27, 12, 13, 18, 12, 0, 9, 11, 13, 14, 8, 13, 15, 12, 11, 0, 11, 13, 12, 18, 14, 19, 16, 8, 10, 0, 13, 8, 18, 11, 23, 12, 14, 12, 15, 0, 14, 17, 14, 12, 23, 15, 9, 16, 10, 0, 17, 18, 12, 12, 34, 24, 14, 22, 14, 0, 16, 14, 16, 14, 19, 13, 7, 12, 17, 0, 14, 26, 15, 13, 27, 13, 18, 18, 11, 0, 16, 18, 16, 7, 69, 16, 17, 14, 11, 0, 16, 8, 8, 12, 17, 9, 17, 17, 17, 0, 13, 11, 18, 26, 18, 17, 17, 18, 16, 0, 10, 13, 16, 19, 13, 14, 18, 12, 15, 0, 13, 14, 16, 12, 19, 9, 16, 14, 11, 0, 12, 19, 11, 14, 25, 17, 8, 17, 13, 0, 19, 13, 11, 13, 30, 14, 13, 14, 15, 0, 14, 17, 16, 19, 25, 15, 13, 12, 14, 0, 14, 19, 13, 21, 32, 13, 8, 29, 12, 0, 17, 14, 15, 20, 29, 12, 18, 14, 14, 0, 9, 17, 14, 14, 31, 16, 12, 17, 11, 0, 9, 11, 13, 19, 25, 17, 14, 11, 13, 0, 14, 20, 17, 17, 18, 19, 12, 16, 11, 0, 13, 16, 17, 18, 33, 17, 7, 21, 14, 0, 14, 14, 8, 14, 26, 13, 14, 14, 13, 0, 7, 18, 14, 19, 27, 14, 16, 14, 13, 0, 14, 23, 12, 12, 17, 20, 13, 14, 8, 0, 11, 13, 18, 16, 19, 13, 15, 15, 14, 0, 19, 19, 14, 14, 30, 19, 16, 20, 13, 0, 11, 8, 9, 20, 34, 13, 12, 15, 11, 0, 16, 15, 13, 14, 23, 18, 10, 14, 8, 0, 15, 6, 18, 19, 24, 21, 16, 18, 8, 0, 13, 14, 12, 17, 22, 18, 8, 18, 16, 0, 17, 18, 14, 21, 144, 17, 14, 17, 12, 0, 14, 11, 13, 18, 22, 14, 10, 14, 18, 0, 13, 10, 13, 19, 26, 13, 12, 22, 13, 0, 13, 9, 11, 13, 30, 13, 11, 17, 11, 0, 12, 13, 11, 20, 29, 8, 10, 15, 12, 0, 11, 13, 8, 11, 26, 18, 16, 13, 17, 0, 13, 14, 13, 16, 17, 19, 15, 17, 16, 0, 19, 13, 16, 20, 33, 15, 16, 13, 17, 0, 17, 19, 11, 14, 27, 19, 13, 16, 13, 0, 9, 19, 11, 14, 23, 19, 13, 14, 13, 0, 14, 17, 16, 17, 35, 14, 11, 47, 14, 0, 13, 19, 16, 21, 30, 19, 10, 13, 18, 0, 16, 15, 13, 17, 13, 14, 13, 15, 9, 0, 13, 16, 15, 16, 21, 14, 10, 8, 14, 0, 14, 13, 14, 21, 38, 21, 16, 13, 13, 0, 10, 12, 14, 15, 23, 18, 13, 15, 14, 0, 10, 14, 11, 16, 30, 19, 11, 13, 15, 0, 13, 18, 15, 14, 30, 12, 14, 21, 17, 0, 14, 19, 16, 16, 30, 10, 13, 15, 11, 0, 7, 14, 15, 19, 33, 20, 12, 14, 17, 0, 17, 18, 16, 15, 29, 17, 13, 19, 12, 0, 13, 19, 15, 17, 18, 21, 17, 12, 13, 0, 17, 16, 15, 15, 29, 20, 16, 16, 11, 0, 13, 20, 16, 14, 17, 19, 14, 14, 13, 0, 5, 5, 9, 19, 32, 16, 16, 16, 9, 0, 5, 13, 10, 14, 30, 18, 18, 14, 10, 0, 18, 15, 12, 13, 25, 15, 12, 17, 10, 0, 15, 15, 13, 26, 23, 19, 14, 19, 13, 0, 12, 17, 15, 14, 15, 21, 12, 20, 16, 0, 11, 21, 15, 13, 34, 16, 13, 11, 14, 0, 15, 17, 16, 14, 31, 13, 17, 14, 13, 0, 16, 12, 13, 15, 29, 21, 13, 16, 12, 0, 10, 15, 15, 13, 24, 18, 14, 18, 19, 0, 11, 11, 13, 13, 25, 16, 7, 28, 14, 0, 5, 13, 11, 15, 21, 19, 16, 15, 16, 0, 19, 30, 6, 19, 6, 14, 11, 18, 12, 0, 12, 17, 17, 17, 17, 14, 17, 12, 12, 0, 11, 14, 6, 13, 16, 18, 13, 13, 16, 0, 11, 18, 13, 16, 21, 15, 13, 21, 13, 0, 13, 17, 17, 14, 28, 14, 8, 16, 8, 0, 15, 28, 15, 17, 45, 16, 14, 13, 11, 0, 11, 15, 12, 13, 29, 19, 8, 13, 8, 0, 15, 15, 10, 15, 30, 11, 12, 14, 12, 0, 14, 13, 17, 21, 26, 16, 11, 18, 15, 0, 14, 17, 16, 17, 21, 15, 10, 17, 10, 0, 12, 19, 13, 19, 33, 18, 13, 9, 11, 0, 14, 15, 14, 19, 26, 23, 17, 27, 13, 0, 10, 18, 7, 14, 21, 20, 13, 9, 18, 0, 16, 17, 8, 15, 22, 20, 15, 11, 12, 0, 13, 11, 13, 19, 21, 16, 13, 26, 10, 0, 12, 9, 12, 29, 17, 15, 16, 19, 11, 0, 14, 16, 13, 20, 38, 16, 12, 12, 8, 0, 15, 13, 11, 16, 23, 11, 15, 14, 8, 0, 16, 15, 17, 14, 19, 21, 14, 11, 11, 0, 19, 16, 16, 23, 17, 9, 12, 11, 14, 0, 11, 8, 6, 14, 35, 18, 17, 7, 12, 0, 15, 11, 18, 10, 26, 22, 11, 13, 12, 0, 14, 16, 16, 13, 24, 21, 12, 14, 13, 0, 18, 11, 13, 17, 29, 17, 16, 18, 11, 0, 10, 12, 15, 20, 19, 18, 13, 17, 11, 0, 12, 12, 12, 18, 22, 18, 12, 18, 13, 0, 15, 14, 10, 12, 26, 21, 16, 15, 13, 0, 11, 12, 13, 18, 18, 22, 15, 20, 10, 0, 16, 16, 13, 16, 21, 9, 16, 13, 9, 0, 18, 19, 18, 19, 27, 15, 17, 21, 10, 0, 14, 18, 17, 17, 22, 14, 13, 56, 8, 0, 16, 11, 12, 16, 24, 13, 14, 15, 13, 0, 17, 13, 15, 9, 30, 18, 11, 15, 10, 0, 13, 17, 12, 18, 24, 18, 13, 20, 15, 0, 14, 18, 13, 12, 21, 20, 17, 17, 11, 0, 7, 13, 13, 17, 29, 19, 11, 10, 10, 0, 13, 24, 12, 17, 26, 8, 11, 16, 14, 0, 12, 13, 14, 18, 24, 16, 15, 20, 13, 0, 13, 22, 11, 18, 34, 12, 12, 14, 12, 0, 14, 19, 13, 21, 20, 17, 13, 22, 14, 0, 12, 20, 13, 16, 19, 21, 11, 12, 16, 0, 8, 8, 13, 19, 29, 18, 17, 14, 9, 0, 13, 19, 9, 14, 29, 12, 13, 14, 15, 0, 16, 14, 13, 15, 28, 11, 6, 17, 10, 0, 14, 13, 9, 12, 27, 13, 11, 12, 10, 0, 13, 19, 12, 17, 32, 7, 15, 7, 7, 0, 17, 19, 12, 16, 17, 16, 12, 7, 13, 0, 16, 17, 16, 20, 29, 16, 15, 13, 10, 0, 19, 19, 19, 13, 13, 17, 14, 17, 14, 0, 16, 16, 18, 13, 34, 14, 9, 22, 14, 0, 15, 15, 15, 9, 116, 12, 10, 14, 16, 0, 14, 12, 18, 13, 20, 25, 7, 18, 7, 0, 13, 13, 13, 14, 14, 19, 16, 11, 13, 0, 11, 14, 13, 12, 61, 12, 13, 18, 14, 0, 13, 20, 15, 32, 25, 11, 15, 18, 17, 0, 13, 13, 16, 22, 36, 14, 9, 20, 12, 0, 16, 19, 11, 27, 18, 20, 14, 20, 18, 0, 14, 60, 12, 13, 26, 13, 15, 18, 15, 0, 13, 19, 14, 17, 20, 20, 14, 13, 18, 0, 13, 14, 15, 19, 27, 15, 16, 17, 17, 0, 15, 17, 15, 14, 36, 12, 15, 19, 19, 0, 15, 11, 13, 12, 26, 8, 13, 18, 7, 0, 12, 11, 9, 19, 21, 15, 12, 21, 13, 0, 15, 17, 16, 17, 28, 15, 17, 17, 12, 0, 8, 18, 12, 17, 14, 8, 18, 19, 13, 0, 14, 14, 14, 11, 23, 17, 15, 13, 14, 0, 11, 16, 15, 12, 20, 20, 11, 16, 13, 0, 15, 17, 17, 20, 30, 15, 15, 11, 13, 0, 19, 9, 14, 16, 29, 16, 15, 13, 16, 0, 16, 25, 14, 20, 20, 13, 19, 14, 9, 0, 12, 13, 20, 16, 25, 19, 12, 15, 12, 0, 12, 13, 11, 20, 34, 16, 13, 18, 9, 0, 13, 18, 15, 19, 23, 14, 17, 18, 16, 0, 15, 13, 10, 19, 27, 15, 12, 20, 13, 0, 16, 13, 13, 19, 15, 19, 11, 14, 10, 0, 14, 20, 10, 8, 33, 23, 21, 17, 13, 0, 10, 19, 18, 12, 27, 13, 18, 11, 17, 0, 16, 16, 14, 20, 12, 11, 13, 13, 14, 0, 14, 7, 15, 15, 14, 20, 9, 14, 15, 0, 12, 13, 14, 17, 24, 6, 8, 17, 13, 0, 16, 14, 11, 17, 32, 19, 15, 14, 11, 0, 14, 9, 9, 18, 52, 14, 11, 21, 15, 0, 10, 16, 18, 15, 29, 14, 11, 15, 13, 0, 14, 17, 13, 11, 27, 15, 16, 13, 9, 0, 15, 19, 10, 16, 22, 17, 12, 15, 14, 0, 17, 25, 15, 17, 20, 20, 17, 17, 16, 0, 12, 14, 13, 19, 21, 16, 16, 13, 17, 0, 14, 18, 15, 21, 15, 17, 11, 14, 13, 0, 14, 19, 13, 15, 18, 16, 14, 15, 14, 0, 5, 11, 8, 9, 30, 10, 15, 16, 13, 0, 14, 11, 11, 14, 53, 17, 13, 13, 10, 0, 18, 15, 7, 18, 24, 21, 17, 9, 13, 0, 14, 13, 14, 14, 24, 16, 17, 20, 7, 0, 16, 19, 13, 17, 33, 14, 8, 14, 14, 0, 14, 16, 9, 14, 22, 29, 11, 10, 7, 0, 13, 19, 13, 13, 37, 14, 18, 12, 16, 0, 11, 13, 16, 13, 23, 21, 15, 13, 17, 0, 19, 11, 9, 17, 32, 17, 12, 9, 8, 0, 11, 14, 13, 17, 50, 18, 9, 12, 8, 0, 13, 18, 10, 13, 29, 15, 17, 15, 14, 0, 7, 16, 16, 14, 35, 22, 15, 12, 13, 0, 15, 19, 16, 20, 25, 14, 16, 21, 12, 0, 14, 16, 12, 13, 111, 19, 11, 17, 9, 0, 11, 15, 9, 18, 18, 21, 12, 11, 8, 0, 13, 21, 17, 14, 45, 13, 9, 14, 17, 0, 10, 17, 13, 14, 20, 14, 15, 14, 16, 0, 12, 16, 10, 13, 29, 14, 16, 7, 11, 0, 11, 13, 10, 23, 29, 17, 15, 12, 14, 0, 14, 19, 15, 14, 18, 23, 15, 16, 14, 0, 17, 21, 14, 17, 23, 17, 18, 12, 13, 0, 8, 21, 12, 19, 23, 17, 14, 13, 13, 0, 9, 17, 13, 16, 23, 18, 16, 12, 10, 0, 14, 12, 13, 14, 11, 13, 18, 12, 17, 0, 8, 10, 8, 20, 29, 19, 16, 19, 16, 0, 16, 13, 13, 13, 19, 22, 9, 12, 16, 0, 8, 16, 13, 20, 34, 14, 19, 17, 9, 0, 14, 21, 18, 12, 29, 14, 13, 17, 10, 0, 14, 21, 17, 18, 23, 15, 9, 12, 12, 0, 14, 22, 16, 15, 20, 17, 13, 16, 11, 0, 11, 15, 12, 15, 30, 11, 17, 13, 11, 0, 13, 16, 13, 19, 15, 19, 13, 17, 11, 0, 16, 12, 13, 24, 23, 14, 10, 18, 13, 0, 16, 22, 13, 9, 22, 14, 14, 11, 12, 0, 19, 16, 17, 14, 32, 20, 6, 6, 6, 0, 11, 16, 13, 17, 23, 11, 7, 6, 6, 0, 16, 14, 13, 16, 33, 17, 9, 12, 6, 0, 11, 17, 16, 18, 32, 20, 14, 22, 14, 0, 15, 13, 16, 15, 41, 13, 14, 17, 11, 0, 13, 17, 13, 14, 22, 15, 11, 13, 16, 0, 11, 14, 14, 16, 22, 17, 13, 14, 16, 0, 12, 17, 17, 14, 24, 21, 18, 16, 14, 0, 16, 14, 9, 14, 28, 19, 14, 14, 15, 0, 12, 19, 11, 13, 19, 22, 16, 18, 11, 0, 8, 28, 13, 17, 32, 19, 11, 20, 13, 0, 11, 13, 14, 10, 30, 23, 14, 6, 6, 0, 12, 15, 15, 16, 22, 14, 18, 19, 6, 0, 16, 13, 14, 21, 33, 19, 12, 13, 12, 0, 13, 14, 11, 18, 22, 16, 13, 21, 17, 0, 14, 13, 12, 13, 33, 14, 12, 12, 10, 0, 10, 20, 14, 22, 17, 21, 19, 17, 15, 0, 15, 16, 12, 15, 29, 12, 16, 14, 17, 0, 14, 19, 13, 14, 27, 18, 13, 9, 15, 0, 7, 16, 7, 13, 14, 18, 12, 25, 11, 0, 10, 13, 14, 19, 29, 15, 14, 12, 15, 0, 12, 7, 7, 22, 21, 17, 18, 18, 19, 0, 16, 13, 13, 16, 32, 19, 9, 19, 6, 0, 18, 16, 13, 12, 30, 22, 18, 15, 15, 0, 13, 19, 11, 19, 26, 15, 13, 21, 13, 0, 8, 12, 14, 11, 27, 21, 11, 14, 8, 0, 10, 11, 14, 9, 21, 18, 17, 16, 11, 0, 13, 19, 13, 20, 36, 20, 13, 22, 13, 0, 18, 19, 13, 18, 36, 22, 13, 13, 13, 0, 16, 13, 13, 16, 23, 14, 9, 19, 14, 0, 9, 11, 11, 9, 27, 12, 12, 22, 15, 0, 12, 9, 11, 19, 25, 11, 14, 16, 13, 0, 12, 19, 17, 8, 37, 26, 14, 20, 14, 0, 14, 21, 14, 17, 17, 17, 12, 15, 15, 0, 17, 17, 8, 18, 21, 14, 14, 12, 9, 0, 11, 19, 8, 10, 13, 14, 10, 26, 12, 0, 13, 13, 15, 13, 30, 15, 13, 13, 8, 0, 17, 16, 13, 18, 27, 19, 12, 18, 13, 0, 12, 14, 11, 14, 25, 12, 16, 18, 14, 0, 12, 19, 11, 15, 28, 16, 8, 27, 14, 0, 11, 9, 14, 17, 25, 19, 13, 14, 13, 0, 13, 14, 15, 15, 61, 19, 14, 14, 10, 0, 13, 15, 13, 20, 23, 12, 11, 14, 11, 0, 13, 16, 14, 19, 25, 14, 10, 20, 14, 0, 13, 14, 16, 23, 29, 21, 9, 19, 9, 0, 17, 16, 13, 13, 23, 19, 18, 14, 12, 0, 14, 17, 20, 18, 19, 17, 12, 17, 11, 0, 10, 21, 12, 18, 52, 16, 13, 14, 11, 0, 14, 17, 13, 19, 26, 19, 9, 20, 11, 0, 18, 14, 16, 17, 28, 25, 6, 16, 19, 0, 18, 25, 19, 20, 23, 15, 11, 14, 14, 0, 9, 19, 11, 13, 21, 21, 13, 15, 16, 0, 13, 19, 17, 18, 23, 22, 16, 19, 9, 0, 15, 13, 16, 15, 21, 17, 14, 23, 13, 0, 18, 19, 16, 20, 32, 13, 15, 15, 8, 0, 11, 18, 12, 17, 30, 17, 11, 18, 10, 0, 15, 22, 14, 15, 23, 17, 11, 19, 14, 0, 14, 20, 14, 8, 35, 14, 13, 14, 16, 0, 13, 21, 13, 15, 34, 18, 13, 12, 13, 0, 16, 14, 15, 19, 23, 18, 14, 14, 16, 0, 11, 19, 11, 22, 25, 19, 13, 21, 11, 0, 14, 11, 15, 19, 24, 22, 18, 18, 16, 0, 16, 17, 10, 18, 37, 8, 14, 16, 10, 0, 13, 20, 9, 14, 30, 23, 13, 15, 11, 0, 12, 14, 14, 22, 20, 19, 19, 9, 14, 0, 10, 21, 16, 11, 26, 15, 13, 14, 16, 0, 5, 13, 16, 19, 35, 19, 13, 17, 16, 0, 14, 17, 13, 18, 33, 15, 18, 23, 13, 0, 15, 18, 9, 12, 24, 13, 12, 14, 12, 0, 14, 14, 11, 22, 23, 15, 20, 19, 12, 0, 13, 18, 12, 13, 19, 13, 7, 11, 7, 0, 15, 16, 9, 15, 21, 15, 9, 14, 14, 0, 13, 19, 13, 14, 35, 13, 16, 18, 16, 0, 10, 18, 6, 12, 32, 14, 17, 15, 13, 0, 17, 29, 10, 18, 24, 16, 14, 15, 16, 0, 13, 14, 13, 14, 26, 13, 10, 15, 14, 0, 12, 14, 14, 19, 23, 14, 17, 13, 11, 0, 12, 19, 6, 25, 38, 9, 15, 14, 8, 0, 11, 16, 16, 19, 38, 18, 14, 20, 13, 0, 7, 15, 14, 17, 24, 22, 14, 10, 14, 0, 17, 18, 8, 19, 45, 14, 8, 17, 17, 0, 15, 20, 15, 12, 15, 20, 16, 19, 14, 0, 13, 22, 13, 14, 20, 13, 10, 18, 7, 0, 12, 14, 14, 21, 18, 13, 13, 13, 12, 0, 20, 17, 13, 19, 29, 15, 13, 20, 14, 0, 16, 14, 14, 18, 26, 18, 14, 14, 15, 0, 15, 19, 10, 22, 23, 19, 15, 22, 9, 0, 17, 19, 14, 13, 34, 14, 20, 17, 20, 0, 16, 18, 10, 21, 25, 22, 12, 20, 17, 0, 11, 22, 13, 11, 21, 17, 15, 15, 17, 0, 18, 22, 14, 14, 25, 16, 17, 13, 14, 0, 19, 19, 13, 20, 32, 16, 16, 14, 16, 0, 17, 7, 17, 22, 81, 13, 8, 16, 12, 0, 14, 10, 15, 21, 21, 16, 14, 17, 11, 0, 16, 15, 12, 21, 20, 14, 15, 19, 13, 0, 15, 13, 11, 9, 29, 17, 13, 16, 13, 0, 8, 14, 15, 15, 29, 23, 13, 17, 15, 0, 17, 18, 13, 18, 33, 14, 13, 13, 11, 0, 15, 19, 11, 18, 29, 19, 15, 18, 14, 0, 11, 12, 14, 21, 18, 19, 13, 13, 13, 0, 13, 15, 12, 17, 21, 8, 11, 14, 16, 0, 14, 20, 12, 20, 33, 10, 17, 15, 14, 0, 13, 17, 13, 16, 42, 18, 16, 14, 14, 0, 16, 20, 18, 17, 19, 14, 10, 13, 13, 0, 15, 18, 15, 20, 26, 11, 16, 14, 15, 0, 13, 19, 14, 13, 25, 14, 14, 16, 13, 0, 12, 21, 7, 23, 24, 14, 12, 21, 14, 0, 13, 13, 16, 14, 38, 17, 16, 17, 13, 0, 12, 17, 15, 14, 29, 15, 13, 17, 14, 0, 11, 16, 13, 25, 15, 19, 14, 16, 14, 0, 15, 14, 13, 20, 24, 17, 17, 17, 15, 0, 13, 20, 12, 15, 32, 18, 11, 6, 6, 0, 13, 15, 14, 13, 21, 28, 11, 20, 6, 0, 13, 20, 14, 18, 34, 17, 10, 21, 13, 0, 13, 13, 13, 17, 26, 14, 14, 16, 10, 0, 9, 21, 13, 14, 38, 20, 10, 25, 17, 0, 11, 17, 16, 14, 21, 18, 13, 14, 12, 0, 13, 20, 15, 22, 33, 17, 8, 8, 15, 0, 12, 14, 13, 16, 23, 17, 13, 16, 12, 0, 14, 13, 12, 12, 13, 20, 11, 16, 11, 0, 13, 24, 16, 17, 21, 20, 16, 14, 14, 0, 8, 18, 13, 14, 22, 22, 14, 13, 12, 0, 11, 22, 12, 14, 26, 14, 14, 22, 6, 0, 8, 18, 19, 14, 24, 19, 14, 16, 17, 0, 16, 12, 14, 15, 34, 14, 15, 21, 13, 0, 16, 19, 12, 18, 29, 18, 16, 17, 13, 0, 13, 13, 14, 21, 10, 15, 14, 20, 15, 0, 13, 22, 14, 14, 33, 14, 11, 12, 12, 0, 15, 14, 12, 17, 15, 9, 14, 7, 7, 0, 12, 13, 14, 13, 36, 23, 16, 19, 10, 0, 15, 18, 8, 13, 15, 20, 16, 16, 14, 0, 18, 19, 10, 10, 24, 10, 14, 29, 15, 0, 9, 14, 16, 17, 35, 13, 21, 21, 13, 0, 18, 21, 13, 16, 24, 20, 16, 11, 13, 0, 14, 17, 16, 13, 29, 19, 13, 15, 11, 0, 18, 14, 15, 15, 32, 16, 16, 8, 10, 0, 10, 15, 14, 19, 27, 19, 13, 9, 10, 0, 17, 13, 15, 16, 29, 17, 8, 11, 10, 0, 13, 12, 17, 21, 16, 19, 13, 18, 7, 0, 11, 17, 9, 13, 20, 9, 17, 14, 13, 0, 14, 17, 15, 19, 34, 19, 12, 14, 11, 0, 8, 12, 16, 19, 28, 12, 14, 13, 15, 0, 12, 14, 14, 20, 20, 21, 12, 21, 11, 0, 13, 19, 15, 13, 29, 15, 11, 15, 14, 0, 14, 14, 16, 13, 24, 24, 9, 17, 13, 0, 14, 21, 14, 16, 16, 13, 11, 11, 17, 0, 15, 13, 16, 10, 34, 14, 15, 14, 17, 0, 13, 21, 13, 9, 16, 18, 19, 26, 14, 0, 11, 30, 13, 13, 30, 15, 14, 19, 13, 0, 9, 18, 15, 19, 26, 18, 12, 13, 14, 0, 14, 15, 16, 19, 31, 16, 14, 21, 10, 0, 11, 17, 19, 15, 14, 21, 16, 10, 16, 0, 9, 15, 15, 14, 204, 18, 15, 14, 17, 0, 13, 12, 14, 14, 27, 18, 9, 17, 14, 0, 13, 19, 14, 17, 34, 14, 15, 23, 14, 0, 19, 20, 16, 16, 29, 17, 13, 22, 18, 0, 12, 17, 14, 19, 32, 13, 13, 18, 17, 0, 9, 15, 8, 20, 90, 15, 13, 20, 13, 0, 10, 15, 16, 23, 29, 14, 16, 20, 14, 0, 18, 13, 15, 11, 21, 16, 13, 8, 9, 0, 14, 17, 13, 18, 19, 22, 13, 19, 13, 0, 13, 19, 15, 13, 21, 21, 14, 13, 9, 0, 8, 19, 19, 21, 25, 15, 17, 18, 16, 0, 17, 18, 13, 8, 20, 11, 16, 15, 14, 0, 12, 14, 13, 10, 23, 18, 17, 16, 14, 0, 13, 18, 15, 19, 30, 23, 10, 12, 16, 0, 5, 10, 15, 19, 30, 13, 9, 10, 14, 0, 9, 19, 17, 14, 23, 16, 16, 21, 13, 0, 15, 14, 14, 13, 23, 18, 14, 13, 14, 0, 14, 16, 16, 12, 26, 14, 11, 13, 14, 0, 15, 25, 14, 20, 21, 9, 12, 14, 8, 0, 13, 20, 9, 14, 24, 12, 11, 17, 17, 0, 12, 15, 17, 19, 35, 14, 12, 21, 12, 0, 11, 13, 14, 28, 29, 14, 14, 17, 10, 0, 14, 16, 17, 17, 20, 16, 13, 19, 17, 0, 11, 13, 15, 14, 28, 18, 13, 13, 9, 0, 13, 14, 14, 23, 23, 19, 13, 20, 11, 0, 15, 19, 13, 17, 30, 14, 20, 17, 14, 0, 18, 15, 11, 19, 24, 14, 14, 22, 13, 0, 18, 9, 10, 12, 28, 18, 16, 19, 16, 0, 13, 21, 7, 14, 24, 14, 14, 16, 12, 0, 16, 14, 13, 22, 15, 17, 10, 14, 13, 0, 17, 14, 16, 17, 21, 11, 14, 18, 16, 0, 9, 17, 16, 15, 24, 13, 17, 14, 16, 0, 14, 15, 15, 19, 25, 11, 14, 7, 19, 0, 8, 17, 14, 17, 21, 18, 13, 14, 12, 0, 14, 14, 10, 19, 25, 17, 14, 13, 13, 0, 12, 16, 18, 17, 31, 13, 14, 21, 15, 0, 14, 17, 13, 16, 29, 14, 13, 11, 12, 0, 9, 18, 11, 30, 38, 15, 16, 11, 15, 0, 12, 14, 13, 14, 32, 14, 14, 20, 14, 0, 17, 20, 9, 16, 26, 16, 16, 15, 18, 0, 13, 13, 10, 12, 12, 23, 14, 17, 14, 0, 13, 17, 14, 18, 24, 9, 17, 19, 13, 0, 18, 15, 12, 19, 26, 13, 11, 21, 16, 0, 13, 23, 11, 17, 13, 15, 14, 25, 16, 0, 17, 19, 9, 13, 30, 13, 14, 22, 11, 0, 16, 13, 13, 18, 30, 8, 14, 13, 14, 0, 12, 13, 11, 14, 33, 19, 14, 18, 19, 0, 16, 20, 12, 18, 25, 18, 11, 16, 8, 0, 10, 13, 19, 13, 29, 25, 18, 21, 19, 0, 14, 12, 6, 13, 27, 16, 14, 19, 18, 0, 14, 10, 17, 27, 33, 14, 14, 15, 11, 0, 11, 19, 14, 18, 23, 21, 11, 22, 14, 0, 14, 16, 17, 17, 27, 16, 13, 8, 14, 0, 16, 17, 14, 21, 28, 21, 16, 8, 9, 0, 14, 17, 15, 16, 29, 9, 15, 15, 13, 0, 10, 19, 15, 13, 23, 19, 13, 17, 16, 0, 14, 12, 12, 19, 21, 15, 13, 19, 15, 0, 12, 13, 14, 15, 26, 14, 15, 17, 14, 0, 13, 17, 12, 20, 25, 5, 17, 14, 19, 0, 13, 17, 13, 10, 30, 18, 19, 14, 13, 0, 18, 13, 11, 14, 34, 17, 16, 22, 11, 0, 17, 19, 12, 9, 25, 19, 13, 17, 17, 0, 14, 10, 11, 15, 24, 14, 12, 11, 13, 0, 11, 22, 11, 17, 29, 21, 8, 9, 15, 0, 16, 14, 9, 22, 19, 20, 18, 17, 13, 0, 11, 19, 13, 16, 84, 18, 20, 13, 7, 0, 12, 22, 19, 12, 26, 20, 18, 19, 13, 0, 14, 18, 9, 17, 20, 19, 12, 19, 11, 0, 13, 19, 15, 16, 24, 16, 12, 21, 13, 0, 8, 17, 15, 20, 34, 12, 9, 20, 12, 0, 16, 14, 18, 14, 26, 21, 13, 14, 6, 0, 13, 16, 13, 13, 27, 21, 13, 12, 7, 0, 13, 16, 10, 20, 20, 11, 10, 14, 11, 0, 11, 15, 15, 13, 33, 24, 8, 21, 16, 0, 16, 16, 20, 21, 38, 10, 12, 14, 17, 0, 12, 13, 16, 16, 37, 19, 11, 20, 16, 0, 12, 16, 13, 14, 19, 11, 17, 19, 16, 0, 13, 12, 14, 22, 52, 14, 13, 16, 13, 0, 15, 12, 11, 20, 40, 16, 14, 14, 18, 0, 13, 23, 14, 17, 29, 19, 14, 10, 13, 0, 13, 14, 14, 16, 36, 22, 15, 17, 13, 0, 8, 20, 11, 11, 30, 19, 16, 17, 18, 0, 14, 22, 16, 15, 20, 21, 17, 12, 13, 0, 17, 17, 13, 18, 14, 19, 16, 14, 16, 0, 13, 13, 13, 19, 21, 16, 19, 14, 17, 0, 13, 19, 15, 11, 34, 19, 11, 16, 14, 0, 15, 16, 14, 20, 19, 17, 15, 19, 14, 0, 8, 17, 13, 15, 23, 16, 7, 14, 14, 0, 15, 11, 20, 17, 27, 27, 14, 14, 11, 0, 12, 23, 8, 9, 29, 19, 12, 18, 14, 0, 8, 13, 6, 20, 21, 12, 7, 12, 10, 0, 12, 13, 14, 22, 25, 16, 7, 18, 11, 0, 16, 13, 13, 18, 22, 13, 12, 16, 17, 0, 15, 13, 14, 12, 28, 14, 15, 14, 13, 0, 19, 13, 9, 13, 14, 18, 7, 19, 10, 0, 17, 19, 17, 15, 38, 6, 15, 8, 13, 0, 13, 13, 18, 19, 50, 8, 18, 14, 14, 0, 9, 13, 15, 16, 23, 13, 14, 20, 8, 0, 14, 26, 16, 21, 26, 14, 9, 23, 14, 0, 16, 19, 17, 16, 21, 16, 8, 12, 15, 0, 12, 17, 12, 22, 37, 13, 13, 13, 13, 0, 16, 18, 13, 21, 14, 15, 10, 16, 9, 0, 15, 20, 13, 17, 18, 17, 17, 16, 14, 0, 10, 14, 18, 13, 21, 21, 12, 15, 16, 0, 16, 11, 16, 19, 32, 36, 13, 19, 11, 0, 11, 15, 8, 16, 26, 12, 15, 13, 13, 0, 8, 25, 12, 9, 23, 18, 13, 19, 14, 0, 9, 12, 14, 18, 21, 14, 15, 19, 12, 0, 15, 18, 15, 8, 29, 14, 13, 9, 15, 0, 17, 16, 13, 14, 30, 18, 13, 14, 16, 0, 18, 14, 14, 16, 14, 11, 7, 21, 13, 0, 9, 22, 16, 16, 61, 21, 14, 13, 19, 0, 19, 12, 9, 15, 22, 21, 16, 20, 18, 0, 11, 16, 19, 14, 23, 14, 18, 15, 14, 0, 15, 13, 14, 18, 26, 11, 16, 19, 10, 0, 13, 19, 16, 19, 32, 18, 13, 22, 14, 0, 14, 18, 12, 19, 26, 13, 12, 17, 16, 0, 14, 14, 18, 27, 21, 16, 16, 19, 14, 0, 13, 19, 11, 20, 27, 11, 12, 18, 12, 0, 14, 17, 13, 15, 24, 22, 14, 17, 7, 0, 16, 21, 9, 12, 35, 21, 20, 23, 11, 0, 14, 18, 15, 14, 34, 19, 19, 12, 18, 0, 12, 18, 11, 19, 23, 13, 16, 8, 17, 0, 15, 19, 13, 20, 23, 20, 12, 13, 11, 0, 11, 16, 11, 20, 34, 18, 13, 21, 13, 0, 15, 11, 13, 16, 34, 20, 12, 17, 12, 0, 17, 13, 15, 14, 28, 15, 19, 15, 15, 0, 12, 9, 13, 20, 28, 21, 9, 12, 12, 0, 15, 20, 14, 21, 17, 8, 16, 22, 17, 0, 14, 14, 17, 9, 21, 19, 15, 18, 15, 0, 14, 23, 16, 19, 26, 14, 11, 19, 17, 0, 16, 18, 16, 19, 30, 14, 16, 11, 14, 0, 12, 13, 15, 19, 26, 15, 9, 22, 13, 0, 13, 20, 13, 13, 26, 15, 13, 15, 11, 0, 9, 13, 17, 16, 28, 22, 8, 19, 11, 0, 16, 19, 13, 13, 54, 21, 14, 17, 19, 0, 12, 18, 13, 13, 19, 19, 14, 15, 15, 0, 7, 19, 13, 19, 25, 19, 11, 12, 14, 0, 17, 21, 16, 15, 16, 20, 9, 17, 13, 0, 12, 15, 14, 19, 10, 16, 14, 19, 16, 0, 13, 16, 17, 18, 23, 19, 13, 19, 15, 0, 14, 16, 13, 19, 26, 18, 11, 21, 6, 0, 14, 16, 14, 19, 26, 12, 14, 21, 14, 0, 16, 12, 19, 13, 19, 11, 14, 16, 17, 0, 11, 9, 19, 17, 21, 9, 13, 17, 12, 0, 15, 18, 13, 21, 27, 19, 18, 15, 13, 0, 9, 11, 13, 17, 24, 13, 17, 20, 16, 0, 16, 13, 19, 13, 26, 19, 15, 23, 8, 0, 13, 20, 10, 13, 94, 7, 13, 13, 15, 0, 13, 12, 15, 11, 25, 19, 10, 19, 14, 0, 11, 11, 16, 20, 32, 19, 15, 13, 15, 0, 14, 19, 12, 14, 27, 18, 14, 14, 13, 0, 15, 16, 9, 21, 26, 13, 19, 12, 13, 0, 17, 12, 12, 19, 22, 22, 12, 19, 12, 0, 16, 19, 12, 6, 25, 17, 8, 15, 11, 0, 16, 14, 14, 16, 33, 19, 13, 13, 13, 0, 11, 13, 10, 7, 21, 18, 11, 20, 17, 0, 13, 20, 13, 19, 30, 14, 18, 16, 15, 0, 13, 16, 17, 19, 18, 16, 14, 26, 11, 0, 15, 13, 10, 18, 21, 16, 12, 13, 17, 0, 14, 12, 16, 19, 19, 17, 14, 16, 13, 0, 15, 17, 13, 8, 25, 15, 15, 18, 15, 0, 16, 13, 15, 15, 29, 17, 11, 18, 14, 0, 15, 17, 11, 21, 20, 19, 11, 19, 13, 0, 15, 9, 14, 16, 20, 19, 16, 18, 16, 0, 14, 14, 12, 30, 26, 18, 17, 18, 14, 0, 13, 15, 19, 22, 24, 11, 13, 19, 10, 0, 16, 19, 10, 16, 25, 22, 17, 18, 13, 0, 16, 15, 13, 16, 21, 24, 14, 22, 12, 0, 14, 15, 13, 19, 13, 22, 14, 13, 13, 0, 18, 12, 14, 15, 36, 15, 12, 18, 17, 0, 13, 8, 13, 20, 12, 19, 16, 24, 14, 0, 16, 14, 18, 21, 29, 17, 13, 17, 17, 0, 18, 18, 20, 20, 26, 23, 9, 9, 9, 0, 18, 13, 15, 19, 33, 11, 13, 16, 18, 0, 13, 17, 7, 19, 20, 13, 17, 13, 14, 0, 16, 17, 14, 21, 23, 17, 12, 20, 13, 0, 12, 16, 16, 15, 24, 21, 15, 9, 19, 0, 11, 21, 16, 17, 28, 18, 10, 20, 11, 0, 12, 13, 13, 19, 32, 14, 15, 20, 18, 0, 16, 19, 19, 16, 38, 9, 16, 18, 8, 0, 11, 19, 10, 22, 32, 17, 15, 19, 16, 0, 9, 13, 13, 11, 22, 14, 16, 21, 13, 0, 14, 15, 17, 12, 32, 17, 15, 11, 14, 0, 13, 16, 13, 18, 22, 22, 17, 18, 9, 0, 12, 19, 13, 13, 53, 18, 16, 14, 17, 0, 15, 9, 13, 17, 29, 11, 19, 14, 17, 0, 15, 18, 9, 14, 35, 19, 12, 27, 17, 0, 10, 6, 13, 20, 26, 14, 13, 18, 16, 0, 14, 14, 11, 23, 29, 10, 19, 18, 14, 0, 14, 17, 13, 13, 33, 21, 18, 18, 14, 0, 12, 16, 12, 15, 30, 19, 14, 11, 17, 0, 8, 20, 17, 17, 34, 25, 16, 19, 17, 0, 14, 21, 8, 15, 24, 19, 11, 13, 15, 0, 10, 18, 8, 18, 16, 11, 15, 21, 14, 0, 12, 17, 9, 18, 35, 21, 13, 14, 18, 0, 16, 18, 13, 17, 26, 12, 13, 16, 13, 0, 14, 20, 15, 22, 33, 20, 13, 20, 14, 0, 12, 17, 12, 17, 29, 19, 14, 11, 18, 0, 12, 16, 14, 21, 25, 13, 14, 14, 14, 0, 12, 14, 21, 19, 33, 8, 10, 14, 13, 0, 12, 20, 16, 15, 27, 25, 19, 17, 13, 0, 21, 13, 8, 14, 27, 18, 17, 12, 13, 0, 11, 20, 13, 18, 32, 19, 11, 19, 13, 0, 14, 14, 12, 17, 23, 16, 19, 22, 14, 0, 14, 12, 10, 19, 33, 19, 13, 20, 16, 0, 8, 13, 16, 23, 26, 14, 5, 16, 9, 0, 16, 21, 16, 16, 29, 12, 12, 13, 15, 0, 18, 13, 17, 14, 22, 20, 13, 16, 16, 0, 11, 14, 13, 11, 30, 22, 18, 14, 9, 0, 12, 14, 14, 14, 35, 19, 17, 17, 16, 0, 20, 21, 8, 8, 32, 14, 13, 12, 13, 0, 12, 19, 14, 17, 31, 12, 14, 18, 15, 0, 7, 21, 13, 22, 32, 16, 13, 21, 11, 0, 16, 17, 18, 13, 32, 19, 13, 16, 12, 0, 17, 17, 13, 15, 23, 13, 14, 13, 14, 0, 14, 17, 17, 21, 21, 28, 18, 10, 17, 0, 11, 19, 15, 14, 27, 14, 8, 18, 16, 0, 10, 14, 13, 19, 23, 19, 14, 19, 15, 0, 12, 14, 14, 12, 23, 18, 13, 8, 8, 0, 11, 15, 13, 15, 34, 18, 15, 17, 8, 0, 12, 23, 19, 16, 27, 20, 15, 14, 11, 0, 10, 14, 10, 23, 109, 14, 9, 13, 14, 0, 13, 17, 12, 14, 26, 9, 13, 9, 11, 0, 14, 18, 17, 19, 26, 21, 14, 13, 15, 0, 14, 17, 14, 12, 45, 17, 17, 18, 15, 0, 17, 19, 13, 13, 26, 17, 13, 14, 9, 0, 12, 22, 13, 16, 25, 19, 12, 22, 17, 0, 10, 14, 15, 15, 24, 16, 13, 13, 16, 0, 12, 19, 14, 19, 24, 16, 11, 13, 14, 0, 7, 15, 10, 17, 35, 12, 15, 18, 13, 0, 15, 19, 15, 19, 18, 19, 15, 13, 18, 0, 14, 18, 16, 17, 36, 24, 14, 14, 19, 0, 13, 12, 8, 13, 23, 13, 16, 20, 14, 0, 13, 15, 11, 19, 27, 17, 13, 21, 17, 0, 15, 20, 11, 16, 35, 11, 16, 24, 14, 0, 9, 16, 13, 18, 32, 18, 10, 19, 18, 0, 15, 21, 14, 12, 24, 8, 14, 14, 17, 0, 14, 13, 15, 17, 29, 11, 14, 20, 12, 0, 14, 21, 11, 20, 30, 16, 17, 17, 19, 0, 7, 17, 13, 18, 29, 22, 15, 21, 17, 0, 12, 19, 10, 8, 28, 19, 13, 19, 13, 0, 14, 30, 13, 19, 22, 13, 16, 21, 14, 0, 14, 22, 13, 17, 29, 20, 14, 20, 14, 0, 14, 13, 19, 14, 21, 11, 12, 14, 14, 0, 11, 21, 13, 20, 33, 17, 14, 20, 12, 0, 14, 14, 14, 22, 23, 15, 20, 15, 11, 0, 13, 14, 7, 8, 36, 21, 18, 18, 19, 0, 14, 19, 14, 22, 25, 13, 13, 20, 12, 0, 11, 22, 8, 16, 29, 18, 12, 20, 14, 0, 16, 13, 14, 17, 19, 13, 14, 14, 15, 0, 16, 13, 15, 13, 13, 20, 15, 28, 15, 0, 19, 19, 17, 20, 30, 14, 10, 17, 17, 0, 15, 22, 8, 13, 24, 14, 15, 17, 14, 0, 12, 18, 13, 16, 23, 10, 12, 19, 9, 0, 8, 14, 14, 21, 32, 15, 14, 8, 12, 0, 12, 12, 12, 12, 10, 13, 13, 25, 10, 0, 16, 22, 16, 12, 26, 18, 10, 7, 13, 0, 15, 30, 14, 12, 34, 14, 12, 21, 8, 0, 18, 21, 13, 15, 38, 20, 10, 20, 19, 0, 8, 12, 12, 21, 31, 14, 12, 20, 11, 0, 14, 15, 14, 14, 29, 14, 18, 8, 17, 0, 13, 15, 9, 19, 26, 19, 15, 21, 11, 0, 15, 17, 13, 13, 27, 17, 17, 15, 18, 0, 13, 13, 11, 16, 16, 15, 17, 17, 14, 0, 13, 19, 14, 11, 17, 24, 18, 18, 18, 0, 11, 14, 13, 19, 32, 16, 12, 13, 6, 0, 8, 32, 16, 14, 19, 21, 13, 13, 16, 0, 9, 21, 10, 13, 17, 16, 14, 17, 10, 0, 13, 20, 11, 16, 21, 15, 13, 17, 12, 0, 15, 17, 17, 16, 53, 15, 13, 11, 13, 0, 14, 18, 13, 13, 29, 19, 13, 16, 14, 0, 16, 16, 13, 20, 13, 22, 13, 13, 11, 0, 16, 20, 14, 17, 23, 11, 11, 11, 17, 0, 8, 22, 13, 17, 25, 15, 11, 16, 16, 0, 8, 19, 13, 20, 35, 11, 16, 22, 13, 0, 11, 17, 13, 19, 21, 15, 16, 13, 12, 0, 19, 17, 18, 16, 27, 17, 14, 17, 15, 0, 15, 18, 8, 18, 41, 20, 9, 13, 13, 0, 13, 23, 14, 19, 21, 20, 12, 13, 15, 0, 13, 13, 10, 13, 705, 14, 16, 6, 6, 0, 6, 18, 6, 18, 22, 14, 12, 6, 10, 0, 15, 22, 13, 17, 29, 16, 11, 17, 11, 0, 13, 20, 6, 6, 30, 16, 11, 12, 13, 0, 15, 15, 13, 13, 23, 8, 11, 21, 12, 0, 13, 20, 15, 19, 35, 19, 9, 6, 18, 0, 16, 7, 14, 21, 26, 9, 14, 19, 12, 0, 8, 21, 13, 20, 25, 13, 10, 18, 19, 0, 12, 13, 6, 18, 21, 16, 18, 15, 18, 0, 9, 20, 18, 14, 20, 12, 16, 15, 16, 0, 13, 16, 20, 16, 25, 14, 13, 6, 16, 0, 17, 13, 14, 20, 28, 14, 18, 13, 17, 0, 14, 13, 15, 95, 34, 7, 16, 17, 12, 0, 16, 14, 6, 27, 24, 15, 13, 17, 13, 0, 15, 17, 17, 13, 26, 17, 17, 15, 16, 0, 18, 17, 18, 14, 16, 12, 20, 13, 10, 0, 10, 17, 13, 19, 38, 22, 9, 25, 11, 0, 11, 22, 12, 19, 29, 19, 17, 13, 16, 0, 13, 19, 14, 14, 25, 20, 10, 13, 13, 0, 19, 19, 13, 18, 21, 12, 13, 27, 15, 0, 14, 22, 14, 14, 34, 13, 13, 17, 8, 0, 19, 21, 17, 14, 26, 11, 13, 16, 15, 0, 11, 17, 8, 17, 36, 14, 16, 17, 15, 0, 9, 14, 16, 12, 15, 19, 10, 14, 13, 0, 17, 14, 8, 25, 20, 20, 13, 12, 12, 0, 15, 15, 14, 17, 15, 21, 11, 6, 6, 0, 18, 18, 14, 19, 21, 13, 11, 18, 15, 0, 11, 18, 15, 20, 31, 19, 13, 18, 15, 0, 7, 17, 6, 22, 28, 14, 14, 18, 16, 0, 7, 21, 11, 16, 29, 19, 10, 9, 17, 0, 13, 15, 16, 11, 26, 14, 18, 13, 10, 0, 14, 23, 13, 20, 32, 18, 17, 19, 19, 0, 9, 19, 9, 18, 26, 22, 16, 22, 13, 0, 16, 15, 11, 15, 18, 21, 13, 14, 15, 0, 10, 8, 13, 20, 23, 14, 17, 17, 12, 0, 18, 22, 15, 17, 142, 18, 9, 23, 13, 0, 14, 15, 14, 11, 23, 14, 9, 20, 17, 0, 11, 17, 14, 13, 30, 14, 13, 19, 14, 0, 14, 9, 14, 20, 13, 16, 15, 19, 15, 0, 12, 20, 16, 16, 28, 21, 12, 11, 9, 0, 14, 14, 16, 16, 33, 17, 7, 24, 12, 0, 18, 12, 9, 23, 17, 17, 17, 20, 15, 0, 7, 27, 12, 18, 22, 14, 13, 15, 15, 0, 16, 26, 12, 18, 21, 14, 15, 9, 13, 0, 12, 17, 15, 11, 28, 9, 16, 15, 16, 0, 18, 21, 14, 13, 33, 20, 13, 17, 13, 0, 14, 17, 13, 21, 20, 11, 14, 18, 13, 0, 14, 20, 21, 16, 26, 13, 11, 14, 15, 0, 13, 17, 16, 14, 19, 24, 11, 11, 8, 0, 12, 18, 13, 10, 22, 16, 18, 17, 13, 0, 12, 19, 13, 23, 24, 13, 17, 6, 16, 0, 14, 23, 6, 21, 29, 15, 14, 16, 13, 0, 17, 12, 17, 19, 23, 14, 8, 8, 10, 0, 6, 16, 15, 19, 61, 20, 13, 14, 13, 0, 13, 18, 15, 12, 21, 17, 13, 17, 12, 0, 17, 19, 9, 16, 38, 19, 9, 13, 17, 0, 19, 21, 14, 19, 15, 10, 15, 19, 10, 0, 18, 19, 9, 16, 30, 18, 14, 14, 15, 0, 12, 18, 11, 15, 19, 16, 17, 19, 13, 0, 18, 11, 14, 20, 23, 22, 17, 14, 12, 0, 15, 16, 15, 22, 16, 16, 14, 10, 12, 0, 12, 21, 11, 26, 25, 20, 13, 13, 16, 0, 9, 16, 12, 13, 29, 23, 10, 18, 16, 0, 16, 11, 15, 14, 23, 14, 15, 10, 17, 0, 12, 14, 14, 17, 25, 42, 19, 19, 11, 0, 8, 21, 16, 11, 24, 16, 13, 13, 15, 0, 10, 16, 15, 21, 34, 16, 14, 13, 16, 0, 16, 13, 8, 12, 18, 14, 9, 25, 11, 0, 18, 13, 16, 17, 52, 11, 15, 13, 15, 0, 15, 19, 11, 22, 29, 11, 13, 20, 15, 0, 15, 17, 11, 13, 34, 21, 13, 19, 18, 0, 14, 15, 10, 11, 21, 20, 13, 11, 17, 0, 13, 18, 13, 21, 23, 13, 13, 9, 15, 0, 15, 18, 19, 12, 29, 11, 11, 10, 12, 0, 14, 13, 13, 13, 27, 19, 14, 15, 14, 0, 10, 19, 15, 14, 18, 17, 8, 6, 19, 0, 18, 10, 13, 20, 25, 16, 18, 21, 11, 0, 12, 17, 15, 15, 33, 22, 17, 20, 7, 0, 12, 11, 15, 20, 19, 18, 13, 12, 16, 0, 11, 16, 16, 19, 30, 16, 7, 19, 19, 0, 8, 17, 18, 18, 38, 14, 13, 14, 13, 0, 14, 18, 11, 13, 24, 19, 13, 19, 8, 0, 12, 18, 12, 14, 28, 15, 14, 10, 13, 0, 14, 14, 15, 20, 21, 18, 16, 26, 11, 0, 13, 17, 12, 13, 30, 14, 14, 23, 18, 0, 11, 16, 15, 20, 20, 16, 8, 17, 15, 0, 17, 15, 13, 14, 21, 16, 10, 14, 13, 0, 16, 17, 12, 18, 21, 15, 11, 14, 13, 0, 14, 13, 14, 21, 25, 14, 14, 19, 16, 0, 18, 18, 18, 11, 61, 16, 14, 19, 14, 0, 15, 30, 12, 13, 53, 17, 13, 17, 18, 0, 17, 15, 18, 13, 21, 14, 11, 18, 13, 0, 10, 20, 14, 21, 23, 15, 11, 19, 12, 0, 13, 24, 12, 13, 24, 13, 10, 21, 15, 0, 15, 9, 14, 18, 29, 13, 15, 16, 12, 0, 13, 13, 14, 20, 35, 23, 11, 13, 16, 0, 13, 11, 15, 17, 32, 9, 14, 16, 16, 0, 19, 15, 14, 14, 22, 13, 9, 14, 7, 0, 19, 20, 12, 23, 29, 18, 16, 20, 12, 0, 17, 20, 11, 15, 28, 20, 15, 21, 15, 0, 11, 18, 13, 22, 27, 14, 12, 6, 13, 0, 15, 14, 10, 8, 40, 19, 15, 9, 16, 0, 14, 11, 9, 24, 33, 12, 13, 12, 10, 0, 13, 20, 15, 14, 31, 19, 11, 15, 14, 0, 9, 22, 14, 13, 15, 16, 17, 22, 15, 0, 11, 19, 12, 17, 33, 7, 12, 15, 9, 0, 19, 22, 15, 21, 28, 7, 11, 8, 7, 0, 16, 12, 10, 14, 12, 24, 9, 19, 7, 0, 16, 13, 12, 14, 16, 19, 12, 17, 13, 0, 14, 13, 12, 20, 33, 19, 12, 17, 16, 0, 15, 12, 18, 14, 34, 19, 11, 19, 8, 0, 12, 11, 16, 15, 33, 12, 14, 17, 18, 0, 9, 17, 17, 13, 23, 24, 13, 19, 11, 0, 13, 19, 13, 17, 23, 15, 14, 13, 8, 0, 13, 21, 18, 20, 12, 18, 13, 20, 23, 0, 14, 21, 14, 15, 14, 21, 17, 18, 16, 0, 16, 18, 16, 19, 12, 13, 15, 18, 13, 0, 13, 20, 8, 14, 22, 18, 13, 15, 10, 0, 15, 16, 11, 19, 27, 14, 16, 18, 8, 0, 12, 13, 17, 14, 18, 18, 15, 13, 13, 0, 21, 15, 17, 8, 24, 19, 18, 18, 16, 0, 13, 20, 11, 14, 29, 20, 8, 13, 13, 0, 16, 14, 15, 18, 21, 16, 12, 18, 16, 0, 11, 15, 16, 19, 26, 18, 14, 19, 14, 0, 8, 17, 12, 20, 17, 14, 15, 16, 9, 0, 16, 19, 10, 21, 29, 14, 14, 6, 11, 0, 14, 18, 14, 14, 25, 18, 8, 18, 13, 0, 11, 13, 13, 16, 38, 18, 17, 16, 12, 0, 18, 11, 14, 10, 9, 18, 11, 17, 14, 0, 12, 20, 15, 14, 29, 15, 15, 17, 19, 0, 13, 20, 15, 25, 34, 18, 14, 20, 20, 0, 15, 15, 15, 16, 18, 23, 14, 30, 12, 0, 11, 17, 11, 24, 34, 15, 20, 18, 13, 0, 6, 14, 14, 19, 32, 13, 12, 14, 15, 0, 14, 16, 15, 15, 37, 17, 14, 18, 14, 0, 14, 23, 16, 14, 28, 12, 14, 10, 13, 0, 12, 14, 10, 18, 17, 9, 12, 17, 18, 0, 13, 13, 9, 18, 23, 21, 15, 15, 16, 0, 13, 26, 12, 19, 20, 14, 13, 20, 8, 0, 16, 14, 16, 20, 15, 17, 13, 18, 13, 0, 7, 13, 17, 15, 24, 11, 11, 14, 10, 0, 13, 21, 12, 27, 33, 16, 14, 14, 14, 0, 10, 18, 14, 14, 28, 12, 15, 16, 18, 0, 14, 18, 12, 18, 34, 20, 13, 11, 11, 0, 10, 19, 18, 13, 19, 11, 16, 18, 16, 0, 10, 19, 13, 15, 28, 19, 8, 11, 14, 0, 16, 22, 17, 20, 23, 15, 17, 18, 14, 0, 13, 14, 14, 16, 18, 20, 13, 25, 14, 0, 11, 18, 17, 17, 30, 11, 13, 19, 13, 0, 16, 14, 9, 16, 26, 17, 17, 36, 15, 0, 9, 16, 12, 19, 28, 13, 12, 11, 18, 0, 16, 20, 14, 14, 20, 14, 11, 19, 15, 0, 15, 16, 11, 9, 29, 19, 15, 16, 13, 0, 13, 13, 18, 14, 23, 18, 14, 12, 10, 0, 9, 21, 14, 19, 27, 17, 8, 17, 17, 0, 7, 14, 12, 19, 26, 18, 18, 14, 18, 0, 12, 18, 18, 20, 24, 16, 14, 17, 18, 0, 17, 11, 16, 24, 25, 18, 15, 10, 13, 0, 11, 18, 17, 18, 33, 13, 14, 12, 10, 0, 13, 17, 10, 18, 21, 19, 14, 13, 18, 0, 13, 17, 16, 20, 42, 13, 16, 13, 11, 0, 14, 25, 16, 13, 28, 17, 11, 19, 14, 0, 14, 17, 11, 21, 33, 19, 13, 19, 15, 0, 13, 23, 13, 17, 24, 21, 11, 26, 17, 0, 19, 13, 15, 18, 61, 14, 16, 21, 14, 0, 13, 21, 16, 19, 32, 19, 17, 11, 14, 0, 8, 15, 14, 15, 21, 14, 13, 12, 11, 0, 15, 23, 12, 20, 32, 13, 14, 10, 13, 0, 18, 14, 19, 15, 23, 16, 14, 18, 14, 0, 16, 11, 15, 19, 28, 10, 11, 16, 13, 0, 14, 28, 8, 16, 38, 13, 17, 19, 14, 0, 13, 14, 16, 22, 19, 19, 14, 20, 17, 0, 16, 16, 12, 15, 23, 17, 15, 13, 8, 0, 15, 14, 7, 25, 32, 21, 17, 17, 17, 0, 13, 14, 19, 11, 33, 18, 14, 20, 9, 0, 13, 18, 14, 16, 26, 12, 8, 19, 14, 0, 16, 19, 13, 25, 27, 27, 18, 27, 16, 0, 17, 18, 9, 7, 32, 16, 10, 13, 17, 0, 9, 15, 18, 19, 14, 13, 17, 15, 16, 0, 19, 13, 16, 17, 21, 18, 16, 13, 18, 0, 14, 22, 13, 21, 90, 12, 11, 22, 15, 0, 16, 20, 12, 19, 31, 15, 10, 19, 13, 0, 17, 13, 15, 17, 21, 16, 16, 19, 18, 0, 13, 22, 14, 8, 23, 19, 16, 16, 16, 0, 12, 20, 12, 19, 22, 17, 17, 22, 13, 0, 12, 9, 19, 15, 21, 20, 16, 21, 16, 0, 14, 19, 17, 16, 23, 13, 13, 16, 13, 0, 11, 23, 10, 17, 40, 21, 13, 12, 14, 0, 16, 17, 12, 17, 21, 11, 15, 22, 11, 0, 14, 13, 14, 14, 23, 18, 18, 17, 13, 0, 13, 12, 19, 20, 32, 19, 17, 14, 13, 0, 14, 14, 13, 15, 12, 16, 15, 16, 8, 0, 20, 20, 15, 19, 25, 21, 17, 20, 16, 0, 10, 18, 11, 13, 23, 14, 13, 19, 13, 0, 10, 16, 11, 18, 18, 16, 12, 14, 15, 0, 17, 18, 12, 17, 22, 20, 14, 20, 16, 0, 15, 15, 9, 7, 31, 13, 8, 18, 14, 0, 7, 9, 8, 18, 29, 22, 16, 11, 15, 0, 18, 12, 16, 13, 26, 12, 11, 12, 12, 0, 11, 18, 13, 17, 29, 14, 14, 18, 15, 0, 13, 13, 10, 20, 34, 18, 18, 16, 14, 0, 9, 21, 13, 18, 38, 12, 16, 14, 14, 0, 16, 15, 13, 15, 20, 17, 9, 7, 12, 0, 11, 14, 15, 19, 27, 18, 14, 14, 11, 0, 13, 12, 14, 14, 29, 11, 20, 22, 13, 0, 16, 17, 16, 20, 26, 21, 12, 17, 13, 0, 17, 19, 13, 20, 28, 18, 14, 19, 12, 0, 17, 16, 13, 22, 24, 17, 11, 15, 13, 0, 19, 13, 13, 14, 24, 25, 13, 17, 14, 0, 17, 19, 16, 21, 28, 20, 15, 18, 17, 0, 15, 18, 14, 14, 20, 17, 17, 20, 17, 0, 12, 11, 13, 17, 28, 17, 12, 16, 13, 0, 11, 17, 9, 15, 23, 8, 15, 29, 13, 0, 9, 16, 15, 21, 29, 18, 19, 21, 13, 0, 15, 10, 14, 20, 25, 13, 12, 15, 9, 0, 13, 15, 13, 19, 45, 13, 16, 9, 11, 0, 15, 17, 19, 21, 29, 17, 12, 19, 13, 0, 15, 14, 13, 10, 26, 18, 17, 16, 17, 0, 8, 20, 13, 18, 23, 13, 11, 20, 17, 0, 13, 17, 15, 14, 15, 21, 15, 21, 19, 0, 19, 14, 18, 18, 32, 14, 11, 8, 9, 0, 16, 17, 12, 19, 28, 23, 15, 21, 15, 0, 20, 18, 11, 27, 26, 17, 30, 24, 21, 0 };

int main()
{
	cin >> n;
	cout << ans[n - 1] << endl;
	return 0;
}
54. police operation
#include <stdio.h>
#include <stdlib.h>
int get_i(double *a,int num,int size);
double med(double *a,int size);
double inter(long long m1,long long n1,long long m2,long long n2);
int a[2000000];
long long dp[2000000],m[2000000],n[2000000];
double aa[2000000];

int main(){
  int N,h,aa_size=0,i,j;
  long long t,tt;
  scanf("%d%d",&N,&h);
  for(i=0;i<N;i++)
    scanf("%d",a+i);
  for(i=0;i<N;i++){
    if(i)
      dp[i]=h+dp[i-1];
    else
      dp[i]=h;
    if(i && a[i]==a[i-1]){
      dp[i]=dp[i-1];
      continue;
    }
    if(aa_size){
      j=get_i(aa,a[i],aa_size-1);
      t=a[i]*(long long)a[i]+m[j]*a[i]+n[j];
      if(t<dp[i])
        dp[i]=t;
    }
    m[aa_size]=-2*a[i];
    if(i)
      n[aa_size]=a[i]*(long long)a[i]+h+dp[i-1];
    else
      n[aa_size]=a[i]*(long long)a[i]+h;
    j=++aa_size;
    while(aa_size>2){
      if(inter(m[aa_size-3],n[aa_size-3],m[j-1],n[j-1])>aa[aa_size-3])
        break;
      aa_size--;
    }
    tt=m[j-1];
    m[j-1]=m[aa_size-1];
    m[aa_size-1]=tt;
    tt=n[j-1];
    n[j-1]=n[aa_size-1];
    n[aa_size-1]=tt;
    if(aa_size>1)
      aa[aa_size-2]=inter(m[aa_size-2],n[aa_size-2],m[aa_size-1],n[aa_size-1]);
  }
  printf("%lld",dp[N-1]);
  return 0;
}
int get_i(double *a,int num,int size){
  if(size==0)
    return 0;
  if(num>med(a,size))
    return get_i(&a[(size+1)>>1],num,size>>1)+((size+1)>>1);
  else
    return get_i(a,num,(size-1)>>1);
}
double med(double *a,int size){
  return a[(size-1)>>1];
}
double inter(long long m1,long long n1,long long m2,long long n2){
  return (n2-n1)/(double)(m1-m2);
}

55. lucky numbers
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

#define NUMDIGITS 19
#define NUMSIEVE ((NUMDIGITS-1)*9*9)

// Sieve for generating primes
int p[1+NUMSIEVE];

// Lookup table for factorials
unsigned long long factorial[NUMDIGITS+1];

// To store binned integers
int bin[10];

// Stuff for number lists
typedef struct {
    short s;
    short q;
    unsigned long long mult;
} Element;

static Element *lists[NUMDIGITS+1];

unsigned int listlen[NUMDIGITS+1];
unsigned int listidx[NUMDIGITS+1];

unsigned long long table[1+(NUMDIGITS-2)*9][1+(NUMDIGITS-2)*9*9];
static unsigned long long lookup[NUMDIGITS-1][1+(NUMDIGITS-2)*9][1+(NUMDIGITS-2)*9*9];

void make_list_1(int digit, int n, unsigned long long num, short s, short q, int N)
{
    int i;
    Element *e = lists[n] + listidx[n]++;

    e->s = s;
    e->q = q;
    e->mult = factorial[n]/num;

    if (n==N) return;    

    for (i=digit; i<=9; i++) {
        bin[i]++;
        make_list_1(i, n+1, num*bin[i], s+i, q+i*i, N);
        bin[i]--;
    }
}

void pack_list(int n)
{
    int i, j, k, idx;
    int imax=n*9, jmax=n*9*9, kmax=listlen[n];
    Element *e;

    for (i=0; i<=imax; i++)
        for (j=0; j<=jmax; j++)
            table[i][j] = 0;

    
    for (k=0; k<kmax; k++) {
        e = lists[n]+k;
        table[e->s][e->q] += e->mult;
    }

    idx = 0;
    for (i=0; i<=imax; i++) {
        for (j=0; j<=jmax; j++) {
            if (table[i][j]) {
                e = lists[n]+idx++;
                e->s = i;
                e->q = j;
                e->mult = table[i][j];
            }
        }
    }
    listlen[n] = idx;
}

void make_list(int N)
{
    int i;
    make_list_1(0, 0, 1, 0, 0, N);

    for (i=1; i<=N; i++) {
        pack_list(i);
    }
}

unsigned long long num_lucky(int n, int ss, int sq)
{
    int i, imax=listlen[n];
    unsigned long long ires = 0;
 
    if (lookup[n][ss][sq]) return lookup[n][ss][sq];

    for (i=0; i<imax; i++) {
        if (p[sq+lists[n][i].q]&&p[ss+lists[n][i].s]) {
            ires += lists[n][i].mult;
        }
    }

    if (ires)
        lookup[n][ss][sq] = ires;

    return ires;
}

int main()
{
    int T;
    int i, j;
    int nsieve, sqrtnsieve;
    int len, alen, blen;
    char A[NUMDIGITS+1], B[NUMDIGITS+1];
    int a[NUMDIGITS+1], b[NUMDIGITS+1];
    unsigned long long ires;
    int ssl, ssu, sql, squ;

    // Lengths of lists of candidates
    for (i=0; i<=NUMDIGITS; i++) {
        if (i>0)
            listlen[i] = ((i+9)*listlen[i-1])/i;
        else
            listlen[i] = 1;
        lists[i] = (Element *)malloc(listlen[i]*sizeof(Element));
        listidx[i] = 0;
    }

    // Make primes
    nsieve = NUMSIEVE;
    sqrtnsieve = sqrt(nsieve);
    p[1] = 0;
    for (i=2; i<=nsieve; i++)
        p[i] = 1;
    for (i=2; i<=sqrtnsieve; i++)
        if (p[i]==1)
            for (j=i+i; j<=nsieve; j+=i)
                p[j] = 0;

    // Make factorials
    factorial[0] = 1;
    for (i=1; i<=NUMDIGITS; i++)
        factorial[i] = i*factorial[i-1];

    // Create the master lists
    make_list(17);

    scanf("%d", &T);

    while (T--) {

        scanf("%s %s", A, B);
        alen = strlen(A);
        blen = strlen(B);

        if (alen==19) {
            alen = 18;
            for (i=0; i<alen; i++)
                A[i] = '9';
        }
        if (blen==19) {
            blen = 18;
            for (i=0; i<blen; i++)
                B[i] = '9';
        }
        len = blen;

        for (i=0; i<len; i++)
            a[i] = (i<blen-alen)?0:(A[i-(blen-alen)]-'0');
        for (i=0; i<len; i++)
            b[i] = B[i]-'0';

        ires = 0;
        for(i=a[0]; i<=b[0]; i++)
            ires += num_lucky(len-1, i, i*i);
        
        ssl = sql = ssu = squ = 0;
        for (j=1; j<len; j++) {
            ssl += a[j-1];
            sql += a[j-1]*a[j-1];
            for (i=0;i<a[j];i++) {
                ires -= num_lucky(len-j-1, ssl+i, sql+i*i);
            }
            ssu += b[j-1];
            squ += b[j-1]*b[j-1];
            for (i=9;i>b[j];i--) {
                ires -= num_lucky(len-j-1, ssu+i, squ+i*i);
            }
        }

        printf("%llu\n", ires);
    }

    for (i=0; i<=NUMDIGITS; i++)
        if (lists[i]) free(lists[i]);

    return 0;
}

56. count scorecards
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <stdio.h>
#include <stdlib.h>

#define P 1000000007
#define N 450

long long bin[50][50],jj,kk,h,ll,ii,t,a[50][50][1010],i,j,k,l,m,n,c[100],b[100];


int com(const void * xx, const void *yy)
{
if(*(long long *)xx < *(long long*)yy) return 1;
return -1;
}

int main()
{

for(i=0;i<50;i++) bin[i][0] = bin[i][i]=1;
for(i=1;i<50;i++)
 for(j=1;j<i;j++) bin[i][j] = (bin[i-1][j-1]+ bin[i-1][j])%P;

scanf("%lld",&t);
while(t--)
{
scanf("%lld",&n);
for(i=0;i<n;i++) scanf("%lld",&c[i]);

qsort(c,n,sizeof(c[0]),com);

for(i=0;i<=n;i++) b[i]=0; 

m=0;
for(i=0;i<n;i++) if(c[i]!=-1) b[c[i]]++; else m++;


for(i=0;i<=n;i++) 
 for(j=0;j<=n;j++) 
  for(k=0;k<=N;k++) a[i][j][k]=0;

a[n][0][0] = 1;
l=0;

for(i=n-1;i>=0;i--) 
{
 for(j=0;j<=m;j++)
 {
  h=0;
  ll=l;
  for(ii=0;ii<b[i];ii++)
    {
    h += (n-ll-j-1) - i;
    ll++;
    }
 
// printf("%lld %lld h %lld %lld=l\n",i,j,h,l);
 
  for(k=0;k<=N;k++) 
   if(k+h>=0) a[i][j][k+h] = (a[i][j][k+h] + a[i+1][j][k])%P;
}

//for(ii=0;ii<=n;ii++)
// for(jj=0;jj<=m;jj++)
//  for(kk=0;kk<=1000;kk++)
//   if(a[ii][jj][kk]) printf("%lld %lld %lld -> %lld\n", ii,jj,kk,a[ii][jj][kk]);
//printf("stred -----------%lld\n",i);



 // continue;
 
 for(j=m;j>=0;j--)
  for(k=0;k<N;k++)
    {
    h = k;
    for(jj=1;jj<=j && h>=0;jj++)
     {
     h -= (n-l-b[i]-(j-jj)-1) - i;
     
     if(h<0) break;
     
     a[i][j][k] = (a[i][j][k] + bin[m-j+jj][jj]*a[i][j-jj][h])%P;
//    if(a[i][j-jj][h]>0)     printf("...%lld=i %lld=j %lld=k %lld=jj %lld=h\n",i,j,k,jj,h);     
     }
}

//for(ii=0;ii<=n;ii++)
// for(jj=0;jj<=m;jj++)
//  for(kk=0;kk<=1000;kk++)
//   if(a[ii][jj][kk]) printf("%lld %lld %lld -> %lld\n", ii,jj,kk,a[ii][jj][kk]);

//printf("-----------%lld\n",i);
 
l+=b[i];
}

/*
for(i=0;i<=n;i++)
 for(j=0;j<=m;j++)
  for(k=0;k<=1000;k++)
   if(a[i][j][k]) printf("%lld %lld %lld -> %lld\n", i,j,k,a[i][j][k]);


for(i=0;i<=n;i++) printf("%lld %lld\n",i,c[i]);
*/
printf("%lld\n",(a[0][m][0]+P)%P);
//return 0;

}


return 0;
}
57. vim war
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1048576
#define MOD 1000000007
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

int n, m, r, pos[25], ar[MAX], temp[MAX], P[MAX], dp[MAX][2];

int Solve(){
    int i, j, k, x, y, u, v, bitmask;

    clr(dp);
    for (i = 0; i < n; i++) dp[ar[i]][0]++;

    for (j = 1; j < 21; j++){
        u = j & 1;
        v = (j - 1) & 1;

        for (i = 0; i < MAX; i++){
            if (i & (1 << (j - 1))) dp[i][u] = dp[i][v];
            else dp[i][u] = (dp[i][v] + dp[i + (1 << (j - 1))][v]);
        }
    }

    int res = P[n];
    for (bitmask = 1; bitmask < MAX; bitmask++){
        x = dp[bitmask][0];
        if (x){
            if (__builtin_popcount(bitmask) & 1) res = (res - P[x] + MOD) % MOD;
            else res = (res + P[x]) % MOD;
        }
    }

    return res;
}

int main(){
    char str[25];
    int i, j, k, x, lim;

    P[0] = 1;
    for (i = 1; i < MAX; i++) P[i] = (P[i - 1] << 1) % MOD;
    for (i = 0; i < MAX; i++) P[i] = (P[i] - 1 + MOD) % MOD;

    while (scanf("%d %d", &n, &m) != EOF){
        for (i = 0; i <= n; i++){
            x = 0;
            scanf("%s", str);

            for (j = 0; str[j]; j++) x = (x << 1) + (str[j] - 48);
            temp[i] = x;
        }

        r = n;
        n = 0, k = 0;
        memset(pos, -1, sizeof(pos));

        for (j = 0; j < m; j++){
            if (temp[r] & (1 << j)) pos[j] = k++;
        }

        lim = (1 << k) - 1;
        for (i = 0; i < r; i++){
            x = 0, k = 0;
            for (j = 0; j < m; j++){
                if (temp[i] & (1 << j)){
                    if (pos[j] == -1){
                        k = 1;
                        break;
                    }
                    x |= (1 << pos[j]);
                }
            }
            if (!k) ar[n++] = x ^ lim;
        }

        printf("%d\n", Solve());
    }
    return 0;
}

58. swap permutations
#include<stdio.h>

int i,j,k,n,mod;
long long ans1,ans2;
long long f[2600][2600],g[2600][2600];

main()
{
	mod=1000000007;
	scanf("%d%d",&n,&k);
	f[1][0]=1;
	for (i=2; i<=n; i++)
	{
		f[i][0]=1;
		for (j=1; j<=k && j<=i*(i-1)/2; j++)
		{
			f[i][j]=f[i][j-1];
			if (j<=(i-1)*(i-2)/2) f[i][j]=(f[i][j]+f[i-1][j])%mod;
			if (j>=i) f[i][j]=(f[i][j]-f[i-1][j-i]+mod)%mod;
		}
	}
	ans1=0;
	for (i=0; i<=k; i++)
		if ((k-i)%2==0) ans1=(ans1+f[n][i])%mod;
	g[1][1]=1;
	for (i=2; i<=n; i++)
	{
		g[i][1]=g[i-1][1]*(i-1)%mod;
		for (j=2; j<i; j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(i-1)%mod)%mod;
		g[i][i]=1;
	}
	ans2=0;

	for (i=n; i>=n-k && i>=1; i--)
		ans2=(ans2+g[n][i])%mod;
	printf("%lld %lld\n",ans1,ans2);
}

59. best spot
#include <stdio.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;

inline int pow(long long n,int k,int m){
    unsigned i;
    int a;
    for(a=i=1;i<=k;i*=2,n=(n*n)%m)
        if(k&i)a=(a*n)%m;
    return a;
}
int rr[512];
inline int rev(int n,int k){
    int i=0;
    while(k--)i=(i<<1)|(n&1),n/=2;
    return i;
}
const long long p=1107296257,r=10;
LL ww[513][2];
void ntt(int f,int n,int s[]){
    int i,j,k=10;
    long long x,w;
    for(i=0;i<n;i++)
        if(i<rr[i]){
            int tmp=s[i];
            s[i]=s[rr[i]];
            s[rr[i]]=tmp;
        }
    for(i=2;i<=n;i<<=1){
        w=ww[i][f];
        for(j=0;j<n;j+=i)
            for(k=0,x=1;k<i/2;k++){
                int a=s[j+k],b=s[j+k+i/2];
                LL tmp=b*x;
                b=(a-tmp)%p;
                if(b<0)b+=p;
                a=(a+tmp)%p;
                s[j+k]=a;
                s[j+k+i/2]=b;
                x=x*w%p;
            }
    }
    x=pow(n,p-2,p);
    if(f)for(j=0;j<n;j++)
        s[j]=(s[j]*x)%p;
}
void mul(int n,int cc[],int a[],int b[]){
    for(int i=0;i<n;i++)
        cc[i]=(1ll*a[i]*b[i])%p;
}
int A[501][512],B[501][512],an[501][501],tmp[512];
int main(){
    REP(i,512)rr[i]=rev(i,9);
    for(int i=2;i<=512;i<<=1)
        for(int f=0;f<2;f++)ww[i][f]=pow(pow(r,(p-1)/512,p),f?p-1-512/i:512/i,p);
    DRII(R,C);
    REP(i,R)REP(j,C){
        RI(A[i][j]);
        A[i][j]+=20;
    }
    DRII(H,W);
    int base=0;
    REP(i,H)REP(j,W){
        RI(B[i][j]);
        B[i][j]+=20;
        base+=B[i][j]*B[i][j];
    }
    for(int i=0;i+H<=R;i++)
        for(int j=0;j+W<=C;j++)an[i][j]+=base;
    REP(i,R){
        base=0;
        for(int j=0;j<C;j++){
            base+=A[i][j]*A[i][j];
            if(j>=W-1){
                for(int k=0;k<H&&k<=i;k++)an[i-k][j-W+1]+=base;
                base-=A[i][j-W+1]*A[i][j-W+1];
            }
        }
    }
    REP(i,R){
        for(int j=0;j<C-1-j;j++){
            int tmp=A[i][j];
            A[i][j]=A[i][C-1-j];
            A[i][C-1-j]=tmp;
        }
        ntt(0,512,A[i]);
    }
    REP(i,W)ntt(0,512,B[i]);
    REP(i,H){
        for(int j=0;j+H<=R;j++){
            mul(512,tmp,A[i+j],B[i]);
            ntt(1,512,tmp);
            //mul(500,B[i],A[j+i],tmp);
            for(int k=0;k+W<=C;k++){
                an[j][k]-=2*tmp[W-1+(C-W-k)];
            }
        }
    }
    int mi=2e9,xx,yy;
    for(int i=0;i+H<=R;i++)
        for(int j=0;j+W<=C;j++){
            if(an[i][j]<mi){
                mi=an[i][j];
                xx=i+1;yy=j+1;
            }
        }
    printf("%d\n%d %d\n",mi,xx,yy);
    return 0;
}

60. robot
#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
  int w;
} node;
void heap_insert(node *heap,node *elem,int *size,int idx);
void heap_read(node *heap,int *size,int idx);
long long get_val(int w,int idx,int *flag);
int *V,*P;
long long *sum,*dp;

int main(){
  int N,i,heap_size=0,flag;
  long long ans,max,t;
  node *heap,elem;
  scanf("%d",&N);
  V=(int*)malloc(N*sizeof(int));
  P=(int*)malloc(N*sizeof(int));
  sum=(long long*)malloc(N*sizeof(long long));
  dp=(long long*)malloc(N*sizeof(long long));
  heap=(node*)malloc(2*N*sizeof(heap));
  for(i=0;i<N;i++)
    scanf("%d%d",V+i,P+i);
  for(i=0;i<N;i++)
    if(i==0)
      sum[i]=V[i];
    else
      sum[i]=sum[i-1]+V[i];
  for(i=0;i<N-1;i++){
    max=0;
    if(heap_size)
      do{
        t=get_val(heap[1].w,i,&flag);
        if(flag>0 && t>max)
          max=t;
        else if(flag==0 && P[i] && t-V[i]>max){
          max=t-V[i];
          heap_read(heap,&heap_size,i);
        }
        else if(flag<=0)
          heap_read(heap,&heap_size,i);
      }while(flag<=0 && heap_size);
    dp[i]=max;
    elem.w=i;
    heap_insert(heap,&elem,&heap_size,i);
  }
  max=0;
  if(heap_size)
    do{
      t=get_val(heap[1].w,i,&flag);
      if(flag>=0 && t>max)
        max=t;
      else if(flag<0)
        heap_read(heap,&heap_size,i);
    }while(flag<0 && heap_size);
  printf("%lld",max);
  return 0;
}
void heap_insert(node *heap,node *elem,int *size,int idx){
  (*size)++;
  int index=(*size);
  while(index>1 && get_val(elem->w,idx,0)>get_val(heap[index/2].w,idx,0)){
    heap[index]=heap[index/2];
    index/=2;
  }
  heap[index]=(*elem);
  return;
}
void heap_read(node *heap,int *size,int idx){
  int index=1;
  while(index*2<*size && get_val(heap[*size].w,idx,0)<get_val(heap[index*2].w,idx,0) || index*2+1<*size && get_val(heap[*size].w,idx,0)<get_val(heap[index*2+1].w,idx,0)){
    index=(get_val(heap[index*2].w,idx,0)<get_val(heap[index*2+1].w,idx,0))?index*2+1:index*2;
    heap[index/2]=heap[index];
  }
  heap[index]=heap[*size];
  (*size)--;
  return;
}
long long get_val(int w,int idx,int *flag){
  if(flag){
    if(idx-w>P[w])
      *flag=-1;
    else if(idx-w==P[w])
      *flag=0;
    else
      *flag=1;
  }
  long long ans;
  if(!w)
    ans=0;
  else
    ans=dp[w-1];
  return ans+sum[idx]-sum[w];
}

61. travel around the world
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

const int max_n = 100000 + 10;

int n, a[max_n], b[max_n];
LL c, fuel[max_n];

int get_start() {
    int valid_start = -1;
    int start_city = 0, current_city = 0;
    LL current_fuel = 0;
    for (int i = 0; i < n * 2 + 10; ++i) {
        fuel[current_city] = current_fuel;
        int next_city = (current_city + 1) % n;
        LL next_fuel = min(current_fuel + a[current_city], c) - b[current_city];
        if (next_fuel < 0) {
            start_city = current_city = next_city;
            current_fuel = 0;
        } else if (next_city == start_city) {
            valid_start = start_city;
            break;
        } else {
            current_city = next_city;
            current_fuel = next_fuel;
        }
    }
    return valid_start;
}

int count_start() {
    int start = get_start();
    if (start == -1)
        return 0;
    int current = start;
    while (true) {
        int pre = (current + n - 1) % n;
        LL tmp = min(max(fuel[current] + b[pre] - a[pre], 0LL), c);
        if (tmp == fuel[pre])
            break;
        fuel[pre] = tmp;
        current = pre;
    }
    return count(fuel, fuel + n, 0);
}

void solve() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    printf("%d\n", count_start());
}

int main() {
    solve();
    return 0;
}

62. repetitive k-sums
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int Tot;

long long a[100010];
map <long long,int> mp;

void dfs(int now,int ee,int les)
{
    if (les==0||now+1==ee)
    {
        Tot++;
        return;
    }
    for (int i=0;i<=les;i++)
        dfs(now+1,ee,les-i);
}

void dfs2(int now,long long num,int les)
{
    if (now==0) num+=les*a[0];
    if (les==0||now==0)
    {
        mp[num]--;
        if (mp[num]==0) mp.erase(num);
        return;
    }
    for (int i=0;i<=les;i++)
        dfs2(now-1,num+i*a[now],les-i);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        Tot=0;
        dfs(0,n,m);
        for (int i=0;i<Tot;i++)
        {
            long long x;
            scanf("%lld",&x);
            mp[x]++;
        }
        for (int i=0;i<n;i++)
        {
            long long now=mp.begin()->first;
            if (i==0)
            {
                a[i]=now/m;
                mp[now]--;
                if (mp[now]==0) mp.erase(now);
            }
            else
            {
                a[i]=now-a[0]*(m-1);
                for (int j=1;j<=m;j++)
                {
                    dfs2(i-1,a[i]*j,m-j);
                }
            }
        }
        for (int i=0;i<n;i++)
        {
            if (i) printf(" ");
            printf("%lld",a[i]);
        }
        puts("");
    }
    return 0;
}

63. dortmund dilemma
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 1e5+5;
const int MOD = 1e9+9;
LL C[27][27],an[27][SIZE],tmp[27][SIZE],pp[27][SIZE],tmp2[27][SIZE],ha[27];
int main(){
    REPP(i,1,27){
        pp[i][0]=1;
        REPP(j,1,SIZE)pp[i][j]=pp[i][j-1]*i%MOD;
    }
    REP(i,27){
        C[i][0]=1;
        REPP(j,1,i+1){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    REPP(i,1,27){
        an[i][1]=i;
        tmp[i][1]=i;
        REPP(j,2,SIZE){
            if(j%2==0)an[i][j]=tmp[i][j/2];
            else an[i][j]=tmp[i][j/2]*i%MOD;
            an[i][j]=pp[i][j]-an[i][j];
            REPP(k,1,i){
                an[i][j]=(an[i][j]-an[k][j]*C[i][k])%MOD;
            }
            if(an[i][j]<0)an[i][j]+=MOD;
            tmp[i][j]=tmp[i][j-1]*i*i%MOD;
            REPP(k,1,i+1){
                tmp[i][j]=(tmp[i][j]+C[i][k]*an[k][j])%MOD;
            }

        }

    }
    CASET{ 
        DRII(N,K);
        if(N==1){
            puts("0");
            continue;
        }
        LL res=0;
        if(N%2==0){
            ha[1]=tmp[1][N/2];
            REPP(i,2,K+1){
                ha[i]=tmp[i][N/2];
                REPP(j,1,i)ha[i]=(ha[i]-ha[j]*C[i][j])%MOD;
                if(ha[i]<0)ha[i]+=MOD;
            }
            res=ha[K]*C[26][K]%MOD;
        }
        else{
            ha[1]=tmp[1][N/2];
            REPP(i,2,K+1){
                ha[i]=tmp[i][N/2]*i%MOD;
                REPP(j,1,i)ha[i]=(ha[i]-ha[j]*C[i][j])%MOD;
                if(ha[i]<0)ha[i]+=MOD;
            }
            res=ha[K]*C[26][K]%MOD;
        }
        if(K==1)res=26;
        if(res<0)res+=MOD;
        printf("%lld\n",res);
    }
    return 0;
}

64. separate the chocolate
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

typedef unsigned long long llu;
struct node {
int  num;   // black - white
char a[9];  //the number of the grid even-white odd-black
char no;   //the forbideen color the 0-white 1-black 2-both can
char vwb;  //the valid color 0-white 1-black 2-both 3-neither
char dwb;  //0-dead white (Never can appear a white grid) 1-dead black 3-neither dead
};

int m,n,last,now,pp,un;
llu ans;
char s[10][10];


inline bool operator<(const node &a,const node &b) {
    if (a.no < b.no) {
        return true;
    }
    if (a.no > b.no) {
        return false;
    }
    if (a.dwb < b.dwb) {
        return true;
    }
    if (a.dwb > b.dwb) {
        return false;
    }
    if (a.vwb < b.vwb) {
        return true;
    }
    if (a.vwb > b.vwb) {
        return false;
    }
        if (a.num<b.num) {
            return true;
        }
        if (a.num>b.num) {
            return false;
        }
    for (int i = 0;i < n;++i) {
        if (a.a[i] < b.a[i]) {
            return true;
        }
        if (a.a[i] > b.a[i]) {
            return false;
        }
    }
    return false;
}

map<node,llu> save[2];

inline bool iswhite(int x) {
    return !(x & 1);
}

inline bool isblack(int x) {
    return (x & 1);
}

void makelone(node &temp,int y,int x,int n) {
int i,j,z = (y << 1) + x;
    temp.a[y] = z;
    z = (y << 1);
    for (i = y + 1;i < n;++i) {
        if (temp.a[i] == z) {
            break;
        }
    }
    for (j = i,i <<= 1; j < n; ++j) {
        if (temp.a[j] == z) {
            temp.a[j] = i;
        }
    }
    z = (y << 1) | 1;
    for (i = y + 1;i < n;++i) {
        if (temp.a[i] == z) {
            break;
        }
    }
    for (j = i,i = (i << 1) | 1;j < n;++j) {
        if (temp.a[j] == z) {
            temp.a[j] = i;
        }
    }

}

void makeunion(node &temp,int x,int y,int n) {
    if (x < y) {
        x ^= y ^= x ^= y;
    }
    for (int i = 0; i < n;++i) {
        if (temp.a[i] == x) {
            temp.a[i] = y;
        }
    }
}


void makewhite(int x,int y,node temp,llu ans,int add) {
bool yes;
int i,j,k,ll,uu;
map<node,llu>::iterator t;

    if ((temp.no == 0) || (temp.dwb == 0))  { 
        return;
    }
    temp.num += add;
    if ((temp.num + un < -pp) || (temp.num - un > pp)) {
        return;
    }
    yes = (temp.dwb == 1);

    if ((x) && (temp.a[y] == ((y << 1) | 1))) { //above is the head of black
        for (i = y + 1;i < n;++i) {
            if (temp.a[i] == temp.a[y]) {
                break;
            }
        }
        if (i >= n) {
            if ((temp.vwb != 1) && (temp.vwb != 2)) { //make black dead
                return;
            }
            yes = true;
        }
    }
    ll = ((y) && iswhite(temp.a[y - 1]))?temp.a[y - 1]:(-1);
    uu = ((x) && iswhite(temp.a[y]))?temp.a[y]:(-1);
    k = x?n:(y + 1);
    if (uu < 0) {
        makelone(temp, y,0 ,k);
        if (ll >= 0) {
            temp.a[y] = ll;
        }
    }
    else if ((ll >= 0) && (ll != uu)) {
        makeunion(temp,ll,uu,k);

    }
    for (i = j = 0;i < k;++i) {
        if ((temp.a[i]== (i<<1)) && (++j > 1)) {
            break;
        }
    }
    if (j == 1) {
        temp.vwb = ((temp.vwb == 1) || (temp.vwb == 2))?2:0;
    }
    else { //j > 1
        temp.vwb = ((temp.vwb == 1) || (temp.vwb == 2))?1:3;
    }
    temp.dwb = yes?1:3;
    temp.no = ((uu >= 0) && (y + 1 < n) && ((temp.a[y + 1] & 1) == 0))?0:2;
    save[now][temp] += ans;

}


void makeblack(int x,int y,node temp,llu ans,int add) {
bool yes;
int i,j,k,ll,uu;
map<node,llu>::iterator t;

    if ((temp.no == 1) || (temp.dwb == 1))  { 
        return;
    }
    temp.num += add;
    if ((temp.num + un < -pp) || (temp.num - un > pp)) {
        return;
    }

    yes = (temp.dwb == 0);
    if ((x) && (temp.a[y]==(y << 1))) { //above is the head of white
        for (i = y + 1;i < n;++i) {
            if (temp.a[i] == temp.a[y]) {
                break;
            }
        }
        if (i >= n) {
            if ((temp.vwb != 0) && (temp.vwb != 2)) { ///make black dead
                return;
            }
            yes = true;
        }
    }

    ll = ((y) && isblack(temp.a[ y - 1]))?temp.a[y - 1]:(-1);
    uu = ((x) && isblack(temp.a[y]))?temp.a[y]:(-1);
    k = x?n:(y + 1);
    if (uu < 0) {
        makelone(temp,y,1,k);
        if (ll >= 0) {
            temp.a[y] = ll;
        }
    }
    else if ((ll >= 0) && (ll != uu)) {
        makeunion(temp,ll,uu,k);
    }
    for (i = j = 0;i < k;++i) {
        if ((temp.a[i]==((i << 1) | 1)) && (++j > 1)) {
            break;
        }
    }
    if (j == 1) {
        temp.vwb = ((temp.vwb==0) || (temp.vwb==2))?2:1;
    }
    else { //j>1
        temp.vwb = ((temp.vwb==0) || (temp.vwb==2))?0:3;
    }
    temp.dwb = yes?0:3;
    temp.no = ((uu >= 0) && (y + 1 < n) && ((temp.a[ y + 1] & 1) == 1))?1:2;
    save[now][temp] += ans;

}


int main() {
int z;
node temp;
    scanf("%d%d%d",&m,&n,&pp);
    assert(0 <= m && m <= 8);
    assert(0 <= n && n <= 8);
    assert(0 <= pp <= m*n);
    memset(temp.a,0,sizeof(temp.a));
    temp.num = 0;
    temp.no = temp.vwb = 2;
    temp.dwb = 3;
    save[0].clear();
    un = 0;
    for (int i  = 0;i < m;++i) {
        scanf("%s",s[i]);
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'T') {
                ++temp.num;
            }
            else if (s[i][j] == 'D') {
                --temp.num;
            }
            else {
                ++un;
            }
        }
    }
    save[last = 0][temp] = 1;
    //printf("un = %d\n",un);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n;++j) {
            save[now = 1 ^ last].clear();
            if (s[i][j] == 'U') {
                --un;
            }   
            for (map<node,llu>::iterator t = save[last].begin();t != save[last].end();++t) {
                if (s[i][j] == 'T') {
                    makeblack(i,j,t->first,t->second, 0);
                }
                else if (s[i][j] == 'D') {
                    makewhite(i,j,t->first,t->second, 0);
                }
                else {
                    makeblack(i,j,t->first,t->second, 1);
                    makewhite(i,j,t->first,t->second, -1);
                }
            }
            last = now;
        }

    }
    ans = 0;
    //printf("un = %d\n",un);
    assert(un == 0);
    for (map<node,llu>::iterator t = save[last].begin();t != save[last].end();++t) {
        if (t->first.vwb == 2) {
            assert((t->first.num >= -pp) && (t->first.num <= pp));
            //printf("%d %llu\n",t->first.num, t->second);
            ans += t->second;
        }
    }
    printf("%llu\n",ans);
    return 0;
}