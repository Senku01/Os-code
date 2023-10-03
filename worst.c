#include<stdio.h>
#define INT_MIN -100
struct MemoryBlock{

int size;
int allocated;
};
void worstFit(struct MemoryBlock memory[],int numBlocks,int processSize){
int worstFitIndex = -1;
int maxFragmentation = INT_MIN;
for(int i=0;i<numBlocks;i++){
if(!memory[i].allocated && memory[i].size>=processSize){
int fragmentation = memory[i].size - processSize;
if(fragmentation > maxFragmentation){
maxFragmentation = fragmentation;
worstFitIndex = i;
}
}
}
if(worstFitIndex != -1){
memory[worstFitIndex].allocated = 1;
printf("Memory allocated at block %d\n",worstFitIndex);
}else{
printf("Insufficient memroy\n");
}
}
int main(){
struct MemoryBlock memory[5] = {{150,0},{400,0},{550,0},{500,0},{200,0}};
worstFit(memory,5,175);
return 0;
}
