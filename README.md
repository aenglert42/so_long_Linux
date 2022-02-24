# so_long_Linux
A small 2D game to learn how to work with windows, colors, events and textures. Inspired by the "42 Coding School" exercise "so_long" (October 2021).

## Table of contents
* [Introduction](#introduction)
  * [Allowed functions](#allowed-functions)
  * [Description](#description)
  * [General rules](#general-rules)
  * [Map-file](#map-file)
* [Approach](#approach)
* [Prerequisites](#prerequisites)
* [How to launch](#how-to-launch)
* [How to play](#how-to-play)

* [Example](#example)
* [Notes](#notes)


## Introduction
### Allowed functions
open, close, read, write, printf, malloc, free, perror, strerror, exit

Aditionally all functions of the [MinilibX](https://github.com/42Paris/minilibx-linux) can be used.

### Description
The aim of the exercise is to create a small 2D game in which the player has to collect some loot on a map, before leaving it.

### General rules
* The player’s goal is to collect all collectibles present on the map and then escape.
* The current number of movements must be displayed.
* The player must be able to move: up, down, left, right.
* The player cannot move into walls.
* The program is dosplayed in a window.
* The arrow-keys and/or the W, A, S, and D keys will be used to move around the map.
* Pressing ESC or clicking on the close button on the window’s frame must close the window and quit the program cleanly.
* As argument the program takes a [map-file](#map-file).
* If a misconfiguration of any kind is encountered in the [map-file](#map-file), the program must exit properly and return "Error\n" followed by an explicit error message.

### Map-file
* The map-file has to be of type ".ber".
* It can only consist of 5 possible characters:
  * '0' for an empty space
  * '1' for a wall
  * 'C' for a collectible
  * 'E' for a map exit
  * 'P' for the player’s starting position
* The map must be closed/surrounded by walls.
* The map must have:
  * at least one exit
  * at least one collectible
  * only one starting position
* The map has to be rectangular.

## Approach
here I will explain, how I approached the problem.

## Prerequisites
Tested on Ubuntu 20.04.3 LTS
* gcc

## How to launch
Compile the program via the Makefile by using ```$ make``` in the root directory of the repository.

Run it by giving it the path to the map-file as argument (in this case the file "example.ber" within the directory "maps"):

```
$ ./so_long maps/example.ber
```

For the required map-file format see: [Map-file](#map-file)

## How to play
You are a fly and have to collect all the poo on the map and escape into the bright light. But be careful, there is a hungry frog who wants to eat you. If you get caught, you lose. You can create your own map, by creating a [map-file](#map-file).

### Keys
```W``` / ```ARROW-UP``` - Move upwards

```A``` / ```ARROW-LEFT``` - Move left

```S``` / ```ARROW-DOWN``` - Move downwards

```D``` / ```ARROW-RIGHT``` - Move right

```ESC``` - Exit game

## Example
_Sample of a game on the map "example_small.ber"_
![so_long](https://user-images.githubusercontent.com/80413516/155494401-f80fc365-a149-4cf7-bba0-c28b14634285.gif)


## Notes
As there was no wait or sleep function allowed, I did something called "busywaiting" or "spinning" to create time-delays. In general this should not be done because it creates unneeded load on the CPU and the delay is unpredictable (depends on the computer and its workload).

Images used from https://opengameart.org/ and https://www.seekpng.com/
