#include "pugixml.hpp"
#include "config.h"
#include <iostream>
#include <string>
#include <map>
#include <time.h>

pugi::xml_document doc;   // load xml file 
std::map<std::string, pugi::xml_node> xmlMap; // store handler

int xmlOpen( char *configFile ){
    pugi::xml_parse_result result = doc.load_file(configFile);     
    if (!result) {
        std::cout << "Error XML: File open error." << std::endl;
        return -1;
    }
    return 0;
}

int xmlHandleCreate(char *xmlHandle, char *configEntity ){
    pugi::xml_node node = doc.first_element_by_path(configEntity, ':');
    if (node == NULL) {
        std::cout << "Error Path: " << configEntity <<  "not found." << std::endl;
        return -1;
    }
    std::string str(xmlHandle);
    xmlMap.insert( std::pair<std::string, pugi::xml_node>(str, node));

    return 0; 
}

void xmlHandleDelete(char *xmlHandle){
     std::string str(xmlHandle);
     xmlMap.erase(str);
}

void xmlHandleMove(char *xmlHandle, char *configEntity){
     std::string str(xmlHandle);
     pugi::xml_node data = xmlMap[str];
     data = data.first_element_by_path(configEntity, ':');
}

int xmlConf(char *xmlHandle, char *configEntity, char *attrStr, char *valBuf, unsigned int bufSize)
{
    std::string str(xmlHandle);
    pugi::xml_node data = xmlMap[str];
    
    if((strchr(configEntity, ':')) != NULL){   
        char *pch = strtok(configEntity, ":");
        while (pch != NULL) {
            data = data.child(pch);
            pch = strtok(NULL, ":");
        }
    }
    else {
        data = data.child(configEntity);
    }
    if (data == NULL) {
        std::cout << "Error Path: " << configEntity << " not found." << std::endl;
        return -1;
    }

    if (data.attribute(attrStr) != NULL) {
        strncpy(valBuf, data.attribute(attrStr).value(), bufSize);
        valBuf[bufSize-1] = '\0';
    }
    else {
        std::cout << "Error: No such attribute: " << attrStr << "." << std::endl;
        return -1;
    }

    return 0;
}
