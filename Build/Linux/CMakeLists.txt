# Version set
cmake_minimum_required(VERSION 3.1)

function(print_list TITLE LIST)
    message(STATUS "##### ${TITLE} #####")
    foreach(ITEM ${LIST})
        message(STATUS "${ITEM}")
    endforeach()
    message("")
endfunction()

# ディレクトリ設定
set(RELEASE_DIR "../../Release/")
set(SRC_DIR "../../Sources/")

# 出力ファイル設定
set(TARGET_NAME "xpress")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${RELEASE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${RELEASE_DIR})
project(${TARGET_NAME}
    VERSION 1.0.0
    DESCRIPTION "xpress-linux"
    LANGUAGES CXX)

# ソースリスト作成
file(GLOB_RECURSE REL_SRC_LIST ${SRC_DIR}/*.cpp ${SRC_DIR}/*.c)
get_filename_component(SOURCE_LIST "${REL_SRC_LIST}" ABSOLUTE DIRECTORY)
print_list("SRC_LIST" "${SOURCE_LIST}")

# ヘッダファイルリスト作成 
file(GLOB_RECURSE REL_HEADER_LIST ${SRC_DIR}/*.hpp ${SRC_DIR}/*.h)
get_filename_component(HEADER_LIST "${REL_HEADER_LIST}" ABSOLUTE DIRECTORY)
print_list("HEADER_LIST" "${HEADER_LIST}")

# インクルードディレクトリリスト作成
set(TMP_INC_DIR_LIST "${HEADER_LIST}")
foreach(ITEM ${TMP_INC_DIR_LIST})
    get_filename_component(DIR ${ITEM} DIRECTORY)
    set(INCLUDE_DIR_LIST ${DIR} ${INCLUDE_DIR_LIST})
endforeach(ITEM)
set(INCLUDE_DIRS "${INCLUDE_DIR_LIST}")

# 静的ライブラリ設定
add_library(${TARGET_NAME} SHARED )
#add_library(${TARGET_NAME} STATIC)

# 外部パッケージ追加
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${TARGET_NAME}  PUBLIC "-pthread")

# インクルード設定
set_property(TARGET ${TARGET_NAME} PROPERTY PUBLIC_HEADER ${HEADER_LIST})
target_include_directories(${TARGET_NAME} PRIVATE "${INCLUDE_DIRS}")

# コンパイラ設定
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D OSAL_LINUX")
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_23)
target_compile_options(${TARGET_NAME} PUBLIC -O3 -std=c++23 -Wall -Wextra -ggdb -lpthread -pthread -lrt -lm )
#target_compile_options(${TARGET_NAME} PUBLIC -O3 -Wall -Wextra -ggdb -lpthread -pthread -lrt -lm )

# ライブラリソース
target_sources(${TARGET_NAME} PRIVATE "${SOURCE_LIST}")

set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
