//first-fit –
// C++ implementation of First - Fit algorithm
#include<bits/stdc++.h>
using namespace std;
// Function to allocate memory to
// blocks as per First fit algorithm
void firstFit(int blockSize[], int m,
int processSize[], int n)
{
// Stores block id of the
// block allocated to a process
int allocation[n];
// Initially no block is assigned to any process
memset(allocation, -1, sizeof(allocation));
// pick each process and find suitable blocks
// according to its size ad assign to it
for (int i = 0; i < n; i++)
{
for (int j = 0; j < m; j++)
{
if (blockSize[j] >= processSize[i])
{
// allocate block j to p[i] process
allocation[i] = j;
// Reduce available memory in this block.
blockSize[j] -= processSize[i];
break;
}
}
}
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < n; i++)
{
cout << " " << i+1 << "\t\t"
<< processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
// Driver code
int main()
{
cout << "First-Fit Alogorithm\n";
int blockSize[] = {100, 500, 200, 300, 600};
int processSize[] = {22, 41, 1112, 86};
int m = sizeof(blockSize) / sizeof(blockSize[0]);
int n = sizeof(processSize) / sizeof(processSize[0]);
firstFit(blockSize, m, processSize, n);
return 0 ;
}

//best-fit –
// C++ implementation of Best - Fit algorithm
#include<bits/stdc++.h>
using namespace std;
// Function to allocate memory to blocks as per Best fit
// algorithm
void bestFit(int blockSize[], int m, int processSize[], int n)
{
// Stores block id of the block allocated to a
// process
int allocation[n];
// Initially no block is assigned to any process
memset(allocation, -1, sizeof(allocation));
// pick each process and find suitable blocks
// according to its size ad assign to it
for (int i=0; i<n; i++)
{
// Find the best fit block for current process
int bestIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (bestIdx == -1)
bestIdx = j;
else if (blockSize[bestIdx] > blockSize[j])
bestIdx = j;
}
}
// If we could find a block for current process
if (bestIdx != -1)
{
// allocate block j to p[i] process
allocation[i] = bestIdx;
// Reduce available memory in this block.
blockSize[bestIdx] -= processSize[i];
Page | 22
}
}
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < n; i++)
{
cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
// Driver code
int main()
{
cout << "Best-fit Allocation\n";
int blockSize[] = {100, 500, 200, 300, 600};
int processSize[] = {212, 417, 112, 426};
int m = sizeof(blockSize)/sizeof(blockSize[0]);
int n = sizeof(processSize)/sizeof(processSize[0]);
bestFit(blockSize, m, processSize, n);
return 0 ;
}

//worst-fit—
// C++ implementation of worst - Fit algorithm
#include<bits/stdc++.h>
using namespace std;
// Function to allocate memory to blocks as per worst fit
// algorithm
void worstFit(int blockSize[], int m, int processSize[],
int n)
{
// Stores block id of the block allocated to a
// process
int allocation[n];
// Initially no block is assigned to any process
memset(allocation, -1, sizeof(allocation));
// pick each process and find suitable blocks
// according to its size ad assign to it
for (int i=0; i<n; i++)
{
// Find the best fit block for current process
int wstIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (wstIdx == -1)
wstIdx = j;
else if (blockSize[wstIdx] < blockSize[j])
wstIdx = j;
}
}
// If we could find a block for current process
if (wstIdx != -1)
{
// allocate block j to p[i] process
allocation[i] = wstIdx;
// Reduce available memory in this block.
Page | 24
blockSize[wstIdx] -= processSize[i];
}
}
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < n; i++)
{
cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
// Driver code
int main()
{
int blockSize[] = {130, 570, 210, 340, 600};
int processSize[] = {122, 400, 11, 326};
int m = sizeof(blockSize)/sizeof(blockSize[0]);
int n = sizeof(processSize)/sizeof(processSize[0]);
worstFit(blockSize, m, processSize, n);
return 0 ;
}
