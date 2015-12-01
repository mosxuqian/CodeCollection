########################################################################################
#############              ���� tinytcp ���ļ�                               ############## 
########################################################################################
LIST (APPEND tinytcp_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/arp.c  
    ${CMAKE_CURRENT_SOURCE_DIR}/sed.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/tinyftp.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/tinytcp.c 
    )


    
########################################################################################
#############               ���� tinytcp ��汾��                          ############## 
########################################################################################
set(tinytcp_LIB_VERSION     "1.0.0")
set(tinytcp_LIB_SOVERSION   "1")


    
########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Network
    ${PROJECT_SOURCE_DIR}/Network/TinyTCP
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
IF (MODULE_tinytcp)

    #���ɶ�̬��  ��̬���� STATIC  
    add_library (tinytcplib SHARED      ${tinytcp_LIB_SRCS})  
    add_library (tinytcps STATIC        ${tinytcp_LIB_SRCS})  
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(tinytcplib   PROPERTIES 
                                        VERSION     ${tinytcp_LIB_VERSION} 
                                        SOVERSION   ${tinytcp_LIB_SOVERSION}  )
ELSE (MODULE_tinytcp)
    MESSAGE(STATUS "Not Include tinytcp module.")
ENDIF (MODULE_tinytcp)





########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_tinytcp)
    add_executable(TestTinyTCP.elf    tinytcpTest.c)
    add_dependencies(TestTinyTCP.elf          tinytcplib loglib)
    target_link_libraries(TestTinyTCP.elf     tinytcplib loglib)

ELSE (TEST_MODULE_FLAG AND MODULE_tinytcp)
    MESSAGE(STATUS "Not Include system_instrument module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_tinytcp)


