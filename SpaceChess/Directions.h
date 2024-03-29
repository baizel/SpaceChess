#pragma once
/**
 * Direction enum which stores the clockwise angle from North in degrees
 * Increments each direction by 45 degrees
 * @author Baizel
 */
enum Direction {
    NORTH = 0,
    NORTH_EAST = 45,
    EAST = 90,
    SOUTH_EAST = 135,
    SOUTH = 180,
    SOUTH_WEST = 225,
    WEST = 270,
    NORTH_WEST = 315
};