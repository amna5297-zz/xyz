#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

char* word_array = new char[26]();


class Dictionary{
	/*struct Tier{
		char character;
		bool word;
		Tier* char_Next;
		Tier* parent;
		Tier* neighbors;
	};
	Tier* tier_root;
	struct Alphabets{
		char alpha;
		Alphabets* alpha_Next;
		Tier* tier_Next;
	};
	Alphabets* alpha_root;*/
	struct Node{
		string word;
		Node* next;
	};
	Node* root;
public:
	Dictionary(){
		//tier_root = NULL;
		//alpha_root = NULL;
		root = NULL;
	};

	void insertion(char word_array1[]);
	//void insertionTier(Alphabets* alpha_newNode,char word_array1[]);
	bool searchDictionary(char temp[]);

};


bool Dictionary :: searchDictionary (char temp[]){
	//cout<<"Dictionary Search Function"<<endl;
	string w(temp);

	Node* node_ptr;
	node_ptr = new Node;

	bool flag = false;

	node_ptr = root;

	if(root == NULL){
		//word not found
		flag = false;
	}
	else{
		node_ptr = root;
		cout<<node_ptr->next->word<<endl;
		while(node_ptr!=NULL){
			if(node_ptr->word == w){
				flag = true;
				return flag;
			}
			else{
				node_ptr = node_ptr->next;
			}
		}
	}
	return flag;

};



void Dictionary :: insertion( char word_array1[]){

	string w(word_array1);

	Node* newNode;
	newNode = new Node;

	newNode->word = w;
	newNode->next = NULL;

	bool flag = true;

	Node* node_ptr;
	node_ptr = new Node;

	Node* prev_ptr;
	prev_ptr = new Node;

	/*Alphabets* alpha_newNode;
	alpha_newNode = new Alphabets;
	bool flag = true;
	Alphabets* node_ptr = NULL;
	Alphabets* prev_ptr = NULL;

	alpha_newNode->alpha = word_array1[0];
	alpha_newNode->alpha_Next = NULL;
	alpha_newNode->tier_Next = NULL;

	Tier* tier_newNode;
	tier_newNode = new Tier;
	tier_newNode->char_Next = NULL;
*/

	int i = 0;

	


	//cout<<alpha_newNode->alpha<<endl;

	if(root == NULL){
		root = newNode;
		//alpha_root->alpha_Next = NULL;
		//cout<<"root\t"<<alpha_newNode->alpha<<endl;
		flag = false;
	}
	else{
		node_ptr = root;
		prev_ptr = node_ptr;
		//CHECK IF THE ALPHABET EXITS
		while((node_ptr != NULL ) && (flag == true)){			
			if(node_ptr->word == newNode->word){
				//cout<<"Same word found!"<<endl;
				flag = false;
			}
			else{
				//cout<<"Word Insert!"<<endl;
				prev_ptr = node_ptr;
				node_ptr = node_ptr->next;
			}			
		}
	}
};






/*
void Dictionary :: insertion( char word_array1[]){
	Alphabets* alpha_newNode;
	alpha_newNode = new Alphabets;
	bool flag = true;
	Alphabets* node_ptr = NULL;
	Alphabets* prev_ptr = NULL;

	alpha_newNode->alpha = word_array1[0];
	alpha_newNode->alpha_Next = NULL;
	alpha_newNode->tier_Next = NULL;

	Tier* tier_newNode;
	tier_newNode = new Tier;
	tier_newNode->char_Next = NULL;


	int i = 0;

	


	//cout<<alpha_newNode->alpha<<endl;

	if(alpha_root == NULL){
		alpha_root = alpha_newNode;
		//alpha_root->alpha_Next = NULL;
		//cout<<"root\t"<<alpha_newNode->alpha<<endl;
		flag = false;
	}
	else{
		node_ptr = alpha_root;
		prev_ptr = node_ptr;
		//CHECK IF THE ALPHABET EXITS
		while((node_ptr != NULL) && (flag == true)){			
			if(node_ptr->alpha == alpha_newNode->alpha){
				//cout<<"Same Alpha found!"<<endl;
				flag = false;
			}
			else{
				prev_ptr = node_ptr;
				node_ptr = node_ptr->alpha_Next;
			}			
		}
		
		if(node_ptr == NULL && flag == true){
			//cout<<"Unique Alpha:   "<<alpha_newNode->alpha<<endl;
			prev_ptr->alpha_Next = alpha_newNode;
			insertionTier(alpha_newNode,word_array1);

		}
		else{	
			insertionTier(alpha_newNode,word_array1);				
		}
	}
};

*/



/*
void Dictionary :: insertionTier(Alphabets* alpha_newNode, char word_array1[]){
	Tier* temp;
	temp = new Tier;
	
		
	temp = alpha_newNode->tier_Next;  //At Alphabet

	int i = 1;

	while(word_array1[i] != NULL){
		// When there is no char at tier level i
		Tier* newNode;
		newNode = new Tier;
		newNode->neighbors = NULL;
		newNode->parent = NULL;
		newNode->character = word_array1[i];

		if(temp == NULL){
			cout<<"Tier next char added: "<<temp->character<<endl;
			temp = newNode;
			temp->neighbors = NULL;
			i++;
		}

		else if(temp != NULL){		

			if(temp->character == word_array1[i]){
				
			}
			else if (temp->character != word_array1[i]){
				Tier* temp2;
				temp2 = new Tier;

				temp2 = temp->neighbors;

				if(temp->neighbors == NULL){
					temp->neighbors = newNode;
					cout<<"Tier next neigbour added: "<<temp->character<<endl;
				}
				else{
					while(temp->neighbors->character != word_array1[i] && temp->neighbors != NULL){
						temp = temp->neighbors;
					}

					if(temp->neighbors == NULL){
						cout<<"Tier next neigbour NULL: "<<temp->character<<endl;
						temp->neighbors = newNode;
					}
					else if(temp->neighbors->character == word_array1[i]){

					}
				}			
			}
		}
		temp = temp->char_Next;
	}
}


*/


class wordLadder{
	string word;
public:
	
	wordLadder(){
		word = '\0';
	};
	void search(char source[], char destination[]){

		cout<<"Word ladder Search Function"<<endl;

		Dictionary w;

		char* temp = new char[26]();
		for(int i = 0;i<27;i++){
			temp[i]='\0';
		}


		temp = source;

		int i = 0;

		if( w.searchDictionary(temp) == true ){
			cout << "Word exists:  "<<endl;
		}

		while(temp != NULL && temp != destination){
			if( w.searchDictionary(temp) == true ){
				cout << "Word exists:  "<<endl;
				temp[i] = destination [i];
				i = 0;
			}
			else{
				i++;			
			}
		}
	};
};







void main(){

	//_________________________________________________________________//
	//					Dictionary Variables						   //
	//_________________________________________________________________//
	string word,meaning,line,extra_char;
	int i=0;
	string word_encapsulation = "\":";
	string meaning_encapsulation = ".\",";
	char dot = '.';
	char comma = ',';
	char quote = '"';
	char colon = ':';
	char closing_bracket=']';
	char closing_braces = ')';
	char semi_colon = ';';
	char escalamation = '!';
	char dash = '-';
	int numberOfWords = 0;

	string source,destination;

	Dictionary d;
	wordLadder W;


	for(int i = 0;i<27;i++){
		word_array[i]='\0';
	}

	//****** PARSING FROM JSON FILE ********//

	//		Getting all the characters	from Dictionary	//
	
	fstream myFile;
	myFile.open("Dictionary.json");

	if(myFile.is_open()){
		getline(myFile,word,'{');
		while(getline(myFile,line)){
			int j = 0;
			for(int i = 0; i<line.length(); i++) {

				/*if(line[i] == dot && line[i+1] == quote && line[i+2] == comma){
					j++;
					cout<<"\n"<<j<<"   "<<endl;
				}*/
				if( line[i] == comma && line[i-1] == quote && (line[i-2] == dot || line[i-2] == closing_bracket || line[i-2] == closing_braces || line[i-2] == semi_colon || line[i-2] == comma || line[i-2] == escalamation || line[i-2] == dash )){
					//End of word
					i++;
					int k = i+1;
					int l = 0;
					while(line[k+1] != colon && line[k] != quote){
						word_array[l] = line[k];
						l++;
						k++;
					}
					for (int j=0; j<26;j++){
						//cout<<word_array[j];
					}
					//cout<<word_array<<endl;
					
					d.insertion(word_array);
					numberOfWords++;
				

					//***** SAVE WORD_ARRAY IN DATA STRUCTURE *****//

					for(int i = 0;i<27;i++){
						word_array[i]='\0';
					}
					i--;
				}
				//else if(line[i+1] == comma && line[i] == quote && line[i+1] == dot){
				//	//cout<<line[i+1];
				//}
				else{
					//cout<<line[i];
					//cout<<endl;
				}
			}
			
		}
		//	getline(myFile,line);
		//	/*getline(myFile,word,':');
		//	getline(myFile,meaning,'.');
		//	getline(myFile,meaning,',');
		//	cout<<i<<"           "<<word<<endl;*/

		//	i++;
		//}
	
		//myFile.close();

		cout<<"Words added from Dictionary\n\n"<<endl;

		//********************    GET SOURCE AND DESTINATION FROM USER   **********************************//
		cout<<"Please Enter Source Word:  ";
		cin>>source;
		cout<<"\nPlease Enter Destination Word:  ";
		cin>>destination;
		cout<<endl;
		cout<<endl;
		cout<<endl;

		std::string s = source;
		std::string d = destination;

		
		char *cstr = new char[s.length() + 1];
		strcpy(cstr, s.c_str());

		
		char *dstr = new char[d.length() + 1];
		strcpy(dstr, d.c_str());


		// do stuff
		W.search(cstr,dstr);
		delete [] cstr;

		cout<<"END OF PROGRAM"<<endl;
	
	}
	else{
		cout << "Unable to open file"<<endl;
	}

	cout<<numberOfWords<<endl;

	cout<<"END OF PROGRAM"<<endl;
	int mainExit;
	cin >> mainExit;
	
}