/*
This file is part of the SSL Wrapper Library (libSSL)

libSSL is free software : you can redistribute it and / or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License.

libSSL is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
libSSL.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ISOCKETLAYER_H
#define ISOCKETLAYER_H
#include <string>
#include <iSocket.h>
#include <iSocketAdaptor.h>


namespace libSSL
{
namespace socketlayer
{


class iSocketLayer
{
public:
    virtual ~iSocketLayer() {}

    virtual iSocket *CreateSocket( SockType type ) = 0;

    virtual std::string ConvertDomainNameToIP( std::string domain ) = 0;

    virtual AddressFamily GetAddressFamily() = 0;
};

}   //  namespace socketlayer
}   //  namespace libSSL

#endif  //  #ifndef ISOCKETLAYER_H
