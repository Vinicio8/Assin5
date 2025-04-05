#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
public:
    User(const std::string& name);
    
    // Big Five
    ~User(); // Destructor
    User(const User& user); // Copy constructor
    User& operator=(const User& user); // Copy assignment
    User(User&& user) = delete; // Move constructor (deleted)
    User& operator=(User&& user) = delete; // Move assignment (deleted)
    
    // Member functions
    void add_friend(const std::string& friend_name);
    void set_friend(size_t index, const std::string& friend_name);
    std::string get_name() const;
    
    // Operators
    User& operator+=(User& rhs);
    bool operator<(const User& rhs) const;
    
    // Friend operators
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    
private:
    std::string _name;
    std::string* _friends;
    size_t _size;
    size_t _capacity;
};

#endif // USER_H
