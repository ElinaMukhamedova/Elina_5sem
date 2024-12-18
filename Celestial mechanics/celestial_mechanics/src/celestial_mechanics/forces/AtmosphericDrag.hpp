#pragma once

#include <Core>
#include <Geometry>
#include <Geocentric.hpp>
#include "GOST4401_81.hpp"

class AtmosphericDrag {

    GOST4401_81 gost_;

    public:
        AtmosphericDrag(GOST4401_81 gost) : gost_(gost) {}

        struct SatelliteParameters {
            double S_drag;
            double C_drag;
        };

        template<typename Params>
        Eigen::Vector3d calcAcceleration(const Eigen::Vector3d& positionECI, const Eigen::Vector3d& velocityECI,
                                            const double mass, const SatelliteParameters& satParams,
                                                const Params& params){
            const Eigen::Quaternion eci2ecef = params.eci2ecef;
            const Eigen::Vector3d posECEF = eci2ecef._transformVector(positionECI);
            const Eigen::Vector3d velECEF = eci2ecef._transformVector(velocityECI);

            const double latitude_degrees, longitude_degrees, height_metres;
            GeographicLib::Geocentric::Reverse(posECEF(0), posECEF(1), posECEF(2),
                                                &latitude_degrees, &longitude_degrees, &height_metres);

            double rho = gost_.density(height_metres);
            double v2 = velECEF.squaredNorm();
            Eigen::Vector3d n = -velECEF.normalized();
            Eigen::Vector3d accECEF = (0.5 * rho * v2 * satParams.C_drag * satParams.S_drag / mass) * n;
            
            return eci2ecef.conjugate()._transformVector(accECEF);
        }
};