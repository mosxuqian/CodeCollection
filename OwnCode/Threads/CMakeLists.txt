########################################################################################
#############              ���� thread ���ļ�                               ############## 
########################################################################################
LIST (APPEND thread_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/logThreads.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ThreadMutex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ThreadTask.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ThreadInterface.c
    )
MESSAGE("${CMAKE_CURRENT_SOURCE_DIR} status.")


########################################################################################
#############               ���� thread ��汾��                          ############## 
########################################################################################
set(thread_LIB_VERSION     "1.0.0")
set(thread_LIB_SOVERSION   "1")



########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Threads
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
IF (COMPONENT_thread)
    #���ɶ�̬��  ��̬���� STATIC  
    add_library (threadlib  SHARED      ${thread_LIB_SRCS})  
    add_library (threads    STATIC      ${thread_LIB_SRCS})  
    
    # ����������ϵ�������ǰ������ײ�Ĺ����⣬����Ҫ����
    add_dependencies (threadlib  loglib  pthread)
    add_dependencies (threads    loglib  pthread)
    
    # ����Ҫ���ӵĹ�����, ���˳����Ǳ�����������ʱ˳��
    target_link_libraries (threadlib  loglib pthread)
    target_link_libraries (threads    loglib pthread)
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(threadlib     PROPERTIES 
                                        VERSION     ${thread_LIB_VERSION} 
                                        SOVERSION   ${thread_LIB_SOVERSION} )
ELSE (COMPONENT_thread)
    MESSAGE(STATUS "Not Include thread module.")
ENDIF (COMPONENT_thread)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND COMPONENT_thread)
    add_executable(TestThread.elf    threadTest.c)
    add_dependencies(TestThread.elf  threadlib   loglib     pthread)
    target_link_libraries(TestThread.elf loglib  threadlib  pthread)

ELSE (TEST_MODULE_FLAG AND COMPONENT_thread)
    MESSAGE(STATUS "Not Include Threads module.")
ENDIF (TEST_MODULE_FLAG AND COMPONENT_thread)



