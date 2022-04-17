# PROBLEM: Alice and Bob are playing a game called Centauri Prime. Centauri Prime represents a planet which is split
# into several idependent kingdoms. Alice and Bob decided to distribute kindoms based on the letter
# the kingdom's name ended with. Alice decided to rule kingdoms whose names ended  in vowel. Bob decides to
# rule kindoms whose names ended in a consonant. Both decided that all kingdoms whose names ended in the
# letter 'y' are left without ruler.
#
# INPUT: 1)first line= the number of test cases n, 2)n lines, each one contains a name of one kingdom
#
# OUTPUT: number of case & the name of the ruler.

def get_ruler(kingdom):
  ruler = ''
  name = kingdom
  w_list = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
  string_tuple = tuple(w_list)
  if name.endswith(string_tuple):
    ruler='Alice'
  elif name.endswith('y') or name.endswith('Y'):
    ruler='nobody'
  else:
    ruler='Bob'
    
  return ruler

def main():
  # Get the number of test cases
  T = int(input())
  for t in range(T):
    # Get the kingdom
    kingdom = input()
    print('Case #%d: %s is ruled by %s.' % (t + 1, kingdom, get_ruler(kingdom)))

if __name__ == '__main__':
  main()
