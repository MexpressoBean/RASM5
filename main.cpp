/************************************************
 * Name : Kevin Ramirez
 * Class: CS3B
 * Date : 5/22/19
 * Lab  : RASM5
 ************************************************/
#include <iostream>
#include <fstream>
#include <ctime>  
#include <time.h>
#include <stdio.h>
  
extern "C" void bubbleSort(int A[], int cnt, bool asc);
using namespace std;

// Global Constants
const int AR_SIZE = 200000;

// Function prototypes
int *getRandom(int r[AR_SIZE]);
void printArToFile(int ar[AR_SIZE]); 
void loadInputFileInAr(int ar[AR_SIZE]);
void BubbleSort (int a[], int length);


// Main Function
int main()
{
    time_t start;
    time_t end;
    ofstream fout;
    int cSeconds         = 0;
    int armSeconds       = 0;
    int menuChoice       = 0;
    int randomNumb       = 0; 
    int cList[AR_SIZE]   = {0};
    int armList[AR_SIZE] = {0};


    cout << "-------------------------------------------------------\n";
    cout << "              RASM5:  C vs Assembly\n";
    cout << "-------------------------------------------------------\n";
    cout << " C        Bubblesort Time: " << cSeconds   << " secs   \n";
    cout << " Assembly Bubblesort Time: " << armSeconds << " secs   \n";
    cout << "-------------------------------------------------------\n";
    cout << "<1> Load input file (integers)              \n";
    cout << "<2> Sort using C Bubblesort algorithm       \n";
    cout << "<3> Sort using Assembly Bubblesort algorithm\n";
    cout << "<4> Quit                                    \n";

    cout << "\n\nPlease enter choice: ";
    cin  >> menuChoice;


    switch(menuChoice)
    {
        case 1: 
            loadInputFileInAr(cList);
            loadInputFileInAr(armList);
            cout << "Arrays loaded from input file!\n\n\n";
        break;
        case 2:
            time(&start);
            BubbleSort(cList, AR_SIZE); // C++ bubble sort
            time(&end);
            
            cSeconds = difftime(end, start);

            cout << "Sorted contents output to cOut.txt\n"; 
            cout << "Time(seconds) recorded above...\n\n\n";
            
            fout.open("cOut.txt");
            
            for(int index = 0; index < AR_SIZE; index++)
            {
                fout << cList[index] << endl;
            }
            fout.close();
            
        break;
        case 3: 
            time(&start);
            bubbleSort(armList, AR_SIZE, false); // Arm assembly bubble sort
            time(&end);
            
            armSeconds = difftime(end, start);
            
            cout << "Sorted contents output to armOut.txt\n";
            cout << "Time(seconds) recorded above...\n\n\n";
            
            fout.open("armOut.txt");
            
            for(int index = 0; index < AR_SIZE; index++)
            {
                fout << armList[index] << endl;
            }
            fout.close();
            
        break;
        case 4: 
        break;
        default:
            cout << "Input not recognized, returning to main menu...\n";
        break;
    }



    while(menuChoice <= 3 || menuChoice >= 5)
    {
        cout << "-------------------------------------------------------\n";
        cout << "              RASM5:  C vs Assembly\n";
        cout << "-------------------------------------------------------\n";
        cout << " C        Bubblesort Time: " << cSeconds   << " secs   \n";
        cout << " Assembly Bubblesort Time: " << armSeconds << " secs   \n";
        cout << "-------------------------------------------------------\n";
        cout << "<1> Load input file (integers)              \n";
        cout << "<2> Sort using C Bubblesort algorithm       \n";
        cout << "<3> Sort using Assembly Bubblesort algorithm\n";
        cout << "<4> Quit                                    \n";

        cout << "\n\nPlease enter choice: ";
        cin  >> menuChoice;



        switch(menuChoice)
        {
            case 1: 
                loadInputFileInAr(cList);
                loadInputFileInAr(armList);
                cout << "Arrays loaded from input file!\n\n\n";
            break;
            case 2:
                time(&start);
                BubbleSort(cList, AR_SIZE);
                time(&end);
                
                cSeconds = difftime(end, start);

                cout << "Sorted contents output to cOut.txt\n";
                cout << "Time(seconds) recorded above...\n\n\n";
                
                fout.open("cOut.txt");
                
                for(int index = 0; index < AR_SIZE; index++)
                {
                    fout << cList[index] << endl;
                }
                fout.close();
                
            break;
            case 3: 
                time(&start);
                bubbleSort(armList, AR_SIZE, false);
                time(&end);
                
                armSeconds = difftime(end, start);
                
                cout << "Sorted contents output to armOut.txt\n";
                cout << "Time(seconds) recorded above...\n\n\n";
                
                fout.open("armOut.txt");
            
                for(int index = 0; index < AR_SIZE; index++)
                {
                    fout << armList[index] << endl;
                }
                fout.close();
                
            break;
            case 4:
            break;
            default:
                cout << "Input not recognized, returning to main menu...\n";
            break;
        }
    }

    return 0;
}// END Main



// Function Definitions
/***************************************************************/
// function to generate and retrun random numbers in arrary r.
int *getRandom(int r[AR_SIZE])
{
   // set the seed
   srand((unsigned)time(NULL));
   
   for (int i = 0; i < AR_SIZE; ++i) 
   {
      r[i] = rand() % 200000 + 1;  
   }

   return r;
}

// Function that prints array to an external output file
void printArToFile(int ar[AR_SIZE])
{
    ofstream fout;

    fout.open("random.txt");
    for (int i = 0; i < AR_SIZE; i++)
    {
        fout << ar[i] << endl;
    }
    fout.close();
}

// Function that inputs into an array from an external input file
void loadInputFileInAr(int ar[AR_SIZE])
{
    ifstream fin;

    fin.open("random.txt");
    for(int i = 0; i < AR_SIZE; i++)
    {
        fin >> ar[i];
    }
    fin.close();
}

// Bubble sort functon - C++ (Provided by Barnett)
void BubbleSort (int a[], int length)
{
	int i, j, temp;
	
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
