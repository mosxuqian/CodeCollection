########################################################################################
##########                  ���� general_printf ���ļ�                       ########### 
########################################################################################
LIST (APPEND general_printf_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/GeneralPrintf.c
    )


    
########################################################################################
###########                 ���� general_printf ��汾��                     ########### 
########################################################################################
set(general_printf_LIB_VERSION     "1.0.0")
set(general_printf_LIB_SOVERSION   "1")



########################################################################################
##########            ���� ������ļ������ͷ�ļ�Ŀ¼                        ########### 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Log   
    ${PROJECT_SOURCE_DIR}/Log/GeneralPrintf
)  
  
  
  
########################################################################################
##########            ���� ���ӿ��ļ�Ŀ¼                                    ########### 
########################################################################################
link_directories(  
    /usr/local/lib   
    )  

    
    
########################################################################################
##########        ����Ŀ����ļ� ��������Ҫ������ ����������ϵ               ########### 
########################################################################################
IF (MODULE_general_printf)
    
    #���ɶ�̬��  ��̬���� STATIC  
    add_library (general_printflib SHARED          ${general_printf_LIB_SRCS})  
    add_library (general_printfs STATIC            ${general_printf_LIB_SRCS})  
        
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(general_printflib   PROPERTIES 
                                    VERSION     ${general_printf_LIB_VERSION} 
                                    SOVERSION   ${general_printf_LIB_SOVERSION} )

ELSE (MODULE_general_printf)
    MESSAGE(STATUS "Not Include general_printf module.")
ENDIF (MODULE_general_printf)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_general_printf)

    add_executable(TestGeneralPrintf.elf    general_printfTest.c)
    add_dependencies(TestGeneralPrintf.elf          general_printflib loglib)
    target_link_libraries(TestGeneralPrintf.elf     general_printflib loglib)

ELSE (TEST_MODULE_FLAG AND MODULE_general_printf)
    MESSAGE(STATUS "Not Include general_printf module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_general_printf)


