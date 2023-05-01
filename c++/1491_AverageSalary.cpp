class Solution {
public:
    double average(vector<int>& salary) {
        double answer = (accumulate(salary.begin(), salary.end(), 0)
                        - *max_element(salary.begin(), salary.end())
                        - *min_element(salary.begin(), salary.end()));
        answer /=  (salary.size() - 2);

        return answer;
    }
};