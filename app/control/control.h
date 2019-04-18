
#define SESSION_FILE "test/app/.session"
#define SCORE_FILE "test/app/db/scores/"

void filter_input(char*);


int login(char*, char*, int*);

int signup(char*, char*, int*); 

void disconnect(void);

int getConnectedPlayer(char*);

int playLevel(int);

int getScore(int*);