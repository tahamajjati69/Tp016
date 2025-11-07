#include <iostream>
#include <memory>
using namespace std;

class Forme {
public:
    virtual void afficher() const = 0;
    virtual ~Forme() = default;
};

class Cercle : public Forme {
public:
    void afficher() const override { cout << "Cercle" << endl; }
};

class Carre : public Forme {
public:
    void afficher() const override { cout << "Carré" << endl; }
};

class Triangle : public Forme {
public:
    void afficher() const override { cout << "Triangle" << endl; }
};

class FabriqueForme {
public:
    static unique_ptr<Forme> creerForme(int type) {
        switch (type) {
            case 1: return make_unique<Cercle>();
            case 2: return make_unique<Carre>();
            case 3: return make_unique<Triangle>();
            default: return nullptr;
        }
    }
};

int main() {
    auto f1 = FabriqueForme::creerForme(1);
    auto f2 = FabriqueForme::creerForme(2);
    auto f3 = FabriqueForme::creerForme(3);

    if (f1) f1->afficher();
    if (f2) f2->afficher();
    if (f3) f3->afficher();

    return 0;
}
