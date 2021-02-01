/*
  Stream.cpp

  Definition file for Stream class
*/

#include "Stream.hpp"

// constructor
Stream::Stream(Video* video, int viewings)
    : streamingVideo(video), numViewed(viewings)
{ }

// number of times watched
int Stream::viewings() const {

    return numViewed;
}

// video rented
Video* Stream::video() const {

    return streamingVideo;
}
