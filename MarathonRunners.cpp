#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

void readData(ifstream& file, string names[], double miles[][NUM_DAYS]);
void calculate(double miles[][NUM_DAYS], double totals[], double averages[]);
void display(string names[], double miles[][NUM_DAYS],
    double totals[], double averages[]);

int main()
{
    string names[NUM_RUNNERS];
    double miles[NUM_RUNNERS][NUM_DAYS];
    double totals[NUM_RUNNERS];
    double averages[NUM_RUNNERS];

    ifstream file("runners.txt");

    if (!file)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    readData(file, names, miles);
    calculate(miles, totals, averages);
    display(names, miles, totals, averages);

    file.close();

    return 0;
}

void readData(ifstream& file, string names[], double miles[][NUM_DAYS])
{
    for (int i = 0; i < NUM_RUNNERS; i++)
    {
        file >> names[i];

        for (int j = 0; j < NUM_DAYS; j++)
        {
            file >> miles[i][j];
        }
    }
}

void calculate(double miles[][NUM_DAYS], double totals[], double averages[])
{
    for (int i = 0; i < NUM_RUNNERS; i++)
    {
        totals[i] = 0;

        for (int j = 0; j < NUM_DAYS; j++)
        {
            totals[i] = totals[i] + miles[i][j];
        }

        averages[i] = totals[i] / NUM_DAYS;
    }
}

void display(string names[], double miles[][NUM_DAYS],
    double totals[], double averages[])
{
    cout << fixed << setprecision(2);

    cout << setw(12) << "Runner";

    for (int j = 0; j < NUM_DAYS; j++)
    {
        cout << setw(8) << "Day" << j + 1;
    }

    cout << setw(10) << "Total";
    cout << setw(10) << "Average" << endl;

    for (int i = 0; i < NUM_RUNNERS; i++)
    {
        cout << setw(12) << names[i];

        for (int j = 0; j < NUM_DAYS; j++)
        {
            cout << setw(8) << miles[i][j];
        }

        cout << setw(10) << totals[i];
        cout << setw(10) << averages[i] << endl;
    }
}
