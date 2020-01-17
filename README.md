# TimedInterpolation
Time-based interpolation library for Arudino.  


## Usage
```
TimedInterpolation interpolation; //create an instance.

interpolation.begin(1000)   //Set the duration.
interpolation.get() // returns the ratio against the duration above.

interpolation.getElapsedTime()  // returns the milliseconds passed from the last call of begin()
interpolation.getElapsedTimeSec() // returns as seconds

// if you just want to know the elapsed time, call without duration.
interpolation.begin()   
```

## Requirements
- None

## License
[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE)