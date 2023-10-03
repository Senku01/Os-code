#include<stdio.h>
struct MemoryBlock{
int size;
int allocated;
};
void firstFit(struct MemoryBlock memory[],int numBlocks,int processSize){
for(int i=0;i<numBlocks;i++){
if(!memory[i].allocated && memory[i].size >= processSize){
memory[i].allocated = 1;
printf("Memory allocated at block %d\n",i);
return;
}
}
printf("Insufficient memory\n");
}
int main() {
struct MemoryBlock memory[5] = {{100, 0}, {200, 0}, {50, 0}, {300, 0}, {150, 0}};
firstFit(memory, 5, 175);
return 0;
}
