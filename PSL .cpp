#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addPlayer()
{
    string name, team, role;
    int runs, wickets;
    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Team Name: ";
    getline(cin, team);
    cout << "Enter Role: ";
    getline(cin, role);
    cout << "Enter Runs: ";
    cin >> runs;
    cout << "Enter Wickets: ";
    cin >> wickets;

    ofstream file("players.txt", ios::app);
    file << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
    file.close();
    cout << "Player added successfully!" << endl;
}

void viewPlayers()
{
    ifstream file("players.txt");
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

void searchPlayer()
{
    string name;
    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);

    ifstream file("players.txt");
    string line;
    while (getline(file, line))
    {
        if (line.find(name) != string::npos)
        {
            cout << line << endl;
            return;
        }
    }
    file.close();
    cout << "Player not found!" << endl;
}

void updatePlayer() 
{
    string name;
    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);

    ifstream file("players.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;
    while (getline(file, line)) 
    {
        if (line.find(name) != string::npos)
        {
            int runs, wickets;
            cout << "Enter New Runs: ";
            cin >> runs;
            cout << "Enter New Wickets: ";
            cin >> wickets;
            cin.ignore();

            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            string playerName = line.substr(0, pos1);
            string team = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string role = line.substr(pos2 + 1, pos3 - pos2 - 1);

            temp << playerName << "," << team << "," << role << "," << runs << "," << wickets << endl;
            found = true;
        }
        else
        {
            temp << line << endl;
        }
    }
    file.close();
    temp.close();
    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (found)
    {
        cout << "Player updated successfully!" << endl;
    }
    else 
    {
        cout << "Player not found!" << endl;
    }
}

void deletePlayer() 
{
    string name;
    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);

    ifstream file("players.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;
    while (getline(file, line))
    {
        if (line.find(name) == string::npos) 
        {
            temp << line << endl;
        }
        else 
        {
            found = true;
        }
    }
    file.close();
    temp.close();
    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (found)
    {
        cout << "Player deleted successfully!" << endl;
    }
    else
    {
        cout << "Player not found!" << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "1. Add Player" << endl;
        cout << "2. View Players" << endl;
        cout << "3. Search Player" << endl;
        cout << "4. Update Player" << endl;
        cout << "5. Delete Player" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            addPlayer();
            break;
        case 2:
            viewPlayers();
            break;
        case 3:
            searchPlayer();
            break;
        case 4:
            updatePlayer();
            break;
        case 5:
            deletePlayer();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}