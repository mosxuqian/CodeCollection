########################################################################################
#############              ���� sntplib ���ļ�                               ############## 
########################################################################################
LIST (APPEND sntplib_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/sntp.c  
    )

    

########################################################################################
#############               ���� sntplib ��汾��                          ############## 
########################################################################################
set(sntplib_LIB_VERSION     "1.0.0")
set(sntplib_LIB_SOVERSION   "1")

    
    
########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Network
    ${PROJECT_SOURCE_DIR}/Network/SNTPlib
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
IF (MODULE_sntplib)

    #���ɶ�̬��  ��̬���� STATIC  
    add_library (sntpliblib SHARED      ${sntplib_LIB_SRCS})  
    add_library (sntplibs STATIC        ${sntplib_LIB_SRCS})  
        
    # ����������ϵ�������ǰ������ײ�Ĺ����⣬����Ҫ����
    add_dependencies (sntpliblib  loglib  m)
    add_dependencies (sntplibs    loglib  m)
    
    # ����Ҫ���ӵĹ�����, ���˳����Ǳ�����������ʱ˳��
    target_link_libraries (sntpliblib  loglib m)
    target_link_libraries (sntplibs    loglib m)
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(sntpliblib   PROPERTIES 
                                    VERSION     ${sntplib_LIB_VERSION} 
                                    SOVERSION   ${sntplib_LIB_SOVERSION} )
ELSE (MODULE_sntplib)
    MESSAGE(STATUS "Not Include sntplib module.")
ENDIF (MODULE_sntplib)





########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_sntplib)
    add_executable(TestSNTPlib.elf    sntpliblibTest.c)
    add_dependencies(TestSNTPlib.elf          sntpliblib loglib m)
    target_link_libraries(TestSNTPlib.elf     sntpliblib loglib m)

ELSE (TEST_MODULE_FLAG AND MODULE_sntplib)
    MESSAGE(STATUS "Not Include sntplib module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_sntplib)


