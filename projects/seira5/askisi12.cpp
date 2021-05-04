#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int get_from_user(char *code, char *text, size_t size)
{
    size_t cnt = 0;
    char c;

    if (code == NULL || text == NULL || size == 0)
        return 0;
    //read code
    while ((c = getchar()) != '\n' && c != EOF && cnt < size - 1)
    {
        code[cnt++] = c;
    }

    code[cnt] = 0; // making sure it's 0-terminated
    if (cnt > 26)
        return -1;
    

    cnt = 0;
    //read text
    while ((c = getchar()) != '\n' && c != EOF && cnt < size - 1)
    {
        if (c == '\n')
        {
            text[cnt] = 0;
            return 1;
        }
        text[cnt++] = c;
    }

    text[cnt] = 0; // making sure it's 0-terminated
    return 1;
}

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

void encode(char *input, char *output, char *code)
{

    char input_c, output_c;
    int i = 0;
    int start = 97;
    int pos;
    do
    {
        input_c = input[i];
        // putchar(input_c);
        if (input_c != 0)
        {
            if (input_c >= 'a' && input_c < 'z')
            {
                pos = input_c - 'a';
                output[i] = code[pos];
            }
            else if (input_c >= 'A' && input_c < 'Z')
            { //capitals
                pos = input_c - 'A';
                output[i] = code[pos] - 32;
            }
            else
                output[i] = input[i];

            // putchar(output[i]);
        }
        else
            output[i] = 0;
        i++;
    } while (input_c != 0);
}

int main()
{
    char code[27], line[200];
    char input[1000], output[1000];

    string mystr;
    // cout << "Encryption code: ";
    // getline(cin, mystr);
    // stringstream(mystr) >> code;
    if (get_from_user(code, input, sizeof(input)) < 0)
    {
        cout << "error" << endl;
        return -1;
    }

    // False denotes an element was not present
    if (!check_elements(code))
    {
        cout << "error" << endl;
        return -1;
    }

    // cout << "Input :";
    //get_from_user(input, sizeof(input));
    // fgets(input, sizeof(input), stdin);

    encode(input, output, code);

    cout << endl
         << "Output : " << output << endl;

    return 0;
}
