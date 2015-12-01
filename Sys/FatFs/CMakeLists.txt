########################################################################################
#############                ���� FatFs ���ļ�                         ############## 
########################################################################################
LIST (APPEND FatFs_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/ff.c
    ${CMAKE_CURRENT_SOURCE_DIR}/diskio.c
    )
    
    

########################################################################################
#############                ���� FatFs ��汾��                       ############## 
########################################################################################
set(FatFs_LIB_VERSION     "1.0.0")
set(FatFs_LIB_SOVERSION   "1")




########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Systerm
    ${PROJECT_SOURCE_DIR}/Systerm/FatFs
    ${PROJECT_SOURCE_DIR}/Systerm/FatFs/option
)  



########################################################################################
#############               ���� ���ӿ��ļ�Ŀ¼                           ############## 
########################################################################################
link_directories(  
    /usr/local/lib   
    )  

    

########################################################################################
#############           ����Ŀ����ļ� �� �����汾��                      ############## 
########################################################################################
IF (MODULE_FatFs)
    #���ɶ�̬��  ��̬���� STATIC  
    add_library (FatFslib SHARED      ${FatFs_LIB_SRCS})  
    add_library (FatFss STATIC        ${FatFs_LIB_SRCS})  
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(FatFslib   PROPERTIES 
                                        VERSION     ${FatFs_LIB_VERSION} 
                                        SOVERSION   ${FatFs_LIB_SOVERSION} )
ELSE (MODULE_FatFs)
    MESSAGE(STATUS "Not Include FatFs module.")
ENDIF (MODULE_FatFs)




########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_FatFs)
    add_executable(TestFatFs.elf    FatFsTest.c)
    add_dependencies(TestFatFs.elf          FatFslib loglib)
    target_link_libraries(TestFatFs.elf     FatFslib loglib)

ELSE (TEST_MODULE_FLAG AND MODULE_FatFs)
    MESSAGE(STATUS "Not Include mount Mini UPnP daemon module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_FatFs)