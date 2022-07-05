#pragma once

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <functional>

typedef void (*VoidFunction)();

//This is necessary to trick our code into causing an exit.
/**
 * @brief This function does NOTHING. Absolutely nothing.
 * Note: This is required for the exit functionality to work.
 * 
 */
void do_nothing(){};

/**
 * @brief This creates a basic terminal menu
 * 
 */
class TerminalMenu
{
    public:
        TerminalMenu() {};
        ~TerminalMenu() {};
        /**
         * @brief Adds an option to the menu
         * 
         * @param option The umessage to show for users to select from.
         * @param callback The function to run when the option is triggered
         */
        void add_option(std::string option, VoidFunction callback)
        {
            if(exit){
                //Remove the exit call
                options.pop_back();
                //Add the new call
                options.push_back({option,callback});
                //Re-Add the exit call
                options.push_back({exit_prompt, do_nothing});
            }
            else{
                options.push_back({option,callback});
            }
        }
        /**
         * @brief Add an exit option to your program
         * 
         * @param exit_prompt The prompt to use for the exit message
         */
        void add_exit(std::string exit_prompt)
        {
            if(!exit){
                add_option(exit_prompt, do_nothing);
                exit = true;
                this->exit_prompt = exit_prompt;
            }
        }
        /**
         * @brief Set the invalid message displayed.
         * 
         * @param message The message to use for invalid options
         */
        void set_invalid_message(std::string message)
        {
            invalid_message = message;
        }
        /**
         * @brief Set continue execute to true
         * 
         */
        void set_continue_execute()
        {
            continue_exec = true;
        }
        /**
         * @brief The primary run loop
         * 
         */
        int execute()
        {
            print_options();
            auto input = read_input();
            if(input < options.size())
            {
                //Execute the function provided.
                options[input-1].second();
                //This includes a safety to prevent infinite looping the menu by requiring an exit option to loop.
                if(continue_exec && exit){
                    execute();
                }
            }
            //Kind of hacky but this forces the last option to exit this function which will return execution to the caller.
            //We enforce this to be the case during the option additions.
            else if (input == options.size())
            {
                return 0;
            }
            else
            {
                printf("%s", invalid_message.c_str());
                execute();
            } 
            return 0;
        }
    private:
        /**
         * @brief The list of ALL options with both user strings and the functions to run
         * 
         */
        std::vector<std::pair<std::string, VoidFunction>> options;
        
        /**
         * @brief The indicator if we are to exit the loop
         * 
         */
        bool exit = false;
        /**
         * @brief The indicator if we need to continue to execute after an option has been selected.
         * 
         */
        bool continue_exec = false;
        
        /**
         * @brief The prompt to use for exit. This is set when you add the exit option.
         * 
         */
        std::string exit_prompt;
        /**
         * @brief The message to show when an invalid option is selected.
         * 
         */
        std::string invalid_message = "Invalid Option\n";
        
        /**
         * @brief Helper function to print al the options from the list.
         * 
         */
        void print_options()
        {
            int i = 1;
            for(auto const& [prompt, function] : options)
            {
                std::cout << i++ << ") " << prompt << std::endl;
            }
        }
        /**
         * @brief Helper function to read an input from the user. Currently only reads numbers in using scanf.
         * 
         * TODO: Add option for other input list types (ex: a,b,c or I, II, III)
         * Custom would also be nice but require a huge amount of restructuring.
         */
        int read_input()
        {
            int input;
            scanf("%d", &input);
            return input;
        }
};