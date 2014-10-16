#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "config.h"


int main(int argc, char const* argv[])
{
    int rc = 0;
    char result[50];
    char *topHandle = "top"; // Given an unique identifier name for the Handler 

    xmlHandleDelete(topHandle);
    rc = xmlOpen("xml_testing.xml");
    if (rc != 0) {   //xml parse status OK = 0
        printf("xml parse status error\n");
        return 0;
    }

    rc = xmlHandleCreate(topHandle, "Profile:Tools");   // Create handler for a path to the near by node/attribute
    if (rc != 0) {   
        printf("xml parse status error\n");
        return 0;
    }

    rc = xmlConf(topHandle, "Tool1", "Filename", result, sizeof(result));   // Access attribute to parse value out
    if (rc != 0) {   
        printf("xml parse status error\n");
        return 0;
    }

    printf("Result 1 = %s\n",  result);
    
    rc = xmlConf(topHandle, "Tool2", "AllowRemote", result, sizeof(result));   // Access attribute to parse value out
    if (rc != 0) {   
        printf("xml parse status error\n");
        return 0;
    }

    xmlHandleDelete(topHandle);  // Clean this unique identifier handler 

    printf("Result 2 = %s\n",  result);

    
    return 0;
}
