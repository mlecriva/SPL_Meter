BOARD = esp32
CHIP = esp32

#Arduino file
SKETCH = spiffs.ino

COMMON = ../../common
#Setup all libs used !
LIBS =  $(ESP_LIBS)/EEPROM \
		$(ESP_LIBS)/Wifi \
		$(ESP_LIBS)/SPIFFS \
		$(ESP_LIBS)/FS \
		$(COMMON)/MicReader \
		$(COMMON)/FileManager \
		$(COMMON)/ESP32_FTP/FTPClient.cpp \
		$(COMMON)/ESP32_FTP/FTPCommands.cpp \


CPPFLAGS += -DCONFIG_CXX_EXCEPTIONS=1

MODULEMK_DIR = ..
CPP_EXTRA += -fexceptions
include $(MODULEMK_DIR)/Module.mk
