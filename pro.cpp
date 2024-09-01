#include<bits/stdc++.h>
#include<fstream>

using namespace std;

class BinTreeElemType {
	public:
	int id;
	int recNo;
};

class Node {
	public:
	BinTreeElemType data;
	Node *lChild, *rChild;
};

enum boolean{ FALSE, TRUE };

class Student {
	public:
	int id;
	char lastName[20];
	char firstName[20];
	char gender;
	char cohort[10];
	int year;
	float grade;
};

void menu(int &option){
	cout << "\n                   Choose One Option               \n";
	cout << "*******************************************************\n";
	cout << "1. Search for a student \n";
	cout << "2. Insert a new student \n";
	cout << "3. Print students having grade >= given grade\n";
	cout << "4. Print students having grade <= given grade\n";
	cout << "5. Print students having grade == given grade\n";
	cout << "6. Print all students (Traverse --> Inorder)\n";
	cout << "7. Print all students (Traverse --> preorder)\n";
	cout << "8. Print all students (Traverse --> postorder)\n";
	cout << "9. Quit\n ";
	cout << "\n Option : ";
	
	// Enter the option no. which is in range of 1 to 8 only
	do {
		cin >> option;
		cin.ignore();	
	} while(option<1||option>9);
}

void createBST(Node* &root){
	root = nullptr;
}

bool isEmpty(Node* &root){
	return root==nullptr;
}

void insert(Node* &root, BinTreeElemType item){
	if(isEmpty(root)){
		root = new Node;
		root->data.id = item.id;
		root->data.recNo = item.recNo;
		root->lChild = nullptr;
		root->rChild = nullptr;
	}
	else{
		if(item.id < root->data.id){
			insert(root->lChild,item);
		}
		else if(item.id > root->data.id){
			insert(root->rChild,item);
		}
		else{
			cout << "Another student is already present with this id.\n";
			return;
		}
	}
}

void search(Node* &root, BinTreeElemType key, boolean &found, Node* &ptr){
	if(isEmpty(root)){
		found = FALSE;
	}
	else{
		if(key.id < root->data.id){
			search(root->lChild,key,found,ptr);
		}
		else if(key.id > root->data.id){
			search(root->rChild,key,found,ptr);
		}
		else{
			found = TRUE;
			ptr = root;
		}
	}
}

void inorder(Node* &root){
	if(root != nullptr){
		inorder(root->lChild);
		cout << "(" << root->data.id << " , " << root->data.recNo << ")";
		inorder(root->rChild);
	}
}

void preorder(Node* &root){
	if(root != nullptr){
		inorder(root->lChild);
		inorder(root->rChild);
		cout << "(" << root->data.id << " , " << root->data.recNo << ")";
	}
}

void postorder(Node* &root){
	if(root != nullptr){
		cout << "(" << root->data.id << " , " << root->data.recNo << ")";
		inorder(root->lChild);
		inorder(root->rChild);
	}
}

// This function will read all the data from the file and create a bst
int buildBST(Node* &root){
	ifstream infile;
	Student stud;
	BinTreeElemType indexRec;
	int size=0;
	
	createBST(root);
	
	infile.open("sample.data");
	if(!(infile)){
		cout << "can't open sample.data\n";
		exit(1);
		// exit the code
	}
	else{
		while(true){
			infile >> stud.id;
			infile.ignore(1); //ignores only one character
			infile.getline(stud.lastName, 20, ',');
			infile.getline(stud.firstName, 20, ',');
			infile >> stud.gender;
			infile.ignore(1);
			infile.getline(stud.cohort, 10, ',');
			infile >> stud.year;
			infile.ignore(1);
			infile >> stud.grade;
			infile.ignore();
			
			if(infile.eof()){
				// All records updated
				break;
			}
			
			indexRec.id = stud.id;
			indexRec.recNo = size; //Insert new student at the last position
			
			insert(root,indexRec);
			size++;
		}
	}
	infile.close();
	
	return size;
}

void printStudent(int recNo){
	ifstream infile;
	int noOfLines=0;
	Student stud;
	infile.open("sample.data");
	if(!(infile)){
		cout << "can't open sample.data\n";
	}
	else{
		while(noOfLines <= recNo){
			infile >> stud.id;
			infile.ignore(1); //ignores only one character
			infile.getline(stud.lastName, 20, ',');
			infile.getline(stud.firstName, 20, ',');
			infile >> stud.gender;
			infile.ignore(1);
			infile.getline(stud.cohort, 10, ',');
			infile >> stud.year;
			infile.ignore(1);
			infile >> stud.grade;
			infile.ignore();
			
			if(infile.eof()){
				// All records updated
				break;
			}
			noOfLines++;
		}
		if(noOfLines != recNo){
			cout << stud.id << "," << stud.firstName << "," << stud.lastName << "," << stud.gender <<
			"," << stud.cohort << "," << stud.year << "," << stud.grade << "\n";
		}
	}
	infile.close();
}

void greaterGrade(){
	ifstream infile;
	Student stud;
	float value;
	cout << "Give the grade: ";
	cin >> value;
	cin.ignore();
	//Only positive grades will be accepted
	while(value<0){
		cout << "Grade can't be a negative number.\n";
		cout << "Give the grade: ";
		cin >> value;
		cin.ignore();
	}
	infile.open("sample.data");
	if(!(infile)){
		cout << "can't open sample.data\n";
		exit(1);
		// exit the code
	}
	else{
		int flag=0;
		while(true){
			infile >> stud.id;
			infile.ignore(1); //ignores only one character
			infile.getline(stud.lastName, 20, ',');
			infile.getline(stud.firstName, 20, ',');
			infile >> stud.gender;
			infile.ignore(1);
			infile.getline(stud.cohort, 10, ',');
			infile >> stud.year;
			infile.ignore(1);
			infile >> stud.grade;
			infile.ignore();
			
			if(infile.eof()){
				// All records updated
				break;
			}
			
			if(stud.grade >= value){
				flag=1;
				cout << stud.id << "," << stud.firstName << "," << stud.lastName << "," << stud.gender <<
				"," << stud.cohort << "," << stud.year << "," << stud.grade << "\n";
			}
		}
		if(flag==0){
			cout << "No students are there with such conditions.";
		}
	}
	infile.close();
}

void lesserGrade(){
	ifstream infile;
	Student stud;
	float value;
	cout << "Give the grade: ";
	cin >> value;
	cin.ignore();
	//Only positive grades will be accepted
	while(value<0){
		cout << "Grade can't be a negative number.\n";
		cout << "Give the grade: ";
		cin >> value;
		cin.ignore();
	}
	infile.open("sample.data");
	if(!(infile)){
		cout << "can't open sample.data\n";
		exit(1);
		// exit the code
	}
	else{
		int flag=0;
		while(true){
			infile >> stud.id;
			infile.ignore(1); //ignores only one character
			infile.getline(stud.lastName, 20, ',');
			infile.getline(stud.firstName, 20, ',');
			infile >> stud.gender;
			infile.ignore(1);
			infile.getline(stud.cohort, 10, ',');
			infile >> stud.year;
			infile.ignore(1);
			infile >> stud.grade;
			infile.ignore();
			
			if(infile.eof()){
				// All records updated
				break;
			}
			
			if(stud.grade <= value){
				flag=1;
				cout << stud.id << "," << stud.firstName << "," << stud.lastName << "," << stud.gender <<
				"," << stud.cohort << "," << stud.year << "," << stud.grade << "\n";
			}
		}
		if(flag==0){
			cout << "No students are there with such conditions.";
		}
	}
	infile.close();
}

void equalGrade(){
	ifstream infile;
	Student stud;
	float value;
	cout << "Give the grade: ";
	cin >> value;
	cin.ignore();
	//Only positive grades will be accepted
	while(value<0){
		cout << "Grade can't be a negative number.\n";
		cout << "Give the grade: ";
		cin >> value;
		cin.ignore();
	}
	infile.open("sample.data");
	if(!(infile)){
		cout << "can't open sample.data\n";
		exit(1);
		// exit the code
	}
	else{
		int flag=0;
		while(true){
			infile >> stud.id;
			infile.ignore(1); //ignores only one character
			infile.getline(stud.lastName, 20, ',');
			infile.getline(stud.firstName, 20, ',');
			infile >> stud.gender;
			infile.ignore(1);
			infile.getline(stud.cohort, 10, ',');
			infile >> stud.year;
			infile.ignore(1);
			infile >> stud.grade;
			infile.ignore();
			
			if(infile.eof()){
				// All records updated
				break;
			}
			
			if(stud.grade == value){
				flag=1;
				cout << stud.id << "," << stud.firstName << "," << stud.lastName << "," << stud.gender <<
				"," << stud.cohort << "," << stud.year << "," << stud.grade << "\n";
			}
		}
		if(flag==0){
			cout << "No students are there with such conditions.";
		}
	}
	infile.close();
}

//---------------------------------------------------------------------------------------------------------------------------//

int main(){
	ifstream infile;
	ofstream outfile;
	boolean found;
	Node* root;
	Node* ptr;
	int option, size;
	BinTreeElemType indexRec;
	Student stud;
	
	size = buildBST(root);
	
	do {
		menu(option);
		
		//Search a students on the basis of ID
		if(option == 1){
			cout << "Give student's ID: ";
			cin >> stud.id;
			indexRec.id = stud.id;
			search(root, indexRec, found, ptr);
			if(found == TRUE){
				indexRec.recNo = ptr->data.recNo;
				printStudent(indexRec.recNo);
			}
			else{
				cout << "There is no students with this ID.\n";
			}
		}
		
		//Insert a new Student in the data
		if(option == 2){
			outfile.open("sample.data", ios::app);
			if(!(outfile)){
				cout << "Can't open sample.data\n";
				exit(1);
			}
			else{
				cout << "Give student's ID: ";
				cin >> stud.id;
				cin.ignore();
				while(stud.id < 0){
					cout << "ID can't be negative number.\n";
					cout << "Give student's ID: ";
					cin >> stud.id;
					cin.ignore(); 
				}
				indexRec.id = stud.id;
				search(root, indexRec, found, ptr);
				if(found == FALSE){
					
					//Last Name
					cout << "Give Student's lastName: ";
					cin.getline(stud.lastName, 20);
					
					//First Name
					cout << "Give Student's firstName: ";
					cin.getline(stud.firstName, 20);
					
					//Gender
					cout << "Give student's gender M/F: ";
					cin >> stud.gender;
					cin.ignore();
					while(stud.gender!='F' && stud.gender!='M'){
						cout << "Give the gender in form of M or F.\n";
						cout << "Give student's gender M/F: ";
						cin >> stud.gender;
						cin.ignore();	
					}
					
					//Cohort
					cout << "Give Student's cohort: ";
					cin.getline(stud.cohort, 10);
					
					//Year
					cout << "Give student's registration year: ";
					cin >> stud.year;
					cin.ignore();
					
					//Grade 
					cout << "Give student's grade (0-100): ";
					cin >> stud.grade;
					cin.ignore();
					while(stud.grade<0 && stud.grade>100){
						cout << "Give the grade in range from 0 to 100.\n";
						cout << "Give student's grade (0-100): ";
						cin >> stud.grade;
						cin.ignore();	
					}
					
					cout << "\nSize = " << size << "\n";
					indexRec.recNo = size;
					insert(root,indexRec);
					outfile << stud.id << "," << stud.firstName << "," << stud.lastName << "," << stud.gender 
						    << "," << stud.cohort << "," << stud.year << "," << stud.grade << "\n";
						    
					size++;
					outfile.close();	    
				}
				else{
					cout << "A student with same ID already exists in the data.\n";
				}
			}
		}
		
		//Print all the students having grade >= given grade
		if(option == 3){
			cout << "Print all the students having grade >= given grade: \n";
			greaterGrade();
		}	
		
		//Print all the students having grade <= given grade
		if(option == 4){
			cout << "Print all the students having grade <= given grade: \n";
			lesserGrade();
		}
		
		//Print all the students having grade == given grade
		if(option == 5){
			cout << "Print all the students having grade == given grade: \n";
			equalGrade();
		}
		
		//Print all the students (Inorder --> Traversal)
		if(option == 6){
			cout << "Print all the students in Inorder Traversal : (ID (ascending order), Number of record): \n";
			inorder(root);
			cout << "\n";
		}
		
		//Print all the students (Preorder --> Traversal)
		if(option == 7){
			cout << "Print all the students in Preorder Traversal : (ID (ascending order), Number of record): \n";
			preorder(root);
			cout << "\n";
		}
		
		//Print all the students (Postorder --> Traversal)
		if(option == 8){
			cout << "Print all the students in Postorder Traversal : (ID (ascending order), Number of record): \n";
			postorder(root);
			cout << "\n";
		}

	} while(option != 9);
	
	return 0;
}