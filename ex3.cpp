#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Observateur {
public:
    virtual void mettreAJour(float temperature, float humidite, float pression) = 0;
    virtual ~Observateur() = default;
};

class StationMeteo {
    float temperature, humidite, pression;
    vector<Observateur*> observateurs;
public:
    void ajouterObservateur(Observateur* o) { observateurs.push_back(o); }
    void retirerObservateur(Observateur* o) {
        observateurs.erase(remove(observateurs.begin(), observateurs.end(), o), observateurs.end());
    }
    void setMesures(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;
        notifier();
    }
    void notifier() {
        for (auto* o : observateurs)
            o->mettreAJour(temperature, humidite, pression);
    }
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float temperature, float, float) override {
        cout << "Température : " << temperature << " °C" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float, float humidite, float) override {
        cout << "Humidité : " << humidite << " %" << endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(float, float, float pression) override {
        cout << "Pression : " << pression << " hPa" << endl;
    }
};

int main() {
    StationMeteo station;

    AffichageTemperature temp;
    AffichageHumidite hum;
    AffichagePression pres;

    station.ajouterObservateur(&temp);
    station.ajouterObservateur(&hum);
    station.ajouterObservateur(&pres);

    station.setMesures(22.5, 60.0, 1013.2);
    cout << "---" << endl;
    station.setMesures(25.0, 55.0, 1009.8);

    return 0;
}
