#pragma once

#include <stdio.h>

/**
 * @brief This creates a basic terminal menu
 * 
 */
template<class BackingStore, class StringType>
class TerminalMenu
{
    public:
        TerminalMenu() {};
        ~TerminalMenu() {};
        /**
         * @brief Adds an option to the menu
         * 
         */
        void add_option(StringType option)
        {
            options += option;
        }
        /**
         * @brief Has the menu run and return an input to you
         * 
         */
        int execute()
        {
            print_options();
            auto input = read_input();
            if(input < options.size())
            {
                return input;
            }
            else
            {
                // TODO: Turn this into something we can manipulate
                printf("Invalid Option\n");
                //Self loop to the start of execute as we need to go till we get an input.
                execute();
            }
        }
    private:
        BackingStore<StringType> options;
        // Helper Functions
        void print_options()
        {
            int i = 1;
            for(StringType option : options)
            {
                printf("{}) {}{}", i++, option, '\n');
            }
        }
        //TODO: Potentially make this accept other types? Chars?
        int read_input()
        {
            int input;
            scanf("%d", &input);
            return input;
        }
};