#ifndef ArrayEmployees_h_included
#define ArrayEmployees_h_included
#define EMPLOYEES 1000
#define LENGTH 51
#define SECTORS 10

typedef struct
{
    int id;
    char name[LENGTH];
    char lastName[LENGTH];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

/** \brief Finds the first free spot on the array list
 *
 * \param employeeList[] eEmployee The array of employees
 * \param len int Array lenght
 * \return int the number of the free index
 *
 */
int getFreeSpot(eEmployee employeeList[], int len);

/** \brief To indicate that all position in the array are empty,
 *  			this function put the flag (isEmpty) in TRUE in all
 * 			position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees( eEmployee employeeList[], int len);

/** \brief Add an employee on the first empty position of the array
 *
 * \param employeeList[] eEmployee The employee list
 * \param len int The lenght of the employee list
 * \return int Return (-1) if Error [Invalid lenght or NULL pointer or without space] - (0) if Ok
 *
 */
int addEmployee(eEmployee employeeList[], int len);

/** \brief Main menu
 *
 * \return void
 *
 */
void menu();

/** \brief Sub menu
 *
 * \param employeeList[] eEmployee The array of employees
 * \param len int The size of the array
 * \return void
 *
 */
void subMenu(eEmployee employeeList[], int len);

/** \brief Sorts by alphabet and sector
 *
 * \param employeeList[] eEmployee The array of employees
 * \param len int The size of the array
 * \return int Returns -1 if the array is NULL and the size of the array is 0, returns 0 if OK
 *
 */
int sortByAlphaAndSector(eEmployee employeeList[], int len);

/** \brief Removes an employee by id
 *
 * \param employeeList[] eEmployee The employee list
 * \param len int the size of the array
 * \return int returns -1 if it didnt find the employee and returns 0 if Ok
 *
 */
int removeEmployee(eEmployee employeeList[], int len);

/** \brief Prints ONE employee
 *
 * \param employee eEmployee The one employee to be printed
 * \return void
 *
 */
void printEmployee(eEmployee employee);

/** \brief Prints all the employees of the array
 *
 * \param employeeList[] eEmployee The employee list
 * \param len int The size of the array
 * \return int Returns -1 if it found nothing or returns 0 if Ok
 *
 */
int printEmployees(eEmployee employeeList[], int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee employeeList[], int len,int id);

/** \brief Edit employee by id
 *
 * \param emplyeeList[] eEmployee
 * \param len int
 * \return int Returns 0 if Ok
 *
 */
int editEmployee(eEmployee employeeList[], int len);
#endif // ArrayEmployees_h_included
