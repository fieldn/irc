#include "client.h"

/***************************************************
 *
 * General operations everyone can run
 *
 **************************************************/
void Client::join(std::string channel, std::string password) {
  // join a channel, with optional password
  Message m = new Message();
  c.write(/*msg*/);
}

void Client::topic(std::string channel, std::string topic) {
  // list the channel's topic string
  Message m = new Message();
  c.write(/*msg*/);
}

void Client::names(std::string channel) {
  // list all the users connected to the channel
  Message m = new Message();
  c.write(/*msg*/);
}

void Client::list(std::string channel) {
  // list all channels and topics; list only channel if channel is specified
  Message m = new Message();
  c.write(/*msg*/);
}

/***************************************************
 *
 * Operations only channel operator can run (ish)
 *
 **************************************************/
void Client::invite(std::string nickname, std::string channel) {

}

void Client::kick(std::string channel, std::string user) {

}

int main(int argc, char* argv[])
{
  try {
    if (argc != 3) {
      std::cerr << "Usage: irc_client <host> <port>\n";
      return 1;
    }

    boost::asio::io_service io_service;

    tcp::resolver resolver(io_service);
    auto endpoint_iterator = resolver.resolve({ argv[1], argv[2] });
    client c(io_service, endpoint_iterator);

    std::thread t([&io_service](){ io_service.run(); });

    // TODO send PASS msg : PASS <password>
    // TODO send NICK msg : NICK <nickname>
    // TODO send USER msg : USER <uname> <hostname> <servername> <realname>

    // TODO send OPER msg : OPER <user> <password>
    
    
    // TODO send QUIT msg at end : QUIT

    char line[chat_message::max_body_length + 1];
    while (std::cin.getline(line, chat_message::max_body_length + 1)) {
      chat_message msg;
      msg.body_length(std::strlen(line));
      std::memcpy(msg.body(), line, msg.body_length());
      msg.encode_header();
      c.write(msg);
    }

    c.close();
    t.join();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
