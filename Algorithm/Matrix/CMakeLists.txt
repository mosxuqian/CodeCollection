########################################################################################
#############              ���� matrix ���ļ�                               ############## 
########################################################################################
LIST (APPEND matrix_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/matrix.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/
    )



########################################################################################
#############               ���� matrix ��汾��                          ############## 
########################################################################################
set(matrix_LIB_VERSION     "1.0.0")
set(matrix_LIB_SOVERSION   "1")



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
IF (MODULE_matrix)

    #���ɶ�̬��  ��̬���� STATIC  
    add_library (matrixlib     SHARED      ${matrix_LIB_SRCS})  
    add_library (matrixs       STATIC        ${matrix_LIB_SRCS})  
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(matrixlib    PROPERTIES 
                                        VERSION     ${matrix_LIB_VERSION} 
                                        SOVERSION   ${matrix_LIB_SOVERSION} )
ELSE (MODULE_matrix)
    MESSAGE(STATUS "Not Include matrix module.")
ENDIF (MODULE_matrix)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_matrix)
    add_executable(TestMatrix.elf  matrixTest.cpp)
    add_dependencies(TestMatrix.elf        matrixlib  loglib)
    target_link_libraries(TestMatrix.elf   matrixlib  loglib )

ELSE (TEST_MODULE_FLAG AND MODULE_matrix)
    MESSAGE(STATUS "Not Include matrix module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_matrix)



