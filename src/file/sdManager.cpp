#include "file/sdManager.h"
#include <SPI.h>
#include <SD.h>

bool SDManager::mount(){
    bool result;
    SPI.begin(SD_SCK_PIN, SD_MISO_PIN, SD_MOSI_PIN, SD_CS_PIN);
    if(SD.begin(SD_CS_PIN, SPI, SD_SPI_FREQ)){
        result = true;
    } else {
        SPI.end();
        result = false;
    }
    return result;
}