########################################################################################
#############              ���� hashtable ���ļ�                               ############## 
########################################################################################
LIST (APPEND hashtable_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/hashtable.c
#    ${CMAKE_CURRENT_SOURCE_DIR}/
    )




########################################################################################
#############               ����Դ����Ŀ¼                                ############## 
########################################################################################
#add_subdirectory( MessageHandler )
#add_subdirectory( libev )




########################################################################################
#############               ���� hashtable ��汾��                          ############## 
########################################################################################
set(hashtable_LIB_VERSION     "1.0.0")
set(hashtable_LIB_SOVERSION   "1")



########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Settings
    ${PROJECT_SOURCE_DIR}/Settings/HashTable
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
IF (MODULE_hashtable)

    #���ɶ�̬��  ��̬���� STATIC  
    add_library (hashtablelib     SHARED      ${hashtable_LIB_SRCS})  
    add_library (hashtables       STATIC        ${hashtable_LIB_SRCS})  
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(hashtablelib    PROPERTIES 
                                        VERSION     ${hashtable_LIB_VERSION} 
                                        SOVERSION   ${hashtable_LIB_SOVERSION} )
ELSE (MODULE_hashtable)
    MESSAGE(STATUS "Not Include hashtable module.")
ENDIF (MODULE_hashtable)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_hashtable)
    add_executable(TestHashTable.elf  hashtableTest.c)
    add_dependencies(TestHashTable.elf        hashtablelib  loglib)
    target_link_libraries(TestHashTable.elf   hashtablelib  loglib )

ELSE (TEST_MODULE_FLAG AND MODULE_hashtable)
    MESSAGE(STATUS "Not Include hashtable module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_hashtable)



