#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string numberToString(int);
int findDigitK(int);
int main(int argc, char *argv[])
{	
	int n = atoi(argv[1]);

	int k = findDigitK(n);

	cout << "Wprowadzona liczba: " << numberToString(n) << endl;
	cout << "Liczba k: " << k << " - " << numberToString(k) << endl;
	cout << "Iloczyn k * n : " << k * n << " - " << numberToString(k*n) << endl;
}

string numberToString(int n)
{	
	if(n > 1000000)
		return "Liczba jest za duza by wyswietlic";

	if(n == 0)
		return "Zero";

	if(n == 1000000)
		return "Milion";


	string units[] = {"", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
	string teens[] = {"", "jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie",
			 			"siedemnascie", "osiemnascie" "dziewietnascie"};
	string tens[] = {"", "dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat",
					"szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
	string hundreds[] = {"", "sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset",
						  "osiemset", "dziewiecset"};
	string thousands[] = {"tysiecy", "", "tysiace", "tysiace", "tysiace", "tysiecy", "tysiecy", "tysiecy", "tysiecy", "tysiecy"};

	int digit[6];

	for(int i = 0; i < 6; i++)
	{
		digit[i] = n%10;
		n /=10;
	}

	string final = "";				//ostateczny string

	final += hundreds[digit[5]] + " ";			//setki tysięcy

	if(digit[4] == 1)
		final += teens[digit[3]] + " " + thousands[5] + " ";	//"nśacie" tysięcy

	else
	{
		final += tens[digit[4]] + " ";			//dziesiątki tysięcy

		if(digit[3] == 1 && digit[4] == 0 && digit[5] == 0) 
			final += "tysiac ";										//pominięcie wyrazu "jeden" przy jednym tysiącu
		else if(digit[5] != 0 || digit[4] != 0 || digit[3] != 0)
			final += units[digit[3]] + " " + thousands[digit[3]] + " ";	//jedności tysięcy
	}

	final += hundreds[digit[2]] + " ";			//setki

	if(digit[1] == 1 && digit[0] != 0)
		final += teens[digit[0]] + " ";			//liczby 11-19

	else
		final += tens[digit[1]] + " " + units[digit[0]];	//dziesiątki i jedności


    for (int i = 0; i < final.length() - 1; i++)			//funkcja usuwajace niepotrzebne spacje
        if (final[i] == ' ')
              while(final[i + 1] == ' ')
                final.erase(i, 1);

     return final;
}

int findDigitK(int n)
{
	if(n == 0 || n == 1)
		return n;

    for(int k = 1;; k++) //petla nie jest nieskonczona,
 						  //bo w końcu i tak znajdziemy liczbę k
    {
        int product = n * k;
        while(product)
        {
            if(product % 10 != 0 && product % 10 != 1)		//sprawdza czy liczba ma na końcu 0 lub 1
                break;

            product /= 10;									//jesli tak dzieli ją przez 10 ... i sprawdza kolejną ostatnią cyfrę
            if(product == 1)								//zwraca k, jeśli ostatnią liczbą będzie 10 lub i
                return k;
        }
    }
}