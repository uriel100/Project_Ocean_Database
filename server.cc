#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_service io_service;

        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1300));

        tcp::socket socket(io_service);
        acceptor.accept(socket);


        for (;;) {
            boost::array<char, 128> buf;
            boost::system::error_code error;
            size_t len = socket.read_some(boost::asio::buffer(buf), error);


            std::string message;

            if (buf[0] == '0' ) { // penguing
                message = "Hi";
            } else if (buf[0] == '1') { // shark
                message = "dangerous ";
            } else {
                message = "sorry choose something else";
            }


            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
