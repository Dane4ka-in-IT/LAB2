#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _node {
    float data;
    struct _node* parent;
    struct _node** children;
    char* name;
} N_Node;

typedef struct _tree {
    N_Node root;
} Tree;

N_Node * newNode(float data) {
    N_Node *node = (N_Node *)malloc(sizeof(N_Node));
    node->data = data;
    node->children = NULL;
    node->name = (char *)malloc(20 * sizeof(char));
    return node;
}

N_Node* addChild(N_Node *parent, float data) {
    N_Node *child = newNode(data);
    child->parent = parent;
    int childCount = 0;
    if (parent->children != NULL) {
        while (parent->children[childCount] != NULL) {
            childCount++;
        }
    }
    parent->children = (N_Node **)realloc(parent->children, (childCount + 2) * sizeof(N_Node *));
    parent->children[childCount] = child;
    parent->children[childCount + 1] = NULL;
    return child;
}

void cleanup(N_Node *node); 

void removeChild(N_Node *parent, N_Node *child) {
    if (parent->children != NULL) {
        int childCount = 0;
        while (parent->children[childCount] != NULL) {
            if (parent->children[childCount] == child) {
                break;
            }
            childCount++;
        }
        if (parent->children[childCount] != NULL) {
            while (parent->children[childCount + 1] != NULL) {
                parent->children[childCount] = parent->children[childCount + 1];
                childCount++;
            }
            parent->children[childCount] = NULL;
            parent->children = (N_Node **)realloc(parent->children, (childCount + 1) * sizeof(N_Node *));
            
            cleanup(child);
        }
    }
}


void printTreeHelper(N_Node *node, int depth) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf(" ");
    }

    printf("%f\n", node->data);

    if (node->children != NULL) {
        int childCount = 0;
        while (node->children[childCount] != NULL) {
            printTreeHelper(node->children[childCount], depth + 1);
            childCount++;
        }
    }
}

void printTree(N_Node *node) {
    printTreeHelper(node, 0);
}

void cleanup(N_Node *node) {
    if (node == NULL) {
        return;
    }

    if (node->children != NULL) {
        int childCount = 0;
        while (node->children[childCount] != NULL) {
            cleanup(node->children[childCount]);
            childCount++;
        }
        free(node->children);
    }
    free(node->name);
    free(node);
}

bool isLinear(N_Node *node) {
    while (node != NULL) {
        int childCount = 0;
        if (node->children != NULL) {
            while (node->children[childCount] != NULL) {
                childCount++;
            }
        }
        if (childCount > 1) {
            return false;
        }
        if (node->children != NULL && node->children[0] != NULL) {
            node = node->children[0]; 
        } else {
            node = NULL; 
        }
    }
    return true;
}

N_Node *findNodeByName(N_Node *node, char *name) {
    if (node == NULL) {
        return NULL;
    }

    if (strcmp(node->name, name) == 0) {
        return node;
    }

    if (node->children != NULL) {
        int childCount = 0;
        N_Node *foundNode = NULL;
        while (node->children[childCount] != NULL && foundNode == NULL) {
            foundNode = findNodeByName(node->children[childCount], name);
            childCount++;
        }
        return foundNode;
    }

    return NULL;
}


int main() {
    N_Node *root = NULL;
    int nodeCount = 0;
    char command[10];
    float value;
    char nodeName1[20], nodeName2[20];
    N_Node *node1, *node2;
    bool exitFlag = false;

    printf("Enter commands:\n");

    while (!exitFlag) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %f", nodeName1, &value);
            if (root == NULL && strcmp(nodeName1, "root") == 0) {
                root = (N_Node *)malloc(sizeof(N_Node));
                root->data = value;
                root->children = NULL;
                root->name = (char *)malloc(20 * sizeof(char));
                strcpy(root->name, "root");
                printf("Created root\n");
            } else {
                node1 = findNodeByName(root, nodeName1);
                if (node1 != NULL) {
                    node2 = addChild(node1, value);
                    nodeCount++;
                    sprintf(node2->name, "node_%d", nodeCount);
                    printf("Created %s\n", node2->name);
                } else {
                    printf("Node not found\n");
                }
            }
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s %s", nodeName1, nodeName2);
            node1 = findNodeByName(root, nodeName1);
            node2 = findNodeByName(root, nodeName2);
            if (node1 != NULL && node2 != NULL) {
                if (node1 == root && node2 == root) {
                    cleanup(root);
                    root = NULL;
                    printf("Root purge\n");
                } else {
                    removeChild(node1, node2);
                }
            } else {
                printf("Node(s) not found\n");
            }
        } else if (strcmp(command, "print") == 0) {
            scanf("%s", nodeName1);
            node1 = findNodeByName(root, nodeName1);
            if (node1 != NULL) {
                printTree(node1);
            } else {
                printf("Node not found\n");
            }
        } else if (strcmp(command, "linear") == 0) {
            scanf("%s", nodeName1);
            node1 = findNodeByName(root, nodeName1);
            if (node1 != NULL) {
                bool isLinearTree = isLinear(node1);
                printf("%s\n", isLinearTree ? "yes" : "no");
            } else {
                printf("Node not found\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            exitFlag = true;
        } else {
            printf("Invalid command\n");
        }
    }

    cleanup(root);

    return 0;
}
