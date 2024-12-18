#include "Eternal.hpp"

double Eternal::AU() {
    double au;
            if (calceph_getconstant(peph, "AU", &au) == 0)
                throw Exception("There is no AU value in the ephemerides file!");
            return au;
}

Eigen::Vector3d Eternal::vector(Time<Scale::TDB> tdb, CelestialBody Centre, CelestialBody Target) {
            double jdInt = tdb.jdInt(); double jdFrac = tdb.jdFrac();

            double PositionKM[3];
            calceph_compute_order(peph, jdInt, jdFrac, static_cast<int>(Target), static_cast<int>(Centre),
                                    CALCEPH_USE_NAIFID+CALCEPH_UNIT_KM+CALCEPH_UNIT_SEC, 0, PositionKM);

            Eigen::Vector3d rKM{PositionKM};
            Eigen::Vector3d rM = rKM * 1000;
            return rM;
        }