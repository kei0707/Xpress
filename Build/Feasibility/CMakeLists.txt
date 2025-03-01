# Version set
cmake_minimum_required(VERSION 3.1)

function(print_list TITLE LIST)
    message(STATUS "##### ${TITLE} #####")
    foreach(ITEM ${LIST})
        message(STATUS "${ITEM}")
    endforeach()
    message("")
endfunction()


# 各種変数設定
set(RELEASE_DIR "../../Release")
set(SRC_DIR "../../Feasibility/")
set(INC_DIR "../../Feasibility/")
set(LIB_CORE "libxpress.so")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../Release/")

set(TARGET_NAME "EXE_Feasibility.exe")
project(${TARGET_NAME}
    VERSION 1.0.0
    DESCRIPTION "MVCS Libraries"
    LANGUAGES CXX)

# ソースリスト作成
file(GLOB_RECURSE REL_SRC_LIST ${SRC_DIR}/*.cpp  )
get_filename_component(SOURCE_LIST "${REL_SRC_LIST}" ABSOLUTE DIRECTORY)
print_list("SRC_LIST" "${SOURCE_LIST}")

# ヘッダファイルリスト作成 
file(GLOB_RECURSE REL_HEADER_LIST ${INC_DIR}/*.hpp "../../Sources/*.hpp")
get_filename_component(HEADER_LIST "${REL_HEADER_LIST}" ABSOLUTE DIRECTORY)
print_list("HEADER_LIST" "${HEADER_LIST}")

# インクルードディレクトリリスト作成
set(TMP_INC_DIR_LIST "${HEADER_LIST}")
foreach(ITEM ${TMP_INC_DIR_LIST})
    get_filename_component(DIR ${ITEM} DIRECTORY)
    set(INCLUDE_DIR_LIST ${DIR} ${INCLUDE_DIR_LIST})
endforeach(ITEM)
set(INCLUDE_DIRS "${INCLUDE_DIR_LIST}")

# ビルドターゲット指定
add_executable(${TARGET_NAME} ${SOURCE_LIST})

#リンク先指定
link_directories(${TARGET_NAME} PRIVATE ${RELEASE_DIR})

# インクルード設定
set_property(TARGET ${TARGET_NAME} PROPERTY PUBLIC_HEADER ${HEADER_LIST})
target_include_directories(${TARGET_NAME} PRIVATE "${INCLUDE_DIRS}")

# コンパイラ設定
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D XPRESS_OSAL_TARGET_LINUX")
target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)
target_compile_options(${TARGET_NAME} PUBLIC -O3 -std=c++20 -Wall -Wextra -ggdb -lpthread -pthread -lrt -lm)

# ライブラリソース
target_sources(${TARGET_NAME} PRIVATE "${SOURCE_LIST}")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${TARGET_NAME} PUBLIC "-pthread" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${RELEASE_DIR}/${LIB_CORE})
