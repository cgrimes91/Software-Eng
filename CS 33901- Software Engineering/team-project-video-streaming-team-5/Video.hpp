/*
  Video.hpp

  Include file for Video class
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class Duration
{
public:
    //constructor
    Duration(int hours, int minutes);

    int hours;
    int minutes;
};

class Video
{
public:
    static const int MOVIE = 0;
    static const int TVSHOW = 1;
    static const int ORIGINAL = 2;

    // constructor
    Video(const std::string &title, int hours, int minutes, int episodes);
    virtual ~Video() = default;
    // video title
    std::string title() const;

    // length of video in hours
    int hours() const;

    // length of video in minutes
    int Minutes() const;

    // number of episodes
    int episodes() const;

    // set video length
    void setLength(int hours, int minutes);

    virtual int getNumberOfStreams(int) const = 0;

    virtual int getNumberOfOriginals(int) const = 0;

    virtual std::string getStreamType() const = 0;

private:
    std::string videoTitle;
    Duration length;
    int numEpisodes;
};

class Movie : public Video
{
public:
    Movie(const std::string &title, int hours, int minutes) : Video(title, hours, minutes, 0) {}
    ~Movie() = default;
    virtual int getNumberOfStreams(int) const;
    virtual int getNumberOfOriginals(int) const;
    virtual std::string getStreamType() const;
};

class TVShow : public Video
{
public:
    TVShow(const std::string &title, int hours, int minutes, int episodes) : Video(title, hours, minutes, episodes) {}
    ~TVShow() = default;
    virtual int getNumberOfStreams(int) const;
    virtual int getNumberOfOriginals(int) const;
    virtual std::string getStreamType() const;
};

class Original : public Video
{
public:
    Original(const std::string &title, int hours, int minutes, int episodes) : Video(title, hours, minutes, episodes) {}
    ~Original() = default;
    virtual int getNumberOfStreams(int) const;
    virtual int getNumberOfOriginals(int) const;
    virtual std::string getStreamType() const;
};

#endif
