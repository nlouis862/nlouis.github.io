/** Author: Ntripang Louis, nlouis862@gmail.com, +237677311281, (twitter) -> @nlouis862
 * Date: 09/03/2018, 8:17:45 PM.
 * Location: In Bedroom.
 * 
 * ------------- -------------  (c)Copyright -------------  ------------- 
 * This piece of code is all reserved and owned by MENDASOFT LTD. 
 * Any copy and/or redistribution must obtain permission from MENDASOFT LTD,
 * Otherwise willingfully gifted by MENDASOFT LTD as a coperative
 * or from any of its affiliates, board members or certified employees.
 * 
 * ------------- -------------  BUGS -------------  ---------------------
 * Though is code produces the desired end results, some cases will crash the
 * program e.g if the user includes a space or a Tab, it will be ignored and 
 * the character after it will also be ignored.
 * 
 * If the bug is solved, it will be very welcoming as it will permit the 
 * encryption of large text files.
 * 
 * ------ -------------  Improvement -------------  --------------
 * The bug above should be solved, and the events of repeated words should also be solved
 * i.e if a word like Hello is entered, it shouldn't produce ifmmp, with repeated m
 * but rather finds another character to replace the next m..... 
 * 
 * 
 * The characters in the arr_list has been intensionally scrambled for a better encryption
 * 
 * 
 * ------ -------------  Summary -------------  --------------
 * The decryption engine is just the reverse of the encryptio. 
 * If any thing is changed in the encryption, then it should also 
 * be the case with the decryption....
 * */


#include <iostream>
#include <string>

using namespace std;

void encrypt(int wordSize, string word, const char arr_list[], int sizeof_arr_list, char arr_new_word[], bool Err);
void decrypt(int wordSize, string word, const char arr_list[], int sizeof_arr_list, char arr_new_word[], bool Err);

int main(){
	int action;
	cout << "Enter 1 for encryption and 2 for decryption \n";
	cin >> action;
	bool Err = false;
	const char arr_list[26*2+42] = { '\\', 'V', '@', '~', '{', '|', '9', '%', ',', 'j', '?', '=', ']', 'm', 'e', '(', '}', 'r', 's', '4', 'u', 'v', 'w', 'x', 'y', 'z',
		                             '>', 'B', 'g', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '/', 'L', '[', 'N', '+', 'P', '&', '#', 'S', 'T', 'U', 'b', 'W', 'X', 'Y', 'Z',
		                             '!', 'd', 'c', 'R', '$', 'h', '^', 'Q', 'n', 'p', ')', '_', '-', 'O', 'l', '`', '8', '2', '0', 't', '5', 'C', '7', '1', '6', '3', 
		                             'a', '\'', 'f', '"', ':', ';', '<', 'A', 'i', '.', 'k', 'K', 'M', '*', 'o', 'q' };
	int sizeof_arr_list = sizeof(arr_list)/sizeof(arr_list[0]);
	string word;
	cout << "Enter a word \n";
	cin >> word;
	int wordSize = word.size();
	char arr_new_word[wordSize];
	
	if(action == 1){
		encrypt(wordSize, word, arr_list, sizeof_arr_list, arr_new_word, Err);
	}else{decrypt(wordSize, word, arr_list, sizeof_arr_list, arr_new_word, Err);}
	
	return 0;
	}
	
	
	
	// Start of encryption engine....
	void encrypt(int wordSize, string word, const char arr_list[], int sizeof_arr_list, char arr_new_word[], bool Err){
		int strCount, searchIndex = 0;
		
		for(strCount = 0; strCount < wordSize; strCount++){
			char search = word[strCount];
			for(searchIndex = 0; searchIndex < sizeof_arr_list; searchIndex++){
				char pos = arr_list[searchIndex];
				if(search == pos){
					if(search != 'q'){arr_new_word[strCount] = arr_list[searchIndex+1];}else{
						arr_new_word[strCount] = ' ';
						}
				}
					else{
						if(searchIndex >= sizeof_arr_list){
							Err = true;
						}
					}
			}
		}
			if(Err == true){
				cout << "\n The search went out of bounds \n";
			}else{
					cout << "Encryption of \"" << word << "\" is \t" <<  arr_new_word;
				}
	}//... End of encryption engine
	
	
	
	// Start of decryption engine....
	void decrypt(int wordSize, string word, const char arr_list[], int sizeof_arr_list, char arr_new_word[], bool Err){
		int strCount, searchIndex = 0;
		
		for(strCount = 0; strCount < wordSize; strCount++){
			char search = word[strCount];
			for(searchIndex = 0; searchIndex < sizeof_arr_list; searchIndex++){
				char pos = arr_list[searchIndex];
				if(search == pos){
					arr_new_word[strCount] = arr_list[searchIndex-1];
				}
					else{
						if(searchIndex >= sizeof_arr_list){
							Err = true;
						}
					}
			}
		}
			if(Err == true){
				cout << "\n The search went out of bounds \n";
			}else{
					cout << "Decryption of \"" << word << "\" is \t" << arr_new_word;
				}
	}//... End of decryption engine

