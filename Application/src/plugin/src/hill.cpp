#include "hill.hpp"

using namespace kanzi;

HillSharedPtr Hill::create(Domain* domain, string_view name)
{
    HillSharedPtr dataSourcePlugin(new Hill(domain, name));

    dataSourcePlugin->initialize();

    return dataSourcePlugin;
}

kanzi::DataObjectSharedPtr Hill::getData()
{
    return m_root;
}

void Hill::initialize()
{
    // Initialize base class.
    DataSource::initialize();

    Domain* domain = getDomain();

    // Construct a data model for the data source. A data model is a tree of data objects.
    // For example, to use the data from a data source you can bind the values of properties in your Kanzi application to these data objects.
    m_root = make_shared<DataObject>(domain, "Root");

    // Here is an example of how to create an integer, a string, and a float data object.
    // Replace these data objects with your own data model.
    m_root->addChild(make_shared<DataObjectInt>(domain, "integer value", 1));
    m_root->addChild(make_shared<DataObjectString>(domain, "string value", "data value"));
    m_root->addChild(make_shared<DataObjectReal>(domain, "float value", 0.5f));
}
