#include&lt;stdio.h&gt;
#include&lt;time.h&gt;
#include&lt;stdlib.h&gt; /* To recognise exit function when compiling with gcc*/
void selsort(int n,int a[]);
void main()
{
int a[15000],n,i,j,ch,temp;
clock_t start,end;
while(1)
{
printf(&quot;\n1:For manual entry of N value and array elements&quot;);
printf(&quot;\n2:To display time taken for sorting number of elements N in the range 500 to 14500&quot;);
printf(&quot;\n3:To exit&quot;);
printf(&quot;\nEnter your choice:&quot;);
scanf(&quot;%d&quot;, &amp;ch);
switch(ch)
{
case 1: printf(&quot;\nEnter the number of elements: &quot;);

scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\nEnter array elements: &quot;);
for(i=0;i&lt;n;i++)
{
scanf(&quot;%d&quot;,&amp;a[i]);
}
start=clock();
selsort(n,a);
end=clock();
printf(&quot;\nSorted array is: &quot;);
for(i=0;i&lt;n;i++)

printf(&quot;%d\t&quot;,a[i]);

printf(&quot;\n Time taken to sort %d numbers is %f Secs&quot;,n, (((double)(end-start))/CLOCKS_PER_SEC));

break;

case 2:
n=500;
while(n&lt;=14500) {
for(i=0;i&lt;n;i++)
{
//a[i]=random(1000);
a[i]=n-i;
}
start=clock();
selsort(n,a);
//Dummy loop to create delay
for(j=0;j&lt;500000;j++){ temp=38/600;}
end=clock();
printf(&quot;\n Time taken to sort %d numbers is %f Secs&quot;,n, (((double)(end-start))/CLOCKS_PER_SEC));
n=n+1000;
}
break;
case 3: exit(0);
}
getchar();
}
}

void selsort(int n,int a[])
{
int i,j,t,small,pos;
for(i=0;i&lt;n-1;i++)
{
pos=i;
small=a[i];
for(j=i+1;j&lt;n;j++)
{
if(a[j]&lt;small)
{
small=a[j];
pos=j;
}
}
t=a[i];
a[i]=a[pos];
a[pos]=t;
}
}
