#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Weapon {
public:
    string name;
    int damage;
    vector<string> specialAbilities;

    Weapon(string n, int d, vector<string> sa) : name(n), damage(d), specialAbilities(sa) {}

    friend ostream& operator<<(ostream& os, const Weapon& w) {
        os << "Weapon Name: " << w.name << "\nDamage: " << w.damage << "\nSpecial Abilities: ";
        for (const string& ability : w.specialAbilities) {
            os << ability << " ";
        }
        return os;
    }

    bool operator==(const Weapon& other) const {
        return (name == other.name && damage == other.damage);
    }
};

class Armour {
public:
    string name;
    string description;
    int value;

    Armour(string n, string desc, int v) : name(n), description(desc), value(v) {}

    friend ostream& operator<<(ostream& os, const Armour& a) {
        os << "Armour Name: " << a.name << "\nDescription: " << a.description << "\nArmour Value: " << a.value;
        return os;
    }

    bool operator==(const Armour& other) const {
        return (name == other.name && value == other.value);
    }
};

class Character {
public:
    string name;
    string species;
    string backstory;
    int health;
    Weapon weapon;
    Armour armour;

    Character(string n, string s, string b, int h, Weapon w, Armour a)
        : name(n), species(s), backstory(b), health(h), weapon(w), armour(a) {
    }

    void display() const {
        cout << "Character Name: " << name << "\nSpecies: " << species << "\nBackstory: " << backstory
            << "\nHealth: " << health << "\n" << weapon << "\n" << armour << "\n";
    }

    bool operator==(const Character& other) const {
        return (name == other.name && species == other.species && health == other.health);
    }
};

void createCharacter(vector<Character>& characters, const vector<Weapon>& weapons, const vector<Armour>& armours) {
    if (characters.size() >= 3) {
        cout << "Maximum number of characters reached.\n";
        return;
    }
    string name, species, backstory;
    int health, weaponChoice, armourChoice;

    cout << "Enter Character name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Species: ";
    getline(cin, species);

    cout << "Enter epic backstory: ";
    getline(cin, backstory);

    do {
        cout << "Enter starting health (25-200): ";
        cin >> health;
    } while (health < 25 || health > 200);
    
    cout << "Choose a weapon: \n";
    for (size_t i = 0; i < weapons.size(); ++i) {
        cout << i + 1 << ". " << weapons[i].name << " (Damage: " << weapons[i].damage << ")\n";
    }
    cin >> weaponChoice;

    cout << "Choose an armour: \n";
    for (size_t i = 0; i < armours.size(); ++i) {
        cout << i + 1 << ". " << armours[i].name << " (Value: " << armours[i].value << ")\n";
    }
    cin >> armourChoice;

    characters.emplace_back(name, species, backstory, health, weapons[weaponChoice - 1], armours[armourChoice - 1]);
    cout << "Character created successfully!! \n";
}

void compareCharacters(const vector<Character>& characters) {
    if (characters.size() < 2) {
        cout << "At least two characters are needed for comparison.\n";
        return;
    }

    int first, second;
    cout << "Select two characters to compare (1-" << characters.size() << "): ";
    cin >> first >> second;

    if (characters[first - 1] == characters[second - 1]) {
        cout << "The characters are the same.\n";
    }
    else {
        cout << "The characters are different.\n";
    }
}

void displayCharacters(const vector<Character>& characters) {
    if (characters.empty()) {
        cout << "No characters created yet.\n";
        return;
    }

    for (size_t i = 0; i < characters.size(); ++i) {
        cout << "\nCharacter " << i + 1 << ":\n";
        characters[i].display();
    }
}

int main() {
    vector<Character> characters;
    vector<Weapon> weapons = { {"Excalibur", 50, {"Holy Slash"}}, {"Shadow Blade", 40, {"Poison Strike"}} };
    vector<Armour> armours = { {"Dragon Scale", "Fire resistant", 40}, {"Titan Shield", "Strong defense", 50} };

    int choice;
    do {
        cout << "\n1. Create a Character\n2. Compare Characters\n3. Display Characters\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) createCharacter(characters, weapons, armours);
        else if (choice == 2) compareCharacters(characters);
        else if (choice == 3) displayCharacters(characters);

    } while (choice != 4);
}
