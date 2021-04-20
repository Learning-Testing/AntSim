#pragma once
#include <unordered_map>
#include <iostream>

#include "objectclasses.h"

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/indexed_by.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/mem_fun.hpp>

namespace bmi = boost::multi_index;

class Coord
{

public:

	Coord() {}

	int x_coord = 0;
	int y_coord = 0;
	int z_coord = 0;

	// operator== is required to compare keys in case of hash collision
	bool operator==(Coord const& p) const
	{
		return (x_coord == p.x_coord && y_coord == p.y_coord && z_coord == p.z_coord);
	}


	void set_xyz(int x, int y, int z)
	{
		x_coord = x;
		y_coord = y;
		z_coord = z;
	}


	std::tuple<int, int, int> get_xyz()
	{
		return {x_coord, y_coord, z_coord};
	}


	/*void set_x(int x)
	{
		x_coord = x;
	}

	void set_y(int y)
	{
		y_coord = y;
	}

	void set_z(int z)
	{
		z_coord = z;
	}

	int get_x()
	{
		return x_coord;
	}

	int get_y()
	{
		return y_coord;
	}

	int get_z()
	{
		return z_coord;
	}*/
};


namespace std
	{
		template<> struct hash<Coord>
		{
			std::size_t operator() (Coord const& c) const
			{
				std::size_t result = 17;
				result = 31 * result + std::hash<int>()(c.x_coord);
				result = 31 * result + std::hash<int>()(c.y_coord);
				result = 31 * result + std::hash<int>()(c.z_coord);
				return result;
			}
		};
	};


typedef bmi::multi_index_container<
	Coord,
	bmi::indexed_by<
	bmi::hashed_unique<
	bmi::const_mem_fun<Coord, std::tuple<int, int, int>, &Coord::get_xyz>
	>
	>
> all_coordinates;


class World
{
private:
	int max_x = 10;
	int max_y = 10;
	int max_z = 10;

public:
	std::unordered_map<Coord, Object*> all_coordinates;
	//all_coordinates.reserve(max_x * max_y * max_z)

	void create_world()
	{
		for (int xval = 0; xval < max_x; xval++)
		{
			for (int yval = 0; yval < max_y; yval++)
			{
				for (int zval = 0; zval < max_z; zval++)
				{
					Coord coordinate;
					coordinate.set_xyz(xval, yval, zval);
					all_coordinates.emplace(coordinate, nullptr);
					//std::cout << xval << " " << yval << " " << zval << "\n";
				}
			}
		}
	}


	/*void update_object_loc(Coord curr_coord, Object* obj_ptr)
	{
		if (all_coordinates.at(curr_coord) == nullptr)
		{
			all_coordinates.at(curr_coord) = obj_ptr;
		}
	}

	void reset_coord(Coord curr_coord)
	{
		all_coordinates.at(curr_coord) = nullptr;
	}*/
};


/*void populate_object_area(World mainworld, Object &the_object, std::unordered_map<Coord, int> map_coords)
{
	// at the coordinate, I want to go out from the center and populate the area the object takes up

	get base coordinate
	apply object to the base coord
	for the size of the object (x,y,z) spread out in both directions for all 3, until the x/y/z_size number is met

	// need to check what value the MAP coordinate is currently holding

}*/