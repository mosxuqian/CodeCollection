########################################################################################
#############              ���� hashtablecpp ���ļ�                               ############## 
########################################################################################
LIST (APPEND hashtablecpp_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/HTAB.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/
    )



########################################################################################
#############               ���� hashtablecpp ��汾��                          ############## 
########################################################################################
set(hashtablecpp_LIB_VERSION     "1.0.0")
set(hashtablecpp_LIB_SOVERSION   "1")



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
IF (MODULE_hashtablecpp)

    #���ɶ�̬��  ��̬���� STATIC  
    add_library (hashtablecpplib     SHARED      ${hashtablecpp_LIB_SRCS})  
    add_library (hashtablecpps       STATIC        ${hashtablecpp_LIB_SRCS})  
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(hashtablecpplib    PROPERTIES 
                                        VERSION     ${hashtablecpp_LIB_VERSION} 
                                        SOVERSION   ${hashtablecpp_LIB_SOVERSION} )
ELSE (MODULE_hashtablecpp)
    MESSAGE(STATUS "Not Include hashtablecpp module.")
ENDIF (MODULE_hashtablecpp)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_hashtablecpp)
    add_executable(TestHashTableCpp.elf  hashtablecppTest.cpp)
    add_dependencies(TestHashTableCpp.elf        hashtablecpplib  loglib)
    target_link_libraries(TestHashTableCpp.elf   hashtablecpplib  loglib )

ELSE (TEST_MODULE_FLAG AND MODULE_hashtablecpp)
    MESSAGE(STATUS "Not Include hashtablecpp module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_hashtablecpp)



