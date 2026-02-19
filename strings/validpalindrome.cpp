// Changes in comment , no code change
class Solution {
public:
// Why bool ? Because we want output in True or False , isPalindrome name of function , input is String hence in () 
bool isPalindrome(string s) {

// Now, just imagine if someone gave me empty string , surprisingly it's still a palindrome!
if(s.size()==0){
return true;}  

// For string having length more than one
int i=0; // low
int j=s.size();  //high 

// Now, we want to iterate through entire string hence using while loop from low to high 
while(i<j){

// isalnum---> checks for alphanumeric character in string , special function in C++  and '!' ignores it here , i++ moves forward , continue--> continues it 
if(!isalnum(s[i])){ i++; continue;} // When continue wasn't there my answer was wrong as it would have not stoped after first space maybe 
if(!isalnum(s[j])){ j--; continue;}// performs backward iteration
if(tolower(s[j])!=tolower(s[i])){ // Converts everything into lowercase and checks if both of them are matching , if not--> false
return false;}
else {i++; // For plain case with no spacing and containing lower case , move forward 
j--;  } // Move backward 
}

return true; // Return true for all other cases
} 
};
