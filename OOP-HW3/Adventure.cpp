#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

struct Room {
    string name;
    int exits[4];
};

class Game {
    private:
        vector<Room> rooms; 
        unordered_map<string, int> map_space; 
        int now;
        bool game_over;
        int princess_room;
        int monster_room;
        int random_jump_room;
        int selective_jump_room;
        string room_name(int id) {
            switch (id) {
                case 0:
                    return "east";
                case 1:
                    return "up";
                case 2:
                    return "west";
                case 3:
                    return "down";
                default:
                    return "";
            }
        }
        int room_id(string name) {
            if (name == "east")
                return 0;
            else if (name == "up")
                return 1;
            else if (name == "west")
                return 2;
            else if (name == "down") 
                return 3;
            else
                return -1;
        }
        int random_room_index() {
            return 1 + rand() % (rooms.size() - 1);//room 0 is the lobby
        }
    public:
        Game() {
            // Read in the room information from the input file
            ifstream infile("castle.txt");
            int number;
            infile >> number;
            rooms.resize(number);
            string name;
            int e_east, e_up, e_west, e_down;
            for (int i = 0; i < number; i++) {
                infile >> name >> e_east >> e_up >> e_west >> e_down;
                map_space[name] = i;
                rooms[i] = {name, {e_east, e_up, e_west, e_down}};
            }
            infile.close();
            // Initialize the game state
            now = map_space["lobby"];
            game_over = false;
            srand(time(0));
            princess_room = random_room_index();
            do {
                monster_room = random_room_index();
                random_jump_room = random_room_index();
                selective_jump_room = random_room_index();
            } while (monster_room == princess_room || random_jump_room == princess_room || random_jump_room == monster_room ||
                selective_jump_room == princess_room || selective_jump_room == monster_room || selective_jump_room == random_jump_room);
            rooms[princess_room].name = "secret room";
            rooms[monster_room].name = "over";
            rooms[monster_room].exits[0] = -1;
            rooms[monster_room].exits[1] = -1;
            rooms[monster_room].exits[2] = -1;
            rooms[monster_room].exits[3] = -1;
            rooms[random_jump_room].name = "random jump room";
            rooms[selective_jump_room].name = "selective jump room";
        }
        void run() {
            while (!game_over) {
                // Enter the random jump room, the player will be randomly teleported to a certain room
                if (rooms[now].name == "random jump room") {
                    cout << "Oh!You entered a Random Teleportation Room, um... let's see where you were sent\n";
                    now = random_room_index();
                }
                // Enter the selective jump room, the player will be teleported to a certain room whatever he want
                else if (rooms[now].name == "selective jump room") {
                    cout << "Oh!You entered the Selective Teleportation Room. Please enter the room id whatever you want to jump to: ";
                    int target_room;
                    cin >> target_room;
                    if (target_room < 0 || target_room >= rooms.size()) {
                        cout << "Invalid room id! Please enter a valid room id.\n";
                    } else {
                        now = target_room;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                }
                // Encountered a monster, game over
                else if (rooms[now].name == "over" || now < 0) {
                    game_over =true;
                    cout << "Game over: you met the monster! You can try again\n";
                }
                // The player is in the lobby with the princess, game over
                else if (now == map_space["lobby"] && rooms[now].name == "lobby" && rooms[princess_room].name == "lobby") {
                    game_over = true;
                    cout << "Congratulations! You have found the princess and saved the world!\n";
                }
                // Normal room
                else{
                    // Print the information of the current room
                    int num_exits = 0;
                    int num_exits2 = 0;
                    for (int i = 0; i < 4; i++) {
                        if (rooms[now].exits[i] >= 0) 
                            num_exits++;
                    }
                    cout << "Welcome to the " << rooms[now].name << ". There are " << num_exits << " exits: ";
                    for (int i = 0; i < 4; i++) {
                        if (rooms[now].exits[i] >= 0) {
                            if (num_exits2 > 0){
                                if (num_exits == 1)
                                    cout << " and ";
                                else
                                    cout << ", ";
                            }
                            cout << room_name(i);
                            num_exits2++;
                            num_exits--;
                        }
                    }
                    cout << ".\nEnter your command: ";
                    string input;
                    getline(cin, input);
                    stringstream ss(input);
                    string command;
                    ss >> command;
               // Process the command
                if (command == "go") {
                    string go_name;
                    ss >> go_name;
                    int go_id = room_id(go_name);
                    if (go_id >= 0 && rooms[now].exits[go_id] >= 0) {
                        now = rooms[now].exits[go_id];
                        // Add this block to check if the player is in the lobby with the princess
                        if (rooms[now].name == "secret room") {
                            // Conversation with the princess
                            cout << "You found the princess!\n";
                            cout << "Princess: Thank you for rescuing me! Let's leave this castle together.\n";
                            cout << "Princess: But I am afraid that the monster is still in the castle. We must hurry!\n";
                            cout << "You: Let me take you out!";
                            cout << "Enter your command: ";
                            getline(cin, input);  // Read in the entire input line again
                            stringstream ss2(input);
                            string go_name2;
                            ss2 >> go_name2;
                            int go_id2 = room_id(go_name2);
                            if (go_id2 >= 0 && rooms[now].exits[go_id2] >= 0) {
                                now = rooms[now].exits[go_id2];
                                if (now == map_space["lobby"]) {
                                    // Congratulations, the player won the game
                                    game_over = true;
                                    cout << "Congratulations, you escaped the castle with the princess!\n";
                                }
                                else 
                                    cout << "Invalid command!\n";
                            }
                            else 
                                cout << "There is no exit in that direction. Please enter a valid direction.\n";
                        }
                    } 
                    else 
                        cout << "There is no exit in that direction. Please enter a valid direction.\n";
                } 
                else if (command == "help") {
                    cout << "Available commands:\n";
                    cout << "  go [direction]: move \n";
                    cout << "  help: display this help message\n";
                    cout << "  q: quit the game\n";
                }
                else if (command == "q") {
                    game_over = true;
                    cout << "Goodbye!\n";
                    cout << "The princess was in room " << princess_room << ".\n";
                    cout << "The monster was in room " << monster_room << ".\n";
                }
                else 
                    // Invalid command
                    cout << "Invalid command!\n";
            }
        }
    }
};

int main() {
    cout << "Welcome to the Adventure!\n";
    cout << "Your mission is to explore the castle, find the princess, and lead her back to the lobby.\n";
    cout << "Hush~ Be careful! -- there's a monster hiding somewhere in the castle!\n";

    Game game;
    game.run();
    system("pause");
}