// IRC SERVER
#include <cstdio>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "tcp_connection.h"
#include "tcp_server.h"

using boost::asio::ip::tcp;

int main()
{
  // start of communications to all clients and other servers
  try {
    boost::asio::io_service io_service;
    tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[2]));

    tcp_server server(io_service);

    // TODO either connect to another server or be the first server : SERVER <servername> <hopcount <info>
    // TODO SQUIT for ending the server : SQUIT <comment>

    io_service.run();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
