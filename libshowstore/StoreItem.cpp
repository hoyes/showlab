#include "StoreItem.h"
#include <memory>

namespace showlab {
namespace showstore {

void StoreItem::resolveRefs()
{
    resolveRefsFromItem(this, mConfig); 
    for (auto it = mChildren.begin(); it != mChildren.end(); ++it) {
        it->second->resolveRefs();
    }
}

void StoreItem::resolveRefsFromItem(StoreItem* item, ConfigNodeRef config)
{
    switch (config->type()) {
        case (TYPE_REF): {
            RefConfigNodeRef node = std::static_pointer_cast<RefConfigNode>(config);
            if (!node->resolved()) {
                auto it = item->items().find(node->id());
                if (it == mChildren.end()) {
                    for (auto it = mChildren.begin(); it != mChildren.end(); ++it) {
                        resolveRefsFromItem(it->second.get(), config);
                    }
                }
                else {
                    node->resolve(it->second);
                }
            }
            break;
        }
        case (TYPE_LIST): {
            ListConfigNodeRef node = std::static_pointer_cast<ListConfigNode>(config);
            for (auto it = node->begin(); it != node->end(); it++) {
                resolveRefsFromItem(item, *it);
            }
            break;
        }
        case (TYPE_MAP): {
            MapConfigNodeRef node = std::static_pointer_cast<MapConfigNode>(config);
            for (auto it = node->begin(); it != node->end(); it++) {
                resolveRefsFromItem(item, it->second);
            }
            break;
        }
        case TYPE_NULL:
        case TYPE_SCALAR:
            break;
    }
}

}}
