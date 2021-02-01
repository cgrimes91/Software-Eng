
/*
  Video_t.cpp

  Test program for class Video
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Video.hpp"

TEST_CASE("NOP", "[Video]")
{
}
TEST_CASE("Accessor Test Cases for type Movie" "[Video]"){

const auto video = new Movie("Tangled", 1, 40);

REQUIRE(video->title() == "Tangled");
REQUIRE(video->hours() == 1);
REQUIRE(video->Minutes() == 40);
REQUIRE(video->episodes() == 0);
  
}

TEST_CASE("Accessor Test Cases for type Movie with episodes in constructor" "[Video]"){

const auto video = new Movie("Tangled", 1, 40);

REQUIRE(video->title() == "Tangled");
REQUIRE(video->hours() == 1);
REQUIRE(video->Minutes() == 40);
REQUIRE(video->episodes() == 0);
  
}


TEST_CASE("Accessor Test Cases for type TVSHOW for episode constructor" "[Video]"){

const auto video = new TVShow("Castle", 0, 45, 173);

REQUIRE(video->title() == "Castle");
REQUIRE(video->hours() == 0);
REQUIRE(video->Minutes() == 45);
REQUIRE(video->episodes() == 173);
  
}

TEST_CASE("Accessor Test Cases for type ORIGINNAL constructor" "[Video]"){

const auto video = new Original("Original Series", 0, 45, 50);

REQUIRE(video->title() == "Original Series");
REQUIRE(video->hours() == 0);
REQUIRE(video->Minutes() == 45);
REQUIRE(video->episodes() == 50);
  
}
TEST_CASE("Zero hours and Zero Minutes", "[Video]")
{

  //Filler data
  auto video = new TVShow("pawn stars", 0, 0, 0);
  //Set hours and minutes
  video->setLength(0, 0);

  REQUIRE(video->hours() == 0);
  REQUIRE(video->Minutes() == 0);
}

TEST_CASE("Positive hours and Positive minutes", "[Video]")
{

  //Filler data
  auto video = new TVShow("pawn stars", 0, 0, 0);

  //Set hours and minutes
  video->setLength(1, 1);
  REQUIRE(video->hours() == 1);
  REQUIRE(video->Minutes() == 1);
}

TEST_CASE("Negative hours and Negative Minutes", "[Video]")
{

  //Filler data
  auto video = new Movie("pawn stars", 0, 0); //This shows the allowance of negative hours and minutes inputs

  //Set hours and minutes
  video->setLength(-1, -1);
  REQUIRE(video->hours() == -1);
  REQUIRE(video->Minutes() == -1);
}

TEST_CASE("61 hours 61 minutes", "[Video]")
{

  //Filler data
  auto video = new Original("pawn stars", 0, 0, 0); //This shows that 60 minutes does not transfer to one hour

  //Set hours and minutes
  video->setLength(61, 61);
  REQUIRE(video->hours() == 61);
  REQUIRE(video->Minutes() == 61);
}
