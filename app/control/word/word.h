#define MAX_WORDS 10


typedef struct {
    char fr[20];
    char en[20];
} Word;
 
char* getLevelPath(int);
Word* loadLevel(int);
char** loadWords(int);
int verifyAnswer(int, char*, char*);
