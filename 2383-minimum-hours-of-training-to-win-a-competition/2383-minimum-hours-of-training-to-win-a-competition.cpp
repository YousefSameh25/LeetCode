class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) 
    {
        int n = energy.size() , need = 0;
        for (int i = 0 ; i < n ; i++)
        {
            if (energy[i] < initialEnergy and experience[i] < initialExperience)
            {
                initialExperience += experience[i];
                initialEnergy -= energy[i];
            }
            else 
            {
                if (energy[i] >= initialEnergy)
                {
                    need += energy[i] - initialEnergy + 1;
                    initialEnergy = energy[i] + 1;
                }
                if (experience[i] >= initialExperience)
                {
                    need += experience[i] - initialExperience + 1;
                    initialExperience = experience[i] + 1;
                }
                initialEnergy -= energy[i];
                initialExperience += experience[i];
            }
        }
        return need;
    }
};