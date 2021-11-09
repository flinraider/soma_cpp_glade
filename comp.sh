#!/bin/bash
g++ soma.cpp -o soma $(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic