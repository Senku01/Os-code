#include<stdio.h>
#define INT_MAX 100
struct MemoryBlock{
int size;
int allocated;
};
void bestfit(struct MemoryBlock memory[],int numblock, int processSize){
int bestfitIndex = -1;
int minfragmentation = INT_MAX;
for(int i=0 ;i< numblock;i++){
if(!memory[i].allocated&&memory[i].size >= processSize){
int fragmentation = memory[i].size-processSize;
if(fragmentation < minfragmentation){
minfragmentation = fragmentation;
bestfitIndex =i;
}
}
}
if(bestfitIndex != -1){
memory[bestfitIndex].allocated =1;
printf("Memory allocated at block %d\n",bestfitIndex);
}
else{
printf("Insufficient memory to allocated \n");
}
}

int main(){
struct MemoryBlock memory[5] = {{100,0},{200,0},{50,0},{300,0},{150,0}};
bestfit(memory,5,175);
return 0;
}
