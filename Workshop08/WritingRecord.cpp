#include <memory>
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id) {
					EmployeeWage* newactiveemployee = new EmployeeWage(emp[i].name, sal[j].salary);
					activeEmp += newactiveemployee;
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id) {
					unique_ptr<EmployeeWage> newactiveemployee = make_unique<EmployeeWage>(EmployeeWage(emp[i].name, sal[j].salary));
					activeEmp += newactiveemployee;
				}
			}
		}
		return activeEmp;
	}
}

