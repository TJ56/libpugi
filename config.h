

#ifdef __cplusplus
extern "C" {
#endif

int xmlOpen( char *configFile );
int xmlHandleCreate(char *xmlHandle, char *configEntity );
void xmlHandleDelete(char *xmlHandle);
int xmlConf(char *xmlHandle, char *configEntity, char *attrStr, char *valBuf, unsigned int bufSize);
void xmlHandleMove(char *xmlHandle, char *configEntity);


#ifdef __cplusplus
}
#endif
