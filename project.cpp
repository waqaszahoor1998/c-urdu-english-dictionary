t#include <iostream>
#include <fstream>
#include <cstring>



using namespace std;

void create_para(){
	//file write operation
	char arr[1000];
	cout << "Enter Text in paragrapgh: " << endl;
	cin.getline(arr, 1000);
	ofstream myfile("para.txt",ios::trunc);
	cout<<endl;
	myfile << arr;
	myfile.close();	
		
}

int main()
{
	create_para();
//------------------------------------------------
    string file1, file2, file3;
    ifstream EngWords, UrduWords, my_file;

    file1="e_dictionary.txt" ;
    file2="u_dictionary.txt" ;
    file3="para.txt" ;
	my_file.open( file3.c_str(), ios::binary );
    EngWords.open( file1.c_str(), ios::binary ); //c_str() returns C-style string pointer
    UrduWords.open( file2.c_str(), ios::binary );

    if (!EngWords)
    {cout << "Couldn't open the file  " << file1<<endl;
    	return 0;
    }

    if (!UrduWords)
    {cout << "Couldn't open the file " << file2 << endl;
    	return 0;
    }


//----------------------------//

    string e_word[106], u_word[106], para_word[1000];
    int j = 0;
    
    while( my_file >> para_word[j] )
    {
        cout << para_word[j] << endl;
        j++;
    }
	if(EngWords.is_open())
    {
        for(int i = 0; i < 106; ++i)
        {
            EngWords >> e_word[i];
            UrduWords >> u_word[i];
        }
    }
     ofstream output("output.txt",std::ios::out | std::ios::app & std::ios::out | std::ios::trunc);
    bool check;
    for ( int i = 0 ; i < 1000 ; i++ ){
    	check = false;
    	for ( int j = 0 ; j < 106 ; j++ ){
    		if( para_word[i] == e_word[j] ){
    			output << u_word[j] << " ";
    			check = true;
    		}
		}
		if ( check == false )
			output << para_word[i] << " ";
	}
	
	output.close();

    return 0;
}
