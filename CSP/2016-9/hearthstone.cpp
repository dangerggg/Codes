#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct minion{
    int attack, health;
    minion* next;
    minion(int _attack, int _health) : attack(_attack), health(_health) {}
} minion;

typedef struct player{
    minion *head;
    int minion_num;
    player() { head = NULL; minion_num = 0;}
    void summon(int pos, int attack, int health){
        ++minion_num;
        minion* new_minion = new minion(attack, health);
        if(head == NULL){
            head = new_minion;
            new_minion->next = NULL;
        }
        else{
            if(pos == 1){
                new_minion->next = head;
                head = new_minion;
                return;
            }
            minion *curNode = head, *tmp = head;
            while(pos-1 > 1 && curNode->next){
                --pos;        
                curNode = curNode->next;
            }
            tmp = curNode->next;
            curNode->next = new_minion;
            new_minion->next = tmp;
        }
    }
    void minion_dead(int pos){
        --minion_num;
        minion* curNode = head;
        if(pos == 1){
            head = head->next;
        }
        else{
            while(pos-1 > 1 && curNode->next ){
                --pos;
                curNode = curNode->next;
            }
            minion* tmp = curNode->next;
            curNode->next = tmp->next;
        }
    }
    minion* get_minion(int pos){
        minion* curNode = head;
        while(pos > 1 && curNode->next){
            --pos;
            curNode = curNode->next;
        }
        return curNode;
    }

} player;

void attack_ops(int defender, int enemy, player* defender_player, player* enemy_player){
    minion* attacker = defender_player->get_minion(defender);
    minion* attackee = enemy_player->get_minion(enemy);
    attacker->health -= attackee->attack;
    attackee->health -= attacker->attack;
    if(attacker->health <= 0) defender_player->minion_dead(defender);
    if(attackee->health <= 0) enemy_player->minion_dead(enemy);
}

int main(){
    int n = 0, pos = 0, attack = 0, health = 0, turn = 0;
    int attack_minion = 0, defender_minion = 0;
    int defender_health = 30, enemy_health = 30;
    char ops[7];
    player* defender = new player();
    player* enemy = new player();
    player* stoner[2]; stoner[0] = defender; stoner[1] = enemy;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", ops);
        if(strcmp(ops, "summon") == 0){
            scanf("%d%d%d", &pos, &attack, &health);
            stoner[turn]->summon(pos, attack, health);
        }
        else if(strcmp(ops, "attack") == 0){
            scanf("%d%d", &attack_minion, &defender_minion);
            if(defender_minion == 0){
                if(turn == 0){
                    enemy_health -= stoner[turn]->get_minion(attack_minion)->attack;
                }
                else{
                    defender_health -= stoner[turn]->get_minion(attack_minion)->attack;
                }
            }
            else{
                attack_ops(attack_minion, defender_minion, stoner[turn], stoner[(turn == 0 ? 1 : 0)]);
            }
        }
        else if(strcmp(ops, "end") == 0){
            turn = (turn == 0) ? 1 : 0; 
        }
    }
    if(defender_health <= 0) printf("%d\n", -1);
    else if(enemy_health <= 0) printf("%d\n", 1);
    else printf("%d\n", 0);
    printf("%d\n", defender_health);
    printf("%d ", defender->minion_num);
    minion *curNode = defender->head;
    while(curNode){
        printf("%d ", curNode->health);
        curNode = curNode->next;
    }
    putchar('\n');

    printf("%d\n", enemy_health);
    printf("%d ", enemy->minion_num);
    curNode = enemy->head;
    while(curNode){
        printf("%d ", curNode->health);
        curNode = curNode->next;
    }
    return 0;
}