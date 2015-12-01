########################################################################################
#############              ���� LwIP ���ļ�                               ############## 
########################################################################################
LIST (APPEND LwIP_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/LwIP.c  
    )

    

########################################################################################
#############               ���� LwIP ��汾��                          ############## 
########################################################################################
set(LwIP_LIB_VERSION     "1.0.0")
set(LwIP_LIB_SOVERSION   "1")

    
    
########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Network
    ${PROJECT_SOURCE_DIR}/Network/LwIP
    ${PROJECT_SOURCE_DIR}/Network/LwIP/src/include
    ${PROJECT_SOURCE_DIR}/Network/LwIP/system/OS
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
IF (MODULE_LwIP)

    #���ɶ�̬��  ��̬���� STATIC  
    add_library (LwIPlib SHARED      ${LwIP_LIB_SRCS})  
    add_library (LwIPs STATIC        ${LwIP_LIB_SRCS})  
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(LwIPlib   PROPERTIES 
                                    VERSION     ${LwIP_LIB_VERSION} 
                                    SOVERSION   ${LwIP_LIB_SOVERSION} )
ELSE (MODULE_LwIP)
    MESSAGE(STATUS "Not Include LwIP module.")
ENDIF (MODULE_LwIP)





########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_LwIP)
    add_executable(TestSNTP.elf    LwIPTest.c)
    add_dependencies(TestSNTP.elf          LwIPlib loglib )
    target_link_libraries(TestSNTP.elf     LwIPlib loglib )

ELSE (TEST_MODULE_FLAG AND MODULE_LwIP)
    MESSAGE(STATUS "Not Include LwIP module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_LwIP)


