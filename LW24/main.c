#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _node {
    struct _node* left;
    struct _node* right;
    char value;
} Node;

Node* parseExpression(char** expression);
Node* parseTerm(char** expression);
Node* parseFactor(char** expression);

Node* newNode(char value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

char* nextToken(char** expression) {
    while (isspace(**expression)) (*expression)++;
    if (**expression == '\0') return NULL;
    char* token = (char*)malloc(2 * sizeof(char));
    token[0] = **expression;
    token[1] = '\0';
    (*expression)++;
    return token;
}

Node* parseFactor(char** expression) {
    char* token = nextToken(expression);
    if (token == NULL) return NULL;
    Node* node;
    if (token[0] == '(') {
        node = parseExpression(expression);
        free(token);
        token = nextToken(expression);
        if (token == NULL || token[0] != ')') {
            printf("Error: Unbalanced parentheses\n");
            exit(1);
        }
    } else {
        node = newNode(token[0]);
    }
    free(token);
    return node;
}

Node* parsePower(char** expression) {
    Node* node = parseFactor(expression);
    char* token;
    while ((token = nextToken(expression)) != NULL) {
        if (strcmp(token, "^") == 0) {
            Node* right = parseFactor(expression);
            Node* parent = newNode('^');
            parent->left = node;
            parent->right = right;
            node = parent;
        } else {
            (*expression)--;
            free(token);
            break;
        }
        free(token);
    }
    return node;
}

Node* parseTerm(char** expression) {
    Node* node = parsePower(expression);
    char* token;
    while ((token = nextToken(expression)) != NULL) {
        if (strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            Node* right = parsePower(expression);
            Node* parent = newNode(token[0]);
            parent->left = node;
            parent->right = right;
            node = parent;
        } else {
            (*expression)--;
            free(token);
            break;
        }
        free(token);
    }
    return node;
}

Node* parseExpression(char** expression) {
    Node* node = parseTerm(expression);
    char* token;
    while ((token = nextToken(expression)) != NULL) {
        if (strcmp(token, "+") == 0) {
            Node* right = parseTerm(expression);
            Node* parent = newNode('+');
            parent->left = node;
            parent->right = right;
            node = parent;
        } else if (strcmp(token, "-") == 0) {
            Node* right = parseTerm(expression);
            Node* parent = newNode('-');
            parent->left = node;
            parent->right = right;
            node = parent;
        } else {
            (*expression)--;
            free(token);
            break;
        }
        free(token);
    }
    return node;
}

void printExpression(Node* node) {
    if (node == NULL) return;
    if (node->left != NULL) printf("(");
    printExpression(node->left);
    printf("%c", node->value);
    printExpression(node->right);
    if (node->right != NULL) printf(")");
}

void removeZeroMultiplications(Node** node) {
    if (*node == NULL) return;
    removeZeroMultiplications(&(*node)->left);
    removeZeroMultiplications(&(*node)->right);
    if ((*node)->value == '*') {
        if (((*node)->left != NULL && (*node)->left->value == '0') || ((*node)->right != NULL && (*node)->right->value == '0')) {
            free((*node)->left);
            free((*node)->right);
            free(*node);
            *node = newNode('0');
        }
    }
}

void removeZeroAdditions(Node** node) {
    if (*node == NULL) return;
    removeZeroAdditions(&(*node)->left);
    removeZeroAdditions(&(*node)->right);
    if ((*node)->value == '+') {
        if ((*node)->left != NULL && (*node)->left->value == '0') {
            Node* temp = (*node)->right;
            free((*node)->left);
            free(*node);
            *node = temp;
        } else if ((*node)->right != NULL && (*node)->right->value == '0') {
            Node* temp = (*node)->left;
            free((*node)->right);
            free(*node);
            *node = temp;
        }
    }
}

void freeTree(Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, 100, stdin);
    char* p = expression;
    Node* root = parseExpression(&p);
    printExpression(root);
    removeZeroMultiplications(&root);
    removeZeroAdditions(&root);
    printf("\n");
    printExpression(root);
    printf("\n");
    freeTree(root);
    return 0;
}