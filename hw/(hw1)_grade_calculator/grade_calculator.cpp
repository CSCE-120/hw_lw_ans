// These headers define some of the classes and functions we need
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>

// ONLY MAKE CHANGES WHERE THERE IS A TODO(student)

// These using declarations let us refer to things more simply
// e.g. instead of "std::cout" we can just write "cout"
using std::cout, std::endl, std::cin, std::string, std::getline;

// Some methods are already implemented for you
// You should not modify them
// Even minor changes might cause you to fail test cases for the wrong reasons

void println(const string& str, double value) {
    cout << str << std::setw(6) << value << endl;
}
void println(const string& str, char value) {
    cout << str << value << endl;
}
void println(const string& str) {
    cout << str << endl;
}

// pretty-print a summary of the grades
void print_results(double homework,
                   double labwork,
                   double midterm_exams,
                   double final_exam,
                   double quizzes,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade) {
    cout << std::fixed << std::setprecision(2);
    println("summary:");
    println("      homework: ", homework);
    println("       labwork: ", labwork);
    println(" midterm exams: ", midterm_exams);
    println("    final exam: ", final_exam);
    println("       quizzes: ", quizzes);
    println("    engagement: ", engagement);
    println("----------------------");
    println("weighted total: ", weighted_total);
    println("final letter grade: ", final_letter_grade);
}

// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
void get_category_and_score(const string& line,
                            string* category,
                            double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

int main() {
    // TODO(student): add more variables, as needed
    double homework_score = 0; // 10% of overall grade.
    double labwork_score = 0; // 5% of overall grade. Score is either 1 for complete or 0 for incomplete.
    double midterm_exams_score = 0; // 35% of overall grade. Lowest midterm is weighed half.
    double final_exam_score = 0; // 25% of overall grade. Only one final exam.
    double quizzes_score = 0; // 20% of overall grade. Maximum score for each quiz is 10.
    double engagement_score = 0; // 5% of overall grade. Only one engagement.

    double lowest_midterm = 100.00; // Placeholder lowest midterm. Check each midterm score for possible lower values.

    double hw_counter = 0;
    double lw_counter = 0;
    double exam_counter = 0;
    double quiz_counter = 0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "hw") {
            // TODO(student): process a homework score
            if (score > 100) {homework_score += 100;} else {homework_score += score;}
            hw_counter++;
        } else if (category == "lw") {
            // TODO(student): process a labwork score
            labwork_score += score;
            lw_counter++;
        } else if (category == "exam") {
            // TODO(student): process a midterm exam score
            midterm_exams_score += score;
            if (score < lowest_midterm) {lowest_midterm = score;}
            exam_counter++;
        } else if (category == "final-exam") {
            // TODO(student): process the final exam score
            final_exam_score += score;
        } else if (category == "quiz") {
            // TODO(student): process a reading score
            quizzes_score += score;
            quiz_counter++;
        } else if (category == "engagement") {
            // TODO(student): process the engagement score
            engagement_score += score;
        } else {
            println("ignored invalid input");
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): finalize computation of component scores
    if (hw_counter == 0) {homework_score += 0;} else {homework_score /= hw_counter;}
    if (lw_counter == 0) {labwork_score += 0;} else {labwork_score /= lw_counter; labwork_score *= 100;}
    if (quiz_counter == 0) {quizzes_score += 0;} else {quizzes_score /= quiz_counter; quizzes_score *= 10;}
    if (engagement_score + 15 > 100) {engagement_score = 100;} else {engagement_score += 15;}

    if (exam_counter == 1) {
        midterm_exams_score = midterm_exams_score / exam_counter;
    } else if (exam_counter == 0) {
        midterm_exams_score += 0;
    } else {
        double highest_midterms = (midterm_exams_score - lowest_midterm) / (exam_counter - 1);
        double highest_midterm_weight = 0.35 / (exam_counter - 1 + 0.5);
        double lowest_midterm_weight = highest_midterm_weight / 2;
        midterm_exams_score = ((highest_midterms * (highest_midterm_weight * (exam_counter - 1))) + (lowest_midterm * lowest_midterm_weight)) / 35 * 100;
    }

    // TODO(student): compute weighted total of components
    double weighted_total = (homework_score * 0.10) + (labwork_score * 0.05) + (midterm_exams_score * 0.35) +
        (final_exam_score * 0.25) + (quizzes_score * 0.20) + (engagement_score * 0.05);

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if (weighted_total + 0.5 >= 90) {
        final_letter_grade = 'A';
    } else if (weighted_total + 0.5 >= 80) {
        final_letter_grade = 'B';
    } else if (weighted_total + 0.5 >= 70) {
        final_letter_grade = 'C';
    } else if (weighted_total + 0.5 >= 60) {
        final_letter_grade = 'D';
    } else {
        final_letter_grade = 'F';
    }

    print_results(
        homework_score,
        labwork_score,
        midterm_exams_score,
        final_exam_score,
        quizzes_score,
        engagement_score,
        weighted_total,
        final_letter_grade);
}