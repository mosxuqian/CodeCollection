########################################################################################
#############              ���� zsort ���ļ�                               ############## 
########################################################################################
LIST (APPEND zsort_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/ZSort.c
#    ${CMAKE_CURRENT_SOURCE_DIR}/
    )



########################################################################################
#############               ���� zsort ��汾��                          ############## 
########################################################################################
set(zsort_LIB_VERSION     "1.0.0")
set(zsort_LIB_SOVERSION   "1")



########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Settings
    ${PROJECT_SOURCE_DIR}/Settings/HashTableCpp
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
IF (MODULE_zsort)

    #���ɶ�̬��  ��̬���� STATIC  
    add_library (zsortlib     SHARED      ${zsort_LIB_SRCS})  
    add_library (zsorts       STATIC        ${zsort_LIB_SRCS})  
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(zsortlib    PROPERTIES 
                                        VERSION     ${zsort_LIB_VERSION} 
                                        SOVERSION   ${zsort_LIB_SOVERSION} )
ELSE (MODULE_zsort)
    MESSAGE(STATUS "Not Include zsort module.")
ENDIF (MODULE_zsort)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_zsort)
    add_executable(TestZSort.elf  zsortTest.c)
    add_dependencies(TestZSort.elf        zsortlib  loglib)
    target_link_libraries(TestZSort.elf   zsortlib  loglib )

ELSE (TEST_MODULE_FLAG AND MODULE_zsort)
    MESSAGE(STATUS "Not Include jsoncpp module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_zsort)



