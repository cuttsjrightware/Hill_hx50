#include "hill_module.hpp"
#include "hill.hpp"

using namespace kanzi;

void HillModule::registerModule(Domain* domain)
{
    domain->registerModule<HillModule>("Hill");
}

HillModule::MetaclassContainer HillModule::getMetaclassesOverride()
{
    MetaclassContainer metaclasses;
    metaclasses.push_back(Hill::getStaticMetaclass());
    return metaclasses;
}

#if defined(KANZI_API_IMPORT) || defined(ANDROID)

extern "C"
{

HILL_API Module* createModule(uint32_t /*kanziVersionMajor*/, uint32_t /*kanziVersionMinor*/)
{
    return new HillModule;
}

}

#endif
