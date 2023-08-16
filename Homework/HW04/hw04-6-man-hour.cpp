/*
    เขียนโปรแกรมภาษาซีเพื่อรับข้อมูลพนักงานของบริษัทซอร์ฟแวร์ โดยรับข้อมูล รหัสประจำตัวพนักงาน , จำนวนชั่วโมงที่ทำงาน , รายได้ต่อชั่วโมง จากนั้นให้แสดงข้อมูลเลขประจำตัวพนักงาน พร้อมกับรายได้ทั้งหมดที่หนักงานจะได้รับทั้งหมด
    (ผลลัพธ์ของ Salary จะต้องอยู่ในรูปแบบ Decimal Number เท่านั้น เช่น 374,000)

    Test case:
        Input the Employees ID(Max. 10 chars): 
            0342
        Input the working hrs: 
            8
        Salary amount/hr: 
            15000
    Output:
        Expected Output:
        Employees ID = 0342
        Salary = U$ 120,000.00

    Test case:
        Input the Employees ID(Max. 10 chars): 
            0000500349
        Input the working hrs: 
            11
        Salary amount/hr: 
            34000
    Output:
        Expected Output:
        Employees ID = 0000500349
        Salary = U$ 374,000.00
*/
// #include <stdio.h>
// #include <locale.h>
// int main()
// {
//     char ID[10] ;
//     int Work_hrs = 0 ;
//     float Salary = 0 ;
//     printf( "Please Enter your ID : " ) ;
//     scanf("%s", ID) ;
//     printf( "Please Enter your working(hrs) : " ) ;
//     scanf("%d", &Work_hrs) ;
//     printf( "Please Enter your Salary : " ) ;
//     scanf( "%f", &Salary);
//     setlocale(LC_NUMERIC, "") ;
//     printf("Expected Output:\n") ;
//     printf( "Employees ID = %s\n", ID ) ;
//     printf( "Salary = U$ %'.2f", Salary * Work_hrs ) ; 
//     return 0;
// }

#include <stdio.h>

int main()
{
    char Eidstr[11];
    float WorkHr, S;
    int i;

    printf("Input the Employees ID(Max. 10 chars): \n");
    scanf("%10s", Eidstr);

    printf("Input the working hrs: \n");
    scanf("%f", &WorkHr);

    printf("Salary amount/hr: \n");
    scanf("%f", &S);

    float salary = WorkHr * S;

    printf("Expected Output:\n");
    printf("Employees ID = %s\n", Eidstr);

    int temp = 1, comma_count = 0;
    int salary_int = (int)salary; // Extracting the integer part of the salary

    // Count the number of digits in the integer part of the salary
    int temp_salary = salary_int;
    while (temp_salary > 0)
    {
        temp_salary /= 10;
        comma_count++;
    }

    for (i = 1; i < comma_count; i++)
    {
        temp *= 10;
    }
    printf("Salary = U$ ");
    i = 0; // Resetting the loop counter
    while (temp > 0)
    {
        printf("%d", salary_int / temp);
        salary_int %= temp;
        temp /= 10;
        i++;

        if (i < comma_count && i % 3 == 0)
        {
            printf(",");
        }
    }
    printf(".00");

    return 0;
}

