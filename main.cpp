#include <iostream>
#define ARRAY_LENGTH 12

/*
 Authours: Abigail Garvey, Zander Guilfoyle, Kieran Hosty
 Start Date: 10/03/2023 19:22
*/

using namespace std;

void displayInstructions();
void display(int input[]);
int total(const int input[]);
double avg(int input[]);
int max(const int input[]);
int min(const int input[]);
int occurrences(const int input[], int toFind);
void scale(int input[], double scaleFactor);
void reverse(int input[]);
void zeroBase(int input[]);

int main()
{
    int option;

    cout << "Please input " << ARRAY_LENGTH << " numbers:\n";

    int array[ARRAY_LENGTH];
    for (int& i : array)
    {
        cin >> i;
    }


    cout << "\nNow please select one of the following operations:\n";
    displayInstructions();

    do
    {

        cout << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            display(array);
            break;
        case 2:

            cout << "The sum of this array is " << total(array) << "\n";
            break;
        case 3:
            cout << "The average value in this array is " << avg(array) << "\n";
            break;

        case 4:
            cout << "The largest number in this array is " << max(array) << "\n";
            break;

        case 5:
            cout << "The smallest number in this array is " << min(array) << "\n";
            break;

        case 6:
            int checkOcc;
            cout << "Input a value to check the occurrence for? ";
            cin >> checkOcc;

            cout << checkOcc << " occurs in this array " << occurrences(array, checkOcc) << " times" << "\n";

            break;

        case 7:
            // makes it possible to scale by .5 or .25 ect
            double toCheck;
            cout << "Input a value to scale by? ";
            cin >> toCheck;

            scale(array, toCheck);
            display(array);
            break;

        case 8:
            reverse(array);
            display(array);
            break;

        case 9:
            zeroBase(array);
            display(array);
            break;

        case 10:
            // remove number funtionality
            break;

        case 11:
            break;

        default:
            cout << "ERROR: INVALID INPUT. Please choose from one of the options below\n";
            displayInstructions();
        }
    } while (option != 10);



    return 0;
}

int max(const int input[])
{
    int maximum = input[0];
    for (int i = 1; i < ARRAY_LENGTH; i++)
    {
        if (input[i] > maximum)
        {
            maximum = input[i];
        }

    }

    return maximum;
}

int min(const int input[])
{
    int minimum = input[0];
    for (int i = 1; i < ARRAY_LENGTH; i++)
    {
        if (input[i] < minimum)
        {
            minimum = input[i];
        }

    }

    return minimum;
}

int total(const int input[])
{
    int total = 0;
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        total += input[i];
    }

    return total;

}

double avg(int input[])
{
    double x = (double)total(input) / ARRAY_LENGTH;

    return x;

}

int occurrences(const int input[], int toFind)
{
    int noOfOccurrences = 0;
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        if (input[i] == toFind)
        {
            noOfOccurrences++;

        }
    }
    return noOfOccurrences;
}

void scale(int input[], double scaleFactor)
{

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        input[i] *= scaleFactor;
    }


}

void reverse(int input[])
{

    int maxIndex = ARRAY_LENGTH - 1;

    for (int i = 0; i < (ARRAY_LENGTH / 2); i++)
    {

        int tempStart = input[i];
        int tempEnd = input[maxIndex - i];

        input[i] = tempEnd;
        input[maxIndex - i] = tempStart;


    }

}

void zeroBase(int input[])
{
    int minimum = min(input);
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        input[i] -= minimum;

    }


}

void display(int input[])
{
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;

}

void displayInstructions()
{
    cout << "\t1: DISPLAY: Displays all of the values in the collection to the computer screen.\n";
    cout << "\t2. TOTAL: Calculates the total of all the values in the collection.\n";
    cout << "\t3. AVERAGE: Calculates the average of all the values in the collection.\n";
    cout << "\t4. LARGEST: Outputs the largest value of all the values in the collection.\n";
    cout << "\t5. SMALLEST: Outputs the smallest value of all the values in the collection.\n";
    cout << "\t6. OCCURRENCES OF VALUE: Outputs the number of occurrences of a particular value in the collection\n";
    cout << "\t7. SCALE UP: Multiplies each value in the collection by the scale factor entered\n";
    cout << "\t8. REVERSE: Rearranges the contents of the collection so that they are in reverse order.\n";
    cout << "\t9. ZERO BASE: Adjust all of the values in the collection so that the smallest value will be zero.\n";
    cout << "\t10. EXIT: Quits the application\n";
}


