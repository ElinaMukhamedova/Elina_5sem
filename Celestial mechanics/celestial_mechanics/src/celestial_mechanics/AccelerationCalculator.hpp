#pragma once

#include <tuple>

template<typename EarthGrav, typename ... OtherForces>
class ForceCalculator{
    EarthGrav EarthGravity_;
    std::tuple<OtherForces...> forces_;

    struct SatelliteParameters : EarthGrav::SatelliteParameters, OtherForces::SatelliteParameters ... {
        double mass;
    };

    public:
        ForceCalculator(const EarthGrav& EarthGravity, const OtherForces& ... forces)
            : EarthGravity_(EarthGravity), forces_(forces ...) {}
};