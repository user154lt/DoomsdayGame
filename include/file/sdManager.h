#ifndef SD_MANAGER_H
#define SD_MANAGER_H

/*
    Simple class to handle mounting sd card
*/
class SDManager{

    private:
    
        static constexpr int SD_SCK_PIN = 40;
        static constexpr int SD_MISO_PIN = 39;
        static constexpr int SD_MOSI_PIN = 14;
        static constexpr int SD_CS_PIN = 12;
        static constexpr int SD_SPI_FREQ = 25000000;

    public:
        
        bool mount();

};

#endif