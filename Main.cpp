#include "Member.h"
#include <iostream>

using namespace std;

int Member::numOfMembers = 0;


int main(){
    
    Member dana, avi, bob, alice;
    cout << "bob.numFollowers() : " << bob.numFollowers() << endl;
    cout << "dana.numFollowers() : " << dana.numFollowers() << endl;
    cout << "avi.numFollowing() : " << avi.numFollowing() << "\n" << endl;
    
    avi.follow(&dana);
    avi.follow(&bob);
    cout << "bob.numFollowers() : " << bob.numFollowers() << endl;
    cout << "dana.numFollowers() : " << dana.numFollowers() << endl;
    cout << "avi.numFollowing() : " << avi.numFollowing() << "\n" << endl;
    
    avi.unfollow(&dana);
    cout << "bob.numFollowers() : " << bob.numFollowers() << endl;
    cout << "dana.numFollowers() : " << dana.numFollowers() << endl;
    cout << "avi.numFollowing() : " << avi.numFollowing() << "\n" << endl;
    
    cout << "count() : " << Member::count() << endl;
    
    return 0;
}