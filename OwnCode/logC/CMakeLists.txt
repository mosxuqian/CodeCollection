########################################################################################
##########         ���� loglib ���ļ�                                        ########### 
########################################################################################
LIST (APPEND log_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/LogC.c 
    )
    
    
########################################################################################
#############               ���� loglib ��汾��                          ############## 
########################################################################################
set(log_LIB_VERSION     "1.0.0")
set(log_LIB_SOVERSION   "1")



########################################################################################
#############               ����Դ����Ŀ¼                                ############## 
########################################################################################
add_subdirectory( DebugHeap )
add_subdirectory( FunctionsStatistics )
add_subdirectory( StackInfoDebug )

MESSAGE("${CMAKE_CURRENT_SOURCE_DIR} status.")



########################################################################################
##########            ���� ������ļ������ͷ�ļ�Ŀ¼                        ########### 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Log   
)  
  
  
########################################################################################
##########            ���� ���ӿ��ļ�Ŀ¼                                    ########### 
########################################################################################
link_directories(  
    /usr/local/lib   
    )  


########################################################################################
##########            ����Ŀ����ļ� �� �����汾��                           ########### 
########################################################################################
IF (COMPONENT_log)
    #���ɶ�̬��  ��̬���� STATIC  
    add_library (loglib SHARED          ${log_LIB_SRCS})  
    add_library (logs STATIC            ${log_LIB_SRCS})  
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(loglib   PROPERTIES 
                            VERSION  ${log_LIB_VERSION} 
                            SOVERSION ${log_LIB_SOVERSION} )
    
ELSE (COMPONENT_log)
    MESSAGE(STATUS "Not Include log module.")
ENDIF (COMPONENT_log)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG)
    add_executable(Testlog.elf  logTest.c)
    add_dependencies(Testlog.elf        loglib)
    target_link_libraries(Testlog.elf   loglib)

ELSE (TEST_MODULE_FLAG)
    MESSAGE(STATUS "Not Include jsoncpp module.")
ENDIF (TEST_MODULE_FLAG)


