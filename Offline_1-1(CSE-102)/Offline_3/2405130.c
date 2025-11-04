#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAX_DOCS 50
#define MAX_LEN 5000
#define MAX_TOKENS 500
#define MAX_TOKEN_LEN 50
#define NUM_STOP_WORDS 8
char documents[MAX_DOCS][MAX_LEN];
char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
char stop_words[NUM_STOP_WORDS][MAX_TOKEN_LEN]={"the","is","a","an","and","in","of","to"};
int doc=0;
int token;
int is_set=0;
int is_preprocessed=0;
char stemmed_docs[MAX_DOCS][MAX_LEN];
void commands(void){
    printf("\nWelcome to the Document Processing System!\n");
    printf("set         - Prompt for the number of documents and their text.\n");
    printf("preprocess  - Apply normalization, tokenization, stop-words removal, and stemming orderly.\n");
    printf("tf          - Compute and display Term Frequency for a specified word across documents.\n");
    printf("idf         - Compute and display Inverse Document Frequency for a specified word.\n");
    printf("tfidf       - Compute and display TF-IDF scores for a specified word across documents.\n");
    printf("stat        - Display TF, IDF, and TF-IDF for all tokens across all documents in a matrix format.\n");
    printf("help        - Print the list of all available commands.\n");
    printf("exit        - Exit the program\n");
}
void normalize_case_all();
void tokenize_all();
int is_stop_word(char word[]);
void remove_stop_words_all();
void stem_token(char word[]);
void stem_all_tokens();
void preprocess_all();
void stemmed_doc(int id,char r[MAX_LEN]);
int count_word_doc(char word[],int id);
int count_total_words_doc(int id);
double compute_idf(char word[]);
double compute_tf(char word[],int doc_id);
void compute_tfidf_all(char word[]);
void sort();
void display_stat();
int main(){
    char s[100];
    commands();
    while(1){
        printf("Enter command: ");
        fgets(s,sizeof(s),stdin);
        s[strcspn(s,"\n")]='\0';

        if(strcmp(s,"exit")==0){
            printf("Exiting program.\n");
            break;
        }
        else if(strcmp(s,"help")==0){
            commands();
        }
        else if(strcmp(s,"set")==0){
            printf("Enter number of documents (1-50): ");
            char temp[10];
            fgets(temp,sizeof(temp),stdin);
            doc=atoi(temp);
            if(doc<1 || doc>MAX_DOCS){
                printf("Invalid number of documents. Must be from 1 to 50.\n");
                continue;
            }
            for(int i=0;i<doc;i++){
                printf("Enter document %d:",i+1);
                fgets(documents[i],MAX_LEN,stdin);
            }
            is_set=1;
            is_preprocessed=0;
            printf("Documents set successfully.Please, enter 'preprocess' command now. It will take other commands.\n");
        }
        else if(strcmp(s,"preprocess")==0){
            if(!is_set){
                printf("No documents set.Use 'set' command first.\n");
                continue;
            }
            preprocess_all();
            is_preprocessed=1;
        }
        else if(strcmp(s,"tf")==0){
            if(!is_set){
                printf("No documents set.Use 'set' command first\n");
                continue;
            }
            char word[50];
            printf("Enter word to compute TF: ");
            fgets(word,sizeof(word),stdin);
            word[strcspn(word,"\n")]='\0';
            for(int i=0;i<doc;i++){
                printf("Documents %d: %.4lf\n",i+1,compute_tf(word,i));
            }
        }
        else if(strcmp(s,"idf")==0){
            if(!is_set){
                printf("No documents set. Use 'set' command first.\n");
                continue;
            }
            char word[50];
            printf("Enter word to compute IDF: ");
            fgets(word,sizeof(word),stdin);
            word[strcspn(word, "\n")] = '\0';
            printf("IDF for '%s': %.4lf\n", word,compute_idf(word));
        }
        else if(strcmp(s,"tfidf")==0){
            if(!is_set){
                printf("No documents set. Use 'set' command first.\n");
                continue;
            }
            char word[50];
            printf("Enter word to compute TF-IDF: ");
            fgets(word,sizeof(word),stdin);
            word[strcspn(word, "\n")] = '\0';
            compute_tfidf_all(word);
        }
        else if(strcmp(s,"stat")==0){
            display_stat();
        }
        else{
            printf("Unknown command. Type 'help' for list of commands.\n");
        }
    }
    return 0;
}
void normalize_case_all(){
    for(int i=0;i<doc;i++){
        for(int j=0;documents[i][j];j++){
            documents[i][j]=tolower(documents[i][j]);
        }
    }
    printf("Normalized Documents:\n");
    for(int i=0;i<doc;i++){
        printf("Document %d: %s",i+1,documents[i]);
    }
    printf("Documents normalized.\n");
}
void tokenize_all(){
    token=0;
    for(int i=0;i<doc;i++){
        int len=strlen(documents[i]);
        char word[MAX_TOKEN_LEN];
        int idx=0;
        for(int j=0;j<=len;j++){
            if(isalnum(documents[i][j])){
                word[idx++]=documents[i][j];
            }
            else{
                if(idx>0){
                    word[idx]='\0';
                    strcpy(tokens[token++],word);
                    idx=0;
                }
            }
        }
    }
    printf("Tokens:\n");
    for(int i=0;i<token;i++){
        printf("%d. %s\n",i+1,tokens[i]);
    }
    printf("Tokenization complete. Total tokens: %d\n",token);
}
int is_stop_word(char word[]){
    for(int i=0;i<NUM_STOP_WORDS;i++){
        if(strcmp(word,stop_words[i])==0) return 1;
    }
    return 0;
}

void remove_stop_words_all() {
    int new_token=0;
    for (int i=0;i<token;i++) {
        if (!is_stop_word(tokens[i])) {
            strcpy(tokens[new_token++],tokens[i]);
        }
    }
    token=new_token;
    printf("Tokens after stop-word removal:\n");
    for (int i=0;i<token;i++) {
        printf("%d. %s\n",i+1,tokens[i]);
    }
    printf("Stop-word removal complete. Tokens remaining: %d\n", token);
}

void stem_token(char word[]){
    int len=strlen(word);
    if(len>3 && strcmp(&word[len-3],"ing")==0){
        word[len-3]='\0';
    }
    else if(len>2 && strcmp(&word[len-2],"ed")==0){
        word[len-2]='\0';
    }
    else if(len>1 && word[len-1]=='s'){
        word[len-1]='\0';
    }
}
void stem_all_tokens(){
    for(int i=0;i<token;i++){
        stem_token(tokens[i]);
    }
    printf("Stemmed Tokens:\n");
    for(int i=0;i<token;i++){
        printf("%d. %s\n",i+1,tokens[i]);
    }
    printf("Stemming complete. Total stemmed tokens: %d\n",token);
}

void preprocess_all(){
    normalize_case_all();
    tokenize_all();
    remove_stop_words_all();
    stem_all_tokens();
}
void stemmed_doc(int id,char r[MAX_LEN]){
    char tmp[MAX_LEN];
    strcpy(tmp,documents[id]);
    int len=strlen(tmp);
    int idx=0;
    char word[MAX_TOKEN_LEN];
    char output[MAX_LEN];
    output[0]='\0';
    for(int i=0;i<=len;i++){
        if(isalnum(tmp[i])){
            word[idx++]=tmp[i];
        }
        else{
            if(idx>0){
                word[idx]='\0';
                if(!is_stop_word(word)){
                    stem_token(word);
                    strcat(output,word);
                    strcat(output," ");
                }
                idx=0;
            }
        }
    }
    strcpy(r,output);
}
int count_word_doc(char word[],int id){
    char processed[MAX_LEN];
    stemmed_doc(id,processed);
    int c=0;
    char *tok=strtok(processed," ");
    while(tok){
        if(strcmp(tok,word)==0)
        c++;
        tok=strtok(NULL," ");
    }
    return c;
}
int count_total_words_doc(int id){
    char processed[MAX_LEN];
    stemmed_doc(id,processed);
    int c=0;
    char *tok=strtok(processed," ");
    while(tok){
        c++;
        tok=strtok(NULL," ");
    }
    return c;
}
double compute_tf(char word[],int doc_id){
    char stemmed[MAX_TOKEN_LEN];
    strcpy(stemmed,word);
    stem_token(stemmed);
    int count=count_word_doc(stemmed,doc_id);
    int t=count_total_words_doc(doc_id);
    if(t==0) return 0.0;
    return (double)count/t;
}
double compute_idf(char word[]){
    char stemmed[MAX_TOKEN_LEN];
    strcpy(stemmed,word);
    stem_token(stemmed);
    int count=0;
    for(int i=0;i<doc;i++){
        if(count_word_doc(stemmed,i)>0)
        count++;
    }
    return log10((double)MAX_DOCS/(1+count));
}
void compute_tfidf_all(char word[]){
    double idf=compute_idf(word);
    char stemmed[MAX_TOKEN_LEN];
    strcpy(stemmed,word);
    stem_token(stemmed);
    printf("TF-IDF for %s:\n",word);
    for(int i=0;i<doc;i++){
        double tf=compute_tf(word,i);
        printf("Document %d: %.4lf\n",i+1,tf*idf);
    }
}
void sort(){
    for(int i=0;i<token-1;i++){
        for(int j=i+1;j<token;j++){
            if(strcmp(tokens[i],tokens[j])>0){
                char t[MAX_TOKEN_LEN];
                strcpy(t,tokens[i]);
                strcpy(tokens[i],tokens[j]);
                strcpy(tokens[j],t);
            }
        }
    }
}
void display_stat(){
    if(!is_set){
        printf("No documents set. Use 'set' command first.\n");
        return;
    }
    sort();
    printf("============== TF ================\n");
    printf("                            ");
    for(int i=0;i<doc;i++)
        printf("doc%d        ",i+1);
        printf("\n");
    for(int i=0;i<token;i++){
        printf("%-28s",tokens[i]);
        for (int j=0;j<doc;j++) {
            printf("%.4lf      ",compute_tf(tokens[i], j));
        }
        printf("\n");
    }
    printf("\n=============== IDF ===============\n");
    printf("                             IDF\n");
    for(int i=0;i<token;i++) {
        printf("%-28s%.4lf\n",tokens[i],compute_idf(tokens[i]));
    }
    printf("\n============= TF-IDF ==============\n");
    printf("                            ");
    for (int i=0;i<doc;i++)
        printf("doc%d        ", i + 1);
        printf("\n");
    for(int i=0;i<token;i++){
        double idf=compute_idf(tokens[i]);
        printf("%-28s",tokens[i]);
        for(int j=0;j<doc;j++){
            printf("%.4lf      ",compute_tf(tokens[i],j)*idf);
        }
        printf("\n");
    }
}
