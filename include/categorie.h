#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class => print get set 
//     constructeur dispo => dans la doc

namespace Categorie {
class Categorie  {

    private:

    public:
        string type;
        string unite;
        int min;
        int max;

        //Categorie(){}
        Categorie(const string& _type, const string& _unite, int _min, int _max): type(_type), unite(_unite), min(_min), max(_max){}

        Categorie(const Categorie& _c){
                this->type = _c.type;
                this->unite = _c.unite;
                this->min = _c.min;
                this->max = _c.max;
            }

        void set_type(const string& _type){type = _type;}
        void set_unite(const string& _unite){unite = _unite;}
        void set_min(int _min){min = _min;}
        void set_max(int _max){min = _max;}

        string get_type(){return type;}
        string get_unite(){return unite;}
        
        int get_min(){return min;}
        int get_max(){return max;}

        void afficherInfos() {
            cout << "---CATEGORIE----" << endl;
            cout << " Type: " << type << endl;
            cout << " Unite en: " << unite  << endl;
            cout << " Taille Min: " << min << endl;
            cout << " Taille Max: " << max << endl;

        }

        //~Categorie(){}
    };
}

