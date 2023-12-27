#include <vector>
#include <iostream>

using namespace std;

void collecting(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, vector<vector<int>>& A, vector<vector<int>>& B);
void multiplying(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, const vector<vector<int>>& A, const vector<vector<int>>& B);
void displaying(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, const vector<vector<int>>& A, const vector<vector<int>>& B);
//void collecting2(vector<vector<int>> A, vector<vector<int>> B);


int main()
{
    //consider using strassen algorithm and openMP later

    //how many rows do you want? alright 3? we make 3 subvectors
    //how many columns? 3? alright each subvector is size 3

    //only square vectors atleast for now
    
    //need a vector of vectors, where each sub-vector represents a row in the matrix A. such as:
    //need one for B too
    //need to check if both matrices match n and m

    int rowsizeA;
    int colsizeA;
    int rowsizeB;
    int colsizeB;
    vector<vector<int>> A;
    vector<vector<int>> B;
    
    cout<<"\n";
    cout<<"give row size of Matrix A"<<endl;
    cin>>rowsizeA;
    cout<<"\n";
    cout<<"give col size of Matrix A"<<endl;
    cin>>colsizeA;
    cout<<"\n";

    cout<<"give row size of Matrix B"<<endl;
    cin>>rowsizeB;
    cout<<"\n";
    cout<<"give col size of Matrix B"<<endl;
    cin>>colsizeB;
    cout<<"\n";


    collecting(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);
    displaying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);
    multiplying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);

    //multiplying()

    //cout<<vectorA(int x);

    return 0;
}







void collecting(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, vector<vector<int>>& A, vector<vector<int>>& B)
{
    
    int num1; // iterators
    int num2;

    for(int i = 0; i<rowsizeA; i++)
    {
       cout<<"For A give the values for row "<<i+1<<"."<<endl;
       vector<int> v1;
       for(int j = 0; j<colsizeA; j++)
       {
           cin>>num1;
           //cin.ignore();
           v1.push_back(num1);
       }
       
       A.push_back(v1);
    }

    cout<<endl;

    for(int i = 0; i<rowsizeB; i++)
    {
       cout<<"For B give the values for row "<<i+1<<"."<<endl;
       vector<int> v2;
       for(int j = 0; j<colsizeB; j++)
       {
           cin>>num2;
           //cin.ignore();
           v2.push_back(num2);
       }
       
       B.push_back(v2);
    }

    cout<<endl;

    //multiplying(vector<vector<int>> A, vector<vector<int>> B);

  
}






void displaying(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, const vector<vector<int>>& A, const vector<vector<int>>& B)
{

  
    cout<<endl;
    cout<<"Your vector A"<<endl;
    cout<<endl;
    

    for(int i = 0; i<rowsizeA; i++)
    {
        for(int j = 0; j<colsizeA; j++)
        {
            cout<<A[i][j];
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Your vector B"<<endl;
    cout<<endl;

    for(int i = 0; i<rowsizeB; i++)
    {
        for(int j = 0; j<colsizeB; j++)
        {
            cout<<B[i][j];
        }
        cout<<endl;
    }

    cout<<endl;


}








void multiplying(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, const vector<vector<int>>& A, const vector<vector<int>>& B)
{
    
    vector<vector<int>> C; //needs to match size of square vectors
    for(int i = 0; i<rowsizeA; i++) //setting resultant vector as empty to start
    {   
        vector<int> x;
        for(int j = 0; j<colsizeA; j++)
        {
            x.push_back(0);
        }
        C.push_back(x);
    }


    for(int n = 0; n<rowsizeB; n++) // adding the products
    {
        int y = 0;
        for(int m = 0; m<colsizeB; m++)
        {
            int x = 0;
            for(int i = 0; i<rowsizeB; i++)
            {
                x = x + A[n][i]*B[i][y];
            }
            C[n][m] = x;
            y++;
        }
    }


    cout<<"multiplied vector C: "<<endl;


    for(int i = 0; i<rowsizeA; i++)
    {
        for(int j = 0; j<colsizeA; j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;


    
}





