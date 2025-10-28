/**
 * @file basic_calculations.cpp
 * @brief Simple example demonstrating propulsion library usage
 * 
 * This example calculates basic orbital and rocket performance values
 * using the propulsion library.
 */

#include <propulsion/orbital.hpp>
#include <propulsion/rocket.hpp>
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << "======================================\n";
    std::cout << "Propulsion Library - Basic Examples   \n";
    std::cout << "======================================\n\n";
    
    // === ORBITAL MECHANICS ===
    std::cout << "ORBITAL MECHANICS\n";
    std::cout << "-----------------\n";
    
    // LEO at 400 km
    double leo_altitude = 400e3;  // meters
    double leo_radius = propulsion::orbital::radius_from_altitude(leo_altitude);
    double leo_velocity = propulsion::orbital::orbital_velocity(
        propulsion::orbital::MU_EARTH, leo_radius
    );
    double leo_period = propulsion::orbital::orbital_period(
        propulsion::orbital::MU_EARTH, leo_radius
    );
    
    std::cout << "Low Earth Orbit (400 km altitude):\n";
    std::cout << "  Velocity: " << leo_velocity/1000 << " km/s\n";
    std::cout << "  Period:   " << leo_period/60 << " minutes\n\n";
    
    // GEO
    double geo_altitude = 35786e3;  // meters
    double geo_radius = propulsion::orbital::radius_from_altitude(geo_altitude);
    double geo_velocity = propulsion::orbital::orbital_velocity(
        propulsion::orbital::MU_EARTH, geo_radius
    );
    double geo_period = propulsion::orbital::orbital_period(
        propulsion::orbital::MU_EARTH, geo_radius
    );
    
    std::cout << "Geostationary Orbit (35,786 km altitude):\n";
    std::cout << "  Velocity: " << geo_velocity/1000 << " km/s\n";
    std::cout << "  Period:   " << geo_period/3600 << " hours\n\n";
    
    // Escape velocity from Earth surface
    double escape_vel = propulsion::orbital::escape_velocity(
        propulsion::orbital::MU_EARTH,
        propulsion::orbital::RADIUS_EARTH
    );
    std::cout << "Escape velocity from Earth surface: "
              << escape_vel/1000 << " km/s\n\n";
    
    // === ROCKET PERFORMANCE ===
    std::cout << "ROCKET PERFORMANCE\n";
    std::cout << "------------------\n";
    
    // Single stage to LEO (hypothetical)
    double m0_ssto = 10000;  // kg
    double mf_ssto = 1000;   // kg
    double isp_ssto = 350;   // seconds
    double dv_ssto = propulsion::rocket::delta_v(m0_ssto, mf_ssto, isp_ssto);
    double mr_ssto = m0_ssto / mf_ssto;
    
    std::cout << "Single-Stage Rocket (Isp = " << isp_ssto << " s):\n";
    std::cout << "  Initial mass:  " << m0_ssto << " kg\n";
    std::cout << "  Final mass:    " << mf_ssto << " kg\n";
    std::cout << "  Mass ratio:    " << mr_ssto << ":1\n";
    std::cout << "  Delta-v:       " << dv_ssto/1000 << " km/s\n";
    std::cout << "  (Note: ~9 km/s needed for LEO)\n\n";
    
    // Required mass ratio for LEO
    double dv_leo = 9000;  // m/s
    double isp_typical = 300;  // seconds
    double mr_required = propulsion::rocket::mass_ratio(dv_leo, isp_typical);
    double propellant_frac = propulsion::rocket::propellant_fraction(
        mr_required, 1.0
    );
    
    std::cout << "LEO Requirements (Isp = " << isp_typical << " s):\n";
    std::cout << "  Required delta-v:    " << dv_leo/1000 << " km/s\n";
    std::cout << "  Mass ratio needed:   " << mr_required << ":1\n";
    std::cout << "  Propellant fraction: " << propellant_frac*100 << "%\n\n";
    
    // Two-stage rocket
    std::cout << "Two-Stage Rocket:\n";
    double dv_stage1 = 4500;  // m/s
    double dv_stage2 = 4500;  // m/s
    double mr_stage1 = propulsion::rocket::mass_ratio(dv_stage1, 310);
    double mr_stage2 = propulsion::rocket::mass_ratio(dv_stage2, 340);
    
    std::cout << "  Stage 1 (Isp=310s): delta-v=" << dv_stage1/1000 
              << " km/s, MR=" << mr_stage1 << ":1\n";
    std::cout << "  Stage 2 (Isp=340s): delta-v=" << dv_stage2/1000 
              << " km/s, MR=" << mr_stage2 << ":1\n";
    std::cout << "  Total delta-v: " << (dv_stage1 + dv_stage2)/1000 << " km/s\n\n";
    
    std::cout << "========================================\n";
    std::cout << "All calculations from propulsion library\n";
    std::cout << "========================================\n";
    
    return 0;
}

