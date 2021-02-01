/*
  Video.cpp

  Definition file for Video class
*/


#include "Video.hpp"



// constructor
Video::Video(const std::string& title, int hours, int minutes, int episodes)
    : videoTitle(title), length(Duration(hours, minutes)), numEpisodes(episodes)
{ }

// video title
std::string Video::title() const {

    return videoTitle;
}


// video length in hours
int Video::hours() const {

    return length.hours;
}

// video length in minutes
int Video::Minutes() const {

    return length.minutes;
}

// number of episodes
int Video::episodes() const {

    return numEpisodes;
}

// set video length
void Video::setLength(int hours, int minutes)
{
    length = Duration(hours, minutes);
}

Duration::Duration(int hours, int minutes) : hours(hours), minutes(minutes) { }


int Movie::getNumberOfStreams(int viewings) const
{
    return viewings * (hours() ? hours() : 1);
}
int TVShow::getNumberOfStreams(int viewings) const
{
    return viewings;
}
int Original::getNumberOfStreams(int viewings) const
{
    return viewings;
}
/*
int Video::getNumberOfStreams(int viewings) const {

        int streamCount = 0;

        switch (type()) {

            // for movies, the stream count is the number of hours, with a minimum of 1
            case Video::MOVIE:
                streamCount += viewings * (hours() ? hours() : 1);
                break;

            // for TV shows, the stream count is just the number of streams
            case Video::TVSHOW:
                streamCount += viewings;
                break;

            // for TV shows, the stream count is just the number of streams
            case Video::ORIGINAL:
                streamCount += viewings;
                break;
        }
      
      return streamCount;
}
*/
int Movie::getNumberOfOriginals(int viewings) const
{
    return 0;
}
int TVShow::getNumberOfOriginals(int viewings) const
{
    return 0;
}
int Original::getNumberOfOriginals(int viewings) const
{
    return viewings;
}

std::string Movie::getStreamType() const
{
    return "MOVIE";
}
std::string TVShow::getStreamType() const
{
    return "TVSHOW";
}
std::string Original::getStreamType() const
{
    return "ORIGINAL";
}
