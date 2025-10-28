/**
 * @file rocket.hpp
 * @brief Rocket performance calculations
 * 
 * This module provides functions for rocket propulsion calculations
 * including the Tsiolkovsky rocket equation, specific impulse conversions,
 * and mass ratio calculations.
 */

#ifndef PROPULSION_ROCKET_HPP
#define PROPULSION_ROCKET_HPP

#include <cmath>
#include "orbital.hpp"  // For G0 constant

namespace propulsion {
namespace rocket {

/**
 * @brief Calculate delta-v using the Tsiolkovsky rocket equation
 * 
 * @param m0 Initial mass (kg)
 * @param mf Final mass after propellant burn (kg)
 * @param isp Specific impulse (seconds)
 * @return Delta-v (m/s)
 * 
 * Formula: Δv = Isp * g0 * ln(m0 / mf)
 */
inline double delta_v(double m0, double mf, double isp) {
    return isp * orbital::G0 * std::log(m0 / mf);
}

/**
 * @brief Calculate delta-v from exhaust velocity
 * 
 * @param m0 Initial mass (kg)
 * @param mf Final mass after propellant burn (kg)
 * @param ve Exhaust velocity (m/s)
 * @return Delta-v (m/s)
 * 
 * Formula: Δv = ve * ln(m0 / mf)
 */
inline double delta_v_from_ve(double m0, double mf, double ve) {
    return ve * std::log(m0 / mf);
}

/**
 * @brief Calculate required mass ratio for a given delta-v
 * 
 * @param dv Required delta-v (m/s)
 * @param isp Specific impulse (seconds)
 * @return Mass ratio (m0 / mf)
 * 
 * Formula: MR = e^(Δv / (Isp * g0))
 */
inline double mass_ratio(double dv, double isp) {
    return std::exp(dv / (isp * orbital::G0));
}

/**
 * @brief Convert specific impulse to exhaust velocity
 * 
 * @param isp Specific impulse (seconds)
 * @return Exhaust velocity (m/s)
 * 
 * Formula: ve = Isp * g0
 */
inline double isp_to_exhaust_velocity(double isp) {
    return isp * orbital::G0;
}

/**
 * @brief Convert exhaust velocity to specific impulse
 * 
 * @param ve Exhaust velocity (m/s)
 * @return Specific impulse (seconds)
 * 
 * Formula: Isp = ve / g0
 */
inline double exhaust_velocity_to_isp(double ve) {
    return ve / orbital::G0;
}

/**
 * @brief Calculate thrust from mass flow rate and exhaust velocity
 * 
 * @param mdot Mass flow rate (kg/s)
 * @param ve Exhaust velocity (m/s)
 * @return Thrust (Newtons)
 * 
 * Formula: F = mdot * ve
 */
inline double thrust(double mdot, double ve) {
    return mdot * ve;
}

/**
 * @brief Calculate propellant mass required
 * 
 * @param m0 Initial total mass (kg)
 * @param mf Final mass after burn (kg)
 * @return Propellant mass (kg)
 */
inline double propellant_mass(double m0, double mf) {
    return m0 - mf;
}

/**
 * @brief Calculate propellant mass fraction
 * 
 * @param m0 Initial total mass (kg)
 * @param mf Final mass after burn (kg)
 * @return Propellant mass fraction (0-1)
 */
inline double propellant_fraction(double m0, double mf) {
    return (m0 - mf) / m0;
}

} // namespace rocket
} // namespace propulsion

#endif // PROPULSION_ROCKET_HPP

