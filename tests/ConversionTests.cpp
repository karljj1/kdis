#include <iostream>

#include "KDIS/Extras/KConversions.h"
#include "KDIS/KDefines.h"
#include "gtest/gtest.h"

TEST(ConversionTests,
     GeocentricToGeodeticToGeocentric_ProducesSameOriginalValues) {
  KDIS::KFLOAT64 Lat = 40.664, Lon = -122.63, Alt = 615;
  KDIS::KFLOAT64 GeoX = 0.0, GeoY = 0.0, GeoZ = 0.0;

  KDIS::UTILS::GeodeticToGeocentric(Lat, Lon, Alt, GeoX, GeoY, GeoZ, WGS_1984);

  KDIS::KFLOAT64 NewLat = 0.0, NewLon = 0.0, NewAlt = 0.0;
  KDIS::UTILS::GeocentricToGeodetic(GeoX, GeoY, GeoZ, NewLat, NewLon, NewAlt,
                                    WGS_1984);

  EXPECT_NEAR(Lat, NewLat, 0.0000001);
  EXPECT_NEAR(Lon, NewLon, 0.0000001);
  EXPECT_NEAR(Alt, NewAlt, 0.0000001);
}
