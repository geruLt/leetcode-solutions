from typing import List, Dict

class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        # define possible group starters
        starters = [i for i in range(len(strs))]

        # define the similarity dictionary
        similarity_dict = self.getSimilarities(strs)

        # get n groups
        similarity_groups = self.getGroups(similarity_dict, starters)

        return similarity_groups

    def isSimilar(self, str1: str, str2: str) -> bool:
        # check if similar by equality
        if str1 == str2:
            return True

        # check if similar by counting mismatches
        else:
            count = 0
            for i in range(len(str1)):
                count += str1[i] != str2[i]
            if count <= 2:
                return True
        return False

    def getSimilarities(self, strs: List[str]) -> dict:
        # Initiate the dictionary
        similarity_dict = {i:[] for i in range(len(strs))}

        # fill the similarity dictionary
        for i in range(len(strs)):
            for j in range(len(strs)):
                if self.isSimilar(strs[i], strs[j]):
                    similarity_dict[i].append(j)
                    if i != j:
                        similarity_dict[j].append(i)

        return similarity_dict

    def getGroups(self, similarity_dict: Dict[int, List[int]], starters: List[int]) -> int:
        # initiate group holder
        groups = []

        # Calculate largest group for convenience
        largest_group = max(similarity_dict.values(), key=len)
        largest_group = self.fillGroup(similarity_dict, largest_group)
        groups.append(largest_group)

        # remove members from group starters
        starters = [x for x in starters if x not in largest_group]

        while len(starters)>0:
            # Find members of the next group
            similarity_group = similarity_dict[starters[0]]
            similarity_group = self.fillGroup(similarity_dict, similarity_group)
            groups.append(similarity_group)

            # remove members from group starters
            starters = [x for x in starters if x not in similarity_group]

        return len(groups)

    def fillGroup(self, similarity_dict: Dict[int, List[int]], group: List[int]) -> List[int]:
        # add similarities by proxy
        count = 0
        while count < len(group):
            group = group + similarity_dict[group[count]]
            group = sorted(set(group), key=group.index)
            count += 1

        return sorted(group)
