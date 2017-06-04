class que():

	def __init__(self):
		self.arr=list();

	def push(self, item):
		tmp_arr=list();
		tmp_arr.append(item)
		if(self.arr):
			tmp_arr.extend(self.arr)
		self.arr=tmp_arr

	def pop(self):
		return self.arr.pop();

def bfs(matr):
	pass


def main():

	matrix = [
		[0, 0, 0, "x", 0, "x"],
		[0, "x", 0, "x", 0, "x"],
		[0, "*", "x", 0, "x", 0],
		[0, "x", 0, 0, 0, 0], 
		[0, 0, 0, "x", "x", 0],
		[0, 0, 0, "x", 0, "x"]
	];

	row, col, j, i, x, y = 0 ,0, 0, 0, 0, 0 
	for row in matrix:
		for col in row:
			if(col=="*"):
				x, y=i,j
			j+=1
		j=0
		i+=1

	print("So we have {0:2d} and {1:2d} ".format(x, y) )

main()
