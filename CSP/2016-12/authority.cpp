#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
typedef struct authority{
    string type;
    int level;
    authority(string _type, int _level) : level(_level) { type = _type; }
} authority;

typedef struct role{
    int num;
    authority* role_auth[15];
    int index;
    role(int _num) : num(_num), index(0) {}
    void add_auth(authority* new_auth){
        role_auth[index++] = new_auth;
    }
} role;

typedef struct user{
    int num;
    role* user_role[15];
    int index;
    user(int _num) : num(_num), index(0) {}
    void add_role(role* new_role){
        user_role[index++] = new_role;
    }
} user;

int main(){
    map<string, authority*> auth_map;
    map<string, role*> role_map;
    map<string, user*> user_map;
    int n = 0;
    char ops[40];
    string sep = ":";
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", ops);
        string s = ops;
        int pos = s.find(sep);
        if(pos == -1){
            authority* newAuth = new authority(s, -1);
            auth_map[s] = newAuth;
        }
        else{
            string sub = s.substr(0, pos);
            for(int j = 0; j <= s[pos+1]-'0'; ++j){
                authority* newAuth = new authority(sub, j);
                auth_map[sub+sep+to_string(j)] = newAuth;
            }
        }
    }
    scanf("%d", &n);
    int auths = 0;
    for(int i = 0; i < n; ++i){
        scanf("%s", ops);
        string s = ops;
        scanf("%d", &auths);
        role* newRole = new role(auths);
        role_map[s] = newRole;
        for(int j = 0; j < auths; ++j){
            scanf("%s", ops);
            string s = ops;
            newRole->add_auth(auth_map[s]);
        }
    }
    scanf("%d", &n);
    int roles = 0;
    for(int i = 0; i < n; ++i){
        scanf("%s", ops);
        string s = ops;
        scanf("%d", &roles);
        user* newUser = new user(roles);
        user_map[s] = newUser;
        for(int j = 0; j < roles; ++j){
            scanf("%s", ops);
            string s = ops;
            newUser->add_role(role_map[s]);
        }
    }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", ops);
        string q_user = ops;
        scanf("%s", ops);
        string q_auth = ops;
        int pos = q_auth.find(sep);
        
        if(user_map.count(q_user) == 0){
            printf("false\n");
        }
        else{
            user* query = user_map[q_user];
            if(pos == -1){
                int max = -1;
                for(int j = 0; j < query->index; ++j){
                    for(int k = 0; k < query->user_role[j]->index; ++k){
                        if(query->user_role[j]->role_auth[k]->type == q_auth){
                            if(query->user_role[j]->role_auth[k]->level == -1) max = -2;
                            else {
                                if(max < query->user_role[j]->role_auth[k]->level){
                                    max = query->user_role[j]->role_auth[k]->level;
                                }
                            }
                        }
                    }
                }
                if(max == -1) printf("false\n");
                else if(max == -2) printf("true\n");
                else printf("%d\n", max);
            }
            else{
                string sub = q_auth.substr(0, pos);
                int max = -1;
                for(int j = 0; j < query->index; ++j){
                    for(int k = 0; k < query->user_role[j]->index; ++k){
                        if(query->user_role[j]->role_auth[k]->type == sub){
                            if(max < query->user_role[j]->role_auth[k]->level){
                                max = query->user_role[j]->role_auth[k]->level;
                            }
                        }
                    }
                }
                if(max >= q_auth[pos+1]-'0') printf("true\n");
                else printf("false\n");
            }
        }
    }
    return 0;
}