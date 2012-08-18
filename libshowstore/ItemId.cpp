#include "ItemId.h"
#include <boost/uuid/uuid_io.hpp>
#include <boost/regex.hpp>
#include <sstream>

namespace showlab {
namespace showstore {

ItemId::ItemId()
{
    static boost::uuids::basic_random_generator<boost::mt19937> gen;
    mId = gen();
}

ItemId::ItemId(std::string str_id)
{
    std::istringstream s(str_id);
    s >> mId;
}

std::string ItemId::str()
{
    std::ostringstream s;
    s << mId;
    return s.str();
}

bool ItemId::isValidId(std::string id)
{
    static boost::regex id_regex("^[a-z0-9]{8}-[a-z0-9]{4}-[a-z0-9]{4}-[a-z0-9]{4}-[a-z0-9]{12}$");
    return boost::regex_match(id, id_regex);
}

}}
