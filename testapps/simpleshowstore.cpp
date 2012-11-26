#include "ShowStore.h"
#include <iostream>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace showlab::showstore;

int main(int argc, char* argv[])
{
    Store s;
    for (auto it = s.items().begin(); it != s.items().end(); it++) {
        ShowRef show = std::static_pointer_cast<Show>(it->second);
        std::cout << show->Name() << std::endl;
        for (auto it2 = show->actions().begin(); it2 != show->actions().end(); ++it2) {
            std::cout << " - " << it2->second->Name() << std::endl;
        }
    }
 //   while (true) {}
};
