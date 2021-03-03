#ifndef HILL_HPP
#define HILL_HPP

// Use kanzi.hpp only when you are learning to develop Kanzi applications. 
// To improve compilation time in production projects, include only the header files of the Kanzi functionality you are using.
#include <kanzi/kanzi.hpp>

class Hill;
typedef kanzi::shared_ptr<Hill> HillSharedPtr;

// The template component.
class HILL_API Hill : public kanzi::DataSource
{
public:

    KZ_METACLASS_BEGIN(Hill, DataSource, "CustomDataSourceType")
    KZ_METACLASS_END()

    // Creates a DataSourcePlugin.
    static HillSharedPtr create(kanzi::Domain* domain, kanzi::string_view name);

    // Return the data model of this data source.
    kanzi::DataObjectSharedPtr getData() KZ_OVERRIDE;

protected:

    // Constructor.
    explicit Hill(kanzi::Domain* domain, kanzi::string_view name):
        DataSource(domain, name)
    {
    }

    // Initializes the created Kanzi Engine plugin.
    // Kanzi node classes typically have a static create() member function, which creates the instance of a node,
    // initializes it, and returns a shared pointer to the instance. To initialize the instance, the initialize()
    // function is called on it. You must initialize a node in the initialize() function, not in the constructor.
    void initialize();

private:

    // Data model of this data source.
    kanzi::DataObjectSharedPtr m_root;
};

#endif
