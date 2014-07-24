[![Build Status](https://travis-ci.org/blasphemy/yrcd.svg?branch=master)](https://travis-ci.org/blasphemy/yrcd) [![Stories in Ready](https://badge.waffle.io/blasphemy/yrcd.png?label=ready&title=Ready)](https://waffle.io/blasphemy/yrcd) 
yrcd
====
A Simple ircd in vala. How simple? So simple that channels don't even exist yet.


BUILDING
========
At the time of writing, yrcd builds on vala 0.14 and up, with both gcc and clang, though I am mainly targetting vala 0.22 and up with gcc. Everything else is just a bonus. Check our [travis instance](https://travis-ci.org/blasphemy/yrcd) to see what it currently builds on.

```mkdir build && cd build && cmake .. && make```
