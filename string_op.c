#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char text[] = "My day begins early, and my dog waits by the door. I pack my bag, grab my coat, and walk with my friend Mia to the bus stop. She laughs at my jokes, but MY teacher does not! Oh my! Yesterday my class read a mystery about an army of ants, and I told everyone about my family. Is my story true? Ask my grandmother, my uncle, or my neighbor. I made this lunch myself, and my sandwich is the best one in school. My secret? Smile, keep my promise, and share my snacks. Oh my, tomorrow my brother comes too!";
    int length, count = 0, i;
    char *word;

    length = strlen(text);                 /* measure BEFORE strtok cuts the text */

    word = strtok(text, " ,.!?;");         /* first word */
    while (word != NULL) {
        for (i = 0; word[i] != '\0'; i++)  /* make the word lower case */
            word[i] = tolower(word[i]);

        if (strcmp(word, "my") == 0)       /* exact match only */
            count++;

        word = strtok(NULL, " ,.!?;");     /* next word, or NULL at the end */
    }

    printf("Length: %d\n", length);
    printf("Count: %d\n", count);
    return 0;
}
