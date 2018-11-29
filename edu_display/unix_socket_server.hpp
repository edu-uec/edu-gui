#ifndef UNIX_SOCKET_SERVER_HPP
#define UNIX_SOCKET_SERVER_HPP

#include <boost/asio.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>
#include <iostream>

namespace asio = boost::asio;
using asio::local::stream_protocol;

class UnixSocketServer
{
  private:
    asio::io_service &io_service_;
    stream_protocol::socket socket_;
    stream_protocol::acceptor acceptor_;
    asio::streambuf receive_buff_;
    boost::system::error_code error;

  public:
    boost::signals2::signal<void(std::string command)> commandArriveEvent;

    UnixSocketServer(asio::io_service &io_service)
        : io_service_(io_service),
          socket_(io_service),
          acceptor_(io_service, stream_protocol::endpoint("/tmp/unix_socket_test"))
    {
    }
    void accept()
    {
        acceptor_.accept(socket_);
    }
    void read()
    {
        if (asio::read_until(socket_, receive_buff_, '!', error))
        {
            if (error && error != asio::error::eof)
            {
                std::cout << "receive failed: " << error.message() << std::endl;
            }
            else
            {
                const char *data = asio::buffer_cast<const char *>(receive_buff_.data());
                std::string dataString = data;
                std::vector<std::string> splitedResult;
                boost::algorithm::split(splitedResult, dataString, boost::is_any_of("!"));
                //std::cout << splitedResult[0] << std::endl;
                commandArriveEvent(splitedResult[0]);
            }
            receive_buff_.consume(receive_buff_.size());
        }
    }
};

#endif
