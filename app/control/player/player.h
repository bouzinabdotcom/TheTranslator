
#define PLAYER_DB "./test/app/db/players"

int PlayerNum ;

typedef struct {
    int id;
    char name[20];
    char password[20];
}Player;



Player* getPlayers(void);

int findPlayer(char*, Player*, Player*);

int createPlayer(char*, char*);


