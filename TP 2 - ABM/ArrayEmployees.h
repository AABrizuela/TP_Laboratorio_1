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

/** \brief
 *
 * \param employeeList[] eEmployee
 * \param len int
 * \return int
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
void initEmployees( eEmployee employeeList[], int len);

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

/** \brief
 *
 * \param employeeList[] eEmployee
 * \param len int
 * \return void
 *
 */
void subMenu(eEmployee employeeList[], int len);

/** \brief
 *
 * \param employeeList[] eEmployee
 * \param len int
 * \return void
 *
 */
void sortByAlphaAndSector(eEmployee employeeList[], int len);

/** \brief
 *
 * \param employeeList[] eEmployee
 * \param len int
 * \return void
 *
 */
void removeEmployee(eEmployee employeeList[], int len);

/** \brief
 *
 * \param employee eEmployee
 * \param len int
 * \return void
 *
 */
void printEmployee(eEmployee employee);

/** \brief
 *
 * \param employeeList[] eEmployee
 * \param len int
 * \return void
 *
 */
void printEmployees(eEmployee employeeList[], int len);

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
