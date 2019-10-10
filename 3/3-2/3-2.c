#include <stdio.h>
 
void escape(char new_line[], char old_line[]);
void reverse_escape(char new_line[], char old_line[]);
 
int main()
{
        char old_line[100] = "C_programming\tc\nsource\ncode\b\\";
        char new_line[100];
    	char new_line2[100];
 
        printf("Original line=\n%s\n\n", old_line);
        escape(new_line, old_line);
        printf("escape=\n%s\n\n", new_line);
        reverse_escape(new_line2, new_line);
        printf("Reverse escape=\n%s\n\n", new_line2);
 
        return 0;
}
 
 
void escape(char new_line[], char old_line[])
{
    	int i, j;
    	for(i = j = 0; old_line[i] != '\0'; i++, j++){
        	switch(old_line[i]){
            		case '\n':
                		new_line[j] = '\\';
        			++j;
                		new_line[j] = 'n';
                		break;
            		case '\t':
                		new_line[j] = '\\';
                		j++;
                		new_line[j] = 't';
               	 		break;
        		case '\b':
                		new_line[j] = '\\';
                		j++;
                		new_line[j] = 'b';
                		break;
        		case '\\':
        			new_line[j] = '\\';
        			j++;
        			new_line[j] = '\\';
        			break;
            		default:
                		new_line[j] = old_line[i];
                		break;
        	}
    	}
    
    	new_line[j] = '\0';
}
 
void reverse_escape(char new_line[], char old_line[])
{
        int i, j;
 
        j = 0;
      	for(i = j = 0; old_line[i] != '\0'; i++){
                switch(old_line[i]){
               		case '\\':
                		switch(old_line[++i]){
    					case 'n':
                				new_line[j++] = '\n';
                                            	break;
                                    	case 't':
                                            	new_line[j++] = '\t';
                                            	break;
                                        case 'b':
                                                new_line[j++] = '\b';
                                                break;
                    			case '\\':
                        			new_line[j++] = '\\';
                        			break;
                                    	default:
                                            	new_line[j++] = '\\';
                        			++j;
                        			new_line[j++] = old_line[i];
                                            	break;
                            	}	
                		break;
                        default:
                                new_line[j++] = old_line[i];
                                break;
               	}
      	}
        new_line[j] = '\0';
}

