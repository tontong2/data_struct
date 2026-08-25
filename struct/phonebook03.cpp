// 배열 재할당
// 라인 단위 입력과 문자열 tokenizing

// 잘못된 입력에 대해 대응하기!
// 저장된 배열의 크기가 모자라면 더 늘리기!

#include <stdio.h>
#include <cstdlib>
#include <cstring>

#define INIT_CAPACITY 3
#define BUFFER_SIZE 50

char **names;
char **numbers;

int people = 0;
int capacity = INIT_CAPACITY;

char delim[] = " ";


// 함수 선언
void init_directory();
int read_line(char str[], int limit);
void reallocate();
void add(char *name, char *number);
int search(char *name);
void find(char *name);
void status();
void remove(char *name);
void load(char *fileName);
void save(char *fileName);
void process_command();


int main() {
    init_directory();
    process_command();

    return 0;
}


// 디렉터리 초기화
void init_directory() {
    names = (char **)malloc(INIT_CAPACITY * sizeof(char *));
    numbers = (char **)malloc(INIT_CAPACITY * sizeof(char *));
}


// 파일로 부터 라인 단위로 읽기 
int read_line(FILE *fp, char str[], int people) {
    int ch, i = 0;

    while((ch == fgetc(fp) )!= '\n' && ch != EOF){
        if(i<people){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;

}


// 배열 크기 2배로 늘리기
void reallocate() {

    capacity *= 2;

    char **tmp1 = (char **)malloc(capacity * sizeof(char *));
    char **tmp2 = (char **)malloc(capacity * sizeof(char *));

    // 기존 배열의 포인터들을 새로운 배열로 복사
    for (int i = 0; i < people; i++) {
        tmp1[i] = names[i];
        tmp2[i] = numbers[i];
    }

    // 기존 배열 메모리 해제
    free(names);
    free(numbers);

    // 새로운 배열을 가리키도록 변경
    names = tmp1;
    numbers = tmp2;
}


// 연락처 추가
void add(char *name, char *number) {

    // 배열이 꽉 찼으면 재할당
    if (people >= capacity) {
        reallocate();
    }

    int i = people - 1;

    // 이름순으로 정렬하기 위해 기존 데이터를 한 칸씩 뒤로 이동
    while (i >= 0 && strcmp(names[i], name) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }

    // 새로운 문자열을 복사해서 저장
    names[i + 1] = strdup(name);
    numbers[i + 1] = strdup(number);

    people++;

    printf("%s %s was added successfully.\n", name, number);
}


// 이름 검색
int search(char *name) {

    for (int i = 0; i < people; i++) {

        if (strcmp(name, names[i]) == 0) {
            return i;
        }
    }

    return -1;
}


// 전화번호 찾기
void find(char *name) {

    int index = search(name);

    if (index == -1) {
        printf("No person named '%s' exists.\n", name);
    }
    else {
        printf("%s\n", numbers[index]);
    }
}


// 전체 연락처 출력
void status() {

    for (int i = 0; i < people; i++) {
        printf("%s %s\n", names[i], numbers[i]);
    }

    printf("Total %d persons.\n", people);
}


// 연락처 삭제
void remove(char *name) {

    int i = search(name);

    if (i == -1) {
        printf("No person named '%s' exists.\n", name);
        return;
    }

    // 삭제할 문자열의 메모리 해제
    free(names[i]);
    free(numbers[i]);

    // 뒤의 데이터를 한 칸씩 앞으로 이동
    for (int j = i; j < people - 1; j++) {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }

    people--;

    printf("'%s' was deleted successfully.\n", name);
}


// 파일에서 연락처 읽기
void load(char *fileName) {

    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }

    // 이름과 전화번호를 한 번에 읽기
    while (fscanf(fp, "%49s %49s", buf1, buf2) == 2) {
        add(buf1, buf2);
    }

    fclose(fp);
}


// 파일에 연락처 저장
void save(char *fileName) {

    FILE *fp = fopen(fileName, "w");

    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }

    for (int i = 0; i < people; i++) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }

    fclose(fp);
}


// 명령어 처리
void process_command() {

    char command_line[BUFFER_SIZE];

    char *command;
    char *argument1;
    char *argument2;

    while (1) {

        printf("$ ");

        // 한 줄 전체 입력
        if (read_line(command_line, BUFFER_SIZE) <= 0) {
            continue;
        }

        // 첫 번째 토큰 = 명령어
        command = strtok(command_line, delim);

        if (command == NULL) {
            continue;
        }


        // read
        if (strcmp(command, "read") == 0) {

            argument1 = strtok(NULL, delim);

            if (argument1 == NULL) {
                printf("File name required.\n");
                continue;
            }

            load(argument1);
        }


        // add
        else if (strcmp(command, "add") == 0) {

            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);

            if (argument1 == NULL || argument2 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }

            add(argument1, argument2);
        }


        // find
        else if (strcmp(command, "find") == 0) {

            argument1 = strtok(NULL, delim);

            if (argument1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }

            find(argument1);
        }


        // status
        else if (strcmp(command, "status") == 0) {

            status();
        }


        // delete
        else if (strcmp(command, "delete") == 0) {

            argument1 = strtok(NULL, delim);

            if (argument1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }

            remove(argument1);
        }


        // save
        else if (strcmp(command, "save") == 0) {

            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);

            if (argument1 == NULL ||
                strcmp("as", argument1) != 0 ||
                argument2 == NULL) {

                printf("Invalid command format.\n");
                continue;
            }

            save(argument2);
        }


        // exit
        else if (strcmp(command, "exit") == 0) {

            break;
        }


        // 존재하지 않는 명령
        else {
            printf("Unknown command.\n");
        }
    }
}