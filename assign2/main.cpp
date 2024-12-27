/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <cmath>

#include "utils.h"

std::string kYourName = "Mac Muir";

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {

  std::ifstream stream(filename);
  std::set<std::string> students;
  std::string student;

  // adding the read in student to the set
  while(std::getline(stream, student)) {
    students.insert(student);
  }

  stream.close();

  return students;
}

namespace compare {
  /**
   * Takes in the name of a student and the name of its potential match to determine
   *  whether they are a potential match based on their first initials.
   * 
   * @param name The address of a student name that we are comparing against its potential match.
   * @param potential_match The address of a student name that we are comparing our name to.
   * @return    True if their initial's match and false otherwise.
   */
  bool compare(const std::string& name, const std::string& potential_match) {

    std::string name_initials;
    std::string match_initials;

    std::string get_single_name;

    std::istringstream stream(name);
    
    // splitting name into parts and appending first letters to a string
    while (getline(stream, get_single_name, ' ')) {
      name_initials += get_single_name.substr(0, 1);
    }

    //re-initializing the string
    stream.str(potential_match);
    stream.clear();

    // splitting name into parts and appending first letters to a string
    while (getline(stream, get_single_name, ' ')) {
      match_initials += get_single_name.substr(0, 1);
    }

    return name_initials == match_initials;
  }
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {

  // a queue containing string pointers
  std::queue<const std::string*> matches;

  for (const auto& s : students) {

    // if the name's are matches
    if (compare::compare(name, s)) {

      // insert the name address into back of queue
      matches.push(&s);
    }
  }

  return matches;

}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {

  if (matches.size() == 0) {
    return "NO MATCHES FOUND.";
  }

  int randomNumber = rand();
  int index = randomNumber % matches.size();

  while ( index > 0) {
    matches.pop();
    index--;
  }

  return *matches.front();
}


/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
