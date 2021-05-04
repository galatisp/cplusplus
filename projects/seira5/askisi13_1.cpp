#include <iostream>
#include <string>
#include <sstream>
#include <string.h>

#define SIZE 200
using namespace std;

// Function to check the array for elements in
// given range
bool check_elements(char arr[])
{
    int n = 26;
    int start = 97;
    int end = start + n - 1;
    char alphabet[26];
    for (int i = 0; i < n; i++)
        alphabet[i] = i + start;

    // Traversing the array
    for (int i = 0; i < n; i++)
    {
        // If an element is in range
        if (arr[i] >= start && arr[i] <= end)
        {
            // Zero value alphabet char at index ‘arr[i] - start’
            int pos = arr[i] - start;
            alphabet[pos] = 0;
        }
    }

    // Checking whether alphabet characters
    // are positive
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // character  is missing from array
        if (alphabet[i] > 0)
            return false;
        else
            count++;
    }
    if (count != n)
        return false;
    // All range elements are present
    return true;
}

int get_line(char *buffer)
{
    size_t cnt = 0;
    char c;

    if (buffer == NULL)
        return 0;

    //read code
    while ((c = getchar()) != '\n' && c != EOF && cnt < SIZE - 1)
    {
        buffer[cnt++] = c;
    }

    buffer[cnt] = 0; // making sure it's 0-terminated
    
    return cnt;
}



int getpos(char *code, char c)
{
    int pos = 0;
    while ((c != code[pos]) && (pos < 26))
        pos++;
    return pos;
}

void reverse(char *code, char *rev_code){
    int pos;
    for (int i =0; i < 26; i++){
        pos = getpos(code, 'a'+i);
        rev_code[i] = 'a'+pos;
    }

}

void encode(char *input, char *output, char *code)
{

    char input_c, output_c;

    int pos;

    int i = 0;
    do
    {
        input_c = input[i];

        if (input_c != 0)
        {

            if (input_c >= 'a' && input_c <= 'z')
            {
                pos = input_c - 'a';
                output[i] = code[pos];
            }
            else if (input_c >= 'A' && input_c <= 'Z')
            { //capitals
                pos = input_c - 'A';
                output[i] = code[pos] - 32;
            }
            else
                output[i] = input[i];
        }
        else
            output[i] = 0;

        i++;
    } while (input_c != 0);
}



void parse_input(char *code)
{
    size_t cnt = 0;
    char c;
    char line[SIZE];
    char output[SIZE];
   

    //read lines - encode line - by line
    while (get_line(line))
    {
        
        encode(line, output, code);
        cout<<output<<endl;
    }

    
}

int main()
{

    char code[27], rev_code[27], action[100], input[1000], output[1000];
    int len = get_line(code);
    if (len > 26) {
        std::cout << "error" << endl;
        return -1;
    } 

    if (!check_elements(code)){
        std::cout << "error" << endl;
        return -1;
    } 

    cout << code << endl;

    
    get_line(action);
 
    if (action[0] == 'd')
    { 
        cout << "Decoding: " << endl;
        reverse(code, rev_code);
        strcpy(code, rev_code);
    }

  
  
    parse_input(code);
    
    
    return 0;
}
