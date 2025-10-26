#include <stdio.h>
#include <stdlib.h>

// Structure of polynomial
struct Node {
    int coeff;             
    int exp;                
    struct Node *next;
};

//create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

//insert a term in descending order of exponent
struct Node* insertTerm(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (head == NULL || exp > head->exp) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->exp > exp)
            temp = temp->next;

        if (temp->next != NULL && temp->next->exp == exp) {
            // If term with same exponent exists, add coefficients
            temp->next->coeff += coeff;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

//display polynomial
void displayPoly(struct Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
}

//create polynomial with user input
struct Node* createPoly() {
    struct Node* head = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    return head;
}

//add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            result = insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            result = insertTerm(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0)
                result = insertTerm(result, sumCoeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

//subtract two polynomials (poly1 - poly2)
struct Node* subPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            result = insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            result = insertTerm(result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int diffCoeff = poly1->coeff - poly2->coeff;
            if (diffCoeff != 0)
                result = insertTerm(result, diffCoeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        result = insertTerm(result, -poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Main function with menu
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice;

    printf("\n--- Polynomial Manipulation using SLL ---\n");
    printf("\nEnter first polynomial:\n");
    poly1 = createPoly();
    printf("\nEnter second polynomial:\n");
    poly2 = createPoly();

    do {
        printf("\n\n===== MENU =====\n");
        printf("1. Display Polynomials\n");
        printf("2. Add Polynomials\n");
        printf("3. Subtract Polynomials\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPolynomial 1: ");
                displayPoly(poly1);
                printf("\nPolynomial 2: ");
                displayPoly(poly2);
                printf("\n");
                break;

            case 2:
                result = addPoly(poly1, poly2);
                printf("\nResultant Polynomial (Addition): ");
                displayPoly(result);
                printf("\n");
                break;

            case 3:
                result = subPoly(poly1, poly2);
                printf("\nResultant Polynomial (Subtraction): ");
                displayPoly(result);
                printf("\n");
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
