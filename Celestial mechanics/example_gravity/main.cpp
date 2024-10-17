#include <iostream>
#include <exception>
#include <cmath>
#include "GeographicLib/include/GeographicLib/GravityModel.hpp"

using namespace GeographicLib;

int main() {
  try {
    const std::string path = "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/gravity";
    
    GravityModel grav("egm2008", path, 100, 100);
    double lat = 27.99, lon = 86.93, h = 8820; // Mt Everest

    GravityModel grav0("egm2008", path, 0, 0);

    double gx, gy, gz;
    grav.Gravity(lat,lon, h, gx, gy, gz);
    double f = std::sqrt(gx * gx + gy * gy + gz * gz);
    std::cout << f << "\n";

    double gx0, gy0, gz0;
    grav0.Gravity(lat,lon, h, gx0, gy0, gz0);
    double f0 = std::sqrt(gx0 * gx0 + gy0 * gy0 + gz0 * gz0);
    std::cout << f0 << "\n";

    double delta1 = std::sqrt((gx0 - gx) * (gx0 - gx) + (gy0 - gy) * (gy0 - gy) + (gz0 - gz) * (gz0 - gz));

    std::cout << std::abs(delta1 / f) << std::endl;

  }
  catch (const std::exception& e) {
    std::cerr << "Caught exception: " << e.what() << "\n";
    return 1;
  }
}