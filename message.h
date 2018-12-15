// shared by the client and server
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <regex>

public class Message {
  // message [':' <prefix> <SPACE> ] <command> <params> <crlf>
  std::string prefix; // (optional) 
                      // <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
  std::string command;// <letter> {letter} | <number> <number> <number>
  std::vector<std::string> params; // command parameters (up to 15)

  Message(std::string msg) {
    std::regex rgx("\\s+");
    std::sregex_token_iterator iter(msg.begin(), msg.end(), rgx, -1);
    std::sregex_token_iterator end;
    // TODO add support for prefix later
    command = *(++iter);
    for ( ; iter != end; ++iter) {
      if (*iter.length() > 0)
        params.push_back(*iter);
    }
  }

  void print();
}

void Message::print() {
  std::cout <<   "PREFIX:  " << prefix 
            << "\nCOMMAND: " << command 
            << "\nPARAMS:  ";
  for (std::string s : params) {
    std::cout << s << " ";
  }
}
