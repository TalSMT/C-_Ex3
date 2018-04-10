#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Member{
    private:
        int numOfFollowers;
        int numOfFollowing;
        
        static int numOfMembers;
        
        vector <Member*> following;
        vector <Member*> followers;
        
        
    public:
        int numFollowers(){ return numOfFollowers; }
        int numFollowing(){ return numOfFollowing; }
        static int count(){ return numOfMembers; }
        
        void follow(Member& member);
        void unfollow(Member& member);
        void unfollow2(Member* member);
        bool compare(Member* a, Member* b);
        bool isFollowing(Member* member);
        bool isFollowedBy(Member* member);
        void tempUnfollow(Member* member);
        void unFollowAll();
        void deleteAllFollowers();
        void printFollowers();
        void printFollowing();
        Member();
        ~Member();

};

int Member::numOfMembers = 0;

void Member::follow(Member& member){
        if(!isFollowing(&member)&&(this != &member)){
            numOfFollowing++; 
            member.numOfFollowers++;
            following.push_back(&member);
            member.followers.push_back(this);
        }
    }
    
    void Member::unfollow(Member& member){
        if(isFollowing(&member)&&(this != &member)){
            numOfFollowing--; 
            (member).numOfFollowers--;
            tempUnfollow(&member);
        }
    }
    
    void Member::unfollow2(Member* member){
        if(isFollowing(member)&&(this != member)){
            numOfFollowing--; 
            member->numOfFollowers--;
            tempUnfollow(member);
        }
    }
    
    
    
    bool Member::compare(Member* a, Member* b){
        return a == b;
    }
    
    bool Member::isFollowing(Member* member){
        for (vector<Member*>::iterator it = following.begin(); it != following.end(); ++it){
            if(compare(*it, member)) return true;
        }
    }
    
    bool Member::isFollowedBy(Member* member){
        for (vector<Member*>::iterator it = followers.begin(); it != followers.end(); ++it){
            if(compare(*it, member)) return true;
        }
    }
    
    void Member::tempUnfollow(Member* member){
        for(vector<Member*>::iterator it = following.begin(); it != following.end(); ++it){
    		if(compare(*it, member)) {
    			it = following.erase(it);
    			return;
    		} 
        }
    }
    
    void Member::unFollowAll(){
        int N = following.size(); // number of members we are following
        for (int i = 0; i < N; i++) { 
            // cout << following.size() << endl;
            this->unfollow2(following[0]);
        }

    }
    
    void Member::deleteAllFollowers(){ // unfollowed all that were followed, used in destructor
        int N = followers.size(); // number of members we are following
        for (int i = 0; i < N; i++) { 
            // cout << followers.size() << endl;
            // printFollowers();
            followers[i]->unfollow2(this);
        }
    }
    
    void Member::printFollowers(){
        for (int i = 0; i < followers.size(); i++) { 
            cout << followers[i]->id << ' ';
        }
        cout << endl;
    }
    
    void Member::printFollowing(){
        for (int i = 0; i < following.size(); i++) { 
            cout << following[i]->id << ' ';
        }
        cout << endl;
    }
    
    Member::Member(){ 
        numOfFollowers = 0;
        numOfFollowing = 0;
        numOfMembers++;
    }
    
    Member::~Member(){
        unFollowAll();
        deleteAllFollowers();
        numOfMembers--;
    }
    
    


        
