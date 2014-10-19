#include <iostream>
#include <mutex>

class Student{};
void swap(Student& lhs, Student& rhs);

class StudentWrapper
{
private:
	Student student;
	std::mutex myMutex;

public:
	StudentWrapper(const Student& student)
	{
		this->student = student;
	}

	friend void swap(StudentWrapper& lhs, StudentWrapper& rhs)
	{
		if (&lhs == &rhs)
		{
			return;
		}

		std::lock(lhs.myMutex, rhs.myMutex);
		std::lock_guard<std::mutex> lock_a(lhs.myMutex, std::adopt_lock);
		std::lock_guard<std::mutex> lock_b(rhs.myMutex, std::adopt_lock);
		swap(lhs.student, rhs.student);
	}
};

int main()
{
	return 0;
}