#include <iostream>
#include <string>
#include <cstdlib>
#include <fileio.h>
#include "func.h"
using namespace std;

const string datapath = "";

int main(){
	mkdir(datapath+"data");
	createfile(datapath + "data/history.txt");
	int mm=0;
	while(mm != 4){
		system("cls");
		cout << "\n1.New Game\n2.View Match History\n3.Delete Match History\n4.Quit\n\nEnter an option: ";cin >> mm;
		switch(mm){
			case 1:
			{
				int mm1=0;
				while(mm1 != 3){
					system("cls");
					cout << "New Game\n\n1.Single Player\n2.Multiplayer\n3.Go back to main menu\n\nEnter an option: ";cin >> mm1;
					switch(mm1){
						case 1:
						{
							system("cls");
							int r,c;
							string p;
							cout << "\nEnter player name: ";cin.ignore(10,'\n');getline(cin,p);
							bool rematch = true;
							while(rematch){
								int mmat[3][3]={{0,0,0},{0,0,0},{0,0,0}};
								printmmat(mmat);
								for(int i=1;i<6;i++){
									
									decideX(mmat,i,r,c);
									
									mmat[r][c] = 1;
									printmmat(mmat);
									if(checkwin1(mmat)){
										cout << "\nComputer WINS!\n";
										appendfile(datapath + "data/history.txt","computer vs "+p+" - Winner Computer\n");
										break;
									}
									
									if(i==5){
										cout << "\nMATCH DRAW\n";
										appendfile(datapath + "data/history.txt","computer vs "+p+" - Match Draw"+"\n");
										break;
									}
									
									cout << p << " - Enter row,column : ";
									cin >> r; cin.ignore(10,','); cin >> c;
									while((r<1)or(r>3)or(c<1)or(c>3)or(mmat[r-1][c-1] != 0)){
										cout << "\nERROR: Invalid Input , Try Again" << endl;
										cout << p << " - Enter row,column : ";
										cin >> r; cin.ignore(10,','); cin >> c;
									}
									mmat[r-1][c-1] = 2;
									printmmat(mmat);
									if(checkwin2(mmat)){
										cout << "\n" <<  p << " WINS!\n";
										appendfile(datapath + "data/history.txt","computer vs "+p+" - Winner "+p+"\n");
										break;
									}
								}
								cout << "\nPlay another match? (y/n) : ";
								char ch;
								cin >> ch;
								if((ch == 'y')or(ch == 'Y')){rematch = true;}
								else {rematch = false;}
							}
							break;
						}
						case 2:
						{
							system("cls");
							int r,c;
							string p1,p2;
							cout << "\nEnter player 1 name: ";cin.ignore(10,'\n');getline(cin,p1); 
							cout << "\nEnter player 2 name: ";getline(cin,p2);
							bool rematch = true;
							while(rematch){
								int mmat[3][3]={{0,0,0},{0,0,0},{0,0,0}};
								printmmat(mmat);
								for(int i=1;i<6;i++){
									cout << p1 << " - Enter row,column : ";
									cin >> r; cin.ignore(10,','); cin >> c;
									while((r<1)or(r>3)or(c<1)or(c>3)or(mmat[r-1][c-1] != 0)){
										cout << "\nERROR: Invalid Input , Try Again" << endl;
										cout << p1 << " - Enter row,column : ";
										cin >> r; cin.ignore(10,','); cin >> c;
									}
									mmat[r-1][c-1] = 1;
									printmmat(mmat);
									if(checkwin1(mmat)){
										cout << "\n" <<  p1 << " WINS!\n";
										appendfile(datapath + "data/history.txt",p1+" vs "+p2+" - Winner "+p1+"\n");
										break;
									}
									
									if(i==5){
										cout << "\nMATCH DRAW\n";
										appendfile(datapath + "data/history.txt",p1+" vs "+p2+" - Match Draw"+"\n");
										break;
									}
									
									cout << p2 << " - Enter row,column : ";
									cin >> r; cin.ignore(10,','); cin >> c;
									while((r<1)or(r>3)or(c<1)or(c>3)or(mmat[r-1][c-1] != 0)){
										cout << "\nERROR: Invalid Input , Try Again" << endl;
										cout << p2 << " - Enter row,column : ";
										cin >> r; cin.ignore(10,','); cin >> c;
									}
									mmat[r-1][c-1] = 2;
									printmmat(mmat);
									if(checkwin2(mmat)){
										cout << "\n" <<  p2 << " WINS!\n";
										appendfile(datapath + "data/history.txt",p1+" vs "+p2+" - Winner "+p2);
										break;
									}
								}
								cout << "\nPlay another match? (y/n) : ";
								char ch;
								cin >> ch;
								if((ch == 'y')or(ch == 'Y')){rematch = true;}
								else {rematch = false;}
							}
							break;
						}
					}
				}
				break;
			}
			case 2:
			{
				system("cls");
				cout << endl;
				printfile(datapath + "data/history.txt");
				cout << "\n" << endl;
				system("pause");
				break;
			}
			case 3:
			{
				char ch;
				system("cls");
				cout << endl;
				cout << "All Match History Details Will Be Deleted\n CONFIRM (y/n): "; cin >> ch;
				if ((ch == 'y')or(ch == 'Y')){
					writefile(datapath + "data/history.txt");
					cout << "\nMatch History Details Deleted!\n\n";
					system("pause");
				}
			}
		}
	}
	system("cls");
	return 0;
}
