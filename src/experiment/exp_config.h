
#ifndef COHORT_CONFIG_H
#define COHORT_CONFIG_H

#include "config/config.h"

EMP_BUILD_CONFIG(ExperimentConfig,
    // General Group 
    GROUP(GENERAL, "General settings"), 
    VALUE(SEED, int, 0, "Random number seed (-1 to use current time)"),
    VALUE(TREATMENT, size_t, 0, "0 for Reduced Lexicase, 1 for Cohort Lexicase,"
        " 2 for Downsampled Lexicase"),
    VALUE(POP_SIZE, size_t, 256, "The size of our evolving population"),
   
    // Program Group 
    GROUP(PROGRAM_GROUP, "General settings specific to programs."),
    VALUE(MIN_PROG_SIZE, size_t, 1, "Minimum program size"),
    VALUE(MAX_PROG_SIZE, size_t, 128, "Maximum program size"),
    VALUE(PROG_EVAL_TIME, size_t, 256, "How many clock cycles should we give a program"
        " during a test?"),

    // Hardware Group
    GROUP(HARDWARE, "Virtual evaluation hardware settings"), 
    VALUE(MIN_TAG_SPECIFICITY, double, 0.0, "What is the minimum tag similarity required for"
        " a tag to successfully reference another tag?"),
    VALUE(MAX_CALL_DEPTH, size_t, 128, "Maximum depth of hardware's call stack."),
    
    // Problem Group 
    GROUP(PROBLEM_GROUP, "General settings for constructing a problem"),
    VALUE(PROBLEM_ID, size_t, 0, "Which problem to test on? (0 for smallest)")
)

#endif