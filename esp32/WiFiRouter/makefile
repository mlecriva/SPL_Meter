BOARD = esp32
CHIP = esp32

#Arduino file
SKETCH = router.ino

COMMON = ../../common
#Setup all libs used !
LIBS =  $(ESP_LIBS)/EEPROM \
		$(ESP_LIBS)/WiFi \
		$(COMMON)/MicReader \


CPPFLAGS += -DCONFIG_CXX_EXCEPTIONS=1

MODULEMK_DIR = ..
CPP_EXTRA += -fexceptions
include $(MODULEMK_DIR)/Module.mk
