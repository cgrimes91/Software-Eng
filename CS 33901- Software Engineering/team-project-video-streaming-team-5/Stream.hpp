/*
  Stream.hpp

  Include file for Stream class
*/

#ifndef RENTAL_H
#define RENTAL_H

#include "Video.hpp"

class Stream {
public:

    // constructor
    Stream(Video* video, int occurrences);
    // number of times watched
    int viewings() const;

    // video rented
    Video* video() const;

private:
    Video* streamingVideo;
    int numViewed;
};

#endif
