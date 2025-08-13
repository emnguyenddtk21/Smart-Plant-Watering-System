# MCU & tần số
MCU     = atmega328p
F_CPU   = 8000000UL

# Toolchain AVR
CC      = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS  = -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)

# Danh sách file nguồn
SRC = main.c actuator.c adc.c button.c timer.c

# Tên file output
TARGET = main

# Quy tắc build
all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	avrdude -c usbasp -p $(MCU) -U flash:w:$<

clean:
	rm -f $(TARGET).elf $(TARGET).hex