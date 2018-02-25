#ifndef __TESTING__
#define __TESTING__

class GPSCoords{
    public:
    GPSCoords(float lat, float lon): lat_(lat), lon_(lon){}

    float getLat() const{return lat_;}
    float getLon() const {return lon_;}


    private:
        float lat_;
        float lon_;
};













#endif
