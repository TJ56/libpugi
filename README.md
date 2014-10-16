libpugi  - A Simple C API for PugiXML 
=========

PugiXML is a fast XML parser based on C++. This libpugi C API helps people to combine PugiXML with C code.

  - Input Parameter use C standard datatype
  - Pugi Document can be use in anywhere (global)
  - Fine-tune API speed and path rule


Version
----

1.0

Tech
-----------

libpugi uses open source project to work properly:

* [pugixml] - C++ XML processing library


Installation
--------------

```sh
git clone [git-repo-url] libpugi
cd libpugi
make
```

Usage
--------------
### Function
---

#### xmlOpen(path)
> Open xml file [realted or direct path]

#### xmlHandleCreate(handler, path)
> Create unique identifier handler for a path to the near by node/attribute

#### xmlHandleDelete(handler)
> Clean unique identifier handler

#### xmlConf(handler, path, attribute, buf, size_of_buf)
> Access attribute to parse value

### Notice
---

#### Speedup Parsing tips
> Its better to create more attribute than more node level, more faster while parsing.

#### Path delimiter
> use ':' as delimiter for the path while travel the xml file,
> for example "Project:Tools:Tool1" represent as a tree path from Project(root)->Tools->Tool1(node).

#### Running Example

```sh
./test_xml  // parsing attribute from xml_testing.xml
```

#### Configure file for PugiXML 

> There are serveral option inside `pugiconfig.hpp`, change config to suit purpose.


```sh
vim pugiconfig.hpp   //direct modifiy configuration 
make clean
make
```


License
----
NON



**Free Software, feel free to use it!**

[pugixml]:https://github.com/zeux/pugixml/
