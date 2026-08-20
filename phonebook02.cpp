#include <stdio.h>
#include <cstdlib>
#include <cstring>

#define CAPACITY 100 // 100명까지 저장 
#define BUFFER_SIZE 20 // 명령문(입력) 사이즈

char *names[CAPACITY];
char *numbers[CAPACITY];

int people = 0; // 저장된 사람 수

void add(){
    // names[people] 에는 buf를 바로 할당할 수 없다. buf1,2 는 스택에 할당되어 add()가 return 되면 소멸되기 때문
    // 따라서 strdup를 사용해 buf에 저장된 문자열을 복제하고 그 복제된 배열의 주소를 names에 저장(연결)한다. 
    // strudp는 malloc으로 heap에 할당되어 소멸하지 않는다!
    
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    scanf("%s", buf1);
    scanf("%s", buf2);

    names[people] = strdup(buf1);
    numbers[people] = strdup(buf2);
    people++;

    printf("%s was added successfully. \n", buf1);
}

void find(){
    char buf[BUFFER_SIZE];
    scanf("%s", buf);
    
    for(int i=0; i<people; i++){
        if(strcmp(buf, names[i]) == 0){
            printf("%s\n", numbers[i]);
            return;
        }
    }
    printf("No person named '%s' exist. \n", buf);
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

    for(int i=0; i<people; i++){
        if(strcmp(buf, names[i]) == 0){
            names[i] = names[people-1]; // 맨 마지막 사람을 삭제된 자리로 옮긴다 (빈칸 없이 만들기)
            numbers[i] = names[people-1];
            people--;
            printf("%s was deleted succesfully. \n", buf);
            return; 
        }
    }
    printf("No person named '%s' exists. \n", buf);
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
        else if(strcmp(command, "exit") == 0){
            break;
        }
    }
    return 0; 
}

