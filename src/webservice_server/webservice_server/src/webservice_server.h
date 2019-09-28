// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef WEBSERVICE_SERVER_H
#define WEBSERVICE_SERVER_H

#include <ngrest/common/Service.h>

//! Dummy description for the service
/*! Some detailed description of the service */
// '*location' comment sets resource path for this service
// *location: webservice_server
class webservice_server: public ngrest::Service
{
public:
    // Here is an example of service operation
    //! Dummy description for the operation
    /*! Some detailed description of the operation */
    // To invoke this operation from browser open: http://localhost:9098/webservice_server/World!
    //
    // '*location' metacomment sets path to operation relative to service operation.
    // Default value is operation name.
    // This will bind "echo" method to resource path: http://host:port/webservice_server/{text}
    // *location: /{text}
    //
    // '*method' metacomment sets HTTP method for the operation. GET is default method.
    // *method: GET
    //
    std::string echo(const std::string& text);

	int add (int a, int b);
};


#endif // WEBSERVICE_SERVER_H


