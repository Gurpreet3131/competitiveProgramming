tabs = int(0)

def dfsUtil(node, visited):
	global tabs
	visited[node] = 1

	for i in range(0, tabs):
		print "   ",

	print "<Node name=\""+ dict[node]['name'] + "\" id=\"" + str(dict[node]['id']) + "\">"

	for i in range(0, len(tree[node])):
		newNode = tree[node][i]
		if visited[newNode] == 0:
			tabs += 1
			dfsUtil(newNode, visited)

	for i in range(0, tabs):
		print "   ",

	print "</Node>"
	tabs -= 1


def dfs(root):
	visited = [0] * (n+1)
	dfsUtil(root, visited)

dict = {
	1: {
	 	'id' : 1,
	 	'name': 'Dinesh',
	 	'managerId' : 2
	},
	2: {
	 	'id' : 2,
	 	'name': 'Ramesh',
	 	'managerId' : 4
	},
	3: {
	 	'id': 3,
	 	'name': 'Sandeep',
	 	'managerId' : 4
	},
	4: {
	 	'id' : 4,
	 	'name': 'Abhishek',
	 	'managerId' : 'NULL'
	}	
}

n = len(dict)
root = int(0)

tree = []

for i in range(0, n+1):
	tree += [[]]
	if i > 0 and dict[i]['managerId'] == 'NULL':
		root = dict[i]['id']

for i in range(1, n+1):
	if dict[i]['managerId'] != 'NULL':
		tree[dict[i]['managerId']] += [dict[i]['id']]

dfs(root)
