BOARD = esp32
CHIP = esp32

#Arduino file
SKETCH = ftp.ino

COMMON = ../../common
#Setup all libs used !
LIBS =  $(ESP_LIBS)/EEPROM \
		$(ESP_LIBS)/WiFi \
		$(ESP_LIBS)/SPIFFS \
		$(ESP_LIBS)/FS \
		$(COMMON)/MicReader \
		$(COMMON)/FileManager \
		$(COMMON)/ESP32_FTP/src/FTPClient.cpp \
		$(COMMON)/ESP32_FTP/src/FTPCommands.cpp \


CPPFLAGS += -DCONFIG_CXX_EXCEPTIONS=1

MODULEMK_DIR = ..
CPP_EXTRA += -fexceptions
include $(MODULEMK_DIR)/Module.mk
