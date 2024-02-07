#include <iostream>

#include "plant.h"
#include "garden.h"

using namespace std;

int main()
{
    double garden_width;
    double garden_height;
    double rotation_angle;

garden:
    cout << "Garden width: ";
    cin >> garden_width;
    cout << "Garden height: ";
    cin >> garden_height;
    cout << "Rotation angle: ";
    cin >> rotation_angle;
    if (garden_width <= 0 || garden_height <= 0 || rotation_angle < 0)
    {
        cout << "The values should be: width > 0, height > 0 rotarion angle >= 0" << endl;
        goto garden;
    }

    Garden garden(garden_width, garden_height, rotation_angle);

    int figura_number;
    double instance1;
    double instance2 = 0;

    do
    {
        cout << "To fill the garden you have to choose the shape of the bushes:\n"
             << "1 = Oval\n"
             << "2 = Circle\n"
             << "3 = Triangle\n"
             << "4 = Hexagon\n ";
        cout << "Your choice: ";
        cin >> figura_number;

        if (figura_number == 1)
        {
            cout << "Small radius: ";
            cin >> instance1;
            cout << "Big radius: ";
            cin >> instance2;
            if (instance1 <= 0 || instance2 <= 0)
            {
                cout << "The values should be: small radius > 0, big radius > 0" << endl;
            }
        }
        else if (figura_number > 1 && figura_number < 5)
        {
            cout << "Side or radius: ";
            cin >> instance1;
            if (instance1 <= 0)
            {
                cout << "The value should be greater than 0" << endl;
            }
        }
        else
        {
            cout << "The values should be: 5 > figure number > 0" << endl;
        }
    } while ((figura_number == 1 && (instance1 <= 0 || instance2 <= 0)) || (figura_number > 1 && figura_number < 5 && instance1 <= 0) || (figura_number <= 0 || figura_number >= 5));

    Plant *plant;
    if (instance2 == 0)
        plant = new Plant(figura_number, instance1);
    else
        plant = new Plant(instance1, instance2);

    garden.fill_garden(*plant);

    double xy_garden_center[2];
    double xy_bush_center[2];

    garden.garden_geometric_center(xy_garden_center);
    garden.bush_geometric_center(xy_bush_center, *plant);

    cout << endl;
    cout << "Plants in garden: " << garden.plants_in_garden() << endl;
    cout << "Points of the geometric center of the garden: "
         << "X:" << xy_garden_center[0] << " Y:" << xy_garden_center[1] << endl;
    cout << "Points of the geometric center of the bushes: "
         << "X:" << xy_bush_center[0] << " Y:" << xy_bush_center[1] << endl;
    cout << "Bushes fill " << garden.filling_area_in_percentages() << " percent of the garden" << endl;
    cout<<endl;

    delete plant;

    return 0;
}
