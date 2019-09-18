#ifndef STATS_H
#define STATS_H

class Stats {
public:
	// Constructor/destructor
	Stats();
	~Stats();

	// Accessors or Getters
	void display() const;

	// Mutators or Setters
	bool record(int r, int c, int val);

private:
	char **s_world; // array for char values
	int **i_world; // array for int values

	// TODO: You will need to determine what structure is appropriate
};

#endif

