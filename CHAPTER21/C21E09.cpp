// CHAPTER 21 EX 09

// Define an Order class with (customer) name, address, data, and vector<Purchase> members. Purchase is a class with a (product) name, unit_price, and count members.
// Define a mechanism for reading and writing Orders to and from a file.
// Define a mechanism for printing Orders.
// Create a file of at least 10 Orders, read it into a vector<Order>, sort it by name (of customer), and write it back out to a file.
// Create another file of at least 10 Orders of which about 1/3 are the same as in the first file, read it into a list<Order>, sort it by address
// (of customer), and write it back out to a file. Merge the 2 files into a third using std::merge().