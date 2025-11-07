#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    string cheminFichier;
    string utilisateur;
    string motDePasse;

    Configuration() : cheminFichier("config.txt"), utilisateur("admin"), motDePasse("1234") {}

    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

public:
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void afficherParametres() const {
        cout << "Chemin : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe : " << motDePasse << endl;
    }
};

int main() {
    Configuration& config1 = Configuration::getInstance();
    Configuration& config2 = Configuration::getInstance();

    config1.afficherParametres();

    if (&config1 == &config2)
        cout << "Même instance (singleton confirmé)" << endl;

    return 0;
}
