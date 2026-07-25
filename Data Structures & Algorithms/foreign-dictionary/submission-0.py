class Solution:
    
    flag = True
    order = ""
    
    def dfs(self, node, graph, visited, path):

        visited.add(node)
        path.add(node)
        
        for neigh in graph[node]:
            
            if neigh not in visited:
                
                self.dfs(neigh, graph, visited, path)
                
                if self.flag == False:
                    return
            
            elif neigh in path:
                self.flag = False
                self.order = ""
                return
        
        path.remove(node)
    
        self.order += node

    def foreignDictionary(self, words):

        self.flag = True
        self.order = ""

        graph = {}

        for word in words:
            for ch in word:
                if ch not in graph:
                    graph[ch] = []
        
        for i in range(len(words)-1):
            
            j = 0
            
            while j < min(len(words[i]), len(words[i+1])) and words[i][j] == words[i+1][j]:
                j += 1
            
            if j == min(len(words[i]), len(words[i+1])):
                if len(words[i]) > len(words[i+1]):
                    return ""
                continue
            
            graph[words[i][j]].append(words[i+1][j])
        
        
        visited = set()
        
        for node in graph:
            
            if node not in visited:
                
                path = set()
                
                self.dfs(node, graph, visited, path)

                if self.flag == False:
                    return ""
        
        
        return self.order[::-1]