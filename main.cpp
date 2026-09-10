#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// --- Color Definitions ---
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[1;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

// --- Helper Functions & Globals ---
inline string cur(int r, int c) {
    return "\033[" + to_string(r) + ";" + to_string(c) + "H";
}

const int W      = 80;
const int H      = 24;
const int GROUND = 20;

struct Star { int r, c, type; };
vector<Star> stars;

void initStars() {
    for(int i = 0; i < 35; i++) {
        // Randomly place stars in the top half of the terminal
        stars.push_back({rand() % 12 + 1, rand() % (W - 2) + 1, rand() % 3});
    }
}

// --- Main Drawing Logic ---
void drawScene(int frame) {
    cout << "\033[2J\033[H"; // Clear screen and reset cursor

    // 1. Draw Twinkling Stars
    const char* starChars = ".*+";
    for (auto& s : stars) {
        if ((s.r + s.c + frame) % 6 == 0) continue; // Twinkle effect math
        cout << cur(s.r, s.c) << YELLOW << starChars[s.type] << RESET;
    }

    // 2. Draw Crescent Moon (Left side)
    cout << YELLOW << BOLD;
    cout << cur(2, 8)  << " _.._";
    cout << cur(3, 6)  << ".' .-'";
    cout << cur(4, 5)  << "/  /";
    cout << cur(5, 5)  << "|  |";
    cout << cur(6, 5)  << "\\  \\";
    cout << cur(7, 6)  << "'. '._.";
    cout << cur(8, 8)  << "  ''";
    cout << RESET;

    // 3. Draw Mosque Silhouette (Right side)
    cout << CYAN << BOLD;
    cout << cur(GROUND - 7, 50) << "      d";
    cout << cur(GROUND - 6, 50) << "     / \\";
    cout << cur(GROUND - 5, 50) << "    /   \\";
    cout << cur(GROUND - 4, 50) << "   /_____\\";
    cout << cur(GROUND - 3, 50) << "  |       |   _l_";
    cout << cur(GROUND - 2, 50) << "  |  ___  |  |   |";
    cout << cur(GROUND - 1, 50) << "  | |   | |  |   |";
    cout << cur(GROUND,     50) << "__|_|___|_|__|___|__";
    cout << RESET;

    // 4. Draw Alternating Fireworks
    if (frame % 8 < 4) {
        cout << MAGENTA << BOLD;
        cout << cur(4, 35) << " \\ | / ";
        cout << cur(5, 35) << "- -* - ";
        cout << cur(6, 35) << " / | \\ ";
    } else {
        cout << RED << BOLD;
        cout << cur(3, 45) << "  \\./  ";
        cout << cur(4, 45) << "-- * --";
        cout << cur(5, 45) << "  /\\  ";
    }
    cout << RESET;

    // 5. Draw Ground
    cout << GREEN;
    cout << cur(GROUND + 1, 1);
    for(int i = 0; i < W; i++) cout << "^";
    cout << RESET;

    // 6. Draw Color-Shifting Banner
    string colors[] = { RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };
    string c1 = colors[frame % 7];
    string c2 = colors[(frame + 3) % 7];

    cout << cur(10, 26) << c1 << BOLD << "+-------------------------+" << RESET;
    cout << cur(11, 26) << c1 << BOLD << "| " << c2 << "EID-UL-AZHA MUBARAK!" << c1 << " |" << RESET;
    cout << cur(12, 26) << c1 << BOLD << "+-------------------------+" << RESET;

    // 7. Draw Walking Sheep/Cow (Facing Right)
    // Moves 2 characters forward per frame
    int sheepX = (frame * 2) % 90 - 10; 
    
    // Only draw the animal if it's within standard terminal bounds
    if (sheepX > 0 && sheepX < W - 15) {
        int r = GROUND - 3;
        bool legsOut = (frame % 2 == 0); // Alternate legs for walking animation
        
        cout << WHITE << BOLD;
        cout << cur(r, sheepX)   << "        ,(__),";
        cout << cur(r+1, sheepX) << "    ____(oo)";
        cout << cur(r+2, sheepX) << "   /(    (__)";
        cout << cur(r+3, sheepX) << (legsOut ? "    -- " : "    \\\\--// ");
        cout << RESET;
    }

    // 8. Footer Message
    cout << cur(23, 7) << WHITE << BOLD << "May Allah accept your sacrifices and bless your family." << RESET;

    cout.flush();
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    
    cout << "\033[?25l"; // Hide the terminal cursor

    initStars();// Run the animation for 70 frames
    for (int f = 0; f < 70; f++) {
        drawScene(f);
        this_thread::sleep_for(chrono::milliseconds(200)); // Wait 200ms per frame
    }

    cout << "\033[?25h"; // Show the terminal cursor again
    cout << cur(H, 1) << "\n\nPress Enter to exit...";
    cin.ignore();
    
    return 0;
}