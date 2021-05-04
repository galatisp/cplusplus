
#include <iostream>
#include <string.h>

using namespace std;

bool isletter(int c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '\"' || c == '-' || c == '\'';
}

bool ispunctuation(char c)
{
    return c == ',' || c == '.' || c == '!' || c == '?';
}

bool isdelimiter(char c)
{
    return c == ',' || c == '.' || c == '!' || c == '?' || c == ' ' || c == '\n' || c == '\t';
}

int main()
{
    const int MAX = 60;

    char line[MAX], word[MAX], ch;
    int chars = 0, lines = 0, words = 0, c;
    FILE *f, *g;
    f = fopen("in.txt", "rt");
    g = fopen("out.txt", "wb");
    if (f == nullptr || g == nullptr)
    {
        printf("Some of the files could not be opened!\n");
        return 0;
    }
    int n;
    c = fgetc(f);
    ch = c;
    line[0] = '\0';
    while (c != EOF)
    {

        if (!isdelimiter(ch))
        {
            n = 0;

            words++;
            do
            {
                chars++;
                word[n++] = c;
                c = fgetc(f);
                ch = c;

            } while (!isdelimiter(ch));
            //add punctuation to word
            if (ispunctuation(ch))
            {
                word[n++] = c;
                chars++;
            }
            word[n] = '\0';
        }
        else
        {
            // empty line if line is full
            if ((strlen(line) + strlen(word)) == MAX)
            {

                strcat(line, word);
                //empty word
                word[0] = '\0';

                fprintf(g, "%s\n", line);
                line[0] = '\0';
                words = 0;
                chars = 0;
            }
            // empty line if word does not fit in line

            else if ((strlen(line) + strlen(word)) > MAX)
            {
                // if last char is space delete it;
                if (line[strlen(line) - 1] == ' ')
                    line[strlen(line) - 1] = '\0';
                // last word does not fit
                // it must not be calculated in spaces
                words--;
                int spaces = words - 1;
                int lineLen = strlen(line);
                // int lastWordLen = strlen(word);

                int totalSpace = MAX - (lineLen - spaces);
                int minSpace = totalSpace / spaces;
                int remains = totalSpace % spaces;

                printf("\nWords = %d, lineLen = %d,  totalspace= %d, spaces = %d, minSpace = %d, remains= %d \n ", words, lineLen, totalSpace, spaces, minSpace, remains);
                const char s[2] = " ";
                char *token;

                /* get the first token */
                token = strtok(line, s);

                int n = 1;
                /* walk through other tokens */
                while (token != NULL)
                {
                    fprintf(g, "%s", token);

                    if (n <= spaces)
                    {
                        for (int i = 0; i < minSpace; i++)
                            fprintf(g, "%s", s);
                        if (((spaces - n) < remains) && (remains > 0))
                        {
                            fprintf(g, "%s", s);
                        }
                    }
                    n++;

                    token = strtok(NULL, s);
                }

                fprintf(g, "\n");

                line[0] = '\0';
                words = 0;
                chars = 0;

                strcat(line, word);
                //empty word
                word[0] = '\0';
            }

            else
            {
                //put word to line
                strcat(line, word);
                //empty word
                word[0] = '\0';

                // // add space to line if space or new line was detected
                if ((isspace(ch)) && (strlen(line) < MAX))
                {
                    char ch = ' ';
                    strncat(line, &ch, 1);
                }
            }

            // printf("line = %s \n", line);
            c = fgetc(f);
            ch = c;
            // put the last line
            if (c == EOF)
            {
                fprintf(g, "%s\n", line);
            }
        }
    }

    fclose(f);
    fclose(g);
}
