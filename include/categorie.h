#pragma once
#include <iostream>
#include <string>
#include <vector>

/**
 * @file categorie.h
 */
using namespace std;

// class => print get set 
//     constructeur dispo => dans la doc

namespace Categorie {
/**
 * @namespace Categorie
 */
class Categorie  {
    /**
     * @class Categorie 
     * @var string type
     * @var string unite
     * @var int min
     * @var int max
     * @file 
     */

    protected:
        string type;
        string unite;
        int min;
        int max;

    public:
        Categorie(const string& _type, const string& _unite, int _min, int _max): type(_type), unite(_unite), min(_min), max(_max)
        /**
         * @brief constructeur par initialisation
         * @param string _type
         * @param string _unite
         * @param int _min
         * @param int _max
         */
        {}

        Categorie(const Categorie& _c){
            /**
             * @brief constructeur par recopie
             * @param Categorie _c
             */
                this->type = _c.type;
                this->unite = _c.unite;
                this->min = _c.min;
                this->max = _c.max;
            }

        void set_type(const string& _type)
        /**
         * @brief set type
         * @param string _type
         */
        {
            type = _type;
        }
        void set_unite(const string& _unite)
        /**
         * @brief set unite
         * @param string _unite
         */
        {
            unite = _unite;
        }
        void set_min(int _min)
        /**
         * @brief set min
         * @param string _min
         */
        {
            min = _min;
        }
        void set_max(int _max)
        /**
         * @brief set max
         * @param int _max
         */
        {
            min = _max;
        }

        string get_type()
        /**
         * @brief get type
         */
        {
          return type;
        }
        string get_unite()
        /**
         * @brief get unite
         */
        {
            return unite;
        }
        
        int get_min()
        /**
         * @brief get minimum
         */
        {
            return min;
        }
        int get_max()
        /**
         * @brief get maximum
         */
        {
            return max;
        }

        void afficherInfos() {
            /**
             * @brief afficher les details
             */
            cout << "---CATEGORIE----" << endl;
            cout << " Type: " << type << endl;
            cout << " Unite en: " << unite  << endl;
            cout << " Taille Min: " << min << endl;
            cout << " Taille Max: " << max << endl;

        }

    };
}

