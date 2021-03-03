#ifndef HILL_MODULE_HPP
#define HILL_MODULE_HPP

#include <kanzi/core/module/plugin.hpp>

class HillModule: public kanzi::Plugin
{
public:

    static void registerModule(kanzi::Domain* domain);

protected:

    virtual MetaclassContainer getMetaclassesOverride() KZ_OVERRIDE;
};

#endif
