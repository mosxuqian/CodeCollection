########################################################################################
#############              ���� dhcp ���ļ�                               ############## 
########################################################################################
LIST (APPEND dhcp_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/dualserverd.cpp  
    )


########################################################################################
#############               ���� dhcp ��汾��                          ############## 
########################################################################################
set(dhcp_LIB_VERSION     "1.0.0")
set(dhcp_LIB_SOVERSION   "1")

    
########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Network 
    ${PROJECT_SOURCE_DIR}/Network/DHCP
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
IF (MODULE_dhcp)

    #���ɶ�̬��  ��̬���� STATIC  
    add_library (dhcplib SHARED      ${dhcp_LIB_SRCS})  
    add_library (dhcps STATIC        ${dhcp_LIB_SRCS})  
    
    # ����������ϵ�������ǰ������ײ�Ĺ����⣬����Ҫ����
    add_dependencies (dhcplib  loglib  pthread)
    add_dependencies (dhcps    loglib  pthread)
    
    # ����Ҫ���ӵĹ�����, ���˳����Ǳ�����������ʱ˳��
    target_link_libraries (dhcplib  loglib pthread)
    target_link_libraries (dhcps    loglib pthread)

    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(dhcplib   PROPERTIES 
                                    VERSION     ${dhcp_LIB_VERSION} 
                                    SOVERSION   ${dhcp_LIB_SOVERSION} )
ELSE (MODULE_dhcp)
    MESSAGE(STATUS "Not Include dhcp module.")
ENDIF (MODULE_dhcp)




########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_dns)
    add_executable(TestDHCP.elf    dhcpTest.cpp)
    add_dependencies(TestDHCP.elf          dhcplib loglib pthread)
    target_link_libraries(TestDHCP.elf     dhcplib loglib pthread)

ELSE (TEST_MODULE_FLAG AND MODULE_dns)
    MESSAGE(STATUS "Not Include dhcp module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_dns)
