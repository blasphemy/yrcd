#! /bin/sh
cd src
valac -C --pkg gee-1.0 --pkg gio-2.0 *.vala
mv *.c generated_c
