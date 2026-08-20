#include <stdio.h>
#include <cstdlib>
#include <cstring>

#define CAPACITY 100 // 100명까지 저장 
#define BUFFER_SIZE 20 // 명령문(입력) 사이즈

char *names[CAPACITY];
char *numbers[CAPACITY];

int people = 0; // 저장된 사람 수

void add(){
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    scanf("%s", buf1);
    scanf("%s", buf2);
    int i=people-1; // 맨마지막 사람 부터
    // strcmp 둘이 같으면 0을 반환 오른쪽이 크면 - 왼쪽이 크면 +
    while( i>=0 && strcmp(names[i], buf1) > 0){
        names[i+1] = names[i];
        numbers[i+1] = numbers[i];
        i--;
    }
    // 배열의 시작을 지나치거나, 추가하려는 숫자보다 비교하는 숫자가 더 작으면 거기서+1 인덱스에 값 저장
    names[i+1] = strdup(buf1);
    numbers[i+1] =strdup(buf2);
    people++;
    printf("%s was added successfully. \n", buf1);
}

int search(char *name){
    for(int i=0; i<people; i++){
        if(strcmp(name, names[i]) == 0){
            return i;
        }
    }
    return -1;
}

void find(){
    char buf[BUFFER_SIZE];
    scanf("%s", buf);
    int index = search(buf);
    if(index == -1){
        printf("No person named '%s' exist. \n", buf);\
    }else{
        printf("%s\n", numbers[index]);
    }
    return;
}

void status(){
    for(int i=0; i<people; i++){
        printf("%s %s\n", names[i], numbers[i]);
    }
    printf("Total %d persons.\n", people);
}

void remove(){
    char buf[BUFFER_SIZE];
    scanf("%s", buf);

    int index = search(buf);
    if(index == -1){
        printf("No person named '%s' exists.\n", buf);
        return;
    }

    for(int j=index; j<people-1; j++){
        names[j] = names[j+1];
        numbers[j] = numbers[j+1];
    }
    people--;
}

void load(){
    char fileName[BUFFER_SIZE];
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Open failed. \n");
        return;
    }

    while((fscanf(fp, "%s", buf1) != EOF)) {
        fscanf(fp, "%s", buf2);
        names[people] = strdup(buf1);
        numbers[people] = strdup(buf2);
        people++;
    }
    fclose(fp);
}

void save(){
    char fileName[BUFFER_SIZE];
    char tmp[BUFFER_SIZE];

    scanf("%s", tmp);
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "w");
    if(fp == NULL){
        printf("Open failed. \n");
        return;
    }

    for(int i=0; i<people; i++){
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}



int main() {
    char command[BUFFER_SIZE]; // 사용자 입력
    while(1){
        printf("$ ");
        scanf("%s", command);

        if(strcmp(command, "add") == 0){
            add();
        }
        else if(strcmp(command, "find") == 0){
            find();
        }
        else if(strcmp(command, "status") == 0){
            status();
        }
        else if(strcmp(command, "delete") == 0){
            remove();
        }
        else if(strcmp(command, "load") == 0){
            load();
        }
         else if(strcmp(command, "save as") == 0){
            save();
        }
        else if(strcmp(command, "exit") == 0){
            break;
        }
    }
    return 0; 
}

