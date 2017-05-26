#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void wordGenerator(const int* const);

int main()
{
    int phoneNumber[7] = {0};  /// <--zapazva telefonniq nomer
    ///pitame potrebitelq za telefonen nomer ///
    cout << " enter phone number 2-9 digits /// int the form xxx-xxxx " << endl;

        for (int u = 0, v = 0; u < 8; u++)
        {
            int i = cin.get();

        ///probvame dali "i" se namira m/u 0 i 9;
        if ( i >= '0' && i <= '9' )

            phoneNumber[v++] = i - '0';
        }
    wordGenerator(phoneNumber); ///duma ot telefonniq nomer;
    return 0;
}
void wordGenerator(const int* const n)
{
    ofstream outFile ("Phone.dat");/// setvame output stream za otvarqne na output faila
    const char *phoneLatters[10] = {"","","","","","","","","",""};///tesksta za vseki edin nomer

    if (!outFile)
    {
        cerr << "/ could not be opened ! ";
        exit(1);
    }
int count = 0; /// nomerata na namerenite dumi.

    for (int i1 = 0; i1 < 2; i1++)
    {
        for (int i2 = 0; i2 < 2; i2++)
        {
            for (int i3 = 0; i3 < 2; i3++)
            {
                for (int i4 = 0; i4 < 2; i4++)
                {
                    for (int i5 = 0; i5 < 2; i5++)
                    {
                        for (int i6 = 0; i6 < 2; i6++)
                        {
                            for (int i7 = 0; i7 < 2; i7++)
                            {
                                outFile <<phoneLatters[n[0]][i1]
                                << phoneLatters [n[1]][i2]
                                << phoneLatters [n[2]][i3]
                                << phoneLatters [n[3]][i4]
                                << phoneLatters [n[4]][i5]
                                << phoneLatters [n[5]][i6]
                                << phoneLatters [n[6]][i7] <<' ';
                                if (++ count % 9 == 0)
                                {
                                    outFile << '/n';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    outFile << "/phoneNumber is";
        for (int i = 0; i < 7; i++)
        {
            if (i == 3)
            {
                outFile <<" ";
                outFile << n[i];
            }
        }
    outFile.close(); ///zatvarqme izhodqshtiq fail.
}
