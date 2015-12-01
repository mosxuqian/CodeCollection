########################################################################################
#############              ���� threadpool ���ļ�                               ############## 
########################################################################################
LIST (APPEND threadpool_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/ThreadPool.c
    )



########################################################################################
#############               ���� threadpool ��汾��                          ############## 
########################################################################################
set(threadpool_LIB_VERSION     "1.0.0")
set(threadpool_LIB_SOVERSION   "1")



########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Threads
    ${PROJECT_SOURCE_DIR}/Threads/ThreadPool
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
IF (COMPONENT_threadpool)
    #���ɶ�̬��  ��̬���� STATIC  
    add_library (threadpoollib SHARED   ${threadpool_LIB_SRCS})  
    add_library (threadpools STATIC     ${threadpool_LIB_SRCS})  
    
    # ����������ϵ�������ǰ������ײ�Ĺ����⣬����Ҫ����
    add_dependencies (threadpoollib   pthread)
    add_dependencies (threadpools     pthread)
    
    # ����Ҫ���ӵĹ�����, ���˳����Ǳ�����������ʱ˳��
    target_link_libraries (threadpoollib  pthread)
    target_link_libraries (threadpools    pthread)
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(threadpoollib   PROPERTIES 
                            VERSION   ${threadpool_LIB_VERSION} 
                            SOVERSION ${threadpool_LIB_SOVERSION} )
ELSE (COMPONENT_threadpool)
    MESSAGE(STATUS "Not Include threadpool module.")
ENDIF (COMPONENT_threadpool)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND COMPONENT_threadpool)
    add_executable(TestThreadPool-heavy.elf    heavyTest.c)
    add_dependencies(TestThreadPool-heavy.elf  threadpoollib     pthread)
    target_link_libraries(TestThreadPool-heavy.elf  threadpoollib  pthread)
    
    add_executable(TestThreadPool-shutdown.elf    shutdownTest.c)
    add_dependencies(TestThreadPool-shutdown.elf  threadpoollib     pthread)
    target_link_libraries(TestThreadPool-shutdown.elf  threadpoollib  pthread)
    
    add_executable(TestThreadPool-thrd.elf    thrdTest.c)
    add_dependencies(TestThreadPool-thrd.elf  threadpoollib     pthread)
    target_link_libraries(TestThreadPool-thrd.elf  threadpoollib  pthread)

ELSE (TEST_MODULE_FLAG AND COMPONENT_threadpool)
    MESSAGE(STATUS "Not Include Threads pool module.")
ENDIF (TEST_MODULE_FLAG AND COMPONENT_threadpool)



