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

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {

  // a queue of string pointers
  std::queue<const std::string*> matches;

  for (auto s : students) {
    
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
  // STUDENT TODO: Implement this function.
}

/**
 * Takes in the name of a student and the name of its potential match to determine
 *  whether they are a potential match.
 * 
 * @param name The address of a student name that we are comparing against its potential match.
 * @param potential_match The address of a student name that we are comparing our name to.
 * @return    True if their initial's match and false otherwise.
 */
bool split_and_compare(std::string& name, std::string& potential_match) {
  //FIXME:
  // std::istream stream(name);
  
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
