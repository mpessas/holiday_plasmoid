project(plasma-holiday)
 
# Find the required Libaries
find_package(KDE4 REQUIRED)
include(KDE4Defaults)
 
add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${CMAKE_BINARY_DIR}
   ${KDE4_INCLUDES}
   )
 
# We add our source code here
set(plasma_holiday_SRCS plasma_holiday.cpp holiday.cpp)
 
# Now make sure all files get to the right place
kde4_add_plugin(plasma_applet_holiday ${plasma_holiday_SRCS})
target_link_libraries(plasma_applet_holiday
                      ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS} kholidays)
 
install(TARGETS plasma_applet_holiday
        DESTINATION ${PLUGIN_INSTALL_DIR})
 
install(FILES plasma-applet-holiday.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
