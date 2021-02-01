/*
  Account.hpp

  Include file for Account class
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Stream.hpp"

#include <string>
#include <vector>

class Account {
public:

    // constructor
    Account(const std::string& name);

    // account name
    std::string name() const;

    // add a new stream
    void addStream(const Stream& stream);

    // account streaming report
    std::string report() const;

    // account data in CSV
    std::string data() const;
private:
    const std::string account_name;
    std::vector<Stream> streams;
};

#endif
