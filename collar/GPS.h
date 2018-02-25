#ifndef __GPS_H__
#define __GPS_H__


class GPSCoords{
    public:
    GPSCoords(float lat, float lon): lat_(lat), lon_(lon){}

    float getLat() const{return lat_;}
    float getLon() const {return lon_;}

    std::string getString() const {


        return std::to_string(lat_) + "," + std::to_string(lon_);

    }

    std::string getJSON() const {

    }



    private:
        float lat_;
        float lon_;
};





#endif
