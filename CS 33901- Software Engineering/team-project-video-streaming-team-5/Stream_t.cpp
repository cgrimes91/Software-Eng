/*
  Stream_t.cpp

  Test program for class Stream
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stream.hpp"

TEST_CASE("NOP", "[Stream]")
{
}

TEST_CASE("Stream Viewings Accessor", "[Stream]")
{
  //Filler Data
  const auto video = new TVShow("Pawn Stars", 1, 0, 10);
  auto stream = Stream(video, 35);
  //Verify Accessor
  REQUIRE(stream.viewings() == 35);
}

TEST_CASE("Stream Video Accessor", "[Stream]")
{
  //Filler Data
  const auto video = new TVShow("Pawn Stars", 1, 0, 10);
  auto stream = Stream(video, 35);
  auto accessedVideo = stream.video();
  //Verify Equality of accessed Video and video used to create the stream
  REQUIRE(accessedVideo->episodes() == video->episodes());
  REQUIRE(accessedVideo->hours() == video->hours());
  REQUIRE(accessedVideo->Minutes() == video->Minutes());
  REQUIRE(accessedVideo->title() == video->title());
}
