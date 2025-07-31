#include "passserver.h"
#include <crypt.h>    
#include <fstream>   
#include <iostream>
#include <string>
#include <utility>

using namespace std;
using namespace cop4530;

PassServer::PassServer(size_t size) : table(size) {}

PassServer::~PassServer() {}

bool PassServer::load(const char *filename)
{
    return table.load(filename);
}

bool PassServer::addUser(pair<string,  string> & kv)
{
    auto user = make_pair(kv.first, encrypt(kv.second));
    return table.insert(user);
}

bool PassServer::addUser(pair<string, string> && kv)
{
    auto user = make_pair(kv.first, encrypt(kv.second));
    return table.insert(user);
}

bool PassServer::removeUser(const string & k)
{
    return table.remove(k);
}

bool PassServer::changePassword(const pair<string, string> &p, const string & newpassword)
{
    string epassword = encrypt(p.second);
    string enpassword = encrypt(newpassword);
    
    if(epassword != enpassword && find(p.first))
    {
        //auto kv = make_pair(p.first, epassword);
        if(table.match(make_pair(p.first, epassword)))
        {
            //auto newkv = make_pair(p.first, enpassword);
            table.insert(make_pair(p.first, enpassword));
            return true;
        }
    }
    return false;
}

bool PassServer::find(const string & user) const
{
    return table.contains(user);
}

void PassServer::dump()
{
    table.dump();
}

size_t PassServer::size() const
{
    return table.size();
}

bool PassServer::write_to_file(const char *filename) const
{
    return table.write_to_file(filename);
}

string PassServer::encrypt(const string & str)
{
    const char salt[] = "$1$########";
    char *e = crypt(str.c_str(), salt);

    if(e) 
    {
        string result(e);
        size_t pos = result.find_last_of('$');  
        return result.substr(pos + 1);         
    }

    return "";
}
