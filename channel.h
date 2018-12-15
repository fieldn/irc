
#include <string>
#include <vector>
#include <time.h>
#include <client.h>

class Channel {
  std::string name;     // Restrictions:
                        //  - max length of 200 chars, 
                        //  - first char & or #
                        //  - no spaces/commas/^G
  time_t creation_time;
  std::string topic;
  std::vector<Client> client_list; // list of clients connected.
                                   // The channel lives only as long as
                                   // clients are connected
  Client chop;  // channel operator (owner) has special permissions 
  std::string password; // channel's password; can be empty
}
