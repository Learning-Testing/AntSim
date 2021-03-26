#pragma once
#include <string>


class Object
{
protected:
	// Object(int h, int x, int y, int z, int u) : health(h), x_size(x), y_size(y), z_size(z), uid(u) {}

	int health;
	int x_size;
	int y_size;
	int z_size;
	int uid;

public:

	//virtual ~Object() {};
	//virtual void info() = 0;

	void set_health(int h)
	{
		health = h;
	}

	int get_health()
	{
		return health;
	}

	void set_x_size(int xs)
	{
		x_size = xs;
	}

	int get_x_size()
	{
		return x_size;
	}

	void set_y_size(int ys)
	{
		y_size = ys;
	}

	int get_y_size()
	{
		return y_size;
	}

	void set_z_size(int zs)
	{
		z_size = zs;
	}

	int get_z_size()
	{
		return z_size;
	}

	/*void set_uid_name(std::string name)
	{
		uid.first = name;
	}

	std::string get_uid_name()
	{
		return uid.first;
	}*/
};


class Insect : public Object
{
protected:
	//Insect(int movement_speed, int carrying_capacity) : Object(health, x_size, y_size, z_size, uid) {}

	int movement_speed;
	int carrying_capacity;

public:
	void set_movespeed(int mspeed)
	{
		movement_speed = mspeed;
	}

	int get_movespeed()
	{
		return movement_speed;
	}

	void set_carry_cap(int cc)
	{
		carrying_capacity = cc;
	}

	int get_carry_cap()
	{
		return carrying_capacity;
	}
};


class Ant : public Insect
{
public:
	Ant() { 
		//set_uid_name("ant");
		set_health(100); 
		set_movespeed(1); 
		set_carry_cap(25); 
		set_x_size(1);
		set_y_size(1);
		set_z_size(1); }
};

class Tree : public Object
{
public:
	Tree() { 
		//set_uid_name("tree");
		set_x_size(15); 
		set_z_size(15); 
		set_y_size(20); }
};



class Cockroach : public Insect
{
	;
};

