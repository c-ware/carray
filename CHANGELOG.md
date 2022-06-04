# CHANGELOG.md

VERSION: 2.0.0
DATE: April 16th, 2022

+ Changed `CWARE_LIBCARRAY` prefix to `CARRAY`
+ Added `CARRAY_COUNTER_TYPE` for synchronizing the lengths and capacities of
  the arrays with the counters to remove type warnings
+ `CARRAY_VERSION`, previously `CWARE_LIBCARRAY_VERSION`, is now a string
+ Initial size must be greater than zero
+ Changed exit to abort
+ Fixed potential float conversion warning
