class Solution {
public:
    vector<string> removeAnagrams(vector<string>& testList) {
         vector<string> output;
    
    // Push back first string as it does not have any previous string
    output.push_back(testList[0]);
    string temp_1,temp_2;
    
    for (int i = 1; i < testList.size(); i++)
    {
        // Check if the length of the cur and prev string are same as it might be an anagram
        if (testList[i].length() == testList[i - 1].length())
        {
            temp_1 = testList[i];
            temp_2 = testList[i - 1];
            
            // Sort the strings to make the strings equal
            sort(temp_1.begin(),temp_1.end());
            sort(temp_2.begin(),temp_2.end());
            
            /* If cur string is same as prev string that means it is an anagram so replace the 
            cur string with the prev string to remove it */
            
            if (temp_1.find(temp_2) != string::npos)
            {
                testList[i] = testList[i - 1];
            }
            else  // Else push back the cur string
            {
                output.push_back(testList[i]);
            }
        }
        else  /* If the lengths are not same , that means the cur string is not an anagram so push 
                back */
        {
            output.push_back(testList[i]);
        }
    }
    
    return output;
    }
};