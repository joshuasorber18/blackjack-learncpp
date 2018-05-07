//
// Created by Josh Sorber on 5/2/18.
//

#ifndef UNTITLED_ARCHIVEFUNCTIONS_H
#define UNTITLED_ARCHIVEFUNCTIONS_H
//int main()
//{
//    int length;
//
//    // Ask the User how many names they want
//    getSomeNumber(&length);
//    string* names = new string[length];
//    // Collect the names using a for
//
//    for (int i = 0; i < length; ++i) {
//        names[i] = getName(i+1);
//    }
//    // Sort the Names
//    sort(names, names + length);
//    for (int j = 0; j < length; ++j) {
//        cout << names[j] << endl;
//    }
//    // Delete the names allocation
//
//    delete[] names;
//    return 1;
//}

//int getGrade(int index) {
//
//    while(true) {
//        int someNumber;
//        cout << "Grade for Student #"<<index<<": ";
//        cin >> someNumber;
//
//        if (cin.fail() || someNumber > 100 || someNumber < 0)
//        {
//            cin.clear();
//            cin.ignore(32767, '\n');
//        } else {
//            cin.clear();
//            cin.ignore(32767, '\n');
//            return someNumber;
//        }
//
//    }
//
//}
//struct Student {
//    string name = "Nobody";
//    int grade = 0;
//};
//void sortByGrade(Student* students, int length) {
//    // Step through each element of the array
//    // (except the last one, which will already be sorted by the time we get there)
//    for (int startIndex = 0; startIndex < length - 1; ++startIndex)
//    {
//        // smallestIndex is the index of the smallest element we’ve encountered this iteration
//        // Start by assuming the smallest element is the first element of this iteration
//        int largestIndex = startIndex;
//
//        // Then look for a smaller element in the rest of the array
//        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
//        {
//            // If we've found an element that is smaller than our previously found smallest
//            if (students[currentIndex].grade > students[largestIndex].grade)
//                // then keep track of it
//                largestIndex = currentIndex;
//        }
//
//        // smallestIndex is now the smallest element in the remaining array
//        // swap our start element with our smallest element (this sorts it into the correct place)
//        std::swap(students[startIndex], students[largestIndex]);
//    }
//}
//int main() {
//    int length = getSomeNumber();
//    auto *students = new Student[length];
//    for (int i = 0; i < length; ++i) {
//        students[i].name = getName(i+1);
//        students[i].grade = getGrade(i+1);
//    }
//    sortByGrade(students, length);
//
//    for (int j = 0; j < length; ++j) {
//        cout << students[j].name << " got a " << students[j].grade << "%" << endl;
//    }
//    delete[] students;
//    return 1;
//}
#endif //UNTITLED_ARCHIVEFUNCTIONS_H
