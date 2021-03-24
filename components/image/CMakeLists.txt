#if(ESP_PLATFORM)


idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS .
                       REQUIRES lvgl)

#endif()
