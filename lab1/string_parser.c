/*
 * string_parser.c
 *
 *  Created on: Nov 25, 2020
 *      Author: gguan, Monil
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_parser.h"

#define _GUN_SOURCE

int count_token (char* buf, const char* delim)
{
	//TODO：
	/*
	*	#1.	Check for NULL string
	*	#2.	iterate through string counting tokens
	*		Cases to watchout for
	*			a.	string start with delimeter
	*			b. 	string end with delimeter
	*			c.	account NULL for the last token
	*	#3. return the number of token (note not number of delimeter)
	*/
    int num_token = 0;
    int old_pos = 0;
    int new_pos = 0;
    int size = strlen(buf);
    //printf("size = %d\n", size);
    for (int i = 0; i < size; i++) {
        if (buf[i] == *delim) {
            new_pos = i;
            //printf("pos = %d\n", new_pos);
        }
        if (new_pos > old_pos + 1) {
            num_token++;
            old_pos = new_pos;
        }
    }
    if (new_pos < size - 1)
        num_token++;
    //printf("number of tokens = %d\n", num_token);
    return num_token;
}

command_line str_filler (char* buf, const char* delim)
{
	//TODO：
	/*
	*	#1.	create command_line variable to be filled and returned
	*	#2.	count the number of tokens with count_token function, set num_token. 
    *           one can use strtok_r to remove the \n at the end of the line.
	*	#3. malloc memory for token array inside command_line variable
	*			based on the number of tokens.
	*	#4.	use function strtok_r to find out the tokens 
    *   #5. malloc each index of the array with the length of tokens,
	*			fill command_list array with tokens, and fill last spot with NULL.
	*	#6. return the variable.
	*/
	command_line token_buffer;
	char* sub_token = strtok(buf, "\n");
	token_buffer.num_token = count_token(sub_token, delim);
	//printf("num_token = %d\n", token_buffer.num_token);
	size_t len = 128;
	token_buffer.command_list = (char**)malloc((token_buffer.num_token + 1) * sizeof(char*));
    for (int i = 0; i < token_buffer.num_token; i++) {
        token_buffer.command_list[i] = (char*)malloc(len * sizeof(char));
        token_buffer.command_list[i] = strtok_r(sub_token, delim, &sub_token);
	
        //printf("token is: %s\n", token_buffer.command_list[i]);
	//
    }
    token_buffer.command_list[token_buffer.num_token] = (char*)malloc(len * sizeof(char));
    token_buffer.command_list[token_buffer.num_token] = NULL;
    return token_buffer;
}


void free_command_line(command_line* command)
{
	//TODO：
	/*
	*	#1.	free the array base num_token
	*/

	for (int i = 0; i <= command->num_token; i++){
		//free(command->command_list[i]);
	}

	     //printf("** token = %s\n", command->command_list[i]);
             //this needs to be fixed, free single pointer
    
    free(command->command_list);  	// works fine
}
