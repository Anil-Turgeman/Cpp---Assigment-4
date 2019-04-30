/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

        // MY TESTS
        ConstantChooser c5678{"5678"}, c98652{"98652"}, c1111{"1111"}, c8524{"8524"}, c1231231{"1231231"}, c1{"1"}, c0{"0"},
                        c12{"12"}, c123{"123"}, c13578{"13578"};
        ConstantGuesser g5678{"5678"}, g98652{"98652"}, g1111{"1111"}, g8524{"8524"}, g1231231{"1231231"}, g1{"1"}, g0{"0"},
                        g12{"12"}, g123{"123"}, g1357{"1357"};

        testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c5678, g5678, 4, 100), 1)         // guesser wins in one turn.
        .CHECK_EQUAL(play(c98652, g98652, 5, 100), 1)       // guesser wins in one turn.
        .CHECK_EQUAL(play(c1111, g1111, 4, 60), 1)          // guesser wins in one turn.
        .CHECK_EQUAL(play(c1231231, c1231231, 7, 70), 1)    // guesser wins in one turn.
        .CHECK_EQUAL(play(c1, g1, 1, 100), 1)               // guesser wins in one turn.
        .CHECK_EQUAL(play(c8524, g8524, 4, 100), 1)         // guesser wins in one turn.

		.CHECK_EQUAL(play(c1111, g1357, 4, 100), 101)       // guesser loses by running out of turns
        .CHECK_EQUAL(play(c1234, c5678, 4, 100), 101)       // guesser loses by running out of turns
        .CHECK_EQUAL(play(c1, g1, 1, 100), 101)             // guesser loses by running out of turns
        .CHECK_EQUAL(play(c0, g1, 1, 10), 11)               // guesser loses by running out of turns
        .CHECK_EQUAL(play(c0, g0, 1, 20), 21)               // guesser loses by running out of turns
        .CHECK_EQUAL(play(c123, g123, 3, 100), 101)         // guesser loses by running out of turns


		.CHECK_EQUAL(play(c1, g12, 1, 100), 101)            // guesser loses technically by making an illegal guess (too long).
        .CHECK_EQUAL(play(c0, g5678, 1, 100), 101)          // guesser loses technically by making an illegal guess (too long).
        .CHECK_EQUAL(play(c12, g8524, 2, 100), 101)         // guesser loses technically by making an illegal guess (too long).
        .CHECK_EQUAL(play(c1111, g98652, 4, 100), 101)      // guesser loses technically by making an illegal guess (too long).
        .CHECK_EQUAL(play(c8524, g98652, 4, 100), 101)      // guesser loses technically by making an illegal guess (too long).
        .CHECK_EQUAL(play(c13578, c1231231, 5, 100), 101)   // guesser loses technically by making an illegal guess (too long).

		.CHECK_EQUAL(play(c5678, g0, 1, 100), 0)            // chooser loses technically by choosing an illegal number (too long).
        .CHECK_EQUAL(play(c12, g1, 1, 100), 0)              // chooser loses technically by choosing an illegal number (too long).
        .CHECK_EQUAL(play(c123, g12, 2, 100), 0)            // chooser loses technically by choosing an illegal number (too long).
        .CHECK_EQUAL(play(c5678, g123, 3, 100), 0)          // chooser loses technically by choosing an illegal number (too long).
        .CHECK_EQUAL(play(c13578, g1234, 4, 100), 0)        // chooser loses technically by choosing an illegal number (too long).
        .CHECK_EQUAL(play(c1231231, g98652, 5, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

        testcase.setname("Play with smart guesser");
		RandomChooser randy2;
		SmartGuesser smarty2;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(ply(randy2, smarty2, 4, 100) >x100, false);  // smarty should always win in at most 10 turns!
		}

		RandomChooser randy2;
		SmartGuesser smarty2;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy2, smarty2, 4, 100) > 100, false);  // smarty should always win in at most 10 turns!
		}


        grade = testcase.grade();
        } else {
            testcase.print_signal(signal);
            grade = 0;
        }
        cout << "Your grade is: "  << grade << endl;
	return 0;
}
