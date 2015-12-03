
########################################################################################
#############             ���� keeping_setting_modify ���ļ�              ############## 
########################################################################################
LIST (APPEND modifykeeping_LIB_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/KeepingModifyUtilitys.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MappingSettingConfigFile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MappingSettingModifyRecord.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MappingSettingStatistics.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SensitiveParamFiltering.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SettingModifyRecordKeeping.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SettingModifyRecordKeepingInterface.cpp
    )
    

    
########################################################################################
#############           ���� keeping_setting_modify ��汾��              ############## 
########################################################################################
set(modifykeeping_LIB_VERSION     "1.0.0")
set(modifykeeping_LIB_SOVERSION   "1")


   
########################################################################################
#############              ����ͷ�ļ�Ŀ¼                                 ############## 
########################################################################################
include_directories(  
    ${PROJECT_SOURCE_DIR}/includes  
    ${PROJECT_SOURCE_DIR}/Settings
    ${PROJECT_SOURCE_DIR}/Settings/KeepingSettingModify
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
IF (MODULE_modifykeeping)
    #���ɶ�̬��  ��̬���� STATIC  
    add_library (modifykeepinglib SHARED      ${modifykeeping_LIB_SRCS})  
    add_library (modifykeepings   STATIC      ${modifykeeping_LIB_SRCS})  
    
    # ����������ϵ�������ǰ������ײ�Ĺ����⣬����Ҫ����
    add_dependencies (modifykeepinglib  loglib threadlib pthread)
    add_dependencies (modifykeepings    loglib threadlib pthread)
    
    # ����Ҫ���ӵĹ�����, ���˳����Ǳ�����������ʱ˳��
    target_link_libraries (modifykeepinglib  loglib threadlib pthread)
    target_link_libraries (modifykeepings    loglib threadlib pthread)
    
    # ���ð汾�ţ�SOVERSIONΪAPI�汾��
    set_target_properties(modifykeepinglib  PROPERTIES 
                                            VERSION     ${modifykeeping_LIB_VERSION} 
                                            SOVERSION   ${modifykeeping_LIB_SOVERSION} )
ELSE (MODULE_modifykeeping)
    MESSAGE(STATUS "Not Include keeping_setting_modify module.")
ENDIF (MODULE_modifykeeping)



########################################################################################
#############                 ����Ŀ�������ļ�                          ############## 
########################################################################################
IF (TEST_MODULE_FLAG AND MODULE_modifykeeping)
    add_executable(TestModifyKeeping.elf    modifykeepingTest.cpp)
    add_dependencies(TestModifyKeeping.elf      loglib settingslib modifykeepinglib threadlib pthread)
    target_link_libraries(TestModifyKeeping.elf loglib settingslib modifykeepinglib threadlib pthread)

ELSE (TEST_MODULE_FLAG AND MODULE_modifykeeping)
    MESSAGE(STATUS "Not Include keeping_setting_modify module.")
ENDIF (TEST_MODULE_FLAG AND MODULE_modifykeeping)



