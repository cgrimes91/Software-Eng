/*
  Account_t.cpp

  Test program for class Account
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Account.hpp"

TEST_CASE("No streaming", "[Account]")
{

    Account customer("Fred");

    REQUIRE(customer.name() == "Fred");
    REQUIRE(customer.data() == "");
}

//Testing the constructor for Account Class
TEST_CASE("Constructor", "[Account]")
{

    Account customer("Mike");

    REQUIRE(customer.name() == "Mike");
    REQUIRE(customer.data() == "");
}

//Testing addStream function with Single Stream
TEST_CASE("SingleStream1", "[Account]")
{
    const auto video = new TVShow("Breaking Bad", 1, 90, 50);
    Account customer("David");
    const auto stream = Stream(video, 2);
    customer.addStream(stream);

    //checking data
    REQUIRE(customer.data() == "David,TVSHOW,Breaking Bad,2,180,2\n");
}

TEST_CASE("SingleStream2", "[Account]")
{
    const auto video = new TVShow("Rick and Morty", 0, 20, 100);
    Account customer("Sarah");
    const auto stream = Stream(video, 45);
    customer.addStream(stream);

    //checking data
    REQUIRE(customer.data() == "Sarah,TVSHOW,Rick and Morty,0,900,45\n");
}

//Testing addStream and data() functions with two streams
TEST_CASE("DoubleStream", "[Account]")
{
    const auto video1 = new Original("CrabMan", 0, 25, 10);
    const auto video2 = new Movie("SuperBad", 1, 45);
    Account customer("John");

    const auto stream1 = Stream(video1, 5);
    const auto stream2 = Stream(video2, 1);
    customer.addStream(stream1);
    customer.addStream(stream2);

    //checking data
    REQUIRE(customer.data() == "John,ORIGINAL,CrabMan,0,125,5\nJohn,MOVIE,SuperBad,1,45,1\n");
}

//Testing addStream and data() functions with three streams
TEST_CASE("ThreeStream", "[Account]")
{
    const auto video1 = new TVShow("Game Of Thrones", 1, 0, 60);
    const auto video2 = new Movie("Hitman", 1, 30);
    const auto video3 = new Original("Super Sunday", 0, 30, 20);
    Account customer("Daniel");

    const auto stream1 = Stream(video1, 8);
    const auto stream2 = Stream(video2, 3);
    const auto stream3 = Stream(video3, 10);

    customer.addStream(stream1);
    customer.addStream(stream2);
    customer.addStream(stream3);

    //checking data
    REQUIRE(customer.data() == "Daniel,TVSHOW,Game Of Thrones,8,0,8\nDaniel,MOVIE,Hitman,3,90,3\nDaniel,ORIGINAL,Super Sunday,0,300,10\n");
}

//Testing addStream and data() functions with four streams
TEST_CASE("FourStream", "[Account]")
{
    const auto video1 = new TVShow("Rick and Morty", 0, 20, 100);
    const auto video2 = new Movie("The Sixth Sense", 1, 50);
    const auto video3 = new Movie("Home Alone", 1, 45);
    const auto video4 = new TVShow("The Office", 0, 30, 100);
    Account customer("Eric");

    const auto stream1 = Stream(video1, 10);
    const auto stream2 = Stream(video2, 1);
    const auto stream3 = Stream(video3, 2);
    const auto stream4 = Stream(video4, 40);

    customer.addStream(stream1);
    customer.addStream(stream2);
    customer.addStream(stream3);
    customer.addStream(stream4);

    //checking data
    REQUIRE(customer.data() == "Eric,TVSHOW,Rick and Morty,0,200,10\nEric,MOVIE,The Sixth Sense,1,50,1\nEric,MOVIE,Home Alone,2,90,2\nEric,TVSHOW,The Office,0,1200,40\n");
}
TEST_CASE("Testing report() with originals", "[Account]"){

    ////tests report() with single stream
  
	//Tests report() with an original
	Account customerA("Spike");

	constexpr auto episodesA = 10;
	const auto videoA = new Original("The One", 0, 30, episodesA);
	const auto streamA = Stream(videoA, 4);

	customerA.addStream(streamA);
	
	REQUIRE(customerA.report() == "Stream Report for Account: Spike\nStreams:\n\tThe One\t4\n\nTotal Stream Events: 4\nNon-Original Stream Events: 0\nTotal Time: 2:0\n");

	//Tests a second original
	Account customerB("Bon");

	constexpr auto episodesB = 100;
	const auto videoB = new Original("HELP!", 1, 30, episodesB);
	const auto streamB = Stream(videoB, 120);

	customerB.addStream(streamB);

	REQUIRE(customerB.report() == "Stream Report for Account: Bon\nStreams:\n\tHELP!\t120\n\nTotal Stream Events: 120\nNon-Original Stream Events: 0\nTotal Time: 180:0\n");

  }

  TEST_CASE("Testing report() with movies", "[Account]") {

    ////tests report() with single stream

        //tests report() with a movie
	Account customer1("Billy");

	const auto video1 = new Movie("Star Wars",2, 30);
	const auto stream1 = Stream(video1, 1);

	customer1.addStream(stream1);

	REQUIRE(customer1.report() == "Stream Report for Account: Billy\nStreams:\n\tStar Wars\t2\n\nTotal Stream Events: 2\nNon-Original Stream Events: 2\nTotal Time: 2:30\n");

	//tests a second movie
	Account customerMoovie("Bon");

	const auto videoMoovie = new Movie("HELP!", 1, 30);
	const auto streamMoovie = Stream(videoMoovie, 120);

	customerMoovie.addStream(streamMoovie);

	REQUIRE(customerMoovie.report() == "Stream Report for Account: Bon\nStreams:\n\tHELP!\t120\n\nTotal Stream Events: 120\nNon-Original Stream Events: 120\nTotal Time: 180:0\n");
	
  }

  TEST_CASE("Testing report() with tv shows", "[Account]") {

    ////tests report() with single stream
    
        //tests report() with no customer name, no title name, and no viewings
	Account customer0("");

	constexpr auto episodes0 = 10;
	const auto video0 = new TVShow("", 0, 30, episodes0);
	const auto stream0 = Stream(video0, 0);

	customer0.addStream(stream0);

	REQUIRE(customer0.report() == "Stream Report for Account: \nStreams:\n\t\t0\n\nTotal Stream Events: 0\nNon-Original Stream Events: 0\nTotal Time: 0:0\n");


	//tests report() with a tv show
	Account customer("Tim");

	constexpr auto episodes = 10;
	const auto video = new TVShow("Pawn Stars", 0, 30, episodes);
	const auto stream = Stream(video, 25);

	customer.addStream(stream);

	REQUIRE(customer.report() == "Stream Report for Account: Tim\nStreams:\n\tPawn Stars\t25\n\nTotal Stream Events: 25\nNon-Original Stream Events: 25\nTotal Time: 12:30\n");

	//Tests a second TV show
	Account customerTV("Bon");

	constexpr auto episodesTV = 100;
	const auto videoTV = new TVShow("HELP!", 0, 30, episodesTV);
	const auto streamTV = Stream(videoTV, 120);

	customerTV.addStream(streamTV);

	REQUIRE(customerTV.report() == "Stream Report for Account: Bon\nStreams:\n\tHELP!\t120\n\nTotal Stream Events: 120\nNon-Original Stream Events: 120\nTotal Time: 60:0\n");
    
  }

TEST_CASE("Testing report() with multiple original streams","[Account]"){

        Account customer5("Richard");

	constexpr auto episodesA = 10;
	const auto videoA = new Original("The One", 0, 30, episodesA);
	const auto streamA = Stream(videoA, 4);
       
	customer5.addStream(streamA); 
	customer5.addStream(streamA);
	
	REQUIRE(customer5.report() == "Stream Report for Account: Richard\nStreams:\n\tThe One\t4\n\tThe One\t4\n\nTotal Stream Events: 8\nNon-Original Stream Events: 0\nTotal Time: 4:0\n");
  
}

TEST_CASE("Testing report() with multiple movie streams", "[Account]"){

        Account customer4("George");

	const auto video4 = new Movie("Star Wars", 2, 30);
	const auto stream4 = Stream(video4, 1);
  
	customer4.addStream(stream4);
	customer4.addStream(stream4);

	REQUIRE(customer4.report() == "Stream Report for Account: George\nStreams:\n\tStar Wars\t2\n\tStar Wars\t2\n\nTotal Stream Events: 4\nNon-Original Stream Events: 4\nTotal Time: 5:0\n");
  
}

TEST_CASE("Testing report() with multiple tv show streams", "[Account]"){

     	Account customer3("Paul");
	
	constexpr auto episodes2 = 10;
	const auto video2 = new TVShow("", 0, 30, episodes2);
	const auto stream2 = Stream(video2, 0);
	
	customer3.addStream(stream2);
	customer3.addStream(stream2);

	REQUIRE(customer3.report() == "Stream Report for Account: Paul\nStreams:\n\t\t0\n\t\t0\n\nTotal Stream Events: 0\nNon-Original Stream Events: 0\nTotal Time: 0:0\n");
}
