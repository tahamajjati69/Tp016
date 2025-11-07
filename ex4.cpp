#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

class StrategieTri {
public:
    virtual void trier(vector<string>& v) const = 0;
    virtual ~StrategieTri() = default;
};

class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& v) const override {
        sort(v.begin(), v.end());
    }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& v) const override {
        sort(v.rbegin(), v.rend());
    }
};

class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& v) const override {
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
    }
};

class GestionnaireTri {
    unique_ptr<StrategieTri> strategie;
public:
    GestionnaireTri(unique_ptr<StrategieTri> s) : strategie(move(s)) {}
    void setStrategie(unique_ptr<StrategieTri> s) { strategie = move(s); }
    void trier(vector<string>& v) const { strategie->trier(v); }
};

int main() {
    vector<string> mots = {"chat", "éléphant", "chien", "lion", "tigre"};

    GestionnaireTri gestionnaire(make_unique<TriCroissant>());
    gestionnaire.trier(mots);

    cout << "Tri croissant : ";
    for (auto& m : mots) cout << m << " ";
    cout << "\n";

    gestionnaire.setStrategie(make_unique<TriDecroissant>());
    gestionnaire.trier(mots);
    cout << "Tri décroissant : ";
    for (auto& m : mots) cout << m << " ";
    cout << "\n";

    gestionnaire.setStrategie(make_unique<TriParLongueur>());
    gestionnaire.trier(mots);
    cout << "Tri par longueur : ";
    for (auto& m : mots) cout << m << " ";
    cout << "\n";

    return 0;
}
