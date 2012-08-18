#include "StorePath.h"
#include <boost/algorithm/string.hpp>

namespace showlab {
namespace showstore {

StorePath::StorePath(std::string path)
{
    std::vector<std::string> strs;
    boost::split(strs, path, boost::is_any_of("/\\"), 
              boost::algorithm::token_compress_on);
             
    for (auto it = strs.begin(); it != strs.end(); ++it) {
        if (*it != "") {
            if (ItemId::isValidId(*it)) {
                mParts.push_back(new IdPathPart(ItemId(*it)));
            }
            else {
                mParts.push_back(new KeyPathPart(*it));
            }
        }
    }
}

StorePath::~StorePath()
{
    for (auto it = mParts.begin(); it != mParts.end(); ++it) {
        delete *it;
    }
}

}}
