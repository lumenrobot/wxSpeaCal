//!****************************************************************************
//! \file client.h
//! \author msantamaria
//!****************************************************************************

#ifndef CLIENT_H__
#define CLIENT_H__

#include <iostream>
#include <boost/asio.hpp>

struct client {

	/*client( boost::asio::io_service& io_s )
	: io_service_(io_s),
	  socket_( io_s) { }

	~client() { }

	void connect( int argc, char** argv ) {
	    if( argc == 3 )
	    	connect_( argv[1], argv[2] );
	    else if( argc == 2 )
	    	connect_( argv[1], "45000" );
	    else
			connect_("127.0.0.1", "45000");
	}

	boost::asio::ip::tcp::socket& socket() {
		return socket_;
	}


private:
	boost::asio::io_service& io_service_;
	boost::asio::ip::tcp::socket socket_;

	void connect_( std::string const & host_ip, std::string const & host_port ) {
		try {
			boost::asio::ip::tcp::resolver resolver( io_service_ );
			boost::asio::ip::tcp::resolver::query query( boost::asio::ip::tcp::v4(),
														 host_ip, host_port );
			boost::asio::ip::tcp::resolver::iterator it = resolver.resolve( query );

			socket_.connect( *it );
		}
		catch( std::exception e ) {
			std::string s("connection error to " + host_ip + ":" + host_port + " | " + e.what() );
			throw std::runtime_error( s );
		}
	}*/
};

#endif


