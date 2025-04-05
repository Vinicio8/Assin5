#include "user.h"

// Constructor
User::User(const std::string& name) 
    : _name(name), _size(0), _capacity(5) {
    _friends = new std::string[_capacity];
}

// Destructor
User::~User() {
    delete[] _friends;
}

// Copy constructor
User::User(const User& user) 
    : _name(user._name), _size(user._size), _capacity(user._capacity) {
    _friends = new std::string[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _friends[i] = user._friends[i];
    }
}

// Copy assignment operator
User& User::operator=(const User& user) {
    if (this == &user) return *this;
    
    delete[] _friends;
    
    _name = user._name;
    _size = user._size;
    _capacity = user._capacity;
    
    _friends = new std::string[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _friends[i] = user._friends[i];
    }
    
    return *this;
}

// Add friend function
void User::add_friend(const std::string& friend_name) {
    if (_size == _capacity) {
        _capacity *= 2;
        std::string* new_friends = new std::string[_capacity];
        for (size_t i = 0; i < _size; i++) {
            new_friends[i] = _friends[i];
        }
        delete[] _friends;
        _friends = new_friends;
    }
    
    _friends[_size++] = friend_name;
}

// Set friend function (needed for tests)
void User::set_friend(size_t index, const std::string& friend_name) {
    if (index < _size) {
        _friends[index] = friend_name;
    }
}

// Get name function (needed for tests)
std::string User::get_name() const {
    return _name;
}

// += operator (add friend)
User& User::operator+=(User& rhs) {
    // Add rhs's name to this user's friends
    this->add_friend(rhs._name);
    
    // Add this user's name to rhs's friends
    rhs.add_friend(this->_name);
    
    return *this;
}

// < operator (comparison)
bool User::operator<(const User& rhs) const {
    return _name < rhs._name;
}

// << operator (print)
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User(name=" << user._name << ", friends=[";
    
    for (size_t i = 0; i < user._size; i++) {
        os << user._friends[i];
        if (i < user._size - 1) {
            os << ", ";
        }
    }
    
    os << "])";
    
    return os;
}
