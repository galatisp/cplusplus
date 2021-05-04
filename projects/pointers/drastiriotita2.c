#include <stdio.h>
int main(){
float x;
float *point_x; /* Δήλωση δείκτη *point_x τύπου float */
x=3.1415;
point_x=&x; /* Η μεταβλητή point_x λαμβάνει τιμή αυτήν της διεύθυνσης του x */
printf("%f \n",x); /* Εκτύπωση της τιμής της μεταβλητής x */
printf("%p \n",&x); /* Εκτύπωση της διεύθυνσης της μεταβλητής x */
printf("%p \n",point_x); /* Εκτύπωση του δείκτη point_x */
printf("%p \n",&point_x); /* Εκτύπωση της διεύθυνσης του point_x */
printf("%f \n",*point_x); /* Εκτύπωση της τιμής της μεταβλητής που δείχνει η point_x */
return 0;
}