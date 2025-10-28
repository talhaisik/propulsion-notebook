/**
 * @file orbital.hpp
 * @brief Orbital mechanics calculations
 * 
 * This module provides functions for basic orbital mechanics calculations
 * including orbital velocity, escape velocity, and period calculations.
 */

#ifndef PROPULSION_ORBITAL_HPP
#define PROPULSION_ORBITAL_HPP

#define _USE_MATH_DEFINES
#include <cmath>

// Define M_PI if not available (MSVC compatibility)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace propulsion {
namespace orbital {

/**
 * @brief Standard gravitational parameter for Earth (m^3/s^2)
 */
constexpr double MU_EARTH = 3.986004418e14;

/**
 * @brief Earth's equatorial radius (m)
 */
constexpr double RADIUS_EARTH = 6.3781e6;

/**
 * @brief Standard gravity (m/s^2)
 */
constexpr double G0 = 9.80665;

/**
 * @brief Calculate orbital velocity for a circular orbit
 * 
 * @param mu Standard gravitational parameter (m^3/s^2)
 * @param r Orbital radius from center of body (m)
 * @return Orbital velocity (m/s)
 * 
 * Formula: v = sqrt(mu / r)
 */
inline double orbital_velocity(double mu, double r) {
    return std::sqrt(mu / r);
}

/**
 * @brief Calculate escape velocity from a given radius
 * 
 * @param mu Standard gravitational parameter (m^3/s^2)
 * @param r Radius from center of body (m)
 * @return Escape velocity (m/s)
 * 
 * Formula: v_esc = sqrt(2 * mu / r)
 */
inline double escape_velocity(double mu, double r) {
    return std::sqrt(2.0 * mu / r);
}

/**
 * @brief Calculate orbital period for a circular orbit
 * 
 * @param mu Standard gravitational parameter (m^3/s^2)
 * @param r Orbital radius from center of body (m)
 * @return Orbital period (seconds)
 * 
 * Formula: T = 2*pi * sqrt(r^3 / mu)
 */
inline double orbital_period(double mu, double r) {
    return 2.0 * M_PI * std::sqrt((r * r * r) / mu);
}

/**
 * @brief Calculate altitude from orbital radius
 * 
 * @param r Orbital radius from center of Earth (m)
 * @param planet_radius Planet radius (m), defaults to Earth
 * @return Altitude above surface (m)
 */
inline double altitude_from_radius(double r, double planet_radius = RADIUS_EARTH) {
    return r - planet_radius;
}

/**
 * @brief Calculate orbital radius from altitude
 * 
 * @param altitude Altitude above surface (m)
 * @param planet_radius Planet radius (m), defaults to Earth
 * @return Orbital radius from center (m)
 */
inline double radius_from_altitude(double altitude, double planet_radius = RADIUS_EARTH) {
    return altitude + planet_radius;
}

} // namespace orbital
} // namespace propulsion

#endif // PROPULSION_ORBITAL_HPP

