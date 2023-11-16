#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main(){
 //Reading line from file
  string line;
  ifstream myfile ("know.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }
cout<<"\nAFTER READING LINE NOW WORDS"<<endl;
 //Reading words
 string k;
  ifstream myfile1 ("know.txt");
 while(!myfile1.eof()){
 	myfile1>>k;
 	cout<<k;
 	myfile1>>k;
 	cout<<k;
 	myfile1>>k;
 	cout<<k;
 	cout<<"\n\n";
}

//Writing file 
  fstream myfile12;
  myfile12.open("know.txt",ios::out);
  myfile12 << "Writing this is\n";
  myfile12 << "Writing this is\n";
  myfile12 << "Writing this is";
  myfile12.close();

// reading charactors

fstream new_file;
new_file.open("know.txt",ios::in);

char ch; 
while (!new_file.eof()) { 
ch=new_file.get();
cout << ch; 
}

//Append

    ofstream fout;  // Create Object of Ofstream
    ifstream fin;
    fin.open("a.txt");
    fout.open ("a.txt",ios::app); // Append mode
    if(fin.is_open())
        fout<< "\n Writing to a file opened from program.\n"; // Writing data to file
    cout<<"\n Data has been appended to file";
    fin.close();
    fout.close(); // Closing the file
    return 0;
    
}
