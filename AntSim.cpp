// AntSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "objectclasses.h"
#include "world.h"

#include <Windows.h>


void assign_to_map(World mainworld)
{
    mainworld.all_coordinates;
}

int main()
{
    World mainworld;

    mainworld.create_world();

    std::vector<Object> objects_vect;
    Ant ant1;
    objects_vect.push_back(ant1);

    Tree tree1;
    objects_vect.push_back(tree1);

    int x_num = 1;



    for (const auto &coordinate : mainworld.all_coordinates)
    {
        std::cout << coordinate.first.x_coord << " " << coordinate.first.y_coord << " " << coordinate.first.z_coord << "\n";
    }

    //mainworld.all_coordinates.at(Coord(0, 0, 0));

    /*while (ant1.get_loc().get_x() < 99) 
    {
        if mainworld.all_coordinates
        ant1.set_loc(x_num++, 0, 0);
        std::cout << ant1.get_loc().get_x() << ", " << ant1.get_loc().get_y() << ", " << ant1.get_loc().get_z() << "\n";
        //Sleep(1000); // 1000 milliseconds = 1 second
    }
    std::cout << ant1.get_health();*/
}

// World is a dict of Coords with each coord having a null value. Each object has it's own coords. 
// When setting coords of an object TO world, first check an object doesn't exist in that space, then assign the object coords to that location in world