//Given two numbers X and Y, how should myCompare() decide which number to put first – 
//we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y).
//If XY is larger, then X should come before Y in output, else Y should come before.
//For example, let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260,
//we put Y first.

int myCompare(string X, string Y) 
{ 
    // first append Y at the end of X 
    string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0; 
} 
  
// The main function that prints the arrangement with the largest value. 
// The function accepts a vector of strings 
void printLargest(vector<string> arr) 
{ 
    // Sort the numbers using library sort function. The function uses 
    // our comparison function myCompare() to compare two strings. 
    // See http://www.cplusplus.com/reference/algorithm/sort/ for details 
    sort(arr.begin(), arr.end(), myCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 
