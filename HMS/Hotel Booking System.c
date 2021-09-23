#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

void main_menu();
void admin();
void customer();
void view_available_rooms();
void book_room();
void manage_booking();
void view_specific_booking(num_ent);
void view_bookings();
void admin_menu();
void checkout_guest(num_ent);
void update_booking(num_ent);
void back();
void view_specific_reciept(num_ent);
FILE* fp;
FILE* enter;
FILE* enter1;

struct booking
{
    char pass[30];
    char nroom_no[10];
    char name[20];
    char room[10];
    char bf[20];
    char num[10];
    char email[30];
    char room_no[10];
    int days;
    char checkin[10];
    char checkout[10];
    char roomtype[20];
    float amount;
    int tax;
    char nname[20];
    char ncheckin[20];
    char ncheckout[20];
    char nemail[30];
    char roomtype2[10];
    
}r;

struct update {
    char pass[30];
    char name[20];
    char num[20];
    char email[30];
    char room_no[20];
    char checkin[20];
    char checkout[20];
    char roomtype[20];
    char roomtype2[20];
    char amount[10];
    char total[10];
    char days[10];
    char tax[10];
    char amount1[10];
}s;

struct update2 {
    char pass[30];
    char name[20];
    char num[10];
    char email[15];
    char room_no[5];
    char checkin[10];
    char checkout[10];
    char roomtype[10];
    char roomtype2[10];
    char amount[10];
    char total[10];
    char days[10];
    char tax[10];
    char amount1[10];
}b;

// This function is the main menu. 
void main_menu()
{
    while (1) {
        int opt1 ;
        printf("\n        Main Menu");
        printf("\n>>>\tTo Access the system as ADMIN enter --> 1 ");
        printf("\n>>>\tTo Access the system as a Guest enter  --> 2 ");
        printf("\n>>>\tTo EXIT from the System enter --> 3  ");
        printf("\n>>\t");
        scanf_s("%d", &opt1);
        switch (opt1)
        {
        case 1: {
            admin();
        }
        case 2: {
            customer();
        }
        case 3: {
            exit(0);
        }
        default: {
            printf("Invalid Entry \n");
            printf("Please Try Again");
            printf("\n");
        }
        }
    }
}

void admin()
{
    char pass[10];
    char pass_r[10];
    int i;
    printf("\n Welcome Admin!");
    for (i = 0; i < 6; i++) {
        printf("\n Please enter the password to continue --> ");
        scanf("%s", pass);
        fp = fopen("Pass.txt", "r");
        if (fp == NULL) { printf("Can't open Pass file"); }
        else {
            fscanf(fp, "%s", pass_r);
            if (strcmp(pass_r, pass) == 0)
            {
                printf("\n Access granted!\n");
                admin_menu();
            }
            else
            {
                printf("\nIncorrect password, Please Try Again.");
                printf("\nYou have %d trys left ", 5 - i - 1);

            }
            if (i == 4) {
                printf("\n Access Denied");
                exit(0);
            }
        }
    }
}
//This is admin menu.
void admin_menu()
{
    while (1) {
        int opt1;
        char num_ent[15];
        printf("\n");
        printf(" Admin Menu \n");
        printf("\n>>>\tView All Customer Booking Details --> 1 ");
        printf("\n>>>\tView Specific Customer Booking Details --> 2 ");
        printf("\n>>>\tView List of Rooms  --> 3 ");
        printf("\n>>>\tView List of all Booked Rooms  --> 4 ");
        printf("\n>>>\tView Specific Customer Booking Reciept  --> 5 ");
        printf("\n>>>\tCheckout Customer --> 6 ");
        printf("\n>>>\tBook Room --> 7 ");
        printf("\n>>>\tExit --> 8 ");
        printf("\n>> ");
        scanf_s("%d", &opt1);
        switch (opt1)
        {
        case 1:
        {
            view_bookings();
            break;
        }
        case 2: {printf("Enter Customer's Passport/IC Number:"); scanf("%s", num_ent); view_specific_booking(num_ent); break; }
        case 3:
        {
            FILE* file = fopen("Room_info.txt", "r");
            if (file == NULL) { printf("can't open the file"); }
            else {
                char line[1000];
                while (fgets(line, 1000, file))
                {
                    printf("%s", line);
                }
                fclose(file);
                break;
            }
        }
        case 4: 
        {
            FILE* file = fopen("Booked_Rooms.txt", "r");
            if (file == NULL) { printf("file can't open"); }
            else {
                char line[1000];
                while (fgets(line, 1000, file))
                {
                    printf("%s", line);
                }
                fclose(file);
                break;
            }
        }
        case 5: {printf("Enter Customer's Passport/IC Number:"); scanf("%s", num_ent); view_specific_reciept(num_ent); break; }
        case 6: {printf("Enter Customer's Passport/IC Number:"); scanf("%s", num_ent); checkout_guest(num_ent);break;}
        case 7: {
            book_room();
            break;
        }
        case 8: {main_menu(); }
        default: {
            printf("Invalid Entry \n");
            printf("Please Try Again");
            printf("\n");
        }
        }
        back();
    }
}

void view_bookings() 
// Looks through the file and displays all the records
{
    FILE* file = fopen("bookings.txt", "r");
    if (file == NULL) { printf("can't open the file"); }
    else
    {
        char line[1000];
        printf("R.No Name   ID No. Pass Email      Chkin  Chkout\n");
        while (fgets(line, 1000, file))
        {
            
            printf("%s", line);
        }
        fclose(file);
    }
}
//Customer menu
void customer() {
    printf("\n");
    printf("\n Welcome to Royale Hotels Booking Portal!");
    printf("\n");
    int opt4;
    while (1)
    {
        printf("\n>>>\t Customer Menu");
        printf("\n>>\tView available rooms --> 1 ");
        printf("\n>>\tBook a Room --> 2 ");
        printf("\n>>\tManage Booking --> 3 ");
        printf("\n>>\tExit --> 4 ");
        printf("\n>> ");
        scanf("%d", &opt4);
        switch (opt4)
        {
        case 1: {
            view_available_rooms();
            break;
        }
        case 2: {
            book_room();
            break;
        }
        case 3: {
            manage_booking();
            break;
        }
        case 4: {
            main_menu();
        }
        default: {
            printf("Invalid Entry \n");
            printf("Please Try Again");
            printf("\n");
        }
        }
        printf("\n");
        back();
    }
}

void view_available_rooms()
// Displays the availability of each room
{
    int opt1;
    int Found = 0;
    char one[10];
    char two[10];
    char three[10];
    char four[10];
    char five[10];
    FILE* file1 = fopen("Room_info.txt", "r");
    if (file1 == NULL) {printf("can't open");}
    char line[1000];
    while (fgets(line, 1000, file1)) 
    {printf("%s", line);}
    fclose(file1);
    printf("\nEnter the room number you want to check the Avalabiity for: ");
    scanf("%s", r.room_no);
    printf("\n");
    FILE* file = fopen("Booked_Rooms.txt", "r");
    if (file == NULL) { printf("can't open"); }
    while (fscanf(file, "%s %s %s %s %s", one, two, three, four, five) != -1)
    {
        if (strcmp(one, r.room_no) == 0)
        {
            Found = 1;
            printf("Room No.%s (%s %s) is NOT Available from %s to %s \n\n",one, two, three, four, five);
        }
    }
    if (Found == 0) {
        printf("This Room is Available Throughout the following week\n");
        printf("Hurry Up!! Book your Desired Room as soon as possible\n\n");
    }
    printf("To Book a Room enter --> 1\n");
    printf("To go Back to Customer Options enter --> 2\n");
    printf(">>");
    scanf("%d", &opt1);
    if (opt1 == 1) { printf("\n"); book_room(); customer(); }
    
}

void book_room()
// This function records the booking from the guests
{
    int total = 0;
    float total2;
    int tax = 10;
    int amount = 0;
    float amount1;
    float total1;
    char c_no[40];
    char cvv_no[10];
    char exp_no[10];
    int days = 0;
    char opt2[10];
    char status1[10] = "Paid";
    char opt3[10];
    time_t t;
    time(&t);

    printf("Enter your name: ");
    scanf("%s", r.name);
    printf("Enter your Passport/IC Number: ");
    scanf("%s", r.num);
    printf("Create a Unique Password : ");
    scanf("%s", r.pass);
    printf("Enter your Email: ");
    scanf("%s", r.email);  
    printf("Enter your check in Day: ");
    scanf("%s", r.checkin);
    printf("Enter your check out Day: ");
    scanf("%s", r.checkout);
    printf("Enter the room number you wish to book: ");
    scanf("%s", r.room_no);
    int Found = 0;
    FILE* file = fopen("Booked_Rooms.txt", "r");
    if (file == NULL) { printf("can't open"); }
    char one[10];
    char two[10];
    char three[10];
    char four[10];
    char five[10];
    while (fscanf(file, "%s %s %s %s %s", one,two,three,four,five) != -1)
    {
        if (strcmp(one, r.room_no) == 0 && strcmp(four,r.checkin)==0 && strcmp(five,r.checkout)==0)
        {
            Found = 1;
            printf("Sorry Room No. %s (%s %s) is booked from %s to %s \n",one, two, three, four,five);
            printf("Please Try Again with different Days\n\n");
            customer();
        }
    }

    if (strstr(r.room_no, "101")) { strcpy(r.roomtype, "Superior Room"); amount = 180; }
    else if (strstr(r.room_no, "102")) { strcpy(r.roomtype, "Deluxe Room"); amount = 200; }
    else if (strstr(r.room_no, "103")) { strcpy(r.roomtype, "Studio Room"); amount = 250; }
    else if (strstr(r.room_no, "104")) { strcpy(r.roomtype, "Executive Studio"); amount = 400; }
    else if (strstr(r.room_no, "105")) { strcpy(r.roomtype, "Deluxe Studio"); amount = 500; }
    else if (strstr(r.room_no, "201")) { strcpy(r.roomtype, "Superior Room"); amount = 150; }
    else if (strstr(r.room_no, "202")) { strcpy(r.roomtype, "Deluxe Room"); amount = 200; }
    else if (strstr(r.room_no, "203")) { strcpy(r.roomtype, "Studio Room"); amount = 250; }
    else if (strstr(r.room_no, "204")) { strcpy(r.roomtype, "Executive Studio"); amount = 400; }
    else if (strstr(r.room_no, "205")) { strcpy(r.roomtype, "Deluxe Studio"); amount = 500; }
    else { printf("\nInvalid Room Number\nPlease Try Again\n\n"); customer(); }
    printf("");
    printf("The amount of the room %s for one day is RM %d \n", r.room_no, amount);
    printf("Enter the number of days you wish to stay at our hotel: ");
    scanf("%d", &days);
    total = days * amount;
    printf("\n");
    printf("Review Your Details Before proceeding with the booking \n");
    printf("\n");
    printf("Name : %s \n", r.name);
    printf("Passport / IC No. : %s \n", r.num);
    printf("Your Unique Password : %s \n", r.pass);
    printf("Email : %s \n", r.email);
    printf("Room Number : %s \n", r.room_no);
    printf("Room Type : %s \n", r.roomtype);
    printf("Check In Day : %s \n", r.checkin);
    printf("Check Out Day : %s \n", r.checkout);
    printf(">>> Total Amount: RM %d\n", total);
    printf("\n");
    printf("Proceed To Payment  --> 1\n");
    printf("Exit --> 2\n");
    printf(">>");
    scanf("%s", opt2);
    if (strstr(opt2, "1"))
    {

        printf("Enter your (Credit/Debit) Card Number:");
        scanf("%s", c_no);
        printf("Enter the 3 digit CVV number:");
        scanf("%s", cvv_no);
        printf("Enter the card's Expiry Date:");
        scanf("%s", exp_no);
        printf("Total Number of days : %d \n", days);
        printf("Total amount for %d days : RM %d \n", days, total);
        printf("Service Tax (in percentage)= %d\n", tax);
        total2 = 0.1f;
        total1 = total * total2;
        amount1 = total + total1;
        printf("Total Amount (including taxes): RM %.2f \n", amount1);
        printf("\n");
        printf("To confirm payment enter -> y OR To exit enter -> n\n");
        printf(">>> ");
        scanf("%s", opt3);
        if (strstr(opt3, "y"))
        {
            printf("Payment Succesful");
            printf("\n");
            printf("\n \t-------------------------------------------------------------------------");
            printf("\n \t                                                                         ");
            printf("\n \t\t\t\t\tRoyale Hotels\t\t\t\t  ");
            printf("\n \t                                                                         ");
            printf("\n \t\t\tBooking Reciept\t%s", ctime(&t));
            printf("\n \tPassport/IC No. : %s\t\t\t\tRoom Number: %s\t\t", r.num, r.room_no);
            printf("\n \t-------------------------------------------------------------------------");
            printf("\n \tContents\t\t Amount(1day)\t No.Of Days    Total Amount(in RM)");
            printf("\n \t%s\t\t RM %d\t\t  %d\t\tRM %d", r.roomtype, amount, days, total);
            printf("\n \tService Tax\t\t\t\t\t\tRM %.2f", total1);
            printf("\n \tTotal (Including Taxes)\t\t\t\t\tRM %.2f  ", amount1);
            printf("\n \t                                                                         ");
            printf("\n \t--------------------------------------------------------------------------");
            printf("\n");
            enter1 = fopen("Reciepts.txt", "a");

            fprintf(enter1, "%s %s %s %s %d %d %d %.2f %.2f %s", r.room_no, r.name, r.num, r.roomtype, amount, total, days, total1, amount1, ctime(&t));
            //fprintf(enter1, "\n");
            fclose(enter1);
        }
        else { printf("Thank You!"); customer(); }
    }
    else { printf("Thank You!"); customer(); }

    enter = fopen("bookings.txt", "a");
    fprintf(enter, "%s %s %s %s %s %s %s", r.room_no, r.name, r.num, r.pass, r.email, r.checkin, r.checkout);
    fprintf(enter, "\n");
    fclose(enter);
    enter1 = fopen("Booked_Rooms.txt", "a");
    fprintf(enter1, "%s %s\t%s %s", r.room_no, r.roomtype, r.checkin, r.checkout);
    fprintf(enter1, "\n");
    fclose(enter1);

    printf("\n");
    printf("Congratulations Your Booking has been processed Successfully \n");
    printf("Thank You For Booking with Royale Hotels\n");
    
}

void manage_booking() 
// This function validates the guest's credentials and then allows them to access their details 
{
    int opt2;
    char num_ent[20];
    char pass[20];
    int found = 0;
    while (getchar() != '\n');
    printf("Enter your Passport/IC number: ");
    scanf("%s", num_ent);
    printf("Enter your Unique Password: ");
    scanf("%s", pass);
    fp = fopen("bookings.txt", "r");
    while (fscanf(fp, "%s %s %s %s %s %s", r.room_no, r.name, r.num, r.pass, r.email, r.checkin) != -1)
    {
        fgets(r.bf, 255, (FILE*)fp);
        if (strcmp(r.num , num_ent) == 0 && strcmp(r.pass,pass)==0)
        {
            found = 1;
            printf("\n Welcome %s\n", r.name);
            break;
            
        }
        
    }
    fclose(fp);
    if (found == 1)
    {
       
        while (1)
        {
            printf("\n");
            printf(" Manage Booking Options\n");
            printf("\n>>\tView Your Booking Details --> 1 ");
            printf("\n>>\tUpdate Booking Details-->2");
            printf("\n>>\tCheckout --> 3 ");
            printf("\n>>\tView Your Booking Reciept --> 4 ");
            printf("\n>>\tExit --> 5 ");
            printf("\n>> ");
            scanf("%d", &opt2);
            switch (opt2)
            {
            case 1: {view_specific_booking(num_ent); break; }
            case 5: {customer(); break; }
            case 2: {update_booking(num_ent); break; }
            case 3: {checkout_guest(num_ent); break;}
            case 4: {view_specific_reciept(num_ent); break; }
            default: { printf("Invalid Entry \n"); printf("Please Try Again"); printf("\n"); }
            }
            back();
        }

    }
    else if (found == 0)
    {
        printf("\nWrong ID number or Password\n"); back(); printf("\n"); customer();
    }
    
}

void back() 
{
    char opt1[10];
    printf("\n");
    printf("Enter y to proceed further: ");
    scanf("%s", opt1);
}

void view_specific_reciept(char num_ent[10])
// Displays the Guest's booking reciept
{
    int guestFound = 0;
    char amount[20];
    char total[20];
    char days[20];
    char tax[20];
    char amount1[10];
    char roomtype2[10];
    char tim[10];
    char tim1[10];
    char tim2[10];
    char tim3[10];
    char tim4[10];
    fp = fopen("Reciepts.txt", "r");
    if (fp == NULL) { printf("Can't Open the file"); }
    else {
        while (fscanf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", r.room_no, r.name, r.num, r.roomtype, roomtype2, amount, total, days, tax, amount1, tim, tim1, tim2, tim3, tim4) != -1)
        {

            if (strcmp(r.num, num_ent) == 0)
            {

                guestFound = 1;
                printf("\n \t-------------------------------------------------------------------------");
                printf("\n \t                                                                         ");
                printf("\n \t\t\t\t\tRoyale Hotels\t\t\t\t  ");
                printf("\n \t                                                                         ");
                printf("\n \t\t\t\t\tBooking Reciept\t");
                printf("\n \tPassport/IC No. : %s\t\t\t\tRoom Number: %s\t\t", r.num, r.room_no);
                printf("\n \t-------------------------------------------------------------------------");
                printf("\n \tContents\t\t Amount(1day)\t No.Of Days    Total Amount(in RM)");
                printf("\n \t%s %s\t\t RM %s\t\t  %s\t\tRM %s", r.roomtype, roomtype2, amount, days, total);
                printf("\n \tService Tax(10)\t\t\t\t\t\tRM %s", tax);
                printf("\n \tTotal (Including Taxes)\t\t\t\t\tRM %s  ", amount1);
                printf("\n \tDate And Time : %s %s %s %s %s", tim, tim1, tim2, tim3, tim4);
                printf("\n \t                                                                         ");
                printf("\n \t--------------------------------------------------------------------------");
                printf("\n");


            }
        }
    }
    if (guestFound == 0)
    {
        printf("\nGuest not found!");
    }
    fclose(fp);
}

void update_booking(char num_ent[10])
// Allows the Guest to make changes in his booking details
{
    int Found = 0;
    int days;
    int day;
    int days_t;
    int total = 0;
    int total_t = 0;
    float amount1;
    float amount1_t;
    float total2;
    int amount = 0;
    float total1;
    float total1_t;
    int guestFound = 0;
    char c_no[10];
    char cvv_no[10];
    char exp_no[10];
    char tim[10];
    char tim1[10];
    char tim2[10];
    char tim3[10];
    char tim4[10];
    time_t t;
    time(&t);
    
    fp = fopen("bookings.txt", "r");
    while (fscanf(fp, "%s %s %s %s %s %s %s", r.room_no, r.name, r.num, r.pass, r.email, r.checkin, r.checkout) != -1)
    {
        if (strcmp(r.num, num_ent) == 0)
        {
            Found = 1;
            printf("\n Name : %s", r.name);
            printf("\n Passport/IC No. : %s", r.num);
            printf("\n Room number : %s", r.room_no);
            printf("\n Email : %s", r.email);
            printf("\n Check In Date : %s", r.checkin);
            printf("\n Check Out Date : %s", r.checkout);
            printf("\n");
            break;
        }
    }
    if (Found == 0)
    {
        printf("\nGuest not found!\n");
        manage_booking();
    }
    fclose(fp);
    FILE* tmp;
    FILE* fp;
    fp = fopen("bookings.txt", "r");
    tmp = fopen("tmp.txt", "w");
    if (fp == NULL) {
        printf("File not found");
    }
    else
    {
        while (fscanf(fp, "%s %s %s %s %s %s %s", s.room_no, s.name, s.num, s.pass, s.email, s.checkin, s.checkout) != -1) {
            fgets(r.bf, 20, (FILE*)fp);
            if (strcmp(s.num, num_ent) != 0) {
                fprintf(tmp, "%s %s %s %s %s %s %s\n", s.room_no, s.name, s.num, s.pass, s.email, s.checkin, s.checkout);
            }
        }
    }

    fclose(fp);
    fclose(tmp);
    remove("bookings.txt");
    rename("tmp.txt", "bookings.txt");

    int opt1;
    printf("\n 1.Name\n 2.Email\n 3.Extend Your Booking\n");
    printf("\nEnter the specific option for which you would like to update: ");
    scanf("%d", &opt1);
    switch (opt1)
    {
    case 1:
    {
        printf("Enter New Name:");
        scanf("%s", r.nname);
        enter = fopen("bookings.txt", "a");

        fprintf(enter, "%s %s %s %s %s %s %s", r.room_no, r.nname, r.num, r.pass, r.email, r.checkin, r.checkout);
        fprintf(enter, "\n");
        fclose(enter);
        break;
    }
    case 3:
    {
        printf("Enter New Check Out Day:");
        scanf("%s", r.ncheckout);
        printf("Enter the number of days you wish to extend your booking:");
        scanf("%d", &days);
        fp = fopen("Reciepts.txt", "r");
        if (fp == NULL) { printf("Can't Open the file"); }
        else
        {
            while (fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", s.room_no, s.name, s.num, s.roomtype, s.roomtype2, s.amount, s.total, s.days, s.tax, s.amount1) != -1)
            {

                if (strcmp(s.num, num_ent) == 0)
                {
                    guestFound = 1;
                    amount = atoi(s.amount);
                    total = days * amount;
                    total2 = 0.1f;
                    total1 = total * total2;
                    amount1 = total + total1;
                    printf("Amount for extra %d days including service tax= RM %.2f\n", days, amount1);

                    amount = atoi(s.amount);
                    day = atoi(s.days);
                    days_t = days + day;
                    total_t = days_t * amount;
                    total2 = 0.1f;
                    total1_t = total_t * total2;
                    amount1_t = total_t + total1_t;
                    break;
                }
            }
        }
        fclose(fp);

        char qns[10];
        printf("Enter y to proceed with the Payment OR Enter n to EXIT\n");
        scanf("%s", qns);
        if (strstr(qns, "y"))
        {
            FILE* tmp;
            FILE* fp;
            fp = fopen("Reciepts.txt", "r");
            tmp = fopen("tmp.txt", "w");
            if (fp == NULL) {
                printf("File not found");

            }
            else
            {
                while (fscanf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", b.room_no, b.name, b.num, b.roomtype, b.roomtype2, b.amount, b.total, b.days, b.tax, b.amount1, tim, tim1, tim2, tim3, tim4) != -1) {
                    fgets(r.bf, 20, (FILE*)fp);
                    if (strcmp(b.num, num_ent) != 0) {
                        fprintf(tmp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", b.room_no, b.name, b.num, b.roomtype, b.roomtype2, b.amount, b.total, b.days, b.tax, b.amount1, tim, tim1, tim2, tim3, tim4);
                    }
                }
            }

            fclose(fp);
            fclose(tmp);
            remove("Reciepts.txt");
            rename("tmp.txt", "Reciepts.txt");

            printf("Enter your (Credit/Debit) Card Number:");
            scanf("%s", c_no);
            printf("Enter the 3 digit CVV number:");
            scanf("%s", cvv_no);
            printf("Enter the card's Expiry Date:");
            scanf("%s", exp_no);
            printf("Payment Successful");
            FILE* fp1 = fopen("Reciepts.txt", "a");
            fprintf(fp1, "%s %s %s %s %s %d %d %d %.2f %.2f %s", s.room_no, s.name, s.num, s.roomtype, s.roomtype2, amount, total_t, days_t, total1_t, amount1_t, ctime(&t));
            fclose(fp1);

            enter = fopen("bookings.txt", "a");
            fprintf(enter, "%s %s %s %s %s %s %s", r.room_no, r.name, r.num, r.pass, r.email, r.checkin, r.ncheckout);
            fprintf(enter, "\n");
            fclose(enter);
        }
        break;
    }
    case 2:
    {
        printf("Enter New email address:");
        scanf("%s", r.nemail);
        enter = fopen("bookings.txt", "a");

        fprintf(enter, "%s %s %s %s %s %s %s", r.room_no, r.name, r.num, r.pass, r.nemail, r.checkin, r.checkout);
        fprintf(enter, "\n");
        fclose(enter);
        break;
    }
    default:
    {
        printf("Invalid Entry\nPLease Try Again\n");
    }
    }
}

void view_specific_booking(char num_ent[10]) 
// Allows the Guest to view his booking details
{
    int Found = 0;
    fp = fopen("bookings.txt", "r");
    while (fscanf(fp, "%s %s %s %s %s %s %s", r.room_no, r.name, r.num, r.pass, r.email, r.checkin, r.checkout) != -1)
    {
        fgets(r.bf, 255, (FILE*)fp);
        if (strcmp(r.num, num_ent) == 0) 
        {
            Found = 1;
            printf("\n Name : %s", r.name);
            printf("\n Passport/IC No. : %s", r.num);
            printf("\n Room number : %s", r.room_no);
            printf("\n Email : %s", r.email);
            printf("\n Check In Day : %s",r.checkin );
            printf("\n Check Out Day : %s", r.checkout);
            printf("\n");
            break;

        }
    }
    if (Found == 0) 
    {
        printf("\nGuest not found!");
    }
    fclose(fp);
}

void checkout_guest(char num_ent[10])
// This function checks out the Guest 
{
    char qns[10];
    FILE* tmp;
    printf("Are You Sure that you want to Checkout?\n");
    printf("Enter y for YES or Enter n for NO\n");
    scanf("%s", qns);
    if (strstr(qns, "y"))
    {

        fp = fopen("bookings.txt", "r");
        tmp = fopen("tmp.txt", "w");

        if (fp == NULL) {
            printf("File not found");
        }
        else
        {
            while (fscanf(fp, "%s %s %s %s %s %s %s", r.room_no, r.name, r.num, r.pass, r.email, r.checkin, r.checkout) != -1) {
                fgets(r.bf, 20, (FILE*)fp);

                if (strcmp(r.num,num_ent) != 0)
                {
                    fprintf(tmp, "%s %s %s %s %s %s %s\n", r.room_no, r.name, r.num, r.pass, r.email, r.checkin, r.checkout);
                }
            }
            printf("Room checked out!");
        }

        fclose(fp);
        fclose(tmp);
        remove("bookings.txt");
        rename("tmp.txt", "bookings.txt");

    }
}

int main()
// This is the first interface of this program
    {
    printf("\n\n\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*        WELCOME TO Royale Hotels            *\n");
    printf("\t\t*       -----------------------------        *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n\n\n");
    time_t t;
    time(&t);
    printf(" %s", ctime(&t));
    main_menu();
}
