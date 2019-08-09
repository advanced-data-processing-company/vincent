#ifndef HTTP_H
#define HTTP_H
#include "config/config.h"
namespace adpc {
class http {
public:
  http();
  ~http();
  /*
   * apis used by client
   */
  bool sendRequest(void (*func)(char *response)) const;

private:
  bool connectServer() const;
};

} // namespace adpc

#endif // HTTP_H
