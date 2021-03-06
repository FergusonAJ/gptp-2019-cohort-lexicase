
#ifndef COHORT_CONFIG_H
#define COHORT_CONFIG_H

#include "config/config.h"

EMP_BUILD_CONFIG(ExperimentConfig,
    // General Group 
    GROUP(GENERAL, "General settings"), 
    VALUE(SEED, int, 909, "Random number seed (-1 to use current time)"),
    VALUE(TREATMENT, size_t, 1, 
        "0 for Reduced Lexicase, " 
        " 1 for Cohort Lexicase, "
        " 2 for Downsampled Lexicase "
        " 3 for Truncated Lexicase"),
    VALUE(POP_SIZE, size_t, 1000, "The size of our evolving population"),
    VALUE(GENERATIONS, size_t, 1000, "The number of generations to simulate"),
    VALUE(DILUTION_PCT, double, 0.0, "The percentage of tests that will be auto-pass "
        "(non-discriminatory)"),
    VALUE(TERMINATE_ON_FOUND, size_t, 0, "If 1, program will terminate as soon as the first "
        "solution is found."),
    
    // Program Group 
    GROUP(PROGRAM_GROUP, "General settings specific to programs."),
    VALUE(MIN_PROG_SIZE, size_t, 1, "Minimum program size"),
    VALUE(MAX_PROG_SIZE, size_t, 64, "Maximum program size"),
    VALUE(PROG_EVAL_TIME, size_t, 64, "How many clock cycles should we give a program"
        " during a test?"),
    VALUE(MUT_PER_BIT_FLIP, double, 0.001, "Program per-bit flip rate."),
    VALUE(MUT_PER_INST_SUB, double, 0.005, "Program per-instruction substitution mutation rate."),
    VALUE(MUT_PER_INST_INS, double, 0.005, "Program per-instruction insertion mutation rate."),
    VALUE(MUT_PER_INST_DEL, double, 0.005, "Program per-instruction deletion mutation rate."),
    VALUE(MUT_PER_PROG_SLIP, double, 0.05, "Program per-program slip mutation rate."),
    VALUE(MUT_PER_MOD_DUP, double, 0.05, "Program per-module whole-module duplication rate."),
    VALUE(MUT_PER_MOD_DEL, double, 0.05, "Program per-module whole-module deletion rate."),
    

    // Hardware Group
    GROUP(HARDWARE, "Virtual evaluation hardware settings"), 
    VALUE(MIN_TAG_SPECIFICITY, double, 0.0, "What is the minimum tag similarity required for"
        " a tag to successfully reference another tag?"),
    VALUE(MAX_CALL_DEPTH, size_t, 64, "Maximum depth of hardware's call stack."),
    
    // Problem Group 
    GROUP(PROBLEM_GROUP, "General settings for constructing a problem"),
    VALUE(PROBLEM_ID, size_t, 0, "Which problem to test on? ("
        "0 for smallest, "
        "1 for for loop index, "
        "2 for median, "
        "3 for compare string lengths, "
        "4 for grade)"),
    VALUE(TRAINING_SET_FILENAME, std::string, "./",  "Path (including name) for the .csv with the "
        "set of training test cases"),
    VALUE(TEST_SET_FILENAME, std::string, "./",  "Path (including name) for the .csv with the "
        "set of validation test cases"),

    // Cohort Lexicase Group
    GROUP(COHORT_LEXICASE_GROUP, "Settings specific to experiments using cohort lexicase (See TREATMENT)"),
    VALUE(PROG_COHORT_SIZE, size_t, 100, "The number of programs in a single cohort"),
    VALUE(TEST_COHORT_SIZE, size_t, 10, "The number of test cases in a single cohort"),
    VALUE(COHORT_MAX_FUNCS, size_t, 0, "Maximum number of tests to check before taking a random " 
        "remaining organism. (0 for no limit, i.e., use the PROG_COHORT_SIZE)."),
    
    // Standard Lexicase Group
    GROUP(LEXICASE_GROUP, "Settings specific to experiments using standard lexicase "
        "(See TREATMENT)"),
    VALUE(LEXICASE_MAX_FUNCS, size_t, 0, "Maximum number of tests to check before taking a random " 
        "remaining organism. (0 for no limit, i.e., use as many cases as needed.)"),
    VALUE(NUM_TESTS, size_t, 0, "The number of the training test cases to actually use (0 for all)"),
   
    // Downsampled Lexicase Group
    GROUP(DOWNSAMPLED_LEXICASE_GROUP, "Settings specific to experiments using downsampled lexicase "
        "(See TREATMENT)"),
    VALUE(DOWNSAMPLED_MAX_FUNCS, size_t, 0, "Maximum number of tests to check before taking random " 
        "remaining organism. (0 for no limit, i.e., use as many cases as needed.)"),
    VALUE(DOWNSAMPLED_NUM_TESTS, size_t, 10, "The number of the training cases to use each update"),
    
    // Truncated Lexicase Group
    GROUP(TRUNCATED_LEXICASE_GROUP, "Settings specific to experiments using truncated lexicase "
        "(See TREATMENT)"),
    VALUE(TRUNCATED_MAX_FUNCS, size_t, 0, "Maximum number of tests to check before taking random " 
        "remaining organism. (0 for no limit, i.e., use as many cases as needed.)"),
    
    // Data Collection Group 
    GROUP(DATA_COLLECTION_GROUP, "Settings specific to data collection."),
    VALUE(OUTPUT_DIR, std::string, "./output/", "Specifies the directory where output files will"
        " be saved"),   
    VALUE(SNAPSHOT_INTERVAL, size_t, 100, "How often should we take population snapshots?"),
    VALUE(SUMMARY_STATS_INTERVAL, size_t, 100, "How often should we output summary stats?"),
    VALUE(SOLUTION_SCREEN_INTERVAL, size_t, 1000, "How often should we screen entire population " 
        "for solutions?"),

    // Debugging Group
    GROUP(DEBUGGING_GROUP, "Settings to help you debug"),
    VALUE(HARDWIRE_SOLUTION, size_t, 1, "If 1, initial population is seeded with "
        "handwritten solutions")

)

#endif
