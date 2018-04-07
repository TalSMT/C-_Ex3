#include <iostream>
using namespace std;

#include "Member.h"


Member avi, beni, chana;

void test1() {
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}

int main() {
	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;
	
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	test1();
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
	cout << Member::count() << endl; // 3
	
	// ///////////////////////////
	
	// beni.follow(avi);
	// chana.follow(avi);
	// yosi.follow(avi);
	// dani.follow(avi);
	// mendel.follow(avi);
	// elad.follow(avi);
	
	// beni.id = 0;
	// chana.id = 1;
	// yosi.id = 2;
	// dani.id = 3;
	// mendel.id = 4;
	// elad.id = 5;
	
	// // avi.follow(beni);
	// // avi.follow(chana);
	// // avi.follow(yosi);
	// // avi.follow(dani);
	// // avi.follow(mendel);
	// // avi.follow(elad);
	
	// cout << "Avi: " << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 3
	// cout << "Beni: " <<  beni.numFollowers() << " " << beni.numFollowing() << endl; // 0 0
	// cout << "Chana: " <<  chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 0
	// cout << "Yosi: " <<  yosi.numFollowers() << " " << yosi.numFollowing() << endl; // 0 0
	// cout << "Dani: " <<  dani.numFollowers() << " " << dani.numFollowing() << endl; // 0 0
	// cout << "Mendel: " <<  mendel.numFollowers() << " " << mendel.numFollowing() << endl; // 0 0
	// cout << "Elad: " <<  elad.numFollowers() << " " << elad.numFollowing() << endl; // 0 0
	// cout << endl;
	// avi.deleteAllFollowers();
	// //avi.unFollowAll();
	// cout << "Avi: " << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	// cout << "Beni: " <<  beni.numFollowers() << " " << beni.numFollowing() << endl; // 0 0
	// cout << "Chana: " <<  chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 0
	// cout << "Yosi: " <<  yosi.numFollowers() << " " << yosi.numFollowing() << endl; // 0 0
	// cout << "Dani: " <<  dani.numFollowers() << " " << dani.numFollowing() << endl; // 0 0
	// cout << "Mendel: " <<  mendel.numFollowers() << " " << mendel.numFollowing() << endl; // 0 0
	// cout << "Elad: " <<  elad.numFollowers() << " " << elad.numFollowing() << endl; // 0 0
	// cout << endl;
	
	// ///////////////////////////
	
}