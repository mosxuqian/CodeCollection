########################################################################################
#############               ���� sha256 ���ļ�                            ############## 
########################################################################################
LIST (APPEND sha256_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/sha2.c
    )

    
    
########################################################################################
#############               ���� sha2 ��汾��                          ############## 
########################################################################################
set(sha2_LIB_VERSION     "1.0.0")
set(sha2_LIB_SOVERSION   "1")



########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Crypto
    ${PROJECT_SOURCE_DIR}/Crypto/SHA256
    ${PROJECT_SOURCE_DIR}/Crypto/SHA256/include
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
IF (MODULE_sha256)
    #���ɶ�̬��  ��̬���� STATIC  
    add_library (sha256lib  SHARED          ${sha256_LIB_SRCS})  
    add_library (sha256s    STATIC          ${sha256_LIB_SRCS})  
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(sha256lib   PROPERTIES 
                                      VERSION     ${sha2_LIB_VERSION} 
                                      SOVERSION   ${sha2_LIB_SOVERSION} )
ELSE (MODULE_sha256)
    MESSAGE(STATUS "Not Include sha256 module.")
ENDIF (MODULE_sha256)





########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_sha256)
    add_executable(TestSha256.elf  sha256Test.c)
    add_dependencies(TestSha256.elf    sha256lib  loglib)
    target_link_libraries(TestSha256.elf   loglib  sha256lib )

ELSE (TEST_MODULE_FLAG AND MODULE_sha256)
    MESSAGE(STATUS "Not Include sha256 module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_sha256)